/*******************************************************************
�ļ���     : HDsnap.c
��˾          : Tianjin Tiandy Tech.
������     : ����
��������: 2011-12-12
��Ҫ����: Ӳ��¼��
�޸ļ�¼: 2011-12-12 yangjue Create this File
******************************************************************/
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>
#include <pthread.h>
#include "playback.h"
#include "libdatabase.h"
#include "td_errno.h"
#include "public_def.h"
#include "config.h"
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


#define MAX_PATHLEN      1024
#define DAYNUM_MONTH     31
#define MAXNUM_MONTH     12
#define MAXNUM_YEAR      9999
#define MAXNUM_SNAPBUF   1024
#define DAYNUM_BUF       32
#define MAX_HDNUM        8			// Ӳ��������
#define MAX_PARTITIONNUM 4			// ��������
#define MAX_EPTFILENUM   64			// ��Ч�ļ����������
#define LEN_FOLDERNAME   16
#define MONTHMAP_READ    (2 * 60 * 60)

#define LEN_SDVNAME      27
#define PER_QUERY_NUM	(1024)
#define CHANNEL_OFFSET   4
#define CHANNEL_MAX      32
#define CHANNEL_CHKALL   255

#define SNAP_DB_REC_IDX   5
#define SNAP_DB_START_IDX 8
#define SNAP_DB_STOP_IDX  9
#define SNAP_BUF_STARTNODE_IDX 0
#define SNAP_BUF_STOPNODE_IDX  1

#define SNAP_NODE_ATTR_START 1
#define SNAP_NODE_ATTR_STOP  0

#define SNAP_DEFAULT_BLURTIME 0

#define SNAP_MAX_SPACETIME   (2 * 60 * 60)

// �տ���¼�����ͻ���
#define DAYMAP_TYPE_NUM       3
#define DAYMAP_RECTYPE_ERROR  0xff	// ¼�����ͳ���
#define DAYMAP_RECTYPE_MANUAL 0		// �ֶ�¼��
#define DAYMAP_RECTYPE_ALARM  1		// ����¼��
#define DAYMAP_RECTYPE_TIMING 2		// ��ʱ¼��
// �����ݿ������¼������
#define DAYMAP_IDX_RECTYPE_MANUAL 3		// �ֶ�¼��
#define DAYMAP_IDX_RECTYPE_TIMING 5		// ��ʱ¼��
#define DAYMAP_IDX_RECTYPE_PORT   7		// �˿ڱ���
#define DAYMAP_IDX_RECTYPE_MD     11	// �ƶ���ⱨ��
#define DAYMAP_IDX_RECTYPE_VL     13	// ��Ƶ��ʧ����
#define DAYMAP_IDX_RECTYPE_OD     19	// �ڵ�����

#define DAYMAP_IDX_RECTYPE_ATM	149	//����¼��

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


typedef struct
{
	time_t m_Time;			// ʱ��ֵ
	int    m_iAttr;			// ���ԣ���ʼ����
	int    m_iPreNodeIdx;	// ��һ����������
	int    m_iNextNodeIdx;	// ��һ����������
} TSnapBuf;




/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#if 0
const char cst_SnapExtName[] = ".sdv";
#endif



static TSnapBuf g_stSnapBuf[DAYMAP_TYPE_NUM][MAXNUM_SNAPBUF];
static int iReadMonthSnap = 0;

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/



/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


/*+++++++++++++++++++++++++++++�¿��ղ�ѯ++++++++++++++++++++++++++++++++*/

/******************************************************************************
	��������: rec_MonthMapChkExtName
	��Ҫ����: ������չ���Ƿ���ϱ�׼
	����          : _pcName------�ļ���
	                      _pcExtName----��չ��
	���          : 0Ϊ���ļ���չ�����ϱ�׼
	�޸���־: 2011-12-12 ���崴���ú���
******************************************************************************/
static int rec_MonthMapChkExtName(char* _pcName, const char* _pcExtName)
{
	int iExtLen = 0;
	int iNameLen = 0;
	
	// �������
	if ((NULL == _pcName) || (NULL == _pcExtName))
	{
		return SNAP_ERR_ARG;
	}

	iExtLen = strlen(_pcExtName);					// ������չ������
	iNameLen = strlen(_pcName);						// �����ļ�������
	// ��չ��Ϊ��˵�������ϱ�׼
	if (0 == iExtLen)
	{
		return 0;
	}
	// �ļ�������С�ڻ������չ�����ȣ��򷵻ع���
	if (iNameLen <= iExtLen)
	{
		return -2;
	}

	if (0 == strcmp(_pcName+(iNameLen-iExtLen), _pcExtName))
	{
		return 0;
	}

	return -3;

}

/******************************************************************************
	��������: rec_MonthMapGetChannelNo
	��Ҫ����: ͨ����ת��
	����          : _iChannelNo----ͨ����
	���          : ת����Ľ��
	�޸���־: 2011-12-13 ���崴���ú���
******************************************************************************/
static char rec_MonthMapGetChannelNo(int _iChannelNo)
{
	// С��0�ͳ�����������Ϊ��������
	if ((_iChannelNo < 0) || (_iChannelNo >= CHANNEL_MAX))
	{
		return SNAP_ERR_ARG;
	}
	// ����ASCII�룬0-9��ת����ASCII��
	else if (_iChannelNo <= 9)
	{
		return ('0' + _iChannelNo);
	}
	// ����9�Ĵ�A��ʼ����
	else
	{
		return ('A' + (_iChannelNo - 10));
	}
}

/******************************************************************************
	��������: rec_MonthMapChkChanel
	��Ҫ����: ���ͨ�����Ƿ���ȷ
	����          : _pcName------�ļ���
	                      _iChannelNo----ͨ����
	���          : 0��ʾ��ȷ
	�޸���־: 2011-12-13 ���崴���ú���
******************************************************************************/
static int rec_MonthMapChkChanel(char* _pcName, int _iChannelNo)
{
	char cChannelNo = 0;

	// �������
	if (NULL == _pcName)
	{
		return SNAP_ERR_ARG;
	}

	// ���������е�ͨ�����򲻼��ͨ����
	if (CHANNEL_CHKALL == _iChannelNo)
	{
		return 0;
	}

	cChannelNo = rec_MonthMapGetChannelNo(_iChannelNo);			// ����ͨ����
	//printf("channel number is %c\n", cChannelNo);

	// ���ͨ������ȷ���򷵻���ȷ��־0
	if (*(_pcName + CHANNEL_OFFSET) == cChannelNo)
	{
		return 0;
	}

	return -2;
	
}

/******************************************************************************
	��������: rec_MonthMapChkSize
	��Ҫ����: ��ȡһ���µ�Ӳ�̿�����Ϣ
	����          : _pcPath------�鿴���յ�·��
	                      _pcName------�ļ���
	���          : �����ļ��Ĵ�С
	�޸���־: 2011-12-12 ���崴���ú���
******************************************************************************/
static off_t rec_MonthMapChkSize(char* _pcPath, char* _pcName)
{
	struct stat stBuf;
	char cPathTemp[MAX_PATHLEN];
	
	// �������
	if ((NULL == _pcPath) || (NULL == _pcName))
	{
		return SNAP_ERR_ARG;
	}

	// ����ļ�·��
	strcpy(cPathTemp, _pcPath);
	strcat(cPathTemp, "/");
	strcat(cPathTemp, _pcName);

	stat(cPathTemp, &stBuf);				// ��ȡ�ļ�����Ϣ

	return stBuf.st_size;
	
}

/******************************************************************************
	��������: rec_CheckSnapFolder
	��Ҫ����: ��ȡһ���µ�Ӳ�̿�����Ϣ
	����          : _pcPath------�鿴���յ�·��
	���          : 0Ϊ���ļ��в���
	�޸���־: 2011-12-12 ���崴���ú���
******************************************************************************/
static int rec_MonthMapChkFolder(char* _pcPath, int _iChannelNo)
{
	DIR* pstDir = (DIR*)NULL;
	struct dirent* pstr = NULL;
	struct dirent tmp;

	// �������
	if (NULL == _pcPath)
	{
		return SNAP_ERR_ARG;
	}
	
	pstDir = opendir(_pcPath);				//��ָ��·��
	// ���ļ���ʧ��
	if (NULL == pstDir)
	{
		return SNAP_ERR_ARG;
	}

	// ��ȡ�����ļ�
	//while (NULL != (pstr = readdir(stDir)))
	memset(&tmp,0,sizeof(tmp));
	while((readdir_r(pstDir, &tmp, &pstr) == 0) && pstr)
	{
		// ������Ƴ���
		if (LEN_SDVNAME != strlen(pstr->d_name))
		{
			continue;
		}
		#if 0
		// �����չ���Ƿ���ϱ�׼
		if (0 != rec_MonthMapChkExtName(pstr->d_name, cst_SnapExtName))
		{
			continue;
		}
		#else
		
		// �����չ���Ƿ���ϱ�׼
		if (0 != rec_MonthMapChkExtName(pstr->d_name, Cfg_gRecExtName()))
		{
			continue;
		}
		
		#endif
		// ���ͨ���Ƿ���ȷ
		if (0 != rec_MonthMapChkChanel(pstr->d_name, _iChannelNo))
		{
			continue;
		}
		// ���ָ���ļ��Ĵ�С����Ϊ0��Ϊ���ļ�����
		if (rec_MonthMapChkSize(_pcPath, pstr->d_name) > 0)
		{
			closedir(pstDir);
			return 0;
		}
	}

	closedir(pstDir);
	
	return -2;

}

/******************************************************************************
	��������: rec_MonthMapInit
	��Ҫ����: �¿�����Ϣ��ʼ��
	����          : _pcInfo-------������Ϣ
	���          : ��������Ϣ����
	�޸���־: 2011-12-26 ���崴���ú���
******************************************************************************/
static int rec_MonthMapInit(int* _pcInfo)
{
	int i = 0;

	if (NULL == _pcInfo)
	{
		return SNAP_ERR_ARG;
	}

	for (i=0; i<DAYNUM_BUF; i++)
	{
		*(_pcInfo + i) = SNAP_EMPTY;
	}

	return 0;
}

/******************************************************************************
	��������: rec_GetMonthMap
	��Ҫ����: ��ȡ�µ�Ӳ�̿�����Ϣ
	����          : _pcPath------�鿴���յ�·��
	                      _pcFolder-----�ļ�������
	                      _iChannelNo---ͨ����
	                      _pcInfo-------������Ϣ
	���          : 0Ϊ��ȡ�ɹ�������Ϊ��ȡʧ��
	�޸���־: 2011-12-26 ���崴���ú���
******************************************************************************/
static int rec_MonthMapRead(char *_pcPath, char *_pcFolder, int _iChannelNo)
{
	int iTemp = 0;
	int i = 0;
	int j = 0;
	char cPath[MAX_PATHLEN];

	// ���в������
	if ((NULL == _pcPath) || (NULL == _pcFolder))
	{
		return SNAP_ERR_ARG;
	}

	for (i = 0; i < MAX_SATA_NUM; i++)
	{
		for (j = 0; j < MAX_PART_NUM; j++)
		{
			sprintf(cPath, "%s/%d/%d/%s", _pcPath, i, j, _pcFolder);
			iTemp = rec_MonthMapChkFolder(cPath, _iChannelNo);			// ��ѯ�ļ������Ƿ��и�ͨ������
			if (0 == iTemp)
			{
				return 0;
			}
		}
	}

	return 1;
	
}

/******************************************************************************
	��������: rec_GetMonthMap
	��Ҫ����: ��ȡ�µ�Ӳ�̿�����Ϣ
	����          : _pcPath------�鿴���յ�·��
	                      _iYear--------���鿴�����
	                      _iMonth-------���鿴���·�
	                      _iChannelNo---ͨ����
	                      _pcInfo-------������Ϣ
	���          : 0Ϊ��ȡ�ɹ�
	�޸���־: 2011-12-26 ���崴���ú���
******************************************************************************/
int rec_GetMonthMap(char* _pcPath, int _iYear, int _iMonth, int _iChannelNo, int* _piInfo)
{
	static int iFirst = 0;
	char cFolderName[LEN_FOLDERNAME];
	int iTemp = 0;
	int i = 0;

	if ((NULL == _pcPath) || (NULL == _piInfo))
	{
		return SNAP_ERR_ARG;
	}
	
	rec_MonthMapInit(_piInfo);				// ��ʼ��������Ϣ

	// ����һ�λ�û�м�����ϣ�UI��ȡʱֱ�ӷ��ؾ���Ч
	if (iFirst && !iReadMonthSnap)
	{
		return 0;
	}
	iFirst = 1;
	
	for (i=1; i<DAYNUM_BUF; i++)
	{
		// �����ļ�������
		sprintf(cFolderName, "%.4d%.2d%.2d", _iYear, _iMonth, i);
		iTemp = rec_MonthMapRead(_pcPath, cFolderName, _iChannelNo);
		if (0 == iTemp)
		{
			*(_piInfo + i) = SNAP_HAVE;
		}
	}

	return 0;

}

// ����20120530 ��ʼ�������̣߳�ÿ��һСʱ����һ�Σ�ÿ�ζ�ȡ���12���µ�����
static void* rec_MonthMapThread(void* _param)
{
	int tmp[CHANNEL_MAX];
	time_t now;
	struct tm tm_now;
	int i = 0;
	int iMonth = 0;
	int iYear = 0;
	int iTime = 0;
	func_info();

	while (1)
	{
		iTime = get_uptime(NULL);
		now = time(&now);
		localtime_r(&now, &tm_now); 

		// ��ѯ��ʮ�����µ�������Ϣ
		iMonth = tm_now.tm_mon+1;
		iYear = tm_now.tm_year+1900;
		for (i = 0; i < MAXNUM_MONTH; i++)
		{
			rec_GetMonthMap(SNAP_DESK_Path, iYear, iMonth, CHANNEL_CHKALL, tmp);
			iReadMonthSnap = 1;
			iMonth--;
			if (iMonth <= 0)
			{
				iMonth = MAXNUM_MONTH;
				iYear--;
			}
		}
		// ÿСʱ��ȡһ��������Ϣ
		while (get_uptime(NULL) - iTime < MONTHMAP_READ)
		{
			sleep(10);
		}
	}
	
	return NULL;}

int rec_GetMonthMapInit()
{
	pthread_t tThread;
	int iRet = 0;
	iRet = pthread_create(&tThread, NULL, rec_MonthMapThread, NULL);
	if (0 == iRet)
	{
		pthread_detach(tThread);
		return 0;
	}
	return -1;
}


/*+++++++++++++++++++++++++++++�տ��ղ�ѯ++++++++++++++++++++++++++++++++*/


/******************************************************************************
	��������: rec_DayInitChkBuf
	��Ҫ����: ��ʼ��������
	����          : ��
	���          : ��
	�޸���־: 2011-12-13 ���崴���ú���
******************************************************************************/
int rec_DayInitChkBuf(void)
{
	int i = 0;
	int j = 0;

	for (j=0; j<DAYMAP_TYPE_NUM; j++)
	{
		for (i=0; i<MAXNUM_SNAPBUF; i++)
		{
			g_stSnapBuf[j][i].m_iPreNodeIdx = -1;
			g_stSnapBuf[j][i].m_iNextNodeIdx= -1;
		}
		// ��ʼ�ڵ�����������г�ʼ��
		g_stSnapBuf[j][SNAP_BUF_STARTNODE_IDX].m_iNextNodeIdx = SNAP_BUF_STOPNODE_IDX;
		g_stSnapBuf[j][SNAP_BUF_STOPNODE_IDX].m_iPreNodeIdx = SNAP_BUF_STARTNODE_IDX;
	}

	return 0;
}

/******************************************************************************
	��������: rec_DayGetNode
	��Ҫ����: �ҵ�һ�����еĽ��
	����          : ��
	���          : ����
	�޸���־: 2011-12-13 ���崴���ú���
******************************************************************************/
int rec_DayGetNode(int _iType)
{
	int i = 0;

	// �������
	if (_iType >= DAYMAP_TYPE_NUM)
	{
		return -1;
	}

	for (i=0; i<MAXNUM_SNAPBUF; i++)
	{
		// ����Ϊ��β��������
		if ((SNAP_BUF_STARTNODE_IDX == i) || (SNAP_BUF_STOPNODE_IDX == i))
		{
			continue;
		}
		// ��ѯ�ý�����βָ���Ƿ��ڷ�Χ��
		if ((g_stSnapBuf[_iType][i].m_iPreNodeIdx < 0) || (g_stSnapBuf[_iType][i].m_iNextNodeIdx < 0))
		{
			return i;
		}
	}
	return -2;
}

/******************************************************************************
	��������: rec_DayInsertNodeBuf
	��Ҫ����: �ڻ���������һ�����
	����          : _iTime--------������ʱ��ֵ
	                      _iAttr---------��ʱ����������ݣ���ʼ���ǽ���
	���          : ������ţ���ֵ��ʾ����ʧ��
	�޸���־: 2011-12-13 ���崴���ú���
******************************************************************************/
int rec_DayInsertNodeBuf(time_t _iTime, int _iAttr, int _iType)
{
	int iNode = 0;
	int i = 0;
	int iReadNode = 0;
	int iPreNode = 0;
	int iNextNode = 0;

	// �������
	if ((SNAP_NODE_ATTR_START != _iAttr) && (SNAP_NODE_ATTR_STOP != _iAttr))
	{
		return -1;
	}
	if (_iType >= DAYMAP_TYPE_NUM)
	{
		return -1;
	}

	iNode = rec_DayGetNode(_iType);			// Ѱ��һ�����еĽ��
	if (iNode < 0)
	{
		return -2;
	}
	// ����ý����Ϣ
	g_stSnapBuf[_iType][iNode].m_Time = _iTime;
	g_stSnapBuf[_iType][iNode].m_iAttr= _iAttr;
	
	iReadNode = SNAP_BUF_STOPNODE_IDX;				// ��ʼ������Ľ���
	for (i=0; i<MAXNUM_SNAPBUF; i++)
	{
		iReadNode = g_stSnapBuf[_iType][iReadNode].m_iPreNodeIdx;		// ������һ�����
		// �����Ľ��������ǿ�ʼ��㣬�������
		if (SNAP_BUF_STARTNODE_IDX != iReadNode)
		{
			// ��������ʱ�����ȵ�ǰ������ʱ����С����������
			if (_iTime < g_stSnapBuf[_iType][iReadNode].m_Time)
			{
				continue;
			}
		}
		// �ڵ�ǰ����֮�����ý��
		iPreNode = iReadNode;
		iNextNode = g_stSnapBuf[_iType][iReadNode].m_iNextNodeIdx;
		g_stSnapBuf[_iType][iNode].m_iPreNodeIdx = iPreNode;
		g_stSnapBuf[_iType][iNode].m_iNextNodeIdx = iNextNode;
		g_stSnapBuf[_iType][iPreNode].m_iNextNodeIdx = iNode;
		g_stSnapBuf[_iType][iNextNode].m_iPreNodeIdx = iNode;
		
		return iNode;
	}

	return -3;
	
}

/******************************************************************************
	��������: rec_DayDelNode
	��Ҫ����: ɾ��һ�����
	����          : _iNode------����
	���          : 0��ʾɾ���ɹ�
	�޸���־: 2011-12-13 ���崴���ú���
******************************************************************************/
int rec_DayDelNode(int _iNode, int _iType)
{
	int iPreNode = 0;
	int iNextNode = 0;
	
	// �������
	if ((SNAP_BUF_STARTNODE_IDX == _iNode) || (SNAP_BUF_STOPNODE_IDX == _iNode))
	{
		return -1;
	}
	if (_iNode < 0)
	{
		return -1;
	}
	if (_iType >= DAYMAP_TYPE_NUM)
	{
		return -1;
	}

	iPreNode = g_stSnapBuf[_iType][_iNode].m_iPreNodeIdx;
	iNextNode = g_stSnapBuf[_iType][_iNode].m_iNextNodeIdx;
	// �жϽ������Ƿ���ȷ
	if ((iPreNode < 0) || (iNextNode < 0))
	{
		return -2;
	}

	// ��������ֵ
	g_stSnapBuf[_iType][iPreNode].m_iNextNodeIdx = iNextNode;
	g_stSnapBuf[_iType][iNextNode].m_iPreNodeIdx = iPreNode;
	g_stSnapBuf[_iType][_iNode].m_iNextNodeIdx = -1;
	g_stSnapBuf[_iType][_iNode].m_iPreNodeIdx = -1;

	return 0;
}

/******************************************************************************
	��������: rec_DayOptNodeBuf
	��Ҫ����: �Ըý�����ݽ����Ż�
	����          : _iNode--------�������
	                      _iBlurTime-----ģ��ʱ��
	���          : 0��ʾ�Ż��ɹ�
	�޸���־: 2011-12-13 ���崴���ú���
******************************************************************************/
int rec_DayOptNodeBuf(int _iNode, int _iBlurTime, int _iType)
{
	int iChkNode = 0;
	
	// �������
	if (_iNode < 0)
	{
		return -1;
	}
	if (_iType >= DAYMAP_TYPE_NUM)
	{
		return -1;
	}

	// ��������Ϊ��ʼ��㣬���������ڵ��п�����㣬ɾ�������
	if (SNAP_NODE_ATTR_START == g_stSnapBuf[_iType][_iNode].m_iAttr)
	{
		// ���ǰһ�����
		iChkNode = g_stSnapBuf[_iType][_iNode].m_iPreNodeIdx;
		if (SNAP_BUF_STARTNODE_IDX != iChkNode)
		{
			if (g_stSnapBuf[_iType][_iNode].m_iAttr == g_stSnapBuf[_iType][iChkNode].m_iAttr)
			{
				rec_DayDelNode(_iNode, _iType);
				return 0;
			}
		}
		// ����һ�����
		iChkNode = g_stSnapBuf[_iType][_iNode].m_iNextNodeIdx;
		if (SNAP_BUF_STOPNODE_IDX != iChkNode)
		{
			if (g_stSnapBuf[_iType][_iNode].m_iAttr == g_stSnapBuf[_iType][iChkNode].m_iAttr)
			{
				rec_DayDelNode(iChkNode, _iType);
			}
		}
		// ���ǰһ������ǽ�����㣬�������ʱ��Ϊģ��ʱ�����ڣ���ɾ��
		iChkNode = g_stSnapBuf[_iType][_iNode].m_iPreNodeIdx;
		if (SNAP_BUF_STARTNODE_IDX != iChkNode)
		{
			if (g_stSnapBuf[_iType][_iNode].m_Time - g_stSnapBuf[_iType][iChkNode].m_Time <= _iBlurTime)
			{
				rec_DayDelNode(_iNode, _iType);
				rec_DayDelNode(iChkNode, _iType);
			}
		}
	}
	// ��������Ϊ������㣬���������ڵ��н�����㣬ɾ����ǰ��
	else if (SNAP_NODE_ATTR_STOP == g_stSnapBuf[_iType][_iNode].m_iAttr)
	{
		// ����һ�����
		iChkNode = g_stSnapBuf[_iType][_iNode].m_iNextNodeIdx;
		if (SNAP_BUF_STOPNODE_IDX != iChkNode)
		{
			if (g_stSnapBuf[_iType][_iNode].m_iAttr == g_stSnapBuf[_iType][iChkNode].m_iAttr)
			{
				rec_DayDelNode(_iNode, _iType);
				return 0;
			}
		}
		// ���ǰһ�����
		iChkNode = g_stSnapBuf[_iType][_iNode].m_iPreNodeIdx;
		if (SNAP_BUF_STARTNODE_IDX != iChkNode)
		{
			if (g_stSnapBuf[_iType][_iNode].m_iAttr == g_stSnapBuf[_iType][iChkNode].m_iAttr)
			{
				rec_DayDelNode(iChkNode, _iType);
			}
		}
		// �����һ������ǿ�ʼ��㣬�������ʱ��Ϊģ��ʱ�����ڣ���ɾ��
		iChkNode = g_stSnapBuf[_iType][_iNode].m_iNextNodeIdx;
		if (SNAP_BUF_STOPNODE_IDX != iChkNode)
		{
			if (g_stSnapBuf[_iType][iChkNode].m_Time - g_stSnapBuf[_iType][_iNode].m_Time <= _iBlurTime)
			{
				rec_DayDelNode(_iNode, _iType);
				rec_DayDelNode(iChkNode, _iType);
			}
		}
	}
	else
	{
		return -2;
	}

	return 0;
	
}



/******************************************************************************
	��������: rec_DayWriteChkBuf
	��Ҫ����: ��ʱ����뻺����
	����          : _iStartTime------��ʼʱ��
	                      _iStopTime-------����ʱ��
	                      _iBlurTime--------ģ��ʱ��
	���          : 0��ʾ����ɹ�
	�޸���־: 2011-12-13 ���崴���ú���
******************************************************************************/
int rec_DayWriteChkBuf(time_t _iStartTime, time_t _iStopTime, int _iBlurTime, int _iType)
{
	int iNode1 = 0;
	int iNode2 = 0;

	if (_iType >= DAYMAP_TYPE_NUM)
	{
		return -1;
	}
	
	// ��ӽ��
	iNode1 = rec_DayInsertNodeBuf(_iStartTime, SNAP_NODE_ATTR_START, _iType);
	iNode2 = rec_DayInsertNodeBuf(_iStopTime, SNAP_NODE_ATTR_STOP, _iType);

	// ������ʧ�ܣ���ɾ����ӵĽ��
	if ((iNode1 < 0) || (iNode2 < 0))
	{
		rec_DayDelNode(iNode1, _iType);
		rec_DayDelNode(iNode2, _iType);
		
		return -2;
	}

	// ����㣬�����Ż�
	rec_DayOptNodeBuf(iNode1, _iBlurTime, _iType);
	rec_DayOptNodeBuf(iNode2, _iBlurTime, _iType);

	return 0;
}


/******************************************************************************
	��������: rec_DayMapGetRecType
	��Ҫ����: ������Ϣ�ص�����
	����          : _iType-----------�������ļ�����
	���          : ��������Ϣ����
	�޸���־: 2011-12-19 ���崴���ú���
******************************************************************************/
int rec_DayMapGetRecType(int _iType)
{
	// �ֶ�¼������
	if (0 == (_iType % DAYMAP_IDX_RECTYPE_MANUAL))
	{
		return DAYMAP_RECTYPE_MANUAL;
	}
	// ��Ƶ��ʧ����
	else if (0 == (_iType % DAYMAP_IDX_RECTYPE_VL))
	{
		return DAYMAP_RECTYPE_ALARM;
	}
	// �ƶ���ⱨ��
	else if (0 == (_iType % DAYMAP_IDX_RECTYPE_MD))
	{
		return DAYMAP_RECTYPE_ALARM;
	}
	// �˿ڱ���
	else if (0 == (_iType % DAYMAP_IDX_RECTYPE_PORT))
	{
		return DAYMAP_RECTYPE_ALARM;
	}
	// od ¼��
	else if (0 == (_iType % DAYMAP_IDX_RECTYPE_OD))
	{
		return DAYMAP_RECTYPE_ALARM;
	}
	// ��ʱ¼��
	else if (0 == (_iType % DAYMAP_IDX_RECTYPE_TIMING))
	{
		return DAYMAP_RECTYPE_TIMING;
	}
	//����¼��
	else if (0 == (_iType % DAYMAP_IDX_RECTYPE_ATM))
	{
		return DAYMAP_RECTYPE_MANUAL;
	}
	else
	{
		return DAYMAP_RECTYPE_ERROR;
	}
}

#if 0

/******************************************************************************
	��������: rec_DayLoadDb
	��Ҫ����: ������Ϣ�ص�����
	����          : _iTime------------ģ��ʱ��
	                      _iColumn----------�ֶ�����
	                      _pcColumn_value---������
	                      _pcColumn_name---������
	���          : ��������Ϣ����
	�޸���־: 2011-12-13 ���崴���ú���
******************************************************************************/
int rec_DayLoadDb(void* _iTime, int _iColumn, char** _pcColumn_value, char** _pcColumn_name )
{
	int iTemp = 0;
	time_t iStartTime = 0;
	time_t iStopTime = 0;
	int iReadType = 0;
	int iType = 0;

	iStartTime = atoi(_pcColumn_value[SNAP_DB_START_IDX]);
	iStopTime = atoi(_pcColumn_value[SNAP_DB_STOP_IDX]);
	iReadType = atoi(_pcColumn_value[SNAP_DB_REC_IDX]);
	if (((iStopTime > iStartTime) && (iStopTime - iStartTime > SNAP_MAX_SPACETIME)) ||
		((iStartTime > iStopTime) && (iStartTime - iStopTime > SNAP_MAX_SPACETIME)))
	{
		return 0;			// ����20120419 ���ظ�ֵ�����������򲻻������ȡ
	}
	iType = rec_DayMapGetRecType(iReadType);			// ��ȡ�տ�������

	// �������Ŀ�ʼʱ��ͽ���ʱ����뵽��������
	iTemp = rec_DayWriteChkBuf(iStartTime, iStopTime, *((int*)_iTime), iType);

	return 0;				// ����20120419 ���ظ�ֵ�����������򲻻������ȡ
	
}
#endif
/******************************************************************************
	��������: rev_GetSnapTime
	��Ҫ����: ���������Ϣ
	����          : _iStartTime------����鿴�Ŀ�ʼʱ��
	                      _iStopTime-------���鿴�Ľ���ʱ��
	                      _pstTime---------ʱ�����ݽṹ��
	                      _iMaxCnt---------����������
	���          : ��������Ϣ����
	�޸���־: 2011-12-14 ���崴���ú���
******************************************************************************/
int rev_GetSnapTime(time_t _iStartTime, time_t _iStopTime, TSnapTime* _pstTime, int _iMaxCnt)
{
	int iNum = 0;
	int iNodeStart = 0;
	int iNodeStop = 0;
	int iType = 0;

	iNum = 0;
	for (iType=0; iType<DAYMAP_TYPE_NUM; iType++)
	{
		iNodeStart = SNAP_BUF_STARTNODE_IDX;					// ��ʼ��Ϊͷ���
		iNodeStop = SNAP_BUF_STARTNODE_IDX; 					// ��ʼ��Ϊͷ���
		for ( ; (iNum<MAXNUM_SNAPBUF)&&(iNum<_iMaxCnt); )
		{
			// �����ʼ�����Ϣ
			iNodeStart = g_stSnapBuf[iType][iNodeStop].m_iNextNodeIdx;		// ��ȡ��ʼ���
			// �����������Ѿ��������
			if ((iNodeStart < 0) || (SNAP_BUF_STOPNODE_IDX == iNodeStart))
			{
				break;
			}
			// ��ȡ������Ϊ���������ݳ���������������
			if (SNAP_NODE_ATTR_START != g_stSnapBuf[iType][iNodeStart].m_iAttr)
			{
				break;
			}
			// �����������Ϣ
			iNodeStop = g_stSnapBuf[iType][iNodeStart].m_iNextNodeIdx;				// ��ȡ�������
			// �����������Ѿ��������
			if ((iNodeStop < 0) || (SNAP_BUF_STOPNODE_IDX == iNodeStop))
			{
				break;
			}
			// ��ȡ������Ϊ���������ݳ���������������
			if (SNAP_NODE_ATTR_STOP != g_stSnapBuf[iType][iNodeStop].m_iAttr)
			{
				break;
			}

			// ��ʼ�������ʼʱ��֮ǰ
			if (g_stSnapBuf[iType][iNodeStart].m_Time < _iStartTime)
			{
				// ������������ڿ�ʼʱ��֮ǰ��������������
				if (g_stSnapBuf[iType][iNodeStop].m_Time < _iStartTime)
				{
					continue;
				}
				// �����β����ڽ���ʱ��֮����ȡ��ʼʱ��Ϊ��ʼʱ�䣬����ʱ��Ϊ��βʱ��
				else if (g_stSnapBuf[iType][iNodeStop].m_Time > _iStopTime)
				{
					(_pstTime + iNum)->m_iType = iType;
					(_pstTime + iNum)->m_iStartTime = _iStartTime;
					(_pstTime + iNum)->m_iStopTime = _iStopTime;
					iNum++;
					break;
				}
				// �����β����ڽ���ʱ��֮ǰ��ȥ��β��㣬��ȡ��ʼʱ��Ϊ��ʼʱ��
				else
				{
					(_pstTime + iNum)->m_iType = iType;
					(_pstTime + iNum)->m_iStartTime = _iStartTime;
					(_pstTime + iNum)->m_iStopTime = g_stSnapBuf[iType][iNodeStop].m_Time;
				}
			}
			// ��ʼʱ����������˽���ʱ�䣬��ֱ���˳�������
			else if (g_stSnapBuf[iType][iNodeStart].m_Time > _iStopTime)
			{
				break;
			}
			else
			{
				// ��β����ڽ���ʱ��֮��ȡ����ʱ��Ϊ��βʱ��
				if (g_stSnapBuf[iType][iNodeStop].m_Time > _iStopTime)
				{
					(_pstTime + iNum)->m_iType = iType;
					(_pstTime + iNum)->m_iStartTime = g_stSnapBuf[iType][iNodeStart].m_Time;
					(_pstTime + iNum)->m_iStopTime = _iStopTime;
					iNum++;
					break;
				}
				else
				{
					(_pstTime + iNum)->m_iType = iType;
					(_pstTime + iNum)->m_iStartTime = g_stSnapBuf[iType][iNodeStart].m_Time;
					(_pstTime + iNum)->m_iStopTime = g_stSnapBuf[iType][iNodeStop].m_Time;
				}
			}
			
			iNum++;
		}
	}
	
	return iNum;
}

static int rec_CalendarMaxDaysForMon(int _iYear, int _iMon, int _iDay)
{
	if(_iYear == 0 || _iMon == 0 || _iDay == 0)
	{
		return -1;
	}
	if ((_iYear < 1900) || (_iYear > 9999))
	{
		return -1;
	}
	if (2 == _iMon)
	{
		if ((_iYear % 100 != 0 && _iYear % 4 == 0) || (_iYear % 400 == 0))
		{
			if(_iDay > 29)
			{
				return -1;
			}
		}
		if(_iDay > 28)
		{
			return -1;
		}
	}
	else if (_iMon <= 7)
	{
		if(_iDay > 30 + ((_iMon & 1) ? 1 : 0))
		{
			return -1;
		}
	}
	else
	{
		if(_iDay > 30 + ((_iMon & 1) ? 0 : 1))
		{
			return -1;
		}
	}
	return 0;
}

/******************************************************************************
	��������: rec_GetDayMap
	��Ҫ����: ��ȡһ��Ӳ�̿�����Ϣ
	����          : _pstDb-------���ݿ�ָ��
	                      _iYear--------���鿴�����
	                      _iMonth-------���鿴���·�
	                      _iDay---------����ѯ������
	                      _iChannelNo---ͨ����
	                      _iBlurTime-----ģ��ʱ��
	                      _iMaxCnt------�������
	                      _pcInfo-------������Ϣ
	���          : ��������Ϣ����
	�޸���־: 2011-12-13 ���崴���ú���
******************************************************************************/

static int rec_JudgeFileValid(TFileInfo *_ptInfo, int _iStartTm, int _iEndTm)
{
	int iFileStartTm;
	int iFileEndTm;
	int iFileType;
	
	if(NULL == _ptInfo)
	{
		return td_failure;
	}

	iFileStartTm = _ptInfo->m_iStartTime;
	iFileEndTm = _ptInfo->m_iStopTime;
	iFileType = _ptInfo->m_iRecAttr;
	
	if(DAYMAP_RECTYPE_ERROR == rec_DayMapGetRecType(iFileType))
	{
		return td_failure;
	}
	if (((iFileEndTm > iFileStartTm) && (iFileEndTm - iFileStartTm > SNAP_MAX_SPACETIME)) ||
	((iFileStartTm > iFileEndTm) && (iFileStartTm - iFileEndTm > SNAP_MAX_SPACETIME)))
	{
		return td_failure;
	}
	if(iFileEndTm <= _iStartTm)
	{
		return td_failure;
	}
	return td_success;
}
static int rec_QueryCondion(int _iChannelNo, int _iStartTm, int _iEndTm, int _iBlurTime)
{
	int i = 0;
	int iRet = 0;
	TQuery Query;
	TFileInfo* ptInfo = NULL;;

	//��ѯ����
	Query.m_uiPageSize = PAGE_SHOW_NUM;
	Query.m_iStartTime = (_iStartTm - 7200 > 0) ? _iStartTm - 7200 : 0;//��ǰ2Сʱ��ѯ���жϱ߽�
	Query.m_iStopTime = _iEndTm;
	Query.m_ucFileType = FILE_REC;
	Query.m_ucRecType = 0xff;			//��ѯ¼����������
	Query.m_ucDevType =0xff;
	Query.m_ucChannelNo = _iChannelNo;
	Query.m_uiPageNo = 0;
	Query.m_uiTotalNum = PER_QUERY_NUM;
	Query.m_cReserved[0] = '\0';	

	ptInfo = (TFileInfo *)malloc(sizeof(TFileInfo) * PER_QUERY_NUM);
	if(NULL == ptInfo)
	{
		goto leave;
	}
	//��ѯ�ļ��б�
	iRet = rec_QueryAllFiles(&Query, ptInfo);
	if(ERR_REC_SUCCESSFUL == iRet)
	{
		Query.m_uiTotalNum = (Query.m_uiTotalNum> PER_QUERY_NUM) ? PER_QUERY_NUM : Query.m_uiTotalNum;
		for(i = 0; i < Query.m_uiTotalNum; i++)
		{
			if(rec_JudgeFileValid(ptInfo + i, _iStartTm, _iEndTm))
			{
				continue;
			}
			rec_DayWriteChkBuf(ptInfo[i].m_iStartTime, ptInfo[i].m_iStopTime, 
				_iBlurTime, rec_DayMapGetRecType(ptInfo[i].m_iRecAttr));
		}
	}
leave:
	if(NULL != ptInfo)
	{
		free(ptInfo);
	}
	return iRet;
}

int rec_GetDayMap(int _iYear, int _iMonth, int _iDay, int _iChannelNo, int _iBlurTime, int _iMaxCnt, TSnapTime* _pstTime)
{
	time_t iStartTime = 0;
	time_t iStopTime = 0;
	struct tm stChkTime;
	int iNum = 0;

	// �������

	if(rec_CalendarMaxDaysForMon(_iYear, _iMonth, _iDay) < 0)
	{
		return SNAP_ERR_ARG;
	}
	if (_iBlurTime < SNAP_DEFAULT_BLURTIME)
	{
		_iBlurTime = SNAP_DEFAULT_BLURTIME;
	}
	
	memset(&stChkTime, 1, sizeof(stChkTime));			// �ṹ���ʼ��
	// ������ǰ����
	stChkTime.tm_year = _iYear - 1900;
	stChkTime.tm_mon = _iMonth - 1;
	stChkTime.tm_mday = _iDay;

	// ���㿪ʼʱ��
	stChkTime.tm_hour = 0;
	stChkTime.tm_min = 0;
	stChkTime.tm_sec = 0;
	iStartTime = mktime(&stChkTime);

	// �������ʱ��
	stChkTime.tm_hour = 23;
	stChkTime.tm_min = 59;
	stChkTime.tm_sec = 59;
	iStopTime = mktime(&stChkTime);

	rec_DayInitChkBuf();			// ���ջ�������ʼ��

	rec_QueryCondion(_iChannelNo, iStartTime, iStopTime, _iBlurTime);

	iNum = rev_GetSnapTime(iStartTime, iStopTime, _pstTime, _iMaxCnt);		// ���������Ϣ
	
	return iNum;

}

/******************************************************************************
	��������: main
	��Ҫ����: ������
	����          : ��
	���          : ����0��ʾ�ɹ������������
	�޸���־: 2011-11-15 ���崴���ú���
******************************************************************************/
#if 0
int main(int argc, char *argv[])
{
	int iMonthInfo[DAYNUM_BUF];
	int iTemp = 0;
	int i = 0;
	//sqlite3* pstDb = NULL;
	//TSnapTime stSnapTime[1024];
	//int iNum = 0;
	//int iChannel = 0;
	//int iDay = 13;

	printf("hello,world\n");
	
	iTemp = rec_GetMonthMap("/mnt/sata", 2011, 12, 255, iMonthInfo);
	if (iTemp < 0)
	{
		printf("read error!\n");
		return -1;
	}

	for (i=1; i<DAYNUM_MONTH; i++)
	{
		printf("2011/01/%.2d %s\n", i, (0 == iMonthInfo[i] ? "N" : "Y"));
	}

#if 0
	//iChannel = 28;

	while (1)
	{
		iTemp = sqlite3_open("./index.db", &pstDb);
		if (iTemp != SQLITE_OK)
		{
			//���ݿ��ʧ��
			printf("database open failed.\n");
			return -1;
		}
		//printf("database open successful.\n");

		printf("day is %d\n", iDay);
		printf("Channel number is %d\n", iChannel);
		iNum = rec_GetHDSnapDay(pstDb, 2011, 11, iDay, iChannel, 5, 1024, stSnapTime);
		//iNum = rec_GetHDSnapDay(pstDb, 2011, 7, 1, iChannel, 5, 1024, stSnapTime);
		printf("read number is %d\n", iNum);
		for (i=0; i<iNum; i++)
		{
			printf("type: %d\n", stSnapTime[i].m_iType);
			//printf("starttime: %.4d/%.2d/%.2d %.2d:%.2d:%.2d\n", stSnapTime[i].m_stStartTime.tm_year+1900, 
			//													 stSnapTime[i].m_stStartTime.tm_mon+1, 
			//													 stSnapTime[i].m_stStartTime.tm_mday, 
			//													 stSnapTime[i].m_stStartTime.tm_hour, 
			//													 stSnapTime[i].m_stStartTime.tm_min, 
			//													 stSnapTime[i].m_stStartTime.tm_sec);
			//printf("stoptime: %.4d/%.2d/%.2d %.2d:%.2d:%.2d\n", stSnapTime[i].m_stStopTime.tm_year+1900, 
			//													 stSnapTime[i].m_stStopTime.tm_mon+1, 
			//													 stSnapTime[i].m_stStopTime.tm_mday, 
			//													 stSnapTime[i].m_stStopTime.tm_hour, 
			//													 stSnapTime[i].m_stStopTime.tm_min, 
			//													 stSnapTime[i].m_stStopTime.tm_sec);
			printf("starttime is %d\n", stSnapTime[i].m_iStartTime);
			printf("stoptime is %d\n", stSnapTime[i].m_iStopTime);
		}

		printf("\n");
		
		sqlite3_close(pstDb);

		iChannel++;
		//if (iChannel >= 16)
		if (iChannel >= 32)
		{
			iChannel = 0;
			iDay++;
			if (iDay > 30)
			{
				iDay = 12;
			}
		}

		sleep(1);
		
	}

#endif

	return 0;
}

#endif


/*---------------------------end of the file----------------------------*/


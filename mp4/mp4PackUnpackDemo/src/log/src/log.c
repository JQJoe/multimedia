/*******************************************************************
�ļ���	  :Log.h
��˾	        :TIANDY
������	  :YP
��������:2009-09-01
��Ҫ����:��־ģ����غ�����ʵ��
�޸ļ�¼:
	��ƽ 2009-09-01 ����
	������ 2010-07-27 �����ִ��룬���ӳ�ʼ���Զ��������Բ��ַ���ֵ
			  ��ָ����ж�
******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <stdarg.h>
#include <pthread.h>
	   
#include <limits.h>
#include "public_def.h"
#include "libtiandy.h"
#include "log.h"
#include "td_errno.h"
#include "config.h"
#include "libfont.h"
#include "rtmsg.h"

#include "libdiskmnt.h" //add  for logpath
#include "libstorage.h" //add for logpath

#define LOG_TEMPLATE_FILE "%s/log_temp_%s.ini"
#define checkIsHZ(c) (/*(c < 0x00) || */(c > 0x7F))		
#define LOG_HEAD_INDEX 9999

static td_u8  uLogFilePath[FULL_PATH_LEN];//��־��¼�ļ�·��
static td_u32 u32LenFile ;//��־��¼�ļ�Ĭ�ϴ�С

static gen_TLogInfo g_TInfo;	//�洢�ļ���Ϣ
static pthread_mutex_t g_LogMutex; //���ļ���ȫ�ֱ������б���
static FILE * g_log_rec = NULL;		//��¼�ļ�
static FILE * g_log_que[LANG_ALL] = {NULL, NULL};		//��ѯ�ļ�
static GetUseInfo gGetUseInfoFun = NULL;


/*
*		@ zhangweiwei add  20120301 
*		@ ���Ƶ��дflash��ɵ����������logģ�����cache
*/

#define       	DEFAULT_LOG_CACHE_SIZE          200     //���� ��־����
#define 		CacheLock(q)	 	 pthread_mutex_lock(&q)
#define 		CacheUnLock(q)	     pthread_mutex_unlock(&q)
#define 		CacheLockInit(q)	 pthread_mutex_init(&q, NULL)
#define         CacheLockDestroy(q)	 pthread_mutex_destroy(&q)

static int g_CacheInit = 0;
static pthread_mutex_t CacheMux;  //cache ʹ���� 
static gen_TLog * stCache = NULL;
static volatile int g_iCacheIndex = 0;         //�ѻ�����Ϣ��

static td_u32 g_uiMinLevel = 0;
static td_s32 g_iSave = 0;
static td_u8  g_ucFileName[FULL_PATH_LEN];//��־��¼�ļ�·��
static td_s32 g_iClosed = 0;
static td_s32 g_iDiskNo = -1;
static td_s32 g_iInited = 0;
static td_s32 log_SetFileSize(td_u32 _usFileSize)//�ᵼ����־���
{
	td_s32 iRet = 0;

	g_TInfo.m_usFileSize = _usFileSize;
	iRet = log_Clear();
	if(iRet != ERR_LOG_SUCCESSFUL)
		return iRet;
	return ERR_LOG_SUCCESSFUL;
}
	
//����Cache
static int log_AllocCacheMem()
{
	if(g_CacheInit !=  0)
	{
		return td_failure;
	}
	
	stCache = (gen_TLog *)malloc(sizeof(gen_TLog) * DEFAULT_LOG_CACHE_SIZE);
	if(NULL == stCache)
	{
		td_printf(0x0, "log_AllocCacheMem error\n");
		return td_failure;
	}
	
	td_printf(0x0, "log_AllocCacheMem ok\n");
	g_CacheInit = 1;

	return td_success;
}


//����Cache 
static void log_FreeCacheMem()
{
	if(g_CacheInit != 1)
	{
		return;
	}
	
	g_CacheInit = 0;
	td_printf(0x0, "log_FreeCacheMem \n");
	free(stCache);

	return;
}

//дCache
static int log_WriteCacheMem(gen_TLog * _stLogItem)
{
	if(NULL == _stLogItem || stCache == NULL)
	{
		return td_failure;
	}

	int iRet;
	td_printf(0x0, "log_WriteCacheMem: id:%d\n", _stLogItem->m_gLogHead.m_uiTemInd);
	
	if(g_iCacheIndex >= DEFAULT_LOG_CACHE_SIZE)
	{
		if((iRet = log_fflushCacheMem(5L)) != td_success)
		{
			return td_failure;
		}
	}

	CacheLock(CacheMux);
	memmove(&stCache[g_iCacheIndex++], _stLogItem, sizeof(gen_TLog));
	CacheUnLock(CacheMux);
	
	td_printf(0x0, "log_WriteCacheMem id:%d ok\n", _stLogItem->m_gLogHead.m_uiTemInd);

	return td_success;
}

//���Cache 
static int log_ClearCacheMem()
{
	if(stCache == NULL)
	{
		return td_failure;
	}

	CacheLock(CacheMux);
	memset(stCache, 0, sizeof(stCache));
	g_iCacheIndex = 0;
	CacheUnLock(CacheMux);
	td_printf(0x0, "log_ClearCacheMem \n");
	
	return td_success;
}

// �޸��ļ�ͷ��������
td_s32 log_ChangeHead(gen_TLogHead* _pTHead, td_u32 _iIndex)
{
	if (NULL == _pTHead)
	{
		return ERR_LOG_FAILED;
	}
	_pTHead->m_usIndex = LOG_HEAD_INDEX;
	_pTHead->m_iTime = 1;
	_pTHead->m_iChannel = _iIndex;
	_pTHead->m_cLevel = LOG_LEVEL_DEBUG + 1;
	_pTHead->m_uiTemInd = 0;
	
	return ERR_LOG_SUCCESSFUL;
}

static td_s32 log_SetLevel(td_u32 _cLevel)
{
	td_printf(0, "set log lever %d\n", _cLevel);
	g_TInfo.m_cLevel = _cLevel;
	return ERR_LOG_SUCCESSFUL;
}

static td_s32 log_ScanLogFile()
{
	int oldtime ;
	int countInx,maxfilelen;
	int i, timeValue;
	//int iRet;
	gen_TLogHead stHead;
	int iStartUseTimeFlag = 0;
	int iNum = 0;
	
	if (NULL == g_log_rec)
	{
		return td_failure;
	}

/*	
	iRet = log_fflushCacheMem(5L);
	if(iRet != td_success)
	{
		return td_failure;
	}
*/

	if(-1 == fseek(g_log_rec, 0, SEEK_END))
	{
		return ERR_LOG_FAILED;
	}
	if(-1 == (countInx = ftell(g_log_rec)))
	{
		return ERR_LOG_FAILED;
	}
	maxfilelen = countInx / LOG_ONE_SIZE;
	td_printf(0,"------>existed log number = %d\n",maxfilelen);

	// �����ļ�ͷ������
	if(-1 == fseek(g_log_rec, 0, SEEK_SET))
	{
		return ERR_LOG_FAILED;
	}
	if ((iNum = fread(&stHead, sizeof(stHead), 1, g_log_rec)) != 1)
	{
		return ERR_LOG_FAILED;
	}
	iStartUseTimeFlag = 1;
	// �ļ�ͷ��ȷ�����ȡ���д������������
	if ((LOG_HEAD_INDEX == stHead.m_usIndex) && (1 == stHead.m_iTime))
	{
		i = stHead.m_iChannel;
		if (i <= maxfilelen)
		{
			iStartUseTimeFlag = 0;
			if(-1 == fseek(g_log_rec, i*LOG_ONE_SIZE, SEEK_SET))
			{
				return ERR_LOG_FAILED;
			}
			if (1 != fread(&stHead, sizeof(stHead), 1, g_log_rec))
			{
				return ERR_LOG_FAILED;
			}
			// �ж��Ƿ����ڽ��и��ǲ���
			if(stHead.m_iTime == 0)
			{
				g_TInfo.m_bCovered = 0;
			}
			else
			{
				g_TInfo.m_bCovered = 1;
			}
		}
	}
	if (iStartUseTimeFlag)
	{
		td_printf(0, "%s(%d): use time check", __func__, __LINE__);
		oldtime = 0;
		for(i = 0; i < maxfilelen; i++)
		{
			if(-1 == fseek(g_log_rec, i*LOG_ONE_SIZE+4, SEEK_SET))
			{
				return ERR_LOG_FAILED;
			}
			if(1 != fread(&timeValue, sizeof(td_s32), 1, g_log_rec))
			{
				return ERR_LOG_FAILED;
			}
			if(timeValue == 0)
			{
				g_TInfo.m_bCovered	 = 0;
				break;
			}
			if (timeValue >= oldtime) 
			{
				oldtime = timeValue;
			}
			else
			{
				g_TInfo.m_bCovered	 = 1;
				break;
			}
		}
	}
	if(i == maxfilelen)
	{
		g_TInfo.m_bCovered   = 0;
	}
	g_TInfo.m_usIndex = i;
	
	td_printf(0x12345678, "=====g_TInfo.m_usIndex:%d, maxfilelen:%d\n",g_TInfo.m_usIndex, maxfilelen);
	g_TInfo.m_usFileSize = maxfilelen*LOG_ONE_SIZE/1024;
	
	if(-1 == fseek(g_log_rec, 0, SEEK_END))
	{
		return ERR_LOG_FAILED;
	}
	return ERR_LOG_SUCCESSFUL;
}

static td_s32 log_Set_Init(td_u32 _iMinLevel, td_u32 _iFileSize)
{	
	td_s32 iRet;
	
	if (_iMinLevel < LOG_LEVEL_MIN || _iMinLevel > LOG_LEVEL_SET_ALL )
		return ERR_LOG_WRONG_PARAM;

	if(g_iDiskNo >= 0 )
	{
		if((_iFileSize < LOG_MIN_FILE_SIZE) || (_iFileSize > LOG_MAX_FILE_SIZE))
			return ERR_LOG_WRONG_PARAM;
	}
	else
	{
		if(_iFileSize != LOG_FLASH_FILE_SIZE)
			return ERR_LOG_WRONG_PARAM;
	}
	iRet  = log_SetLevel(_iMinLevel);
	if(iRet != ERR_LOG_SUCCESSFUL)
		return iRet;
	iRet = log_SetFileSize(_iFileSize);
	if(iRet!= ERR_LOG_SUCCESSFUL)
		return iRet;
	if (td_success != Cfg_sLog(_iMinLevel, _iFileSize))
	{
		return ERR_LOG_FAILED;
	}

	return ERR_LOG_SUCCESSFUL;
}

static td_s32 log_OpenFile()
{
	//td_s32 iRet = td_failure;
	td_s32 s32I = 0;
	td_u8  aszFileName[256];
	td_u32 iLogFileSize = 0;
	const TDiskInfo *pstDiskInfor = NULL;
	td_s32 iDiskNo = 0;
	td_s32 i = 0;
	td_s32 iHaveFileFlag = 0;
	
	if(1 == g_iSave)
	{
		if (1 == Cfg_gLogWriteDiskEnable())
		{
			//add  �����Ӳ�����log�ļ�д��Ӳ���ϣ����û��Ӳ����д��flash�
			if(disk_GetDiskNum(SATA) > 0)
			{
				if (disk_GetDistIsExist() >= 0) //�ų�������
				{
					pstDiskInfor = disk_GetDiskInfoArray();
					for (i = 0; i < MAX_SATA_NUM; i++)
					{
						td_printf(0, "%s(%d)pstDiskInfor + %d)->m_eUsage=%d", __func__, __LINE__, i, (pstDiskInfor + i)->m_eUsage);
						if ((pstDiskInfor + i)->m_eState >= STATE_MOUNTED)
						{
							iDiskNo = (pstDiskInfor + i)->m_uiDiskNo;
							
							if('/' == *g_ucFileName)
							{
								sprintf((char *)aszFileName,"%s/%d/0%s", SATA_PATH, iDiskNo, g_ucFileName);
							}
							else
							{
								sprintf((char *)aszFileName,"%s/%d/0/%s", SATA_PATH, iDiskNo, g_ucFileName);
							}
							memcpy(uLogFilePath, aszFileName, sizeof(uLogFilePath));
							iHaveFileFlag = 1;
							g_iDiskNo = (pstDiskInfor + i)->m_uiDiskNo;
							break;
						}
					}
				}
			}
		}

		if (0 == iHaveFileFlag)
		{
			if('/' == *g_ucFileName)
			{
				sprintf((char *)aszFileName,"%c%s", '.', g_ucFileName);
			}
			else
			{
				sprintf((char *)aszFileName,"%s%s", "./", g_ucFileName);
			}
			memcpy(uLogFilePath, g_ucFileName, sizeof(uLogFilePath));
			
			u32LenFile = LOG_FLASH_FILE_SIZE;		//�ļ����д��flash�ϣ�Ĭ��Ϊ100K
			g_TInfo.m_usFileSize = u32LenFile;
		}

	    td_printf(0,"==================================\r\n");
	    td_printf(0,"log file : %s begin\r\n",aszFileName);
	    td_printf(0,"==================================\r\n");
		
	    for(s32I = strlen((char *)aszFileName) - 1; s32I >= 0; s32I--)
	    {
	        if('/' == aszFileName[s32I])
	        {
	            aszFileName[s32I] = '\0';
	            break;
	        }
	    }
		
	    //��log �ļ�·��
	    if(s32I >= 0)
	    {
			make_dir(aszFileName);//yp20100112��������ǰlogĿ¼
      		aszFileName[s32I] = '/';
	    }
	   
	    td_printf(0,"==================================\r\n");
	    td_printf(0,"log file : %s end\r\n",aszFileName);
	    td_printf(0,"==================================\r\n");
	
	}
	
	g_TInfo.m_uLogFileName = (td_u8 *)strdup((char *)aszFileName);
	g_log_rec = fopen((char *)g_TInfo.m_uLogFileName,"r+");
	td_printf(0, "log file len = %d/%d", u32LenFile, g_TInfo.m_usFileSize);
	
	if(g_log_rec != NULL)
	{
	#if 1
		struct stat stLogFile;
		stat((char *)uLogFilePath, &stLogFile);
		iLogFileSize = stLogFile.st_size;
		if(iLogFileSize > u32LenFile*1024)		//liuyang modsify 20130603
		{
			log_SetFileSize(u32LenFile);
		}
#endif
		log_ScanLogFile();
		log_SetLevel(g_uiMinLevel);
	}
	else
	{
		g_log_rec = fopen((char *)g_TInfo.m_uLogFileName,"w+");
		if(g_log_rec == NULL)
		{
			td_printf(0,"file open failed!\n");
			return ERR_LOG_FAILED;
		}
		log_Set_Init(g_uiMinLevel, u32LenFile);
	}
	
	td_printf(0,"----->g_TInfo.m_usFileSize= %d g_TInfo.m_usIndex= %d \
		g_TInfo.m_bCovered= %d\n",
		g_TInfo.m_usFileSize,g_TInfo.m_usIndex,g_TInfo.m_bCovered);

	return ERR_LOG_SUCCESSFUL;
}

td_s32 log_HeadInit(gen_TLogHead* _pTHead)
{
	if (NULL == _pTHead)
	{
		return ERR_LOG_FAILED;
	}
	
	return log_ChangeHead(_pTHead, 1);
}

static td_s32 log_DoClear()
{
    td_s32 iRet = 0;
    td_s32 usFileSize;
    gen_TLogHead stHead;

    if (NULL == g_log_rec)
    {
        return ERR_LOG_FAILED;
    }

    fseek(g_log_rec,0,SEEK_SET);
    if((iRet = truncate((char *)g_TInfo.m_uLogFileName,0)) != 0)        //ע��g_ifd
    {
        return ERR_LOG_FAILED;
    }
    fseek(g_log_rec,0,SEEK_SET);
    g_TInfo.m_usIndex = 1;          // ������1��ʼ
    g_TInfo.m_bCovered = 0;
    usFileSize = g_TInfo.m_usFileSize;
    if((iRet = truncate((char *)g_TInfo.m_uLogFileName,usFileSize*1024)) != 0)  //ע��g_ifd
    {
        td_printf(0, "%s : truncate error!!!\n", __func__);
        return ERR_LOG_FAILED;
    }
    fseek(g_log_rec,0,SEEK_SET);
    // ����ļ�ͷ
    log_HeadInit(&stHead);
    fwrite(&stHead, 1, sizeof(gen_TLogHead), g_log_rec);
    fflush(g_log_rec);
    
    fseek(g_log_rec, LOG_ONE_SIZE, SEEK_SET);
    return ERR_LOG_SUCCESSFUL;
}

td_s32 log_Clear()
{
	td_s32 iRet = 0;
	
	log_ClearCacheMem();
	
	pthread_mutex_lock(&g_LogMutex);
    iRet = log_DoClear();
	pthread_mutex_unlock(&g_LogMutex);
	return iRet;
}


int log_CheckFileSize()
{
	struct stat stLogFile = {0};
	int iLogFileSize = u32LenFile * 1024;
	int iRet = -1;
    
    iRet = stat((char *)uLogFilePath, &stLogFile);
    if(0 != iRet)
    {
        return td_failure;
    }

    iLogFileSize = stLogFile.st_size;    
    if(iLogFileSize > u32LenFile * 1024)
    {
        td_printf(0, "%s %d: iLogFileSize=%d\r\n", __func__,__LINE__, iLogFileSize);

        g_TInfo.m_usFileSize = u32LenFile;
        log_ClearCacheMem();
        if (log_DoClear() != ERR_LOG_SUCCESSFUL)
        {
            return td_failure;
        }
    }
    return td_success;
}

//��ϴCache
int log_fflushCacheMem(unsigned long _param)
{
	gen_TLogHead stHead;
	
	int i = 0;
	int iRet = -1;
	
	if(stCache == NULL )
	{
		return td_failure;
	}

	if (1 == g_iClosed || NULL == g_log_rec)
	{
		return td_failure;
	}

	#if 0//���̴���־·���л��߼������߼�
	iRet = access((char *)uLogFilePath, F_OK | W_OK);
	if (-1 == iRet)
	{
		iRet = log_ChangePath(g_iDiskNo, 2);
		if (iRet != td_success)
		{
			return td_failure;
		}
	}
	#endif

	if(g_iCacheIndex == 0)
	{
        return log_CheckFileSize();
	}

	iRet = fseek(g_log_rec, g_TInfo.m_usIndex*LOG_ONE_SIZE, SEEK_SET);//��λ��д��λ��
	if (-1 == iRet)
	{
        log_CheckFileSize();
		return td_failure;
	}

	CacheLock(CacheMux);
	while(g_iCacheIndex > 0)
	{
		#if 0//���̴���־·���л��߼������߼�
		iRet = access((char *)uLogFilePath, F_OK | W_OK);
		if (-1 == iRet)
		{
			iRet = log_ChangePath(g_iDiskNo, 2);
			if (iRet != td_success)
			{
				CacheUnLock(CacheMux);
				return ERR_LOG_FAILED;
			}

		}
		#endif
		
		stCache[i].m_gLogHead.m_usIndex = g_TInfo.m_usIndex;		// ������ÿ������
		if (sizeof(gen_TLog) != fwrite(&stCache[i++],  1, sizeof(gen_TLog), g_log_rec))
		{
			CacheUnLock(CacheMux);
			return ERR_LOG_FAILED;
		}
		g_TInfo.m_usIndex++;
		// �������־�������޵�������֣���Ҫѭ������
		if(g_TInfo.m_usIndex >= g_TInfo.m_usFileSize*1024/LOG_ONE_SIZE)
		{
			g_TInfo.m_bCovered = td_true;
			g_TInfo.m_usIndex = 1;			// ���Ǻ��1��ʼ
			fseek(g_log_rec, g_TInfo.m_usIndex*LOG_ONE_SIZE, SEEK_SET);//��λ��д��λ��
		}
		g_iCacheIndex--;
		td_printf(0x0, "log_fflushCacheMem:g_iCacheIndex:%d \n", g_iCacheIndex);
		if(i > DEFAULT_LOG_CACHE_SIZE)
		{
			g_iCacheIndex = 0;
			break;
		}
	}
	// д���ļ�ͷ
	log_ChangeHead(&stHead, g_TInfo.m_usIndex);
	fseek(g_log_rec, 0, SEEK_SET);
	fwrite(&stHead, 1, sizeof(gen_TLogHead), g_log_rec);
	
	CacheUnLock(CacheMux);
	fflush(g_log_rec);
	
    log_CheckFileSize();
	return td_success;
}

//---------------------- zhangweiwei 20120301 add End -------------------------



static td_s32 log_QuePara(td_u32* _pcLevel, td_u32* _pusFileSize)
{
	*_pcLevel = g_TInfo.m_cLevel;
	*_pusFileSize = g_TInfo.m_usFileSize;
	return ERR_LOG_SUCCESSFUL;
}

td_s32 log_Get(td_u32 * _piMinLevel, td_u32 * _piFileSize)
{
	td_u32  cLevel;
	td_u32 usFileSize;
	
	if(ERR_LOG_SUCCESSFUL != log_QuePara(&cLevel, &usFileSize))
		return ERR_LOG_FAILED;
	*_piMinLevel = cLevel;
	*_piFileSize = usFileSize;

	td_printf(0, "log level = %d, size = %d\n", cLevel, usFileSize);
	return ERR_LOG_SUCCESSFUL;
}

td_s32 log_Set(td_u32 _iMinLevel, td_u32 _iFileSize)
{	
	td_s32 iRet;
	td_s32 iLenChanged = 1;
	td_s32 iTmpLevel = 0;
	td_s32 iTmpLen = 0;
	td_s32 blSave = 1;
	char   cLogName[64]="";
	
	if ((_iMinLevel < LOG_LEVEL_MIN || _iMinLevel > LOG_LEVEL_SET_ALL )|| \
		_iFileSize < LOG_MIN_FILE_SIZE || _iFileSize > LOG_MAX_FILE_SIZE)
	{
		return ERR_LOG_WRONG_PARAM;
	}
	iRet  = log_SetLevel(_iMinLevel);
	if(iRet != ERR_LOG_SUCCESSFUL)
		return iRet;

	//zhangweiwei add 20120301
	if((iRet = log_fflushCacheMem(5L)) != td_success)
	{
		return ERR_LOG_FAILED;
	}

	if(g_TInfo.m_usFileSize != _iFileSize)
	{
		if(g_TInfo.m_usFileSize < _iFileSize)
		{
			pthread_mutex_lock(&g_LogMutex);
			fseek(g_log_rec,0,SEEK_SET);
			if((iRet = truncate((char *)g_TInfo.m_uLogFileName,_iFileSize*1024)) != 0)	//ע��g_ifd
			{
				td_printf(0, "%s : truncate error! iRet = %d\n", __func__, iRet);
				pthread_mutex_unlock(&g_LogMutex);
				return ERR_LOG_FAILED;
			}
			fseek(g_log_rec,0,SEEK_SET);
			pthread_mutex_unlock(&g_LogMutex);
			g_TInfo.m_usFileSize = _iFileSize;
		}
		else if(g_TInfo.m_usFileSize > _iFileSize)
		{
			iRet = log_SetFileSize(_iFileSize);
			if(iRet!= ERR_LOG_SUCCESSFUL)
				return iRet;
		}
		u32LenFile = _iFileSize;
	}
	else
	{
		td_printf(0, "%s :%d, Log file size not changed!\n", __func__, __LINE__);
		iLenChanged = 0;
	}

	if(!iLenChanged)
	{
		Cfg_gLog(&iTmpLevel, &iTmpLen,&blSave,(td_u8*)cLogName);			
	}
	else
		iTmpLen = _iFileSize;
	
	//if (td_success != Cfg_sLog(_iMinLevel, _iFileSize))
	if (td_success != Cfg_sLog(_iMinLevel, iTmpLen))
	{
		return ERR_LOG_FAILED;
	}

	return ERR_LOG_SUCCESSFUL;
}

//for test add by liuyang_dvr
td_s32 log_Write(td_u32 arg, td_u32 _cLevel, td_u32 _iChannelNo, td_u32 _temID, td_u8* _pcMsg, ...)
{
	va_list apLogWrite;
	td_s32 iRet;
	gen_TLog TLogTemp;

	if (NULL == g_log_rec)
	{
		return ERR_LOG_FAILED;
	}
	
	memset(&TLogTemp,'\0',sizeof(TLogTemp));	//��0����'\0'
	if (((g_TInfo.m_cLevel >> _cLevel) & 0x1) != 1)		//ע����־����
	{
		return ERR_LOG_WRONG_PARAM;//�ȼ�У��
	}
	
	if(_pcMsg != NULL)
	{
		if(strlen((char *)_pcMsg) > (MAX_LOG_WRITE_PARA_STRING_TYPE_SIZE - 1))
		{
			return ERR_LOG_WRONG_PARAM;
		}
	}
	pthread_mutex_lock(&g_LogMutex);
	if(g_TInfo.m_usIndex >= g_TInfo.m_usFileSize*1024/LOG_ONE_SIZE)
	{
		g_TInfo.m_bCovered = td_true;
		g_TInfo.m_usIndex = 1;			// ���Ǻ��1��ʼ
	}
	TLogTemp.m_gLogHead.m_usIndex = g_TInfo.m_usIndex;
	TLogTemp.m_gLogHead.m_iTime    = time((time_t*)NULL);
	TLogTemp.m_gLogHead.m_iChannel = _iChannelNo;
	TLogTemp.m_gLogHead.m_cLevel   = _cLevel;
	TLogTemp.m_gLogHead.m_uiTemInd = _temID;
	if((NULL == gGetUseInfoFun) || 
		(td_failure == gGetUseInfoFun(arg, (char *)TLogTemp.m_gLogHead.m_UserName, sizeof(TLogTemp.m_gLogHead.m_UserName))))
	{
		TLogTemp.m_gLogHead.m_UserName[0] = '0';
	}
	
	if(_pcMsg != NULL)
	{
		va_start(apLogWrite, _pcMsg);
	//	iRet = vsprintf(TLogTemp.m_uMsgParaStr, _pcMsg, apLogWrite);
		iRet = vsnprintf((char *)TLogTemp.m_uMsgParaStr, MSG_SIZE - 1 , (char *)_pcMsg, apLogWrite);
		TLogTemp.m_uMsgParaStr[MSG_SIZE - 1] = 0;
		//ע��_pcMsg��apLogWrite�Ĵ�СԽ��
		va_end(apLogWrite);
		if (iRet < 0)
		{
			goto fail;
		}
	}
	else
	{
//		td_printf(0,"===the logWrite input is NULL===\r\n");
	}

	if((iRet = log_WriteCacheMem(&TLogTemp)) != td_success)
	{
		goto fail;
	}

	pthread_mutex_unlock(&g_LogMutex);
	return ERR_LOG_SUCCESSFUL;

fail:
	pthread_mutex_unlock(&g_LogMutex);
	return ERR_LOG_FAILED;
	
}

static td_s32 log_Index2Mes(td_u32 _temID, td_u8* _pcMsg, td_s32 blang)
{
	td_u32 temID=0,pcNum=0,iRet=0;
	td_u8  temMsg[1024];
	td_u8 *pcWord = NULL;// *str = temMsg, *p = temMsg;
	char *pcDelim = TAB_STR;//�ո��ð����Ϊ��ָ���
	FILE * pfLogQue = NULL;

	td_assert((blang >= LANG_EN || blang < LANG_ALL), td_failure); //modify by yjq 20110831
	pfLogQue = g_log_que[blang];
	if(!pfLogQue)
	{
		td_printf(0, "%s , pfLogQue failed", __func__);
		return ERR_LOG_FAILED;
	}

	memset(temMsg,'\0',MAX_LOG_TEMPLATE_LEN);
	iRet = fseek(pfLogQue, 0, SEEK_SET);
	if(iRet == -1)
	{
		td_printf(0, "%s , fseek failed", __func__);
		return ERR_LOG_FAILED;
	}	
	while ((fgets((char *)temMsg,MAX_LOG_TEMPLATE_LEN,pfLogQue))!= NULL)	//ע��MSG�Ĵ�С
	{	
		if(!isdigit(temMsg[0]))
			continue;
		
		pcWord = (td_u8 *)strtok((char *)temMsg, pcDelim);//ȡ�õ�һ�����ʵĵ�ַ
		//add by ssn 2010/12/10
		if (pcWord == NULL)
		{
			continue;
		}
		//add end 
		temID  = (td_u32)atoi((char *)pcWord);
		pcWord = (td_u8 *)strtok(NULL, pcDelim);
		//add by ssn 2010/12/10
		if (pcWord == NULL)
		{
			continue;
		}
		//add end
		pcNum = (td_u32)strlen((char *)pcWord) - 1;
		while((pcWord[pcNum]== '\n')||(pcWord[pcNum]== '\r'))
		{
			pcWord[pcNum] ='\0'; 
			pcNum--;
		}
		if(temID == _temID)
		{
			strncpy((char *)_pcMsg, (char *)pcWord, LOG_ONE_SIZE - 1);	
			_pcMsg[LOG_ONE_SIZE - 1] = 0;
//			funlockfile(pfLogQue);
			return ERR_LOG_SUCCESSFUL;
		}
	}
//	funlockfile(pfLogQue);
	return ERR_LOG_FAILED;
}

// ����20120522 ��ѯ��־ģ���Ƿ���Խ��ж�����
static td_s32 log_CheckLog(td_s32 _bLang)
{
	td_s32 iRet = 0;
	FILE * pfLogQue = NULL;
	td_u8  temMsg[1024];

	if (_bLang >= LANG_ALL)
	{
		return ERR_LOG_FAILED;
	}
	pfLogQue = g_log_que[_bLang];
	if (NULL == pfLogQue)
	{
		return ERR_LOG_FAILED;
	}
	iRet = fseek(pfLogQue, 0, SEEK_SET);
	if(iRet == -1)
	{
		td_printf(0, "%s , fseek failed", __func__);
		return ERR_LOG_FAILED;
	}	
	if (NULL == fgets((char *)temMsg,MAX_LOG_TEMPLATE_LEN,pfLogQue))	//ע��MSG�Ĵ�С
	{
		td_printf(0, "==============%s , fgets failed==================", __func__);
		td_printf(0, "error : (%d)%s", errno, strerror(errno));
		return ERR_LOG_FAILED;
	}
	return ERR_LOG_SUCCESSFUL;
}

static td_s32 log_ParseLog(td_u8* _pcSource, TLogInfo* _stInfo, td_s32 _bLang)
{
	td_u8 * srcTmp = _pcSource;
	td_s32  tag = 0;
	td_u8 * puMsg = NULL;
	td_u8 *dstMsg = NULL;
	td_u8   pcDelim = TAB_CHAR;
	td_u8   pcMsg[LOG_ONE_SIZE];
	td_u8 strMsg[1024];

	puMsg = pcMsg;
	memset(puMsg,'\0',LOG_ONE_SIZE);
	srcTmp += LOG_HEAD_SIZE;
	if(ERR_LOG_SUCCESSFUL != log_Index2Mes(_stInfo->m_gLogHead.m_uiTemInd, puMsg, _bLang))
	{
		return ERR_LOG_FAILED;
	}

	dstMsg = strMsg;
	
	while (*puMsg)
	{
		switch (*puMsg) 
		{
			case '%':
				tag = 1;
				puMsg++;
				break;
			case 's':			   // string 
				if (tag ==1)
					{
						while((*srcTmp != pcDelim)&&(*srcTmp != '\0'))
						{
							*dstMsg++ = *srcTmp++;
						};
						srcTmp++;
						tag = 0;
						puMsg++;
					}
				else
					{
						*dstMsg++ = *puMsg++;
					}
				break;
			case 'd':			   //int
				if (tag ==1)
					{
						while((*srcTmp != pcDelim)&&(*srcTmp != '\0'))
						{
							*dstMsg++ = *srcTmp++;
						};
						srcTmp++;
						tag = 0;
						puMsg++;
					}
				else
					{
						*dstMsg++ = *puMsg++;
					}
				break;
			case 'X':			   //int
				if (tag ==1)
					{
						while((*srcTmp != pcDelim)&&(*srcTmp != '\0'))
						{
							*dstMsg++ = *srcTmp++;
						};
						srcTmp++;
						tag = 0;
						puMsg++;
					}
				else
					{
						*dstMsg++ = *puMsg++;
					}
				break;
			default:
				if(tag == 0)
					*dstMsg++ = *puMsg++;
				else
					puMsg++;
				break;
		}
	}
	*dstMsg = '\0';

	strncpy((char *)_stInfo->m_cContent, (char *)strMsg, MAX_LOG_MSG_LEN - 1);
	_stInfo->m_cContent[MAX_LOG_MSG_LEN - 1] = 0;
	return ERR_LOG_SUCCESSFUL;
}

// ����20120522 �ر���־ģ��
static td_s32 log_CloseLogQue()
{
	td_s32 i = 0;
	for (i=0; i<LANG_ALL; i++) 
	{
		if(g_log_que[i])
		{
			fclose(g_log_que[i]);	
			g_log_que[i] = NULL;
		}
	}
	return ERR_LOG_SUCCESSFUL;
}

// ����־ģ��
// ����20120522 �����˺�����������
static td_s32 log_OpenLogQue()
{
	#if 1	//modiy by yjq 20110831
	td_s32 i;
	td_s8 cTempBuf[64] = {0};			// 20120522 ���壬��ֹԽ��
	td_s32 iLogOpenCnt = LANG_ALL;
	//0-en 1-ch 2-tch 3-kor 4-span 5- ita Ϊ������SDK���ݣ�en ��ch��ֵ�������л�������෴��
	char *cLangType[LANG_ALL] = {"en","ch","tch","kor","span","ita"}; 
	td_s8 cDir[32] = {0};
	GetCurGuiLangDir((char *)cDir);
	td_printf(0,"======log++++cDir:%s\n", cDir);
	for (i=0; i<LANG_ALL; i++)
	{
		memset(cTempBuf, 0, sizeof(cTempBuf));
		sprintf((char *)cTempBuf, LOG_TEMPLATE_FILE, cDir, cLangType[i]);
		if((g_log_que[i] = fopen((char *)cTempBuf, "r")) == NULL)
		{
			iLogOpenCnt--;
		}
	}
	if (iLogOpenCnt < 1)
	{
		fclose(g_log_rec);
		g_log_rec = NULL;
		td_printf(0, "Open None Template File fail!\n");
		return ERR_LOG_FAILED;
	}
	#else
	if((g_log_que[LANG_EN]= fopen("log_template_en.ini","r"))==NULL)
	{
		td_printf(0, "open EN TEMPLATE FILE fail!\n");

		fclose(g_log_rec);
		g_log_rec = NULL;
		return ERR_LOG_FAILED;
	}
	if((g_log_que[LANG_CH]= fopen("log_template_ch.ini","r"))==NULL)
	{
		td_printf(0, "open CH TEMPLATE FILE fail!\n");

		fclose(g_log_rec);
		g_log_rec = NULL;		
		return ERR_LOG_FAILED;
	}
	#endif
	return ERR_LOG_SUCCESSFUL;
}

td_s32 log_Query(TLogQuery* _stQ)
{
	td_u8	cBuffer[LOG_ONE_SIZE];
	TLogInfo	stTmpInfo;
	gen_TLogHead TLogHead;
	td_s32	usIndex;
	td_s32 i, iRet, iLen;
	td_s32 iConut = 0;
	td_s32 iMaxCount = 0;
	td_s32 iStartIndex = 0;
	FILE* fp = NULL;

	if (NULL == g_log_rec)
	{
		return ERR_LOG_FAILED;
	}

	//zhangweiwei add 20120301
	//��ѯʱflush Cache
	if((iRet = log_fflushCacheMem(5L)) != td_success)
	{
		return ERR_LOG_FAILED;
	}
	
	memset(cBuffer,0,LOG_ONE_SIZE);
	memset(&stTmpInfo,0,sizeof(stTmpInfo));
	memset(&TLogHead,0,sizeof(TLogHead));
	
	if (_stQ == NULL || \
		(_stQ->m_iLevel != LOG_LEVEL_ALL && \
		(_stQ->m_iLevel < LOG_LEVEL_MIN || \
		_stQ->m_iLevel > (LOG_LEVEL_NUM - 1))))
	{
		return ERR_LOG_WRONG_PARAM;
	}
	
	if(_stQ->m_iStartTime >= _stQ->m_iStopTime)
	{
		return ERR_LOG_WRONG_PARAM;
	}
	_stQ->m_iShowNum = 0;
	_stQ->m_iTotalNum = 0;

	if ((fp = fopen((char *)g_TInfo.m_uLogFileName, "r")) == NULL)
	{
		td_perror("Open log file failed!");
		return ERR_LOG_FAILED;
	}

	iMaxCount = g_TInfo.m_usFileSize * 1024 / LOG_ONE_SIZE;
	
	if(g_TInfo.m_bCovered)
	{
		iConut = iMaxCount;
		iStartIndex = g_TInfo.m_usIndex + iMaxCount;
	}
	else
	{
		iConut = g_TInfo.m_usIndex;
		iStartIndex = g_TInfo.m_usIndex;
	}
	td_printf(0, "the index is  %d�� cover:%d\n", iStartIndex,g_TInfo.m_bCovered );

	// ����20120522�������־ģ���Ƿ���Զ�����������ܶ��������´�ģ��
	if (ERR_LOG_SUCCESSFUL != log_CheckLog(_stQ->m_blLang))
	{
		log_CloseLogQue();
		iRet = log_OpenLogQue();
		if (ERR_LOG_SUCCESSFUL != iRet)
		{
			td_printf(0, "Open LogQue failed!");
			fclose(fp);
			return iRet;
		}
		// ��¼������־20120523 ����
		char logmsg[128];
		snprintf(logmsg,127,"log query error, repair"); 
		WRITE_LOG_DebugInfo(LOG_LEVEL_DEBUG, (td_u8*)logmsg);
	}

	for (i = 0; i < iMaxCount; i++)
	{
		usIndex = (--iStartIndex) % iMaxCount;

		// ���ļ�ͷ���˵�
		if (0 == usIndex)
		{
			continue;
		}

		if (usIndex < 0)
		{
			break;
		}
		
		iRet = fseek(fp, usIndex * LOG_ONE_SIZE, SEEK_SET);
		if(iRet == -1)
		{
			td_printf(0, "log query error1 %d", usIndex);
			fclose(fp);
			return ERR_LOG_FAILED;
		}
		if (LOG_ONE_SIZE != fread(cBuffer, 1, LOG_ONE_SIZE, fp))
		{
			td_printf(0, "log query error2");
			fclose(fp);
			return ERR_LOG_FAILED;
		}
		
		memcpy(&TLogHead, cBuffer, sizeof(gen_TLogHead));

		if(TLogHead.m_usIndex == LOG_DEL_FLAG)
			continue;
		stTmpInfo.m_gLogHead.m_usIndex = TLogHead.m_usIndex;
		stTmpInfo.m_gLogHead.m_iTime = TLogHead.m_iTime;
		stTmpInfo.m_gLogHead.m_iChannel = TLogHead.m_iChannel;
		stTmpInfo.m_gLogHead.m_cLevel = TLogHead.m_cLevel;
		stTmpInfo.m_gLogHead.m_uiTemInd = TLogHead.m_uiTemInd;
		
		if(_stQ->m_iChannel == CHANNEL_ALL || _stQ->m_iChannel == stTmpInfo.m_gLogHead.m_iChannel)
		{
			if (_stQ->m_iLevel == LOG_LEVEL_ALL || _stQ->m_iLevel == stTmpInfo.m_gLogHead.m_cLevel)
			{
				if (stTmpInfo.m_gLogHead.m_iTime >= _stQ->m_iStartTime && stTmpInfo.m_gLogHead.m_iTime <= _stQ->m_iStopTime)
				{	
					if ((_stQ->m_iShowNum < MAX_LOG_PAGE_SIZE)&&(_stQ->m_iShowNum < _stQ->m_iPageSize) && (_stQ->m_iTotalNum >= _stQ->m_iPageSize * _stQ->m_iPageNo))
					{
						_stQ->m_stInfo[_stQ->m_iShowNum].m_gLogHead.m_usIndex = stTmpInfo.m_gLogHead.m_usIndex;
						_stQ->m_stInfo[_stQ->m_iShowNum].m_gLogHead.m_iTime = stTmpInfo.m_gLogHead.m_iTime;
						_stQ->m_stInfo[_stQ->m_iShowNum].m_gLogHead.m_cLevel = stTmpInfo.m_gLogHead.m_cLevel;
						_stQ->m_stInfo[_stQ->m_iShowNum].m_gLogHead.m_iChannel = stTmpInfo.m_gLogHead.m_iChannel;
						
						if (log_ParseLog(cBuffer, &stTmpInfo, _stQ->m_blLang) == ERR_LOG_SUCCESSFUL)
							memcpy(_stQ->m_stInfo[_stQ->m_iShowNum].m_cContent, stTmpInfo.m_cContent, MAX_LOG_MSG_LEN);
						else
						{
							td_printf(0, "query error!\n");
							continue;
						}
						_stQ->m_iShowNum++;
					}
					_stQ->m_iTotalNum++;
				}
			}
		}
	}

	fclose(fp);
	for (i = 0; i < _stQ->m_iShowNum; i++)
	{
		#if 0
		//���������Ϊ����
		_stQ->m_stInfo[i].m_cContent[MAX_LOG_LEN] = '\0';
		iLen = MAX_LOG_LEN - 1;
		
		while(checkIsHZ(_stQ->m_stInfo[i].m_cContent[iLen]))
		{
			iLen--;
			if (iLen < 0)
			{
				break;
			}
		}
		iCount = (MAX_LOG_LEN - 1) - iLen;
		if (iCount % 2 == 1)
		{
			_stQ->m_stInfo[i].m_cContent[MAX_LOG_LEN - 1] = '\0';
		}
		#else
		_stQ->m_stInfo[i].m_cContent[MAX_LOG_LEN] = '\0';
		iLen = 0;
		while(_stQ->m_stInfo[i].m_cContent[iLen])
		{
			td_s32 nBytes = GetUniCharBytes(_stQ->m_stInfo[i].m_cContent + iLen);
			
			if(iLen + nBytes > MAX_LOG_LEN)
			{
				td_s32 j = 0;
				for(j=0; j<(MAX_LOG_LEN - iLen); j++)
				{
					_stQ->m_stInfo[i].m_cContent[MAX_LOG_LEN - j - 1] = '\0';
				}
			}
			else
			{
				iLen += nBytes;
			}
		}
		
		#endif
	}
	return ERR_LOG_SUCCESSFUL;
}

td_s32 log_QueryEx(TLogQuery* _stQ)

{
	td_u8	cBuffer[LOG_ONE_SIZE];
	TLogInfo	stTmpInfo;
	gen_TLogHead TLogHead;
	td_s32	usIndex;
	td_s32 i, iRet, iLen;
	td_s32 iConut = 0;
	td_s32 iMaxCount = 0;
	td_s32 iStartIndex = 0;
	FILE* fp = NULL;

	if (NULL == g_log_rec)
	{
		return ERR_LOG_FAILED;
	}

	//zhangweiwei add 20120301
	//��ѯʱflush Cache
	if((iRet = log_fflushCacheMem(5L)) != td_success)
	{
		return ERR_LOG_FAILED;
	}
	
	memset(cBuffer,0,LOG_ONE_SIZE);
	memset(&stTmpInfo,0,sizeof(stTmpInfo));
	memset(&TLogHead,0,sizeof(TLogHead));
	
	if (_stQ == NULL || \
		(_stQ->m_iLevel != LOG_LEVEL_ALL && \
		(_stQ->m_iLevel < LOG_LEVEL_MIN || \
		_stQ->m_iLevel > (LOG_LEVEL_NUM - 1))))
	{
		return ERR_LOG_WRONG_PARAM;
	}
	
	if(_stQ->m_iStartTime >= _stQ->m_iStopTime)
	{
		return ERR_LOG_WRONG_PARAM;
	}
	_stQ->m_iShowNum = 0;
	_stQ->m_iTotalNum = 0;

	if ((fp = fopen((char *)g_TInfo.m_uLogFileName, "r")) == NULL)
	{
		td_perror("Open log file failed!");
		return ERR_LOG_FAILED;
	}

	iMaxCount = g_TInfo.m_usFileSize * 1024 / LOG_ONE_SIZE;
	
	if(g_TInfo.m_bCovered)
	{
		iConut = iMaxCount;
		iStartIndex = g_TInfo.m_usIndex + iMaxCount;
	}
	else
	{
		iConut = g_TInfo.m_usIndex;
		iStartIndex = g_TInfo.m_usIndex;
	}
	td_printf(0, "the index is  %d�� cover:%d\n", iStartIndex,g_TInfo.m_bCovered );

	// ����20120522�������־ģ���Ƿ���Զ�����������ܶ��������´�ģ��
	if (ERR_LOG_SUCCESSFUL != log_CheckLog(_stQ->m_blLang))
	{
		log_CloseLogQue();
		iRet = log_OpenLogQue();
		if (ERR_LOG_SUCCESSFUL != iRet)
		{
			td_printf(0, "Open LogQue failed!");
			fclose(fp);
			return iRet;
		}
		// ��¼������־20120523 ����
		char logmsg[128];
		snprintf(logmsg,127,"log query error, repair"); 
		WRITE_LOG_DebugInfo(LOG_LEVEL_DEBUG, (td_u8*)logmsg);
	}

	for (i = 0; i < iMaxCount; i++)
	{
		usIndex = (--iStartIndex) % iMaxCount;

		// ���ļ�ͷ���˵�
		if (0 == usIndex)
		{
			continue;
		}

		if (usIndex < 0)
		{
			break;
		}
		
		iRet = fseek(fp, usIndex * LOG_ONE_SIZE, SEEK_SET);
		if(iRet == -1)
		{
			td_printf(0, "log query error1 %d", usIndex);
			fclose(fp);
			return ERR_LOG_FAILED;
		}
		if (LOG_ONE_SIZE != fread(cBuffer, 1, LOG_ONE_SIZE, fp))
		{
			td_printf(0, "log query error2");
			fclose(fp);
			return ERR_LOG_FAILED;
		}
		
		memcpy(&TLogHead, cBuffer, sizeof(gen_TLogHead));

		if(TLogHead.m_usIndex == LOG_DEL_FLAG)
			continue;
		stTmpInfo.m_gLogHead.m_usIndex = TLogHead.m_usIndex;
		stTmpInfo.m_gLogHead.m_iTime = TLogHead.m_iTime;
		stTmpInfo.m_gLogHead.m_iChannel = TLogHead.m_iChannel;
		stTmpInfo.m_gLogHead.m_cLevel = TLogHead.m_cLevel;
		stTmpInfo.m_gLogHead.m_uiTemInd = TLogHead.m_uiTemInd;
		strncpy((char *)stTmpInfo.m_gLogHead.m_UserName,(char *)TLogHead.m_UserName, LENGTH_USER_NAME + 1);
		
		if(_stQ->m_iChannel == CHANNEL_ALL || _stQ->m_iChannel == stTmpInfo.m_gLogHead.m_iChannel)
		{
			if (_stQ->m_iLevel == LOG_LEVEL_ALL || _stQ->m_iLevel == stTmpInfo.m_gLogHead.m_cLevel)
			{
				if (stTmpInfo.m_gLogHead.m_iTime >= _stQ->m_iStartTime && stTmpInfo.m_gLogHead.m_iTime <= _stQ->m_iStopTime)
				{	
					if ((_stQ->m_iShowNum < MAX_LOG_PAGE_SIZE)&&(_stQ->m_iShowNum < _stQ->m_iPageSize) && (_stQ->m_iTotalNum >= _stQ->m_iPageSize * _stQ->m_iPageNo))
					{
						_stQ->m_stInfo[_stQ->m_iShowNum].m_gLogHead.m_usIndex = stTmpInfo.m_gLogHead.m_usIndex;
						_stQ->m_stInfo[_stQ->m_iShowNum].m_gLogHead.m_iTime = stTmpInfo.m_gLogHead.m_iTime;
						_stQ->m_stInfo[_stQ->m_iShowNum].m_gLogHead.m_cLevel = stTmpInfo.m_gLogHead.m_cLevel;
						_stQ->m_stInfo[_stQ->m_iShowNum].m_gLogHead.m_iChannel = stTmpInfo.m_gLogHead.m_iChannel;
						strncpy((char *)_stQ->m_stInfo[_stQ->m_iShowNum].m_gLogHead.m_UserName,(char *)stTmpInfo.m_gLogHead.m_UserName, LENGTH_USER_NAME + 1);

						if (log_ParseLog(cBuffer, &stTmpInfo, _stQ->m_blLang) == ERR_LOG_SUCCESSFUL)
							memcpy(_stQ->m_stInfo[_stQ->m_iShowNum].m_cContent, stTmpInfo.m_cContent, MAX_LOG_MSG_LEN);
						else
						{
							td_printf(0, "query error!\n");
							continue;
						}
						_stQ->m_iShowNum++;
					}
					_stQ->m_iTotalNum++;
				}
			}
		}
	}

	fclose(fp);
	for (i = 0; i < _stQ->m_iShowNum; i++)
	{
		#if 0
		//���������Ϊ����
		_stQ->m_stInfo[i].m_cContent[MAX_LOG_LEN] = '\0';
		iLen = MAX_LOG_LEN - 1;
		
		while(checkIsHZ(_stQ->m_stInfo[i].m_cContent[iLen]))
		{
			iLen--;
			if (iLen < 0)
			{
				break;
			}
		}
		iCount = (MAX_LOG_LEN - 1) - iLen;
		if (iCount % 2 == 1)
		{
			_stQ->m_stInfo[i].m_cContent[MAX_LOG_LEN - 1] = '\0';
		}
		#else
		_stQ->m_stInfo[i].m_cContent[MAX_LOG_LEN] = '\0';
		iLen = 0;
		while(_stQ->m_stInfo[i].m_cContent[iLen])
		{
			td_s32 nBytes = GetUniCharBytes(_stQ->m_stInfo[i].m_cContent + iLen);
			
			if(iLen + nBytes > MAX_LOG_LEN)
			{
				td_s32 j = 0;
				for(j=0; j<(MAX_LOG_LEN - iLen); j++)
				{
					_stQ->m_stInfo[i].m_cContent[MAX_LOG_LEN - j - 1] = '\0';
				}
			}
			else
			{
				iLen += nBytes;
			}
		}
		
		#endif
	}
	return ERR_LOG_SUCCESSFUL;
}
//��־�л��洢·��,��ʱ����
td_s32 log_ChangePath(td_s32 _iDiskNo, td_s32 _iFormatStat)
{
	td_s32 iRet = td_failure;

	if ((_iFormatStat >= 1 && _iDiskNo != g_iDiskNo) || 0 == g_iInited)
	{
		//td_printf(0, "%s(%d)", __func__, __LINE__);
		goto Leave;
	}
	
	if (0 == g_iClosed || g_log_rec != NULL)
	{
		//td_printf(0, "%s(%d)", __func__, __LINE__);
		fclose(g_log_rec);
		g_iClosed = 1;
	}

	iRet = log_OpenFile();
	if (iRet != ERR_LOG_SUCCESSFUL)
	{
		td_printf(0, "%s(%d)open error!!!", __func__, __LINE__);
		iRet = td_failure;	
		goto Leave;
	}
	//td_printf(0, "%s(%d)", __func__, __LINE__);
	g_iClosed = 0;
	iRet = td_success;
Leave:
	return iRet;
}

td_s32 log_Pause(td_s32 _iDiskNo)
{
	td_s32 iRet = td_failure;

	if (_iDiskNo != g_iDiskNo || 0 == g_iInited)
	{
		goto Leave;
	}

	if (0 == g_iClosed && g_log_rec != NULL)
	{
		fclose(g_log_rec);
        g_log_rec = NULL;
		g_iClosed = 1;		
	}
	iRet = td_success;
Leave:
	return iRet;
}

td_s32 log_Restart(td_s32 _iDiskNo)
{
	td_s32 iRet = td_failure;

	if (0 == g_iInited)
	{
		goto Leave;
	}
    if (g_iDiskNo != -1 && _iDiskNo != g_iDiskNo)
    {
		goto Leave;
    }

    if (g_log_rec != NULL)
    {
		fclose(g_log_rec);
        g_log_rec = NULL;
    }

	//��Ҫ���»�ȡ��־�ļ���С
	Cfg_gLog((td_s32 *)&g_uiMinLevel, (td_s32 *)&u32LenFile, &g_iSave, g_ucFileName);
	if(u32LenFile < LOG_MIN_FILE_SIZE || u32LenFile > LOG_MAX_FILE_SIZE)
	{
	    //u32LenFile = 100;
	    u32LenFile = 1024;		//�����������־��С��Ĭ��Ϊ1M
	}	

    	iRet = log_OpenFile();
    	if (iRet != ERR_LOG_SUCCESSFUL)
    	{
    		td_printf(0, "%s(%d)open error!!!", __func__, __LINE__);
    		iRet = td_failure;	
    		goto Leave;
    	}
    	g_iClosed = 0;

	iRet = td_success;
Leave:
	return iRet;
}


#if 0
static td_s32 log_DelLog(td_u32 _usIndex)
{
	td_u32 cBuffer, cValue;
//	td_s32 iRet;

	cBuffer = LOG_DEL_FLAG;
	pthread_mutex_lock(&g_LogMutex);
	if(-1 == fseek(g_log_rec, _usIndex*LOG_ONE_SIZE, SEEK_SET))
	{
		pthread_mutex_unlock(&g_LogMutex);
		return ERR_LOG_FAILED;
	}
	if(1 !=fread(&cValue, sizeof(td_u32), 1, g_log_rec))
	{
		pthread_mutex_unlock(&g_LogMutex);
		return ERR_LOG_FAILED;
	}
	if(cValue != _usIndex)
	{
		pthread_mutex_unlock(&g_LogMutex);
		return ERR_LOG_FAILED;
	}
	if(-1 == fseek(g_log_rec, _usIndex*LOG_ONE_SIZE, SEEK_SET))
	{
		pthread_mutex_unlock(&g_LogMutex);
		return ERR_LOG_FAILED;
	}
	if (1 != fwrite(&cBuffer, sizeof(td_u32), 1, g_log_rec))
	{
		pthread_mutex_unlock(&g_LogMutex);
		return ERR_LOG_FAILED;
	}
	//û��ɾ�����пռ�
	fflush(g_log_rec);
	pthread_mutex_unlock(&g_LogMutex);
	return ERR_LOG_SUCCESSFUL;
}
#endif

td_s32 log_Init(GetUseInfo _fun)
{
	RtMsg_WriteLog(3, " %s\n", "��ʼ����־ģ�� ��ʼ");

	int    iRet = 0;

	pthread_mutex_init(&g_LogMutex, NULL);
	Cfg_gLog((td_s32 *)&g_uiMinLevel, (td_s32 *)&u32LenFile, &g_iSave, g_ucFileName);

	if(u32LenFile < LOG_MIN_FILE_SIZE || u32LenFile > LOG_MAX_FILE_SIZE)
	{
	    //u32LenFile = 100;
	    u32LenFile = 1024;		//�����������־��С��Ĭ��Ϊ1M
	}
	
	g_TInfo = LOGINFO_DEFAULT;
	g_TInfo.m_cLevel = g_uiMinLevel;
	g_TInfo.m_usFileSize = u32LenFile;

	memcpy(uLogFilePath, g_ucFileName, sizeof(uLogFilePath));

	iRet = log_OpenFile();
	if (iRet != ERR_LOG_SUCCESSFUL)
	{
		td_printf(0, "%s(%d)open error!!!", __func__, __LINE__);
		return iRet;
	}
	// ����20120522 ���˲��ֶ����ɵ����ĺ���
	iRet = log_OpenLogQue();
	if (ERR_LOG_SUCCESSFUL != iRet)
	{
		return iRet;
	}
	
    iRet = log_AllocCacheMem();
	if(iRet != td_success)
	{
        if(g_log_rec)
        {
    		fclose(g_log_rec);
	    	g_log_rec = NULL;
        }
		td_printf(0, "log_AllocCacheMem fail!\n");
		return ERR_LOG_FAILED;
	}
		
	CacheLockInit(CacheMux);
	log_ClearCacheMem();
	//��ȡ�û�����Ϣ�ص�������ʼ��
	gGetUseInfoFun = _fun;
	g_iInited = 1;
	RtMsg_WriteLog(3, " %s\n", "��ʼ����־ģ�� ����");
	return ERR_LOG_SUCCESSFUL;
}


td_s32 log_Exit()
{
	td_s32 iRet = 0;
	#if 1 // modiy by yjq 20110831
	td_s32 i;
	td_s32 iLogCloseCnt = 0;

	log_fflushCacheMem(5L);
	log_FreeCacheMem();
	CacheLockDestroy(CacheMux);
	
	for(i=0; i<LANG_ALL; i++) 
	{
		if(g_log_que[i])
		{
			if((iRet = fclose(g_log_que[i])) != 0)	
			{
				iLogCloseCnt++;
			}
			else
			{
				g_log_que[i] = NULL;
			}
		}
	}
	if(iLogCloseCnt)
	{
		return ERR_LOG_FAILED;
	}
	#else
	if(g_log_que[LANG_CH])
	{
		if((iRet = fclose(g_log_que[LANG_CH])) != 0)	
		{
			return ERR_LOG_FAILED;
		}
	}
	if(g_log_que[LANG_CH])
	{
		if((iRet = fclose(g_log_que[LANG_EN])) != 0)	
		{
			return ERR_LOG_FAILED;
		}
	}
	#endif
	if(g_log_rec)
	{
		if((iRet = fclose(g_log_rec)) != 0)
		{
			return ERR_LOG_FAILED;
		}
		g_iClosed = 1;
		g_log_rec = NULL;
	}
	g_iInited = 0;
	pthread_mutex_destroy( &g_LogMutex); 
	gGetUseInfoFun = NULL;
	return ERR_LOG_SUCCESSFUL;
}

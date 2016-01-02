#ifndef _LIBDVRRECORDER_H_
#define _LIBDVRRECORDER_H_

#include "public_def.h"
#include "td_types.h"
#include "libdiskmnt.h"
#include "dvdpublic.h"
#include "libstorage.h"
#include "libdiskgrp.h"

#define MAX_DVD_SPACE 				(4.2*1024)
#define MAX_BLUE_SPACE          	(23*1024)
#define DVD_MAX_REMAIN_CD_SPACE 	(1.5*1024) //���Ԥ��1.5G
#define DVD_MIN_REMAIN_CD_SPACE 	(0.6*1024) //���ڹ�����ʱ���׿̻���������СԤ����0.5G��Ϊ0.6G

#define BLUE_MAX_REMAIN_CD_SPACE 	(2.0*1024) //���Ԥ��2.0G
#define BLUE_MIN_REMAIN_CD_SPACE 	(0.5*1024) //��СԤ��0.5G
#define RES_FILE_SIZE            	2        //M
#define CONVERT_DIR_SPACE           25       //G
#define DISK_REMAIN_SPACE           8        //Ӳ��0����Ԥ���ռ�Ϊ8G
#define MIN_RECORD_SPACE            (128*1024) //��С¼���С128K,��¼¼�����С��128K,����ӵ���¼����
#define UDF_INIT_COUNT              5 //����udf��ʼ��������
#define UDF_CHECK_COUNT             5 //����check������
#define UDF_START_ADDRESS           1040//UDF���̵ڶ��������ʼ��ַ

//add by gyn 20121008
typedef enum
{
	DISK_BK_NONE = -1,
	DISK_BK_ING = 0,
	DISK_BK_FIN = 1,
	DISK_BK_PRE = 2,
	DISK_BK_MUTE
}tag_RecordBackupType;//���̱��ݵ�״̬
//add by gyn 20121008
typedef enum
{
	NotCloseDisk = 0,//������
	CloseDisk = 1,//����
}tag_BurnCloseCmd;//��������������´���recorder���򣬲�������Э���Ӧ��ϵ


typedef enum
{
	BurnIsEject = 0,//����
	BurnNotEject = 1,//������
}tag_DiskEject;//���̵���״̬


typedef enum
{
	ISO_DISK = 0,//ios����
	UDF_DISK = 1,//udf����
}Type_Disk;//���̿�¼��ͣ״̬

typedef enum
{
	DIRECT_OK = 0,//ֱ������
	DIRECT_ERROR = 1,//ֱ����
}DIRECT_STATE;//��Ӳ��ֱ��״̬

typedef enum
{
	BurnIsPause = 0,//��ͣ
	BurnNotPause = 1,//����ͣ
}tag_BurnPauseType;//���̿�¼��ͣ״̬

enum // ��¼״̬
{
	CBL_STA_FREE	= 0,	 //�����У�
	CBL_STA_DOING	= 1, //���ڿ�¼��
	CBL_STA_PACK	= 2, //���ڴ��
};

enum // ����״̬
{
	CBL_CD_STA_FREE	= 0, //����δʹ��
	CBL_CD_STA_BUSY	= 1, //�������ڿ�¼
	CBL_CD_STA_BAD	= 2, //��������
	CBL_CD_STA_FULL	= 3, //�����Ѿ���
	CBL_CD_STA_PACK	= 4, //�������ڴ��
	CBL_CD_STA_NODISK = 5, //����û�з������
	CBL_CD_STA_CHECKDISK = 6, //���̼����
	CBL_CD_STA_BURN_FINISH =7,//���� ��¼ ����
	CBL_CD_STA_FORMATDISK = 8,//���̸�ʽ���� 
};

enum //�ϴ����ͻ��˵Ŀ�¼״̬
{
	CBL_CD_STA_START_SUCCESS = 101,//��ʼ��¼�ɹ�
	CBL_CD_STA_START_FAILED  = 102,//��ʼ��¼ʧ��
	CBL_CD_STA_PAUSE         = 103,//��ͣ��¼
	CBL_CD_STA_RESUME		 = 104,//�ָ���¼
	CBL_CD_STA_STOP_SUCCESS  = 105,//ֹͣ��¼�ɹ�
	CBL_CD_STA_STOP_FAILED   = 106,//ֹͣ��¼ʧ��
	CBL_CD_STA_FORCE_SUCCESS = 107,//ǿ��ֹͣ�ɹ�
	CBL_CD_STA_FORCE_FAILED  = 108,//ǿ��ֹͣʧ��
	CBL_CD_STA_NOFREE_SPACE  = 109,//Ԥ���ռ䲻��
};

typedef enum
{
	SINGLE_BURN=0, 			//���̿�¼
	DOUBLE_BURN,  			//˫��ͬʱ��¼
	RECYCLE_BURN,   		//ѭ����¼
	BUTT_BURN,      		//�գ�����δ�μӿ�¼
}BURN_TYPE_E;

typedef struct	//������Ϣ
{
	int m_iSta;		//״̬
	int m_iUsed;		// ռ�ñ�ʶ(0��ʽδռ�ã�������ʽ���̺ţ�����ʹ��)
	int m_iUsedSize;	//�ѿ�¼��С(��λK)
	int m_iTotalSize;	//�����ܴ�С(��λK)
} TCdSta;

//���ڱ������¼���ļ��Ľṹ��
#define MAX_CD_FILE_NUM			128		//���̻طŵĶ��г���
#define MAX_FILE_LIST 			1024   //��¼�б���
#define MAX_BACKUP_FILE_LIST    1024    //�����б���
#define MAX_UDF_FILE  100    //Udf�ļ�ϵͳ�Ĺ������֧�ֿ�¼100���ļ�.
#define DIRECT_BUFFER_SIZE  (2*1024*1024)  //ֱ��ѭ��buffer���ٴ�СΪ2M
#define DIRECT_MD5_COUNT   1500   //��Ӳ��ʱ,ÿ�ο�¼64KB,��¼1500�κ�ѵ�ǰmd5ֵ��¼��nand��,Ϊ�˶ϵ��޸�md5ֵ
#define DVD_READ_BLOCK  (32*1024)  //��Ӳ��ʱ,�ϵ��޸�md5ʱ,ÿ�ζ�ȡ32KB����
#define DVD_BLOCK (64*1024)   //DVD����ֱ��ʱ,ÿ�ο�¼�Ļ�����λΪ64KB
 
typedef struct
{
	int m_iChn;
	int m_iStartTm;
	int m_iEndTm;
	char m_strFileName[FILE_NAME_LEN+1];
}TCdVideoFile;

typedef struct
{
	int 			m_iCd;		//cd��ţ�Ĭ��0��ʽȫ��cd
	int 			m_iChn;		//ͨ����, 0��ʾ����
	int 			m_iStartId;	// ��ʱ��������¼�Ŀ�ʼ����
	int 			m_iMaxCnt;	// ��Ҫ��ȡ�ļ�¼����
	int 			m_iStartTm;	// ��ʼʱ��(Ԥ����Ĭ��Ϊ0)
	int 			m_iEndTm;	// ����ʱ��(Ԥ����Ĭ��Ϊ0)
	int 			m_iCount;
	TCdVideoFile	m_VideoFile[MAX_CD_FILE_NUM]; 
}TCdQuery;




#define	MAX_VIDEO_MARK_NUM		256
typedef struct 
{
	int m_iChn;
	int m_iStartTm;
	int m_iEndTm;
	
}TCDVideoMark;

typedef struct tdINQUEST_MARK_QUERY
{
	int 			m_iCount;
	TCDVideoMark	m_VideoMark[MAX_VIDEO_MARK_NUM];	
}TMarkQuery;

typedef struct
{
	int		m_hasDisk;					//�������Ƿ��й���
	int		m_diskFreeSpace;				//�����й��̵Ŀ��ÿռ�
	unsigned long long		m_diskFullSpace;	     //�����й��̵����ÿռ�
}TRecoderDvdInfo;

//////////////////////
typedef enum
{
	PreBurn= 0, //  δ��¼
	//Burnning,	//   ��¼��
	BurnFinished, //  ��¼���	
}FileStatus;

typedef enum
{
	PRE_CONVERT= 0, //  ת��δ���
	CONVERT_FINISHED, //  ת�����	
}ConvertStatus;

typedef enum
{
	CONVERT_THREAD_FINISHED= 0,//ת���߳�δ����
	CONVERT_THREAD_START,//  ת���߳��ѿ���
}ConvertThreadStatus;

typedef enum
{
	DVD_NOT_REPAIR= 0,//���̴�ʱû�����޸�
	DVD_REPAIRING,//���̴�ʱ���޸�  
}DvdRepairStatus;

typedef enum
{
	StartBurn= 0, //  ��ʼ��¼
	StopBurn, //    ֹͣ��¼	
}BurnStatus;

typedef enum
{
	NOT_CONVERT_FULL= 0, //  ת��δ��һ�Ź���
	CONVERT_FULL, //  ת��¼������һ�Ź���	
}DvdConvertStatus;

typedef enum
{
	VIDEO_CONVERT_NOT_FINISH= 0, // ¼��ת��δ���
	VIDEO_CONVERT_FINISH, //  ¼��ת����� 	
}VideoConvertStatus;

typedef enum
{
	MP4_CONVERT_SUCESS= 0, // MP4¼��ת������	
	MP4_CONVERT_FAILURE,//MP4¼��ת��ʧ��
}MP4ConvertStatus;


typedef enum
{
	DVD_NOT_BURNNING = 0, // ����û�ڿ�¼
	DVD_BURNNING, // �������ڿ�¼
}DvdBurnStatus;

typedef enum
{
	BIG_FILE_MIDDLE = 0,//���ļ��е��м��ļ�
	BIG_FILE_END,//���ļ��е����һ���ļ�
}BigFileStatus;


typedef struct
{
	td_u8   	m_ucFileName[FILE_NAME_LEN];		//�ļ���
	td_u32		m_uiFileSize;					//�ļ�����
	TFileType	m_eFileType;					//�ļ�����
	
}TBurnFileInfo;

typedef struct
{
	TBurnFileInfo   stFileInfo;
	FileStatus 	      Fileinfo;
}Rec_FileStat;

typedef enum
{
	Burnning=0,  //���ڿ�¼
	Reburnning,  //�����ؿ�
	Eject, 		//�����ѵ���
	Nodisk,		//����
	DiskFull, 	//����ʣ��ռ䲻��
	Diskerror,	//������дʧ��
	Other,
}Rec_Stats;
////////////////////////

typedef struct t_Burn_File_List
{
	Rec_FileStat    Rec_File[MAX_FILE_LIST];  //1024����¼�ļ��б�
	int 			m_iChnNum;		//��¼ͨ���ţ���λ
	int 			m_iRead;		//����־
	int 			m_iWrite;  		//д��־
	int				m_iStatus;		//��¼״̬
	int				m_iType;		//��¼����
	pthread_mutex_t m_ListMutex;	//��
}T_BURN_FILE_LIST;//��ǰ�Ŀ�¼����

typedef struct t_Temp_Burn_List  //ͬһʱ��ε�¼���ļ��б�
{
	TFileInfo     Rec_File[MAX_CHANNEL_NUM]; //�������ͨ��
	int 		  m_iRead;                   //����־
	int 		  m_iWrite;                  //д��־
	int           m_iChnCount;               //��ѡͨ������
	unsigned int  m_iTotalFileSize;          //ͬһʱ���¼���ļ��ܴ�С
	pthread_mutex_t m_ListMutex;	         //��
}T_TEMP_BURN_LIST;//��ǰ�Ŀ�¼��ʱ�����

typedef struct
{
	unsigned int m_uiDevNo; // �����豸��
	unsigned int m_uiFileNum; // ������һ��Ҫ�̼��������ļ�
	unsigned int m_uiFolderNum; // ������һ��Ҫ�̼���Ŀ¼
	unsigned char m_pLogicVolIdent[128]; // ���̾��
	unsigned int m_lengthAlloc; // �䳤���䣬����ֶμ�¼allocUdfFile��m_allocUdfFolder�ķ��䳤�ȣ���λ���ֽ�
	udf_file    m_allocUdfFolder[MAX_UDF_FILE];// ʵ�ʵ�struct udf_file Ŀ¼���Զ�������װ
	udf_file    m_allocUdfFile[MAX_UDF_FILE];// ʵ�ʵ�struct udf_file  �����ļ�
}udf_temp_fs;

/* MD5 context. */
typedef struct MD5_CTX
{
	/* state (ABCD) */   
	/*�ĸ�32bits�������ڴ�����ռ���õ�����ϢժҪ������Ϣ���ȡ�512bitsʱ��Ҳ���ڴ��ÿ��512bits���м���*/ 
	unsigned long int state[4];  

	/* number of bits, modulo 2^64 (lsb first) */    
	/*�洢ԭʼ��Ϣ��bits������,����������bits���Ϊ 2^64 bits����Ϊ2^64��һ��64λ�������ֵ*/
	unsigned long int count[2];

	/* input buffer */ 
	/*����������Ϣ�Ļ�������512bits*/
	unsigned char buffer[64]; 
} MD5_CTX;

typedef struct 
{
	char   cFileName[64];
    unsigned int iMd5Addreess;
	unsigned int iPreMd5Addreess;
	MD5_CTX   Md5_File_Info;
	MD5_CTX   PRE_Md5_File_Info;
}T_MD5_INFO;


//add by gyn
typedef struct t_Back_Burn_List  //ͬһʱ��ε�¼���ļ��б�
{
	Rec_FileStat    Rec_File[MAX_BACKUP_FILE_LIST];  	//1024����¼�ļ��б�
	int				m_iStatus;					//��ʶ�Ƿ���б���
	int 		  	m_iRead;                    //����־
	int 		  	m_iWrite;                   //д��־
	unsigned int  	m_iTotalFileSize;           //¼���ļ��ܴ�С
	pthread_mutex_t m_ListMutex;	         	//��
}T_BACK_BURN_LIST;//��ǰ���ݶ���

typedef struct	// ʵʱ��¼״̬��Ϣ
{
	int m_iStat;	//��¼״̬
	TCdSta m_tSCdSta[MAX_RECORDER_NUM];
	
} TCblSta;//UI��ʹ�øýṹ��


typedef struct	
{
	int m_iStat;  			//���ݹ���״̬
	int m_iLastPrg; 		//��һ�Ź��̽���
	int m_iTotalSize; 		//������
	int m_iBackUpSize;		//�ѿ�¼����
	int m_iTotalFileNum; 	//���ļ���
	int m_iBackUpFile; 		//�ѿ�¼�ļ���
} TCblBackUpStat;			//���ݵ�״̬��Ϣ


typedef enum
{
    BURN_TYPE_CBL= 1,   //ʵʱ��¼
    BURN_TYPE_BACKUP,  //���ݿ�¼
    BURN_TYPE_MAX
}TCblBurnType;

typedef struct
{
	int m_iOkNum;
	int m_iErrNum;
}TSaveDvdInfo;

td_s32 rec_GetRecorderList(TDiskInfo* _pstDisk);
/*
 * �������ƣ�rec_GetRecorderList
 * ��Ҫ����: ��ȡ��¼���б�
 * ��    ��:  ��
 *
 * ��	 ����_pstDisk
 *
 * �޸���־��
 * 			2012-10-08��sunlnע��
 */

td_s32 Burn_GetDvdInfo(int _iDvdNo,TRecoderDvdInfo* _ptDvdInfo);
/*
 * �������ƣ�Burn_GetDvdInfo
 * ��Ҫ����: ��ȡ������Ϣ
 * ��    ��: _iDvdNo
 *
 * ��	 ����_ptDvdInfo
 *
 * �޸���־��
 * 			2012-10-08��sunlnע��
 */

 
td_s32 RtBurn_SetBackUpState(td_s32 _iDvdNo,td_s32 _iBkState);
/*
 * �������ƣ�RtBurn_SetBackUpState
 * ��Ҫ���������ù��̱���״̬
 * ����     : _iBkState,���̱���״̬
 * ����ֵ  : >=0 �ɹ�   -1 ʧ��				 
 *			
 *			
 * 
 * 			
 *			
 *			
 * �޸���־��
 * 			2014-8-14,zmw,����
 */

 td_s32 RtBurn_setBackupIndex(td_s32 _iBackupIndex,td_s32 _iBackupCnt);
 /*
 * �������ƣ�RtBurn_setBackupIndex
 * ��Ҫ���������õ�ǰ���ݵڼ���ʱ���¼��
 * ����     : _iBackupIndex,���̱���ʱ���������
 			  _iBackupCnt,���̱���ʱ��θ���
 * ����ֵ  : >=0 �ɹ�   -1 ʧ��				 
 *			
 *			
 * 
 * 			
 *			
 *			
 * �޸���־��
 * 			2014-8-14,zmw,����
 */
td_s32 RtBurn_GetBurnStatus();
 /*
 * �������ƣ�RtBurn_GetBurnStatus
 * ��Ҫ��������¼��״̬
 * ����     : ��
 * ����ֵ  :   ��¼��״̬			 
 *			
 *			
 * 
 * 			
 *			
 *			
 * �޸���־��
 * 			2014-12-19,zmw,����
 */
 td_s32 RtBurn_getBackupIndex(td_s32* _iBackupIndex,td_s32* _iBackupCnt);
  /*
 * �������ƣ�RtBurn_getBackupIndex
 * ��Ҫ��������ȡ��ǰ���ݵڼ���ʱ���¼��
 * ���     : _iBackupIndex,���̱���ʱ���������
 			: _iBackupCnt,���̱���ʱ��θ���
 * ����ֵ  : >=0 �ɹ�   -1 ʧ��				 
 *			
 *			
 * 
 * 			
 *			
 *			
 * �޸���־��
 * 			2014-8-14,zmw,����
 */
  //�жϹ��̵����ÿռ��Ƿ�С���޶�ֵ
td_s32 RtBurn_CheckDiskCanUsed(int _iDvdNo,int _iUsedLimit);
/*
 * �������ƣ� Burn_CheckDiskCanUsed
 * ��Ҫ����:
 * ��    ��: _iDvdNo
 *			_iUsedLimit
 * ��	 �������̵����ÿռ�
 *
 * �޸���־��
 * 			2014-03-08 zmw ע��
 */

td_s32 BigFile_CheckDiskCanUsed(int _iDvdNo);
/*
 * �������ƣ� BigFile_CheckDiskCanUsed
 * ��Ҫ����:
 * ��    ��: _iDvdNo
 *			
 * ��	 ���������Ƿ��ǿհ׹���
 *
 * �޸���־��
 * 			2015-05-07 zmw ע��
 */


int RtBurn_MountCD(int _iCdNo,int _iDiskType);
/*
 * �������ƣ�RtBurn_MountCD
 * ��Ҫ����: ���ع���
 * ��    ��: _iCdNo		������
 			_iDiskType	��������
 *
 * ��	 ����
 *
 * �޸���־��
 * 			2015-02-02��zmwע��
 */
int BigFile_CheckUDFExist(int _iCdNo);
/*
 * �������ƣ�BigFile_CheckUDFExist
 * ��Ҫ����: ��������Ĺ�������������
 * ��    ��: _iCdNo : ������ 
 *
 * ��	 ������������������
 *
 * �޸���־��
 * 			2015-06-08��xiejingע��
 */

td_s32 RtBurn_GetFileListFromCd(int _iChn,TCdQuery* _CdQuery);
/*
 * �������ƣ�RtBurn_GetFileListFromCd
 * ��Ҫ����: ��ù����ϵ��ļ��б�
 * ��    ��: _iChn : ͨ���� _CdQuery:��ѯ���
 *
 * ��	 ����
 *
 * �޸���־��
 * 			2012-10-08��sunlnע��
 */
td_s32 DvdEject(int _iDvdNo);
/*
 * ��������:	DvdEject
 * ��Ҫ����:	������������ҵ��ģ���ã��û�����֪����������
 * ��	 ��: 	_iDvdNo ������� ��0��ʼ
 * ��	 ��:	�ɹ� 0 ��ʧ�� 1
 * �޸���־:
 *				2013-08-02,����骣�������
 */
td_s32 DvdUnEject(td_s32 _iDvdNo,td_s32 _s32Type);
/*
 * ��������:	DvdUnEject
 * ��Ҫ����:	�������
 * ��	 ��: 	_iDvdNo,������ _s32Type����¼���ͣ���Ϊ���̿�¼ʱ��ֻ����ָ�������������������й���
 * ��	 ��:	�ɹ� 0 ��ʧ�� 1
 * �޸���־:
 *				2009-12-03,��������������
 */

#if 0
//add by gyn
//��ȡӲ���ϵĴ����Ϣ
int 	RtBurn_ReadVideoMarkEx(char * _pcFileName,TMarkQuery *_MarkQuery);
/*
	����		:��ȡ�����Ϣ
	����		:_MarkQuery		���ڷ��ز�ѯ��Ľ��
	����ֵ	:0		�ɹ�
				 ����	ʧ��
*/
//add end

int 	RtBurn_ReadVideoMark(TMarkQuery *_MarkQuery);
/*
	����		:��ȡ�����Ϣ
	����		:_MarkQuery		���ڷ��ز�ѯ��Ľ��
	����ֵ	:0		�ɹ�
				 ����	ʧ��
*/
#endif
td_s32 Burn_GetCDNum();
/*
 * �������ƣ�RtBurn_GetCDNum
 * ��Ҫ����:    ��ȡ��Ч������
 * ��       ��: 	
 * ��	  ����	��Ч������
 				
 * �޸���־				
 * 			2010-09-19,�����봴��
 */



//------------���ݿ�¼�ӿ�------------------------------------------
td_s32 BkBurn_PrepareToRecord(td_s32 _iCdNo,td_s32 _iType);		
/*
 * �������ƣ�rec_PrepareToRecord
 * ��Ҫ����: ����׼��
 * ��    ��: _iCdNo
 * ��	 ������
 * �޸���־��
 * 			2012-10-08��sunlnע��
 */
 
td_s32 BkBurn_MakeLinkForFile(td_u8* _pcFileName,td_s32 _iCdNo);
/*
 * �������ƣ�BkBurn_MakeLinkForFile
 * ��Ҫ����: Ϊ����¼���ļ���������
 * ��    ��: _pcFileName,_iCdNo
 * ��	 ������
 * �޸���־��
 * 			2012-10-08��sunlnע��
 */

td_s32 BkBurn_DoRecord(td_s32 _iCdNo);
/*
 * �������ƣ�BkBurn_DoRecord
 * ��Ҫ����: ��¼׼���õ�Ŀ¼
 * ��    ��: _iCdNo
 * ��	 ������
 * �޸���־��
 * 				2012-10-08��sunlnע��
 */

td_s32 BkBurn_DoBigFileRecord(td_s32 _iCdNo);
/*
 * �������ƣ�BkBurn_DoBigFileRecord
 * ��Ҫ����: ��¼׼���õ�Ŀ¼
 * ��    ��: _iCdNo
 * ��	 ������
 * �޸���־��
 * 				2012-10-08��zmwע��
 */

td_s32 BkBurn_GetBurnProgress(td_s32* _piStat,td_s32 _iCdNo );
/*
 * �������ƣ�BkBurn_GetBurnProgress
 * ��Ҫ����: ��ȡ��¼����
 * ��    ��: _iCdNo 
 * ��	 ����_piStat
 * �޸���־��
 * 				2014-03-10��zmw�޸�
 */

td_s32 BkBurn_ForceStopBackUp(td_s32 _iCdNo );
/*
 * �������ƣ�BkBurn_ForceStopBackUp
 * ��Ҫ����: ǿ��ֹͣ����
 * ��    ��: _iCdNo 
 * ��	 ������
 * �޸���־��
 * 			2014-03-10��zmw�޸�
 */

typedef td_s32 (*GETBITRATE)(td_s32 _u8Channel);

//------------ʵʱ��¼�ӿ�gxl------------------------------------------
td_s32 CDROM_init(void);
td_s32 RtBurn_Init(GETBITRATE _cbkGetBitRate);
/*
 * ��������:	tBurn_Init
 * ��Ҫ����: 	��ʼ�������ڴ棬��ȡʵ����Ч������
 *
 * ��       ��	:      _cbkGetBitRate: ��ȡʵʱ��¼���ʵĻص�����
 * ��	 ����	��Ч������
 *			
 * �޸���־��
 * 				2010-09-19,�����봴��
 */

//��Ϊ�ص�����
//void RtBurn_Add2List(int _iChn, const char *_strFileName,int _iFileLen,TFileType _FileType);
/*
 * ��������:	tBurn_Init
 * ��Ҫ����: 	��ʼ�������ڴ棬��ȡʵ����Ч������
 *
 * ��       ��	:      _cbkGetBitRate: ��ȡʵʱ��¼���ʵĻص�����
 * ��	 ����	��Ч������
 *			
 * �޸���־��
 * 				2010-09-19,�����봴��
 */

//int RtBurn_ListGetType(int _iDiskNo, BURN_TYPE_E* _piType);
td_s32 BkBurn_SetPolicy(BURN_TYPE_E _s32Type, td_s32 _s32DiskNo);
/*
 * �������ƣ�BkBurn_SetPolicy
 * ��Ҫ����: ���ñ��ݲ��ԡ�
 *
 * ��       ��: _s32Type:���ݲ���
					 	SINGLE_BURN=0,	//���̱���
						DOUBLE_BURN,  	//˫��ͬʱ��¼
						BUTT_BURN,     	//�գ�����δ�μӿ�¼
						
			    			    
			    _s32DiskNo: ��¼�����
			   
 * ��	  �����ɹ�
 *			
 * �޸���־��
 * 			2014-11-27,zmw����
 */

td_s32 BkBurn_SetBigFilePolicy(BURN_TYPE_E _s32Type, td_s32 _s32DiskNo);
/*
 * �������ƣ�BkBurn_SetBigFilePolicy
 * ��Ҫ����: ���ñ��ݲ��ԡ�
 *
 * ��       ��: _s32Type:���ݲ���
					 	SINGLE_BURN=0,	//���̱���
						DOUBLE_BURN,  	//˫��ͬʱ��¼
						BUTT_BURN,     	//�գ�����δ�μӿ�¼
						
			    			    
			    _s32DiskNo: ��¼�����
			   
 * ��	  �����ɹ�
 *			
 * �޸���־��
 * 			2014-11-27,zmw����
 */

td_s32 RtBurn_SetPolicy(BURN_TYPE_E _s32Type, td_s32 _s32Chn, td_s32 _s32DiskNo,td_s32 _s32Operation);
/*
 * �������ƣ�RtBurn_SetPolicy
 * ��Ҫ����: ���ÿ�¼���ԡ��������õ��̿�¼��ͬ�Ĺ������Կ�¼��ͬ��ͨ��
 *                         �����Ժ�һ������Ϊ׼
 *
 * ��       ��: _s32Type:��¼����
					 	SINGLE_BURN=0,	//���̿�¼
						DOUBLE_BURN,  	//˫��ͬʱ��¼
						RECYCLE_BURN,  	//ѭ����¼
						BUTT_BURN,     	//�գ�����δ�μӿ�¼
						
			    _s32Chn:��¼ͨ���ţ���λ���á�
			    
			    _s32DiskNo: ��¼����ţ���λ���á�
			    _s32Operation Ϊ0�������̣�Ϊ1������
 * ��	  ������Ч������
 *			
 * �޸���־��
 * 			2010-09-19,�����봴��
 */
td_s32 RtBurn_Isinsmod(td_s32 _s32BurnType);
/*
 * �������ƣ�RtBurn_Isinsmod
 * ��Ҫ����:  ���ݿ�¼�����Լ������ţ����Ƿ�Ҫ���¼��ع�������
 *
 * ��       ��: _s32BurnType:��¼����
					 	SINGLE_BURN=0,	//���̿�¼
						DOUBLE_BURN,  	//˫��ͬʱ��¼
						RECYCLE_BURN,  	//ѭ����¼
						BUTT_BURN,     	//�գ�����δ�μӿ�¼
						
			    
 * ��	  �����ɹ�
 *			
 * �޸���־��
 * 			2014-07-21,zmw����
 */
td_s32 RtBurn_GetPolicy(BURN_TYPE_E* _ps32Type, td_s32 _s32DiskNo, td_s32* _ps32ChnNum);
/*
 * �������ƣ�RtBurn_GetPolicy
 * ��Ҫ����: ��ȡ��¼���ԡ�
 *
 * ��       ��: _ps32Type:������¼����
					 	SINGLE_BURN=0, 	//���̿�¼
						DOUBLE_BURN,  	//˫��ͬʱ��¼
						RECYCLE_BURN,   	//ѭ����¼
						BUTT_BURN,      	//�գ�����δ�μӿ�¼
									    
			    _s32DiskNo: ��¼�����
			    _ps32ChnNum:������¼ͨ���б�
			    
 * ��	  ������ǰ��¼״̬
 						GUI_CBL_STA_FREE: ���̿���
 						GUI_CBL_STA_DOING:���ڿ�¼
 						GUI_CBL_STA_PACK:���״̬(���Ƴɽ�����¼״̬������δ��¼���)
 						
 *			
 * �޸���־��
 * 			2010-09-19,�����봴��
 */


td_s32 RtBurn_Start(td_s32 _s32DiskNo);
/*
 * �������ƣ�RtBurn_Start
 * ��Ҫ����: 	��ʼ��¼
 * ��       ��: 	_s32DiskNo	�������
 							�����¼������˫��ͬ�̻����ֿ̣��ò�����������
 * ��	  ����	�ɹ�ERR_REC_SUCCESSFUL
 				�޿��ô���:ERR_REC_NO_DISK
 				���ڿ�¼:ERR_REC_USING_DISK
 * �޸���־��
 * 			2010-09-19,�����봴��
 */
td_s32 RtBurn_StartEx(td_s32 _s32DiskNo,td_s32 _iIsOverLap);
/*
 * �������ƣ�RtBurn_StartEx
 * ��Ҫ����: 	��ʼ��¼
 * ��       ��: 	_s32DiskNo	�������
 							�����¼������˫��ͬ�̻����ֿ̣��ò�����������
 * ��	  ����	�ɹ�ERR_REC_SUCCESSFUL
 				�޿��ô���:ERR_REC_NO_DISK
 				���ڿ�¼:ERR_REC_USING_DISK
 * �޸���־��
 * 			2012-10-08��sunlnע��
 */


td_s32 RtBurn_Stop(td_s32 _s32DiskNo);
/*
 * �������ƣ�RtBurn_Stop
 * ��Ҫ����:    ֹͣ��¼
 * ��       ��: 	_s32DiskNo	�������
 							�����¼������˫��ͬ�̻����ֿ̣��ò�����������
 * ��	  ����		
 * �޸���־��
 * 			2010-09-19,�����봴��
 */

 
 td_s32 RtBurn_DelayPackTime(td_s32 _s32DiskNo);
 /*
 * �������ƣ�RtBurn_DelayPackTime
 * ��Ҫ����:    ��¼�������ӳ�¼����ʱ��
 * ��       ��: 	_s32DiskNo	�������
 				
 * ��	  ����		
 * �޸���־��
 * 			2014-04-10,zmwע��
 */
td_s32 RtBurn_StopEx(td_s32 _s32DiskNo);
/*
 * �������ƣ�RtBurn_StopEx
 * ��Ҫ����:    ֹͣ��¼
 * ��       ��: 	_s32DiskNo	�������
 				�����������������ֹͣ������ǿ��ֹͣ
 * ��	  ����		
 * �޸���־��
 * 			2012-10-16,sunlnע��
 */


//�Լ�����״̬
td_s32 RtBurn_GetStatus(td_s32 _s32DiskNo, TCdSta* _pCDStatus);
/*
 * �������ƣ�RtBurn_GetStatus
 * ��Ҫ����:    ��ȡ��¼״̬
 * ��       ��: 	_s32DiskNo:	��¼�����
 				_pCDStatus:�������������ڴ�����¼״̬
 * ��	  ����	ERR_REC_NO_DISK��w����Ч����
 				ERR_REC_SUCCESSFUL:�ɹ�
 * �޸���־				
 * 			2010-09-19,�����봴��
 */
 
td_s32 DvdEjectRemote(int _iOption,int _iDvdNo);
/*
 * �������ƣ�DvdEjectRemote
 * ��Ҫ����: Զ�̵���
 * ��    ��: _iOption,_iDvdNo
 			
 * ��	 ����	
 			0:�ɹ�
 * �޸���־				
 * 			
 			2012-09-29�������
 */

td_s32 RtBurn_DvdEject(int _iOption,int _iDvdNo,td_bool _iForce);
/*
  * ��������:RtBurn_DvdEject
  * ��Ҫ����:����/�ջع���
  * ��	  ��:
  *			 _iDvdNo, ��¼�����
  *			 _iOption,��1 �ջأ�0 ������
 */

td_s32 BigFile_DvdEject(int _iOption,int _iDvdNo,td_bool _iForce);
 				
td_s32 RtBurn_SetCloseProperty(int _iClose,int _iJet);
/*
 * �������ƣ�RtBurn_SetCloseProperty
 * ��Ҫ����: ���ù�����¼�Ƿ�
 * ��       ��: 	
 //�ж��ǲ��Ƿ����뵯������_iClose = 0������_iClose = 1����
//_iJet = 0�������̣�_iJet = 1����������				
 * ��	  ����	
 				0:�ɹ�
 * �޸���־				
 * 			
 			2012-03-13�������
 */
 td_s32 RtBurn_GetCloseProperty(int *_iClose,int* _iJet);
/*
 * �������ƣ�RtBurn_GetCloseProperty
 * ��Ҫ����: ��ȡ������¼�Ƿ�
 * ��       ��: 	
 //�ж��ǲ��Ƿ����뵯������_iClose = 0������_iClose = 1����
//_iJet = 0�������̣�_iJet = 1����������				
 * ��	  ����	
 				0:�ɹ�
 * �޸���־				
 * 			
 			2012-09-29�������
 */
void GetAdditionalFilePath(char *_pcDesFilePath);//��ȡ��ǰ��·��
/*
 * �������ƣ�GetAdditionalFilePath
 * ��Ҫ����: ��ȡ��������·��
 * ��     ��: 	
 				
 * ��	  ����	_pcDesFilePath�ļ���·��	
 				
 * �޸���־				
 			2012-03-13�������ע��
 */

void SetAdditionalFilePathOther(const char *_pcFilePath);
/*
 * �������ƣ�SetAdditionalFilePathOther
 * ��Ҫ����: ���õ�ǰϵͳ������ʾ֤�����ϵ��ļ���
 * ��       ��: _pcFilePath�ļ���·��	
 				
 * ��	  ����	
 * �޸���־				
 * 			
 			2012-03-13�������ע��
 */
void GetAdditionalFilePathOther(char *_pcDesFilePath);//��ȡ��ǰ��·��
/*
 * �������ƣ�GetAdditionalFilePathOther
 * ��Ҫ����: ��ȡ��ǰϵͳ������ʾ֤�����ϵ��ļ���
 * ��     ��: 	
 				
 * ��	  ����	_pcDesFilePath�ļ���·��	
 * �޸���־				
 * 			
 			2012-03-13�������ע��
 */


 int RtBurn_OverLapBurn();
 /*
  * ��������:RtBurn_OverLapBurn
  * ��Ҫ����:��ѯ¼���ļ��������뵽��¼����
  * ��	  ��:
  *			 ��ѯ¼��Ŀ�ʼʱ��
  * �޸���־				
  * 			
 			2012-01-29��zhuangzhibing
  */
 td_s32 RtBurn_IsOverLapBurn();
 /*
  * ��������:RtBurn_IsOverLapBurn
  * ��Ҫ����:�ж��Ƿ��и����ļ�
  * ��	  ��:
  *			��
  * �޸���־				
  * 			
 			2012-01-29��zhuangzhibing
  */
  
int RtBurn_SetOverLapBurnInfo(int  _iDiskNo,int _iChn,char *_pcName,char *_pcFlag);
 /*
  * ��������:RtBurn_SetOverLapBurnInfo
  * ��Ҫ����:�����ѿ�¼�ļ����������ļ���
  * ��	  ��:
  *			��¼����š�ͨ���š��ļ�������һ��д�����ļ���ʶ
  * �޸���־				
  * 			
 			2012-01-29��zhuangzhibing
  */
int RtBurn_ClearOverLapBurnInfo(int  _iDiskNo);
 /*
  * ��������:RtBurn_ClearOverLapBurnInfo
  * ��Ҫ����:��տ�¼�����ļ�
  * ��	  ��:
  *			��¼�����
  * �޸���־				
  * 			
 			2012-01-29��zhuangzhibing
  */


td_s32 RtBurn_Force_Stop(td_s32 _s32DiskNo);
/*
* �������ƣ�RtBurn_Force_Stop
* ��Ҫ����: ǿ��ֹͣ��¼
* ��		 ��:	 _s32DiskNo�������
		 
* ��	   ����  
		 
* �޸���־			 
	 2012-03-13�������ע��
*/
td_s32 RtBurn_Reset_Force(td_s32 _s32BurnType,td_s32 _s32DiskNo);
/*
* �������ƣ�RtBurn_Reset_Force
* ��Ҫ����: ��ǿ��ֹͣ
* ��		 ��:	_s32BurnType,��¼���ԣ� _s32DiskNo��������
		 
* ��	   ����  
		 
* �޸���־			 
	 2014-04-01    zmw ע��
*/
td_s32 RtBurn_Uninit();

void SetAdditionalFilePath(const char *_pcFilePath);
/*
* �������ƣ�SetAdditionalFilePath
* ��Ҫ����: ���ò�������·��
* ��       ��: 	_pcFilePath�ļ���·��
				
* ��	  ����	
				
* �޸���־				
			2012-03-13�������ע��
*/
 void GetAdditionalFilePath(char *_pcDesFilePath);
/*
* �������ƣ�GetAdditionalFilePath
* ��Ҫ����: ��ȡ��ǰϵͳ��������·��
* ��     ��: 	
				
* ��	  ����	_pcDesFilePath�ļ���·��	
* �޸���־				
* 			
			2012-03-13�������ע��
*/

int  GetRecorderConfig(TRecordConfig *_pstConfig);//
/*
* �������ƣ�GetRecorderConfig
* ��Ҫ����: ��ȡ¼����ԣ�¼��ʱ���̶�Ϊ10����
* ��       ��: 
				
* ��	  ����	_pstConfig ¼����Խṹ
				
* �޸���־				
*
*			2012-09-29��sunlnע��
*/

int SetOldRecordConfig(TRecordConfig *_pstOldConfig);//
/*
* �������ƣ�SetOldRecordConfig
* ��Ҫ����: ���þɵ�¼�����
* ��       ��: _pstConfig ¼����Խṹ
				
* ��	  ����	
				
* �޸���־				
*			2012-09-29��sunlnע��
*/

int ResumeOldRecordConfig(void);//
/*
* �������ƣ�ResumeOldRecordConfig
* ��Ҫ����: �ָ�ԭ�е�¼�����
* ��       ��: ��
				
* ��	  ����	
				
* �޸���־				
*			2012-09-29��sunlnע��
*/
//add by sunln 20120401
int RtBurn_ClearList(int _iDiskNo);//
/*
* �������ƣ�RtBurn_ClearList
* ��Ҫ����: ��տ�¼���� 
* ��       ��: _iDiskNo ������
				
* ��	  ����	
				
* �޸���־				
*			2012-09-29��sunlnע��
*/

td_s32 OneRtBurn_IsOverLapBurn(int _iDisknum);
/*
* ��������:OneRtBurn_IsOverLapBurn
* ��Ҫ����:�жϹ����Ƿ��и����ļ�
*
* ��	  ��:_iDisknum ������
*			
* �޸���־				
*			2012-09-29��sunlnע��
*/

int RtBurn_SetOverLapBurnInfoEx(int _iDiskNo,char *_pcName,int _iFirstFlag);
/*
* ��������:RtBurn_SetOverLapBurnInfoEx
* ��Ҫ����:�����ѿ�¼�ļ����������ļ���
* ��	  ��:
*			��¼����š��ļ�������һ��д�����ļ���ʶ
* �޸���־				
*			2012-09-29��sunlnע��
*/

int RtBurn_ClearOverLapBurnInfoEx(int  _iDiskNo);
/*
* ��������:RtBurn_ClearOverLapBurnInfoEx
* ��Ҫ����:��տ�¼�����ļ�
* ��	  ��:
*			��¼�����
* �޸���־				
*			2012-09-29��sunlnע��
*/

td_s32 RtBurn_IsOverLapBurnEx();
/*
* ��������:RtBurn_IsOverLapBurnEx
* ��Ҫ����:�ж��Ƿ��и����ļ�
* ��	  ��:
*			��
* �޸���־				
*			2012-09-29��sunlnע��
*/
void  RtBurnDeleteVideo(char *_pcRecorderPath);
/*
* ��������:RtBurnDeleteVideo
* ��Ҫ����:ɾ��Ӳ���е���Ƶ�ļ�Ŀ¼
* ��	  ��:Ҫɾ����Ŀ¼
*			
* �޸���־				
*			2014-05-26��zmwע��
*/
td_s32 OneRtBurn_IsOverLapBurnEx(int _iDisknum);
/*
* ��������:OneRtBurn_IsOverLapBurnEx
* ��Ҫ����:�жϹ����Ƿ��и����ļ�
*
* ��	  ��:_iDisknum ������
*			
* �޸���־				
*			2012-09-29��sunlnע��
*/


void RtBurn_ResetRecoverCfg();
/*
* �������ƣ�RtBurn_ResetRecoverCfg
* ��Ҫ����: ���ϵ縴�̱�־��λ�����ڿ�¼������
* ��       ��: ��
				
* ��	  ����	
				
* �޸���־				
*			2012-09-29��sunlnע��
*/
td_s32 RtBurn_SetBurnHours(int _iBurnHour,int _iDiskType);
/*
* �������ƣ�RtBurn_SetBurnHours
* ��Ҫ����: ���õ�ǰ�Ŀ�¼ʱ���͹�������
* ��       ��: 
				
* ��	  ����	0����ɹ�
				
* �޸���־				
*			2012-10-08��sunlnע��
*/


td_s32 RtBurn_GetBurnHours(int *_iBurnHour,int *_iDiskType);
/*
* �������ƣ�RtBurn_GetBurnHours
* ��Ҫ����: ��ȡ��ǰ��¼ʱ���͹�������
* ��       ��: 
				
* ��	  ����	0����ɹ�
				
* �޸���־				
*			2012-10-08��sunlnע��
*/		
td_s32 RtBurn_GetBurnChnBitrates(td_s32 _iCdNo);
/*
* �������ƣ�RtBurn_GetBurnChnBitrates
* ��Ҫ����: ��ȡ��¼ͨ����������
* ��       ��:    ������
				
* ��	  ����	��¼ͨ����������
				
* �޸���־				
*			2014-3-6��zmwע��
*/	
td_s32 RtBurn_GetLeftBurnTime(td_s32 _iCdNo);
/*
* �������ƣ�RtBurn_GetLeftBurnTime
* ��Ҫ����: ��ȡ���̵�ʣ���¼ʱ��
* ��       ��:   ���̱��
				
* ��	  ��:���̵�ʣ���¼ʱ��
				
* �޸���־				
*			2014-2-27��zmwע��
*/		

td_s32 RtBurn_GetLeftPackTime(td_s32 _iCdNo);
/*
* �������ƣ�RtBurn_GetLeftPackTime
* ��Ҫ����: ��ȡ���̵�ʣ����ʱ��
* ��       ��:   ���̱��
				
* ��	  ��:���̵�ʣ����ʱ��
				
* �޸���־				
*			2014-2-27��zmwע��
*/	

td_s32 RtBurn_GetRealSpeed(int _iCdNo,int * _iSpeed);

td_s32 RtBurn_GetBurnSpeed(int *_iSpeed);
/*
* �������ƣ�RtBurn_GetBurnSpeed
* ��Ҫ����: ��ȡ��ǰ��¼����
* ��       ��: 
				
* ��	  ����	0����ɹ�
				
* �޸���־				
*			2012-10-08��sunlnע��
*/
td_s32  RtBurn_GetBurnRealSpeed(int _iCdNo,int * _iSpeed);
/*
* �������ƣ�RtBurn_GetBurnRealSpeed
* ��Ҫ����:��ȡƽ����¼�ٶ�
* ��       ��: _iCdNo �����ţ� * _iSpeed,��¼�ٶ�
				
* ��	  ����	0����ɹ�
				
* �޸���־				
*			2014-03-23��zmwע��
*/
td_s32 RtBurn_SetBurnRealSpeed(td_s32 _iDvdNo,td_s32 _iUseTime,td_s32 _iBurnSize);
/*
* �������ƣ�RtBurn_SetBurnRealSpeed
* ��Ҫ����: ���ÿ�¼�ٶ�
* ��       ��: _iCdNo �����ţ�_iUseTime����¼���õ�ʱ�� _iBurnSize,��¼��С
				
* ��	  ����	0����ɹ�
				
* �޸���־				
*			2014-03-23��zmwע��
*/
td_s32 RtBurn_SetConvertFileExtName(td_s32 _iFileFormate);
/*
* �������ƣ�RtBurn_SetConvertFileExtName
* ��Ҫ����: ����ת���ļ��ĺ�׺��
* ��       ��: _iFileFormate :�ļ�ת������.
				
* ��	  ����	0����ɹ�
				
* �޸���־				
*			2014-12-09��zmwע��
*/
td_s32 Convert_GenerateVideoFileExtName(char* _pcTempName);
/*
* �������ƣ�Convert_GenerateVideoFileExtName
* ��Ҫ����: �����ļ�ת�������޸�¼���׺��
* ��       ��: _pcTempName :ԭ�ļ���.
				
* ��	  ����	0����ɹ�
				
* �޸���־				
*			2014-12-09��zmwע��
*/
//td_s32 ConvertVideoFile(char* _pcSrcFile, char *_pcDesFile, int _iFileFormate);

td_s32 Convert_VideoFile ( char* _pcSrcFileName, char* _pcDstFileName, int _iFileFormate);

/*
* �������ƣ�ConvertVideoFile
* ��Ҫ����: �ļ�ת������
* ��       ��: _pcSrcFile :ԭ�ļ���.
			   _pcDesFile :Ŀ���ļ�
			   _iFileFormate : ת����ʽ
				
* ��	  ����	0����ɹ�
				
* �޸���־				
*			2014-12-09��zmwע��
*/
td_s32 RtBurn_SetBurnSpeed(int _iSpeed);
/*
* �������ƣ�RtBurn_SetBurnSpeed
* ��Ҫ����: ���ÿ�¼����
* ��       ��: 
				
* ��	  ����	0����ɹ�
				
* �޸���־				
*			2012-10-08��sunlnע��
*/
int RtBurn_ReadResSpace(void);
/*
* �������ƣ�RtBurn_ReadResSpace
* ��Ҫ����: ��ȡ�����ļ���ʣ��ռ�ֵ
* ��	   ��: 
				
* ��	  ����	0����ɹ�
				
* �޸���־				
*			2015-04-27��xiejingע��
*/
int RtBurn_GetResSpace(int *_piResSpace);
/*
* �������ƣ�RtBurn_GetResSpace
* ��Ҫ����: ��ȡ��ǰʣ��ռ�
* ��	   ��: 
				
* ��	  ����	0����ɹ�
				
* �޸���־				
*			2015-04-27��xiejingע��
*/
int RtBurn_SetResSpace(int _iResSpace);
/*
* �������ƣ�RtBurn_SetResSpace
* ��Ҫ����: ���õ�ǰʣ��ռ�
* ��	   ��: 
				
* ��	  ����	0����ɹ�
				
* �޸���־				
*			2015-04-27��xiejingע��
*/

td_s32 RtBurn_SetBurnCdNameAndSpace(int _iSpace,const char *_pcName);
/*
* �������ƣ�RtBurn_SetBurnCdNameAndSpace
* ��Ҫ����: ���ù�������Ԥ���ռ�
* ��       ��: //_pcName ����ı�����gb2312��ʽ
				
* ��	  ����	0����ɹ�
				
* �޸���־				
*			2012-10-08��sunlnע��
*/

td_s32 RtBurn_GetBurnCdNameAndSpace(int *_iSpace,char *_pcName);
/*
* �������ƣ�RtBurn_GetBurnCdNameAndSpace
* ��Ҫ����: ��ȡ��������Ԥ���ռ�
* ��       ��: 
				
* ��	  ����	0����ɹ�
				
* �޸���־				
*			2012-10-08��sunlnע��
*/
td_s32 RtBurn_SetBurnPauseState(int _iState);
/*
* �������ƣ�RtBurn_SetBurnPauseState
* ��Ҫ����: ���ù�������ͣ���߻ָ�
* ��       ��: 
				
* ��	  ����	0����ɹ�
				
* �޸���־				
*			2012-10-08��sunlnע��
*/

td_s32 RtBurn_GetBurnPauseState(int *_iState);
/*
* �������ƣ�RtBurn_GetBurnPauseState
* ��Ҫ����: ��ȡ��������ͣ���߻ָ�
* ��       ��: 
				
* ��	  ����	0����ɹ�
				
* �޸���־				
*			2012-10-08��sunlnע��
*/


td_s32 RtBurn_SaveCfg();
/*
* �������ƣ�RtBurn_SaveCfg
* ��Ҫ����: ����߼����õĲ���
* ��       ��: 
				
* ��	  ����	0����ɹ�
				
* �޸���־				
*			2012-10-08��sunlnע��
*/
td_s32 RtBurn_ClearBurnLable();
/*
* �������ƣ�RtBurn_ClearBurnLable
* ��Ҫ����: ������̱�ǩ
* ��       ��: 
				
* ��	  ����	0����ɹ�
				
* �޸���־				
*			2012-10-08��sunlnע��
*/

td_s32 RtBurn_SetCDTitle(td_s32 _s32DiskNo,const char* const _pcTitle);
/*
* �������ƣ�RtBurn_SetCDTitle
* ��Ҫ����:  ���ù��̵Ĺ������
* ��       ��: 
				
* ��	  ����	0����ɹ�
				
* �޸���־				
*			2012-10-08��sunlnע��
*/

td_s32 RtBurn_DefaultCfg();
/*
* �������ƣ�Burn_DefaultCfg
* ��Ҫ����: ���ټ����̵��̲����ָ�Ĭ��
* ��       ��: 
				
* ��	  ����	0����ɹ�
				
* �޸���־				
*			2012-10-08��sunlnע��
*/

td_s32 RtBurn_RmDvdConfigFile(const char *_pcPath,int _iDiskNo);
/*
* �������ƣ�RtBurn_RmDvdConfigFile
* ��Ҫ����: ɾ��config.ini��Player��Other�ļ����е�ָ������
* ��       ��: 
				
* ��	  ����	0����ɹ�
				
* �޸���־				
*			2012-10-19��sunlnע��
*/
td_s32 RtBurn_SetToDefalutStat(td_bool _iState);
/*
* �������ƣ�RtBurn_SetToDefalutStat
* ��Ҫ����:���õ�ǰ״̬Ϊ�ָ�Ĭ��
* ��       ��: 
				
* ��	  ����	0����ɹ�
				
* �޸���־				
*			2012-10-19��sunlnע��
*/


td_s32 RtBurn_GetCDStatus(void);
/*
* �������ƣ�RtBurn_GetCDStatus
* ��Ҫ����: ��ȡ��¼״̬
* ��    ��: ��
				
* ��    ������	
				
* �޸���־				
*		  20121109 ����add
*/

char * RtBurn_GetTDplayerPath(void);
/*
* �������ƣ�RtBurn_GetTDplayerPath
* ��Ҫ����: ��ȡ��ҵ���·��
* ��    ��: ��
				
* ��    ������	
				
* �޸���־				
*		  20130205 ����add
*/

td_s32 RtBurn_GetBackUpState(void);
/*
* �������ƣ�RtBurn_GetBackUpState
* ��Ҫ����:��ȡ����״̬
* ��       ��: 
				
* ��	  ����	DISK_BK_ING��ʾ���ڱ���
				
* �޸���־				
*			2012-10-19��sunlnע��
*/


td_s32 RtBurn_GetBurnIfStop(int _iDiskNo);
/*
* �������ƣ�RtBurn_GetBurnIfStop
* ��Ҫ����:��ȡ�ϵ�ʱ�Ƿ�ֹͣ��¼��
* ��       ��: 
				
* ��	  ����	1����ֹͣ��¼��
				
* �޸���־				
*			2012-10-19��sunlnע��
*/

td_s32 RtBurn_SetBurnIsStop(int _iDiskNo,int _iFlag);
/*
* �������ƣ�RtBurn_SetBurnIsStop
* ��Ҫ����:����ֹͣ��¼״̬
* ��       ��: 
				
* ��	  ����	1����ֹͣ��¼��
				
* �޸���־				
*			2012-10-19��sunlnע��
*/


td_s32 RtBurn_ClearStopInfo(int  _iDiskNo);
/*
* �������ƣ�RtBurn_ClearStopInfo
* ��Ҫ����:��������ļ�
* ��       ��: 
				
* ��	  ����	
				
* �޸���־				
*			2012-10-19��sunlnע��
*/
td_s32 RtBurn_StopOverLapBurn(int _iDiskNo);
/*
* �������ƣ�RtBurn_StopOverLapBurn
* ��Ҫ����:ֹͣ�ϵ縴�̣�����ֹͣ��ʱ�����ϵ縴�̣��ڿ�¼�������ô˺���ֹͣ��¼
* ��       ��: 
				
* ��	  ����	
				
* �޸���־				
*			2012-10-19��sunlnע��
*/
td_s32 RtBurn_ClearBurnCountInfo(int  _iDiskNo);
/*
* �������ƣ�RtBurn_ClearBurnCountInfo
* ��Ҫ����:�����¼��¼�����������ļ�
* ��       ��: 
				
* ��	  ����	
				
* �޸���־				
*			2012-10-19��sunlnע��
*/
td_s32 BkBurn_AddFileToBackUpList(td_u8* _pcFileName,td_s32 _iCdNum);
/*
* �������ƣ�BkBurn_AddFileToBackUpList
* ��Ҫ����:��¼���ļ����뱸�ݶ�����
* ��       ��: _iCdNum
				
* ��	  ����	
				
* �޸���־				
*			2012-10-19��sunlnע��
*/

td_s32 BkBurn_AddFileToConvertList(td_u8* _pcFileName);
/*
* �������ƣ�BkBurn_AddFileToConvertList
* ��Ҫ����:��¼���ļ�����ת��������
* ��       ��: _pcFileName ¼���ļ���
				
* ��	  ����	
				
* �޸���־				
*			2014-11-27��sunlnע��
*/

int RtBurn_GetDebugInfo(char *_cString);
/*
* �������ƣ�RtBurn_GetDebugInfo
* ��Ҫ����:��ȡ������Ϣ
* ��       ��: 
				
* ��	  ����	
				
* �޸���־				
*			2012-10-19��sunlnע��
*/

int RtBurn_ReleasePlayer(void);
/*
* �������ƣ�RtBurn_ReleasePlayer
* ��Ҫ����:�ͷŲ�������Player Ŀ¼��
* ��       ��: 
				
* ��	  ����	
				
* �޸���־				
*			2012-10-19��sunlnע��
*/
td_s32 RtBurn_GetDriverStateForUk(int _s32DiskNo);
td_s32 RtBurn_GetDriverState(int _s32DiskNo);
/*
* �������ƣ�RtBurn_GetDriverState
* ��Ҫ����:��ȡ����״̬
* ��       ��: 
				
* ��	  ����	
				
* �޸���־				
*			
*/
int RtBurn_CheckCdError(int _iCdNo);
/*
* �������ƣ�RtBurn_CheckCdError
* ��Ҫ����:��ȡ�����Ƿ��ǻ���
* ��       ��: ������
				
* ��	  ����	
				
* �޸���־				
*			
*/
int BigFile_CheckCdError(int _iCdNo);
/*
* �������ƣ�BigFile_CheckCdError
* ��Ҫ����:ֱ�����ʱ����ȡ�����Ƿ��ǻ���
* ��       ��: ������
				
* ��	  ����	
				
* �޸���־				
*			
*/

int RtBurn_UmountCD(int _iCdNo);
/*
* �������ƣ�RtBurn_UmountCD
* ��Ҫ����:ж�ع���
* ��       ��: ������
				
* ��	  ����	
				
* �޸���־				
*			
*/
int RtBurn_init_CDROMSerialNo(int _iCDROMNum);		
int RtBurn_GetCDSerialNo(int _iCDindex, td_u8* _cSerialNo);
int	RtBurn_UpdateCDSerialNo(int _iCDROMNum,int _iIsOverLap);
int RtBurn_UpdateFileTail_CDSerialNo(td_u8* _cFileName);
int RtBurn_ReadCDROMSerialNoValue4GUI (int _iDiskNo, const td_s8* _pcFileFullPath, td_s8* _pcCDROMSerialNoValue);
td_s32 RtBurn_CleanBurnStatus(void);//����¼״̬��λ
td_s32 RtBurn_GetConvertThreadState(void);//��ȡmp4ת���߳�״̬
int RtBurn_ListGetStatus(int _iDiskNo, int* _piStatus);

td_s32 RtBurn_SetDirectPolicy(BURN_TYPE_E _s32Type, td_s32 _s32Chn, td_s32 _s32DiskNo,td_s32 _s32Operation);
/*
������ 	    :   RtBurn_SetDirectPolicy
����	    :	 ��Ӳ��ʱ,����ֱ�̲���.
�������	:	 _s32Type:��¼����
					 	SINGLE_BURN=0,	//���̿�¼
						DOUBLE_BURN,  	//˫��ͬʱ��¼
						RECYCLE_BURN,  	//ѭ����¼
						BUTT_BURN,     	//�գ�����δ�μӿ�¼
						
			    _s32Chn:��¼ͨ���ţ���λ���á�
			    
			    _s32DiskNo: ��¼����ţ���λ���á�
			    _s32Operation Ϊ0�������̣�Ϊ1������			            
����ֵ	: 	 >=0 �ɹ�   -1 ʧ��

*/

int BurnComplete_ProcessDvdInfo(int _iDiskNo, int _iRtn);
/*
* �������ƣ�BurnComplete_ProcessDvdInfo
* ��Ҫ����:��¼�ڿ�һ��ͥ���ڼ䣬�������������ĺ����뻵��
* ��	   ��: 
					
* ��	  ����	
					
* �޸���־				
*			2015-04-10��xiejingע��
*/

int SetDvdInfo_Config();
/*
* �������ƣ�SetDvdInfo_Config
* ��Ҫ����:�ѹ��̵���Ϣд��Ӳ��
* ��	   ��: 
					
* ��	  ����	
					
* �޸���־				
*			2015-04-11��xiejingע��
*/

int GetDvdInfo_Config();
/*
* �������ƣ�GetDvdInfo_Config
* ��Ҫ����:��Ӳ�̶���������Ϣ
* ��	   ��: 
					
* ��	  ����	
					
* �޸���־				
*			2015-04-11��xiejingע��
*/

int DvdNumInfo_WriteConfig();
/*
* �������ƣ�DvdNumInfo_WriteConfig
* ��Ҫ����:��¼�ڿ�ͥ���ڼ䣬�������������ĺ����뻵�̣���������д��flash
* ��	   ��: 
					
* ��	  ����	
					
* �޸���־				
*			2015-04-11��xiejingע��
*/

int DvdNumInfo_ReadConfig();
/*
* �������ƣ�DvdNumInfo_ReadConfig
* ��Ҫ����:��Flash�ж��������ļ�����������д���Ӧ��ȫ�ֱ���
* ��	   ��: 
					
* ��	  ����	
					
* �޸���־				
*			2015-04-11��xiejingע��
*/

td_s32 RtBurn_SetBigFilePolicy(BURN_TYPE_E _s32Type, td_s32 _s32Chn, td_s32 _s32DiskNo,td_s32 _s32Operation);
/*
������ 	    :   RtBurn_SetDirectPolicy
����	    :	  ��Ӳ��ʱ,���ô��ļ���¼����.
�������	:	 _s32Type:��¼����
					 	SINGLE_BURN=0,	//���̿�¼
						DOUBLE_BURN,  	//˫��ͬʱ��¼
						RECYCLE_BURN,  	//ѭ����¼
						BUTT_BURN,     	//�գ�����δ�μӿ�¼
						
			    _s32Chn:��¼ͨ���ţ���λ���á�
			    
			    _s32DiskNo: ��¼����ţ���λ���á�
			    _s32Operation Ϊ0�������̣�Ϊ1������			            
����ֵ	: 	 >=0 �ɹ�   -1 ʧ��

*/

td_s32 Rtburn_StartDirectBurn(td_s32 _s32DiskNo);
/*
������ 	:	Rtburn_StartDirectBurn
����	    :	ie�Ͽ�����¼,��Ӳ��ʱ��ʼֱ�̽ӿ�,���һЩ��¼�����ĳ�ʼ��.
�������	:	 _s32DiskNo : ������  
����ֵ	: 	��=0 �ɹ�  -1 ʧ��

*/
td_s32 Rtburn_StartBigFileBurn(td_s32 _s32DiskNo);
/*
������ 	:	Rtburn_StartBigFileBurn
����	    :	ie�Ͽ�����¼,��Ӳ��ʱ�������ļ���¼�ӿ�,���һЩ��¼�����ĳ�ʼ��.
�������	:	 _s32DiskNo : ������  
����ֵ	: 	��=0 �ɹ�  -1 ʧ��

*/
td_s32 Rtburn_StartBigFileBurnEx(td_s32 _s32DiskNo,td_s32 _iIsOverLap);
/*
������ 	    :	Rtburn_StartBigFileBurnEx
����	    :	ui�Ͽ�ͥ,��Ӳ��ʱ�������ļ���¼�ӿ�,���һЩ��¼�����ĳ�ʼ��
�������	:	 _iCdNo : ������  _iIsOverLap:�Ƿ�ϵ粹��
����ֵ	: 	��=0 �ɹ�  -1 ʧ��

*/

int  Direct_AddUdfFile(int  _CdNo,char* _pcFileName,int _iFileType,int  _iFileLocate);
/*
������ 	  :	Direct_AddUdfFile
����	  :	�ڿ�¼�ļ�ʱ,���øýӿ������������ļ��������Ϣ,���ļ���,�ļ���ʼ��ַ,�ļ�����(Ŀ¼�����ļ�),�ļ�λ��(��Ŀ¼�»���OtherĿ¼��).
�������  :	 _iCdNo:������.  _pcFileName:Ҫ��¼���ļ���. _iFileType:�ļ�����,Ŀ¼�����ļ�. _iFileLocate:�ļ���ַ,�Ǹ�Ŀ¼������Ŀ¼�µ��ļ�.
����ֵ	  : 	 >=0 �ɹ�, -1 ʧ��

*/
int BigFile_CheckBurnList(int _iCdNo);
/*
������ 	  :	 BigFile_CheckBurnList
����	  :	    ��ȡ��¼���.
�������  :	 _iCdNo:������.
����ֵ	  :   ERR_RTBURN_FINISHED ��¼���, ERR_REC_DISK_FULL ������,
			 td_success �������ļ�, td_failure  ����û���ļ�.

*/
int BigFile_AddBurnFileList(int _iDiskNo);
/*
������ 	  :	 BigFile_AddBurnFileList
����	  :	  ���ӿ�¼���ж�ָ��.
�������  :	 _iDiskNo:������.
����ֵ	  :   >=0 �ɹ�, -1 ʧ��
*/
int BigFile_FillTempBurnList(int _iDiskNo);
/*
������    :	BigFile_FillTempBurnList
����	  :	    �ӿ�¼�б��ȡ¼����ӵ�ֱ�̶���..
�������  :	 _iDiskNo:������.
����ֵ	  : 	 >=0 �ɹ�, -1 ʧ��

*/
td_s32 BigFile_BurnComplete(td_s32 _s32DiskNo, td_s32 _s32CompleteType);
/*
������ 	  :   BigFile_BurnComplete
����	  :	     ����ʵʱ��¼�������߹��̿�¼��ɵ��ô˽ӿ�,��������ļ��Ŀ�¼�Լ�udf�ļ�ϵͳ�Ŀ�¼Ȼ�����.
�������  :	 _s32DiskNo:������  _s32CompleteType:���������߹��̿�¼���.
����ֵ	  : 	 >=0 �ɹ�, -1 ʧ��

*/
int BigFile_BurnOneTempFileEx(td_s32 _iCdNo);
/*
������ 	  :	 BigFile_BurnOneTempFileEx
����	  :	     ���ô˽ӿ�ֱ��һ��¼��.
�������  :	 _iCdNo:������
����ֵ	  : 	 >=0 �ɹ�, -1 ʧ��

*/
int BigFileBurn_Direct(int _iCdNo);
/*
������ 	  :	 BigFileBurn_Direct
����	  :	 ��ֱ�̶���templist������ȡ¼�����ֱ��.
�������  :	 _iCdNo:������
����ֵ	  : 	 >=0 �ɹ�, -1 ʧ��

*/

int  Direct_BurnFile(int  _iCdNo,char* _pcFileName,int _iEndFile);
/*
������ 	  :	Direct_BurnFile
����	  :	ֱ�ӿ�¼�ļ�,��һ���ļ��򿪺������ķ�ʽ���п�¼.
�������  :	 _iCdNo:������.  _pcFileName:Ҫ��¼���ļ���. _iEndFile:�Ƿ�Ҫ��������ļ�,���Ҫ����,�ļ�β����32KB���򲹳�0.���������,�ļ�β����32KB�����ݲ���¼.
����ֵ	  : 	 >=0 �ɹ�, -1 ʧ��

*/
int  Direct_EndUdfFile(int  _CdNo,int _iFileType);
/*
������ 	  :	Direct_EndUdfFile
����	  :	 ����һ���ļ���¼��ɺ�,���ô˽ӿ������µ�ǰ��¼�ļ��Ľ�����ַ.
�������  :	 _iCdNo:������. _iFileType:�ļ�����
����ֵ	  : 	 >=0 �ɹ�, -1 ʧ��

*/
int BigAacFileBurn_Direct(int _iCdNo);
/*
������    :  BigAacFileBurn_Direct
����	  :	 ����¼����Ƶ���ļ���,���˽ӿڿ�¼���ļ���Ӧ��aac�ļ�
�������  :	 _iCdNo:������  
����ֵ	  :  >=0 �ɹ�, -1 ʧ��

*/
int BigFile_GetNotesFielName(int _iCdNo,char *_pcFileName);
/*
������ 	  :	 BigFile_GetNotesFielName 
����	  :	 ��Ӳ����Ѷ��¼���ļ�ʱ��ȡNotes.doc�ļ�
�������  :	 _iCdNo:������
			 _pcFileName:�ļ���
����ֵ	  :  >=0 �ɹ�, -1 ʧ��
*/

int  BigFile_BurnOtherFile(int  _CdNo);
/*
������ 	  :	 BigFile_BurnOtherFile 
����	  :	 ��Ӳ����Ѷ��¼���ļ�ʱ��¼������Ƶ�ļ���������������ļ�.
�������  :	 _iCdNo:������
����ֵ	  :  >=0 �ɹ�, -1 ʧ��
*/
int BigFile_BurnOtherDir(int _s32DiskNo,char * _pcDirName);
/*
������ 	  :	BigFile_BurnOtherDir
����	  :	����ֱ��Other�ļ���.
�������  :	 _iCdNo:������. _pcDirName:Other �ļ�������·��
����ֵ	  :  >=0 �ɹ�, -1 ʧ��

*/

int BigFile_BurnOtherDirEx(int _s32DiskNo,int _iOtherDirIndex);
/*
������ 	  :	BigFile_BurnOtherDirEx
����	  :	����ֱ��Other�ļ�����߳���Notes.doc��config.ini�������ļ�.
�������  :	 _s32DiskNo:������. _iOtherDirIndex:Other �ļ��е�����
����ֵ	  :  >=0 �ɹ�, -1 ʧ��

*/

int BigFile_BurnNotesFile(int _s32DiskNo,char * _pcDirName);
/*
������ 	  :	BigFile_BurnNotesFile
����	  :	����ֱ��Other�ļ�����ߵ�Notes.doc�ļ���config.ini�ļ�.
�������  :	_s32DiskNo:������. _pcDirName:Other �ļ�������·��
����ֵ	  :  >=0 �ɹ�, -1 ʧ��

*/

void BigFile_DeleteConvertVideo(BURN_TYPE_E _s32Type,td_s32 _s32DiskNo);
/*
������ 	  :  BigFile_DeleteConvertVideo
����	  :	 ���̿�¼���̺�,Ȼ��ɾ��ConvertVideoĿ¼�µ�ת���ļ�.
�������  :	 _ s32Type:��¼����  _ s32DiskNo:������
����ֵ	  :  >=0 �ɹ�, -1 ʧ��

*/
int BigFile_Add2TempBurnList(TBurnFileInfo stFileInfo, int _iDiskNo);
/*
������ 	    :    BigFile_Add2TempBurnList(TBurnFileInfo stFileInfo, int _iDiskNo)
����	    :	 �ӿ�¼�������ȡ¼����ӵ�ֱ�̶�����
�������	:	 stFileInfo:¼����Ϣ   _iDiskNo:������
����ֵ	    : 	 >=0 �ɹ�, -1 ʧ��

*/
td_s32 BkBigFile_BurnComplete(td_s32 _s32DiskNo, td_s32 _s32CompleteType);
/*
������ 	  :  BkBigFile_BurnComplete
����	  :	 ���̱��������߹��̱�����ɵ��ô˽ӿ�,��������ļ��Ŀ�¼�Լ�udf�ļ�ϵͳ�Ŀ�¼Ȼ�����.
�������  :	 _s32DiskNo:������  _s32CompleteType:���������߹��̿�¼���.
����ֵ	  :   >=0 �ɹ�, -1 ʧ��

*/
int  BkBigFile_BurnOtherFile(int  _CdNo);
/*
������ 	  :	 BkBigFile_BurnOtherFile 
����	  :	 ���̱��ݴ��ļ�ʱ��¼������Ƶ�ļ���������������ļ�.
�������  :	 _iCdNo:������
����ֵ	  :  >=0 �ɹ�, -1 ʧ��
*/
int  Direct_BurnDirFile(int  _CdNo,char * _pcDirName,int _iDirIndex);
/*
������ 	  :	 Direct_BurnOtherFile
����	  :	 ����Ӳ������¿�¼����Ƶ�ļ�����������ļ�.
�������  :	 _iCdNo:������
����ֵ	  :  >=0 �ɹ�, -1 ʧ��

*/
int Direct_GetBurnState(int  _CdNo);
/*
������    :	Direct_GetBurnState 
����	  :	����Ӳ��ģʽ��,��ȡֱ��״̬.
�������  :	 _iCdNo:������
����ֵ	  :  ERR_RTBURN_FINISHED �����ļ�ת�����, ERR_REC_DISK_FULL:������
             VIDEO_CONVERT_FINISH:һ���ļ�ת�����

*/


int Direct_CreatMp4Buffer(int _iCdNo);
/*
������ 	  :	Direct_CreatMp4Buffer
����	  :	��Ӳ��ֱ��ʱ,����ѭ��buffer���ڱ���mp4����.
�������  :	_iCdNo:������
����ֵ	  : >=0 �ɹ�, -1 ʧ��
*/
int RtBurn_CreatUdfFs(int _iCdNo);
/*
������ 	  :	RtBurn_CreatUdfFs
����	  :	���̿�¼�����е�����Ƶ�ļ���,���ô˽ӿڴ���udf�ļ�ϵͳ.
�������  :	_iCdNo:������
����ֵ	  : >=0 �ɹ�, -1 ʧ��
*/
int RtBurn_InitDirectBurn(int _iCdNo);
/*
������ 	  :	RtBurn_InitDirectBurn
����	  :	��ʼ��ֱ�����õı���.
�������  :	_iCdNo:������
����ֵ	  : >=0 �ɹ�, -1 ʧ��
*/
int rec_CheckDiskIsExist();
/*
������ 	  :	rec_CheckDiskIsExist
����	  :	��ȡ��û��������Ӳ��.
�������  :	��
����ֵ	  : >=0 ���ؿ��õĴ���, -1 û�п��õĴ���
*/
int RtBurn_ListGetType(int _iDiskNo, BURN_TYPE_E* _piType);
int Direct_SetMp4FileHeader(unsigned int _uiCDNo, unsigned int _uiMdatSize, int _iConvertType);
/*
������ 	  :	Direct_SetMp4FileHeader
����	  :	��ȡMP4�ļ�ͷ.
�������  :	_CdNo:������ _uiMdatSize:mp5����С,_iConvertType:ת������ 
����ֵ	  : >=0 �ɹ�, -1 ʧ��
*/
int  Direct_SetMp4FileTail(unsigned int _uiCDNo,int _iConvertType);
/*
������ 	  :	Direct_SetMp4FileTail
����	  :	��ȡMP4�ļ�β.
�������  :	_uiCDNo:������ 
����ֵ	  : >=0 �ɹ�, -1 ʧ��
*/
int Direct_DestoryMp4Buffer(int _iCdNo);
/*
������ 	  :	Direct_DestoryMp4Buffer
����	  :	����ѭ��buffer
�������  :	_CdNo:������
����ֵ	  : >=0 �ɹ�, -1 ʧ��
*/
int Direct_InitMp4Buffer(int _iCdNo);
/*
������ 	  :	Direct_InitMp4Buffer
����	  :	��ʼ��ѭ��buffer
�������  :	_CdNo:������
����ֵ	  : >=0 �ɹ�, -1 ʧ��
*/

int Direct_MakeUpDvd();
/*
������ 	  :	Direct_MakeUpDvd
����	  :	��Ӳ��ֱ��ʱ,�ϵ��޸�����
�������  :	��
����ֵ	  : >=0 �ɹ�, -1 ʧ��
*/
int RtBurn_UpdateMp4FileTime(char *_cFileName);
/*
������ 	  :	RtBurn_UpdateMp4FileTime
����	  :	����mp4ʱ��
�������  :	_cFileName:�ļ���
����ֵ	  : >=0 �ɹ�, -1 ʧ��
*/
int BigFile_WriteBuffer(unsigned int _uiDevNo, unsigned char* _pcbuf, unsigned int _uiBufferLen);
/*
������ 	  :	BigFile_WriteBuffer
����	  :	��Ӳ��ʱ��ѭ��buffer���д����.
�������  :	_uiDevNo:������._pcbuf:����._uiBufferLen:��������
����ֵ	  : >=0 �ɹ�, -1 ʧ��
*/
int BigFile_ReadDisk(unsigned int _uiDevNo, unsigned long long  _uiAddress, unsigned char* _pcbuf, unsigned long long _uiLen);
/*
������ 	  :	BigFile_ReadDisk
����	  :	�ӹ�������������
�������  :	_uiDevNo:������._uiAddress:����ļ�ͷ��ַ._pcbuf:�����е�����._uiLen:Ҫ�������ݳ���
����ֵ	  : >=0 �ɹ�, -1 ʧ��
*/
int Direct_SetMp4FileHeader(unsigned int _uiCDNo, unsigned int _uiMdatSize, int _iConvertType);
/*
������ 	  :	Direct_SetMp4FileHeader
����	  :	��ȡMP4�ļ�ͷ.
�������  :	_CdNo:������ _uiMdatSize:mp4����С,_iConvertType:ת������ 
����ֵ	  : >=0 �ɹ�, -1 ʧ��
*/

int BigFile_BurnMp4FileTail(int _iCdNo);
/*
������ 	  :	BigFile_BurnMp4FileTail
����	  :	��Ӳ��ʱ��¼mp4�ļ�β
�������  :	_iCdNo:������.
����ֵ	  : >=0 �ɹ�, -1 ʧ��
*/

int BigFile_AddMp4TailToHashList(int _iCdNo);
/*
������ 	  :	BigFile_AddMp4TailToHashList
����	  :	��Ӳ��ʱ��¼ʱ,��mp4�ļ�β��ӵ�����hash������
�������  :	_iCdNo:������.
����ֵ	  : >=0 �ɹ�, -1 ʧ��
*/
int BigFile_StartRepair(int _iCdNo);
/*
������ 	  :	BigFile_StartRepair
����	  :	��Ӳ��ֱ��,�ϵ��޸�����¼״̬�óɴ��״̬
�������  :	_iCdNo:������.
����ֵ	  : >=0 �ɹ�, -1 ʧ��
*/
int BigFile_FinishRepair(int _iCdNo);
/*
������ 	  :	BigFile_FinishRepair
����	  :	��Ӳ��ֱ��,�ϵ��޸���ɺ󽫿�¼״̬�óɿ���
�������  :	_iCdNo:������.
����ֵ	  : >=0 �ɹ�, -1 ʧ��
*/
int BigFile_SetMD5Info(int _iCdNo);
/*
������ 	  :	BigFile_SetMD5Info
����	  :	���öϵ��ϵ��޸���md5ֵ
�������  :	_iCdNo:������.
����ֵ	  : >=0 �ɹ�, -1 ʧ��
*/
int BigFile_RepairMp4FileMd5(int _iCdNo);
/*
������ 	  :	BigFile_RepairMp4FileMd5
����	  :	��Ӳ��ֱ��,�ϵ��ϵ��޸�md5ֵ
�������  :	_iCdNo:������.
����ֵ	  : >=0 �ɹ�, -1 ʧ��
*/
int BigFile_CreatMd5File(int _iCdNo);
/*
������ 	  :	BigFile_CreatMd5File
����	  :	��¼���ļ�ʱ,����md5�ļ�
�������  :	_iCdNo:������.
����ֵ	  : >=0 �ɹ�, -1 ʧ��
*/
int BigFile_ReleaseDVDDevice(int _iCdNo);
/*
������ 	  :	BigFile_ReleaseDVDDevice
����	  :	�ͷŹ����豸��Դ�ӿ�
�������  :	_iCdNo:������.
����ֵ	  : >=0 �ɹ�, -1 ʧ��
*/

int BigFile_SetCdTitle(int _iDiskNo);
/*
������ 	  :	BigFile_SetCdTitle
����	  :	���ù��̱�ǩ
�������  :	_iDiskNo:������
����ֵ	  : >=0 �ɹ�, -1 ʧ��
*/
int GB2312ToUNICODE16(const unsigned char *_Gb2312, unsigned char *_Unicode16, int _iBufSize);
/*
������ 	  :	GB2312ToUNICODE16
����	  :	GB2312ת����UNICODE16
�������  :	_Gb2312:GB2312�ַ�._Unicode16:unicode�ַ�,_iBufSize:unicode�ַ�����
����ֵ	  : >=0 �ɹ�, -1 ʧ��
*/
int Direct_SetMd5Name(int _iCdNo,char *_pcMd5FileName);
/*
������ 	  :	Direct_SetMd5Name
����	  :	����md5�ļ�������
�������  :	_iCdNo:������._pcMd5FileName:md5�ļ���
����ֵ	  : >=0 �ɹ�, -1 ʧ��
*/
int Direct_GetMd5Name(int _iCdNo,char *_pcMd5FileName);
/*
������ 	  :	Direct_GetMd5Name
����	  :	��ȡmd5�ļ�������
�������  :	_iCdNo:������._pcMd5FileName:md5�ļ���
����ֵ	  : >=0 �ɹ�, -1 ʧ��
*/
int BigFile_BurnMd5File(int _iCdNo);
/*
������ 	  :	BigFile_BurnMd5File
����	  :	��¼md5�ļ�
�������  :	_iCdNo:������.
����ֵ	  : >=0 �ɹ�, -1 ʧ��
*/

int Direct_BurnMp4Tail(int _iCdNo);
/*
������ 	  :	Direct_BurnMp4Tail
����	  :	�ϵ��޸�ʱ��¼�ļ�β
�������  :	_iCdNo:������.
����ֵ	  : >=0 �ɹ�, -1 ʧ��
*/
void* Direct_RepairVideo(void* _iCdNo);
/*
������ 	  :	Direct_RepairVideo
����	  :	�ϵ��޸��߳�
�������  :	_iCdNo:������.
����ֵ	  : >=0 �ɹ�, -1 ʧ��
*/
int BigFile_SetStartConvertFile(int _iCdNo,int _iStartConvertFile);
/*
������ 	  :	BigFile_SetStartConvertFile
����	  :	����sdv�ļ���ʼת��mp4�ļ�
�������  :	_iCdNo:������ _iStartConvertFile:�Ƿ�ʼת��
����ֵ	  : >=0 �ɹ�, -1 ʧ��
*/

int BigFile_GetStartConvertFile(int _iCdNo);
/*
������ 	  :	BigFile_GetStartConvertFile
����	  :	��ȡsdv�ļ��Ƿ�ʼת��mp4�ļ�
�������  :	_iCdNo:������
����ֵ	  : >=0 �ɹ�, -1 ʧ��
*/
int BigFile_CheckStartConvertFile(int _iCdNo);
/*
������ 	  :	BigFile_CheckStartConvertFile
����	  :	����Ƿ��Ѿ���ʼת��
�������  :	_iCdNo:������
����ֵ	  : >=0 �ɹ�, -1 ʧ��
*/
int BigFile_GetBurnChn(int* _piChnList);
/*
������ 	  :	BigFile_GetBurnChn
����	  :	��ȡ��¼��һ���ļ��Ŀ�¼ͨ��
�������  :	_piChnList:��ȡ��¼��һ���ļ��Ŀ�¼ͨ��
����ֵ	  : 
*/
int Direct_RecoveryConfigIni();
/*
*����: Direct_RecoveryConfigIni
*����: ��Ӳ��ֱ��ʱ,����nand�ϵ�config.ini�ļ�������Ӳ����,���ڶϵ��޸�
*����: ��
*		   
*���: >= 0 �ɹ�,-1 ʧ��

*/
int DirectBurn_GetState(int _iCdNo);
/*
*����: DirectBurn_GetState
*����: ��Ӳ��ֱ��ʱ,��ȡ��¼״̬.
*����: _iCdNo :������
*		   
*���: ����ֱ��״̬

*/
int DirectBurn_SetState(int _iCdNo,int _iDirectBurnState);
/*
*����: DirectBurn_SetState
*����:  ��Ӳ��ֱ��ʱ,���ÿ�¼״̬
*����: _iCdNo:������. _iDirectBurnState:ֱ��״̬
*		   
*���: >= 0 �ɹ�,-1 ʧ��

*/

#endif /*_RECORDER_H_*/


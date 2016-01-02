/*******************************************************************
�ļ���	:Storage.h
��˾	:������ΰҵ����Ƽ����޹�˾
������	:������
��������:2008-08-28
��Ҫ����:��洢��صı�������Ķ��壬�洢ģ��ӿں���ԭ��
�޸ļ�¼:2008-08-28,������������
        
******************************************************************/
#ifndef STORAGE_H_
#define STORAGE_H_

#include <stdio.h>
#include <sys/time.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>

#include "public_def.h"

//#define MAX_DVD_NUM		2		//֧������DVD��¼������
#define PAGE_SHOW_NUM		20		//¼���ѯ�����һҳ�����ʾ����Ŀ��
#if 0
#define DATA_BUFFER_LEN		512 * BYTES_1K 	//һ֡����󳤶�

#define VOD_BUFFER_LEN		512 * BYTES_1K 	//VOD��������С
#else
#define DATA_BUFFER_LEN MAX_FRAME_SIZE

#define VOD_BUFFER_LEN MAX_FRAME_SIZE
#endif


//#define MAX_RESERVED_INFO_LEN	64	//¼���ļ���Ϣ�е�Ԥ����Ϣ����


//������ 091105 �����Զ������͵ķ�Χ
#define CUSTOM_RECORD_NAME_LEN	16	//�Զ���¼���������ĳ���
#define MIN_CUSTOM_RECORD_TYPE	32	//�Զ���¼�����͵���Сֵ
#define MAX_CUSTOM_RECORD_TYPE	64	//�Զ���¼�����͵����ֵ
#define ATM_RECORD_TYPE         34  //�Զ���atm¼������
#define CUSTOM_RECORD_NUM		(MAX_CUSTOM_RECORD_TYPE - MIN_CUSTOM_RECORD_TYPE)
									//�Զ���������Ŀ
#define MAX_RECORD_TYPE	MAX_CUSTOM_RECORD_TYPE //¼�����͵����ֵ
									

#define IS_FS_ERROR			(EIO == errno || EROFS == errno)	//�Ƿ�Ϊ���̶�д����

#define REC_IFRAME_INDEX_MAGIC_NUMBER   0x0123abcd//wangsong,check the file contains iFramIndex or not
#define REC_FALSE_FRAME_FLAG			     0x7788
#define REC_APPEND_CHAR_FLAG			0x1199aabb

#define RECORDER_BLOCK_FILE		"/dev/sr0"
#define RECORD_TEMP_DIRECTORY(iDiskNo)	  rec_TempRecorderPath(iDiskNo) 	//������ 100802 �������ַ����޸�Ϊ����
#define RECORD_TEMP_MD5DIRECTORY(iDiskNo) rec_TempRecorderMd5Path(iDiskNo)
//add by gyn
#define RECORD_CONVERTVIDEO_DIRECTORY   rec_ConvertRecorderPath()
	

#define RECORD_DVDINFO_DIRECTORY    rec_DvdInfoFile()
#define RECORD_MID_DIRECTORY(iDiskNo)	rec_MidRecorderPath(iDiskNo) //add by gyn	
#define RECORD_FIN_DIRECTORY(iDiskNo)	rec_FinRecorderPath(iDiskNo) //add by gyn	
#define RECORD_AUD_DIRECTORY(iDiskNo)	rec_AudRecorderPath(iDiskNo) //add by gyn	

#define RECORD_TRUEFIN_DIRECTORY(iDiskNo) rec_TrueFinRecorderPath(iDiskNo) 
//add end
//������������������ļ����ļ�Ӱ���������Լ���һ���ļ��Ŀ�¼

#define RECORD_OVERLAP_DIRECTORY rec_OverLapRecorderPath() //zhuangzhibing �ϵ縴��

#define MAX_RECORDER_DISK_VOLUME	4200 * BYTES_1K
#define FRAME_INDEX 				//������֡��λ

#define MAX_HOLIDAY_NUM 			10	//dce add 20130320,���������
#define	HOLIDAY_NAME_LENTH			32	//�����������ֵ

#ifdef TD_DEBUG
#define MAX_IMAGE_NUM_PER_DAY	50000
#else
#define MAX_IMAGE_NUM_PER_DAY	3000	//ÿ������ץ�ĵ��ļ���Ŀ
#endif
#define MAX_IMAGE_NUM_PER_DEL	500	    //ÿ�θ���ɾ�������ץ���ļ���Ŀ
#define MAX_IMAGE_NUM			100000	//ͼƬ����������ﵽ�����������ʼ����
#define OVERWRITE_IMAGE_INTERVAL	86400	//ͼƬ���Ǽ��
#define OVERWRITE_LIMIT		    100     //����ɾ��ÿ�β�ѯ�ļ���


/*
	�ڷ���¼�񸲸ǻ����ؽ�����ʱ���øú���֪ͨATMģ��
	_iType 	0: ɾ���ļ�  			�ļ���������_ucFileName[0]��
	        1: �ؽ����������ļ���	���ļ���������_ucFileName[0]�У����ļ���������_ucFileName[1]��
	        2: �ؽ������ļ���δ���� �ļ���������_ucFileName[0]��
	        3: �ؽ���������
*/

typedef td_s32 (*REC_NOTIFY_TO_ATM)(char* _ucFileName[2],int _iType);
typedef int (*MainTimeChnPara)(int _iChn);
typedef td_s32 (*SetSmartRecCallBack)(td_s32 _iChn, td_s32 _iType);

#if 0//cwm_todo
//�����ַ���Ϣ�ṹ
typedef struct
{
	td_s32		 m_iFlag;
	td_u32 		 m_iSize;
	td_u8		 m_pcCharInfo[0];
}TAppendCharInfo;
//I֡������Ϣ�ṹ
typedef struct
{
	time_t 		m_iTimeNow;
	td_u32		m_iPos;
	td_u32 		m_iSign;//0����δ��ǣ�1������,2-�������к�//add by gyn
	td_u32      m_iVdeoSize;
	td_u8		m_cTagName[64];//¼���ǩ��
}TIFrameIndexInfo;
 

 //����֡ͷ�ṹ��
typedef struct
{
	S_FrameHeader  	m_stHead;//��ͷ
	td_s32 			m_iNum;//I֡��Ŀ
	td_s32			m_iInfoSize;//I֡��Ϣ��С
	td_s32          m_iMemNum;
}TIFrameIndexHead;

//����֡β�ṹ��
typedef struct
{
	td_s32		m_iFlag;
	td_s32      m_iSize;//����֡��С
}TIFrameIndexTail;
#endif//cwm_todo
//�����������ṹ��
typedef struct
{
	unsigned char m_ucVideoChn; //��Ƶͨ����
	unsigned char m_ucHasAudioStat; //�Ƿ�����Ƶ (0--����Ƶ1-����Ƶ)
	unsigned short m_usFrameNo; //֡�ŵĵ�16λ
}TAudioTagInfo;

//�������
typedef enum
{
	BEGIN = 0,		//��ʼ����
	COMMIT,			//�ύ����
	ROLLBACK,		//�ع�����
	END,			//��������
}TTransaction;

//¼�����ͣ���REC_NONE�⣬����ԽС�����ȼ�Խ��
/*������ 091203 Ϊ֧���Զ���¼�����ͣ���ԭ����TRecordType����ΪTBasicRecordType��
 *���µ�TRecordType����Ϊtd_s32
 */
//typedef td_s32 TRecordType;

typedef enum
{
	REC_NONE = 0,    //��¼��
	REC_MANUAL,      //�ֶ�¼��
	REC_TIMING,      //��ʱ¼��
	REC_PORT,        //�˿ڱ���¼��
	REC_MD,          //�ƶ���ⱨ��¼��,Motion Detect
	REC_VL,			 //Video Lost����Ƶ��ʧ����¼��һ���Ǳ�����ͨ������
	REC_AL,			 //Audio Lost; 120229 added by lc
	REC_OD,			 //20130305 SUN Wei add for OD alarm
	REC_BASIC_TYPE,	 //¼�������������Ҫ�������ͣ����ڸ�ֵ������ӣ���Ҫ���ڽ�������
	REC_MP = 31,//�����ͽ������Ŷӣ�ʵ������ΪMD
	REC_VCA = 32,
	REC_ATM = 34,	 //����¼��	
	REC_SNAPEX = 40//���ץ������
}TBasicRecordType;

//�ж�ĳ��¼�������Ƿ񱨾�¼��
#define REC_ALARM(type)		(type == REC_PORT || type == REC_MD || type == REC_VL || type == REC_AL || type == REC_OD)
#define REC_CSTM(type)		(type >= MIN_CUSTOM_RECORD_TYPE && type <= MAX_CUSTOM_RECORD_TYPE && type != ATM_RECORD_TYPE)//wangsong, atm, 20120917


#if 0
//��ƵԴ�豸����
typedef enum
{
	DEV_CAMERA,		//����¼�������
	DEV_NVS,		//�����豸��������Ƶ������
	DEV_IPC,		//�����豸�����������
}TDeviceType;
#endif
#if 0
//�ļ������ṹ
typedef struct
{
	td_u64	m_ulFileIndex;					//�ļ�������
	td_u8	m_ucChannelNo;					//ͨ����
	TFileType	m_eFileType;				//�ļ�����,TFileType
	TRecordType	m_eRecordType;				//¼������,TRecordType
	td_u64 	m_eDevType;						//��ƵԴ�豸���� 
	td_s32 	m_iRecAttr;						//¼���ļ������ԣ��ò�ͬ¼������Ȩֵ�ĳ˻�����ʾһ��¼���ļ������еĶ�������
	td_u8	m_ucFileName[FILE_NAME_LEN];	//�ļ���������·��
	td_u8	m_ucFileNameSed[FILE_NAME_LEN];//����¼���ļ���
	td_u32	m_uiFileSize;					//�ļ���С����λBYTES
	time_t	m_iStartTime;					//¼��ʼʱ��
	time_t	m_iStopTime;					//¼�����ʱ��
	td_u8	m_cReserved[MAX_RESERVED_INFO_LEN];	//Ԥ����Ϣ����������Զ�����Ϣ	
}TFileInfo;
#endif
//��ѯ�����ṹ
typedef struct
{
	td_u64		m_ulFileIndex;					//�ļ�������
	td_u8		m_ucChannelNo;					//ͨ����
	td_u8		m_ucFileType;					//�ļ�����
	td_u8		m_ucRecType;					//¼������
	td_u64		m_ucDevType;					//��ƵԴ�豸����
	time_t		m_iStartTime;					//ʱ�����ʼʱ��
	time_t		m_iStopTime;					//ʱ��ν���ʱ��
	td_u8		m_cReserved[MAX_RESERVED_INFO_LEN];	//Ԥ����Ϣ����������Զ�����Ϣ	
	td_u32		m_uiPageNo;						//��ѯ���ҳ��,��0��ʼ
	td_u32		m_uiPageSize;					//ÿҳ��Ŀ��
	td_s32		m_uiTotalNum;					//����Ŀ��
	td_u32		m_uiShowNum;					//����ʾ����Ŀ��
	TFileInfo	m_stFileInfo[PAGE_SHOW_NUM];	//�ļ���Ϣ
}TQuery;

//����¼��ʱ���
typedef struct
{
	td_u32		m_blSegmentEnable;					//��ʱ��ε�ʹ��
	td_u32		m_uiStartHour;						//��ʼʱ
	td_u32		m_uiStartMin;						//��ʼ��
	td_u32		m_uiStopHour;						//����ʱ
	td_u32		m_uiStopMin;						//������
	td_u8		m_blTimingEnable;				//��ʱ¼��ʹ��
	td_u8		m_blPortEnable;					//�˿ڱ���¼��ʹ��
	td_u8		m_blMDEnable;					//�ƶ���ⱨ��¼��ʹ��
	td_u8		m_blVLEnable : 1;					//��Ƶ��ʧ����¼��ʹ��
	td_u8		m_blODEnable : 1;					//��Ƶ�ڵ�����¼��ʹ��
	td_u8       m_blMPEnable : 1;               //�����ұ���¼��ģ��ʹ��
	td_u16      m_TemplateType;                     //SUN Wei add record Template end
}TSchedule;


//¼�����
typedef struct
{
	td_u8				m_ucChannelNo;				//ͨ����
	TRecordType			m_eRecordType;				//¼������
	td_u8				m_blScheduleEnable;			//�Ƿ�����¼��ģ��
	td_u8				m_blTimingEnable;			//��ʱ¼��ʹ��
	td_u8				m_blPortEnable;				//�˿ڱ���¼��ʹ��
	td_u8				m_blMDEnable;				//�ƶ���ⱨ��¼��ʹ��
	td_u8				m_blVLEnable : 1;				//��Ƶ��ʧ����¼��ʹ��
	td_u8               m_blODEnable : 1;               //��Ƶ�ڵ�����¼��ʹ��
	td_u8		        m_blMPEnable : 1;               //�����ұ���¼��ģ��ʹ��
	td_u8				m_blPreEnable;				//Ԥ¼ʹ��
	td_u8				m_ucPreTime;				//Ԥ¼ʱ��
	td_u8				m_blDelayEnable;			//��¼ʹ��
	td_u32				m_uiDelayTime;				//��¼ʱ��
	TSchedule			m_stSchedule[7][MAX_TIME_SEGMENT];	//����¼��ģ��
}TRecordParam;

//20130327 ����add
typedef struct 
{
	td_s32 m_iStoreTime;// ¼�񱣴�ʱ����0~60����λ����
	td_s32 m_iPickFrame;//��֡¼��
	td_s32 m_iAudioStat;//��¼��Ƶ
	td_s32 m_iRedundRec;//����¼��
	td_s32 m_iSubRec;//������¼��
	td_s32 m_iSubStoreTime;//����������ʱ��
} TChnRecPara;


#if 0
//�������ڵ�
typedef struct
{
	td_s16				m_sFrameType;				//֡����
	td_s16				m_sFramePos;				//֡�ڻ�������������λ��
	td_s32				m_iFrameSize;				//֡��С
}TBufferNode;
#endif

//������ 100120 �µ�ץ�ķ�ʽ��������Ҫ����ṹ��
//#if 0
//ץ�Ľṹ��
typedef struct td_Snap_S								
{
	int  		iChn;				//��Ƶͨ����
	int  		iPicChn;				//ץ��ͨ����
	int  		iEnable; 			//ץ��ʹ�ܱ�־
	//FILE* 	pFile;				//ץ���ļ���� 20100919 // dxlɾ���ļ����(������й©)
	//TFileInfo	stInfo;				//ͼƬ�ļ�����
	td_u8	ucFileName[128];		//�ļ��� ȫ·��
	pthread_mutex_t	stMutex;		//ץ�Ļ���������Ҫ���ڱ����ļ���	
}TD_SNAP_S;
//#endif

//dce add 20130320,�������ò���
typedef struct	
{
	int m_iId;   //���ձ��
	char m_strHolidayName[HOLIDAY_NAME_LENTH + 1];  //��������
	int m_iType;   //�����������ͣ���Ϊ����(1)���·�(2)������(3)
	int m_iStatus;  //0��������1��ʾ����
	int m_iStartFirst;    //ͨ�ò���
	int m_iStartSecond;   //ͨ�ò���
	int m_iStartLast;     //ͨ�ò���,���·�ʱԤ��
	int m_iEndFirst;
	int m_iEndSecond;
	int m_iEndLast;
}THolidayInfo;

//////////////¼���ǩ���//////////////
typedef struct
{
	td_u32 	m_iTagTime;
	td_u8 	m_cTagName[64];
}TTagInfo;
////////////////////////////////////////

td_s32 rec_StartAlarmRecord(td_s32 _iCh, TRecordType _eRecType, td_u64 _ulTrigger);

#define rec_StartRecord(_iCh, _eRecType) rec_StartAlarmRecord(_iCh, _eRecType, -1)

td_s32 rec_UpdateAlarmRecord(td_s32 _iCh, TRecordType _eRecType, td_u64 _ulTrigger);

#if 0
td_s32 rec_StartRecord(td_s32 _iCh, TRecordType _eRecType);
/*
 * �������ƣ�StartRecord
 * ��Ҫ����: ��ʼ¼��
 * ��	  �룺
 * 			_iCh,ͨ����,0~15
 * 			_eRecType,¼������,TRecordType
 * ��	  ����
 * 		ERR_REC_WRONG_PARAM,����Ĳ���
 * 		ERR_REC_SUCCESSFUL,��ʼ¼��ɹ�
 * 		ERR_REC_OTHER_RECORDING,��ͨ�����ڽ�����������¼��,�������¼��
 * 		ERR_REC_DISK_FULL,������
 * 		ERR_REC_NO_DISK,�޿��ô���
 * 		ERR_REC_DISABLED_TYPE,�ƶ���ⱨ��¼��δʹ��
 * �޸���־��
 * 			2008-08-28,������,����
 */
#endif
td_s32 rec_StopRecord(td_s32 _iCh,TRecordType _eRecType);
/*
 * �������ƣ�StopRecord
 * ��Ҫ������ֹͣ¼�����ֹͣĳ�����͵�¼����б������ȼ��͵����������Ŷӣ���������ʼ�����͵�¼��
 * ��	  �룺
 * 			_iCh,ͨ���ţ�0~15
 * 			_eRecType,¼������,TRecordType
 * ��	 ����
 * 			ERR_REC_WRONG_PARAM,����Ĳ���
 * 			ERR_REC_SUCCESSFUL,ֹͣ¼��ɹ�
 * 			ERR_REC_NONE_RECORDING,��ǰδ��¼��
 * 			ERR_REC_WRONG_TYPE,ֹͣ¼�����ʹ���
 * �޸���־��
 * 			2008-08-28,������,����
 */

td_s32 rec_ForcePackage(td_s32 _iCh);
/*
 * �������ƣ�ForcePackage
 * ��Ҫ��������ĳ��ͨ��ǿ�ƴ��
 * ��	  �룺
 * 			_iCh,ͨ���ţ�0~15
 * ��	 ����
 * 			ERR_REC_WRONG_PARAM,����Ĳ���
 * 			ERR_REC_SUCCESSFUL,ֹͣ¼��ɹ�
 * 			ERR_REC_NONE_RECORDING,��ǰδ��¼��
 * �޸���־��
 * 			2009-12-01,������,����
 */

 
td_s32 rec_SnapShot(td_s32 _iCh, td_s32 _iSnapType, char *_strFileName, td_u64 _ulTrigger);
/*
 * �������ƣ�SnapShot
 * ��Ҫ������ץ��ͼƬ
 * ��	  �룺
 * 			_iCh,ͨ���ţ�0~MAX_CHANNEL_NUM
 * 			_iSnapType,ץ������,TRecordType��16λ���ϣ�ÿλ��ʾһ�ֱ������ͣ��Դ˱�ʾ������
 			_strFileName:ץ��ͼƬ����dxl 20110805
 			_ulTrigger,���������Ĵ���Դ����λ��ʾ��ֵΪ-1ʱ��Ч
 * ��	 ����
 * 			ERR_REC_WRONG_PARAM,����Ĳ���
 * 			ERR_REC_SUCCESSFUL,ץ�ĳɹ�
 * �޸���־��
 * 			2008-10-28,������,����
 *                  2012-09-19,wangsong
 */
 
td_s32 rec_RecordData(td_s32 _iCh, td_u8* _pcData, td_s32 _iDataLen, td_s32 _iFrameType, td_s32 _iFlagAudio);
/*
 * ��������:RecordData
 * ��Ҫ����:������Ƶ���л�ȡ����
 * ��	 ��:
 *			_iCh,ͨ���ţ�0~MAX_CHANNEL_NUM
 *			_pcData,����Ƶ�����ݻ��壬�ǿ�
 *			_iDataLen,�������е����ݳ���,0~128*1024
 *			_iFrameType,֡����,0,1,2
 			_iFlagAudio,0:����Ƶ����;1:����Ƶ���ݡ�
 * ��	 ��:
 *			ERR_REC_SUCCESSFUL,��ȡ���ݳɹ�
 * 			ERR_REC_WRONG_PARAM,����Ĳ���
 * �޸���־:
 *			2008-09-19,������������
 */
td_s32 rec_StopAllRecord();
/*
 * �������ƣ�StopAllRecord
 * ��Ҫ������ֹͣ����¼��
 * ��	 �룺��
 * ��	 ����
 * 			ERR_REC_SUCCESSFUL,ֹͣ¼��ɹ�
 * 			ERR_REC_NONE_RECORDING,��ǰδ��¼��
 * �޸���־��
 * 			2008-08-28,������,����
 */
td_s32 rec_QueryFiles(td_u32 _uiSocket, TQuery* _stQ);
/*
 * �������ƣ�QueryFiles
 * ��Ҫ��������ѯ¼���ͼƬ�ļ�
 * ��	 �룺
 *			_iSocket,SOCKET,���ڱ�ʾ��˭ִ���������ѯ;0��ʾUI��>0��ʾ����ͻ��ˣ������Ƿ�
 * 			_stQ,��ѯ�壬���������ѯ��Ϣ�������ѯ���
 * ��        ����
 *			ERR_REC_WRONG_PARAM,����Ĳ���
 *			ERR_REC_SUCCESSFUL,��ѯ¼���ļ��ɹ�
 * �޸���־��
 * 			2008-08-28,������,����
 *			2008-10-23,����������Ӳ���_iSocket
 */

td_s32 rec_QueryAllFiles(TQuery *_stQ, TFileInfo* _stInfo);
/*
 * �������ƣ�QueryAllFiles
 * ��Ҫ��������ѯ�����ļ�
 * ��	 �룺
 * 			_stQ,��ѯ�壬���������ѯ����.ע����m_uiTotalNum��ԱҪ�����ļ��б�Ĵ�С��
 *			_stInfo, �ļ��б�,���������ѯ���
 * ��        ����
 *			ERR_REC_SUCCESSFUL,��ѯ�ɹ�
 *			ERR_REC_NO_DISK,�޴���
 *			ERR_REC_OPEN_DB_FAILED,���ݿ�δ��ʼ��
 *			ERR_REC_FAILED������ԭ���²�ѯʧ��
 * �޸���־��
 * 			2008-12-02,������,����
 */

td_s32 rec_StopQuery(td_u32 _uiSocket);
/*
 * �������ƣ�StopQuery
 * ��Ҫ������ֹͣ��ѯ¼���ͼƬ�ļ�
 * ��	 �룺
 *			_iSocket,SOCKET,���ڱ�ʾ��˭ִ���������ѯ;0��ʾUI��>0��ʾ����ͻ��ˣ������Ƿ�
 * ��        ����
 *			ERR_REC_WRONG_PARAM,����Ĳ���
 *			ERR_REC_SUCCESSFUL,ֹͣĳ����ѯ�ɹ�
 * �޸���־��
 * 			2008-10-23,������,����
 */
#if 0
	td_s32 rec_RebuildIndex();
	/*
	 * �������ƣ�RebuildIndex
	 * ��Ҫ�������ؽ����д洢���ϵ�����
	 * ��	  �룺��
	 * ��	  ����
	 *			ERR_REC_SUCCESSFUL,�ؽ������ɹ�
	 *			ERR_REC_SOME_RECORDING,��ͨ������¼��
	 * �޸���־��
	 *			2008-08-28,������,����
	 */
 #else

td_s32 rec_StartRebuildIdx(td_u32 _socket);
/*
 * ��������:rec_StartRebuildIdx
 * ��Ҫ����:�ؽ�����
 * ��	 ��:
 *			����λ��
 * ��	 ��:
 *			ERR_REC_SUCCESSFUL,�����ɹ�
 *			ERR_REC_FAILED,����ʧ��
 * �޸���־:
 *			2012-10-22,���ڣ�������
*/
#endif


td_s32 rec_GetAlarmRules(td_s32 _iCh, td_s32 * _pblPreEnable, td_s32 * _piPreTime, td_s32 * _pblDelayEnable, td_s32 * _piDelayTime);
/*
 * �������ƣ�GetAlarmRules
 * ��Ҫ��������ȡ����¼�����
 * ��	 ��:
 *			_iCh,����ȡ��ͨ���ţ�0~MAX_CHANNEL_NUM
 * 			_pblPreEnable,�������Ԥ¼ʹ�ܣ��ǿ�
 * 			_piPreTime,�������Ԥ¼ʱ�䣬�ǿ�
 *			_ppblDelayTime,���ڴ�����¼ʹ�ܣ��ǿ�
 * 			_piDelayTime,���������¼ʱ�䣬�ǿ�
 * ��	 ��:
 * 			ERR_REC_SUCCESSFUL,��ȡ��������ɹ�
 * 			ERR_REC_WRONG_PARAM,����Ĳ���
 * �޸���־��
 * 			2008-08-28,������������
 */
 td_s32 rec_SetAlarmRules(td_s32 _iCh, td_s32 _blPreEnable, td_s32 _iPreTime, td_s32 _blDelayEnable, td_s32 _iDelayTime);
/*
 * ��������:SetAlarmRules
 * ��Ҫ����:���ñ���¼�����
 * ��	 ��:
 *			_iCh,�����õ�ͨ���ţ�0~MAX_CHANNEL_NUM
 *			_blPreEnable,Ԥ¼ʹ�ܣ�0��1
 *          _iPreTime,Ԥ¼ʱ�䣬0~MAX_PRE_TIME
 *			_blDelayEnable,��¼ʹ��,0��1
 *			_iDelayTime,��¼ʱ�䣬0~MAX_DELAY_TIME
 * ��	 ��:
 *			ERR_REC_SUCCESSFUL,���óɹ�
 *			ERR_REC_WRONG_PARAM,����Ĳ���
 * �޸���־:
 *			2008-09-28,������������
 */

td_s32 rec_SetSchedule(td_s32 _iCh,td_s32 _iWeekly,TSchedule* _pstSchedule);
/*
 * �������ƣ�SetSchedule
 * ��Ҫ��������������¼��ģ��
 * ��	 ��:
 * 			_iCh,ͨ����,0~MAX_CHANNEL_NUM
 * 			_iWeekly,0~6,һ�ܵ�7�죬0��6�ֱ�������յ�����
 * 			_pstSchedule,ģ�壬����ʱ��κ͸�¼�����͵�ʹ�ܣ��������ݲμ�TSchedule�Ķ���
 * ��	 ��:
 *			ERR_REC_SUCCESSFUL,����ģ��ɹ�
 *			ERR_REC_WRONG_PARAM,����Ĳ���
 * �޸���־��
 * 			2008-08-29,������������
 */
td_s32 rec_GetSchedule(td_s32 _iCh,td_s32 _iWeekly,TSchedule* _pstSchedule);
/*
 * �������ƣ�GetSchedule
 * ��Ҫ��������ȡ����¼��ģ��
 * ��	 ��:
 * 			_iCh,ͨ���ţ�0��MAX_CHANNEL_NUM
 * 			_iWeekly,���ڣ�0��6����ʾ���յ�����
 * 			_pstSchedule,��������¼��ģ�壬�ǿ�
 * ��	 ��:
 * 			ERR_REC_SUCCESSFUL,��ȡ����¼��ģ��ɹ�
 * 			ERR_REC_WRONG_PARAM,����Ĳ���
 * �޸���־��
 * 			2008-08-29,������������
 */
td_s32 rec_SetRecEnable(td_s32 _iCh,td_s32 _blTimingEnable,td_s32 _blMDEnable,td_s32 _blPortEnable);
/*
 * �������ƣ�SetRecEnable
 * ��Ҫ���������ø���¼�����͵�ʹ��
 * ��	 ��:
 * 			_iCh,ͨ���ţ�0��MAX_CHANNEL_NUM
 * 			_blTimingEnable,����¼��ʹ�ܣ�����ֵ
 * 			_blMDEnable,�ƶ����¼��ʹ�ܣ�����ֵ
 * 			_blPortEnable,�˿ڱ���¼��ʹ�ܣ�����ֵ
 * ��	 ��:
 * 			ERR_REC_SUCCESSFUL,���óɹ�
 * 			ERR_REC_WRONG_PARAM,����Ĳ���
 */
td_s32 rec_GetRecEnable(td_s32 _iCh,td_s32* _pblTimingEnable,td_s32* _pblMDEnable,td_s32* _pblPortEnable);
/*
 * �������ƣ�GetRecEnable
 * ��Ҫ��������ȡ����¼�����͵�ʹ��
 * ��	 ��:
 * 			_iCh,ͨ���ţ�0��MAX_CHANNEL_NUM
 * 			_pblTimingEnable,��������¼��ʹ�ܣ�����ֵ��ָ�룬��ΪNULL
 * 			_pblMDEnable,�ƶ����¼��ʹ�ܣ�����ֵ��ָ�룬��ΪNULL
 * 			_pblPortEnable,�˿ڱ���¼��ʹ�ܣ�����ֵ��ָ�룬��ΪNULL
 * ��	 ��:
 * 			ERR_REC_SUCCESSFUL,��ȡ�ɹ�
 * 			ERR_REC_WRONG_PARAM,����Ĳ���
 * �޸���־��
 * 			2008-08-29,������������
 */
 td_s32 rec_GetRecEnableEx(td_s32 _iCh, td_s32 iMode, td_s32* _pblEnable);
td_s32 rec_GetRecordStatus(td_s32 _iCh, td_s32* _piType);
/*
 * ��������:GetRecordStatus
 * ��Ҫ����:��ȡָ��ͨ����¼������
 * ��    ��:
 *			_iCh,ͨ���ţ�0~MAX_CHANNEL_NUM
 *			_piType,���ڴ���¼�����ͣ�TRecordType,�ǿ�
 * ��	 ��:
 *			ERR_REC_SUCCESSFUL����ȡ�ɹ�
 *			ERR_REC_WRONG_PARAM,����Ĳ���
 * �޸���־:
 *			2008-09-18,������������
 */
td_s32  rec_Init();
/* 
 * ��������: Init
 * ��Ҫ����:��ʼ���洢ģ�飬��ʼ��ȫ�ֱ�������ȡ������Ϣ�������洢�߳�
 * ��    ��:
 *			��
 * ��	 ��:
 *			ERR_REC_SUCCESSFUL
 * �޸���־:
 *			2008-09-11,������������
 */
td_s32 rec_Exit();
/*
 * ��������:Exit
 * ��Ҫ����:�˳��洢ģ��,ֹͣ����¼�񣬹ر����ݿ�
 * ��    ��:
 *			��
 * ��    ��:
 *		    ERR_REC_SUCCESSFUL
 * �޸���־:
 *			2008-09-17,������������
 */

td_s32 rec_BackupFile(td_s8* _pcFileName, td_s32 _iDiskNo, td_char *_pcDirName);
/*
 * ��������:BackUpFile
 * ��Ҫ����:����ָ���ļ�
 * ��	 ��:
 *			_pcFileName,��Ҫ���ݵ��ļ���
 *			_iDiskNo,����Ŀ����̱��
 * ��	 ��:
 *			ERR_REC_SUCCESSFUL,���ݳɹ�
 *			ERR_REC_WRONG_PARAM,����Ĳ���
 *			ERR_REC_DISK_FULL��Ŀ����̿ռ䲻��
 * �޸���־:
 *			2008-10-13,������������
 */

td_s32 rec_BackupPlayer(td_s32 _iDiskNo,const td_s8 *_pcDirName, td_s8* _pcDestPath);
/*
 * ��������:rec_BackupPlayer
 * ��Ҫ����:���ݲ������
 * ��	 ��:
 *			_pcDestPath,������Ҫ���ݵ���U��·��
 *			_iDiskNo,����Ŀ����̱��
 * ��	 ��:
 *			ERR_REC_SUCCESSFUL,���ݳɹ�
 *			ERR_REC_WRONG_PARAM,����Ĳ���
 *			ERR_REC_DISK_FULL��Ŀ����̿ռ䲻��
 * �޸���־:
 *			2013-02-05,���ڣ�����
 */

td_s32 rec_DeleteFile(td_s8* _pcFileName);
/*
 * ��������:DeleteFile
 * ��Ҫ����:ɾ��ָ���ļ�
 * ��    ��:
 *		    _pcFileName,��ɾ�����ļ���
 * ��    ��:
 *			ERR_REC_SUCCESSFUL,ɾ���ɹ�
 *			SQLITE_ERROR,SQL���ִ�д���
 * �޸���־:
 *			2008-09-18,������������
 */
td_s32 rec_DefaultCfg();
/*
 * ��������:DefaultCfg
 * ��Ҫ����:�ָ��洢ģ��ĳ�ʼ����
 * ��	 ��:
 *          ��
 * ��	 ��:
 *			ERR_REC_SUCCESSFUL,�����ɹ�
 *			ERR_REC_OPEN_FILE_FAILED,�������ļ�ʧ��
 *			ERR_REC_WRITE_FILE_ERROR,д�����ļ�����
 * �޸���־:
 *			2008-09-23,������������
 */

void rec_RecordTimer(unsigned long _param);
/*
 * ��������:rec_RecordTimer
 * ��Ҫ����:���ڼ��¼�����Ķ�ʱ��
 * ��	 ��:
 *          ��
 * ��	 ��:
 *			��
 * �޸���־:
 *			2009-01-23,����������ԭ�е��߳��޸�ΪTIMER��
 */
 
void rec_CheckScheduleTimer(unsigned long _param);
/*
 * ��������:CheckScheduleTimer
 * ��Ҫ����:���ڼ��¼��ģ��Ķ�ʱ��
 * ��	 ��:
 *          ��
 * ��	 ��:
 *			��
 * �޸���־:
 *			2009-01-23,����������ԭ�е��߳��޸�ΪTIMER��
 */

//td_s32 rec_SetDiskException(td_s32 _blDiskFull, td_s32 _blDiskErr, td_s32 _blDisplay, td_s32 _blSound);
/*
 * ��������:SetDiskException
 * ��Ҫ����:���ô����쳣�������
 * ��	 ��:
 *          _blDiskFull, 0��1�� �������쳣����ʹ��
 *			_blDiskErr, 0��1�� ���̴��쳣����ʹ��
 *			_blDisplay, 0��1�� �����쳣ʱ��Ļ��ʾ
 *			_blSound, 0��1�� �����쳣ʱ������ʾ
 * ��	 ��:
 *			ERR_REC_SUCCESSFUL, ���óɹ�
 * �޸���־:
 *			2009-02-19,��������������
 */

//td_s32 rec_GetDiskException(td_s32* _blDiskFull, td_s32* _blDiskErr, td_s32* _blDisplay, td_s32* _blSound);
/*
 * ��������:GetDiskException
 * ��Ҫ����:��ȡ�����쳣�������
 * ��	 ��:
 *          _blDiskFull, Ϊ��ʱ�������� �����������쳣����ʹ��
 *			_blDiskErr, Ϊ��ʱ�������� �������̴��쳣����ʹ��
 *			_blDisplay, Ϊ��ʱ�������� ���������쳣ʱ��Ļ��ʾ
 *			_blSound, Ϊ��ʱ�������� ���������쳣ʱ������ʾ
 * ��	 ��:
 *			ERR_REC_SUCCESSFUL, ��ȡ�ɹ�
 * �޸���־:
 *			2009-02-19,��������������
 */


td_s32 rec_DataBaseDiskNo(void);
/*
 * ��������:DataBaseDiskNo
 * ��Ҫ����:�������ݿ�����ʹ�õĴ��̺�
 * ��	 ��:
 *          ��
 * ��	 ��:
 *			��ɹ��򷵻ش��̱�ţ�ʧ���򷵻�-1
 * �޸���־:
 *			2009-03-11,��������������
 */

td_u8* rec_TempRecorderPath(int _iDvdNo);
/*
 * ��������:TempRecorderPath
 * ��Ҫ����:��ȡ��¼��ʹ�õ���ʱ·��
 * ��	 ��:
 *          ��
 * ��	 ��:
 *			��ʱ·������ʧ���򷵻�"/dev/null"
 * �޸���־:
 *			2010-08-02,��������������
 */
td_u8* rec_TempRecorderMd5Path(int _iDvdNo);
/*
 * ��������:rec_TempRecorderMd5Path
 * ��Ҫ����:��ȡ��¼��ʹ�õ���ʱ·��
 * ��	 ��:
 *			��
 * ��	 ��:
 *			��ʱ·������ʧ���򷵻�"/dev/null"
 * �޸���־:
 *			2010-08-02,��������������
 */

td_s32 rec_Pause(td_s32 _iParam, td_s32 _iDisk);
/*
 * ��������:Pause
 * ��Ҫ����:��ͣ�洢ģ�飬ͨ�����ڸ�ʽ������ʱ
 * ��	 ��:
 *          _iParam,��ͣ����.bit0,ֹͣ����¼��bit1��ֹͣ���в�ѯ��bit2���ر����ݿ⣻bit3���ر���ʱ�����ļ�
 * ��	 ��:
 *			ERR_REC_SUCCESSFUL;
 * �޸���־:
 *			2009-04-07,��������������
 */

td_s32 rec_Restart(td_s32 _iDisk);
/*
 * ��������:Restart
 * ��Ҫ����:�ָ��洢ģ��
 * ��	 ��:
 *          ��
 * ��	 ��:
 *			ERR_REC_SUCCESSFUL
 * �޸���־:
 *			2009-04-07,��������������
 */

td_s32 rec_IfRecEnable(void);
/*
 * ��������:IfRecEnable
 * ��Ҫ����:�洢ģ���Ƿ�ʹ��
 * ��	 ��:
 *          ��
 * ��	 ��:
 *			1, ʹ�ܣ�0�� ��ʹ��
 * �޸���־:
 *			2009-05-11,��������������
 */

td_s32 rec_TryRebuildIndex(void);
/*
 * ��������:TryRebuildIndex
 * ��Ҫ����:�����ؽ�����
 * ��	 ��:
 *          ��
 * ��	 ��:
 *			ERR_REC_SUCCESSFUL,�����ɹ�
 *			ERR_REC_FAILED,����ʧ��
 * �޸���־:
 *			2009-05-21,��������������
 */

td_s32 rec_FixBadFileSystem(void);
/*
 * ��������:FixBadFileSystem
 * ��Ҫ����:�޸����ļ�ϵͳ
 * ��	 ��:
 *          ��
 * ��	 ��:
 *			ERR_REC_SUCCESSFUL,�����ɹ�
 *			ERR_REC_FAILED,����ʧ��
 * �޸���־:
 *			2009-06-13,��������������
 */

td_s32 rec_IsRebuildingIndex(void);
/*
 * ��������:IsRebuildingIndex
 * ��Ҫ����:��ѯ�ؽ�����״̬
 * ��	 ��:
 *          ��
 * ��	 ��:
 *			0,δ���ؽ��������ؽ���������;1,�����ؽ�����
 * �޸���־:
 *			2009-08-06,��������������
 */

 
td_s32 rec_SetCustomRecordType(td_s32 _iType, td_u8* _pucName);
/*
 * ��������:SetCustomRecordType
 * ��Ҫ����:�����û��Զ���¼������
 * ��	 ��:
 *          _iType, �Զ���¼������ֵ
 *			_pucName�� �Զ���¼��������
 * ��	 ��:
 *			ERR_REC_SUCCESSFUL, �ɹ�
 *			ERR_REC_FAILED, ʧ��
 *			ERR_REC_WRONG_PARAM, ����Ĳ���
 * �޸���־:
 *			2009-11-05,��������������
 */

td_u8* rec_GetCustomRecordType(td_s32 _iType);
/*
 * ��������:GetCustomRecordType
 * ��Ҫ����:��ȡ�û��Զ���¼������
 * ��	 ��:
 *          _iType, �Զ���¼������ֵ
 * ��	 ��:
 *			NULL, ��ȡʧ��
 *			����, ������
 * �޸���־:
 *			2009-11-05,��������������
 */


td_s32 rec_AddReserveInfoToFile(td_s32 _iCh, td_s32 _iFlag);
/*
 * ��������:AddReserveInfoToFile
 * ��Ҫ����: ����¼���ļ��ĸ�����Ϣ
 * ��	 ��:
 *			_iCh, 0~MAX_CHANNEL_NUM, ͨ����
 *			_iFlag, 0, �޸�ԭ����Ϣ��1��׷���µ���Ϣ
 * ��	 ��:
 *			ERR_REC_NO_DBFILE, ���ݿ�δ��ʼ��
 *			ERR_REC_SUCCESSFUL, �����ɹ�
 *			ERR_REC_FAILED,����ԭ���²���ʧ��
 * �޸���־:
 *			2009-12-03,��������������
 */

td_s32 rec_ReadFileHeader(FILE* _fp, td_u8* _pcFileName, S_FileHeader* _pHeader);
/*
 * ��������:ReadFileHeader
 * ��Ҫ����:��ȡ�ļ�ͷ
 * ��	 ��:
 *			_fp, ����ȡ���������Ϊ��������ļ���
 *			_pcFileName, �ǿ�, ����ȡ���ļ�
 *			_pHeader, ���ڴ����ļ�ͷ
 * ��	 ��:
 *			ERR_REC_NO_DBFILE, ���ݿ�δ��ʼ��
 *			ERR_REC_SUCCESSFUL, �����ɹ�
 *			ERR_REC_FAILED,����ԭ���²���ʧ��
 * �޸���־:
 *			2009-12-03,��������������
 */

td_s32 rec_WriteCfg(void);
td_s32 rec_IsValidFrame(S_FrameHeader _stHead);
td_s32 rec_CompleteFileName(td_s8* _pcFileName, td_s8* _pcFullPath, td_s8* _pcPath, td_s8* _pcShortPath);
/*
 * ��������: CompleteFileName
 * ��Ҫ����:�����ļ���ȫ�����·��
 * ��	 ��:
 *			_pcFileName,�����ļ���,H00CFT20070802113038C38.sdv
 *			_pcFullPath,���ڴ����ļ��ľ���·��,/mnt/sata/0/0/20070802/H00CFT20070802113038C38.sdv
 *			_pcPath,���ڴ����ļ�����·��,/mnt/sata/0/0/20070802
 *			_pcShortPath,���ڴ����ļ��Ķ�·��,/mnt/ide/0/0
 * ��	 ��:
 *			ERR_REC_SUCCESSFUL,�����ɹ�
 * �޸���־:
 *			2008-09-10,������������
 */
td_s32 rec_IsRecordFile(td_u8* _pucFileName);
td_s32 rec_IsValidFileName(td_u8* _pucFileName);
td_s32 rec_AddFileToIndex(td_s8* _pcFullPath, td_s32 _iAtmFlag);
typedef void (*rec_AtmRebuildCallBack)(td_s8* _ucFileName, td_s8* _ucNewFileName, td_s32 _iType);
td_s32 rec_RegAtmRebuildCallBack(rec_AtmRebuildCallBack _CallBack);
typedef void (*rec_AtmRecordUpdateCallBack)(td_s8 *_pcFileName, td_s32 _iFileSize, td_s32 _iStopTime);
td_s32 rec_RegAtmRecordUpdateCallBack(rec_AtmRecordUpdateCallBack _CallBack);


//20130322 SUN Wei add for send pic
typedef void (*rec_PicSendCallBack)(td_s8 * _pcFileName, td_s32 _iCh, td_s32 _ioffset);
td_s32 rec_RegPicSendCallBack(rec_PicSendCallBack _CallBack);


// ¼��״̬�ı�֪ͨ
typedef void (*rec_StatChgNotifyCallBack)(int _iChn, int _iStat);

td_s32 rec_RegStatNotify(rec_StatChgNotifyCallBack _CallBack);

td_s32 rec_RegStatUiNotify(rec_StatChgNotifyCallBack _CallBack);
#ifdef OverLapBurn
//�ص���������һ���������ò�����ʾ���ļ��Ƿ��Ѿ���¼��
typedef void (*rec_StartRecorderNotifyCallBack)(td_s32 _iChn, const char *_strFileName, td_s32 _iFileLen, TFileType _FileType,td_s32 iIsOverBurn);
#else
typedef void (*rec_StartRecorderNotifyCallBack)(td_s32 _iChn, const char *_strFileName, td_s32 _iFileLen, TFileType _FileType);
#endif
typedef void (*rec_GetCDSerialNoCallBack)(int _iCDindex, td_u8* _cSerialNo);
td_s32 rec_RegRecorderStartNotifyCallBack(rec_StartRecorderNotifyCallBack _CallBack);
td_s32 rec_RegGetCDSerialNoCallBack(rec_GetCDSerialNoCallBack _CallBack);

td_s32 rec_GetFdTempIndex();  //��ȡ��ʱ�����ļ����
//wdlxh td_s32 rec_InitTempIndex();
td_s32 rec_GetFilePathSizeLog();

td_s32 rec_InitBfIndex();//miracle,ws

td_s32 rec_SeekIFrame_Ex(FILE* _fp, td_s32 *_pStop);
#define rec_SeekIFrame(_fp)	rec_SeekIFrame_Ex(_fp, NULL)

td_s32 rec_SetBuf(FILE *_fp, td_s32 _iSize);

td_s32 rec_OpenFile(FILE** _fp, td_s8* _pcFileName);
/*
 * ��������:rec_OpenFile
 * ��Ҫ����:���ļ�
 * ��	 ��:
 *			_fp, ����ȡ����ָ���ָ��
 *			_pcFileName, �ǿ�, ����ȡ���ļ�
 * ��	 ��:
 *			ERR_REC_SUCCESSFUL, �����ɹ�
 *			ERR_REC_FAILED,����ԭ���²���ʧ��
 * �޸���־:
 *			2011-04-01,���ɣ�������
 */

td_s32 rec_CloseFile(FILE **_fp);
/*
 * ��������:rec_CloseFile
 * ��Ҫ����:�ر��ļ�
 * ��	 ��:
 *			_fp, ����ȡ����ָ���ָ��
 * ��	 ��:
 *			ERR_REC_SUCCESSFUL, �����ɹ�
 *			ERR_REC_FAILED,����ԭ���²���ʧ��
 * �޸���־:
 *			2011-04-01,���ɣ�������
 */

td_s32 rec_ValidFrame(S_FrameHeader *_pTFrameheader, int _iMaxLen);
td_s32 rec_SeekFile_Ex(FILE*_fp, td_s32 _iPosOrTime, td_s32 *_iRemainT, td_s32 *_pStop);
#define rec_SeekFile(_fp, _iPosOrTime, _iRemainT)	rec_SeekFile_Ex(_fp,  _iPosOrTime, _iRemainT, NULL)
/*
 * ��������:rec_SeekFile
 * ��Ҫ����:��λ�ļ�
 * ��	 ��:
 *			_fp, ����ȡ����ָ��
 *			_iPosOrTime,��λ�㣬��С��100ʱΪ�ٷֱȶ�λ������Ϊʱ��㶨λ
 * ��	 ��:
 *			ERR_REC_SUCCESSFUL, �����ɹ�
 *			ERR_REC_FAILED,����ԭ���²���ʧ��
 * �޸���־:
 *			2011-04-01,���ɣ�������
 */
td_s32 rec_GetFileStartTime(td_s8* _pcFileName, time_t* _pStartTime);
td_s32 rec_GetFileStopTime(td_s8* _pcFileName, time_t* _pStopTime);
td_s32 rec_GetFileSize(td_s8* _pcFileName, int* _pSize);
td_s32 rec_GetFileTimeLen(td_s8* _pcFileName, time_t* _pTimeLen);

int Storage_GetDebug(char *_cString,int _iLen);
td_s32 rec_WriteBfIndex();
td_s32 rec_GetPeriodOfFileMark(IN char *_strName, OUT int *_iCnt, OUT int *_iMark, int _iLen);
/*
��������:����ʱ��λ�ȡ�����Ϣ
���:
_iStartTm :��ȡ�����Ϣ�Ŀ�ʼʱ��
_iEndTm :��ȡ�����Ϣ�Ľ���ʱ��
_iChn :��ȡ�����Ϣ��ͨ��

_iCnt:�ļ��д��ĸ���
_iMark:���Ŀ�ʼʱ��
_iLen:_iMark�ĳ���
*/
td_s32 rec_GetPeriodOfTimeMark(int _iChn, time_t _iStartTm, time_t _iEndTm, OUT int *_iCnt, OUT int *_iMark, int _iLen);

//////////////////////////////////////////////////////////////////atm
td_s32 rec_AtmStartRecord(void);
/*
*��������:rec_AtmStartRecord
*��Ҫ����:��������¼��
*���:ERR_REC_SUCCESSFUL, �����ɹ�
*		ERR_REC_FAILED,����ԭ���²���ʧ��
*�޸���־:2012-09-14�����ɣ�����
*/
td_s32 rec_AtmStopRecord(void);
/*
*��������:rec_AtmStopRecord
*��Ҫ����:ֹͣ����¼��
*���:ERR_REC_SUCCESSFUL, �����ɹ�
*		ERR_REC_FAILED,����ԭ���²���ʧ��
*�޸���־:2012-09-14�����ɣ�����
*/
td_s32 rec_GetNowRecord(int *_iRecChn, char _strFileName[][FILE_NAME_LEN]);
/*
*��������:rec_GetNowRecord
*��Ҫ����:��ȡ��ǰ¼����Ϣ
*����:_iRecChn����λ��ʾ��ͨ���Ƿ�����¼��
*		_strFileName[][FILE_NAME_LEN],��ȡ����¼����ļ����������鳤��ΪMAX_CHANNEL_NUM
*���:ERR_REC_SUCCESSFUL, �����ɹ�
*		ERR_REC_FAILED,����ԭ���²���ʧ��
*�޸���־:2012-09-14�����ɣ�����
*/

//////////////////////////////////////////////////////////////////atm
td_s32 rec_GetPartFile(td_u8* _pcFileName, td_u8 *_pClipName, td_s32 _iStartPos, td_s32 _iStopPos);
int rec_playCapPicture(int _iTime, char _cChn, void *_buf, int _iSize);
td_s32 rec_StopCopy(void);
td_s32 rec_ClearStopCopyFlag(void);
int rec_SetAudioStorageStat(int _iChn, int _iEnable);
int rec_GetAudioStorageStat(int _iChn);
/*
*��Ҫ����:��ȡ�ļ�Ƭ��
*����:_iStartPos,��ʼ��֮ǰ���I֡λ�ã�-1��ʾ�ļ���ʼ�β���ض�
*		_iStopPos��������P֡����λ�ã�-1��ʾ�ļ������β���ض�
*���:ERR_REC_SUCCESSFUL, �����ɹ�
*		ERR_REC_FAILED,����ԭ���²���ʧ��
*/
td_s32 rec_DvrSignToFile(td_s32 _iCh);//add by gyn
//20120913  ���� add �ж��ļ��Ƿ�Ϊ��ǰ����¼���ļ�
td_s32 rec_IsCurrentFile(FILE*_fp);
//20120913  ���� add 
td_u32 rec_GetCurFileSize(int _iCh);
//20121120  ���� add 
td_s32 rec_GetRebuildStatus(void);
TFileInfo rec_GetCurFileInfo(td_s32 _iChnNo);
/*
**20130326 ����add
*�޸��ļ�Ϊ���������
*iLockFlag: 1---������0---����
*/
td_s32 rec_RenameFileModifyLock(char *_pcFileName, td_u32 iLockFlag);
td_s32 rec_GetRecFileLockStatus(char *_pcFileName, td_s32 *_piLockStatus);

td_u8* rec_MidRecorderPath(int _iDvdNo);
/*
 * ��������:rec_MidRecorderPath
 * ��Ҫ����:��ȡ��ǰ��Ҫ��¼��¼���ļ�
 * ��	 ��:
 *          ��
 * ��	 ��:
 *			��ʱ·������ʧ���򷵻�"/dev/null"
 * �޸���־:
 *			2012 06 12
 */
 
td_u8 *rec_ConvertRecorderPath();
/*
 * ��������:rec_ConvertRecorderPath
 * ��Ҫ����:��ȡת��¼��Ĵ��·��
 * ��	 ��:
 *          ��
 * ��	 ��:
 *			��ʱ·������ʧ���򷵻�"/dev/null"
 * �޸���־:
 *			2014 11 27
 */
 
  td_u8 *rec_DvdInfoFile();
/*
 * ��������:rec_DvdInfoFile
 * ��Ҫ����:��ȡ���̺��̻��̵Ĵ��·��
 * ��	 ��:
 *          ��
 * ��	 ��:
 *			��ʱ·������ʧ���򷵻�"/dev/null"
 * �޸���־:
 *			2015 04 11
 */
 
td_u8* rec_FinRecorderPath(int _iDvdNo);
/*
 * ��������:rec_FinRecorderPath
 * ��Ҫ����:��ȡ��¼һ�Ź���¼���¼���ļ�
 * ��	 ��:
 *          ��
 * ��	 ��:
 *			��ʱ·������ʧ���򷵻�"/dev/null"
 * �޸���־:
 *			2012 06 06
 */
td_u8* rec_TrueFinRecorderPath(int _iDvdNo);


td_u8* rec_AudRecorderPath(int _iDvdNo);
/*
 * ��������:rec_AudRecorderPath
 * ��Ҫ����:��ȡ��¼һ�Ź���¼���¼���ļ�
 * ��	 ��:
 *          ��
 * ��	 ��:
 *			��ʱ·������ʧ���򷵻�"/dev/null"
 * �޸���־:
 *			2012 06 06
 */

td_s32 rec_OverLapRecorderPath(char *_pcPath);
/*
* ��������:rec_OverLapRecorderPath
 * ��Ҫ����:��ȡ���������ļ���·��
 * ��	 ��:
 *			�ļ�·��
 *
 * ��	 ��:�ɹ�����0�����򷵻ظ�ֵ
 *			
 * �޸���־:2012-1-29,ׯ־����������
 *			
*/
td_s32 rec_Stat(char * _pcFilePath, struct stat * _pstStat);

td_s32 rec_Atoi(char a);//

int rec_GetFileChn(char * _pcFileName);
int rec_GetFileChnEx(char * _pcFileName, OUT int *_piMainOrSub);
#define rec_GetFileChn(_pcFileName) 	rec_GetFileChnEx(_pcFileName, NULL)

td_s32 rec_QueryMemCurFile(TQuery* _pstQuery, TFileInfo *_pstFileInfo);

td_s32 rec_GetIFrameIndexInfo(IN char *_strName, OUT S_FrameHeader *FrameHeader, OUT int *_iLocIFrameIndexHeader, OUT int *_iIndexLen, OUT int *_iIndexCnt, OUT int *_iFileLoc);

td_s32 rec_GetPeriodOfFileMark(IN char *_strName, OUT int *_iCnt, OUT int *_iMark, int _iLen);
/*
��������:����ʱ��λ�ȡ�����Ϣ
���:
_iStartTm :��ȡ�����Ϣ�Ŀ�ʼʱ��
_iEndTm :��ȡ�����Ϣ�Ľ���ʱ��
_iChn :��ȡ�����Ϣ��ͨ��

_iCnt:�ļ��д��ĸ���
_iMark:���Ŀ�ʼʱ��
_iLen:_iMark�ĳ���
*/
td_s32 rec_GetPeriodOfTimeMark(int _iChn, time_t _iStartTm, time_t _iEndTm, OUT int *_iCnt, OUT int *_iMark, int _iLen);
/********************************���ռƻ�****************************/

/*
 * ��������:rec_SetHolidayParam
 * ��Ҫ����:���������Ϣ����
 * ��	 ��:
 *			_pstHoliday, ������Ϣ
 * ��	 ��:
 *			td_success, ����ɹ�
 *			td_failure, ����ʧ��		
 */
td_s32 rec_SetHolidayParam(THolidayInfo *_pstHoliday);

/*
 * ��������:rec_GetHolidayParam
 * ��Ҫ����:���������Ϣ����
 * ��	 ��:
 *			_iHolidayId, ���ձ��
 * ��	 ��:	
 */
td_s32 rec_GetHolidayParam(td_s32 _iHolidayId, THolidayInfo *_pstHolidayInfor);


/*
 * ��������:rec_SetHolidaySchedule
 * ��Ҫ����:�������ģ��
 * ��	 ��:
 *			_iChannelNo, ͨ����
 *			_pstSchedule, ģ����Ϣ
 * ��	 ��:	
 *			td_success, ����ɹ�
 *			td_failure, ����ʧ��
 */	
td_s32 rec_SetHolidaySchedule(td_s32 _iChannelNo, TSchedule* _pstSchedule);

/*
 * ��������:rec_GetHolidaySchedule
 * ��Ҫ����:��ȡ����ģ��
 * ��	 ��:
 *			_iChannelNo, ͨ����
 *			_pstSchedule, ģ����Ϣ
 * ��	 ��:	
 *			td_success, ��ȡ�ɹ�
 *			td_failure, ��ȡʧ��
 */
td_s32 rec_GetHolidaySchedule(td_s32 _iChannelNo, TSchedule* _pstSchedule);

/************************************end******************************/

/*
**20130327 ����add
*���ü�¼¼����ʱ����ȫ�ֱ���
*_iChn------ͨ����
*/
td_s32 rec_SetStoreTime(int _iChn, int _iDays);

/*
**20130401 ����add
*���ü�¼¼���Ƿ��֡��ȫ�ֱ���
*_iChn------ͨ����
*_iEnable---��֡״̬
*/
td_s32 rec_SetPickFrame(int _iChn, int _iEnable);
//������¼��
td_s32 rec_SetSubRecord(int _iChn, int _iEnable);

/*
**20130401 ����add
*���ü�¼¼���Ƿ������ȫ�ֱ���
*_iChn------ͨ����
*_iEnable---����¼��״̬
*/
td_s32 rec_SetRedundRecState(int _iChn, int _iEnable);

//����ʵʱ��ȡ���ֱ���
td_s32 rec_GetMaxVideoSize(td_s32 _iCh, td_u32 _u8VideoSize, td_s32 _iNorm);

//ע������������(��ʱ)�����ص�
td_s32 rec_MainTimeStreamPara(MainTimeChnPara _MainTimeChnParaCallBack);

//����Ƿ���Ҫ�л�����
td_s32 rec_ChangeVencParam(td_s32 _iChn, td_s32 _iVencParamChangeFlag);

TChnRecPara rec_GetChnRecParam(int _iChn);

td_s32 rec_MakeUpIframeIndex(td_u8 * _pcFullFilePath, td_u8 * _pcCDROMSerialNo);
td_s32 rec_UpdateFileTail4CDSerialNo(td_u8 * _pcFullFilePath, td_u8 * _pcCDROMSerialNo);

td_s32 rec_AlterFirstDiskNum(td_s32 _iDiskNum);
//SUN Wei add record Template 
td_s32 rec_SetSmartRecTemplate(td_s32 _iCh,td_s32 _iWeekly,td_s32 _iSegment,td_s32 _iTemplateType);
td_s32 rec_GetSmartRecTemplate(td_s32 _iCh,td_s32 _iWeekly,td_s32 _iSegment);
td_s32 rec_RegSmartRecCallBack(SetSmartRecCallBack _SetSmartRecCallBack);
//SUN Wei add record Template 
//SUN Wei add record Template 
/////////////¼���ǩ/////////////
td_s32 rec_TagModify(int _iOperation, char* _cFileName, int* _piTagTm,char* _cTagName);
td_s32 rec_TagQuery(IN char *_cFileName,IN char* _cTagName, OUT TTagInfo _stTagInfo[], int _iMaxTagNum);
//////////////////////////////////
void rec_doSendStat();
void rec_ResetDBFile(int _iDBNum);

//������Ƶ�����Ϣ���洢ģ�飬���ںϳ�ͨ���Ը���ͨ����Ƶ�ļ�����ȡ���
int rec_DvrAudioSignToFile(TAudioTagInfo *_tAudioTagInfo, int _iChnCnt);

//ͨ�ô�㹦��
td_s32 rec_DvrCommonSignToFile(td_s32 _iCh, td_s32 _iType, td_char *_pcTag);

#endif /* STORAGE_H_ */


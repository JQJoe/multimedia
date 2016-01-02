/*****************************************************************************
 * NAME         : td_mp4.h
 * FUNCTION     : MP4  ת���ط����
 * PROGRAMMED   : ��ʤ
 * DATE         : 2014-12-10
 * PROJECT      : 
 * OS           : Linux
 ****************************************************************************/  

#ifndef __TD_MP4_H_INCLUDED__
#define __TD_MP4_H_INCLUDED__

#define FOR_MP4SDK
#define	ZHENGFA
#ifdef FOR_MP4SDK
#ifndef ALONE
#define ALONE
#endif
typedef unsigned char	MP4_VOID;
#else
typedef void			MP4_VOID;
#endif

#include "public_def.h"
#include "ringbuf.h"
//#include "dlist.h"

#ifdef TD_VFS
#include "libvfs.h"
#include "libstdfs.h"
#include "libtdfs.h"
#endif


#ifndef FILENAMEMAXNUM
#define FILENAMEMAXNUM	128
#endif

typedef off_t __int64;

#define MAX_ExInfo_SIZE       						1024
#define MAX_VIDEO_SAMPLE_SIZE 						1024*1024
#define MAX_AUDIO_SAMPLE_SIZE 						1024
#define MAX_AUDIO_FRAMENUM                          20
#define MP4_BOX_SIEZ_LENGTH   						4
#define MP4_BOX_SIZE_LENGTH_BIG                     8
#define MP4_FILE_FLAG_LENGTH 						4
#define MP4_FILE_TYPE_LENGTH 						4
#define MP4_BOX_TYPE_LENGTH 						4
#define MP4_CUSTOM_MDATFLAG_LENGTH 					8
#define MP4_MDAT_VERSION_LENGTH 					4
#define MP4_SAMPLE_TYPE_LENGTH 						1
#define MP4_MAX_RECORD_BUF_SIZE 					512*1024
#define MP4_CYSTOMBOX_HEAD_LEN 						28
#define MP4_RESUM_DATA_BUF_SIZE 					1024*1024
#define MP4_MAX_WRITELEN_ONCE                       512*1024

#define MAX_FRAME_INTERVAL        1000 //ms
#define DEFAULT_FRAME_INTERVAL    40   //ms

#define REC_ISAMPLE_INDEX_MAGIC_NUMBER   0x0123abce//MP4�ļ���ʾ

#define MP4_AAC_TYPE_SIGN 		"AAC"
#define MP4_G711A_TYPE_SIGN 	"alaw"
#define MP4_G711U_TYPE_SIGN 	"ulaw"
#define MP4_PCM_TYPE_SIGN 		"pcm"
#define MP4_PCM_TYPE_SIGN2 		"PCM"

#define TYPE_TIANDY_MP4_FILE     1 		
#define TYPE_OTHER_MP4_FILE      2 		

#ifdef FOR_MP4SDK
//add for windows 
#define MAX_WIDE_CHAR_NUM     254
//add end
#endif

/* H264 NALU TYPES */
#define SLICE_LAYER_WITHOUT_PARTITIONING_RBSP    0x01  /*��IDR ͼ��ı���slice*/
#define SLICE_DATA_PARTITION_A_LAYER_RBSP        0x02  /*����slice ���ݻ���A*/
#define SLICE_DATA_PARTITION_B_LAYER_RBSP    	 0x03  /*����slice ���ݻ���B*/
#define SLICE_DATA_PARTITION_C_LAYER_RBSP        0x04  /*����slice ���ݻ���C*/
#define SLICE_LAYER_WITH_PARTITIONING_RBSP       0x05  /*IDR ͼ���еı���slice*/
#define SEI_RBSP                                 0x06  /*SEI (������ǿ��Ϣ)*/
#define SEQ_PARAMETER_SET_RBSP                   0x07  /*SPS (���в�����)*/
#define PIC_PARAMETER_SET_RBSP                   0x08  /*PPS (ͼ�������)*/
#define ACCESS_UNIT_DELIMITER_RBSP               0x09  /*���뵥Ԫ�����*/
#define END_OF_SEQ_RBSP                          0x10  /*���н���*/
#define END_OF_STREAM_RBSP                       0x11  /*��������*/
#define FILLER_DATA_RBSP                         0x12  /*�������*/

/**
 * Table 7-3: NAL unit type codes H265 cwm
 */
typedef enum {
    NAL_TRAIL_N    = 0,//Ĭ�����ͣ���Ч
    NAL_TRAIL_R    = 1,
    NAL_TSA_N      = 2,
    NAL_TSA_R      = 3,
    NAL_STSA_N     = 4,
    NAL_STSA_R     = 5,
    NAL_RADL_N     = 6,
    NAL_RADL_R     = 7,
    NAL_RASL_N     = 8,
    NAL_RASL_R     = 9,
    NAL_BLA_W_LP   = 16,
    NAL_BLA_W_RADL = 17,
    NAL_BLA_N_LP   = 18,
    NAL_IDR_W_RADL = 19,
    NAL_IDR_N_LP   = 20,
    NAL_CRA_NUT    = 21,
    NAL_VPS        = 32,
    NAL_SPS        = 33,
    NAL_PPS        = 34,
    NAL_AUD        = 35,
    NAL_EOS_NUT    = 36,
    NAL_EOB_NUT    = 37,
    NAL_FD_NUT     = 38,
    NAL_SEI_PREFIX = 39,//cwm Ϊ��˾��˽������
    NAL_SEI_SUFFIX = 40,
} NALUnitType;

//cwm��Ƶ���������
typedef enum AVCodecID{
	AV_CODEC_ID_H264,
	AV_CODEC_ID_HEVC,
}AVCodecID;

/***************************************************************************/
//Macro defined area begin
#ifndef MAX_RESERVED_INFO_LEN
#define MAX_RESERVED_INFO_LEN	64	//¼���ļ���Ϣ�е�Ԥ����Ϣ����
#endif
#define CRYPT_KEY_STR       "yszjtszj"
#define MP4_APPEND_CHAR_INFO_SIZE	(MAX_RESERVED_INFO_LEN+8)	//72
#define ADTS_HEADER_LENGTH				7
#define HAVE_SDV_VIRTUAL_FRAME_FLAG		1
#define HAVE_NO_SDV_VIRTUAL_FRAME_FLAG  0
#define APPEAR_SDV_VIRTUAL_FRAME_FLAG	1
#define TD_MP4_CONVERT_RUNNING	1
#define TD_MP4_CONVERT_STOP		0
//Macro defined area end
/***************************************************************************/

typedef struct
{
	unsigned int m_VideoTrackID;    /*��ƵID*/
	unsigned int m_AudioTrackID;    /*��ƵID*/
	void* m_MP4Handle;    /*MP4 �ļ����*/
#ifdef TD_VFS
	TVfile* m_pfSDVFileHandle;        /*SDV �ļ����*/
#else
	FILE* m_pfSDVFileHandle;        /*SDV �ļ����*/
#endif
	char m_cMP4FilePath[FILENAMEMAXNUM];  /*MP4 �ļ�·��*/
	char m_cSDVFilePath[FILENAMEMAXNUM];  /*SDV �ļ�·��*/
	S_FileHeader m_stSDVFileHead;   /*��¼SDV �ļ���ʽͷ���̶���Ϣ*/
	S_FrameHeader m_stSDVFrameHead; /*��¼����Ƶ֡��ʵʱ��Ϣ*/
	unsigned long long m_VedioDuration;    /*��Ƶ���������ʵ��֡���*/
	int m_bVedioFirstAppearFlag;   /*��Ƶ��һ�γ��ֱ�ʶ����ʼֵΪ0����һ��֮��Ϊ1�������һ��д��MP4��Ƶ֡ʱʹ��*/
	int m_bFirstSpsFlag;           /*ֻд��һ��SPS �ı�ʶ����ֵΪ0����һ��֮��Ϊ1*/
	int m_bFirstPpsFlag;           /*ֻд��һ��PPS �ı�ʶ����ֵΪ0����һ��֮��Ϊ1*/
	int m_bFoundSpsPpsFlag;     
	int m_bHaveSDVVirtualFrameFlag;   /*��ֵΪ0����SDV �ļ�ʱ��⵽SDV ����֡βʱ��ΪHAVE_SDV_VIRTUAL_FRAME_FLAG*/
	int m_bConvertExitFlag;           /*ת��ֹͣ��ʶ*/
	int m_bAudioFirstAppear;    /*��Ƶ��һ�γ��ֱ�ʶ����ʼֵΪ0�����ֺ�Ϊ1*/
	int m_bIFrameFlag;
	int m_bCryptFlag;          /*�Ƿ�ת���н�������*/
	off_t m_lCurFilePos;         /*SDV�ļ���ǰ�α�λ��*/
	off_t m_lStartConvertPos;  /*SDV�ļ���ʼת���Ĳ�λ*/
	off_t m_lStopConvertPos;		/*SDV�ļ�ֹͣת����λ*/
	off_t m_lFileStopPos;        /*SDV�ļ�������λ*/
	unsigned long long m_AudioDuration;       /*��Ƶ���������ʵ��֡�������עͬһ�ε���Ƶ���Ϊ0*/
	unsigned int m_uiAudioSampleID;    /*��ƵID ����*/
	unsigned int m_uiVedioSampleID;    /*��ƵƵID ����*/
	unsigned int m_uiUselessCount;     /*��Ч֡��ǰ����*/
	unsigned long long m_AudioTotalDuration;
	unsigned long long m_VedioTotalDuration;
	int m_iIFrameCount;
	unsigned int m_uiLastAudioTime;    /*��¼��һ�δ�SDV�ļ��ж�ȡ����Ƶʱ��*/
	void* m_pvMP4VirtualFramebuffer;   /*ָ��MP4 ����֡��ָ�룬��ע��������ָ������֡֡ͷ*/
	int m_uiMP4VirtualFramebufferSize;
	void* m_pvSDVVirtualFramebuffer;   /*ָ��SDV ����֡��ָ�룬��ע��������ָ������֡֡ͷ*/
	int m_uiSDVVirtualFramebufferSize;
	unsigned char* m_ucAVDataBuf;/*����Ƶ����buf*/
	int m_iAVDataBufSize;        /*����Ƶ����buf���볤��*/
	unsigned char* m_ucVideoSampleDataBuf;/*��Ƶ����buf*/
	int m_iVideoSampleDataBufSize;         /*��Ƶ����buf ���볤��*/
}TMP4Mgr;


/***************************************************************************/
//Data structure defined area begin

typedef struct
{
	int m_iHasCnt;
	int m_iMaxCnt;
	int *m_piMark;
}MP4_TMark;

typedef struct
{// NALU
	int m_iType;  
	int m_iVedioSize;  
	unsigned char* m_pucVedioData;  
}TMP4Nalu;  

typedef struct
{//ISO/IEC 14496-3 ADTS����
	//adts_fixed_header
	int synword;										//0~11		12 bslbf
	unsigned char ID;									//12			1  bslbf
	unsigned char layer;								//13~14		2  uimsbf
	unsigned char protection_absent;					//15			1  bslbf
	unsigned char profile_ObjectType;					//16~17		2  uimsbf
	unsigned char sampling_frequency_index;			//18~21		4  uimsbf
	unsigned char private_bit;							//22			1  bslbf
	unsigned char channel_configuration;				//23~25		3  uimsbf
	unsigned char original_copy;						//26			1  bslbf
	unsigned char home;								//27			1  bslbf
	//adts_variable_header
	unsigned char copyright_identification_bit;			//28			1  bslbf
	unsigned char copyright_identification_start;			//29			1  bslbf
	unsigned char _[1];
	int aac_frame_length;								//30~42		13 bslbf
	int adts_buffer_fullness;							//33~53		11 bslbf
	unsigned char number_of_raw_data_blocks_in_frame;	//54~55		2 uimsfb
	unsigned char __[3];
}TADTSHeader;
//Data structure defined area end
/***************************************************************************/

//MP4ת��ʧ�ܷ���ֵ����
#define MP4_CONVERT_ERROR_CRYPT_FAILED          -2
#define MP4_CONVERT_ERROR_SPSPPS_CONTINUE       -3
#define MP4_CONVERT_ERROR_FATAL                 -4
#define MP4_CONVERT_ERROR_TRYNEXT               -5
#define MP4_CONVERT_ERROR_OVER_CURCONVERT       -6

//�����޸�����ֵ����
#define MP4_DIRBURN_READCD_FAILED  				-11
#define MP4_DIRBURN_READCD_NOTENOUGH 			-12
#define MP4_DIRBURN_READCD_OVER    				-13
#define MP4_DIRBURN_NOT_CONFORM 				-14


#ifdef ALONE
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
#ifdef FOR_MP4SDK
	td_u32 		m_iTimeNow;
#else
	time_t		m_iTimeNow;
#endif
	td_u32		m_iPos;
	td_u32 		m_iSign;//0����δ��ǣ�1������//add by gyn
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
#endif

 //---------------------------------------------------------------------------------------------

typedef struct
{
	 S_FileHeader	  m_stSdvFileHead;   	/*���ڱ���ԭSDV �ļ�ͷ*/
	 int	          m_iFileEndTime;	    /*���ڱ���ԭSDV �ļ�����ʱ��*/
	 int              m_iReserveFlag;       /*���ñ�־*/
}TExRecInfo;

 //MP4����֡ͷ�ṹ��
typedef struct
{
	 TIFrameIndexHead m_stSdvIndexHead;//ԭSDV ����ͷ
	 TExRecInfo 	  m_stExRecInfo;//�����¼��ԭSDV �ļ���Ϣ
}TMP4ISampleIndexHead;

 //����֡β�ṹ��
typedef struct
{
	td_s32		m_iFlag;
	td_s32      m_iSize;//����֡��С
	//td_u8 		m_cCDSerialNo[MAX_CDROMSERIALNO_LEN];
}TMP4ISampleIndexTail;

 //��չMP4 ������Ϣ
typedef struct
{
	 int				 m_iSampleID;		 //֡���
#ifdef FOR_MP4SDK
	 td_u32 			 m_tSampleTimeStamp; // ʱ���
#else
	 time_t 			 m_tSampleTimeStamp; // ʱ���		
#endif
 }TMP4ISampleExIndexInfo;

 //MP4����֡��Ϣ�ṹ��Ԫ
typedef struct
{
	 TIFrameIndexInfo		 m_stSdvIndexInfo;	 // SDV������Ϣ
	 unsigned int            m_uiUselessCount;    // ��Ч֡֡��
	 TMP4ISampleExIndexInfo  m_stVideoSampleIndexInfo;	 //��Ƶ������Ϣ
	 TMP4ISampleExIndexInfo  m_stAudioSampleIndexInfo;	 //��Ƶ������Ϣ
 }TMP4ISampleIndexInfo;

//�����ַ���Ϣ�ṹ
typedef struct
{
	td_s32		 m_iFlag;
	td_u32 		 m_iSize;
	td_u8		 m_pcCharInfo[MAX_RESERVED_INFO_LEN];
}TAppendCharInfoEx;

typedef struct
{
	char                 	m_cBoxheader[MP4_BOX_SIEZ_LENGTH+MP4_SAMPLE_TYPE_LENGTH];
	TMP4ISampleIndexHead 	m_stMP4ISampleIndexHead;
	TMP4ISampleIndexInfo*	m_pMP4ISampleMem;//������Ϣ����
	TAppendCharInfoEx    	m_stMP4Appendinfo;
	TMP4ISampleIndexTail 	m_stMP4ISampleIndexTail;
}TMP4VirFrameInfo; 

typedef struct
{
	int m_iStartTime;
	int m_iEndTime;
}TSdvFileTime;

typedef struct
{
	int m_iStartTime;
	int m_iEndTime;
}TAdjournInfo;

typedef struct
{
	int         m_iFlag;          //��־0x0123abcf
	int 		m_iCounts;        //ת����С�ļ�����
	int 		m_iMemNum;        //����TSdvFileTime �ڴ����
	TSdvFileTime* 	m_pSdvFileTimeMem;//ת���ļ�ʱ����Ϣbuf
}TSdvTimeSumInfo;
 
//---------------------------------------------------------------------------------------------
#define MAX_MP4_FILE_HEADER_SIZE       	1024
#define MAX_MP4_File_TAIL_SIZE         	512*1024
#define MAX_MP4_CONVSESSION_NUM     	2
#define MAX_RELLOC_MEMNUM               500
#define MAX_ADJOURN_TIMES               50

#ifndef FILE_HEADER_COVER_WORD
#define FILE_HEADER_COVER_WORD	"S MULTI-MEDIA STREAM (H.264)"
#endif

typedef enum
{
	DIRBURN_WITHSATA = 1,//��Ӳ��ֱ��
	DIRBURN_WITHOUTSATA,//��Ӳ��ֱ��
}MP4ConvertType;

typedef enum
{
	VIDEODATA = 1,//��Ƶ����
	AUDIODATA,   //��Ƶ����
}DataType;

typedef enum
{
	READFILE = 1,//���ļ�
	READCDROM,   //������
}ReadType;

typedef enum
{
	CHINESE = 1,//����
	ENGLISH, //Ӣ��
}LanguageType;

#ifdef FOR_MP4SDK
#pragma pack (1)
typedef struct
{
	int                     m_iUsing;                   /*�Ƿ�����ʹ��*/
	unsigned int       		m_uiDevNo;					/*   ���ػ���Ӧ������*/
	int                		m_iConvertNO;				/*   ת�����ļ����*/
	int                		m_iConvertType;				/*   ת������*/
	unsigned int            m_uiEncryptFlag;			/*   �Ƿ����0��������1������*/
	unsigned int            m_uiAudioType;				/*   ��Ƶ����*/
	int                		m_iStopConvert;				/*   ǿ��ֹͣ��־*/
	int	               		m_iFileBeginTime;			/*   ��MP4�ļ���ת����ʼʱ��*/
#ifdef TD_VFS
	TVfile* 				m_CurMP4Handle;		  		/*   ��ǰMP4�������ļ����*/
#else
	FILE* 					m_CurMP4Handle;		
#endif
	TMP4Mgr            		m_stMP4Manager;
	TSdvTimeSumInfo     	m_stSdvTimeSumInfo;      /*   ��¼���ļ��е���ͥ��Ϣ*/
	unsigned long long 		m_ullFileSize;				/*   ��ǰ��¼���ļ���С*/	
	unsigned long long    	m_ullVideoTotalDuration;	/*   ת��������Ƶ�����̶�*/
	unsigned long long    	m_ullAudioTotalDuration;	/*   ת��������Ƶ�����̶�*/
	unsigned char*          m_puVirFrameBuf;        /*   MP4 ����֡����*/
	pthread_mutex_t    		m_SesssionLock;
}TMP4ConvertSession;
#pragma pack ()

#else
typedef struct
{
	int                     m_iUsing;                   /*�Ƿ�����ʹ��*/
	unsigned int       		m_uiDevNo;					/*   ���ػ���Ӧ������*/
	int                		m_iConvertNO;				/*   ת�����ļ����*/
	int                		m_iConvertType;				/*   ת������*/
	unsigned int            m_uiEncryptFlag;			/*   �Ƿ����0��������1������*/
	unsigned int            m_uiAudioType;				/*   ��Ƶ����*/
	int                		m_iStopConvert;				/*   ǿ��ֹͣ��־*/
	int	               		m_iFileBeginTime;			/*   ��MP4�ļ���ת����ʼʱ��*/
#ifdef TD_VFS
	TVfile* 				m_CurMP4Handle;		  		/*   ��ǰMP4�������ļ����*/
#else
	FILE* 					m_CurMP4Handle;		
#endif
	TMP4Mgr            		m_stMP4Manager;
	TSdvTimeSumInfo     	m_stSdvTimeSumInfo;      /*   ��¼���ļ��е���ͥ��Ϣ*/
	unsigned long long 		m_ullFileSize;				/*   ��ǰ��¼���ļ���С*/	
	unsigned long long    	m_ullVideoTotalDuration;	/*   ת��������Ƶ�����̶�*/
	unsigned long long    	m_ullAudioTotalDuration;	/*   ת��������Ƶ�����̶�*/
	unsigned char*          m_puVirFrameBuf;        /*   MP4 ����֡����*/
	pthread_mutex_t    		m_SesssionLock;
}__attribute__((packed))TMP4ConvertSession;
#endif
//---------------------------------------------------------------------------------------------
int td_printf_mp4log(unsigned int handle, char* pszfmt, ...);

void* td_mp4_fopen(void* _pFileParam, const char* _cFileName, char* _cMode);

int td_mp4_fread(void *ptr, size_t size, size_t nmemb, void *stream);

int td_mp4_fwrite(const void *ptr, size_t size, size_t nmemb, void *stream);

#ifdef FOR_MP4SDK

int td_mp4_fseek(void *stream, __int64 offset, int whence);

__int64 td_mp4_ftell(void *stream);
#else


//int td_mp4_fseek(void *stream, long offset, int whence);

int td_mp4_fseek(void *stream, off_t offset, int whence);

//long td_mp4_ftell(void *stream);

off_t td_mp4_ftell(void *stream);
#endif

int td_mp4_feof(void *stream);

int td_mp4_fclose(void *fp);

int td_mp4_stat(char* _cFileName, void*_buf);

int td_mp4_unlink(char* _cFileName);
//---------------------------------------------

int MP4_GetMP4FreeVerSion(char* _pcFileName, int _iFreeNo, unsigned int* _puiVersion);

//����ǿ��ֹͣת��״̬������ʱ�豣֤ת���ӿڴ��е���
int MP4_SetForceStopState(int _iState);//0 ��ֹͣ1 ֹͣ

int MP4_GetForceStopState();

/************************************************* 
  Function: MP4_ConvertSdvToMp4
  Author: ��־��(Huangzhigang)
  Description: ���ڽ�SDV �ļ�ת���ɱ�׼MP4 �ļ�
  Input: _pcSrcFilePath ��ԴSDV �ļ�·��
  Input: _pcDstFilePath ��Ŀ������ɵ�MP4 �ļ�·��
  Output:
  Return: ����ִ�гɹ����� -1, ʧ�ܷ��� 0
  Others: 
*************************************************/
int MP4_ConvertSdvToMp4(const char* _pcSrcFilePath, char* _pcDstFilePath);
int MP4_ConvertSdvToMp4Ex(const char* _pcSrcFilePath,  char* _pcDstFilePath, unsigned int _uiStartPos, unsigned int _uiEndPos);
//�ж��Ƿ�ΪMP4 �ļ�
int MP4_IsMP4File(char* _pcFileName);
//�ж��ļ��Ƿ�������ת��
int MP4_CheckFileConvertState(char* _pcFileName);
//��ȡý��TrackId
int MP4_GetTrackId(char* _pcFileName, unsigned int* _puTrackId, char* _pcTrackType);
int MP4_GetTrackId_V2(void* _pMP4Handle, unsigned int* _puTrackId, char* _pcTrackType);
//��ȡ��ӦTrack��sample����
int MP4_GetTrackSampleNums(char* _pcFileName, unsigned int _uTrackId, unsigned int* _piNums);
//��ȡ�ļ�SPS��PPS��Ϣ
int MP4_GetSpsPps(char* _pcFileName, char* _pcSps, int* _piSpsSize, char* _pcPps, int* _piPpsSize);
int MP4_GetSpsPps_V2(void* _pMP4Handle, char* _pcSps, int* _piSpsSize, char* _pcPps, int* _piPpsSize);

//��ȡ�ļ�VPS��SPS��PPS��Ϣ
int MP4_GetVpsSpsPps(char* _pcFileName, char* _pcVps, int* _piVpsSize, char* _pcSps, int* _piSpsSize, char* _pcPps, int* _piPpsSize);
int MP4_GetVpsSpsPps_V2(void* _pMP4Handle, char* _pcVps, int* _piVpsSize, char* _pcSps, int* _piSpsSize, char* _pcPps, int* _piPpsSize);
//��ȡMP4 �ļ��е���Ƶ����
int MP4_GetAudioType(char* _pcFileName, int* _piAudioType);
//��ȡmp4�ļ��ļ���״̬
int MP4_GetMP4FileEncryptStat(char* _pcFileName, int* _piEncryptStat);
//��ȡ�ļ�������Ϣ(��һ������Ϊ�ļ�����ÿ��һ�Σ���ִ��һ��
//MP4Read���Դ��ļ����Ժ�ʱ�ϳ�)
int MP4_ReadSampleIndex(char* _pcFileName, 
								TMP4ISampleIndexHead *_pstMP4ISampleIndexHead, 
								TMP4ISampleIndexTail* _pstMP4ISampleIndexTail, 
								void ** _pIMP4SampleIndex, 
								int* _piIMP4SampleIndexmollocLen);
//��ȡ�ļ�������Ϣ(��һ������Ϊ�ļ���������ٺ�ʱ���MP4Read����
//���Կ�Դ������������ӿڵ��ã���������Ȼ���ʱ������)
int MP4_ReadSampleIndex_V2(void* _pMP4Handle, 
									TMP4ISampleIndexHead *_pstMP4ISampleIndexHead, 
									TMP4ISampleIndexTail* _pstMP4ISampleIndexTail, 
									void ** _pIMP4SampleIndex, 
									int* _piIMP4SampleIndexmollocLen);
//��ȡ�ļ�������Ϣ(���µ��ļ���¼����ȥ�������֡��������һ����Դ��ӿ�
//��ʱ��̣�ǰ�����°汾�Ĵ�MP4�ļ�)
int MP4_ReadSampleIndex_V3(char* _pcFileName, 
									TMP4ISampleIndexHead *_pstMP4ISampleIndexHead, 
									TMP4ISampleIndexTail* _pstMP4ISampleIndexTail, 
									void ** _pIMP4SampleIndex, 
									int* _piIMP4SampleIndexmollocLen);
#ifdef ZHENGFA
//��ȡ�ļ�CD ���к�
int MP4_GetFileCDSerialNo(char* _pcFileName, td_u8* _CDSerialNOBuf);
#endif
//��ȡ�ļ�����ʱ��
int MP4_GetFileEndTime(char* _pcFileName, time_t *_pFileEndTime);
//��ȡ������Ϣ�б����SDV �ļ�ͷ
int MP4_ReadSdvFileHeader(char* _pcFileName, S_FileHeader* _pstFileHeader);
int MP4_ReadSdvFileHeader_V2(void* _pMP4Handle, S_FileHeader* _pstFileHeader);
//��ȡ�ļ��ص�����Ϣ
int MP4_ReadSign(char*_pcFileName, void* _pMarkInfo);
//��λMP4 �ļ�
int MP4_SeekFile(TMP4ISampleIndexHead *_pstMP4ISampleIndexHead, 
				TMP4ISampleIndexTail* _pstMP4ISampleIndexTail, 
				void * _pIMP4SampleIndex, 
				int _iPosOrTime, 
				unsigned int* _puiSeekVideoSampleId, 
				unsigned int* _puiSeeKAudioSampleId);
//V2�汾���漰����SEI ����Ч֡�ļ���
int MP4_SeekFile_V2(TMP4ISampleIndexHead *_pstMP4ISampleIndexHead, 
					TMP4ISampleIndexTail* _pstMP4ISampleIndexTail, 
					void * _pIMP4SampleIndex, 
					int _iPosOrTime, 
					unsigned int* _puiSeekVideoSampleId, 
					unsigned int* _puiSeeKAudioSampleId,
					unsigned int* _puiUselessCount);
//����ʱ�䶨λ֡��
unsigned int MP4_GetSeekPosSampleId(void* _hFile, unsigned int _trackId, unsigned long long _when, int _wantSyncSample);
//��MP4 �ļ�
int MP4_OpenFile(void** _MP4fp, char* _pcFileName);
//�ر�MP4 �ļ�
int MP4_CloseFile(void** _MP4fp);
//��MP4 �ļ��л�ȡһ֡˽��֡
int MP4_GetOneTiandyFrame(void* _pMP4fp, 
									 unsigned int _u32VideoTrackId, 
									 unsigned int _u32AudioTrackId,
									 unsigned int* _puiCurVideoSampleId, 
									 unsigned int* _puiCurAudioSampleId, 
									 char* _pSps, 
									 int _iSpsSize, 
									 char* _pPps, 
									 int _iPpsSize,
									 void* _pTiandyFrameBuf, 
									 S_FrameHeader* _pstFrmaeHeader, 
									 int _iAudioType);
//��MP4 �ļ��л�ȡ��һ��I  ˽��֡
int MP4_GetOneITiandyFrame(void* _pMP4fp, 
									 unsigned int _u32VideoTrackId, 
									 unsigned int _u32AudioTrackId,
									 unsigned int* _puiCurVideoSampleId, 
									 unsigned int* _puiCurAudioSampleId, 
									 char* _pSps, 
									 int _iSpsSize,
									 char* _pPps, 
									 int _iPpsSize,
									 void* _pTiandyFrameBuf, 
									 S_FrameHeader* _pstFrmaeHeader, 
									 int _iAudioType);
//��MP4 �ļ��л�ȡһ֡˽��֡������SEI ����
int MP4_GetOneTiandyFrame_V2(void* _pMP4fp, 
										 unsigned int _u32VideoTrackId, 
										 unsigned int _u32AudioTrackId,
										 unsigned int* _puiCurVideoSampleId, 
										 unsigned int* _puiCurAudioSampleId, 
										 char* _pSps, 
										 int _iSpsSize, 
										 char* _pPps, 
										 int _iPpsSize,
										 void* _pTiandyFrameBuf, 
										 S_FrameHeader* _pstFrmaeHeader, 
										 int _iAudioType, 
										 unsigned int* _puiUseLessIdCount, 
										 int _iNeedIFrame);
//�Ӽ���MP4�ļ��л�ȡһ�����˽��֡
td_s32 MP4_GetOneEncryptTiandyFrame(void* _pMP4fp,  
												 unsigned int _u32VideoTrackId, 
												 unsigned int _u32AudioTrackId,
												 unsigned int* _piCurVideoSampleId, 
												 unsigned int* _piCurAudioSampleId, 
												 void* _pTiandyFrameBuf, 
												 S_FrameHeader* _pstFrmaeHeader, 
												 int _iAudioType,
												 int _iNeedIFrame);

int MP4_GetOneTiandyFrameH265(void* _pMP4fp, 
									 unsigned int _u32VideoTrackId, 
									 unsigned int _u32AudioTrackId,
									 unsigned int* _puiCurVideoSampleId, 
									 unsigned int* _puiCurAudioSampleId,
									 char* _pVps, 
									 int _iVpsSize, 
									 char* _pSps, 
									 int _iSpsSize, 
									 char* _pPps, 
									 int _iPpsSize,
									 void* _pTiandyFrameH265Buf, 
									 S_FrameHeader* _pstFrmaeHeader, 
									 int _iAudioType);
int MP4_GetOneITiandyFrameH265(void* _pMP4fp, 
									 unsigned int _u32VideoTrackId, 
									 unsigned int _u32AudioTrackId,
									 unsigned int* _puiCurVideoSampleId, 
									 unsigned int* _puiCurAudioSampleId,
									 char* _pVps, 
									 int _iVpsSize,
									 char* _pSps, 
									 int _iSpsSize,
									 char* _pPps, 
									 int _iPpsSize,
									 void* _pTiandyFrameH265Buf, 
									 S_FrameHeader* _pstFrmaeHeader, 
									 int _iAudioType);
int MP4_GetOneTiandyFrameH265_V2(void* _pMP4fp, 
										 unsigned int _u32VideoTrackId, 
										 unsigned int _u32AudioTrackId,
										 unsigned int* _puiCurVideoSampleId, 
										 unsigned int* _puiCurAudioSampleId, 
										 char* _pVps, 
										 int _iVpsSize, 
										 char* _pSps, 
										 int _iSpsSize, 
										 char* _pPps, 
										 int _iPpsSize,
										 void* _pTiandyFrameH265Buf, 
										 S_FrameHeader* _pstFrmaeHeader, 
										 int _iAudioType, 
										 unsigned int* _puiUseLessIdCount, 
										 int _iNeedIFrame);
td_s32 MP4_GetOneEncryptTiandyFrameH265(void* _pMP4fp,  
												 unsigned int _u32VideoTrackId, 
												 unsigned int _u32AudioTrackId,
												 unsigned int* _piCurVideoSampleId, 
												 unsigned int* _piCurAudioSampleId, 
												 void* _pTiandyFrameH265Buf, 
												 S_FrameHeader* _pstFrmaeHeader, 
												 int _iAudioType,
												 int _iNeedIFrame);




//new interface
typedef int (*MP4BigFileWirteBuffer)(unsigned int _uiDevNo, unsigned char* _pcbuf, unsigned int _uiBufferLen);
typedef int (*MP4BigFileReadDisk)(unsigned int _uiDevNo, unsigned long long _ullAddress, unsigned char* _pcbuf, unsigned long long _ullLen);

//��ʼ��MP4 ת��ģ��
void MP4_BurnInit();
//ע��MP4 дbuf �ص�����
int MP4_RegWriteBufCallBack(MP4BigFileWirteBuffer _CallBack);
//ע��MP4 ��Ӳ�̻ص�����
int MP4_RegReadDiskCallBack(MP4BigFileReadDisk _CallBack);
//��ȡת����β��С
int MP4_GetConvertTailSize(void* _MP4File, unsigned long long* _pullTailSize);
//����ת��MP4 �ļ���ʱ��
int MP4_DirBurnUpdateMP4FileTime(unsigned long long _ullMP4Time);
//��ȡMP4 �ļ�ͷ
void* MP4_DirBurnGetFileHeader(unsigned int _uiDevNo, unsigned int _uiMdatSize, int _iConvertType);
//��ȡMP4 �ļ�����
int MP4_DirBurnGetFileData(void* _pMP4FileHandle, char *_pSrcFile,  char* _pDstFile);
//��ȡMP4 �ļ�β
int MP4_DirBurnGetFileTail(void* _pMP4FileHandle, char* _pTailFilePath);
//�ϵ��޸�MP4 �ļ�
int MP4_DirBurnResum(unsigned int _uiDevNo, unsigned long long _iDiskTotalSize, char* _pFilePath);
//����ת��
int MP4_StopConvert(void* _pMP4FileHandle);
//��ȡ����ת������sdv���ļ�ʱ��
int MP4_GetSdvConvertInfo(char* _pFilename, int* _piCounts, char** _pcInfoBuf, int* _piInfoLen);
//��ȡ���ļ��е���ͥʱ��
int MP4_GetFileAdjournTime(char* _pFilename, int* _piAdjournCnt, char** _pcAdjournInfo);
//�ϵ��޸����
#ifdef FOR_MP4SDK
#pragma pack (1)
typedef struct 
{
	unsigned char AudioType;
	unsigned char ProfileLevel;
	unsigned char languagetype;
	unsigned char other;//�ֽڶ�������
	unsigned int timeScale;
	unsigned long long sampleDuration;
}TAudioTrackInfo;

typedef struct 
{
	unsigned char AVCProfileIndication;
	unsigned char profile_compat;
	unsigned char AVCLevelIndication;
	unsigned char sampleLenFieldSizeMinusOne;
	unsigned short sequenceLen;
	unsigned short pictLen;						
	unsigned short width;
	unsigned short height;
	unsigned int timeScale;
	unsigned long long sampleDuration;
	//unsigned char pSequence; 
	//unsigned char pPict;
}TVideoTrackInfo;

typedef struct
{
	unsigned int 	     uiSampleSize;      /* ��С*/
	unsigned long long   sampleDuration;/* �����̶�*/
}TSizeAndDuring;


typedef struct
{
	int 			m_iFrameFlag;     /* �Ƿ�I ֡����Ƶ(-1: ��Ƶ0:��Ƶ��I֡1:��ƵI ֡)*/
	TSizeAndDuring 	m_uiAVSizeAndDuring;      /*��Ƶ��Ϣ*/
}TAVSampleInfo;

//Box size 4, type 4       4 �ֽ�
//Custom Flag               8 �ֽ�
//vsersion                     4 �ֽ�

typedef struct
{
	unsigned int  m_uiSize;    /* ������Ϣ��С */
	unsigned char m_ucType[4]; /* ���� VIRTUAL_FRAME_TYPE  SAMPLE_OFFSET_TYPE SAMPLE_TS_TYPE AV_INFO_TYPE*/
	unsigned int  m_uiMemSize; /*��Ԫ��Ϣ�Ĵ�С*/
	unsigned char m_pData[0];	    /* ��Ԫ��Ϣ����*/
}TBaseUnit;

typedef enum
{
	BOXHEAD_HALF = 1,    
	BOXHEAD_WHOL, 
	SMALLMDAT,
	OTHER,
}AnalasyType;

typedef struct
{
	int                   m_iUsing;//�˻Ự�Ƿ���ʹ��
	unsigned int          m_uiDevNo;
	unsigned int 		  m_uiCurMP4BoxSize;
	unsigned int          m_uiLastBoxResumSum;//���һ����box ������������
	unsigned int          m_uiLastBoxResumZero;//���һ����box ����0 ��������
	int                   m_iFileBeginTime;
	unsigned int 		  m_VideoTrackID;    /*��ƵID*/
	unsigned int          m_AudioTrackID;    /*��ƵID*/
	unsigned int          m_AudioType;       /*��Ƶ����*/
	unsigned int 	      m_uiCurBoxReadSum;
	unsigned long long    m_ullCDSize;
	unsigned long long    m_ullCDAddress;	
	unsigned long long    m_ullVideoTotalDuration;//�޸���¼����Ƶ�����̶�
	unsigned long long    m_ullAudioTotalDuration;//�޸���¼����Ƶ�����̶�
	TVideoTrackInfo       m_VideoTrackInfo;
	TAudioTrackInfo       m_AudioTrackInfo;	
	int                   m_iMoovOrFree;   //�������𻵵���moov ��free ��Ҫע�������ͣ�������ǣ���Ĭ��ֵ0
	unsigned int          m_uiMoovOrFreeLen;//����𻵵�moov ��free ����
	void*				  m_MP4Handle;    /*MP4 �ļ����*/
	unsigned char*        m_pVideoTrackInfo;
	unsigned char*        m_pLastResumBox;
	unsigned char*		  m_puVirFrameBuf;		/*	 MP4 ����֡����*/
	unsigned char*        m_pDataBuf;
	pthread_mutex_t    	  m_SesssionLock;
}TMP4ResumSession;
#pragma pack ()
#else
typedef struct 
{
	unsigned char AudioType;
	unsigned char ProfileLevel;
	unsigned char languagetype;
	unsigned char other;//�ֽڶ�������
	unsigned int timeScale;
	unsigned long long sampleDuration;
}__attribute__((packed))TAudioTrackInfo;

typedef struct 
{
	unsigned char AVCProfileIndication;
	unsigned char profile_compat;
	unsigned char AVCLevelIndication;
	unsigned char sampleLenFieldSizeMinusOne;
	unsigned short sequenceLen;
	unsigned short pictLen;						
	unsigned short width;
	unsigned short height;
	unsigned int timeScale;
	unsigned long long sampleDuration;
	//unsigned char pSequence; 
	//unsigned char pPict;
}__attribute__((packed))TVideoTrackInfo;

typedef struct
{
	unsigned int 	     uiSampleSize;      /* ��С*/
	unsigned long long   sampleDuration;/* �����̶�*/
}__attribute__((packed))TSizeAndDuring;


typedef struct
{
	int 			m_iFrameFlag;     /* �Ƿ�I ֡����Ƶ(-1: ��Ƶ0:��Ƶ��I֡1:��ƵI ֡)*/
	TSizeAndDuring 	m_uiAVSizeAndDuring;      /*��Ƶ��Ϣ*/
}__attribute__((packed))TAVSampleInfo;

//Box size 4, type 4       4 �ֽ�
//Custom Flag               8 �ֽ�
//vsersion                     4 �ֽ�

typedef struct
{
	unsigned int  m_uiSize;    /* ������Ϣ��С */
	unsigned char m_ucType[4]; /* ���� VIRTUAL_FRAME_TYPE  SAMPLE_OFFSET_TYPE SAMPLE_TS_TYPE AV_INFO_TYPE*/
	unsigned int  m_uiMemSize; /*��Ԫ��Ϣ�Ĵ�С*/
	unsigned char m_pData[0];	    /* ��Ԫ��Ϣ����*/
}__attribute__((packed))TBaseUnit;

typedef enum
{
	BOXHEAD_HALF = 1,    
	BOXHEAD_WHOL,  
	SMALLMDAT,
	OTHER,
}AnalasyType;

typedef struct
{
	int                   m_iUsing;//�˻Ự�Ƿ���ʹ��
	unsigned int          m_uiDevNo;
	unsigned int 		  m_uiCurMP4BoxSize;
	unsigned int          m_uiLastBoxResumSum;//���һ����box ������������
	unsigned int          m_uiLastBoxResumZero;//���һ����box ����0 ��������
	int                   m_iFileBeginTime;
	unsigned int 		  m_VideoTrackID;    /*��ƵID*/
	unsigned int          m_AudioTrackID;    /*��ƵID*/
	unsigned int          m_AudioType;       /*��Ƶ����*/
	unsigned int 	      m_uiCurBoxReadSum;
	unsigned long long    m_ullCDSize;
	unsigned long long    m_ullCDAddress;	
	unsigned long long    m_ullVideoTotalDuration;//�޸���¼����Ƶ�����̶�
	unsigned long long    m_ullAudioTotalDuration;//�޸���¼����Ƶ�����̶�
	TVideoTrackInfo       m_VideoTrackInfo;
	TAudioTrackInfo       m_AudioTrackInfo;	
	int                   m_iMoovOrFree;   //�������𻵵���moov ��free ��Ҫע�������ͣ�������ǣ���Ĭ��ֵ0
	unsigned int          m_uiMoovOrFreeLen;//����𻵵�moov ��free ����
	void*				  m_MP4Handle;    /*MP4 �ļ����*/
	unsigned char*        m_pVideoTrackInfo;
	unsigned char*        m_pLastResumBox;
	unsigned char*		  m_puVirFrameBuf;		/*	 MP4 ����֡����*/
	unsigned char*        m_pDataBuf;
	pthread_mutex_t    	  m_SesssionLock;
}__attribute__((packed))TMP4ResumSession;

#endif

//==========================mp4 decode start=============================================


typedef void*       td_MP4FileHandle;

typedef struct{
	TMP4ISampleIndexHead	m_stTMP4ISampleIndexHead;
	TMP4ISampleIndexTail	m_stTMP4ISampleIndexTail;
}TMP4FileHead;

typedef enum{
	SEEK_FORWARD,
	SEEK_BACKWARD,
	SEEK_ABSOLUTE,		
}ESeekOps;

td_MP4FileHandle * MP4_Open (td_char *_pcFileName);
td_s32 MP4_Close (td_MP4FileHandle *_pMP4fh);
td_s32 MP4_GetFileHead(td_MP4FileHandle *_pMP4fh, TMP4FileHead *_pstMP4FileHead);
td_s32 MP4_Read (td_MP4FileHandle *_pMP4fh, td_void *_pFrameBuf, td_u32 _bufLen);
td_s32 MP4_Seek(td_MP4FileHandle *_pMP4fh, td_u64 _frameId, ESeekOps _type);


//==========================mp4 decode end==============================================


#endif //__TD_MP4_H_INCLUDED__


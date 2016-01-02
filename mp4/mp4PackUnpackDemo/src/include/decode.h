#ifndef _DECODE_H
#define _DECODE_H

#include "td_media.h"
#include "libtdvo.h"
#include "libdec.h"
#include "libdatacenter.h"
#include "ringbuf.h"
#include "libstorage.h"
#include "td_mp4.h"

#define AO_DEV_ID	0
#define FILENAMEMAXNUM	128
#define MAXAUDIOFRAMES 100
#define MAXPLAYER 16
#define DELAYTM	(5 * 1000)
#define BUF
#define READDATA		0
#define COPYDATA	1
#define MOVRDATA	2

#define PLAYBACK_IFRAME		2000

#define PLAYBACK_FILEFINISH_NOEFFECT		-1000
//#define PLAYBACK_FILEFINISH_EFFECT		-1001
#define PLAYBACK_READFILE_ERR				-1002
#define PLAYBACK_PLUGFRAME				-1003
#define PLAYBACK_NOINDEX					-1004
#define Play_Set_CapErr(n)	(n &= ~(1<<1), n |= (1<<0))
#define Play_Set_CapOk(n)	(n &= ~(1<<0), n |= (1<<1))
#define Play_Clr_Cap(n)		(n &= ~(1<<0), n &= ~(1<<1))
#define Play_Test_CapErr(n)	(n & (1<<0))
#define Play_Test_CapOk(n)	(n & (1<<1))
#define Play_Set_BackErr(n)	(n |= (1<<2))
#define Play_Clr_Back(n)		(n &= ~(1<<2))
#define Play_Test_BackErr(n)	(n & (1<<2))
#define Play_Clr_All(n)		(n = 0)
#define PLAYBACK_MEM_FULL		3000
#define PLAYBACK_BACK_NOCLIP	(-1000)
#define PLAYBACK_BACK_BITNUM	10

typedef enum
{
	PLAYBACK_STAT_INIT = 0, 	//��ʼ״̬
	PLAYBACK_STAT_PLAY,	//���ڲ���״̬
	PLAYBACK_STAT_PAUSE,	//�ط���ͣ״̬
	PLAYBACK_STAT_STOP,	//�طŽ���״̬
	PLAYBACK_STAT_STEP,	//�طŲ���״̬
	PLAYBACK_STAT_BACK,	//����״̬
	PLAYBACK_STAT_BACKSTEP,	//���Ų���״̬
	PLAYBACK_STAT_ERROR = 100	//����״̬
} PLAYBACK_STAT;

typedef enum
{
	DECODEBUF_NOUSE = 0, 	//��ʼ״̬
	DECODEBUF_READY = 1,
	DECODEBUF_WORK = 2,
	DECODEBUF_OVER = 3,
	DECODEBUF_ERROR = 100	//����״̬
} DECODEBUF_STAT;

typedef struct _Td_AO
{
	int             m_iAoId;
	int				m_iAencType;		//��Ƶ��������
	int				m_iAoPoiNum;		//��Ƶ�������֡��
}Td_AO;
typedef struct 
{
	unsigned char EncrptTestBuf[64];
	unsigned int FrameID;
}TEncryp;

typedef struct
{
	void *m_pCoach;
	void *m_pData;// ԭʼ����������
	void *m_pDataHeader;// ԭʼ������ͷ��
	int m_iLen;// ���ݵĴ�С
}TOrigData;

typedef struct
{
	void *m_data;
	int (*BackMem_Init)(void *_this);
	int (*BackMem_destroy)(void *_this);
	int (*BackMem_could_write)(void *_this);//0:������д��1:����д
	int (*BackMem_write)(void *_this,TOrigData *ptr, S_FrameHeader *_pFrameHeader, int _iFileLoc, int _iFinishFlag);
	int (*BackMem_read)(void *_this, TOrigData *ptr);//����֡ͷ��Ϣ
	int (*BackMem_read_nofree)(void *_this, S_FrameHeader *_pheader);//����֡ͷ��Ϣ
	int (*BackMem_getSize)(void *_this, int _iOrgDataLen);
	int (*BackMem_clear)(void *_this);
}TDecodeMem;//���Žṹ��

//�ļ�����//MP4--ZS
typedef enum
{
	FILE_TYPE_SDV = 1,
	FILE_TYPE_MP4,
	FILE_TYPE_MAX	
}EFileType;

//MP4�����Ϣ
typedef struct _MP4info
{
	void* m_pMp4_fp;
	unsigned int m_u32Version;
	unsigned int m_u32VideoTrackId;
	unsigned int m_u32AudioTrackId;
	int  m_iAudioType;
	int  m_iVideoType;
	char m_cVps[256];
	int  m_iVpsSize;
	char m_cSps[256];
	int  m_iSpsSize;
	char m_cPps[256];
	int  m_iPpsSize;
	int  m_iEncryptFlag;//�Ƿ�Ϊ�����ļ�0: ������1: ����
	//MP4����֡
	TMP4ISampleIndexHead m_stMP4ISampleIndexHead;
	TMP4ISampleIndexTail m_stMP4ISampleIndexTail;
	unsigned int m_uiCurVideoSampleId;//��ǰ��Ƶsample���
	unsigned int m_uiCurAudioSampleId;//��ǰ��Ƶsample���
	unsigned int m_u32UseLessIdCount;//������������֡��
	int m_iIMP4SampleIndexmollocLen;//����֡�����ڴ��С
	void *m_pIMP4SampleIndex;//��һ��������Ϣָ��
}TMP4info;

typedef struct _Stream
{
	int m_iForceDestroyFlag;
	int m_id;
	FILE *m_fp;
	TVdecChannel *m_pTVDec;
	Td_AO m_AO;
	Td_VO *m_pVO;//��Ӧ�Ľ���ͨ������Ƶ���ͨ��
	TVdecPara m_vdecPara;
	char m_File[FILENAMEMAXNUM];//¼���ļ����ļ���(����������·��)
	
	int m_iFileLen;//�ļ�����Ч����(����������֡��)
	int m_FileLoction;//����Ҫ�������ļ�λ��
	unsigned short m_u16BefAudioFrames;
	unsigned short m_u16ZeroAudioFrames;

	int m_iLeaveAudioFrames;
	int m_iLeaveAudioLoaction;
	int m_iLeaveAudioFramesLen;
	
	int m_iFileStartTime;
	int m_iFileEndTime ;
	int m_iOnlyIFrame;//�������I֡��־
	unsigned char m_ucEncrypt[ENCRYPT_PWD_LENGTH+1];
	
	S_FileHeader m_FileHeader;//�ļ�ͷ
	S_FrameHeader m_FrameHeader;//֡ͷ

	TEncryp m_tEncrypbuf;

	int m_iFindNoIndex;
	int m_IFrameLoaction;
	int m_IFrameLen;
	int m_mollocLen;
	
	int m_iIndexLen;
	int m_iFrameRate;
	pthread_mutex_t m_StructLock;
	///////////////����///////////
	int *m_piStop;
	int m_iVoHide;
	int m_iSeparate;
	int m_iBackFlag;
	int m_iFrameLoc;
	int m_iIFrameFileLoc;
	int m_iOrigFrameLen;
	unsigned int m_u32MoveMemFrameBit[PLAYBACK_BACK_BITNUM];
	int m_iMoveMemFrameNo;
	int m_iMoveMemFrameNoOrig;
	int m_iMoveMemFrameNum;
	S_FrameHeader m_tBackFrameHeader;//֡ͷ
	int m_iMemFrameLoc;

	int m_iBackFileLoc[2];
	int m_iSendStreamLoc;
	int m_iBackClip;
	TDecodeMem m_tBackMem;

	TOrigData m_tOrigData[2];
	
	volatile int m_BackId;
	pthread_cond_t m_iMemCondFullLock;
	//ץ��
	int m_iCapCnt;
	int m_iOptFlag;
	void *m_snapBuf;
	int m_iTime;
	void *m_pBuf;
	void *m_pIFrameIndex;
	//�ļ�����
    int m_iFileType;
	//MP4�����Ϣ
	TMP4info m_stMP4Info;
}TStream;
typedef struct _decode
{
	TStream m_Stream;

	int (*Init)(void * _This, int *_piStopFlag);
	int (*Destroy)(void * _This);
	int (*ForceDestroy)(void *_This);
	int (*CreateVo)(TStream *_This,TRect *_ptRect,int _iVoDev);
	int (*CreateVdec)(TStream *_This);
	int (*GetRate)(TStream *_This,double _dSpeed,int _iFlag);//
	int (*SetRate)(TStream *_This,int _iFrame, int _iPreFrameRate);
	int (*FullScr)(TStream *_This);
	int (*FullScrExit)(TStream *_This, TRect *_pRect);
	int (*OpenFile)(TStream *_This,IN td_s8* _cFileName);
	int (*CloseFile)(TStream *_This);
	td_s32 (*ReadFrame)(TStream *_This);
	td_s32 (*SendVStream)(TStream *_This);
	td_s32 (*SendAStream)(TStream *_This);
	int   (*SetPassword)(TStream *_This,char* _cPassword);
	int (*GetFileHeader)(TStream * _This, S_FileHeader * _pFileHeader);
	int (*GetFileName)(TStream *_This, td_u8 *_pcFileName);
	int (*GetFileAttribute)(TStream *_This,void * _Value, int _iFlag);
	int (*SeekPos)(TStream *_This,int _iPos, int *_pStopFlag);
	int (*ReleaseVStream)(TStream *_This);
	int (*VoContrl)(TStream *_This, int _iFlag);
	int (*DestroyAo)(TStream *_This);
	unsigned int (*GetFrameTm)(TStream *_This);
	td_s32 (*TestEncrypt)(TStream *_This, char* _cPassword);
	int (*DestroyVo)(TStream *_This);
	int (*DestroyVdec)(TStream * _This);
	int (*SendLeaveAudioFrames)(TStream *_This);
	td_s32 (*clearLeaveAudioStream)(TStream *_This);
	int (*capPicture)(TStream * _This, int _iTime, int _iFlag);
	int (*init_back)(TStream * _This, int _iClip);
	int (*destroy_back)(TStream * _This, int _iCommonly);
	int (*getOptStat)(TStream * _This, int *_piOptFlag);
}Decode;

int IsValidFileHeader(S_FileHeader* _header);
td_s32 _pack(td_s32 _s32Value);
//���ϵͳʱ��
int decode_GetSysTime(OUT long long *_lTime);
int decode_ChangeVoDisplayArea(int _iWidth,int _iHeight,TRect *_pRect,void  *_pVo);
int decode_Init(void *_This, int *_piStopFlag);

int decode_EnableBuf(void);
int decode_DisableBuf(void);
int  IsValidFrame(S_FrameHeader* frHeader);

int decode_mem_Init(void *_this);
int decode_getLobby(int _iHeight, int _iWith);

int decode_setdefaultAo(int _iDefaultAo);
int decode_Get_MAXBUFEX(void);
#endif


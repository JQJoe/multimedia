#ifndef _H_TD_STREAM_H_
#define _H_TD_STREAM_H_

#include "sysnotify.h"
#include "libtiandy.h"
#include "libother.h"
#include "hisi_head.h"

#define BASE_VO_VDEC_FRATE			10000
#define BASE_VO_VI_FRATE			20000
#define BASE_VO_CASCADE_VI_FRATE 	30000
#define BASE_VO_PCI_FRATE			40000

#define SNAP_FILE_NAME_LEN	64
#define DEFAULT_PIC_QUALITY	3	//Ĭ��ץ��ͼƬ����
#define SNAP_HD				0
#define SNAP_SD				1

#define VI_EZOOM	0
#define VDEC_EZOOM	1

#define VDEC_CHAN_NUM		20		
#define ADEC_CHAN_NUM		4

#define VIR_CHN_1			16  //�ϳ�ͨ��1��ͨ����



#define VIR_VO_VPSS_1		VI_VPSS_VIRVO_START		//48	//�ϳ�ͨ��1��vpssͨ����
#define VIR_VO_VENC_1_MAIN	48	//�ϳ�ͨ��1������������ͨ����
#define VIR_VO_VENC_1_SUB	50	//�ϳ�ͨ��1�ĸ���������ͨ����
#define VIR_VO_VENC_1_CAP	52	//�ϳ�ͨ��1��ץ�ı���ͨ����

#define VIR_VO_VENC_2_MAIN	49	//�ϳ�ͨ��2������������ͨ����
#define VIR_VO_VENC_2_SUB	51	//�ϳ�ͨ��2�ĸ���������ͨ����
#define VIR_VO_VENC_2_CAP	53	//�ϳ�ͨ��2��ץ�ı���ͨ����


#define AODEV_NUM_BASS	((td_s32)MediaGetChipInfo(MEDIA_INFO_AOBASSDEV))
#define AUDIO_OUT_DEV 	0			
#define AUDIO_OUT_CHN 	0

//��ʱʹ�ã���д��������������ܲ�����Ҫ
#define MIC_AI_DEV	tdmedia_InitMicDev()        //mic ��Ƶ�����豸��wsl 20111222 3531�޸�

#define HDMI_AO_DEV ((td_s32)MediaGetChipInfo(MEDIA_INFO_AOHDMIDEV))			//hdmi����豸��
#define TC_908NC_AI_CNT 5

//��Ƶ������𻮷�
#define F_MICIN			0x01 //1st tlv320 �����������
#define F_AOUT			F_MICIN //1st tlv320 ���ڱ������
#define F_HD_AIN		0x02 // 2nd,3rd,4th,5th tlv320 ���ڸ���ͨ������
#define F_SD_AIN		0x03 //ʹ��ADоƬ�ṩ������Ƶ����

//#define	OSD_OVERLAYEX_MAX_LEN 796 //hq, sdk7.1��ǰ���Ƶ�����vi�ϵĲ��ó���800��600��
#define	OSD_OVERLAYEX_MAX_LEN 1920 /*hq, sdk7.2�Ժ����Ƶ�����vi�ϵĲ��ó���1920��1080��
									ͬʱ������ܳ���800x600,��������δʹ���������*/

typedef struct
{
	td_u32 m_uPoolId;
	td_u32 m_uPhyAddr;
	td_u32 m_VbBlk;
	td_u8  *	m_VirAddr;
	td_u32		m_uBlkSize;
}strVbCoach;

typedef struct
{
	td_u8 *pu8Addr[2];
	td_u32 u32Len[2];
}strVencPack;

typedef struct 
{
	td_u32 u32PackCount;
	td_u32 u32Seq;
	td_u32 u32FrameType;	//֡����    FRAME_I = 0,   FRAME_P = 1;  
	td_u64 u64PTS;			//ʱ���, us
	strVencPack* pstPack;   //gxl modified 20110323
}strVencStream;

typedef struct 
{
	td_u8 *pStream; /*stream buffer */
	td_u32 u32Len; /*stream lenth*/
	td_u64 u64TimeStamp; /*frame time stamp*/
	td_u32 u32Seq; /*frame seq,if stream is not a valid frame,u32Seq is 0*/
}strAencStream;

typedef td_s32 (*VIDEOSTREAMCBK)(td_s32 _s32Chn, td_s32 _s32IsMainChn, strVencStream* _pstVStream);
typedef td_s32 (*AUDIOSTREAMCBK)(td_s32 _s32Chn,strAencStream* _pstAStream);
typedef td_s32 (*SNAPSHOTCBK)(td_s32 _s32Chn, td_s32 _s32BuffLen);

typedef struct
{	
	td_s32		m_s32VencChn;			//����ͨ���ţ��ڲ�ʹ�ã�����ʱ��Ч
	td_s32 		m_s32ChnType;			//����ͨ������0 ģ��ͨ��2�ϳɱ���ͨ��
	td_s32		m_s32EncType;			//��������0 H264 1 JPEG 
	td_s32		m_s32VideoSize;			//��Ƶ��С
	td_s32 		m_s32FrameRate;			//����֡��
	td_s32 		m_s32BitRate;			//����
	td_s32		m_s32IFrameRate;		//I֡֡��
	td_s32 		m_s32MainStream;		//����������ʶ 0 ������ 1������
	td_s32 		m_s32StreamType;		//�������� 0 ������ 1 ������
	td_s32 		m_s32Quality;			//��Ƶ����
	td_s32		m_s32VoDev;				//vo�����豸�ţ���vo����ͨ����Ч
	td_s32		m_s32SlaveStreamType;	//������Ƭ����ʱ����������(����Ƶ ����Ƶ)
	td_s32		m_s32VideoProfile;		//��Ƶprofile����
	pthread_mutex_t	m_vencLock;			//lxy add 20120515
} strVencParameter;

typedef struct
{
	strVencParameter 	m_stVencParamter;
	td_s32				m_Reserved[4];  //m_Reserved[1]Ϊ�����ص�����ָ�룬
	 									//m_Reserved[2]Ϊץ�Ļص�����ָ�룬
	 									//m_Reserved[3]Ϊ��ͨ������������
	VIDEOSTREAMCBK m_cbkVStream; 		//��Ƶ�ص�����
}strVencParam;
#if 0
typedef struct
{
	td_s32 		m_s32AencChn;	//��Ƶ����ͨ���ţ��ڲ�ʹ�ã�����ʱ��Ч 
	td_s32 		m_s32AudioType;	//��Ƶ��������
	pthread_mutex_t	m_aencLock;			//ljj add 20121221
	td_s32		m_Reserved[4];
	td_s32		m_s32AudioSample;// huaqiang add 20130105 for AAC
	AUDIOSTREAMCBK m_cbkAStream;
}strAencParam;
#else
typedef struct
{
	td_s32 		m_s32ChnCount;		//ע��ͨ������
	td_s32 		m_s32ChnNum[16];	//ÿ��ע��ͨ����ͨ����
	td_s32 		m_s32RegEnable;     //ʹ��ʱ��ʹ�ø���ģʽ������Ǹ���ģʽ
}strChnRegister;

typedef struct
{
	td_s32 		m_s32AencChn;	//��Ƶ����ͨ���ţ��ڲ�ʹ�ã�����ʱ��Ч 
	td_s32 		m_s32AudioType;	//��Ƶ��������
	pthread_mutex_t	m_aencLock;			//ljj add 20121221
	td_s32		m_Reserved[4];
	td_s32      m_s32AudioSample;
	strChnRegister m_register;
	AUDIOSTREAMCBK m_cbkAStream;
}strAencParam;

#endif

typedef struct
{
	td_s32 		m_s32PicChn;	//ץ�ı���ͨ���ţ��ڲ�ʹ�ã�����ʱ��Ч 
	td_s32 		m_s32VideoSize;	//ͼƬ��С  ����ͨ��ץ�ĸ�16λ��ʾ�߶ȣ���16λ��ʾ���
	td_s32 		m_s32Quality;	//ͼƬ����
	td_s32		m_iVoDev;		
	td_s32		m_iVoChan;
	void * 		m_pChan;		//����ͨ����ַ
	td_u8		m_FileName[SNAP_FILE_NAME_LEN]; //ץ���ļ���
	td_s32		m_s32BuffLen;	//buffer����
	td_u8*		m_pu8Buffer;	//buffer
	pthread_mutex_t	m_vencLock;	
	td_s32		m_Reserved[4];
	SNAPSHOTCBK m_cbkSnapShot;
}strPicParam;


typedef struct  //��Ƶ������-1��ʾ�����ã�����ԭֵ
{
	td_s32 m_s32Bright;
	td_s32 m_s32Contrast;
	td_s32 m_s32Saturation;
	td_s32 m_s32Hue;
}strVideoParam;



typedef enum 
{
	VO_ENABLE = 0,
	VO_DISABLE,
	VO_PAUSE,
	VO_RESUME,
	VO_STEP,
	VO_HIDE,
	VO_SHOW,
	VO_CLEAR,
	VO_REFRESH,
	VO_BUTT,
}VO_CTRL_E;

typedef enum
{
	VO_VIDEOLEVEL = 0,
	VO_PIPLEVEL,
	VO_MULTISCREEN,//add by gyn 
	VO_LEVENBUTT,
}VO_CHN_LEVEL_E;

typedef struct
{
	td_s32	m_iType; 		//��������	0 :H264  1: JPEG
	td_s32	m_iMod; 		//��ʽ	
	td_s32  m_iHeight;		//��Ƶ�߶�	
	td_s32	m_iWidth;		//��Ƶ���
}strVdecPara;

//hq add, 20130424
#define MEDIA_INFO_TYPE_CNT 64
#define MEDIA_INFO_MAXAIDEV_CNT 8
//�洢MEDIA_INFO_AICONF�ж���ĸ�����Ϣ
typedef struct
{
	td_s32 s32MediaInfo[MEDIA_INFO_TYPE_CNT];  //����MEDIA_INFO_AICONF��Ϣ���ڴ˴��洢
}stChipMediaInfo; 

//�洢MEDIA_INFO_AICONF��Ϣ,����3531��16·����dvr, ʹ�õ���ai1��16��ͨ��
//��ôs8NormAiCnt=1, s8NormAiChnCnt=16,s8NormAiDevList[0]=1
typedef struct
{
	td_s8 s8NormAiCnt;		//��ͨai������
	td_s8 s8MicAiCnt;		//�Խ�ai������
	td_s8 s8NormAiChnCnt;	//��ͨai�豸�µ�ͨ������
	td_s8 s8MicAiChnCnt;	//�Խ�ai�豸�µ�ͨ������
	td_s8 s8NormAiDevList[MEDIA_INFO_MAXAIDEV_CNT];	//��ͨai���豸������ȡֵ,������Ϊ-1
	td_s8 s8MicAiDevList[MEDIA_INFO_MAXAIDEV_CNT];	//�Խ�ai���豸������ȡֵ,������Ϊ-1
}stMediaAiInfo; 

// оƬý�����ò������Ͷ���
typedef enum
{
	//ϵͳ
	MEDIA_INFO_DDRCTL = 0,		//ddr������������
	MEDIA_INFO_HDDEV,			//�Ƿ��Ǹ����豸0:sd; 1:hd
	//AI
	MEDIA_INFO_AICONF,			//������ͨ��Ƶ���Խ�ʹ�õ��豸�����豸ֵ
	//AO
	MEDIA_INFO_AOBASSDEV,		//Ao����豸
	MEDIA_INFO_AOHDMIDEV,		//hdmi ��Ƶ����豸
	//VI
	MEDIA_INFO_VIDEVCOEF,		//�߼�vi�豸ͬ����vi�豸ת����ϵ��
	//VO
	MEDIA_INFO_BT1120,			//�Ƿ�֧��bt1120, 0:��֧��; 1:֧��
	MEDIA_INFO_HDVOCNT, 		//HD VO�豸����
	MEDIA_INFO_MAXVOCHN,		//VO�豸ͨ������
	MEDIA_INFO_VIRVOSTART,		//����vo�豸����ʼ��
	//VENC
	MEDIA_INFO_PROFILELEV,		//����h264�ļ���
	MEDIA_INFO_IPSNAPNUM,		//JPEGץ�ı���������
	//VDEC
	MEDIA_INFO_MAXH264DECSIZE,		//������߻طŵ��������С
	MEDIA_INFO_MAXSNAPDECSIZE,		//JPEGץ�ĻطŴ�С
	MEDIA_INFO_MAXH264VDECNUM,		//vdec������������
	//M7.6�Ժ�����ֻ�����ں���׷��
	MEDIA_INFO_VIRVOINTYSYNC,		//����VO��ʱ����Ϣ
} MEDIA_INFO_TYPE;
//end

#define DECODE_MODE_FRAME 0   //֡ģʽ����
#define DECODE_MODE_STREAM 1  //��ģʽ����
#define VI_MODE_LOCAL		2

#if 1
/********************td_media.c********************************/
td_s32 tdmedia_Init(td_u8 _u8InputNorm, td_u8 _u8BncInput, td_u8 _u8IpcInput, td_u8 _u8VcInput, 
	td_s32 _uiCodePerformance,td_s32 _s32BncBits, td_s32 _s32ADChkMode);
/****************************************
	����:	��ʼ��ý���	
	����:	_s32VideoNorm: ��Ƶ������ʽ
			_s32ViNum:ʵ������vi��
			_s32MaxDecAbilty:����������
			_s32BncBits:ģ��ͨ�����ͣ���λ��ʾ��0 ����ģ��ͨ�� 1 pciͨ��
	���:

			
	�޸���־:20110301 �����봴��
			 20110302 ȥ��_s32ChnCnt
			 20110307 �޸Ľӿ�
			 20110506 ����_s32ViNum
*****************************************/

td_s32 tdmedia_InitLocalChn(td_s32 _s32Chn,td_s32 _samplerate, td_s32 _s32AencType);
/****************************************
	����:	��ʼ������ͨ�������ý�����Դ��������ͨ����create�б�����
	����:	_s32Chn:ͨ���ţ�����ͨ��Ϊbnc��
	���:
	�޸���־:20120829 hq����:��tdmedia_Init����ͨ����صĲ�����ȡ���� 
				   20130107 huaqiang �޸�: �����Ƶ���뷽ʽ����
*****************************************/

td_s32 tdmedia_InitPciChn(td_s32 _s32Chn,td_s32 _samplerate, td_s32 _s32AencType);
/****************************************
	����:	��ʼ��PCIͨ�������ý�����Դ��������ͨ����create�б�����
	����:	_s32Chn:ͨ���ţ�����ͨ��Ϊbnc��
	���:
	�޸���־:20120829 hq����:��tdmedia_Init����ͨ����صĲ�����ȡ���� 
				  20130107 huaqiang �޸�: �����Ƶ���뷽ʽ����
*****************************************/

td_s32 tdmedia_InitVcChn(td_s32 _s32Chn);
/****************************************
	����:	��ʼ��VCͨ�������ý�����Դ��������ͨ����create�б�����
	����:	_s32Chn:ͨ���ţ�vcͨ���Ŵ�VIR_CHN_1������
	���:
	�޸���־:20120829 hq����:��tdmedia_Init����ͨ����صĲ�����ȡ���� 
*****************************************/

td_s32 tdmedia_InitSdiPciChn(td_s32 _s32Chn, td_s32 _s32AudioChn, td_s32 _s32Samplerate, td_s32 _s32AencType);
/****************************************
	����:	��ʼ��SDIPCIͨ�������ý�����Դ��������ͨ����create�б�����
	����:	_s32Chn:ͨ���ţ�����ͨ��Ϊbnc�ţ�
	���:
	�޸���־:20120829 hq����:��tdmedia_Init����ͨ����صĲ�����ȡ���� 
				  20130107 huaqiang �޸�: �����Ƶ���뷽ʽ����
*****************************************/

td_s32 tdmedia_InitSdiLocalChn(td_s32 _s32Chn, td_s32 _s32AudioChn, td_s32 _s32Samplerate, td_s32 _s32AencType);
/****************************************
	����:	��ʼ��SdiLocalͨ�������ý�����Դ��������ͨ����create�б�����
	����:	_s32Chn:ͨ���ţ�����ͨ��Ϊbnc�ţ�
	���:
	�޸���־:201301 shihc create
*****************************************/


td_s32 tdmedia_CreatePool(td_s32 _iVW, td_s32 _iVH, strVbCoach * _pstPool);
td_s32 tdmedia_DestoryPool(strVbCoach * _pstr_pool);
td_s32 media_DestoryCoach(void **Coach);
void *media_initCoach(td_s32 _iW, td_s32 _iH, int *_CoachAdr, int *_DataHeader);
td_s32 media_GetFrmInfoStrucLen(void);
td_s32 media_VdecGetStreamData(td_s32 _s32ID, void *_Coach);
td_s32 media_VpssSendStreamData(td_s32 _s32Dev, td_s32 _s32Chn, void *_Coach);

#endif
#if 1
/********************td_media_pub.c********************************/
td_s32 MediaSetChipInfo(td_s32 _s32Type, void * _s32Value);
/****************************************
	����:	���ں�˼оƬ��ͬ��ʼ��ý���ͬhi3531�Ĳ��첿��
	����:	_s32Type: ĳ��ý������
	              _s32Value: ʵ��ƽ̨ʹ�õ�ֵ
	���:
	�޸���־:20130403 hq����
*****************************************/

void * MediaGetChipInfo(td_s32 _s32Type);
/****************************************
	����:	���ں�˼оƬ��ͬ,��ȡĳ�����ͬhi3531�Ĳ������
	����:	_s32Type: ĳ��ý������
	���:
	�޸���־:20130403 hq����
*****************************************/

td_s32 MediaInitChipInfo(void);
/****************************************
	����:	����hi3531�������ʼ��ý�����Դ
	����:	
	���:
	�޸���־:20130403 hq����
*****************************************/
#endif
#if 1
/********************����Ƶ����td_media_avenc.c*********************************/
td_s32 tdmedia_StartAenc(td_s32 _s32Chn, strAencParam* _pstAencParam); 
/****************************************
	����:	������Ƶ����
	����:	_s32Chn ��Ƶ����ͨ����
			_pstAencParam ��Ƶ�������
	���:


	�޸���־:20110301 �����봴��
*****************************************/


td_s32 tdmedia_StopAenc(td_s32 _s32Chn); 
/****************************************
	����:	ֹͣ��Ƶ����
	����:	_s32Chn ��Ƶ����ͨ����
	���:


	�޸���־:20110301 �����봴��
*****************************************/


td_s32 tdmedia_StartTalk(strAencParam* _pstAencParam); 
/****************************************
	����:	�����Խ�����
	����:
			_pstAencParam ��Ƶ�������
	���:


	�޸���־:20110322 �����봴��
*****************************************/


td_s32 tdmedia_StopTalk(); 
/****************************************
	����:	ֹͣ�Խ�����
	����:
	���:


	�޸���־:20110322 �����봴��
*****************************************/

void tdmedia_StartTalkStreamProc();
/****************************************
	����:	
	����:
	���:
	�޸���־:20120704  create
*****************************************/

void tdmedia_StopTalkStreamProc();
/****************************************
	����:	
	����:
	���:
	�޸���־:20120704  create
*****************************************/

td_s32 tdmedia_StartVenc(td_s32 _s32Chn, td_s32 _s32IsMainChn, strVencParam* _pstVencParam); 
/****************************************
	����:	������Ƶ����	
	����:	_s32Chn ��Ƶ����ͨ����
			_s32IsMainChn: ��������0��1��
			_pstVencParam: ��Ƶ�������
	���:


	�޸���־:20110301 �����봴��
*****************************************/


td_s32 tdmedia_StopVenc(td_s32 _s32Chn, td_s32 _s32IsMainChn); 
/****************************************
	����:	ֹͣ��Ƶ����	
	����:	_s32Chn ��Ƶ����ͨ����
			_s32IsMainChn ��������0��1��
	���:


	�޸���־:20110301 �����봴��
*****************************************/


td_s32 tdmedia_SetBitrate(td_s32 _s32Chn,td_s32 _s32IsMainChn, td_s32 _s32Bitrate); 
/***********************************************
	����:	���ñ�������
	����:	_s32Chn ͨ����
			_s32Bitrate ����
	���:
	
	�޸���־:20110301 �����봴��
************************************************/

td_s32 tdmedia_GetFramerate( td_s32 _s32Chn,td_s32* _s32Framerate, td_s32 _s32IsMainChn);
/***********************************************
	����:	��ȡ�û����õ�֡��ֵ
	����:	_s32Chn: ͨ����
			_s32Framerate : ֡��
			_s32IsMainChn : ��(0)��(1)����
	���:
	
	�޸���־:20120419 lxy create
************************************************/

td_s32 tdmedia_GetFramerateEx( td_s32 _s32Chn,td_s32* _s32Framerate, td_s32 _s32IsMainChn);
/***********************************************
	����:	�ӵײ��ȡʵ����ʹ�õ�֡��
	����:	_s32Chn: ͨ����
			_s32Framerate : ֡��
			_s32IsMainChn : ��(0)��(1)����
	���:
	
	�޸���־:20120419 lxy create
************************************************/


td_s32 tdmedia_SetFramerateEx( td_s32 _s32Chn,td_s32 _s32Framerate, td_s32 _s32IsMainChn);
/***********************************************
	����:	����֡��,�����޸�ȫ�ֱ���
	����:	_s32Chn: ͨ����
			_s32Framerate : ֡��
			_s32IsMainChn : ��(0)��(1)����
	���:
	
	�޸���־:20120424 lxy create
************************************************/


td_u32 tdmedia_GetHDMaxFrmRate(td_s32 _s32Chn, td_s32 _s32IsMainChn);
/***********************************************
	����:	�����ָ���sdi�豸ʱ�����������ͨ�������֡�ʣ�
			�˺������Ի�ȡ��ʱ֧�ֵ����֡��
	����:	_s32Chn: ͨ����
	���:
	
	�޸���־:20130228 hq create
************************************************/


td_s32 tdmedia_SetFramerate( td_s32 _s32Chn, td_s32 _s32IsMainChn, td_s32 _s32Framerate); 
/***********************************************
	����:	����֡�ʣ��޸�ȫ�ֱ���
	����:	_s32Chn: ͨ����
			_s32Framerate : ֡��
		
	���:
	
	�޸���־:20110301 �����봴��
************************************************/


td_s32 tdmedia_SetIframerate( td_s32 _s32Chn, td_s32 _s32IsMainChn, td_s32 _s32Iframerate);
/***********************************************
	����:	����I֡֡��
	����:	_s32Chn: ͨ����
			_s32Iframerate :I֡ ֡��
		
	���:
	
	�޸���־:20110301 �����봴��
************************************************/


td_s32 tdmedia_ForceIFrame(td_s32 _s32Chn, td_s32 _s32IsMainChn);
/***********************************************
	����:	ǿ��I ֡
	����:	_s32Chn ͨ����
	���:
	�޸���־:20110301 �����봴��
************************************************/


td_s32 tdmedia_SetEncodetype(td_s32 _s32Chn, td_s32 _s32IsMainChn, td_s32 _s32Type);
/***********************************************
	����:	���ñ�������
	����:	_s32Chn ͨ����
			_s32Type ��������
			0 ������
			1 ������
	���:
	�޸���־:20110301 �����봴��
************************************************/

td_s32 tdmedia_SetPciChnVencInfo(td_s32 _s32Chn, strVencParam* _pstVencParam);
/***********************************************
	����:	�����Ƭ����ͨ����Ϣ
	����:	_s32Chn ͨ����
			_pstVencParam ����ͨ������
	���:
	�޸���־:20120321 hq����,����pciͨ���ı����С����Ϣ
************************************************/


td_s32 tdmedia_SetProFile(td_s32 _s32Chn,td_s32 _s32Type, td_s32 _s32IsMainChn);
/***********************************************
	����:	����ProFile����
	����:	_s32Chn ͨ����
			_s32Type  ProFile����
			0 :BaseLine
			1:MainLine
			2:HighLine
			���:
	�޸���־:20120308 ����������
************************************************/


td_s32 tdmedia_SetVideosize(td_s32 _s32Chn, td_s32 _s32IsMainChn, td_s32  _s32Videosize); 
/***********************************************
	����:	������Ƶ��С
	����:	_s32Chn ͨ����
			_s32Videosize ��Ƶ��С

	���:
	�޸���־:20110301 �����봴��
************************************************/


td_s32 tdmedia_CapPicture(td_s32 _s32Chn, strPicParam* _pstSnapMsg);
/***********************************************
	����:ץ��ͼƬ
	����:	_s32Chn:ͨ����
			_pstSnapMsg ץ�Ľṹ��
	���:
	�޸���־:20110301 �����봴��
************************************************/


td_s32 tdmedia_GetVoPicture(strPicParam* _pstSnapMsg);
/***********************************************
	����:VO ץ��
	����:	_s32VoDev:VO�豸��
			_s32VoChn: voͨ����
			_pstSnapMsg ץ�Ľṹ��
	���:
	�޸���־:20110301 �����봴��
************************************************/


td_s32 tdmedia_SetVideoQuality(td_s32 _s32Chn, td_s32 _s32IsMainChn, td_s32  _s32Quality);
/***********************************************
	����:������Ƶ����
	����:	_s32Chn:ͨ����
			_s32Quality ��Ƶ����
			_s32IsMainChn ����������־
	���:
	�޸���־:20110309 �����봴��
************************************************/

td_s32 tdmedia_GetFrameSize(td_s32 _sample,td_s32 _AencType);

#endif
#if 1
/************************OSD td_media_osd.c*******************************************/
td_s32 tdmdia_StartOsd(td_s32 _s32Chn);
/***********************************************
	����:	�����ַ����ӣ��ڴ�������ͨ��
	             ��������Ч
	����:	_s32Chn ͨ����
			
	���:
	�޸���־:20110315�����봴��
				
************************************************/

td_s32 tdmedia_SetVideoLost(td_s32 _s32Chn, td_s32 _s32lost);
/***********************************************
	����:	����vi������ʧ����ʱ���ṩ��־λ
	����:	_s32Chn ͨ����
			_s32lost �Ƿ�ʧ
	���:
	�޸���־:shihc add 2012123
************************************************/

td_s32 tdmedia_SetText(td_s32 _s32Chn,td_u8* _pu8text);
/***********************************************
	����:	�����ַ����Ӱ�����
	����:	_s32Chn ͨ����
			_pu8text �ַ���������
			
	���:
	�޸���־:20110301 �����봴��
************************************************/


td_s32  tdmedia_SetOverlay(td_s32 _s32Chn,td_s32 _s32X,td_s32 _s32Y,td_u8* _pu8Text);
/***********************************************
	����:	�����ַ�����λ��
	����:	_s32Chn ͨ����
			_s32X: X���� (��_s32YΪ-1ʱΪ����λ��)
			_s32Y: Y���� (��λ�õ���ʱΪ-1)
			
	���:
	�޸���־:20110301 �����봴��
************************************************/

td_s32  tdmedia_SetMutiOverlay(td_s32 _s32Chn, td_s32 _s32LayNo, td_s32 _s32X, td_s32 _s32Y, td_u8* _pu8Text);
/***********************************************
	����:	�����ַ�����λ��
	����:	_s32Chn ͨ����
			_s32LayNo	������
			_s32X: X���� (��_s32YΪ-1ʱΪ����λ��)
			_s32Y: Y���� (��λ�õ���ʱΪ-1)
			
	���:
	�޸���־:2015-8-7 ��������
************************************************/

td_s32  tdmedia_SetLogo(td_s32 _s32Chn,td_s32 _s32Width,td_s32 _s32Height,td_u8* _pu8Buf);
/***********************************************
	����:	����logo����
	����: _s32Chn ͨ����
			_s32Width : logo��
			_s32Height: logo��
			_pu8Buf: logo buffer
	���:
	�޸���־:20110301 �����봴��
************************************************/


void tdmedia_SetVICoverPos(td_s32 _s32Chn, TRect* _pstRegion, td_s32 _s32Num, td_s32 _s32VencSize);
/***********************************************
	����:	
	����: _s32Chn ͨ����
			_pstRegion : �ڵ�����λ����Ϣ
			_s32Num: : �ڵ�������
			_s32VencSize :_pstRegion��ʱ��Ӧ��venc�Ĵ�С		
	���:
	�޸���־:20121008 hq create
************************************************/

void *tdmedia_GetVINamePos(td_s32 _s32Chn);
/***********************************************
	����:	
	����: _s32Chn ͨ����
	���:
	�޸���־:20121008 hq create
************************************************/

td_s32 tdmedia_SetTextLocalVencChn(td_s32 _s32Chn, td_u8* _pu8text);
/***********************************************
	����:	�趨�����ַ�
	����:	_s32Chn ͨ����
			_pu8text: ��������ָ��
			
	���:
	�޸���־:201302 create
************************************************/

td_s32 tdmedia_SetTextPos(td_s32 _s32Chn,td_s32 _s32X, td_s32 _s32Y);
td_s32  tdmedia_SetTextPosLocalVencChn(td_s32 _s32Chn, td_s32 _s32X, td_s32 _s32Y);
/***********************************************
	����:	�����ַ�����λ��
	����:	_s32Chn ͨ����
			_s32X: X���� (��_s32YΪ-1ʱΪ����λ��)
			_s32Y: Y���� (��λ�õ���ʱΪ-1)
			
	���:
	�޸���־:20110301 �����봴��
************************************************/


td_s32 tdmedia_SetTimePos(td_s32 _s32Chn,td_s32 _s32X, td_s32 _s32Y);
/***********************************************
	����:	����ʱ�����λ��
	����:	_s32Chn ͨ����
			_s32X: X���� (��_s32YΪ-1ʱΪ����λ��)
			_s32Y: Y���� (��λ�õ���ʱΪ-1)
			
	���:
	�޸���־:20110301 �����봴��
************************************************/


td_s32  tdmedia_ShowLogo(td_s32 _s32Chn,td_s32 _s32X,td_s32 _s32Y,td_s32 _s32Show);
/***********************************************
	����:	��ʾ/����logo
	����: _s32Chn ͨ����
			_s32X : X����
			_s32Y: Y����
			_s32Show: 1 ��ʾlogo
					   0 ����logo
	���:
	�޸���־:20110301 �����봴��
************************************************/


td_s32  tdmedia_ShowText(td_s32 _s32Chn,td_s32 _s32Show);
td_s32  tdmedia_ShowTextLocalVencChn(td_s32 _s32Chn,td_s32 _s32Show);
/***********************************************
	����:	��ʾ/�����ַ�����
	����: _s32Chn ͨ����
			_s32Show 1  ��ʾ�ַ�
			               0 �����ַ�
	���:
	�޸���־:20110301 �����봴��
************************************************/


td_s32  tdmedia_ShowTime(td_s32 _s32Chn,td_s32 _s32Show);
/***********************************************
	����:	��ʾ/����ʱ�����
	����: _s32Chn ͨ����
			_s32Show 1  ��ʾ�ַ�
			               0 �����ַ�
	���:
	�޸���־:20110301 �����봴��
************************************************/


td_s32 tdmedia_SetColor(td_s32 _s32Chn, td_s32 _s32Color, td_s32 _s32Type);
/***********************************************
	����:	�����ַ�������ɫ
	����: _s32Chn ͨ����
		  _s32Color �ַ���ɫ
		  _s32Type ��������:
					0 �ַ�����
					1 ʱ�����
					2 �����ַ�����
	���:
	�޸���־:20110301 �����봴��
************************************************/

td_s32 tdmedia_SetFontSize(td_s32 _s32Chn, td_s32 _s32FontSize, td_s32 _s32Type);
/***********************************************
	����:	�����ַ�������ɫ
	����: _s32Chn ͨ����
		  _s32FontSize �ַ��ֺ�
		  _s32Type ��������:
					0 �ַ�����
					1 ʱ�����
					2 �����ַ�����
	���:
	�޸���־:2015-08-19 zhangchao
************************************************/


td_s32 tdmedia_SetOverLayColor(td_s32 _s32Chn, td_s32 _s32LayNo, td_s32 _s32Color);
/***********************************************
	����:	�����ַ�������ɫ
	����: _s32Chn ͨ����
		  _s32LayNo	������
		  _s32Color �ַ���ɫ
	���:
	�޸���־:2015-8-7 ��������
************************************************/
td_s32 tdmedia_SetOverLayFontSize(td_s32 _s32Chn, td_s32 _s32LayNo, td_s32 _s32FontSize);
/***********************************************
	����:	�����ַ������ֺ�
	����: _s32Chn ͨ����
		  _s32LayNo	������
		  _s32FontSize �ַ��ֺ�
	���:
	�޸���־:2015-08-19 zhangchao
************************************************/

td_s32	tdmedia_SetTimeMode(td_s32 _s32Mode,td_u8* _pu8SplitChar);
/***********************************************
	����:	����ʱ����Ӹ�ʽ
	����:	_s32Mode ʱ��ģʽ
	                           0 : yyyy/mm/dd
	                           1 : mm/dd/yyyy
	                           2 : dd/mm/yyyy
	                           3 : M day yyyy
	                           4 : day M yyyy
			_pu8SplitChar: �ָ���
			
	���:
	�޸���־:20110301 �����봴��
****************************************************/

td_s32 tdmdia_DestoryTimeOsd(td_s32 _s32Chn);
/***********************************************
	����:	OSDʱ�临λ
	����: _s32Chn ͨ����
	���:
	�޸���־:shihc mod 20111227
			liuqi 2014-11-14 �޸ĺ�����,tdmdia_osd_DestoryAllRegion-->tdmdia_DestoryTimeOsd
************************************************/

td_s32 tdmedia_ResetTimeOsd(td_s32 _s32Chn);
/***********************************************
	����:	OSDʱ�临λ
	����: _s32Chn ͨ����
	���:
	�޸���־:20110301 �����봴��
************************************************/

td_s32	tdmedia_SetVideoCover(td_s32 _s32Chn,TRect* _pstRegion,td_s32 _s32Num);
/***********************************************
	����:	��ʾ/����ʱ�����
	����: _s32Chn ͨ����
			_pstRegion : �ڵ�����,ΪNULLʱΪȡ����Ƶ�ڵ�
			_s32Num: : �ڵ�������
	���:
	�޸���־:20110301 �����봴��
************************************************/


td_s32 tdmedia_SetVideoCoverEx(td_s32 _s32Chn,TRect* _pstRegion,td_s32 _s32Num, td_s32 _s32VideoSize);
/***********************************************
	����:	��ʾ/����ʱ�����
	����: _s32Chn ͨ����
		  _pstRegion : �ڵ�����,ΪNULLʱΪȡ����Ƶ�ڵ�
		  _s32Num: : �ڵ�������
	���:
	�޸���־:20110301 �����봴��
************************************************/

td_s32 tdmedia_SetVideoCoverPos(td_s32 _s32Chn, td_s32 _s32IsMainChn, td_s32 _s32NewVencSize);
/***********************************************
	����:	�л�����ֱ���ʱ������Ƶ�ڵ���λ�úʹ�С��Ϣ
	����: _s32Chn ͨ����
		  _s32IsMainChn : ��������
		  _s32NewVencSize: �µı����С
	���:
	�޸���־:20120908 hq create
************************************************/
#endif
#if 1
/************************�ƶ����td_media_md.c****************************************/
td_s32 tdmedia_StartMD(td_s32 _s32Chn);
/***********************************************
	����:	�����ƶ���⣬�ڴ�������ͨ��
	             ��������Ч
	����:	_s32Chn ͨ����
			
	���:
	�޸���־:20110315�����봴��
				
************************************************/


td_s32 tdmedia_SetMDArea(td_s32 _s32Chn,td_s32  _s32Area[]);
/***********************************************
	����:	�����ƶ���ⱨ������
	����: _s32Chn ͨ����
			_s32Color �ַ���ɫ
			_s32Area �ƶ���ⱨ������
	���:
	�޸���־:20110301 �����봴��
************************************************/


td_s32 tdmedia_SetMDSen(td_s32 _s32Chn,td_s32 _s32Sen);
/***********************************************
	����:	�����ƶ���ⱨ��������
	����: _s32Chn ͨ����
			_s32Color �ַ���ɫ
			_s32Area �ƶ���ⱨ������
	���:
	�޸���־:20110301 �����봴��
************************************************/


td_s32 tdmedia_GetMD(td_s32 _s32Chn);
/***********************************************
	����:��ȡ�ƶ���ⱨ��״̬
	����:	_s32Chn:ͨ����
	����ֵ: 1: �б���
			     0: �ޱ���
	���:
	�޸���־:20110301 �����봴��
************************************************/
#endif
#if 1
/************************��Ƶ�ڵ�td_media_od.c****************************************/
td_s32 tdmedia_GetOD(td_s32 _s32Chn);//��ȡĳͨ�����ƶ�����״̬

td_s32 tdmedia_SetOdEn(td_s32 _s32Chn, td_s32  _s32En);
/***********************************************
	����:	ʹ����Ƶ�ڵ�����
	����: _s32Chn ͨ����
			_s32En ʹ��
	���:
	�޸���־:20130313
************************************************/
#endif
#if 1
/****************************��Ƶ�������td_media_vio.c********************************/
td_s32 InitAD(td_s32 _s32ViNorm);
/***********************************************
	����:	��ʼ��ADоƬ
	����:	_s32ViNorm ��Ƶ��ʽ

	���:
	�޸���־:20111221 wsl
************************************************/

td_s32 tdmedia_ChangeColortogray(td_s32 _s32Chn, td_s32 _s32ColorToGray);
/***********************************************
	����:	��ת��
	����: 	_s32Chn ͨ����
			_s32ColorToGray 0 ȡ����ת��
						    1 ���ò�ת��

	���:
	�޸���־:20110301 �����봴��
************************************************/


td_s32 tdmedia_ChangeVideopara(td_s32 _s32Chn, strVideoParam* _pstVideoParam);
/***********************************************
	����:	������Ƶ����
	����: _s32Chn ͨ����
			_pstVideoParam  ��Ƶ�����ṹ��

	���:
	�޸���־:20110301 �����봴��
************************************************/


td_s32 tdmedia_EnableUserPic(td_s32 _s32Chn, td_s32 _s32Enable);
/***********************************************
	����:	ʹ��/ȡ��novido ͼƬ
	����: _s32Chn ͨ����
			_s32Enable  1 ʹ��
					    0 ȡ��

	���:
	�޸���־:20110301 �����봴��
************************************************/
  
td_s32 tdmedia_GetVirVODiff(void);
/***********************************************
  ����: ��ȡ����vo�ֱ���
  ����:
  ���:
  �޸���־:created by hq(2175)
  ************************************************/

td_s32 tdmedia_GetSupportVencSize(td_s32 _s32Chn);
/***********************************************
  ����: ��ȡ���ظ���ͨ����ǰ֧�ֵ��������С
  ����:
  ���:
  �޸���־:20120305 created by hq(2175)
  ************************************************/

td_s32 tdmedia_CheckHD_ViFormat(td_s32 _s32chn);
/***********************************************
  ����: �Զ��������������vi����Ƶ��С
  ����:
  ���:
  �޸���־:created by shihc 20121223
  ************************************************/

td_s32 tdmedia_CopyVpssFrame(td_s32 _iFromDev, td_s32 _iFromChan, td_s32 _iToDev, td_s32 _iToChan);
/***********************************************
	����:���ӷŴ󣬽���ͨ����Ӧ��vpss����ͼƬ�����ӷŴ�vpss
	����:	_iFromDev: ����ͼ����ʾ���ڵ�vo�豸
			_iFromChan:  ����ͼ����ʾ���ڵ�voͨ��
			_iToDev: Ҫ��������vo��ʾ�豸
			_iToChan: Ҫ��������vo��ʾͨ��
	�޸���־:20130205 hq create
            20130301 hq modified
************************************************/


td_s32 tdmedia_SendVoUserPic(td_s32 _VoDev, td_s32 _VoChn);
/***********************************************
	����:	��VOͨ����novido ͼƬ
	����: _VoDev VO�豸��
			_VoChn  VOͨ����

	���:
	�޸���־:20110301 �����봴��
************************************************/


td_s32 tdmedia_Start_WBC(td_s32 _s32VoNorm, td_s32 _s32BindVoDev);
/*********************************
	����:����ͬԴ��ʾ
	����:_s32VoDev�̶�Ϊ1
*********************************/


td_s32 tdmedia_StartVideoPreview(td_s32 _s32Chn,  td_s32 _s32VoDev, td_s32 _s32VoChn);
/***********************************************
	����: ��ʼ��ƵԤ��
	����:	_s32VoDev vo�豸��
			_s32Chn viͨ����
			_s32VoChn  voͨ����
	���:
	�޸���־:20110301 �����봴��
************************************************/

td_s32 tdmedia_StartCascadePreview(td_s32 _s32VoDev, td_s32 _s32VoChn);
/***********************************************
	����: sdi dvr��ʼ��ƵԤ��,����Ԥ��ʵ��
	����:	_s32VoDev vo�豸��
			_s32VoChn  voͨ����
	���:
	�޸���־:20120601
************************************************/

td_s32 tdmedia_StopVideoPreview(td_s32 _s32Chn, td_s32 _s32VoDev, td_s32 _s32VoChn);
/***********************************************
	����: ֹͣ��ƵԤ��
	����: _s32VoDev vo�豸��
	      _s32Chn viͨ����
	      _s32VoChn  voͨ����
	���:
	�޸���־:20110301 �����봴��
************************************************/

td_s32 tdmedia_StopCascadePreview(td_s32 _s32VoDev, td_s32 _s32VoChn);
/***********************************************
	����:sdi dvr ֹͣ��ƵԤ��,����Ԥ��
	����: _s32VoDev vo�豸��
	      _s32VoChn  voͨ����
	���:
	�޸���־:20120601
************************************************/

td_s32 tdmedia_StartAudioPreview(td_s32 _s32Chn,td_s32 _s32AoBindChn);
/***********************************************
	����: ��ʼ��ƵԤ��
	����: _s32Chn ͨ����
			_s32AoBindChn :�󶨵�AOͨ����
	���:
	�޸���־:20110301 �����봴��
************************************************/


td_s32 tdmedia_StopAudioPreview(td_s32 _s32Chn,td_s32 _s32AoBindChn);

/***********************************************
	����: ֹͣ��ƵԤ��
	����: _s32Chn ͨ����
	���:
	�޸���־:20110301 �����봴��
************************************************/

td_s32 tdmedia_GetViNorm();
//shihc add 20121120 ������Ƭ����pcivͨ�������Ұ�
td_s32 tdmedia_BindPciv(td_s32 _s32LocPcivChn);
td_s32 tdmedia_UnbindPciv(td_s32 _s32PcivChn);
td_s32 tdmedia_BindPcivChn(td_s32 _s32VoDev, td_s32 _s32VoChn, td_s32 _s32PcivChn);
td_s32 tdmedia_UnbindPcivChn(td_s32 _s32VoDev, td_s32 _s32VoChn);

td_s32 tdmedia_GetVideoLost(td_s32 _s32Chn);
/***********************************************
	����:��ȡ��Ƶ��ʧ����״̬
	����:	_s32Chn:ͨ����
	����ֵ: 1: �б���
		0: �ޱ���
	���:
	�޸���־:20110301 �����봴��
************************************************/

td_s32 tdmedia_ReConfigVIChn(td_s32 _s32Chn, td_s32 _s32Size);
/***********************************************
	����:D1&960H����DVRͳһ����Ҫ���ݱ���ֱ��ʸ���vi�ĳߴ�
	����:	_s32Chn: vi ͨ��
		_s32Size:����ֱ���
	���:
	�޸���־:20120906 add
************************************************/

td_s32 GetViSize(td_s32 _s32Chn, td_s32* _Width,td_s32* _Height);

td_s32 tdmedia_ChangeVI(td_s32 _s32Chn, td_s32 _s32ViType);
/****************************************
	����:	�ı�vi�ֱ���
	����:	_s32Chn	vi ͨ��
			_s32ViType vi�ֱ���
	���:
	�޸���־:20110301 �����봴��
	         20111212 ���Ǳ����ӿڣ�ɾ��ʵ��
*****************************************/

td_s32 ChangeHdmiDevice(td_s32 _s32DevType);
td_s32 GetHdmiCapability(td_s32 *_s32DevType);
void SetHdmiPixelRange(td_s32 _s32ChipModel);
td_s32 tdmedia_VoInit(td_s32 _s32VoDev, td_s32 _s32Diff, td_s32 _s32VoDevIntftype, td_s32 _s32WbcBindVoDev);
td_s32 tdmedia_HdmiInit(td_s32 _iHdmi0_Size);
td_s32 StopHdmiDevice();
td_s32 tdmedia_HdmiReInit(td_s32 _iHdmi0_Size);
void DetectHdmiDevice();

td_s32 tdmedia_VoDevSize(td_s32  _s32VoDev,  td_s32 _s32Diff, td_s32 _s32VoDevIntfType, td_s32 _s32WbcBindVoDev);
/****************************************
	����:	������Ƶ����ֱ���
	����:	_s32VoDev	vo�豸��
			_s32Diff		vo�ֱ���
	���:
	�޸���־:20110301 �����봴��
			 20111212 �����޸ĺ�����
*****************************************/


//td_s32 tdmedia_SetVoCnt(td_s32  _s32VoDev,  td_s32 _s32Cnt);
/****************************************
	����:	������Ƶ���������
	����:	_s32VoDev	vo�豸��
			_s32Diff		vo�ֱ���
	���:
	�޸���־:20110301 �����봴��
			 20111212 ����ɾ��
*****************************************/


td_s32 media_DisableVo( td_s32 _s32VoDev);
/************************************************************
	����: ��ֹ����voͨ����ͬ���顢��Ƶ�㡣
	�ı�vo�ֱ���ǰ����
	����:	
				_s32VoDev VO�豸��
	���:
	�޸���־:20110301 �����봴��
*************************************************************/

td_s32 tdmedia_SetVoChnRect(td_s32 _s32VoDev, td_s32 _s32VoChn, TRect* _ptRect); 
/****************************************
	����:	����vo��ʾ����
	����:	_s32VoDev	vo�豸��
			_s32VoChn	voͨ����
			_ptRect		��ʾ����
	���:
	�޸���־:20110301 �����봴��
*****************************************/

td_s32 tdmedia_EnablePipLevel(td_s32 _s32VoDev, td_s32 _s32Diff);
/****************************************
	����:	ʹ��PIP�㣬����PIP��VO�豸
	����:	_s32VoDev	vo�豸��

	���:
	�޸���־:20120209 ���Ǵ���
*****************************************/

td_s32 tdmedia_DisablePipLevel(td_s32 _s32VoDev);
/****************************************
	����:	��ֹPIP�㣬����PIP���VO�豸
	����:	_s32VoDev	vo�豸��

	���:
	�޸���־:20120209 ���Ǵ���
*****************************************/

td_s32 tdmedia_SetPipChnAttr(td_s32 _s32VoDev, td_s32 _s32VoChn, TRect* _stVO);
/******************************************
	����:	����PIP��ͨ������

	�޸���־:20130321 ���Ǵ���
*******************************************/


td_s32 tdmedia_SetVoChnPri(td_s32 _s32VoDev, td_s32 _s32VoChn, td_s32  _s32Pri);
/****************************************
	����:	����vo��ʾ���ȼ�
	����:	_s32VoDev	vo�豸��
			_s32VoChn	voͨ����
			_s32Pri		���ȼ�
	���:
	�޸���־:20110301 �����봴��
*****************************************/

td_s32 tdmedia_GetVoChnPri(td_s32 _s32VoDev, td_s32 _s32VoChn);
/****************************************
	����:	��ȡvo��ʾ���ȼ�
	����:	_s32VoDev	vo�豸��
			_s32VoChn	voͨ����
	����: ���ȼ�
	�޸���־:20120607 hq create
*****************************************/


td_s32 tdmedia_SetVoChnCtrl(td_s32  _s32VoDev, td_s32 _s32VoChn, VO_CTRL_E _eCtrl);
/****************************************
	����:	voͨ����ʾ����
	����:	_s32VoDev	vo�豸��
			_s32VoChn	voͨ����
			_eCtrl		��ʾ������
						0 ʹ��
						1 ��ֹ
						2 ��ͣ
						3 �ָ�
						4 ����
						5 ����
						6 ��ʾ
						7 ���
	���:
	�޸���־:20110301 �����봴��
*****************************************/

//td_s32 media_ResumeVo(const td_s32 _s32VoDev, const td_s32 _s32VoChn, TRect* _ptRect);
td_s32 media_ViStartClipSide(const td_s32 _s32ViChan,TRect* _ptRect);
TRect *media_GetViEZoomClipSide(const td_s32 _s32ViChn, TRect* _ptRect);
TRect *media_SetViEZoomClipSide(const td_s32 _s32VoDev, const td_s32 _s32VoChn,TRect* _ptRect);
td_s32 media_ViStopClipSide(const td_s32 _s32ViChn);

td_s32 tdmedia_SetVoImgRect(td_s32 _s32VoDev, TRect* _pstRect);
/****************************************
	����:����image���С
	����:	_s32VoDev vo�豸��
			pstRect: image���С
	���: 
	�޸���־:20110311 �����봴��
*****************************************/

td_s32 tdmedia_SetVoFrameRate(td_s32  _s32VoDev, td_s32 _s32VoChn, td_s32 _s32FrameRate);
/****************************************
	����:	����vo��ʾ֡��
	����:	_s32VoDev	vo�豸��
			_s32VoChn	  voͨ����
			_s32FrameRate	��ʾ֡��
	���:
	�޸���־:20110301 �����봴��
*****************************************/

td_s32 tdmedia_SetVoChnField(td_s32 _s32VoDev, td_s32 _s32VoChn, td_s32 _s32Field);
td_s32 tdmeida_SetSampleRate(td_s32 _s32AFunc, td_s32 _s32ADev, td_s32 _samRate);
td_s32 media_StopAi(td_s32 _s32AiDevId );
td_s32 media_StopHDAi(void);



td_s32 media_GetEzoomChn(td_s32 _iType);
/********************************************************************
	����:	��ȡ���ӷŴ�ͨ����
	����:	_iType 0:����	_iType 1:����
********************************************************************/

td_s32 media_EnterEzoom(td_s32 _s32VoDev, td_s32 _s32VoChan);
/********************************************************************
	����:	��ʼ���ӷŴ���
	�޸���־:20120209 ���Ǵ���
*********************************************************************/

td_s32 media_EnterCascadeEzoom(td_s32 _s32VoDev, td_s32 _s32VoChan);
/********************************************************************
	����:	sdi dvr��ʼ���ӷŴ���,�������ӷŴ�
	�޸���־:20120601
*********************************************************************/

td_s32 media_ExitEzoom(td_s32 _s32VoDev, td_s32 _s32VoChan);
/********************************************************************
	����:	�������ӷŴ���
	�޸���־:20120209 ���Ǵ���
*********************************************************************/

td_s32 media_ExitCascadeEzoom(td_s32 _s32VoDev, td_s32 _s32VoChan);
/********************************************************************
	����:	sdi dvr�������ӷŴ���,�������ӷŴ�
	�޸���־:20120601
*********************************************************************/

td_s32 media_SetEzoom(td_s32 _s32VoDev,  td_s32 _s32VoChan, TRect* _pstZoomAttr);
/********************************************************************
	����:	�������ӷŴ�����
	����:	
			_s32VoDev    		vo�豸��							
			_pstZoomRect		���ӷŴ�����
	���:
	�޸���־:20110301 �����봴��
*********************************************************************/

td_s32 media_SetVoClipArea(td_s32 _s32VoDev,  td_s32 _s32VoChan, TRect* _pstZoomAttr);
/**********************************************************************
	����:	������Ƶ�����ü�
	����:	
		  _s32VoDev   	vo�豸��
		  _s32Chn	ͨ����
				Ԥ�����ӷŴ�ʱΪviͨ����
				�طŵ��ӷŴ�ʱΪvdecͨ����
							
		  _pstZoomRect	���ӷŴ�����
	�޸���־:20111213 ���Ǵ���
**********************************************************************/

td_s32 media_StartMicAi(td_s32 s32PtNumPerFrm);
/********************************************************************

*********************************************************************/

td_s32 media_StartNormAiChn(td_s32 _s32Chn,td_s32 _s32AudioSample, td_s32 _s32AencType);
/********************************************************************
����:��Ƶ�豸ͨ����ʼ��
�޸���־:ljj ���ϱ���͸�����Ƶ�豸�ĳ�ʼ��
*********************************************************************/
td_s32 media_GetNormAiInfo(td_s32 _s32Chn, td_s32 *_s32AiDev, td_s32 *_s32AiChn);
/********************************************************************
����:��ȡ��Ƶ�豸����ز���
�޸���־:ljj ���
*********************************************************************/

td_s32 media_StartAo(td_s32 _s32AoDev, td_s32 _s32AoCnt,td_s32 _sample);
/********************************************************************
	����:	������Ƶ����豸
	����:	
			//_pstVoParam	VO�豸����
			_s32AoCnt : ��Ƶ�������
	���:
	�޸���־:20110301 �����봴��
				   20110301 �������޸Ĳ���
	
*********************************************************************/


td_s32 media_SetAoChnCnt(td_s32 _s32AoChnCnt);
/********************************************************************
	����:����aoͨ������
	����:	
			_s32AoChnCnt : ao ͨ������
	���:
	�޸���־:
				   
	
*********************************************************************/



td_s32 media_StopAo(td_s32 _s32AoDev);
/********************************************************************
	����:	ֹͣ��Ƶ����豸
	����:	
			//_pstVoParam VO�豸����
	���:
	�޸���־:20110301 �����봴��
				    20110301 �������޸Ĳ���
*********************************************************************/

td_s32 media_StopAoChn(td_s32 _s32AoDev, td_s32 _s32AoChn);
/********************************************************************
	����:	ֹͣ��Ƶ����豸ͨ��
	����:	
	���:
	�޸���־:2015-1-10 ��������
*********************************************************************/

td_s32 media_ClearAo(td_s32 _s32AoDev, td_s32 _s32AoBindChn);
/********************************************************************
	����:	���AO�л��������
	����:	
	���:
	�޸���־:20110301 �����봴��
*********************************************************************/


//Sherry add 20130111 ��ȡ2964������״̬
td_s32 tdmedia_GetAddevState(void);
//����Norm AI�豸����
td_s32 tdmedia_Change_NormAiDevAttr(td_s32 _iChn,strAencParam* _pstAencParam);
td_s32 tdmedia_Change_SVCAiDevAttr(td_s32 _iChn,strAencParam* _pstAencParam);

td_s32 tdmedia_SetRealBnc(td_s32 _s32RealBncNum);
td_s32 tdmedia_Change_AoDevAttr(td_s32 _s32AoDev,td_s32 _s32SampleRate,td_s32 _s32PtNumPerFrm);
td_s32 tdmedia_GetNormAiSampleRate();

#endif
#if 1
/******************����Ƶ����td_media_avdec.c************************************/
td_s32 media_CreateVdec(strVdecPara* _pstVdecParam, td_s32 _iType, td_s32 _s32LogChn);
/********************************************************************
	����:	������Ƶ����ͨ��
	����:	
			_pstVoParam �������
			_iType  	0:common vdec; 1:vca vdec
	���: ����ͨ��ID
	�޸���־:20110301 �����봴��
*********************************************************************/


td_s32 media_DestoryVdec(td_s32 _s32ID, td_s32 _iType);
/********************************************************************
	����:	������Ƶ����ͨ��
	����:	
			_s32ID ��Ƶ����ͨ��ID
			_iType		0:common vdec; 1:vca vdec
	���: 
	�޸���־:20110301 �����봴��
*********************************************************************/

td_s32 media_SetLogChnToVdecChn(td_s32 _s32LogChn, td_s32 _VdecChn);
td_s32 media_GetLogChnToVdecChn(td_s32 _s32LogChn);

td_s32 media_QueryVdec(td_s32 _s32ID);
/****************************************
	����:	��ѯ����ͨ��״̬����������������ͨ��������ʱ����
	����:	_s32ID	����ͨ��ID
	���: 
	�޸���־:20110301 �����봴��
*****************************************/


td_s32 media_VdecBindOutput(td_s32 _s32ID, td_s32 _s32VoDev, td_s32 _s32VoChn);
/****************************************
	����:	��Vdec��Vo�豸��ĳһͨ��
	����:	_s32ID		����ͨ��ID(����ͨ���Ƕ�̬������)
			_s32VoDev	�󶨵�Vo�豸��
			_s32VoChn	�󶨵�Voͨ����
	���: 
	�޸���־:20110301 �����봴��
*****************************************/


td_s32 media_VdecUnBindOutput(td_s32 _s32ID, td_s32 _s32VoDev, td_s32 _s32VoChn);
/****************************************
	����:	���Vdec
	����:	_s32ID		����ͨ��ID
			_s32VoDev	��󶨵�Vo�豸��
			_s32VoChn	��󶨵�Voͨ����
	���: 
	�޸���־:20110301 �����봴��	
*****************************************/


td_s32 media_VdecSendStream(td_s32 _s32ID, td_u8* _pstStream, td_s32 _s32StreamLen, td_u32 _u32Pts, td_u32 _s32BlockFlag);
/****************************************
	����:	����Ƶ����ͨ����������
	����:	_s32ID		Vdec ͨ����
			_pstStream	������������ָ��
			_s32StreamLen ����
			_s32BlockFlag	����/��������־
	���: 
	�޸���־:20110301 �����봴��
	 			   20110317���ӳ��ȱ���
*****************************************/


td_s32 media_VdecStartRecvStream(td_s32 _s32ID);
/****************************************
	����:����ͨ����ʼ��������
	����:	_s32ID		Vdec ͨ����

	���: 
	�޸���־:20110314 �����봴��	
*****************************************/


td_s32 media_VdecStopRecvStream(td_s32 _s32ID);
/****************************************
	����:����ͨ��ֹͣ��������
	����:	_s32ID		Vdec ͨ����

	���: 
	�޸���־:20110314 �����봴��	
*****************************************/


td_s32 media_CreateAdec(td_s32 _s32Type);
/****************************************
	����:	������Ƶ����ͨ��
	����:	_pstAdecParam	��Ƶ�������
	���: ��Ƶ����ͨ��ID
	�޸���־:20110301 �����봴��	
	
*****************************************/


td_s32 media_DestoryAdec(td_s32 _s32ID);
/****************************************
	����:	������Ƶ����ͨ��
	����:	_s32ID	����ͨ��ID
	���:
	�޸���־:20110301 �����봴��	
	
*****************************************/


td_s32 media_AdecSendStream(td_s32 _s32ID, td_u8* _pstStream, td_s32 _s32StreamLen, td_u32 _s32BlockFlag);
/****************************************
	����:	����Ƶ����ͨ����������
	����:	_s32ID		Adec ͨ����
			_pstStream	������������ָ��
			_s32StreamLen ����
			_s32BlockFlag	����/��������־
	���: 
	�޸���־:20110301 �����봴��
				   20110317���ӳ��ȱ���
*****************************************/


td_s32 media_AdecBindAo(td_s32 _s32AoDev, td_s32 _s32AdecID,td_s32 _s32AoBindChn);
/****************************************
	����:	����Ƶ��������
	����:	_s32AoDev		��Ƶ����豸��
			_s32AoChn		��Ƶ���ͨ����
			_s32AdecID		��Ƶ����ͨ��ID
	���: 
	�޸���־:20110301 �����봴��	
*****************************************/


td_s32 media_AdecUnBindAo(td_s32 _s32AoDev, td_s32 _s32AdChn,td_s32 _s32AoBindChn);
/****************************************
	����:	��ADEC��AO���
	����:	_s32AoDev		��Ƶ����豸��
			_s32AoChn		��Ƶ���ͨ����
			_s32AdChn		��Ƶ����ͨ����
	���: 
	�޸���־:20110301 �����봴��
*****************************************/


td_s32 media_AdecClear(td_s32 _s32AdecID);
/****************************************
	����: �����Ƶ����ͨ��
	����:	_s32AdecID		��Ƶ����ͨ��
	���: 
	�޸���־:20110311 �����봴��
*****************************************/

td_s32 media_VdecClearStreamData(td_s32 _s32ID);
/****************************************
        �޸���־:20120131
*****************************************/

td_s32 media_VdecReset(td_s32 _s32ID);
td_s32 media_VdecStartClipSide(const td_s32  _s32VdecChn, TRect* _ptRect);
td_s32 media_VdecStopClipSide(const td_s32  _s32VdecChn);
TRect *media_GetVdecEZoomClipSide(const td_s32 _s32VoDev, const td_s32 _s32VoChn, const td_s32 _s32ViChn, TRect* _ptRect);
TRect *media_SetVdecEZoomClipSide(const td_s32 _s32VoDev, const td_s32 _s32VoChn,TRect* _ptRect);
td_s32 media_SetLogChnClipRect(td_s32 _s32LogChn, TRect *_ptRect);
TRect *media_GetLogChnClipRect(td_s32 _s32LogChn);
td_s32 media_SetLogChnClipStat(td_s32 _s32LogChn, td_s32 _s32tClipStat);
td_s32 media_GetLogChnClipStat(td_s32 _s32LogChn);
//��ʱʹ�ã���д��������������Ӧ��ɾ��
td_s32 tdmedia_InitMicDev();

// *************************VDEC&VPSS Bind/UnBind****************************
int tmcm_VdecBindVpss(int _s32DecChn);
int tmcm_VdecUnBindVpss(int _s32DecChn);

td_s32 media_TalkingAiAoStream(td_s32 _BindFlag);

//td_s32 media_getAoChnBuf(td_s32 _s32AoDev,td_s32 _s32AoChn);

td_s32 media_VdecBind(td_s32 _s32DecChn);
td_s32 media_VdecUnBind(td_s32 _s32DecChn);

//td_s32 tdmedia_VideoOpt(VIDEO_FRAME_INFO_S * _pstFrmSrcInfo, TSize * _pstSize, strVbCoach * _pstFrmDstInfo);//cwm_todo

td_s32 tdmedia_SetVoCSC(td_s32 _s32VoDev, TVoCSCMsg *_pVoOutCsc);

td_s32 media_getAoChnBufStat(td_s32 _s32AoDev, td_s32 _s32AoChn, td_s32 _s32ClearNum);

#endif

#endif


//*****************************************
// ����ͨ���ṹ��ӿڶ���
//
// ά����¼:
// ������,2011/02/24,����
//******************************************

#ifndef _CHANNEL_H_
#define _CHANNEL_H_

#include "td_types.h"
#include "libdatacenter.h"
#include "alarmer.h"
#include "ringbuf.h"
#include "vca.h"
#define PLAYBACK_CHN	10000

typedef struct _TChannel
{
	td_s32 m_iChn;					//�߼�ͨ����
	td_s32 m_iType;					//ͨ������(����)
	
	td_s32 m_iVideoSize[2];			//��Ƶ�ߴ�
	td_s32 m_iVideNorm[2];			//��Ƶ��ʽ
	td_s32 m_iVencType[2];			//���뷽ʽ

	TDataCenter *m_ptStreanDc[2];	//���������

	TAlarmer *m_ptMdAlarmer;		//�ƶ���ⱨ��
	TAlarmer *m_ptVideoLostAlarmer;	//��Ƶ��ʧ����
	//TAlarmer *m_ptOdAlarmer;		//��Ƶ�ڵ�����		//zhangyi del 20130411

	// ע�⣬Ϊ��֤�����ԣ��˽ṹ�岻�����ٱ�����
	//add by caizhaoxu for vca 20120321
	TAlarmer * m_ptTripWireAlarmer[MAX_RULE_NUM];  // ���߱���    
	TAlarmer * m_ptPeriMeterAlarmer[MAX_RULE_NUM]; //�ܽ籨��
	TAlarmer * m_ptDiagnoseAlarmer[MAX_RULE_NUM];  //��Ƶ��ϱ���
	TAlarmer * m_ptOSCerAlarmer[MAX_RULE_NUM];     // ��Ʒ����

	TAlarmer *m_ptAudioLostAlarmer;//��Ƶ��ʧ���add by zhuangzhibing 20120222

	//��������/��ȡ�ӿ�
	td_s32 (*SetAttribute)(td_s32 _iAid, const void *_pValue, struct _TChannel *_ptThis);
	td_s32 (*GetAttribute)(td_s32 _iAid, void *_pValue, struct _TChannel *_ptThis);
	// ��������ӿ�
	td_s32 (*DoCmd)(td_s32 _iCid, void *_pArg, struct _TChannel *_ptThis);
	// ����Ӳ����������
	td_s32 (*PerformanceCost)(td_s32 _iPid, struct _TChannel *_ptThis);
	// ��Ϣ����ص�
	td_s32 (*MsgNotifyCallback)(td_s32 _iMid, td_s32 _iSubId, void *_pMsg, struct _TChannel *_ptThis);								//�ϳ�ͨ������Ƶ�Ƿ���
} TChannel;

// �ӿڷ���ֵ����
typedef enum
{
	CHN_RET_FAILD = -1,			//ͨ��ʧ����(���������ɱ�ʾ��ȷ�Ĵ�����)
	CHN_RET_SUCCESS = 0,		//�ɹ�
	CHN_RET_PENDING = 1,		//δ��
	CHN_RET_NOSUPPORT = 2,	//��֧��
} CHANNEL_RET_VALUE;

// ͨ���������붨��
typedef enum
{
	//�������
	CHN_ATTR_VIDEO_SIZE = 0x00000,	//��Ƶ�ߴ�
	CHN_ATTR_VIDEO_NORM,			//��Ƶ��ʽ
	CHN_ATTR_VENC_FRAME_RATE,	//֡��
	CHN_ATTR_VENC_IFRAME_RATE,	//I֡���
	CHN_ATTR_VENC_QUALITY,		//��Ƶ����
	CHN_ATTR_VENC_TYPE,			//��Ƶ�����ʽ
	CHN_ATTR_VENC_BIT_TYPE,		//λ������(������/������)
	CHN_ATTR_VENC_BIT_RATE,		//����kbps

	CHN_ATTR_STREAM_TYPE,			//������������
	CHN_ATTR_AVENC_TYPE,			//��Ƶ�����ʽ

	CHN_ATTR_VENC_PIXEL_SIZE,		//��Ƶ������ʵ�����طֱ���(��ȡ����, ��TVideoSize)
	CHN_ATTR_VENC_MAX_SIZE,		//��Ƶ���ı���ߴ�

	CHN_ATTR_VIDEO_MODE_CHECK,	//�Զ������ʽ	
	CHN_ATTR_VIDEO_PROFILE,		//������Ƶprofile


	CHN_ATTR_AUDIO_SAMPLE,		//��Ƶ������
	CHN_ATTR_AUDIO_SAMPLE_LIST,
	CHN_ATTR_VIDEOSIZE_LIST,	// huaqiang add 20121126
	CHN_ATTR_AUDIOCODER_LIST,  // huaqiang add 20130218, 18
	CHN_ATTR_VDEC_LIMIT_PREVIEW,
	CHN_ATTR_VDEC_FOR_COST,		// zhangyi add 20130617
	
	CHN_ATTR_MEDLEY_AV_ENABLE, //ƴ������Ƶʹ��
	CHN_ATTR_FORCEIFRAME,		//ǿ��I֡ liuqi add 2015-5-25

	//��Ƶ�������
	CHN_ATTR_VI_CNF = 0x00050,		//����ɫ�ȱ��ͶȶԱȶ�(��TChnViCnf)
	CHN_ATTR_VI_C2B,				//��ת��
	CHN_ATTR_VI_SIZE,				//VI��С�ı�
	CHN_ATTR_SENSORSPIN,			//��Ƶ��ת
	CHN_ATTR_VIDEOENCRYPT,		// ��Ƶ����

	//��Ƶ����
	CHN_ATTR_AI_VOL = 0x00060,			//��Ƶ��������
	CHN_ATTR_AI_STAT,					//��Ƶ״̬

	//OSD���
	CHN_ATTR_OSD_NAME_EN = 0x00100,	//ͨ�����Ƶ���ʹ��
	CHN_ATTR_OSD_NAME_CNF,			//ͨ�����Ƶ����ı�λ����ɫ(��TChnNameOsdCnf)
	CHN_ATTR_OSD_NAME_DSP,			//ͨ�����Ƶ���ʹ����λ�ò���(��TOsdDspCnf)
	CHN_ATTR_OSD_NAME_STR,			//ͨ�����Ƶ����ַ���
	CHN_ATTR_OSD_NAME_COLOR,		//ͨ�����Ƶ�����ɫ

	
	CHN_ATTR_OSD_TIME_EN = 0x00110,	//ʱ�����ʹ��
	CHN_ATTR_OSD_TIME_CNF,			//ʱ�������Ϣ(��TChnTimeOsdCnf)
	CHN_ATTR_OSD_TIME_DSP,			//ʱ�����ʹ����λ��(��TOsdDspCnf)
	CHN_ATTR_OSD_TIME_FORMAT,		//ʱ�����ģʽ(��ʽ<<16 | �ָ���,�γ�һ������)
	CHN_ATTR_OSD_TIME_COLOR,			//ʱ�������ɫ
	

	CHN_ATTR_OSD_TEXT_EN = 0x00120,	//�Զ����ı�����ʹ��
	CHN_ATTR_OSD_TEXT_CNF,			//�Զ����ı�������Ϣ(��TChnTextOsdCnf)
	CHN_ATTR_OSD_TEXT_DSP,			//�Զ��ı���ʾ(��TOsdDspCnf)
	CHN_ATTR_OSD_TEXT_STR,			//�Զ��ı�����
	CHN_ATTR_OSD_TEXT_COLOR,			//�Զ����ı���ɫ
	

	CHN_ATTR_OSD_LOGO_EN = 0x00130,	//LOGO����ʹ��
	CHN_ATTR_OSD_LOGO_CNF,		//LOGO������Ϣ(��TChnLogOsdCnf)

	CHN_ATTR_OSD_VCOVER_EN = 0x00140,	//��Ƶ�ڵ�ʹ��
	CHN_ATTR_OSD_VCOVER_AREAS,	//��Ƶ�ڵ�����(��TChnVideoCoverAreaCnf)
	CHN_ATTR_OSD_FONT_SIZE,

	//��Ƶ���ܽ���
	CHN_ATTR_STREAM_ENCRYPT_PSW = 0x00150,	//��Ƶ��������(���ַ���ָ��,Ϊ��ֹͣ����)
	CHN_ATTR_STREAM_DECRYPT_PSW = 0x00151,	//��Ƶ��������(ͬ��)

	//�������
	CHN_ATTR_MD_EN = 0x00200,		//�ƶ����ʹ��
	CHN_ATTR_MD_SENS,			//�ƶ����������	
	CHN_ATTR_MD_AREAS,		//�ƶ��������(��TChnMdAreaCnf)

	CHN_ATTR_VL_EN = 0x00210,		//��Ƶ��ʧ���ʹ��
	
	CHN_ATTR_OD_EN = 0x00230,		//��Ƶ�ڵ�����ʹ��
	CHN_ATTR_OD_ODSADSENS,		//��Ƶ�ڵ��������������
	CHN_ATTR_OD_ODAREASENS,		//��Ƶ�ڵ��������������
	CHN_ATTR_OD_AREAS,		//��Ƶ�ڵ������������

	//��ֵ���
	CHN_ATTR_MAX_FRAME_SIZE = 0x00300,		//���֡����

	
    //���ܷ������	add nsg 20120309
	CHN_ATTR_VCA_CFGCHN = 0x00350,
	CHN_ATTR_VCA_CFGVIDEO,
	CHN_ATTR_VCA_CFGADV,
	CHN_ATTR_VCA_CFGTARGET,
	CHN_ATTR_VCA_RULESET,
	CHN_ATTR_VCA_RULEEVENT0,
	CHN_ATTR_VCA_RULEEVENT2,
	CHN_ATTR_VCA_RULEEVENT7,
	CHN_ATTR_VCA_RULEEVENT8,
	CHN_ATTR_VCA_RULEEVENT9,
	CHN_ATTR_VCA_RULEEVENT10,
	CHN_ATTR_VCA_RULEEVENT11,
	CHN_ATTR_VCA_RULEEVENT12,
	CHN_ATTR_VCA_RULEEVENT13,
	CHN_ATTR_VCA_RULEEVENT_SVD,
	//PTZ ���
	CHN_ATTR_PTZ_PRIORITY = 0x00400,

	/* �Խ����*/
	CHN_ATTR_TALK_OK = 0x00600,			//�Խ��ɹ�
	CHN_ATTR_TALK_ERROR, 				//�Խ�����
	CHN_ATTR_TALK_END, 					//�Խ�����

	//�������
	CHN_ATTR_BESTIR = 0x00800,	 //��������
	
	//����ͨ��
	CHN_ATTR_IP_CNF = 0x01000,		//����ͨ��������Ϣ(��TIpChannelMsg)
	CHN_ATTR_REGCENTER,			//ע������(��TRegCenterMsg������ͨ������)
	CHN_ATTR_VIDEO_HEADER,
	CHN_ATTR_AENC_FRAME_LEN,	//��Ƶ����(��ȡ)
	CHN_ATTR_CONNECT_MAC,	//mac
	CHN_ATTR_TALK_AENC_TYPE,	//���жԽ�����ʱʹ�õ���Ƶ��������
	CHN_ATTR_PREVIEW_PREFER,// Ԥ��ƫ��
    CHN_ATTR_IPC_GETVERSION,	        //��ȡipc�汾
	CHN_ATTR_UPGRATE_STA,//��ȡIPC����״̬
	CHN_ATTR_ALARM_TYPE_CHG = 0x01050,	//���������͸ı�(����ͨ��ר�ã���TIpAlarmerMsg)


	// �ϳ�ͨ��
	CHN_ATTR_VC_CNF = 0x01100,		//�ϳ�ͨ��������Ϣ(��TVcChannelMsg)
	CHN_ATTR_VODEV_FOUCUS,		//��ǰ��Ƶͨ����(��TVoDevFocusChgMsg)

	CHN_ATTR_MIX_AUDIO_CHN,		//����ͨ����Ϣ(��TVcMixAudioChnMsg)
	CHN_ATTR_VITAL_DATA_RINGBUF,		//��������RingBuf

	CHN_ATTR_CHANNEL_ENABLE = 0X01200, // ͨ��ʹ��״̬

	CHN_ATTR_ALARMER = 0x09000,		//��ȡ������ʵ��(��TChnAlarmer)
	
	//������Ը�������������������������Ӧֵ��+ CHN_ATTR_SUB_START
	CHN_ATTR_SUB_START = 0x100000,	//�����������뿪ʼ

} CHANNEL_ATTRIBUTE;


// ͨ���������Ŷ���
typedef enum
{
	// �������
	CHN_CMD_START_ENCODE = 0x00001,	//��ʼ����
	CHN_CMD_STOP_ENCODE,				//ֹͣ����
	CHN_CMD_FORCE_IFRAME,			//ǿ��I֡
	CHN_CMD_SNAPSHOT,				//ͼƬץ��(���Ͳ���ΪTChnSnapshotMsg)

	//Ԥ�����
	CHN_CMD_BIND_VO 		= 0x00010,	//��Ԥ������(���Ͳ���ΪTVoBindMsg)
	CHN_CMD_UNBIND_VO,				//���Ԥ������(���Ͳ���ΪTVO)
	CHN_CMD_BIND_AO,					//����ƵԤ��
	CHN_CMD_UNBIND_AO,				//�����ƵԤ��
	CHN_CMD_DRAW_PREVIEW_OSD,		//��ʾԤ��OSD�ַ�(���Ͳ���ΪTChnOsdCnf)
	CHN_CMD_CLEAR_PREVIEW_OSD,		//���Ԥ��OSD�ַ���ʾ
	CHN_CMD_CHG_DSP_AREA_ON_VO,	//����Ԥ��VO��ʾ����(��TVoBindMsg)
	CHN_CMD_PRV_CHECK,				//Ԥ��״̬���(���Ͳ���ΪTVoBindMsg)
	CHN_CMD_AUDIO_PV,				//(��ƵԤ����ǿ�ӿڣ���ָ��AO�豸�ţ���������)

	//�������
	CHN_CMD_START_AS_SEND	= 0x00020, //��������Ƶ����(���Ͳ���TRingBuf)
	CHN_CMD_STOP_AS_SEND	= 0x00021, //ֹͣ����Ƶ����

	// ��̨�������
	CHN_CMD_PTZ_CTR 		= 0x00100,	//�����ƾ�������(����TPtzCtrParam)

	//����ϳ�ͨ�����
	CHN_CMD_ATYPE_CHG		= 0x00200,	//ͨ����Ƶ���ͱ��(��ͨ����)
	CHN_CMD_ASAMPLERATE_CHG,                        //��Ƶ�����ʱ�� ljj add
	//���ܷ������ nsg add 2012007
	CHN_CMD_VCA_REBOOT		= 0x00300,	// �������ܷ�����
	CHN_CMD_VCA_ALARMSTATCLR,			// ���ܷ���������������
	//end
	CHN_CMD_VCA_RECREATE,				//���ܷ����ؽ�

	// �л�Ԥ������
	CHN_CMD_CHANGE_PREVIEWSTREAM = 0x00400,

	// ���������(�����ͨ���޹أ�����Ȼ��ͨ������ʽ����)
	CHN_CMD_SPECIAL		= 0xF0000,
	CHN_CMD_IPC_SEARCH,				//����ͨ������(��TIpcSearchParam)
	CHN_CMD_IPC_LIST,				//��ȡIPC ����״̬�б�(���ַ���ָ�룬6K��С)
	CHN_CMD_IPC_SET_TIME,			//�޸�ʱ��(�޲���)
	CHN_CMD_IPC_SET_TIMEZONE,       //�޸�ʱ��
	CHN_CMD_CLIP_SIDE,				//���òñ�
	CHN_CMD_IPC_CHANGE,
	CHN_CMD_IPC_TALK_START,		//������ͨ����ʼ�Խ�(���Ͳ���TIpTalkPara)
	CHN_CMD_IPC_TALK_STOP,		//������ͨ��ֹͣ�Խ�
	CHN_CMD_IPC_SEND_PUSH_DATA,	//������ͨ������push��(���Ͳ���TPushData)
	CHN_CMD_IPC_REBOOT,				//����ǰ���豸
	CHN_CMD_IPC_UPGRADE,			//����bin��box�ļ�

	CHN_CMD_IPC_CHANGEIP = 0xF000F,	//�޸�ǰ��IPC IP��ַ
	CHN_CMD_CHN_REBOOT,
	
	CHN_CMD_SUB_START 	= 0x100000,	//�����������뿪ʼ
} CHANNEL_CMD;


// ��Ϣ֪ͨ��Ŷ���:
typedef enum
{
	CHN_MSG_NOP = 0x00000,
	CHN_MSG_ATTR_CHG,					//ͨ�����Ը���

	//ץ�����
	CHN_MSG_SNAPSHOT_DONE = 0x00010,		//ץ�����
	CHN_MSG_SNAPSHOT_FAILD = 0x00011, 	//ץ��ʧ��

	// ����ͨ��
	CHN_MSG_CONNECT_BAD = 0x00100,		//�����ж�
	CHN_MSG_CONNECT_RECOVER,			//���ӻָ�

	//����
	CHN_MSG_HEART = 0x00200,			//���ӻָ�
} CHANNEL_MSG;

// ��������ID
typedef enum
{
	CHN_PM_PREVIEW = 0,	//Ԥ��
	CHN_PM_ENCODE,		//����
	CHN_PM_NTX,			//����
	CHN_PM_USERSET_STREAM,

	CHN_PM_SUB_START = 0x10000,	//������ͨ�����ܼ���
} CHANNEL_PERFORMANCE;

// ͨ������
typedef enum
{
	CHN_TYPE_TEST		= 0x000,		//�����õ�ͨ������
	CHN_TYPE_BNC 		= 0x100,		//BNCͨ������(ͨ�������������LOCAL��PCI)
	CHN_TYPE_LOCAL 		= 0x101,		//��Ƭͨ��
	CHN_TYPE_PCI		= 0x102,		//pci��Ƭͨ��
	CHN_TYPE_SDIPCI		= 0x150,		//sdi��Ƭͨ��
	CHN_TYPE_SDILOCAL 	= 0x151,		//sdi��Ƭͨ��
	CHN_TYPE_VC			= 0x200,		//VO�ϳ�ͨ��
	CHN_TYPE_SVC		= 0x201,		//��ҵVO�ϳ�ͨ��
	CHN_TYPE_IP			= 0x300,		//����ͨ��
} CHANNEL_TYPE;

// �ص�����ID�Ŷ���
typedef enum
{
	CHN_CB_ATTACH_AUDIO_STREAM = 0x0001,	//��ȡͨ����Ƶ���ݻص�
	CHN_CB_DETACH_AUDIO_STREAM = 0x0002, 	//ֹͣ��ȡͨ����Ƶ���ݻص�
	CHN_CB_GET_CHANNEL_INSTANCE = 0x0003, 	//ͨ��ͨ���Ż�ȡͨ��ʵ��
	CHN_CB_ALARMER_REGISTER = 0x0004,			//������ע�ắ��
	CHN_CB_STREAM_CRYPT = 0x0005,				//��Ƶ�ӽ��ܺ���

	CHN_CB_COM_DATA		= 0x0101,			//��������

	CHN_CB_PTZ_CTRL		= 0x0201,			//ptz//dxl 20130117
} CHANNEL_CALLBACK_ID;
//dxl 20130117
typedef struct
{
	int iPreset;
	int iSpeedX;
	int iSpeedY;
} TChnPtzParam;

typedef TRingBuf *(*ChnAttachAudioStreamCallback)(td_s32 _iChn);
typedef td_s32 (*ChnDetachAudioStreamCallback)(TRingBuf * _ptBuf);
typedef TChannel *(*ChnGetInstanceCallback)(td_s32 _iChn);
typedef td_s32 (*ChnAlarmerRegisterCallBack)(td_s32 _iId, td_s32 _iType, TAlarmer *_ptAlarm);
typedef td_s32 (*ChnStreamCryptCallBack)(void *_pBuf, td_s32 _iSize, td_u32 _uiKey,  td_u8 *_strPsw, td_s32 _iPswLen);
typedef td_s32 (*ChnComDataProcCallBack)(td_s32 _iChn, td_s32 _iComdId, td_s32 _iLength, void *_pBuf);
typedef td_s32 (*ChnPtzCtrlCallBack)(td_s32 _iChn, int _iPtzAction, TChnPtzParam * _ptTChnPtzParam);//dxl 20130117 ͨ��PTZ�ص�����

// ÿ��ѯ��һ���豸��ͨ���˻ص����Ϸ���һ��TIpcDevItemʵ��, ��NULL���ѯ����
typedef td_s32 (*ChnIpcSearchReportCallBack)(TIpcDevItem *_ptItem);

typedef struct //����ͨ����������
{
	ChnIpcSearchReportCallBack m_fReportFun;
	td_s32 m_iSearchType;
} TIpcSearchParam;

// for decoder
typedef struct
{
	TDataCenter* m_pIpTalkCenter; 
}TIpTalkPara;

typedef struct
{
	td_u8* 	m_pBuf;
	int 		m_iBufLen;
}TPushData;
//������ͨ������ͨ��push������
td_s32 chnmnt_ChannelIpChannelPushData(td_s32 _iChn,TPushData* _ptPushData);
#endif


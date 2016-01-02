#ifndef _TD_SDK_H_
#define _TD_SDK_H_

enum TVVIDEOSIZE
{
	TVQCIF  =	0,
	TVHCIF	=	1,
	TVFCIF	=	2,
	TVHD1	=	3,
	TVFD1	=	4,
	TVMD1	=	5,
	TVQVGA	=	6,
	TVFVGA	=	7,
	TVHVGA	=	8,
	TVF720P	=	9,
	TVF960P	=	10,
	TVF1200	=	11,
	TVF1080P	=	12,
	TVF960H		=	13, 
	TVF300W		= 	14,
	TVF500W		= 	15,
	TVMAX		=	16
};

typedef struct
{
	int 		m_iType;							//�豸����
	char		m_serName[40];						//����������(��ʱ����)
	char		m_serIP[40];						//��������ַ��������IP��ַ��Ҳ������������  m_strUrl
	char		m_serProxy[40];						//�������ϼ�����m_strProxy
	int			m_serNetmode;						//����Э��0��TCP��1��UDP
	int			m_iCoonectMod;						//���ӷ�ʽ  0--IP   1----���� 2----����ģʽ
	int			m_iPort;							//�������˿�  
	int 		m_serChan;							//������ͨ��m_iChn
	int			m_serStream;						//��������������m_iStremType  0������ 1������	2��Ƶ��
	char		m_strUserName[40+1];				//�û���
	char		m_strUserPsw[40+1];					//����
	char		m_strVdecPsw[40 + 1];				//��Ƶ��������
	char		m_strMac[40];
	char		m_strKey[8];
	int		m_iUseKey;// 0:��һ�ε�¼��1:�������ĵ�¼��2�������ĵ�¼
	char		m_strRtspUrl[256];   //������չRTSP�ĵ�ַ����RTSP ��ַ���ȴ���80�ֽ�ʱ��ʹ�ñ��ֶΣ�����ʹ��ԭ�ֶΡ�
}TNVSITEM; 


typedef struct
{
    char  * m_cBuf;					
    int 	m_iLen;		
    int 	m_iCom;
}ComRcv;	


typedef struct
{
    int 	m_iWidth;				//��Ƶ���
    int 	m_iHeight;				//��Ƶ�߶�
    int 	m_iType;				//��Ƶѹ����ʽ
    int 	m_iFrame;				//��Ƶ֡��
}VideoDim;	//��Ƶ�ߴ�

typedef struct				//��Ƶ�����������
{
	int m_iHue;				//ɫ���� 0-255
	int m_iLum;				//������ 0-255
	int m_iContrast;			//�Աȶ� 0-255
	int m_iSaturation;		//���Ͷ� 0-255
} VideoP;


typedef struct
{
	int 	m_iLeft;
	int 	m_iTop;
	int 	m_iWidth;
	int 	m_iHeight;
} RectArea;

#define CHN_MAX_VC_AREAS					4
typedef struct	// ��Ƶ�ڵ���������
{
	int m_iAreaCnt;							//�������
	RectArea m_tAreas[CHN_MAX_VC_AREAS];	//����(�ߴ簴ʵ������)
} VideoCoverAreaCnf;

typedef struct				//��Ƶ�����������
{
	char m_cAreaEnBmp[18][22];
} MdArea;

typedef struct
{
	int			m_iState;		// ����״̬
	unsigned int 	m_iTid;			// Ŀ��ID
	int 			m_iEventType;	// �¼�����
	int			m_iRuleID;		// ����ID
	int			m_iTType;		// Ŀ������
	int			m_iTposition;		// Ŀ��λ��
	int			m_iTspeed;		// Ŀ���ٶ�
	int			m_iTdirection;	// Ŀ���˶�����
}VCAAlarmParam, *pVCAAlarmParam;

typedef struct	//OSD����ͨ��ʹ����λ�ò���
{
	int m_iEnable;	//ʹ��
	int m_iLeft;		//x
	int m_iTop;		//y
	int m_iType;		//����1--ʱ�� 2--ͨ������  4---�Զ����ַ�
} OsdDspCnf;

typedef struct	//OSD������ɫ
{
	int m_iType;		//����1--ʱ�� 2--ͨ������  4---�Զ����ַ�
	int m_iColor;		//��ɫ
} OsdColor;


typedef struct	//ͨ�����Ƶ�����Ϣ
{
	int m_iLeft;								//x����
	int m_iTop;								//y����
	int m_iColor;								//��ɫRGB
	char m_strText[256];						//ͨ�����ı�

	int m_iOldLeft;								//x����
	int m_iOldTop;								//y����
} NameOsdCnf;

typedef struct	//ʱ�������Ϣ
{
	int m_iLeft;								//x����
	int m_iTop;								//y����
	int m_iColor;								//��ɫRGB
	int m_iFormate;							//ʱ���ʽ
	int  m_iGit;

	int m_iOldLeft;								//x����
	int m_iOldTop;								//y����
} TimeOsdCnf;

typedef struct	//�Զ����ı�������Ϣ
{
	int m_iLeft;								//x����
	int m_iTop;								//y����
	int m_iColor;								//��ɫRGB
	char m_strText[512];						//�ı�
	int m_iLayNo;
	int m_iFontSize;
	int m_iOldLeft;								//x����
	int m_iOldTop;								//y����
} TextOsdCnf;

typedef struct	// LOGO������Ϣ
{
	int m_iDsp;	                            //shc add ���������ʾλ
	int m_iLeft;							//x����
	int m_iTop;							//y����
	int m_iBmpWidth;					//λͼ��
	int m_iBmpHeight;					//λͼ��
	char *m_pcBmpData;					//λͼ����(24ɫRGB)
	int m_iOldLeft;								//x����
	int m_iOldTop;								//y����
} LogOsdCnf;


typedef struct
{
	char m_cIp[32];
	int m_iPort;
	char m_cUserName[16];
	char m_cUserPass[16];
}DdnsInfor;


enum SETMSGTYPE
{
	MSG_DDNS = 0,
	MSG_MAINDDNS,
	MSG_SUBDDNS
};

enum STREAMTYPE
{
	VIDEO_STREAM = 1,
	AUDIEO_STREAM = 2,
	AV_STREAM
};


enum EVENTTYPE
{
	EVENT_CONNECT = 0,
	EVENT_CHANPARA,
	EVENT_ALARM,
	EVENT_TALK,
	EVENT_COMRCV,
	EVENT_UPGRATE
};


enum MSGTYPE
{
	/*��Ƶ������� */
	MSG_VIDEOSIZE = 0x00000,			//��Ƶ�ߴ�
	MSG_VIDEOMODE,					//��Ƶ��ʽ
	MSG_FRAMERATE,					//֡��
	MSG_IFRAMERATE,					//I֡���
	MSG_VIDEOQUALITY,					//��Ƶ����
	MSG_VENCTYPE,						//��Ƶ�����ʽ
	MSG_ENCODETYPE,					//λ������(������/������)
	MSG_BITRATE,						//����kbps

	MSG_STREAMTYPE,					//������������
	MSG_AUDIOCODER,					//��Ƶ�����ʽ
	
	MSG_VIDEOPIXEL,
	MSG_MAXVIDEOSIZE,					//��Ƶ���ı���ߴ�
	MSG_ATUOCHECK,
	MSG_VIDEOPROFILE,				//��Ƶprofile
	MSG_AUDIOSAMPLE,					//��Ƶ������
	MSG_AUDIOSAMPLELIST,
	MSG_VIDEOLIST,						// ��Ƶ�ֱ����б�
	MSG_AUDIOCODERLIST,				// ��Ƶ�����������
	
	//��Ƶ�������
	MSG_VIDOEPARA = 0x00050,			//����ɫ�ȱ��ͶȶԱȶ�(��TChnViCnf)
	MSG_COLORPARA,					//��ת��
	MSG_SENSORSPIN = 0x00053,					//��Ƶ��ת
	MSG_VIDEOENCRYPT,					// ��Ƶ����

	//��Ƶ����
	MSG_AIVOL = 0x00060,				//��Ƶ��������

	//OSD���
	MSG_OSDTITLE_ENABLE = 0x00100,	//ͨ�����Ƶ���ʹ��
	MSG_OSDTITLE,						//ͨ�����Ƶ����ı�λ����ɫ(��TChnNameOsdCnf)
	MSG_OSDTITLE_DSP,
	MSG_OSDTITLE_STR,
	MSG_OSDTITLE_COLOR,
	
	MSG_OSDTIME_ENABLE = 0x00110,	//ʱ�����ʹ��
	MSG_OSDTIME,						//ʱ�������Ϣ(��TChnTimeOsdCnf)

	MSG_OSDTEXT_ENABLE = 0x00120,		//�Զ����ı�����ʹ��
	MSG_OSDTEXT,						//�Զ����ı�������Ϣ(��TChnTextOsdCnf)

	MSG_OSDLOGO_ENABLE = 0x00130,	//LOGO����ʹ��
	MSG_OSDLOGO,						//LOGO������Ϣ(��TChnLogOsdCnf)

	MSG_VIDEOCOV_ENABL = 0x00140,	//��Ƶ�ڵ�ʹ��
	MSG_VIDEOCOV,						//��Ƶ�ڵ�����(��TChnVideoCoverAreaCnf)
	MSG_OSD_FONTSIZE,				// OSD �ֺ�

	//�������
	MSG_MDALARM_ENABLE = 0x00200,	//�ƶ����ʹ��
	MSG_MDALARM_SEN,				//�ƶ����������	
	MSG_MDALARM_AREAS,				//�ƶ��������(��TChnMdAreaCnf)

	MSG_VLALARM_ENABLE = 0x00210,	//��Ƶ��ʧ���ʹ��


	/*��������*/
	MSG_PORTALARM_ENABLE = 0x00220,		
	MSG_PORTALARM_TYPE,
	MSG_PORTALARM_STATE,
	MSG_MDALARM_STATE,					//�ƶ����״̬
	MSG_VLALARM_STATE,					//��Ƶ��ʧ����״̬

	/*  ��Ƶ�ڵ��������*/
	MSG_ODALARM_ENABLE = 0x00230, // ��Ƶ�ڵ�����ʹ��
	MSG_ODALARM_STATE,			 // ��Ƶ�ڵ�����״̬

	MSG_VCAALARM_STATE = 0x00240, // ���ܷ�������״̬

	/*�������*/
	MSG_CONNECT_SUCCESS =0x00300,	//���ӳɹ�
	MSG_CONNECT_ING,					//������
	MSG_CONNECT_ERROR,				//���Ӵ����豸
	MSG_VIDEO_HEADER,
	MSG_VIDEO_BITRATE,
	MSG_CONNECT_MAC,

	MSG_COMDATA	=0x00500,

	/* �Խ����*/
	MSG_TALK_OK = 0x00600,			//�Խ��ɹ�
	MSG_TALK_ERROR, 				//�Խ�����
	MSG_TALK_END, 					//�Խ�����
	MSG_TALK_AENC_TYPE,

	
	//�������
	MSG_BESTIR = 0x00800, // ��������

	/*����*/
	MSG_MASTER_VERSION	= 0x01006,
	MSG_UPGRATE_STA =0x01007, //Զ������IPC ״̬

	//������Ը�������������������������Ӧֵ��+ MSG_SUB_START
	MSG_SUB_START = 0x100000,	//�����������뿪ʼ
};

// ͨ���������Ŷ���
typedef enum
{
	// �������
	CMD_START_ENCODE = 0x00001,	//��ʼ����
	CMD_STOP_ENCODE,				//ֹͣ����
	CMD_FORCE_IFRAME,			//ǿ��I֡
	CMD_SNAPSHOT,				//ͼƬץ��(���Ͳ���ΪTChnSnapshotMsg)

	//Ԥ�����
	CMD_BIND_VO 		= 0x00010,	//��Ԥ������(���Ͳ���ΪTVoBindMsg)
	CMD_UNBIND_VO,				//���Ԥ������(���Ͳ���ΪTVO)
	CMD_BIND_AO,					//����ƵԤ��
	CMD_UNBIND_AO,				//�����ƵԤ��
	CMD_DRAW_PREVIEW_OSD,		//��ʾԤ��OSD�ַ�(���Ͳ���ΪTChnOsdCnf)
	CMD_CLEAR_PREVIEW_OSD,		//���Ԥ��OSD�ַ���ʾ
	CMD_CHG_DSP_AREA_ON_VO,	//����Ԥ��VO��ʾ����(��TVoBindMsg)
	CMD_PRV_CHECK,				//Ԥ��״̬���(���Ͳ���ΪTVoBindMsg)


	//�������
	CMD_START_AS_SEND	= 0x00020, //��������Ƶ����(���Ͳ���TRingBuf)
	CMD_STOP_AS_SEND	= 0x00021, //ֹͣ����Ƶ����

	// ��̨�������
	CMD_PTZ_CTR 		= 0x00100,	//�����ƾ�������(����TPtzCtrParam)

	//����ϳ�ͨ�����
	CMD_ATYPE_CHG		= 0x00200,	//ͨ����Ƶ���ͱ��(��ͨ����)
	CMD_ASAMPLERATE_CHG,                        //��Ƶ�����ʱ�� ljj add
	//���ܷ������ nsg add 2012007
	CMD_VCA_REBOOT		= 0x00300,	// �������ܷ�����
	CMD_VCA_ALARMSTATCLR,			// ���ܷ���������������
	//end
	CMD_VCA_RECREATE,				//���ܷ����ؽ�

	// �л�Ԥ������
	CMD_CHANGE_PREVIEWSTREAM = 0x00400,

	// ���������(�����ͨ���޹أ�����Ȼ��ͨ������ʽ����)
	CMD_SPECIAL		= 0xF0000,
	CMD_IPC_SEARCH,				//����ͨ������(��TIpcSearchParam)
	CMD_IPC_LIST,				//��ȡIPC ����״̬�б�(���ַ���ָ�룬6K��С)
	CMD_IPC_SET_TIME,			//�޸�ʱ��(�޲���)
	CMD_IPC_SET_TIMEZONE,       //�޸�ʱ��
	CMD_CLIP_SIDE,				//���òñ�
	CMD_IPC_CHANGE,
	CMD_IPC_TALK_START,		//������ͨ����ʼ�Խ�(���Ͳ���TIpTalkPara)
	CMD_IPC_TALK_STOP,		//������ͨ��ֹͣ�Խ�
	CMD_IPC_SEND_PUSH_DATA,
	
	CMD_IPC_REBOOT,				//����ǰ���豸
	CMD_IPC_UPGRADE,			//����bin��box�ļ�

	CMD_CHN_REBOOT = 0xF0010,// ����ǰ��IPC

	CMD_SUB_START 	= 0x100000,	//�����������뿪ʼ
} CHN_CMD;


enum SERCHTYPE
{
	NET_TYPE = 0,
	DNS_TYPE  =  1,        
	ID_TYPE   = 2,
	ALL_TYPE = 0xFF
};

enum SENDVCPARAMSTAT
{
	PARAM_NOSEND = 0,
	PARAM_RCVHEAD  =  1,        
	PARAM_SENDED = 2,
	PARAM_LIMIT = 3
};

// zty 20120220
//enum
//{
//	GUI_DEV_TYPE_PRIVATE = 0, //�豸����Ϊ˽������
//	GUI_DEV_TYPE_ONVIF,      //�豸����Ϊonvif
//};
// zty add end
#define GUI_DEV_TYPE_PRIVATE 	0
#define GUI_DEV_TYPE_ONVIF		1
#define GUI_DEV_TYPE_PUSH		2		
#define GUI_DEV_TYPE_RTSP		3		

typedef struct
{
	char m_cMac[32];
	char m_cMask[40];			
	char m_cGateWay[40];		
	char m_cDNS[40];
	char m_cFactoryID[40];
	char m_cName[32];
	char m_cIp[40];
	char m_cProxyIp[40];
	int m_iPort;
	int m_iChanNum;
	char m_strServerType[32];//����������
}NvsLook;







typedef int  (*EVENT_PROCESS)(void * _pIpChan[],int _iNum, int _EventID,int _MsgID, void *_pMsg);
typedef int  (*DATA_PROCESS)(void * _pIpChan[],int _iNum, char *_cBuf,int _iLen,int _iFrameType);
typedef int (*NVSSERCH_PROCESS)(void * _pModule,NvsLook * _pNvs);



typedef struct
{
	int		m_iType;																				//��������
	char 	m_cTypeStrig[128];																		//��������	
	
	int		m_iNum;																				//��������
	
	int (*module_SetTime)(void *_pMChan,int _iYear,int _iMonth,int _iData,int _iHour,int _iMin,int _iSec);			//Уʱ

	int (*module_SetTimeZone)(void *_pMChan, int _iTimeZone);

	int (*module_SetVideoPara)(void *_pMChan, VideoP * _pVideo);											//������Ƶ����
	
	int (*module_SetFrameRate)(void *_pMChan, int _iFrame);												//����֡��
	
	int (*module_SetIFrameRate)(void *_pMChan, int _iIFrame);											//����I֡��
	
	int (*module_SetBitRate)(void *_pMChan, int _iBitRate);												//��������
	
	int (*module_SetVideoSize)(void *_pMChan, int _iVideoSize);											//������Ƶ��С

	int (*module_SetVideoProfile)(void *_pMChan, int _iVideoProfile);									//������Ƶprofile
	
	int (*module_SetAideoEnType)(void *_pMChan, int _iType);											//������Ƶ�����ʽ
	
	int (*module_SetStreamType)(void *_pMChan, int _iStreamType);										//������������ ��Ƶ ��Ƶ ����Ƶ
	
	int (*module_SetVideoQuality)(void *_pMChan,int _iVideoQuality);										//������Ƶ����
	
	int	(*module_SetEncodeType)(void *_pMChan,int _iEncodeType);										//����CBR����VBR
	
	int	(*module_SetAudioSample)(void *_pMChan,int _iEncodeType);	

	int	(*module_SetVencType)(void *_pMChan,int _iVencType);											//���ñ����ʽ0��H.264��1��M-JPEG��2��MPEG4
	
	int (*module_SetInputNorm)(void *_pMChan,int _iMod);												//������ʽ
	
	int (*module_SetColorToGray)(void *_pMChan,int _iColorGray);											//���ò�ת��
	
	int (*module_SetVideoCovArea)(void *_pMChan,VideoCoverAreaCnf * _pCover);							//������Ƶ�ڵ�����

	int (*module_SetOsdDisplay)(void *_pMChan, OsdDspCnf* _pOsdDspCnf);								//�����ַ����ӵ�λ�ü�ʹ��
	
	int (*module_SetOsdColor)(void *_pMChan, OsdColor* _pOsdColor);										//�����ַ����ӵ���ɫ
	int (*module_SetOsdTitle)(void *_pMChan, char * _cTitle);												//�����ַ����� ͨ������
	
	int (*module_SetOsdTime)(void *_pMChan, int _iFormat);												//�����ַ����� ʱ���ʽ

	int (*module_SetOsdChannnelTitlePara)(void *_pMChan, NameOsdCnf* _pOsdChannelTitle);					//����ͨ�����Ƶ��� ����
	
	int (*module_SetOsdChannnelTitleEnable)(void *_pMChan, int  _iEnable);								//����ͨ�����Ƶ��� ʹ��
	
	int (*module_SetOsdTimePara)(void *_pMChan, TimeOsdCnf* _pOsdTime);								//����ʱ����� ����
	
	int (*module_SetOsdTimeEnable)(void *_pMChan, int  _iEnable);										//����ʱ����� ʹ��
	
	int (*module_SetOsdLogPara)(void *_pMChan, LogOsdCnf* _pOsdLog);									//����LOG���� ����
	
	int (*module_SetOsdLogEnable)(void *_pMChan, int  _iEnable);											//����log���� ʹ��
	
	int (*module_SetOsdTextPara)(void *_pMChan, TextOsdCnf* _pOsdText);									//�����Զ����ַ�L���� ����
	
	int (*module_SetOsdTextEnable)(void *_pMChan, int  _iEnable);											//�����Զ����ַ����� ʹ��

	int (*module_SetInportEnable)(void *_pMChan,int _iEnable);											//���ö˿ڱ���ʹ��
	
	int (*module_SetInputAlarmMode)(void *_pMChan, int _iLowOrHigh);									//���ö˿ڱ���������ʽ
	
	int (*module_SetAlarmVideoLostEnanle)(void *_pMChan,int _iEnable);									//������Ƶ��ʧ����ʹ��

	int (*module_SetMotionAlarmEnable)(void *_pMChan,int _iEnable);										//������Ƶ�ƶ�����ʹ��
	
	int (*module_SetMotionAlarmThreshold)(void *_pMChan,int _iThreshold);								//������Ƶ�ƶ��������������
	
	int (*module_SetMotionAlarmArea)(void *_pMChan,MdArea * _pMD);									//������Ƶ�ƶ������������
	
	int (*module_SetAttribute)(void *_pMChan,int _iAid, const void *_pValue);									//����������չ
	
	int (*module_ForceIFrame)(void *_pMChan);															//ǿ��I֡
	
	//int (*module_PtzContorl)(void *_pMChan,void * _cbuf, int _iLen,void * _ComNum);							//PTZ����
	// zty 20120220
	int (*module_PtzContorl)(void *_pMChan,void * _cbuf, int _iLen,void * _ComNum, void *_ptProtocolData);	//PTZ����
	
	int (*module_Talk)(void *_pChan,void * _pIpChan,int _iFlag);											//�Խ� ���󼰹ر�
	
	int (*module_SendTalkData)(void *_pMChan,void * _cbuf, int _iLen);										//�Խ�����
	
	void *  (*module_Connect)(TNVSITEM *_pIpChan,void * _pIpchan);										//����ͨ�� ������Ƶ
	
	int (*module_DisConnect)(void *_pMChan,void * _pIpChan);											//����ͨ�� �Ͽ�����
	
	int (*module_DoCmd)(void *_pMChan,int _iCid, void *_pArg);											// ������չ
	
	int (*module_GetAttribute)(void *_pMChan,int _iAid, void *_pValue);										//��ȡ����

	int (*module_SetMoudAttribute)(void *_pMod,int _iAid, void *_pValue);									// ����ģ�����

	int (*module_SerchNvs)(int _iType);	
	
	int (*module_StopSerchNvs)(int _iType);	

	int (*module_ChangeIp)(void *_tChgIp);
	
	void (*module_Uninit)(void);
	
	int (*module_GetDebug)(char * _cSting,int _iLen);
	
	int (*module_GetNetCost)(void);
	
	int (*module_SetEncrypt)(void *_pMChan,char *_pcPasswd);//add by gyn 20120918����ͨ����Ƶ����

	EVENT_PROCESS	MsgNotifyCallback;																// ��Ϣ����ص�	
	
	DATA_PROCESS	VidoeCallback;																	// ����Ƶ���ݻص�  
	
	NVSSERCH_PROCESS	SerchResultCallback;															// ��������ص�
	
}TNVSMODULE;						//�򿪿��ʱ���ʼ��  ���ٸ����Ҷ��ٸ�ʵ��


typedef struct 
{
	char m_strMac[40];
	char m_strIP[40];
	char m_strSubMask[40];
	char m_strGateWay[40];
	char m_strDNS[40];
}TChgIp;

#endif



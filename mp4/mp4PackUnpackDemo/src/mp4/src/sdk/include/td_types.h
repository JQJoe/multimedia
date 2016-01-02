// ͨ�����ݽṹ����
// duxiulong 2011/03/01
// ע��: ���ļ�ֻ����ͨ�õ����ݽṹ��������ӿ�

#ifndef _TD_TYPES_H_
#define _TD_TYPES_H_

#include <time.h>

#include "public_def.h"

//#include "alarmer.h"

// =========== ������ض���==================================
//usbģ�⴮��ΪNULL ʱ�����߼���
#define NULL_USB_SERIAL_COMID 201104

typedef struct	//��������
{
	td_s32 m_iBitRate;		//������
	td_s32 m_iDataBits;		//����λ
	td_s32 m_iStopBits;		//ֹͣλ
	td_s32 m_iChecksum;	//��żУ��
} TComAttribute;

typedef struct _TComInstance	//����ʵ��
{
	td_s32 m_iComId;	//�����߼���

	//��������
	td_s32 (*Close)(struct _TComInstance *_ptThis); 
	//���ڶ�����(�첽)
	td_s32 (*Read)(td_s32 _iSize, void *_pBuf, struct _TComInstance *_ptThis);
	//����д����
	td_s32 (*Write)(td_s32 _iSize, const void *_pBuf, struct _TComInstance *_ptThis);
	//������������
	td_s32 (*SetAtrribute)(TComAttribute *_ptAttr, struct _TComInstance *_ptThis);
} TComInstance;

// ============ ͨ��������ض���==============================

// !!!!!ע�⣬���ṹ�����������ݣ�ֻ������ĩβ׷�ӣ��������м���� 
typedef struct	//��ͨ��ģ���ʼ�����ò����ṹ
{
	td_s32 m_iLenght;		//�ṹ����

	// ����ͨ��ר��
	td_s32 m_iVideoNorm;	//��Ƶ������ʽ

	// �ϳ�ͨ��ר��
	td_s32 m_iVoDev;		//�豸��,VO_DEV_VGA,VO_DEV_BNCx����Ļ¼��,VO_DEV_VC��VO�ϳ�

	// ����ͨ��ʹ��(ע������)
	td_u8 m_strRcIp[2][32];			//ע������IP��ַ(��֧������)
	td_s32 m_iRcPort[2];			//ע�����Ķ˺�
	char m_strRcUserName[2][16];	//ע�������û���
	char m_strRcUserPass[2][16];	//ע����������
	td_s32 m_iMaxNetBitrate;			//����ͨ����������������
	
} TChnModuleInitParam;

// !!!!!ע�⣬���ṹ�����������ݣ�ֻ������ĩβ׷�ӣ��������м���� 
typedef struct //ͨ����ʼ������
{
	td_s32 m_iLength;				//���ṹ����
	td_s32 m_iLogicNo;				//�߼�ͨ����(�ϲ�ָ��)
	td_s32 m_iType;					//ͨ������
	
	// ģ��ͨ����
	td_s32 m_iChnNo;	 			//ͨ����(����ͨ����Ϊ�Է�ͨ����)
	td_s32 m_iMaxVideoSize;			//�����Ƶ�ߴ�
	td_s32 m_iVideoNorm;			// ��Ƶ��ʽ
	td_s32 m_iVencType;				//��Ƶ�����ʽ
	td_s32 m_iAencType;				//��Ƶ����ģʽ
	td_s32 m_iAudioSample;			//��Ƶ������
	td_s32 m_iVideoSize[2];			//��ǰ��Ƶ�ߴ�
	td_s32 m_iFrameRate[2];			//֡��
	td_s32 m_iIFrameRate[2];			//I֡���
	td_s32 m_iQuality[2];				//��Ƶ����
	td_s32 m_iStreamType[2];			//��������
	td_s32 m_iBitsType[2];			//λ������
	td_s32 m_iBitsRate[2];			//����(����)

	// ����ͨ����
	td_s32 m_iIpcEnable;				//ʹ�ܱ�ʶ
	td_s32 m_iServerType;			//�豸����
	td_u8 m_strServerName[40];		//����������(��ʱ����)
	td_u8 m_strServerIP[40];			//��������ַ��������IP��ַ��Ҳ������������  m_strUrl
	td_u8 m_strServerProxy[40];		//�������ϼ�����m_strProxy
	td_s32 m_iChnType;				//��������������0������ 1������
	td_s32 m_iNetMode;				//����Э��1��TCP��2��UDP��3���ಥ��m_iConntectType
	td_s32 m_iCoonectMode;			//���ӷ�ʽ  0--IP   1----���� 2----����ģʽ
	td_s32 m_iServerPort;			//�������˿�   
	td_u8 m_strUserName[20 + 1];		//�û���
	td_u8 m_strUserPsw[20 + 1];		//����
	td_u8 m_strVdecPsw[20 + 1];		//��Ƶ��������

	// ����ϳ�ͨ��
	td_s32 m_iVoDev;				//��ʾ�豸��	

	//hq:20121210 Ϊ��Ӧ16:9��ƵԴ��4:3�ֱ�������ʾ��0:ƽ������ʾ����1:���ֿ���������ʾ
	td_s32 m_iPreviewMode; //����ͨ��ʹ��
	td_s32 m_iaudiochn;		//ͨ����Ӧ����Ƶͨ��
} TChnInitParam;

typedef struct	//��Ƶ�����������
{
	td_s32 m_iHue;								//ɫ���� 0-255
	td_s32 m_iLum;								//������ 0-255
	td_s32 m_iContrast;							//�Աȶ� 0-255
	td_s32 m_iSaturation;						//���Ͷ� 0-255
} TChnViCnf;

typedef struct	//OSD����ͨ��ʹ����λ�ò���
{
	td_s32 m_iEnable;	//ʹ��
	td_s32 m_iLeft;		//x
	td_s32 m_iTop;		//y
} TOsdDspCnf;

typedef struct	//ͨ�����Ƶ�����Ϣ
{
	td_s32 m_iLeft;								//x����
	td_s32 m_iTop;								//y����
	td_s32 m_iColor;								//��ɫRGB
	td_u8 m_strText[256];						//ͨ�����ı�
} TChnNameOsdCnf;


typedef struct	//ʱ�������Ϣ
{
	td_s32 m_iLeft;								//x����
	td_s32 m_iTop;								//y����
	td_s32 m_iColor;							//��ɫRGB
	td_s32 m_iFormate;							//ʱ���ʽ
	td_s32 m_iSeparator;						//�ָ���(���ַ�����)
} TChnTimeOsdCnf;

typedef struct	//�Զ����ı�������Ϣ
{
	td_s32 m_iLeft;								//x����
	td_s32 m_iTop;								//y����
	td_s32 m_iColor;								//��ɫRGB
	td_u8  m_strText[512];						//�ı�
	td_s32 m_iLayNo; //����ID,֧��5��	
	td_s32 m_iFontSize;
} TChnTextOsdCnf;

typedef struct	// LOGO������Ϣ
{
	td_s32 m_iDsp;								//�Ƿ���ʾ
	td_s32 m_iLeft;								//x����
	td_s32 m_iTop;								//y����
	td_s32 m_iBmpWidth;						//λͼ��
	td_s32 m_iBmpHeight;						//λͼ��
	td_u8 *m_pcBmpData;						//λͼ����(24ɫRGB)
} TChnLogOsdCnf;

typedef struct // ���е�����Ϣ
{
	void *m_ptVo;	//vo
	TChnNameOsdCnf *m_ptChnNameOsd; //ͨ����Ϣ
	TChnTimeOsdCnf *m_ptTimeOsd;
	TChnTextOsdCnf *m_ptTextOsd;
	TChnLogOsdCnf *m_ptLogOsd;
} TChnOsdCnf;


typedef struct
{
	td_s32 m_iLeft;
	td_s32 m_iTop;
	td_s32 m_iWidth;
	td_s32 m_iHeight;
} TChnArea;

#define CHN_MAX_VC_AREAS					4
typedef struct	// ��Ƶ�ڵ���������
{
	td_s32 m_iAreaCnt;							//�������
	TChnArea m_tAreas[CHN_MAX_VC_AREAS];	//����(�ߴ簴ʵ������)
} TChnVideoCoverAreaCnf;

typedef struct	// �ƶ��������
{
	td_u8 m_cAreaEnBmp[18][22];				//��18x22С��1��ʾѡ��
} TChnMdAreaCnf;

typedef struct		//ץ����Ϣ
{
	td_u8 m_strFileName[128];	//ͼƬ�ļ���
	td_u8 m_strFileNameRedund[128];	//����ͼƬ�ļ���
	td_s32 m_iBufSize;			//ͼƬ���ݻ����ڴ��С
	td_s32 m_iPicSize;			//ʵ��ͼƬץ�Ĵ�С
	td_u64 m_ulTrigger;          //��������Դ��wangsong, atm, 20120920
	td_s32 m_iRecAttr;          //�ļ����ԣ�wangsong, atm, 20120920
	td_u8 *m_pcPicBuf;			//ͼƬ����
} TChnSnapshotMsg;

typedef struct		// ����ͨ����Ϣ
{
	td_s32 m_iEnable;				//ʹ�ܱ�ʶ
	td_s32 m_iServerType;			//�豸����
	td_u8 m_strServerName[40];		//����������(��ʱ����)
	td_u8 m_strServerIP[40];			//��������ַ��������IP��ַ��Ҳ������������  m_strUrl
	td_u8 m_strServerProxy[40];		//�������ϼ�����m_strProxy
	td_s32 m_iChnType;				//��������������0������ 1������ 2��Ƶ��
	td_s32 m_iChnNo;				//�Է�ͨ����
	td_s32 m_iNetMode;				//����Э��1��TCP��2��UDP��3���ಥ��m_iConntectType
	td_s32 m_iCoonectMode;			//���ӷ�ʽ  0--IP   1----���� 2----����ģʽ
	td_s32 m_iServerPort;			//�������˿�   
	td_u8 m_strUserName[20 + 1];		//�û���
	td_u8 m_strUserPsw[20 + 1];		//����
	td_u8 m_strVdecPsw[20 + 1];		//��Ƶ��������
	//hq:20121210 Ϊ��Ӧ16:9��ƵԴ��4:3�ֱ�������ʾ��0:ƽ������ʾ����1:���ֿ���������ʾ
	td_s32 m_iPreviewMode;
	td_u8	m_strRtspUrl[256];	// ������չRTSP�ĵ�ַ����RTSP ��ַ���ȴ���80�ֽ�ʱ��ʹ�ñ��ֶΣ�����ʹ��ԭ�ֶΡ�
} TIpChannelMsg;

typedef struct
{
	td_s32 m_iTigerType;	//����������ʽ
	void *m_ptAlarmer;		//������ʵ��ָ��
} TIpAlarmerMsg;	//����ͨ������������ʽ

typedef struct		//ע��������Ϣ
{
	td_u8 m_strIp[2][32];			//ע������IP��ַ(��֧������)
	td_s32 m_iPort[2];			//ע�����Ķ˺�
	char m_strUserName[2][16];	//ע�������û���
	char m_strUserPass[2][16];	//ע����������
} TRegCenterMsg;

typedef struct		// �ϳ�ͨ����Ϣ		
{
	td_s32 m_iVoDev;				//��ʾ�豸��
} TVcChannelMsg;

typedef struct		//Ԥ���豸����ͨ��
{
	td_s32 m_iVoDev;	//�豸��
	td_s32 m_iChn;		//ͨ����
	td_s32 m_iChncnt;    //�Ƿ�����Ƶ20120831 add by zhuangzhibing
} TVoDevFocusMsg;

typedef struct		//����ͨ��
{
	int m_iEnable;//add by nsg
	int m_iChns[3]; //20120203mode by nsg 2 to 3
} TVcMixAudioChnMsg;

#if 0
typedef struct // �ƾ�͸��ͨ������
{
	td_s32 m_iDataSize; 	//���ݳ���
	td_u8 m_uDataBuf[0]; //��������(�䳤)
} TPtzData;
#endif

// zty 20120220
typedef struct
{
	td_s32 m_iPtzCode;			//ptz������
	td_s32 m_iAddress;			//ptz��ַ��
	td_s32 m_iPreset;			//Ԥ��λ��
	td_s32 m_iSpeedX;			//ˮƽ�ٶ�
	td_s32 m_iSpeedY;			//��ֱ�ٶ�
} TPtzCtrProtocolData;

typedef struct //�ƾ������������
{
	TComInstance *m_ptCom;		//����ʵ��
	TComAttribute *m_ptAttribute; //��������
	td_s32 m_iDataSize; 			//���ݳ���
	td_u8 *m_ucData;			//��������

	// dxl 20120131 Э��ģʽ
	TPtzCtrProtocolData *m_ptProtocolData;
	
} TPtzCtrParam;

enum
{
	CHN_ALARMER_VL = 0x000001,  //��Ƶ��ʧ
	CHN_ALARMER_AL,				// ��Ƶ��ʧ
	CHN_ALARMER_MD,				// �ƶ����
	CHN_ALARMER_VC,				// ��Ƶ�ڵ�
	CHN_ALARMER_OD,				// �ڵ�����		//zhangyi add 20130411
	CHN_ALARMER_VCA	= 0x100000,// ���ܷ�������(0x10ttrr, tt������,rr������)
} CHN_ALARMER_TYPE;

/*typedef struct
{
	int m_iType;	// ����������(��CHN_ALARMER_TYPE)
	TAlarmer *m_ptAlarm;	//������ʵ��
} TChnAlarmer;*/

//================= ����ͨ�����ݽṹ==============

typedef struct	//������
{
	td_s32 m_iLeft;
	td_s32 m_iTop;
	td_s32 m_iWidth;
	td_s32 m_iHeight;
} TRect;

typedef struct	//������
{
	td_s32 m_iClipStat;
	td_s32 m_iTop;
	td_s32 m_iBottom;
	td_s32 m_iLeft;
	td_s32 m_iRight;
} TRitioRect;


typedef struct	//��Ƶ�ߴ�������Ϣ
{
	td_s32 m_iWidth;
	td_s32 m_iHeight;
} TVideoSize;

typedef struct	// vo����Ϣ
{
	void *m_ptVo;		//vo����
	TRect *m_ptRect;	//�����С(��D1Ϊ��׼)
} TVoBindMsg;

typedef struct //VO�豸�Ķ���Ϣ 
{ 
    td_s32 m_iLuma;                     /* ����:   0 ~ 100 */ 
    td_s32 m_iContrast;                /* �Աȶ� :  0 ~ 100 */ 
    td_s32 m_iHue;                      /*�Ҷ�      :  0 ~ 100 */ 
    td_s32 m_iSatuature;               /* ���Ͷ� :  0 ~ 100 */ 
	td_s32 m_iGain;                    /*  ����      :  0 ~64  */
} TVoCSCMsg;


typedef enum
{
	VO_DEV_VGA 		= 0x00,
	VO_DEV_BNC1 	= 0x01,
	VO_DEV_BNC2 	= 0x02,
	VO_DEV_HDMI1 	= 0x00,
	VO_DEV_HDMI2 	= 0x01,
	VO_DEV_WBC      = 0x02,
	VO_DEV_VC		= 0x10,		//�ϳ�ͨ��
	VO_DEV_VIR_PIP	= 0x15,
} VO_DEV_ID;

typedef enum
{
	VO_SIZE_NTSC = 0,	// 720x480
	VO_SIZE_PAL,		// 720x576
	VO_SIZE_VGA,		// 800x600
	VO_SIZE_1024x768,
	VO_SIZE_1280x1024,
	VO_SIZE_1440x900,
	
	VO_SIZE_720P_50 = 0x100,
	VO_SIZE_720P_60,
	VO_SIZE_720P_25,
	VO_SIZE_720P_30,
	VO_SIZE_1080P_50 = 0x110,
	VO_SIZE_1080P_60,
	VO_SIZE_1080P_25,
	VO_SIZE_1080P_30,
	VO_SIZE_1080I_50 = 0x120,
	VO_SIZE_1080I_60,
	VO_SIZE_1080I_25,
	VO_SIZE_1080I_30,
	VO_SIZE_1280x800_60,	//add by zxs 2012.8.15
	VO_SIZE_1366x768_60,	//add by lxy 2012.11.23	
} VO_DEV_SIZE;

typedef enum
{
	SENSOR_FLIP = 1,
	SENSOR_MIRROR ,
	SENSOR_MAX
}TSensorSpin;

// ================== ԭconfig.h���������================
//Cheng 11/12
typedef struct
{
	char		m_PPPoeUserName[32];	//PPPoe Username
	char 		m_PPPoePassword[32];	//PPPoe password
	td_u8	m_u8AutoDial;			//Enable dial
	td_u8      	m_u8DialTimes;               //Dial times
}strPPPoePara;

//Sherry add for Domain Name Parse

//���ƹ�������
typedef enum
{
	CSTM_RAILWAY = 0,				//��·��Ƶ���ϵͳ
}TCustomization;

typedef struct
{
	char    	m_cUserId  [16];		//ʺ	
	char    	m_cNvsName [32];		//	
	char    	m_cPassword[16];		//
	td_u32  	m_u32RegTime;			//ƵԶעʱ
	char		m_cDomainName1[32];		//(ĿǰIPĵַ)
	int		m_iPort1;
	char		m_cDomainName2[32];		//(ݲʹ)
	int		m_iPort2;
}strParsePara;

//Cheng 12/02 add 
typedef struct 
{
	char		m_NtpServerIp[32];	//ntp������IP, �п�����������
	unsigned int		m_NtpServerPort;		//ntp�������˿�
	unsigned int		m_Interval;	//У����
	struct timespec m_Ntptime;
}NtpServer;

//zy-add ddns-080708 
typedef struct
{
	char 	m_cUserName[32];
	char	m_cPassword[32];
	char	m_cNvsName[32];
	char	m_cDomainName[32];
	int	m_iPort;
	int 	m_iDdnsEnable;
	int 	m_iChanged; //Cheng 100907 add for change 
}strDdnsPara;

#if 0
//shihc add 20121027
//*******wifi*********************************/
typedef struct
{
	//int m_iNetlistNo;
	char m_cEssid[32];
	int m_iSetSafeEnable;
	int m_iSafeType;
	int m_iKeyFormat;
	int m_iKeyType;
	int m_iKeySelect;
	//Cheng 100905 move from nDev
	char		m_cWifiEncryption[16]; //replaced with m_iSafeType
	char		m_cWifiPwdType[16]; //replaced with m_iKeyType
	char		m_cWifiPwd[80]; //password
	td_u16	m_u16WifiKeyNum; //seems == m_iKeySelect
	
	//char m_cPassword[GUI_WIFI_PWD_STR_LEN + 1];
	unsigned int m_uiIpAddress;
	unsigned int m_uiSubMask;
	unsigned int m_uiGateWay;
	unsigned int m_uiDNS;
	unsigned int m_uiBackDNS;
    	td_u8   	m_u8Mac[6];

	int m_DHCPEnable;
	int m_DHCPTimes;	
	int m_iOnLine;
}strWifiCnf;
//add end
#endif

typedef struct 
{
	td_u8   	m_u8Adapter;        	//
	char 		m_cHostName[16];		//
	char		m_cDomainName[16];		//	
	
//��һ����������
	td_u32  	m_u32IpAddress;     	//IPַ
	td_u32  	m_u32SubMask;       	//
	td_u32  	m_u32GateWay;       	//صַ
	td_u32  	m_u32DNS;           	//DNSַ
	td_u32       m_u32BackDNS;
	td_u16		m_u16DHCPenable;
								
//�ڶ�����������	
	td_u32  	m_SndIpAddress;     	
	td_u32  	m_SndSubMask;       	
	td_u32  	m_SndGateWay;       	
	td_u32  	m_SndDNS;           	
	td_u32      m_SndBackDNS;
	td_u16		m_SndDHCPenable;	
	
	td_u8   	m_u8Mac[6];         	//
	td_u8       m_u8SecondMac[6];       //�ڶ�������mac
	td_u8		m_u8FactoryID[32];
	td_u8		m_cFactory[32];	
	td_u8		m_u8UPNPenable;
	td_u8		m_u8DHCPTimes;

	td_u32      m_u32bonding;
}NetDevice;

typedef struct 
{
	td_u8       m_product;				//product: 1 channel 4channel 8channel 16channel
	td_u8     	m_u8VideoInput;      	//video input num
	td_u8		m_u8AudioInput;			//audio input num
	td_u8     	m_u8VideoOutport;    	//video output num
	td_u32		m_u32VoDevIntfType;		//zhangyi add 20130104
	td_u8     	m_u8AudioOutport;    	//audio output num
	td_u8		m_InputNorm;			//video input mode
	td_u8		m_OutputNorm;			//video output mode		Add by Leeon Tonie for Tiandy-Dvr, 090106
	//enum SENSOR_TYPE	m_u8SensorType;	//sensor type
	td_s32		m_iProductModel;		//��Ʒ������,������Ʒ�Ļ�������
	td_s32		m_iCustomization;		//���ƹ��ܼ�
	td_u8		m_cAppName[32];			//���ƹ�����������
	td_u8		m_u8DHCPTimes;//DHCP�������� 11/15 from S2
	//td_u8		m_u8AlarmType;

	// dxl 20110309
	td_u8	m_u8BncInput;		//����ģ��ͨ����
	td_u8	m_u8IpcInput;		//����ͨ����
	td_u8	m_u8VcInput;		//����ϳ�ͨ����

	td_s32 m_iVcDevSize;		//����ϳ�ͨ���ֱ���(�Ǳ���ֱ���)

	//zhangweiwei 20120130
	td_s32 m_iNetWorkCardNum;   //������Ŀ 
	//lbl 20121206
	td_s32 m_iPlaybackCost;
}MediaDevice;

//�洢���ӵ��ַ�������Ϣ ������ 091117 ��cmd_execute.h�Ƶ���

#define MAX_WORDOVERLAY_LEN	256

typedef struct
{
	td_s16	m_u16x;			//Sherry modify 20120925 
	td_s16  m_u16y;			//Sherry modify 20120925 
	//td_u16	m_u16xApp;
	//td_u16  m_u16yApp;	
	td_u16	m_u16Size;
	td_u16	m_usEnable;		//Added by Leeon Tonie 090211, for 3511.
	td_u8	m_cWord[MAX_WORDOVERLAY_LEN];//xujiayu 081204
	//td_u8	m_u8Renew;//xujiayu 081226 ��ʾ�����ַ��Ƿ����
	td_u32    m_osdColor;            //cheng 02/08 ��¼��ɫ	
	td_u32    m_iFontSize;            //cheng 02/08 ��¼��ɫ	
}STR_WordOverlay;

//TV���ڽṹ��
typedef struct
{
	int m_iTop;			//�ϱ߾�(��Χ:0~100)
	int m_iBottom;		//�±߾�(��Χ:0~100)
	int m_iLeft;		//��߾�(��Χ:0~100)
	int m_iRight;		//�ұ߾�(��Χ:0~100)
}TDevTV;

#define MAX_MIX_AUDIO_CHN_CNT	2

//add by nsg 20120130
typedef struct
{
	td_s32 m_uiMixAudiocnt;    		//����Դ�ĸ���
	td_s32 m_uiMixAduiochn;  		//�ϳ�ͨ����
	td_s32 m_uiState;               //�ṹ���Ƿ�ʹ�ù�1����ʹ�ù�
	td_s32 m_uiAudiochnlist[MAX_MIX_AUDIO_CHN_CNT]; //����Դͨ����
	td_s32 m_uiAudiochnState;  		//����Դ״̬,��λΪ1�����ĸ�ͨ�����Ǿ���
    
} TMixAudio;
//add end

//add by nsg 120905

#define SNAPTYPE_SINGLE 2
#define SNAPTYPR_MULTI 3

typedef struct
{
	td_s32	m_iType;	//ץ��ģʽ0����ʹ�� 1��ʹ�ܣ���ʱ�� 2:����������ץ�ģ�3�������������ץ��ע�ͣ�Ĭ��Ϊ2
	td_s32	m_iQvalue;  //ץ��ͼƬ����
	td_s32	m_iTimeval;	//ץ��ʱ����
	td_s32	m_iMethod;	//������ʽ����λ��ʾ0x1:����ftp�ϴ���0x2:����Email֪ͨ 0x3:ͬʱ���� 0x0 ����������//20130314 SUN Wei add for 7.6
	td_s32	m_iSize;	//ץ��ͼƬ��С��0x7fff�������Զ��������Ӧ�ֱ��ʴ�С
	td_s32  m_iRetryTimes; //ʧ���ط����� 20130311 SUN Wei add for 7.6

}TSnapShot;			//ͼƬץ�Ĳ�������
//end add

#define MAX_AUDIO_LIST 16
#define MAX_VIDEOLIST_CNT 32
#define MAX_AUDIOCODERLIST_CNT 16 // huaqiang add 20130218
typedef struct
{
	td_u8			m_u8MediaType;                     	//32,1 	 3--Ƶ 2--Ƶ  1--Ƶ
	td_u8			m_u8FrameRate;                     	//33,1   ֡
	td_u8			m_u8VideoQuality;                  	//34,1	 Ƶ   
	OSD_CHANNAME_T 	stu_OSDChannel;
	OSD_CHANNAME_T 	stu_OSDTime;		
	OSD_CHANNAME_T	stu_OsdLogo;
	structVideoParam    m_VideoParam[MAX_TIME_SEGMENT];                       //video setting
	td_u32			m_MDArea[18];            	//motion detect area 22*18 blocks ,one block size is 16*16(D1)
	td_u8			m_u8Threshold;                     	//244,1	 Ƶƶж
	td_u8			m_u8ReduceNoiseEnable;			//1,?
	td_u8			m_u8IFrameRate;						//251,1	 I֡֡
	td_u32			m_u32EncodeType;						//251,0	ʱģʽCBR(0)/VBR (1)ѡ
	td_u32			m_u32PreferMode;						//251,0	?ģʽ(0)/֡ģʽ(1)
	td_u32			m_AudioType;
	Rect_t			m_VideoCov[MAX_VIDEO_COVER_NUM];							//253,8	 modified by gxl 20081022	,�ĸ��ڵ�����	        	
	td_u32			m_u8VideoSize;						//261,1    
	td_u32			m_u32BitRate;						//262,4
	td_u32			m_u32VideoWidth;
	td_u32			m_u32VideoHeight;	
	td_s32			m_s32AudioSample;		
	td_u8           		m_u8VideoMode;                     	//Ƶʽ豣E2,ϵͳ??Զʶ
	structVideoParam	m_NowVideoParam;
	td_u8			m_blManualVideoParam;				//�Ƿ��ֶ����ù���Ƶ����
	td_u8			m_blVideoParamTimerEnable;			//��Ƶ������ʱ���ʹ��
	td_s32 			m_MaxVencSize;				//������ֱ���
	td_s32 			m_MaxFrmRate;				//���֡��
	td_u8			m_PreviewRec;						//�Ƿ�ΪVO����
	td_u8			m_VideoEncrypt[ENCRYPT_PWD_LENGTH+1];	//��Ƶ��������
	td_u8			m_u8InVolume;

	td_u8			m_u8Norm;		//��ʽ
	td_s32			m_u32VideoModeCheck;//�Զ����
	// dxl 20110308
	td_u32			m_u32ChnType;		//ͨ������
	td_u32			m_u32OriginalChnType;	//��¼ԭʼ��ͨ������
	td_s32			m_s32BncNo;		//BNC�ţ�����ģ��ͨ��ר��
	td_s32			m_s32BncNoAlias;	//BNC alias����������ui����ʾͨ������
	TVcChannelMsg	m_tVcMsg;			// ���⻭��ϳ�ͨ��ר��
	TIpChannelMsg	m_tIpMsg;			// ����ͨ��ר��
	// dxl 20111013	����
	td_s32			m_iMixAudioChnCnt;	//��������
	td_s32			m_iMixAudioChnList[MAX_MIX_AUDIO_CHN_CNT];	//����ͨ���б�
	//TMixAudio       m_tMixAudio;//add by gyn 20120130 ��������
	
	TSnapShot m_stSnapShotPara;  //add by nsg 120905�ڴ����У�����һ��ͼƬץ�Ĳ�������
	//wsl 20120906 �ñ�
	TRitioRect		m_iRitioClipRect;
	td_s32			m_iProfile;

	int m_iChnAudioSizeListCnt;
	int m_iChnAudioSizeList[MAX_AUDIO_LIST];
	char m_strPNPMac[40];

	td_s32			m_iVideoListCnt;
	td_s32			m_iVideoList[MAX_VIDEOLIST_CNT];

	// huaqiang add 20130218
	td_s32			m_s32AudioCoderListCnt;
	td_s32			m_s32AudioCoderList[MAX_AUDIOCODERLIST_CNT];
	// add end
	td_s32			m_audiochn;	//ͨ����Ӧ����Ƶͨ��wsl add
	td_s32			m_iVideoModleEnable;
	td_s32			m_iVideoTurnEnable;//��Ƶ��ת0x0:��ʹ��;0x1:���·�תʹ��;0x2:����ʹ��;0x3:�������Ҷ�ʹ��
}strChannelParam;
typedef struct
{
	td_u8		m_u8IFrameRate;			//ŸͨI֡֡
	td_u8   		m_u8FrameRate;          //ʸͨ֡
	td_u8   		m_u8VideoQuality;       //ʸͨƵ
	td_u8		m_u8VideoSize;			//ͨƵС
	td_u32		m_u32VideoWidth;
	td_u32		m_u32VideoHeight;	
	td_u8		m_u8StreamType;			//ͨͣƵ?Ƶ
	td_u8   		m_u8OneStream;
	td_u32		m_u32BitRate;			//ͨ
	td_u32		m_u32EncodeType;						//251,0	ñģʽCBR(0)/VBR (1)ѡ
	td_u32		m_u32PreferMode;						//251,0	?ģʽ(0)/֡ģʽ(1)
	td_u8		m_VideoEncrypt[ENCRYPT_PWD_LENGTH+1];	//��Ƶ��������    	
	td_s32		m_s32Profile;
	td_s32		m_iVideoListCnt;
	td_s32		m_iVideoList[MAX_VIDEOLIST_CNT];
}strAppChannel;

//dongchengen add
typedef struct
{
	td_u32			m_u32VideoSize;		//�ֱ���
	td_u8			m_u8FrameRate;		//֡��
	td_u8			m_u8IFrameRate;		//I֡֡��
	td_u8			m_u8VideoQuality;	//��������
	td_u32			m_u32EncodeType;	//λ������
	td_u32			m_u32BitRate;		//����
	td_u8			m_u8MediaType;		//��������
}TChannelParamEvent;
//add end 

//dlq add for smart template at 20130907
typedef struct
{
	td_u32			m_u32FrameRate;		//֡��
	td_u32			m_u32VideoQuality;	//��������
	td_u32			m_u32VideoSize;		//�ֱ���
	td_u32			m_u32BitRate;		//����
}TChannelParamSmart;
//add end 

//��·��Ƶ���ϵͳ����
typedef struct
{
	td_u8		m_cFtpAddress[64];						//ftp��ַ
	td_s32		m_iFtpPort;								//ftp�˿ں�
	td_u8		m_cFtpUser[32];							//ftp�û���
	td_u8		m_cFtpPassword[32];						//ftp����
	td_u8		m_cSoapUrl[64];							//soap���
	td_s32		m_iSoapPort;							//soap�˿�
	td_s32		m_iDistance;							//�������ʶ��װ�õľ���
	td_u8		m_cSoapActionUrl[64];
	td_u8		m_cSoapRange[64];
}TRailWay;

typedef struct
{
	td_u32	m_u8Mode;//��¼��ʽ
	td_u32	m_u8DevList;//��¼�豸�б�
	td_u32	m_u32ChannelList[MAX_RECORDER_NUM];//��¼ͨ��
}TCdrwPolicy;
typedef enum
{
	DISK_AUTO = 0,
	STD_DVD_DISK,
	BLUE_DISK,
	DISK_MUTE
}tag_DiskType;//��Ƭ����
//add by gyn
typedef struct
{
	td_u32 m_uCloseDisk;//��¼����
	td_u32 m_uEjectDisk;//�Ƿ���
	td_u32 m_uBurnHour;//��¼ʱ����0��������
	td_u32 m_uBurnSpeed;//��¼�ٶ�
	td_u32 m_uDiskType;//��������//add by gyn 20130802
}TCdrwAdvBurnPara;//��¼�ĸ߼�����
//add end

// dxl 20110307 ��user���Ƶ��˴�
#define LENGTH_USER_NAME		16
#define LENGTH_PASSWORD		16
#define MAX_CLIENT				32
#define MAX_USER_NUM			32//liyang modify
#define USER_RIGHT_MAX_NUM  32
#define USER_CHANNEL_MAX_NUM 32
#define USER_KEY_LEN	8
#define USER_ENCRYPT_LEN	128
#define PASSWORD_ENCRYPT_LEN	128
//ÿһ̨������Ƶ������������16���û�
typedef struct 											
{
	td_u16 		m_u16UserNum;									//0,4		��������Ƶ���������û�����
	td_u16		m_u16MaxUser;									//��������Ƶ������������������û���
	char			m_cUserName[MAX_USER_NUM][LENGTH_USER_NAME + 1];	//4,128		�û���
	char        	m_cPassWord[MAX_USER_NUM][LENGTH_PASSWORD + 1];		//132,128	����
	td_u8		m_u8Level[MAX_USER_NUM];						//260,8		Ȩ��
	td_u8		m_u8ConUserNum;									//���ڼ�¼�Ѿ���½���û���
	td_u32		m_ClientIP[MAX_CLIENT];							//��¼�Ѿ���½�Ŀͻ��˵�IP��ַ
	void*		m_ClientPoint[MAX_CLIENT];							//��¼�Ѿ���½�Ŀͻ��˵�IP��ַ
	td_u8		m_u8VerifyNum[MAX_CLIENT];						//��¼ÿһ�ͻ��˵�У�����,Sherry add 20050804
	td_u8		m_u8NetMode[MAX_CLIENT];						//��¼ÿһ�ͻ��˵�����ģʽ
	char			m_cLogonUser[MAX_CLIENT][LENGTH_USER_NAME];	//record the logon user's name
	td_u32		m_u32Authority[MAX_USER_NUM][USER_RIGHT_MAX_NUM];//20120920 ����add �û�Ȩ��

	td_u8		m_u8Key[MAX_CLIENT][USER_KEY_LEN];//��¼��ÿ���û���¼����Կ��ÿ���ͻ���һ��
} NetUser;
typedef int (*LogonDecodeCallBack)(const char* _cSrcStr1, int _iStrLen1, const char * _cSrcStr2, int _iStrLen2, OUT char *_cOutBuf, int _iOutLen);
// dxl 20110309 ����ͨ�������豸��Ŀ
typedef struct
{
	td_s8 m_cMac[32];			
	td_s8 m_cMask[40];			
	td_s8 m_cGateWay[40];		
	td_s8 m_cDNS[40];
	
	td_s32 m_iServerType;		//��������
	td_u8 m_strIp[40];			//�豸IP
	td_s32 m_iPort;				//�豸����˿ں�
	td_s32 m_iChnNum;			//ͨ������
	td_u8 m_strFactoryID[40];	//����ID
	td_u8 m_strName[32];		//�豸����
	td_u8 m_strProxyIp[40];		//���������
	td_u8 m_strDevType[32];		//����������(DVR/NVR/UNK...)
} TIpcDevItem;

#define MAN_PNP			0
#define AUTO_PNP		2
#define MAN_AUTO_PNP	1
typedef struct
{
	int m_iPlugStart;
}TPlugConf;

//#define MAX_WORDOVERLAY_NUM	1	//������ʱֻ֧��һ�飬modify by liuqi 2014-7-18
// for decoder
typedef struct
{
    td_s32		m_iEnable;           //�Ƿ����Logo
    td_s32		m_iPosX;            //����Logo������
    td_s32		m_iPosY;            //����Logo������
    td_s32		m_iAlpha;           //͸����(0~100)��100Ϊ��ȫ��͸��
    td_s32		m_iTransparentColor;//����ɫ��RGB��ʽ(0x00000000~0x00ffffff)
}TLogoParam;

//zhangyi add 20140314
#define MAX_RAIDARRAY_NUM	4

#if JMB39X == ON
#define MAX_LOCAL_DISK_NUM	5
#else
#define MAX_LOCAL_DISK_NUM	4
#endif

typedef struct
{
	td_s32	m_iNo;
	td_s32	m_iEnableRaidArray;
	td_s8 	m_cRaidName[64];
	td_s32 	m_iRaidType;
	td_s32	m_iDisklist[MAX_LOCAL_DISK_NUM];
	td_s32	m_iDiskTotal;
}TRaidArrayCfg;

typedef struct
{
	td_s32 m_iRaidId;
	td_s32 m_iRaidAllSize;
	td_s32 m_iRiadUseAbleSize;
	td_s32 m_iDiskList;
	td_s32 m_iDiskList1;
	td_s32 m_iDiskBackUpId;  	//0��ʾû���ȱ���
	td_s32 m_iRaidStat;   		//����״̬ TGuiRaidStatus
	td_s32 m_iRaidType;
	td_s32 m_iRaidTask;  		//��������TGuiRaidTaskType
	td_s32 m_iRaidTaskPara[4]; 	//Ԥ�����ٷֱȣ�ʣ��ʱ���
	td_s8 m_strRaidName[31 + 1];
}TRaidArrayStat;

typedef struct
{
	td_s32	m_iDiskId;
	td_s8 	m_cRaidName[64];
	td_s32	m_iWorkMode;
}TRaidHdCfg;

typedef struct
{
	td_s32 m_iDiskId;
	td_s32 m_iDiskType;
	td_s32 m_iDiskStat;
	td_s32 m_iDiskSize; 						//��λΪM
	td_s8 m_strRaidName[31 + 1];
	td_s8 m_strDiskModel[31 + 1];
}TSataDiskCfg;


#define MAX_VIRDISK_NUM	8
typedef struct
{
	td_s8 	m_cVdName[64];
	td_s32	m_iVdSize;
	td_s32	m_iInitType;
	td_s8	m_cRaidName[64];
}TRaidVdCfg;
typedef struct
{
	td_s32 	m_iRaidVdSize;
	td_s32  m_iVdStat;       		//�������״̬TGuiVdStatType
	td_s32 	m_iRaidtype;    		//�������������raid����
	td_s32 	m_iVdTask;      		//���������������TGuiVdTaskType
	td_s32 	m_iVdTaskPara[4];  		//����Ԥ�������������ٷֱȣ�ʣ��ʱ���
	td_s8 	m_strVdName[31 + 1];
	td_s8 	m_strRaidName[31 + 1];
}TRaidVdStat;

// ���������
typedef struct		//ƽ̨�Խӽӿ�IP���˿�
{
	char m_cControlIp[40];	
	int m_iPort;	
	int m_iEnable;
}TPlatformCtrlInfo;

typedef struct		//ƽ̨�Խӽӿ�IP���˿�
{
	char m_cDevID[21];	
	char m_cDevName[33];		
}TPlatformDevInfo;

typedef struct
{
	char Pro_ID[4];
	char Data_ID[2];
	char Rsp_Ctl[2];
	char Cmd_Len[2];
	char FrameHead[2];
	char Chn;
	char PicNum;
	char LinkMode;
	char IpAddr[4];
	char  DomainName[32];
	char  ID[32];
	char ProxyIP[4];
	char DevChn[2];
	char Port[5];
	char  StreamType;
	char  NetType;
	char  PtzProtocol;
	char  PtzAddr[3];
	char   UserName[16];
	char   Password[16];
	char   VideoEncryptPass[16];
	char  CheckSum;
	char  UserID;
	char  FrameTail[2];
}stVirtualMatrixCtlMsg;

typedef struct
{
	int m_iVideoPwdEnable;
	char m_cVideoPwd[ENCRYPT_PWD_LENGTH + 1];
}TPoliticsVideoPwdMsg;

#define STREAM_AUDIO_START_CHN 7

typedef enum
{
	BESTIR_STAT_RESERVER = 0,
	BESTIR_STAT_VALID,
	BESTIR_STAT_CANCEL,
	BESTIR_STAT_LIMIT
}E_BESTIR_STAT;

#endif


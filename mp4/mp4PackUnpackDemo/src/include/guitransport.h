/****************************************************************************
�ļ���:		guitransport.h
��	��:		ͼ�ν��������س������ݽ����ӿ�

�޸���־:
�޸���		�޸�����		�޸�˵��
==========  ==============  ===========================================
������		2008-09-16		������ʵ�ֻ�������
****************************************************************************/

#ifndef _GUI_TRANSPORT_H_
#define _GUI_TRANSPORT_H_

#define GUI_TX_NO_WAIT			0					//���ݴ��䲻�ȴ�
#define GUI_TX_WAIT_DONE		0x7FFFF000		//���ݴ���ȴ����
#define GUI_TX_WAIT_DEF			10					//Ĭ�ϳ�ʱʱ��

#define GUI_TX_SERVER			0	//������������(�������س���)
#define GUI_TX_CLIENT			1	//�ͻ���������(����ͼ�ν���)

#define GUI_TX_LOCAL_IP			0	//����IP
#define GUI_TX_MAIN_PORT		1	//������ͨ���˿�
#define GUI_TX_MSG_PORT			2	//��Ϣ����ͨ���˿�
#define GUI_TX_DATA_PORT		3	//͸�����ݡ��������ݴ���ͨ��

#define GUI_VIDEO_IN_CHN_CNT	32	//��Ƶ����ͨ����

#define GUI_VIDEO_FREE			0	//ͨ��δ¼��
#define GUI_VIDEO_HUM			1	//ͨ�����ڽ����ֶ�¼��
#define GUI_VIDEO_TM			2	//ͨ�����ڽ��ж�ʱ¼��
#define GUI_VIDEO_ALARM			3	//ͨ�����ڽ��б���¼��
#define GUI_VIDEO_DEF			4	//ͨ�����ڽ����Զ���¼��
#define GUI_VIDEO_NONE_HUM		11	//ͨ�����ڽ����ֶ�¼��(����Ƶ)
#define GUI_VIDEO_NONE_TM		12	//ͨ�����ڽ��ж�ʱ¼��(����Ƶ)
#define GUI_VIDEO_NONE_ALARM	13	//ͨ�����ڽ��б���¼��(����Ƶ)
#define GUI_VIDEO_NONE_DEF		14	//ͨ�����ڽ����Զ���¼��(����Ƶ)
#define GUI_VIDEO_NONE			-1	//ͨ������Ƶ����

typedef struct					//¼��״̬
{
	int m_iVideoSta[GUI_VIDEO_IN_CHN_CNT];	//��ͨ����Ӧ��¼��״̬
} TGuiVideoStatus;

extern TGuiVideoStatus *g_ptDvrVideoStaForGui; //¼��״̬������

#define GUI_ALARM_NONE			0	//�ޱ���
#define GUI_ALARM_PORT			1	//�˿ڱ���
#define GUI_ALARM_MD			2	//�ƶ���ⱨ��
#define GUI_ALARM_VLST			3	//��Ƶ��ʧ����
#define GUI_ALARM_VCVR			4	//��Ƶ�ڵ�����
//add 
#define GUI_ALARM_TW            5   //���߱���
#define GUI_ALARM_PM            6   //�ܽ籨��
#define GUI_ALARM_FACE          7   //������� zhangweiwei add for VCA 0527
#define GUI_ALARM_DIAGNOSE      8   //��Ƶ���
#define	GUI_ALARM_OSCER			9	//��Ʒ����add by nsg 20120801
#define GUI_ALARM_VCA           10   //���ܷ��� zhangweiwei 06/21/2011
#define GUI_ALARM_ALST			11	//��Ƶ��ʧ����

typedef struct					//����״̬
{
	int m_iAlarmSta[GUI_VIDEO_IN_CHN_CNT];	//��ͨ����Ӧ�ı���״̬
	int m_iAlarmSound;			//����������ʾ(����ģ�����ò����)
	int m_iAlarmLed;			//ǰ��屨��״̬��
} TGuiAlarmStatus;

extern TGuiAlarmStatus *g_ptDvrAlarmStaForGui; //����״̬������

#define GUI_PRIVATE_DATA_SIZE		512
extern void *g_pGuiPrivateData;				 //U˽������

#define GUI_SYS_STA_STARTUP			0		//ϵͳ��������
#define GUI_SYS_STA_RUNNING			1		//ϵͳ��������
#define GUI_SYS_STA_REBOOT			2		//ϵͳ��������
#define GUI_SYS_STA_SHUTDOWN		3		//ϵͳ���ڹػ�
#define GUI_SYS_STA_SATA_REBOOT_APP 4		//��Ӳ���������
#define GUI_SYS_STA_MEMSATA_REBOOT_APP 5	//ֱ���������

#define GUI_SYS_ERR_NONE			0		//�޴���
#define GUI_SYS_ERR_DISK_FULL		1		//������
#define GUI_SYS_ERR_DISK_NULL		2		//�޿��ô���
#define GUI_SYS_ERR_DISK_RW			3		//��д����ʧ��
#define GUI_SYS_ERR_ACCESS			4		//�Ƿ�����
#define GUI_SYS_ERR_IP_CONF			5		//IP��ַ��ͻ
#define GUI_SYS_ERR_NET_INTE		6		//�����ж�
#define GUI_SYS_ERR_VIDEOIN_MODE	7		//������ʽ����

#define GUI_SYS_STA_PCNT			4		//ϵͳ״̬��������
#define GUI_SYS_ERR_PCNT			4		

#define GUI_SHR_MEM_EXT				1
//m_cShmRsv�ֶ��ڴ��������ʼ��ַ
#define GUI_GPS_OFFSET            	0  //����GPS��ʾ��ƫ��GPSռ��36�ֽ�
#define GUI_ALM_SPIC_OFFSET			48		//��������������(4 * 3�ֽ�)
#define GUI_CBL_SHM_START			128    //����CBL��ƫ���ֽ� ռ��44�ֽ�
#define GUI_TEMP_SHM_START          256    //������ʪ�ȵ�ƫ��(32�ֽ�) 
#define GUI_PIC_STAT_START			288     //����UIͬ���������ö໭����������λ��У��(Ԥ��6�ֽ�)
#define GUI_DEV_STAT_START			294		//���ڳ���wifi,GPS�ź�ǿ�ȵ�Դ��ѹ�¶ȼ����Ǹ���(Ԥ��12�ֽ�)
#define GUI_SHR_FANTEMP_STAT_STAET  306  //���ڷ��ȿ����¶� ��Ԥ��1�ֽڣ�
#define GUI_SHR_STAT_UPDATE_STAET   307  //����֪ͨ���״̬��Ϣ�и��� ��Ԥ��4�ֽڣ� ��λʹ��
#define GUI_ALAR_STA_START			512		//���ڱ����������״̬(Ԥ��128�ֽ�)
#define GUI_AUDIO_STA_START			640		//������Ƶ����״̬(Ԥ��128�ֽ�)
#define GUI_SHR_DECODER_START       770     //���ںͽ�����ͨѶ(Ԥ��56�ֽ�)
#define GUI_VIDEO_HEADER_START		826		//����Ƭͷ�Ƿ����(Ԥ��2�ֽ�)
#define GUI_FIND_UPNP_DEV_OFFSET	828		// ���ڼ��弴�û�ȡ�����豸��ʶ (Ԥ��2���ֽ�)      
#define GUI_PREVIEW_WIN_MSG_START		830		//Ԥ��������������ǰ���ڶ�ӦԤ����ͨ���� (130  ���ֽ�)	
#define GUI_PREVIEW_SLAVER_WIN_MSG_START	960	 //����Ԥ������״̬��Ϣ(Ԥ��130���ֽ�)
#define GUI_POE_MSG_START						1090   //ÿ��POEͨ����Ϣ(Ԥ��96���ֽ�)
#define GUI_DIGITAL_CHN_START					1186	//ÿ��ͨ���Ƿ����ӹ�(Ԥ��8���ֽ�)
#define GUI_PICSIZE_START						1194	//ÿ��ͨ���ķֱ���(Ԥ��256���ֽ�)
#define GUI_H323_STAT_START			1450 //h323����״̬����������״̬(Ԥ��1���ֽ�)ȡֵʹ��
#define GUI_TXSLEEP_START						1451      //recv��send�Ƿ�sleep��־(Ԥ��4���ֽ�)

#if 1
#define GUI_SHR_MEM_RSV				(4 * 1024)
#else
#define GUI_SHR_MEM_RSV				0
#endif

typedef struct						//GUI��ϵͳ״̬
{
	int m_iGuiPid;					//UI���̺�
	int m_iDvrPid;					//DVR��������̺�
	int m_iGuiLastActiveTm;		//UI����Ծʱ�䣬�൱��UI��������UI����
	int m_iSysUpdateTm;			//���������״̬��ʱ�䣬������������
	int m_iSysSta;					//ϵͳ״̬��������������
	int m_iParams[GUI_SYS_STA_PCNT];	//״̬��������������m_iSysSta���� 
	//m_iParams[2] ֵΪ0xFF-��ʾ�ȴ���0x1XX ��ʾ��HDMI0
	int m_iSysErr;					//ϵͳ�����ʶ,��������ά��
	int m_iSysErrTm;				//ϵͳ������ʱ��(time()ֵ)����������ά��
	int m_iSysErrMsg[GUI_SYS_ERR_PCNT]; //ϵͳ������չ��Ϣ����ʱ����
									//2011-8-10 ���һ������������ΪԤ��������
	int m_iDvrErrNo;				//DVR������
	int m_iGuideFlg;				//���������б�ʶ,��UI��ʶ
	int m_iGuideEnFlg;				//�����򵼿����б�ʶ,��dvr��ʶ
	char m_cShmRsv[GUI_SHR_MEM_RSV];	 //Ԥ�������ڴ棬��������
} TGuiSysStatus;

extern TGuiSysStatus *g_ptGuiSysStatus;		//UI������ϵͳ״̬

typedef struct
{
	int m_iEast; //����X10000  (-180.0000~180.0000)
	int m_iNorth; //γ��X10000  (-180.0000~180.0000)
	int m_iSpeed; //�ٶ�X100(0.01km/h)
	int m_iHeight;//����X100 (0.01m)
	char m_cEnable;
	char m_cEastWest; //����(E, W )
	char m_cSouthNorth; //�ϱ�(S,N)
}TGuiGpsShrMsg;

#define g_ptGuiGpsShrMsg ((TGuiGpsShrMsg *)(g_ptGuiSysStatus->m_cShmRsv + GUI_GPS_OFFSET))


typedef struct
{
	// �˿ڵ���ʵ״̬
	int m_iAlarmOutValue;		//��������˿�״̬1-32
	int m_iAlarmOutValue1;		//Ԥ��
	int m_iAlarmInValue;			//��������˿�״̬1-32
	int m_iAlarmInValue2;		//Ԥ��

	// �˿��Ƿ����ڱ���
	int m_iAlarmOut;				//�˿��������1-32
	int m_iAlarmOut1;
	int m_iAlarmIn;				//�˿����뱨��1-32
	int m_iAlarmIn1;

	// ��Ƶ��ʧ����
	int m_iVideoLost;				//��Ƶ��ʧ����1-32
	int m_iVideoLost1;			//Ԥ��

	// ��Ƶ�ƶ�����
	int m_iVideoMd;				//�ƶ���ⱨ��1-32
	int m_iVideoMd1;

	// ��Ƶ�ڵ�
	int m_iVideoCover;
	int m_iVideoCover1;

	//��Ƶ��ʧ����
	int m_iAudioLost;			//��Ƶ��ʧ����1-32
	int m_iAudioLost1;			
} TGuiAlarmInOutStatus;

#define g_ptGuiAlarmInOutStatus	((TGuiAlarmInOutStatus *)(g_ptGuiSysStatus->m_cShmRsv + GUI_ALAR_STA_START))

typedef struct
{
	int m_iInputBits;			//��Ƶ����״̬,bit0-bit32��ʽ��Ƶ0-31ͨ��,1��ʽ����Ƶ,0��ʽ����Ƶ
	int m_iInputBitsEx;			//������չ64·ʹ��
	unsigned char m_ucVolValue[64];	//����ֵ(����)
} TGuiAudioInputStatus;

#define g_ptGuiAudioInputStatus ((TGuiAudioInputStatus *)(g_ptGuiSysStatus->m_cShmRsv + GUI_AUDIO_STA_START))

enum
{
	GUI_NO_SHOW = 0,
	GUI_SHOW_TEMP_MSG,
	GUI_SHOW_HEARTRATE = 2,			//����
	GUI_SHOW_BLOODOXYGEN,		//Ѫ��
	GUI_SHOW_BLOODPRESSURE,		//Ѫѹ
};//��������


typedef struct   //��ʪ����Ϣ
{
	int m_iDspEnable;  //�Ƿ���ʾ�ı�־0:����1:��ʾ��ʪ��2:��ʾ���ʼ��Ϸ�ö��
	float m_fTemp;       //�¶ȣ�m_iDspEnableΪ2��3��4ʱΪ��Ӧ��ֵ
	float m_fHumidity;  //ʪ�ȣ�m_iDspEnableΪ2��3��4ʱ��ʹ��
}TGuiTempMsg;
#define g_ptGuiTemperatureMsg ((TGuiTempMsg *)(g_ptGuiSysStatus->m_cShmRsv + GUI_TEMP_SHM_START))

typedef struct	//������Ϣ
{
	int m_iSta;		//״̬
	int m_iUsed;		// ռ�ñ�ʶ(0��ʽδռ�ã�������ʽ���̺ţ�����ʹ��)
	int m_iUsedSize;	//�ѿ�¼��С(��λK)
	int m_iTotalSize;	//�����ܴ�С(��λK)
} TGuiCdSta;

#define GUI_CBL_MAX_CD		2
typedef struct	// ʵʱ��¼״̬��Ϣ
{
	int m_iStat;	// ��¼״̬
	TGuiCdSta m_tSCdSta[GUI_CBL_MAX_CD];
} TGuiCblSta;
#define g_ptGuiCblStat ((TGuiCblSta *)(g_ptGuiSysStatus->m_cShmRsv + GUI_CBL_SHM_START))

typedef struct	// ʵʱ��¼״̬��Ϣ
{
	TGuiCblSta m_tGuiCblSta;//old
	int m_iCdLeftTime[GUI_CBL_MAX_CD]; //��¼״̬�±�ʾ����ʣ��ʱ�䣬
								   //�ڴ��״̬�±�ʾ���̵���ʱ��
} TGuiCblStaEx;

#define g_ptGuiCblStatEx ((TGuiCblStaEx *)(g_ptGuiSysStatus->m_cShmRsv + GUI_CBL_SHM_START))

typedef struct			//����������������Ϣ��
{
	char m_iVoDev[4];	//VO�豸��
	char m_iChn[4];		//ͨ����
	char m_iAlarm[4];	//��������
} TGuiAlarmLinkSinglePicMsg;
#define g_ptGuiAlarmLinkSinglePicMsg ((TGuiAlarmLinkSinglePicMsg *)(g_ptGuiSysStatus->m_cShmRsv + GUI_ALM_SPIC_OFFSET))


typedef struct
{
	char m_cDevNo;  //������ʾ�豸�� 
	char m_cCurWinId; //��ǰѡ�д��ڣ������������������ ���Ϊ31��(-1)-����ʾ���
	char m_cPvMode[2]; //����ģʽ[0]-VGA  [1]-HDMI  m_cPvMode[0]-������������iE���û���ģʽ����λ��UI�ж������λ���ͻ�ȡ����ģʽЭ�顣
}TGuiPicStatShrMsg;  //UI ͬ���ͻ������õĶ໭�漰��ǰ������λ��
#define g_ptGuiPicStatShrMsg ((TGuiPicStatShrMsg *)(g_ptGuiSysStatus->m_cShmRsv + GUI_PIC_STAT_START))


//������
#if 1 //V3.0�汾��ǰ�ϰ汾ʹ��
typedef struct
{
	char m_cDecChnCnt[2];  		//������������
	char m_cDecCurChn;    		//��������ǰ����(Ԥ��)
	char m_cDecAlarmer[16]; 		//��������������λ��ʾ bit0 ��Ƶ��ʧ bit1�˿� bit2��Ƶ�ƶ� (�ߵ�λ����,��4λΪ����豸1,��4λ����豸2)
	char m_cDecSwitchStat[16];  	//�������л�״̬(�ߵ�λ����,��4λΪ����豸1,��4λ����豸2)
	char m_cDecCtrlStat[16];    	//����������״̬(�ߵ�λ����,��4λΪ����豸1,��4λ����豸2)
	char m_cLogoDspStat;         //Logo��ʾ 0-������ 1-���� 2-����
	char m_cDecAttr;            //��λbit0-�������Ըı�
	unsigned char m_cOtherAttr[2];          //��ʾ�ֱ��ʣ�ֵ��guiparameter.h (0~160����ɢֵ)
}TGuiDecShrMsg;
#define g_ptGuiDecoderShrMsg ((TGuiDecShrMsg *)(g_ptGuiSysStatus->m_cShmRsv + GUI_SHR_DECODER_START))
#endif

//��Ƕ�����Ƿ����Ƭͷ����
typedef struct
{
	char m_cIsHeaderDsp;
}TGuiVideoHeaderShrMsg;
#define g_ptGuiVideoHeaderShrMsg ((TGuiVideoHeaderShrMsg *)(g_ptGuiSysStatus->m_cShmRsv + GUI_VIDEO_HEADER_START))

typedef struct
{
	char m_cUpnpNewDev; //1--�����豸 ,0 �����豸
	char m_cUpnpAddType; //0 --�����ü��弴�ã�1--�Զ���ʽ��2--��ʾ��ʽ
}TGuiFindUpnpNewDevShrMsg;
#define g_ptGuiFindUpnpNewDevShrMsg ((TGuiFindUpnpNewDevShrMsg *)(g_ptGuiSysStatus->m_cShmRsv + GUI_FIND_UPNP_DEV_OFFSET))

typedef struct
{
	char m_cWifiSignalState;//Wifi �ź�ǿ�� 
	char m_cSatelliteCnt;   //���Ǹ���
	char m_cGpsSignalState; //GPS�ź�ǿ��	
	char m_c3GSignalState;	// 3G�ź�ǿ��,��4λ��������״̬������λ�����ź�ǿ��
	short m_sOnDelayTm;	    //������ʱ(Max:3600s) ����Ϊ0
	short m_sOffDelayTm;    //�ػ���ʱ(Max:3600s) ����Ϊ0  [�����ں��Ϸ�]
	short m_sPowerVoltage; 	//��Դ��ѹ(��10)  [ ����UI�·�]
	short m_sDevTemp;     	//�豸�¶�ֵ(��10)
}TGuiDevStatShrMsg;
#define g_ptGuiDevStatShrMsg ((TGuiDevStatShrMsg *)(g_ptGuiSysStatus->m_cShmRsv + GUI_DEV_STAT_START))

typedef struct
{
	unsigned int m_iStatUpdate; //��λ0x0001 --RTMP��Ϣ�и���  0x0002--RTSP�б���Ϣ�и���,�漰����λ������������޷�����
}TGuiStatUpdateShrMsg; //״̬����֪ͨApp
#define g_ptGuiStatUpdateShrMsg ((TGuiStatUpdateShrMsg *)(g_ptGuiSysStatus->m_cShmRsv + GUI_SHR_STAT_UPDATE_STAET))

typedef struct
{
	char m_cTempValue;
}TGuiFanTempShrMsg; //��������ת���¶�ֵ(ȡ����������)
#define g_ptGuiFanTempShrMsg ((TGuiFanTempShrMsg *)(g_ptGuiSysStatus->m_cShmRsv + GUI_SHR_FANTEMP_STAT_STAET))

typedef struct
{
	unsigned char m_cReferCnt;             //���ü������ں˲���ѭ������
	unsigned char m_cPreviewMode;            	//��ǰԤ��ģʽ
	short m_sChn[64];			//ÿ�����ڵ�ǰԤ����ͨ����
}TGuiPreviewWinMsg;
#define g_ptGuiPreviewWinMsg ((TGuiPreviewWinMsg *)(g_ptGuiSysStatus->m_cShmRsv + GUI_PREVIEW_WIN_MSG_START))
#define g_ptGuiPreviewSlaverWinMsg ((TGuiPreviewWinMsg *)(g_ptGuiSysStatus->m_cShmRsv + GUI_PREVIEW_SLAVER_WIN_MSG_START))

#define GUI_POE_OFFLINE		1	//poe�Ͽ�
#define GUI_POE_ONLINE		2	//POE���ӳɹ�
#define GUI_POE_OFFLINE_OUTOFPOWER	3	//POE�����ɶϿ�

typedef struct
{
	unsigned short m_sPower[GUI_VIDEO_IN_CHN_CNT];    //ÿ��poeͨ�����ʣ��ں˳���100��������UI����100����ʾ
	unsigned char m_cStatus[GUI_VIDEO_IN_CHN_CNT];	//ÿ��POEͨ����״̬
}TGuiPoeChnMsg;		
#define g_ptGuiPoeMsg  ((TGuiPoeChnMsg *)(g_ptGuiSysStatus->m_cShmRsv + GUI_POE_MSG_START))

typedef struct
{
	unsigned int m_iChn;    //��λ1��ʾ���ӹ���0��ʾδ���ӹ�
	unsigned int m_iChnEx;  //��32����
}TGuiDigitalChnMsg;
#define g_ptDigitalChnMsg ((TGuiDigitalChnMsg *)(g_ptGuiSysStatus->m_cShmRsv + GUI_DIGITAL_CHN_START))

typedef struct
{
	int m_iPicSize[GUI_VIDEO_IN_CHN_CNT];   //ǰ32����������Ӧͨ���ķֱ���
	int m_iPicSizeEx[GUI_VIDEO_IN_CHN_CNT];   //��32����������Ӧͨ���ķֱ���
}TGuiChnPicSizeMsg;
#define g_ptPicSizeMsg  ((TGuiChnPicSizeMsg *)(g_ptGuiSysStatus->m_cShmRsv + GUI_PICSIZE_START))

//===============״̬===========================
enum
{
	GUI_H323_STAT_FREE  = 0, //����									   //����
	GUI_H323_STAT_LINKING, //����������						   //����������
	GUI_H323_STAT_LINK,  //������									    //������
	GUI_H323_STAT_REFUSE, //�Է��ܾ�
	GUI_H323_STAT_CLOSE, //�Է��ر�									//���йҶ���
	GUI_H323_STAT_CALLIN,	 //Զ�̺���								//���н�����
	GUI_H323_STAT_ERROR,	//����ʧ�ܣ�������
};

typedef struct
{
	unsigned char m_cH323Stat; //��λ����λ-GK״̬������λ-����״̬
}TGuiH323StatMsg;
#define g_ptH323StatMsg ((TGuiH323StatMsg *)(g_ptGuiSysStatus->m_cShmRsv + GUI_H323_STAT_START))

#define TX_MAGIC_NO     20150422  //Send��Recv�Ƿ���Ҫsleep��־
typedef struct
{
	int m_iSleepFlg;
}TGuiTxSleepMsg;

#define g_ptGuiTxSleepMsg ((TGuiTxSleepMsg *)(g_ptGuiSysStatus->m_cShmRsv + GUI_TXSLEEP_START))

static inline int GetDvrErrNo()			//��ȡDVR�����룬��UI����
{
	int n = g_ptGuiSysStatus->m_iDvrErrNo;
	
	g_ptGuiSysStatus->m_iDvrErrNo = 0;
	return n;
}

static inline void SetDvrErrNo(int _iNo)			//����DVR��������dvr����
{
	g_ptGuiSysStatus->m_iDvrErrNo = _iNo;
}

#define GUI_VIDEO_KEY_FILE  "guibmp/main/systemSetting_1.bmp"
#define GUI_ALARM_KEY_FILE	"guibmp/main/systemSetting_2.bmp"
#define GUI_ALARM_ALLMSG_KEY_FILE "guibmp/main/VideoPlayback_3.bmp"
#define GUI_CHNSTA_KEY_FILE  "guibmp/main/videoSetting_1.bmp"

enum
{
	GUI_VIDEO_STA = 1, //¼��״̬
	GUI_ALARM_STA,      //����״̬
	GUI_ALARM_MSG,      
	GUI_CHN_STA,          //����ͨ������״̬
};

extern void* g_pAlarmStatusMem;
extern void* g_pVideoStatusMem;
extern void *g_pAlarmStatusForPlat;
extern void *g_ptChnStatusMem;

/**********************************************************************
������:		GuiTxInit()
��	��:		���ݴ�������ʼ��
�Ρ���:		��
����ֵ:		0:�ɹ�, -1ʧ��
��	־:		2008-09-22����������������ʵ��
**********************************************************************/
int GuiTxInit();

/**********************************************************************
������:		GuiTxUninit()
��	��:		���ݴ���������ʼ��
�Ρ���:		��
����ֵ:		��
��	־:		2008-09-22����������������ʵ��
**********************************************************************/
void GuiTxUninit();

/**********************************************************************
������:		GuiTxOpen()
��	��:		��һ�����ݴ���ͨ��
�Ρ���:		_uiIp:		����IP��ַ
			_uiPort:	�����˿ں�
����ֵ:		������ʧ�ܣ�����ֵΪ����ͨ��������
��	־:		2008-09-16����������������ʵ��
			2008-92-22������������Ӳ���ip��port��
**********************************************************************/
int GuiTxOpen(unsigned int _uiIp, int _iPort);

/**********************************************************************
������:		GuiTxWaitConnector()
��	��:		�ȴ��Ѵ򿪵Ĵ���ͨ�����Է����룬�������GuiOpen���漴����
			�ú���
�Ρ���:		iTid:		����ͨ�����
			iTimeOut:	��ʱʱ�䣬��
����ֵ:		��
��	־:		2008-92-22������������Ӳ���ip��port��
***********************************************************************/
void GuiTxWaitConnector(int _iTid, int _iTimeOut);


/**********************************************************************
������:		GuiTxWaitSeverStart()
��	��:		�ȴ��Է���ָ����IP��Port�ϴ�������ͨ�����������GuiTxConnect
			����ǰ���ô˽ӿ�
�Ρ���:		_iPort:		�˿�
			_uiIp:		ip��ַ
			_iTimeOut:	��ʱʱ��,��
����ֵ:		��
��	־:		2008-92-22������������Ӳ���ip��port��
***********************************************************************/
void GuiTxWaitServerStart(unsigned int _uiIp, int _iPort, int _iTimeOut);

/**********************************************************************
������:		GuiTxConnect()
��	��:		��һ�����ݴ���ͨ��
�Ρ���:		_uiIp:		�Է�IP��ַ
			_uiPort:	�Է��˿ں�
����ֵ:		������ʧ�ܣ�����ֵΪ����ͨ��������
��	־:		2008-09-22����������������ʵ��
**********************************************************************/
int GuiTxConnect(unsigned int _uiIp, int _iPort);

/**********************************************************************
������:		GuiTxReConnect()
��	��:		��һ�����ݴ���ͨ��(��������)
�Ρ���:		_uiIp:		�Է�IP��ַ
			_uiPort:	�Է��˿ں�
����ֵ:		������ʧ�ܣ�����ֵΪ����ͨ��������
��	־:		2008-09-22����������������ʵ��
**********************************************************************/
int GuiTxReConnect(unsigned int _uiIp, int _iPort);

/**********************************************************************
������:		GuiTxClose()
��	��:		�ر�ָ�����Ѵ򿪴���ͨ��
�Ρ���:		_iTid:		����ͨ��������
����ֵ:		��
��	־:		2008-09-16����������������ʵ��
**********************************************************************/
void GuiTxClose(int _iTid);

/**********************************************************************
������:		GuiTxSend()
��	��:		ͨ����������������
�Ρ���:		_iTid:		����ͨ�����
			_pSndBuf:	���������׵�ַ
			_iSize:		�������ݴ�С
			_iTimeOut:	��ʱ���ã���ΪGUI_TX_NO_WAIT, GUI_TX_WAIT_DONE��
						������ʽ��Ӧ��������ʱ
����ֵ:		������ʧ�ܣ�����ֵ��ʾʵ�ʴ����������
��	־:		2008-09-16����������������ʵ��
**********************************************************************/
int GuiTxSend(int _iTid, const void *_pSndBuf, int _iSize, int _iTimeOut);

/**********************************************************************
������:		GuiTxRcv()
��	��:		�Ӵ�������ȡ����
�Ρ���:		_iTid:		����ͨ�����
			_pRcvBuf:	���ջ����׵�ַ
			_iSize:		�������ݴ�С
			_iTimeOut:	��ʱ���ã���ΪGUI_TX_NO_WAIT, GUI_TX_WAIT_DONE��
						������ʽ��Ӧ��������ʱ
����ֵ:		������ʧ�ܣ�����ֵ��ʾʵ�ʶ�ȡ��������
��	־:		2008-09-16����������������ʵ��
**********************************************************************/
int GuiTxRcv(int _iTid, void *_pRcvBuf, int _iSize, int _iTimeOut);

/**********************************************************************
������:		GuiTxReset(int _iTid)
��	��:		���贫��ͨ��״̬
�Ρ���:		_iTid:		����ͨ�����
����ֵ:		��
��	־:		2008-09-16����������������ʵ��
**********************************************************************/
void GuiTxReset(int _iTid);

/*********************************************************************
������: GuiGetShmAddr
����: ���ع����ڴ��ַ
����: _iKey:�����ڴ��ֵ,_iSize:�����ڴ��С
����ֵ: �����ڴ��ַ
��־: 2014-03-17, wzy��������ʵ��
**********************************************************************/
void *GuiGetShmAddr(int _iKey, int _iSize);

int GuiVideoAlarmStaShm(int _iType, int _iChnCnt);

#endif


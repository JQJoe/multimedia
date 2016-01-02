#ifndef _IP_CHANNEL_H_
#define _IP_CHANNEL_H_

#include "vca.h"
#include "td_types.h"
#include "td_errno.h"
#include "td_media.h"
#include "channel.h"
#include "libdatacenter.h"
#include "alarmer.h"
#include "libtdvo.h"
#include "libtdao.h"
#include "td_sdk.h"
#include "libdec.h"



#ifdef IP_CHANNEL_GLOBAL
#define IP_CHANNEL_EXTERN
#else
#define IP_CHANNEL_EXTERN   extern
#endif


#define MODULE_MAX_NUM   		10
#define IPCHANNEL_MAX_NUM   	(32 + 1)
#define	BIND_VO_MAXNUM			16
//��¼״̬
enum
{
    NOT_CONNECT           		= 0,
    CONNECT_ING ,
    CONNECT_SUCCESS ,
    CONNECT_ERROR  
};

//����ͨ������
enum
{
	TDSTREAM = 0,
	ONVIFSTREAM,
	PUSHSTREAM,
};


typedef struct	// vo����Ϣ
{
	void * m_ptVo;		//vo����
	TRect m_tRect;	//�����С(��D1Ϊ��׼)
	TRect * m_ptRect;
} IPTVoBindMsg;





typedef struct
{
	TChannel m_TChannel;
	
	int m_iLogicNo;
	
	TAlarmer *m_ptPortAlarmer;					//�˿ڱ���
	
	TDataFIFO * m_PreviewDataFifo;				//��������ƵԤ��  
	
	TDataPackage * m_PreviewPacket;
	
	TDataPackage * m_PreviewTmpPacket;
	int  			    m_PreviewTmpPacketType;
	
	
	TRingBuf * m_AudioRngBuf;
	volatile  int m_iASendLen;
	volatile  int m_iARnStat;
	
	TNVSMODULE * m_pModule;						//�����������  ����ͨ����ʱ��ֵ
	
	void *	m_pNext;
	
	int		m_iIsUse;								//�Ƿ�ʹ��
	
	int		m_iIndex;
	
	volatile  int 	m_iSata;							//����״̬	
	
	/*������ƵԤ��*/
	pthread_mutex_t m_MutexOpt;

	volatile  int 		m_iVencType;						//��������0��H.264��1��M-JPEG��2��MPEG4
	volatile  int		m_iVideNorm;						//��ʽ    
	volatile  int		m_iFrameRate;						//֡��
	volatile  int		m_iFrameRateChgFlg;					// dxl 20120222	�����ۼӣ���VO��
	volatile  int		m_iFrameRateChgFlg_ex;				// ���ۼӣ������ܷ�����
	volatile  int 		m_iWidth;							//ͼ����
	volatile  int 		m_iHeight;							//ͼ��߶�	
	volatile  int		m_iPreviwSata;						//Ԥ��״̬
	volatile  int		m_iBusyCount;
	volatile  int		m_iVSendStat;
	volatile  int		m_iVideoSize;						//��Ƶ��С ����ͳ��Ԥ������
	volatile  int		m_iVideoProfile;
	//volatile  int		m_iVideoProfileChgFlg;
	volatile  int		m_iVideoBitRate;					//��Ƶ���� 
	volatile  int 		m_iVideoBitRateChgFlg;
	volatile  int		m_iNeedStartEncode;					//dxl 20120521
	volatile  int		m_iCVBRType;						//�������� ������ ������
	volatile  int		m_iCVBRTypeChgFlg;
	volatile  int		m_iIFrameRate;						//I ֡֡��
	volatile  int		m_iIFrameRateChgFlg;
	volatile  int		m_iQuality;
	volatile  int		m_iQualityChgFlg;
	volatile  int		m_iSensorSpin;						//��Ƶ��ת��aaron
	
	TVdecChannel *	m_pVDecChan;					//����ͨ��
	
	IPTVoBindMsg	m_TVoList[BIND_VO_MAXNUM];				//Ԥ��VO
	
	int 	m_iTVoNum;
	int	m_iCreateVdecFail;

	volatile int m_iRepreiw;
	
	/*������ƵԤ��*/
	volatile  int		m_iStreamType;						//�������ʹ���Ƶ����Ƶ���߸�������
	volatile  int		m_iAEnc;							//��Ƶ���뷽ʽ
	volatile  int		m_iAFrameLen;								//��Ƶ֡����
	volatile  int		m_iAEncold;							//��Ƶ���뷽ʽ
	volatile int		m_iAPreviwSata;						//��ƵԤ��״̬
	int		m_iABusyCnt;
	int		m_iSendIndex;
	int		m_iAoDev;
	volatile  int 		m_iAoID;
	int		m_iASendStat;
	
	TChnSnapshotMsg  * m_pSnapMsg;
	
	void * m_pMchan;
	
	TIpChannelMsg m_IpChannelMsg;				//��������Ҫ����Ϣ
	
	TNVSITEM m_IpChannelInfor;				//��������Ҫ����Ϣ
	
	/*������Ϣ*/
	volatile  int  m_iPortAlarmStat;
	volatile  int  m_iVLAlarmStat;
	volatile  int  m_iMDAlarmStat;
	volatile  int  m_iVCAAlarmStat[MAX_RULE_NUM][MAX_EVENT_NUM];
	volatile  int  m_iODAlarmStat;
	
	int  m_iPortAlarmType;
	int  m_iPortAlarmEnable;
	int  m_iVLAlarmEnable;
	int  m_iMDAlarmEnable;
	
	volatile int  m_iBindNum;
	volatile int  m_iBindFlag;
	volatile int  m_iAudioSample;
	volatile int m_iAudioSampleBak;
	volatile td_u16  m_u16AFrameSize;
	/*���ܷ������*/						//zhangyi add 20120904
	td_s32			m_iVcaEnable;	
	volatile td_s32 	m_iReCreateVca;
	//TVdecChannel 	*	m_pVcaVdecPara;
	td_s32				m_iVdecChan;		//zhangyi add 20121114
	td_s32			m_iVencChan;
	td_s32				m_iVcaVideoWidth;
	td_s32				m_iVcaVideoHeight;
	td_s32				m_iVcaVideoNorm;

	//add by gyn
	td_s32 m_iAudioCheckSeed;//add by gyn 20120201 ��Ƶ���ļ��
	
	td_s32 m_iAudioStat;								//�ϳ�ͨ������Ƶ�Ƿ���
	//0��������1����������
	//add end

	td_s32 m_iPreviewMode; //hq 20121210 Ϊ��Ӧ16:9��ƵԴ��4:3�ֱ�������ʾ��0:ƽ������ʾ����1:���ֿ���������ʾ

	void* m_pSIpChan;
	td_s32 m_iSubStreamFlag;
	td_s32 m_iPreviewSubStreamFlag;

	TAlarmer * m_ptCapAlarmer[MAX_RULE_NUM];   
	TAlarmer * m_ptCpcAlarmer[MAX_RULE_NUM]; 
	TAlarmer * m_ptCddAlarmer[MAX_RULE_NUM]; 
	TAlarmer * m_ptSvdAlarmer[MAX_RULE_NUM]; 
	//�������
	TAlarmer *m_ptOdAlarmer;		//��Ƶ�ڵ�����;		zhangyi add 20130411

	//add for decoder ע:�ò�����Ҫ���ģ���Ӳ����ʣ�fifo��center��Ҫ�����ϲ�ʵ�ֺ�ά��
	volatile  int		m_iTalkEnc;
	TDataFIFO * m_TalkDataFifo;	
	TDataCenter* m_TalkDataCenter;
	volatile  int   m_iTalkSata;				//�Խ�״̬
	volatile  int   m_iTalkWait;				//�Խ�״̬
	int m_iStartViewFlag;
	
	td_s32 m_iPreviewPrefer;// Ԥ��ƫ��
	long long m_llLastSendFrameTime;// ���һ�η���֡��ʱ��

	td_char cIpcVersion[32];
	td_s32 m_iUpgrateSta;
	td_s32 m_iUpgrateStaHeartbeat;
	char m_cVideoEncrypt[ENCRYPT_PWD_LENGTH]; // 0: ������1: AES���� 
	td_s32 m_iScrect;

	td_s32 m_iMedleyAvEnable;
	td_u32 m_uiLostAudioFrmNum;
	td_s32 m_iPreviewAudioTime;
}IpChannel, *pIpChannnel;


typedef struct
{
	TAlarmer m_tAlarm;
	IpChannel * m_ptChn;
	//move from 3520 by caizhaoxu for vca 20120321
	td_s32 m_iRuleNo;   //zhangweiwei add for VCA
} IpChnAlarmer;

typedef struct
{
	TNVSMODULE * m_pModule[MODULE_MAX_NUM];		
	char 	m_cLibName[MODULE_MAX_NUM][256];	
	void  * m_dp[MODULE_MAX_NUM];		
	int 	m_iModuleNum;
	int 	m_iChannelNum;
	char	m_cVersion[64];
	int 	m_iIsInit;
	
	int (*SearchReportCallBack)(TIpcDevItem *_ptItem);
	int 	m_iSerchModuleNum;		//��������
	int 	m_iSerchType;				//��������
	int 	m_iSerchModu;				//��������
	volatile  int 	m_iLiveTime;				//������Чʱ��
	int 	m_iEndSerchCount;			//������Чʱ��

	int 	m_iMaxBitRate;

	volatile  int 	m_iSnapFlag;				
	
	pthread_mutex_t m_MutexSerch;

	

	int (*ChnAlarmerRegisterCallBack)(int _iId, int _iType, TAlarmer *_ptAlarm);

	int (*ChnStreamCryptCallBack)(void *_pBuf, td_s32 _iSize, td_u32 _uiKey,  td_u8 *_strPsw, td_s32 _iPswLen);
	
	int (*ChnComDataProcCallBack)(int _iChn, int _iComdId, int _iLength, void *_pBuf);
}IpChannelMang;



td_s32 Init(void *_ptParam);



typedef struct				//ͨ���ṹ��
{
	td_s32 m_iChnNo;	 				//ͨ����(����ͨ����Ϊ�Է�ͨ����)
	td_s32 m_iAencType;				//��Ƶ����ģʽ
	td_s32 m_iAudioSample;			//��Ƶ������
	td_s32 m_iAencStart;				//��Ƶ�����Ƿ�����
	td_s32 m_iAudioFrameSize;			//��Ƶ֡����
	td_s32 m_iSendAudio;				//�Ƿ���Ҫ������Ƶ���Ͳ���
	td_s32 m_iStreamType[2];			//��������
	TRingBuf* 			m_ptAudioBuf[2];	//
	TRingBuf* 			m_ptAsRingBuf;			//���ڼ�¼�ϴ���Ƶ���ݵĻ���Buf
	pthread_mutex_t m_tAudioLock; //dlx 20110408 �����Ƶ������	
	//TDataPackage* m_ptPackage;
} TLocalAudioChannel;



#undef  IP_CHANNEL_EXTERN

#endif






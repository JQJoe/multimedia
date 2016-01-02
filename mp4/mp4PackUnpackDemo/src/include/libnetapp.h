/*************************************************************
*george(393) transplant&modify for this linux version  2006.9.1
*
**************************************************************/
#ifndef LIBNETAPPH
#define LIBNETAPPH

#include "public_def.h"
#include "td_types.h"
#include "wifi.h"

#define CONNECT_FREE 0x00
#define CONNECT_BUSY 0x01

#define PPPOE_CMD_STOP 0
#define PPPOE_CMD_CONNECT 1

//shihaichao add 20120918 ����wifi APģʽ
#define WIFI_RT73 	0x0073
#define WIFI_RT3070 0x3070

//Cheng 12/10 add pppoe info
typedef struct 
{
	char dev_name[16];
	char ip_address[16];
	char net_mask[16];
	char gate_way[16];
	int  on_line;                    //state of pppoe add by cheng
	                                                       //0 ���ųɹ�1  δ���� 2 ������ 3 �Ͽ���	                                                       
}PPPOE_IPInfo;

typedef struct 
{
	int m_iType;
	int m_iTimes;
	strPPPoePara m_sPPPoePara;
}PPPOE_Cmd;

typedef int (*SENDMSGTOSERVER)(int _u32IP,char*,int,int);


//pppoe
void *pThread_PPPOE(void *_Para);
int td_cmd_pppoestop();
int td_cmd_getpppoeconfig(char* cUserName, char* cPassword, int *iAutoDial);
int td_cmd_setpppoeconfig(char* cUserName, char* cPassword, int iAutoDial);//Leeon Tonie add for compiling warnings
int td_cmd_get_pppoestate(void * _pPPPoeStatus);//void TcpClient_Init(void);

int td_cmd_pppoestart(strPPPoePara* _Para, int _iDialTimes);
int td_cmd_pppoestop();

//�ṩһ����ȡ�������Ϳͻ��˵�port�ӿ�
int GetServerClientPort(int* _iServerPort, int* _iClientPort);

int GetIPbyDNS_Ex(char * _domainName, char _cIP [ 16 ]);
void GetEthIp_DHCP(unsigned long para);

//dhcp
td_s32 SetDhcpEnable(td_u8* _u8ItemName, td_s32 _s32Enable);//dhcpʹ��
td_u32 GetClientLocalIP(td_u8 _cClientIp[]);
//zhangweiwei 0412
td_u32 GetSndClientLocalIP(td_u8 _cClientIp[]);
int td_cmd_get_dhcp_netconfig(char* mac, char* ip, char* mask, char* gateway, char* dns, char* backdns);
td_u32 GetDhcpAddress(td_u32 *_u32DhAddr);
td_s32 GetDhcpDns(td_u8 _cDhDns[]);
//zhangweiwei 0412
int  GetSndDhcpDns(char _cSndDns[]);
td_s32 GetDhcpMask(td_u8 _cDhMask[]);
td_s32 GetDhcpGateWay(td_u8 _cDhGateWay[]);

//nfs
td_s32 SetNfs(const td_u8* _u8Ip,const td_u8* _u8Path);

//ip��ȡ������
int td_cmd_getnetconfig(char* mac,char* ip,char* mask,char* gateway,char* dns, char * backdns);
int td_cmd_setnetconfig(td_u32 _u32IP,char* const ip,char* const mask, char* const gateway,char* const dns, char* back_dns);

//zhangweiwei add 20120205
int td_get_dhcp_SndNetConfig(char* mac, char* ip, char* mask, char* gateway, char* dns, char* backdns);
int td_cmd_setSndNetConfig(int bind, char* const ip,char* const mask, char* const gateway,char* const dns, char* back_dns);

int td_cmd_getSndNetConfig(char* mac,char* ip,char* mask,char* gateway,char* dns, char * backdns);
//int td_cmd_setSndNetConfig(char* const ip,char* const mask, char* const gateway,char* const dns, char* back_dns);


//Ntp
int td_cmd_setntpserver(const char* _cServerIP ,const char*  _cPort,const  char* _Interval);

//int td_cmd_querylog(char *cBuf, TLogQuery *tQuery);

//ddns
int td_cmd_set_ddnspara(const char * _cDomainName, const char * _cNvsName,  const char * _cUserName, 
							const char * _cPassWord, int _iPort, int _iEnable);
int td_cmd_get_ddnspara(char * _cDomainName, char * _cNvsName,  char * _cUserName,
							char * _cPassWord, int *_iPort, int *_iEnable);
//ddns������
int NetServer_CheckIp(strDdnsPara* _pDdnsPara);								//Leeon Tonie add for DDNS 090301

//UPNP
int td_cmd_setupnp(int _iEnable);

//��ʼ��
int pppoe_init();
int ntp_init(void * _pstNtp);
void DDNSService_Init();
int Inet_Init();

//zhangweiwei add 20120106
void Net_Upgrade_TimerMonitor(unsigned long _param);

td_s32 td_cmd_set_ftppara(TFtpPara _stFtpPara);//add by nsg 120914
td_s32 td_cmd_get_ftppara(TFtpPara *_pstFtpPara);//add by nsg120914
int net_ftp_sendfile(char* _pcFileName, char* _pcFactoryID) ;  //add by nsg120911 FTP����ץ��ͼƬ
int net_ftp_exit();


//shihaichao add 20120918 ����wifi APģʽ
td_s32 WifiInit();
td_s32 NetWifi_sWIFIAPIPAddress(td_s32 _cIPAddress,td_s32 _cSubMask,td_s32 _cGateWay,td_s32 _cDNS);
td_s32 NetWifi_setwifidhcpconfig(td_char* const _ipstart,td_char* const _ipend, td_char* const _lease);

td_s32 NetWifi_setwifiapconfig(td_char* const ip,td_char* const mask, td_char* const gateway,td_char* const dns, td_char* essid, td_char* encripy, td_char* pwdtype, td_char* pwd, td_char* keynum);
td_s32 NetWifi_ResetWiFiIP();
td_s32 NetWifi_ResetWiFiCard();
td_s32 NetWifi_ResetDHCPServer();

td_s32 NetWifi_sDefaultAP();
td_s32 NetWifi_Cfg_gNetApConfig(NetWifiAP* _stap);

td_s32 NetWifi_setwifimode(td_char *_cwifimode);
td_s32 NetWifi_setapdhcp(td_char *_cdhcpenable);


td_s32 NetWifi_GetWiFiCardType();
td_s32 NetWifi_StaOnline();
//shihc add 20130319 ������������ͳ��
td_s32 td_cmd_flux_state(td_s32 _ilannum,td_char *_pcState);

//20130320 SUN Wei add for smtp
//Email�����ṹ��
typedef struct
{	
	char * m_pPicBuff;//ͼƬ�ļ�����
	int m_PicBuffLen;//ͼƬ�ļ�����
	char m_cPicName[FILE_NAME_LEN];//ͼƬ�ļ���
}TEmailAlarm;

#define MAX_LEN_EMAILPARM 64
#define ON                1
#define OFF               0
//���ϴ���ͬ�����ã����ٱ��������ļ�
#define IDENTICAL_CFG 10
TEmailAlarm* msmtp_GetPic();
td_s32 msmtp_switchAuth2Num(char* _cAuthtype);
int msmtp_send_mail(const char * from_field,const char * to_field,const char * subject_field,const char * buff,td_u32 len,const char * mailaddr);
int td_GenerateEmailConfigFile(TSmtpPara* _pconfig);
typedef int (*MSMTP_SEND)(char* _cMailAddr, char* _cMailBody);
void msmtp_init();
int msmtp_CopyPic2Mem(char* _pcFileName);
char** msmtp_GetAuthtype(void);
//20130320 SUN Wei add for smtp end
//20130320 SUN Wei add for send pic
typedef struct {
    int     m_iChn;
	int     m_iRetryTimes_ftp;//20130314 SUN Wei add for 7.6 resend
	int     m_iRetryTimes_smtp;//20130314 SUN Wei add for 7.6 resend
    char    m_cPicName[FILE_NAME_LEN];
	
} TPicName;
void net_StartPicSendInit(void);

//shihc add ���ӳ��ض�������������ȼ�����
int Net_CardSwitch_Manage(char * _cDevname, int _iEnable);
int Net_CardSwitch_Manage2(char * _cDevname, int _iEnable);
#endif


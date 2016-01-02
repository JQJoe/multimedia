#ifndef _TD_WIFI_H
#define _TD_WIFI_H

typedef enum    //wifi ģʽ
{
	MODE_NONE = 0,
	MODE_STA,
	MODE_AP,
	MODE_BUT,
}TWIFIMODE;


typedef struct 
{
	int m_iInterVal;                        //�������״̬���
	int m_iSearchInterVal;      //����AP���
	int m_iSearchFlag;              //��������
	int m_iSearchState;           //��ǰ����״̬
}stWifiSearch;

typedef enum
{
	AUTH_OPEN = 0,
	AUTH_WEP,
	AUTH_WPA,
	AUTH_WPA2,
}TSafeType;

typedef enum
{
	ENC_NONE = 0,
	ENC_TKIP,
	ENC_AES,
}TEncryptType;

typedef struct
{
	
	char m_cEssid[32];//Ҫ���ӵ�wifi�ȵ�����
	int m_iSetSafeEnable; //�Ƿ�����ȫ����
	TSafeType m_iSafeType;//���ܷ�ʽ//WPA2��WEP��WPA �μ�enum TSafeType ����
	int m_iKeyFormat;//��Կ��ʽ//ASCII��HEX
	TEncryptType m_iKeyType;//��Կ����//2: AES, 1: TKIP
	int m_iKeySelect;//��Կѡ��//WEP
	char m_cWifiEncryption[16]; //�洢�ַ������͵ļ��ܷ�ʽ //WPA-PSK WPA2-PSK
	char m_cWifiPwdType[16]; //�洢�ַ������͵���Կ����
	char m_cWifiPwd[80]; //��Կ
	int m_iWifiKeyNum; //����wifilib���ﲻ��

	unsigned int m_uiIpAddress;//�����ȵ����õ�ip
	unsigned int m_uiSubMask;//�����ȵ����õ�����
	unsigned int m_uiGateWay;//�����ȵ����õ�����
	unsigned int m_uiDNS;//�����ȵ����õ�DNS
	unsigned int m_uiBackDNS;
//	unsigned  char  m_ucMac[8];//��ȡ��wifi����mac

	int m_DHCPEnable;//����DHCP, ipΪ�ղ��Ҵ�ֵΪ1��Ч
	int m_DHCPTimes;//�Զ���ȡip�Ĵ���	
	int m_iOnLine;//�����������ݲ�ʹ��
}strWifiCnf;

typedef struct 
{								
   	unsigned int m_uiAPIpAddress;     	//
   	unsigned int m_uiAPSubMask;       	//ap ģʽ�¸���IP�Զ�����
   	unsigned int m_uiAPGateWay;		//ap ģʽ�¸���IP�Զ�����
   	unsigned int m_uiAPDNS;			//���Ҳ���

	int m_iChannel;
	int m_iAPKeyFormat;				//�����ʽ: ASCII HEX  �ݲ�֧��HEX
	TSafeType m_iSafeType;			//���ܷ�ʽ : OPEN WPA-PSK WPA2-PSK �μ�enum TSafeType ����
	TEncryptType m_iAPKeyNum;		//�������:	0 NONE, 1 TKIP, 2 AES �� 3 WEP(��֧��)	
	char m_cAPESSID[32];			//essid
	char m_cAPPWD[80];				//��������
}StrWifiAP;

typedef struct
{
	unsigned int m_uiIPStart;		//��ʼIP
	unsigned int m_uiIPEnd;		//����IP
	unsigned int m_uiSubMask;	//��������
	unsigned int m_uiGateWay;	//����
	unsigned int m_uiDNS;		//��ѡDNS
	unsigned int m_uiBackDNS;	//����DNS
	int m_iLease;		//���ڣ���λ����
}DHCPServerInfo;

typedef struct 
{								
	//wifi ap parameters yansm
	unsigned int m_uiWifiMode;         	 //0��������  1����ͨwifiģʽ(sta) 2��apģʽ  3��AP+sta
	StrWifiAP m_sWifiAPConfig;        //wireless ����
	unsigned int m_uiAPDHCPenable;   	//ap ģʽ���Ƿ�����dhcp
	DHCPServerInfo m_TDhcpServerConfig;	//DHCP ����������
}NetWifiAP;


typedef struct
{
	char m_cMAC[20];//MAC��ַ�ַ���������00:50:C2:28:10:00
	char m_cProtocol[32];//WiFi Э������
	char m_cESSID[64];
	char m_cMode[32];
	int m_iChannel;//�ŵ�
	unsigned int m_uiQuality;//��������16 λ������ӣ���16 λ�����ĸ
	int m_iSignalLevel;//�ź�ˮ׼(dBm)
	int m_iNoiseLevel;//����ˮ׼(dBm)
	int m_blEncryptionKey;//�Ƿ����
	int m_iBitRate;//���ʣ�(Mb/s)
}TAPattribute;



/***********************************************************
����
���������Ƿ�Ϸ�

����
_uiSubMask	�������룬С��˳����

����ֵ
0	�Ϸ�����
-1	�Ƿ�����

created by Liu Deqiang on October 08, 2013
************************************************************/
int NetWifi_IsValidMask(unsigned int _uiSubMask);


/***********************************************
����: WiFi ��ʼ��
WiFi ��ʼ������,

����
_tMode	wifiģʽ����ΪMODE_STA ��MODE_AP

����ֵ
0		�ҵ���������ʼ���ɹ�
��0	��ʼ��ʧ��

created by Liu Deqiang on August 26, 2013
************************************************/
int NetWifi_Init(TWIFIMODE _tMode);


/***********************************************
����
����WiFi ���������ӵ��ȵ�
STA ģʽ�µ���

����:	wifi ���ò���

����ֵ
0		�ɹ�
��0	ʧ��

created by Liu Deqiang on August 27, 2013
************************************************/
int NetWifi_Connect(strWifiCnf *_psWifiPara);


/*****************************************************************************************
����
��ȡsta wifi ������״̬

����
_piOnline	1: ���ߣ�   0: ������
_piSign	�ź�ǿ��0-100

����ֵ
0		�ɹ�
��0	ʧ��

created by Liu Deqiang on August 28, 2013
******************************************************************************************/
int NetWifi_GetWifiState(int* _piOnline,int* _piSign);


//AP�������
/*****************************************************************************************
����
����DHCP ����������
����
_iStart	��ʼIP, IP ��ַ�����һλ
_iEnd	����IP, IP ��ַ�����һλ
_iLease: ���ڣ���λ���ӣ���Χ60~14400, 1Сʱ~10��

����ֵ
0		�ɹ�
��0	ʧ��
���ô˺�������Ĭ��dhcp����: "0" "0" lease

created by Liu Deqiang on August 28, 2013
******************************************************************************************/
int  NetWifi_Setwifidhcpconfig(int _iStart,int _iEnd, int _iLease);


/*****************************************************************************************
����
AP ģʽ������/ֹͣDHCP ������

����
_iDhcpenable	����/ֹͣ
ע�⣬ÿ����һ�Σ�DHCP ���������̶����ؽ�������Ƶ������

created by Liu Deqiang on August 28, 2013
******************************************************************************************/
int NetWifi_Setapdhcp(int _iDhcpenable);


/*****************************************************************************************
����
����AP����

����
_pWifiAp	Ap����

����ֵ
0		�ɹ�
��0	ʧ��

���غ�dnsδʹ�� �������ò���
created by Liu Deqiang on August 28, 2013
******************************************************************************************/
int NetWifi_Setwifiapconfig(StrWifiAP *_psWifiAp);


/*****************************************************************************************
���ܣ���ȡwifi��ip����Ϣ,Staģʽ�µ���

����
_pcMac		MAC ��ַ
_pcIp		IP ��ַ
_pcMask		��������
_pcGateWay	����
_pcDns		DNS

����ֵ
0		�ɹ�
��0	ʧ��

created by Liu Deqiang on August 27, 2013
******************************************************************************************/
int NetWifi_Getwifinetconfig(char* _pcMac,char* _pcIp, char* _pcMask, char* _pcGateWay, char* _pcDns);


/*****************************************************************************************
*���ƣ�NetWifi_setwifimode
*���ܣ�����wifiģʽ
*������	_iwifimode:
*����ֵ: 0 success   <0 fail   
*yanshiming creat the fun 20120710
ע: ��������Ч
******************************************************************************************/
int NetWifi_Setwifimode(int _iWifiMode);


/***********************************************
����
WiFi ģʽ���

����ֵ
MODE_NONE	��������δ��ʼ��
MODE_STA	STA ģʽ����
MODE_AP	AP ģʽ����	

created by Liu Deqiang on August 29, 2013
************************************************/
int NetWifi_WifiTypeCheck();


/****************************************************
����
���������ر�

created by Liu Deqiang on July 11, 2012
*****************************************************/
int NetWifi_ResetWiFiCard();


/***********************************************
����
��������AP

����
_pcWifiList	��������ַ���

����ֵ:
0		�����ɹ�
��0	�޿���AP

created by Liu Deqiang on August 28, 2013
************************************************/
int NetWifi_DetectAP(char *_pcWifiList);


/****************************************************
����
��iwlist scan ��ȡ���ַ������н�������ÿ��
�ȵ����Ϣд��TAPattribute �ṹ����

����
_iMaxCells	���������ٸ��ȵ�
_pcToAnalyze	��iwlist ���ص��ַ���
_PTinfo		ָ��TAPattribute ���飬�������д��
������

����ֵ
����	���������ٸ��ȵ���Ϣ
-1		ʧ��

created by Liu Deqiang on August 28, 2013
*****************************************************/
int IwlistAnalyse(int _iMaxCells, TAPattribute * _PTinfo);


/***********************************************************
����
���������Ͽ�

����ֵ
0		�ɹ�
��0	ʧ��

created by Liu Deqiang on August 28, 2013
************************************************************/
int NetWifi_SetOffline();


/***********************************************************
����
������������

����ֵ
0		�ɹ�
��0	ʧ��

created by Liu Deqiang on August 29, 2013
************************************************************/
int NetWifi_SetOnline();

#endif

//��DHCP�뼴�弴�÷ֿ������弴�ø������Ӳ��ԣ�DHCP�����豸�豸IP�ȡ�
//����ֻ��DHCP��һ���̣߳�������IP���ֻ�����ʧʱͨ���ص����弴�ò㡣
#ifndef _PLUG_H
#define _PLUG_H
#include "public_def.h"

#define DIG_CHN_PTZ_NAME	31
#define DIG_CHN_NAME_LEN	31
#define MAX_DEV_NUM	(64)
#define MAX_OLD_DEV_NUM	(200)
typedef int (*LinkCallBack)(unsigned int _ip, char *_mac, int _iChn,int _iStat, int _iLink);

typedef struct 
{
	char m_cMac[32];
	unsigned int m_u32Delay;
	unsigned int m_iTime;
}TChangeMacList;

typedef struct 
{
	unsigned int m_u32Time;
	unsigned int m_inter;
	int (*fun)(unsigned int);
}Ttask;

typedef struct
{
	unsigned int m_Ip;
	int m_iChn;
	char m_cMac[40];
	char m_Use;//0:û�ã�1:����ʹ�ã�2:��ʱ������
	char m_cConfict;
	unsigned int m_submask;
	unsigned int m_iTime;
	unsigned int m_iDelay;
}TUseIp;

typedef struct
{
	unsigned int m_ip;
	unsigned int m_iChn;
	char m_cMac[40];
	unsigned int m_iTime;
	unsigned int m_iDelay;
}TLinkStat;

typedef struct
{
	int m_ibonding;
	unsigned int m_u32MyIp;
	char *m_strMac;
	unsigned int m_u32MyIp2;
	char *m_strMac2;
	TUseIp *m_pUseLink;
	TUseIp *m_strOldDev;
	TUseIp *m_strNewDev;
	int *m_piFlushNewDevFlag;
}TPlugSeachInit;
	
typedef enum
{
	PLUG_SEARCH,		//����IPʵ��
	PLUG_CHECKIP,		//���IP���Ƿ��г�ͻ
	PLUG_LINKTASK,			//����
	PLUG_MAX				//�޶���С
} TPlugMode;//���弴�õ�ʵ�ַ�ʽ��

typedef enum
{
	PLUG_NODEV,	//��ͨ��û���豸�������ӣ�����ͨ���ǿ���״̬
	PLUG_LINKING,
	PLUG_LINK,		//��ͨ��������
	PLUG_BRADKOFFING,
	PLUG_BRADKOFF = 0xff,	//�����жϣ�������Ϊ����ԭ���µ���ʱ�ж�
}TPlugStat;

typedef struct
{
	int m_iOtherChn;	//�Է�ͨ����
	int m_iPrivate;		//0-˽�У�1-onvif
	int m_iTcp;		//0-TCP,		1-UDP
	int m_iPort;	//�˿ں�
	int m_iStreamType;	//��������,0:������, 1������
	unsigned int m_ip;
	char m_strPtzProtocol[DIG_CHN_PTZ_NAME + 1]; //ptzЭ��
	char m_strUserName[DIG_CHN_NAME_LEN + 1]; //�û���
	char m_strUserPsw[DIG_CHN_NAME_LEN + 1];	//����
	char m_strVdecPsw[DIG_CHN_NAME_LEN + 1];	//��Ƶ��������
}TDevAttribute;
typedef struct 
{
	int m_id;
	int m_iChn;
	char m_cMac[40]; 
	char m_strIp[40];
}TUiGetDev;
/////////////////////////plug////////////////////
int Plug_init(void);
int Plug_SetMod(int _Mod);
int Plug_Destroy(void);
int Plug_GetStat(void);
int plug_UiGetNewDev(int *_iNum, TUiGetDev *_pDev);
int plug_UiSetNewDev(int _iMove, int _id, int _iChn);
////////////////////////dhcp////////////////////
////////////////////////search///////////////////
int search_init(TPlugSeachInit *_tPlug);

#endif



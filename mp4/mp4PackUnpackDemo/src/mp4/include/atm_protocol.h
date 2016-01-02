#ifndef ATM_PROTOCOL_H_
#define ATM_PROTOCOL_H_

#include "td_types.h"
#include "public_def.h"
#include "libstorage.h"
#include "alarm.h"

#define ATM_MAX_RECV_MSG_LEN 1024
#define ATM_MAX_IPADDR_LEN	 20	



#define DOMAINDATA_NUM 5
#define STRBUF_LEN     33
#define DOMAINDATA_LEN 65

//ATM��������
typedef enum
{
	TC_QUERY			= 0,	//	��ѯ
	TC_GETMONEY,				//	ȡ��
	TC_CHANGEPASSWORD,			//	����
	TC_TRANSFER,				//	ת��
	TC_DEPOSIT,					//	���
	TC_QUERYNOCARD,				//	�޿���ѯ
	TC_DEPOSITNOCARD,			//	�޿����
	TC_OTHER,					//	����
	TC_INSERT_CARD,				//  �忨
	TC_REMOVE_CARD,				//	�ο�		
	TC_NULL = 0xFE,			
}TAtmTransaction;

//ATM�쳣����
typedef enum
{
	EC_SWALLOW_MONEY			= 0,	//	�̳�
	EC_SWALLOW_CARD,					//	�̿�
	EC_NULL = 0xFE,
}TAtmException;

//ATM��������
typedef enum
{
	ATM_CMD_SYNC		= 2,	//ͬ��
	ATM_CMD_INSERT_CARD = 8,		//�忨
	ATM_CMD_REMOVE_CARD = 9,		//�ο�
	ATM_CMD_TRANSACTION = 0x0A,		//����
	ATM_CMD_EXCEPTION 	= 0x0B,			//�쳣
	ATM_CMD_SET_TIME	= 0x0C,			//Уʱ
	ATM_CMD_DOMAIN_INFO,		//����Ϣ
}TAtmCmd;

//ATM Э������
typedef enum
{
	ATM_PROTOCOL_COM = 0,		//����ͨѶ
	ATM_PROTOCOL_NET,			//����ͨѶ
}TAtmProtocolType;


typedef struct
{
	unsigned char 	m_uc8ProtocolName[33];		//atmЭ������
	unsigned int 	m_s32Type;					//Э������ ����Э���������Э��
	unsigned long 	m_ulSrcIp;					//Դ��ַ ATM
	unsigned long	m_ulSrcPort;				//Դ�˿�	
	unsigned long	m_ulDestIp;					//Ŀ�ĵ�ַ DVR
	unsigned long	m_ulDestPort;				//Ŀ�Ķ˿�
	TComInstance* 	m_ptComIns;					//����ʵ��
}TAtmProtocolParam;

typedef struct
{
	unsigned char 		m_ucCardNo[DOMAINDATA_LEN];
	TAtmTransaction		m_eTransaction;
	TAtmException		m_eException;
	unsigned int 		m_iCash;	
	unsigned int 		m_iTime;
	unsigned char 		m_ucUseInfo[DOMAINDATA_LEN];
}TAtmTransactionMsg;

typedef struct 
{
	unsigned int	m_iYear;	//��	
	unsigned int	m_iMonth;	//��
	unsigned int	m_iDay;		//��
	unsigned int	m_iHour;	//ʱ
	unsigned int	m_iMinute;	//��
	unsigned int	m_iSecond;	//��
}TAtmSetTime;
typedef struct
{
    //SUN Wei debug for 12725 
    unsigned int 	m_iTime;
	unsigned char 	m_ucDomian1[DOMAINDATA_LEN];
	unsigned char 	m_ucDomian2[DOMAINDATA_LEN];
	unsigned char 	m_ucDomian3[DOMAINDATA_LEN];
	unsigned char 	m_ucDomian4[DOMAINDATA_LEN];
	unsigned char 	m_ucDomian5[DOMAINDATA_LEN];
}TAtmDomainMsg;

typedef td_u8 (*ATMPROTOCOL_RECVMSG)(TAtmProtocolType _eCmd,void* _pCmdMsg);
/*
	���ڴ���ATM�¼��Ļص�����
	_u8CardNo: 		����
	_s32Operate:	�������忨/�ο�/��ѯ/ȡ���
	_s32Cash:		���
	_s32Event:		�쳣�¼����̿��̳�
*/


typedef td_u8 (*ATMPROTOCOL_OSD)(TAtmProtocolType _eCmd,void* _pCmdMsg);
/*
	���ڴ���ATMOSD�Ļص�����
*/	

//td_s32 atmprotocol_Init(TAtmProtocolParam* _pProtocolParam,ATMPROTOCOL_RECVMSG _AtmRecvMsg);

/*
	����:	ȥ��ʼ��atmЭ�����ģ��
	����:	��
	����:	0		�ɹ�
			����	ʧ��	

*/
//td_s32 atmprotocol_DeInit(void);

/*
	����:	֪ͨATM�������ı�
	����:	_eType		��������
			_iChnNo		ͨ����
			_cAlias		����
	����ֵ: 0		�ɹ�
			����	ʧ��
*/
//td_s32 atmprotocol_AliasChangeNotify(TAliasType _eType,int _iChnNo,char* _cAlias);


/*
	����:	֪ͨATM��¼��״̬�ı�
	����:	_iChnNo		ͨ����
			_eState		¼��״̬
	����ֵ: 0		�ɹ�
			����	ʧ��
*/
//td_s32 atmprotocol_RecordStateNotify(int _iChnNo,TRecordType _eRecordState);



/*
	����:	֪ͨATM������״̬�ı�
	����:	_eType		��������
			_iAlarmNo	����ͨ���Ż򱨾��˿ں�
			_eState		����״̬������������	
	����ֵ: 0		�ɹ�
			����	ʧ��
*/
//td_s32 atmprotocol_AlarmStateNotify(TAlarmType _s32Type,int _iAlarmNo,TAlarmState _eState);


/*
	����:	֪ͨATMͨ������������˿����ͱ�������˿���
	����:	_iChnNo		ͨ����
			_iAlarmInputNo	��������˿���
			_iAlarmOutputNo		��������˿���	
	����ֵ: 0		�ɹ�
			����	ʧ��
*/
//td_s32 atmprotocol_GetChnNoInOutPortNo(int _iChnNo,int _iAlarmInputNo,int _iAlarmOutputNo);

td_s32 Sendinfo2ATM(unsigned char* _ucSendBuf, int iCommandlen);

#endif

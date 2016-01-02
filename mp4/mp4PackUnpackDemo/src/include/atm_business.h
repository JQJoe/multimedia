#ifndef ATM_BUSINESS_H_
#define ATM_BUSINESS_H_
//��ѯ�����ṹ

#include "atm_protocol.h"

#define		MAX_ATM_PROTOCOL_NUM		64				//���֧�ֵ�PTZЭ����
#define		MAX_ATM_PROTOCOL_PATH_LEN	256				//���Э�鶯̬��·������

typedef struct
{
	td_s32			m_iType;				//���ͣ�0Ϊ�����Ų�ѯ��1Ϊ�����ѯ
	td_s8			m_ucChannelNo;			//ͨ����
	time_t			m_iStartTime;			//¼��ʼʱ��
	time_t			m_iStopTime;			//¼�����ʱ��	
	//20121130 SUN Wei debug for Domain Query 12733 
	td_u8			m_QueryKey[5][DOMAINDATA_LEN];		//���ýṹ�壬����/��	
	//20121130 SUN Wei debug for Domain Query 12733 end
	td_u32			m_uiPageNo;				//��ѯ���ҳ��,��0��ʼ
	td_u32			m_uiPageSize;			//ÿҳ��Ŀ��
	td_s32			m_uiTotalNum;			//����Ŀ��
	td_u32			m_uiShowNum;						//����ʾ����Ŀ��
	TAtmTransaction	m_atmTransaction[PAGE_SHOW_NUM];	//ATM������Ϣ
	TAtmException	m_atmException[PAGE_SHOW_NUM];		//ATM�쳣��Ϣ
	TFileInfo		m_stFileInfo[PAGE_SHOW_NUM];		//�ļ���Ϣ��ʹ��ԭ���ģ�
}TAtmQuery;
/*
	atmbusinessģ����Ҫ���Ĺ���

	1����ʼ��/ȥ��ʼ��atm_protocol��
	2�����������л�ȡ������Ϣ��¼��״̬������״̬��������ȡ������Ϣ�·���atmЭ��ģ��
	3�������ϴ���atm��Ϣ������Ӧ�Ĵ���
	//�����������أ����������ļ������Ƿ�����
	
*/

//Define in atm_protocol.h

//��ʼ����ȷ�����ң�����/���ڣ�
//typedef struct
//{
//	td_u8			m_u8ProtocolName[32];		//atmЭ������
//	td_s32 			m_s32Type;					//Э������ ����Э���������Э��
//	unsigned long 	m_ulSrcIp;					//Դ��ַ
//	unsigned long	m_ulSrcPort;				//Դ�˿�	
//	unsigned long	m_ulDestIp;					//Ŀ�ĵ�ַ
//	unsigned long	m_ulDestPort;				//Ŀ�Ķ˿�
//	TComInstance* 	m_ptComIns;					//����ʵ��
//}TAtmProtocolParam;



//��ʼ��
td_s32 atmbusiness_Init();
/*
	����:	��ʼ�����ݿ�
			��ʼ��ATMЭ�������

			��Э�������ע�����ڴ���ATM�ϴ���Ϣ�Ļص�����
			�ص������������´���
			1��	�忨�¼����߲忨����¼��Ĳ������̡�
			2��	�ο��¼����߰ο�ֹͣ¼��Ĳ������̡�	
			3��	���������¼�������¼���ݿ⣬������¼��
			4��	Уʱ����������ϵͳУʱ��������Уʱ������			
				��������������¼��־
	
	����:	_pProtocolParam		Э��������������ơ����͵�
			
	����ֵ:	0		�ɹ�
			����	ʧ��	
*/


td_s32 atmbusiess_DeInit();
/*
	����:ȥ��ʼ��ATMҵ��ģ��
*/

td_s32 atmbusiness_AlarmStateNotify(TAlarmType _eType,int _iAlarmNo,TAlarmState _eState);
/*
	����:	��DvrAlarmStatChgNotify������������ATMҵ��ģ�鴫�ݱ�����Ϣ�Ĵ���
			��atmЭ�����ģ��֪ͨ����״̬�ı䡣	
	����:	_eType		��������
			_iAlarmNo	����ͨ���Ż򱨾��˿ں�
			_eState		����״̬������������	
	����ֵ: 0		�ɹ�
			����	ʧ��
*/
td_s32 atmbusiness_OutPortStateNotify(int _iPortNo, TAlarmState _eState);
/*
	����:	��DvrAlarmStatChgNotify������������ATMҵ��ģ�鴫�ݱ�����Ϣ�Ĵ���
			��atmЭ�����ģ��֪ͨ����״̬�ı䡣	
	����:	_eType		��������
			_iAlarmNo	����ͨ���Ż򱨾��˿ں�
			_eState		����״̬������������	
	����ֵ: 0		�ɹ�
			����	ʧ��
*/

td_s32 atmbusiness_RecordStateNotify(int _iChnNo,TRecordType _eRecordState);
/*
	����:	��DvrRecStatChgNotify������������ATMҵ��ģ�鴫¼��״̬�Ĵ���
			��atmЭ�����ģ��֪ͨ��¼��״̬�ı䡣
	����:	_iChnNo		ͨ����
			_eState		¼��״̬
	����ֵ: 0		�ɹ�
			����	ʧ��
*/

td_s32 atmbusiness_AliasChangeNotify(TAliasType _eType,int _iChnNo,td_u8* _cAlias);
/*
	����:	��ChnAttrChgMsgProc������������ATMҵ��ģ�鴫�ݱ�����Ϣ�Ĵ���
			��atmЭ�����ģ��֪ͨ�����ı䡣
	����:	_eType		��������
			_iChnNo		ͨ����
			_cAlias		����
	����ֵ: 0		�ɹ�
			����	ʧ��
*/

td_s32 atmbusiness_Query(td_u32 _uiSocket, TAtmQuery* _stQ);
/*
	����:	����¼���ѯ
	����:	_uiSocket	���ڱ�ʾ��˭ִ���������ѯ;0��ʾUI��>0��ʾ����ͻ��ˣ������Ƿ�
			_iChnNo		��ѯ�壬���������ѯ��Ϣ�������ѯ���
	����ֵ: 0		�ɹ�
			����	ʧ��
*/

void atmbusiness_UpgradeIndex(td_s8* _ucFileName, td_s8* _ucNewFileName,td_s32 _iType);
/*
	����:	������洢ģ��ע��Ļص�����,�ڷ���¼�񸲸ǻ����ؽ�����ʱ���øú���֪ͨATMģ��
	_iType 	0: ɾ���ļ�  				�ļ���������_ucFileName[0]��
	        1: �ؽ����������ļ���		���ļ���������_ucFileName[0]�У����ļ���������_ucFileName[1]��
	        2: �ؽ������ļ���δ���� 	�ļ���������_ucFileName[0]��
	        3: �ؽ���������
*/

td_s32 atmbusiness_GetProtocolList(char _cList[MAX_ATM_PROTOCOL_NUM][256],int* _iProtocolNum);
/*
	����:	��ȡatmЭ���б�
	����:	_cList	Э���б�
	����ֵ: 0		�ɹ�
			����	ʧ��
*/

td_s32 atmbusiness_SetPara(TAtmPara* _patmPara);
//20121120 SUN Wei add for filesize problem
void cbk_UpdateAtmTableRecFileSize(td_s8 * _ucFileName, td_s32 _iRecFileSize, td_s32 _iStopTime);
//20121120 SUN Wei
td_s32 atmbusiness_DeleteDataBase(void);
//wangsong, 20121224, ɾ���������ݿ�������Ƶ���Ŀ
#endif

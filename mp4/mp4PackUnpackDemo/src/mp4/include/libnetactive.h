#ifndef NET_ACTIVE_TCP_H_
#define NET_ACTIVE_TCP_H_

typedef struct
{
	strParsePara 	m_ParsePara;			            //���޸� �Լ�����
	td_u8		m_cLocalIP[16];							//�豸�ľ�����IP
 	td_u8		m_cFactoryID[32];		                //�豸��ƷID
 	td_u8		m_cRegistedIp[16];	                    //�ɹ�ע��ı���ip
	td_u8		m_cProxiedIp[16];	                    //�ɹ�������ı���ip
}strRegisterMsg;

typedef td_s32 (*ACTIVE_PROCESS_CMD)(td_u8* _u8Buf, td_s32 _iBufLength, void* _pClient);			
/*
* �������ƣ�ACTIVE_PROCESS_CMD
* ��Ҫ��������������Ļص�����
* ��           �룺_pClient		�����ӵ�ָ��
*				  _u8Buf			�����
*				  _iBufLength 		�����
* ��           ����
* �޸���־��2010-01-28,½���ƣ�����
*/

typedef td_s32 (*ACTIVE_PROCESS_DATA)(td_u8* _u8Buf, td_s32 _iBufLength,void* _pClient);			
/*
* �������ƣ�ACTIVE_PROCESS_DATA
* ��Ҫ�������������ݵĻص�����
* ��           �룺_pClient		�����ӵ�ָ��
*				  _u8Buf			���ݻ���
*				  _iBufLength 		���ݳ���
* ��           ����
* �޸���־��2010-01-28,½���ƣ�����
*/

typedef td_s32 (*ACTIVE_PROCESS_ERROR)(td_u8 _u8Error, void* _pClient);
/*
* �������ƣ�ACTIVE_PROCESS_ERROR
* ��Ҫ�������������ӳ���Ļص�����
* ��           �룺 _u8Error		������
				  _pClient			�����ӵ�ָ��
* ��           ����
* �޸���־��2010-01-28,½���ƣ�����
*/
strRegisterMsg* active_GetRegisterInfo();

td_s32 	active_Init(strRegisterMsg* _pRegisterMsg,ACTIVE_PROCESS_CMD _recvCmdEvent,
			ACTIVE_PROCESS_DATA _recvDataEvent,ACTIVE_PROCESS_ERROR _errEvent);
/*
* �������ƣ�active_Init
* ��Ҫ��������ʼ���ص�����ģ��
* ��           �룺_pParsePara		Ŀ¼����������ز���
*				  _RecvCmdEvent	���ڴ�������Ļص�����
*				  _recvDataEvent 	���ڴ������ݵĻص�����
*				 _errEvent		���ڴ������ӳ���Ļص�����	
* ��           ����
* �޸���־��2010-01-28,½���ƣ�����
*/
void TcpClient_Init(strParsePara* ParsePara);

void active_DebugInfor(char *_cString);

void* active_FindConnect(td_u32 _Socket);
int active_FindCmdSocket(td_u32 _Socket);

#endif

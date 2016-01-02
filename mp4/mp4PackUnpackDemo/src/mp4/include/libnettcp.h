/*************************************************************
*transplant&modify for this linux version  2006.9.1
*
**************************************************************/
#ifndef TCPSERVERH_HEAD_FILE
#define TCPSERVERH_HEAD_FILE

#define NS_MAX_CLIENT	64		/*һ��TcpServer��������64������	*/

// for test dxl 20110725
#ifdef TD_DEBUG
#define NS_MAX_CONNECT	64
#else
#define NS_MAX_CONNECT 	48		/*һ��TcpServer��������32��connect	*/
#endif

#include "public_def.h"
#include "td_types.h"
#include "td_media.h"

typedef struct TcpServer
{
	HI_SOCKET			m_sTcpListen;		//����SOCKET
	pthread_t				m_pthreadListen;	//�����߳�	
	PCONNECT			m_pClients[NS_MAX_CLIENT];			//���ӵĿͻ����б�1
	td_u16				m_u16Port;			//�����˿�	
	td_u16				m_u16Reserv;		//����,����32λ����
	TCP_PROCESSCONNECT  	m_ConnectEvent;		//���ӳɹ�������Ļص�����
	
	int (*Init)(void* _tsThis, td_u16 _u16Port,TCP_PROCESSRECVCMD _RecvCmdEvent,
		TCP_PROCESSRECVDATA _RecvDataEvent,TCP_PROCESSCONNECT _ConnectEvent, 
		TCP_PROCESSDISCONNECT _DisConnectEvent,TCP_PROCESSERROR _ErrEvent);
	/*
	���ܣ�	����TcpServer
			�󶨶˿ڣ�Ϊ���ݽ��ջص�������ֵ
			������������
			��������
		
	������	_u16Port			�˿�
			_RecvEvent			�������ݽ��յĻص�����
			_ErrEvent			������ص�����
			_ConnectEvent		�ͻ������ӳɹ��Ļص�����
			_DisConnectEvent	�ͻ��˶Ͽ����ӵĻص�����
		
	���أ�	��
	*/
	
	int (*SendData)(void* _tsThis, PCONNECT _pClient, td_u8* _u8SendBuffer, td_u32 _u32SendLength,td_u8 _u8Channel);
	/*
	���ܣ�	�������ݷ��Ͳ���	
	
	������	_u8SendBuffer	���ݷ��ͻ���
			_u32SendLength	���ݷ��ͻ��峤��	
	
	���أ�	��
	*/
	
	int (*SendCmd)(void* _tsThis, PCONNECT _pClient, td_u8* _u8SendBuffer,td_u32 _u32SendLength);
	/*
	���ܣ�	��������Ͳ���	
	
	������	_u8SendBuffer	���ݷ��ͻ���
			_u32SendLength	���ݷ��ͻ��峤��	
	
	���أ�	��
	*/	

	PCONNECT  (*FindConnect)(void* _tsThis, td_u32 _socket);
	/*
	���ܣ�	����Socket ������������ 
	
	������	_socket	socket��
	
	���أ�	����ָ��		
	*/
	
	void (*CloseOneLink)( PCONNECT _pClient);
	/*
	���ܣ�	�ر�ĳһ�����ӣ����رո����ӵ�SOCKET��ͬʱɾ�������ӵĽ�������
			�ú����ڴ������Ӵ���ʱ���ڲ�����(�������ڲ�����)
			���յ��ͻ��˶Ͽ���Ϣ�����ⲿ����
	
	������	_i	���ӵ����
	
	���أ�	��
	*/
	
	void (*Close)(void* _tsThis);
	/*
	���ܣ�	�ر�TcpServer
			ͣ����������
			ͣ�����ݷ��ͺͽ�������
			ɾ������
	
	������	��
	
	���أ�	��
	*/
	
}TcpServer;

//��ʼ��
int Tcp_Init();			

//ȥ��ʼ��
int Tcp_Uninit();		

//����һ��TcpServer
TcpServer *Tcp_CreateTcpServer(td_u16 _u16Port,TCP_PROCESSRECVCMD _RecvCmdEvent,
		TCP_PROCESSRECVDATA _RecvDataEvent,TCP_PROCESSCONNECT _ConnectEvent, 
		TCP_PROCESSDISCONNECT _DisConnectEvent,TCP_PROCESSERROR _ErrEvent);

//����һ��UDP��������
int Tcp_DestroyTcpServer(TcpServer* _tcpServer);


#endif


#ifndef _NET_TCP_COMMON_H
#define _NET_TCP_COMMON_H

#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

#include "public_def.h"
#include "td_types.h"
#include "libdatacenter.h"

#define USE_SYS_MUTEX	1

#if USE_SYS_MUTEX
#include <pthread.h>

#define TDataLock 			pthread_mutex_t
#define InitDataLock(lck)		pthread_mutex_init(&(lck), NULL)
#define LockDataLock(lck)		pthread_mutex_lock(&(lck))
#define UnLockDataLock(lck)	pthread_mutex_unlock(&(lck))
#else
#include <unistd.h>

#define TDataLock	int
#define InitDataLock(lck)		(lck) = 0
#define LockDataLock(lck)		{while ((lck) > 0) {usleep(14);}; (lck)++;}
#define UnLockDataLock(lck)	(lck)--
#endif

#define SENDBUFNUM 	4

#define TCPSTREAMSIZE		1460
#define RECVBUFSIZE			4096
#define BUFFER_LENGTH_CMD         384

#define STREAMSIZE              1440
#define COMMANDSIZE             1440
#define TCPSTREAMSIZE		1460
#define RECVBUFSIZE				4096

typedef int HI_SOCKET;

#define CONNECTION_ALIVE  0x00
#define CONNECTION_CLOSE 0x01

#define CONNECTION_PASSIVE 0x00			//add 2010/5/7
#define CONNECTION_ACTIVE  0x01			//add 2010/5/7	

#define CONNECT_FREE 0x00
#define CONNECT_BUSY 0x01

#ifndef INVALID_SOCKET
#define INVALID_SOCKET  -1
#endif

#define  DATAPACKHEAD			0xF9EAF5F1    //���ݰ���ͷ ���4λΪ�汾��
#define  COMMPACKHEAD			0xF5EAF5F1    //�������ͷ

typedef struct
{
	td_u32	m_ui32Head;			//���ݰ���ͷ
	td_u32    m_ui32Serial;         //���к�
	td_u32	  m_ui32Source;	        //���ݰ�Դ��ַ
	td_u8     m_ui8Channel;         //ͨ����
	td_u8     m_ui8FrameType;       //֡����
	td_u16    m_ui16Size;      		//���ݳ���
    	td_u32    m_ui32StreamType;//��������
}STREAMHEAD,*PSTREAMHEAD;


//�������ͷ
typedef struct
{
	td_u32     m_ui32Head;			    //�������ͷ
	td_u16	   m_ui16Serial;	        //���к�,�����ж��Ƿ񶪰�
	td_u16     m_ui16CommandSize;       //�����ܳ���
	td_u32	   m_ui32Target;		    //�����Ŀ�ĵأ����Ϊȫ1���ǹ㲥��
	td_u32	   m_ui32Source;	        //�����Դ��ַ
    td_u16	   m_ui16Order;		        //������
	td_u16	   m_ui16ParaCount;	        //�����ĳ���
}COMMANDHEAD,*PCOMMANDHEAD;


typedef td_u8 (*TCP_PROCESSDISCONNECT)(void* _pClient);
/*
	���ܣ�	�ͻ��˶Ͽ����ӵĻص�����
	������  _pClient	�����ӵ�ָ��
*/
typedef td_u8 (*TCP_PROCESSCONNECT)(void* _pClient);
/*
    ���ܣ�  ���ӳɹ�������Ļص�����()
	������  _pClient	�����ӵ�ָ��          
*/
typedef td_u8 (*TCP_PROCESSRECVCMD)(td_u8* _u8Buf, int _iBufLength, void* _pClient);
/*
    ���ܣ�  SOCKET�յ������Ļص�����
    
    ������  _cBuf��			���ջ���ָ��
            _iBufLength��	���ջ����С
			_pClient		�����ӵ�ָ��  
*/
typedef td_u8 (*TCP_PROCESSRECVDATA)(td_u8* _u8Buf, int _iBufLength, void* _pClient);
/*
���ܣ�  SOCKET�յ����ݺ�Ļص�����
    
    ������  _cBuf��			���ջ���ָ��
            _iBufLength��	���ջ����С
			_pClient		�����ӵ�ָ��
*/
typedef td_u8 (*TCP_PROCESSERROR)(td_u8 _u8Error, void* _pClient);
/*
	���ܣ�	SOCKET���������Ļص�����
	
	������	_u8Error:		�����
			_pClient		�����ӵ�ָ��  
*/

/*Ϊÿһ�����ӽ���һ���ṹ,��¼������Ϣ*/
typedef struct ConnectNode
{
	HI_SOCKET			m_socket;					//��ͻ������ӵ�SOCKET������д�ڵ�һ��
	HI_SOCKET			m_Cmdsocket;				//������ͨ����Ӧ������ͨ��
	td_u32				m_u32IpAddress;				//�ͻ��˵�IP��ַ
	pthread_t				m_pthreadRecv;				//�����߳�
	pid_t					m_pidRecv;					//�����߳�PID ������ 090619 ���
	pthread_t				m_pthreadSend;				//�����߳�
	volatile int					m_hRecState;				//����������  Sherry add 20051121	
	volatile int 					m_hSendState;
	int					m_iNeedFrameType;
	//Cheng 02/04 ���,��m_LiveTime����ʹ�ã�������ͨ��ִ����������
	//����m_BlockExecΪ1���������ۼӣ������ۼ�
	td_u32                             m_BlockExec;
	td_u32				m_LiveTime;
	//int 				m_hMbxSend;					//��������������
	td_u32				m_ConnectType;				//���ӱ��1:cmd  2;data 0:dida
	td_u32				m_bConnected;				//�������Ƿ��ѱ�ռ��
	td_u32				m_chnNum;					//��¼�����ĸ�ͨ������
	td_u8				m_u8SendBuf[TCPSTREAMSIZE];	//���ݷ��ͻ��� ��¼
	TDataLock				m_tDataLock;			//������dxl 2010/08/13
	TDataPackage *                m_CurrentDataPkt;      //��¼δ���ͳɹ������ݰ�
	td_u32                             	m_SendPos;                 //��¼�ѷ��͵�λ��
	td_u8				m_u8RecvBuf[RECVBUFSIZE];	//���ݽ��ջ���	Sherry add 20051122
	td_u32				m_u32RecvLen;				//���յ������ݳ���
	td_u32			  	m_u32BufDataLen;            //��¼m_u8SendBuf����Ч���ݳ��ȣ� 0 Ϊ������
	td_u16				m_u16Port;					//�˿�
	td_u8				m_u8Flag;				//add 2010/5/7���ڱ�ʶ�����ӵ�ģʽ�������򱻶�
	td_s32              m_iCharSet;            //��¼�ͻ����ַ��� 1--GB2312   2--UTF-8
	//Cheng 10/01/13 from S2 for multi IP addr
	td_u8					m_u8ServerIP[16];				//�ͻ������ӵķ�����IP
	TCP_PROCESSRECVCMD     	m_RecvCmd;					//������ջص�����
	TCP_PROCESSRECVDATA		m_RecvData;					//���ݽ��ջص�����
	TCP_PROCESSERROR		m_ErrEvent;					//������ص�����
	TCP_PROCESSCONNECT  		m_ConnectEvent;				//���ӳɹ�������Ļص�����
	TCP_PROCESSDISCONNECT	m_DisConnectEvent;			//�ͻ��˶Ͽ����ӵĻص�����
	TDataFIFO* 				m_DataFifo;
	
	TDataCenter* m_pDataCenter;

	TDataLock	m_tSafeLock;						//��ȫ�� 20110721
	
	struct ConnectNode	*m_next;
	
	
	void (*ParseStreamData)(void* _pClient,td_u8* _u8RecvBuffer, td_u32 _u32RecvLength);
	/*
		���ܣ�	�����յ������ݣ�����յ���Ϊ����������������ص�����
	    	    ���˵����Ϊ���ݰ���������ݻص�����	
	
		������	_u8RecvBuffer	�������ݻ���
				_u32RecvLength	�������ݳ���
	
		���أ�	��	
	*/
}CONNECT, *PCONNECT;	

static inline TDataPackage *GetDataPakageOfConnect(PCONNECT _ptConnect) //dxl
{
	TDataPackage *ptPkg = NULL;
	
	LockDataLock(_ptConnect->m_tDataLock);

	ptPkg = _ptConnect->m_CurrentDataPkt;

	_ptConnect->m_CurrentDataPkt = NULL;
		
	UnLockDataLock(_ptConnect->m_tDataLock);

	return ptPkg;
}

static inline void SetDataPakageOfConnect(PCONNECT _ptConnect, TDataPackage *_ptPkg) //dxl
{
	LockDataLock(_ptConnect->m_tDataLock);

	if (_ptConnect->m_CurrentDataPkt)
	{
		datacenter_PackageRelease(_ptConnect->m_CurrentDataPkt);
	}

	_ptConnect->m_CurrentDataPkt = _ptPkg;
		
	UnLockDataLock(_ptConnect->m_tDataLock);
}

#endif

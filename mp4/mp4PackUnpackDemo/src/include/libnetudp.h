#ifndef _NET_NETUDP_H
#define _NET_NETUDP_H


typedef int (*PROCESSRECV)(td_u8* _u8Buf,int _iBufLength,
	td_u32 _u32IpAddress,td_u16 _u16Port,int _socket);
/*
    ���ܣ�  SOCKET�յ����ݺ�Ļص�����
    
    ������  _cBuf��			���ջ���ָ��
            _iBufLength��	���ջ����С
            _astrFromIP��	���ݷ��Ͷ˵�IP��ַ
            _iPort��		�������ݵĶ˿�
            
    ����ֵ:	0	�ɹ�
			-1	ʧ��
*/

typedef int (*PROCESSERROR)(td_u8 _u8Error,td_u32 _u32IpAddress,td_u16 _u16Port);
/*
	���ܣ�	SOCKET���������Ļص�����
	
	������	_u8Error:		�����
			_u32IpAddress:	IP��ַ
			_u8Port:		�˿ں�
	
	����ֵ:	0	�ɹ�
			-1	ʧ��
*/

typedef struct
{
	td_u8       m_u8Type;		//����Ϣ��Ӧ�õ���������
	//td_u8	m_u8Buf[STREAMSIZE];
	td_u8*	m_u8Buf;
	td_u32 	m_u32Length;	//�������ݻ����С
	td_u32      m_u32IpAddress;	//Ŀ��IP
	td_u32	m_u32Port;
	td_u16      m_u16Reply;
}DataSend_Msg;


typedef struct CMDUdp
{
  	int 				m_sUdp;
	td_u32  			m_u32Port;
	
	td_u8*			m_u8SendBuffer;
	td_u8*			m_u8RecvBuffer;	
	PROCESSRECV  	m_RecvEvent;
	PROCESSERROR 	m_ErrEvent;
	
	pthread_t			m_pthreadRecv;
	pthread_t			m_pthreadSchedule;
	

	void (*Init)(void* _uThis,td_u32 _u32Port,PROCESSRECV _RecvEvent,
				PROCESSERROR _ErrEvent,int _iMode);
/*	
	���ܣ�����Udp
			����SOCKET ΪSOCKET�󶨵�ַ�Ͷ˿�
			Ϊ���ݽ��ջص�������ֵ
			�ֱ𴴽����ݷ�����������ݽ�������
			��������(��ֻ�������ݽ��ղ����ɲ�����)
				
	������_u32Port		�˿�
			_RecvEvent		�������ݽ��յĻص�����
			_ErrEvent		�����������Ļص�����
			_iMode			0x01 ��UDP���������ݷ��Ͳ���
							0x02 ��UDP��ͬʱӦ�������ݽ��ռ����Ͳ���
		
	����ֵ����
*/	
	void (*SendData)(void* _uThis, td_u32 _u32IpAddress, td_u32 _u32Port,
					td_u8* _u8SendBuffer, td_u32 _u32SendLength, td_u16 _reply);
/*	
	���ܣ��������ݷ��Ͳ���	
			���ݺ�������Ϊm_MsgDataSend��������Ա m_cBuf��m_iLength��ֵ
			�����ݷ�������Post m_MsgDataSend
			(���ݷ������������󼴴��ڵȴ���Ϣ��״̬��ÿ�յ�һ��Msg������һ�����ݷ��Ͳ���)
		
	������_u32IpAddress	Ŀ��IP��ַ
			_u8SendBuffer	�������ݻ���
			_u32SendLength	�������ݻ��峤��	
			_reply			�������Ƿ���Ҫ��Ӧ		
		
	����ֵ����
*/	
	
	void (*Close)(void* _uThis);
/*	
	���ܣ��ر�Udp
			ͣ�����ݷ��ͺ����ݽ�������
			������ɾ��
	������	��
	����ֵ����
*/	
		
	//DataSend_Msg	m_MsgDataSend;	

	char*			m_cmdQueue;
}CMDUdp;


typedef struct DATAUdp
{
  	int 			m_sUdp;  	

	td_u32  		m_u32Port;
	
	td_u8*			m_u8SendBuffer;
	td_u8*			m_u8RecvBuffer;	
	PROCESSRECV  	m_RecvEvent;
	PROCESSERROR 	m_ErrEvent;
	
	pthread_t			m_pthreadRecv;
	pthread_t			m_pthreadSchedule;
	
	td_u32		m_RecvStopFlag;
	td_u32		m_ScheduleStopFlag;

	td_u32		m_ExitFlag;
	TDataFIFO* 	m_DataFifo;
	
	//MBX_Handle  	m_hUDPDataSendMbx;	//�������ݷ��Ͳ���������

	void (*Init)(void* _uThis, td_u32 _u32Host, td_u16 _u16Port, PROCESSRECV _RecvEvent, 
				PROCESSERROR _ErrEvent, int _iMode);
/*	
	���ܣ�	����Udp
			����HI_SOCKET ΪHI_SOCKET�󶨵�ַ�Ͷ˿�
			Ϊ���ݽ��ջص�������ֵ
			�ֱ𴴽����ݷ�����������ݽ�������
			��������(��ֻ�������ݽ��ղ����ɲ�����)
				
	������	_u32Port		�˿�
			_RecvEvent		�������ݽ��յĻص�����
			_ErrEvent		�����������Ļص�����
			_iMode			0x01 ��UDP���������ݷ��Ͳ���
							0x02 ��UDP��ͬʱӦ�������ݽ��ռ����Ͳ���
		
	����ֵ����
*/	
	void (*SendData)(void* _uThis, td_u8* _u8SendBuffer,td_u32 _u32SendLength,
		td_u32 _u32IpAddress,td_u16 _u16Port);
/*	
	���ܣ�	�������ݷ��Ͳ���	
			���ݺ�������Ϊm_MsgDataSend��������Ա m_cBuf��m_iLength��ֵ
			�����ݷ�������Post m_MsgDataSend
			(���ݷ������������󼴴��ڵȴ���Ϣ��״̬��ÿ�յ�һ��Msg������һ�����ݷ��Ͳ���)
		
	������	_u32IpAddress	Ŀ��IP��ַ
			_u8SendBuffer	�������ݻ���
			_u32SendLength	�������ݻ��峤��	
			_reply			�������Ƿ���Ҫ��Ӧ		
		
	����ֵ����
*/	
	
	void (*Close)(void* _uThis);
/*	
	���ܣ�	�ر�Udp
			ͣ�����ݷ��ͺ����ݽ�������
			������ɾ��
	������	��
	����ֵ����
*/	
		
	DataSend_Msg	m_MsgDataSend;			
	char*		m_dataBuffer;  //ͷ���(��������Ϣ)	
}DATAUdp;

//��ʼ��
int Udp_Init();			

//ȥ��ʼ��
int Udp_Uninit();		

//����һ��UDP��������
CMDUdp *udp_CreateCmdNode(td_u32 _u32Port,	
	PROCESSRECV _RecvEvent,PROCESSERROR _ErrEvent,int _iMode);

//����һ��UDP��������
int Udp_DestroyCmdNode(CMDUdp* _CmdUdp);

//����һ��UDP��������
DATAUdp *Udp_CreateDataNode( td_u32 _u32Host, 
	td_u16 _u16Port, PROCESSRECV _RecvEvent, PROCESSERROR _ErrEvent, int _iMode);

//����һ��UDP��������
int Udp_DestroyDataNode(DATAUdp* _DataUdp);

#endif

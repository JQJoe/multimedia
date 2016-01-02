/*******************************************************************
�ļ���     : smartctl.h
��˾          : Tianjin Tiandy Tech.
������     : ����
��������: 2011-12-5
��Ҫ����: smart������
�޸ļ�¼: 2011-12-5 yangjue Create this File
******************************************************************/

#ifndef SMART_H
#define SMART_H

#define SMART_NAME_LEN  32		// ��Ϣ����󳤶�
#define SMART_VALUE_NUM 6		// ÿ����Ϣ������Ϣ������
#define SMART_VALUE_LEN 16		// ÿ����Ϣ����Ϣ����

// ʵ��ʹ�õķ���ֵҲ�����������н�һ���ĸ���
// ��������ֵ
#define SMART_SUCCESS		0		// ����ִ�гɹ�
#define SMART_OPEN			0		// �豸����
#define SMART_NOTSUPPORT	-1
#define SMART_CLOSE			-2
#define SMART_READERROR		-3
#define SMART_ARGERROR		-4
#define SMART_OPENERROR		-5
#define SMART_SETERROR		-6
#define SMART_AUTOTIMEERR	-7
#define SMART_AUTOSAVEERR	-8

// ��Ϣ������
#define SMART_MSGIDX_FLAG	0
#define SMART_MSGIDX_VALUE	1
#define SMART_MSGIDX_WORST	2
#define SMART_MSGIDX_THRE	3
#define SMART_MSGIDX_STATUS	4
#define SMART_MSGIDX_RAW	5

// smart��Ϣ
typedef struct
{
	int  m_iSmartID;  //HEX ֵ
	char m_cSmartName[SMART_NAME_LEN];    //smart ��������
	int  m_iSmartFlag;   //��ʶ
	int  m_iSmartValue;
	int  m_iSmartWorst;
	int  m_iSmartThresh;
	char m_cSmartStatus[SMART_VALUE_LEN]; //Ӳ��״̬
	int  m_iResInt;      // �ֽڶ������
	long long m_llSmartRawValue;
} TSmartMsg;

// smart������Ϣ
typedef struct
{
	long long m_llCapacity;  //Ӳ������
	char m_cDevModel[SMART_NAME_LEN];
	char m_cSerialNum[SMART_VALUE_LEN];
	int m_iTemp; //�¶�
	int m_iUsedTime;// �������
	int m_iHealth; // 1-ͨ�� 0-��ͨ��
	int m_iAllHealth; // 1-����״������
}TSmartBasicMsg;


/******************************************************************************
	��������: smart_GetDiskMsg
	��Ҫ����: ��ȡӲ����Ϣ
	����          : _strDiskDev-------Ӳ���豸��
	                      _ptMsg-----------��Ϣ����
	                      _iMaxCnt----------�����ȡ���������
	���          : ����ʵ�ʶ�������Ϣ����
	                      ��ֵ��ʾ��ȡ��������������������
	�޸���־: 2011-12-05 ���崴���ú���
******************************************************************************/
int smart_GetDiskMsg(char *_strDiskDev, TSmartMsg *_ptMsg, int _iMaxCnt);


/******************************************************************************
	��������: smart_SetStatus
	��Ҫ����: ���Ӳ��״̬
	����          : _strDiskDev-------Ӳ���豸��
	                      _iStatus----------smart����״̬
	                                                 SMART_OPENΪ����SMART_CLOSEΪ�ر�
	���          : 0 ����smart���óɹ�
	                      ��ֵ��ʾ��ȡ��������������������
	�޸���־: 2011-12-05 ���崴���ú���
******************************************************************************/
int smart_SetStatus(char *_strDiskDev, int _iStatus);


/******************************************************************************
	��������: smart_GetDiskBasicMsg
	��Ҫ����: ��ȡӲ�̻�����Ϣ
	����          : _strDiskDev-------Ӳ���豸��
	                      _ptMsg-----------��Ϣ����
	���          : 0��ʾ��ȡ��ȷ
	                      ��ֵ��ʾ��ȡ��������������������
	�޸���־: 2012-01-18 ���崴���ú���
******************************************************************************/
int smart_GetDiskBasicMsg(char *_strDiskDev, TSmartBasicMsg *_ptMsg);



#endif

/***********************end of the file***************************/


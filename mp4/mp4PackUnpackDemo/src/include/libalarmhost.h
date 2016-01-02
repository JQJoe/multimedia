#ifndef _ALARMER_CNF_H_
#define _ALARMER_CNF_H_

#include "alarmer.h"
#include "td_types.h"

//���籨��������Ϣ
typedef struct
{
	td_s32 m_iDevNo;						//�������
	td_s32 m_iIsUsed;						//����
	char m_strAddress[32];	//ip��ַ
	td_s32 m_iPort;							//�˿ں�

	td_s32 m_iAlarmInNum;	   	 			//����������
	td_s32 m_iAlarmOutNum;   	 			//���������
}TNetAlarmerCnf;

//���ڱ���������Ϣ
typedef struct
{
	td_s32 m_iDevNo;					//�������
	td_s32 m_iIsUsed;		   	 		//�Ƿ�����
	td_s32 m_iSerialNo;	     		//���ں�
	td_s32 m_iProtocoType;	     		//Э������
	td_s32 m_iAddress;					//��ַ(0~255)
	td_s32 m_iAlarmInNum;	   	 		//����������
	td_s32 m_iAlarmOutNum;   	 		//���������
}TSerialarmerCnf;

//��ȡ�����ļ�
td_s32 alarmhost_GetNetAlarmerCnf(td_s32 _iAhDevNo, TNetAlarmerCnf *_ptCnf);
//д�����ļ�
td_s32 alarmhost_SetNetAlarmer(td_s32 _iAhDevNo, TNetAlarmerCnf *_ptCnf);
//��ȡ���ڱ�����������
td_s32 alarmhost_GetSerialAlarmerCnf(td_s32 _iAhDevNo, TSerialarmerCnf *_ptCnf);
//д�����ļ�
td_s32 alarmhost_SetSerialAlarmer(td_s32 _iAhDevNo, TSerialarmerCnf *_ptCnf);
//����������������������
td_s32 alarmhost_CreateAlarmInPort(TAlarmer *_ptAlarms[], td_s32 _iMaxCnt);
//���������������������
td_s32 alarmhost_CreateAlarmOutPort(TAlarmOutPort *_ptAlarmOutPort[], td_s32 _iMaxCnt);

td_s32 alarmhost_Init(TComInstance *_ptComIns, void (*ComDataProc)(td_s32, td_s32, td_u8 *));

//�ָ�������������
td_s32 alarmerHost_DefaultCfg(void);

int alarmhost_GetOutPortAlamerAttr(int _iportNo, char * _strMsg);



#endif


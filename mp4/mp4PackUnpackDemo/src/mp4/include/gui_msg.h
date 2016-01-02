#ifndef _GUI_MSG_H_
#define _GUI_MSG_H_

#include "guitransport.h"

/***********************Alarm Message Begin************************************/
//֪ͨUIĳ��ͨ���ı���״̬
#define msg_TellUIAlarmState(ch, state)			g_ptDvrAlarmStaForGui->m_iAlarmSta[ch] = state

//֪ͨUI�豸��ǰ�Ƿ�Ϊ����״̬
#define msg_TellUIIfAlarming(state)				g_ptDvrAlarmStaForGui->m_iAlarmLed = state

//�ж�ĳ��ͨ����״̬�Ƿ�Ϊ������
#define msg_IfAlarmState(ch, state)				(g_ptDvrAlarmStaForGui->m_iAlarmSta[ch] == state)
/***********************Alarm Message End**************************************/

/***********************Storage Message Begin**********************************/
//֪ͨUI¼��״̬
#define msg_TellUIRecordStatus(ch, state)		g_ptDvrVideoStaForGui->m_iVideoSta[ch] = state

//��UI��ȡĳ��ͨ����״̬
#define msg_GetUIRecordStatus(ch)				g_ptDvrVideoStaForGui->m_iVideoSta[ch]

/***********************Storage Message End************************************/

/***********************Public Message Begin***********************************/
//����������
#define msg_Buzzer(enable)				g_ptDvrAlarmStaForGui->m_iAlarmSound = enable

//֪ͨUIĿǰ������״̬
#define msg_TellUIStatus(status, param)	g_ptGuiSysStatus->m_iSysSta = status;\
										g_ptGuiSysStatus->m_iParams[0] = param
//����/�ػ�����
#define GUI_GET_NET_REBOOT_CMD 			20120224
	
//��ȡUIĿǰ������״̬����
#define msg_GetUIStatusParam()			g_ptGuiSysStatus->m_iParams[0]
//֪ͨUI���̱��
#define msg_TellUIDiskNo(diskno)		g_ptGuiSysStatus->m_iParams[1] = diskno

//֪ͨUIƽ̨��ʼ�����
#define msg_TellUIPlatformInit(status)		g_ptGuiSysStatus->m_iParams[2] = status

//��GUI�����쳣���
#define msg_ReportException(exception)	g_ptGuiSysStatus->m_iSysErr = exception

//��GUI���������
#define msg_ReportError(errorno)				SetDvrErrNo(errorno)   //yp2009

//֪ͨԤ��״̬(VO)
#define msg_ReportPreviewStat(s)		g_ptGuiSysStatus->m_iSysErrMsg[GUI_SYS_ERR_PCNT - 1] = s
#define msg_GetPrePreviewStat()		(g_ptGuiSysStatus->m_iSysErrMsg[GUI_SYS_ERR_PCNT - 1])

//֪ͨUI���ػ���ʱʱ��
#define msg_ReportPowerDelay(ontime, offtime) g_ptGuiDevStatShrMsg->m_sOnDelayTm = ontime;\
											  g_ptGuiDevStatShrMsg->m_sOffDelayTm = offtime
/***********************Public Message End*************************************/

#endif /*_GUI_MSG_H_*/


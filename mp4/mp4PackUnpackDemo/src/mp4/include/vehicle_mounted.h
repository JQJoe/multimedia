/***********************************************************************
�ļ���	:vehicle_mounted.h
��˾	:������ΰҵ����Ƽ����޹�˾
������	:
��������:2013-8-21
��Ҫ����:����ģ�飬��Ҫʵ�����¹���
         1����ʼ������ʼ��3g��GPS�����͵�ѹ�����͵�ѹ�ػ�����ع��ܡ�
         2����Ҫʵ�����¹���
            ��Դ�����¶��ϱ����˿ڱ���������㡢GPS����3G����
         3����Ƭ���汾����������ver.c�ļ��У����ڴ˴�ʵ��
            ��ʱ�ػ�����ʱ�������ܣ��ں˽�ʵ�ֱ������ù��ܣ�Ҳ���ڴ�ʵ��
         4��¼���ļ�ftp�ϴ���¼���ļ���������
*************************************************************************/

#ifndef VEHICLE__MOUNTED_H
#define VEHICLE__MOUNTED_H

#include "public_def.h"

#define MAX_PHONE_COUNT		5

typedef int  (*SEND_MSG_TO_ALL_CLIENT)(char* _cMsg,int _iLen,int _iType);
typedef int  (*SEND_COMDATA_TO_ALL_CLIENT)(td_u8* _u8Data,td_s32 _iLen,td_s32 _iComNo);

typedef struct 
{
	int m_iOpenEnable;		//������ʱʹ��
	int m_iOpenDevDelayTime;	//������ʱʱ��
	int m_iCloseEnable;		//�ػ���ʱʹ��
	int m_iCloseDevDelayTime;       //�ػ���ʱʱ��
}TPowerManageMsg;//��Դ������Ϣ�ṹ

typedef struct 
{
	int m_iPoweroffVoltage;	 //�ػ���ѹֵ
	int m_iAlarmVoltage;	 //��ѹ����ֵ
}TPowerAlarmMsg;//�����ػ���ѹֵ�ṹ



td_s32 Vehcl_Init(SEND_MSG_TO_ALL_CLIENT _SendMsgToAllClient);
/*
 * �������ƣ�Vehcl_Init
 * ��Ҫ����: ����ģ���ʼ��
 *           ���ε���Vehcl_PowerManagerInit,Vehcl_GPSInit,Vehcl_3GInit����
 *           �ֱ���е�ѹ���,GPS,3G�ĳ�ʼ������             
 * ��	  �룺SEND_MSG_TO_ALL_CLIENT ������ͻ��˹㲥��Ϣ�Ļص�����
 * ��	  ������
 */


td_s32 Vehcl_DetectVoltage(void);
/*
 * �������ƣ�Vehcl_DetectVoltage
 * ��Ҫ����: �������쳣���ģ��ע��ĺ���           
             ����⵽��Դ��ѹ�����趨�ı�����ѹֵʱ�������쳣����
 * ��	  �룺��
 * ��	  ����0		���쳣
 			  >0	��ѹ�쳣
 */

td_s32 Vehcl_GetVoltageTemperature();
/*
 * �������ƣ�Vehcl_GetVoltageTemperature
 * ��Ҫ����: ��ȡ��ѹ���¶�ֵ,���ڿͻ��˵�¼ʱ���͵�¼��Ϣ
 * ��	  �룺��
 * ��	  ������ѹ���¶�ֵ(��16λ�¶�ֵ,��16λ��ѹֵ)
 */

#if 0
//GPS����
td_s32 Vehcl_SetGPSTimeEnable(int _iEnable);
/*
 * �������ƣ�Vehcl_SetGPSTimeEnable
 * ��Ҫ����: ����ʹ��GPSУʱ
 * ��	  �룺_iEnable	1	ʹ��
 * 						0   ��ʹ��
 * ��	  ����td_success	�ɹ�
 *			  td_failuer	ʧ��
 */
#endif

td_s32 Vehcl_SetGPSMsgChnOverlay(int _iChn,int _iEnable);
/*
 * �������ƣ�Vehcl_SetGPSMsgChnOverlay
 * ��Ҫ����: ����GPS��Ϣͨ������ʹ��
 * ��	  �룺_iChn		ͨ����
 			  _iEnable	1	ʹ��
 * 						0   ��ʹ��
 * ��	  ����td_success	�ɹ�
 *			  td_failuer	ʧ��
 */
 
td_s32 Vehcl_GetGPSModuleType();
/*
 * �������ƣ�Vehcl_GetGPSModuleType
 * ��Ҫ����: ��ȡGPSģ�����ͣ�GPS�򱱶�
 * ��	  �룺��
 * ��	  ����ģ������
 */


td_s32 Vehcl_GetGPSInfor(td_s32 *_iSateNum, td_s32 *_iIntensity);
/*
 * �������ƣ�Vehcl_GetGPSInfor
 * ��Ҫ����: �ͻ��˵�¼ʱ��ȡ��Ҫ���͵�GPS��Ϣ,����������(��16λ)���ź�ǿ��(��16λ)
 * ��	  �룺
 * ��	  ����
 */

td_s32 Vehcl_SetGPSFilter(td_s32 _iFilter);
/*
 * �������ƣ�Vehcl_SetGPSFilter
 * ��Ҫ����:����GPS��Ϣ���� 
 * ��	  �룺��
 * ��	  ������
 */

td_s32 Vehcl_PortAlarmLinkVideoMark();
/*
 * �������ƣ�	Vehcl_PortAlarmLinkVideoMark
 * ��Ҫ����: 	�˿ڱ����������
 * 				��DvrAlarmStatChgNotify�����е���
 *              �������ģ��û�г�ʼ����ֱ�ӷ���
 *				�������ģ���ѳ�ʼ������д�����
 * ��	  �룺	��
 * ��	  ����	td_success	�ɹ�
 *			  	td_failure	ʧ��
 */

td_s32 Vehcl_SetPowerAlarmMsg(td_s32 _iAlarm);
/*
 * �������ƣ�	Vehcl_SetPowerAlarmMsg
 * ��Ҫ����:	���ñ�����ѹֵ
 * ��	  �룺	
 * ��	  ����	td_success	�ɹ�
 *				
 */

td_s32 Vehcl_SetPowerOffMsg(td_s32 _iShutDown);
/*
 * �������ƣ�	Vehcl_SetPowerOffMsg
 * ��Ҫ����:	���ùػ���ѹֵ
 * ��	  �룺	
 * ��	  ����	td_success	�ɹ�
 *				
 */


td_s32 Vehcl_UsbEsataState(td_s32 _iDiskNo);
/*
 * �������ƣ�	Vehcl_UsbEsataState
 * ��Ҫ����:		�յ����̹���ģ��֪ͨ������USB��Esata������Ϣ������¼
 * ��	  �룺	
 * ��	  ����	td_success	�ɹ�
 *			  	
 */
td_s32 Vehcl_Set_WifiFtp_AutoEn(td_s32 _iEnable);

td_s32 Vehcl_Get_WifiFtp_AutoEn();

td_s32 Vehcl_Set_WifiFtp_Manual();
td_s32 Vehcl_IsInited();

td_s32 Vehcl_GetVoltage();

td_s32 Vehcl_GetTemperature();

td_s32 	Vehcl_SendComDataCallBack(SEND_COMDATA_TO_ALL_CLIENT _SendComDataCallBack);


#endif



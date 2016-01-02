/*******************************************************************
�ļ���	:exception.h
��˾	:������ΰҵ����Ƽ����޹�˾
������	:������
��������:2009-10-28
��Ҫ����:�쳣����ģ��궨�塢���ݽṹ���弰�ӿں���ԭ��
�޸ļ�¼:2009-10-28,������������
        
******************************************************************/

#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#define EXCEPTION_TYPES		10

//�쳣״̬
typedef enum
{
	ESTATE_HAPPEN = 0,							//�����쳣
	ESTATE_DISAPPEAR = 1,							//�쳣��ʧ
}TEstate;


//�쳣����
typedef enum
{
	EXP_DISK_FULL = 0,							//������ ������ 091127 1->0
	EXP_NO_DISK = 1,							//�޴��� ������ 091127 new
	EXP_DISK_IOERROR = 2,						//���̶�д���� ������ 091127 3->2
	EXP_ACCESS = 3,								//�Ƿ����� ������ 091127 4->3
	EXP_IP_CONFLICT = 4,						//IP��ͻ ������ 091127 5->4
	EXP_ETHERNET = 5,							//�����ж� ������ 091127 6->5
	EXP_SYSTEMBUSY = 6,                         //ϵͳæ
	EXP_NOREBUNDANCE_DISK = 7,                  //�������� ��ΰ 20130327
	EXP_LOWPOWERVOLTAGE = 8,					//��Դ��ѹ��dce20130823
	EXP_MAC_CONFLICT = 9,                       //MAC��ͻ ׯ־�� 20131024
}TException;


typedef void (*ExcptionReprot)(int _iStat, int _iWho);


td_s32 excp_SetCheckFunction(td_s32 _iId, td_s32 (*_CheckFun)(void));

td_s32 excp_SetEnable(td_s32 _iType, td_s32 _blEnable);
/*
 * �������ƣ�excp_SetEnable
 * ��Ҫ�����������쳣ʹ��
 * ��	  �룺
 * 			_iType, �쳣���ͣ�TException
 * 			_blEnable,ʹ�ܣ�0��1
 * ��	 ����
 * 			ERR_EXCP_SUCCESSFUL,�ɹ�
 *			ERR_EXCP_WRONG_PARAM,����Ĳ���
 *			ERR_EXCP_WRITE_CONFIG,д�����ļ�ʧ��
 * �޸���־��
 * 			2009-10-29,������,����
 */
 
td_s32 excp_GetEnable(td_s32 _iType);
/*
 * �������ƣ�excp_GetEnable
 * ��Ҫ��������ȡ�쳣ʹ��
 * ��	  �룺
 * 			_iType, �쳣���ͣ�TException
 * ��	 ����
 * 			TD_DISABLE,��ʹ��
 *			TD_ENABLE,��ʹ��
 *			ERR_EXCP_WRONG_PARAM,����Ĳ���
 * �޸���־��
 * 			2009-10-29,������,����
 */
 
td_s32 excp_SetParam(td_s32 _iType, td_s32 _blHint, td_s32 _blBuzzer, td_s32 _blNotify);
/*
 * �������ƣ�excp_SetParam
 * ��Ҫ�����������쳣�������
 * ��	  �룺
 * 			_iType, �쳣���ͣ�TException
 *			_blHint,�û�����Ի�����ʾ��TD_ENABLE/TD_DISABLE
 *			_blBuzzer,��������ʾ��TD_ENABLE/TD_DISABLE
 *			_blNotify,֪ͨ����ͻ��ˣ�TD_ENABLE/TD_DISABLE
 * ��	 ����
 * 			ERR_EXCP_SUCCESSFUL,�ɹ�
 *			ERR_EXCP_WRONG_PARAM,����Ĳ���
 *			ERR_EXCP_WRITE_CONFIG,д�����ļ�ʧ��
 * �޸���־��
 * 			2009-10-29,������,����
 */
 
td_s32 excp_GetParam(td_s32 _iType, td_s32* _blHint, td_s32* _blBuzzer, td_s32* _blNotify);
/*
 * �������ƣ�excp_GetParam
 * ��Ҫ��������ȡ�쳣�������
 * ��	  �룺
 * 			_iType, �쳣���ͣ�TException
 *			_blHint,�����û�����Ի�����ʾ���ǿ�
 *			_blBuzzer,������������ʾ���ǿ�
 *			_blNotify,����֪ͨ����ͻ��ˣ��ǿ�
 * ��	 ����
 * 			ERR_EXCP_SUCCESSFUL,�ɹ�
 *			ERR_EXCP_WRONG_PARAM,����Ĳ���
 * �޸���־��
 * 			2009-10-29,������,����
 */
 
//��ȡ�쳣����״̬
td_s32 excp_GetStat(td_s32 _iType);
td_s32 excp_SetStat(td_s32 _iType, td_s32 _iState);


//td_s32 excp_Init(void);
td_s32 excp_Init(ExcptionReprot _ReportUI, ExcptionReprot _ReportNet, ExcptionReprot _ReportUIBuzzer);

/*
 * �������ƣ�excp_Init
 * ��Ҫ�������쳣����ģ���ʼ��
 * ��	  �룺
 * 			��
 * ��	 ����
 * 			ERR_EXCP_SUCCESSFUL,�ɹ�
 *			ERR_EXCP_READ_CONFIG, ��ȡ�����ļ�ʧ��
 *			ERR_EXCP_CREATE_THREAD, �����߳�ʧ��
 * �޸���־��
 * 			2009-10-29,������,����
 */

td_s32 excp_Exit(void);
/*
 * �������ƣ�excp_Exit
 * ��Ҫ�������쳣����ģ���˳�
 * ��	  �룺
 * 			��
 * ��	 ����
 * 			ERR_EXCP_SUCCESSFUL,�ɹ�
 *			ERR_EXCP_FAILED��ʧ��
 * �޸���־��
 * 			2009-10-29,������,����
 */
 
#endif /*_EXCEPTION_H_*/


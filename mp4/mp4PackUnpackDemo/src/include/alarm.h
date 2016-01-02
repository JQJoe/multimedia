/*******************************************************************
�ļ���	:Alarm.c
��˾	:������ΰҵ����Ƽ����޹�˾
������	:������
��������:2008-10-24
��Ҫ����:������ز����Ķ��壬�ӿں���ԭ�͵�
�޸ļ�¼:2008-10-24,������������
        
******************************************************************/

#ifndef ALARM_H
#define ALARM_H

#include "alarmer.h"

#define MAX_OUTPORT_DELAY_TIME	3600			//��󱨾�����˿���ʱʱ��
#define MOTION_DETECT_DELAY_TIME	5			//�ƶ���ⱨ����ʱʱ��
#define MAX_PTZ_LINKAGE_TYPE	3				//���PTZ����������

#define DETECT_INTERVAL		200*1000			//�������ʱ��������λ MicroSecond

//#define 	REC_VCA            32  				//���ܷ�������¼������


// �����ص�(0 : ��ʽ����, 0x0001 : ������, ����λԤ�����������)
typedef void (*AlarmMakeSoundCallBack)(td_s32 _iSndType);
// ����LED ��ʾ�ص�(chn:ͨ����, -1����LED����, stat : 1��ʾ��0����ʾ)
typedef void (*AlarmLedDspCallBack)(td_s32 _iChn, td_s32 _iStat);

// ��������˿�״̬֪ͨ�ص�
typedef void (*AlarmOutPortStatNotifyCallBack)(td_s32 _iPortNo, td_s32 _iStat);
// ����״̬���»ص�(type:��������, chn:ͨ��, stat:����״̬, 1����, 0����)
typedef void (*AlarmStatChgNotifyCallBack)(td_s32 _iType, td_s32 _iChn, td_s32 _iStat);

typedef void (*AlarmSinglePicDspCallBack)(td_s32 _iChn, td_s32 _iAlarm);

//typedef int (*pReportAlarm)(int chn, int state, unsigned int ip);	//����֪ͨ����Ļص�����
typedef int (*MainEventChnParaCallBack)(int _iChn);//�����������¼�Ϊ��ǰ����
typedef int (*AlarmClearExceptionCallBack)(td_s32 _iType, td_s32 _iState);//ȫ������ʱ�����쳣�����ص�

//����������ʽ
typedef enum
{
	LK_SOUND = 0,								//����������ʾ
	LK_DISPLAY,									//������Ļ��ʾ
	LK_OUTPORT,									//������������˿�
	LK_RECORD,									//����¼��
	LK_PTZ,										//����Ԥ��λ
	LK_SNAPSHOT,								//����ץ��
	LK_SINGLE_PIC,								//���˵�������ʾ
	LK_MARKFILE,								//dce add ,�����м���Ķ˿ڱ�������¼����
	LK_MAX,										//���ֵ����ֵ����������ʱʹ�ã�Ҫ��չ�������ڸ�ֵ�������
}TAlarmLinkage;

//����״̬
typedef enum
{
	STATE_DISAPPEAR = 0,						//��������״̬							
	STATE_ALARM,								//��������״̬
	STATE_CLEAR,								//�ֶ�����״̬ ������ 090414 �������޸�BUG���������߼�
}TAlarmState;

//����������ʽ
typedef enum
{
	TR_OPEN = 0,								//�Ͽ���������,����·���������ձ���
	TR_CLOSE,									//�պϴ�������,����·��������������
}TTrigger;

enum
{
	VCA_DISABLE = 0,    //��ʹ�����ܷ���
	VCA_USE_LOCAL,      //ʹ�ܱ���ͨ�����ܷ���
	VCA_USE_REMOTE,		//ʹ��ǰ��ͨ�����ܷ���
}; //���ܷ���ʹ�ܱ�ʶ


//����PTZ�ļ�������
typedef enum
{
	PTZ_NONE = 0,								//������
	PTZ_PRESET,									//����Ԥ��λ
	PTZ_ROUTINE,								//����ģʽ·��
	PTZ_CRUISE,									//����Ѳ���켣
}TPTZType;

//������ 091125 ��ԭ����������Ա����һ������
//����PTZ�Ĳ���
typedef struct
{
	TPTZType	m_ePTZType;						//����PTZ����
	td_s8		m_cChannelNo;					//����ͨ��
	td_u8		m_PTZNo[MAX_PTZ_LINKAGE_TYPE];	//PTZ������
}TPTZLinkage;

//����ʱ���
typedef struct
{
	td_s32		m_iStartHour;					//��ʼʱ
	td_s32		m_iStartMin;					//��ʼ��
	td_s32		m_iStopHour;					//����ʱ
	td_s32		m_iStopMin;						//������
	td_s32		m_blEnable;						//��ʱ��ε�ʹ��
}TTimeSegment;

//��������
typedef struct
{
	td_s8				m_blTimeEnable;							//����ʱ���ʹ��  mode by nsg ����ģ���Ƿ�ʹ��
	td_s8				m_blEnable;								//���ֱ��������Ƿ�����  mode by nsg ��ǰʱ���Ƿ��ڱ���ʱ�����
	TTimeSegment		m_stSegment[7][MAX_TIME_SEGMENT];		//����ʱ���
	td_s8				m_blLinkage[LK_MAX];					//����������ʽ
	TAlarmState			m_eState;								//����״̬
	TTrigger			m_eTrigger;								//����������ʽ
	td_s32				m_blOutPortNo[MAX_OUTPORT_NUM];			//Ҫ�����ı�������˿�
	td_s32				m_iPreset;								//Ҫ������Ԥ��λ��
	td_s32				m_iChannelNum;							//Ҫ����¼���ͨ����Ŀ
	td_s32				m_iRecordChannels[MAX_CHANNEL_NUM];		//Ҫ����¼���ͨ����
	td_s32				m_iSnapNum;								//Ҫ����ץ�ĵ�ͨ����Ŀ
	td_s32				m_iSnapChannels[MAX_CHANNEL_NUM];		//Ҫ����ץ�ĵ�ͨ����
	td_s32				m_iPTZNum;								//Ҫ������PTZͨ����
	TPTZLinkage			m_stPTZLinkage[MAX_CHANNEL_NUM];		//Ҫ������PTZͨ��
}TAlarmParam;

//��������˿�����,
typedef struct
{
	td_s32				m_iDelayTime;							//������ʱʱ�䣬��λ:�룬-1��ʾ����󣬼��ֶ�����
	td_s32				m_iLastTime;							//�����������ʱ��
	td_s32				m_blTimeEnable;							//����ʱ���ʹ��
	td_s32				m_blEnable;								//��������˿�ʹ��
	TAlarmState			m_eState;								//��������˿�״̬
	TTrigger			m_eTrigger;								//����������ʽ
	TTimeSegment		m_stSegment[7][MAX_TIME_SEGMENT];		//����ʱ���
}TOutPortParam;

td_s32 alm_SetAlarmSchedule(TAlarmType _eType, td_s32 _iChannelNo, td_s32 _iEnable, td_s32 _iWeekDay, TTimeSegment* _pstSeg);
/*
 * �������ƣ�SetAlarmSchedule
 * ��Ҫ����: ���ñ������ʱ��κ�ʹ��
 * ��	  �룺
 *			_eType, ��������
 * 			_iChannelNo, 0~MAX_CHANNEL_NUM,ͨ����
 *			_iEnable, 0��1,�Ƿ���ʱ��μ��
 *			_iWeekDay,0~6,����(wday)
 *			_pstSeg, �ǿգ�ʱ���ָ��(����ĸ�ʱ���)
 * ��	  ����
 * 			ERR_ALM_WRONG_PARAM,����Ĳ���
 * 			ERR_ALM_SUCCESSFUL,�����ɹ�
 * 			ERR_ALM_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-11-11,������,����
 *			2009-11-25,������,�ϲ��ӿ�
 */
 
td_s32 alm_GetAlarmSchedule(TAlarmType _eType, td_s32 _iChannelNo, td_s32* _piEnable, td_s32 _iWeekDay, TTimeSegment* _pstSeg);
/*
 * �������ƣ�GetAlarmSchedule
 * ��Ҫ����: ��ȡ�������ʱ��κ�ʹ��
 * ��	  �룺
 *			_eType,��������
 * 			_iChannelNo, 0~MAX_CHANNEL_NUM,ͨ����
 *			_piEnable, �ǿ�,���ڴ����Ƿ���ʱ��μ��
 *			_iWeekDay,0~6,����(wday)
 *			_pstSeg, �ǿգ����ڴ���ʱ���(����ĸ�ʱ���)
 * ��	  ����
 * 			ERR_ALM_WRONG_PARAM,����Ĳ���
 * 			ERR_ALM_SUCCESSFUL,�����ɹ�
 * 			ERR_ALM_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-11-11,������,����
 *			2009-11-25,������,�ϲ��ӿ�
 */

td_s32 alm_SetOutPortSchedule(td_s32 _iPortNo, td_s32 _iEnable, td_s32 _iWeekDay, TTimeSegment* _pstSeg);
/*
 * �������ƣ�SetOutPortSchedule
 * ��Ҫ����: ���ö˿ڱ������ʱ��κ�ʹ��
 * ��	  �룺
 * 			_iPortNo, 0~MAX_OUTPORT_NUM,ͨ����
 *			_iEnable, 0 �� 1,�Ƿ���ʱ��μ��
 *			_iWeekDay,0~6,����(wday)
 *			_pstSeg, �ǿգ�ʱ���ָ��(����ĸ�ʱ���)
 * ��	  ����
 * 			ERR_ALM_WRONG_PARAM,����Ĳ���
 * 			ERR_ALM_SUCCESSFUL,�����ɹ�
 * 			ERR_ALM_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-11-11,������,����
 */
 
td_s32 alm_GetOutPortSchedule(td_s32 _iPortNo, td_s32* _piEnable, td_s32 _iWeekDay, TTimeSegment* _pstSeg);
/*
 * �������ƣ�GetOutPortSchedule
 * ��Ҫ����: ��ȡ��������˿ڼ��ʱ��κ�ʹ��
 * ��	  �룺
 * 			_iPortNo, 0~MAX_OUTPORT_NUM,ͨ����
 *			_piEnable, �ǿ�,���ڴ����Ƿ���ʱ��μ��
 *			_iWeekDay,0~6,����(wday)
 *			_pstSeg, �ǿգ����ڴ���ʱ���(����ĸ�ʱ���)
 * ��	  ����
 * 			ERR_ALM_WRONG_PARAM,����Ĳ���
 * 			ERR_ALM_SUCCESSFUL,�����ɹ�
 * 			ERR_ALM_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-11-11,������,����
 */
 
td_s32 alm_SetAlarmLinkRecord(TAlarmType _eType, td_s32 _iChannelNo, td_s32 _iEnable, td_s32* _iChannelList, td_s32 _iChannelNum);
/*
 * �������ƣ�SetAlarmLinkRecord
 * ��Ҫ����: ���ñ�������¼�����
 * ��	  �룺
 *			_eType,��������
 * 			_iChannelNo, 0~MAX_CHANNEL_NUM,ͨ����
 *			_iEnable, 0 �� 1, �Ƿ�����¼��
 *			_iChannelList, �ǿգ�Ҫ������ͨ������б�
 *			_iChannelNum, 0~MAX_CHANNEL_NUM, ���������ٸ�ͨ��
 * ��	  ����
 * 			ERR_ALM_WRONG_PARAM,����Ĳ���
 * 			ERR_ALM_SUCCESSFUL,�����ɹ�
 * 			ERR_ALM_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-11-11,������,����
 *			2009-11-25,������,�ϲ��ӿ�
 */
 
td_s32 alm_GetAlarmLinkRecord(TAlarmType _eType, td_s32 _iChannelNo, td_s32* _piEnable, td_s32* _iChannels, td_s32* _iChannelNum);
/*
 * �������ƣ�GetAlarmLinkRecord
 * ��Ҫ����: ��ȡ��������¼�����
 * ��	  �룺
 *			_eType,��������
 * 			_iChannelNo, 0~MAX_CHANNEL_NUM,ͨ����
 *			_piEnable, 0 �� 1, ���ڴ����Ƿ�����¼��
 *			_iChannels, �ǿգ����ڴ���Ҫ������ͨ������б�
 *			_iChannelNum, 0~MAX_CHANNEL_NUM, ���ڴ������������ٸ�ͨ��
 * ��	  ����
 * 			ERR_ALM_WRONG_PARAM,����Ĳ���
 * 			ERR_ALM_SUCCESSFUL,�����ɹ�
 * 			ERR_ALM_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-11-11,������,����
 *			2009-11-25,������,�ϲ��ӿ�
 */
 
td_s32 alm_SetAlarmLinkSound(TAlarmType _eType, td_s32 _iChannelNo, td_s32 _iEnable);
/*
 * �������ƣ�SetAlarmLinkSound
 * ��Ҫ����: ���ñ�������������ʾʹ��
 * ��	  �룺
 * 			_iChannelNo, 0~MAX_CHANNEL_NUM,ͨ����
 *			_iEnable, 0 �� 1, �Ƿ�����������ʾ
 * ��	  ����
 * 			ERR_ALM_WRONG_PARAM,����Ĳ���
 * 			ERR_ALM_SUCCESSFUL,�����ɹ�
 * 			ERR_ALM_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-11-11,������,����
 *			2009-11-25,������,�ϲ��ӿ�
 */
 
td_s32 alm_GetAlarmLinkSound(TAlarmType _eType, td_s32 _iChannelNo, td_s32* _piEnable);
/*
 * �������ƣ�GetAlarmLinkSound
 * ��Ҫ����: ��ȡ��������������ʾʹ��
 * ��	  �룺
 *			_eType,��������
 * 			_iChannelNo, 0~MAX_CHANNEL_NUM,ͨ����
 *			_piEnable, �ǿ�, ���ڴ����Ƿ�����������ʾ
 * ��	  ����
 * 			ERR_ALM_WRONG_PARAM,����Ĳ���
 * 			ERR_ALM_SUCCESSFUL,�����ɹ�
 * 			ERR_ALM_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-11-11,������,����
 *			2009-11-25,������,�ϲ��ӿ�
 */
 
td_s32 alm_SetAlarmLinkDisplay(TAlarmType _eType, td_s32 _iChannelNo, td_s32 _iEnable);
/*
 * �������ƣ�SetAlarmLinkDisplay
 * ��Ҫ����: ���ñ���������Ļ��ʾʹ��
 * ��	  �룺
 *			_eType, ��������
 * 			_iChannelNo, 0~MAX_CHANNEL_NUM,ͨ����
 *			_iEnable, 0 �� 1, �Ƿ�������Ļ��ʾ
 * ��	  ����
 * 			ERR_ALM_WRONG_PARAM,����Ĳ���
 * 			ERR_ALM_SUCCESSFUL,�����ɹ�
 * 			ERR_ALM_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-11-11,������,����
 *			2009-11-25,������,�ϲ��ӿ�
 */
 
td_s32 alm_GetAlarmLinkDisplay(TAlarmType _eType, td_s32 _iChannelNo, td_s32* _piEnable);
/*
 * �������ƣ�GetAlarmLinkDisplay
 * ��Ҫ����:��ȡ����������Ļ��ʾʹ��
 * ��	  �룺
 *			_eType,��������
 * 			_iChannelNo, 0~MAX_CHANNEL_NUM,ͨ����
 *			_piEnable, �ǿ�, ���ڴ����Ƿ�������Ļ��ʾ
 * ��	  ����
 * 			ERR_ALM_WRONG_PARAM,����Ĳ���
 * 			ERR_ALM_SUCCESSFUL,�����ɹ�
 * 			ERR_ALM_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-11-11,������,����
 *			2009-11-25,������,�ϲ��ӿ�
 */

td_s32 alm_GetAlarmLinkSingPic(TAlarmType _eType, td_s32 _iChannelNo, td_s32* _piChn);
/*
 * �������ƣ�alm_GetAlarmLinkSingPic
 * ��Ҫ����:��ȡ����������������ʾͨ��
 * ��	  �룺
 *			_eType,��������
 * 			_iChannelNo, 0~MAX_CHANNEL_NUM,������ͨ����
 *			_piChn, �ǿ�, ���ڴ��������ĸ�ͨ����������ʾ(ͨ����+1��0��ʽ������)
 * ��	  ����
 * 			ERR_ALM_WRONG_PARAM,����Ĳ���
 * 			ERR_ALM_SUCCESSFUL,�����ɹ�
 * 			ERR_ALM_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2011-04-07,������,����
 */

td_s32 alm_SetAlarmLinkSingPic(TAlarmType _eType, td_s32 _iChannelNo, td_s32 iChn);
/*
 * �������ƣ�alm_SetAlarmLinkSingPic
 * ��Ҫ����:���ñ���������������ʾͨ��
 * ��	  �룺
 *			_eType,��������
 * 			_iChannelNo, 0~MAX_CHANNEL_NUM,������ͨ����
 *			_piChn, �ǿ�, ���ڴ��������ĸ�ͨ����������ʾ(ͨ����+1��0��ʽ������)
 * ��	  ����
 * 			ERR_ALM_WRONG_PARAM,����Ĳ���
 * 			ERR_ALM_SUCCESSFUL,�����ɹ�
 * 			ERR_ALM_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2011-04-07,������,����
 */

// ����20120418 ��������������Ѳ��ʱ���������ȡ
td_s32 alm_SetAlarmLInkSingPicIntv(td_s32 _iInterval);
td_s32 alm_GetAlarmLInkSingPicIntv(void);

td_s32 alm_SetAlarmLinkOutPort(TAlarmType _eType, td_s32 _iChannelNo, td_s32 _iEnable, td_s32* _piOutPortNo);
/*
 * �������ƣ�SetAlarmLinkOutPort
 * ��Ҫ����: ���ñ���������������˿ڲ���
 * ��	  �룺
 *			_eType,��������
 * 			_iChannelNo, 0~MAX_CHANNEL_NUM,ͨ����
 *			_iEnable, 0 �� 1, �Ƿ���������˿�
 *			_iOutPortNo, 0~MAX_OUTPORT_NUM, Ҫ����������˿ں�
 * ��	  ����
 * 			ERR_ALM_WRONG_PARAM,����Ĳ���
 * 			ERR_ALM_SUCCESSFUL,�����ɹ�
 * 			ERR_ALM_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-11-11,������,����
 *			2009-11-25,������,�ϲ��ӿ�
 */
 
td_s32 alm_GetAlarmLinkOutPort(TAlarmType _eType, td_s32 _iChannelNo, td_s32* _piEnable, td_s32* _piOutPortNo);
/*
 * �������ƣ�GetAlarmLinkOutPort
 * ��Ҫ����:��ȡ������������˿ڲ���
 * ��	  �룺
 *			_eType,��������
 * 			_iChannelNo, 0~MAX_CHANNEL_NUM,ͨ����
 *			_piEnable, �ǿ�, ���ڴ����Ƿ���������˿�
 *			_piOutPortNo, �ǿգ����ڴ���Ҫ����������˿ں�
 * ��	  ����
 * 		ERR_ALM_WRONG_PARAM,����Ĳ���
 * 		ERR_ALM_SUCCESSFUL,�����ɹ�
 * 		ERR_ALM_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-11-11,������,����
 *			2009-11-25,������,�ϲ��ӿ�
 */
 
td_s32 alm_SetAlarmLinkSnap(TAlarmType _eType, td_u64 _ulChannelNo, td_s32 _iEnable, td_s32 _iChannelNum, td_s32* _piChannels);
/*
 * �������ƣ�SetAlarmLinkSnap
 * ��Ҫ����: ���ñ�������ץ�Ĳ���
 * ��	  �룺
 *			_eType, ��������
 * 			_iChannelNo, 0~MAX_CHANNEL_NUM,ͨ����
 *			_iEnable, 0 �� 1, �Ƿ�����¼��
 *			_piChannels, �ǿգ�Ҫ������ͨ������б�
 *			_iChannelNum, 0~MAX_CHANNEL_NUM, ���������ٸ�ͨ��
 * ��	  ����
 * 			ERR_ALM_WRONG_PARAM,����Ĳ���
 * 			ERR_ALM_SUCCESSFUL,�����ɹ�
 * 			ERR_ALM_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-11-11,������,����
 *			2009-11-25,������,�ϲ��ӿ�
 */
 
td_s32 alm_GetAlarmLinkSnap(TAlarmType _eType, td_s32 _iChannelNo, td_s32* _piEnable, td_s32* _piChannelNum, td_s32* _piChannels);
/*
 * �������ƣ�GetAlarmLinkSnap
 * ��Ҫ����: ��ȡ��������ץ�Ĳ���
 * ��	  �룺
 *			_eType, ��������
 * 			_iChannelNo, 0~MAX_CHANNEL_NUM,ͨ����
 *			_piEnable, 0 �� 1, ���ڴ����Ƿ�����¼��
 *			_piChannels, �ǿգ����ڴ���Ҫ������ͨ������б�
 *			_piChannelNum, 0~MAX_CHANNEL_NUM, ���ڴ������������ٸ�ͨ��
 * ��	  ����
 * 			ERR_ALM_WRONG_PARAM,����Ĳ���
 * 			ERR_ALM_SUCCESSFUL,�����ɹ�
 * 			ERR_ALM_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-11-11,������,����
 *			2009-11-25,������,�ϲ��ӿ�
 */
 
td_s32 alm_SetAlarmLinkPTZ(TAlarmType _eType, td_s32 _iChannelNo, td_s32 _iEnable, td_s32 _iChannelNum, TPTZLinkage* _pstLinkage);
/*
 * �������ƣ�SetAlarmLinkPTZ
 * ��Ҫ����: ���ñ�������PTZ����
 * ��	  �룺
 *			_eType, ��������
 * 			_iChannelNo, 0~MAX_CHANNEL_NUM,ͨ����
 *			_iEnable, 0 �� 1, �Ƿ�����¼��
 *			_pstLinkage, �ǿգ�Ҫ������ͨ����PTZ�����б�
 *			_iChannelNum, 0~MAX_CHANNEL_NUM, ���������ٸ�ͨ��
 * ��	  ����
 * 			ERR_ALM_WRONG_PARAM,����Ĳ���
 * 			ERR_ALM_SUCCESSFUL,�����ɹ�
 * 			ERR_ALM_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-11-11,������,����
 *			2009-11-25,������,�ϲ��ӿ�
 */
 
td_s32 alm_GetAlarmLinkPTZ(TAlarmType _eType, td_s32 _iChannelNo, td_s32* _piEnable, td_s32* _piChannelNum, TPTZLinkage* _pstLinkage);
/*
 * �������ƣ�GetAlarmLinkPTZ
 * ��Ҫ����: ��ȡ��������PTZ����
 * ��	  �룺
 *			_eType, ��������
 * 			_iChannelNo, 0~MAX_CHANNEL_NUM,ͨ����
 *			_piEnable, 0 �� 1, ���ڴ����Ƿ�����¼��
 *			_pstLinkage, �ǿգ����ڴ���Ҫ������ͨ����PTZ�����б�
 *			_piChannelNum, 0~MAX_CHANNEL_NUM, ���ڴ������������ٸ�ͨ��
 * ��	  ����
 * 			ERR_ALM_WRONG_PARAM,����Ĳ���
 * 			ERR_ALM_SUCCESSFUL,�����ɹ�
 * 			ERR_ALM_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-11-11,������,����
 *			2009-11-25,������,�ϲ��ӿ�
 */

td_s32 alm_SetAlarmLinkPTZbyNet(TAlarmType _eType, td_s32 _iChannelNo, td_s32 _iLinkChannel, td_s32 _iLinkType, td_s32 _iLinkNo);
/*
 * �������ƣ�SetAlarmLinkPTZbyNet
 * ��Ҫ����: ͨ���������ñ�������PTZ
 * ��	  �룺
 *			_eType, ��������
 *			_iChannelNo, �����õ�ͨ���ţ�0~MAX_CHANNEL_NUM
 *			_iLinkChannel, ��������ͨ���ţ�0~MAX_CHANNEL_NUM
 *			_iLinkType, �������ͣ� TPTZLinkage
 *			_iLinkNo, Ԥ��λ�š��켣�Ż�·����
 * ��	  ����
 *			ERR_ALM_WRONG_PARAM,����Ĳ���
 * 			ERR_ALM_SUCCESSFUL,�����ɹ�
 * 			ERR_ALM_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-12-09,������,����
 *			2009-11-25,������,�ϲ��ӿ�
 */
 
td_s32 alm_SetPortAlarmTrigger(td_s32 _iPortNo, td_s32 _iTrigger);
/*
 * �������ƣ�SetPortAlarmTrigger
 * ��Ҫ����: ���ö˿ڱ����Ĵ�����ʽ
 * ��	  �룺
 * 			_iPortNo, 0~MAX_INPORT_NUM,ͨ����
 *			_iTrigger, 0 �� 1, 0Ϊ��·������1Ϊ��·����
 * ��	  ����
 * 		ERR_ALM_WRONG_PARAM,����Ĳ���
 * 		ERR_ALM_SUCCESSFUL,�����ɹ�
 * 		ERR_ALM_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-11-11,������,����
 */
 
td_s32 alm_GetPortAlarmTrigger(td_s32 _iPortNo, td_s32* _piTrigger);
/*
 * �������ƣ�GetPortAlarmTrigger
 * ��Ҫ����: ��ȡ�˿ڱ����Ĵ�����ʽ
 * ��	  �룺
 * 			_iPortNo, 0~MAX_INPORT_NUM,ͨ����
 *			_piTrigger, �ǿգ����ڴ����ö˿ڵĴ�����ʽ, 0Ϊ��·������1Ϊ��·����
 * ��	  ����
 * 		ERR_ALM_WRONG_PARAM,����Ĳ���
 * 		ERR_ALM_SUCCESSFUL,�����ɹ�
 * 		ERR_ALM_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-11-11,������,����
 */
 
td_s32 alm_SetOutPortParam(td_s32 _iPortNo, td_s32 _iTrigger, td_s32 _iDelayTime);
/*
 * �������ƣ�SetOutPortParam
 * ��Ҫ����: ���ñ�������˿ڲ���
 * ��	  �룺
 * 			_iPortNo, 0~MAX_OUTPORT_NUM,ͨ����
 *			_iTrigger, 0 �� 1, 0Ϊ��·������1Ϊ��·����
 *			_iDelayTime,,������ʱʱ�䣬 0~MAX_OUTPORT_DELAY_TIME,��Ϊ-1���ʾ�ֶ�������������ʱ
 * ��	  ����
 * 		ERR_ALM_WRONG_PARAM,����Ĳ���
 * 		ERR_ALM_SUCCESSFUL,�����ɹ�
 * 		ERR_ALM_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-11-11,������,����
 */
 
td_s32 alm_GetOutPortParam(td_s32 _iPortNo, td_s32* _piTrigger, td_s32* _piDelayTime);
/*
 * �������ƣ�GetOutPortParam
 * ��Ҫ����: ��ȡ��������˿ڲ���
 * ��	  �룺
 * 			_iPortNo, 0~MAX_OUTPORT_NUM,ͨ����
 *			_piTrigger, 0 �� 1, 0Ϊ��·������1Ϊ��·����
 *			_piDelayTime, �ǿ�,���ڴ���������ʱʱ�䣬0~MAX_OUTPORT_DELAY_TIME,��Ϊ-1���ʾ�ֶ�������������ʱ
 * ��	  ����
 * 		ERR_ALM_WRONG_PARAM,����Ĳ���
 * 		ERR_ALM_SUCCESSFUL,�����ɹ�
 * 		ERR_ALM_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-11-11,������,����
 */
 
//td_s32 alm_GotoPreset(td_s32 _iChannelNo, td_s32 _iPresetNo);
/*
 * �������ƣ�GptoPreset
 * ��Ҫ����: ����Ԥ��λ
 * ��	  �룺
 * 			_iChannelNo,ͨ����,0~15
 * 			_iPresetNo,Ԥ��λ��,0~64
 * ��	  ����
 * 		ERR_ALM_WRONG_PARAM,����Ĳ���
 * 		ERR_ALM_SUCCESSFUL,����Ԥ��λ�ɹ�
 * 		ERR_ALM_WRITE_COM_FAILED,�򴮿�д����ʧ��
 * 		ERR_ALM_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-10-24,������,����
 */
 
//td_s32 alm_HandleMotionDetect(td_s32 _iChannelNo);
/*
 * �������ƣ�HandleMotionDetect
 * ��Ҫ����: �ƶ������Ļص�����
 * ��	  �룺
 * 			_iChannelNo,ͨ����,0~MAX_CHANNEL_NUM
 * ��	  ����
 * 		ERR_ALM_WRONG_PARAM,����Ĳ���
 * 		ERR_ALM_SUCCESSFUL,�����ɹ�
 * 		ERR_ALM_WRITE_COM_FAILED,�򴮿�д����ʧ��
 * 		ERR_ALM_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-10-24,������,����
 */
#if 0
td_s32 alm_HandleVideoLost(td_s32 _iChannelNo, td_s32 _iState);
/*
 * �������ƣ�HandleVideoLost
 * ��Ҫ����: ��Ƶ��ʧ�������ص�����
 * ��	  �룺
 * 			_iChannelNo,ͨ����,0~MAX_CHANNEL_NUM
 *			_iState, ����״̬��0������ 1����
 * ��	  ����
 * 		ERR_ALM_WRONG_PARAM,����Ĳ���
 * 		ERR_ALM_SUCCESSFUL,�����ɹ�
 * 		ERR_ALM_WRITE_COM_FAILED,�򴮿�д����ʧ��
 * 		ERR_ALM_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-12-26,������,����
 */
#endif
td_s32 alm_GetPortNum(td_s32 * _piInPort, td_s32 * _piOutPort);
/*
 * �������ƣ�GetPortNum
 * ��Ҫ����: ��ȡ������������˿���
 * ��	  �룺
 * 			_piInPort,���ڴ�������˿������ǿ�
 *			_piOutPort,���ڴ�������˿������ǿ�
 * ��	  ����
 * 		ERR_ALM_WRONG_PARAM,����Ĳ���
 * 		ERR_ALM_SUCCESSFUL,�����ɹ�
 * 		ERR_ALM_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-12-2,������,����
 */

td_s32 alm_ClearAllAlarm(td_s32 _iAlarmType);
/*
 * �������ƣ�ClearAllAlarm
 * ��Ҫ����: �������б���
 * ��	  �룺
 * 			_iAlarmType, ��������,3~5,0xFF
 * ��	  ����
 * 		ERR_ALM_SUCCESSFUL,�����ɹ�
 * 		ERR_ALM_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-12-7,������,����
 */
td_s32 alm_ClearAlarm(td_s32 _iAlarmType, td_s32 _iChn);//wangsong16D1
/*
 *��������:ClearAlarm
 *��Ҫ����:��������,��ͨ���Ż��߶˿ں�
 *����:
 *		_iAlarmType,��������
 *		_iChn,ͨ���Ż��߶˿ں�
 */
td_s32 alm_DefaultCfg(void);
/*
 * �������ƣ�DefaultCfg
 * ��Ҫ����: �ָ���ʼ����
 *			��
 * ��	  ����
 * 		ERR_ALM_SUCCESSFUL,�����ɹ�
 *		ERR_ALM_OPEN_FILE_ERROR,���ļ�����
 *		ERR_ALM_WRITE_FILE_ERROR,д�ļ�����
 * 		ERR_ALM_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-12-09,������,����
 */

td_s32 alm_WriteCfg();
/*
 * �������ƣ�DefaultCfg
 * ��Ҫ����: �ָ���ʼ����
 *			��
 * ��	  ����
 * 		ERR_ALM_SUCCESSFUL,�����ɹ�
 *		ERR_ALM_OPEN_FILE_ERROR,���ļ�����
 *		ERR_ALM_WRITE_FILE_ERROR,д�ļ�����
 * 		ERR_ALM_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-12-09,������,����
 */


td_s32 alm_InitBefor();

td_s32 alm_Init(TComInstance *_ptAlarmerHostCom, void (*ComDataProc)(td_s32, td_s32, td_u8 *));
/*
 * �������ƣ�Init
 * ��Ҫ����: ��ʼ������ģ��
 * ��	  �룺
 * 			��
 * ��	  ����
 * 		ERR_ALM_WRONG_PARAM,����Ĳ���
 * 		ERR_ALM_SUCCESSFUL,����Ԥ��λ�ɹ�
 * 		ERR_ALM_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-11-4,������,����
 */

td_s32 alm_Exit();
/*
 * �������ƣ�Exit
 * ��Ҫ����: �˳�����ģ��
 * ��	  �룺
 * 			��
 * ��	  ����
 * 		ERR_ALM_WRONG_PARAM,����Ĳ���
 * 		ERR_ALM_SUCCESSFUL,����Ԥ��λ�ɹ�
 * 		ERR_ALM_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-11-5,������,����
 */

td_s32 alm_ChangeOutPort(td_s32 _iPortNo, td_s32 _iState);
/*
 * �������ƣ�ChangeOutPort
 * ��Ҫ����: �ı䱨������˿�״̬
 * ��	  �룺
 * 			_iPortNo, ����˿ں�, 0~ MAX_OUTPORT_NUM
 *			_iState, ����˿�״̬��1���պϣ�0���Ͽ�
 * ��	  ����
 * 		ERR_ALM_WRONG_PARAM,����Ĳ���
 * 		ERR_ALM_SUCCESSFUL,����Ԥ��λ�ɹ�
 * 		ERR_ALM_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2009-03-11,������,����
 */

td_s32 alm_GetOutPortState(td_s32 _iPortNo);
/*
 * �������ƣ�GetOutPortState
 * ��Ҫ����: ��ȡ��������˿�״̬
 * ��	  �룺
 * 			_iPortNo, ����˿ں�, 0~ MAX_OUTPORT_NUM
 * ��	  ����
 * 			1���պϣ�0���Ͽ�
 * �޸���־��
 * 			2009-06-10,������,����
 */
 
td_s32 alm_GetState(td_s32 _iChannelNo, TAlarmType _eType);
/*
 * �������ƣ�GetState
 * ��Ҫ����: ��ȡ����ͨ���ĸ��ֱ�����״̬
 * ��	  �룺
 * 			_iChannelNo, ͨ����, 0~ MAX_CHANNEL_NUM
 *			_eType, �������ͣ�TAlarmType
 * ��	  ����
 * 		-1, ��������
 * 		TAlarmState, ����״̬
 * �޸���־��
 * 			2009-04-20,������,����
 */
 
//td_s32 alm_AlarmLinkage(TAlarmType _eType, td_s32 _iNo, td_s32 _iState);
//void alm_PortAlarmTimer(unsigned long _param);
void alm_CheckScheduleTimer(unsigned long _param);
//void alm_ClearAlarmTimer(unsigned long _param);
//void alm_VideoLostTimer(unsigned long _param);
//void alm_CheckSlaveMdTimer(unsigned long _param);

td_s32 alm_ChangeOutPortAlarmState(td_s32 _iPortNo, td_s32 _iState);
/*
 * �������ƣ�ChangeOutPortAlarmState
 * ��Ҫ����: ���Ʊ�������˿ڵ�״̬
 * ��	  �룺
 * 			_iPortNo, ����˿ں�, 0~ MAX_OUTPORT_NUM
 *			_iState, �˿�״̬��1��������0������
 * ��	  ����
 * 			ERR_ALM_SUCCESSFUL, �����ɹ�
 * 			ERR_ALM_FAILED, ����ʧ��
 * �޸���־��
 * 			2009-09-07,������,����
 */


td_s32 alm_CD_LinkBuzzer(td_s32 _iState);
/*
	*��������:alm_CD_LinkBuzzer
	*��Ҫ����:��¼ʱ��������������
	*����: _iState:
		   STATE_ALARM ��������״̬
		   STATE_DISAPPEAR ��������״̬
	*���: 
	       ERR_ALM_SUCCESSFUL, �����ɹ�
  		   ERR_ALM_FAILED, ����ʧ��
  	*�޸���־:
  			2010/11/17�� ʯʤ��
*/


// ע�ᱨ��״̬�ı�֪ͨ����
td_s32 alm_RegAlarmStatChgNotify(AlarmStatChgNotifyCallBack _CallBack);

// ע�ᱨ�����״̬֪ͨ����
td_s32 alm_RegOutPortStatNofify(AlarmOutPortStatNotifyCallBack _CallBack);

// ���������ص�����
td_s32 alm_SetMakeSoundCallBack(AlarmMakeSoundCallBack  _MakeSound);

// ����LED��ʾ�ص�
td_s32 alm_SetLedDspCallBack(AlarmLedDspCallBack _LedDsp);

// ���ñ���������������ʾ�ص�
td_s32 alm_SetSinglePicDspCallBack(AlarmSinglePicDspCallBack _CallBack);

// ע��һ��������
// type : ���������� ALM_MD, ALM_PORT�� 
// chn : �䵱���౨���ĵڶ���·
// alarm : ������ʵ�� 
td_s32 alm_RegAlarmer(td_s32 _iType, int _iChn, TAlarmer *_ptAlarm);

// ��ⱨ����ʵ�����ұ���ͨ����������
td_s32 alm_GetAlarmerMesg(TAlarmer *_ptAlarm, td_s32 *_iType, td_s32 *_iNo);
 
//zhangweiwei add 20120113
int  alm_SetInPortAlarmerOrder(int _iOrder);

int alm_GetInPortAlarmerOrder(void);

int alm_UiGetOutPortAlarmState(int _portNo, int * _pState, char * _strMsg, char * _strName);

int alm_UiSetOutPortAlarmState(int _portNo, int _iState);
//�ֶ�����ʱ֪ͨ�쳣����ģ������
td_s32 alm_RegClearExceptionCallBack(AlarmClearExceptionCallBack _AlarmClearExceptionCallBack);

//add by nsg 20120524
td_s32 vca_alm_GetAlarmLinkOutPort(td_s32 _iChannelNo, td_s32 _iRulesNo, TVcaEventType _eType,  td_s32* _piEnable, td_s32* _piOutPortNo);
td_s32 vca_alm_SetAlarmLinkOutPort(td_s32 _iChannelNo, td_s32 _iRulesNo, TVcaEventType _eType, td_s32 _iEnable, td_s32* _piOutPortNo);
td_s32 vca_alm_GetAlarmSchedule(td_s32 _iChannelNo, td_s32 _iRulesNo, TVcaEventType _eType, td_s32 _iWeekDay, td_s32* _piEnable, TTimeSegment* _pstSeg);
td_s32 vca_alm_SetAlarmSchedule(td_s32 _iChannelNo, td_s32 _iRulesNo, TVcaEventType _eType, td_s32 _iWeekDay, td_s32 _iEnable, TTimeSegment* _pstSeg);
td_s32 vca_alm_GetAlarmLinkDisplay(td_s32 _iChannelNo, td_s32 _iRulesNo, TVcaEventType _eType, td_s32 * _piEnable);
td_s32 vca_alm_SetAlarmLinkDisplay(td_s32 _iChannelNo, td_s32 _iRulesNo, TVcaEventType _eType, td_s32 _iEnable);
td_s32 vca_alm_GetAlarmLinkSingPic(td_s32 _iChannelNo, td_s32 _iRulesNo, TVcaEventType _eType, td_s32 *_piChn );
td_s32 vca_alm_SetAlarmLinkSingPic(td_s32 _iChannelNo, td_s32 _iRulesNo, TVcaEventType _eType, td_s32 _iChn );
td_s32 vca_alm_GetAlarmLinkSnap(td_s32 _iChannelNo, td_s32 _iRulesNo, TVcaEventType _eType, td_s32* _piEnable, td_s32* _piChannelNum, td_s32* _piChannels);
td_s32 vca_alm_SetAlarmLinkSnap(td_s32 _iChannelNo, td_s32 _iRulesNo, TVcaEventType _eType, td_s32 _iEnable, td_s32 _iChannelNum, td_s32* _piChannels);
td_s32 vca_alm_GetAlarmLinkRecord( td_s32 _iChannelNo, td_s32 _iRulesNo, TVcaEventType _eType,  td_s32* _piEnable, td_s32* _iChannels, td_s32* _iChannelNum);
td_s32 vca_alm_SetAlarmLinkRecord(td_s32 _iChannelNo, td_s32 _iRulesNo, TVcaEventType _eType, td_s32 _iEnable, td_s32* _iChannelList, td_s32 _iChnTotalNum);
td_s32 vca_alm_GetAlarmLinkSound(td_s32 _iChannelNo, td_s32 _iRulesNo, TVcaEventType _eType, td_s32* _piEnable);
td_s32 vca_alm_SetAlarmLinkSound(td_s32 _iChannelNo, td_s32 _iRulesNo, TVcaEventType _eType, td_s32 _iEnable);
td_s32 vca_alm_GetAlarmLinkPTZ(td_s32 _iChannelNo, td_s32 _iRulesNo, TVcaEventType _eType, td_s32* _piEnable, td_s32* _piChannelNum, TPTZLinkage* _pstLinkage);
td_s32 vca_alm_SetAlarmLinkPTZ(td_s32 _iChannelNo, td_s32 _iRulesNo, TVcaEventType _eType, td_s32 _iEnable, td_s32 _iChnTotalNum, TPTZLinkage* _pstLinkage );
td_s32 vca_alm_SetAlarmLinkPTZbyNet(td_s32 _iChannelNo, td_s32 _iRulesNo, TVcaEventType _eType, td_s32 _iLinkType, td_s32 _iLinkChannel, td_s32 _iLinkNo);
td_s32 vca_TellUIAndIEAlarmStop(int _iChn, int _iRuleNum, TVcaEventType _eEventType);

//add by nsg120613
//��ʼ���������ץ��ȫ�ֱ���
int alm_LinkMulitSnapParamInit();
//end

void alm_ClearVCAAlarm(int _chn, int _rule, TVcaEventType _type);
/*
 * �������ƣ�alm_ClearVCAAlarm
 * ��Ҫ����: ������ܷ�����������������
 *�������������ܷ�����Ϣ�����������У�һ��ͬһ������������¼����ͣ�
 * �򱨾��������޷�ֹͣ��ֻ�������ù����¼�ʱ��ձ�������
 * ��	  �룺
 * 			_chn, ͨ����, 0~ ��Чͨ��
 *			_rule, ���ܷ�������ã�0~7
 *          _type, ���ܷ����¼����� VCA_TRIPWIRE~VCA_CAP
 * ��	  ����
 * 			��
 * �޸���־��
 * 			2012-1031,������,����
 */

TOutPortParam* alm_GetOutPortStatus(void);

//dce add,��������л���������(�¼�)
void alm_RegMainEventNotify(MainEventChnParaCallBack _MainEventCallBack);


//�����������ץ��
typedef struct  TAlarmInforType
{
	td_u64 m_ulTriggerSource;   //����Դ
	int m_iAlarmType;		//��������
	struct  TAlarmInforType *m_stListNext;
}TAlarmInform;

typedef struct TMultiSnapShotTyp
{
	td_s32 	m_iSecond;	//ʱ�����
	td_s32* m_piInterval;	//ץ��ʱ����
	td_s32*	m_piType;	//ץ��ģʽ0����ʹ�� 1��ʹ�ܣ���ʱ�� 2:����������ץ�ģ�3�������������ץ��

	//20121120 SUN Wei modify for vca_linkage start
	//td_s32  m_RecTypeCount[REC_BASIC_TYPE];	//��¼ÿ����������ץ��ͼƬ���͵Ĵ����Ĵ���
	td_s32  m_RecTypeCount[16];	//16�־��鰴λ��ʾ 0~7�Ѷ��壬8-15δ���壬modified by sunwei for vca_linkage
	//20121120 SUN Wei modify for vca_linkage end

	td_u64  m_ulTrigger;					//����Դ�ţ���λ��ʾ��������һ������Դ�����˴�ͨ��

	//SUN Wei 20130722 �����ڹ̶�����ץ��ģʽ�£�����ץ������
	td_s32  m_iCount;					//��¼��ͨ������������ 
	
	TAlarmInform *m_stListHead;
	pthread_mutex_t m_Mutexlock;

	int (*AddList)(td_u64 _ulTrigger, TAlarmType iAlarmType, struct TMultiSnapShotTyp *stSnapShotParam);
	int (*DelList)(td_u64 _ulTrigger, TAlarmType iAlarmType, struct TMultiSnapShotTyp *stSnapShotParam);
	
}TMultiSnapShot;

//ץ��ģʽ
enum
{
	SNAPSHOT_DISABLE = 0,    //��ʹ��
	SNAPSHOT_ENABLE,         //ʹ�� 
	SINGLESHOT,              //����ץ��
	MULTISNAPSHOT,		     //�����������ץ��ģʽ
	PRESETSHOTNUM,           //Ԥ��ץ������ģʽ
}; 

//�����������ץ�� end

#endif  /*ALARM_H*/


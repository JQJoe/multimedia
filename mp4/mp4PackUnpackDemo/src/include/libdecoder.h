#ifndef _LIB_DECODER_H
#define _LIB_DECODER_H

#include "public_def.h"
#include "ptz.h"
#include "td_types.h"
#include "guiparameter.h"
/*
	��Ҫ����:
	1�������������DVR֮��Ĳ��죬�������������ģ��ֱ�ӵ���
	        ����ĳ����ʾ�豸��ĳ������Ĳ����任Ϊ��ĳ������ͨ���Ĳ�����
                ����Ĳ���������
                ����/�Ͽ���Ƶ
                ��/�ر���ƵԤ��
                ��/�رնԽ�
                �豸����/����͸��ͨ������
                ��ʼ/ֹͣPUSH�� 
	2���û����úͻ�ȡ�л��б�ֱ�Ӳ��������ļ���
	3�����л��������п��ƣ���ʼ/ֹͣ�ѻ��л�������
	               
*/

#define LOOPNVS_MAX_NUM		64		//�л��б����󳤶�Ϊ64

#define DEC_MAX_VO_DEV_NUM		2
#define DEC_MAX_VO_CHN_NUM		16
#define DEC_MAX_CHN_NUM			32

/*
	������Ŀǰ������VOdev,Ϊ��ʵ�ֽ�����ͨ��1:VGA+BNC  2:HDMI,��Ҫ���·���ͨ����
	����ת��
*/
//#define DecChanNoSwitch(_iChanNo)  ((0 == (_iChanNo)) ? 1 : 0)	

/*��Ƶͨ��ѭ������======================================*/
typedef struct
{
    td_s32			m_iEnable;			//�Ƿ�ѭ��1��ѭ��
    td_s32			m_iCount;			//ѭ�������ж�������
    td_s32			m_iIndex;			//Ŀǰ���ĸ�����
    td_s32			m_iAudio;			//Ŀǰ���ĸ���Ƶ���
    td_s32 			m_iTalk;				//�Ƿ����ڽ��жԽ�
    TDECNVSITEM	m_strNVSItem[LOOPNVS_MAX_NUM];	
} TLoopNvsItem; 

typedef enum
{
	DEC_ENABLEID_START = 0x13000,	// ������ʹ��ID ��ʼ
	DEC_SAVELASTFRAME,			// Ԥ���������һ֡
	DEC_PREVIEWPREFER,			// Ԥ��ƫ��

	DEC_ENABLEID_END = 0x13fff,	// ������ʹ��ID ����
} DEC_ENABLEID;


//����һ���ص�����
typedef int  (*EVENT_VIEWSTATE)(int _iChn,int _iPic, TDECNVSITEM* _nvsItem,int  _iState);
typedef void (*DEC_RESTARTAPPCALLBAK)();


td_s32 Dec_Init(EVENT_VIEWSTATE _eViewState);


/*
	�������ļ��л�ȡ�л��б�
*/
td_s32  Dec_GetLoopItem(TLoopNvsItem* _LoopItem, int _iChan, int _iPic);


/*
	���л��б��浽�����ļ���
*/
td_s32 Dec_SetLoopItem(TLoopNvsItem* _LoopItem, int _iChan, int _iPic);


/*
	���л��б�������һ��ǰ���豸��������Ϣ
*/
td_s32 Dec_AddLoopItem(int _iChan,int _iPic,int _iIndex,TDECNVSITEM* _pNvsItem);


/*
	ɾ���л��б��е�ĳ����Ϣ
*/
td_s32 Dec_DeleteLoopItem(int _iChan,int _iPic,int _iIndex);


/*
	��ʼ�л�
*/
td_s32 Dec_StartLoop(int _iChan,int _iPic);

/*
	ֹͣ�л�
*/
td_s32 Dec_StopLoop(int _iChan,int _iPic);

int Dec_LoopListGetAudioStat(int _iChan,int _iPic);

void Dec_LoopNotifyToUI(int _iChan,int _iPic,int _iLoopStat);

/*
	����ĳ��NVS
*/
td_s32 Dec_StartView(int _iChan,int _iPic,TDECNVSITEM* _nvsItem,int _iTimeOut,int _iLoop);


/*
	�Ͽ���ĳ��NVS������
*/
td_s32 Dec_StopView(int _iChan,int _iPic,int _iAudioMark,int _iTimeOut,int _iLoop, int _iSaveLastFrame);

/*
	�л�����һ���豸
*/
td_s32 Dec_SwitchUp(int _iChan,int _iPic);

/*
	�л�����һ���豸
*/
td_s32 Dec_SwitchDown(int _iChan,int _iPic);

/*
	��ĳ���������Ƶ
*/
td_s32 Dec_StartAudio(int _iChan,int _iPic,int _iLoop);


/*
	�ر�ĳ���������Ƶ
*/
td_s32 Dec_StopAudio(int _iChan,int _iPic);


/*
	��ĳ��������жԽ�����
*/
td_s32 Dec_StartTalk(int _iChan,int _iPic);

/*
	ֹͣ��ĳ��������жԽ�����
*/
td_s32 Dec_StopTalk(int _iChan,int _iPic);


/*
	��ĳ����������豸���Ʋ���
*/
td_s32 Dec_PtzCtrl(int _iChan,int _iPic,td_s32 _iAction ,PTZ_DATA* _pData);


/*
	��ǰ��ĳ�����淢��485����
*/
td_s32 Dec_PtzClarity(int _iChan,int _iPic,td_u8* _u8Data,int _iDataLen);


/*
	�������ͻ��˿�ʼPUSH������
	����:�´���������push��������ͨ����	
*/
td_s32 Dec_StartPush(int _iChan,int _iPic,VENC_TYPE_E _VencType,VIDEO_SIZE_E _VideoSize, const char* _VencPsw, int _iAudioSample);

td_s32 Dec_SetPushData(td_s32 _s32Chn,td_u8* _u8DataBuf,int _iDataLen);


/*
	�������ͻ���ֹͣPUSH������
*/
td_s32 Dec_StopPush(int _iChan, int _iSaveLastFrame, int _iFrom);

/*
	���ý������ı���������ϵ
	��������ϵ�����е�����ͨ������Ч
	��Ӧ��0�ű�������˿�
	_iAlarmOut 	0x01:�˿ڱ���
				0x02:��ʧ����
				0x04:�ƶ�����
	_iAlarmOutStat		0:������
					1:�����ر�
*/
td_s32 Dec_SetAlarmLink(int _iAlarmOut,int _iAlarmOutStat);

/*
	��ȡ�������ı���������ϵ
*/
td_s32 Dec_GetAlarmLink();


td_s32 Dec_GetCurNvsItem(int _iChan,int _iIndex,TDECNVSITEM* _pNvsItem);

td_s32 Dec_GetCurTalkState(int _iChan,int _iIndex);

td_s32 Dec_GetCurAudioState(int _iChan,int _iIndex);

td_s32 Dec_ConnectStateChange(int _iChn,int _iState);

int Dec_GetDebug(char *_cString,int _iLen);

td_s32 Dec_AddPTZProtocols(td_s8 _cProtocol[MAX_PROTOCOL_NAME_LEN]);

td_s32 Dec_WritePTZProtocols(int _len, char * _buf);

void Dec_AlarmChange(int _iChn,TAlarmType _alarmType,int _iStat);

td_s32 Dec_LoopListClear(int _iChn,int _iPic);

td_s32 Dec_LoopListClearAll();

int Dec_ChnListFindByPos(int _iVoDev,int _iVoChn);

td_s32 Dec_GetConnetcStat(int _iChan,int _iPic);

void Dec_AlarmNotifyToUI(int _iChn,TAlarmType _alarmType,int _iStat);

void Dec_AlarmNotifyToUIByPos(int _iChn, int _iChan, int _iPic, TAlarmType _alarmType,int _iStat);

void Dec_GetCurrentPic(int* _iChan,int* _iPic);

void Dec_SelectPicNotieyToUI(int _iChan,int _iPic);

void Dec_PicsNotifyToUI(int _iChan,int _iPics);

void Dec_ResChangeNotifyToUI(int _iChan, int _iVgaMode);

void Dec_LogoNotifyToUI(int _iChan);

void Dec_LogoNotifyToUIEx(int _iChan);

void Dec_PtzNotifyToUI(int _iChan,int _iPic,int _iCtrlStat);

void Dec_ComAttrNotifyToUI(int _iChan);

td_s32 Dec_SwitchUp(int _iChan,int _iPic);
td_s32 Dec_SwitchDown(int _iChan,int _iPic);

td_s32 Dec_NameFifo_Init();

td_s32 Dec_Send485DataToFifo(char *_buf, int _len);

td_s32 Dec_Exit();
int Dec_LoopListGetAudioStat(int _iChan,int _iPic);
int Dec_LoopListGetTalkStat(int _iChan,int _iPic);
//td_s32 Dec_BigSmallSwitch(int _iChan);

void Dec_AlarmDisableToUI(TAlarmType _alarmType);
void Dec_AlarmEnableToUI(TAlarmType _alarmType);
int Dec_LoopListGetLoopStat(int _iChan,int _iPic);
td_s32 Dec_SetDebugFlag(td_s32 _s32Flag);

td_s32 Dec_SetPreviewPrefer(int _iChan, int _iEnable);
td_s32 Dec_SetSaveLastFrame(int _iChan, int _iEnable);
td_s32 Dec_ChanNoSwitch(int _iChan);
td_s32 Dec_Save_Bnc_mode(td_s32 _iMode);
td_s32 Dec_VoDevGetVgaPixel(int _iChan);
int Dec_GetInitFlag();
void  Dec_RestartApp(DEC_RESTARTAPPCALLBAK  _Fun); 
#endif

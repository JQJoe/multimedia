#ifndef _LIB_TD_VO_H_
#define _LIB_TD_VO_H_

#include "public_def.h"
#include "td_types.h"

#define MAX_PRIORITY_LEVEL 	8
#define MAX_AO_NUM		 	4		// 3531SDKʵ��ֻ��2��AoDev,��������չ
#define MAX_AO_CHNNUM		2
typedef enum
{
	AO_BIND_AI,			//��AIͨ��
	AO_BIND_ADEC,		//����ͨ��Ԥ��
	AO_BIND_PCI,		//��PCIͨ��
	AO_BIND_BUTT,
}TAOBindType;

typedef enum
{
	AO_PRI_PREVIEW_AI		=0,
	AO_PRI_PREVIEW_ADEC		=0,	
	AO_PRI_PALYBACK			=1,
	AO_PRI_TALK				=2,
	AO_PRI_ALARM			=3,
	AO_PRI_BUTT				= MAX_PRIORITY_LEVEL,
}TAOPriority;

td_s32 TdAO_Init(td_s32 _iAoChnCnt);
/*
	����:��ʼ��AO
*/

//td_s32 TdAO_Uninit();
/*
	����:ȥ��ʼ��AO
*/

td_s32 TdAO_Start(td_s32 _iAoDevId,TAOPriority _iPriority,TAOBindType _iBindType,td_s32 _iChnNum, AUDIO_TYPE_E _iAdecType, td_s32 _iAoSamples, td_s32 _iAoSampleRate);
/*
	����:��TdAO_Stop���ʹ�ã���Ҫ����������Ƶ����Ĳ���Ƶ��
	����:
		_iAoDevId:Ao�豸�ţ�
		_iPriority:���ȼ�;
		_iBindType:������;
		_iChnNum:��ͨ����,����ʱ��Ϊ����ֵ��
		_iAdecType:�������ͣ�Ԥ��ʱ��Ϊ����ֵ;
		_iAoSamples:������.
	���:
		Ao��� �ɹ���
		-1 ʧ��
*/


td_s32 TdAO_SendStream(td_s32 _iAoId, td_u8* _u8Data,td_s32 _iLen, td_s32 _s32BlockFlag);
/*
	����:��Ao��������
	����:
		_iAoId:Ao���;
		_u8Data:������ָ��;
		_iLen:���ݳ���
		_s32BlockFlag:������־;
	���:
		���ݳ���   �ɹ�
		-1 ʧ��
		-2 ����
*/

td_s32 TdAO_Stop(td_s32 _iAoId);
/*
	����:ֹͣĳһ��Ӧ��ŵ�Ao,����Ϊ���ȼ���ߣ�������������ȼ���AO
	����:
		_iAoDevId:Ao�豸�ţ�
*/

//td_s32 TdAO_Clear(td_s32 _iAoId);
td_s32 TdAO_CheckAOChnBufStat(td_s32 _iAoId);

int libTdAO_GetDebug(char *_cString,int _iLen);

void vGetAACEnble(td_s32 _iEnble);
#endif

#ifndef _LIB_INIT_H_
#define _LIB_INIT_H_

#include "td_types.h"

#define SYS_ALIGN_WIDTH  16	

enum
{
	PLATFORM_CMD_TM_SYNC = 0,
	PLATFORM_CMD_GET_SLV = 1,	//��ȡ��Ƭ����汾
	PLATFORM_CMD_RBOOT_SLV,		//������Ƭ
};

typedef struct
{
	td_s32 (*HeartbeatCheck)();		//�������
	td_s32 (*DoCmd)(td_s32 _iId, void *_arg);
	td_s32 m_uiBncBits;				//�����������ӱ�ʶ,0Ϊ��Ƭͨ��,1Ϊ��Ƭpciͨ��
	td_s32 m_uiCodePerformance;		//Ӳ�����������,��D1Ϊ��׼��1��D1Ϊ100
	td_s32 m_uiPreviewPerformance;	//Ӳ��Ԥ������,��D1Ϊ��׼, 1��D1Ϊ100
	td_s32 m_iMediaChnCnt;			//��Ƭ����ý��ͨ���Ÿ���
} TPlatformMsg;

// ƽ̨���Գ�ʼ��
// _HeartBeatFun : ����ƽ̨Ӳ���������ָ��
// _uiBncBits : ����ƽ̨Ӳ������ͨ�����ԣ���λ��0����Ƭͨ����1���Ƭpciͨ��
td_s32 init_PlatformInit(IN MediaDevice *_ptDev, OUT TPlatformMsg *_ptMsg, td_s32 _iHdmi0_Size, td_s32 _iHdmi1_Size, td_s32 _iBnc_Size);


#endif


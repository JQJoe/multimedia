#ifndef _LIB_TALK_H
#define _LIB_TALK_H

#include "public_def.h"

#define SINGLE_TALK_START	0
#define SINGLE_TALK_STOP	1

//typedef td_s32 (*SendAudioStream)(const td_u8 *_pBuf, td_u32 _iLen);
//����Խ�
td_s32 StartSingleTalking(td_s32 _iAOpreviewDefault);
td_s32 StartSingleTalkingPCM(td_s32 _iAOpreviewDefault);
//td_s32 SendSingleTalkingData(const td_u8* _cAudioData, td_u32 _iDataLen);
td_s32 SendSingleTalkingData(const td_u8* _cAudioData, td_u32 _iDataLen,int _itype);//modify by zhb 20121030 
td_s32 StopSingleTalking();
//����Խ�������_iFlg:������0������ֵ:����+1������ʱ����
td_s32 SingleTalkingHeartbeat(td_s32 _iFlg);


//˫��Խ�
TDataCenter* StartDoubleTalking(td_s32 s32AencType,td_s32 s32PtNumPerFrm);
td_s32 StopDoubleTalking();
td_s32 InitTalk();
td_s32 GetDoubleTalkStat();
td_s32 SetIpTalkChn(int _iChn);
td_s32 GetIpTalkChn();

#endif

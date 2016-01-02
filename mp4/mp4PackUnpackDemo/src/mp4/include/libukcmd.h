/*******************************************************************
�ļ���	:GuiCmdExcute.h
��      ˾	:������ΰҵ����Ƽ����޹�˾
������	:������
��������:2008-10-09
��Ҫ����:������UI  �������ݽ����ӿں���ͷ�ļ�
�޸ļ�¼:2008-10-10,������  ����
        
******************************************************************/
#ifndef  GUICMDEXECUTE_H
#define  GUICMDEXECUTE_H

//#include "guiparameter.h"
void UKCmd_CreateRecvThread(td_s32 _iTid, td_s32 _iWait, td_s32 *_iHeardbeat);
void UKCmd_Start(td_s32 _iTid, td_s32 _iWait, td_s32 *_iHeardbeat);
void UKCmd_CreateDataProcThread(td_s32 _iTid, td_s32 _iWait, td_s32 *_iHeardbeat);

// ����<->���͸������
td_s32 UKCmd_SendAppString(td_u32 _uiIp, char *_str);
td_s32 UKCmd_SetAppStringProcFun(void (*_Fun)(td_u32 _uiIp, char *_str));


// UK͸������
td_s32 UKCmd_SendUKData(void *_pData, int _iSize);
td_s32 UKCmd_SetUKDataProcFun(void (*_Fun)(void *_pData, int _iSize));
td_s32 UKCmd_SetChnCommDataFun(td_s32 (*ChnComDataProc)(td_s32 _iChn, td_s32 _iComdId, td_s32 _iLength, void *_pBuf));

// ��������
td_s32 UKCmd_SendComData(int _iComd, void *_pData, int _iSize);

td_s32 UKCmd_ClearTalkStat();

td_s32 UKCmd_SendComDataToApp(td_u32 _iComId, char *_str,  int _iSize);

td_s32 UKCmd_SendDataToApp(td_u32 _iComId, char *_str, int _iSize,int _itype);//modify by zhuangzhibing

td_s32 UKCmd_ClearRingBuf();//add by zhuangzhibing 20120215 ��ջ���buffer

#define GUI_RECORD_STATE
#ifdef GUI_RECORD_STATE
#define GUI_IDLE_STATE 0
#define GUI_SPIC_PREVIE_STATE 1
#define GUI_JPEG_VIEWER_STATE 2
#define GUI_VIDEO_PLAYER_STATE 3
#define GUI_TRACK_PTZ_STATE 4
#define GUI_ZOOM_STATE 5
#endif
//add by sunlining
td_s32 UKCmd_ReburnCreatFileReq(td_s32 _iDiskNo,const char *_pcPath);   
/*
֪ͨ��Ҵ��������������ļ�
*/
td_s32 UKCmd_ReburnRmFileReq(const char *_pcPath);
/*
֪ͨ���ɾ����һ�����ɵ������ļ��������Ѷ�������ļ��Ѿ�������ɾ����
*/


//td_s32 UKCmd_SendOsdWord(td_s32  _iChn,td_s32 _iX,td_s8* _pstrOsdtext);

/*
֪ͨ�����ҳ���õĸ����ַ�
*/


td_s32 UKCmd_Burn_Send_Encrypt(int iChn);
/*
֪ͨ��Ҵ��������ֶ�
*/
td_s32 UKCmd_SettingRenewReq();
/*
֪ͨ��һָ�Ĭ��
*/
//td_s32 UKCmd_Set307PTimeReq();
/*
֪ͨ��Ҹ�307pУʱ
*/

td_s32 UKCmd_FormatNoteWgReq();
/*
֪ͨ��ҶϿ����ݿ������
*/
td_s32 UKCmd_PoweroffStatRsp();
/*
֪ͨ��ҷ��͸��пعػ�ָ��
*/
td_s32 UKCmd_FormatStatRsp();
/*
֪ͨ��Ҹ�ʽ�����
*/

int UKCmd_DvdNumStatusToApp(int _iOkNum, int _iErrNum);
/*
֪ͨ��� ��һ��ͥ�������ĺ����뻵��
*/

/*
UI���ö໭��ʱ��֪ͨ���
*/
td_s32 UKCmd_SetPreviewReq(TGuiSetPreviewReq *_ptReq);

td_s32 UKCmd_VideoHeaderToApp(void *_pData);

//add end
//liyang add 
td_s32 UKCmd_GetUKTid(td_s32 _iTid);
//add end
/*
֪ͨ��Ҽ���
*/
td_s32 UKCmd_SendBestirToApp(int _iChn, int _iStat);

//�������������㲥�߳�
void CreateVoiceBestirThread(void *_pArg);
//����ͨ�����һ�μ�����ʱ��
void SetLastBestirTime(int _iChn, int _iTime);

td_s32 UKCmd_ForceIframeWgReq(int _iChn);//���������ǿ��I֡

#endif


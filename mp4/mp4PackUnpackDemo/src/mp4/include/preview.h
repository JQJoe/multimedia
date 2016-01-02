/*******************************************************************
�ļ���	:TD_Preview.h
��˾	:������ΰҵ����Ƽ����޹�˾
������	:����
��������:2010-02-25
��Ҫ����:��ƵԤ��ģ��ͷ�ļ�
        
******************************************************************/
#ifndef _PREVIEW_H
#define _PREVIEW_H

#include "td_types.h"

#define PV_MAX_QUEUE_LEN	64
#define PV_MAX_VO			32
#define PV_VO_MAX_DEV_NUM 			4		//�������豸

typedef enum
{
	PV_MOD_ERR 		= -1,	// ����
	PV_SINGLE_PIC 	= 1, 	// ������

	PV_PIC_IN_PIC 	= 2, 	// ���л�
	PV_PIC_IN_PIC_1 = 2001,
	PV_PIC_IN_PIC_2 = 2002,
	PV_PIC_IN_PIC_3 = 2003,
	PV_EZOOM		= 2011,

	PV_3PICS 		= 3,
	PV_3PICS_1 		= 3001,
	PV_4PICS_MIN	= 4000,
	PV_4PICS_MAX 	= 4301,
	PV_USER_DEF = 0xFFFF,  //�Զ���ģʽ
} PV_MOD;


typedef struct
{
    int m_iVoChnCnt;//�Զ��廭��ָʽ�»�����
    TRect m_tVoAreas[PV_MAX_VO]; // PV_MAX_VO=32
}TCustomPreviewParam;


typedef struct
{
	td_s32 m_iPicCnt;									//Ԥ��ģʽ
	td_s32 m_iChnCnt[PV_MAX_VO];						//���г���
	td_s32 m_iChnList[PV_MAX_VO][PV_MAX_QUEUE_LEN];		//�����б�
	td_s32 m_iSwitchTime;								//Ѳ��ʱ����
	TCustomPreviewParam m_tCustomPvPara;//�Զ��廭��ָʽ
}TPreviewParam;




//����״̬
typedef enum
{
	PV_STA_ERR = -1,	//����
	PV_STA_PUASE = 0, 	//Ԥ����ͣ
	PV_STA_NORMAL, 	//����Ԥ��
	PV_STA_SINGLE_PIC,	//������
	PV_STA_EZOOM,		//���ӷŴ�
} PREVIEW_STA;


//----------------------------�ӿں���---------------------------
td_s32 preview_Init_Ex(td_s32 _iVoDev, td_s32 _iVoDevSize, td_s32 _iWbcBindVoDev);

td_s32 preview_Init(td_s32 _iVoDevCnt, td_s32 _iVoDevIds[], td_s32 _iVoDevSize[], td_s32 _iVoDevIntfType[], td_s32 _iWbcBindVoDev);
/*
 * �������ƣ�PreviewInit
 * ��Ҫ����: ��ƵԤ��ģ���ʼ��
 *
 * ��     ��: _iCnt: Ԥ��������
 * ��	  ���� 0:��ʼ���ɹ�
 			  -1:��ʼ��ʧ��

*/

td_s32 preview_Uninit();

// ����Ԥ��������1��D1�ȼ���100
td_s32 preview_SetMaxPerformance(td_s32 _iMaxPerformance);


td_s32 preview_SetConfig(td_s32 _iVoDev, TPreviewParam *_ptArg);
/*
 * �������ƣ�PreviewSetConfig
 * ��Ҫ����: ����Ԥ������
 *
 * ��       ��: _DispDev:      Ԥ���豸
 * ��	  ����
*/


td_s32 preview_StartSwitch(td_s32 _iVoDev);
/*
 *��������: PreviewStartSwitch
 *��Ҫ����: ����Ԥ���л�

 *����:_iDispDev:Ԥ���豸
 *���:

*/
td_s32 preview_StopSwitch(td_s32 _iVoDev);
/*
 *��������: PreviewStopSwitch
 *��Ҫ����: ֹͣ��ƵԤ��

 *����:_iDispDev:Ԥ���豸
 	  :_iPicCnt :Ԥ��������
 *���:

*/

td_s32 preview_PageUp(td_s32 _iVoDev);
/*
 *��������: PreviewPageUp
 *��Ҫ����: ��ƵԤ����һҳ

 *����:
 *���:

*/
td_s32 preview_PageDown(td_s32 _iVoDev);
/*
 *��������: PreviewPageDown
 *��Ҫ����: ��ƵԤ����һҳ

 *����:
 *���:

*/

td_s32 preview_EnterSinglePic(td_s32 _iVodev, td_s32 _iChn);
/*
 *��������: PreviewEnterSinglePic
 *��Ҫ����: ������Ԥ��

 *����:_iVodev:Ԥ���豸
 		_iChn:Ԥ��ͨ��
 *���:

*/
td_s32 preview_ExitSinglePic(td_s32 _iVodev);
/*
 *��������: PreviewEnterSinglePic
 *��Ҫ����: �˳�������Ԥ��

 *����:_iVodev:Ԥ���豸
 		_iVoChn:Ԥ��ͨ��
 *���:

*/

td_s32 preview_EnterEzoom(td_s32 _iVodev, td_s32 _iChn);

/*
 *��������: PreviewEnterEzoom
 *��Ҫ����: ������ӷŴ�

 *����:_iVodev:Ԥ���豸
 		_iChn:Ԥ��ͨ��
 *���:

*/
td_s32 preview_ExitEzoom(td_s32 _iVodev);
/*
 *��������: PreviewExitEzoom
 *��Ҫ����: �˳����ӷŴ�

 *����:_iVodev:Ԥ���豸
 		_iVoChn:Ԥ��ͨ��
 *���:

*/

// ���õ��ӷŴ���ʾ����
td_s32 preview_SetEzoomArea(td_s32 _iVoDev, TRect *_ptArea);

td_s32 preview_Pause(td_s32 _iVoDev);
/*
 *��������: PreviewPause
 *��Ҫ����: Ԥ����ͣ

 *����:_iVodev:Ԥ���豸
 *���:

*/
td_s32 preview_Resume(td_s32 _iVoDev);
/*
 *��������: PreviewResume
 *��Ҫ����: �ָ�Ԥ��

 *����:_iVodev:Ԥ���豸
 *���:

*/
td_s32 preview_GetCurStat(td_s32 _iVoDev);
/*
 *��������: PreviewCurStat
 *��Ҫ����: ��ǰԤ��״̬

 *����:_iVodev:Ԥ���豸
 		_iVoChn:Ԥ��ͨ��
 *���:

*/

// ��ȡԤ���л�״̬
td_s32 preview_IsSwitch(td_s32 _iVoDev);

// ���ĵ�ǰԤ��ģʽ
td_s32 preview_ChgMod(td_s32 _iVoDev, td_s32 _iMod);

td_s32 preview_GetCurMode(td_s32 _iVoDev);
/*
 *��������: PreviewGetMode
 *��Ҫ����: ��ȡ��ǰԤ��ģʽ

 *����:_iVodev:Ԥ���豸
 		_iVoChn:Ԥ��ͨ��
 *���:

*/
td_s32 preview_GetCurDspChn(td_s32 _iVoDev, td_s32 _iVoChn);
/*
 *��������: PreviewGetCurDsp
 *��Ҫ����: ��ȡ��ǰԤ����ʾ

 *����:_iVodev:Ԥ���豸
 		_iVoChn:Ԥ�������
 *���:

*/

// ��ʱ�޸Ĵ��ڻ�����ʾ
td_s32 preview_ChgCurDspChn(td_s32 _iVoDev, td_s32 _iVoChn, td_s32 _iViChn);

td_s32 preview_SetFocus(td_s32 _iVoDev, td_s32 _iVoChn);
/*
 *��������: PreviewSetFocus
 *��Ҫ����: ����Ԥ������(����"���")

 *����:_iVodev:Ԥ���豸
 		_iVoChn:VO���ں�
 *���:

*/

td_s32 preview_PicMap(td_s32 _iVoDev, td_s32 _iChn, TRect *_ptRect);
td_s32 preview_PicUnMap(td_s32 _iVoDev);


td_s32 preview_SetVoDevSize(td_s32 _iVoDev, td_s32 _iSize);


td_s32 preview_ChannelOsdChangeNotify(td_s32 _iChn);

td_s32 preview_SetFocusVoDev(td_s32 _iVoDev);
td_s32 preview_SetMasterVoDev(td_s32 _iVoDev);
#define preview_GetMasterVoDev()	preview_SetMasterVoDev(-1)

td_s32 preview_SetVoDevsSize(td_s32 _iHdmi0Size, td_s32 _iHdmi1Size, td_s32 _iBncSize);

// �����ļ����
td_s32 preview_LoadCnf(td_s32 _iVoDev, TPreviewParam *_ptParam);
td_s32 preview_GetPicPoint(td_s32 _iVoDev, td_s32 _iMod, TRect * _ptRects);

td_s32 preview_SaveCnf(td_s32 _iVoDev,const TPreviewParam *_ptParam);
td_s32 preview_MakeDefaultCnf(td_s32 _iMod, td_s32 _iChnCnt, TPreviewParam *_ptParam);
// �ָ�Ĭ��
td_s32 preview_DefaultCfg();

// ������Ƶ������ʽ
td_s32 preview_SetViNorm(td_s32 _iNorm);

// Ϊ��֤�طŽ��/�ָ�����ͨ��Ԥ��
td_s32 preview_VdencPause();
td_s32 preview_VdencResum();

td_s32 preview_VoDevTest(td_s32 _iVoDev);

td_s32 preview_SetOldFocusVoDev(td_s32 _iVoDev);

td_s32 preview_GetOldFocusVoDev(void);


//����TV��ʾ����
td_s32 preview_SetVoDevDspAreaOnScreen(td_s32 ivodev, td_s32 iXp, td_s32 iYp, td_s32 iWidth, td_s32 iHeight);
//����TV�������
td_s32 preview_SetTVParam(TDevTV * _ptDevTv);


td_s32 preview_GetBncDevMode();

////��ȡ��ǰϵͳ�ĺϳɻ����������ͨ����
td_s32 preview_CurVoMainChn(int _iVoDev,int *_piVcMainChnNo);
td_s32 Preview_SetPreviewQualityCnf(int _iPreviewCnf);
td_s32 preview_SetchgValue(int _iValue);
td_s32 Preview_SetPreviewAudioMod(int _iAOPreviewMod);
td_s32 preview_SetStartAudioLeftRight(td_s32 _iVoDev, td_s32 _iLeft, td_s32 _iRight, td_s32 _iLeft1, td_s32 _iRight1);
td_s32 Preview_SetPreviewDefaultAudioLR(int _iDefaultLR);

// for decoder��ʱ������������ʱӦ��ɾ��
td_s32 preview_StopCurChnDsp(td_s32 _iVoDev, td_s32 _iVoChn);
td_s32 preview_sShowNovideo(int _iNovideo);
td_s32 preview_sVoNoClearStat(td_s32 _iVoDev, td_s32 _iVoChn, td_s32 _iClear);

td_s32 preview_GetFocusVoDev(void);
td_s32 preview_GetVoDevSize(td_s32 _iVoDev, td_s32 *_piWith, td_s32 *_piHeight);

td_s32 preview_startpage(td_s32 _iVoDevId);
td_s32 preview_stoppage(td_s32 _iVoDevId);
td_s32 preview_SetNoValidSize(TVideoSize _tVideoSize[], td_s32 _iCnt);

td_s32 preview_sShowPreviewFrameEnable(int _iEnable); //����Ԥ���ڱ߿�ʹ��--�㽭������Ҫ

int Perview_GetDebugInfo(char *_cString);


#endif

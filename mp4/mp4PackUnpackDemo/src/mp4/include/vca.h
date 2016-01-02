
/*zhangyi add 20110309*/
#ifndef __VCA_H__
#define __VCA_H__

#include "vca_head.h"
#include "td_types.h"

#include "alarm.h"				//zhangyi add 20110426
extern td_s32 g_blClrAlmCntVca;	

#define		MAX_RULE_NUM				8
#define		MAX_POLYGON_POINT_NUM		8
#define		MAX_TRIPWIRE_NUM			8
//#define		MAX_RULE_NAME_LEN			16  detel by nsg 20120321
#define		MAX_TIMESEGMENT				4
#define		MAX_EVENT_NUM				14
#define		MAX_SAVE_TARGET_NUM			16
#define		LINKAGE_VCA					3
#define     MAX_SLAVE_CHN_NUM  			8
#define 	MAX_MSG_NUM      			30  // ���ܷ���������໺������
#define		MAX_FDEPTH_LINE_NUM			3	// ���ܷ����궨����(Ĭ��Ϊ3��)

//move from old vca_core by caizhaoxu 2012-08-02
#define   	VIDEOINPUT_VCA_MAX_CHANNEL_NUM  32 //3516ֻ��һ·���˲���Ԥ����������Ŀ
#define   	MAX_VCA_TIMESEGMENT  		4

//shihc add 20130111 Ϊ���ܷ���������������Ҫ�ĺ�
#define CAP_WIDTH 352
#define CAP_HEIGHT 288
#define CAP_PWIDTH 11 //352/32
#define CAP_PHEIGHT 9//288/32
#define PTZ_OFFSET_SPEED 6


#define		VCA_MODULE	  				1
#define 	PI 3.1415926
#define 	ARROW_ANGLE PI/10
#define 	ARROW_LEN 10
#define 	TRIPWIRE_ARROW_LEN 30
#define 	PERIMETER_ARROW_LEN 60
#define 	ASCLENGTH 4096

#define		RET_CAP_STOP 1
//----------------------------------------------------------------------------------
typedef struct
{
	int		m_iVideoSize;
	int		m_iDisplayTarget;			// �Ƿ����Ŀ���
	int		m_iDisplayTrace;			// �Ƿ���ӹ켣	
	int		m_iDisplayAllTargetTrace;	// �Ƿ��������Ŀ�꼰�켣		//zhangyi add 20110720
	int		m_iTargetColor;				// Ŀ�����ɫ
	int		m_iTargetAlarmColor;		// ����ʱĿ�����ɫ
	int		m_iTraceLength;				// �켣����
} vca_TConfig_ex; 			// ���ܷ������ò���  
//----------------------------------------------------------------------------------
typedef struct
{
	int m_iX;
	int	m_iY;
} vca_TPoint_ex;

typedef struct
{
	vca_TPoint_ex m_sTripwireArrow[4];
	vca_TPoint_ex m_sPerimeterArrow[4];
}vca_TRuleArrow_ex;
#if 0
//liusong added
typedef struct
{
	td_s32             m_VideoSize;
	vca_TRuleArrow m_stArrowInfo[MAX_RULE_NUM];
}vca_ArrowInfo;
#endif
typedef struct
{
	TVcaPoint 	m_stStart;
	TVcaPoint 	m_stEnd;
} vca_TLine_ex;

typedef struct
{
	int				m_iValid;
	int				m_iTargetTypeCheck;
	int				m_iMinDistance;
	int				m_iMinTime;	
	int				m_iDisplayRule;
	int				m_iDisplayStat;
	int				m_iColor;
	int				m_iAlarmColor;
	int				m_iType;
	int				m_iTDirection;
	vca_TLine_ex	m_stLine;
    
} TVcaTripParam_ex;  	// �������¼�������ز���

typedef struct
{
	//TVcaTripParam_ex	m_stVcaTripParam;
	int				m_iAlarmCount;
	TAlarmParam		m_stAlarmParam;	
} vca_TTripEvent_ex; 	// �����߲���

typedef struct
{
	int 		    m_iPointNum;
	TVcaPoint 	m_stPoint[MAX_POLYGON_POINT_NUM];   
} vca_TPolygon_ex;

typedef struct
{
	int				m_iValid;
	int				m_iDisplayRule;
	int				m_iDisplayStat;
	int				m_iColor;
	int				m_iAlarmColor;	
	int				m_iTargetTypeCheck;
	int				m_iMode;
	int 			m_iMinDistance;					
	int 			m_iMinTime;					
	int				m_iType;
	int 			m_iDirection;
	vca_TPolygon_ex	m_stRegion;		
} TVcaPeriParam_ex;	// �ܽ��¼�������ز���

typedef struct
{
	//TVcaPeriParam_ex	m_stVcaPeriParam;
	int				m_iAlarmCount;					
	TAlarmParam		m_stAlarmParam;	
} vca_TPeriEvent_ex; // �ܽ����

typedef struct
{
    int				m_iValid;
	int				m_iDisplayRule;
	int				m_iDisplayStat;
	int				m_iColor;
	int				m_iAlarmColor;	
	int				m_iMinTime;
	int				m_iMinSize;
	int 			m_iMaxSize;	
	int				m_iChildAreaNum;    //��Ч���������
	vca_TPolygon_ex	m_stMainRegion;	    //����Ķ��������	
    vca_TPolygon_ex	m_stRegionA;	    //������A
	vca_TPolygon_ex	m_stRegionB;        //������B
	vca_TPolygon_ex	m_stRegionC;        //������C

}TVcaLeaveParam_ex;// ����������ز���

typedef struct
{
    //TVcaLeaveParam_ex  m_stLeaveParam;
    int             m_iAlarmCount;
    TAlarmParam		m_stAlarmParam;	
}vca_TLeaveEnevnt_ex;

typedef struct
{
	int 			m_iValid;
	int 			m_iDisplayRule;
	int 			m_iDisplayStat;
	int				m_iColor;
	int 			m_iAlarmColor;		//����ʶ��û�д�λ
	vca_TPolygon_ex	m_stRegion;
} TVcaFaceParam_ex;	// ��������¼�������ز���

typedef struct
{
	//TVcaFaceParam_ex	m_stVcaFaceParam;
	int				m_iAlarmCount;				
	TAlarmParam		m_stAlarmParam;	
} vca_TFaceEvent_ex;	// ����������

typedef struct
{
	int				m_iValid;
	int				m_iDisplayStat;
	int				m_iCheckTime;
} TVcaDiagParam_ex;	// ��Ƶ����¼����ò���

typedef struct
{
	//TVcaDiagParam_ex	m_stVcaDiagParam;
	int				m_iAlarmCount;				
	TAlarmParam		m_stAlarmParam;	
} vca_TDiagEvent_ex;	// ��Ƶ��ϲ���

typedef struct
{
	int				m_iAlarmCount;				
	TAlarmParam		m_stAlarmParam;	
} vca_TCAPEvent_ex;	// ���ܸ��ٲ���

typedef struct
{
	int				m_iAlarmCount;				
	TAlarmParam		m_stAlarmParam;	
} vca_TCpcEvent_ex;	// ����ͳ��

typedef struct
{
	int				m_iAlarmCount;				
	TAlarmParam		m_stAlarmParam;	
} vca_TCddEvent_ex;	// ��Ⱥ�ۼ�
typedef struct
{
	int				m_iAlarmCount;				
	TAlarmParam		m_stAlarmParam;	
} vca_TSvdEvent_ex;	// ��ڼ��

typedef struct
{
	vca_TTripEvent_ex		m_stTripEvent;		// ��Խ���߲���
	vca_TPeriEvent_ex		m_stPeriEvent;		// �ܽ����
	vca_TFaceEvent_ex		m_stFaceEvent;		// ����ʶ�����
	vca_TDiagEvent_ex		m_stDiagEvent;		// ��Ƶ��ϲ���	zhangyi add 20110601
	vca_TLeaveEnevnt_ex    	m_stLeaveEvent;     // ��Ʒ��������   add by nsg 20120313	
	vca_TCAPEvent_ex		m_stCAPEvent;       // ���ܸ��ٲ���  add by shihc 20130227
	vca_TCpcEvent_ex		m_stCpcEvent; 		// ����ͳ�Ʋ���
	vca_TCddEvent_ex		m_stCddEvent; 		//��Ⱥ�ۼ�����
	vca_TSvdEvent_ex		m_stSvdEvent;		//��ڼ�����
} vca_TEventParam_ex; 		// ��Ϊ�����¼�����

typedef struct
{
	vca_TEventParam_ex	m_stEventParam;						// ��Ϊ�����¼�����
} vca_TRuleParam_ex;   	// �������ò���


//----------------------------------------------------------------------------------
typedef struct 
{
	int		m_iEnableAdvanced; 				//�Ƿ����ø߼�����
	int		m_iMinSize; 					//Ŀ����С������
	int		m_iMaxSize; 					//Ŀ�����������
	int   	m_iMinWidth;  					//�����
	int		m_iMaxWidth;  					//��С���
	int		m_iMinHeight;  					//���߶�
	int		m_iMaxHeight;  					//��С�߶�
	int		m_iTargetMinSpeed;				//Ŀ����С�����ٶ�(-1Ϊ��������)
	int 	m_iTargetMaxSpeed;				//Ŀ����������ٶ�(-1Ϊ��������)
	int		m_iMinWHRatio;					//��С�����
	int 	m_iMaxWHRatio;					//��󳤿��
	int		m_iSensitivity;					//�����ȼ���
} vca_TAdvancedParam_ex; 	// ���ܷ����߼�����
//-----------------------------------------------------------------------------------
typedef struct 
{
	vca_TLine_ex 	m_stRefLine;		// ��ֱ�߶�����(unit: pixel)
	int 		m_s32RefLen;		// �߶γ���(unit: cm)
} vca_TFdeLine_ex;		// �����߽ṹ

typedef struct
{
	unsigned int	m_i32NumUsed; 					// ������Ŀ ���ڵ���2
	vca_TFdeLine_ex 	m_stLines[MAX_FDEPTH_LINE_NUM];	// ������Ŀ
} vca_TFdeMeasure_ex; 	// �궨��������

typedef struct
{
	unsigned int 			m_iEnableFdepth;	//���ñ�ʶ
	vca_TFdeMeasure_ex 		m_stMeasure;		//�궨����
} vca_TFdepthParam_ex;	// ���ܷ����궨���ò���
//-----------------------------------------------------------------------------------
typedef struct
{
	int 					m_chn;
   	vca_TRuleParam_ex		m_stRule[MAX_RULE_NUM]; 	// �������ò���
} vca_TVCAParam_ex;	// ���ܷ������ò���
//-----------------------------------------------------------------------------------
typedef struct 
{
	time_t  		m_iTime;
	int 			m_iChn;
	int     		m_iRule;
	TVcaEventType 	m_eType;
	int     		m_iState;
	unsigned int 	m_u32TId;
	int 			m_u32Type;	
}AlarmData_ex;
typedef enum CAPResultStatus
{
	CAP_RESULT_A=0,//PT to origin & Z wide
	CAP_RESULT_B=1,//To do nothing
	CAP_RESULT_C=2,//PT move
	CAP_RESULT_D=3,//ZoomBegin&Z close up
	CAP_RESULT_E=4,//ZoomProcess & To do nothing
	CAP_RESULT_F=5,//ZoomEnd & Z stop
	CAP_RESULT_G=6//PT Stop
	
}CAP_RESULT_STATUS_E;

typedef struct 
{
	TVcaEventType 	m_eType;
	TAlarmParam     *m_pAlarmParam;
}vca_strRuleAlarmMap;

typedef struct
{
	vca_strRuleAlarmMap m_RuleAlarmMap[MAX_RULE_NUM];
}vca_AlarmMap;

int vca_SetAlarmMap(int _iChn, int _iRule, TVcaEventType _type);

vca_strRuleAlarmMap* vca_GetAlarmMap(int _iChn, int _iRule);

#define DFT_WRITE_CFG	0		//дĬ������
#define	SET_WRITE_CFG	1		//д��������
td_s32 vca_WriteCfg();
/*
 * �������ƣ�vca_WriteCfg
 * ��Ҫ����: д���ܷ��������ļ�
 * ��	  �룺
 * 			
 * ��	  ����
 *			ERR_VCA_SUCCESSFUL
 *			ERR_VCA_FAILED
 *			ERR_VCA_OPEN_FILE_ERROR			
 *			ERR_VCA_WRITE_FILE_ERROR					
 *			ERR_VCA_NO_SUCH_FILE			
 * �޸���־��
 * 			2011-03-21,����,����
 *			2011-08-02,����,�޸�
 */
td_s32 vca_ReadCfg();
/*
 * �������ƣ�vca_ReadCfg
 * ��Ҫ����: �����ܷ��������ļ�
 * ��	  �룺
 * 			
 * ��	  ����
 *			ERR_VCA_SUCCESSFUL
 *			ERR_VCA_FAILED
 *			ERR_VCA_OPEN_FILE_ERROR					
 *			ERR_VCA_READ_ERROR				
 *			ERR_VCA_NO_SUCH_FILE
 * �޸���־��
 * 			2011-03-21,����,����
 */

td_s32 vca_DefaultCfg();
/*
 * �������ƣ�vca_DefaultCfg
 * ��Ҫ����: �ָ����ܷ���Ĭ�������ļ�
 * ��	  �룺
 * 			
 * ��	  ����
 *			ERR_VCA_SUCCESSFUL
 *			ERR_VCA_FAILED
 *			ERR_VCA_OPEN_FILE_ERROR			
 *			ERR_VCA_WRITE_FILE_ERROR					
 * �޸���־��
 * 			2011-03-21,����,����
 */
 
td_s32 vca_Init(const MediaDevice* _pMediaDevice,strChannelParam *_tChnPara,td_s32 _iCfgVideo,td_s32 _iVideoInput);

/*
 * �������ƣ�vca_Init
 * ��Ҫ����: ��ʼ�����ܷ���ģ��
 * ��	  �룺
 * 			
 * ��	  ����
 *			ERR_VCA_SUCCESSFUL				
 * �޸���־��
 * 			2011-03-21,����,����
 */

#if 0 		//zhangyi add 20110707
td_s32 vca_Exit(void);
/*
 * �������ƣ�vca_Exit
 * ��Ҫ����: ж�����ܷ���ģ��
 * ��	  �룺
 * 			
 * ��	  ����
 *			ERR_VCA_SUCCESSFUL					
 * �޸���־��
 * 			2011-03-21,����,����
 */
#endif

vca_TVCAParam_ex* vca_GetAlarmParam(td_s32 _iChannelNo);
/*
 * �������ƣ�vca_GetParam
 * ��Ҫ����: ��ȡ���ܷ�����������
 * ��	  �룺
 * 			
 * ��	  ����
 *								
 * �޸���־��
 * 			2012-09-03,������,���⿪��
 */


//vca_TVCAParam_ex* vca_GetParam(td_s32 _iChannelNo);
TVcaParam* vca_GetParam(td_s32 _iChannelNo);
/*
 * �������ƣ�vca_GetParam
 * ��Ҫ����: ��ȡ��ͨ�����ܷ������ò���	
 * ��	  �룺
 * 			
 * ��	  ����
 *								
 * �޸���־��
 * 			2011-04-22,����,����
 */

TVcaEventType vca_GetChanRuleEventType(td_s32 _iChannelNo, td_s32 _iRuleID);
/*
 * �������ƣ�vca_GetChanRuleEventType
 * ��Ҫ����: 
 * ��	  �룺
 * ��	  ����
 * �޸���־��
 *			2011-06-03,���ǣ�����
 */


//-------------------------------------------------------------------------------------------------------------
td_s32 vca_SetChannelEnable(td_s32 _iChn, td_s32  _iEnable);
td_s32 vca_GetChannelEnable(td_s32 _iChn, td_s32 *_piEnable);
//-------------------------------------------------------------------------------------------------------------
td_s32 vca_SetVideoInputSize(td_s32 _iChannelNo, td_s32  _iVideoSize);
td_s32 vca_GetVideoInputSize(td_s32 _iChannelNo, td_s32 *_piVideoSize);
//-------------------------------------------------------------------------------------------------------------
td_s32 vca_SetDrawVSize(td_s32 _iChn, td_s32 _iVideoWidth, td_s32 _iVideoHeight);
td_s32 vca_GetDrawVSize(td_s32 _iChn, td_s32 *_iVideoWidth, td_s32 *_iVideoHeight);
//-------------------------------------------------------------------------------------------------------------
td_s32 vca_SetAdvancedParameter(td_s32 _iChn, TVcaAdvanceParam *_pstAdvancedParam);
td_s32 vca_GetAdvancedParameter(td_s32 _iChn, TVcaAdvanceParam *_pstAdvancedParam);
//-------------------------------------------------------------------------------------------------------------
td_s32 vca_SetParameterandColour(td_s32 _iChn, TVcaConfig *_pstConfig);
td_s32 vca_GetParameterandColour(td_s32 _iChn, TVcaConfig *_pstConfig);
//-------------------------------------------------------------------------------------------------------------
td_s32 vca_SetRuleParameter(td_s32 _iChannelNo, td_s32 _iRuleID, char *_cRuleName, td_s32  _iValid);
td_s32 vca_GetRuleParameter(td_s32 _iChannelNo, td_s32 _iRuleID, char *_cRuleName, td_s32 *_iValid);
//-------------------------------------------------------------------------------------------------------------
td_s32 CoordinateVaryformNTSCtoPAL(int iChn, TVcaPoint *pstPoint);
td_s32 CoordinateVaryformPALtoNTSC(int iChn, TVcaPoint *pstPoint);
td_s32 CoordinateVaryFormCurrentSizetoFD1(int _iChn, TVcaPoint *_pstPoint);
td_s32 CoordinateVaryformFD1toCurrentSize(int _iChn, TVcaPoint *_pstPoint);
//-------------------------------------------------------------------------------------------------------------
td_s32 vca_SetTripwireParameter(td_s32 _iChn, td_s32 _iRul, TVcaParamTripwire *_pstVcaTripParam, td_s32 _iType);
td_s32 vca_GetTripwireParameter(td_s32 _iChn, td_s32 _iRul, TVcaParamTripwire *_pstVcaTripParam, td_s32 _iType);
//-------------------------------------------------------------------------------------------------------------
//caizhaoxu add 20130117 �������ܷ�������
td_s32 vca_SetCAPParameter(td_s32 _iChn, td_s32 _iRul, TVcaParamCAP *_pstVcaCapParam, td_s32 _iType);
td_s32 vca_GetCAPParameter(td_s32 _iChn, td_s32 _iRul, TVcaParamCAP *_pstVcaCapParam, td_s32 _iType);
td_s32 vca_SetCPCParameter(td_s32 _iChn, td_s32 _iRul, TVcaParamCPC *_pstVcaCpcParam, td_s32 _iType);
td_s32 vca_GetCPCParameter(td_s32 _iChn, td_s32 _iRul, TVcaParamCPC *_pstVcaCpcParam, td_s32 _iType);
td_s32 vca_SetCDDParameter(td_s32 _iChn, td_s32 _iRul, TVcaParamCDD *_pstVcaCddParam, td_s32 _iType);
td_s32 vca_GetCDDParameter(td_s32 _iChn, td_s32 _iRul, TVcaParamCDD *_pstVcaCddParam, td_s32 _iType);
td_s32 vca_SetSvdParameter(td_s32 _iChn, td_s32 _iRul, TVcaParamSVD *_pstVcaSvdParam);
td_s32 vca_GetSvdParameter(td_s32 _iChn, td_s32 _iRul, TVcaParamSVD *_pstVcaSvdParam);


//���ø�����ʹ�õ�PTZ�ص�����
td_s32 vca_SetCapPTZCallBack(td_u32 _iChn, td_u32 _iRule, void* _pFuncPtz);
//-------------------------------------------------------------------------------------------------------------
td_s32 vca_SetPerimeterParameter(td_s32 _iChn, td_s32 _iRul, TVcaParamPerimeter *_pstVcaPeriParam, td_s32 _iType);
td_s32 vca_GetPerimeterParameter(td_s32 _iChn, td_s32 _iRul, TVcaParamPerimeter *_pstVcaPeriParam, td_s32 _iType);
//-------------------------------------------------------------------------------------------------------------
//td_s32 vca_SetFaceParameter(td_s32 _iChannelNo, td_s32 _iRuleID, TVcaFaceParam_ex *_pstVcaFaceParam, td_s32 _iType);
//td_s32 vca_GetFaceParameter(td_s32 _iChannelNo, td_s32 _iRuleID, TVcaFaceParam_ex *_pstVcaFaceParam, td_s32 _iType);
//-------------------------------------------------------------------------------------------------------------
td_s32 vca_SetDiagnoseParameter(td_s32 _iChn, td_s32 _iRul, TVcaParamAVD *_pstVcaDiagParam, td_s32 _iType);
td_s32 vca_GetDiagnoseParameter(td_s32 _iChn, td_s32 _iRul, TVcaParamAVD *_pstVcaDiagParam, td_s32 _iType);
//-------------------------------------------------------------------------------------------------------------
td_s32 vca_SetOscParameter(td_s32 _iChn, td_s32 _iRul, TVcaParamOSC * _pstVcaOscParam, td_s32 _iType);
td_s32 vca_GetOscParameter(td_s32 _iChn, td_s32 _iRul, TVcaParamOSC * _pstVcaOscParam, td_s32 _iType);
//-------------------------------------------------------------------------------------------------------------
//td_s32 vca_Reboot(void);
//td_s32 vca_ParaSetAlmCountClr(td_s32 _iChannelNo, td_s32 _iRuleID, TVcaEventType _iEventType);
//td_s32 vca_ParaGetAlmCountTol(td_s32 _iChannelNo, td_s32 _iRuleID, TVcaEventType _iEventType, td_s32 *_iCount);

//-----------------------------------------------------------------------------------
int vca_putAlarmMsg(int _iChn, int _iRule, TVcaEventType _eType, int _iState, unsigned int _u32TId, unsigned int _u32Type);
int vca_getAlarmMsg(void);
//---------------------------------------------------------------------------------

td_s32 vca_ReSetDrawVSize(td_s32 _iChn, td_s32 _iVWSize, td_s32 _iVHSize);

int vca_get_alarm_state(int _iChn, int _iRule, int _iType);

int vca_set_module_reboot(int _iChn);
int vca_get_all_alarm();
int vca_clean_alarm(int _iChn, int _iRuleID, int _iEventType,int _iZeroFlag);

//void vca_get_avd_alarm_count(int _chn, int _rule);

int vca_get_alarm_count(int _chn, int _rule, TVcaAlarmMsg *pAlarMsg); // reopen by caizhaoxu for fix warning

//int vca_impowerlib_state();

int vca_GetVcaModuleEnable();

td_u32 vca_IfCapEnable(td_u32 _iChn, td_u32 _iRule);

//td_s32 vca_VCAAlarmInTimeSegToCore(int _iChn, vca_TRuleParam_ex *_stRuleParam);
//shihc move 20130225
td_s32 vca_capptz_speed(unsigned int _iW, unsigned int _iH);
td_s32 vca_capptz_action(td_s32 _s32Xcoordinate, td_s32 _s32Ycoordinate,td_s32 * _nx,td_s32 * _my,td_s32 * _action);
//shihc add 20130425 ����
td_s32 vca_SetCapPtzPriority(td_s32 _iChn, td_s32 _iPriority);
td_s32 vca_GetCapDelayFlat(td_s32 _iChn);
td_s32 Vca_CoordinateD1ToNet(td_s32 _iChn, TVcaPoint *_pstPoint);
td_s32 Vca_CoordinateNetToD1(td_s32 _iChn, TVcaPoint *_pstPoint);



#endif






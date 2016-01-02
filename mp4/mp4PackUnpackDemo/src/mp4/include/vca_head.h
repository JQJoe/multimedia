#ifndef __VCA_HEAD_H__
#define __VCA_HEAD_H__

#define VCA_OAB_FLAG 0
#define VCA_LPR_FLAG 0

#define	MAX_POLYGON_POINT_NUM		8
#define	MAX_CPC_POINT_NUM			4
#define	MAX_RULE_NUM				8
#define	MAX_RULE_NAME_LEN			16
#define	MAX_SAVE_TARGET_NUM		16
#define	MAX_ALARM_NUMBER		20000
#define MAX_PARAM_SIZE			2048		/*����������������ʱΪ2048���ֽ�*/
#define MAX_DATA_SIZE			2048		/*���ܷ����ϴ�������Ĳ�����С*/
#define MAX_IGNORE_REGION_NUM	3

#define TD_VCA_SUCCESS          0
#define TD_VCA_FAILURE          (-1)

#define	TD_LICENSE_CHECK_FAILE		0x0101			/*MAC��ַУ��ʧ��*/
#define	TD_LICENSE_NO_FILE			0x0102			/*û�п�����ļ�*/
#define	TD_DLOPEN_ERROR				0x0103			/*û�п�����ļ�*/

#define	TD_VCA_DISABLE				0x0201			/*��Ӧͨ�������ܷ�������δ��*/
#define	TD_VCA_DRAW_SIZE_ERROR		0x0202			/*���ӻ��ߵ�ͼ��ߴ����ʼ���ĳߴ粻һ��*/
#define	TD_VCA_ANALYSE_SIZE_ERROR	0x0203			/*����ͼ��ĳߴ����ʼ���ĳߴ粻һ��*/
#define	TD_VCA_CREAT_IMAGE_FAILE	0x0204			/*����ͼ��ʧ��*/
#define	TD_VCA_INIT_PEA_FAIL		0x0205			/*PEA��ʼ��ʧ��*/
#define	TD_VCA_INIT_OSC_FAIL		0x0206			/*OSC��ʼ��ʧ��*/
#define	TD_VCA_INIT_AVD_FAIL		0x0207			/*AVD��ʼ��ʧ��*/
#define TD_VCA_NO_ANALYSE			0x0208			/*��ͨ���ķ����߳�δ��������ֹreload��*/
#define TD_VCA_HAVE_NOT_INIT		0x0209			/*��ͨ�������ܷ�����û�г�ʼ��*/
#define TD_VCA_REINIT				0x020a			/*��ͨ�����ܷ����ظ���ʼ��*/
#define TD_VCA_NO_PTZ_FUNCTION		0x020b			/*���������PTZ �ص�����ָ��Ϊ��*/
		/*Ԥ������Ϊ��������µ����ܷ������ܱ���*/

#define	TD_VCA_PARAM_ERROR			0x0901			/*������������ȷ*/

#define ENABLE_PEA			0x01
#define ENABLE_OSC			0x02
#define ENABLE_AVD			0x04
#define ENABLE_CAP			0x08
#define ENABLE_CAP_td		0x10
#define ENABLE_CDD			0x20
#define ENABLE_CPC			0x40
#define ENABLE_VFD			0x80
#define ENABLE_SVD			0x100
#if VCA_OAB_FLAG
#define ENABLE_OAB			0x200	/*����- ˫����- �ǻ�*/
#endif

#if VCA_LPR_FLAG
#define ENABLE_LPR			0x400
#endif

/*�����ṹ��*/
typedef struct
{
	int	m_iX;
	int	m_iY;
} TVcaPoint;

/*ֱ�߽ṹ��*/
typedef struct
{
	TVcaPoint 	m_stStart;
	TVcaPoint 	m_stEnd;
}TVcaLine;

typedef struct
{
	int m_s32X1;
	int m_s32Y1;
	int m_s32X2;
	int m_s32Y2;
}TVcaRect;

/*����νṹ��*/
typedef struct
{
	int			m_iPointNum;
	TVcaPoint	m_stPoint[MAX_POLYGON_POINT_NUM];   
}TVcaPolygon;

/*ʸ������*/
typedef struct
{
	int     flag;			/**��ȡ���״̬��
			1: ��ʾ�ջص�Ԥ��λ; 0��ʾ�˶���;
			2:��ʾ������ٸ�ͣ����; 3:��ʾ��Ԥ��λ������;4:�ֿ�*/
							/**�������״̬��
			0:�������; 1:����������������˶�*/
	float	m_s32X1;		/**���·����˶�����*/
	float	m_s32Y1;		/**���ҷ����˶�����*/
	float	m_s32Z1;		/**����*/

	int		m_s32Speed;	/*�ٶ�*/
}TVcaMovVector;

typedef struct		/*��Ƶԭʼ���ݵĲ���*/
{
	int				m_iPixelFormat;		/*YUV��ʽ*/
	int				m_iWidth;			/*YUVͼ��Ŀ��*/
	int				m_iHeight;			/*YUVͼ��ĸ߶�*/
	int				m_iStride;			/*YUVͼ��Ŀ��*/
	unsigned char*	m_u8Data;			/*YUVͼ������*/
	unsigned int*	m_u32PhyAddr;		/*YUV�����ַ,�����Ժ���չ*/
}TVcaFrameParma;

/*��ɫö��*/
typedef enum
{
	VCA_COLOR_red	= 1,	
	VCA_COLOR_green,			
	VCA_COLOR_yellow,		
	VCA_COLOR_blue,			
	VCA_COLOR_magenta,		
	VCA_COLOR_cyan,		
	VCA_COLOR_black,			
	VCA_COLOR_white			
}TVcaColor;

typedef struct
{
	TVcaPoint	m_sTripwireArrow[4];
	TVcaPoint	m_sPerimeterArrow[4];
}TVcaRule;

typedef enum
{
	YUV_PLANAR_420 = 1,
	YUV_PLANAR_422,
	YUV_PLANAR_444
}EVcaPixelFormat;

typedef enum  
{
	VCA_TRIPWIRE = 0,		/* �����¼�*/
	VCA_DBTRIPWIRE,			/* ˫�����¼�*/
	VCA_PERIMETER,			/* �ܽ��¼�*/
	VCA_LOITER,				/* �ǻ��¼�*/
	VCA_PARKING,			/* ͣ���¼�*/
	VCA_RUN,				/* �����¼�*/
	VCA_HIGH_DENSITY,		/* ��Ա�ܶ��¼�*/
	VCA_ABANDUM,			/* �������¼�*/
	VCA_OBJSTOLEN,			/* �������¼�*/
	VCA_FACESPOT,           /* ����ʶ��*/
	VCA_AVD,				/*��Ƶ���*/
	VCA_CAP,				/*Ŀ�����*/
	VCA_CAP_td,				/*tdĿ�����*/
	VCA_CDD,				/*��Ա�ۼ�*/
	VCA_CPC,				/*����ͳ��*/
	VCA_VFD,				/*�������*/
	VCA_SVD,				/*��ڼ��*/
#if VCA_OAB_FLAG
	VCA_OAB_RTO,			/*����*/
	VCA_OAB_BTP,			/*˫����*/
	VCA_OAB_LOI,			/*�ǻ�*/
#endif

#if VCA_LPR_FLAG
	VCA_LPR,				/*����ʶ��*/
#endif
	
	VCA_MAX
} TVcaEventType;

typedef enum	/*������Ʊ�ʶ,vca����Ҫ�������,��ͨ���ص�����,�˱�ʶ����
				�ص�������Ҫ��ʲô*/
{
	CAP_SET_DOME_STATUS		= 0x00000000,		/**< �������״̬������*/
	CAP_GET_DOME_STATUS		= 0x00000001,		/**< ��ȡ���״̬������*/

	CAP_SET_DOME_TO_PRESET	= 0x00000002,		/**< ���������Ԥ��λ*/	
	CAP_ENABLE_DOME			= 0x00000003,		/**< ʹ���������*/
	CAP_DISABLE_DOME			= 0x00000004		/**< ��ʹ���������*/
}TVcaCapControlFlag;

typedef struct
{
	int				s32DetPanRange;
	int				s32DetTiltRange;
	unsigned char	cVelocityStatus;	//0:disable   0xff:enable
	int				s32PanVelocity;
 	int				s32TiltVelocity;
}TVcaPTZContrule;

typedef struct vcaCapSpeedResult
{
	int sUseSpeedCalc;
	int sXSpeed;
	int sYSpeed;
}TvcaCapSpeedResult;

typedef struct vcaCapResult
{
	int s32TargetStatus;					//Target Status.	-1：Lost 0：Searching  1：Tracking
	TVcaPTZContrule stPtzResult;			//Information about PTZ Control. valid only when s32TargetStatus=1.
	int	s32ReservedResult1;				//Reserved Result output
	unsigned int u32ReservedResult2;				//Reserved Result output
	TvcaCapSpeedResult stSpeedResult;
	unsigned int m_iTargetW;
	unsigned int m_iTargetH;
}TVcaCapResult;

//�ص�����
typedef int (* VcaContrlCapStatus)(TVcaCapResult *_VcaCapResult);
typedef int (* VcaContrlCap_td)(TVcaMovVector* _pVcaMovVector, TVcaCapControlFlag _iFlag);
typedef int (* VcaEraseFog)(int _iFlag);

typedef struct		/* �����߲���*/
{
	int				m_iStructSize;			/*�ýṹ����ֽ����������ò�������*/
	int				m_iTargetTypeCheck;		/*�������: 1-�ˡ�2-����3-�˳���0-������*/
	int				m_iType;				/*0-������߻�1-˫�����*/
	int				m_iTDirection;			/*���߱�������*/
	int				m_iMinDistance;			/*���ü����С����: Ĭ��0*/
	int				m_iMinTime;				/*����ʱ��: Ĭ��0*/
	int				m_iDisplayRule;			/*�Ƿ���ʾ������: 0 - ����ʾ	1-��ʾ */
	int				m_iDisplayStat;			/*�Ƿ���ʾ��������: 0 - ����ʾ	1-��ʾ*/
	int				m_iAlarmCount;			/*��������: �ø���������Ļ����ʾ*/
	int				m_iColor;				/*δ����ʱ��������ɫ*/
	int				m_iAlarmColor;			/*����ʱ�Ĺ�������ɫ*/
	TVcaLine		m_stLine;				/**/
}TVcaParamTripwire;

typedef struct		/*�ܽ����*/
{
	int				m_iStructSize;			/*�ýṹ����ֽ����������ò�������*/
	int				m_iTargetTypeCheck;		/*�������: 1-�ˡ�2-����3-�˳���0-������*/
	int				m_iMode;				/*����ģʽ: ���֡����롢�뿪*/
	int				m_iType;				/*���޷���*/
	int 			m_iDirection;       	/*��������*/
	int				m_iMinDistance;			/*������С���ؾ���: Ĭ��0	*/
	int 			m_iMinTime;				/*�������ʱ��: Ĭ��0*/
	int				m_iDisplayRule;			/*�Ƿ���ʾ������: 0 - ����ʾ	1-��ʾ */
	int				m_iDisplayStat;			/*�Ƿ���ʾ��������: 0 - ����ʾ	1-��ʾ*/
	int				m_iAlarmCount;			/*��������: �ø���������Ļ����ʾ*/
	int				m_iColor;           	/*δ����ʱ��������ɫ*/
	int				m_iAlarmColor;      	/*����ʱ�Ĺ�������ɫ*/
	TVcaPolygon		m_stRegion;	
}TVcaParamPerimeter;

typedef struct		/*��Ʒ��������*/
{
	int				m_iStructSize;		/*�ýṹ����ֽ����������ò�������*/
	int				m_iSceneType;		/*��������  0���� 1����*/
	int				m_iCameraType;		/*�������  0��ͨ��� 1������*/
	int				m_iDisplayRule;		/*�Ƿ���ʾ������: 0 - ����ʾ	1-��ʾ */
	int				m_iDisplayStat;		/*�Ƿ���ʾ��������: 0 - ����ʾ	1-��ʾ*/
	int				m_iAlarmCount;		/*��������: �ø���������Ļ����ʾ*/
	int				m_iColor;			/*δ����ʱ��������ɫ*/
	int				m_iAlarmColor;		/*����ʱ�Ĺ�������ɫ*/
	int				m_iTimeMin;    		/*�������ʱ�䣬��Ʒ��ʧʱ�����Ҫ���ڴ˷�ֵ*/
	int				m_iSizeMin;			/*������������С������*/
	int				m_iSizeMax;			/*�������������������*/
	TVcaPolygon		m_stMainRegion;		/*�������ṹ*/
	TVcaPolygon		m_stIgnoreRegion[MAX_IGNORE_REGION_NUM]; 	/*���Լ���С��*/
}TVcaParamOSC;

typedef struct		/*��Ƶ���AVD ����*/
{
	int				m_iStructSize;			/*�ýṹ����ֽ����������ò�������*/
	int				m_iRuleEvevtid;		/* ��Ƶ��Ϲ����ʶ����λ��Э���ĵ����
											������� 	0x0000000001
											���������	0x0000000010
											�������	0x0000000100 
											��������Ϊƫɫ��ϡ����涳����ϡ��ź�ȱʧ���
											�����任��� ��Ϊ������� PTZʧ�����*/
	int				m_iAlarmCount;      /*��������: �ø���������Ļ����ʾ*/
	int				m_iDisplayStat;
	int				m_iCheckTime;
} TVcaParamAVD;

typedef struct		/*�������CAP ���ò���*/
{
	int				m_iStructSize;		/*�ýṹ����ֽ����������ò�������*/
	int				m_s32Mode;			/*����С����*/
	int				m_s32Color;		/*δ����ʱ��������ɫ*/
	int				m_s32AlarmColor;	/*����ʱ�Ĺ�������ɫ*/	
	int				m_s32PresetNum;	/*��ʼλ�ñ��*/
	int				m_s32ShowPresetNum;	/*��Ҫ��ʾ����ʼλ�ñ��*/
	TVcaPolygon		m_stRegion;			/*�������ṹ*/
	VcaContrlCapStatus	m_pVcaContrlCapStatus;	/*�������ת���Ļص�����*/
	VcaContrlCap_td		m_pVcaContrlCap_td;		/*td�������ת���Ļص�����*/
	int             m_s32ZoneSet;       /*������������0����ȫ������1������߸���2�����������*/
	TVcaLine		m_stLine;			/*�����߽ṹ*/
}TVcaParamCAP;

typedef struct 
{
	TVcaPoint m_LeftUp;
	TVcaPoint m_RightDown;
}TVcaRect_Ex;

typedef struct		/*��Ա�ۼ�CDD���ò���*/
{
	int				m_iStructSize;		/*�ṹ���С*/
	int				m_iSensitivity;		/*������*/
	int				m_iFlag;			/*��ʱ����*/
	int				m_iRegionNum;		/*�������*/
	//TVcaRect		m_stRegion[4];		/*�������,���4��*/
	TVcaRect_Ex		m_stRegion[4];		/*�������,���4��*/
}TVcaParamCDD;

typedef struct		/*����ͳ��CPC���ò���*/
{
	int				m_iStructSize;		/*�ṹ���С*/
	int				m_iSensitivity;		/*������*/
	int				m_iPointNum;		/*�������߶ε�ĸ���,���4��*/
	int				m_iAlarmCount;		/*��������*/
	TVcaPoint		m_stPoint[MAX_CPC_POINT_NUM];
}TVcaParamCPC;

typedef struct		/*����ʶ��VFD���ò���*/
{
	int				m_iStructSize;		/*�ṹ���С*/
	int				m_iRegionNum;
	TVcaRect_Ex		m_stRegion[4];		/*�������,���4��*/
}TVcaParamVFD;

typedef struct		/*��ڼ��SVD���ò���*/
{
	int				m_iStructSize;		/*�ṹ���С*/
	int				m_iAlertTime;
	int				m_iClearTime;
	int				m_iSensitivity;
	int				m_iAlarmCount;
	int				m_iColor;			/*δ����ʱ��������ɫ*/
	int				m_iAlarmColor;		/*����ʱ�Ĺ�������ɫ*/
	int				m_iDisplayRule;		
	int				m_iDisplayStat;
	int				m_iRegionNum;
	TVcaRect_Ex		m_stRegion[4];		/*�������,���4��*/
}TVcaParamSVD;

#if VCA_OAB_FLAG
typedef struct		/*�ǻ�������ò���*/
{
	int				m_iStructSize;		/*�ṹ���С*/
	int				m_iMinTime;			/*��Сʱ��*/
	int				m_iAlarmCount;		/*��������: �ø���������Ļ����ʾ*/
	TVcaPolygon		m_stRegion;	
}TVcaParamOabLoi;
#endif

#if VCA_LPR_FLAG
typedef struct		/*����ʶ�����ò���*/
{
	int				m_iStructSize;		/*�ṹ���С*/
	int				m_iRegionNum;
	TVcaRect_Ex		m_stRegion[4];		/*�������,���4��*/
}TVcaParamOabLpr;
#endif
typedef struct
{
	unsigned short	lb_x;
	unsigned short	lb_y;
	unsigned short	ru_x;
	unsigned short	ru_y;
}vca_TRECT;
//�û������б������Ϣ
typedef struct
{
	vca_TRECT		rect;		/*���ϡ���������*/
	unsigned short	type;		/*���ͣ��ˡ�����*/
	unsigned short	velocity;	/*�ٶ�*/
	unsigned short	direction; 	/*����*/
	unsigned short	id;			/*Ŀ��ID*/
}vca_TTargetInfo;
typedef struct
{
	unsigned short	target_num;	/*Ŀ�����*/
	vca_TTargetInfo	targets[MAX_SAVE_TARGET_NUM]; /*Ŀ����Ϣ*/
}vca_TTargetSet;

typedef struct		/*������*/
{
	int 	m_iFlag;	/*��������*/
}TVcaParamEFG;

/**********           ��Ϊ�����¼�����        **********/
typedef union
{
	TVcaParamTripwire	m_stTripwire;	/* ��Խ���߲���*/
	TVcaParamPerimeter	m_stPerimeter;	/* �ܽ����*/
	TVcaParamOSC		m_stoscer;		/*��Ʒ��������*/
	TVcaParamAVD		m_stDiagEvent;	/*��Ƶ��ϲ���*/
	TVcaParamCAP		m_stCap;		/*�Զ�Ŀ�����*/
	TVcaParamEFG		m_stEfg;		/*������*/
	TVcaParamCDD		m_stCdd;		/* ��Ա�ۼ�*/
	TVcaParamCPC		m_stCpc;		/* ����ͳ��*/
	TVcaParamVFD		m_stVfd;		/* �������*/
	TVcaParamSVD		m_stSvd;		/* ��ڼ��*/
#if VCA_OAB_FLAG
	TVcaParamOabLoi		m_stOabLoi;		/* �ǻ�*/
#endif

#if VCA_LPR_FLAG
	TVcaParamOabLpr		m_stOabLpr;		/*����ʶ��*/
#endif
				/*������������ռ䡣�Ժ���ӵ����ܷ����ܲ������ܳ��������ʹ�С*/
	char				m_s8MaxSize[MAX_PARAM_SIZE];	
}UVcaEventParam;		

typedef struct			/*�������ò���*/
{
	int		m_iAnalyseVideoWidth;			/*����ͼ��Ŀ��*/
	int		m_iAnalyseVideoStride;		/*����ͼ��Ŀ��*/
	int		m_iAnalyseVideoHeight;			/*����ͼ��ĸ߶�*/
	int		m_iTargetMainVideoWidth;		/*������ͼ��Ŀ��*/
	int		m_iTargetMainVideoStride;	/*������ͼ��Ŀ��*/
	int		m_iTargetMainVideoHeight;		/*������ͼ��ĸ߶�*/
	int		m_iTargetSubVideoWidth;		/*������ͼ��Ŀ��*/
	int		m_iTargetSubVideoStride;		/*������ͼ��Ŀ��*/
	int		m_iTargetSubVideoHeight;			/*������ͼ��ĸ߶�*/
	int		m_iDisplayTarget;		/* �Ƿ����Ŀ���*/
	int		m_iDisplayTrace;		/* �Ƿ���ӹ켣��*/
	int		m_iTraceLength;			/* �켣����*/
	int		m_iTargetColor;			/* Ŀ�����ɫ*/
	int		m_iTargetAlarmColor;	/* ����ʱĿ�����ɫ*/
}TVcaConfig; // ���ܷ������ò���  

typedef struct
{
	int					m_iRuleID;						/*�����*/
	char				m_cRuleName[MAX_RULE_NAME_LEN];	/* ��������*/
	int					m_iValid;				/* �ù����Ƿ���Ч*/
	TVcaEventType		m_eEventType;			/* ��Ϊ�����¼����� */
	UVcaEventParam		m_stEventParam;			/* ��Ϊ�����¼�����*/
}TVcaRuleParam;   /* �������ò���*/

typedef struct 
{
	int		m_iEnableAdvanced; 	/*�Ƿ����ø߼�����*/
	int		m_iMinSize; 		/*Ŀ����С������*/
	int		m_iMaxSize; 		/*Ŀ�����������*/
	int		m_iMinWidth;  		/*��С���*/
	int		m_iMaxWidth;  		/*�����*/
	int		m_iMinHeight;  		/*��С�߶�*/
	int		m_iMaxHeight;  		/*���߶�*/
	int		m_iTargetMinSpeed;	/*Ŀ����С�����ٶ�(-1Ϊ��������) */
	int		m_iTargetMaxSpeed;	/*Ŀ����������ٶ�(-1Ϊ��������) */
	int 	m_iMinWHRatio;		/*��С����ȡ�������ȡ���˲���*/
	int 	m_iMaxWHRatio;		/*��󳤿�ȡ�������ȡ���˲���*/
	int		m_iSensitivity;		/*�����ȼ���*/
}TVcaAdvanceParam;		/* ���ܷ����߼�����*/

typedef struct
{
	int					m_iEnable;		/* �ò�����Ч��δ��ʹ��*/
	int 				m_iEnVca;		/*ʹ�����������ܷ�������λʹ�ܣ�0-�ر�	1-ʹ�ܡ�
											�ñ��������������ƣ�����ʹ���������ܷ�����
											ÿһλ��ʾ�����ܷ������ͷֱ�ΪΪ��0-PEA	  1-OSC    2-AVD	*/
	int					m_iChn;			/* ���ܷ���ͨ����*/
	
	TVcaConfig			m_stConfig;		/* ���ܷ������ò���  */
	
  	TVcaRuleParam		m_stRule[MAX_RULE_NUM];		/* ��Ϊ�������ò���*/
	
  	TVcaAdvanceParam	m_stAdvancedParam;			/* ���ܷ����߼�����*/
}TVcaParam;

//������Ϣ ����business����ͻ��˷��ͱ�����Ϣ
typedef struct
{
	unsigned int	m_iTargetId;			/*Ŀ��id*/
	int				m_iTargetType;			/*1- �� 2- ������� 3-��*/
	int				m_iTargetSpeed;			/*Ŀ���ٶ�*/
	int				m_iTargetDirection;		/*Ŀ���˶�����*/
	TVcaRect		m_stPosition;			/*Ŀ���λ��*/
}TPeaOscTargetInfo;

typedef struct
{
	int						m_s32AlarmTargetNum;	/*��ǰ����Ŀ��ĸ���*/
	TPeaOscTargetInfo		m_stAlarmTargetInfo[MAX_SAVE_TARGET_NUM];		/*����Ŀ����Ϣ*/
}TVcaPeaOscAlmInfo;/*OABҲ�ô˽ṹ*/

typedef enum	/*����״̬���㷨��ǰ״̬*/
{
	ATF_FOLLOW_START         = 0x00000000,		/**< ���ٳ�����*/
	ATF_FOLLOW_RUNING        = 0x00000001,		/**< ����������*/	
	ATF_FOLLOW_POZITION      = 0x00000002		/**< �ػ�Ԥ��λ*/	
}TVcaCapStatus;

typedef struct		/*����������㷨�����ݽṹ*/
{
	//int					m_iTargetFlag;				/*�Ƿ����Ŀ���1-����  !1-������*/
	//TVcaCapStatus		m_stStatus;			/*�����㷨��ǰ��״̬*/
	TVcaMovVector		m_stMovVector;		/*�����Ҫ��ͷ�˶�����ͷ���˶���ʽ*/
	TVcaRect			m_stRect;
}TVcaCapAlmInfo;

typedef struct		/*cdd ������Ϣ*/
{
	char m_iStatusBuf[4][32];	/*��¼�˶�����*/
}TVcaCddAlmInfo;

typedef struct
{
    unsigned int m_iInNum;
    unsigned int m_iOutNum;
}TVcaCpcAlmInfo;

typedef struct
{
	TVcaEventType			m_eEventType;			/*�¼�����*/
	int						m_s32AlarmStatus;		/*����״̬��0-����1-����2-(CDDʱ��������1-MIDD  2-HIGH)*/
													/*�¼�����Ϊ��Ƶ���ʱ,��λ��ʾ����״̬
													*������� 		0x0000000001
													*���������	0x0000000010
													*�������		0x0000000100 
													*��������Ϊƫɫ��ϡ����涳����ϡ��ź�ȱʧ���
													*�����任��� ��Ϊ������� PTZʧ�����*/
	int						m_s32AlarmCount;		/*��ֹ��ǰ���ۼӵ���ʵ��������*/
	unsigned char			m_u8Data[MAX_DATA_SIZE];			/*������Ҫ���ݲ�ͬ�ı�������ǿ��ת����*/
}TVcaRuleAlarmInfo;

typedef struct
{
	TVcaRuleAlarmInfo	m_stAlarmRuleInfo[MAX_RULE_NUM];
}TVcaAlarmMsg;

/**************************************************************************************************************
*���ƣ�td_vca_DrawTarget
*���ܣ����øú�������YUV �����ϵ��ӻ��ߣ���Ҫ��֪YUV ���ݵĵ�ַ��С����Ӧ��Ϣ��
			ע: �����ͨ���ű���Ϊһ���Ѿ��������ܷ�����ʼ����ͨ�����������ʾ
			����Ҫ���ߵ�ͨ����û�ж����ܷ������г�ʼ����
*���룺	_iChn :		ͨ����			_pstFrameParam : ��Ƶͼ�����
			_pstFrameAND, _pstFrameSUB : IVE ����
			_iHardOrSoft : ���߷�ʽ��1-IVE����		0-�������
*���: ��
*����ֵ:TD_VCA_HAVE_NOT_INIT		TD_VCA_DRAW_SIZE_ERROR		TD_VCA_SUCCESS
**************************************************************************************************************/
int td_vca_DrawTarget(int _iChnId, TVcaFrameParma* _pstFrameParam,
			TVcaFrameParma* _pstFrameAND, TVcaFrameParma* _pstFrameSUB, int _iHardOrSoft);

/****************************************************
*���ƣ�td_vca_AnalyseSource
*���ܣ����øú����Ὣ��ƵYUV ���������ܷ�����
			ע: �����ͨ���ű���Ϊһ���Ѿ��������ܷ�����ʼ����ͨ�����������ʾ
			����Ҫ���ߵ�ͨ����û�ж����ܷ������г�ʼ����
*���룺_iChn:ͨ����			_iWidth:��Ƶ���			_iHeight:��Ƶ�߶�
		    _pFrame:��ǰ֡����	_ibufsize:֡��С			_iFrameNum:֡���
*����ֵ: TD_VCA_SUCCESS			
****************************************************/
int td_vca_AnalyseSource(int _iChnId, TVcaFrameParma* _pstFrameParam);

/**************************************************************************************************************
*���ƣ�td_vca_Init
*���ܣ�У�����ܷ��������ļ���������ܷ����ɷ����С�
			�������ʧ�ܣ����ܶ��κ���Ƶͨ���������ܷ�����ʼ����
*��������
*����ֵ: TD_VCA_SUCCESS		TD_LICENSE_CHECK_FAILE		TD_LICENSE_NO_FILE
***************************************************************************************************************/
int td_vca_Init(void);

/***************************************************************************************************************
*���ƣ�td_vca_Creat
*���ܣ����ܷ����ں˳�ʼ����ÿ��ʼ��һ��ͨ��Ҫ���øú���һ�Ρ�
*������_pstVCAParam:���ܷ������ò���
			_iChnNo : ���ܷ���ͨ���š�
*����ֵ: TD_VCA_SUCCESS		TD_LICENSE_NO_FILE		TD_LICENSE_CHECK_FAILE
**************************************************************************************************************/
int td_vca_Create(int _iChnId, TVcaParam* _pstVCAParam);

/*************************************************************************************************************
*���ƣ�td_vca_Destroy
*���ܣ���ĳ��ͨ�������ܷ���ȥ��ʼ����
*������_iChnNo : ȥ��ʼ����ͨ����
*����ֵ: TD_VCA_SUCCESS		TD_VCA_HAVE_NOT_INIT
*************************************************************************************************************/
int td_vca_Destroy(int _iChnId);

/*************************************************************************************************************
*���ƣ�td_vca_Reload
*���ܣ�������������ô˺����������¼������ܷ�������
*������_iChnNo : ���¼��ص�ͨ����
*����ֵ: TD_VCA_SUCCESS		TD_VCA_HAVE_NOT_INIT		TD_VCA_NO_ANALYSE
*************************************************************************************************************/
int td_vca_Reload(int _iChnId, TVcaParam* _pstVCAParam);


/*************************************************************************************************************
*���ƣ�td_vca_GetUserData
*���ܣ����ܷ���˽�����ݻ�ȡ
*������_iChn : ͨ����		_cBuffer :  �����ַ	iBufferLen : ���ݳ���
*����ֵ:  TD_VCA_SUCCESS		TD_VCA_HAVE_NOT_INIT		TD_VCA_NO_ANALYSE
***************************************************************************************************************/
int td_vca_GetUserData(int _iChnId, unsigned char* _pcBuffer, int* _iBufferLen);

/*************************************************************************************************************
*���ƣ�td_vca_StopDraw
*���ܣ�ֹͣ����,�ķֱ���ʱʹ��,ǰ���ǻ���λ��û��,
			������Ĭ���ǻ��ߵ�,���ķֱ���û���κ�Ӱ��
*������_iChn : ͨ����
*����ֵ:  TD_VCA_SUCCESS		TD_VCA_HAVE_NOT_INIT		TD_VCA_NO_ANALYSE
***************************************************************************************************************/
int td_vca_StopDraw(int _iChnId, TVcaParam* _pstVCAParam);

/*************************************************************************************************************
*���ƣ�td_vca_StartDraw
*���ܣ���������,���td_vca_StopDraw�ӿ�
*������_iChn : ͨ����		
*����ֵ:  TD_VCA_SUCCESS		TD_VCA_HAVE_NOT_INIT		TD_VCA_NO_ANALYSE
***************************************************************************************************************/
int td_vca_StartDraw(int _iChnId, TVcaParam* _pstVCAParam);

/**************************************************************************************************************
*���ƣ�td_vca_GetAlarmInfo
*���ܣ���ȡ���ܷ�����������
*������_iChnNo : ͨ����
*����ֵ: 
***************************************************************************************************************/
TVcaAlarmMsg*  td_vca_GetAlarmInfo(int _iChnId);


/***************************************************************************************************************
*���ƣ�td_vca_SetAlarmInfo
*���ܣ��������ܷ���ģ�鱨�������ۼӳ�ֵ��
*������_pstVCAParam:���ܷ������ò���			_iRuleId : �����
*����ֵ: TD_VCA_HAVE_NOT_INIT		TD_VCA_SUCCESS
****************************************************************************************************************/
int td_vca_SetAlarmCount(int _iChnId, int _iRuleId, int _iCount);

/*
* �Ƚϰ�ȫ�Ļ�ȡ������Ϣ�ӿڡ�
*/
int td_vca_GetAlarmInfo_s(int _iChnId, TVcaAlarmMsg *stVcaAlarmMsg);

#endif

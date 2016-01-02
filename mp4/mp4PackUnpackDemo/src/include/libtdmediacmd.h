/*******************************************************************
�ļ���	:assistant.h
��˾	:������ΰҵ����Ƽ����޹�˾
������	:������
��������:2009-10-28
��Ҫ����:ý��㸨��ģ�����ݶ��弰�ӿں���ԭ��
�޸ļ�¼:2009-10-28,��������������
        
******************************************************************/
#ifndef _ASSISTANT_H_
#define _ASSISTANT_H_
#include "guiparameter.h"
#include "ptz.h"
#include "vca.h"
#include "atm_business.h"
#include "user.h"
#include "vehicle_mounted.h" 
#include "wifi.h"
#include "preview.h"
#define ONEKEY_BURN         0  //add by shishengnan 2010/11/16 ���ʱ����һ����¼
#define PLAYBACK            1  //add by shishengnan 2010/11/16 ��¼�ʹ��ʱ���ܻط�
#define SET_PACKAGE_POLICY  2  //���ô������ ��¼ʱֻ�ܰ�ʱ����
#define SET_DELETE_POLICY   3  //���ô�����ʱ��ɾ�����ԣ���¼ʱֻ��ѡ��ɾ���ļ�
#define TAG_QUERY           4  //��ѯ�����Ϣ�� ��¼����ʱ���ܲ�ѯ
#define SET_VIDEO_ENCODER   5  //������Ƶ���룬�޸�֡�ʣ��ֱ��ʣ���Ƶ���������
      						   //��¼ʱ�޸Ļᵼ�¸���ͨ���ļ�ʱ��β�ͳһ����˼�������
#define FORCE_PACKAGE       6  //¼���ļ�ǿ�ƴ��

#define ADD_PTZ_PROTOCOL	0	//���Э��
#define DEL_PTZ_PROTOCOL	1	//ɾ��Э��
#define PTZ_PROTOCOL_USE	0	//�����Э��
#define PTZ_PROTOCOL_DEL	1	//�����Э��
#define	PTZ_CRUISE_START	0	//��ʼ����Ѳ���켣
#define PTZ_CRUISE_STOP		1	//ֹͣ����Ѳ���켣


typedef struct
{
	int m_iConnectMod;		//��16λ��ʾ ģʽ ip/����/����ģʽ����16λ0-˽�У�1-onvif  ����:
	char m_strUrl[GUI_DIG_CHN_URL_LEN  + 1]; //��������ַ
	char m_strProxy[GUI_DIG_CHN_URL_LEN  + 1]; //����IP
	int m_iPort;	//�˿ں�
	int m_iChn;	//�Է�ͨ����
	int m_iStreamType;	//��������,0:������, 1������
	int m_iConntectType;  //tcp/udp/bc
	int m_iPtzAddr;	//ptz��ַ
	char m_strPtzProtocol[GUI_DIG_CHN_PTZ_NAME + 1]; //ptzЭ��
	char m_strUserName[GUI_DIG_CHN_NAME_LEN + 1]; //�û���
	char m_strUserPsw[GUI_DIG_CHN_NAME_LEN + 1];	//����
	int m_iEnable;    //״̬
	char m_strVdecPsw[GUI_DIG_CHN_NAME_LEN + 1];	//��Ƶ��������
	td_u8 m_strRtspUrl[256];	// ������չRTSP�ĵ�ַ����RTSP ��ַ���ȴ���80�ֽ�ʱ��ʹ�ñ��ֶΣ�����ʹ��ԭ�ֶΡ�
} TDigChnPamaMsg;


typedef struct
{
	int m_iRuleEnable;			//�����Ƿ�ʹ��
	int m_iTripwireEnable;		//�������¼��Ƿ�ʹ��
	int m_iPerimeterEnable;		//�ܽ��¼��Ƿ�ʹ��
	int m_iFaceEnable;			//��������¼��Ƿ�ʹ��
	int m_iDiagnoseEnable;		//��Ƶ����¼��Ƿ�ʹ��
	int m_iLeaveEnable;         //��Ʒ�����¼��Ƿ�ʹ��
	int m_iLostEnabe;           //��Ʒ��ʧ�¼��Ƿ�ʹ��
	int m_iCapEnable;			//���ܸ����¼��Ƿ�ʹ��
	int m_iCpcEnable;           //����ͳ���¼��Ƿ�ʹ��
	int m_iCddEnabe;            //��Ⱥ�ۼ��¼��Ƿ�ʹ��
	int m_iSvdEnable;		//��ڼ���¼��Ƿ�ʹ��

} TVcaRuleEnableType;

typedef struct
{
	int 					m_iChannel;
	int 					m_iRulesNo;
	TVcaRuleEnableType	m_iEnableMsg;
} TVcaRuleEnableStat;

typedef struct
{
	td_s32 m_iIpcInsert;  
	td_s32 m_iRemotePreview;
	td_s32 m_iRemoteDownload;   
	td_s32 m_iRxSum;   
	td_s32 m_iTxSum; 
}TCmdNetPerformanceCost; 

typedef void (*td_cmd_ProcRebldProgCallBack)(int);

void GetZoomTimes(int _iChn,int *_piPx,int *_piPy);
//int Storage_Init();
//int GetComFormat(COM_Params* _comParams,int _iComNum);




//---------------------------------------------------------------------------
//int td_cmd_setwifinetconfig(char* const ip,char* const mask, char* const gateway,char* const dns, char* essid, char* encripy, char* username, char* pwd, char* keynum);//xujiayu wifi
int td_cmd_setInputNorm(td_s32 _iChn, const int mode);
int td_cmd_getInputNorm(td_s32 _iChn, int * mode);
int td_cmd_setOutputNorm(const int mode);		//Added by Leeon Tonie for Tiandy-Dvr, 090106
int td_cmd_getOutputNorm(int * mode);		//Added by Leeon Tonie for Tiandy-Dvr, 090106
int td_cmd_getvideopara(const int chn,structVideoParam* _sp,int _iNum);
int td_cmd_getvideopara(const int chn,structVideoParam* _sp,int _iNum);
td_s32 td_cmd_changevideopara(const td_s32 _iChn, td_s8* const bright, td_s8* const contrast, td_s8* const saturation, td_s8* const hue);
int td_cmd_getvideoquality(const int chn);  //modified by gxl 081023
td_s32 td_cmd_setvideoquality(const td_s32 _iChn,td_s8* const _cQua); //modified by gxl 20081023
int td_cmd_getframerate(const int chn); //modified by gxl 20081023
td_s32 td_cmd_setframerate(const td_s32 _iChn,td_s8* const _Framerate); //modified by gxl 20081023

int td_cmd_getiframerate(const int chn);
td_s32 td_cmd_setiframerate(const td_s32 _iChn,td_s8* const _Framerate);

int td_cmd_getstreamtype(const int chn);
td_s32 td_cmd_setstreamtype(const td_s32 _iChn, td_s8* const _streamtype);
//SUN Wei add for 7.6
td_s32 td_cmd_setmotiondetectenable(const int _iChn, td_s32 _iEnable);
//SUN Wei add for 7.6 end
td_s32 td_cmd_getmotiondetectarea(const td_s32 _iChn, td_s8* area[]);
td_s32 td_cmd_setmotiondetectarea(const int _iChn, char* const area[]);
int td_cmd_getmotiondetectsensitivity(const int chn);
td_s32 td_cmd_setmotiondetectsensitivity(const td_s32 _iChn, td_s8* const _threshold);
td_s32 td_cmd_setOverlaydetectenable(const int _iChn, td_s32 _iEnable);


//---------------------------------gxl-----------------------------------------
td_s32 td_cmd_setdateformat(td_s32 _iMode, td_u8* _pcSeperatechar);			//Added by Leeon Tonie 090206, as an interface function.
td_s32 td_cmd_getdateformat(td_s32* _piMode, td_u8* _pcSeperatechar);		//������ 100107
td_s32 td_cmd_getosdtext(const td_s32 _iChn, td_s8* _text);
td_s32 td_cmd_setosdtext(const td_s32 _iChn, td_s8* const _text);
int td_cmd_getosdpos(const int chn, int distype, int* enable);							//������ 100322

td_s32 td_cmd_getosddisplayex(const td_s32 _iChn, td_s32 layno,td_s32 _iDistype, td_s32* x, td_s32* y, td_s32* _iEnable);

#define td_cmd_getosddisplay(chn, distype, x, y, enable)  td_cmd_getosddisplayex(chn, 0, distype, x, y, enable)

td_s32 td_cmd_setosddisplay(const td_s32 _iChn, td_s8* const _iDistype, td_s8* const x, td_s8* const y, td_s8* const _iEnable);
unsigned int td_cmd_get_osdcolor( int _iChn, int _iOSDType);
int td_cmd_set_osdcolor(int _iChn, int _iOSDType, unsigned int _iColor);	//������ 100210 ��cmd_execute.h������
td_u32 td_cmd_get_fontsize( td_s32 _iChn, td_s32 _iOSDType);
int td_cmd_setfontsize(td_s32 _iChn, td_s32 _iOSDType, td_u32 _iFontSize);
int td_cmd_getcoverarea(const int chn, int* left, int* top, int* right, int* bottom, const int Num);

td_s32 td_cmd_setcoverarea(const td_s32 chn,char* const left,td_s8* const top,td_s8* const right,td_s8* const bottom, const td_s32 Num);//modified by gxl 081022

//int td_cmd_getmdenable(const int chn,const char* enable);  //gxl modified 20081119
//int td_cmd_setmdenable(const int chn,char* const enable);  //gxl modified 20081119
int td_cmd_getbitrate(const int chn); //gxl modified 20081119
td_s32 td_cmd_setbitrate(const td_s32 _iChn, td_s8 * const _Bitrate);  //modified by gxl 20081119

td_s32 td_cmd_setaudiocoder(const td_s32 _iChn, td_s8* const _cCoder);
const TDevTV *td_cmd_getdevTV(const td_s32 _iDevNo);
td_s32 td_cmd_setdevTV(TGuiDevTVMsg *_pGuiDevTv);
td_s32 td_cmd_resumedevTV(const td_s32 _iDevNo);
int td_cmd_getaudiocoder(const int chn); //gxl modified 20081119
int td_cmd_getencodetype(const int chn); //gxl modified 20081119
td_s32 td_cmd_setencodetype(const td_s32 _iChn, td_s8* const _cType);  //modified by gxl 20081119
int td_cmd_getvideosize(const int chn); //gxl modified 20081119
td_s32 td_cmd_setvideosize(const td_s32 _iChn, td_s8* const videosize); //modified by gxl 20081119
td_s32  td_cmd_setprofile(const td_s32 _iChn, td_s32* const videoprofile);
 td_s32 td_cmd_getvideoprofile(const td_s32 _iChn);


td_s32 td_cmd_setaudiosample(const td_s32 _iChnStart, const td_s32 _iChnEnd, td_u32 const _s32AudioSample);
 td_s32 td_cmd_getprefermode(const td_s32 chn,const td_s8* prefermode); //����֧��

td_s32 td_cmd_setprefermode(const td_s32 chn, td_s8* const prefermode); //����֧��

 td_s32 td_cmd_getaudiochn(const td_s32 chn,const td_s8* audiochn); //?

 td_s32 td_cmd_setaudiochn(const td_s32 chn, td_s8* const audiochn); //?
//------------------------------------------------------------------------------------------------------------
int td_cmd_usbaction(const int action);
td_s32 td_cmd_getrecordschedule(const td_s32 chn,const td_s32 week,const td_s8* time);

td_s32 td_cmd_setrecordschedule(const td_s32 chn,const td_s32 week,td_s8* const time,td_s8* const mode);
int td_cmd_Store_Query(td_u32 _uiSocket, const int chn,const char* recType,const char* beginTime,const char* endTime,const char* pageSize,const char* pageNo, char* fileType, char* devType, const char *reserved , const char* trigger, char* cMsg); //modified by gxl 20081024
int td_cmd_Store_Query_Atm(td_u32 _uiSocket, const int chn,const char* recType,const char* beginTime,const char* endTime,const char* pageSize,const char* pageNo, char* fileType, char* devType, const char *reserved , const char* trigger, const char* atmQueryType, const char* pcStr, TAtmQuery* _tQuery,char* cMsg);

//------------------------------------------------------------------------------------
int td_cmd_ForceIFrame(const int chn);
//int td_cmd_setsmtpinfo(const char* ip,const char* port,const char* account,const char *password,const char* authtype,const char* emailaddr,const char* emailsubject );
//int td_cmd_setsmtpenable(const int chn,const char *smtpenable);
int td_cmd_ReduceNoise(const int chn,int enable);
int td_cmd_setosddiaphaneity(const int chn, const int dia); //gxl added 20081023
int td_cmd_setwordoverlay(int _iChn, int _iX, int _iY, int _iWordSize, td_u8* _cWord, int _blStore);
int td_cmd_setMultiwordoverlay(td_s32 _iChn, td_s32 _iLayNo, td_s32 iColor, td_s32 iDiaphaneity, td_s32 iFontSize, td_s32 _iX, td_s32 _iY, td_u8* _cWord, td_s32 _blStore);
td_s32 td_cmd_getwordoverlay(td_s32 _iCh, td_s32* _piX, td_s32* _piY, td_s8* _pcText);
td_s32 td_cmd_getMultiwordoverlay(td_s32 _iCh, td_s32 _iLayNo, TChnTextOsdCnf *_ptParam);
//int td_cmd_setpppoeconfig(char* cUserName,char* cPassword,int iAutoDial);//Leeon Tonie add for compiling warnings
int td_cmd_setvideopara(const int chn,structVideoParam* _sp,int _iNum);//Leeon Tonie add for compiling warnings
int td_cmd_change_colortogray(td_s32 _iCh, td_s32 _blColorToGray);	//Leeon Tonie added for compiling warnings.
int td_cmd_getencoder_ability(int Chn);

int td_cmd_set_previewrec(int _iChn,int _iEnc);
int td_cmd_get_previewrec(int _iChn);

td_s32 td_cmd_set_previewmode(int _iQualityCnf);
td_s32 td_cmd_get_previewmode(void);

td_s32 td_cmd_set_videoencrypt(int _socket, td_s32 _iChn, td_s8* _cPassword,td_s32 _iType);
td_s32 td_cmd_get_videoencrypt(td_s32 _iChn, td_s8 _cPassword[ENCRYPT_PWD_LENGTH+1]);
int td_cmd_get_videoencrypt_ex(int _iChn);
td_s32 td_cmd_get_videoencrypt_passwd(td_s32 _iChn,char *_pcPassword);
td_s32 td_cmd_set_recorderpolicy(td_s32 _iMode,td_u32 _iChannelListByBits,td_s32 _iDeviceListByBits);
int td_cmd_get_recorderpolicy(int* _iMode,int* _iChannelListByBits,int _iDeviceListByBits[MAX_RECORDER_NUM]);
int td_cmd_startburn(int _iCdNo,td_s32 _iIsOneKey);
int td_cmd_stopburn(int _iCdNo);
td_s32 td_cmd_stopburnEx(td_s32 _iCdNo);
td_s32 td_cmd_startburnEx(td_s32 _iCdNo,td_s32 _iIsOneKey,td_s32 _iIsOverLap);
int td_cmd_force_stopburn(int _iCdNo);
int td_cmd_video_mark(int _iChn);
td_s32 td_cmd_common_mark(td_s32 _iChn, td_s32 _iType, td_char *_pcTag);
int td_cmd_set_video_header(int _iOverlayTime,int _iX,int _iY,char* _cBuf);
int td_cmd_overlay_video_header();
int td_cmd_set_audiovolume(int _iChn,int _iVolume);
int td_cmd_get_audiovolume(int _iChn);
int td_cmd_shortcut_burn();
td_s32 td_cmd_shortcut_burn_ex(int _iAct);

int td_cmd_set_H323LocalPara(int _iLocalGroupId,int _iListenPort,char* _pcLocalNo,char* _pcPassWord,int _iIdCodeType,int _iAnwTypeForCall,int _iMainSrcChnNo,int _iSubSrcChnNo,int _iMainDecChnNo,int _iSubDecChnNo);
/*
	��������:td_cmd_set_H323LocalPara
	����: ���ñ��ز���
	����: _iLocalGroupId
		  _iListenPort
	      _pcLocalNo
	      _pcPassWord
	      _iIdCodeType
	      _iAnwTypeForCall
	      _iMainSrcChnNo
	      _iSubSrcChnNo
	      _iMainDecChnNo
	      _iSubDecChnNo	      
	����ֵ: td_successs �ɹ� td_failure ʧ��	
*/
int td_cmd_get_H323LocalPara(int* _piLocalGroupId,int* _piListenPort,char* _pcLocalNo,char* _pcPassWord,int* _piIdCodeType,int* _piAnwTypeForCall,int* _piMainSrcChnNo,int* _piSubSrcChnNo,int* _piMainDecChnNo,int* _piSubDecChnNo);
/*
	��������:td_cmd_get_H323LocalPara
	����: ��ȡ���ز���
	����: _piLocalGroupId
		  _piListenPort
	      _pcLocalNo
	      _pcPassWord
	      _piIdCodeType
	      _piAnwTypeForCall
	      _piMainSrcChnNo
	      _piSubSrcChnNo
	      _piMainDecChnNo
	      _piSubDecChnNo
	����ֵ: td_successs �ɹ� td_failure ʧ��	
*/
int td_cmd_set_H323GKPara(int _iGKGroupId,int _iGkType,char* _pcGkIP,int _iGkPort,char* _pcGkRegName,int _iEncType);
/*
	��������:td_cmd_set_H323GKPara
	����: �������ز���
	����: _iGKGroupId
		  _iGkType
	      _pcGkIP
	      _iGkPort
	      _pcGkRegName
	      _iEncType
	����ֵ: td_successs �ɹ� td_failure ʧ��	
*/
int td_cmd_get_H323GKPara(int* _piGKGroupId,int* _piGkType,char* _pcGkIP,int* _piGkPort,char* _pcGkRegName,int* _piEncType);
/*
	��������:td_cmd_get_H323GKPara
	����: ��ȡ���ز���
	����: _piGKGroupId
		  _piGkType
	      _pcGkIP
	      _piGkPort
	      _pcGkRegName
	      _piEncType
	����ֵ: td_successs �ɹ� td_failure ʧ��	
*/

/*
	��������:td_cmd_manual_record
	����: ������ֹͣ�ֶ�¼��
	����: _iChn,ͨ���� ��0��ʼ
	      _iStart: 
	       #define GUI_START_HUM_VIDEO		1			//�����ֶ�¼��
		   #define GUI_STOP_HUM_VIDEO		2			//ֹͣ�ֶ�¼��
	����ֵ: td_successs �ɹ� td_failure ʧ��
	
*/
int td_cmd_manual_record(int _iChn, int _iStart);

/*
	��������:td_cmd_can_start
	����:  _iOperaType �������ͣ�
		#define ONEKEY_BURN         0  
		#define PLAYBACK            1 
	����ֵ: td_success �ɹ�  �������Կ�ʼ
	 		���� ʧ�� ���ش�����  �������ܽ���
		 
*/
int td_cmd_can_start_ex(int _iOperaType,int _iChn);
/*
	��������:td_cmd_can_start
	����:  _iOperaType �������ͣ�
		#define ONEKEY_BURN         0  
		#define PLAYBACK            1 
	����ֵ: td_success �ɹ�  �������Կ�ʼ
	 		���� ʧ�� ���ش�����  �������ܽ���
		 
*/
int td_cmd_can_start(int _iOperaType);

/*
	��������:td_cmd_draw_video_header 
	����:����Ƭͷ������Ϣ����ƵԤ������
	����:_uVideoHeader Ƭͷ��Ϣ
	˵��:�� Inquest.c����
*/
int td_cmd_draw_video_header(td_u8 *_uVideoHeader);

/*
	��������: td_cmd_get_record_policy
	����:��ȡ��¼����
	����:eType������:��¼����(���̡�˫��ͬ�̡��ֿ�) 
		 _s32DiskNo:���̺�
	����ֵ: td_success �ɹ��� td_failure ʧ��

*/
int td_cmd_get_record_policy(td_s32*eType, td_s32 _s32DiskNo);


td_s32 td_cmd_get_ex_cbl_mode(TGuiCblModeMsgEx *_ptMsg);
/*
	��������: td_cmd_get_ex_cbl_mode/
	����:��ȡ/ ������չ��¼����(���١����̡����̡�ʱ������Ƭ)
	����:_ptMsg����չ������Ϣ
	����ֵ: td_success �ɹ��� td_failure ʧ��

*/

td_s32 td_cmd_get_dvd_driver_state(td_s32 _iCdNo);
/*
	��������:  td_cmd_get_dvd_driver_state/
	����:��ȡ����״̬
	����:_iCdNo�� ���̺�
	����ֵ: ����״̬

*/
td_s32 td_cmd_set_ex_cbl_mode(TGuiCblModeMsgEx *_ptMsg);
/*
	��������: td_cmd_set_ex_cbl_mode/
	����:��ȡ/ ������չ��¼����(���١����̡����̡�ʱ������Ƭ)
	����:_ptMsg����չ������Ϣ
	����ֵ: td_success �ɹ��� td_failure ʧ��

*/
int td_cmd_get_ResSpace(int *_piSpace);
/*
	��������: td_cmd_get_ResSpace
	����:��ȡ����ʣ��ռ�
	����:_piSpace
	����ֵ: td_success �ɹ��� td_failure ʧ��

*/
int td_cmd_set_ResSpace(int _iSpace);
/*
	��������: td_cmd_set_ResSpace
	����:���ù���ʣ��ռ�
	����:_iSpace
	����ֵ: td_success �ɹ��� td_failure ʧ��

*/
int td_cmd_direct_ConfigVideoPara(int _iCdNo);
/*
	��������: td_cmd_direct_ConfigVideoPara
	����:����ֱ�̲���(����ʱ������Ƭ����)
	����ֵ: td_success �ɹ������� ʧ��

*/

td_s32 td_cmd_config_video_para(td_s32 _iCdNo);
/*
	��������: td_cmd_config_video_para
	����:���ÿ�¼����(����ʱ������Ƭ����)
	����ֵ: td_success �ɹ������� ʧ��

*/
td_s32 td_cmd_force_eject(int _iMode,int _iCDNo);


//zhangyi modify 20120215
//int td_cmd_set_vga_mode(td_s32 _s32VgaMode);
td_s32 td_cmd_set_vga_mode(td_s32 _s32VoDev, td_s32 _s32VoDevMode);

int td_cmd_set_bnc_mode(td_s32 _iBncId, td_s32 _iBncMode);

unsigned int td_cmd_getipaddr(void); 		//������ 091117 ��ȡ32λ������ʽ��IP��ַ

td_s32 permillage(td_s32 _iType, td_s32 _iChn, td_u16 *_piPx, td_u16 *_piPy);
//td_s32 td_cmd_CreateFtpDirectory();
//int td_cmd_assistant_init(void);
//td_s32 td_cmd_IsTplayerExits();


#if (PLATFORM == HI3520 || PLATFORM == HI3520SC)
#define SLAVE_DOWN_TIMEOUT   40 
void td_heartbeat_with_slave(unsigned long para);
#endif

//��Ƶ �����ı�֪ͨ
typedef void (*tdMediaCmd_StatChgNotifyCallBack)(int _iChn, int _iCmd);

td_s32 tdMediaCmd_RegStatNotify(tdMediaCmd_StatChgNotifyCallBack _CallBack);



td_s32 td_cmd_GetAlias(TAlias* _pstAlias);
/*
 * �������ƣ�GetAlias
 * ��Ҫ��������ȡ��������
 * ��	  �룺
 * 			_pstAlias, �ǿգ���������
 * ��	 ����
 * 			ERR_SYS_SUCCESSFUL,�ɹ�
 *			ERR_SYS_WRONG_PARAM,����Ĳ���
 *			ERR_SYS_FAILED, ����ԭ����ʧ��
 * �޸���־��
 * 			2009-12-22,������,����
 */
 
td_s32 td_cmd_GetAliasVer(td_s32 _iType);
/*
 * �������ƣ�GetAliasVer
 * ��Ҫ��������ȡ�����汾
 * ��	  �룺
 * 			_iType, ALIAS_CHANNEL~ALIAS_ALARM_OUTPUT, ��������
 * ��	 ����
 * 			>= 0,�����汾
 *			������ʧ��
 * �޸���־��
 * 			2009-12-22,������,����
 */
td_s32 td_cmd_SetDevCommonAlias(td_s32 _iType, td_s32 _iNo, td_char* _pcAlias); 
td_s32 td_cmd_SetAlias(td_s32 _iType, td_s32 _iNo, td_u8* _pcAlias);
/*
 * �������ƣ�SetAlias
 * ��Ҫ���������ñ���
 * ��	  �룺
 * 			_iType, ALIAS_CHANNEL~ALIAS_ALARM_OUTPUT, ��������
 *			_iNo, ȡֵ��Χ�ɱ�������ȷ����ͨ��/�˿ں�
 *			_pcAlias, �ǿգ�����
 * ��	 ����
 * 			ERR_SYS_SUCCESSFUL,�ɹ�
 *			ERR_SYS_WRONG_PARAM,����Ĳ���
 *			ERR_SYS_FAILED, ����ԭ����ʧ��
 * �޸���־��
 * 			2009-12-22,������,����
 */



// �ָ���������
// _iFlg : 0Զ��,1����
td_s32 td_cmd_ToDefaultCnf(td_s32 _iFlg);
//���ù��̱���״̬
td_s32 td_cmd_BkBurn_SetBkState(td_s32 _iDvdNo,td_s32 _iBkState);
td_s32 td_cmd_cleanPathName(void);
/*
 * �������ƣ�td_cmd_cleanPathName
 * ��Ҫ���������·����Ϣ
 *  
 * ����ֵ  : >=0 �ɹ�   -1 ʧ��				 
 *			
 *			
 * 
 * 			
 *			
 *			
 * �޸���־��
 * 			2014-8-12,zmw,����
 */
td_s32 td_cmd_getPathName(td_char *_pcPathName);
/*
 * �������ƣ�td_cmd_getPathName
 * ��Ҫ��������ȡ�ں�·�������ڴ���Ŀ¼
 * ���:    _pcPathName	��·����Ϣ��
 *
 * ����ֵ  : >=0 �ɹ�   -1 ʧ��				 
 *			
 *			
 * 
 * 			
 *			
 *			
 * �޸���־��
 * 			2014-8-12,zmw,����
 */
td_s32 td_cmd_setPathName(const td_char *_pcPathName);
/*
 * �������ƣ�td_cmd_setPathName
 * ��Ҫ������UK֪ͨ�ں�·��
 * ��	  �룺  _pcPathName	��·����Ϣ��
 *
 * ����ֵ  :  	>=0 �ɹ�   -1 ʧ��				 
 *			
 *			
 * 
 * 			
 *			
 *			
 * �޸���־��
 * 			2014-8-12,zmw,����
 */
 td_s32 td_cmd_setBackupIndex(td_s32 _iBackupIndex,td_s32 _iBackupCnt);
 /*
 * �������ƣ�td_cmd_setBackupIndex
 * ��Ҫ������UK֪ͨ�ں˵�ǰ���ݵڼ���ʱ��ε�¼��
 * ��	  �룺  _iBackupIndex	��ʱ��������š�
 				_iBackupCnt     : ʱ��θ���
 				
 *
 * ����ֵ  :  	>=0 �ɹ�   -1 ʧ��				 
 *			
 *			
 * 
 * 			
 *			
 *			
 * �޸���־��
 * 			2014-8-12,zmw,����
 */

 td_s32 td_cmd_getBackupIndex(td_s32* _iBackupIndex,td_s32* _iBackupCnt);
  /*
 * �������ƣ�td_cmd_getBackupIndex
 * ��Ҫ��������ȡ��ǰ���ݵڼ���ʱ��ε�¼��
 * ��	  ����  _iBackupIndex	��ʱ��������š�
 *				_iBackupCnt     :���̱���ʱ��θ�����
 * ����ֵ  :  	>=0 �ɹ�   -1 ʧ��				 
 *			
 *			
 * 
 * 			
 *			
 *			
 * �޸���־��
 * 			2014-8-12,zmw,����
 */
td_s32 td_cmd_RtBurn_DvdEject(td_s32 _iOption,td_s32 _iDvdNo,td_s32 _iForce);
/*
  * ��������:td_cmd_RtBurn_DvdEject
  * ��Ҫ����:����/�ջع���
  * ��	  ��:
  *			 _iDvdNo, ��¼�����
  *			 _iOption,��1 �ջأ�0 ������
  *          _iForce, �Ƿ�ǿ�Ƶ���
  *  ��	  ���E   ERR_REC_SUCCESSFUL���ɹ�
  *				 ERR_REC_FAILED ,    ʧ��
 */
td_s32 td_cmd_Burn_CheckDiskCanUsed(td_s32 _iDvdNo,td_s32 _iUsedLimit);
/*
 * �������ƣ�td_cmd_Burn_CheckDiskCanUsed
 * ��Ҫ�������жϹ��̵Ŀ��ÿռ��Ƿ�С���޶�ֵ
 * ��	  �룺   _iDvdNo   ���̺�
 * 				  _iUsedLimit  �����޶�ֵ
 *			
 *			
 * ��	 ���E    ERR_REC_SUCCESSFUL���ɹ�
 				 ERR_REC_HUGE_SIZE_TO_BURN  ʧ��
 * 			
 *			
 *			
 * �޸���־��
 * 			2014-3-12,zmw,����
 */
 td_s32 td_cmd_BigFile_CheckDiskCanUsed(td_s32 _iDvdNo);
/*
 * �������ƣ�td_cmd_BigFile_CheckDiskCanUsed
 * ��Ҫ��������¼udf��ʽ�Ĺ���,�ж��Ƿ��ǿհ׹���
 * ��	  �룺   _iDvdNo   ���̺�
 * 				 
 *			
 *			
 * ��	 ���E    ERR_REC_SUCCESSFUL���ɹ�
 				 ERR_REC_HUGE_SIZE_TO_BURN  ʧ��
 * 			
 *			
 *			
 * �޸���־��
 * 			2014-3-12,zmw,����
 */
 td_s32 td_cmd_BkBurn_PrepareToRecord(td_s32 _iCdNo,td_s32 _iType);
 /*
 * �������ƣ�td_cmd_BkBurn_PrepareToRecord
 * ��Ҫ��������鵱ǰ�Ĵ����Ƿ���ã������޷�����¼���ļ�
 * ��	  �룺   _iDvdNo   ���̺�
 * 				
 *			
 *			
 * ��	 ���E    ERR_REC_SUCCESSFUL���ɹ�
 				 ERR_REC_FAILED         ʧ��
 * 			
 *			
 *			
 * �޸���־��
 * 			2014-3-12,zmw,����
 */

td_s32 td_cmd_BkBurn_AddFileToConvertList(td_u8* _pcFileName);
/*
 * �������ƣ�td_cmd_BkBurn_AddFileToConvertList
 * ��Ҫ���������ת���ļ��б�
 * ��	  �룺    _pcFileName    ¼���ļ���
 *			
 *			
 * ��	 ���E   td_success���ɹ�
 				  td_failure         ʧ��
 * 			
 *			
 *			
 * �޸���־��
 * 			2014-11-27,zmw,����
 */
td_s32 td_cmd_BkBurn_AddFileToBackUpList(td_u8* _pcFileName,td_s32 _iCdNum);
/*
 * �������ƣ�td_cmd_BkBurn_AddFileToBackUpList
 * ��Ҫ��������ӱ����б�
 * ��	  �룺   _iDvdNo   ���̺�
 * 				 _pcFileName    ¼���ļ���
 *			
 *			
 * ��	 ���E   td_success���ɹ�
 				  td_failure         ʧ��
 * 			
 *			
 *			
 * �޸���־��
 * 			2014-3-12,zmw,����
 */
td_s32 td_cmd_BkBurn_DoRecord(td_s32 _iCdNo);
/*
 * �������ƣ�td_cmd_BkBurn_DoRecord
 * ��Ҫ������ִ�б���
 * ��	  �룺   _iDvdNo   ���̺�
 * 				
 *			
 *			
 * ��	 ���E   td_success���ɹ�
 				  td_failure         ʧ��
 * 			
 *			
 *			
 * �޸���־��
 * 			2014-3-12,zmw,����
 */
td_s32 td_cmd_BkBurn_GetBurnProgress(td_s32* _piStat,td_s32 _iCdNum);
/*
 * �������ƣ�td_cmd_BkBurn_GetBurnProgress
 * ��Ҫ������ ��ȡ������״̬
 * ��	  �룺   _iDvdNo   ���̺�
 * 				  _piStat	   ����״ָ̬��
 *			
 *			
 * ��	 ���E    ���ݽ���
 				
 * 			
 *			
 *			
 * �޸���־��
 * 			2014-3-12,zmw,����
 */
td_s32 td_cmd_BkBurn_ForceStopBackUp(td_s32 _iCdNum);
/*
 * �������ƣ�td_cmd_BkBurn_ForceStopBackUp
 * ��Ҫ������ ǿ��ֹͣ����
 * ��	  �룺   _iDvdNo   ���̺�
 * 				
 *			
 *			
 * ��	 ���E    td_success���ɹ�
   			        td_failure         ʧ��
 				
 * 			
 *			
 *			
 * �޸���־��
 * 			2014-3-12,zmw,����
 */


td_s32 td_cmd_StartSearchIpc(td_s32 _iSearchMod);//�������ѯ����ͨ���豸�������ѯģʽ
td_s32 td_cmd_GetIpcSearchMsg(TIpcDevItem *_ptItem);//����UI �����豸��Ϣ��һ�δ���һ���豸����Ϣ������ֵΪ1 -���豸0 -���豸 -1 -��������
td_s32 td_cmd_EnableVideoParamTimer(td_s32 _blEnable);

// ����ֵ:0����ͨ��,1����ͨ��,2����ͨ��
td_s32 td_cmd_get_ChnType(td_s32 _iChn, td_s32 *_iType);//��ȡͨ������


td_s32 td_cmd_get_LocalChnAttr(td_s32 _iChn, td_s32 *_iBncInput); //��ȡ����ͨ������
td_s32 td_cmd_set_LocalChnAttr(td_s32 _iChn, td_s32 _iBncInput);
td_s32 td_cmd_get_VcChnAttr(td_s32 _iChn, td_s32 *_iVoDev); //��ȡ����ͨ������
td_s32 td_cmd_set_VcChnAttr(td_s32 _iChn, td_s32 _iVodev);

td_s32 td_cmd_set_ParsePara(strParsePara *_ptParam);

// ��ȡͨ���ɱ༭����,����-1��ʧ��
// �ɸ������Ͱ�λ��ʾ��0,1,2λ�ֱ��Ӧ����ģ��VC
// 0��ʾ���ɸ��ģ�1��ʾ�ɸ��ĳɴ�����
td_s32 td_cmd_get_ChnTypeEditAbleFlg(td_s32 _iChn);
// ����ͨ������,0,1,2�ֱ��Ӧ����ģ��VC
td_s32 td_cmd_set_ChnType(td_s32 _iChn, td_s32 _iChnType, td_s32 _iParam);
//���緽ʽʵ���л�ͨ������shihc add 20130327
td_s32 td_cmd_set_ChnType_Net(td_s32 _iChn, td_s32 _iChnNetType);


/*
_iChn : ͨ���� 
_iEnable : ʹ�� 0-���ø�����ͨ����1-���ø�����ͨ����Ĭ��Ϊ����
_iConnectMode : 0-IP��1-������2-����ģʽ��Ĭ��ΪIP
_strIp : _iConnectMode=0ʱΪIP��ַ��_iConnectMode=1ʱΪ������_iConnectMode=2ʱΪ�豸ID��Ĭ��Ϊ�գ�����32���ַ�
_strProxy : ����IP , iConnectMode=2ʱ�����ֶ���Ч��Ĭ��Ϊ�գ�����32���ַ�
_iChnNo : ǰ���豸ͨ����, ȡֵ��Χ��ǰ���豸����������Ĭ��Ϊ0
_uiPort : ȡֵ81��65535��Ĭ��Ϊ3000
_iStreamType : 0-��������1-��������Ĭ��Ϊ������
_iNetMode : 1-TCP��2-UDP��3-�鲥���ݶ�ΪTCP,���ɸ���
_strName : ��¼ǰ���豸���û���������Ϊ�գ�����16���ַ�
_strPsw  : ��¼ǰ���豸�����룬����Ϊ�գ�����16���ַ�
_strDecrypt : ǰ���豸��Ƶ���ܵ����룬Ϊ�����ʾ�����ܣ�����16���ַ�
*/
td_s32 td_cmd_get_IpcChnAttr(td_s32 _iChn, td_s32 *_iEnable, td_s32 *_iConnectMode, char *_strIp,
		char *_strProxy, td_s32 *_iChnNo, td_u32 *_uiPort, td_s32 *_iStreamType, td_s32 *_iNetMode, char *_strName,
		char *_strPsw, char *_strDecrypt);

td_s32 td_cmd_set_IpcChnAttr(td_s32 _iChn, td_s32 _iEnable, td_s32 _iConnectMode, const char *_strIp,
		const char *_strProxy, td_s32 _iChnNo, td_u32 _uiPort, td_s32 _iStreamType, td_s32 _iNetMode, const char *_strName,
		const char *_strPsw, const char *_strDecrypt, td_s32 _iServerType, const char *_strRtspUrl);


td_s32 td_cmd_setlogodisplay(td_s32 _iChn, td_s32 _iXp, td_s32 _iYp, td_s32 _iDsp);

// �������ģ��(_strAppName������".bin"��ΪNULLʱ��ʽ�������κ����)
td_s32 td_cmd_set_appname(char *_strAppName);
// ��ȡ��ǰ��������
td_s32 td_cmd_get_appname(char *_strAppName);
// ��ȡϵͳ��ǰ���õ�����б�,����ֵΪ����
td_s32 td_cmd_get_applist(char _strAppList[][64], int _iMaxCnt);

td_s32 td_cmd_getappserverlist(char _strAppSrvList[][64]);
td_s32 td_cmd_setappserverpara(char *_para);
td_s32 td_cmd_getappnettype(char *_strAppType);

td_s32 td_cmd_GetRtmpInfo(td_s32 _iNo, TGuiRtmpInfoItem *_ptInfoItem);
td_s32 td_cmd_SetRtmpInfo(const TGuiRtmpInfoItem *_ptInfoItem);

td_s32 td_cmd_GetRtspInfo(td_s32 _iNo, TRtspInfoItem *_ptInfoItem);
td_s32 td_cmd_SetRtspInfo(TRtspInfoItem *_ptInfoItem);

td_s32 td_cmd_set_channle_venc_stat(int _iChn, int _piStat);
td_s32 td_cmd_get_channle_venc_stat(int _iChn);
int td_cmd_set_channle_stat(int _iChn, int _istat);
void TdGetIpcChnPara(TDigChnPamaMsg *_tChnMsg, int _iChn);
//add by zhuangzhibing 20120129 
int td_cmd_StartOverLapBurn();
//add end
td_s32 td_cmd_can_set_videoencrypt();//�ж��Ƿ���Խ��м�������
void Public__EncryptString(const char* _pstrSrc,char * _pstrDst);//���̼����㷨


// ��ȡU �̷�����Ϣ�б�20120220 ����
td_s32 td_cmd_GetUsbPartMsg(td_s32 _iDiskId, td_s32 _iPartId, td_s32* _piWriteProtect, 
	td_s8* _pcDiskName, td_u64* _pullSize, td_u64* _pullUsed, td_u64* _pullFree);

//add by nsg 20120207  ���ܷ������ú���
td_s32 td_cmd_get_VcaChnPolicy(td_s32 _iChn);
td_s32 td_cmd_get_VcaCfgChn(const td_s32 _iChn, td_s32 *_piEnable);
td_s32 td_cmd_set_VcaCfgChn(const td_s32 _iChn, const td_s32  _iEnable);
//---------------------------------------------------------------------------------------------------------------------------------------
//td_s32 td_cmd_get_VcaCfgVideo(const td_s32 _iChn, td_s32 *_piVideoSize);
//td_s32 td_cmd_set_VcaCfgVideo(const td_s32 _iChn, const td_s32  _iVideoSize);
//---------------------------------------------------------------------------------------------------------------------------------------
td_s32 td_cmd_get_VcaCfgAdv(const td_s32 _iChn,  TVcaAdvanceParam  *_pstAdvancedParam);
td_s32 td_cmd_set_VcaCfgAdv(const td_s32 _iChn, const TVcaAdvanceParam const *_pstAdvancedParam);
//---------------------------------------------------------------------------------------------------------------------------------------
td_s32 td_cmd_get_VcaCfgFde(const td_s32 _iChn, vca_TFdepthParam_ex *_pstFdepthParam);
td_s32 td_cmd_set_VcaCfgFde(const td_s32 _iChn, const vca_TFdepthParam_ex const *_pstFdepthParam);
//---------------------------------------------------------------------------------------------------------------------------------------
td_s32 td_cmd_get_VcaCfgTarget(const td_s32 _iChn, 		 TVcaConfig 	   *_pstConfig);
td_s32 td_cmd_set_VcaCfgTarget(const td_s32 _iChn, const TVcaConfig const *_pstConfig);
//---------------------------------------------------------------------------------------------------------------------------------------
td_s32 td_cmd_get_VcaRuleSet(const td_s32 _iChn, const td_s32 _iRuleId, char* 		 _pcRuleName, 		td_s32* _piValid);
td_s32 td_cmd_set_VcaRuleSet(const td_s32 _iChn, const td_s32 _iRuleId,  char*  _pcRuleName, const td_s32  _iValid);
//---------------------------------------------------------------------------------------------------------------------------------------
td_s32 td_cmd_get_VcaRuleEvent0(const td_s32 _iChn, const td_s32 _iRuleId,		 TVcaParamTripwire		*_pstVcaTripParam, const td_s32 _iType);
td_s32 td_cmd_set_VcaRuleEvent0(const td_s32 _iChn,	const td_s32 _iRuleId, const TVcaParamTripwire const *_pstVcaTripParam, const td_s32 _iType);
//---------------------------------------------------------------------------------------------------------------------------------------
td_s32 td_cmd_get_VcaRuleEvent2(const td_s32 _iChn, const td_s32 _iRuleId,		 TVcaParamPerimeter 		 *_pstVcaPeriParam, const td_s32 _iType);
td_s32 td_cmd_set_VcaRuleEvent2(const td_s32 _iChn, const td_s32 _iRuleId, const TVcaParamPerimeter const *_pstVcaPeriParam, const td_s32 _iType);
//---------------------------------------------------------------------------------------------------------------------------------------
td_s32 td_cmd_get_VcaRuleEvent7(const td_s32 _iChn,	const td_s32 _iRuleId, 		 TVcaParamOSC  		*_pstVcaOscParam, const td_s32 _iType);
td_s32 td_cmd_set_VcaRuleEvent7(const td_s32 _iChn,	const td_s32 _iRuleId, const TVcaParamOSC const 	*_pstVcaOscParam, const td_s32 _iType);
//---------------------------------------------------------------------------------------------------------------------------------------
td_s32 td_cmd_get_VcaRuleEvent9(const td_s32 _iChn, const td_s32 _iRuleId, 		 TVcaFaceParam_ex  	 *_pstVcaFaceParam, const td_s32 _iType);
td_s32 td_cmd_set_VcaRuleEvent9(const td_s32 _iChn, const td_s32 _iRuleId, const TVcaFaceParam_ex const *_pstVcaFaceParam, const td_s32 _iType);
//---------------------------------------------------------------------------------------------------------------------------------------
td_s32 td_cmd_get_VcaRuleEvent10(const td_s32 _iChn, const td_s32 _iRuleId,		 TVcaParamAVD		 *_pstVcaDiagParam, const td_s32 _iType);
td_s32 td_cmd_set_VcaRuleEvent10(const td_s32 _iChn, const td_s32 _iRuleId,const TVcaParamAVD const *_pstVcaDiagParam, const td_s32 _iType);
//---------------------------------------------------------------------------------------------------------------------------------------
//caizhaoxu 20130117
td_s32 td_cmd_get_VcaRuleEvent11(const td_s32 _iChn, const td_s32 _iRuleId,TVcaParamCAP	*_pstVcaCapParam,const td_s32 _iType);
td_s32 td_cmd_set_VcaRuleEvent11(const td_s32 _iChn, const td_s32 _iRuleId,const TVcaParamCAP const *_pstVcaCapParam,const td_s32 _iType);
//---------------------------------------------------------------------------------------------------------------------------------------
//shihc add 20130323
td_s32 td_cmd_get_VcaRuleEvent12(const td_s32 _iChn, const td_s32 _iRuleId,TVcaParamCPC	*_pstVcaCpcParam,const td_s32 _iType);
td_s32 td_cmd_set_VcaRuleEvent12(const td_s32 _iChn, const td_s32 _iRuleId,const TVcaParamCPC const *_pstVcaCpcParam,const td_s32 _iType);
//---------------------------------------------------------------------------------------------------------------------------------------//caizhaoxu 20130117
td_s32 td_cmd_get_VcaRuleEvent13(const td_s32 _iChn, const td_s32 _iRuleId,TVcaParamCDD	*_pstVcaCddParam,const td_s32 _iType);
td_s32 td_cmd_set_VcaRuleEvent13(const td_s32 _iChn, const td_s32 _iRuleId,const TVcaParamCDD const *_pstVcaCddParam,const td_s32 _iType);
//---------------------------------------------------------------------------------------------------------------------------------------
td_s32 td_cmd_set_VcaRuleEvent(td_s32 _iChn,td_s32 _iRuleId,void* _pstVcaEventParam,td_s32 _iVcaType);
td_s32 td_cmd_get_VcaRuleEvent(td_s32 _iChn,td_s32 _iRuleId,void* _pstVcaEventParam,td_s32 _iVcaType);




td_s32 td_cmd_get_VcaRuleEnableType(const td_s32 _iChn,const td_s32 _iRuleId,TVcaRuleEnableStat* _pEnableStat);

td_s32 td_cmd_setVcaReboot(td_s32 _iChn);
td_s32 td_cmd_setVcaAlarmStatClr(const td_s32 _iChn, const td_s32 _iRuleId, const TVcaEventType _eEventType);


//end


//add by nsg 20120131 
//��ȡ�ϳ�ͨ��������������
 td_s32 td_cmd_get_mixaudio(int *_piEnable, int *_piMixAudioChn, char *_pcAudioChnParam);
//���úϳ�ͨ����������
td_s32 td_cmd_set_mixaudio(int _iAudioChnCnt, int _iMixAudiochn, char *_pcAudioChnParam);
//end add

//lc 121012;����/ ��ȡ���������ֵ;
td_s32 td_cmd_get_mute_bounds(td_s32 _iChn);
td_s32 td_cmd_set_mute_bounds(td_s32 _iChn,td_s32 _iBounds);
//

//add by nsg 120905
//��ȡATM��������
int td_cmd_get_CnfAtm(TAtmPara *_pstAtmPara);
//����ATM��������
int td_cmd_set_CnfAtm(TAtmPara _stAtmPara);
//����ͼ��ץ�Ĳ���
int td_cmd_set_SnapShotPara(td_u8 _u8Channel, TSnapShot _stSnapShotPara);
//��ȡͼ��ץ�Ĳ���
int td_cmd_get_SnapShotPara(td_u8 _u8Channel, TSnapShot *_pstSnapShotPara);
//���ÿ��ŵ��Ӳ���
int td_cmd_set_AtmCardOverlay(int iOverlayChn, STR_WordOverlay _stWordOverlay);
//��ȡ���ŵ��Ӳ���
int td_cmd_get_AtmCardOverlay(int iOverlayChn, STR_WordOverlay *_pstWordOverlay);
//����ͼƬץ����������
int td_cmd_set_SnapShotLinkPara(td_u8 _u8Channel, int _iMode);
//��ȡͼƬ����ץ�Ĳ���
int td_cmd_get_SnapShotLinkPara(td_u8 _u8Channel, int *_piMode );


//end add
//td_s32 td_cmd_CreateOtherFileFtpDirectory();
td_s32 td_cmd_CreateFtpDirectory();

td_s32 td_cmd_CreateBaseFtpDirectory();
td_s32 td_cmd_CreateFtpDirectoryAndLink();


//add by gyn 20120904
//��ȡ����ϳ�Ч��
//td_s32 td_cmd_get_multipic(td_s32* _piPicCnt, char* _pcChnParam);
//���û���ϳ�Ч��
td_s32 td_cmd_set_multipic(int _iPicCnt, char* _cChannelParam,int _iVoDevId, char *_cPara);

//��ȡ�ϳɻ���Ч��
td_s32 td_cmd_get_multipic(td_s32* _piPicCnt, char* _pcChnParam, int _iVoDevId);

//add end
//��ȡ�Զ��廭������
td_s32 td_cmd_get_picPoint(td_s32 _iVoDevId,TRect *_ptRects);



//�����Զ��廭��ָʽ 
td_s32 td_cmd_set_freevo(td_s32 _iVodev, td_s32 _iPicCnt, TRect _ptRect[],td_s32 *_piChnList);
//����Vc��VGA/HDMI1��HDMI2���ͬԴ
td_s32 td_cmd_set_vcaffinal(td_s32 _iVcId,td_s32 _iVodev);
td_s32 td_cmd_get_vcaffinal(td_s32 _iVcId);


td_s32 td_cmd_set_inquest_header(TGuiGetVideoHeaderOsdMsgRsp *_pstVideoHeader);

td_s32 td_cmd_get_inquest_header(TGuiGetVideoHeaderOsdMsgRsp *_pstVideoHeader);

td_s32 tdCmdGetFileTime(char *_strName, td_s32 *_iBeginTm, td_s32 *_iEndTm);

//����������Ƭͷ��Ϣ
td_s32 td_cmd_inquest_set_video_header(td_s32 _iOverlayTime,
td_s32 _iX,td_s32 _iY,char* _cBuf);
td_s32 td_cmd_setwordoverlayforatm(td_s32 _iChn, td_s32 _iPos,td_u8* _cText);

//-
int td_cmd_direct_RecoveryConfigIni();
//��Ӳ�̶ϵ�ֱ���޸���ԭconfig.ini
int td_cmd_direct_RecoveryVideoPara();
//��Ӳ�̶ϵ�ֱ���޸���ԭĬ�ϲ�������--
int td_cmd_direct_ConfigVideoPara_to_Default();
//��Ӳ��ֱ�̻�ԭĬ�ϲ�������-----------------------------------------------------------------------------------
td_s32 td_cmd_config_video_para_to_default(td_s32 _iCdNo);

td_s32 td_cmd_set_VcTime(td_s32 _isleepTime);
td_s32 td_cmd_get_VcTime();

//Sherry add 20130111 ��ȡ��Ƶ������
td_s32 td_cmd_getaudioSampleRate(const td_s32 _iChn);

td_s32 td_cmd_StartAppEncode(int _iChannelNo);
//shihc  add 20130312 ��������ͨ������״̬��ȡ
td_s32 td_cmd_GetIpChanConnect(td_s32 _iChannelNo);
td_s32 td_cmd_SavelogoPic(td_u8* _u8Buf,td_s32 _iLength);
//shihc  add 20130318 ����ʵʱ��ȡ��������
td_s32 td_cmd_GetNetWorkState(td_s32 _ilannum,td_char *_pcState,td_s32 _itimers);
void td_cmd_NetWorkState_Timers(unsigned long _param);
//shihc add 20130320 ����ģ��ʹ�ܵ�ͨ�ú���
td_s32 td_cmd_common_setserviceable(td_s32 _iServiceID,td_s32 _iChannelno,td_s32 _iable);
td_s32 td_cmd_common_getserviceable(td_s32 _iServiceID,td_s32 _iChannelno,td_s32 *_pGetAble);

td_s32 td_cmd_snmpable(td_s32 _isetget,td_s32 _iable, td_s32 *_pGetAble);


//20130314 SUN Wei add for 7.6 smtp
td_s32 td_cmd_get_smtppara(TSmtpPara *_pstSmtpPara);
td_s32 td_cmd_set_smtppara(TSmtpPara _stSmtpPara);
//20130314 SUN Wei add for 7.6 smtp end

td_s32 td_cmd_setsensorspin (const td_s32 _iChn, TSensorSpin _eType);
td_s32 td_cmd_getsensorspin (td_s32 _iChn);




/************************************�ƾ�����***************************/

/*
 * �������ƣ�td_cmd_ManualPtzControl
 * ��Ҫ����: �ֶ�����ptz
 * ��	  �룺
 * 			_pstData, UI���͹�����ptz����
 *			_iChannelNo,ͨ����
 *			_iCmdCode,UI���͹����Ŀ�����ֵ
 * ��	  ����
 * 			ERR_PTZ_WRONG_PARAM,����Ĳ���
 *			ERR_PTZ_SUCCESSFUL,�����ɹ�
 *			ERR_PTZ_FAILED,����ʧ��
 *			
 * �޸���־��
 * 			2013-02-20 dce move from ukcmd.c
 */
td_s32 td_cmd_ManualPtzControl(td_s32 _iChannelNo, td_s32 _iCmdCode, PTZ_DATA *_pstData);

/*
 * �������ƣ�td_cmd_GuiPtzRemote
 * ��Ҫ����: ��������Զ��(���������)��PTZ����
 * ��	  �룺
 *			_iChannelNo,ͨ����
 *			_iCmdCode,������ֵ
 * ��	  ����
 * 			ERR_PTZ_WRONG_PARAM,����Ĳ���
 *			ERR_PTZ_SUCCESSFUL,�����ɹ�
 *			ERR_PTZ_FAILED,����ʧ��
 *			
 * �޸���־��
 * 			2013-02-20 dce move from ukcmd.c
 */
td_s32 td_cmd_GuiPtzRemote(td_s32 _iChannelNo, td_s32 _iCmdCode);

/*
 * �������ƣ�td_cmd_GuiPtzTrackStart
 * ��Ҫ����: ��ʼ¼�ƹ켣
 * ��	  �룺
 *			_iChannelNo,ͨ����
 * ��	  ����
 * 			ERR_PTZ_WRONG_PARAM,����Ĳ���
 *			
 * �޸���־��
 * 			2013-02-20 dce move from ukcmd.c
 */
td_s32 td_cmd_GuiPtzTrackStart(td_s32 _iChannelNo);

/*
 * �������ƣ�td_cmd_GuiPtzTrackEnd
 * ��Ҫ����: ֹͣ¼�ƹ켣
 * ��	  �룺
 *			_iChannelNo,ͨ����
 * ��	  ����
 * 			ERR_PTZ_WRONG_PARAM,����Ĳ���
 *			
 * �޸���־��
 * 			2013-02-20 dce move from ukcmd.c
 */
td_s32 td_cmd_GuiPtzTrackEnd(td_s32 _iChannelNo);

/*
 * �������ƣ�td_cmd_GuiPtzTrackPlayStart
 * ��Ҫ����: ��ʾ�켣
 * ��	  �룺
 *			_iChannelNo,ͨ����
 * ��	  ����
 * 			ERR_PTZ_WRONG_PARAM,����Ĳ���
 *			
 * �޸���־��
 * 			2013-02-20 dce move from ukcmd.c
 */
td_s32 td_cmd_PtzTrackPlayStart(td_s32 _iChannelNo);

/*
 * �������ƣ�td_cmd_PtzTrackPlayEnd
 * ��Ҫ����: ֹͣ���Ź켣
 * ��	  �룺
 *			_iChannelNo,ͨ����
 * ��	  ����
 * 			ERR_PTZ_WRONG_PARAM,����Ĳ���
 *			
 * �޸���־��
 * 			2013-02-20 dce move from ukcmd.c
 */
td_s32 td_cmd_PtzTrackPlayEnd(td_s32 _iChannelNo);

/*
 * �������ƣ�td_cmd_GetPtzCruise
 * ��Ҫ����: ��ȡѲ���켣����
 * ��	  �룺
 *			_iChannelNo,ͨ����
 *			_iCruiseNo,Ѳ���켣��
 *			_pstCruise,Ѳ���켣����
 * ��	  ����
 * 			ERR_PTZ_WRONG_PARAM,����Ĳ���
 *			ERR_PTZ_SUCCESSFUL,�����ɹ�
 *			
 * �޸���־��
 * 			2013-02-20 dce move from ukcmd.c
 */
td_s32 td_cmd_GuiGetPtzCruise(td_s32 _iChannelNo, td_s32 _iCruiseNo, TCruise *_pstCruise);

/*
 * �������ƣ�td_cmd_GuiSetPtzCruise
 * ��Ҫ����: ����Ѳ���켣����
 * ��	  �룺
 *			_iChannelNo,ͨ����
 *			_iCruiseNo,Ѳ���켣��
 *			_pstCruise,Ѳ���켣����
 * ��	  ����
 * 			ERR_PTZ_WRONG_PARAM,����Ĳ���
 *			ERR_PTZ_SUCCESSFUL,�����ɹ�
 *			ERR_PTZ_FAILED,����ʧ��
 * �޸���־��
 * 			2013-02-20 dce move from ukcmd.c
 */
td_s32 td_cmd_GuiSetPtzCruise(td_s32 _iChannelNo, td_s32 _iCruiseNo, TCruise *_pstCruise);

/*
 * �������ƣ�td_cmd_GuiSetPtzCruise
 * ��Ҫ����: ����Ѳ���켣����
 * ��	  �룺
 *			_iChannelNo,ͨ����
 *			_piParam,3D��λ�������������飬����Ϊ���λ��x/���λ��y/��Ļ��/��Ļ��/
 *			�����(����������������, 0���)/�����(����������������, 0���)
 * ��	  ����
 * 			ERR_PTZ_WRONG_PARAM,����Ĳ���
 * �޸���־��
 * 			2013-02-20 dce move from ukcmd.c
 */
td_s32 td_cmd_Gui3DPosition(td_s32 _iChannelNo, td_s32 *_piParam);

/*
 * �������ƣ�td_cmd_GuiGetPtzConfig
 * ��Ҫ����: ��ȡptz����
 * ��	  �룺
 *			_iChannelNo,ͨ����
 *			_pstPtzCnf,PTZ������Ϣ
 *			_pstCom,��������
 * ��	  ����
 * 			ERR_PTZ_WRONG_PARAM,����Ĳ���
 *			ERR_PTZ_FAILED,����ʧ��
 *			ERR_PTZ_SUCCESSFUL,�����ɹ�
 * �޸���־��
 * 			2013-02-20 dce move from ukcmd.c
 */
td_s32 td_cmd_GuiGetPtzConfig(td_s32 _iChannelNo, TGuiPtzDecodeCnf *_pstPtzCnf, TCom *_pstCom);

/*
 * �������ƣ�td_cmd_SetChannelPTZ
 * ��Ҫ����: ����ĳͨ����PTZ����
 * ��	  �룺
 * 			_iChannelNo, ͨ����
 *			_iComNo, ���ø�ͨ������PTZ���ƵĶ˿�,0~MAX_SERIAL_NUM
 *			_cProtocolName,��ͨ������PTZ���Ƶ�Э����������,�ǿ�
 *			_iAddress,��ͨ�������豸��PTZ��ַ
 * ��	  ����
 * 			ERR_PTZ_WRONG_PARAM,����Ĳ���
 * �޸���־��
 * 			2013-02-20 dce move from ukcmd.c
 */
td_s32 td_cmd_SetChannelPTZ(td_s32 _iChannelNo, td_s32 _iComNo, td_u8 *_pcProtocolName, td_s32 _iAddress);

/*
 * �������ƣ�td_cmd_SetChannelComAttr
 * ��Ҫ����: ����ͨ��PTZ�Ĵ�������
 * ��	  �룺
 * 			_iChannelNo, ͨ����
 *			_pstCom, �������ԣ��ǿ�
 *			_blEnable, �Ƿ��Զ��崮�����ԣ�0��1
 * ��	  ����
 *			ERR_PTZ_WRONG_PARAM, ����Ĳ���
 * �޸���־��
 * 			2013-02-20 dce move from ukcmd.c
 */
td_s32 td_cmd_SetChannelComAttr(td_s32 _iChannelNo, TCom* _pstCom, td_s32 _blEnable);

/*
 * �������ƣ�td_cmd_DealProtocol
 * ��Ҫ����: ����ptzЭ��(��ӻ�ɾ��)
 * ��	  �룺
 * 			_cProtocol, Э�����������ΪMAX_PROTOCOL_NAME_LEN
 *			_iDealCode, Э�鴦���룬ADD_PTZ_PROTOCOL(���)��DEL_PTZ_PROTOCOL(ɾ��)
 * ��	  ����
 *			ERR_PTZ_WRONG_PARAM, ����Ĳ���
 * �޸���־��
 * 			2013-02-20 dce creat
 */
td_s32 td_cmd_DealProtocol(td_u8 _cProtocol[MAX_PROTOCOL_NAME_LEN], td_s32 _iDealCode);

/*
 * �������ƣ�td_cmd_GetProtocol
 * ��Ҫ����: ��ȡptzЭ��(����ӻ������)
 * ��	  �룺
 * 			_cList, Э���б�
 *			_iProtocolAttr, Э�����ͣ�PTZ_PROTOCOL_USE(�����)��PTZ_PROTOCOL_DEL(�����)
 * ��	  ����
 *			ERR_PTZ_WRONG_PARAM, ����Ĳ���
 * �޸���־��
 * 			2013-02-20 dce creat
 */
td_s32 td_cmd_GetProtocol(td_u8 _cList[MAX_PROTOCOL_NUM][MAX_PROTOCOL_NAME_LEN], td_s32 _iProtocolAttr);

/*
 * �������ƣ�td_cmd_ControlCruise
 * ��Ҫ����: ��ʼ���������Ѳ���켣
 * ��	  �룺
 * 			_iChannelNo, ͨ����
 *			_iCruiseNo, Ѳ���켣��
 *			_iControlCode,�����룬PTZ_CRUISE_START(��ʼѲ���켣)��PTZ_CRUISE_STOP(����Ѳ���켣)
 * ��	  ����
 *			ERR_PTZ_WRONG_PARAM, ����Ĳ���
 * �޸���־��
 * 			2013-02-20 dce creat
 */
td_s32 td_cmd_ControlCruise(td_s32 _iChannelNo, td_s32 _iCruiseNo, td_s32 _iControlCode);


/*
 * �������ƣ�td_cmd_SetComBaudRate
 * ��Ҫ����: ���ô��ڲ�����
 * ��	  �룺
 * 			_iComNo, ���ں�
 *			_iBaudRate, ����Ĳ�����ֵ
 * ��	  ����
 *			ERR_COM_WRONG_PARAM, ����Ĳ���
 * �޸���־��
 * 			2013-02-21 dce creat
 */
td_s32 td_cmd_SetComBaudRate(td_s32 _iComNo, td_s32 _iBaudRate);

/*
 * �������ƣ�td_cmd_GetComBaudRate
 * ��Ҫ����: ��ȡ���ڲ�����
 * ��	  �룺
 * 			_iComNo, ���ں�
 *			_piBaudRate, ��ȡ��õĲ�����ֵ
 * ��	  ����
 *			ERR_COM_WRONG_PARAM, ����Ĳ���
 * �޸���־��
 * 			2013-02-21 dce creat
 */
td_s32 td_cmd_GetComBaudRate(td_s32 _iComNo, td_s32 *_piBaudRate);

/*
 * �������ƣ�td_cmd_SetComBits
 * ��Ҫ����: ���ô�������λ��ֹͣλ��У��λ
 * ��	  �룺
 * 			_iComNo, ���ں�
 *			_iDataBit, ���������λ��ȡֵΪ7��8
 *			_iStopBit, �����ֹͣλ��ȡֵΪ1��2
 *			_iCheckBit, �����У��λ��ȡֵΪ'o'(��У��)��'e'(żУ��)��'s'(��У��)��'n'(��У��)�������ִ�Сд
 * ��	  ����
 *			ERR_COM_WRONG_PARAM, ����Ĳ���
 * �޸���־��
 * 			2013-02-21 dce creat
 */
td_s32 td_cmd_SetComBits(td_s32 _iComNo, td_s32 _iDataBit, td_s32 _iStopBit, td_s32 _iCheckBit);

/*
 * �������ƣ�td_cmd_GetComBits
 * ��Ҫ����: ��ȡ��������λ��ֹͣλ��У��λ
 * ��	  �룺
 * 			_iComNo, ���ں�
 *			_piDataBit, ��ȡ��õ�����λ
 *			_piStopBit, ��ȡ��õ�ֹͣλ
 *			_piCheckBit, ��ȡ��õ�У��λ
 * ��	  ����
 *			ERR_COM_WRONG_PARAM, ����Ĳ���
 * �޸���־��
 * 			2013-02-21 dce creat
 */
td_s32 td_cmd_GetComBits(td_s32 _iComNo, td_s32 *_piDataBit, td_s32 *_piStopBit, td_s32 *_piCheckBit);

/*
 * �������ƣ�td_cmd_SetComWorkMode
 * ��Ҫ����: ���ô��ڹ���ģʽ
 * ��	  �룺
 * 			_iComNo, ���ں�
 *			_iWorkMode, ����Ĵ��ڹ���ģʽ
 * ��	  ����
 *			ERR_COM_WRONG_PARAM, ����Ĳ���
 * �޸���־��
 * 			2013-02-21 dce creat
 */
td_s32 td_cmd_SetComWorkMode(td_s32 _iComNo, td_s32 _iWorkMode);

/*
 * �������ƣ�td_cmd_GetComWorkMode
 * ��Ҫ����: ��ȡ���ڹ���ģʽ
 * ��	  �룺
 * 			_iComNo, ���ں�
 *			_piWorkMode, ��ȡ���ڵĹ���ģʽ
 * ��	  ����
 *			ERR_COM_WRONG_PARAM, ����Ĳ���
 * �޸���־��
 * 			2013-02-21 dce creat
 */
td_s32 td_cmd_GetComWorkMode(td_s32 _iComNo, td_s32 *_piWorkMode);

/*
 * �������ƣ�td_cmd_PTZClarity
 * ��Ҫ����: ͸��ͨ���µ�PTZ����
 * ��	  �룺
 * 			_iComNo, ���ں�
 *			_pcData, Ҫд�����ڵ�����
 *			_iLen, ���ݳ���
 * ��	  ����
 *			ERR_COM_WRONG_PARAM, ����Ĳ���
 * �޸���־��
 * 			2013-02-21 dce creat
 */
td_s32 td_cmd_PTZClarity(td_s32 _iComNo, td_u8* _pcData, td_s32 _iLen);

td_s32 td_cmd_SetChannelPTZForVc(td_s32 _iMainChannelNo);

/*
 * ��������: td_cmd_GetComNum
 * ��Ҫ����: ��ȡ�������ʹ���ʹ��
 * ��	  �룺
 * 			_piComNum, ��ȡ��ô�����
 *			_piComEnable, ��ȡ��ȡ�Ĵ���ʹ��
 * ��	  ����
 *			ERR_COM_WRONG_PARAM, ����Ĳ���
 * �޸���־��
 * 			2013-02-21 dce creat
 */
td_s32 td_cmd_GetComNum(td_s32 *_piComNum, td_s32 *_piComEnable);

/*
 * ��������: td_cmd_GetVcChnComNo
 * ��Ҫ����: ��ȡ�ϳ�ͨ���Ĵ��ڱ��
 * ��	  �룺
 * 			_piComNo, ���ں�
 *			_piVcMainChnNo,  �ϳ�ͨ�����������
 * ��	  ����
 *			ERR_COM_WRONG_PARAM, ����Ĳ���
 * �޸���־��
 * 			2013-02-21 dce creat
 */
td_s32 td_cmd_GetVcChnComNo(td_s32 *_piComNo,td_s32 *_piVcMainChnNo);

td_s32 td_cmd_GetChannelPTZ(td_s32 _iChannelNo, td_s32* _piComNo, td_u8* _pcProtocol, td_s32* _piAddress);

td_s32 td_cmd_PtzControl(td_s32 _iChannelNo, td_s32 _iAction, PTZ_DATA *_pData);

td_s32 td_cmd_GetChannelComAttr(td_s32 _iChannelNo, TCom* _pstCom, td_s32* _pblEnable);

//20130305 add

/*
 * ��������: td_cmd_GetVideoparaCnf
 * ��Ҫ����: ��ȡ��Ƶ��������
 * ��	  �룺
 * 			_iChannelNo,ͨ����	
 *			_piMaxFrameRate, ���֡��
 *			_piMaxVencSize,  ������ֱ���
 * ��	  ����
 *			TD_SUCCESS ��ȡ�ɹ�
 *			TD_FAILURE ��ȡʧ��
 */
td_s32 td_cmd_GetVideoparaCnf(td_s32 _iChannelNo, td_s32 *_piMaxFrameRate, td_s32 *_piMaxVencSize);

/*
 * ��������: td_cmd_SetVideoparaCnf
 * ��Ҫ����: ������Ƶ��������
 * ��	  �룺
 * 			_iChannelNo,ͨ����	
 *			_iMaxFrameRate, ���֡��
 *			_iMaxVencSize,  ������ֱ���
 * ��	  ����
 *			TD_SUCCESS���óɹ�
 *			TD_FAILURE ����ʧ��
 */
td_s32 td_cmd_SetVideoparaCnf(td_s32 _iChannelNo, td_s32 _iMaxFrameRate, td_s32 _iMaxVencSize);

/*
 * ��������: td_cmd_GetChnParam
 * ��Ҫ����: ��ȡͨ������
 * ��	  �룺
 * 			_iChannelNo,ͨ����	
 * ��	  ����
 */
strChannelParam *td_cmd_GetChnParam(td_s32 _iChannelNo);

/*
 * ��������: td_cmd_GetMediaDevice
 * ��Ҫ����: ��ȡ�豸����
 * ��	  �룺
 * 			_pstDev,�豸����
 * ��	  ����
 */
const MediaDevice *td_cmd_GetMediaDevice(MediaDevice *_pstDev);

td_s32 td_cmd_ChannelOsdChangeNotify(td_s32 _iChannelNo);

/*
 * ��������: td_cmd_SetVideoModeCheck
 * ��Ҫ����: ������Ƶ��ʽ�Զ����
 * ��	  �룺
 * 			_iVideoModeCheck,��Ƶ��ʽ�Զ��������ֵ
 * ��	  ����
 */
td_s32 td_cmd_SetVideoModeCheck(td_s32 _iVideoModeCheck);

/*
 * ��������: td_cmd_GuiGetMixAudioChn
 * ��Ҫ����: UI��ȡ����ͨ������
 * ��	  �룺
 * 			_iChannelNo,��Ƶͨ����
 *			_pstMixaudioMsg,��������
 * ��	  ����
 *			TD_FAILURE,��ȡʧ��
 */
td_s32 td_cmd_GuiGetMixAudioChn(td_s32 _iChannelNo,  TMixAudio *_pstMixaudioMsg);

/*
 * ��������: td_cmd_GuiSetMixAudioChn
 * ��Ҫ����: UI���û���ͨ������
 * ��	  �룺
 *			_pstMixAudio,��������
 * ��	  ����
 *			TD_SUCCESS,���óɹ�
 *			TD_FAILURE,����ʧ��
 */
td_s32 td_cmd_GuiSetMixAudioChn(TMixAudio *_pstMixAudio);

/*
 * ��������: td_cmd_GetVideoSizeList
 * ��Ҫ����: ��ȡ��Ƶ�ֱ����б�
 * ��	  �룺
 *			_iChannelNo,ͨ����
 *			_iVideoList,��Ƶ�ֱ����б�
 *			_iMaxCnt,
 * ��	  ����
 *			TD_SUCCESS,���óɹ�
 *			TD_FAILURE,����ʧ��
 */
td_s32 td_cmd_GetVideoSizeList(td_s32 _iChannelNo, td_s32 *_iVideoList, td_s32 _iMaxCnt);

/*
 * ��������: td_cmd_GetFrameRateList
 * ��Ҫ����: ��ȡͨ��֡���б�
 * ��	  �룺
 *			_iChannelNo,ͨ����
			 _iMaxCnt,������
 *			
 * ��	  ����
 			_iFrameList,֡���б�
 *			����֡���б����
 */
td_s32 td_cmd_GetFrameRateList(td_s32 _iChannelNo, td_s32 *_iFrameList, td_s32 _iMaxCnt);
/*
 * ��������: td_cmd_SetFrameRateList
 * ��Ҫ����: ����ͨ��֡���б�
 * ��	  �룺
 *			_iChannelNo,ͨ����
 *			_iFrameList,֡���б�
 			_iCnt,�б����
 * ��	  ����
 *			TD_SUCCESS,�ɹ�
 *			TD_FAILURE,ʧ��
 */
td_s32 td_cmd_SetFrameRateList(td_s32 _iChannelNo, td_s32 *_iFrameList, td_s32 _iCnt, int _iSaveToCfg);

td_s32 td_cmd_GuiVolCtr(td_s32 _iChannelNo, td_s32 *_piVolume);

/*
 * ��������: td_cmd_SingleTalkingCtrl
 * ��Ҫ����: �Խ�����
 * ��	  �룺
 *			_iType,�Խ���Ƶ���ݸ�ʽ
 *			_iTalkingCtrl,�Խ����Ʒ�ʽ(ֻ���ܿ�ʼ��ֹͣ���ֿ���)
 * ��	  ����
 *			TD_SUCCESS,���Ƴɹ�
 *			TD_FAILURE,����ʧ��
 */
td_s32 td_cmd_SingleTalkingCtrl(td_s32 _iType, td_s32 _iTalkingCtrl);

td_s32 td_cmd_SetAoVolume(td_s32 _iAoDev, td_s32  _iVolume, td_s32 _iFlag);
//�û�
td_s32 td_cmd_setUserRight(char *_UserName, int *_iRightId,unsigned int *_iChnBit, int _iCnt);
td_s32 td_cmd_judgeRightType(int _iAuthority);
td_s32 td_cmd_AddUser(char* _cUserName, char* _cPwd, int _iAuthority);
int  td_cmd_DelUser(char* _cUserName);
int td_cmd_ModifyLevel(char* _pcUser, int iLevel);
td_s32 td_cmd_GetNetDefaultGroupRights(int _iGroupId, OUT unsigned int *_u32Authority);
td_s32 td_cmd_GetNetMaxGroupRights(int _iGroupId, OUT unsigned int *_u32Authority);

//20120403 ����add ʵʱ��ȡ����ͨ�����ֱ���

td_s32 td_cmd_getMaxVideoSize(td_s32 _iChn, td_u32 _u8VideoSize, td_s32 _iNorm);

/**********************************���ռƻ�**************************/

/*
 * ��������: td_cmd_setHolidayPara
 * ��Ҫ����: ���ü��ռƻ�����
 * ��	  �룺
 *			_pstHolidayParam,������Ϣ
 * ��	  ����
 *			td_success,���óɹ�
 *			td_failure,����ʧ��
 */
td_s32 td_cmd_setHolidayPara(THolidayInfo *_pstHolidayParam);


/*
 * ��������: td_cmd_getHolidayPara
 * ��Ҫ����: ��ȡ���еļ��ռƻ���Ϣ
 * ��	  �룺
 *			_iHolidayId,���ձ��
 *			_pstHolidayInfor,��ȡ������Ϣ
 * ��	  ����
 */
td_s32 td_cmd_getHolidayPara(td_s32 _iHolidayId, THolidayInfo *_pstHolidayInfor);

/*
 * ��������: td_cmd_setHolidaySchedule
 * ��Ҫ����: ���ü��ռƻ�¼��ģ��
 * ��	  �룺
 *			_iChannelNo,ͨ����

 *			_pstRecTmp, ģ�����
 * ��	  ����
 *			td_success,���óɹ�
 *			td_failure,����ʧ��
 */
td_s32 td_cmd_setHolidaySchedule(td_s32 _iChannelNo, TGuiHolidayRecTemplate *_pstRecTmp);

/*
 * ��������: td_cmd_getHolidaySchedule
 * ��Ҫ����: ��ȡ���ռƻ�¼��ģ��
 * ��	  �룺
 *			_iChannelNo,ͨ����

 *			_pstRecTmp, ģ�����
 * ��	  ����
 *			td_success,��ȡ�ɹ�
 *			td_failure,��ȡʧ��
 */
td_s32 td_cmd_getHolidaySchedule(td_s32 _iChannelNo, TGuiHolidayRecTemplate *_pstRecTmp);

td_s32 td_cmd_set_FileLockStatus(char *_pcFileName, td_u32 iLockFlag);
//20130327 ����add ��ȡ�ļ�����
td_s32 td_cmd_Get_FileLockStatus(char *_pcFileName, td_s32 *_piLockStatus);

//20130328�������ļ���д�뱣��ʱ��
td_s32 td_cmd_Set_StoreTime(int _iChn, int _iDays);

//20130328�������ļ��ж�ȡ����ͨ���ļ�����ʱ��
td_s32 td_cmd_GetStoreTime(td_s32 _iChn);

//20130401 ����add ���ó�֡¼��״̬
td_s32 td_cmd_SetFramePick(int _iChn, int _iEnable);
//20130401 ����add	�������ļ��ж�ȡ����ͨ����֡¼��״̬
td_s32 td_cmd_GetFramePick(int _iChn);
//������¼��add
td_s32 td_cmd_SetSubRecord(int _iChn, int _iEnable);
td_s32 td_cmd_GetSubRecord(int _iChn);
//end
//20130408 ����add ��������¼��״̬
int td_cmd_SetRedundRecState(int _iChn, int _iEnable);
//20130408 ����add  �������ļ��ж�ȡ����ͨ������¼��״̬
int td_cmd_GetRedundRecStat(int _iChn);
td_s32 td_cmd_GetChnRecParam(TChnRecPara * _pstChnRecPara, int _iChn);
td_s32 td_cmd_VcaTypeToNet(td_s32 _iEventType,td_s32 _iFlg);



/**************************************end******************************/

int td_cmd_getDiskGrpInfo(int _iDiskGrp, unsigned int* _puiDisks, unsigned int* _puiChannels);

int td_cmd_setDiskGrpInfo(unsigned int _uiDisks[], unsigned int _uiChannels[]);

int td_cmd_getChnSpaceInfo(int _iChn, unsigned int* _puiUsedRec, unsigned int* _puiLimitRec, unsigned int* _puiUsedSnap, unsigned int* _puiLimitSnap);

int td_cmd_setChnSpaceInfo(int _iChn, unsigned int _uiLimitRec, unsigned int _uiLimitSnap);

int td_cmd_getStorageMode();

int td_cmd_setStorageMode(int _iMode);

int td_cmd_setDiskUsage(td_s32 _iDiskNum, td_s32 _iUsage);

int td_cmd_getDiskUsage(td_s32 _iDiskNum, td_s32 *_piUsage);

//�������ʣ��ռ��¼��ʱ��
td_s32 td_cmd_calcDiskandRecTime (int _iDiskNo, int *_iDiskFree, int *_iRecTime);


//dce add ,������������ʱ����
td_s32 td_cmd_setMainTimeParam(td_s32 _iChn);

//dce add, �����������¼�����
td_s32 td_cmd_setMainEventParam(td_s32 _iChn);

td_s32 td_cmd_getMainAlarmStat(int _iChn);

//dce add,������������ʱ��Ƶ��ز���������
td_s32 td_cmd_SaveMainTimeParam(td_s32 _iChn, TChannelParamEvent *_ptCnf);


//dce add,�����������¼�����������
td_s32 td_cmd_SaveMainEventParam(td_s32 _iChn, TChannelParamEvent *_ptCnf);


//dce add,���ñ������
td_s32 td_cmd_setVideoPara(td_s32 _iChn, td_s32 _iType, TChannelParamEvent *_ptCnf);

//dce add,��ȡ�����������(�¼�)�������
TChannelParamEvent *td_cmd_GetChnParamEvent(td_s32 _iChannelNo, TChannelParamEvent *_Arg);

//dce add,��ȡ�����������(��ʱ)�������
TChannelParamEvent *td_cmd_GetChnParamTime(td_s32 _iChannelNo, TChannelParamEvent *_Arg);

strAppChannel *td_cmd_GetChnParamSub(td_s32 _iChannelNo);
//����¼�����
td_s32 td_cmd_SaveVencSamrtParamTemplate(td_s32 _iChn, td_s32 _iTemplateType, TChannelParamSmart *_ptCnf);
TChannelParamSmart *td_cmd_GetMainSmart(td_s32 _iChn, td_s32 _iTemplate);
td_s32 td_cmd_SetSmartRecTemplate(td_s32 _iCh,td_s32 _iWeekly,td_s32 _iSegment,td_s32 _iTemplateType);
td_s32 td_cmd_GetSmartRecTemplate(td_s32 _iCh,td_s32 _iWeekly,td_s32 _iSegment);
td_s32 td_cmd_SetSmartRecCallBack(td_s32 _iChn, td_s32 _iType);

//shihc add 20130422
td_s32 td_cmd_SetChnPtzPriority(td_s32 _iChannelNo,td_s32 _iPriority);
td_s32 td_cmd_setwififtp_auto(td_s32 _iEnable);
td_s32 td_cmd_getwififtp_auto();
td_s32 td_cmd_setwififtp_manual();
//liyang add
td_s32 td_cmd_set3GDialog(td_s32 _iStartType,td_s32 _iStopType,td_s32 _iDuration);
td_s32 td_cmd_set3GMessage(td_char cPhone[5][32]);
td_s32 td_cmd_Set3GSim(td_char * _pcSim);
td_s32 td_cmd_set3GTaskSchdule(td_s32 _iStopType[3],td_s32 _iDuration[3]);
td_s32 td_cmd_set3GNotify(td_s32 _iType, td_char *_pcMessage);
td_s32 td_cmd_set3GVpdnpara(td_char *_pcDialNumber,td_char *_pcAccount,td_char *_pcPassword);
td_s32 td_cmd_Get3GDialog(td_s32* _iStartType,td_s32* _iStopType,td_s32* _iDuration);
td_s32 td_cmd_Get3GMessage(char _cPhone[5][32]);
td_s32 td_cmd_Get3GSim(td_char * _pcSim);
td_s32 td_cmd_Get3GTaskSchdule(td_s32* _iTimeEnable,td_s32 _iStartTime[3],td_s32 _iStopTime[3]);
td_s32 td_cmd_Get3GNotify(td_s32* _iType, td_char *_pcMessage);
td_s32 td_cmd_Get3GVpdnpara(td_char *_pcApn,td_char *_pcAccount,td_char *_pcPassword);


td_s32 td_cmd_SetWifi_Module(td_s32 _iWifiMode);
td_s32 td_cmd_SetWifi_StaConfig(unsigned int _uiIP,unsigned int _uiMask,unsigned int _uiGateWay, unsigned int _uiDNS,td_char* _pcESSID,td_s32 _iENCRYPTION,td_s32 _iWifiKeyType,td_char* _pcWifiPassword,td_s32 iWifiKeyNum);
td_s32 td_cmd_SetWifi_StaDhcpEn(td_s32 _iEnable);
td_s32 td_cmd_SetWifi_StaPara(td_s32 _iKeySelect,td_s32 _iKeyType,td_s32 _iSetSafeEnable);
td_s32 td_cmd_SetWifi_ApNetConfig(td_char* _pcIP,td_char* _pcMask,td_char* _pcGateWay,td_char* _pcDNS,td_char* _pcESSID,td_s32 _pcENCRYPTION,td_s32 _pcWifiKeyType,td_char* _pcWifiPassword,td_s32 _iWifiKeyNum);
td_s32 td_cmd_SetWifi_ApNetConfig_Ex(StrWifiAP* _psWifiAp);
td_s32 td_cmd_SetWifi_ApDhcpConfig(td_s32 _iDHCPStart,td_s32 _iDHCPEnd,td_s32 _iDHCPLease);
td_s32 td_cmd_SetWifi_ApDhcpEnable(td_s32 _iEnable);
td_s32 td_cmd_SetWifi_Break(td_s32 _iBreak);
td_s32 td_cmd_GetWifi_StaConfig(strWifiCnf* _psWifiAp);
td_s32 td_cmd_GetWifi_ModuleEn();
td_s32 td_cmd_GetWifi_ApConfig(NetWifiAP* _psWifiAp);
td_s32 td_cmd_GetWifiConnectStat();
td_s32 td_cmd_Search_ApList(td_char *_pMsg);

//add end


//dce add,��Դ�������
td_s32 td_cmd_SetPowerAlarmMsg (td_s32 _iAlarm);
td_s32 td_cmd_SetPowerOffMsg (td_s32 _iShutdown);

//��ȡ�����ػ���ѹ��ֵ
td_s32 td_cmd_GetPowerAlarmMsg ();
td_s32 td_cmd_GetPowerOffMsg ();

td_s32 td_cmd_SetPowerManagerMsg (TPowerManageMsg *_ptPowerManageMsg);
td_s32 td_cmd_GetPowerManagerMsg (TPowerManageMsg *_ptPowerManageMsg);
td_s32 td_cmd_GetVoltage();
td_s32 td_cmd_GetTemperature();


//add end

//dce add, ��ȡGPSģ������
td_s32 td_cmd_GetGPSModuleType();

td_s32 td_cmd_SetGPSMsgOvelay(td_s32 _iEnable);
td_s32 td_cmd_GetGPSMsgOveray();
td_s32 td_cmd_SetGPSTimeEnable(td_s32 _iEnable);
td_s32 td_cmd_GetGPSTimeEnable();
td_s32 td_cmd_SetGPSMsgChnOverlay(td_s32 _iChn, td_s32 _iEnable);
td_s32 td_cmd_GetGPSMsgChnOverlay();

td_s32 td_cmd_GetGPSInfor(td_s32 *_iSateNum, td_s32 *_iIntensity);
td_s32 td_cmd_SetGPSFilter(td_s32 _iFilter);
td_s32 td_cmd_GetGPSFilter();

//��ʽ��������´���־�ļ����
td_s32 td_cmd_RestartLog(td_s32 _iDiskNo);
//��ʽ����ʼ�ر���־�ļ����
td_s32 td_cmd_PauseLog(td_s32 _iDiskNo);
//add by liuyan
void td_cmd_RegProcRebldProgCallBack(td_cmd_ProcRebldProgCallBack _CallBack, td_u8 _Who);
td_s32 td_cmd_ProcRebuildProgress(int _iProgress);
td_s32 td_cmd_SetPreviewPrefer(td_s32 _iEnable);
td_s32 td_cmd_GetPreviewPrefer();


//shihc add 20130422
td_s32 td_cmd_SetChnPtzPriority(td_s32 _iChannelNo,td_s32 _iPriority);

td_s32 td_cmd_GetNetPerformanceCost(TCmdNetPerformanceCost * _stPerformanceCost);

td_s32 td_cmd_NetstatusTest(td_s32 _iEth,void *_pNetstatus);//add by zhb 20131027
td_s32 td_cmd_NetDelayTest(td_s32 _iEth,char *_cIp,void *_pNetDelay);//add by zhb 20131027

td_s32 td_cmd_NetPackCapture(td_s32 _iEth, td_u8* _cPath, td_s32 _iPackSize, td_s32 _iTmDelay);


td_s32 td_cmd_IpcChnParaExport(td_s32 _iChn,const td_char* _cFileName);
td_s32 td_cmd_IpcChnParaImport(td_s32 _iChn, const td_char* _cFileName);

//zhangsheng add 20131027
td_s32 td_cmd_SetSysAutoMaintain(td_s32 _iRebootDay, td_s32 _iRebootTime);
td_s32 td_cmd_GetSysAutoMaintain(td_s32* _piRebootDay, td_s32* _piRebootTime);
//zhangshengusr
td_s32 td_cmd_GetUserOnline(td_s32 _iNum, TGuiOnlineUserMsg* _pReq);
td_s32 td_cmd_SetDisconnectUsr(td_s32 _iTime, char* _cIpAddr);
//huweixu add 20150411
td_s32 td_cmd_DisconnectIPFilterUsr(void);
td_s32 td_cmd_GetIpcVersion(td_s32 _iChn,td_char* _cVersion);
td_s32 td_cmd_ChangeIpcIp (const char* _cMac,const  char* _cIP,const char* _cSubMask,const char* _cGateway,const char* _cDns);
td_s32 td_cmd_IpcReboot (int _iChn);
td_s32 td_cmd_RebootChn (int _iChn);
td_s32 td_cmd_IpcUpgrade (int _iChn,const char* _cFileName);
td_s32 td_cmd_GetIpcUpgrateSta(int _iChn,int *_piRate);
//////////////¼���ǩ���////////////////
td_s32 td_cmd_TagModify(int _iChn, int _iOperation, char* _cFileName, int* _piTagTm, char* _cTagName);
td_s32 td_cmd_TagQuery(char* _cFileName, char* _cTagName, TTagInfo _stTagInfo[],int _iMaxTagNum);
td_s32 td_cmd_setvideooutmode(int _iVoid,TVideoOutputType _iMode);
void td_cmd_RegProcRebldProgCallBack(td_cmd_ProcRebldProgCallBack _CallBack, td_u8 _Who);
td_s32 td_cmd_ProcRebuildProgress(int _iProgress);
//////////////////////////////////////////

//��ϣ����ʹ���������ȡ
td_s32 td_cmd_setHashEnable(td_s32 _iEnable);
td_s32 td_cmd_getHashEnable(td_s32 *_iEnable);
td_s32 td_cmd_GetAdditonFileInfo(td_s32 _iFileType,td_s8* _pcFileName);
//��������
td_s32 td_cmd_GetCreateFreeVo();


//����������Ѷ��������
td_s32 td_cmd_SetPoliticsVideoEncrypt(td_char *_cPassword, td_s32 _iEnable);

td_s32 td_cmd_GetPoliticsVideoEncrypt(td_char _cPassword[ENCRYPT_PWD_LENGTH+1], td_s32 *_iEnable);


//���������ط�ʱ��Ĭ�������Ƚ���һ�Σ���������ʾ��������
td_s32 td_cmd_SetPoliticVideoEncrypt();
td_s32 td_cmd_GetRaidStat(td_s32 *_piEnable);
td_s32 td_cmd_SetRaidStat(td_s32 _iEnable);
td_s32 td_cmd_setRaidName(const char * _pcRaidName);
td_s32 td_cmd_getRaidName(OUT char *_pcRaidName);
//td_s32 td_cmd_setSataRaid(void);
td_s32 td_cmd_setDiskinfo(td_s32 iNowSataNum);

//��ȡ����Ƶ����ʹ���������ȡ
td_s32 td_cmd_setSplitAvEnable(td_s32 _iChn, td_s32 _iEnable);
td_s32 td_cmd_getSplitAvEnable(td_s32 _iChn, td_s32 *_iEnable);
	
td_s32 td_cmd_setRaidArrayMsg(td_s8 *_pcRaidName, td_s32 _iOptType, td_s32 _iRaidType, td_s8 *_pcDisklist, td_s32 *_piDisklist, td_s32 _iDiskTotal);
td_s32 td_cmd_getRaidArrayMsg(td_s32 _iNo, TRaidArrayCfg *_pstRaidArryCfg, td_s8 *_pcDisklists);
td_s32 td_cmd_setHddWorkMode(td_s32 _iHddNo, td_s8 *_pcRaidName, td_s32 _WorkMode);
td_s32 td_cmd_setRaidVirDiskMsg(td_s8 *_pcVDName, td_s32 _iOptType, td_s32 _iVdSize, td_s32 _iInitType, td_s8 *_pcRaidName);
td_s32 td_cmd_getRaidVirDiskMsg(td_s32 _iNo, TRaidVdCfg *_pstRaidVdCfg);
td_s32 td_cmd_getRaidSataList(TSataDiskCfg *_pstSataDiskCfg, td_s32 *_piTotal);
td_s32 td_cmd_getRaidVirDiskStatInfo(TRaidVdStat *_pstRaidVdStat, td_s32 *_piTotal);
td_s32 td_cmd_getRaidArrayStatInfo(TRaidArrayStat *_pstRaidArrayStat, td_s32 *_piTotal);
td_s32 td_cmd_GetRaidRiadUseAbleSize(char* _cRaidName);
td_s32 td_cmd_setDevTemp(int _iStartTemp, int _iForceCtrl);
td_s32 td_cmd_getDevTemp();
td_s32 td_cmd_GetDvdSerialNum(td_s32 _iCdNum,td_u8* _pcCDROMSerialNoValue);

//�л���ƵԴ����ģʽ,_iModȡֵ:0-������1-��������ģʽ��2-ʾ֤����ģʽ
td_s32 td_cmd_SetViMod(td_s32 _iChn, td_s32 _iMod);
td_s32 td_cmd_GetViMod(td_s32 _iChn);
td_s32 td_cmd_GetCurViMod(void);

//���úͻ�ȡVo�豸��Ϣ
int td_cmd_get_vodev_cnt();
int td_cmd_set_vodev_cnt(int _iVoDevCnt);

//����������ȡ��������ƵƵƴ��ʹ��
int td_cmd_GetMedleyAvEnable(int _iChn);
int td_cmd_SetMedleyAVEnable(int _iChn, int _iEnable);
//���ÿ�¼�ͱ��ݲ�ͬ¼���ļ���ʽ���ļ�
td_s32 td_cmd_SetFileConvertFrmt(td_s32 _iBurnType,td_s32 _iFileFrmt);
td_s32 td_cmd_GetFileConvertFrmt(td_s32 _iBurnType,td_s32 *_piFileFrmt);

//����/��ȡ��¼��һ¼���ļ���ʽ
td_s32 td_cmd_SetBurnSingleFileFrmt(td_s32 _iBurnType,td_s32 _iFileFrmt);
td_s32 td_cmd_GetBurnSingleFileFrmt(td_s32 _iBurnType,td_s32 *_piFileFrmt);

//���ÿ�¼/������Ƶ�ļ�����
td_s32 td_cmd_SetFileAudioBackFrmt(td_s32 _iBurnType,td_s32 _iFileFrmt);
td_s32 td_cmd_GetFileAudioBackFrmt(td_s32 _iBurnType,td_s32 *_piFileFrmt);


td_s32 td_cmd_getSplitAvBurnEnable(td_s32 *_iEnable);
td_s32 td_cmd_getSplitAvBackupEnable(td_s32 *_iEnable);
td_s32 td_cmd_setSplitAvBurnEnable(td_s32 _iEnable);
td_s32 td_cmd_setSplitAvBackupEnable(td_s32 _iEnable);


// ������������
int td_cmd_SetBestirResponse(int _iChn, int _iStat);

//֪ͨ�����������
int td_cmd_SetBestirToApp(int _iChn, int _iStat);
//����MIC ����
td_s32 td_cmd_set_MicType(int _iVideoChn, int _iAudioChn, int _iMicType);
td_s32 td_cmd_ForceIframeToApp(int _iChn);//֪ͨ���ǿ��I֡


typedef enum
{
	//0-������1-���룬2-�����3-LineIn��4-MicIn
	AUDIO_VOLUME_TYPE_IN = 0,
	AUDIO_VOLUME_TYPE_OUT,
	AUDIO_VOLUME_TYPE_LINE_IN,
	AUDIO_VOLUME_TYPE_MIC_IN,
}TAVLOUMETYPE;
/*
������ 		:	td_cmd_GetAudioVolume
����	    :	��ȡ��ӦID������ֵ
�������	:	_iId:ID��
				_piVolume:	������С
����ֵ		: >=0 �ɹ�   -1 ʧ��
*/
td_s32 td_cmd_GetAudioVolume(td_s32 _iId, td_s32 *_piVolume);

/*
������ 		:	td_cmd_SetAudioVolume
����	    :	��ȡ��ӦId������ֵ
�������	:	_iId:ID��
				_iVolume:������С
����ֵ		: >=0 �ɹ�   -1 ʧ��
*/
td_s32 td_cmd_SetAudioVolume(td_s32 _iId, td_s32 _iVolume);
/*
������ 		:	td_cmd_AudioVolCtr
����	    :	����/��ȡ��ӦId������ֵ
�������	:	_iId:ID��
				_iVolume:������С,	-1:��ȡ����
����ֵ		: >=0 �ɹ�   -1 ʧ��
*/
td_s32 td_cmd_AudioVolCtr(td_s32 _iId, td_s32 *_piVolume);

//��ʼ���豸����ֵ
int td_cmd_AudioVolInit(int _iProductModel);

td_s32 td_cmd_set_commoninfo(STR_COMMON_INFO _stCommonInfo);
td_s32 td_cmd_get_commoninfo(STR_COMMON_INFO *_pstCommonInfo);

//���û�ȡ��������
td_s32 td_cmd_set_BestirType(int _iType);
td_s32 td_cmd_get_BestirType(int *_piType);

//��ȡAO����
int td_cmd_GetAoCnt();

//��ȡԶ����Ƶͨ��
int td_cmd_GetAudioRemoteChn(int _iId);

td_s32 td_cmd_DirectStartBurn(td_s32 _iCdNo,td_s32 _iIsOneKey);
/*
������ 		:	td_cmd_DirectStartburn
����	    :	ui����ieʵʱ��¼���ļ��ӿ�
�������	:	 _iCdNo : ������  _iIsOneKey:�Ƿ�ϵ���
����ֵ		: 	��=0 �ɹ�  -1 ʧ��
*/
td_s32 td_cmd_DirectStartBurnEx(td_s32 _iCdNo,td_s32 _iIsOneKey,td_s32 _iIsOverLap);
/*
������   	:	td_cmd_DirectStartBurnEx
����	    :	ui����ͥ��ʱ��¼���ļ��ӿ�
�������	:	 _iCdNo : ������  _iIsOneKey:�Ƿ���  _iIsOverLap:�Ƿ�ϵ縴��
����ֵ	    : 	��=0 �ɹ�  -1 ʧ��

*/

//���ø����п��ϱ���mic ��ַ��Ӧ��ͨ���Ƿ�����Ƶ���д��
int td_cmd_SetAudioChangeTag(unsigned char _ucVideoChn, unsigned char _ucStat);

td_s32 td_cmd_SetCloseProperty(td_s32 _iEnable);
/*
������   	:	td_cmd_SetCloseProperty
����	    :	���÷��̡�����ʹ��
�������	:	 _iEnable : ���̵��̺ͷ���״̬  0����������λbit0-1,���� bit0-0,������; bit1-1,����;bit1-0,������
����ֵ	    : 	=0 �ɹ�  -1 ʧ��

*/

td_s32 td_cmd_getcloseproperty(td_s32 *_iEnable);
/*
������   	:	td_cmd_getcloseproperty
����	    :	��ȡ���̡�����ʹ��
�������	:	 _iEnable : ���̵��̺ͷ���״̬  0����������λbit0-1,���� bit0-0,������; bit1-1,����;bit1-0,������
����ֵ	    : 	=0 �ɹ�  -1 ʧ��

*/

int td_cmd_getScheduleEnable(int *_iEnable); //���� -��ȡ�Ƿ�֧������
int td_cmd_getProofEnable(int *_iEnable); //����-��ȡ�Ƿ�֧��ʾ֤�л�
int td_cmd_getVcSetVodevListEnable(int *_iEnable); //����-��ȡ�Ƿ�֧�ֺϳɻ�����������豸�б�
int td_cmd_GetVoDevList(int *_iVoDevList, int _iMaxCnt);//����-��ȡ֧�ֵĺϳɻ�����������豸�б�



#endif /*_ASSISTANT_H_*/



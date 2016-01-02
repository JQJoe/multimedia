
#ifndef _TD_PLAY_BACK_1_H_
#define _TD_PLAY_BACK_1_H_
#ifdef PLAYBACK1_H
#define EXT 
#else
#define EXT extern 
#endif

#include <semaphore.h>

#include "libstorage.h"
#include "decode.h"

//#define PLAYPATH 			"/dvr/player/MiniPlayer.exe"
#define PLAYPATH 			"/dvr/player/MiniPlayer.exe.tar.gz"
//Ӳ�̿���
#define SNAP_ERR_ARG    -1
#define SNAP_HAVE       1
#define SNAP_EMPTY      0

//�ط�
#define MAX_CUT_NUM 30
#if 1
#define 	USLEEP(t)		do \
							{  \
								struct timeval tm = {0, t};  \
								select(0, NULL, NULL, NULL, &tm);\
							}while(0);

#else
#define 	USLEEP(t) usleep(t)
#endif


//#define MAXFILELISTLEN (1024 + 512)   	//�����ڲ�ѯ��ļ���Ŀ
#define MAXFILELISTLEN (1024)   	//�����ڲ�ѯ��ļ���Ŀ

#define USUALLY 1
#define CUTVO 2
#define RECONNECT 3

#define PLAYBACKNOCREATE (-1)
#define FILENAMELENOVER	(-2)
#define TIMEERR	(-3)
#define OPENFILEERR (-4)
#define NOFILE	(-5)
#define SPEEDMAXOVER (-6)
#define SPEEDMINOVER (-7)
#define SPEEDSETERR (-8)

#define FINDING	1
#define FINDED	2

#define START	1
#define PAUSE	0
#define STOP		2

#define MAXSPEED  16
#define MINSPEED  (-16)

#if 0
#define SpeedFastTwo (15)
#define SpeedFastFour	(18)
#define SpeedFastEight	(20)
#endif
#define SpeedFastTwo 	(2 * 10)
#define SpeedFastFour	(4 * 10)
#define SpeedFastEight	(6 * 10)
#define SpeedFastMax	(MAXSPEED*10)
#define GUI_VIDEO_PLAY_NEED_PWD  200

#define PICLIMITFLAG 		1
#define SPEEDLIMITFLAG 	2
#define PICANDSPEEDLIMITFLAG 3




typedef struct
{
	int m_iPid;			//�ط������
	volatile PLAYBACK_STAT m_iStat;		//״̬PLAYBACK_STAT
	int m_iSpeed;		//��ǰ�ط��ٶ�
	int m_iFinishFileFlag;
	int m_iFullScreen;
	time_t m_tCurPlayTm; 	//��ǰ�ط�λ�ã�ʱ��ֵ��//�ٷֱ�
	int m_iTimeSeg;//ʱ�����
	int m_iBlackScreen;//���ļ�ʱ�����ı�ʶ
	int m_iRate;
	int iATrueFalse;

	int m_iNeedSecret;
	double m_dSpeed;//�ٶȿ���(ʵ���ٶ�)
		
} TPlayerStat;

typedef struct
{
	int iEncrypt;
	int iATrueFalseBak;//�Ƿ񲥷�����
	double m_dSpeedBak;//�ٶȱ�ʶ����
	PLAYBACK_STAT m_iRunFlagBak;//��ʼ/��ͣ��ʶ����
	long long m_iSkipPosBak;
}TPlayerInterface;//�ⲿ���ƽӿ�

typedef struct 
{
	Decode m_pDc;//
	TPlayerStat m_RunStat;
	int m_ptFileBeginTm;//¼���ļ��Ŀ�ʼʱ��
	int m_ptFileEndTm;//¼���ļ��Ľ���ʱ��
	unsigned int m_u32UpFrameSTime;//��һ֡��ʱ���
	long long m_iSkipPos;//��ת��ʱ��(����:S,�ٷֱ�)
	int m_iPlayILocation;//�ڲ��Ź�����ǰһ��I֡��λ��
	int iTimeChange;//�ı��׼ʱ���ʶ
	int iHasBind;//��ʾ����ͨ������Ƶ���ͨ���Ƿ��
	volatile int m_iImperTm;
	unsigned int m_uiTimePot;//��¼��ʱ���
	int m_iOlnyReadIFrame;
	double m_dBefSpeed;//�ı�֡��ʱ������״̬
	double m_fSpeedValue;//�ı�֡��ʱ������״̬
	pthread_mutex_t AudioLock;
	unsigned int m_u32TimeStamp;
	unsigned short m_AudioFlag;
	unsigned short m_u16BefAudioFrames;
	unsigned int m_u32BefSleepTm;
	int iSpeed16Rate;
	int m_iOptStat;
	struct 
	{
		long long m_lFrameTime;//֡ʱ������ڶ����������Ǳ仯��
		long long m_lForkTime;//����ʱ������ڿ����ŵ�ʱ���Ǳ仯��
	}s_TimeStamp;//��׼
}TPlayBack;

typedef struct
{
	TFileInfo *m_pFileList;
	int 		m_NULL;//�����ļ��Ƿ�Ϊ�գ�0û���ļ���1 �հ��ļ���2:ʵ���ļ�
	time_t	m_iStartTime;					//¼��ʼʱ��
	time_t	m_iEndTime;					//¼�����ʱ��
	//int 	m_FileRunTime;
}TFileListPlay;

typedef struct 
{
	td_s32 	m_s32ListHead;
	td_s32 	m_s32FileListLength;
	int m_iFileNum;//�ļ�������(��1��ʼ)
	int m_iFileCurrent;//��ǰ��ȡ���ļ������б��е�λ��(��0��ʼ)
	TFileInfo 	*m_ptFileListInfo;
	TFileListPlay m_pFileListPlay[2 * MAXFILELISTLEN];
}TFileList;//�ļ��б�ṹ


typedef struct 
{
	TFileList	m_TFileListMsg[MAXPLAYER];
}TsynPlayBack;



//�첽�طż����
//����ȷ��VO����ʵ�����뽨��VO�ĸ���
int TD_Playback_Active(int _s32VoDev, int _iVoCnt, TRect *_pVoRect);//ok


//����:��ʼ���������������
//����ֵ:0:		�ɹ�
//			����:	ʧ��
int TD_Playback_Init(int _iPlayid);//ok

// ���ƣ�playback_SetPlayeFile
// ���ܣ����ûط��������ļ������ô˽ӿڽ����»ط������õ���ʼ״̬
// ������
//	_pPlayBack	:�ط������
//	_strFile		:¼���ļ�����ȫ·����
//	_ptBeginTm	:ָʾ��¼���ļ��Ŀ�ʼʱ��
//	_ptEndTm		:ָʾ��¼���ļ��Ľ���ʱ��
// ����ֵ��0�ɹ��ܣ�������ʧ��
int Playback_SetPlayeFile(IN int _iPlayid, IN char *_strFile, IN time_t _iBeginTm, IN time_t _iEndTm, IN int _iFileNum);//ok

// ���ƣ�playback_CreatePlayer
// ���ܣ�����һ���ط����������ط�������Դ���󶨽�������VO��ʾ��ϵ���ط������ڳ�ʼ����״̬
// ������
//	_ptVo	:ָ����ʾ����
// ����ֵ����ֵ��ʧ�ܣ��Ǹ���ط�������������طŲ�����ʹ�ô˾��
int Playback_CreatePlayer(IN int _iPlayid);//ok

// �ط���������ؽӿڣ�����ֵ0��ɹ���������ʧ��
int Playback_Start(int _iPlayid);		//��ʼ�ط�//ok

//��ͣ
int Playback_Pause(int _iPlayid);//ok
int Playback_BackStep(int _iPlayid);		//�����ط�
int Playback_Back(int _iPlayid);		//����
int Playback_Stop(int _iPlayid);		//�����ط�//ok

int Playback_WaitUinit(int _iPlayid, int _iWaitTime, int _iClearFlag);
#define Playback_WaitStop(_iPlayid)		Playback_WaitUinit(_iPlayid, 10 * 1000 * 1000, 1)
//����
int Playback_Step(int _iPlayid);		//�����ط�//ok

int Playback_Resume(int _iPlayid);//ok

int Playback_Fast(int _iPlayid, int _iCheck);//�طż���//ok

int Playback_Slow(int _iPlayid, int _iCheck);//�طż���//ok

int Playback_PlayAudio(int _iPlayid);//ok

int Playback_StopAudio(int _iPlayid);//ֻҪ�����˲������Ϳ��Թر�����//ok

//ȫ������
int Playback_SetFullScreen(int _iPlayid);//ֻ�д����Ҳ��ǿ��ļ���ʱ�򣬲ſ���ȫ��//ok

//�˳�ȫ��
int Playback_ESCFullScreen(int _iPlayid);//ֻҪ�����Ϳ����˳�ȫ��//ok

/////////////////////////////////////////////////////////
// ���ƣ�playback_GetCurStat
// ���ܣ���ȡ��ǰ�ط�״̬
// ������
//	_iPid		:�ط������
//	_ptStat	:״̬��Ϣ�������
// ����ֵ��0�ɹ��ܣ�-1ʧ��
int Playback_GetCurStat(int _iPlayid, OUT TPlayerStat *_ptStat);//ok

int Playback_SetDecodePassword(int _iPlayid, char* _cPassword);//ok

int Playback_SetSpeed(int _iPlayid, int _iSpeed);//ok

int Playback_Seek(int _iPlayid, IN long long _iSeekTm);
int Playback_Sync_Seek(IN int _iSeekTm, int _iValue);
int Playback_Sync_Step(void);
int Playback_Sync_Stop(void);
int Playback_Sync_Pause(void);
int Playback_GetSynCurStat(OUT TPlayerStat *_ptStat);//ok
int Playback_GuiGetSynStat(OUT PLAYBACK_STAT * _piStat);
int Playback_Sync_Start(void);
td_s32 Playback_Sync_Build_FileList(time_t _iStartTime,time_t _iStopTime,int _Chan[]);
int  Playback_Sync_Active(int _s32VoDev, int _iVoCnt, TRect *_pVoRect);
int Playback_Sync_Destroy(void);
int Playback_Sync_SetDecodePassword(char* _cPassword);//ok
int Playback_Active(int _s32VoDev, int _iVoCnt, TRect *_pVoRect);
int Playback_Init(int _iPlayid);
int Playback_Sync_Continue(void);

int Playback_Sync_Fast(void);
int Playback_Sync_Resume(void);

int Playback_Sync_Slow(void);
int Playback_Clear(void);
int Playback_StatInit(int _iPlayid);
int Playback_DestroyPlayer(IN int _iPlayid);
int Playback_SetSpeedEx(int _iPlayid, int _iSpeed);
int Playback_Sync_SpeedEx(int _iSpeed);
void Playback_InitLimit(void);

void Playback_ClearLimitFlag(int _iPicOrSpeedFlag);

void Playback_SetLimit(int _iPicOrSpeedFlag, int _iChannelNo);
void Playback_TestLimit(int _iPicOrSpeedFlag, int *_piLimit);
int Playback_Sync_Clear();
int Playback_UkStart(int _iPlayid, IN char *_strFile);
void PlaybackSetMaxDecode(td_s32 _iMaxDecode);
///////////////���ӷŴ�///////////////
int  Playback_Ezoom(int _iHandle);
int  Playback_ExitEzoom( );
int  Playback_AdjustEzoom(TRect * _pRect);
//////////////ץ��Ԥ��////////////////
int Playback_OpenJpeg(char* _cFileName);
int Playback_ExitJpeg(td_s32 _s32VoDev);
int Playback_InitJpeg(int _s32VoDev);
//Ӳ�̿���
#define SNAP_DESK_Path "/mnt/sata/"
typedef struct
{
	int m_iType;
	int m_iStartTime;
	int m_iStopTime;
} TSnapTime;
int rec_GetMonthMap(char* _pcPath, int _iYear, int _iMonth, int _iChannelNo, int* _piInfo);
int rec_GetMonthMapInit();
int rec_GetDayMap(int _iYear, int _iMonth, int _iDay, int _iChannelNo, int _iBlurTime, int _iMaxCnt, TSnapTime* _pstTime);


//����
void PlaybackVideoBackup(void);
int Playback_GetPlayState(void);//add by gyn��ȡ��ǰ�طŵ�״̬����0���ڻطţ�=0û�лط�
int Playback_Video_Clip_Query_Pro(int _iClipID);
int Playback_Video_Clip(int _iChn, int _iStartTime, int _iEndTime, char *_pcPath);
int ClipGetSegmentLen(int _iChn, int _iStartTime, int _iEndTime);
//ץ��
int Playback_CapPicture(int _iPlayid);
//
int Playback_GetOptStat(int _iPlayid);
#define UkSubToData(chn)	((((unsigned int)(chn) >> 16) << 7) | ((chn) & 0xffff))

///////////////////////////////////////////////////
#define PLAYFILE void
//#define SELF_DEC
typedef struct
{
	int m_iStat;
	int m_iSpeed;
	int m_iSchedule;
	int m_iPassword;
	int m_iCurTime;
}TplyStat;
PLAYFILE *playfile_build_List(time_t _iStartTime, time_t _iStopTime, int _Chn);
int playfile_unbuild_List(PLAYFILE *_ptPlayFile);
int playfile_read(PLAYFILE *_PlayId, void *_buf, int _iLen, int _iType, S_FrameHeader **_ptFrameHeader, S_FileHeader **_ptFileHeader, int *_piChgFile);
int playfile_seek(PLAYFILE *_PlayId, int _pos, int _iTime, int *_iReTime, S_FileHeader **_ptFileHeader);
int playfile_GetCmd(PLAYFILE *_PlayId, int _iCmd, void *_ptValue);
int playfile_SetCmd(PLAYFILE *_PlayId, int _iCmd, void *_ptValue);
int Play_SetTime(int _iChn, int _iVoChn, int _iVoDevId, IN time_t _iBeginTm, IN time_t _iEndTm);
int Play_Exit(int _iPlayId);
int Play_Pause(int _iPlayId);
int Play_Start(int _iPlayId);
int Play_Seek(int _iPlayId, int _iPos, int _iTm);
int Play_GetStat(int _iPlayId, TplyStat *_ptStat);
int Play_SetEncrypt(int _iPlayId, char *_cPassWord);
int playback_setdefaultAo(int _iDefaultAo);

int Playback_SetPoliticsVideoEncrypt(int _iPlayid, char *_cPasswd);


#endif


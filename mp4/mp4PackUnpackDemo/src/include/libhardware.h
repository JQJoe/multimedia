/*******************************************************************
�ļ���	:hardware.h
��˾	:������ΰҵ����Ƽ����޹�˾
������	:������
��������:2009-10-28
��Ҫ����:Ӳ������������ݶ��塢�ӿں���ԭ��
�޸ļ�¼:2009-10-28,��������������
		 2009-12-08,�����������¹滮�ӿڣ���ӦHi3520��Ӳ��
        
******************************************************************/

#ifndef _LIB_HARD_WARE_H
#define _LIB_HARD_WARE_H

typedef struct rtc_time
{
        unsigned char tm_sec;
        unsigned char tm_min;
        unsigned char tm_hour;
        unsigned char tm_wday;
        unsigned char tm_mday;
        unsigned char tm_mon;
        unsigned char tm_year;
} TRtcTime;

/*
 * ��ʼ��Ӳ��ģ��
 */
td_s32 hardware_Init(td_s32 _iWatchdogTimeout, td_s32 _iHardReset, td_s32 s32AoVolume);
/*
 * �˳�Ӳ��ģ��
 */
void hardware_Uninit();

#define MAXAUDIO	69
#define MAXTOUIAUDIO	255
//AD���͸��������屣��һ��
#define TW2865              2865
#define TW2960              2960
#define TW2964              2964
#define GV7601              7601 //shihc add 20121206
#define SD_VIDEO_WIDTH_D1	0x0
#define SD_VIDEO_WIDTH_960H	0x1
#define HD_VIDEO_WIDTH		0x10

/*
 * ��ȡ��������״̬
 * Bit0-15 ���� 1-16·��������
 * 1�����б�����0�����ޱ���
 */
void hw_GetAlarmIn(td_u32 *_u32Status);

/*
 * ���ñ������״̬
 * Bit0-3 ����1-4·�������
 * 1��ʾ���������0��ʾ�����������
 */
td_s32 hw_GetAlarmOut(td_s32 _iPortNo);
td_s32 hw_SetAlarmOut(td_s32 _iPortNo, td_u32 _u32Status);

/*
 * ��ȡCPLD�汾��ĿǰCPLD�İ汾������ϢΪ��0x10��
 * ����汾V1.0��
 */
td_s32 hw_GetCpld();

/*
 * ���ô����Զ�ת���·�Ĳ����ʡ�
 * �������ã� Ĭ����1200�����ʽ����Զ�������ơ�
 * ����:
 *      uart_num:��Ҫ���õ�UART��(dxl: uart_num����һλ��ʽaurt��,��һλΪ1���λ,0���λ)
 *      rate:������
 *       0	1200
 *       1	2400
 *       2	4800
 *  	 3	9600
 *       4	19200
 *       5	38400
 *       6	57600
 *       7 	115200
 *       ���� ����
 */
void hw_SetUart(td_s32 _iUartNum, td_s32 _iRate);

/*
����cpld ,ʹ485����
*/
td_s32 inline hw_SetCpld(td_s32 _iNo, td_s32 _iSpeed);

/*
 * ����LED�Ƶ�����
 * ����:
 *     ledno:Led�ƺţ�1:�Ƶ� 2:�̵�
 *     statu: 0:�� 1��
 */
void hw_SetLight(td_s32 _iLedNo, td_s32 _iStatus);

td_s32 hw_StopLed();

/*
 * ��ȡreset����״̬
 * ����:��
 * ����ֵ:
 *       1:����reset���� 0����δ����
 */
td_s32 hw_GetResetState();

/*
 * ��ȡ���뿪��״̬
 */
td_s32 hw_GetSwitchState();

/*
 * ���÷�����
 * ����:
 *     status: 1:�� 0:����
 */ 
void hw_SetBuzzer(td_s32 _iStatus);

// ���÷������Ƿ�ʹ��
void hw_SetBuzzerEnable(td_s32 _iStatus);

/*
 * ����Ӳ������ʱ
 * ����:
 *     secs: ��ʱ������
 * ����ֵ:
 *     <0:����ʧ�� 0:���óɹ�
 */ 
td_s32 hw_SetDogTimeOut(td_u32 _u32Secs);

/*
 * ι��
 * ����ֵ:
 *      <0:ι��ʧ��
 */
td_s32 hw_FeedDog();

//������ 091221 ֹͣι��
td_s32 hw_StopDog();

//������ 091221 ������Ϊ��ʹ��
td_s32 hw_DisableDog();

/*
 * ��rtcʱ��
 * ����
 *     rtc_time:
 */
td_s32 hw_GetRtcTime(int *_iYear, int *_iMonth, int *_iDay, int *_iHour, int *_Min, int *_iSec);

/*
 * ����rtcʱ��
 * ����:
 *    rtc_time:
 */
td_s32 hw_SetRtcTime(int _iYear, int _iMon, int _iDay, int _iHour, int _iMin, int _iSec);

//��ȡʵ��ad�豸������ֵ��2960��2865�ȣ���host��slave����
td_s32 hw_GetAdType(void);

//����ad�豸����ֵ����slave����
td_s32 hw_SetAdType(td_s32 _s32Type);

// ������Ƶ������ʽ, TD_PAL/TD_NTSC
td_s32 hw_SetViNorm(int _iVideoMode);

// ��ȡ��Ƶ������ʽ
td_s32 hw_GetViNorm();

td_s32 hw_GetViNormAuto(td_s32 _s32ADChkMode);

// ������Ƶ�������
td_s32 hw_SetViParam(td_s32 _iChn, td_s32 _iBright, td_s32 _iContrast, td_s32 _iSaturation, td_s32 _iHue);

// ��ȡ��Ƶ�������
td_s32 hw_GetViParam(td_s32 chn, td_u8 *bright, td_u8 *contrast, td_u8 *saturation, td_u8 *hue);

// ��ȡ��ǰ��Ƶ����״̬0:����Ƶ,1����Ƶ
td_s32 hw_QueryVideo(td_s32 _iChn);

// ��ȡgv7601(sdi����)��Ƶ����״̬0:����Ƶ,1����Ƶ
td_s32 hw_QueryVideo_HD(td_s32 _iChn);

//��ȡgv7601��⵽�Ĳ�����Ƶ�ĸ�ʽ
td_s32 hw_GetViFormat(td_s32 _iChn);
//����gv7601��ǰ����Ƶ����ģʽ
int hw_SetCurrentViMod(int _iMod);

// ���ò�ת��
/*
 *	value:
 *	0 : disable colortogray
 *	1 : enable colortogray
 *	2 : default, auto detective
 */
td_s32 hw_SetViColorToGray(td_s32 _iChn, td_s32 _iValue);

// ������Ƶ�����С
// ����:
// aodev:	ao�豸�ţ�Ŀǰʹ��0, 
// volume:	����, -1ʱflag��Ч
// flag:		1�����ӣ�0������
td_s32 hw_SetAoVolume(td_s32 _iAoDev, td_s32  _iVolume, td_s32 _iFlag);
//libaoliang add 2012.2.16
//��ȡAO��������С
td_s32 hw_GetAoVolume(td_s32 _iAoDev);


// ��ȡ��ǰ��Ƶ����״̬, 0����Ƶ����,1����Ƶ����
td_s32 hw_QueryAudio(td_s32 _iChn);


// ������Ƶ����
td_s32 hw_SetAudioIn(td_s32 _iSamplerate, td_s32 _iBitwidth, td_s32 _iChnnum, td_s32 _iSeq);

// ������Ƶ��������
td_s32 hw_SetAudioInVolume(td_s32 _iChn, td_s32 _iVolume);

//��������ĳͨ�������ͼ����
td_s32 hw_SetVideoSize(int _iChn, int _iWidth);

//��ȡ���������õ�ĳͨ�������ͼ����
td_s32 hw_GetVideoSize(int _iChn);

//������Ƶ������
td_s32 hw_SetADSamplerate(td_s32 _s32DevId, td_s32 _s32SampleRate);
td_s32 hw_SetTlv320Samplerate(td_s32 _s32FuncTpe, td_s32 _s32Aidev, td_s32 _s32Sample);

//shihc add 20121030 ������Ƶ����Ŀ��ƴ���
td_s32 hw_GetAioFd(void);
td_s32 hw_GetHDStartFlg(void);
td_s32 hw_GetAIVolume(td_s32 _iChn);
td_s32 hw_SetAIVolume(td_s32 _iChn, td_s32 _iVolume);

// ����ϵͳ
void set_Reboot(void);
void hw_SetFanRun(td_s32 _s32FanType);
td_s32 hw_VgaCheck();

//Sherry add 20130110 ��ȡ2964״̬ 
td_s32 hw_GetAddevState(void);
td_s32 hw_SetVinInitVolume(int _iVolume);//����VIN��������ʼֵ


td_s32 hw_Set_3g_Power(td_s32 _iState);
td_s32 hw_Set_Wifi_Power(td_s32 _iState);
td_s32 hw_Set_3g_Light  (td_s32 _iState);
td_s32 hw_Set_Wifi_Light(td_s32 _iState);
td_s32 hw_Reset_BD(td_s32 _iState);
td_s32 hw_SetAutoCopy(td_s32 _iState);
td_s32 hw_Set_Rec_Light(td_s32 _iState);
td_s32 hw_SetAoInitVolume(int _iVolume);//������Ƶ����ĳ�ʼֵ
td_s32 hw_GetSysTemp();

td_u32 hw_GetViMod();
td_u32 hw_SetViMod(td_u32 _u32ViMod);

enum
{
	AUDIO_VOLUME_CTRL_START_MIC_ID  = 1,  //MIC��Ƶ������ Ԥ��64����2Uʵ��4����3Uʵ��16������Ӧ�豸��ʵ��micͨ��id
	AUDIO_VOLUME_CTRL_START_MIC_ID_MAX = 64,//MIC��Ƶ���������

	AUDIO_VOLUME_CTRL_PROOF1_ID = 65,  //ʾ֤��Ƶ������ ʾ֤��ֻ��1��

	AUDIO_VOLUME_CTRL_REMOTE_ID = 100,  //Զ����Ƶ���룬��4·����ӦAO4��0-3·
	AUDIO_VOLUME_CTRL_REMOTE_ID_MAX = 103, //Զ����Ƶ�������ID
};
/*
������ 		:	hw_SetAudioVolume
����	    :	���ö�ӦID������ֵ
�������	:	_iId:ID��
				_iVolume:������С
����ֵ		: >=0 �ɹ�   -1 ʧ��
*/
td_s32 hw_SetAudioVolume(td_s32 _iId, td_s32 _iVolume);

//����MIC���͵������������޸ĵ�Ե�������ֵ����档
td_s32 hw_SetMicType(td_s32 _iVideoChn, td_s32 _iAudioChn, td_s32 _iMicType);


#endif


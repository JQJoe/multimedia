#ifndef _LIBMIX_AUDIO_H_
#define _LIBMIX_AUDIO_H_
#include <unistd.h>
#include <pthread.h>
#include "td_types.h"

//������ֵת��ϵ����UI �õ�ֵΪ0-100����uk����Ӧ��ת��
#define THRESHOLD_COEFFICIENT 	1000

#define AUDIO_BOUNDS            50000//150000  	//����С��5000��Ϊ�Ǿ��� add by ��˼�� 2011.10.20
#define MAX_MIX_AUDIO_CHN		2     	//ÿ·����ͨ���ϳ���Ƶͨ����
#define MAX_AUDIO_FRAME_LENGTH		512
#define AUDIO_MIX_CHN_NUM		1		//����ͨ����
#define PCM_BUFFER_LEN			480//320     //һ֡��Ƶ��320��short���
#define MAX_ANEC_CHNNUM  		30 		//���������Ƶ����ͨ����
#define BUFFER_SIZE   			200 * 480 //2560*2 	//����buffer��С320*2*4
#define AUDIO_DATE_LEN      	960//640   	//����ʱ��Ƶ���ݵĳ���
#define MAX_AUDIO_LEN			484*110 //56*324
#define MIXAUDIO_NULL_CHN_NO	0x7FFFFFFF	//��������Դͨ����, ���Ա�ʾ"--"ѡ��
#define MAX_READ_CNT 8			//ljj add

#define AUDIO_BUF_LEN 			 MAX_READ_CNT*484//2*484//

typedef struct
{
	int m_iAudioSrcChn;//��Դ�߼�ͨ����
	int m_iAudioType;
	int m_iAudioLen;
	int m_iAudioSample;//ljj add 20121022
	unsigned char m_bAudio[AUDIO_BUF_LEN];
	int m_iAudioNUll[2];   //������һ֡�Ƿ��Ǿ�����0���Ǿ�����1�Ǿ���
} TMixAudioMsg;


typedef struct
{
	int m_iUsedFlag;
	int m_iMixAdecType[MAX_MIX_AUDIO_CHN]; 
	int m_iMixAencType;
	pthread_mutex_t m_MutexAudioMix;
} TMixAudioChn;


//��Ƶ״̬��Ԥ�����ھ�����⣬gxl
typedef enum
{
	AUDIO_MUTE = 0,		  //����
	AUDIO_NORM,   //������Ƶ
	AUDIO_NULL,		  //��
}AUDIO_STATUS;

//buffer״̬
typedef enum
{
	BUFFER_NULL = 0,	//buffer�����ݳ��Ȳ���320
	BUFFER_HALF = 1,	//buffer�����ݳ��ȴ���320��û����
	BUFFER_FULL = 2,	//buffer����
}TBuffer_Status;			//add by nsg 20111103

typedef struct
{
	int m_iResult;	//��������
	int m_iSeq;	//��Ƶ֡��ţ�ÿ25֡����һ�η�����
}AUDIO_VARIANCE;        //add by ��˼��20111020


typedef struct
{
	short m_iMax;	//��֡��Ƶ���ݵ����ֵ
	short m_iMin;	//��֡��Ƶ���ݵ���Сֵ
	int m_iNum;	//��������֮��
}AUDIO_DATA;

// ����һ������ͨ������������
int CreateMixAudioChannel();

// ����һ������ͨ��
int DestroyMixAudioChannel(int _iId);

// ������ƵԴ������һ��ΪNULL��ע���ʱ�Ĵ���
// �����ı��뷽ʽ��m_iAudioTypeָ��
// ������ı��볤����m_iAudioLen����
int AudioCheckVarianceEx(const TMixAudioMsg *_ptAudio);
int MixAudio(int _iId, TMixAudioMsg *_ptAudio1, TMixAudioMsg *_ptAudio2, TMixAudioMsg *_ptAudioMix);
//int MixAudio(int _iId,td_u8 *_ptAudio1,  td_u8 *_ptAudio2, td_u8 *_ptAudioMix);

int ClearMixaudio(int _iId);//ljj add

int AudioCheckVariance(const unsigned char g711a_data[], int g711a_bytes);//add by gyn

//int GetChnAudioState( void );// ��ȡ�ĸ�ͨ���Ǿ���add by nsg 20120129

int SetAudioLen(int _iAudioLen);
//����/ ��ȡ���������ֵ;
//��ȡ���: ��Ƶͨ��, ������ֵ
int AudioCheckGetBounds(int _iAudioChn);
//����:��Ƶͨ�� ����ֵ;���سɹ���ʧ��
int AudioCheckSetBounds(int _iAudioChn,int _iBounds);

td_s32 MixAudioGetSleepTm(td_s32 _iSleepTm);

#endif


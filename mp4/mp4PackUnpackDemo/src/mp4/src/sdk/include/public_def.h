/*********************************************************************************
[File information]
FileName = PublicDef.h
Description =  head file
Corp.= Tianjin Tiandy Tech
Author = george
Date= 2006-09-01
[History] 	
XH1=XM20060901,george
*********************************************************************************/
#ifndef _PUBLICDEF_H_
#define _PUBLICDEF_H_

#ifdef FOR_MP4SDK
#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include <time.h>
#include <pthread.h>
#else
#include <assert.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#endif // FOR_MP4SDK

#ifdef MEMWATCH
#include "memwatch.h"
#endif

#define UILOCALSET -1
#define SYSTEMSTAT -2 

//#define OverLapBurn
#define VIOLENCE_DEBUG
#define DOUBLE_TEST
#define ADDIO_MAXCHN		(2)
#define AUDIO_LEFTCHN		0x02
#define AUDIO_RIGHTCHN	0x01

#define AO_DEVICE_LEFT(Device)	((AUDIO_LEFTCHN << 16) | Device)  //������
#define AO_DEVICE_RIGHT(Device)	((AUDIO_RIGHTCHN << 16) | Device)  //������
#define AO_DEVICE_DUALTRACK(Device)	(((AUDIO_LEFTCHN |AUDIO_RIGHTCHN) << 16) | Device) //˫����

#define IN const
#define OUT

#define HI3510		3510
#define HI3511		3511
#define HI3512		3512	
#define HI3515		3515
#define HI3515A		35150
#define HI3520		3520
#define HI3521		3521
#define HI3520A		35200
#define HI3520D		35203
#define HI3531		3531
#define HI3535		3535
//������ 100727 blade_all
#define HI3520SC		35201

#define ALIGN_UP(x, a)				((x+a-1)&(~(a-1)))
#define ALIGN_BACK(x, a)			((a) * (((x) / (a))))

/*
 * The basic data type defination
 */
#define PRODUCT_CHN_1	1
#define PRODUCT_CHN_4	4
#define PRODUCT_VGA		6
#define PRODUCT_DVR_4	14
#define PRODUCT_DVR_8	18
#define PRODUCT_DVR_16	26
#define		CRE 	"^M^[[K"                                                                    
#define 	NORMAL	"[0;39m"                                                               
#define		RED		"[1;31m"                                                                  
#define		GREEN	"[1;32m"                                                                
#define		YELLOW	"[1;33m"                                                               
#define		BLUE	"[1;34m"                                                                 
#define		MAGENTA	"[1;35m"                                                              
#define		CYAN	"[1;36m"                                                                 
#define		WHITE	"[1;37m"

//string length
#define SHORT_PATH_LEN		16		//��·������
#define FILE_NAME_LEN		32		//�ļ�������
#define MIDDLE_PATH_LEN		32		//��·������
#ifdef FOR_MP4SDK
#define	FULL_PATH_LEN		512		//ȫ·������
#else
#define	FULL_PATH_LEN		64		//ȫ·������
#endif
#define MAX_ALIAS_LEN		64		//�������ȣ�������Ƶͨ�����������롢�������

#define INT_NUM_STR_LEN		16		//�����ַ������� dxl 20110722

#define MAX_EXTNAME_LEN     15		//���¼����չ������
//disk num
#define MAX_SATA_NUM		8		//֧������SATAӲ�̸���
#define MAX_USB_NUM			4		//֧������USB���̸���
#define MAX_NFS_NUM			1		//֧������NFS����
#define MAX_ESATA_NUM		1		//֧������eSATA����
#define MAX_HDD_NUM	        8		//֧�����ı���Ӳ�̸���
#define MAX_RECORDER_NUM	2		//֧�����Ŀ�¼����
#define MAX_SD_NUM			1		//֧������SD��
#define MAX_PART_NUM		4		//ÿ������֧�ֵ���������
#define MAX_DISK_NUM		(MAX_SATA_NUM + MAX_USB_NUM + MAX_NFS_NUM + MAX_ESATA_NUM + MAX_SD_NUM)
									//֧�ֵ������̸���
//device parameter
#define MAX_CHANNEL_NUM		32					//���ͨ����Ŀ
#define MAX_INPORT_NUM		64					//��󱨾�����˿���
#define MAX_OUTPORT_NUM		32					//��󱨾�����˿���
#define MAX_SERIAL_NUM		5					//��󴮿���,��ʵֻ��ǰ4������������PTZ���Ƶģ����һ��Ԥ��

#define MAX_VIDEO_COVER_NUM	4					//�����Ƶ�ڵ�������
#define MAX_TIME_SEGMENT	4					//���ʱ��θ���

#define MAX_VCHN_CNT		32					//����ϳ�ͨ�����ĺϳɻ�����
#define ENCRYPT_PWD_LENGTH		16			//��Ƶ�������볤��
//20120913 ����add
#define LOG_ITEM_LEN		(FULL_PATH_LEN + 8)	//log�ļ������ÿ����Ŀ�ĳ��ȣ�Ϊ¼���ļ�ȫ·������¼���С
//add end

//limits
#define MAX_VIDEO_QUALITY	14					//�����Ƶ����
#define MIN_VIDEO_QUALITY	6					//��С��Ƶ����

#define RETURN_NONE			0x12345678			//Magic Number,�����ж���td_assert���Ƿ���Ҫ����ֵ

#define ENCRYPT_PWD_LENGTH		16				//��Ƶ���ܵ��������Ϊ16�ֽ�	
#define ENCRYPT_VIDEO_LENGTH	64				//����Ƶ֡�е�ǰ64�ֽڽ��м���

//������ 100322 �Ƿ����ַ�����λ�á��Ϸ���λ��Ϊ0~15
#define INVALID_OSD_POS				0xFF


// dxl 20110307 ��assiatan.h�Ƶ��˴�
#define VIDEO_WIDTH_BASE	1000
#define VIDEO_HEIGHT_BASE	1000

//added by wanzy 20110902
//shihc mod 20130222
#define CHNNAME_LEN	65
#define CHNNAME_LEN_OLD 33

#define ENCRYPT_STRING	"\1"
#define ENCRYPT_CHAR	'\1'
//����״̬������ʱ����,Add by Leeon Tonie, 081219
typedef enum
{
	STATUS_NORMAL = 0,		//��������
	STATUS_EXIT,			//�˳�����
	STATUS_RESTART,			//��������
	STATUS_HOST_READY,		//��Ƭ������ϣ���ʼ����
}THeartBeat;

extern FILE* fpDebugFile;
extern FILE* fpThreadFile;
extern unsigned int g_iProcThreadNum;
#define MAX_CDROMSERIALNO_LEN 32
//��net_public.h���ƶ���public_def.h�У��Ժ����ú��������Ե���
#define ClearString(str, size)	*((char *)(str)) = '\0'
//������ 091117 �Ϸ����ڴ��ַ��Χ
#define valid_logic_addr(pointer)	((void*)pointer >= (void*)0x00008000 && (void*)pointer <= (void*)0xc0000000)
//#define debug_info(string)	printf(MAGENTA"[%s || %d || %s || PID = %d || errno = %d] %s\r\n"NORMAL, __FILE__, __LINE__, __func__, getpid(), errno, string)
#if 0
#define get_tid()	pthread_self()
#else
#define get_tid()	syscall(224)
#endif

#ifdef TD_DEBUG
#define func_info()\
	do{\
		time_t tUniqueName = time(NULL);\
		printf(BLUE"%s"NORMAL, ctime(&tUniqueName));\
		printf(BLUE"PID = %d, PPID = %d, Thread ID = %lu, Thread Name: %s\r\n"NORMAL, getpid(),getppid(), get_tid(), __func__);\
		printf(BLUE"Created at line %d, file %s\r\n"NORMAL, __LINE__, __FILE__);\
		printf(BLUE"=================================================================================\r\n"NORMAL);\
	}while(0)


		
#define start_exec(name)\
		struct timeval unique_start ## name;\
		gettimeofday(&unique_start ## name, (struct timezone *)NULL);
		
#define stop_exec(name)\
	do{\
		struct timeval unique_stop ## name;\
		gettimeofday(&unique_stop ## name, (struct timezone *)NULL);\
		printf(CYAN"In function : %s, tid : %d your test %s costs %d microseconds\r\n"NORMAL,\
		__func__, (int)pthread_self(), #name, (int)(1000000*(unique_stop ## name.tv_sec - unique_start ## name.tv_sec) + \
		(unique_stop ## name.tv_usec - unique_start ## name.tv_usec)));\
	}while(0)
		
#define td_show(color, msg) printf(color"[%s || %d || %s] : %s\r\n"NORMAL, __FILE__, __LINE__, __func__, msg)
	#ifdef VIOLENCE_DEBUG
	#define debug_info(string)	printf(MAGENTA"[%s || %d || %s || PID = %d || errno = %d] %s\r\n"NORMAL, __FILE__, __LINE__, __func__, getpid(), errno, string)
	#endif

//������ 091029 DEBUG�¶��ԣ���ӡ��������Ϣ������SIGABRT�ź�
#define td_assert(exp, errorno)	assert(exp)
//������ 100208 ��void�͵ĺ�����ʹ�øú�
#define td_assert_s(exp) td_assert(exp, RETURN_NONE)
//������ 100210 ����td_perror
#define td_perror(string) \
	td_printf(0xFF00000, "[%s]%s : %s", __func__, string, strerror(errno))
#else

#define func_info()\
	do{\
		if(fpThreadFile != NULL )\
		{\
			if(g_iProcThreadNum++ <= 200)\
			{\
				time_t tUniqueNameInFuncInfo = time(NULL);\
				fprintf(fpThreadFile, "%s", ctime(&tUniqueNameInFuncInfo));\
				fprintf(fpThreadFile, "%d, PID = %d, PPID = %d, Thread ID = %lu(%lu), Thread Name: %s\r\n", g_iProcThreadNum,getpid(),getppid(), get_tid(), pthread_self(), __func__);\
				fprintf(fpThreadFile, "Created at line %d, file %s\r\n", __LINE__, __FILE__);\
				fprintf(fpThreadFile, "=================================================================================\r\n");\
				fflush(fpThreadFile);\
			}\
		}\
	}while(0)

#define start_exec(name)
#define stop_exec(name)
#define td_show(color, msg)
	#ifdef VIOLENCE_DEBUG
	#define debug_info(string)
	#endif
	
//������ 091029 RELEASE�¶��ԣ���������Ϣ��¼��debug_info.txt������errorno
#define td_assert(exp, errorno)\
	do{\
		if (!(exp))\
		{\
			if (fpDebugFile != NULL)\
			{\
				time_t tUniqueNameInTdAssert = time(NULL);\
				fprintf(fpDebugFile, "%s%s: %d: %s: Assertion \'%s\' failed.\r\n",\
				ctime(&tUniqueNameInTdAssert), __FILE__, __LINE__, __func__, #exp);\
			}\
			return (errorno);\
		}\
	}while(0)
//������ 100208 ��void�͵ĺ�����ʹ�øú�
#define td_assert_s(exp)\
	do{\
		if (!(exp))\
		{\
			time_t tUniqueNameInTdAssert = time(NULL);\
			if (fpDebugFile != NULL)\
			{\
				fprintf(fpDebugFile, "%s%s: %d: %s: Assertion \'%s\' failed.\r\n",\
				ctime(&tUniqueNameInTdAssert), __FILE__, __LINE__, __func__, #exp);\
			}\
			return;\
		}\
	}while(0)
#define td_perror(string)	
#endif

#define set1(byte, bitn) (byte) |= 0x1 << (bitn)		//��byte�ĵ�bitnλ��1
#define set0(byte, bitn) (byte) &= ~(0x1 << (bitn))		//��byte�ĵ�bitnλ��0
#define getbit(byte, bitn) (((byte) >> bitn) & 0x1)	//��ȡbyte�ĵ�bitnλ
//#define absollute()		 (int)(times(NULL) / 100)
typedef unsigned char		td_u8;
typedef unsigned char       td_uchar;
typedef unsigned short		td_u16;
typedef unsigned int		td_u32;
typedef unsigned long long 	td_u64;
typedef signed char			td_s8;
typedef short				td_s16;
typedef int					td_s32;
typedef long long			td_s64;


typedef char                td_char;
typedef float				td_float;
typedef double				td_double;
typedef void                td_void;
typedef long double			td_ldouble;
#define PACKED				__attribute__((packed))	

/*******************************************From 3510 below**********************************************************/
#define OSD_REGION_HANDLE td_u32
typedef struct							//Sherry modify 20081121
{
	td_u8 		m_u8Brightness;
	td_u8 		m_u8Hue;
	td_u8 		m_u8Contrast;
	td_u8 		m_u8Saturation;
	td_u8		m_u8StartTime[3];		//0:Hour 1:Minute 2:Second
	td_u8		m_u8StopTime[3];		//0:Hour 1:Minute 2:Second
	td_u8		m_u8CtoG;				//Leeon Added 090112, ��ת��(Color/Gray)ʹ��
}structVideoParam;

typedef struct __RECT__
{
	unsigned short left;
	unsigned short top;
	unsigned short right;
	unsigned short bottom;
}Rect_t;

typedef struct
{
	td_u8		m_u8SensorFlipEnable;
	td_u8		m_u8SensorMirrorEnable;
	td_u8		m_u8SensorScene;
}SENSORPARA;

/*���ڵ���ͨ������*/
typedef struct osd_text_struct
{
//	OSD_REGION_HANDLE osd_handle;     	/*����osd ʱ�ײ㷵��*/
	int  	show;      					/*true = show ���Ƿ���ʾ*/
	char	text[CHNNAME_LEN];					/*�����ַ�����*/
	int	osdpos;          				/*����λ��0~15*/
	int 	osdX;						//����λ�ú�����
	int 	osdY;						//����λ��������
	td_u32	osdColor;      				//�����ַ���ɫ
}OSD_CHANNAME_T;

/*******************************************From 3510 above**********************************************************/

/*----------------------------------------------*
 * The common constant                          *
 *----------------------------------------------*/
typedef enum {
    td_false    = 0,
    td_true     = 1,
} td_bool;

#ifndef NULL
#define NULL             0L
#endif

#define td_success          0 
#define td_failure          (-1)
//device capability
//������ 100727 blade_all
#define VIDEOENCODE_MAX_CHANNEL_NUM		32//16  //sherry 20100613 modify for 3520-single-chip
#define MAX_VCA_CHN_NUM    32
#define VIDEOINPUT_MAX_CHANNEL_NUM		32
#define AUDIOENCODE_MAX_CHANNEL_NUM	16
#define AUDIOINPUT_MAX_CHANNEL_NUM		16
#define VIDEOOUTPUT_MAX_CHANNEL_NUM		16    //gxl added 20091215
//#define GPIN_MAX_NUM	4
//#define GPOUT_MAX_NUM 4
//Cheng 2010/02/21 add talk channel
#define AUDIO_CHANNEL_TALK_NUM                    1

// for test
#ifdef TD_DEBUG
#define	MAX_CONNECTION		4		//����ʱʹ��
#else
#define	MAX_CONNECTION		8		//ÿһͨ��������8������
#endif
#define   MAX_ENCODE_ABILITY	480        //����������480 cif

#define NO_STREAM   		0
#define ONLY_VIDEO  		1
#define ONLY_AUDIO  		2
#define VIDEO_AUDIO 		3

#define NETMODE_TCP     	1
#define NETMODE_UDP     	2
#define NETMODE_MC      	3
#define NVS_ACTIVE      	4

#define BYTES_1K			(0x1 << 10)
#define BYTES_1M			(0x1 << 20)
#define BYTES_1G			((td_u64)0x1 << 30)
#define BYTES_1T			((td_u64)0x1 << 40)

#ifndef MIN
#define 	MIN(x,y) ((x) < (y) ? (x) : (y))
#endif
#ifndef MAX
#define 	MAX(x,y) ((x) > (y) ? (x) : (y))
#endif

#define MAX_FRAME_SIZE   BYTES_1M    // ���֡1M 

//��������
#define CONNECTMODE_CMD		1
#define CONNECTMODE_DATA		2
#define CONNECTMODE_DIDA		0

#define	 TD_AUTO     		1

#define DEVICE_DVRS 0
#define DEVICE_DECS 1

typedef enum
{
	AUDIO_TYPE_G711A = 1,
	AUDIO_TYPE_G711U,
	AUDIO_TYPE_DVI4,
	//ljj add
	AUDIO_TYPE_MEDIA_G726_1_24 = 0x05,
	AUDIO_TYPE_MEDIA_G726_1_32 = 0x06,
	AUDIO_TYPE_MEDIA_G726_1_40 = 0x07,
	AUDIO_TYPE_MEDIA_AAC = 0x16, // huaqiang add for AAC 20130107
	AUDIO_TYPE_ADPCM_IMA = 0x23,
	//ljj add end 
	// zty 20120220
	AUDIO_TYPE_MEDIA_G726_16 = 0x24,
	AUDIO_TYPE_MEDIA_G726_24 = 0x25,
	AUDIO_TYPE_MEDIA_G726_32 = 0x26,
	AUDIO_TYPE_MEDIA_G726_40 = 0x27,
	// zty add end
	
	//ljj add 
	AUDIO_TYPE_PCM	= 0x33,
	AUDIO_BUTT,	

    //qiaohaijun for audio error
	AUDIO_TYPE_ERROR = 0xff
}AUDIO_TYPE_E;

typedef enum 
{
	ANALOG_CHN = 0,  //ģ��ͨ��
	DIG_CHN,		 //����ͨ��
	VOENC_CHN,       //VO���ϱ���ͨ��
	BUTT,
}CHN_TYPE;

typedef enum
{
	VENC_H264 = 0,
	VENC_MJPEG,
	VENC_BUTT,
}VENC_TYPE_E;

typedef enum
{
	QCIF =0,
	HCIF,
	FCIF,
	HD1,
	FD1,
	MD1,
	QVGA,
	VGA,
	HVGA,
	F720P,
	F960P,
	F1200,
	F1080P,
	QXGA,
	QHD	= 0x0100,
	H960 = 0x0200,
	MA5 = 0x300,
	M5 = 0x400,
	QSXGA = 0x0500,
    //����ģʽ�ֱ��ʸ�ʽ:100000 + N(NΪ���Ϸֱ��ʴ���),�Դ�����
    F720P_9_16 = 0x100009,    //720x 1280
    F1080P_9_16 = 0x10000C,	//1080x 1920
	VIEDOSIZE_BUTT,
}VIDEO_SIZE_E;

#define F1080I 40

#define CIF		FCIF
#define D1		FD1
#define SXGA		HVGA


//����3520 SDI�豸�����������궨�壬�����豸��Ҫ��
#define    HD_SDI720P 		2
#define    HD_SDI1080P 	3
//end

typedef enum
{
	VI_NORM_PAL 		= 0x0000,
	VI_NORM_NTSC,
	VI_NORM_AUTO		= 0x0004,

	VI_NORM_960H_PAL 	= 0x0010,
	VI_NORM_960H_NTSC,
	
	VI_NORM_720P		= 0x040,//0x0100
	VI_NORM_1080P		= 0x050,//0x0110
	VI_NORM_BUTT,
}VI_NORM;

typedef enum //shihc add 20121206
{
	VI_1080P30 = 0,
	VI_1080P25,
	VI_1080I60,
	VI_1080I50,
	VI_720P60,
	VI_720P50,
	VI_720P30,
	VI_720P25,
	VI_1080P60,
	VI_1080P50,
} VI_HD_FROMAT_E;


typedef struct
{
    char    m_cDeviceId[64];
    char    m_cDeviceName[64];
    char    m_cNFSIp[16];
    char  	m_cNFSPath[255+1];
	int		m_iDevNo;								//�豸��ţ���������2008-12-03��DVR�����ֶ�
	int 	m_blNfsEnable;							//NFSʹ��
	int		m_iVspport;
	int		m_iVapport;
	char	m_cAccessnum[64];
}STR_COMMON_INFO;

#define MAX_PATH_LEN         (255+1)
#define USER_NAME_LEN       16
#define PASSWORD_LEN        16

typedef struct
{
	char    m_cManagerServerIp[16];
	long    m_lManagerServerPort;
	char    m_cHeartBeatServerIp[16];
	long    m_lHeartBeatPort;
	char    m_cRegisterServerIP[16];
	long    m_lRegisterPort;
	char     m_cEnableHeartBeat[16];
	int     m_iHeartBeatPeriod;
	int     m_iRegisterTime;
	char    m_cVapPath[MAX_PATH_LEN];
	char    m_authServerIp[16];
	long    m_lauthServerPort;
	char    m_authUserName[USER_NAME_LEN];
	char    m_authUserPassword[PASSWORD_LEN];
	char    m_cputhreshold;
	char	m_memthreshold;
}STR_NET_MANAGE_INFO;


#define VERSION_LEN     64
typedef struct
{
    char    m_csoftWareVersion[VERSION_LEN];
}STR_UPGRADE_INFO;

typedef struct
{
 	int    m_iFormat;
	char m_cSeperatechar[8]; 
}STR_DATE_FORMAT;
/**************************Other Attributes Begin*******************************/
//������ 091222 ��������
typedef enum
{
	ALIAS_CHANNEL = 0,		//ͨ��
	ALIAS_ALARM_INPUT,		//��������
	ALIAS_ALARM_OUTPUT,		//�������
}TAliasType;

typedef struct
{
	td_u8	m_cChannel[MAX_CHANNEL_NUM][MAX_ALIAS_LEN + 1];		//ͨ������
	td_u8	m_cAlarmInput[MAX_INPORT_NUM][MAX_ALIAS_LEN + 1];	//��������ͨ������
	td_u8	m_cAlarmOutput[MAX_OUTPORT_NUM][MAX_ALIAS_LEN + 1];	//�������ͨ����
	td_s32	m_iChannelVer;									//ͨ�������汾
	td_s32	m_iAlarmInputVer;								//��������ͨ�������汾
	td_s32	m_iAlarmOutputVer;								//�������ͨ�������汾
}TAlias;

/**************************Other Attributes Begin*******************************/
/**************************Media Attributes Begin*******************************/
typedef enum hiFRAME_TYPE_E
{
    FRAME_I = 0,   /* I frame */
    FRAME_P,       /* P frame */
    FRAME_BUTT
} FRAME_TYPE_E;

//����Ƶ֡ͷ
typedef struct
{
    unsigned int	u32FrameID ;	//��ʾID,32λ,�̶�Ϊ: 0x 00 00 00 02
    unsigned int	u32FrameSize;	//֡��С32λ,����֡��С,�ֽ���
    unsigned char	u8FrameType;	//֡����,8λ,FRAME_I=0,  FRAME_P=1, FRAME_B=2 
    unsigned int	u32FrameNO;	//֡���,32λ,֡���,ѭ������
    unsigned int	u32TimeStamp;	//ʱ���,32λ,��ʱ��֪����ʲô��
    unsigned int	u32VStreamLen;	//��Ƶ���ݳ���,32λ,��Ƶ���ݴ�С
    unsigned short	u16AFrames;	//��Ƶ֡��,16λ,����Ƶ֡Я����Ƶ֡��
    unsigned short	u16AFrameSize;	//��Ƶ֡��С,16λ,��Ƶ֡��С
    unsigned char	u8ACoder;	//��Ƶѹ����ʽ,8λ,��ѹ��:0;G711_A:0x01; G711_U:0x02;ADPCM_A :0x03;G726:0x04
    unsigned short	reserved;		//16λ,����,32λ����
}S_FrameHeader,*pS_FrameHeader;
//֡ͷ�����ȸ���֡��Ƶ����,�ٸ�������Ƶ����

#define MAX_COVWORD_LEN 36
//�ļ�ͷ�ṹ
typedef struct
{
    unsigned short  FrameRate;	//֡��
    unsigned short  Width;		//ͼ���
    unsigned short  Height;		//ͼ���
    unsigned short  Mode;		//����ģʽ��11��MP4)�� 21(H264)
    unsigned short  bAudio;		//�Ƿ����Ƶ
    unsigned short  Year;		//H264���벻���������ֶΣ�ȫ����0xFF,���Բ���Ϊ¼��ʱ��
    unsigned short  Month;
    unsigned short  Day;
    unsigned short  Hour;
    unsigned short  Minute;
    unsigned short  Second;
    unsigned short  CoverMask;
    char cCovWord[36];		//�̶�����ַ���"S MULTI-MEDIA STREAM (H.264)"��0x00��������ʣ�ಿ�����0xFF
    unsigned int 	m_uiFrameNoDiff;	// �ļ���β֡�Ų�
    unsigned int 	TriggerHigh;	// ��¼�����˿ں�20120906 ����
    unsigned int 	TriggerLow;	// ��¼�����˿ں�20120906 ����
    unsigned short	reserved;		//��cCovWord��ǰ�ĳ��ȣ���ǰֵΪ36
    unsigned char   AChannels;   // ����1/2��Ĭ��Ϊ1
	unsigned char   BitsPerSample;// ����λ��8/16/24, Ĭ��16
    unsigned int 	AudioSample;
    unsigned int    TotalSize;	//�ļ��ܴ�С(�ֽ���)���ϰ汾����
    unsigned int    FrameCount;	//�ļ���֡��,�ϰ汾����
}S_FileHeader,*pS_FileHeader;
/**************************Media Attributes End*******************************/
/**************************Alarm Attributes Begin*******************************/
//���ֱ�������
#if 1 // modify by caizhaoxu 20120321
typedef enum
{
	ALM_VIDEO_LOST,								//��Ƶ��ʧ����,1
	ALM_PORT,									//�˿ڱ���,0
	ALM_MD,										//�ƶ���ⱨ��,2
	ALM_VIDEO_COVER,							// video cover
	ALM_VCA,									// this value only for ensure ALM_AUDIO_LOST is 5
	//add by gyn 20120903
	ALM_AUDIO_LOST,                             //��Ƶ��ʧ����
	//add end
	ALM_TEM_HUM,
	/****************************************************************
	* if you want to save your alarm info into config_alm.dat by type,
	* please add you type over this value
	*****************************************************************/
	ALM_SAVE_TO_CFG, 

	ALM_TW,                						//���߱��� 
	ALM_PM,										// �ܽ籨��
	ALM_OSCER,									//��Ʒ����
	//ALM_FACE,									//�������
	ALM_DIAGNOSE,								//��Ƶ���
	ALM_CAP,								    //���ܸ���//shihc add 20130225
	ALM_CAP_td,
	ALM_CPC,									//����ͳ��
	ALM_CDD,                                    //��Ⱥ�ۼ�
	ALM_SVD,									//���
	ALM_MAX,									//���ֵ����ֵ����������ʱʹ�ã�Ҫ��չ�������ڸ�ֵ�������
}TAlarmType;

#else
typedef enum
{
	ALM_VIDEO_LOST,								//��Ƶ��ʧ����
	ALM_PORT,									//�˿ڱ���
	ALM_MD,										//�ƶ���ⱨ��
	ALM_TW,                //zhangweiwei add
	ALM_PM,
	ALM_FACE,
	ALM_DIAGNOSE,
	ALM_MAX,									//���ֵ����ֵ����������ʱʹ�ã�Ҫ��չ�������ڸ�ֵ�������
}TAlarmType;
#endif
/**************************Alarm Attributes End*******************************/
/**************************Hardware Attributes Begin*******************************/

/**************************Hardware Attributes End*******************************/

/**************************Com Attributes Begin*******************************/

//���ڵĹ���ģʽ
typedef enum
{
	PTZ_PROTOCOL = 1,								//Э�����ģʽ
	PTZ_STREAM = 2,									//͸��ͨ��ģʽ
	PTZ_RESERVED = 3,								//Ԥ��
	PTZ_7601B = 4,									//7601B�������߱�����
	key_485 = 5,
	GPS_MOD = 6,									//����GPS
	ATM_PROTOCOL = 7,
	PTZ_WORKMODE_MAX,								//���ֵ������������������������
}TComWorkMode;

//��¼�������õĽṹ��
typedef struct
{
	td_s32		m_iBaudRate;								//�豸�Ĳ�����
	TComWorkMode	m_eMode;									//���ڵĹ���ģʽ
	td_u8		m_ucDataBit;								//����λ
	td_u8		m_ucStopBit;								//ֹͣλ
	td_u8		m_ucVerifyBit;								//У��λ
	td_u8		m_uUartId;									// dxl 20110513 ����UART���ã��Լ��ݲ�ͬӲ��ƽ̨
}TCom;
/**************************Com Attributes End**********************************/
/**************************PTZ Attributes Begin**********************************/
//ͨ����ص�PTZ����
typedef struct
{
	//Leeon Tonie Added below for 3511, new PTZ mode.
	td_u8			m_cProtocol;						//��ͨ����ʹ�õĿ���Э����
	td_u8			m_cProtocolName[32];				//��ͨ����ʹ�õ�Э������
    td_u8			m_cComNo;							//��ͨ����Ӧ��ͨ����
    td_s16			m_sAddress;							//��ͨ���������豸�ĵ�ַ
    td_u8			m_blComAttrEnable;					//�Ƿ��Զ��崮������
    TCom			m_stComAttr;						//��Э������Ӧ�Ĵ������ԣ���9600,'n',8,1
}TPTZChannel;
/**************************PTZ Attributes End*******************************/
/**************************User Attributes Begin*******************************/
#define MAX_IPFILTER_NUM			16

//������ 091028 ΪIP���˶�����������ݽṹ���������û�ģ��
typedef struct
{
	//��������ͨ���������õ����η�ʽ
    td_u32	    m_u32ExpectIP;					//�����ε�IP��ַ
    td_u32		m_u32ExpectMask;				//�����ε�IP������
	
	//Leeon Tonie add for Tiandy-Dvr, more ip filter
	//���²�����ͨ���������õĺ�����/�������ķ�ʽ
	td_u8		m_cFilterType;					//����:������/������/������
	td_u8		m_cIPNum;						//��������
	td_u32		m_uiIPList[MAX_IPFILTER_NUM];	//����
}TIpFilter;
//zhangshengusr 20131029 Ϊ���˱��Ͽ���ip����Ľṹ��
typedef struct
{
	td_u32  m_uiIP;		//���Ͽ���ip
	td_s32  m_iTime;	//���Ͽ���ʱ��
}TdicUsrMsg;

typedef struct
{
	td_s32  m_iNumNow;  //Ŀǰ����ֹ��ip����
	TdicUsrMsg  m_IPMember[32];//��󱣴�32���û�
	pthread_mutex_t g_mutexIPforbidLogon;//���ڱ༭��ֹ��½ip�б�ı���
} TIPFilter_ex;

/**************************User Attributes End**********************************/
//�豸֧�ֵ��ַ���
typedef enum
{
	GB2312 = 1,
	UTF8,
}TCharsetType;


//add by wanzy  2011/10/19 �������sipЭ��

//SIP�豸����
typedef struct
{
	char m_SipServerIp[33];	//sip������ip
	int  m_SipServerPort;	//sip�������˿ں�
	char m_SipServerID[33];	//sip������ID
	char m_SipDeviceID[33]; //�豸���
	char m_SipUserName[33]; //�û���
	char m_SipPassword[33];	//����
	int  m_RegisterValidity;//ע����Ч��	
	int  m_keepalivetime;	//����ʱ��
	int  m_HeartBeatinterval;	//�������ʱ��
	int  m_HeartBeatTimes;	//��������
	int  m_EnableRegister;
}TSIPDeviceInfo;

//SIP��Ƶͨ������
typedef struct
{
	int   	m_iChannelNo;
	char	m_pcChannelId[32];	//ͨ���豸���
	int   	m_iLevel;		//��ǰptz���Ƽ���
	int   	m_iPTZtime;		//�ϴ�ptz���Ƽ�ʱ
}TSIPChnPara;

//SIP����ͨ������
typedef struct									
{
	int   	m_iChannelNo;
	char	m_pcChannelId[32]; //ͨ���豸���
	int   	m_iLevel;			//ͨ����������
}TSIPAlarmPara;

//add by wanzy 2011/10/19
typedef struct
{
	int	m_iCmdNo;
	int   	m_iChannelNo;
	char	m_pcChannelId[32];
	int   	m_iLevel;
	int   	m_iPTZtime;
}TCstmChnParaID;

//add by nsg 120905
typedef struct
{
	td_s32	m_iInformWay;			//ͨ�ŷ�ʽ0:���� 1:UDP
	char	m_cProtocolType[33];	//Э�鳧������	
	td_u32  m_uiSrcIP;				//ATM  IP��ַ
	td_s32	m_iSrcPort;				//ATM�˿ں�
	td_u32	m_uiDestIP;				//�豸IP��ַ
	td_s32	m_iDestPort;			//�豸�˿ں�
}TAtmPara;			//ATM����

#define STR_SERVER_NAME_LEN 63
#define IP_STR_LEN 31

typedef struct 
{
	char	m_cServerName[STR_SERVER_NAME_LEN + 1];       	//��������ַ
	char	m_cPath[STR_SERVER_NAME_LEN + 1];				//�ļ�·��
	char 	m_cUserName[IP_STR_LEN + 1];         			//�û���
	char	m_cPassword[IP_STR_LEN + 1];					//����
	int		m_iPort;										//�˿ں�
	int 	m_iUseage;                   					//��;0 ���� 1�ϴ�
	int 	m_iUploadMethod;              					//�ϴ���ʽ0:�Զ�1:�ֶ�
}TFtpPara;	//	FTP����

#define MAX_LEN_EMAILPARM 64
typedef struct TSmtpPara
{
	char m_SmtpServerIp[MAX_LEN_EMAILPARM];
	char m_SmtpServerPort[MAX_LEN_EMAILPARM/8];
	char m_SmtpServerAccount[MAX_LEN_EMAILPARM];
	char m_SmtpServerPassword[MAX_LEN_EMAILPARM];
	char m_AuthType[MAX_LEN_EMAILPARM/2];
	char m_TimeOut[MAX_LEN_EMAILPARM/8];
	
	char m_From[MAX_LEN_EMAILPARM];
	char m_To[MAX_LEN_EMAILPARM];
	char m_EmailSubject[MAX_LEN_EMAILPARM*2];
	char m_EmailAddr[4][MAX_LEN_EMAILPARM];
}TSmtpPara;

//end

#define TR_SUBDEVIDREQ 1000
#define TR_SUBDEVIDRSP -1000
#define TR_MAINDEVIDREQ 1001
#define TR_MAINDEVIDRSP -1001

//add by zhuangzhibing 20120216
typedef enum
{
	NETDATA_COM 	= 1,									//��������ͨ��͸��ͨ������
	COMDATA			= 2,									//��������
	UIDATA			= 3,									//Ui����ͨ��������ת��
	NETDATA_DZ		= 4,									//��������ͨ��DZЭ�鷢��
}TDataType;//����ҷ������ݵ�����
//add end
//�ļ�����
typedef enum
{
	FILE_REC = 0,    //¼���ļ�
	FILE_IMG,        //ͼƬ�ļ�
	FILE_BACKUP,	 //����¼��
	FILE_AUDIO,      //��Ƶ�ļ�
	MAX_FILE_TYPE,	 //�ļ����͵����ֵ
}TFileType;

typedef enum
{
	CONVERT_FILETYPE_SDV=1, 	//Ĭ��SDV��ʽ,��ת��
	CONVERT_FILETYPE_AVI,  	//ת����AVI��ʽ
	CONVERT_FILETYPE_MP4,   	//ת����MP4��ʽ
	CONVERT_FILETYPE_MAX,  //Ԥ��
}CONVERT_TYPE_E;

typedef enum
{
	CBL_SINGLE_FILETYPE_DISABLE=0, 	//��ʹ�ܵ�һ�ļ���¼
	CBL_SINGLE_FILETYPE_SDV,
	CBL_SINGLE_FILETYPE_AVI,
	CBL_SINGLE_FILETYPE_MP4,
	CBL_SINGLE_FILETYPE_MAX,  //Ԥ��
}CBL_SINGLE_TYPE_E;//���ݻ��¼��һ�ļ�¼���ʽ


typedef enum
{
	AUDIO_FILETYPE_NONE =0, 	//Ĭ�ϲ�������Ƶ�ļ�
	AUDIO_FILETYPE_AAC,  	//����AAC��Ƶ�ļ�
	AUDIO_FILETYPE_MAX,  //Ԥ��
}BACK_AUDIO_TYPE_E;

typedef td_s32 TRecordType;
#define MAX_RESERVED_INFO_LEN	64	//¼���ļ���Ϣ�е�Ԥ����Ϣ����

//�ļ������ṹ
typedef struct
{
	td_u64	m_ulFileIndex;					//�ļ�������
	td_u8	m_ucChannelNo;					//ͨ����
	TFileType	m_eFileType;				//�ļ�����,TFileType
	TRecordType	m_eRecordType;				//¼������,TRecordType
	td_u64 	m_eDevType;						//��ƵԴ�豸���� 
	td_s32 	m_iRecAttr;						//¼���ļ������ԣ��ò�ͬ¼������Ȩֵ�ĳ˻�����ʾһ��¼���ļ������еĶ�������
	td_u8	m_ucFileName[FILE_NAME_LEN];	//�ļ���������·��
	td_u8	m_ucFileNameSed[FILE_NAME_LEN];//����¼���ļ���
	td_u32	m_uiFileSize;					//�ļ���С����λBYTES
	time_t	m_iStartTime;					//¼��ʼʱ��
	time_t	m_iStopTime;					//¼�����ʱ��
	td_u8	m_cReserved[MAX_RESERVED_INFO_LEN];	//Ԥ����Ϣ����������Զ�����Ϣ	
	td_u32  m_iFileSizeIndex;
	td_u32  m_iSedFileSizeIndex;
	td_u32  m_iChnPickFlag;
}TFileInfo;
typedef struct TQueryResult_S TQueryResult;
struct TQueryResult_S
{
	TFileInfo		m_stFileInfo;
	int				m_iDisk;
	TQueryResult*	m_pstNext;
};
//�ýṹ�����ڲ�ѯִ����
typedef struct
{
	td_u32 		m_uiSocket;								//SOCKET������Ψһ��ʶ˭ִ���������ѯ;0��ʾUI��������ʾ����ͻ���
	char**		m_ppcResult;							//��ѯ�����¼
	TQueryResult*	m_stResult;
	td_s32		m_iColumn;								//��ѯ��������
	td_s32		m_iNum;									//��¼��ѯ���Ľ����
	td_u8		m_blNewestData;							//���ڱ�ʶ�ýڵ��д洢���ǲ������µĲ�ѯ���
	td_s32		m_iStartQueryTime;						//��¼��ѯ��ʼʱ�䣬���ڳ�ʱ�˳�.
	//���¼�¼��ѯ����
	td_u8		m_ucChannelNo;							//ͨ����
	td_u8		m_ucFileType;							//�ļ�����
	td_u8		m_ucRecType;							//¼������
	td_u8		m_ucDevType;							//��ƵԴ�豸����
	time_t		m_iStartTime;							//ʱ�����ʼʱ��
	time_t		m_iStopTime;							//ʱ��ν���ʱ��
	td_u8		m_cReserved[MAX_RESERVED_INFO_LEN];		//Ԥ����Ϣ����������Զ�����Ϣ	
}TQueryNode;

#ifdef TD_DEBUG
#else
#define TODO
#endif
//shihc add 20130320  ����ͨ�õ�dvr�����IDֵ,�������������չ
typedef enum
{
	COMMON_AUDIOVIDEO	= 0x1000,//����Ƶģ�鿪ʼ
	
	COMMON_FONTOVerlAY  = 0x2000,//�ַ�����ģ�鿪ʼ

	COMMON_COMPTZ	    = 0x3000,//����PTZģ�鿪ʼ
	
	COMMON_ABNORMAL     = 0x4000,//ϵͳ�쳣ģ�鿪ʼ
	
	COMMON_ARLAM_MD	    = 0x5000,//����ģ�鿪ʼ//�ƶ�����ʹ��
	COMMON_ARLAM_OD,
	
	COMMON_STORAGE      = 0x6000,//�洢ģ�鿪ʼ	
	COMMON_COMMONENABLE_ONEKEYREC, //һ��¼�� 0-ֹͣ��1-����
	COMMON_COMMONENABLE_HASHENABLE, //��ϣУ�� 0-�����ܣ�1-ʹ��
	COMMON_COMMONENABLE_SPLITAVENABLE, //��ȡ����Ƶ�ļ�0-��ʹ�ܣ�1-ʹ��
	
	COMMON_COMMONENABLE_SPLITAVBURNENABLE, //��¼����Ƶ�ļ�0-��ʹ�ܣ�1-ʹ��
	COMMON_COMMONENABLE_SPLITAVBACKUPENABLE, //���ݿ�¼����Ƶ�ļ�0-��ʹ�ܣ�1-ʹ��
	COMMON_COMMONENABLE_BURNFILEFORMAT = 0x6006, //0-������1-sdv,2-avi, 3-mp4
	

	COMMON_NETSERVICE_SNMP = 0x7000,//�������ģ�鿪ʼ,//SNMP
	COMMON_NETSERVICE_SMTP,//SMTP
	COMMON_NETSERVICE_RTSP_VERIFY,//rtspУ��
	COMMON_NETSERVICE_28181,//28181����Ƶ 

	
	COMMON_USERS        = 0x8000,//�û�ģ�鿪ʼ
	
	COMMON_PUSET	    = 0x9000,//PUģ�鿪ʼ

 
	COMMON_DISK_DISCGROUP= 0xA000,//����ģ�鿪ʼ,//�������
	COMMON_DISK_QUOTA,    //������
	COMMON_RAID,					//RAIDģ�鿪ʼ




	
	COMMON_SYSTEM	    = 0xB000,//ϵͳ����ģ�鿪ʼ
	COMMON_TEMPCTRL,//�����¿ط�ֵ����
	
	COMMON_COMMUNICATION  = 0xC000,//ͨ��ģ�鿪ʼ
	
	COMMON_NETCONNECT	  = 0xD000,//��������ģ�鿪ʼ
	
	COMMON_VCA            = 0xE000,//���ܷ���ģ�鿪ʼ

	COMMON_ATM	          = 0xF000,//ATMģ�鿪ʼ
	
	COMMON_TRAFFIC        = 0x10000,//��ҵ��ͨģ�鿪ʼ
	
	COMMON_DZ	          = 0x11000,//DZ���ģ�鿪ʼ

	COMMON_COMMONENABLE   = 0x12000,//����ͨ��ʹ��ģ�鿪ʼ
	COMMON_COMMONENABLE_GPSTIMING,//GPSУʱ
	COMMON_COMMONENABLE_ALARM,//�豸������ѹ��ֵ
	COMMON_COMMONENABLE_SHUTDOWN,//�豸�ػ���ѹ��ֵ

	COMMON_END            = 0x14000,//������
	

}SYSTEM_SERVICE_COMMON_ID;
//shihc add 20130320  ����ͨ�õ�ϵͳ����IDֵ,�������������չ
typedef enum
{
	LASTERROR_AUDIOVIDEO_CHANGECHNTYPE = 0x1000,//����Ƶģ�鿪ʼ,//�л�ͨ������ʧ��
	
	LASTERROR_FONTOVerlAY     = 0x2000,//�ַ�����ģ�鿪ʼ

	LASTERROR_COMPTZ	      = 0x3000,//����PTZģ�鿪ʼ
	
	LASTERROR_ABNORMAL        = 0x4000,//ϵͳ�쳣ģ�鿪ʼ
	
	LASTERROR_ARLAM	          = 0x5000,//����ģ�鿪ʼ
	   	
	LASTERROR_SETLOCKSTATUS_FAILURE = 0x6000,//�洢ģ�鿪ʼ,	//�����ļ���״̬ʧ��
	LASTERROR_COMMONENABLE_ONEKEYREC,//ͨ��ҵ��洢ģʽ����ʧ��
	LASTERROR_COMMONENABLE_HASHENABLE,//ͨ��ҵ���ϣʹ������ʧ��
	LASTERROR_COMMONENABLE_SPLITAVENABLE, //ͨ��ҵ�����ɴ���Ƶ�ļ�����ʧ��
	
	LASTERROR_COMMONENABLE_SPLITAVBURNENABLE, //��¼����Ƶ�ļ�0-��ʹ�ܣ�1-ʹ��
	LASTERROR_COMMONENABLE_SPLITAVBACKUPENABLE, //���ݿ�¼����Ƶ�ļ�0-��ʹ�ܣ�1-ʹ��
	LASTERROR_COMMONENABLE_BURNFILEFORMAT = 0x6006, //ͨ��ҵ������ʵʱ��¼¼���ļ���ʽʧ��
	
	LASTERROR_NETSERVICE	  = 0x7000,//�������ģ�鿪ʼ
	LASTERROR_SMTP,//smtp����ʧ��
	LASTERROR_RTSP_VERIFY,//rtsp��������ʧ��

	LASTERROR_USERS           = 0x8000,//�û�ģ�鿪ʼ
	
	LASTERROR_PUSET	          = 0x9000,//PUģ�鿪ʼ
	
	LASTERROR_DISK            = 0xA000,//����ģ�鿪ʼ
	LASTERROE_RAID,						//ͨ��ҵ��RAIDģʽ����ʧ��

	LASTERROR_SYSTEM	      = 0xB000,//ϵͳ����ģ�鿪ʼ
	
	LASTERROR_COMMUNICATION   = 0xC000,//ͨ��ģ�鿪ʼ
	
	LASTERROR_NETCONNECT	  = 0xD000,//��������ģ�鿪ʼ
	
	LASTERROR_VCA             = 0xE000,//���ܷ���ģ�鿪ʼ

	LASTERROR_ATM	          = 0xF000,//ATMģ�鿪ʼ
	
	LASTERROR_TRAFFIC         = 0x10000,//��ҵ��ͨģ�鿪ʼ
	
	LASTERROR_DZ	          = 0x11000,//DZ���ģ�鿪ʼ

	LASTERROR_COMMONENABLE_SNMP = 0x12000,//ͨ��ҵ��ʹ��ģ�鿪ʼ	,//SNMPʹ��ʧ��
	LASTERROR_COMMONENABLE_STORAGEMODE,//ͨ��ҵ��洢ģʽ����ʧ��
	LASTERROR_COMMONENABLE_GPSTIMING,//ͨ��ҵ��GPSУʱʹ������ʧ��
	LASTERROR_COMMON_COMMONENABLE_ALARMPOWER,//�����ػ���ѹ��ֵ����ʧ��

	LASTERROR_END             = 0x14000,//������
	

}LASTERROR_ID;


//int td_printf(unsigned int handle, char* pszfmt, ...);
typedef enum
{
	PTZPRI_ALARM  = 0,      //��������
	PTZPRI_VCACAP  ,       //���ܸ���
	PTZPRI_REMOTE,         //Զ�����ȼ�
	PTZPRI_LOCAL,	        //�������ȼ�
	PTZPRI_MAX,	        // ���
}TPTZ_PRIORITY;

//zy 20130926
typedef struct 
{
    td_u32 u32Width;
    td_u32 u32Height;
}TSize;

typedef enum
{
	REC_TAG_ADD  = 0,      //��ӱ�ǩ
	REC_TAG_DEL  ,       //ɾ����ǩ
	REC_TAG_UPDATE,         //�༭��ǩ
	REC_TAG_QUERY,         //�༭��ǩ
}TREC_TAG_OPERATION;

typedef struct
{
   time_t	m_iStartTime;					//ʱ�����ʼʱ��
   time_t	m_iStopTime;					//ʱ��ν���ʱ��
}vca_TimeSegment;

#define MAX_RTMP_LIST_INFO		16					//RTMP�б���Ϣ�����
#define MAX_RTSP_LIST_INFO		64					//RTSP�б���Ϣ�����

#define JMB39X ON

#endif

#ifndef _SYS_NOTIFY_H_
#define _SYS_NOTIFY_H_


typedef enum
{
	IS_ENCODER 	= 0x001,		//�����߳�
	IS_DECODER,					//�����߳�
	IS_HARDWARE,				//Ӳ��
	IS_SYSTEM,					//ϵͳ
	IS_PREVIEW,					//Ԥ��
	IS_CONTECT,					//����20121106 wsl add
	
	IS_SLAVER_CHIP = 0x2001,	// ��Ƭ
} WHO;

typedef enum
{
	GET_SOMETHING_ERROR 	= 0x000,	//ͨ�õĴ���ָʾ
	LOST_HEARTBEAR			= 0x001,	//��ʧ����
	REC_ERROR				= 0x002,	//¼�����
	TIME_CHANGED			= 0x1000,	//ϵͳʱ��ı�	
	REBOOT_SLV				= 0x1001,	//������Ƭ
	REBOOT_SYS				= 0x1002,	//ϵͳ������20120510 dxl
	AUDIO_SAMPLERATE_CHANGE = 0x1003, 	//��Ƶ�����ʸı�	Sherry add 20130110

	CHN_PV_HIDEN			= 0x2000,	//ͨ��Ԥ������
	CHN_PV_RE_MAP_ERR		= 0x2100,	//�ظ����ͨ������
	CHN_NOT_CONTECT			= 0x2200,	//ͨ��ȡ������20121106 wsl add
	CHN_PV_VDEC_LIMIT		= 0x2300,	//����ͨ���������ɹ�

    DB_OVERWRT_ERR          = 0x3000,   //����ɾ��¼���쳣
    DB_OVERWRT_OK           = 0x3001,   //����ɾ��¼��ָ�����
} WHAT;

typedef enum
{
	DO_NOTHING			= 0x000,		//�����κδ���(�Լ��㶨)
	DO_ANYTHING			= 0x001,		//�ϲ������δ���
	DO_SYSTEM_RESET 	= 0x100,		//ϵͳ����
	DO_SELF_RESET		= 0x101,		//ģ������
} HOW;

int SysNotifyInit();
void SysNotifyUninit();

#ifdef MASTER_CHIP
void SysNotify(int _iWho, int _iWhat, int _iHow);
#else
#define SysNotify(_iWho, _iWhat, _iHow)
#endif

int GetSysNotify(int *_piWho, int *_piWhat, int *_iHow);

#endif


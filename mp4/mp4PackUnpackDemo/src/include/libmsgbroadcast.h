#ifndef _MSGBROADCAST_H_
#define _MSGBROADCAST_H_

typedef int  (*MSG_BROADCAST)(char *_cBuf,int _iLen);

enum MSGSNDTYPE
{
	/*��Ƶ������� */
	MSGSND_VIDEOSIZE = 0x00000,		//��Ƶ��С
	MSGSND_VIDEOHEADER,				//��Ƶͷ
	MSGSND_VIDEOMODE,				//��Ƶ��ʽ         1
	MSGSND_FRAMERATE,					//֡��1
	MSGSND_IFRAMERATE,				//I֡���1
	MSGSND_VIDEOQUALITY,				//��Ƶ����1
	MSGSND_VENCTYPE,					//��Ƶ�����ʽ
	MSGSND_ENCODETYPE,				//λ������(������/������)
	MSGSND_BITRATE,					//����kbps
	MSGSND_STREAMTYPE,				//������������1
	MSGSND_AUDIOCODER,				//��Ƶ�����ʽ1
	MSGSND_VIDEOENCRYPT,				//��Ƶ��������1
	CHN_ATTR_VIDEO_LIST,               //��Ƶ�ֱ����б�
	MSGSND_VIDEOPROFILE,
	MSGSND_VIDEO_MODE_CHECK,			//�����Զ������ʽ��־
	MSGSND_AUDIO_SAMPLE,				//������
	MSGSND_AUDIO_SAMPLE_LIST,
	MSGSND_AUDIOCODER_LIST,			// ��Ƶ���뷽ʽ�б�
	//��Ƶ�������
	MSGSND_VIDOEPARA = 0x00050,		//����ɫ�ȱ��ͶȶԱȶ�1
	MSGSND_VIDEOPARA_SCHEDULE,		//����ɫ�ȱ��ͶȶԱȶ�ģ��
	MSGSND_COLORPARA,					//��ת��
	MSGSND_SENSORSPIN,					//��Ƶ��ת

	//OSD���
	MSGSND_OSD_TITLDISPLAY = 0x00100,	//�ַ����� ͨ������ʹ�ܼ�����1
	MSGSND_OSD_TIMEDISPLAY,			//�ַ�����ʱ��ʹ�ܼ�����1
	MSGSND_OSD_WORDDISPLAY,			//�ַ������Զ����ַ� ʹ��1
	MSGSND_OSD_WORDOVERLAY,			//�ַ������Զ����ַ����꼰����1
	MSGSND_OSD_MULTIWORDOVERLAY,			//�ַ������Զ����ַ����꼰����(��չ)
	MSGSND_OSD_LOGDISPLAY,			//�ַ�����LOG1
	
	MSGSND_OSD_TITLCOLOR,			//ͨ��������ɫ1
	MSGSND_OSD_TIMECOLOR,			//ʱ����ɫ1
	MSGSND_OSD_WORDCOLOR,			//�Զ����ַ���ɫ1
	
	MSGSND_OSDLOGOBACKCOLOR,		//log����ɫ
	MSGSND_OSDTEXT,					//ͨ�����Ƶ�������1
	MSGSND_VIDEOCOV,					//��Ƶ�ڵ�����

	MSGSND_MOTION_THRESHOLD,		//��Ƶ�ƶ����������1
	MSGSND_MOTION_AREA,				//��Ƶ�ƶ��������1
	MSGSND_IPCHANPARAM,				//����ͨ��������Ϣ
	MSGSND_PORTALARMTYPE,			//����ͨ��������Ϣ
	MSGSND_IPCPLUGANDDPLAY,			//����ͨ�����弴��
	MSGSND_MD_EN,					//�ƶ�����ʹ��
	MSGSND_OD_EN,					//�ڵ�����ʹ��
    //���ܷ������ nsg add 20120309
	MSGSND_VCA_CFGCHN	= 0x00150,	//���ܷ�����ͨ��ʹ��
	MSGSND_VCA_CFGVIDEO,
	MSGSND_VCA_CFGADV,
	MSGSND_VCA_CFGTARGET,
	MSGSND_VCA_RULESET,
	MSGSND_VCA_RULEEVENT0,
	MSGSND_VCA_RULEEVENT2,
	MSGSND_VCA_RULEEVENT7,
	MSGSND_VCA_RULEEVENT8,
	MSGSND_VCA_RULEEVENT9,
	MSGSND_VCA_RULEEVENT10,
	MSGSND_VCA_RULEEVENT11,//caizhaoxu 20130117
	MSGSND_VCA_RULEEVENT12,
	MSGSND_VCA_RULEEVENT13,
	MSGSND_VCA_RULEEVENT14,
	//ͨ��ҵ��ʹ�����
	MSGSND_COMMON_NETSERVICE_SNMP	= 0x00200,	

};


int msgbroadcast_Init(MSG_BROADCAST _msgsnd);
int msgbroadcast_MsgSnd(int _iChan,int _iMsgId);

//*************************************
int AppChn_MsgSnd(int _iChan,int _iMsgId);
//20130320 wsl add Ϊ�������ص����
//*************************************

#endif



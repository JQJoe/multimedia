/********************************************************
// gui/dvr�������ͨ��Э�鶨��
Create by duxiulong(duxlong@live.cn), 2009
*********************************************************/
#ifndef _GUI_PARAMETER_H_
#define _GUI_PARAMETER_H_

//�������óɹ�ʧ�ܷ�����
#define GUI_SET_OK  0  //���óɹ�
#define GUI_SET_ERR 1  //����ʧ��

#define GUI_SET_DISENABLE   0 //���ò�ʹ��
#define GUI_SET_ENABLE 1      //����ʹ��

#define MAX_CONFIGFILE_LISTNUM 64 //UI ����


//��������ĳ��� (ʹ��ʱ��Ҫ + 1)
#define GUI_PUBLIC_LEN_15	 15
#define GUI_PUBLIC_LEN_31     31
#define GUI_PUBLIC_LEN_63     63
#define GUI_PUBLIC_LEN_127    127
#define GUI_PUBLIC_LEN_255    255


#define GUI_DVR_SCR_COLS			22			//��ĻС������
#define GUI_DVR_SCR_ROWS			18			//��ĻС������

#define GUI_DVR_CHN_CNT			    32			//ͨ������

#define GUI_SERIAL_PORT_CNT			16			//�����ܸ���

#define GUI_PAL_MODE				1			//PAL��
#define GUI_NTSC_MODE				2			//NTSC��
#define GUI_AUTO_MODE               3           //����Ӧ��ʽ

// ��ʾ�豸���
#define GUI_VGA_DEV					0			//VGA���
#define GUI_BNC_DEV					1			//BNC���
#define GUI_BNCA_DEV				2			//BNC���(����)
#define GUI_VC_DEV 					16          //�����豸
#define GUI_HDMI0_DEV				0         //HDMI0�豸
#define GUI_HDMI1_DEV				1		  //HDMI1�豸

//���̱��
#define GUI_NFS_DISK_ID				12			//nfs���̱��
#define GUI_DISK_CD					13			//�������̱�� 
#define GUI_ESATA_DISK_ID			14          //ESATA���̱��
#define GUI_DISK_SEC_CD_ID			15          //�ڶ����������
#define GUI_SD_DISK_ID				50			//SD�����

#define GUI_MIN_SATA_EXTEND_NUM			1008  //��չ������ʼλ��
#define GUI_MAX_SATA_EXTEND_NUM			1015  //��չ���̽���λ��	
#define GUI_VDISK_NUM_BEGIN				2000  //������̿�ʼ	
#define GUI_IPSAN_NUM_BEGIN				3000  //IPSAN��ʼ	
#define GUI_IPSAN_NUM_END					3007
#define GUI_USB_NUM_BEGIN					8
#define GUI_USB_NUM_END					12


// VGA�ֱ���
#define VGA_800x600_60				0
#define VGA_1024x768_60				10
#define VGA_1280x1024_60			20
#define VGA_1440x900_60				30
#define VGA_1366x768_60				40
#define VGA_DEF_SIZE				VGA_1024x768_60
#define VGA_640x480					90
//HDMI
#define HDMI_1280x720_50            100
#define HDMI_1280x720_60            110
#define HDMI_1920x1080_25			120
#define HDMI_1920x1080_30			130
#define HDMI_1920x1080_50           140
#define HDMI_1920x1080_60           150
#define HDMI_1280x800_60            160
#define HDMI_2560x1600_60          170
#define HDMI_3840x2160_30          180 //��ʱû�õ�
#define HDMI_3840x2160_60          190


// ��Ƶ�ֱ���
#define GUI_QCIF 				0		  //P:176��144 N:176��120
#define GUI_HCIF 			    1         //P:352��144 N:352��120
#define GUI_CIF					2		  //P:352��288 N:352��240
#define GUI_2CIF				3		  //P:720��288 N:720��240
#define GUI_D1					4         //P:720��576 N:720��480
#define GUI_MD1					5         //P:720��288 N:720��240
#define GUI_QVGA            	6		  //320��240
#define GUI_FVGA            	7         //640��480
#define GUI_HVGA            	8         //640��240
#define GUI_720P           		9		  //1280��720
#define GUI_960P           		10		  //1280��960
#define GUI_1200           		11		  //1600��1200
#define GUI_1080P          		12        //1920��1080
#define GUI_QXGA				13        //2048��1536
#define GUI_QHD					0x0100    //960��540
#define GUI_960H				0x0200    //P:960��576 N:960��480
#define GUI_4M					0x0210    //2560*1440
#define GUI_4MB					0x0220	//2592*1520
#define GUI_5MA					0x0300    //2448*2048
#define GUI_5M 					0x0400    //2560*1920
#define GUI_5MB					0x0410    //2592*1944
#define GUI_5MC					0x0420    //2592*2048
#define GUI_5MD					0x0430	//2528*2128
#define GUI_QSXGA				0x0500    //2560*2048
#define GUI_6M					0x0600    //2752*2208
#define GUI_6MB					0x0610	//3008*2008
#define GUI_6MC					0x0620    //3408*2008
#define GUI_7M					0x0700	//3392x2008     
#define GUI_8M					0x0800    //3840x2160
#define GUI_8MB					0x0810	//3264x2448
#define GUI_8MC					0x0820	//3296*2472
#define GUI_8MD					0x0830	//4096*2160

//����ģʽ�ֱ��ʸ�ʽ:100000 + N(NΪ���Ϸֱ��ʴ���),�Դ�����
#define GUI_COORIDOR_BASE		0x100000     //����ģʽ��ʼ    
#define GUI_720P_9_16			0x100009    //720x 1280
#define GUI_960P_3_4			0x10000A      //960x1280
#define GUI_1080P_9_16		  	0x10000C	//1080x 1920
#define GUI_QXGA_3_4		  	0x10000D	//1536 x 2048
#define GUI_4M_9_16				0x100210	//1440*2560
#define GUI_4MB_9_16			0x100220	//1520*2592

// ��Ƶ���뷽ʽ
#define GUI_H264			1
#define GUI_MPG4			2
#define GUI_MJPG			3
#define GUI_H265			23     //h265����

//��Ƶ���뷽ʽ
#define GUI_AUDIO_TYPE_G711A	1
#define GUI_AUDIO_TYPE_G711U	2
#define GUI_AUDIO_TYPE_ADPCM	3
#define GUI_AUDIO_TYPE_AAC		22

// ȫ֡Ч(PAL:25 NTSC:30)
#define GUI_FULL_FRAME_RATE		2009
//��Ƶ��������֡��
#define GUI_0_FRAME_RATE     0
#define GUI_1_FRAME_RATE     1
#define GUI_5_FRAME_RATE     5
#define GUI_10_FRAME_RATE    10
#define GUI_15_FRAME_RATE    15
#define GUI_20_FRAME_RATE    20
#define GUI_25_FRAME_RATE    25
#define GUI_30_FRAME_RATE    30
#define GUI_50_FRAME_RATE    50
#define GUI_60_FRAME_RATE    60
#define GUI_MAX_FRAME_RATE   480

#define GUI_NUM_FRAME_RATE   	7  //0, 1, 5, 10, 15, 20, full

#define GUI_CMD_NOP				0			//�ղ���

//���������ػ�������� ��ֵ��g_ptGuiSysStatus->m_iParams[0]����
#define GUI_GET_NET_REBOOT_CMD  20120224 

// �û�����
#define GUI_USER_LOGIN_REQ		1				//�û���¼����
#define GUI_USER_LOGIN_RSP		-1				//�û���¼��Ӧ
#define GUI_USER_LOGOUT_REQ		2			//�û�ע������
#define GUI_USER_LOGOUT_RSP		-2			//�û�ע����Ӧ
#define GUI_ADD_USER_REQ		3			//����û�����
#define GUI_ADD_USER_RSP		-3			//����û���Ӧ
#define GUI_RM_USER_REQ			4			//ɾ���û�����
#define GUI_RM_USER_RSP			-4				//ɾ���û���Ӧ
#define GUI_EDIT_USER_REQ		5			//�޸��û���������
#define GUI_EDIT_USER_RSP		-5			//�޸��û����ϻ�Ӧ
#define GUI_GET_USER_MSG_REQ	6			//��ȡ�û���������
#define GUI_GET_USER_MSG_RSP	-6			//��ȡ�û����ϻ�Ӧ
#define GUI_GET_USER_GROUP_REQ	7			//��ȡ�û����б�����
#define GUI_GET_USER_GROUP_RSP	-7				//��ȡ�û����б��Ӧ
#define GUI_GET_USER_LIST_REQ	8			//��ȡ�û��б�����
#define GUI_GET_USER_LIST_RSP	-8			//��ȡ�û��б��Ӧ
#define GUI_GET_USER_LIST_REQ_EX	 9			//��ȡ�û��б�������չ
#define GUI_GET_USER_LIST_RSP_EX	-9			//��ȡ�û��б��Ӧ��չ

//UI������Ϣ
#define GUI_START_UP_MSG		10			//UI������Ϣ
#define GUI_START_UP_RSP		-10			//UI������Ϣ��Ӧ

//����VGA��ʽ
#define GUI_SET_VGA_MOD_REQ		11			//����VGA��ʽ����
#define GUI_SET_VGA_MOD_RSP		-11			//����VGA��ʽ��Ӧ

//����BNC��ʽ
#define GUI_SET_BNC_MOD_REQ		12
#define GUI_SET_BNC_MOD_RSP		-12


//------------------------------ϵͳ����---------------------------------
// 1.���̹���
#define GUI_GET_DISK_LIST_REQ	50			//��ȡ�����б�����
#define GUI_GET_DISK_LIST_RSP	-50			//��ȡӲ���б��Ӧ
#define GUI_FORMAT_DISK_REQ		51			//��ʽ����������
#define GUI_FORMAT_DISK_RSP		-51			//��ʽ�����̻�Ӧ
#define GUI_GET_FORMAT_STAT_REQ	52			//��ȡ���̸�ʽ��״̬����
#define GUI_GET_FORMAT_STAT_RSP	-52			//��ȡ���̸�ʽ��״̬��Ӧ
#define GUI_DISK_PART_REQ		53			//Ӳ�̷�������
#define GUI_DISK_PART_RSP		-53			//���̷�����Ӧ
#define GUI_GET_DISK_MSG_REQ	54			//��ȡ������Ϣ����
#define GUI_GET_DISK_MSG_RSP	-54			//��ȡ������Ϣ��Ӧ
#define GUI_SET_DISK_MSG_REQ	55			//���ô�����Ϣ����
#define GUI_SET_DISK_MSG_RSP	-55			//��ī������Ϣ��Ӧ
// 2.��������
#define GUI_GET_SPORT_MSG_REQ		60			//��ȡ������������
#define GUI_GET_SPORT_MSG_RSP		-60			//��ȡ�������û�Ӧ
#define GUI_SET_SPORT_MSG_REQ		61			//���ô�����������
#define GUI_SET_SPORT_MSG_RSP		-61			//���ô������û�Ӧ

// 3.ϵͳ��Ϣ
#define GUI_GET_SYS_MSG_REQ		70			//��ȡϵͳ��Ϣ����
#define GUI_GET_SYS_MSG_RSP		-70			//��ȡϵͳ��Ϣ��Ӧ
#define GUI_SET_SYS_MSG_REQ		71			//����ϵͳ��Ϣ����
#define GUI_SET_SYS_MSG_RSP		-71			//����ϵͳ��Ϣ��Ӧ
#define GUI_CHG_SYS_TIME_MSG		72			//ϵͳʱ�����֪ͨ


// 5.ϵͳ����
#define GUI_SYS_UPDATE_STA_REQ		91			//ϵͳ����״̬��ѯ����
#define GUI_SYS_UPDATE_STA_RSP		-91			//ϵͳ����״̬��ѯ��Ӧ
#define GUI_SYS_FILE_UPDATE_REQ	92			//ϵͳ�ļ���������
#define GUI_SYS_FILE_UPDATE_RSP	-92			//ϵͳ�ļ�������Ӧ
#define GUI_SYS_FTP_UPDATE_REQ		93			//ϵͳFTP��������
#define GUI_SYS_FTP_UPDATE_RSP		-93			//ϵͳFTP������Ӧ
#define GUI_SYS_FILE_UPDATE_NUM_REQ	94		//ϵͳ�ļ�����
#define GUI_SYS_FILE_UPDATE_NUM_RSP	-94		//ϵͳ�ļ���Ӧ
#define GUI_SYS_UPDATE_SUCCESS 	0
#define GUI_SYS_UPDATE_FAIL    		1


// 6.�ָ���������
#define GUI_SET_RENEW_REQ			100		//ϵͳ������������
#define GUI_SET_RENEW_RSP			-100		//ϵͳ���������Ӧ

// 7.��������
#define GUI_GET_IP_REQ				110		//��ȡIP��������
#define GUI_GET_IP_RSP				-110		//��ȡIP������Ӧ
#define GUI_SET_IP_REQ				111		//����IP��������
#define GUI_SET_IP_RSP				-111		//����IP������Ӧ
#define GUI_GET_NET_CNF_REQ		112		//��ȡ���������������
#define GUI_GET_NET_CNF_RSP		-112		//��ȡ����������û�Ӧ
#define GUI_SET_NET_CNF_REQ		113		//�������������������
#define GUI_SET_NET_CNF_RSP			-113		//��������������û�Ӧ
#define GUI_GET_REG_CNF_REQ		114		//��ȡע��������Ϣ����
#define GUI_GET_REG_CNF_RSP		-114		//��ȡע��������Ϣ��Ӧ
#define GUI_SET_REG_CNF_REQ		115		//����ע��������Ϣ����
#define GUI_SET_REG_CNF_RSP		-115		//����ע��������Ϣ��Ӧ
#define GUI_GET_DDNS_REQ			130     	 //DDNS����
#define GUI_GET_DDNS_RSP 			-130      	//DDNS�����Ӧ
#define GUI_SET_DDNS_REQ			131  		//��dvr�����й�DDNS�����ò���
#define GUI_SET_DDNS_RSP			-131   	//��dvr�����й�DDNS�����ò�����Ӧ
#define GUI_GET_NTP_REQ				132      	//NTP����
#define GUI_GET_NTP_RSP				-132      //NTP�����Ӧ
#define GUI_SET_NTP_REQ				133   	//��dvr�����й�NPT�����ò���
#define GUI_SET_NTP_RSP				-133 	//dvr��Ӧ
#define GUI_CONNECT_OVER_PPPOE_STAT_REQ 	134        //��ȡPPPoE״̬����
#define GUI_CONNECT_OVER_PPPOE_STAT_RSP	-134		//��Ӧ
#define GUI_CONNECT_OVER_PPPOE_REQ     	135       // PPPoE��������
#define GUI_CONNECT_OVER_PPPOE_RSP 	-135       //PPPoE���ӻ�Ӧ
#define GUI_CUT_CONNECT_OVER_PPPOE_REQ 136     // �Ͽ�PPPoE����
#define GUI_CUT_CONNECT_OVER_PPPOE_RSP -136   // �Ͽ�PPPoE���ӻ�Ӧ
#define GUI_SET_PPPOE_REQ 		137                      //����PPPOE��������
#define GUI_SET_PPPOE_RSP 		-137                     //��Ӧ

// 8.�쳣����
#define GUI_GET_EXCEP_CNF_REQ		120		//��ȡ�쳣�����������
#define GUI_GET_EXCEP_CNF_RSP		-120		//��ȡ�쳣���������Ӧ
#define GUI_SET_EXCEP_CNF_REQ		121		//�����쳣�����������
#define GUI_SET_EXCEP_CNF_RSP		-121		//�����쳣���������Ӧ

//9.��������
#define GUI_GET_CHN_ALIAS_REQ		140      	//��ȡͨ����������
#define GUI_GET_CHN_ALIAS_RSP		-140
#define GUI_SET_CHN_ALIAS_REQ 		141     	 //ͨ������
#define GUI_SET_CHN_ALIAS_RSP		-141  	//ͨ�����û�Ӧ
#define GUI_GET_CHN_ALIAS_VER_REQ	142		//��ȡͨ�������汾����
#define GUI_GET_CHN_ALIAS_VER_RSP	-142		//��ȡͨ�������汾��Ӧ


//------------------------------ͼ������---------------------------------
// 1.Ԥ������
#define GUI_GET_PREVIEW_REQ		200			//��ȡԤ����������
#define GUI_GET_PREVIEW_RSP		-200		//��ȡԤ��������Ӧ
#define GUI_SET_PREVIEW_REQ		201			//����Ԥ����������
#define GUI_SET_PREVIEW_RSP		-201		//����Ԥ��������Ӧ
#define GUI_PREVIEW_SW_START_REQ	204			//Ԥ���л���ʼ����
#define GUI_PREVIEW_SW_START_RSP	-204		//Ԥ���л���ʼ��Ӧ
#define GUI_PREVIEW_SW_STOP_REQ	205			//Ԥ���л���ͣ����
#define GUI_PREVIEW_SW_STOP_RSP	-205		//Ԥ���л���ͣ��Ӧ
#define GUI_PREVIEW_SINGLE_PIC	206			//������(��GUI_PREVIEW_SPIC_REQͬ)
#define GUI_PREVIEW_SPIC_REQ		206			//������
#define GUI_PREVIEW_SPIC_RSP		-206		//�������Ӧ
#define GUI_PREVIEW_SPIC_EXIT_MSG	251		//�������˳���Ϣ

// 1.1 ��������
#define GUI_SND_DEC_MSG			253			//��������Ϣ
#define GUI_SND_ASC_MSG			254			//��������Ϣ
#define GUI_VOL_CTR_REQ			255			//������������(��Ƶ����)
#define GUI_VOL_CTR_RSP				-255	

// 2.������ʾ
#define GUI_GET_DISPLAY_CNF_REQ	210			//��ȡ������ʾ��������
#define GUI_GET_DISPLAY_CNF_RSP	-210		//��ȡ������ʾ���Ի�Ӧ
#define GUI_SET_DISPLAY_CNF_REQ	211			//���ñ�����ʾ��������
#define GUI_SET_DISPLAY_CNF_RSP	-211		//���ñ�����ʾ���Ի�Ӧ


// 3.��Ƶ�������
#define GUI_GET_VIDEOIN_CNF_REQ	220			//��ȡ��Ƶ�����������
#define GUI_GET_VIDEOIN_CNF_RSP	-220		//��ȡ��Ƶ���������Ӧ
#define GUI_SET_VIDEOIN_CNF_REQ	221			//������Ƶ�����������
#define GUI_SET_VIDEOIN_CNF_RSP	-221		//������Ƶ���������Ӧ
#define GUI_CHG_VIDEOIN_CNF_REQ	222			//(��ʱ)������Ƶ�����������
#define GUI_CHG_VIDEOIN_CNF_RSP	-222		//(��ʱ)������Ƶ���������Ӧ
#define GUI_GET_VIDEOIN_NOR_REQ	223			//��ȡͨ����Ƶ������ʽ����	//2009/12/22
#define GUI_GET_VIDEOIN_NOR_RSP	-223		//��ȡͨ����Ƶ������ʽ��Ӧ
#define GUI_SET_VIDEOIN_NOR_REQ	224
#define GUI_SET_VIDEOIN_NOR_RSP	-224

#define GUI_GET_VIDEOIN_MOD_AUTO_CHK_REQ 225	//��ȡ��Ƶ��ʽ�Զ��������
#define GUI_GET_VIDEOIN_MOD_AUTO_CHK_RSP -225	//��ȡ��Ƶ��ʽ�Զ�����Ӧ
#define GUI_SET_VIDEOIN_MOD_AUTO_CHK_REQ 226	//������Ƶ��ʽ�Զ��������
#define GUI_SET_VIDEOIN_MOD_AUTO_CHK_RSP -226	//������Ƶ��ʽ�Զ�����Ӧ


// 5.��Ƶǰ�˵���
#define GUI_GET_VOVERLAY_CNF_REQ	240			//��ȡ��Ƶǰ�˵��Ӳ�������
#define GUI_GET_VOVERLAY_CNF_RSP	-240		//��ȡ��Ƶǰ�˵��Ӳ�����Ӧ
#define GUI_SET_VOVERLAY_CNF_REQ	241			//������Ƶǰ�˵��Ӳ�������
#define GUI_SET_VOVERLAY_CNF_RSP	-241		//������Ƶǰ�˵��Ӳ�����Ӧ
#define GUI_CHG_LOGO_BMP_REQ		242			//����logoͼ������
#define GUI_CHG_LOGO_BMP_RSP		-242		//����logoͼ���Ӧ
//----------------------��Ƶ������������----------------------------
//��Ƶ��������
#define GUI_GET_VIDEOPARA_CNF_REQ 232       //��ȡ��Ƶ������������
#define GUI_GET_VIDEOPARA_CNF_RSP -232     //��ȡ��Ƶ�������û�Ӧ
#define GUI_SET_VIDEOPARA_CNF_REQ 233	   //������Ƶ������������
#define GUI_SET_VIDEOPARA_CNF_RSP -233     //������Ƶ�������û�Ӧ
//��Ƶ�ܱ�����������
#define GUI_GET_TOTALCODE_CNF_REQ 234      //��ȡ��Ƶ�����������ܵı�����������
#define GUI_GET_TOTALCODE_CNF_RSP -234     //��ȡ��Ƶ�����������ܵı���������Ӧ


//------------------------------¼������---------------------------------
// 1.¼��ģ��
#define GUI_GET_VR_TEMPLATE_REQ	300			//��ȡ¼��ģ������
#define GUI_GET_VR_TEMPLATE_RSP	-300		//��ȡ¼��ģ���Ӧ
#define GUI_SET_VR_TEMPLATE_REQ	301			//����¼��ģ������
#define GUI_SET_VR_TEMPLATE_RSP	-301		//����¼��ģ���Ӧ

// 2.¼�����
#define GUI_GET_VR_STRATEGY_REQ	310			//��ȡ¼���������
#define GUI_GET_VR_STRATEGY_RSP	-310		//��ȡ¼����Ի�Ӧ
#define GUI_SET_VR_STRATEGY_REQ	311			//����¼���������
#define GUI_SET_VR_STRATEGY_RSP	-311		//����¼����Ի�Ӧ

// 3.¼���ļ�
#define GUI_COUNT_VIDEO_FILE_REQ	320			//ͳ��¼���ļ���������
#define GUI_COUNT_VIDEO_FILE_RSP	-320		//ͳ��¼���ļ�������Ӧ
#define GUI_BACKUP_VIDEO_FILE_REQ	322		//����¼���ļ�����
#define GUI_BACKUP_VIDEO_FILE_RSP	-322	//����¼���ļ���Ӧ
#define GUI_DEL_VIDEO_FILE_REQ	323			//ɾ��¼���ļ�����
#define GUI_DEL_VIDEO_FILE_RSP	-323		//ɾ��¼���ļ���Ӧ
#define GUI_BACKUP_TODAY_VIDEO_REQ	324		//���ݵ���¼���ļ�����
#define GUI_BACKUP_TODAY_VIDEO_RSP	-324	//���ݵ���¼���ļ���Ӧ	
#define GUI_QUERY_VIDEO_END_MSG		325		//¼���ļ���ѯ����
#define GUI_GET_VIDEO_FILE_MAP_REQ	326		//��ȡ¼���ļ���������(һ������Щ����¼��)
#define GUI_GET_VIDEO_FILE_MAP_RSP	-326	//��ȡ¼���ļ����ջ�Ӧ


// ץ��ͼƬ
#define GUI_COUNT_SNATCH_PIC_REQ	327			//ͳ��ץ��ͼƬ��������
#define GUI_COUNT_SNATCH_PIC_RSP	-327		//ͳ��ץ��ͼƬ������Ӧ
#define GUI_QUERY_SNATCH_PIC_REQ	328			//��ѯץ��ͼƬ����
#define GUI_QUERY_SNATCH_PIC_RSP	-328		//��ѯץ��ͼƬ��Ӧ
#define GUI_DEL_SNATCH_PIC_REQ	329				//ɾ��ץ��ͼƬ����
#define GUI_DEL_SNATCH_PIC_RSP	-329			//ɾ��ץ��ͼƬ��Ӧ
//ͼƬ����
#define GUI_BACKUP_PIC_REQ		1300	      //����ͼƬ����
#define GUI_BACKUP_PIC_RSP			-1300		//����ͼƬ��Ӧ


// 4.¼��ط�
#define GUI_PLAY_VIDEO_START_REQ	330			//����¼���ļ�����
#define GUI_PLAY_VIDEO_START_RSP	-330		//����¼���ļ���Ӧ
#define GUI_PLAY_VIDEO_PAUSE_REQ	331			//������ͣ����
#define GUI_PLAY_VIDEO_PAUSE_RSP	-331		//������ͣ��Ӧ
#define GUI_PLAY_VIDEO_CONT_REQ		332			//���ż�������
#define GUI_PLAY_VIDEO_CONT_RSP		-332		//���ż�����Ӧ
#define GUI_PLAY_VIDEO_STOP_REQ		333			//����ֹͣ����
#define GUI_PLAY_VIDEO_STOP_RSP		-333		//����ֹͣ��Ӧ
#define GUI_PLAY_VIDEO_SPEEDX_REQ	334		//N���ٶȲ�������
#define GUI_PLAY_VIDEO_SPEEDX_RSP	-334	//N���ٶȲ��Ż�Ӧ
#define GUI_PLAY_VIDEO_SPEED_CMD	336		//���ÿ��/���ű�������
#define GUI_PLAY_VIDEO_BY_STEP_REQ	335		//������������
//#define GUI_PLAY_VIDEO_BY_STEP_RSP	-335	//�������Ż�Ӧ
//#define GUI_PLAY_VIDEO_NEXT_FRM_REQ	336		//ǰ��һ֡����
//#define GUI_PLAY_VIDEO_PRE_FRM_REQ	337		//���һ֡����
#define GUI_PLAY_VIDEO_LOC_REQ	338			//���Ŷ�λ����
//#define GUI_PLAY_VIDEO_LOC_RSP	-338		//���Ŷ�λ��Ӧ
#define GUI_GET_VPLAY_STA_REQ		339			//����¼���ļ�����״̬
#define GUI_GET_VPLAT_STA_RSP		-339		//��Ӧ¼���ļ�����״̬
#define GUI_GET_VPLAY_STA_RSP		GUI_GET_VPLAT_STA_RSP
//#define GUI_PLAY_VIDEO_RESIZE_REQ	340		//���Ŵ��������С����
//#define GUI_PLAY_VIDEO_RESIZE_RSP	-340	//���Ŵ��������С��Ӧ
#define GUI_VIDEO_PLAYER_ACTIVE_MSG		341		//����������֪ͨ(��ʼ��VO�������浱ǰԤ��״̬)
#define GUI_VIDEO_PLAYER_ACTIVE_REQ		GUI_VIDEO_PLAYER_ACTIVE_MSG
#define GUI_VIDEO_PLAYER_ACTIVE_RSP		-341	//�����������Ӧ
#define GUI_VIDEO_PLAYER_EXIT_MSG		342		//�������˳�֪ͨ(Ӧ��ֹͣ��ǰ�طţ�ǰ�ָ���ǰ�����Ԥ��״̬)
#define GUI_VPLAY_FULL_SCR_REQ			343		//ָ������ȫ����������
#define GUI_VPLAY_FULL_SCR_RSP			-343	//ָ������ȫ�����Ż�Ӧ
#define GUI_VPLAY_FULL_SCR_EXIT_REQ		344		//ȫ�������˳�����
#define GUI_VPLAY_FULL_SCR_EXIT_RSP		-344	//ȫ�������˳���Ӧ
#define GUI_VPLAY_SET_SND_REQ			355		//�ط�������������
#define GUI_VPLAY_SET_SND_RSP			-355	//�ط��������û�Ӧ

#define GUI_GET_VPLAY_MARK_MSG_REQ      358    //��ȡ¼���ļ��Ĵ����Ϣ����
#define GUI_GET_VPLAY_MARK_MSG_RSP      -358   //��ȡ¼���ļ��Ĵ����Ϣ��Ӧ

#define GUI_SYNC_PLAY_VIDEO_FILE_REQ 		370		//ͬ�����󲥷��ļ�
#define GUI_SYNC_PLAY_VIDEO_FILE_RSP  		-370		//ͬ�������ļ������Ӧ
#define GUI_SYNC_PLAY_VIDEO_NOFILE 			371		//ͬ���طż���
#define GUI_SYNC_PLAY_VIDEO_PAUSE_REQ 		372 		//ͬ���ط���ͣ
#define GUI_SYNC_PLAY_VIDEO_FILE_STOP_REQ 373 	//ͬ��ֹͣ����
#define GUI_SYNC_PLAY_VIDEO_FILE_STEP_REQ 374 	//ͬ����������
#define GUI_SYNC_VPLAY_SET_SND_REQ 375       		//ͬ��������������
#define GUI_SYNC_VPLAY_SET_SND_RSP -375        	//ͬ���������û�Ӧ
#define GUI_VIDEO_PLAYER_COORDIRATE_REQ 376	//��������,��������ʼ������
#define GUI_VIDEO_PLAYER_COORDIRATE_RSP -376	//��������ʼ�������Ӧ
#define GUI_SYNC_PLAY_VIDEO_LOC_REQ		377	//ͬ�����Ŷ�λ����
#define GUI_SYNC_GET_VPLAY_STA_REQ		378	//����¼���ļ�����״̬
#define GUI_SYNC_GET_VPLAY_STA_RSP		-378	//��Ӧ¼���ļ�����״̬
#define GUI_SYNC_VIDEO_PLAYER_EXIT_MSG	379		//�������˳�֪ͨ(Ӧ��ֹͣ��ǰ�طţ�ǰ�ָ���ǰ�����Ԥ��״̬)
#define GUI_SYNC_VPLAY_FULL_SCR_REQ		380		//ָ������ȫ����������
#define GUI_SYNC_VPLAY_FULL_SCR_RSP		-380		//ָ������ȫ�����Ż�Ӧ
#define GUI_SYNC_PLAY_VIDEO_SPEEDX_REQ	381		//N���ٶȲ�������
#define GUI_SYNC_VPLAY_FULL_SCR_EXIT_REQ	382		//ȫ�������˳�����
#define GUI_SYNC_VPLAY_FULL_SCR_EXIT_RSP    -382    //ȫ�������˳������Ӧ
#define GUI_SYNC_SND_DEC_MSG              		383       //ͬ������������
#define GUI_SYNC_SND_ASC_MSG              		384        //ͬ������������
#define GUI_SYNC_PLAY_VIDEO_SPEED_CMD		385		//ͬ�����ÿ��/���ű�������

// ��Ƶ����
#define GUI_VDECODE_PWD_SET_REQ    386    //��Ƶ����������������
#define GUI_VDECODE_PWD_SET_RSP    -386    //��Ƶ�������������Ӧ

// ��Ƶ����
#define GUI_VENCODE_PWD_SET_REQ	387 //������Ƶ��������
#define GUI_VENCODE_PWD_SET_RSP	-387//������Ƶ���ܻ�Ӧ	
#define GUI_VENCODE_PWD_GET_REQ	388 //��ȡ��Ƶ��������
#define GUI_VENCODE_PWD_GET_RSP	-388//��ȡ��Ƶ���ܻ�Ӧ

// 5.�ֶ�¼��
#define GUI_HUM_REC_VIDEO_CMD			350		//�ֶ�¼������
#define GUI_REC_VIDEO_REQ				351		//ͨ��¼������
#define GUI_REC_VIDEO_RSP				-351	//ͨ��¼���Ӧ

// 6.�ؽ�����
#define GUI_REBUILD_INDEX_REQ			356		//�ؽ���������
#define GUI_REBUILD_INDEX_RSP			-356	//�ؽ�������Ӧ
#define GUI_REBUILD_INDEX_STA_REQ	357		//��ȡ�ؽ�����״̬����
#define GUI_REBUILD_INDEX_STA_RSP	-357	//��ȡ�ؽ�����״̬��Ӧ

// ץ�����
#define GUI_JPEG_VIEWER_INIT_REQ		360		//JPEG��ʾ��ʼ������
#define GUI_JPEG_VIEWER_INIT_RSP		-360		//JPEG��ʾ��ʼ����Ӧ
#define GUI_JPEG_VIEWER_EXIT_MSG		361		//JPEG��ʾ�˳���Ϣ
#define GUI_JPEG_DSP_REQ				362		//JPEG��ʾ����
#define GUI_JPEG_DSP_RSP				-362		//JPEG��ʾ��Ӧ



//------------------------------��̨����---------------------------------
// ����������
#define GUI_GET_PTZ_DECODE_CNF_REQ	400		//��ȡ��������������
#define GUI_GET_PTZ_DECODE_CNF_RSP	-400	//��ȡ������������Ӧ
#define GUI_SET_PTZ_DECODE_CNF_REQ	401		//���ý�������������
#define GUI_SET_PTZ_DECODE_CNF_RSP	-401	//���ý�����������Ӧ

// ��̨����
#define GUI_GET_PTZ_PRESETPOINT_REQ	405		//��ȡԤ�õ��б�����
#define GUI_GET_PTZ_PRESETPOINT_RSP	-405	//��ȡԤ�õ��б��Ӧ
#define GUI_ADD_PTZ_PRESETPOINT_REQ	406		//�����Ԥ�õ�����
#define GUI_ADD_PTZ_PRESETPOINT_RSP	-406	//�����Ԥ�õ��Ӧ
#define GUI_DEL_PTZ_PRESETPOINT_REQ	407		//ɾ��Ԥ�õ�����
#define GUI_DEL_PTZ_PRESETPOINT_RSP	-407	//ɾ��Ԥ�õ��Ӧ
#define GUI_TRN_PTZ_PRESETPOINT_REQ	408		//����Ԥ�õ�����
#define GUI_TRN_PTZ_PRESETPOINT_RSP	-408	//����Ԥ�õ��Ӧ
#define GUI_GET_PTZ_CRUISROUTE_REQ	409		//��ȡѲ��·������
#define GUI_GET_PTZ_CRUISROUTE_RSP	-409	//��ȡѲ��·����Ӧ
#define GUI_SET_PTZ_CRUISROUTE_REQ	410		//����Ѳ��·������
#define GUI_SET_PTZ_CRUISROUTE_RSP	-410	//����Ѳ��·����Ӧ

#define GUI_PTZ_LOCAL_CODE			411		//����(UI)���ɵ���̨������
#define GUI_PTZ_REMOTE_CODE			412		//Զ��(�������)���ɵ���̨����	

#define GUI_PTZ_TRACK_START_REQ		415		//��ʼ��¼�켣����
#define GUI_PTZ_TRACK_START_RSP		-415	//��ʼ��¼�켣��Ӧ
#define GUI_PTZ_TRACK_END_REQ			416		//������¼�켣����
#define GUI_PTZ_TRACK_END_RSP			-416	//������¼�켣��Ӧ
#define GUI_PTZ_TRACK_PLAY_START_REQ	417		//��ʼ���Ź켣����
#define GUI_PTZ_TRACK_PLAY_START_RSP	-417	//��ʼ���Ź켣��Ӧ
#define GUI_PTZ_TRACK_PLAY_END_REQ	418		//�������Ź켣����
#define GUI_PTZ_TRACK_PLAY_END_RSP	-418	//�������Ź켣��Ӧ

#define GUI_PTZ_PATH_PLAY_REQ			419		//��ʾ·������
#define GUI_PTZ_PATH_PLAY_RSP			-419	//��ʾ·����Ӧ

#define GUI_PTZ_3D_MSG					420		// 3d��λ

#define GUI_GET_PROTOCOL_DECODE_CNT_REQ	421		//��ȡЭ������
#define GUI_GET_PROTOCOL_DECODE_CNT_RSP	-421		//��ȡЭ������
#define GUI_GET_PROTOCOL_DEL_REQ			422		//ɾ��Э������
#define GUI_GET_PROTOCOL_DEL_RSP			-422		//ɾ��Э���Ӧ



//------------------------------��������---------------------------------
// ��������
#define GUI_GET_ALARM_IN_CNF_REQ		500		//��ȡ���������������
#define GUI_GET_ALARM_IN_CNF_RSP		-500	//��ȡ�������������Ӧ
#define GUI_SET_ALARM_IN_CNF_REQ		501		//���ñ��������������
#define GUI_SET_ALARM_IN_CNF_RSP		-501	//���ñ������������Ӧ

#define GUI_GET_ALARM_OUT_CNF_REQ	510		//��ȡ���������������
#define GUI_GET_ALARM_OUT_CNF_RSP	-510	//��ȡ�������������Ӧ
#define GUI_SET_ALARM_OUT_CNF_REQ	511		//���ñ��������������
#define GUI_SET_ALARM_OUT_CNF_RSP	-511	//���ñ������������Ӧ

#define GUI_GET_MD_ALARM_CNF_REQ		520		//��ȡ�ƶ���ⱨ����������
#define GUI_GET_MD_ALARM_CNF_RSP		-520	//��ȡ�ƶ���ⱨ��������Ӧ
#define GUI_SET_MD_ALARM_CNF_REQ		521		//�����ƶ���ⱨ����������
#define GUI_SET_MD_ALARM_CNF_RSP		-521	//�����ƶ���ⱨ��������Ӧ

#define GUI_GET_VL_ALARM_CNF_REQ		530		//��ȡ��Ƶ��ʧ������������
#define GUI_GET_VL_ALARM_CNF_RSP		-530	//��ȡ��Ƶ��ʧ����������Ӧ
#define GUI_SET_VL_ALARM_CNF_REQ		531		//������Ƶ��ʧ������������
#define GUI_SET_VL_ALARM_CNF_RSP		-531	//������Ƶ��ʧ����������Ӧ

#define GUI_CLEAR_ALARM_CMD			540		//������������


// ע��
#define GUI_SYS_RESET_REQ				600		//ϵͳ��������
#define GUI_SYS_RESET_RSP				-600	//ϵͳ������Ӧ
#define GUI_SYS_POWEROFF_REQ			601		//�ػ�����
#define GUI_SYS_POWEROFF_RSP			-601	//�ػ���Ӧ
#define GUI_EXIT_MSG					602		//UI(���)�˳���Ϣ

// ���ӷŴ�
#define GUI_EZOOM_ENTER_REQ			700		//������ӷŴ�������
#define GUI_EZOOM_ENTER_RSP			-700	//������ӷŴ��ܻ�Ӧ
#define GUI_EZOOM_EXIT_REQ			701		//�˳����ӷŴ�������
#define GUI_EZOOM_EXIT_RSP			-701	//�˳����ӷŴ�������
#define GUI_EZOOM_SET_ATTR_REQ		702		//���õ��ӷŴ��������(����ͨ����Ŵ�����)
#define GUI_EZOOM_SET_ATTR_RSP		-702	//���õ��ӷŴ������Ӧ


// ���̿�¼
#define GUI_CD_BACKUP_START_REQ		720	//��¼��ʼ֪ͨ
#define GUI_CD_BACKUP_START_RSP		-720
#define GUI_CD_BACKUP_FILE_REQ			721 	//���Ϳ�¼�ļ��б�
#define GUI_CD_BACKUP_FILE_RSP			-721
#define GUI_CD_BACKUP_EXEC_REQ		722	//��¼ִ������
#define GUI_CD_BACKUP_EXEC_RSP		-722
#define GUI_CD_BACKUP_PRG_REQ			723	//��¼��������
#define GUI_CD_BACKUP_PRG_RSP			-723

// ʵʱ��¼		20100913 dxl
#define GUI_CBL_TAG_REQ					728	//��¼�������
#define GUI_CBL_TAG_RSP					-728	//��¼�������
#define GUI_CBL_FORCE_END_REQ            729     //ǿ����ֹ��¼����
#define GUI_CBL_FORCE_END_RSP            -729    //ǿ����ֹ��¼�����Ӧ

//ͨ������
#define GUI_GET_CHN_TYPE_REQ         		  800   //��ȡͨ����������
#define GUI_GET_CHN_TYPE_RSP           		 -800  //��ȡͨ�����ͻ�Ӧ
#define GUI_GET_LOCAL_CHN_ATTR_REQ 	 		  801   //��ȡ����ģ��ͨ����������
#define GUI_GET_LOCAL_CHN_ATTR_RSP	 		-801  //��ȡ����ģ��ͨ�����Ի�Ӧ
#define GUI_GET_VC_CHN_ATTR_REQ				  802  //��ȡ�ϳ�ͨ����������
#define GUI_GET_VC_CHN_ATTR_RSP 				-802  //��ȡ�ϳ�ͨ�����Ի�Ӧ
#define GUI_SET_CHN_TYPE_REQ                   803   //����ͨ����������
#define GUI_SET_CHN_TYPE_RSP                   -803  //����ͨ�����ͻ�Ӧ
#define GUI_GET_CHN_TYPE_EDIT_ABLE_FLG_REQ     804   //��ȡͨ���ɱ༭��������
#define GUI_GET_CHN_TYPE_EDIT_ABLE_FLG_RSP     -804  //��ȡͨ���ɱ༭���ͻ�Ӧ

#define GUI_SYSTEM_EXIT			1000		//ϵͳ�˳�֪ͨ

// ��Ϣ
#define GUI_KEY_TX					5000		//ң��������
#define GUI_KEY_NET_TX				5001		//�������

// ��������
#define GUI_STREAM_CONNECT_REQ		2001
#define GUI_STREAM_CONNECT_RSP		-2001
#define GUI_STREAM_DISCONNECT_REQ		2002
#define GUI_STREAM_DISCONNECT_RSP		-2002
#define GUI_FORCE_IFRAME_REQ			2003
#define GUI_FORCE_IFRAME_RSP			-2003

/********************************************************************************/
//***********************************��������******************************//
#define GUI_GET_NET_ALARMER_CNF_REQ     	100010	//��ȡ���籨��������������
#define GUI_GET_NET_ALARMER_CNF_RSP    	   -100010	//��ȡ���籨���������û�Ӧ
#define GUI_SET_NET_ALARMER_CNF_REQ			100011	//�������籨��������������
#define GUI_SET_NET_ALARMER_CNF_RSP		   -100011	//�������籨���������û�Ӧ

#define GUI_GET_SERIAL_ALARMER_CNF_REQ		100012	//��ȡ���ڱ���������������
#define GUI_GET_SERIAL_ALARMER_CNF_RSP		-100012	//��ȡ���ڱ����������û�Ӧ
#define GUI_SET_SERIAL_ALARMER_CNF_REQ      100013	//���ô��ڱ���������������
#define GUI_SET_SERIAL_ALARMER_CNF_RSP      -100013	//���ô��ڱ����������û�Ӧ


//������������л�֪ͨ
#define GUI_SET_CHANGE_LANG_REQ                100100  //���������л�����
#define GUI_SET_CHANGE_LANG_RSP                -100100  //���������л���Ӧ



// ��׼Э���
typedef struct
{
	int m_iCmd;									//������
	int m_iLength;								//pdu���س���
	char m_cPayload[0];						//ʵ������
} TGuiParamPdu;								//���ݴ��䵥Ԫ�ṹ

//===========================================

enum
{
	ITEM_HASH_CHECK_STAT = 1,			//��ϣУ��
	ITEM_HEARTRATE_DATA_STAT = 10000,	//��������
	ITEM_HEARTRATE_WAVE_STAT,			//���ʲ���
	ITEM_BLOODOXYGEN_DATA_STAT,			//Ѫ������
	ITEM_BLOODOXYGEN_WAVE_STAT,			//Ѫ������
	ITEM_BLOODPRESSURE_DATA_STAT,		//Ѫѹ����
	ITEM_VITAL_SIGN_REGPORT_CENTER_STAT,//���������ϱ�����
	ITEM_VITAL_SIGN_OSD_STAT,			//��������OSD����
	ITEM_VITAL_SIGN_AUTO_BLOODPRESSURE,	//�Զ�����Ѫѹ
	ITEM_VITAL_SIGN_AUTO_TIMEINTVAL,    //�Զ�����Ѫѹʱ����
};//����״̬id

#define GUI_GET_ITEM_STAT_REQ     48	//��ȡ�����Ƿ�ʹ������
#define GUI_GET_ITEM_STAT_RSP    -48	//��ȡ�����Ƿ�ʹ�ܻ�Ӧ

typedef struct
{
	int m_iChn;  //-1-��ʾ�豸���ԣ�>0��ʾͨ����
	int m_iId;
}TGuiGetItemStatReq;

typedef struct
{
	int m_iChn;  //-1-��ʾ�豸���ԣ�>0��ʾͨ����
	int m_iId;
	int m_iEnable;				// -1��֧�֣� 0��ʹ��, 1ʹ��
}TGuiGetItemStatRsp;

#define GUI_SET_ITEM_STAT_REQ     49	//���ù����Ƿ�ʹ������
#define GUI_SET_ITEM_STAT_RSP    -49	//���ù����Ƿ�ʹ�ܻ�Ӧ

typedef struct
{
	int m_iChn;  //-1-��ʾ�豸���ԣ�>0��ʾͨ����
	int m_iId;
	int m_iEnable;				// 0��ʹ��, 1ʹ��
}TGuiSetItemStatReq;

typedef struct								
{	
	int m_iRetCode;
}TGuiSetItemStatRsp;
//===========================================


// -----------------------�û�����-----------------------------

#define GUI_MAX_USER_CNT 			32			//���֧��32���û�
#define GUI_USER_NAME_LEN			15
#define GUI_USER_PSW_LEN			15
typedef struct									//�û���¼����ṹ��
{
	char m_strName[GUI_USER_NAME_LEN + 1];		//�û���
	char m_strPsw[GUI_USER_PSW_LEN + 1];		//����
} TGuiUserLoginReq;

#define GUI_USER_LOGIN_OK			0			//��¼�ɹ�
#define GUI_USER_LOGIN_PSW_ERR	1			//�������
#define GUI_USER_LOGIN_NAME_ERR	2			//�û���������
#define GUI_USER_LOGIN_ERR		3			//��¼ʧ��
#define GUI_USER_LOGIN_UPTIMES	4			//������½5��ʧ�ܣ��˺�����

typedef struct 								//�û���¼��Ӧ
{
	int m_iLoginRs;							//������(��16λ����ʧ�ܴ�������16λ��ʾ������)
} TGuiUserLoginRsp;

typedef struct 								//�û�ע������
{
	char m_strName[GUI_USER_NAME_LEN + 1];		//�û���
} TGuiUserLogoutReq;

#define GUI_USER_LOGOUT_OK		0			//ע���ɹ�
#define GUI_USER_LOGOUT_ERR		1			//ע��ʧ��
typedef struct 								//�û�ע����Ӧ
{
	int m_iLogoutRs;							//������
} TGuiUserLogoutRsp;

typedef struct 								//����û�����
{
	int m_iGroupId;							//����
	char m_strName[GUI_USER_NAME_LEN + 1]; 	//�û���
	char m_strPsw[GUI_USER_PSW_LEN + 1];		//����
} TGuiAddUserReq;

#define GUI_ADD_USER_OK			0			//����û��ɹ�
#define GUI_ADD_USER_GID_ERR		1			//�û��鲻����
#define GUI_ADD_USER_EXIST		2			//ͬ���û��Ѵ���
#define GUI_ADD_USER_OTHER_ERR	3			//����û�����ʧ����
typedef struct 								//����û���Ӧ
{
	int m_iAddUserRs;							//��Ӧ��
} TGuiAddUserRsp;

typedef struct 								//ɾ���û�����
{
	char m_strName[GUI_USER_NAME_LEN + 1]; 	//�û���
} TGuiRmUserReq;

#define GUI_RM_USER_OK				0			//ɾ���û��ɹ�
#define GUI_RM_USER_NOT_EXIST		1			//ɾ�����û�������
#define GUI_RM_USER_CAN_NO_RM		2			//ָ���û��޷���ɾ��
#define GUI_RM_USER_OTHER_ERR		3			//ɾ���û�ʧ������������

typedef struct									//ɾ���û���Ӧ
{
	int m_iRmUserRes;
} TGuiRmUserRsp;

typedef struct 								//�޸��û���������
{
	char m_strName[GUI_USER_NAME_LEN + 1];		//�û���
	int m_iNewGroupId;							//�����
	char m_strNewPsw[GUI_USER_PSW_LEN + 1];	//�����룬Ϊ�����޸�
} TGuiEditUserReq;

#define GUI_EDIT_USER_OK			0			//�޸��û��ɹ�
#define GUI_EDIT_USER_ERR			1			//�޸��û�ʧ��
typedef struct 								//�޸��û����ϻ�Ӧ
{
	int m_iEditUserRes;
} TGuiEditUserRsp;


typedef struct 								//��ȡ�û���Ϣ����
{
	char m_strName[GUI_USER_NAME_LEN + 1];
} TGuiGetUserMsgReq;


//�����û�
#define GUI_GET_USERS_ONLINE_REQ		23
#define GUI_GET_USERS_ONLINE_RSP	   -23
typedef struct
{
	int m_iGid;  //�û���,Ŀǰ���Բ���
	char m_strUser[GUI_USER_NAME_LEN + 1];
	char m_strIp[GUI_PUBLIC_LEN_31 + 1];
}TGuiOnlineUserMsg;

typedef struct
{
	int m_iUsersCnt;
}TGuiGetUsersMsgRsp; //�ȷ��������û�������Ȼ�����������û���Ϣ

//�Ͽ������û�Э��
#define GUI_DISCONNECT_ONLINE_USER_CMD_REQ		24
#define GUI_DISCONNECT_ONLINE_USER_CMD_RSP		-24
typedef struct
{
	int m_iDisconnectTime; //�Ͽ�ʱ��
	TGuiOnlineUserMsg m_tOnlineUserMsg;
}TGuiSetDisOnlineUserCmdReq;

typedef struct
{
	int m_iRetCode;
}TGuiSetDisOnlineUserCmdRsp;

#define GUI_GET_USER_MSG_OK				0	//��ȡ�û���Ϣ�ɹ�
#define GUI_GET_USER_MSG_ERR				1	//��ȡ�û���Ϣʧ��
#define GUI_USER_FLG_CNT					12	//�û�Ȩ�ޱ�ʶ��
#define GUI_USER_FLG_ADD_AND_RM_USER		0	//����û�Ȩ��
#define GUI_USER_FLG_SYS_SETTING			1	//ϵͳ��������Ȩ��
#define GUI_USER_FLG_VIDEO_VIEW			2	//��ƵԤ��Ȩ��
#define GUI_USER_FLG_VIDEO_PLAY			3	//��Ƶ�ط�Ȩ��
#define GUI_USER_FLG_VIDEO_RM				4	//��Ƶɾ��Ȩ��
#define GUI_USER_FLG_CAN_BE_DELETED		5	//���ʺ��Ƿ��ܱ�ɾ����ʶ����
#define GUI_USER_FLG_USER_MNT				6	//�û�����Ȩ��
#define GUI_USER_FLG_SYS_SET_HI			7	//ϵͳ���ø߼�Ȩ��
#define GUI_USER_FLG_PTZ					8	//��̨����Ȩ��
#define GUI_USER_FLG_REC					9	//�ֶ�¼��Ȩ��

#define GUI_COMMON_USER					1	//��ͨ�û�(ֻ���������Ƶ)
#define GUI_SPECIAL_USER					2	//��Ȩ�û�(�ɽ�����̨����)
#define GUI_SUPPER_USER					3	//�����û�(�ɽ���ϵͳ����)
#define GUI_ADIMN_USER						4	//����Ա(�ɽ����û�����)

typedef struct 								//��ȡ�û���Ϣ��Ӧ
{
	int m_iGetUserMsgRs;						//������
	int m_iGroupId;							//����
	// Ȩ�ޱ�ʶ��ʱ������������id�ж�
	char m_cFlgs[GUI_USER_FLG_CNT];				//�û�Ȩ�ޱ�ʶ��ÿ��Ȩ�޶�Ӧһ���ֽ�
												// 1��ʾ�û�ӵ�и�Ȩ�ޣ�0��ʾ��
} TGuiGetUserMsgRsp;


typedef struct 								//��ȡ���б��Ӧ
{
	int m_iGrpCnt;	 							//���ܸ���
} TGuiGetUserGroupListRsp;

#define GUI_USER_GROUP_NAME_LEN		23
typedef struct 								//�û�������
{
	int m_iGrpId; 								//����
	char m_strName[GUI_USER_GROUP_NAME_LEN + 1]; //������
} TGuiUserGroupMsg;

typedef struct 								//��ȡ�û��б��Ӧ
{
	int m_iUserCnt;							//�û�����
} TGuiGetUserListRsp;

typedef struct 								//�û��б���
{
	int m_iGrpId; 								//�û���������
	char m_strName[GUI_USER_NAME_LEN + 1]; 	//�û���
} TGuiUserMsg;

typedef struct 								//�û��б���
{
	int m_iGrpId; 								//�û���������
	char m_strName[GUI_USER_NAME_LEN + 1]; 	//�û���
	char m_strPwd[GUI_USER_NAME_LEN + 1]; //����
} TGuiUserMsgEx;


//===================�û�Ȩ��ϸ��====================
#define	GUI_GET_USER_RIGHT_REQ		20			//��ȡ�û�Ȩ������
#define	GUI_GET_USER_RIGHT_RSP		-20			//��ȡ�û�Ȩ�޻�Ӧ

#define GUI_USER_RIGHT_MAX_NUM    16         //�û�Ȩ���������

#define GUI_USER_RIGHT_PTZ			0		//ͨ��PTZ����Ȩ��
#define GUI_USER_RIGHT_VIDEO_PLAY		1		//�طſ���Ȩ��

typedef struct
{
	char m_strName[GUI_USER_NAME_LEN + 1];
}TGuiGetUserRightReq;

typedef struct
{
	char m_strName[GUI_USER_NAME_LEN + 1];
	int m_iUserRight[GUI_USER_RIGHT_MAX_NUM];   //�û�Ȩ�ޣ�ÿ��Ԫ�ش���һ��Ȩ�ޣ�ͨ��Ȩ��intÿһλ����һ��ͨ��
}TGuiGetUserRightRsp;


#define GUI_SET_USER_RIGHT_REQ		21			//�����û�Ȩ������
#define GUI_SET_USER_RIGHT_RSP		-21			//�����û�Ȩ�޻�Ӧ

typedef struct
{
	char m_strName[GUI_USER_NAME_LEN + 1];
	int m_iUserRight[GUI_USER_RIGHT_MAX_NUM];  //�û�Ȩ�ޣ�ÿ��Ԫ�ش���һ��Ȩ�ޣ�ͨ��Ȩ��intÿһλ����һ��ͨ��
}TGuiSetUserRightReq;

typedef struct
{
	int m_iRetCode;									//������
}TGuiSetUserRightRsp;						//�����û�Ȩ�޻�Ӧ

//===================���û�ȡ/�����û�Ȩ�޷�Χ======================
typedef enum 
{
	GUI_RIGHT_REMOTE_PTZ = 2,       //Զ���ƾ�����   2
	GUI_RIGHT_REMOTE_VPLAY_PSCAN,	//Զ�̻ط����3
	GUI_RIGHT_REMOTE_PREV,			//Զ��Ԥ�� 4
	GUI_RIGHT_LOCAL_HAND_RECSNAP,	//�����ֶ�¼��ץ��5
	GUI_RIGHT_REMOTE_HAND_RECSNAP,  //Զ���ֶ�¼��ץ��6
	GUI_RIGHT_LOCAL_ALARMCLEAR,   	//��������7
	GUI_RIGHT_LOCAL_DVD,			//����ʵʱ��¼�͹��̻ط�8
	GUI_RIGHT_LOCAL_LOG,			//������־����9
	GUI_RIGHT_LOCAL_ALARMSET,		//���ر�������10
	GUI_RIGHT_LOCAL_CHNMANAGE,		//����ͨ������11
	GUI_RIGHT_LOCAL_PARASET,		//���ز�������(���룬ͼ����ʾ��¼��ģ�壬¼����Ե�) 12
	GUI_RIGHT_LOCAL_SYSSET,			//����ϵͳ����13
	GUI_RIGHT_LOCAL_USERMANAGE,		//�����û�����14
	GUI_RIGHT_REMOTE_ALARMCLEAR,	//Զ������15
	GUI_RIGHT_REMOTE_REBOOT,		//Զ������/�ػ�16
	GUI_RIGHT_REMOTE_DVD,			//Զ��ʵʱ��¼17
	GUI_RIGHT_REMOTE_LOG,			//Զ����־����18
	GUI_RIGHT_REMOTE_ALARMSET,		//Զ�̱�������19
	GUI_RIGHT_REMOTE_CHNMANAGE,		//Զ��ͨ������20
	GUI_RIGHT_REMOTE_PARASET,		//Զ�̲�������21
	GUI_RIGHT_REMOTE_SYSSET,		//Զ��ϵͳ����22
	GUI_RIGHT_REMOTE_USERMANAGE,	//Զ���û�����23
	GUI_RIGHT_REMOTE_TALK,			//�����Խ�24
	GUI_RIGHT_LOCAL_REBOOT,			//���عػ������� 25
	GUI_RIGHT_MAX_NUM,				
}GUI_USER_RIGHT_ID;

#define GUI_SET_USER_RIGHT_ID_REQ		22		//�����û�Ȩ��id��Χ����(��ȡ/����ǰ�ȷ��������ʶ��ȡ/���õ�id��Χ)
#define GUI_SET_USER_RIGHT_ID_RSP		-22		//�����û�Ȩ��id��Χ��Ӧ

typedef struct
{
	char m_strName[GUI_USER_NAME_LEN + 1];
	int m_iStartId;
	int m_iEndId;
}TGuiSetRightIdReq; //�����û�Ȩ��id��Χ����(��ȡ/����ǰ�ȷ��������ʶ��ȡ/���õ�id��Χ)

#define GUI_SET_RIGHT_ID_OK   0	//���óɹ�
#define GUI_SET_RIGHT_ID_ERR  1	//����ʧ��
typedef struct
{
	int m_iRetCode;		//������
}TGuiSetRightIdRsp;	//�����û�Ȩ��id��Χ��Ӧ


#define	GUI_GET_USER_RIGHT_REQ_EX		25 //��ȡ�û�Ȩ������(��·����չ)
#define	GUI_GET_USER_RIGHT_RSP_EX		-25	//��ȡ�û�Ȩ�޻�Ӧ(��·����չ)
typedef struct
{
	char m_strName[GUI_USER_NAME_LEN + 1];
	int m_iChnOffset;                //ͨ��ƫ������ͨ��������32ʱ��ʹ�ô�Э�飬��ֵ32
}TGuiGetUserRightReqEx;

typedef struct
{
	char m_strName[GUI_USER_NAME_LEN + 1];
	int m_iUserRight[GUI_USER_RIGHT_MAX_NUM];   //�û�Ȩ�ޣ�ÿ��Ԫ�ش���һ��Ȩ�ޣ�ͨ��Ȩ��intÿһλ����һ��ͨ��
}TGuiGetUserRightRspEx;

#define GUI_SET_USER_RIGHT_REQ_EX		26  //�����û�Ȩ������(��·����չ)
#define GUI_SET_USER_RIGHT_RSP_EX			-26  //�����û�Ȩ�޻�Ӧ(��·����չ)
typedef struct
{	
	char m_strName[GUI_USER_NAME_LEN + 1];
	int m_iChnOffset;   //ͨ��ƫ������ͨ��������32ʱ��ʹ�ô�Э�飬��ֵ32
	int m_iUserRight[GUI_USER_RIGHT_MAX_NUM];   
}TGuiSetUserRightReqEx;

typedef struct
{
	int m_iRetCode;     //0��ɹ���1��ʧ��
}TGuiSetUserRightRspEx;


// ------------------------ϵͳ����----------------------------------

//~~~~~~~~~~~~~~~~~~~~~~~~~1.���̹���~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

typedef struct 								//��ȡ�����б��Ӧ
{
	int m_iDiskCnt;							//��������
} TGuiGetDiskListRsp;

#define GUI_DISK_NAME_LEN		31

typedef struct 								//�����б���
{
	int m_iDiskId; 							//����Ψһ���
	char m_strDiskName[GUI_DISK_NAME_LEN + 1]; //������
	unsigned long long m_ullDiskSize; 			//�����ܴ�С
	unsigned long long m_ullDiskUsed;			//�������ÿռ�
	unsigned long long m_ullDiskFree;			//���пռ�
	int m_iFormatStat;							//�Ƿ��ʽ��(0:no, 1:yes)
	int m_iSleepStat;							//����״̬(0:no, 1:yes)
	int m_iSubAreaCnt;							//������
	int m_iUseForBackup;						//�Ƿ�Ϊ������(0:no, 1:yes)08/12/22��� TGuiDiskMsg�ṹ�����m_iDiskUsage
} TGuiDiskListItem;

typedef struct									//��ʽ����������
{
	int m_iDiskId;								//���̱��
} TGuiFormatDiskReq;

typedef struct									//��ʽ�����̻�Ӧ
{
	int m_iDiskId; 							//���̱�ţ�
	int m_iFormatId;							//��ʽ����ţ�ÿ�θ�ʽ������ֵΨһ, ����-1��ʾ�ܾ���ʽ������
} TGuiFormatDiskRsp;

typedef struct 								//��ȡ��ʽ������״̬����
{
	int m_iDiskId;
	int m_iFormateId;
} TGuiGetDiskFormatStatReq;

#define GUI_DISK_FORMAT_ERROR		0			//��ʽ������״̬
#define GUI_DISK_FORMAT_DOING		1			//��ʽ��������״̬
#define GUI_DISK_FORMAT_DONE		2			//��ʽ�����״̬

typedef struct 								//��ȡ��ʽ������״̬��Ӧ
{
	int m_iDiskId;
	int m_iFormatId;
	int m_iStat;								//��ǰ��ʽ��״̬
	int m_iFormatRate;							//��ʽ�����Ȱٷֱ�,-1��ʽ���Ȳ���֪
} TGuiGetDiskFormatStatRsp;

typedef struct									//���̷�������
{
	int m_iDiskId;								//���̱��
	int m_iSubAreaCnt;							//������Ŀ
} TGuiDiskPartReq;

#define GUI_DISK_PART_OK			0			//���̷����ɹ�
#define GUI_DISK_PART_ERR			1			//���̷���ʧ��
typedef struct									//���̷�����Ӧ
{
	int m_iDiskPartRetCode;					//����������
} TGuiDiskPartRsp;

typedef struct									//��ȡ������Ϣ����
{
	int m_iDiskId;								//���̱��
} TGuiGetDiskMsgReq;

#define GUI_DISK_USE_FOR_REC			1			//��������¼��
#define GUI_DISK_USE_FOR_BACK			2			//�������ڱ���
#define GUI_DISK_USE_FOR_REDUNDANCE	    3      		//��������
#define GUI_DISK_USE_FOR_READONLY		4        	//��������ֻ��

typedef struct									//������Ϣ
{
	int m_iDiskUsage;							//������;
	int m_iAlarmWhenErr;						//���̴���ʱ������ʶ
	int m_iAlarmWhenOutOfSpace;				//���̿ռ䲻��ʱ������ʶ
	unsigned int m_uiDiskReservedSize;		//���̿ռ�����(M)
	int m_iAlartMethod[2];					//���̱���������, 0:��Ļ��ʾ,1������ʾ
} TGuiDiskMsg;

typedef struct									//��ȡ������Ϣ��Ӧ
{
	int m_iDiskId;								//���̱�ţ���ֵ��ʾ����
	TGuiDiskMsg m_tMsg;							//������Ϣ
} TGuiGetDiskMsgRsp;

typedef struct									//���ô�����Ϣ����
{
	int m_iDiskId;								//���̱��
	TGuiDiskMsg m_tMsg;							//������Ϣ
} TGuiSetDiskMsgReq;

#define GUI_SET_DISK_MSG_OK		0			//���ô�����Ϣ�ɹ�
#define GUI_SET_DISK_MSG_ERR		1			//���ô�����Ϣʧ��
typedef struct									//���ô�����Ϣ��Ӧ
{
	int m_iSetDiskMsgRetCode;					//���ô�����Ϣ������
} TGuiSetDiskMsgRsp;


#define GUI_SET_DISK_SMART_ENABLE_REQ  56   //���ô�������smart��Ϣ����
#define GUI_SET_DISK_SMART_ENABLE_RSP -56   //���ô�������smart��Ϣ��Ӧ

typedef struct
{
	int m_iDiskNo;  //�̺�
	int m_iEnable;   //���ö�ȡsmart��Ϣ��1-���ã�0-������
}TGuiSetDiskSmartEnableReq;

typedef struct
{
	int m_iRetCode; //0 - ���óɹ���1-ʧ��
}TGuiSetDiskSmartEnableRsp;

#define GUI_GET_DISK_SMART_ENABLE_START_REQ  57  //��ȡ����smart �Ƿ�����״̬����
#define GUI_GET_DISK_SMART_ENABLE_START_RSP  -57 //��ȡ����smart �Ƿ�����״̬��Ӧ
#define GUI_SMART_STR_NAME_LEN 31
typedef struct
{
	int m_iDiskNo;
}TGuiGetDiskSmartEnableStartReq;
typedef struct
{
	int m_iDiskNo;
	int m_iEnable; //0 - ���óɹ���1-ʧ��
}TGuiGetDiskSmartEnableStartRsp; 

#define GUI_GET_DISK_SMART_MSG_REQ   58 //��ȡ����smart��Ϣ����
#define GUI_GET_DISK_SMART_MSG_RSP   -58 //��ȡ����smart ��Ϣ��Ӧ
typedef struct
{
	long long m_llCapacity;  //Ӳ������
	char m_cDevModel[GUI_SMART_STR_NAME_LEN + 1];
	char m_cSerialNum[GUI_SMART_STR_NAME_LEN + 1];
	int m_iTemp; //�¶�
	int m_iUsedTime;// �������
	int m_iHealth; // 1-ͨ�� 0-��ͨ��
	int m_iAllHealth; // 1-����״������
}TGuiDiskSmartBasicMsg;

typedef struct
{
	int m_iDiskNo;
}TGuiGetDiskSmartMsgReq;

typedef struct
{
	int m_iDiskNo;
	int m_iSmartMsgCnt;
	TGuiDiskSmartBasicMsg m_tSmartBasicMsg;
}TGuiGetDiskSmartMsgRsp;

typedef struct
{
	int m_iSmartID;  //HEX ֵ
	char m_cSmartName[GUI_SMART_STR_NAME_LEN + 1];    //smart ��������
	int m_iSmartFlag;   //��ʶ
	int m_iSmartValue;
	int m_iSmartWorst;
	int m_iSmartThresh;
	char m_cSmartStatus[GUI_SMART_STR_NAME_LEN + 1]; //Ӳ��״̬
	long long int m_llSmartRawValue;
}TGuiDiskSmartMsg;


#define GUI_GET_DISK_PART_MSG_REQ    59  //��ȡ���̷�����Ϣ����
#define GUI_GET_DISK_PART_MSG_RSP    -59  //��ȡ���̷�����Ϣ��Ӧ

typedef struct  
{
	int m_iDiskId;   //����id�Ÿ�16λ(0 ���� ��Э�飬 U��1 ���� U�̣�2 ���� esata)
	int m_iDiskPartId; //���̷���id �Ŵ�0��ʼ��-1-��ʾ���з���
}TGuiGetDiskPartMsgReq;

typedef struct
{
	int m_iDiskId;   //����id��
	int m_iDiskPartCnt;  //���̷�����
}TGuiGetDiskPartMsgRsp;

#define GUI_DISK_WRITE_PROTECT_YES   1
#define GUI_DISK_WRITE_PROTECT_NO    0
typedef struct
{
	int m_iDiskId; //����id��
	int m_iDiskPartId; //���̷���id �Ŵ�0��ʼ��-1-��ʾ���з���
	int m_iDiskPartWriteProtect;					//���̷���д����
	char m_strDiskName[GUI_DISK_NAME_LEN + 1]; //������
	unsigned long long m_ullDiskPartSize; 			//���̷�����С
	unsigned long long m_ullDiskPartUsed;			//���̷������ÿռ�
	unsigned long long m_ullDiskPartFree;			//���̷������пռ�
}TGuiDiskPartListItem;




// ---------------------2.��������------------------------------------

#define GUI_SPORT_DATA_NONE_CHECK	0 		//��У��
#define GUI_SPORT_DATA_ODD_CHECK		1 		//��У��
#define GUI_SPORT_DATA_EVEN_CHECK	2 		//żУ��

typedef struct									//����������Ϣ�ṹ��
{
	int m_iPortId;								//���ڱ��
	unsigned int m_uiBitRate;					//������
	unsigned char m_ucDataBits;				//����λ
	unsigned char m_ucStopBits;				//ֹͣλ
	unsigned char m_ucCheckType;				//У��λ
} TGuiSerialPortMsg;


typedef struct									//��ȡ����������Ϣ����
{
	int m_iPortId;								//���ڱ��
} TGuiGetSerialPortMsgReq;

#define GUI_GET_SPORT_MSG_OK		0
#define GUI_GET_SPORT_MSG_ERR		-1

typedef struct									//��ȡ����������Ϣ��Ӧ
{
	int m_iRetCode;							//������
	TGuiSerialPortMsg m_tPortMsg;				//����������Ϣ
} TGuiGetSerialPortMsgRsp;

typedef struct									//������������
{
	int m_iPortId;								//���ڱ��
	TGuiSerialPortMsg m_tSetMsg;				//�����õ�������Ϣ
} TGuiSetSerialPortMsgReq;


#define GUI_SET_SPORT_MSG_OK		0
#define GUI_SET_SPORT_MSG_ERR		-1

typedef struct									//���ô��ڻ�Ӧ
{
	int m_iRetCode;							//������
} TGuiSetSerialPortMsgRsp;


enum
{
	GUI_SERIAL_WORKMODE_PROCO = 1, //Э��ģʽ
	GUI_SERIAL_WORKMODE_CLARITY, //͸��ͨ��
	GUI_SERIAL_WORKMODE_APP,       //���ģʽ
	GUI_SERIAL_WORKMODE_ALARMHOST,  //��������
	GUI_SERIAL_WORKMODE_485COM,		//485����
	GUI_SERIAL_WORKMODE_GPS,		//����GPS
	GUI_SERIAL_WORKMODE_ATM,		//ATM 
};

#define GUI_GET_SPORT_WORKMODE_REQ  62  //��ȡ���ڵĹ���ģʽ����
#define GUI_GET_SPORT_WORKMODE_RSP  -62  //��ȡ���ڵĹ���ģʽ��Ӧ
typedef struct
{
	int m_iPortId;	//���ڱ��
}TGuiGetSerialWorkModeReq;

typedef struct
{
	int m_iPortId;
	int m_iWorkMode;
}TGuiGetSerialWorkModeRsp;

#define GUI_SET_SPORT_WORKMODE_REQ  63 //���ô��ڵĹ���ģʽ����
#define GUI_SET_SPORT_WORKMODE_RSP -63 //���ô��ڵĹ���ģʽ��Ӧ
typedef struct
{
	int m_iPortId;
	int m_iWorkMode;
}TGuiSetSerialWorkModeReq;
typedef struct
{
	int m_iRetCode;
}TGuiSetSerialWorkModeRsp;
	



// ---------------------3.ϵͳ��Ϣ------------------------------------

#define GUI_DVE_NAME_LEN			31			//�豸������
#define GUI_SYS_MSG_STR_LEN			31			//ϵͳ��Ϣ���ַ�������

typedef struct									//��ȡϵͳ��Ϣ��Ӧ
{
	char m_strDveName[GUI_DVE_NAME_LEN + 1];	//�豸��
	int m_iDevNo;								//�豸���
	char m_strManufacturer[GUI_SYS_MSG_STR_LEN + 1];	//������
	char m_strSN[GUI_SYS_MSG_STR_LEN + 1];		//���к�
	char m_strKernelVer[GUI_SYS_MSG_STR_LEN + 1];		//�ں˰汾
	char m_strKernelVerSlaver[GUI_SYS_MSG_STR_LEN + 1];	 //��Ƭ�ں˰汾��
	char m_strWebVer[GUI_SYS_MSG_STR_LEN + 1];	//��ҳ�汾
	char m_strSDKVer[GUI_SYS_MSG_STR_LEN + 1];	//sdk�汾
} TGuiGetSysMsgRsp;

typedef struct									//����ϵͳ��Ϣ����
{
	char m_strDveName[GUI_DVE_NAME_LEN + 1];	//�豸��
	int m_iDevNo;								//�豸���	
} TGuiSetSysMsgReq;

#define GUI_SET_SYS_MSG_OK		0			//����ϵͳ��Ϣ�ɹ�
#define GUI_SET_SYS_MSG_ERR		1			//����ϵͳ��Ϣʧ��

typedef struct									//����ϵͳ��Ϣ��Ӧ
{
	int m_iSetSysMsgRetCode;					//������
} TGuiSetSysMsgRsp;


//===================================
//��ȡ��Ƭ���汾��(����)
#define GUI_SET_SCM_VER_REQ	 79	//�����ں˵�Ƭ���汾����
#define GUI_SET_SCM_VER_RSP	-79	//�����ں˵�Ƭ���汾��Ӧ

#define GUI_SCM_VER_LEN   31
//��Ƭ���汾
typedef struct
{
	char m_strScmVer[GUI_SCM_VER_LEN + 1];//��Ƭ���汾��
}TGuiSetScmVerReq;

typedef struct								
{	
	int m_iRetCode;
}TGuiSetScmVerRsp;
//===================================

//��ȡ����汾
#define GUI_GET_COMPONENT_VER_REQ	 85	//���ں˻�ȡ����汾����
#define GUI_GET_COMPONENT_VER_RSP	-85	//��Ӧ

typedef enum
{
	GUI_VER = 1,
	ZFZJ_VER,          //�����е����
	ONVIF_VER,
	P2P_VER,
}TGuiComponetEnum;

typedef struct
{
	int m_iComponentType;      //������ö�� TGuiComponetEnum
}TGuiGetComponentVerReq;

typedef struct								
{	
	int m_iComponentType; 
	char m_strComponentVer[GUI_SYS_MSG_STR_LEN + 1];	//����汾��
}TGuiGetComponentVerRsp;


// ---------------------4.��־����------------------------------------
// ===================ͳ����־����=====================
#define GUI_LOG_COUNT_REQ			80			//ͳ����־��������
#define GUI_LOG_COUNT_RSP			-80			//ͳ����־������Ӧ

#if 1
#define GUI_LOG_TYPE_ALL		0				//ȫ����־
#define GUI_LOG_LANG_CHI		1				//������־
#define GUI_LOG_LANG_ENG		2				//Ӣ����־
#define GUI_LOG_LANG_TCHI		3				//����������־
#define GUI_LOG_LANG_KOR		4				//������־
#define GUI_LOG_LANG_SPAN		5				//����������־
#define GUI_LOG_LANG_ITA		6				//������־
#define GUI_LOG_LANG_THAI		7				//̩����־
#endif

typedef struct									//ͳ����־����
{
	int m_iBeginTm;							//��ʼʱ��
	int m_iEndTm;								//����ʱ��
	int m_iType;								//��־����
	int m_iChn;								//ͨ����0��ȫ�� dxl 2009/12/01
} TGuiLogCountReq;

typedef struct									//ͳ����־��Ӧ
{
	int m_iLogCnt;								//��־������
} TGuiLogCountRsp;

//======================��ѯ��־=======================
#define GUI_LOG_QUERY_REQ			81			//��ѯ��־����
#define GUI_LOG_QUERY_RSP			-81			//��ѯ��־��Ӧ

typedef struct									//��־��ѯ����
{
	int m_iBeginTm;							//��־��ʼʱ��
	int m_iEndTm;								//��־����ʱ��
	int m_iType;								//��־����
	int m_iChn;								//ͨ��dxl 2009/12/01
	int m_iLang;								//����,
	int m_iStartId;							//��־��ʼ���
	int m_iCnt;									//������־����
} TGuiLogQueryReq;

typedef struct									//��־��ѯ��Ӧ
{
	int m_iRcdCnt;								//������־������
} TGuiLogQueryRsp;

#define GUI_LOG_CONTENT_LEN	127				//��־������󳤶�
typedef struct									//��־�ṹ��
{
	int m_iRecTm;								//��¼ʱ��
	int m_iType;								//��־������
	int m_iChn;									//ͨ��,0��ʾ��ͨ���޹�dxl 2009/12/01
	char m_strContent[GUI_LOG_CONTENT_LEN + 1];	//��־����
} TGuiLog;
//======================�����־=======================

#define GUI_LOG_CLEAR_REQ			82			//�����־����
#define GUI_LOG_CLEAR_RSP			-82			//�����־��Ӧ

#define GUI_LOG_CLEAR_OK		0				//�����־�ɹ�
#define GUI_LOG_CLEAR_ERR		1				//�����־ʧ��
typedef struct									//�����־��Ӧ
{
	int m_iRetCode;							//��־��շ�����
} TGuiLogClearRsp;

//======================��¼��־=======================

#define GUI_LOG_NOTE_REQ		83     //��¼��־����
#define GUI_LOG_NOTE_RSP        -83    //��¼��־��Ӧ

typedef struct
{
	int m_iChn;			//ͨ����0-��ʾ��ͨ���޹�
	int m_iLogLevel;       //��־����
	char strContent[GUI_LOG_CONTENT_LEN + 1]; //��־����
}TGuiLogNoteReq;              

typedef struct
{
	int m_iRetCode;
}TGuiLogNoteRsp;   //��¼��־��Ӧ

//================��չ��־��ѯ========================
#define GUI_LOG_QUERY_EX_REQ		84			//(��չ)��־��ѯ����
#define GUI_LOG_QUERY_EX_RSP		-84			//(��չ)��־��ѯ��Ӧ
typedef TGuiLogQueryReq TGuiLogQueryExReq;

typedef TGuiLogQueryRsp TGuiLogQueryExRsp;

//�¼���־�û�
typedef struct									//��־�ṹ��
{
	int m_iRecTm;								//��¼ʱ��
	int m_iType;								//��־������
	int m_iChn;								//ͨ��,0��ʾ��ͨ���޹�dxl 2009/12/01
	char m_strContent[GUI_LOG_CONTENT_LEN + 1];	//��־����
	char m_strUserName[GUI_USER_NAME_LEN + 1];   //��־�û�
} TGuiLogEx;



// ---------------------5.ϵͳ����------------------------------------
#define GUI_SYS_UPDATE_USE_USB	0			//USB��ʽ����
#define GUI_SYS_UPDATE_USE_FTP	1			//FTP��ʽ����
#define GUI_SYS_UPDATE_FTP_LEN	64			//FTP��ַ����
#define GUI_SYS_UPDATE_ACCEPT		0			//ϵͳ�������󱻽���
#define GUI_SYS_UPDATE_USB_ERR	1			//ϵͳ�����Ҳ���USB�豸
#define GUI_SYS_UPDATE_FTP_ERR	2			//ϵͳ�����޷�����FTP
#define GUI_SYS_UPDATE_FILE_ERR	3			//��ָ���豸���Ҳ��������ļ�
#define GUI_SYS_UPDATE_OTHER_ERR	4			//��������

#define GUI_BACKUP_KERNEL_REQ	1400	
#define GUI_BACKUP_KERNEL_RSP	-1400	
#define GUI_BACKUP_KERNEL_OK	0	//�ں˱��ݳɹ�
#define GUI_BACKUP_KERNEL_ERR	1	//�ں˱���ʧ��

typedef struct
{
	int m_iRetCode;							//�����룬0-�ɹ���1-ʧ��
}TGuiBackupKernelRsp;

typedef struct									//ϵͳ��������
{
	int m_iMethod;								//������ʽ
	char m_strFtpAddr[GUI_SYS_UPDATE_FTP_LEN + 1]; //FTP��ַ
} TGuiSysUpdateReq;

typedef struct								//ϵͳ��������
{
	char m_strFtpAddr[GUI_SYS_UPDATE_FTP_LEN + 1];	//FTP��ַ
	char m_strFtpUser[GUI_SYS_UPDATE_FTP_LEN + 1]; 	//FTP�û���
	char m_strFtpPasswd[GUI_SYS_UPDATE_FTP_LEN + 1]; 	//FTP����
} TGuiSysFtpUpdateReq;

typedef struct										//��������
{
	char m_strFileName[GUI_SYS_UPDATE_FTP_LEN + 1]; 	 //�����ļ���
} TGuiSysUpdateFileReq;

typedef struct										//�����ļ�����
{
	char m_strFileName[GUI_SYS_UPDATE_FTP_LEN + 1];	 //�����ļ���
} TGuiSysUpdateFileRsp;

typedef struct 								//��ȡ�����ļ��б��Ӧ
{
	int m_iUpdateId;							//�������
	int m_iCfgCnt;							//�ļ�����
} TGuiGetSysUpdateFileListRsp;

#define GUI_UPDATE_REBOOT_HAND		2000  //���Զ�����

typedef struct									//ϵͳ������Ӧ
{
	int m_iUpdateId;							//�������
	int m_iRetCode;							//������
} TGuiSysUpdateRsp;

typedef struct									//ϵͳ����״̬��ѯ
{
	int m_iUpdateId;							//�������
} TGuiSysUpdateStaReq;

#define GUI_SYS_UPDATE_DOING		0			//ϵͳ����������
#define GUI_SYS_UPDATE_DONE		1			//ϵͳ�������
#define GUI_SYS_UPDATE_ERR		2			//ϵͳ��������
typedef struct
{
	int m_iUpdateId;							//������� ����Id ΪGUI_UPDATE_REBOOT_HAND���ж�UI�Ƿ��Զ�����
	int m_iUpdateSta;							//����״̬
	int m_iUpdateRate;							//�������Ȱٷֱ�(0-100,����ֵ��ʾ����Ԥ��)
} TGuiSysUpdateStaRsp;

// ---------------------6.��������------------------------------------
#define GUI_SET_RENEW_ACCEPT		0			//ϵͳ���ܲ�������
#define GUI_SET_RENEW_REFUSE		1			//ϵͳ�ܾ���������
typedef struct
{
	int m_iRetCode;							//������
} TGuiSettingRenewRsp;

#define GUI_SET_EXPORT_CNF_REQ       866             //������ȡ�����б�����
#define GUI_SET_EXPORT_CNF_RSP		  867			 //������ȡ�����б��Ӧ
#define GUI_CNF_EXPORT_REQ   868             //��������
#define GUI_CNF_EXPORT_RSP   869			//������Ӧ
#define GUI_SET_IMPORT_CNF_REQ 874			//�����ȡ�����б�����
#define GUI_SET_IMPORT_CNF_RSP 875			//�����ȡ�����б��Ӧ
#define GUI_CNF_IMPORT_REQ   870			//��������
#define GUI_CNF_IMPORT_RSP	  871			//�����Ӧ
#define GUI_CNF_IMPORT_FILE_REFRESH_REQ   872   //�����ļ�ˢ������
#define GUI_CNF_IMPROT_FILE_REFRESH_RSP   873   //�����ļ�ˢ�»�Ӧ
#define GUI_CNF_SUCESS 0
#define GUI_CNF_FAIL   1
#define GUI_CNF_NAME_LEN 32
#define GUI_IMPORT_FILE_STAT_YES	1				//�����ļ�ѡ��
#define GUI_IMPORT_FILE_STAT_NO		2				//�����ļ�δѡ��

typedef struct							
{
	char m_iDstDevName[GUI_CNF_NAME_LEN + 1];	//���������ļ���������
} TGuiCfgPositionExportReq;
typedef struct							
{
	char m_strFileName[GUI_CNF_NAME_LEN + 1];  //���������ļ���
} TGuiCfgFileExportReq;

typedef struct							
{
	char m_strFileName[GUI_CNF_NAME_LEN + 1];  //���������ļ���
} TGuiCfgFileImportReq;

typedef struct 								
{
	int m_iCfgCnt;							//����
} TGuiGetCfgListRsp;

typedef struct								//��Ӧ
{
	int m_iRetCode;
} TGuiCfgRsp;




// ---------------------7.�������------------------------------------
//====================SMTP����============================
#define GUI_GET_SMTP_CNF_REQ			108    	//��ȡSMTP������Ϣ����
#define GUI_GET_SMTP_CNF_RSP			-108	//��ȡSMTP������Ϣ��Ӧ
#define GUI_SET_SMTP_CNF_REQ			109		//����SMTP������Ϣ����
#define GUI_SET_SMTP_CNF_RSP			-109	//����SMTP������Ϣ��Ӧ

#define GUI_RECEVIE_COUNT				4   //֧��4���ռ��˵�ַ
#define GUI_STR_SMTP_ADDRESS_LEN		63
typedef struct
{
	char	m_cServerName[GUI_STR_SMTP_ADDRESS_LEN + 1];    //smtp����������
	char	m_cUserName[GUI_STR_SMTP_ADDRESS_LEN + 1];      //�û���
	char	m_cPassword[GUI_STR_SMTP_ADDRESS_LEN + 1];		//����
	char	m_cReciveAddress[GUI_RECEVIE_COUNT][GUI_STR_SMTP_ADDRESS_LEN + 1];	//�ռ��˵�ַ
	char	m_cEmailTitle[GUI_STR_SMTP_ADDRESS_LEN + 1];		//�ʼ�����
	int		m_iPort;											//�˿ں�
	int		m_iType;							//��16λ��ʾ��¼ģʽ,��16λ��ʾ���ܷ�ʽ��0-������1-�����ܣ�2-SSL��3-TLS
}TGuiSMTPCnfMsg;		//SMTP������Ϣ

typedef struct
{
	TGuiSMTPCnfMsg m_tSMTPCnf;
}TGuiGetSMTPCnfRsp;		//��ȡSMTP������Ϣ��Ӧ

typedef struct
{
	TGuiSMTPCnfMsg m_tSMTPCnf;
}TGuiSetSMTPCnfReq;		//����SMTP������Ϣ����

#define GUI_SET_SMTP_CNF_OK		0 //���óɹ�
#define GUI_SET_SMTP_CNF_ERR	1  //����ʧ��
typedef struct
{
	int m_iRetCode;
}TGuiSetSMTPCnfRsp;		//����SMTP������Ϣ��Ӧ

//===================�������========================

#define GUI_GET_NET_SERVICE_ENABLE_REQ		106			//��ȡ�����������״̬����
#define GUI_GET_NET_SERVICE_ENABLE_RSP	    -106		//��ȡ�����������״̬��Ӧ
#define GUI_SET_NET_SERVICE_ENABLE_REQ		107			//���������������״̬����
#define GUI_SET_NET_SERVICE_ENABLE_RSP		-107		//���������������״̬��Ӧ

enum
{
	SNMP_SERVICE = 1, //SNMP�������
	HTTPS_SERVICE,    //HTTPS����
	FTP_SERVICE,	  //ftp����
	HTTP_SERVICE,	  //http����
	RTSP_SERVICE,   //rtsp���� (��������ʱ�����ں˻�ȡһ��Э�顣)
	T28181_SERVICE,   //28181����Ƶ (��������ʱ�����ں˻�ȡһ��Э�顣)	
	SCHEDULE_SERVICE, //ͥ�󰸼����ڷ���
};//�������id

typedef struct
{
	int m_iId;
}TGuiGetNetServiceReq; //��ȡ�����������״̬����

typedef struct
{
	int m_iId;   //�������id��
	int m_iEnable;  //�Ƿ�ʹ��
}TGuiGetNetServiceRsp;    //��ȡ�����������״̬��Ӧ

typedef TGuiGetNetServiceRsp TGuiSetNetServiceReq;

#define GUI_SET_NET_SERVICE_OK    	0   //���óɹ�
#define GUI_SET_NET_SERVICE_ERR  	1	//����ʧ��
typedef struct
{
	int m_iRetCode; 
} TGuiSetNetServiceRsp;  //���������������״̬��Ӧ

#define GUI_GET_NET_SERVICE_PORT_REQ	104	 //��ȡ�������˿�����
#define GUI_GET_NET_SERVICE_PORT_RSP	-104 //��ȡ�������˿ڻ�Ӧ
#define GUI_SET_NET_SERVICE_PORT_REQ	105	//�����������˿�����
#define GUI_SET_NET_SERVICE_PORT_RSP	   -105	//�����������˿ڻ�Ӧ

typedef struct
{
	int m_iId; 
}TGuiGetNetServicePortReq;   //��ȡ�������˿ں�

typedef struct
{
	int m_iId;
	int m_iPort;
} TGuiGetNetServicePortRsp;

typedef TGuiGetNetServicePortRsp TGuiSetNetServicePortReq;

typedef struct
{
	int m_iRetCode;
} TGuiSetNetServicePortRsp;


//===================�������===========================
#define GUI_GET_NET_FLUX_STATE_REQ		119   //��ȡ��������״̬����
#define GUI_GET_NET_FLUX_STATE_RSP		-119  //��ȡ��������״̬��Ӧ

#define GUI_NET_FLUX_STATE_CNT    31
typedef struct
{
	char m_cUploadRate[GUI_NET_FLUX_STATE_CNT + 1];   //�ϴ�����
	char m_cDownloadRate[GUI_NET_FLUX_STATE_CNT + 1]; //��������
	char m_cUploadTotal[GUI_NET_FLUX_STATE_CNT + 1];     //�ϴ������� 
	char m_cDownloadTotal[GUI_NET_FLUX_STATE_CNT + 1]; //����������  
}TGuiNetFluxState;    //������Ϣ���������ʺ�������

typedef struct
{
	int m_iCardNo;  //������  0-Ԥ�� 1-����1��  2-����2
}TGuiGetNetFluxStateReq; //��ȡ��������״̬����

typedef struct
{
	int m_iCardNo;  //������0-Ԥ�� 1-����1��  2-����2
	TGuiNetFluxState m_iNetFluxState; 
}TGuiGetNetFluxStateRsp;  //��ȡ��������״̬��Ӧ

//=================���綪������ʱ����===================
#define GUI_NET_DELAY_TEST_CMD_REQ	124  //������ʱ������������
#define GUI_NET_DELAY_TEST_CMD_RSP	-124  //������ʱ��������

typedef struct
{
	int m_iCardNo;         //�������0������1��2 ��10 PPP0�����USB������11 USB0�����USB����
	char m_strDstIp[GUI_PUBLIC_LEN_31 + 1];			//Ŀ��ip��ַ
}TGuiNetDelayTestCmdReq;

typedef struct
{
	int m_iCardNo;
	int m_iReachable; 	//�����ַ�Ƿ�ɴ�,0:�ɴ����:���ɴ�
	int m_iDelayTm;		//������ʱ,��λ(ms)
	int m_iLostrate;		//������,ȡֵ��Χ:0-100,ֵΪ50��ʾ:������:50%
}TGuiNetDelayTestCmdRsp;

//====================ץ������====================
#define GUI_NETPACK_CAPTURE_CMD_REQ	125  //����ץ����������
#define GUI_NETPACK_CAPTURE_CMD_RSP	-125  //����ץ�����������Ӧ

typedef struct
{
	int m_iCardNo;	     //������
	int m_iDiskNo;       //���̺�
	int m_iPackSize;      //�������С�����1M
	int m_iTmDelay;      //��ʱʱ�䣬Ĭ��1���ӣ��ȵ���Ϊ׼ 
}TGuiNetPackCaptureReq;

typedef struct
{
	int m_iRetCode;
} TGuiNetPackCaptureRsp;

//=================״̬���=======================
#define GUI_NET_STATUS_TEST_CMD_REQ  126   //����״̬���
#define GUI_NET_STATUS_TEST_CMD_RSP	  -126  //��Ӧ

typedef struct
{
	int m_iCardNo;
}TGuiGetNetStatusTestReq;  //��ȡ����������

//0��ʾ�������綼�ɴ1��ʾ���ز��ɴ2��ʾDNS���ɴ3��ʾ�������ɴ�
typedef struct
{
	int m_iCardNo;   //������
	int m_iRetCode;	//��λ��ʾ�������λ��ʼ
}TGuiGetNetStatusTestRsp;

//==============������Դ���=========================
#define GUI_NET_RESOURCE_CHECK_REQ   127  //������Դ�������
#define GUI_NET_RESOURCE_CHECK_RSP	   -127  //������Դ����Ӧ

typedef struct
{
	int m_iIpChnBandWidth;	   //ipͨ��������λΪM���������ƣ�
	int m_iRePreBandWidth;    //Զ��Ԥ��
	int m_iRePlayBandWidth;   //Զ�̻ط�
	int m_iNetReciveBandWidth;   //������մ���
	int m_iNetSendBandWidth;    //���緢�ʹ���
}TGuiNetResourceMsg;

typedef struct
{
	TGuiNetResourceMsg m_tNetResMsg;
}TGuiGetNetResourceMsgRsp;  //�ظ����ִ���

#define GUI_EMAIL_TEST_CMD_REQ	128    //�ʼ�������������
#define GUI_EMAIL_TEST_CMD_RSP	-128	//�ʼ����������Ӧ

typedef struct
{
	int m_iRetCode; //���Խ����0��ɹ��������ʧ��
}TGuiEmailTestRsp;


//============�������ù���====================

#define GUI_GET_IP_VIA_DHCP			0			//dhcp��ʽ��ȡIP
#define GUI_GET_IP_VIA_HUM			1			//�ֶ�����IP
#define GUI_GET_IP_VIA_PPPOE		2			//PPPoE��ʽ
#define GUI_IP_STR_LEN				31			//IP��ַ�ַ�������
#define GUI_GET_DNS_VIA_DHCP    	0
#define GUI_GET_DNS_VIA_HUM    		1

#define GUI_GET_IP_VIA_PPPOE_ENABLE		true			//PPPoE��ʽ�ܹ�����
#define GUI_GET_IP_VIA_PPPOE_UNENABLE		false			//PPPoE��ʽ���ܹ�����

typedef struct									//�������
{
	int m_iGetIpMethod;						//��ȡip��ַ�ķ�ʽ
	int m_blIsHandSetDns;						//�ֶ�����DNS
	char m_strMac[GUI_IP_STR_LEN + 1];			//mac��ַ
	char m_strIp[GUI_IP_STR_LEN + 1];			//ip��ַ
	char m_strSubMsk[GUI_IP_STR_LEN + 1];		//��������
	char m_strGetWay[GUI_IP_STR_LEN + 1];		//����
	char m_strDNS[GUI_IP_STR_LEN + 1];			//��ѡ��������
	char m_strSecDNS[GUI_IP_STR_LEN + 1];			//��ѡ��������
} TGuiIpMsg;

typedef struct									//��ȡIP������Ӧ
{
	TGuiIpMsg m_tIpMsg;						//ip��Ϣ
} TGuiGetIpRsp;

typedef struct									//����IP��������
{
	TGuiIpMsg m_tIpMsg;
} TGuiSetIpReq;

#define GUI_SET_IP_OK			0				//����IP��ַ�ɹ�
#define GUI_SET_IP_ERR			1				//����IP��ַʧ��
typedef struct									//����IP��ַ��Ӧ
{
	int m_iRetCode;							//������
	TGuiIpMsg m_tIpMsg;						//������IP��Ϣ
} TGuiSetIpRsp;

#define GUI_GET_SECOND_NETWORK_IP_REQ  138  //��ȡ�ڶ�������ip��ַ��Ϣ����
#define GUI_GET_SECOND_NETWORK_IP_RSP  -138 //��ȡ�ڶ�������ip��ַ��Ϣ��Ӧ

#define GUI_SECOND_NETWORK_CARD_NO 2  //�ڶ���������
#define GUI_BOND_NETWORK_CARD_NO 3  //˫�����ۺ�ģʽ�µ�������

enum
{
	GUI_NETWORK_CARD_MODE_DIFFERENT = 0, // �ڶ���������ģʽ������1��ͬ
	GUI_NETWORK_CARD_MODE_SAME,   //�ڶ���������ģʽ������1��ͬ
};

enum
{
	GUI_NET_WORK_Redundancy = 1, //����ģʽ
	GUI_NET_WORK_Balance,        //���ؾ���ģʽ
};

typedef struct
{
	int m_iNetWorkCardNo; //���ں�
}TGuiGetSecondNetWorkIpReq;
typedef struct
{
	int m_iNetWorkCardNo;
	int m_iNetWorkCardMode;//�Ƿ������1��ͬ������
	int m_iNetWorkMode; //����ģʽ��1-����ģʽ��2-���ؾ���ģʽ
	TGuiIpMsg m_tIpMsg;		
}TGuiGetSecondNetWorkIpRsp;

#define GUI_SET_SECOND_NETWORK_IP_OK			0				//����IP��ַ�ɹ�
#define GUI_SET_SECOND_NETWORK_IP_ERR			1				//����IP��ַʧ��
#define GUI_SET_SECOND_NETWORK_IP_REQ   139  //���õڶ�������ip��ַ��Ϣ����
#define GUI_SET_SECOND_NETWORK_IP_RSP   -139 //���õڶ�������ip��ַ��Ϣ��Ӧ

typedef TGuiGetSecondNetWorkIpRsp TGuiSetSecondNetWorkIpReq;

typedef struct
{
	int m_iRetCode;
	int m_iNetWorkCardNo;
	int m_iNetWorkCardMode;//�Ƿ������1��ͬ������
	int m_iNetWorkMode; //����ģʽ��1-����ģʽ��2-���ؾ���ģʽ
	TGuiIpMsg m_tIpMsg;		
}TGuiSetSecondNetWorkIpRsp;
	
//==================IPv6�������=====================
#define GUI_GET_NETCARD_IPV6_MSG_REQ	2020//��ȡ����IPV6��ַ����
#define GUI_GET_NETCARD_IPV6_MSG_RSP	  	-2020//��ȡ����IPV6��ַ��Ӧ
typedef struct									//�������
{
	int m_iGetIpMethod;						//��ȡip��ַ�ķ�ʽ
	int m_blIsHandSetDns;						//�ֶ�����DNS
	char m_strMac[GUI_PUBLIC_LEN_31 + 1];			//mac��ַ
	char m_strIp[GUI_PUBLIC_LEN_63  + 1];			//ip��ַ
	char m_strSubMsk[GUI_PUBLIC_LEN_63  + 1];		//��������
	char m_strGetWay[GUI_PUBLIC_LEN_63  + 1];		//����
	char m_strDNS[GUI_PUBLIC_LEN_63 + 1];			//��ѡ��������
	char m_strSecDNS[GUI_PUBLIC_LEN_63  + 1];			//��ѡ��������
} TGuiIpV6Msg;

typedef struct
{ 
	int m_iNetCardNo;        //������
}TGuiGetIpv6MsgReq;
	
typedef struct
{
	int m_iNetCardNo;
	TGuiIpV6Msg m_tIpV6Msg;
}TGuiGetIpv6MsgRsp;

#define GUI_NET_SV_STR_LEN		64
#define GUI_NET_SV_IP_CNT			16
#define GUI_NET_IP_DISENABLE		0			//����ipȨ���趨
#define GUI_NET_IP_FORBID			1			//��ֹIP����
#define GUI_NET_IP_ACCESS			2			//����IP����
typedef struct
{
	char m_strDnsServer[GUI_NET_SV_STR_LEN + 1];	//DNS������
	int m_iFtpPort;		//ftp�˿ں�
	int m_iHttpPort;		//http�˿ں�
	int m_iNfsEnable;		//����洢����ʹ��
	int m_bupnpenable;                //UPNPʹ��
	char m_strNfsServer[GUI_NET_SV_STR_LEN + 1];	//����洢������
	int m_iNfsPort;								//����洢�˿ں�
	char m_strNfsPath[GUI_NET_SV_STR_LEN + 1];		//����洢·��
	char m_strNfsUser[GUI_NET_SV_STR_LEN + 1];		//����洢�ʺ�
	char m_strNfsPsw[GUI_NET_SV_STR_LEN + 1];		//����洢����
	int m_iIpPopedomType;							//IPȨ������ 1:��ֹ,2:������������ 
	int m_iIpListSize;								//IP�б���,0-16(GUI_NET_SV_IP_CNT)
	char m_strIpList[GUI_NET_SV_IP_CNT][GUI_NET_SV_STR_LEN + 1]; //IP�б�
} TGuiNetServerCnf;

typedef struct										//��ȡ�������û�Ӧ
{
	TGuiNetServerCnf m_tCnf;
} TGuiGetNetCnfRsp;

typedef struct										//����������������
{
	TGuiNetServerCnf m_tCnf;
} TGuiSetNetCnfReq;

#define GUI_SET_NET_CNF_OK		0				//�����������óɹ�
#define GUI_SET_NET_CNF_ERR		1				//������������ʧ��
typedef struct										//�����������û�Ӧ
{
	int m_iRetCode;
} TGuiSetNetCnfRsp;

#define GUI_REG_CENTER_SVR_LEN		31
#define GUI_REG_CENTER_USER_LEN		15
#define GUI_REG_CENTER_PSW_LEN		15
#define GUI_DEV_NAME_LEN				31
typedef struct										//ע��������Ϣ
{
	int m_iPort1;									//�˿�
	char m_strSvr1[GUI_REG_CENTER_SVR_LEN + 1];	//��ַ
	int m_iPort2;									//�˿�
	char m_strSvr2[GUI_REG_CENTER_SVR_LEN + 1];	//��ַ
	char m_strDevName[GUI_DEV_NAME_LEN + 1];		//�豸����
	char m_strName[GUI_REG_CENTER_USER_LEN + 1];	//�û���
	char m_strPsw[GUI_REG_CENTER_PSW_LEN + 1];		//����
} TGuiRegCenterCnf;

#define GUI_GET_REG_CNF_OK			0			//��ȡ�ɹ�
#define GUI_GET_REG_CNF_ERR			1			//��ȡʧ��
typedef struct										//��ȡע��������Ϣ��Ӧ
{
	int m_iRetCode;								//������
	TGuiRegCenterCnf m_tCnf;						//ע������������Ϣ
} TGuiGetRegCenterCnfRsp;

typedef struct										//����ע��������Ϣ����	
{
	TGuiRegCenterCnf m_tCnf;						//ע������������Ϣ
} TGuiSetRegCenterCnfReq;

#define GUI_SET_REG_CNF_OK			0
#define GUI_SET_REG_CNF_ERR			1
typedef struct
{
	int m_iRetCode;								//������
} TGuiSetRegCenterCnfRsp;

#define GUI_PPPOE_DISCONNECT	0				//PPPoE����δ����
#define GUI_PPPOE_CONNECTING 	1				//PPPoE���ڲ���
#define GUI_PPPOE_CONNECTED    	2				//PPPoE���ųɹ�(������)

typedef struct									//�������
{
	int m_iRetCode;                           				 //������ 0:�ɹ���1:ʧ��
	int m_iConnectStat;							//PPPoE��ǰ����״̬
	int m_bIsPppoE;                            				//PPPoE�Զ�����ʹ�ܿ���
	char m_strPPPoeUsr[GUI_IP_STR_LEN + 1]; 		//PPPoE�ʺ�
	char m_strPPPoePsw[GUI_IP_STR_LEN + 1];		//PPPoE����
	char m_strPPPoEIp[GUI_IP_STR_LEN + 1];			//PPPoE��ַ
	char m_strPPPoESubMsk[GUI_IP_STR_LEN + 1];		//PPPoE��������
	char m_strPPPoEGetWay[GUI_IP_STR_LEN + 1];		//PPPoE����
} TGuiPppoeMsg;

typedef struct
{
	char	m_cNvsName[GUI_IP_STR_LEN + 1];          //�豸����
	char	m_cDomainName[GUI_IP_STR_LEN + 1];       //��������ַ
	char 	m_cUserName[GUI_IP_STR_LEN + 1];         //�û���
	char	m_cPassword[GUI_IP_STR_LEN + 1];			//����
	int		m_iPort;					//�˿ں�
	int 	m_iDdnsEnable;				//DDNSʹ��
}TGuiStrDdnsPara;

typedef struct
{
	int m_iRetCode;
}TGuiSetDdnsRsp;

typedef struct
{
	char m_strNtpIp[GUI_IP_STR_LEN + 1];			//�����ַ
	int m_iport;                           //�˿ں�
	int m_itime;                           //ʱ����                   
}TGuiSetNtp;

typedef struct
{
	int m_iRetCode;
}TGuiSetNtpRsp;

#define GUI_GET_NTP_REQ_EX			5132      	//��չ��NTP���� (ʱ������λΪs, ������ʾ����)
#define GUI_GET_NTP_RSP_EX			-5132      //��չ��NTP�����Ӧ
#define GUI_SET_NTP_REQ_EX			5133   	//��չ��NTP��������
#define GUI_SET_NTP_RSP_EX				-5133 	//��չ��NTP���û�Ӧ
//---------------Э��ṹ���TGuiSetNtpһ��-------------------//

//---------------------------DHCP�����-------------------------------
#define GUI_GET_DHCP_SERVER_MSG_REQ		116		//��ȡDHCP������Ϣ����
#define GUI_GET_DHCP_SERVER_MSG_RSP		-116		//��ȡDHCP������Ϣ��Ӧ

typedef struct						//DHCP�������
{
	int m_blEnable;				//�Ƿ�����DHCP����
	int m_iRentTime;				//��ַ���ڣ����ӣ�
	char m_strStartIp[GUI_IP_STR_LEN + 1];		//��ַ�ؿ�ʼIP��ַ
	char m_strEndIp[GUI_IP_STR_LEN + 1];		//��ַ�ؽ���IP��ַ
	char m_strGetWay[GUI_IP_STR_LEN + 1];		//����
	char m_strDNS[GUI_IP_STR_LEN + 1];		//��ѡ��������
	char m_strSecDNS[GUI_IP_STR_LEN + 1];		//��ѡ��������
} TGuiDhcpServerMsg;

typedef struct						//��ȡDHCP���������Ӧ
{
	TGuiDhcpServerMsg m_tDhcpServerMsg;
}TGuiGetDhcpServerMsgRsp;

#define GUI_SET_DHCP_SERVER_MSG_REQ		117		//����DHCP������Ϣ����
#define GUI_SET_DHCP_SERVER_MSG_RSP		-117	//����DHCP������Ϣ��Ӧ

#define GUI_SET_DHCP_SERVER_MSG_OK			0
#define GUI_SET_DHCP_SERVER_MSG_ERR			1

typedef struct						//����DHCP�����������
{
	TGuiDhcpServerMsg m_tDhcpServerMsg;
}TGuiSetDhcpServerMsgReq;

typedef struct					//����DHCP���������Ӧ
{
	int m_iRetCode;				//����DHCP���������Ӧ��0��ʾ�ɹ�
}TGuiSetDhcpServerMsgRsp;

#define GUI_GET_DHCP_CLIENT_MSG_REQ 		118		//��ȡDHCP�ͻ��������б�����
#define GUI_GET_DHCP_CLIENT_MSG_RSP 		-118	//��ȡDHCP�ͻ��������б��Ӧ

#define GUI_CLIENT_NAME_LEN		31

typedef struct						//�ͻ�����Ϣ
{
	int m_iClientID;				//�ͻ���ID
	int m_iRentTime;				//��Чʱ��
	char m_strClientName[GUI_CLIENT_NAME_LEN + 1];	//�ͻ�����
	char m_strMac[GUI_IP_STR_LEN + 1];		//mac��ַ
	char m_strIp[GUI_IP_STR_LEN + 1];		//IP��ַ
} TGuiDhcpClientMsg;

typedef struct						//�ͻ��������б������Ӧ
{
	int m_iDhcpClientCnt;			//�ͻ�������������
}TGuiGetDhcpClientMsgRsp;


// ---------------------8.�쳣����------------------------------------
#define GUI_MAX_EXCEPTION_CNT		12
#define GUI_SUGGEST_CNT       3
#define GUI_SCREEN_DSP        0
#define GUI_SOUND_ENABEL      1
#define GUI_TRAN_TO_SERVER    2

typedef enum
{
	DISK_FULL_EXP = 0,			//������
	DISK_EMPTY_EXP,				//�޴���
	DISK_ERR_EXP,					//���̶�д����
	ACCESS_ERR_EXP,				//�Ƿ�����
	IP_ERR_EXP,					//IP��ͻ	
	NET_ERR_EXP,					//�����ж�
	SYSTEM_BUSY_EXP,				//ϵͳæ
	REDUANCYDISK_EMPTY_EXP,		//��������	
	POWER_EXP,					//��ѹ�쳣
	MAC_ERR_EXP,					//MAC��ַ��ͻ�쳣
	RAID_ERR_EXP,					//�����쳣
	HOTSPARE_ERR_EXP,				//�ȱ��쳣
	POWERPSE_EXP = 12,					//PSE���ų������쳣
	DISK_UPLOAD_EXP,                  //���̳�����
	RECORD_ERR_EXP = 14,			 //¼���쳣
}EExceptionType;

typedef enum
{    
	GUI_SHOW_ONSCREEN = 0,	//��Ļ��ʾ	
	GUI_SOUND_NOTICE,	//������ʾ
	GUI_UPDATE_TOSERVER,	//�ϴ�����
	GUI_EMAIL_ALARM,		//�ʼ�����
	GUI_LINK_ALMOUT,		//�����˿ڱ������
}EGuiSuggestType;


typedef struct										//�쳣����������Ϣ
{
	int m_iExHanldFlg[GUI_MAX_EXCEPTION_CNT]; 		// 1: ����, 0 : ������
	int m_iSuggestFlg[GUI_MAX_EXCEPTION_CNT][GUI_SUGGEST_CNT];   //1:���� 0:������
} TGuiExceptionCnf;

#define GUI_GET_EXCEP_CNF_OK		1
#define GUI_GET_EXCEP_CNF_ERR		0

typedef struct										//��ȡ������Ϣ��Ӧ
{
	int m_iRetCode;								//��Ӧ��
	TGuiExceptionCnf m_tCnf;						//������Ϣ
} TGuiGetExceptionCnfRsp;

typedef struct										//����������Ϣ����	
{
	TGuiExceptionCnf m_tCnf;
} TGuiSetExceptionCnfReq;

#define GUI_SET_EXCEP_CNF_OK		1
#define GUI_SET_EXCEP_CNF_ERR		0

typedef struct										//����������Ϣ��Ӧ
{
	int m_iRetCode;								//��Ӧ��
} TGuiSetExceptionCnfRsp;

#define GUI_GET_EXCEP_CNF_REQ_EX		122		//��չ�Ļ�ȡ�쳣�����������
#define GUI_GET_EXCEP_CNF_RSP_EX		-122	//��չ�Ļ�ȡ�쳣���������Ӧ
typedef struct
{
	int m_iOffset;               //��ʼ���
}TGuiGetExceptionCnfExReq;

typedef struct										//��ȡ������Ϣ��Ӧ
{
	int m_iRetCode;								//��Ӧ��
	int m_iOffset;
	TGuiExceptionCnf m_tCnf;						//������Ϣ
} TGuiGetExceptionCnfExRsp;

#define GUI_SET_EXCEP_CNF_REQ_EX		123		//��չ�������쳣�����������
#define GUI_SET_EXCEP_CNF_RSP_EX		-123	//��չ�������쳣���������Ӧ

typedef struct										//��ȡ������Ϣ��Ӧ
{
	int m_iOffset;
	TGuiExceptionCnf m_tCnf;						//������Ϣ
} TGuiSetExceptionCnfExReq;

typedef struct										//����������Ϣ��Ӧ
{
	int m_iRetCode;								//��Ӧ��
} TGuiSetExceptionCnfExRsp;

#define GUI_GET_EXCEPTION_LINK_ACT_REQ     2520
#define GUI_GET_EXCEPTION_LINK_ACT_RSP     -2520
typedef struct
{
	int m_iExpType;       	//�쳣����
	int m_iSuggestType;	//��ʾ���� ����ö��EGuiSuggestType
}TGuiGetExpSuggestReq;

typedef struct
{
	int m_iExpType;
	int m_iSuggestType;
	int m_iSuggestEnable;  //��ʾ����ʹ�ܣ�����������˿������ʹ��������ֶ�
	int m_iParamEx[32];   //����Ƕ˿ڱ�������λ��ʾ�˿�ʹ��(����ͨ��+ ����+��������)
}TGuiGetExpSuggestRsp;

#define GUI_SET_EXCEPTION_LINK_ACT_REQ     2521
#define GUI_SET_EXCEPTION_LINK_ACT_RSP     -2521
typedef struct
{
	int m_iExpType;
	int m_iSuggestType;
	int m_iSuggestEnable;  //��ʾ����ʹ�ܣ�����������˿������ʹ��������ֶ�
	int m_iParamEx[32];   //����Ƕ˿ڱ�������λ��ʾ�˿�ʹ��(����ͨ��+ ����+��������)
}TGuiSetExpSuggestReq;

typedef struct
{
	int m_iRetCode;
}TGuiSetExpSuggestRsp;


//-------------------------------9.��������-------------------------------
#define GUI_ALIAS_NAME_STR_LEN 	16
#define GUI_VIDEO_FLAG 1
#define GUI_ALARM_IN_FLAG 2
#define GUI_ALARM_OUT_FLAG 3

typedef struct
{
	int m_iNameFlag;//������־��1Ϊ��Ƶ��2Ϊ�������롢3Ϊ�������
	int m_iChnNum;//ͨ����
	char m_cChnName[GUI_ALIAS_NAME_STR_LEN + 1];//ͨ����	
} TGuiChnAlais;	//ͨ������

typedef struct
{
	int m_iNameFlag;
	int m_iChnNum;
} TGuiGetChnAliasReq;

typedef struct
{
	int m_iRetCode;		// 0��ʾ�ɹ�
	TGuiChnAlais m_tAlias;
} TGuiGetChnAliasRsp;

typedef struct
{
	TGuiChnAlais m_tAlias;
}TGuiSetChnAliasReq;

typedef struct
{
	int m_iRetCode;	// 0��ʾ�ɹ�
}TGuiSetChnAliasRsp;

typedef struct		//��ȡͨ�������汾����
{
	int m_iType;		//���ͺ�
} TGuiGetChnAliasVerReq;

typedef struct
{
	int m_iType;		//���ͺ�
	int m_iCurVer;	//�汾��
} TGuiGetChnAliasVerRsp;

//��չ��ͨ������(֧��64���ֽ�)
#define GUI_GET_CHN_ALIAS_REQ_EX		143
#define GUI_GET_CHN_ALIAS_RSP_EX		-143
#define GUI_SET_CHN_ALIAS_REQ_EX		144
#define GUI_SET_CHN_ALIAS_RSP_EX		-144

typedef struct
{
	int m_iNameFlag;//������־��1Ϊ��Ƶ��2Ϊ�������롢3Ϊ�������
	int m_iChnNum;//ͨ����
	char m_cChnName[GUI_PUBLIC_LEN_63 + 2];//ͨ����	
} TGuiChnAlaisEx;	//ͨ������

typedef struct
{
	int m_iNameFlag;
	int m_iChnNum;
} TGuiGetChnAliasReqEx;

typedef struct
{
	int m_iRetCode;		// 0��ʾ�ɹ�
	TGuiChnAlaisEx m_tAliasEx;
} TGuiGetChnAliasRspEx;

typedef struct
{
	TGuiChnAlaisEx m_tAliasEx;
}TGuiSetChnAliasReqEx;

typedef struct
{
	int	m_iRetCode;
}TGuiSetChnAliasRspEx;
//==============end=========


//�Զ�ά��
#define GUI_GET_AUTOMAINTAIN_REQ	880
#define GUI_GET_AUTOMAINTAIN_RSP	-880
#define GUI_SET_AUTOMAINTAIN_REQ	881
#define GUI_SET_AUTOMAINTAIN_RSP	-881

//�����յ�������Ϊ0��6��7-ÿ�죬8-�Ӳ�
typedef struct
{
	int m_iType;      //�������ͣ���λ��ʾ�����һλΪ1����ʾ��ʱ����
	int m_iWeekDay;   //���ڼ�
	int m_iTm;        //ÿ���0�㿪ʼ���ŵ�����
}TGuiClockMsg;

typedef struct
{
	TGuiClockMsg m_tClockMsg;
}TGuiGetAutoMaintainRsp;

typedef struct
{
	TGuiClockMsg m_tClockMsg;
}TGuiSetAutoMaintainReq;

//ʹ�ù��õķ����룬GUI_SET_OK��ɹ���GUI_SET_ERR��ʧ��
typedef struct
{
	int m_iRetCode;
} TGuiSetAutoMaintainRsp;


//==============================ͼ������ ===============================
//============================Ԥ��Ч��===========================
#define GUI_GET_PREVIEW_PIC_QUALITY_REQ		198			//��ȡԤ��Ч����������
#define GUI_GET_PREVIEW_PIC_QUALITY_RSP		-198		//��ȡԤ��Ч��������Ӧ
#define GUI_SET_PREVIEW_PIC_QUALITY_REQ		199			//����Ԥ��Ч����������
#define GUI_SET_PREVIEW_PIC_QUALITY_RSP		-199		//����Ԥ��Ч��������Ӧ

enum
{
	PIC_HIGH_QUALITY = 0,			//���ͼ������
	PIC_HIGH_PERFORMANCE = 1,		//���Ԥ������
}; //Ԥ��ͼ��Ч������

enum
{
	PIC_LOW_DELAY = 0,                   //����ʱ
	PIC_HIGH_FLUENT = 1,               //������
};

typedef struct
{
	int m_iPicQP;		//Ԥ��ͼ��Ч������, ��16λ(0��ʾ���ͼ��������1��ʾ���Ԥ������, 2��ʾ�Զ�ѡ��)��
	//��չ��16λ(0��ʾ����ʱ��1��ʾ������)
}TGuiPreviewPicQualityCnf;			

typedef struct									//��ȡԤ��Ч��������Ӧ
{
	TGuiPreviewPicQualityCnf m_tCnf;			//Ԥ��Ч��
} TGuiGetPreviewPicQualityRsp;					//��ȡԤ��Ч��������Ӧ			

typedef struct											
{
	TGuiPreviewPicQualityCnf m_tCnf;			//Ԥ��Ч��
} TGuiSetPreviewPicQualityReq;				//����Ԥ��Ч����������

#define GUI_SET_PREVIEW_PIC_QUALITY_OK		0	//���óɹ�
#define GUI_SET_PREVIEW_PIC_QUALITY_ERR		1	//����ʧ��
typedef struct											
{
	int m_iRetCode;			//������
} TGuiSetPreviewPicQualityRsp;				//����Ԥ��Ч��������Ӧ

//�������һ֡����novideo
#define GUI_GET_PREVIEW_IPC_OFFLINE_STATUS_REQ		196
#define GUI_GET_PREVIEW_IPC_OFFLINE_STATUS_RSP		-196
#define GUI_SET_PREVIEW_IPC_OFFLINE_STATUS_REQ		197
#define GUI_SET_PREVIEW_IPC_OFFLINE_STATUS_RSP		-197
	
enum
{
	PIC_NOVIDEO = 0,	//novideo
	PIC_LASTFRAME,	   //���һ֡
};

typedef struct
{
	int m_iPicStatus;  // ���һ֡������novideo 
}TGuiIpcOfflinePicCnf;


typedef struct
{
	TGuiIpcOfflinePicCnf m_tCnf;
}TGuiGetIpcOfflinePicStatusRsp;

typedef struct
{
	TGuiIpcOfflinePicCnf m_tCnf;
} TGuiSetIpcOfflinePicStatusReq;


typedef struct
{
	int m_iRetCode;                   //0�ɹ���1ʧ��
} TGuiSetIpcOfflinePicStatusRsp;


//------------------------------ 1.Ԥ������ ----------------------------
//�̶�����ģʽ�·�������
typedef struct									//Ԥ���л�����
{
	int m_iCnt;									//���г���
	int m_iChnList[GUI_DVR_CHN_CNT];		//���ͨ����
} TGuiPreviewSeq;
//======================================================

#define GUI_PIC_USER_DEF   0xFFFF
//�Զ��廭��ģʽ�·��������
typedef struct	//������
{
	int m_iLeft;
	int m_iTop;
	int m_iWidth;
	int m_iHeight;	
} TGuiRect;

typedef struct
{
    TGuiRect m_tVoAreas;
}TGuiUserPreviewParamSeq;
//==============================


// �ڻ�ȡԤ��������Ӧ������Ԥ����������ʱ����������Ӧ��rsp��req�⣬�漴��
// ����Ӧ������TGuiPreviewSeq

typedef struct
{
	int m_iDevId;								//�豸���
} TGuiGetPreviewReq;						//��ȡԤ���������� dxl 2009/11/30

typedef struct									//��ȡԤ��������Ӧ
{
	int m_iPicCnt;								//��������0��ʾ��ȡʧ��
	int m_iInterval;							//�л�ʱ����,0���б���
} TGuiGetPreviewRsp;

typedef struct									//����Ԥ����������
{
	int m_iDevId;								//�豸��� 2009/11/30
	int m_iPicCnt;
	int m_iInterval;
} TGuiSetPreviewReq;

#define GUI_SET_PREVIEW_OK		0			//���óɹ�
#define GUI_SET_PREVIEW_ERR		1			//����ʧ��
typedef struct									//����Ԥ��������Ӧ
{
	int m_iRetCode;							//������
} TGuiSetPreviewRsp;

//============��չԤ������(��·��)===================
#define GUI_GET_PREVIEW_REQ_EX          2080 //��ȡԤ����������
#define GUI_GET_PREVIEW_RSP_EX	    -2080	//��ȡԤ�����û�Ӧ

#define GUI_SET_PREVIEW_REQ_EX          2081  //����Ԥ����������
#define GUI_SET_PREVIEW_RSP_EX         -2081  //����Ԥ�����û�Ӧ

// �ڻ�ȡԤ��������Ӧ������Ԥ����������ʱ����������Ӧ��rsp��req�⣬�漴��
// ����Ӧ������TGuiPreviewSeqEx

typedef struct									//Ԥ���л�����
{
	int m_iCnt;									//���г���
	int m_iChnList[0];			//���ͨ����
} TGuiPreviewSeqEx;

typedef TGuiGetPreviewReq TGuiGetPreviewReqEx;
typedef TGuiGetPreviewRsp	TGuiGetPreviewRspEx;

typedef TGuiSetPreviewReq TGuiSetPreviewReqEx;
typedef TGuiSetPreviewRsp TGuiSetPreviewRspEx;

typedef struct
{
	int m_iDevId;									//�豸���
} TGuiPreviewSwStartReq;					//��ʼ��ƵԤ���л�����dxl 2009/11/30

#define GUI_PREVIEW_SW_START_DONE	0		//�ɹ�������Ƶ�л�
#define GUI_PREVIEW_SW_START_ERR		1		//������Ƶ�л�ʧ��
typedef struct									//������Ƶ�л���Ӧ
{
	int m_iRetCode;
} TGuiPreviewSwStartRsp;

typedef struct
{
	int m_iDevId;									//�豸���
} TGuiPreviewSwStopReq;						//ֹͣԤ���л����� 2009/11/30

#define GUI_PREVIEW_SW_STOP_DONE		0		//�ɹ�ֹͣ��Ƶ�л�
#define GUI_PREVIEW_SW_STOP_ERR		1		//ֹͣ��Ƶ�л�ʧ��
typedef struct									//ֹͣ��Ƶ�л���Ӧ
{
	int m_iRetCode;
} TGuiPreviewSwStopRsp;

typedef struct									//�����沥������
{
	int m_iDevId;									//�豸��� dxl 2009/11/30
	int m_iChn;									//������ͨ����
} TGuiPreviewSingPicReq;

#define GUI_PREVIEW_SPIC_OK		0			//���õ�����ɹ�
#define GUI_PREVIEW_SPIC_ERR		1			//���õ�����ʧ��
typedef struct									//�����沥�������Ӧ
{
	int m_iDevId;
	int m_iChn;									//������ͨ����
	int m_iRetCode;							//������
} TGuiPreviewSingPicRsp;

typedef struct
{
	int m_iDevId;									//�豸���
} TGuiPreviewSingPicExitMsg;					//�������˳�֪ͨdxl 2009/11/30

#define GUI_PREVIEW_MAP_REQ		207			//��Ƶӳ������
#define GUI_PREVIEW_MAP_RSP		-207		//��Ƶӳ���Ӧ
typedef struct									//��Ƶӳ������
{
	int m_iDevId;									//�豸��
	int m_iChn;									//ͨ����
	int m_iLeft;									//���Ͻ�x����
	int m_iTop;									//���Ͻ�y����
	unsigned int m_uiWidth;						//��
	unsigned int m_uiHeight;						//��
} TGuiPreviewMapReq;

#define GUI_PREVIEW_MAP_OK			0		//��Ƶӳ��ɹ�
#define GUI_PREVIEW_MAP_ERROR		1		//��Ƶӳ��ʧ��
typedef struct								//��Ƶӳ���Ӧ
{
	int m_iRetCode;
} TGuiPreviewMapRsp;

#define GUI_PREVIEW_MAP_EXIT_MSG	260		//������Ƶӳ��(�޻�Ӧ)
typedef struct								//������Ƶӳ��
{
	int m_iDevId;	 //�豸��
} TGuiPreviewMapExitMsg;

#define GUI_PREVIEW_SW_STA_REQ	208			//��ȡ��Ƶ�л�״̬����
#define GUI_PREVIEW_SW_STA_RSP	-208		//��ȡ��Ƶ�л�״̬��Ӧ
typedef struct
{
	int m_iDevId;								//�豸��
} TGuiPreviewSwStaReq;					//��ȡԤ��״̬���� 2009/11/30

#define GUI_PREVIEW_SW_STA_STARTED	0		//��ƵԤ���л��ѿ���
#define GUI_PREVIEW_SW_STA_STOPED	1		//��ƵԤ���л���ֹͣ	
typedef struct									//��ȡ��ƵԤ���л�״̬��Ӧ
{
	int m_iRetStat;							//����״̬
} TGuiPreviewSwStaRsp;

#define GUI_PREVIEW_MULTI_PIC_REQ	209		//����Ԥ������������
#define GUI_PREVIEW_MULTI_PIC_RSP	-209	//����Ԥ����������Ӧ
typedef struct									//���ĵ�ǰԤ������������
{
	int m_iDevId;								//�豸��	2009/11/30 dxl
	int m_iPicCnt;								//�����õ�Ԥ��������(0��ʾ��ѯ)
} TGuiPreviewMultiPicReq;

typedef struct
{
	int m_iPicCnt;								//��ǰ��Ԥ��������
} TGuiPreviewMultiPicRsp;

#define GUI_PREVIEW_PAGE_UP		202			//Ԥ����һҳ
typedef struct
{
	int m_iDevId;
} TGuiPreviewPageUpReq;					//Ԥ���Ϸ�ҳ

#define GUI_PREVIEW_PAGE_DOWN	203			//Ԥ����һҳ
typedef struct
{
	int m_iDevId;
} TGuiPreviewPageDownReq;					//Ԥ���·�ҳ

#define GUI_PREVIEW_CHG_CHN_REQ	250			//��ʱ���Ļ�����ʾ����Ƶ����ͨ������
#define GUI_PREVIEW_CHG_CHN_RSP	-250		//��ʱ���Ļ�����ʾ����Ƶ����ͨ����Ӧ
typedef struct									//��ʱ����Ԥ���������Ƶ����ͨ������
{
	int m_iDevId;								//�豸���dxl 2009/11/30
	int m_iVoChn;								//vo������(1-16)
	int m_iViChn;								//vi���(0-16, 0��ʾ��ѯ��ǰ����ĵ�ǰ��Ƶ����ͨ��)
} TGuiPreviewChgChnReq;

typedef struct									//��ʱ����Ԥ���������Ƶ����ͨ����Ӧ
{
	int m_iDevId;									//�豸���
	int m_iVoChn;								//vo������(1-16)
	int m_iViChn;								//��ǰvo��Ӧ��vi���
} TGuiPreviewChgChnRsp;

#define GUI_PREVIEW_SND_BIND_MSG	252			//Ԥ�������󶨵�VO֪ͨ
typedef struct									//Ԥ��������
{
	int m_iDevId;									//��ʾ�豸���
	int m_iVoChn;								//voͨ����(1-16, 0��ȫ��???)
} TGuiPreviewSoundBindMsg;

#define GUI_SET_PREVIEW_EXCHANGE_REQ  249     //���ý�������Ƶ��������
#define GUI_SET_PREVIEW_EXCHANGE_RSP  -249     //���ý�������Ƶ�����Ӧ

typedef struct
{
	int m_iDevId;             //��16λΪFFʱ����ʾ����ģʽ(������������ͨ��������)
	int m_iSrcVoChn;       //vo����Դͨ���� ��1��ʼ
	int m_iDstVoChn;       //vo����Ŀ��ͨ���� ��1��ʼ
}TGuiSetPreviewExchangeReq;   //���ý�������Ƶ��������

#define GUI_SET_PREVIEW_EXCHANGE_OK  0
#define GUI_SET_PREVIEW_EXCHANGE_ERR 1
typedef struct
{
	int m_iRetCode;
}TGuiSetPreviewExchangeRsp;  //���ý�������Ƶ�����Ӧ

//------------------------------ 2.������ʾ ----------------------------

#define GUI_LAN_DEFAULT		0				//Ĭ������
#define GUI_LAN_CHI			1				//��������
#define GUI_LAN_ENG			2				//Ӣ��
#define GUI_LAN_TCHI		3				//��������
#define GUI_LAN_KOR			4				//����
#define GUI_LAN_SPAN		5				//��������
#define GUI_LAN_ITA			6				//�������
typedef struct
{
	int m_iDspMode;							//��ʽ,PAL/NTSC
	int m_iTimeDspMode;						//ʱ����ʾ��ʽ��0��ʾ����ʾ
	int m_iGuiTrnsRate;						//�˵�͸����0-100��ֵ��Խ͸��
	int m_iVgaMode;							//��16λvga��ʾģʽ  ��16λ HDMIģʽ
	int m_iSoundFlg;							//����ʹ�ܿ���
	int m_iAlarmStaDspFlg;					//����״̬��ʾ����
	int m_iVedioRcdStaDspFlg;					//¼��״̬��ʾ����
	int m_iGuiTimeOut;							//ͼ�ν��泬ʱ����,0����ʱ
	int m_iGuiLang;							//����
	int m_iStyle;								//��ʽ
	int m_iDeflicker;							//������
	int m_iMainportDetect;					//���ڼ��
	int m_iLinkSPicInterval;          		//���������������л�ʱ����
	int m_iAutoHidenRecLed;						//��16λ���Ƿ�����¼��״̬��,1����,0������
										//��16λ, �Ƿ���ʾ����ﵽ������ʾ1��ʾ,0����ʾ
	int m_iHdmiDspMode;                     //HDMI ��ʾģʽ0-Auto , 1-YCBCR, 2-sRGB
	int m_iLcdScreenTmOut;					//ATMҺ������ʱ��
	int m_iBrightness;						//Һ�����ȵ���
	int m_iAudioWaveState;					//�Ƿ���ʾ��Ƶ����,1��ʾ,0����ʾ
	int m_iShowCblMsg;					//�Ƿ���ʾ��¼��Ϣ��1��ʾ��0����ʾ
	int m_iSizeAuto;						//�ֱ�������Ӧ��1ѡ�У�0��ѡ(��16λ��ʾvga1����16λ��ʾvga2)
	int m_iMouseSpeed;					//����ƶ��ٶ�0-100
	int m_iBatteryLowBeep;				//��ص�����ʱ�Ƿ��������
	int m_iPowerBeep;					//��ε�Դʱ�Ƿ��������
	int m_iMouseSoundCtr;				//�����ֶ������ĵ���
	int m_iShowH323Stat;				//�Ƿ���ʾH323�������״̬��1��ʾ��0����ʾ
} TGuiDisplayCnf;

typedef struct									//��ȡ������ʾ������Ӧ
{
	int m_iVideoMode;							//��Ƶ�����ʽ, PAL/NTSC
} TGuiGetDisplayCnfRsp;

typedef struct									//���ñ�����ʾ��������
{
	int m_iVideoMode;							//��Ƶ�����ʽ, PAL/NTSC
} TGuiSetDisplayCnfReq;

#define GUI_SET_DSP_CNF_OK	0				//���ñ�����ʾ�����ɹ�
#define GUI_SET_DSP_CNF_ERR	1				//ʧ��
typedef struct									//���ñ�����ʾ������Ӧ
{
	int m_iRetCode;
} TGuiSetDisplayCnfRsp;

#define GUI_GET_MASTER_DEV_REQ  212         //��ȡ���豸������
#define GUI_GET_MASTER_DEV_RSP  -212        //��ȡ���豸�Ż�Ӧ
typedef struct
{
	int m_iMasterDev;
}TGuiGetMasterDevRsp; 

//=========TV����======
#define GUI_GET_DEV_TV_MSG_REQ   256      	//��ȡ�豸TV���ڲ�����Ϣ����
#define GUI_GET_DEV_TV_MSG_RSP   -256		//��ȡ�豸TV���ڲ�����Ϣ��Ӧ

typedef struct
{
	int m_iVoDevNo;		//����豸��
	int m_iTop;			//�ϱ߾�(��Χ:0~100)
	int m_iBottom;		//�±߾�(��Χ:0~100)
	int m_iLeft;		//��߾�(��Χ:0~100)
	int m_iRight;		//�ұ߾�(��Χ:0~100)
}TGuiDevTVMsg;

typedef struct
{
	int m_iVoDevNo;		//����豸�� Ĭ����BNC�豸 GUI_BNC_DEV
}TGuiGetDevTvMsgReq;						//��ȡ�豸TV���ڲ�����Ϣ����

typedef struct
{
	TGuiDevTVMsg m_tTvMsg;
}TGuiGetDevTvMsgRsp;						//��ȡ�豸TV���ڲ�����Ϣ��Ӧ


#define GUI_SET_DEV_TV_MSG_REQ   257      	//�����豸TV���ڲ�����Ϣ����
#define GUI_SET_DEV_TV_MSG_RSP   -257		//�����豸TV���ڲ�����Ϣ��Ӧ
typedef struct
{
	TGuiDevTVMsg m_tTvMsg;
}TGuiSetDevTvMsgReq;         		//�����豸TV���ڲ�����Ϣ����

typedef struct
{
	int m_iVoDevNo;
	int m_iRetCode;
}TGuiSetDevTvMsgRsp;   			//�����豸TV���ڲ�����Ϣ��Ӧ


//-------------------------Ԥ���ñ�-----------------------------------------------
#define GUI_GET_PREVIEW_CUT_MSG_REQ		213		//��ȡ��ƵԤ���ñ���Ϣ����
#define GUI_GET_PREVIEW_CUT_MSG_RSP		-213		//��ȡ��ƵԤ���ñ���Ϣ��Ӧ

typedef struct					//��Ƶ�ñ�
{
	int m_iEnable;					//�Ƿ�����Ԥ���ñ�
	int m_iTop;					//ǧ�ֱ��ϲ�
	int m_iBottom;				//ǧ�ֱȵײ�
	int m_iLeft;					//ǧ�ֱ����
	int m_iRight;					//ǧ�ֱ��ұ�
} TGuiPreviewCutMsg;

typedef struct						//��ȡ��ƵԤ���ñ���Ϣ����
{
	int m_iChn;					//ͨ����
}TGuiGetPreviewCutMsgReq;

typedef struct						//��ȡ��ƵԤ���ñ���Ϣ��Ӧ
{
	int m_iChn;
	TGuiPreviewCutMsg m_tPreviewCutMsg;	//�ü�ǧ�ֱ���Ϣ	
}TGuiGetPreviewCutMsgRsp;

#define GUI_SET_PREVIEW_CUT_MSG_REQ		214		//������ƵԤ���ñ���Ϣ����
#define GUI_SET_PREVIEW_CUT_MSG_RSP		-214		//������ƵԤ���ñ���Ϣ��Ӧ

typedef struct						//������ƵԤ���ñ�����
{
	int m_iChn;							//ͨ����	
	TGuiPreviewCutMsg m_tPreviewCutMsg;	//�ü�ǧ�ֱ���Ϣ		
}TGuiSetPreviewCutMsgReq;

#define IP_CHN_NOT_ENABLE  			2				//����ͨ��δ���û����
#define IP_CHN_NOT_VIDEO_CONTECT  	3				//����ͨ��û����Ƶ����
#define IP_CHN_NOT_INIT    			4				//����ͨ����ʼ������

typedef struct						//������ƵԤ���ñ߻�Ӧ
{
	int m_iRetCode;					//������,0:�ɹ�2/3/4ʧ�ܣ�ʧ��˵������
}TGuiSetPreviewCutMsgRsp;

//------------------------------ 3.��Ƶ������� --------------------------

typedef struct			//��ȡ��Ƶ����ͨ����ʽ����
{
	int m_iChn;			//ͨ����,1 - 16
} TGuiGetVideoInNorReq;

typedef struct			//��ȡ��Ƶ����ͨ����ʽ��Ӧ
{
	int m_iNor;			//��ʽ, GUI_PAL_MODE / GUI_NTSC_MODE
 } TGuiGetVideoInNorRsp;

typedef struct
{
	int m_iChn;
	int m_iNor;
} TGuiSetVideoInNorReq;

typedef struct
{
	int m_iRetCode;
} TGuiSetVideoInNorRsp;

#define GUI_VIVEOIN_TM_CNF_CNT		5		//ͬһͨ��֧�����ʱ��	

enum //��ת������
{
	VIDEOIN_COLOR = 0,   		//��ɫ
	VIDEOIN_GRAY,				//�ڰ�	
	VIDEOIN_INNER,      		//��ͬ��
	VIDEOIN_OUTSIDE,	 		//��ͬ��
	VIDEOIN_ALARM,       		//����ͬ��
	VIDEOIN_NONE = 0xFF,                   //������
};								

typedef struct									//��Ƶ�������ʱ����Ϣ
{
	int m_iBenginTm;							//��ʼʱ�䣬�ӵ���00:00��������
	int m_iEndTm;								//����ʱ��
	int m_iHue;									//ɫ���� 0-100
	int m_iLum;									//������ 0-100
	int m_iContrast;							//�Աȶ� 0-100
	int m_iSaturation;							//���Ͷ� 0-100
	// 2008-12-26 ��Ӳ�ת��
	int m_iGrayFlg;								//��ת������(0:��ɫ, 1:��ɫ)
} TGuiVideoInCnf;

typedef struct									//��ȡ��Ƶ�����������
{
	int m_iChn;									//ͨ����
} TGuiGetVideoInCnfReq;

typedef struct									//��ȡ��Ƶ���������Ӧ
{
	int m_iChn;									//ͨ����, 1-16��0��ʾ����
	int m_iVideMode;							//��Ƶ������ʽ,PAL/NTSC/�Զ����
	TGuiVideoInCnf m_tCnf[GUI_VIVEOIN_TM_CNF_CNT]; //���ò���
} TGuiGetVideoInCnfRsp;

typedef struct									//������Ƶ�����������
{
	int m_iChn;									//ͨ����
	int m_iVideMode;							//��Ƶ������ʽ,PAL/NTSC
	TGuiVideoInCnf m_tCnf[GUI_VIVEOIN_TM_CNF_CNT]; //���ò���
} TGuiSetVideoInCnfReq;

//�����Զ������Ƶ������ʽ
typedef struct
{
	int m_iChn;						//0��ʾ����ͨ��,����ͨ���Ŷ�Ӧ
} TGuiGetVideoInModeAutoCheckReq;

typedef struct
{
	int m_iChn;				
	int m_iViModeAutoCheck;
} TGuiGetVideoInModeAutoCheckRsp;	//��ȡ��Ƶ�����Զ�����Ӧ


typedef struct
{
	int m_iChn;	
	int m_iViModeAutoCheck;			//��Ƶ������ʽ�Զ����,1��ʾ����,0��ʾ�ر�
} TGuiSetVideoInModeAutoCheckReq;

typedef struct
{
	int m_iRetCode;					//��Ӧ��,0:�ɹ���1:ʧ��
} TGuiSetVideoInModeAutoCheckRsp;


#define GUI_SET_VIDEOIN_CNF_OK	0			//������Ƶ��������ɹ�
#define GUI_SET_VIDEOIN_CNF_ERR	1			//������Ƶ�������ʧ��
typedef struct									//������Ƶ���������Ӧ
{
	int m_iRetCode;
} TGuiSetVideoInCnfRsp;

typedef struct									//�޸���Ƶ�����������
{
	int m_iChn;									//ͨ�����
	int m_iVideoMod;							//��Ƶ������ʽ
	int m_iHue;									//ɫ���� 0-100
	int m_iLum;									//������ 0-100
	int m_iContrast;							//�Աȶ� 0-100
	int m_iSaturation;							//���Ͷ� 0-100
	// 2008-12-26 ��Ӳ�ת��
	int m_iGrayFlg;
} TGuiChgVideoInCnfReq;

#define GUI_CHG_VIDEOIN_CNF_OK	0			//�޸���Ƶ��������ɹ�
#define GUI_CHG_VIDEOIN_CNF_ERR	1			//�޸���Ƶ�������ʧ��
typedef struct
{
	int m_iRetCode;
} TGuiChgVideoInCnfRsp;

//=============================�������=========================
// 4.��Ƶ�������
#define GUI_GET_VENCODE_CNF_REQ	230			//��ȡ��Ƶ�����������
#define GUI_GET_VENCODE_CNF_RSP	-230		//��ȡ��Ƶ���������Ӧ
#define GUI_SET_VENCODE_CNF_REQ	231			//������Ƶ�����������
#define GUI_SET_VENCODE_CNF_RSP	-231		//������Ƶ���������Ӧ


#define GUI_VIDEO_FULL_FRAME_RATE			2009	//��Ƶȫ֡��

// ��GUI_VIDEO_BIT_STREAM_STATIC�����в��
// �ж϶�������!= GUI_VIDEO_BIT_STREAM_DYNAMICΪ׼
#define GUI_VIDEO_BIT_STREAM_DYNAMIC		1	//������
#define GUI_VIDEO_BIT_STREAM_STATIC			2	//�������϶���,ע�����
#define GUI_VIDEO_BIT_STREAM_STATIC_NEW		0	//������ dxl 2011/02/23

// ��GUI_VIDEO_AUDIO�����в���жϸ���������
// != GUI_VIDEO_ONLYΪ׼
#define GUI_VIDEO_ONLY						1	//����Ƶ
#define GUI_VIDEO_AUDIO						2	//������Ƶ	�϶���,ע�����			
#define GUI_VIDEO_AUDIO_NEW					3	//������Ƶ	
#define GUI_AUDIO_ONLY						20

//����ģʽ
enum
{
	GUI_ENCODE_MODE_BASELINE_PROFILE = 0,
	GUI_ENCODE_MODE_MAIN_PROFILE,
	GUI_ENCODE_MODE_HIGH_PROFILE,
};

enum//��������
{
	GUI_MAIN_CHANNEL_INSTANT = 0, //��ʱֵ
	GUI_MAIN_CHANNEL_TIME,    	//����������ʱ��
	GUI_MAIN_CHANNEL_INCIDENT,      //���������¼���	
	GUI_SUB_CHANNEL,          		//������
	GUI_MAIN_CHANNEL_TIME_TEMP1,    //����������ʱģ��1��
	GUI_MAIN_CHANNEL_TIME_TEMP2,     //����������ʱģ��2��
	GUI_MAX_STREAM_TYPE,               //���ģ����
}TGuiVTempType; 

typedef struct									//��Ƶ�������
{
	int m_iEncodeType;							//��16λ��Ƶ���뷽ʽH264, ��16λΪ����ģʽ 
	int m_iPicSize;							//�ֱ��ʱ��
	int m_iFrameRate;							//��Ƶ֡��
	int m_iBitStreamType;						//��������
	int m_iBitRate;							//������С(����):kbps
	int m_iPicQualityLv;						//���ʼ���
	int m_iIFrameRate;							//I֡֡��
	int m_iComplexType;						//����Ƶ��������
	int m_iAudioEncodeType;					//��Ƶ���뷽ʽ
} TGuiVideoEncodeCnf;

typedef struct					//��ȡ��Ƶ�����������
{
	int m_iChn;					//ͨ����(��չ�������ͣ���16λ˵������������TGuiVTempType)
} TGuiGetVideoEncodeCnfReq;

typedef struct					//��ȡ��Ƶ���������Ӧ
{
	int m_iChn;					//ͨ����(��չ�������ͣ���16λ˵������������TGuiVTempType)
	TGuiVideoEncodeCnf m_tCnf;	//������Ϣ
} TGuiGetVideoEncodeCnfRsp;

// ������Ƶ�����������
typedef TGuiGetVideoEncodeCnfRsp TGuiSetVideoEncodeCnfReq;

#define GUI_SET_VENCODE_CNF_OK		0		//���óɹ�
#define GUI_SET_VENCODE_CNF_ERR		1		//����ʧ��
typedef struct									//������Ƶ���������Ӧ
{
	int m_iRetCode;
} TGuiSetVideoEncodeCnfRsp;


#define GUI_GET_INCIDENT_TEMPLATE_ENABLE_REQ	2300   	//��ȡ�¼�ģ���Ƿ���������
#define GUI_GET_INCIDENT_TEMPLATE_ENABLE_RSP	-2300 	//��ȡ�¼�ģ���Ƿ����û�Ӧ

typedef struct
{
	int 	m_iChn;
}TGuiGetIncidentTmpEnableReq;

typedef struct
{
	int 	m_iChn;
	int 	m_iEnable;
}TGuiGetIncidentTmpEnableRsp;

#define GUI_SET_INCIDENT_TEMPLATE_ENABLE_REQ	2301	//�����¼�ģ���Ƿ���������
#define GUI_SET_INCIDENT_TEMPLATE_ENABLE_RSP	-2301	//�����¼�ģ���Ƿ����û�Ӧ

typedef struct
{
	int 	m_iChn;
	int 	m_iEnable;
}TGuiSetIncidentTmpEnableReq;

typedef struct
{
	int	m_iRetCode;
}TGuiSetIncidentTmpEnableRsp;


//------------------------------��Ƶ������--------------------------------
#define GUI_GET_AUDIO_RATE_CNF_REQ    236    //��ȡ��Ƶ����������
#define GUI_GET_AUDIO_RATE_CNF_RSP 	 -236    //��ȡ��Ƶ�����ʻ�Ӧ

typedef struct			//��ȡ��Ƶ�����ʲ�������
{
	int m_iChn;			//ͨ����
} TGuiGetAudioRateCnfReq;

typedef struct			//��ȡ��Ƶ�����ʲ�����Ӧ
{
	int m_iAudioRate;	//��Ƶ������8000:8K;32000:32K;48000:48K
} TGuiGetAudioRateCnfRsp;

#define GUI_SET_AUDIO_RATE_CNF_REQ   237     //������Ƶ����������
#define GUI_SET_AUDIO_RATE_CNF_RSP  -237     //������Ƶ�����ʻ�Ӧ

#define GUI_SET_AUDIO_RATE_CNF_OK   0		 //���óɹ�
#define GUI_SET_AUDIO_RATE_CNF_ERR  1		 //����ʧ��

typedef struct			//������Ƶ�����ʲ�������
{
	int m_iChn;	//ͨ����
	int m_iAudioRate;	//��Ƶ������8:8K;32:32K;48:48K
} TGuiSetAudioRateCnfReq;

typedef struct			//������Ƶ�����ʲ�����Ӧ
{
	int m_iRetCode;		//�����룬0��ʾ�ɹ�
} TGuiSetAudioRateCnfRsp;

#define GUI_GET_CHN_AUDIO_RATE_LST_REQ    238  //��ȡÿ��ͨ������Ƶ�������б�����
#define GUI_GET_CHN_AUDIO_RATE_LST_RSP    -238  //��ȡÿ��ͨ������Ƶ�������б��Ӧ

typedef struct
{
	int m_iChn;   //����ͨ��
}TGuiGetChnAudioRateLstReq;

typedef struct
{
	int m_iChn;
	int m_iCnt;   //��������ͨ��֧�ּ�����Ƶ������
}TGuiGetChnAudioRateLstRsp;

typedef struct
{
	int m_iAudioRate;  //��Ƶ������
}TGuiAudioRateItem;

//����Ƶƴ��
#define GUI_SET_AV_MEDLEY_REQ			20007	//��������Ƶƴ������
#define GUI_SET_AV_MEDLEY_RSP			-20007 	//��������Ƶƴ�ӻ�Ӧ


typedef struct
{
	int m_iChn;
	int m_iEnable; 			// ����Ƶƴ��ͨ��ʹ��
} TGuiSetAVMedleyReq;

typedef struct
{
	int m_iRetCode;				// ����Ƶƴ��ͨ��ʹ��
} TGuiSetAVMedleyRsp;

#define GUI_GET_AV_MEDLEY_REQ			20008	//��ȡ����Ƶƴ������
#define GUI_GET_AV_MEDLEY_RSP			-20008 	//��ȡ����Ƶƴ�ӻ�Ӧ

typedef struct
{
	int m_iChn; 			// ����Ƶƴ��ͨ��ʹ��
} TGuiGetAVMedleyReq;

typedef struct
{
	int m_iChn;
	int m_iEnable;			// ����Ƶƴ��ͨ��ʹ��
} TGuiGetAVMedleyRsp;

//------------------------��Ƶ���뷽ʽ-------------------------------
#define GUI_GET_CHN_AUDIO_CODETYPE_LST_REQ  239   //��ȡͨ����Ƶ���뷽ʽ�б�����
#define GUI_GET_CHN_AUDIO_CODETYPE_LST_RSP  -239  //��ȡͨ����Ƶ���뷽ʽ�б��Ӧ

typedef struct
{
	int m_iChn;
}TGuiGetChnAudioCodeTypeLstReq;   //��ȡͨ����Ƶ���뷽ʽ�б�����

typedef struct
{
	int m_iChn;
	int m_iCnt;
}TGuiGetChnAudioCodeTypeLstRsp;   //��ȡͨ����Ƶ���뷽ʽ�б��Ӧ

typedef struct
{
	int m_iAudioCodeType;
}TGuiAudioCodeTypeItem;  //��Ƶ���뷽ʽ

//-----------------------��Ƶ���뷽ʽ-------------------------------
#define GUI_GET_CHN_VIDEO_CODETYPE_LST_REQ  245   //��ȡͨ����Ƶ���뷽ʽ�б�����
#define GUI_GET_CHN_VIDEO_CODETYPE_LST_RSP  -245  //��ȡͨ����Ƶ���뷽ʽ�б��Ӧ

typedef struct
{
	int m_iChn;
}TGuiGetChnVideoEncodeTypeLstReq;   //��ȡͨ����Ƶ���뷽ʽ�б�����

typedef struct
{
	int m_iChn;
	int m_iCnt;
}TGuiGetChnVideoEncodeTypeLstRsp;   //��ȡͨ����Ƶ���뷽ʽ�б��Ӧ

typedef struct
{
	int m_iVideoEncodeType;
}TGuiVideoEncodeTypeItem;  //��Ƶ���뷽ʽ

//------------------------------ 4.��Ƶǰ�˵��� --------------------------
typedef struct
{
	int m_iXp;
	int m_iYp;
} TGuiLoc;

typedef struct
{
	int m_iTop;
	int m_iLeft;
	unsigned int m_uiWidth;
	unsigned int m_uiHeight;
} TGuiArea;

#define GUI_CHN_NAME_LEN		32				//ͨ������󳤶�
#define GUI_CHN_TEXT_LEN		255				//�Զ����ı���󳤶�
#define GUI_MAX_COVER_AREA		4

typedef struct									//��Ƶ���Ӳ���
{
	int m_iNameOverlayEnable;					//ͨ��������ʹ�ܱ�ʶ
	char m_strName[GUI_CHN_NAME_LEN + 1];		//ͨ����
	int m_iChnColor;                            //ͨ����ɫ                          
	TGuiLoc m_tNameLoc;						//ͨ��������λ��
	
	int m_iTimeOverlayEnable;					//ʱ�����ʹ�ܱ�ʶ
	int m_iTimeFormat;							//ʱ���ʽ,�Ͱ�λ����format���ھ�λ�����Ƿ�������ڣ���ʮλΪ0����24ʱ�ơ�Ϊ1����12ʱ��
	int m_iTimeColor;                           //����ʱ����ɫ
	TGuiLoc m_tTimeLoc;						//ʱ�����λ��
	
	int m_iTextEnable;							//�Զ����ı�����ʹ��
	char m_strText[GUI_CHN_TEXT_LEN + 1];		//�Զ����ı�
	TGuiLoc m_tTextLoc;						//�ı�����λ��

	int m_iLogoEnable;							//Logo����ʹ�ܱ�ʶ
	TGuiLoc m_tLogoLoc;						//Logo����λ��

	int m_iVideoCoverEnable;					//��Ƶ�ڵ�ʹ�ܱ�ʶ
	int m_iCoverAreaCnt;						//��Ƶ�ڵ����������õĸ���
	TGuiArea m_tCoverAreas[GUI_MAX_COVER_AREA]; //��Ƶ�ڵ�����
} TGuiVideoOverlayCnf;

typedef struct									//��ȡ��Ƶ���Ӳ�������
{
	int m_iChn;									//ͨ����
} TGuiGetVideoOverlayCnfReq;

typedef struct									//��ȡ��Ƶ���Ӳ�����Ӧ
{
	int m_iChn;									//ͨ����
	TGuiVideoOverlayCnf m_tCnf;					//���ò���
} TGuiGetVideoOverlayCnfRsp;

typedef struct									//������Ƶ���Ӳ�������
{
	int m_iChn;									//ͨ����
	TGuiVideoOverlayCnf m_tCnf;					//���ò���							
} TGuiSetVideoOverlayCnfReq;

#define GUI_SET_VOVERLAY_CNF_OK	0			//���óɹ�
#define GUI_SET_VOVERLAY_CNF_ERR	1			//����ʧ��
typedef struct									//������Ƶ���Ӳ�����Ӧ
{
	int m_iRetCode;							//������
} TGuiSetVideoOverlayCnfRsp;

typedef struct									//����logoͼ������
{
	int m_iChn;									//ͨ����
} TGuiChgLogoBmpReq;

#define GUI_CHG_LOGO_BMP_OK		0			//����ͼ��ɹ�
#define GUI_CHG_LOGO_BMP_ERR		1			//����ͼ��ʧ��
typedef struct									//����logoͼ���Ӧ
{
	int m_iRetCode;
} TGuiChgLogoBmpRsp;

//==============================¼������ ===============================
//=======================���ռƻ�========================
#define GUI_GET_HOLIDAY_MSG_REQ		296	 	//��ȡ���ռƻ���Ϣ����
#define GUI_GET_HOLIDAY_MSG_RSP		-296	//��ȡ���ռƻ���Ϣ��Ӧ

#define GUI_SET_HOLIDAY_MSG_REQ		297		//���ü��ռƻ���Ϣ����
#define GUI_SET_HOLIDAY_MSG_RSP		-297	//���ü��ռƻ���Ϣ��Ӧ

#define GUI_HOLIDAY_NAME_LEN	32
#define GUI_MAX_HOLIDAY_CNT		10

enum
{
	HOLIDAY_TYPE_WEEK = 1, 	//����
	HOLIDAY_TYPE_MONTH,		//�·�
	HOLIDAY_TYPE_DATE,		//����
}; //��������

typedef struct
{
	int m_iId;   //���ձ��
	char m_strHolidayName[GUI_HOLIDAY_NAME_LEN + 1];  //��������
	int m_iStatus;  //0��������1��ʾ����
	int m_iType;   //�������ͣ������������ͣ���Ϊ���ڡ��·ݡ�����
	int m_iStartFirst;    //
	int m_iStartSecond;  //
	int m_iStartLast;   //
	int m_iEndFirst;
	int m_iEndSecond;
	int m_iEndLast;
}TGuiHolidayMsg;
/*������������ڣ���m_iStartFirst��m_iStartSecond��m_iStartLast��ʾ��ʼʱ���������
���������ڣ���m_iStartFirst��m_iStartSecond��m_iStartLast��ʾ��ʼʱ��ĵڼ����¡��ڼ������ڣ����ڼ�������������·ݣ���m_iStartFirst��m_iStartSecond��ʾ�ڼ����£����ţ�m_iStartLast��m_iEndLast��ʹ�� */

typedef struct
{
	TGuiHolidayMsg m_tHolidayMsg[GUI_MAX_HOLIDAY_CNT];
}TGuiGetHolidayMsgRsp; //��ȡ���ռƻ���Ϣ��Ӧ

typedef struct
{
	TGuiHolidayMsg m_tHolidayMsg[GUI_MAX_HOLIDAY_CNT];
}TGuiSetHolidayMsgReq;       //���ü��ռƻ���Ϣ����

#define GUI_SET_HOLIDAY_MSG_OK   0 //���óɹ�
#define GUI_SET_HOLIDAY_MSG_ERR	1	//����ʧ��
typedef struct
{
	int m_iRetCode;         //0��ʾ�ɹ���1��ʾʧ��
} TGuiSetHolidayMsgRsp; 	//���ü��ռƻ���Ϣ��Ӧ

//=======================¼����ʱ��====================
#define GUI_GET_REC_REMAIN_TIME_REQ   298 	//��ȡ¼���ļ�����ʱ������
#define GUI_GET_REC_REMAIN_TIME_RSP   -298	//��ȡ¼���ļ�����ʱ���Ӧ
#define GUI_SET_REC_REMAIN_TIME_REQ   299	//����¼���ļ�����ʱ������
#define GUI_SET_REC_REMAIN_TIME_RSP   -299	//����¼���ļ�����ʱ���Ӧ

typedef struct
{
	int m_iChn;					//��16λ 0-������1-������
}TGuiGetRecRemainTmReq;		//��ȡ¼���ļ�����ʱ������

typedef struct
{
	int m_iChn;				//��16λ 0-������1-������
	int m_iTm;  			//��λ������
}TGuiGetRecRemainTmRsp;	//��ȡ¼���ļ�����ʱ���Ӧ

typedef struct
{
	int m_iChn;				//��16λ 0-������1-������
	int m_iTm;	
}TGuiSetRecRemainTmReq;	//����¼���ļ�����ʱ������

#define GUI_SET_REC_REMAIN_TM_OK  0 //���óɹ�
#define GUI_SET_REC_REMAIN_TM_ERR 1	//����ʧ��
typedef struct
{
	int m_iRetCode;
}TGuiSetRecRemainTmRsp;	//����¼���ļ�����ʱ���Ӧ




//=========================¼��������==============================
//¼��������
#define GUI_GET_VIDEO_TYPE_REQ 			390      	//¼����������
#define GUI_GET_VIDEO_TYPE_RSP			-390
#define GUI_SET_VIDEO_TYPE_REQ 			391      	//¼����������
#define GUI_SET_VIDEO_TYPE_RSP 			-391      //¼���������û�Ӧ

#define GUI_VIDEO_TYPE_NAME_STR_LEN	16

typedef struct
{
	int m_iChnNum;       //���ͺ�
	char m_strVideoType[GUI_VIDEO_TYPE_NAME_STR_LEN + 1];           //¼��������
}TGuiVideoTypeName;

typedef struct
{
	int m_iRetCode;
}TGuiSetTypeRsp;

typedef struct
{
	int m_iTypeId;			//�Զ���¼�����ͺţ�32-63
	char m_strTypeName[GUI_VIDEO_TYPE_NAME_STR_LEN + 1];    //¼��������
} TGuiGetVideoTypeReq;

typedef struct
{
	int m_iTypeId;			//�Զ���¼�����ͺţ�32-63��-1���ȡʧ��
	char m_strTypeName[GUI_VIDEO_TYPE_NAME_STR_LEN + 1];    //¼��������
} TGuiGetVideoTypeRsp;

typedef struct
{
	int m_iTypeId;			//�Զ���¼�����ͺţ�32-63
	char m_strTypeName[GUI_VIDEO_TYPE_NAME_STR_LEN + 1];    //¼��������
} TGuiSetVideoTypeReq;

typedef struct
{
	int m_iRetCode;
} TGuiSetVideoTypeRsp;

//=======================¼���ļ�����=====================
#define GUI_VF_NAME_LEN		67				//¼���ļ�����󳤶�


#define GUI_GET_RECFILE_LOCK_STATUS_REQ		394   //��ȡ¼���ļ���״̬����
#define GUI_GET_RECFILE_LOCK_STATUS_RSP		-394  //��ȡ¼���ļ���״̬��Ӧ

enum//��״̬
{
	RECFILE_UNLOCK = 0,  //0��ʾ����
	RECFILE_LOCK,        //1�����
};

typedef struct
{
	char m_strFileName[GUI_VF_NAME_LEN + 1];	//¼���ļ���
}TGuiGetRecFileLockStatusReq;	

typedef struct
{
	char m_strFileName[GUI_VF_NAME_LEN + 1];	//¼���ļ���
	int m_iAction;  //��״̬
} TGuiGetRecFileLockStatusRsp;

#define GUI_SET_RECFILE_LOCK_STATUS_REQ		395   //����¼���ļ���״̬����
#define GUI_SET_RECFILE_LOCK_STATUS_RSP		-395 //����¼���ļ���״̬��Ӧ

typedef struct
{
	char m_strFileName[GUI_VF_NAME_LEN + 1];	//¼���ļ���
	int m_iAction;  //��״̬
} TGuiSetRecFileLockStatusReq;

#define GUI_SET_RECFILE_LOCK_STATUS_OK	 0  //���óɹ�
#define GUI_SET_RECFILE_LOCK_STATUS_ERR 1	//����ʧ��
typedef struct
{
	int m_iRetCode;   //0��ɹ���1��ʾʧ��
} TGuiSetRecFileLockStatusRsp;



//=========================¼��ģ��=================================

// ¼��������
typedef enum
{
	GUI_VR_TYPE_ALL = 0,		//ȫ��¼��
	GUI_VR_TYPE_HUM,				//�ֶ�¼��
	GUI_VR_TYPE_ALARM,				//����¼��
	GUI_VR_TYPE_TIME,				//��ʱ¼��
	GUI_VR_TYPE_MD,				//�ƶ����¼��
	GUI_VR_TYPE_LOST,				//��Ƶ��ʧ¼��
	GUI_VR_TYPE_MD_EX,				//�ƶ����|����¼��
	GUI_VR_TYPE_ALOST,			//��Ƶ��ʧ����
	GUI_VR_TYPE_OD,					//��Ƶ�ڵ�����
	GUI_VR_TYPE_MD_ALARM,			//�ƶ����&����¼��
		
	GUI_VR_TYPE_VCA = 32,                      //���ܷ���| ����¼��  
	GUI_VR_TYPE_TEMP,				//��ʪ�ȱ���¼��
	GUI_VR_TYPE_ATM,				//ATM ���Ų�ѯ
	GUI_VR_TYPE_ITS,					//ITS ¼��
}EGuiRecType;

typedef struct									//¼��ʱ��ģ��
{
	int m_iEnable;								//��¼��ʱ���Ƿ�����
	int m_iStartTm;							//¼��ʼʱ��,�Ե���00:00������������
	int m_iEndTm;								//¼�����ʱ��
	int m_iType;								//¼������
} TGuiVideoRecTmTmp;

#define GUI_VR_TM_CNT_PER_DAY		4			//ÿ��������ʱ��
typedef struct									//¼������ģ��
{
	TGuiVideoRecTmTmp m_tRecTm[GUI_VR_TM_CNT_PER_DAY];
} TGuiVideoRecDayTmp;

typedef struct									//¼��ģ��
{
	int m_iPreRcdTm;							//Ԥ¼ʱ���������
	int m_iDelayTm;							//��ʱʱ���������
	TGuiVideoRecDayTmp m_tRecDay[7];			//һ������¼�����
} TGuiVideoRecTemplate;

typedef struct									//��ȡ¼��ģ������
{
	int m_iChn;									//¼��ͨ��
} TGuiGetVideoTemplateReq;

typedef struct									//��ȡ¼��ģ���Ӧ
{
	int m_iChn;									//ͨ����
	TGuiVideoRecTemplate m_tTmp;				//ͨ����Ӧ��¼��ģ��
} TGuiGetVideoTemplateRsp;

typedef struct									//����¼��ģ������
{
	int m_iChn;
	TGuiVideoRecTemplate m_tTmp;				//ͨ����Ӧ��¼��ģ��
} TGuiSetVideoTemplateReq;

#define GUI_SET_VR_TEMPLATE_OK		0		//����¼��ģ��ɹ�
#define GUI_SET_VR_TEMPLATE_ERR		1		//����¼��ģ��ʧ��
typedef struct									//����¼��ģ���Ӧ
{
	int m_iRetCode;
} TGuiSetVideoTemplateRsp;

#define GUI_SET_AUDIOREC_TEMPLATE_REQ   302  //¼��ģ�������ü�¼��Ƶ����
#define GUI_SET_AUDIOREC_TEMPLATE_RSP   -302  //¼��ģ�������ü�¼��Ƶ��Ӧ
typedef struct
{
	int m_iChn;
	int m_iAudioRec; // 1-��¼ 0 -����¼
}TGuiSetAudioRecTemplateReq;
typedef struct
{
	int m_iRetCode;
}TGuiSetAudioRecTemplateRsp;

#define GUI_GET_AUDIOREC_TEMPLATE_REQ   303  //¼��ģ���л�ȡ��¼��Ƶ����
#define GUI_GET_AUDIOREC_TEMPLATE_RSP   -303  //¼��ģ���л�ȡ��¼��Ƶ��Ӧ
typedef struct
{
	int m_iChn;
}TGuiGetAudioRecTemplateReq;
typedef struct
{
	int m_iChn;
	int m_iAudioRec; // 1-��¼ 0 -����¼
}TGuiGetAudioRecTemplateRsp;


#define GUI_GET_BACKUPREC_TEMPLATE_REQ   304	//¼��ģ���л�ȡ����¼������
#define GUI_GET_BACKUPREC_TEMPLATE_RSP   -304	//¼��ģ���л�ȡ����¼���Ӧ

typedef struct
{
	int m_iChn;
}TGuiGetBackUpRecTemplateReq;

typedef struct
{
	int m_iChn;
	int m_iBackUpRec; // 1-����¼��0 -������¼��
}TGuiGetBackUpRecTemplateRsp;

#define GUI_SET_BACKUPREC_TEMPLATE_REQ   305  //¼��ģ������������¼������
#define GUI_SET_BACKUPREC_TEMPLATE_RSP   -305  //¼��ģ������������¼���Ӧ

#define GUI_SET_BR_TEMPLATE_OK		0		//����¼��ģ��ɹ�
#define GUI_SET_BR_TEMPLATE_ERR		1		//����¼��ģ��ʧ��
typedef struct
{
	int m_iChn;
	int m_iBackUpRec; // 1-����¼��0 -������¼��
}TGuiSetBackUpRecTemplateReq;

typedef struct
{
	int m_iRetCode;
}TGuiSetBackUpRecTemplateRsp;

//===================���ռƻ�¼��ģ��=========================
#define GUI_GET_HOLIDAY_VR_TEMPLATE_REQ	  	306		//��ȡ���ռƻ�¼��ģ������
#define GUI_GET_HOLIDAY_VR_TEMPLATE_RSP		-306	//��ȡ���ռƻ�¼��ģ���Ӧ

typedef struct
{
	int m_iPreRcdTm;							//Ԥ¼ʱ���������
	int m_iDelayTm;							//��ʱʱ���������
	TGuiVideoRecDayTmp m_tRecDay;			//һ������¼�����	
}TGuiHolidayRecTemplate;

typedef struct
{
	int m_iChn;
}TGuiGetHolidayTempReq;		//��ȡ���ռƻ�¼��ģ������

typedef struct
{
	int m_iChn;
	TGuiHolidayRecTemplate m_tHolidayTemp;
}TGuiGetHolidayTempRsp;	//��ȡ���ռƻ�¼��ģ���Ӧ

#define GUI_SET_HOLIDAY_VR_TEMPLATE_REQ		307		//���ü��ռƻ�¼��ģ������
#define GUI_SET_HOLIDAY_VR_TEMPLATE_RSP		-307	//���ü��ռƻ�¼��ģ���Ӧ

typedef struct
{
	int m_iChn;
	TGuiHolidayRecTemplate m_tHolidayTemp;
}TGuiSetHolidayTempReq;		//���ü��ռƻ�¼��ģ������

#define GUI_SET_HOLIDAY_TEMP_OK   0  //���óɹ�
#define GUI_SET_HOLIDAY_TEMP_ERR  1	 //����ʧ��
typedef struct
{
	int m_iRetCode;
}TGuiSetHolidayTempRsp;		//���ü��ռƻ�¼��ģ���Ӧ

//=======================��֡¼��===============================
#define GUI_GET_TAKEIFRAME_TEMPLATE_REQ		308		//��ȡ�Ƿ��֡¼������
#define GUI_GET_TAKEIFRAME_TEMPLATE_RSP		-308	//��ȡ�Ƿ��֡¼���Ӧ

typedef struct
{
	int m_iChn;
}TGuiGetTakeIFrameTemplateReq;		//��ȡ�Ƿ��֡¼������

typedef struct
{
	int m_iChn;
	int m_iTakeIFrame;	 // 0 -����֡¼�� 1-��֡¼��
}TGuiGetTakeIFrameTemplateRsp;		//��ȡ�Ƿ��֡¼���Ӧ

#define GUI_SET_TAKEIFRAME_TEMPLATE_REQ		309		//�����Ƿ��֡¼������
#define GUI_SET_TAKEIFRAME_TEMPLATE_RSP		-309	//�����Ƿ��֡¼���Ӧ

#define GUI_SET_TAKEIFRAME_TEMPLATE_OK		0		//����¼��ģ��ɹ�
#define GUI_SET_TAKEIFRAME_TEMPLATE_ERR		1		//����¼��ģ��ʧ��
typedef struct
{
	int m_iChn;
	int m_iTakeIFrame; //0 -����֡¼��  1-��֡¼��
} TGuiSetTakeIFrameTemplateReq;		//�����Ƿ��֡¼������

typedef struct
{
	int m_iRetCode;
} TGuiSetTakeIFrameTemplateRsp;		//�����Ƿ��֡¼���Ӧ

//=================================
#define GUI_GET_SUBSTREAMREC_TEMPLATE_REQ		312		//��ȡ�Ƿ�����¼������
#define GUI_GET_SUBSTREAMREC_TEMPLATE_RSP		-312	//��ȡ�Ƿ�����¼���Ӧ

typedef struct
{
	int m_iChn;
}TGuiGetSubStreamRecTemplateReq;		//��ȡ�Ƿ���������¼������

typedef struct
{
	int m_iChn;
	int m_iSubStreamRec;	 			// 0 -�����ø�����¼�� 1-����(�������궨��)
}TGuiGetSubStreamRecTemplateRsp;		//��ȡ�Ƿ�����¼���Ӧ

//=================================
#define GUI_SET_SUBSTREAMREC_TEMPLATE_REQ		313		//�����Ƿ�����¼������
#define GUI_SET_SUBSTREAMREC_TEMPLATE_RSP		-313	//�����Ƿ�����¼���Ӧ

typedef struct
{
	int m_iChn;
	int m_iSubStreamRec; 		// 0 -�����ø�����¼�� 1-����(�������궨��)
} TGuiSetSubStreamRecTemplateReq;		//�����Ƿ�����¼������

typedef struct
{
	int m_iRetCode; 
} TGuiSetSubStreamRecTemplateRsp;		//�����Ƿ�����¼���Ӧ

//=================================

#define GUI_GET_VR_SMART_TEMPLATE_REQ	314			//��ȡ����¼��ģ������
#define GUI_GET_VR_SMART_TEMPLATE_RSP	-314		//��ȡ����¼��ģ���Ӧ
#define GUI_SET_VR_SMART_TEMPLATE_REQ	315			//��������¼��ģ������
#define GUI_SET_VR_SMART_TEMPLATE_RSP	-315		//��������¼��ģ���Ӧ

#define GUI_VR_TM_DAY_CNT  8

enum
{
	TEMPLATE_DISABLE,  //ģ�岻��Ч
	TIME_TEMPLATE_1,   //��ʱģ��1
	TIME_TEMPLATE_2,   //��ʱģ��2
};

typedef  struct
{
	int m_iChn;
}TGuiGetSmartTemplateReq;

//iTemplateType[x][x] ��ֵö�ٲο��������ͣ�Ĭ��Ϊ-1 
typedef struct
{
	int iTemplateType[GUI_VR_TM_DAY_CNT] [GUI_VR_TM_CNT_PER_DAY];   //ÿ��ͨ����Ӧÿ���Ӧ4��ʱ��Σ�ÿ��ʱ���һ��ģ�壬���±�����
}TGuiVideoRecSmartTemplate;


typedef struct
{
	int m_iChn;
	TGuiVideoRecSmartTemplate m_tSmartTempCnf;
} TGuiGetRecSmartTemplateRsp;  //��ȡ����¼��ģ���Ӧ

typedef struct
{
	int m_iChn;
	TGuiVideoRecSmartTemplate m_tSmartTempCnf;
} TGuiSetRecSmartTemplateReq; //��������¼��ģ������

//0��ɹ� 1��ʧ��
typedef struct
{
	int m_iRetCode;
} TGuiSetRecSmartTemplateRsp; //��������¼��ģ���Ӧ


//================ANR������¼=============
#define GUI_GET_CHN_ANR_ENABLE_REQ   	2030 //��ȡANRʹ��״̬����
#define GUI_GET_CHN_ANR_ENABLE_RSP   -2030//��ȡANRʹ��״̬��Ӧ
typedef struct
{
	int m_iChn;
}TGuiGetChnAnrEnableReq;

typedef struct
{
	int m_iChn;
	int m_iEnable;
}TGuiGetChnAnrEnableRsp;

#define GUI_SET_CHN_ANR_ENABLE_REQ 	2031//����ANRʹ��״̬����
#define GUI_SET_CHN_ANR_ENABLE_RSP	-2031//����ANRʹ��״̬��Ӧ
typedef struct
{
	int m_iChn;
	int m_iEnable;
}TGuiSetChnAnrEnableReq;

typedef struct
{
	int m_iRetCode;         //0��ɹ���1��ʧ��
}TGuiSetChnAnrEnableRsp;

//===================¼�����===================================


#define GUI_VRF_ENAME_LEN				5		//¼���ļ���չ������
#define GUI_VRF_PACK_BY_TIME			2		//��ʱ�䳤�ȴ��
#define GUI_VRF_PACK_BY_SIZE			1		//���ļ���С���

// ���̿ռ䲻��ʱ����
#define GUI_DEL_VRF_WHEN_DOS			1		//ɾ���ļ�
#define GUI_DEL_NA_VRF_WHEN_DOS			2		//ɾ���Ǳ���¼���ļ�
#define GUI_STOP_VR_WHEN_DOS			3		//ֹͣ¼��

typedef struct									//¼����Բ���
{
	char m_strRxtName[GUI_VRF_ENAME_LEN + 1];	//¼���ļ���չ��
	int m_iFilePackType;						//¼���ļ������ʽ
	int m_iFilePackTime;						//���ʱ��(��λ��)
	int m_iFilePackSize;						//�ߴ����С(��λK)
	int m_iActionWhenDiskOutOfSpace;			//���̿ռ䲻��ʱ�Ķ���(���1��3)
} TGuiVideoStrategy;

typedef struct									//��ȡ¼����Ի�Ӧ
{
	TGuiVideoStrategy m_tStrategy;
} TGuiGetVideoStrategyRsp;

typedef struct									//����¼���������
{
	TGuiVideoStrategy m_tStrategy;
} TGuiSetVideoStrategyReq;

#define GUI_SET_VR_STRATEGY_OK		0			//����¼����Գɹ�
#define GUI_SET_VR_STRATEGY_ERR		1			//����¼�����ʧ��
typedef struct									//����¼����Ի�Ӧ
{
	int m_iRetCode;
} TGuiSetVideoStrategyRsp;


// �ֶ�¼��
#define GUI_START_HUM_VIDEO		1			//�����ֶ�¼��
#define GUI_STOP_HUM_VIDEO		2			//ֹͣ�ֶ�¼��
#define GUI_START_ITS_ILLEGAL_VIDEO     69  //������ͨΥ��¼��
#define GUI_STOP_ITS_ILLEGAL_VIDEO      70  //ֹͣ��ͨΥ��¼��

typedef struct									//�ֶ�¼������
{
	int m_iChn;									//ͨ����(0-16, 0��ʾ���ȫ��ͨ��)
	int m_iCmd;									//�ֶ�¼������:����/ֹͣ
} TGuiHumRecVideoCmd;

//������µ��л�Ӧ���ֶ�¼������Э��
#define GUI_HUM_REC_VIDEO_CMD_REQ  352            //�ֶ�¼������
#define GUI_HUM_REC_VIDEO_CMD_RSP  -352            //�ֶ�¼������
typedef struct
{
	int m_iChn;              //ͨ����(0-16, 0��ʾ���ȫ��ͨ��)
	int m_iCmd;              //�ֶ�¼������:����/ֹͣ GUI_START_HUM_VIDEO /GUI_STOP_HUM_VIDEO
}TGuiHumRecVideoCmdReq;    //�ֶ�¼����������

#define GUI_HUM_REC_VIDEO_CMD_OK   0 //����ִ�гɹ�
#define GUI_HUM_REC_VIDEO_CMD_ERR  1 //����ִ��ʧ��
typedef struct
{
	int m_iRetCode;
}TGuiHumRecVideoCmdRsp;   //�ֶ�¼�������Ӧ

// ͨ��¼��
#define GUI_START_REC_CMD		1
#define GUI_STOP_REC_CMD		2
typedef struct
{
	int m_iChn;					//ͨ����(0��ȫ��,1-16��ͨ��)
	int m_iCmd;					//��ʼ/ֹͣ¼��
	int m_iType;				//¼������
} TGuiRecReq;

typedef struct
{
	int m_iRetCode;				//������, 0�ɹ�,����ʧ��
} TGuiRecRsp;

// ¼���ļ�
//����
typedef struct									//��ȡ¼���ļ���������
{
	int m_iChn;     //��ѯ��ͨ�� 
	int m_iYear;	//�� >= 2008
	int m_iMon;		//��: 1-12
} TGuiGetVideoFileMapReq;

typedef struct
{
	int m_iChn;
	int m_iYear;
	int m_iMon;
	int m_iFileMap[32];	//0��λ�ñ����������0, 1-31��λ�ô�Ŷ�Ӧ�����Ƿ���¼���־:0�ޣ�1��
} TGuiGetVideoFileMapRsp;

//����
#define GUI_GET_VIDEO_FILE_DAY_MAP_REQ  319     //��ȡ¼���ļ������������(1��)
#define GUI_GET_VIDEO_FILE_DAY_MAP_RSP  -319    //��ȡ¼���ļ�������ջ�Ӧ(1��)

#define GUI_MAX_VIDEO_SECT_PER_DAY 300  //ÿ��ͨ�����300��ʱ���
typedef struct
{
	int m_iChn;
	int m_iYear;
	int m_iMon;
	int m_iDay;
}TGuiGetVideoFileDayMapReq;

typedef struct
{
	int m_iChn;
	int m_iYear;
	int m_iMon;
	int m_iDay;
	int m_iCnt;  //¼�����
}TGuiGetVideoFileDayMapRsp;

typedef struct
{
	int m_iType; //¼������
	int m_iStartTime;
	int m_iEndTime;
}TGuiGetVideoFileDayMapMsg;  //¼���ļ���Ϣ


typedef enum
{
	GUI_VIDEO_FILE = 1,
	GUI_IMAGE_FILE,
}EGuiFileType;

#define GUI_GET_VIDEO_FILE_MAP_REQ_EX	1319		//��ȡ¼���ļ���������(һ������Щ����¼��)
#define GUI_GET_VIDEO_FILE_MAP_RSP_EX	-1319	//��ȡ¼���ļ����ջ�Ӧ
typedef struct									//��ȡ¼���ļ���������
{
	int m_iChn;   		  //��ѯ��ͨ�� 
	int m_iYear;			//�� >= 2008
	int m_iMon;			//��: 1-12
	int m_iFileType;			//��ö��EGuiFileType
	int m_iRecordType;		//��ö��EGuiRecType
} TGuiGetVideoFileMapReqEx;
typedef TGuiGetVideoFileMapRsp TGuiGetVideoFileMapRspEx;

#define GUI_GET_VIDEO_FILE_DAY_MAP_REQ_EX		1320	//��ȡ¼���ļ���������(����)
#define GUI_GET_VIDEO_FILE_DAY_MAP_RSP_EX		-1320	//��ȡ¼���ļ����ջ�Ӧ
typedef struct
{
	int m_iChn;
	int m_iYear;
	int m_iMon;
	int m_iDay;
	int m_iFileType;
	int m_iRecordType;
}TGuiGetVideoFileDayMapReqEx;

typedef TGuiGetVideoFileDayMapRsp TGuiGetVideoFileDayMapRspEx;


//====================================
//¼���ѯ
#define GUI_QUERY_VIDEO_FILE_REQ	321			//��ѯ¼���ļ�����
#define GUI_QUERY_VIDEO_FILE_RSP	-321		//��ѯ¼���ļ���Ӧ

typedef struct									//¼���ļ���ѯ����
{
	int m_iChn;									//ͨ���� ��16λ0-������1-������
	int m_iDev;									//0~7λ��ATM�������ͣ�8~15ATM�쳣��16~23ATM�˿ں�24�Ǽ����ļ���25~31Ԥ��
	int m_iType;								//¼���ļ�����
	int m_iTypeRange;                        //¼��Χ
	int m_iBeginTm;							//��ʼʱ��
	int m_iEndTm;								//����ʱ��
} TGuiVideoFileQueryCondition;

typedef struct									//ͳ��¼���ļ�����
{
	TGuiVideoFileQueryCondition m_tCondition;	//��ѯ����
} TGuiCountVideoFileReq;

typedef struct									//ͳ��¼���ļ���Ӧ
{
	int m_iVideoFileCnt;						//¼���ļ��ܸ���
} TGuiCountVideoFileRsp;

typedef struct									//��ѯ¼���ļ�����
{
	TGuiVideoFileQueryCondition m_tCondition;	//��ѯ����
	int m_iPageId;								//ҳ��(��һҳΪ0)
	int m_iRcntPerPage;						//ÿҳ��¼����
} TGuiQueryVideoFileReq;

typedef struct									//��ѯ¼���ļ���Ӧ
{
	int m_iCnt;									//�δ˲��¼���ļ�����
} TGuiQueryVideoFileRsp;						//�������Ӧ������¼���ļ�Դ��
//====================================


typedef long long TGuiVideoFileId;			//¼���ļ��������
typedef struct									//¼���ļ�����
{
	#if 0 //�ļ����δ��
	TGuiVideoFileId m_tFileId;					//¼���ļ����
	#endif
	char m_strFileName[GUI_VF_NAME_LEN + 1];	//¼���ļ���
	unsigned int m_uiFileSize;					//¼���ļ���С
	int m_iBeginTm;							//¼���ļ���ʼʱ��
	int m_iEndTm;								//¼���ļ�����ʱ��
	int m_iChn;									//¼���ļ���Ӧ��ͨ����
	int m_iDev;									//¼���ļ���Ӧ���豸��
	int m_iType;								//¼���ļ�����
} TGuiVideoFileMsg;

typedef struct									//����¼���ļ�����
{
	#if 0
	TGuiVideoFileId m_tFileId;					//¼���ļ����
	#endif
	char m_strFileName[GUI_VF_NAME_LEN + 1];	//¼���ļ���
	int m_iDstDevId;							//Ŀ¼�豸��
} TGuiVideoFileBackupReq;

#define GUI_BACKUP_VIDEO_FILE_OK			0	//����¼���ļ��ɹ�
#define GUI_BACKUP_VIDEO_FILE_ERR			1	//����¼���ļ�ʧ��
#define GUI_BACKUP_VIDEO_FILE_NO_DEV		2	//�Ҳ����豸����
#define GUI_BACKUP_VIDEO_FILE_NO_SPACE		3	//���̿ռ䲻�����
typedef struct									//����¼���ļ���Ӧ
{
	int m_iRetCode;
} TGuiVideoFileBackupRsp;

typedef struct									//ɾ��¼���ļ�����
{
	#if 0 //�ļ����δ��
	TGuiVideoFileId m_tFileId;					//¼���ļ����
	#endif
	char m_strFileName[GUI_VF_NAME_LEN + 1];	//¼���ļ���	
} TGuiVideoFileDeleteReq;

#define GUI_DEL_VIDEO_FILE_OK			0		//ɾ���ļ��ɹ�
#define GUI_DEL_VIDEO_FILE_ERR			1		//ɾ���ļ�ʧ��
typedef struct									//ɾ��¼���ļ���Ӧ
{
	int m_iRetCode;							//������
} TGuiVideoFileDeleteRsp;

#define  GUI_DSP_VIDEOFILE_BYPIC_REQ  	  2302      //�����ѯ¼������ͼ����ʾ
#define  GUI_DSP_VIDEOFILE_BYPIC_RSP	  -2302    //��Ӧ��ѯ¼������ͼ����ʾ
typedef struct
{
	char  m_strVFileName[GUI_VF_NAME_LEN + 1];     //�ļ���
	char  m_strPicPath[GUI_PUBLIC_LEN_63 + 1];       //�ں˴��I֡bmp��·��,uiָ��
}TGuiDspVFByPicReq;

typedef struct
{
	int  m_iRetCode;          //����ֵ
}TGuiDspVFByPicRsp;

//�ؽ�����
typedef struct									//�ؽ�������Ӧ
{
	int m_iRebuildId;							//�ؽ�������ʶ��(С��0��ܾ���������ֵΨһ��ʶ�˴��ؽ�����)
} TGuiRebuildIndexRsp;

typedef struct									//��ȡ����״̬����
{
	int m_iRebuildId;							//�ؽ�������ʶ��
} TGuiGetRebuildIndexStaReq;

#define GUI_REBUILD_INDEX_ERR		0			//�ؽ�������������
#define GUI_REBUILD_INDEX_DOING		1			//�ؽ�����������
#define GUI_REBUILD_INDEX_DONE		2			//�ؽ��������
typedef struct									//��ȡ����״̬��Ӧ
{
	int m_iState;								//״̬��
	int m_iProgress;							//��ǰ����0-100(�����������֧�����0)
} TGuiGetRebuildIndexStaRsp;

//¼��ط�
typedef struct									//¼��ط�����
{
	int m_iVoId;								//VOͨ����(��ʱ����)
	char m_strFile[GUI_VF_NAME_LEN + 1];		//�����ŵ�¼���ļ�
	int m_iSoundEnable;						//����ʹ��(0/1)
} TGuiVideoPlayReq;

#define GUI_VIDEO_PLAY_OK				0		//¼��ط�����ɹ�
#define GUI_VIDEO_PLAY_FILE_LOST		1		//¼���ļ�������
#define GUI_VIDEO_PLAY_FILE_FERR		2		//�޷��򿪻��߲���ָ�����ļ�
typedef struct									//¼��طŻ�Ӧ
{
	int m_iRetCode;							//������
	int m_iPlayId;								//¼��طű�ţ����Ըôβ��ŵ���ز�����
												//�Դ˺ű�ʶ
	long long m_llFrameCnt;					//��֡��
	int m_iFrameRate;							//֡�ʣ�ÿ��طŵ�֡��
} TGuiVideoPlayRsp;

typedef struct									//¼��ط���ͣ����
{
	int m_iPlayId;								//�طű�ţ���GuiVideoPlayRspָ��
} TGuiVideoPlayPauseReq;

typedef struct									//¼���ļ��̲�������
{
	int m_iPlayId;								//�طű��
} TGuiVideoPlayCntnReq;

typedef struct									//¼���ļ�����ֹͣ����
{
	int m_iPlayId;
} TGuiVideoPlayStopReq;

typedef struct									//��֡����(�޻�Ӧ)
{
	int m_iPlayId;								//���ű��
	int m_iType;								//��������(1:����, -1����)
} TGuiVideoPlayStepCmd;

typedef struct									//���Ŷ�λ����(�޻�Ӧ)
{
	int m_iPlayId;								//���ű��
	int m_iLoc;									//��λ�ٷֱ�(0-100)
} TGuiVideoPlayLocCmd;

//========================¼�񵹷�====================
#define GUI_VIDEO_PLAY_REVERSE_REQ	            348    //����
typedef struct									//¼��طŵ�������
{
	int m_iPlayId;								//�طű�ţ���GuiVideoPlayRspָ��
} TGuiVideoPlayReverseReq;

//========================¼��ط���ץ��=============
#define GUI_VIDEO_PLAY_SNAP_REQ					349    //�ط�ץ��
typedef struct									//¼��ط�ץ������
{
	int m_iPlayId;								//�طű�ţ���GuiVideoPlayRspָ��
} TGuiVideoPlaySnapReq;

//-----------------------ATM¼���ѯ��λ-----------------------------------------------
//ATM ���ݲ���ʱ�䶨λ¼��
#define GUI_PLAY_VIDEO_LOCEX_REQ		345		//������ʱ�䶨λ
typedef struct
{
	int m_iPlayId;				//���ű��
	int m_iAbsLocTm;			//����ʱ��
}TGuiVideoPlayLocCmdEx; //������ʱ�䶨λ

//����¼���ѯ
#define GUI_QUERY_ATM_VIDEO_FILE_REQ		346
#define GUI_QUERY_ATM_VIDEO_FILE_RSP		-346

#define MAX_CRADNO_LEN		64
#define MAX_FILED_NUM       5   //5���ֶ�

typedef enum
{
	QUERY_BY_CARDNO = 0,    //�����Ų�ѯ
	QUERY_BY_FIELD,			//�����ѯ
}TAtmQueryType;      //����¼���ѯ��ʽ����Ϊ�����źͰ����ѯ

typedef enum
{
	ATM_OPERATE_ALL = 0,	//ȫ��
	ATM_QUERY,				//��ѯ
	ATM_TAKE,				//ȡ��
	ATM_CHANGEPASSWD,		//����
	ATM_TRANSFER,			//ת��
	ATM_DEPOSIT,			//���
	ATM_QUERY_NOCARD,		//�޿���ѯ
	ATM_DEPOSIT_NOCARD,		//�޿����
	ATM_OTHER,				//����
	ATM_INSERT_CARD,    	//�忨
	ATM_REMOVE_CARD,		//�ο�
	ATM_NULL = 0xff,		//�޲���
}TAtmOperateType;

typedef enum
{
	EXCEPTION_ALL = 0,			//ȫ��	
	EXCEPTION_EATMONEY,		//�̳�
	EXCEPTION_EATCARD,			//�̿�
	EXCEPTION_NULL = 0xff,		//���쳣
}TAtmExpType;

typedef struct
{
	int  iType;                     //0Ϊ�����Ų�ѯ��1Ϊ�����ѯ
	char m_cCardNum[MAX_FILED_NUM][MAX_CRADNO_LEN + 1];	  //���� �����ã����ǿ��ţ����ַ�������ֱ�Ϊ���š��������͡����쳣����������ֱ�Ϊ��1-��4
}TAtmFileInfo;

typedef struct									//ͳ��¼���ļ�����
{
	TGuiQueryVideoFileReq m_tBaseCondition;	//��ѯ����
	TAtmFileInfo	m_tCardCondition;	//���Ų�ѯ����
} TGuiQueryVideoFileExReq;        //��չ�Ŀ��Ų�ѯ¼��

#define GUI_QUERY_VIDEO_FILE_BEGIN_END_TM_REQ		347   //��ѯ¼���ļ��Ŀ�ʼʱ�����ʱ������
#define GUI_QUERY_VIDEO_FILE_BEGIN_END_TM_RSP		-347  //��ѯ¼���ļ��Ŀ�ʼʱ�����ʱ���Ӧ
typedef struct
{
	char m_strFileName[GUI_VF_NAME_LEN + 1];	//¼���ļ���	
}TGuiQueryVideoFileBeginEndTmReq;

typedef struct
{
	char m_strFileName[GUI_VF_NAME_LEN + 1];	//¼���ļ���	
	int m_iFileBeginTm;                        //�ļ���ʼʱ��
	int m_iFileEndTm;                          //�ļ�����ʱ��
}TGuiQueryVideoFileBeginEndTmRsp;

//====================��ʱ�ط�=======================
#define GUI_VIDEO_INSTANT_PLAY_REQ     1100   //��ʱ�ط�����
#define GUI_VIDEO_INSTANT_PLAY_RSP	   -1100  //��ʱ�طŻ�Ӧ

typedef struct
{
	int	m_iChn;            //ͨ����
	int	m_iVoDevId; 
	int	m_iVoChn;
	int	m_iTime;
}TGuiVideoInstantPlayReq;

typedef struct
{
	int m_iPlayId;  //-1��ʾʧ�ܣ������ʾid
} TGuiVideoInstantPlayRsp;    //0��ɹ��������ʾʧ��

//============��ǩ�ط�============
//��ǩ����ɾ�Ĳ�
typedef struct
{
	int m_iTagTm;              //��ǩʱ�䣨������Ϣһ�£�
	int m_iTagChn;              //��ǩ����¼���ļ���VO ID
	char m_strFileName[GUI_VF_NAME_LEN + 1];//¼���ļ���
	char m_strTagName[GUI_PUBLIC_LEN_63 + 1];   //��ǩ����   
}TGuiVpTagMsg;     //��ǩ�ṹ��

#define GUI_ADD_VP_TAG_REQ	 1110    //���ӱ�ǩ
#define GUI_ADD_VP_TAG_RSP    -1110
typedef struct
{
	TGuiVpTagMsg m_tVpTagMsg;   
}TGuiAddVpTagReq;                  //���ӱ�ǩ����

typedef struct
{
	int m_iRetCode; //0��ʾ�ɹ���1��ʾ�����ļ���64����ǩ��2��ʾ�������е�ʧ�������3��ʾ����¼��
	int m_iTagTm;   //���ر�ǩ��ʵ��ʱ��
} TGuiAddVpTagRsp;     
      
#define GUI_ADD_VP_TAG_REQ_EX	 	5110    //���ӱ�ǩ
#define GUI_ADD_VP_TAG_RSP_EX   	 -5110
typedef struct
{
	TGuiVpTagMsg m_tVpTagMsg;   
}TGuiAddVpTagReqEx;                  //���ӱ�ǩ����

typedef struct
{
	int m_iRetCode; //0��ʾ�ɹ���1��ʾ�����ļ���64����ǩ��2��ʾ�������е�ʧ�������3��ʾ����¼��
	TGuiVpTagMsg m_tVpTagMsg;   //���ر�ǩ�ľ�����Ϣ
} TGuiAddVpTagRspEx;    

      
#define GUI_DELETE_VP_TAG_REQ 	1111	    //ɾ����ǩ
#define GUI_DELETE_VP_TAG_RSP	-1111
typedef struct
{
	TGuiVpTagMsg m_tVpTagMsg;   
}TGuiDelVpTagReq;                  //ɾ����ǩ����

typedef struct
{
	int m_iRetCode;
} TGuiDelVpTagRsp;

#define GUI_MODIFY_VP_TAG_REQ 	1112	    //�༭��ǩ
#define GUI_MODIFY_VP_TAG_RSP	-1112

typedef struct
{
	TGuiVpTagMsg m_tVpTagMsg;   
}TGuiEditVpTagReq;                  //��ǩ����

typedef struct
{
	int m_iRetCode;
} TGuiEditVpTagRsp;

#define GUI_SEARCH_VP_TAG_REQ	1113    //������ǩ
#define GUI_SEARCH_VP_TAG_RSP	-1113

typedef struct
{
	TGuiQueryVideoFileReq m_tBaseCondition;
	char m_strTagName[GUI_PUBLIC_LEN_63 + 1];//����Ϊ�ձ�ʾȫ����ȡ�����򰴹ؼ��ֻ�ȡ
}TGuiSearchVpTagReq;

#define GUI_MAX_VPTAG_CNT_PER_FILE	64   //ÿ���ļ����֧��64����ǩ
//��ѯʱ���ȷ����ļ�����������������TGuiSearchVpTagRetRsp
typedef TGuiQueryVideoFileRsp TGuiQueryVideoTagRsp;

typedef struct
{
	int m_iFB;   //�ļ���ʼʱ��
	int m_iFE;	 //��ǩ�����ļ��Ľ���ʱ��
	TGuiVpTagMsg m_tVpTagMsg;
}TGuiSearchVpTagRetRsp;

//==============�ⲿ�ļ�����============
#define  	 GUI_OUTSIDE_PLAY_VF_REQ	 1114    //�����ⲿ�ļ�����
#define	 GUI_OUTSIDE_PLAY_VF_RSP	 -1114    //�����ⲿ�ļ���Ӧ

#define GUI_VF_NAME_LEN_EX		127	   //¼���ļ�����·��
typedef struct
{
	int m_iVoId;				     //VOͨ����(��ʱ����)	
	int m_iSoundEnable;
	char m_strOutFile[GUI_VF_NAME_LEN_EX + 1];   //¼���ļ���
}TGuiOutSideVideoPlayReq;

typedef TGuiVideoPlayRsp	TGuiOutSideVpRsp;  //����֮ǰ�Ľṹ��

#define GUI_GET_OUTSIDE_VF_TM_REQ	1115	//��ȡ�ⲿ�ļ���ֹʱ�������
#define GUI_GET_OUTSIDE_VF_TM_RSP	-1115	//��ȡ�ⲿ�ļ���ֹʱ��Ļ�Ӧ

typedef  struct
{
	char m_strOutFile[GUI_VF_NAME_LEN_EX + 1];   //¼���ļ��� 
}TGuiGetOutSideVfTmReq;

typedef struct
{
	int m_iChn;					//�ļ�����ͨ����
	int m_iBeginTm;					//�ļ���ʼʱ��
	int m_iEndTm;					//�ļ�����ʱ��
	char m_strOutFile[GUI_VF_NAME_LEN_EX + 1];   //¼���ļ��� 
}TGuiGetOutSideVfTmRsp;
//=========end============================


//----------------------------------------------------------------------
typedef struct									//��ȡ��ǰ�ط�״̬����
{
	int m_iPlayId;
} TGuiGetVideoPlayStaReq;

#define GUI_VIDEO_PLAY_DOING		1			//���ڲ���״̬
#define GUI_VIDEO_PLAY_PUASED		2			//��ͣ״̬
#define GUI_VIDEO_PLAY_STOPED		3			//������ֹͣ
#define GUI_VIDEO_PLAY_STEP			4			//����״̬
#define GUI_VIDEO_PLAY_REVERSE		5			//����״̬
#define GUI_VIDEO_PLAY_STEP_REVERSE	6			//����״̬

#define GUI_VIDEO_PLAY_ERR			100			//���ŷ�������
#define GUI_VIDEO_PLAY_NEED_PWD		200			//�ȴ�����
//�����ĸ���Ӧͬ���ط� ��λ��
#define CHN_PLAY_PWD(n) 			(200 + (1<<(n - 1))) // n ����Ŵ�1��ʼ
#define GUI_VIDEO_PLAY_NEED_PWD_1  201      //��һ������Ҫ����
#define GUI_VIDEO_PLAY_NEED_PWD_2  202      //�ڶ�������Ҫ����
#define GUI_VIDEO_PLAY_NEED_PWD_3  204      //����������Ҫ����
#define GUI_VIDEO_PLAY_NEED_PWD_4  208      //���Ļ�����Ҫ����

#define GUI_VD_VCA_PLAY_NEED_PWD	-1		//���������û�������Ҫ����

#define GUI_VIDEO_PLAY_DECODE_CAP_LIMIT	300         //�طŽ������ܲ���
#define GUI_VIDEO_PLAY_SPEED_CAP_LIMIT  301			//�ط��ٶ��������ޣ�ֻ��Խ�����

typedef struct									//��ȡ��ǰ�ط�״̬��Ӧ
{
	int m_iPlayId;								//�������к�
	int m_iCurPlayStat;						//��ǰ����״̬
	int m_iPlayRate;							//��ǰ���ŵĽ���(0-100000)
	int m_iSpeed;								//��ǰ���ű���(������٣��������, 0����)
} TGuiGetVideoPlayStatRsp;

#define GUI_PLAYER_MAX_VO_CNT		4			//���������֧�ֻ�����

typedef struct									//������VO����
{
	int m_iLeft;								//���Ͻ�x����
	int m_iTop;									//���Ͻ�y����	
	int m_iWidth;
	int m_iHeight;
} TGuiVoAttr;

typedef struct									//�����������ʼ����Ϣ
{
	int m_iDevId;								//����豸���,dxl 2009/12/02
	int m_iVoCnt;								//������VO������
	// 2008-12-17 dxl ���Vo����
	TGuiVoAttr m_tVoAttrs[GUI_PLAYER_MAX_VO_CNT];
} TGuiVideoPlayerActiveMsg;

typedef TGuiVideoPlayerActiveMsg TGuiVideoPlayerActiveReq;

#define GUI_VIDEO_PLAYER_ACTIVE_OK	0		//��ʼ���ɹ�
#define GUI_VIDEO_PLAYER_ACTIVE_ERR	1		//��ʼ��ʧ��
typedef struct									//�����������ʼ�������Ӧ
{
	int m_iRetCode;
} TGuiVideoPlayerActiveRsp;

typedef struct									//���ű�������
{
	int m_iPlayId;								//���ű��
	int m_iSpeed;								//��n��ʾ��ǰ����xn����, -n��ʾ/n����
} TGuiVideoPlayChgSpeedCmd;

typedef struct									//���/��������
{
	int m_iPlayId;								//���ű��
	int m_iSpeed;								//��n��ʾn���ٲ���,-n��ʾ1/n���ٲ���(1, 0, -1����ʾ�����ٲ���)
} TGuiVideoPlaySpeedCmd;

typedef struct									//ȫ����������
{
	int m_iVoId;								//�����(1-4)
} TGuiVideoPlayFullScrReq;

#define GUI_VIDEO_PLAY_FULL_SCR_OK		0		//ȫ�����ųɹ�
#define GUI_VIDEO_PLAY_FULL_SCR_ERR		1		//ȫ������ʧ��
typedef struct									//ȫ�����Ż�Ӧ
{
	int m_iRetCode;
} TGuiVideoPlayFullScrRsp;

typedef struct									//�˳�ȫ����������
{
	int m_iVoId;								//�����(1-4)
} TGuiVideoPlayFullScrExitReq;

#define GUI_VIDEO_PLAY_FULL_SCR_EXIT_OK		0		//�˳�ȫ�����ųɹ�
#define GUI_VIDEO_PLAY_FULL_SCR_EXIT_ERR	1		//�˳�ȫ������ʧ��
typedef struct									//�˳�ȫ�����Ż�Ӧ
{
	int m_iRetCode;
} TGuiVideoPlayFullScrExitRsp;

typedef struct									//���ûط���������
{
	int m_iActiveVoId;		//��ǰ������������ͨ����1-4��ʾ�л�������ֵ�޲���
	int m_iSoundEnFlg;		// 1 - 4    :��ʹ��ָ��ͨ�����������
							// - 1 - -4 :  �ر�ָ��ͨ�����������(voͨ����ȡ����ֵ)
} TGuiVideoPlaySetSoundReq;

#define	GUI_VPLAY_SET_SOUND_OK		0		//���ûط������ɹ�
#define GUI_VPLAY_SET_SOUND_ERR		1		//���ûط�����ʧ��
typedef struct									//���ûط�������Ӧ
{
	int m_iRetCode;		//�����룬GUI_VPLAY_SET_SOUND_OK/ERR
} TGuiVideoPlaySetSoundRsp;

//ͬ���ط�
#define GUI_VIDEO_SYNC_PLAYER_ACTIVE_OK	0		//��ʼ���ɹ�
#define GUI_VIDEO_SYNC_PLAYER_ACTIVE_ERR	1		//��ʼ��ʧ��

#define GUI_SYNC_PLAY_SOUND_ENABLE 1
#define GUI_SYNC_PLAY_SOUND_DISABLE 0

typedef struct									//¼���ļ���ѯ����
{
	int m_iChn[4];									//ͨ����
	int m_iDev;									//�豸��
	int m_iBeginTm;							//��ʼʱ��
	int m_iEndTm;								//����ʱ��
	int m_iSoundEnable[4];
} TGuiVideoFileQuerySyncCondition;


typedef struct
{
	int m_iCmd;									//������
	int m_iLength;								//pdu���س���
	char m_cPayload[0];						//ʵ������
} TGuiSyncParamPdu;								//���ݴ��䵥Ԫ�ṹ

typedef struct									//�����������ʼ����Ϣ
{
	int m_iDevId;								//�豸��
	int m_iVoCnt;								//������VO������
	// 2008-12-17 dxl ���Vo����
	TGuiVoAttr m_tVoAttrs[GUI_PLAYER_MAX_VO_CNT];
} TGuiVideoSyncPlayerActiveMsg;
/********************************************/
//��ͬ���ط�
#define GUI_SYNC_PLAYER_VIDEO_FILE_REQ 	368			//ͬ�����󲥷��ļ�
#define GUI_SYNC_PLAYER_VIDEO_FILE_RSP  -368		//ͬ�������ļ������Ӧ

#define GUI_SYNC_PLAYER_MAX_CNT   16
typedef struct									//¼���ļ���ѯ����
{
	int m_iChn[GUI_SYNC_PLAYER_MAX_CNT];	//ͨ���Ÿ�16λ0-������1-������
	int m_iDev;								//�豸��
	int m_iBeginTm;							//��ʼʱ��
	int m_iEndTm;							//����ʱ��
	int m_iSoundEnable[GUI_SYNC_PLAYER_MAX_CNT];
} TGuiSyncPlayerVideoQueryConditionReq;

typedef struct
{
	int m_iRetCode;
}TGuiSyncPlayerVideoQueryConditionRsp;

#define GUI_VIDEO_SYNC_PLAYER_COORDIRATE_REQ 369	//��������,��������ʼ������
#define GUI_VIDEO_SYNC_PLAYER_COORDIRATE_RSP -369	//��������ʼ�������Ӧ

typedef struct									//�����������ʼ����Ϣ
{
	int m_iDevId;								//�豸��
	int m_iVoCnt;								//������VO������
	// 2008-12-17 dxl ���Vo����
	TGuiVoAttr m_tVoAttrs[GUI_SYNC_PLAYER_MAX_CNT];
} TGuiSyncPlayerActiveMsgReq;
typedef struct
{
	int m_iRetCode;
}TGuiSyncPlayerActiveMsgRsp;



typedef struct									//�����������ʼ�������Ӧ
{
	int m_iRetCode;
} TGuiVideoSyncPlayerActiveRsp;

typedef struct									//���Ŷ�λ����(�޻�Ӧ)
{
	int m_iLoc;									//��λ�ٷֱ�(0-100)
} TGuiVideoSyncPlayLocCmd;
typedef struct									//���ű�������
{
	int m_iSpeed;								//��n��ʾ��ǰ����xn����, -n��ʾ/n����
} TGuiVideoSyncPlayChgSpeedCmd;

typedef struct									//���ű�������
{
	int m_iSpeed;								//��n��ʾ��ǰ����xn����, -n��ʾ/n����
} TGuiVideoSyncPlaySpeedCmd;


typedef struct									//��ȡ��ǰ�ط�״̬��Ӧ
{
	int m_iCurPlayStat;						//��ǰ����״̬
	int m_iPlayRate;							//��ǰ���ŵĽ���(0-100000)
	int m_iSpeed;								//��ǰ���ű���(������٣��������, 0����)
} TGuiGetVideoSyncPlayStatRsp;

typedef struct									//ȫ����������
{
	int m_iVoId;								//�����(1-4)
} TGuiVideoSyncPlayFullScrReq;

#define GUI_VIDEO_SYNC_PLAY_FULL_SCR_OK	0		//ȫ�����ųɹ�
#define GUI_VIDEO_SYNC_PLAY_FULL_SCR_ERR	1		//ȫ������ʧ��
typedef struct									//ȫ�����Ż�Ӧ
{
	int m_iRetCode;
} TGuiVideoSyncPlayFullScrRsp;

#define GUI_VIDEO_SYNC_PLAY_FULL_SCR_EXIT_OK		0		//�˳�ȫ�����ųɹ�
#define GUI_VIDEO_SYNC_PLAY_FULL_SCR_EXIT_ERR	1		//�˳�ȫ������ʧ��
typedef struct									//�˳�ȫ�����Ż�Ӧ
{
	int m_iRetCode;
} TGuiVideoSyncPlayFullScrExitRsp;

typedef struct									//�˳�ȫ����������
{
	int m_iVoId;								//�����(1-4)
} TGuiVideoSyncPlayFullScrExitReq;

typedef struct									//���Ż�Ӧ
{
	int m_iRetCode;
} TGuiVideoSyncPlayVideoRsp;

typedef struct									//���ûط���������
{
	int m_iActiveVoId;		//��ǰ������������ͨ����1-4��ʾ�л�������ֵ�޲���
	int m_iSoundEnFlg;		// 1 - 4    :��ʹ��ָ��ͨ�����������
							// - 1 - -4 :  �ر�ָ��ͨ�����������(voͨ����ȡ����ֵ)
} TGuiVideoSyncPlaySetSoundReq;

#define	GUI_SYNC_VPLAY_SET_SOUND_OK		0		//���ûط������ɹ�
#define GUI_SYNC_VPLAY_SET_SOUND_ERR		1		//���ûط�����ʧ��

typedef struct									//���ûط�������Ӧ
{
	int m_iRetCode;		//�����룬GUI_VPLAY_SET_SOUND_OK/ERR
} TGuiVideoSyncPlaySetSoundRsp;

#define GUI_SYNC_PLAY_VIDEO_REVERSE_REQ   367 //ͬ���طŵ�������


// ץ�����

// ���ȣ�UI����������jpeg�����ʼ������(GUI_JPEG_VIEWER_INIT_REQ)
// ������ӵ������ʼ����Դ����ӦGUI_JPEG_VIEWER_INIT_ESP
typedef struct
{
	int m_iDevId;		//�豸��
} TGuiJpegViewerInitReq;

#define GUI_JPEG_VIEWER_INIT_OK		0		//jpeg�����ʼ���ɹ�
#define GUI_JPEG_VIEWER_INIT_ERR		1		//jpeg�����ʼ��ʧ��
typedef struct									//jpeg�����ʼ����Ӧ
{
	int m_iRetCode;
} TGuiJpegViewerInitRsp;

// ��ʼ���ɹ���UI��ʱ����������������jpeg��ʾ����
typedef struct
{
	char m_strJpegFile[GUI_VF_NAME_LEN + 1];
} TGuiJpegDspReq;

#define GUI_JPEG_DSP_OK				0		//jpeg��ʾ�ɹ�
#define GUI_JPEG_DSP_ERR				1		//jpeg��ʾʧ��
typedef struct
{
	int m_iRetCode;
} TGuiJpegDspRsp;

// ���UI֪ͨ���������jpeg���(GUI_JPEG_VIEWER_EXIT_MSG)��
// ������Ӧ���ͷ�jpeg��ʾ��ص���Դ����
// ��dvr�ָ�����ʼ��jpeg���ǰ��״̬��


//==============================��̨����=================================
//-----------------------------����������--------------------------------


typedef struct									//��ȡ��������������
{
	int m_iChn;									//ͨ����
} TGuiGetPtzDecodeCnfReq;

#define GUI_PTZ_DEC_PRO_NAME_LEN		31		//������Э��������

typedef struct
{
	int m_iAddr;								//��ַ
	#if 1
	char m_strProtocol[GUI_PTZ_DEC_PRO_NAME_LEN + 1]; //Э����
	#else
	int m_iProtocol;							//Э����
	#endif
	int m_iSportId;							//���ڱ��
	int m_iComAttrEn;							//�Զ��崮������ʹ�ܱ�ʶ
	int m_iBitRate;							//������
	int m_iDataBits;							//����λ
	int m_iStopBits;							//ֹͣλ
	int m_iCheckType;							//У��λ	
} TGuiPtzDecodeCnf;

typedef struct									//��ȡ������������Ӧ
{
	int m_iChn;									//ͨ����
	TGuiPtzDecodeCnf m_tCnf;					//������Ϣ
} TGuiGetPtzDecodeCnfRsp;

typedef struct									//���ý�������������
{
	int m_iChn;									//ͨ����
	TGuiPtzDecodeCnf m_tCnf;					//������Ϣ
} TGuiSetPtzDecodeCnfReq;

#define GUI_SET_PTZ_DECODE_CNF_OK	0		//���ò����ɹ�
#define GUI_SET_PTZ_DECODE_CNF_ERR	1		//���ò���ʧ��

typedef struct									//���ý�����������Ӧ
{
	int m_iRetCode;							//������
} TGuiSetPtzDecodeCnfRsp;

typedef struct 								//��ȡЭ���б��Ӧ
{
	int m_iProtocolCnt;							//Э������
} TGuiGetProtocolListRsp;

typedef struct 								//Э���б���
{
	#if 0
	int m_iProtocolId; 							//Э��Ψһ���
	#endif
	int m_iExistProtocol;      //1Ϊ����Э�飬0Ϊ����ӵ�Э��
	char m_strProtocolName[GUI_PTZ_DEC_PRO_NAME_LEN + 1]; //Э����
} TGuiProtocolListItem;

typedef struct 								//��ȡЭ���б��Ӧ
{
	int m_iProtocolCnt;							//Э������
} TGuiSetProtocolListReq;

//------------------------------��̨����---------------------------------

typedef struct									//��ȡԤ��λ�б�����
{
	int m_iChn;									//ͨ�����
} TGuiGetPtzPresetPointListReq;

typedef struct									//��ȡԤ��λ�б��Ӧ
{
	int m_iChn;									//ͨ�����
	int m_iCnt;									//Ԥ��λ����
} TGuiGetPtzPresetPointListRsp;
//����������͸���Ԥ�õ�ı��,�����α�ʽ


#define GUI_PTZ_MAX_POINT_PER_ROUTE		32	//ÿ��Ѳ��·������������Ѳ������
#define GUI_PTZ_MAX_ROUTE_PER_CHN		8	//ÿ��ͨ���������Ѳ��·����

typedef struct									//Ѳ����
{
	int m_iPointId;							//Ԥ��λ���
	int m_iSpeed;								//Ѳ���ٶ�
	int m_iDelay;								//ͣ��ʱ��(��λ:s)
} TGuiPtzCruiseRoutePoint;

typedef struct									//Ѳ��·��
{
	int m_iEnable;								//ʹ�ܱ�ʶ(1ʹ��/0δʹ��)
	int m_iPointCnt;							//Ѳ������
	TGuiPtzCruiseRoutePoint m_tPoints[GUI_PTZ_MAX_POINT_PER_ROUTE]; //Ѳ����
} TGuiPtzCruiseRoute;

typedef struct									//��ȡѲ��·������
{
	int m_iChn;									//ͨ����
} TGuiGetPtzCruiseRouteReq;

typedef struct									//��ȡѲ��·����Ӧ
{
	int m_iChn;									//ͨ����(0��ʾ��ȡʧ��)
	TGuiPtzCruiseRoute m_tRoutes[GUI_PTZ_MAX_ROUTE_PER_CHN]; //ͨ����Ӧ��Ѳ��·��
} TGuiGetPtzCruiseRouteRsp;

typedef struct									//����Ѳ��·������
{
	int m_iChn;									//ͨ����
	TGuiPtzCruiseRoute m_tRoutes[GUI_PTZ_MAX_ROUTE_PER_CHN]; //ͨ����Ӧ��Ѳ��·��
} TGuiSetPtzCruiseRouteReq;

#define GUI_SET_PTZ_CRUISROUTE_OK	0		//���óɹ�
#define GUI_SET_PTZ_CRUISROUTE_ERR	1		//����ʧ��
typedef struct									//����Ѳ��·����Ӧ
{
	int m_iRetCode;							//������
} TGuiSetPtzCruiseRouteRsp;

//ע�⣬UI��Ԥ��λ��Ŵ�1��ʼ��0��ʾ����ֵ
typedef struct									//���Ԥ��λ����
{
	int m_iChn;									//ͨ�����
	int m_iPointId;							//Ԥ�õ���(0��ʽ�����Ԥ��λ,
												//����ֵ��ʽ��ָ����Ŵ�����Ԥ��λ��Ϣ)
} TGuiAddPtzPresetPointReq;

typedef struct									//���Ԥ��λ��Ӧ
{
	int m_iChn;									//0��ʾ���Ԥ��λʧ��
	int m_iPointId;							//�¼ӵ�Ԥ��λ���
} TGuiAddPtzPresetPointRsp;

typedef struct									//ɾ��Ԥ��λ����
{
	int m_iChn;
	int m_iPointId;
} TGuiDelPtzPresetPointReq;

#define GUI_DEL_PTZ_PRESETPOINT_OK		0	//ɾ��Ԥ��λ�ɹ�
#define GUI_DEL_PTZ_PRESETPOINT_ERR		1	//ɾ��Ԥ��λʧ��
typedef struct									//ɾ��Ԥ��λ��Ӧ
{
	int m_iRetCode;							//������
} TGuiDelPtzPresetPointRsp;

typedef struct									//����Ԥ��λ����
{
	int m_iChn;									//ͨ�����
	int m_iPointId;							//Ԥ��λ���
} TGuiTurnToPtzPresetPointReq;

#define GUI_TRN_PTZ_PRESETPOINT_OK		0	//����Ԥ��λ�ɹ�
#define GUI_TRN_PTZ_PRESETPOINT_ERR		1	//����Ԥ��λʧ��
typedef struct									//����Ԥ��λ��Ӧ
{
	int m_iRetCode;							//������
} TGuiTurnToPtzPresetPointRsp;

// ��̨���Ʊ��ؿ�����:
// 1. �������, m_iParam[0]����ٶ�(˫������ˮƽ����ֱ�ٶ�)
#define GUI_PTZ_LOCAL_CODE_UP				1
#define GUI_PTZ_LOCAL_CODE_DOWN			2
#define GUI_PTZ_LOCAL_CODE_LEFT			3
#define GUI_PTZ_LOCAL_CODE_RIGHT			4
#define GUI_PTZ_LOCAL_CODE_RIGHTUP		5
#define GUI_PTZ_LOCAL_CODE_LEFTUP		6
#define GUI_PTZ_LOCAL_CODE_RIGHTDOWN		7
#define GUI_PTZ_LOCAL_CODE_LEFTDOWN		8
#define GUI_PTZ_LOCAL_CODE_STOP			9

// 2. �佹���䱶����Ȧ����
#define GUI_PTZ_LOCAL_CODE_ZOOM_ASC		10	//�䱶+
#define GUI_PTZ_LOCAL_CODE_ZOOM_DEC		11	//�䱶-
#define GUI_PTZ_LOCAL_CODE_ZOOM_STOP		12	//�䱶stop
#define GUI_PTZ_LOCAL_CODE_FOCUS_ASC		13	//�佹+
#define GUI_PTZ_LOCAL_CODE_FOCUS_DEC		14	//�佹-
#define GUI_PTZ_LOCAL_CODE_FOCUS_STOP	15	//�佹stop
#define GUI_PTZ_LOCAL_CODE_IRIS_ASC		17	//��Ȧ+
#define GUI_PTZ_LOCAL_CODE_IRIS_DEC		18	//��Ȧ-

// 3. �Զ�ɨ��
#define GUI_PTZ_LOCAL_CODE_AUTO_START	23
#define GUI_PTZ_LOCAL_CODE_AUTO_STOP		24

// �ƹ⡢��ˢ������
#define GUI_PTZ_LOCAL_CODE_LIGHT_ON		21
#define GUI_PTZ_LOCAL_CODE_LIGHT_OFF		22
#define GUI_PTZ_LOCAL_CODE_WIPE_START	19
#define GUI_PTZ_LOCAL_CODE_WIPE_STOP		20
#define GUI_PTZ_LOCAL_CODE_ASS_ON		29
#define GUI_PTZ_LOCAL_CODE_ASS_OFF		30

// 4. Ԥ��λ
#define GUI_PTZ_LOCAL_CODE_GO_PRESET		25	//ת��Ԥ��λ
#define GUI_PTZ_LOCAL_CODE_SET_PRESET	28	//����Ԥ��λ

// 5. �켣

typedef struct									//��̨���Ʊ��ؿ�����
{
	int m_iChn;									//ͨ����
	int m_iCode;								//������ֵ
	int m_iParam[4];							//��ز���
} TGuiPtzLocalCode;

typedef struct									//��ʼ��¼�켣����
{
	int m_iChn;									//ͨ����
} TGuiStartPtzTrackReq;

#define GUI_PTZ_TRACK_START_OK			0	//��ʼ��¼�켣�ɹ�
#define GUI_PTZ_TRACK_START_ERR			1	//��ʼ��¼�켣ʧ��
typedef struct									//��ʼ��¼�켣��Ӧ
{
	int m_iRetCode;
} TGuiStartPtzTrackRsp;

typedef struct									//������¼�켣����
{
	int m_iChn;
} TGuiEndPtzTrackReq;

#define GUI_PTZ_TRACK_END_OK				0	//������¼�켣�ɹ�
#define GUI_PTZ_TRACK_END_ERR				1	//������¼�켣ʧ��
typedef struct									//������¼�켣��Ӧ
{
	int m_iRetCode;
} TGuiEndPtzTrackRsp;

typedef struct									//��ʼ��ʾ�켣����
{
	int m_iChn;									//ͨ����
} TGuiStartPtzTrackPlayReq;

#define GUI_PTZ_TRACK_PLAY_START_OK		0	//��ʼ��ʾ�켣�ɹ�
#define GUI_PTZ_TRACK_PLAY_START_ERR		1	//��ʼ��ʾ�켣ʧ��
typedef struct									//��ʼ��ʾ�켣��Ӧ
{
	int m_iRetCode;
} TGuiStartPtzTrackPlayRsp;

typedef struct									//������ʾ�켣����
{
	int m_iChn;
} TGuiEndPtzTrackPlayReq;

#define GUI_PTZ_TRACK_PLAY_END_OK		0	//������ʾ�켣�ɹ�
#define GUI_PTZ_TRACK_PLAY_END_ERR		1	//������ʾ�켣ʧ��
typedef struct									//������ʾ�켣��Ӧ
{
	int m_iRetCode;
} TGuiEndPtzTrackPlayRsp;

typedef struct									// 3d��λ
{
	int m_iChn;				//ͨ����
	int m_iMxp;				//���λ��xp
	int m_iMyp;				//���λ��yp
	int m_iScrWidth;		//��Ļ��
	int m_iScrHeight;		//��Ļ��
	int m_iWidth;			//�����(����������������, 0���)
	int m_iHeight;			//�����(����������������, 0���)
} TGuiPtz3DLocMsg;


//==============================��������=================================
//------------------------------��������---------------------------------
typedef struct									//ʱ���
{
	int m_iEnable;								//ʱ��ʹ�ܱ�ʶ
	int m_iBeginTm;							//��ʼʱ�䣬�Ե������������
	int m_iEndTm;								//����ʱ��
} TGuiTimePair;

#define GUI_ALARM_TIME_PER_DAY	4			//ÿ�����ʱ��θ���
#define GUI_ALARM_OPEN_TYPE		1			//��������
#define GUI_ALARM_CLOSE_TYPE		2			//���ձ���
#define GUI_DVR_ALARM_OUT_CNT		4			//�������ͨ������

typedef struct									//ptz����
{
	int m_iPreSetPointEnable;					//Ԥ�õ�ʹ��
	int m_iPreSetPointId;						//Ԥ�õ���
	int m_iCruisePathEnable;					//Ѳ��·��ʹ��
	int m_iCruisePathId;						//Ѳ��·�����
	int m_iTrackEnable;						//�켣ʹ��
} TGuiPtzLinkage;

typedef struct									//������������
{
	int m_iAlarmType;							//���������ͣ�����/����
	int m_iEnable;								//��������ʹ�� 0/1
	int m_iSoundEnable;						//����ʹ�� 0/1 ���ε��ֽ�(bit8~bit15)��ʾ�Ƿ������ʼ�����0/1
	int m_iDisplayEnable;						//��Ļ��ʾʹ�ܵ��ֽ� 0/1, �ε��ֽڱ�ʾʹ�������Ǹ�����
	int m_iTranToServerEnable;                  //�ϴ�����ʹ�� 0/1
	int m_iVideoEnable[GUI_DVR_CHN_CNT];		//������ͨ��¼��ʹ�� 0/1, (0/1 ��λ˳�����������Ԫ�ص�1λ�ֱ��Ӧ1,2,3,4,5��.ͨ��������ѭ��������Ҳ���մ˴���)
	int m_iPicEnable[GUI_DVR_CHN_CNT];			//������ͨ��ͼƬץ��ʹ��
	int m_iAlarmOutEnable[GUI_DVR_ALARM_OUT_CNT];			//�����������ʹ�� 0/1 ��λ˳�����������Ԫ�ص�1λ�ֱ��Ӧ1,2,3,4ͨ��������ѭ��
	TGuiTimePair m_tTimes[7][GUI_ALARM_TIME_PER_DAY];		//ÿ���ĸ�ʱ�Σ�һ��7��
	TGuiPtzLinkage m_tPtzLinkage[GUI_DVR_CHN_CNT];			//ptz����
} TGuiAlarmInCnf;

typedef struct									//��ȡ���������������
{
	int m_iPortId;								//��������˿ڱ��1-16
} TGuiGetAlarmInCnfReq;

typedef struct									//��ȡ�������������Ӧ
{
	int m_iPortId;								//�˿ں�
	TGuiAlarmInCnf m_tCnf;						//��������
} TGuiGetAlarmInCnfRsp;

typedef struct									//���ñ��������������
{
	int m_iPortId;								//�˿ں�
	TGuiAlarmInCnf m_tCnf;						//��������
} TGuiSetAlarmInCnfReq;

#define GUI_SET_ALARM_IN_CNF_OK		0		//���ò����ɹ�
#define GUI_SET_ALARM_IN_CNF_ERR		1		//���ò���ʧ��
typedef struct									//���ñ������������Ӧ
{
	int m_iRetCode;
} TGuiSetAlarmInCnfRsp;

//��·����������ptz,ǰ32ͨ��ʹ����Э��
#define GUI_GET_ALARM_LINK_PTZ_REQ    2510
#define GUI_GET_ALARM_LINK_PTZ_RSP	-2510
typedef struct
{
	int m_iChn;
	int m_iAlarmType;   //�������ͼ�guitransport.h
	int m_iChnOffSet;   
}TGuiGetAlarmLinkPtzReq;

typedef struct
{
	int m_iChn;
	int m_iAlarmType;
	int m_iChnOffSet;
	TGuiPtzLinkage m_tPtzLinkage[GUI_DVR_CHN_CNT];			//ptz����
}TGuiGetAlarmLinkPtzRsp;

#define GUI_SET_ALARM_LINK_PTZ_REQ	2511
#define GUI_SET_ALARM_LINK_PTZ_RSP	-2511
typedef TGuiGetAlarmLinkPtzRsp  TGuiSetAlarmLinkPtzReq;

typedef struct
{
	int m_iRetCode;
}TGuiSetAlarmLinkPtzRsp;


//------------------------------�������---------------------------------
typedef struct									//�����������
{
	int m_iMsgDelay;							//�ź���ʱ
	int m_iType;								//����������:����/����
	TGuiTimePair m_tTimes[7][GUI_ALARM_TIME_PER_DAY]; //����ʱ��,7�죬ÿ���ĸ�ʱ��
} TGuiAlarmOutCnf;

typedef struct									//��ȡ���������������
{
	int m_iPortId;								//�������ͨ��
} TGuiGetAlarmOutCnfReq;

typedef struct									//��ȡ���������������
{
	int m_iPortId;								//�������ͨ����
	TGuiAlarmOutCnf m_tCnf;
} TGuiGetAlarmOutCnfRsp;

typedef struct									//���ñ��������������
{
	int m_iPortId;								//�������ͨ����
	TGuiAlarmOutCnf m_tCnf;
} TGuiSetAlarmOutCnfReq;

#define GUI_SET_ALARM_OUT_CNF_OK		0		//���ñ�����������ɹ�
#define GUI_SET_ALARM_OUT_CNF_ERR	1		//���ñ����������ʧ��

typedef struct									//���ñ������������Ӧ
{
	int m_iRetCode;							//������
} TGuiSetAlarmOutCnfRsp;

// �ֶ�����

#define GUI_ALARM_ALL					0
// �������ͼ�GuiTransport

typedef struct									//������������
{
	int m_iType;
} TGuiClearAlarmCmd;
//----------------------------��������������-------------------------
#define GUI_GET_ALARM_LINK_SPIC_INTERVAL_REQ   541 //��ȡ��������������Ѳ�����ʱ������
#define GUI_GET_ALARM_LINK_SPIC_INTERVAL_RSP   -541   //��ȡ��������������Ѳ�����ʱ���Ӧ
typedef struct
{
	int m_iTm;
}TGuiGetAlarmLinkSpicIntervalRsp;


#define GUI_SET_ALARM_LINK_SPIC_INTERVAL_REQ  542  //���ñ�������������Ѳ���������
#define GUI_SET_ALRRM_LINK_SPIC_INTERVAL_RSP  -542 //���ñ�������������Ѳ�������Ӧ
typedef struct
{
	int m_iTm; // 0- ��Ѳ��������ʱ���Ѳ��
}TGuiSetAlarmLinkSpicIntervalReq;
#define GUI_SET_ALARM_LINK_OK    0 //���óɹ�
#define GUI_SET_ALARM_LINK_ERR   1 //����ʧ��
typedef struct
{
	int m_iRetCode;   
}TGuiSetAlarmLinkSpicIntervalRsp;


//------------------------------�ƶ����---------------------------------
typedef struct									//��ȡ�ƶ���ⱨ����������
{
	int m_iChn;									//ͨ����
} TGuiGetMdAlarmCnfReq;

typedef struct									//�ƶ���ⱨ������
{
	int m_iSensitive;							//������
	int m_iEnable;								//�ƶ����ʹ�� 0/1
	int m_iSoundEnable;						//����ʹ�� 0/1 ���ε��ֽ�(bit8~bit15)��ʾ�Ƿ������ʼ�����0/1
	int m_iDisplayEnable;						//��Ļ��ʾʹ�� 0/1,��Ļ��ʾʹ�ܵ��ֽ� 0/1, �ε��ֽڱ�ʾʹ�������Ǹ�����,
	//bit16~bit17��ʾ����˫�ƣ�bit16 1��������� 0����Ʋ����ã�bit17-1�׹������ 0-�׹�Ʋ�����
	int m_iToServerEnable;
	int m_iVideoEnable[GUI_DVR_CHN_CNT];		//������ͨ��¼��ʹ�� 0/1, (0/1 ��λ˳�����������Ԫ�ص�1λ�ֱ��Ӧ1,2,3,4,5��.ͨ��������ѭ��������Ҳ���մ˴���)
	int m_iPicEnable[GUI_DVR_CHN_CNT];			//������ͨ��ͼƬץ��ʹ��
	int m_iAlarmOutEnable[GUI_DVR_ALARM_OUT_CNT];			//�����������ʹ�� 0/1
	TGuiTimePair m_tTimes[7][GUI_ALARM_TIME_PER_DAY];		//ÿ���ĸ�ʱ�Σ�һ��7��
	char m_cAreas[GUI_DVR_SCR_ROWS][GUI_DVR_SCR_COLS];		//�ƶ��������22x18С��0/1
} TGuiMdAlarmCnf;

typedef struct									//��ȡ�ƶ���ⱨ��������Ӧ
{
	int m_iChn;									//ͨ����
	TGuiMdAlarmCnf m_tCnf;						//�������ñ�
} TGuiGetMdAlarmCnfRsp;						//��ȡ�ƶ���ⱨ������

typedef struct									//�����ƶ���ⱨ����������
{
	int m_iChn;									//ͨ����
	TGuiMdAlarmCnf m_tCnf;						//�������ñ�
} TGuiSetMdAlarmCnfReq;						//��ȡ�ƶ���ⱨ������

#define GUI_SET_MD_ALARM_CNF_OK		0		//���ò����ɹ�
#define GUI_SET_MD_ALARM_CNF_ERR		1		//���ò���ʧ��
typedef struct									//�����ƶ���ⱨ��������Ӧ
{
	int m_iRetCode;
} TGuiSetMdAlarmCnfRsp;


//------------------------------��Ƶ��ʧ---------------------------------
typedef struct									//��ȡ��Ƶ��ʧ������������
{
	int m_iChn;									//ͨ����
} TGuiGetVideoLostAlarmCnfReq;

typedef struct									//��Ƶ��ʧ��������
{
	int m_iEnable;								//�ƶ����ʹ�� 0/1
	int m_iSoundEnable;							//����ʹ�� 0/1 ���ε��ֽ�(bit8~bit15)��ʾ�Ƿ������ʼ�����0/1
	int m_iDisplayEnable;						//��Ļ��ʾʹ�� 0/1
	int m_iToServerEnalbe;
	int m_iVideoEnable[GUI_DVR_CHN_CNT];		//������ͨ��¼��ʹ�� 0/1, (0/1 ��λ˳�����������Ԫ�ص�1λ�ֱ��Ӧ1,2,3,4,5��.ͨ��������ѭ��������Ҳ���մ˴���)
	int m_iPicEnable[GUI_DVR_CHN_CNT];			//������ͨ��ͼƬץ��ʹ��
	int m_iAlarmOutEnable[GUI_DVR_ALARM_OUT_CNT];			//�����������ʹ�� 0/1
	TGuiTimePair m_tTimes[7][GUI_ALARM_TIME_PER_DAY];		//ÿ���ĸ�ʱ�Σ�һ��7��
	TGuiPtzLinkage m_tPtzLinkage[GUI_DVR_CHN_CNT];			//ptz����
} TGuiVideoLostAlarmCnf;

typedef struct									//��ȡ��Ƶ��ʧ����������Ӧ
{
	int m_iChn;									//ͨ����
	TGuiVideoLostAlarmCnf m_tCnf;				//�������ñ�
} TGuiGetVideoLostAlarmCnfRsp;

typedef struct									//������Ƶ��ʧ������������
{
	int m_iChn;									//ͨ����
	TGuiVideoLostAlarmCnf m_tCnf;				//�������ñ�
} TGuiSetVideoLostAlarmCnfReq;

#define GUI_SET_VL_ALARM_CNF_OK		0		//���ò����ɹ�
#define GUI_SET_VL_ALARM_CNF_ERR		1		//���ò���ʧ��
typedef struct									//�����ƶ���ⱨ��������Ӧ
{
	int m_iRetCode;
} TGuiSetVideoLostAlarmCnfRsp;
//===========================��Ƶ��ʧ����==================================
#define GUI_GET_AL_ALARM_CNF_REQ		532		//������Ƶ��ʧ������������
#define GUI_GET_AL_ALARM_CNF_RSP		-532	//������Ƶ��ʧ����������Ӧ

typedef struct									//�ƶ���ⱨ������
{
	int m_iEnable;								//�ƶ����ʹ�� 0/1
	int m_iSoundEnable;						//����ʹ�� 0/1 ���ε��ֽ�(bit8~bit15)��ʾ�Ƿ������ʼ�����0/1
	int m_iDisplayEnable;						//��Ļ��ʾʹ�� 0/1
	int m_iToServerEnalbe;
	int m_iVideoEnable[GUI_DVR_CHN_CNT];		//������ͨ��¼��ʹ�� 0/1, (0/1 ��λ˳�����������Ԫ�ص�1λ�ֱ��Ӧ1,2,3,4,5��.ͨ��������ѭ��������Ҳ���մ˴���)
	int m_iPicEnable[GUI_DVR_CHN_CNT];			//������ͨ��ͼƬץ��ʹ��
	int m_iAlarmOutEnable[GUI_DVR_ALARM_OUT_CNT];			//�����������ʹ�� 0/1
	TGuiTimePair m_tTimes[7][GUI_ALARM_TIME_PER_DAY];		//ÿ���ĸ�ʱ�Σ�һ��7��
	TGuiPtzLinkage m_tPtzLinkage[GUI_DVR_CHN_CNT];			//ptz����
} TGuiAudioLostAlarmCnf;

typedef struct									//��ȡ��Ƶ��ʧ������������
{
	int m_iChn;									//ͨ����
} TGuiGetAudioLostAlarmCnfReq;

typedef struct									//��ȡ��Ƶ��ʧ����������Ӧ
{
	int m_iChn;									//ͨ����
	TGuiAudioLostAlarmCnf m_tCnf;				//�������ñ�
} TGuiGetAudioLostAlarmCnfRsp;


#define GUI_SET_AL_ALARM_CNF_REQ		533		//������Ƶ��ʧ������������
#define GUI_SET_AL_ALARM_CNF_RSP		-533	//������Ƶ��ʧ����������Ӧ

typedef struct									//������Ƶ��ʧ������������
{
	int m_iChn;									//ͨ����
	TGuiAudioLostAlarmCnf m_tCnf;				//�������ñ�
} TGuiSetAudioLostAlarmCnfReq;

#define GUI_SET_AL_ALARM_CNF_OK			0		//���ò����ɹ�
#define GUI_SET_AL_ALARM_CNF_ERR		1		//���ò���ʧ��

typedef struct									//�����ƶ���ⱨ��������Ӧ
{
	int m_iRetCode;
} TGuiSetAudioLostAlarmCnfRsp;

//=========================��ʪ�ȱ���==========================
//��Ƕ����ֵ������
#define GUI_GET_TEMPHUM_ALARM_CNF_REQ		534		//��ȡ��ʪ�ȱ�����������
#define GUI_GET_TEMPHUM_ALARM_CNF_RSP		-534	//��ȡ��ʪ�ȱ���������Ӧ

typedef struct	//������������
{
	int m_iEnable;									//��������ʹ�� 0/1
	int m_iSoundEnable;								//����ʹ�� 0/1 ���ε��ֽ�(bit8~bit15)��ʾ�Ƿ������ʼ�����0/1
	int m_iDisplayEnable;							//��Ļ��ʾʹ�ܵ��ֽ� 0/1 �ε��ֽڱ�ʾʹ�������ĸ�����
	int m_iToServerEnalbe;                  		//�ϴ�����ʹ�� 0/1
	int m_iVideoEnable[GUI_DVR_CHN_CNT];			//������ͨ��¼��ʹ�� 0/1, (0/1 ��λ˳�����������Ԫ�ص�1λ�ֱ��Ӧ1,2,3,4,5��.ͨ��������ѭ��������Ҳ���մ˴���)
	int m_iPicEnable[GUI_DVR_CHN_CNT];				//������ͨ��ͼƬץ��ʹ��
	int m_iAlarmOutEnable[GUI_DVR_ALARM_OUT_CNT];		//�����������ʹ�� 0/1 ��λ˳�����������Ԫ�ص�1λ�ֱ��Ӧ1,2,3,4ͨ��������ѭ��
	TGuiTimePair m_tTimes[7][GUI_ALARM_TIME_PER_DAY];	//ÿ���ĸ�ʱ�Σ�һ��7��
	TGuiPtzLinkage m_tPtzLinkage[GUI_DVR_CHN_CNT];		//ptz����
} TGuiTempHumAlarmCnf;

typedef struct											//��ȡ��ʪ�ȱ�����������
{
	int m_iDevId;										//��ʪ��ģ����
} TGuiGetTempHumAlarmCnfReq;

typedef struct											//��ʪ��ģ����
{
	int m_iDevId;										//��ʪ��ģ����
	TGuiTempHumAlarmCnf m_tCnf;							//��������
} TGuiGetTempHumAlarmCnfRsp;

#define GUI_SET_TEMPHUM_ALARM_CNF_REQ		535			//������ʪ�ȱ�����������
#define GUI_SET_TEMPHUM_ALARM_CNF_RSP		-535		//������ʪ�ȱ���������Ӧ

#define GUI_SET_ALARM_TEMPHUM_CNF_OK		0			//���ò����ɹ�
#define GUI_SET_ALARM_TEMPHUM_CNF_ERR		1			//���ò���ʧ��

typedef struct											//������ʪ�ȱ�����������
{
	int m_iDevId;										//��ʪ��ģ���ַ
	TGuiTempHumAlarmCnf m_tCnf;							//��������
} TGuiSetTempHumAlarmCnfReq;

typedef struct											//������ʪ�ȱ���������Ӧ
{
	int m_iRetCode;
} TGuiSetTempHumAlarmCnfRsp;

//==========================��Ƶ�ڵ�����=============================
#define GUI_GET_OD_ALARM_CNF_REQ	  536  		//��ȡ��Ƶ�ڵ�������������
#define GUI_GET_OD_ALARM_CNF_RSP	  -536		//��ȡ��Ƶ�ڵ�����������Ӧ
#define	GUI_SET_OD_ALARM_CNF_REQ      537	    //������Ƶ�ڵ�������������
#define	GUI_SET_OD_ALARM_CNF_RSP   	  -537		//������Ƶ�ڵ�����������Ӧ

typedef struct							//��ȡ��Ƶ�ڵ�������������
{
	int m_iChn;							//ͨ����
} TGuiGetODAlarmCnfReq;

typedef struct										//��Ƶ�ڵ���������
{
	int m_iSensitive;								//������
	int m_iEnable;									//�ƶ����ʹ�� 0/1
	int m_iSoundEnable;								//����ʹ�� 0/1
	int m_iDisplayEnable;							//��Ļ��ʾʹ�� 0/1
	int m_iToServerEnable;
	int m_iVideoEnable[GUI_DVR_CHN_CNT];			//������ͨ��¼��ʹ�� 0/1, (0/1 ��λ˳�����������Ԫ�ص�1λ�ֱ��Ӧ1,2,3,4,5��.ͨ��������ѭ��������Ҳ���մ˴���)
	int m_iPicEnable[GUI_DVR_CHN_CNT];				//������ͨ��ͼƬץ��ʹ��
	int m_iAlarmOutEnable[GUI_DVR_ALARM_OUT_CNT];	//�����������ʹ�� 0/1
	TGuiTimePair m_tTimes[7][GUI_ALARM_TIME_PER_DAY];		//ÿ���ĸ�ʱ�Σ�һ��7��
	TGuiPtzLinkage m_tPtzLinkage[GUI_DVR_CHN_CNT];			//����ptz
	char m_cAreas[GUI_DVR_SCR_ROWS][GUI_DVR_SCR_COLS];		//��Ƶ�ڵ�����22x18С��0/1
} TGuiODAlarmCnf;

typedef struct							//��ȡ��Ƶ�ڵ�����������Ӧ
{
	int m_iChn;							//ͨ����
	TGuiODAlarmCnf m_tCnf;				//�������ñ�
} TGuiGetODAlarmCnfRsp;				//��ȡ��Ƶ�ڵ���������

typedef struct							//������Ƶ�ڵ�������������
{
	int m_iChn;							//ͨ����
	TGuiODAlarmCnf m_tCnf;				//�������ñ�
} TGuiSetODAlarmCnfReq;				//��ȡ��Ƶ�ڵ���������

#define GUI_SET_OD_ALARM_CNF_OK			0			//���ò����ɹ�
#define GUI_SET_OD_ALARM_CNF_ERR		1			//���ò���ʧ��
typedef struct								
{
	int m_iRetCode;
} TGuiSetODAlarmCnfRsp;			//������Ƶ�ڵ�����������Ӧ


// ===========================ϵͳע��==================================
#define GUI_SYS_SPEC_CODE1			0x20090624
#define GUI_SYS_SPEC_CODE2			0x06242009   //����
#define GUI_SYS_SPEC_CODE3          0x20130425   //Զ��

typedef struct
{
	int m_iCode1;								//�̶�ֵ GUI_SYS_SPEC_CODE1
	int m_iCode2;								//�̶�ֵ GUI_SYS_SPEC_CODE2	
} TGuiSystemReSetReq;

#define GUI_SYS_RESET_ACCEPT			0		//��������
#define GUI_SYS_RESET_REFUSE			1		//�ܾ�����
typedef struct									//ϵͳ������Ӧ
{
	int m_iRetCode;
} TGuiSystemReSetRsp;


typedef struct
{
	int m_iCode1;								//�̶�ֵ GUI_SYS_SPEC_CODE1
	int m_iCode2;								//�̶�ֵ GUI_SYS_SPEC_CODE2
} TGuiSystemPowerOffReq;
	
#define GUI_SYS_POWEROFF_ACCEPT		0		//����ػ�
#define GUI_SYS_POWEROFF_REFUSE		1		//�ܾ��ػ�
typedef struct									//ϵͳ�ػ���Ӧ
{
	int m_iRetCode;
} TGuiSystemPowerOffRsp;


#define GUI_SET_DEFAULT_REQ		603     //�µĻָ�Ĭ��������(�����ݳ���)
#define GUI_SET_DEFAULT_RSP		-603	//�ָ�Ĭ�ϻ�Ӧ

#define GUI_SYS_DEF_CODE1			0x20150617
#define GUI_SYS_DEF_CODE2			0x06172015  //����
#define GUI_SYS_DEF_CODE3          	0x20040425   //Զ��

typedef struct
{
	int m_iCode1;			//�̶�ֵ GUI_SYS_DEF_CODE1
	int m_iCode2;			//�̶�ֵ GUI_SYS_DEF_CODE2	
} TGuiSysToDefaultReq;

#define GUI_SYS_DEFAULT_ACCEPT			0		//����ָ�Ĭ��
#define GUI_SYS_DEFAULT_REFUSE			1		//�ܾ��ָ�Ĭ��

typedef struct							//�ָ�Ĭ�ϻ�Ӧ
{
	int m_iRetCode;
} TGuiSysToDefaultRsp;


// ��Ϣ
typedef int TGuiKey;

// JPGEץ��
#define GUI_SNAPSHOT_REQ				363		//JPEGץ������
#define GUI_SNAPSHOT_RSP				364		//JPEGץ�Ļ�Ӧ
typedef struct									//ץ������
{
	int iChn;	 								// 1-16��Ӧͨ����0:ȫ��ͨ��
} TGuiSnapshotReq;

#define GUI_SNAPSHOT_OK			0
#define GUI_SNAPSHOT_ERR		1
typedef struct									//ץ�Ļ�Ӧ
{
	int m_iRetCode;							//������
} TGuiSnapshotRsp;

// ��ǿ��ץ�Ĺ��ܣ�����ץ���ļ��� (IPCʹ��)
#define GUI_SNAPSHOT_REQ_EX			365			//JPEDץ�ģ�ͬʱ����ץ��ͼƬ����
#define GUI_SNAPSHOT_RSP_EX			-365
typedef struct									//ץ������
{
	int iChn;	 								// 1-16��Ӧͨ����0:ȫ��ͨ��( ��λ��0x1000��ʾ������ʱץ��)
} TGuiSnapshotReqEx;

typedef struct									//ץ�Ļ�Ӧ
{
	int m_iRetCode;							//������
	char m_cPicName[64];						//ץ��ͼƬ����	
} TGuiSnapshotRspEx;

//��ͨ��ץ�� (�Ϻ��ر꣬���ʹ��)
#define GUI_MULTI_CHN_SNAPSHORT_REQ			366  //��ͨ��ץ������ ���Ϻ��ر꣬���ʹ�ã�
#define GUI_MULTI_CHN_SNAPSHORT_RSP	    	-366 //��ͨ��ץ�Ļ�Ӧ  (�Ϻ��ر꣬���ʹ��)

typedef struct
{
	int m_iChn;  //��Ҫץ�ĵ�ͨ���б�, ͨ����λ��ʾ 0-����Ҫץ��1-��Ҫץ�ġ�
	int m_iChnEx; //Ԥ����չ�á�
}TGuiSnapshotMultiChnReq;

typedef struct
{
	int m_iChnCnt;     //����ץ�ĳɹ�ͨ������
}TGuiSnapshotMultiChnRsp;

typedef struct
{
	char m_iChn;   //ͨ����
	char m_cPicName[GUI_PUBLIC_LEN_63 + 1];  //��Ӧͨ����ץ��ͼƬ·��������
}TGuiSnapshotMultiChnMsg;  //����ץ��ͼƬ·��������


// ·����ʾ
#define GUI_PTZ_PATH_PLAY_START	1			//��ʼ��ʾ·��
#define GUI_PTZ_PATH_PLAY_STOP	0			//������ʾ·��
typedef struct
{
	int m_iCmd;									//������:��ʼ/����
	int m_iChn;									//ͨ����, 1-16
	int m_iPath;								//·����, 1-8
} TGuiPtzPathPlayReq;

#define GUI_PTZ_PATH_PLAY_OK		0			//��ʾ/����·���ɹ�
#define GUI_PTZ_PATH_PLAY_ERR		1			//��ʾ/����·��ʧ��
typedef struct
{
	int m_iRetCode;							//������
} TGuiPtzPathPlayRsp;

// ���ӷŴ�

#define EZOOM_VO_START				1000

typedef struct
{
	int m_iChn;			//ͨ����: 1-16
	int m_iLeft;		//�Ŵ�����XP����
	int m_iTop;			//�Ŵ�����YP����
	int m_iWidth;		//�Ŵ�������
	int m_iHeight;		//�Ŵ�����߶�
} TGuiEzoomAttr;

typedef struct
{
	int m_iDevId;								//�豸��dxl 2009/12/02
	TGuiEzoomAttr m_tAttr;						//��ʼ�����ӷŴ����
} TGuiEzoomEnterReq;							//������ӷŴ�����

#define GUI_EZOOM_ENTER_OK		0
#define GUI_EZOOM_ENTER_ERR		1
#define GUI_EZOOM_CHN_BIGGER_14	20131105  //���ط�·������14·ʱ����֧�ֵ��ӷŴ�
typedef struct									//������ӷŴ��Ӧ
{
	int m_iRetCode;
} TGuiEzoomEnterRsp;    

// �˳����ӷ�

typedef struct
{
	int m_iDevId;	
} TGuiEzoomExitReq; // �˳����ӷŴ�����dxl 2009/12/02

#define GUI_EZOOM_EXIT_OK			0
#define GUI_EZOOM_EXIT_ERR		1
typedef struct
{
	int m_iRetCode;
} TGuiEzoomExitRsp;							//�˳����ӷŴ��Ӧ

typedef struct
{
	TGuiEzoomAttr m_tAttr;						//�Ŵ����
} TGuiEzoomSetAttrReq;						//���õ��ӷŴ��������

#define GUI_EZOOM_SET_ATTR_OK		0
#define GUI_EZOOM_SET_ATTR_ERR	1
typedef struct
{
	int m_iRetCode;
} TGuiEzoomSetAttrRsp;						//���õ��ӷŴ��������

// UI������Ϣ
#define GUI_VER_LEN		31
typedef struct
{
	int m_iMasterDspDev;			//����ʾ�豸
	int m_iVgaMode;				//VGA��ʾģʽ
	int m_iBncMode;				//BNC��ʾģʽ
	char m_strGuiVer[GUI_VER_LEN + 1];	//UI�汾��
} TGuiStartUpMsg;				//֪ͨ��Ϣ

//add by wanzy 2011/10/11
typedef struct
{
	int m_iMasterDspDev;				//����ʾ�豸
	int m_iVgaMode;				//VGA��ʾģʽ
	int m_iBncMode;				//BNC��ʾģʽ
	char m_strGuiVer[GUI_VER_LEN + 1 - 4];	//UI�汾��
	char m_strCharSet[4];			//�ַ����汾 "GB"/"UTF"
} TGuiStartUpMsgEx;					//֪ͨ��Ϣ

typedef struct
{
	int m_iRetCode;				//����ֵ,0��ʾ�ɹ�������ֵ��ʧ��
} TGuiStartUpRsp;				//��Ϣ��Ӧ

//����VGA�ֱ���(��HDMI �豸1ͬԴ)
//����HD0\HD1�ֱ���(��16λ��HD0 ��16λ��HD1)
typedef struct
{
	int m_iVgaMode;				//VGA��ʾģʽ
} TGuiSetVgaModeReq;		//����VGA��ʽ

#define GUI_SET_VGA_OK		0
#define GUI_SET_VGA_ERR		1
typedef struct
{
	int m_iRetCode;				//������
} TGuiSetVgaModeRsp;

//����BNC��ʽ
typedef struct
{
	int m_iBncId;					//BNC��ţ���ʱʹ��0����ʾȫ��BNC
	int m_iBncMode;				//ģʽ
} TGuiSetBncModeReq;

#define GUI_SET_BNC_OK		0
#define GUI_SET_BNC_ERR		1
typedef struct
{
	int m_iRetCode;
} TGuiSetBncModeRsp;

//����HDMI�ֱ���(�豸0)
#define GUI_SET_HDMI_MOD_REQ 13
#define GUI_SET_HDMI_MOD_RSP -13

typedef struct
{
	int m_iHDMIMode;				//HDMI��ʾģʽ
} TGuiSetHDMIModeReq;		//����HDMI��ʽ

#define GUI_SET_HDMI_OK			0
#define GUI_SET_HDMI_ERR		1
typedef struct
{
	int m_iRetCode;				//������
} TGuiSetHDMIModeRsp;

//����HDMI����ʾ����ʾģʽ

#define GUI_SET_HDMI_DSP_MODE_REQ  14
#define GUI_SET_HDMI_DSP_MODE_RSP  -14
typedef struct
{
	int m_iHDMIDspMode;   //0-Auto, 1-YCBCR, 2-RGB
}TGuiSetHDMIDspModReq;

#define GUI_SET_HDMI_DSP_MODE_OK   0
#define GUI_SET_HDMI_DSP_MODE_ERR  1
typedef struct
{
	int m_iRetCode;
}TGuiSetHDMIDspModeRsp;

//VGA��HDMI���ģʽ����
#define GUI_GET_VIDEO_OUTMOD_REQ	15		//��ȡ���ģʽ����
#define GUI_GET_VIDEO_OUTMOD_RSP		-15		//��ȡ���ģʽ��Ӧ
#define GUI_SET_VIDEO_OUTMOD_REQ	 	16		//�������ģʽ����
#define GUI_SET_VIDEO_OUTMOD_RSP		-16		//�������ģʽ��Ӧ

typedef enum
{	
	MOD_STANDARD = 0,		//��׼
	MOD_SOFTNESS,			//���
	MOD_BRIGHT,			//����
	MOD_HIGHLIGHT,			//����
}TVideoOutputType;     //���ģʽ

typedef struct
{
	int m_iVoId;     //�豸��,0��ʾȫ��,1��ʾVGA,2��ʾHDMI
}TGuiGetVideoOutputReq;

typedef struct									//��ȡ���ģʽ������Ӧ
{
	int m_iVoId;
	int m_iVideoOutMode;							//���ģʽ
} TGuiGetVideoOutputRsp;

typedef struct									//�������ģʽ��������
{
	int m_iVoId;
	int m_iVideoOutMode;							//���ģʽ
} TGuiSetVideoOutputReq;

typedef struct
{
	int m_iRetCode;
}TGuiSetVideoOutputRsp;
//###################end#############

// ���̿�¼
typedef struct				// ��¼��ʼ��Ӧ
{
	int m_iRetCode;			// 0�ɹ�, 1ʧ��
} TGuiCdBackupStartRsp;

typedef struct				// ��¼�ļ��б�
{
	int m_iSeq;							// ���кţ�����
	char m_strFile[GUI_VF_NAME_LEN + 1];	// �ļ���
} TGuiCdBackupFileReq;

typedef struct
{
	int m_iRetCode;			// 0�ɹ���1ʧ��
} TGuiCdBackupFileRsp;

typedef struct
{
	int m_iDid;				// ���̱�ţ��Ͱ�λ(bit0-bit7)�������һ��bit8-bit15������̶�
} TGuiCdBackupExecReq;

typedef struct
{
	int m_iRetCode;			// 0�ɹ���1ʧ��
	int m_iBackupId;			//��¼ID����ȡ����ʱʹ�ã��Ͱ�λ(bit0-bit7)�������һ��bit8-bit15������̶�
} TGuiCdBackupExecRsp;

typedef struct				// ��������
{
	int m_iBackupId;			//��¼ID
} TGuiCdBackupPrgReq;

enum	// ��¼״̬
{
	GUI_CD_BACKUP_FREE	= 0,   //����
	GUI_CD_BACKUP_DOING = 1,	// ���ڿ�¼
	GUI_CD_BACKUP_DONE,		// ��¼���
	GUI_CD_BACKUP_ERROR,	// ������
	GUI_CD_BACKUP_FULL, 	//������һ����
	GUI_CD_BACKUP_STARTERROR, 	//���ݳ���
};

typedef struct
{
	int m_iStat;				//��ǰ״̬
	int m_iPrg;				//��ǰ����
} TGuiCdBackupPrgRsp;


/***************************************************/
//��Ƶ��������(������������)
typedef struct
{
	int m_iMaxPicSize; //���ֱ���
	int m_iMaxFrameRate; //���֡��
}TGuiVideoParaConf;
typedef struct
{
	int m_iValue;
}TGuiVideoParaUsedFpsConf;
//��ȡ��Ƶ���ò�������
typedef struct									
{
	int m_iChn;									//ͨ����
} TGuiGetVideoParaCnfReq;

//��ȡ��Ƶ�������������Ӧ
typedef struct									//��ȡ��Ƶ���������Ӧ
{
	int m_iChn;									//ͨ����
	TGuiVideoParaConf m_tCnf;					//������Ϣ
} TGuiGetVideoParaCnfRsp;
// ������Ƶ�����������
typedef TGuiGetVideoParaCnfRsp TGuiSetVideoParaCnfReq;

#define GUI_SET_VIDEOPARA_CNF_OK		0		//���óɹ�
#define GUI_SET_VIDEOPARA_CNF_ERR		1		//����ʧ��

//������Ƶ�������û�Ӧ
typedef struct									
{
	int m_iRetCode;
} TGuiSetVideoParaCnfRsp;
//************************************




//************************************

//��ȡ�ܵı�����������
typedef struct
{
	int m_iTotalCode;
}TGuiGetTotalFrameRateRsp;
//************************************
//��ȡĳͨ��֧�ֵ���Ƶ�ֱ��ʴ�С
#define GUI_GET_CHN_VIDEO_SIZE_REQ     235   //��ȡ����ͨ��֧�ֵ���Ƶ�ֱ��ʴ�С����
#define GUI_GET_CHN_VIDEO_SIZE_RSP     -235   //��ȡ����ͨ��֧�ֵ���Ƶ�ֱ��ʴ�С��Ӧ
typedef struct
{
	int m_iChn;   //����ͨ��
}TGuiGetChnVideoSizeReq;

typedef struct
{
	int m_iChn;
	int m_iCnt;   //��������ͨ��֧�ּ�����Ƶ�ֱ���
}TGuiGetChnVideoSizeRsp;

typedef struct
{
	int m_iVideoSize;  //�ֱ��ʴ�С(GUI_1080P Ϊ12)
}TGuiVideoSizeItem;

//*****************************WIFI���**************************************
//��������

//Wifi����״̬
#define NET_WIFI_UNONLINE    0
#define NET_WIFI_ONLINE       1
//wifi��ȫ��ʽ
#define NET_WIFI_WEP      1
#define NET_WIFI_WPA_PSK      2
#define NET_WIFI_WPA2_PSK     3
//wifi ��Կ��ʽ
#define NET_WIFI_KEYTYPE_HEX    1
#define NET_WIFI_KEYTYPE_ASCII  2
//wifi���ܷ���
#define NET_WIFI_ENCRYPT_TKIP  1
#define NET_WIFI_ENCRYPT_AES   2
//wifi ��������
#define NET_WIFI_PWDTYPE_DISEABLE   0
#define NET_WIFI_PWDTYPE_64BITS  1
#define NET_WIFI_PWDTYPE_128BITS 2
//wifi ��Կѡ��
#define NET_WIFI_KEYNUM_1     1
#define NET_WIFI_KEYNUM_2     2
#define NET_WIFI_KEYNUM_3     3
#define NET_WIFI_KEYNUM_4     4

//wifi ��������
#define GUI_GET_WIFI_NET_CNF_REQ    100000   //��ȡwifi����������Ϣ����
#define GUI_GET_WIFI_NET_CNF_RSP    -100000//��ȡwifi����������Ϣ��Ӧ

//wifi �����������ý���
#define GUI_GET_WIFI_IP_VIA_DHCP		0			//dhcp��ʽ��ȡIP
#define GUI_GET_WIFI_IP_VIA_HUM		1			//�ֶ�����IP
#define GUI_GET_WIFI_DNS_VIA_DHCP    0      //dhcp��ʽ��ȡdns
#define GUI_GET_WIFI_DNS_VIA_HUM    1       //�ֶ���ʽ����dns
#define GUI_WIFIESSID_STR_LEN  31

typedef struct 
{
	//int m_iHaveWifiCard;
	int m_iOnLineState;
	int m_iGetWifiIpMethod; 					//��ȡip��ַ�ķ�ʽ
	int m_blWifiIsHandSetDns;						//�ֶ�����DNS
	char m_strWifiMac[GUI_IP_STR_LEN + 1]; //mac��ַ
	char m_strWifiEssid[GUI_WIFIESSID_STR_LEN + 1];  //essid
	char m_strWifiIp[GUI_IP_STR_LEN + 1];			//ip��ַ
	char m_strWifiSubMsk[GUI_IP_STR_LEN + 1];		//��������
	char m_strWifiGateWay[GUI_IP_STR_LEN + 1];		//����
	char m_strWifiDNS[GUI_IP_STR_LEN + 1];			//��ѡ��������
	//char m_strWifiSecDNS[GUI_IP_STR_LEN + 1];			//��ѡ��������
}TGuiWifiIpMsg;

//��ȡwifi��������ip������Ӧ
typedef struct
{
	TGuiWifiIpMsg m_tWifiIpMsg;
}TGuiGetWifiIpRsp;    

#define GUI_SET_WIFI_NET_CNF_REQ    100001 //����wifi����������Ϣ����
#define GUI_SET_WIFI_NET_CNF_RSP    -100001//����wifi����������Ϣ��Ӧ
//����wifi��������ip��������
typedef struct
{
	TGuiWifiIpMsg m_tWifiIpMsg;
}TGuiSetWifiIpReq;   


//����wifi��������ip������Ӧ
#define GUI_SET_WIFI_NET_IP_OK			0				//����WIFI IP��ַ�ɹ�
#define GUI_SET_WIFI_NET_IP_ERR			1				//����WIFI IP��ַʧ��
typedef struct
{
	int m_iRetCode; 						//������
	TGuiWifiIpMsg m_tWifiIpMsg;             //������IP��Ϣ
}TGuiSetWifiIpRsp;

//wifi���ý���
#define GUI_GET_WIFI_PARA_CNF_REQ      100002   //��ȡwifi������������
#define GUI_GET_WIFI_PARA_CNF_RSP      -100002 //��ȡwifi�������û�Ӧ

#define GUI_WIFI_PWD_STR_LEN           64
#define GUI_SAFE_WIFI_UNSET           0
#define GUI_SAFE_WIFI_SET             1

typedef struct
{
	//int m_iOnLineState;
	char m_strEssid[GUI_WIFIESSID_STR_LEN + 1];
	int m_iSetSafeEnable;
	int m_iSecurityType;
	int m_iKeyFormat;
	int m_iKeyType;
	int m_iKeySelect;
	char m_cPassword[GUI_WIFI_PWD_STR_LEN + 1];
}TGuiWifiParaMsg;

typedef struct								//��ȡwifi������Ӧ	
{
	TGuiWifiParaMsg m_tWifiParaMsg;						
} TGuiGetWifiParaCnfRsp;

#define GUI_SET_WIFI_PARA_CNF_REQ      100003   //����wifi������������
#define GUI_SET_WIFI_PARA_CNF_RSP      -100003   //����wifi�������û�Ӧ
typedef struct								//����wifi��������
{
	TGuiWifiParaMsg m_tWifiParaMsg;
} TGuiSetWifiParaCnfReq;

#define GUI_SET_WIFI_PARA_CNF_OK			0
#define GUI_SET_WIFI_PARA_CNF_ERR			1
typedef struct								//����wifi������Ӧ
{
	int m_iRetCode;
}TGuiSetWifiParaCnfRsp;


//wifi���ý���-��������
//wifi����-�����¼�
#define GUI_GET_SEARCH_WIFI_NET_REQ    100004 //��ȡwifi���������������
#define GUI_GET_SEARCH_WIFI_NET_RSP   -100004 //��ȡwifi �������������Ӧ
typedef struct
{
	char m_cWifiName[GUI_WIFIESSID_STR_LEN + 1];
	char m_cWifiEssid[GUI_WIFIESSID_STR_LEN + 1];
	int m_iSafeEnable;
}TGuiWifiNetListItem;

//��ȡwifi���������Ӧ
#define GUI_WIFI_SEARCH_OK    0   //wifi  ִ�������ɹ� 
#define GUI_WIFI_SEARCH_ERR   1   //wifi ִ������ ʧ��
typedef struct								
{
	int m_iWifiNetCnt;
	int m_iRetCode;
}TGuiGetWifiNetParaListRsp;

//=================WIFI=AP===================================
#define GUI_GET_WIFI_AP_CNF_REQ      100005		//��ȡWIFI AP ��������
#define GUI_GET_WIFI_AP_CNF_RSP      -100005	//��ȡWIFI AP ������Ӧ

typedef struct
{
	int m_iOnLineState;							//����״̬
	char m_strWifiIp[GUI_IP_STR_LEN + 1];		//ip��ַ
	char m_strWifiSubMsk[GUI_IP_STR_LEN + 1];	//��������
	TGuiDhcpServerMsg m_tDhcpServerMsg;
	TGuiWifiParaMsg	m_tWifiParaMsg;
}TGuiWifiApMsg;

typedef struct
{
	TGuiWifiApMsg m_tWifiApMsg;
}TGuiGetWifiApRsp;								//��ȡWIFI AP ������Ӧ

#define GUI_SET_WIFI_AP_CNF_REQ			100006		//����WIFI AP��������
#define GUI_SET_WIFI_AP_CNF_RSP			-100006		//����WIFI AP������Ӧ

typedef struct
{
	TGuiWifiApMsg m_tWifiApMsg;
}TGuiSetWifiApReq;				//����WIFIAP����

#define GUI_SET_WIFI_AP_OK    0
#define GUI_SET_WIFI_AP_ERR	  1
typedef struct
{
	int m_iRetCode; 
}TGuiSetWifiApRsp;				//����WIFIAP��Ӧ 


//=====================================================================
//WIFI����Э��

#define GUI_GET_WIFI_ENABLE_STAT_REQ	100021 //��ȡwifiʹ��״̬����
#define GUI_GET_WIFI_ENABLE_STAT_RSP	-100021 //��ȡwifiʹ��״̬��Ӧ

#define GUI_WIFI_ENABLE_STAT    1  //ʹ��
#define GUI_WIFI_DISENABLE_STAT 0  //��ʹ��

typedef struct								
{	
	int m_iEnable;  
}TGuiGetWifiEnableStatRsp;

#define GUI_SET_WIFI_ENABLE_STAT_REQ	100022 //����wifiʹ��״̬����
#define GUI_SET_WIFI_ENABLE_STAT_RSP	-100022 //����wifiʹ��״̬��Ӧ

typedef struct								
{	
	int m_iEnable;
}TGuiSetWifiEnableStatReq;

typedef struct
{
	int m_iRetCode; // GUI_SET_OK .GUI_SET_ERR
}TGuiSetWifiEnableStatRsp;


//============================
//����wifi�Ͽ�������

#define GUI_WIFI_DISCONNECT		0  //δ����
#define GUI_WIFI_CONNECT		1  //����

#define GUI_GET_WIFI_CONNECT_STAT_REQ	100023 //��ȡwifi����״̬����
#define GUI_GET_WIFI_CONNECT_STAT_RSP	-100023 //��ȡwifi����״̬��Ӧ

typedef struct								
{
	int m_iConnectCmd;	//0:�Ͽ���1������
}TGuiGetWifiConnectStaRsp;

#define GUI_SET_WIFI_CONNECT_STAT_REQ	100024 //�������ӻ�Ͽ�wifi����
#define GUI_SET_WIFI_CONNECT_STAT_RSP	-100024 //�������ӻ�Ͽ�wifi��Ӧ

typedef struct								
{
	int m_iConnectStat;	//0:�Ͽ���1������
}TGuiSetWifiConnectCmdReq;

typedef struct								
{	
	int m_iRetCode;
}TGuiSetWifiConnectCmdRsp;
//============================











//-----------------------------------------------------------------------------------------
#define GUI_CD_BACKUP_INDEX_REQ		717	//֪ͨ�ں˵�ǰ����������Ϣ����
#define GUI_CD_BACKUP_INDEX_RSP		-717     //֪ͨ�ں˵�ǰ����������Ϣ��Ӧ

typedef struct
{
	int m_iCdBackUpIndex;	//��ǰ���ݵڼ���ʱ���
	int m_iCdBackUpCnt;	//���̱���ʱ����ܸ���
}TGuiCdBackUpIndexReq;  

typedef struct
{
	int m_iRetCode;
}TGuiCdBackUpIndexRsp; //֪ͨ�ں˵�ǰ���ݵڼ���ʱ��λ�Ӧ

#define GUI_CD_BACKUP_STOP_REQ			718	//ǿ��ֹͣ���̱��ݿ�¼����
#define GUI_CD_BACKUP_STOP_RSP			-718 //ǿ��ֹͣ���̱��ݿ�¼�����Ӧ

#define GUI_CD_BACKUP_STOP_OK      		0    //ǿ��ȡ���ɹ�
#define GUI_CD_BACKUP_STOP_ERR     		1    //ǿ��ȡ��ʧ��

typedef struct
{
	int m_iCdNo;
}TGuiCdBackupStopReq;     //ǿ��ֹͣ���̱��ݿ�¼����

typedef struct				// ǿ��ֹͣ���ݻ�Ӧ
{
	int m_iCdNo;
	int m_iRetCode;			
} TGuiCdBackupStopRsp;  	//ǿ��ֹͣ���̱��ݿ�¼�����Ӧ


#define GUI_CD_BACKUP_START_REQ_EX		719	//��¼��ʼ֪ͨ
#define GUI_CD_BACKUP_START_RSP_EX		-719 

typedef struct
{
	int m_iCdNo;              //������ GUI_DISK_CD(ԭ���߼�) GUI_DISK_SEC_CD_ID (�����߼�)
	int m_iCdBackUpMode;      //Ԥ������ģʽ
}TGuiCdBackUpStartReqEx;    //��չ��¼���ݿ�ʼЭ������

typedef struct
{
	int m_iCdNo;            //������
	int m_iRetCode;
}TGuiCdBackUpStartRspEx; //��չ��¼���ݿ�ʼЭ���Ӧ


// ����ʵʱ��¼
#define GUI_CBL_MAX_CD		2

enum	//��¼ģʽ
{
	GUI_CBL_MODE_SCD = 0,	//���̿�¼
	GUI_CBL_MODE_DCD = 1,	//˫�̿�¼
	GUI_CBL_MODE_CYC = 2,	//�ֿ�
	GUI_CBL_MODE_NSP = -1, //��֧��ʵʱ��¼����
};

typedef struct
{
	int m_iMode;				// ��¼ģʽ
	int m_iCd;				// ������,���̿�¼ʱʹ��(1, 2)
	int m_iChnEnBits; 			// ��¼ͨ��ʹ��λ,bit:0-31��1-32ͨ��
	int m_iReserved;			//ͨ����Ŀ����32ʱʹ��
} TGuiCblModeMsg;

#define GUI_CBL_MODE_GET_REQ			724	//��ȡʵʱ��¼ģʽ����
#define GUI_CBL_MODE_GET_RSP			-724 //��ȡʵʱ��¼ģʽ��Ӧ
typedef struct				// ��ȡ��¼ģʽ��Ӧ
{
	TGuiCblModeMsg m_tMode;
} TGuiCblModeGetRsp;

//�رտ�¼���屣���¼ģʽ
#define GUI_CBL_MODE_SET_REQ			725	//����ʵʱ��¼ģʽ����(Ԥ��)
#define GUI_CBL_MODE_SET_RSP			-725	//����ʵʱ��¼ģʽ��Ӧ(Ԥ��)

typedef struct
{
	TGuiCblModeMsg m_tMode;
}TGuiSetCblModeReq;                   //���ÿ�¼ģʽ����

typedef struct
{
	int m_iRetCode;
}TGuiSetCblModeRsp;                  //���ÿ�¼ģʽ��Ӧ


#define GUI_CBL_START_REQ				726	//��������ʵʱ��¼����
#define GUI_CBL_START_RSP				-726 //��������ʵʱ��¼��Ӧ

typedef struct				// ����ʵʱ��¼����
{
	TGuiCblModeMsg m_tMode;
} TGuiCblStartReq;

typedef struct				// ����ʵʱ��¼��Ӧ
{
	int m_iPid;				// ʵʱ��¼�����ţ�-1��ʽ����ʧ��
} TGuiCblStartRsp;



//=======================��ҵǶ��ʽ==================
#define GUI_CBL_GET_MODEEX_REQ			733	//��ȡʵʱ��¼��չģʽ����
#define GUI_CBL_GET_MODEEX_RSP			-733 //��ȡʵʱ��¼��չģʽ��Ӧ

#define GUI_CBL_DISC_LABEL_LEN       	63
typedef struct
{
	int m_iSealDisc;									//��¼����Ƿ����
	int m_iSpeed;										//��¼����,������ֵΪʵ��ֵ�������Ϊ16����
	int m_PopDisc;										//��¼����Ƿ���
	int m_iDiscType;   									//��������
	int m_iBurnTimes;  									//��¼ʱ��
	char m_cDiscLabel[GUI_CBL_DISC_LABEL_LEN + 1];		//���̱�ǩ
}TGuiCblModeMsgEx;

typedef struct
{
	TGuiCblModeMsgEx m_tModeEx;
}TGuiCblGetModeExRsp;

#define GUI_CBL_SET_MODEEX_REQ			734	//����ʵʱ��¼��չģʽ����
#define GUI_CBL_SET_MODEEX_RSP			-734 //����ʵʱ��¼��չģʽ��Ӧ

typedef struct
{
	TGuiCblModeMsgEx m_tModeEx;
}TGuiCblSetModeExReq;

#define GUI_CBL_SET_MODEEX_OK  0   //���óɹ�
#define GUI_CBL_SET_MODEEX_ERR 1	//����ʧ��
typedef struct
{
	int m_iRetCode;
}TGuiCblSetModeExRsp;

#define GUI_CBL_SET_POP_DISC_REQ      735 //���̳�������
#define GUI_CBL_SET_POP_DISC_RSP      -735 //���̳��ֻ�Ӧ

typedef struct
{
	int m_iMode;   //��¼ģʽ
	int m_iCdNo;   // 0 --������ (˫�̺�ѭ����¼�����̳���)������ʱΪ��ȡ�Ĺ�����
}TGuiCblSetPopDiscReq;

typedef struct
{
	int m_iRetCode;
}TGuiCblSetPopDiscRsp;


#define GUI_SET_CBL_DVD_NUM_REQ   790//���ÿ�¼���̵ĺ��̺ͻ�����������
#define GUI_SET_CBL_DVD_NUM_RSP	  -790//���ÿ�¼���̵ĺ��̺ͻ���������Ӧ

typedef struct
{
	int m_iCdNo; //������ Ԥ��
	int m_iOkNum; 
	int m_iErrNum;
}TGuiSetCblDvdNumReq;

typedef struct
{
	int m_iRetCode;
}TGuiSetCblDvdNumRsp;




//======================================================


#define GUI_CBL_END_REQ					727	//��ֹʵʱ��¼�������
#define GUI_CBL_END_RSP					-727	//��ֹʵʱ��¼�������


typedef struct				// ��ֹ����ʵʱ��¼���������
{
	int m_iPid;				// �����ţ���TGuiCblStartRsp����
} TGuiCblEndReq;

#define GUI_CBL_END_OK		0
#define GUI_CBL_END_ERR		1
typedef struct				// ��ֹ����ʵʱ��¼���������
{
	int m_iRetCode;				// �����ţ���TGuiCblStartRsp����
} TGuiCblEndRsp;


#define GUI_CBL_TAG_ALL_PID	-1
typedef struct				// �������
{
	int m_iPid;				// �����ţ�-1��ʽȫ�����������
	int m_iChn;				// ͨ���ţ�Ĭ��0������ͨ��
} TGuiCblTagReq;

#define GUI_CBL_TAG_OK 	0
#define GUI_CBL_TAG_ERR	1
typedef struct
{
	int m_iRetCode;
} TGuiCblTagRsp;

#define GUI_ONEKEY_CBL_REQ              732  //һ����¼����
#define GUI_ONEKEY_CBL_RSP              -732 //һ����¼��Ӧ

typedef struct
{
	int m_iRetCode;
}TGuiOneKeyCblRsp;


#define GUI_ONEKEY_CBL_EX_REQ			736 //����һ����¼����
#define GUI_ONEKEY_CBL_EX_RSP			-736

typedef enum
{	
	ACT_CBL_START = 0,	//��ʼһ����¼
	ACT_CBL_STOP,		//����һ����¼
	ACT_REC_START,		//��ʼ��Ѷ��¼��ģʽ
	ACT_REC_STOP,		//������Ѷ��¼��ģʽ
}TGuiOneKeyCblAct;    //���ģʽ

typedef struct
{
	int m_iAct; //TGuiOneKeyCblAct
}TGuiOneKeyCblExReq;

typedef struct
{
	int m_iRetCode;    //����ֵ����ͬTGuiOneKeyCblRsp��m_iRetCode;
}TGuiOneKeyCblExRsp;


#define GUI_GET_PLAYABLECD_CNT_REQ    737	//��ȡ����״̬
#define GUI_GET_PLAYABLECD_CNT_RSP    -737	//��ȡ����״̬

typedef enum
{
	GUI_DVD_DRIVER_NO_INFO	= 0,	
	GUI_DVD_DRIVER_NO_DISC	= 1,	//����
	GUI_DVD_DRIVER_OPEN		= 2,	//��������
	GUI_DVD_DRIVER_NOT_READY	= 3,	//�������ƽ�ȥ
	GUI_DVD_DRIVER_DISC_OK		= 4,	//����������׼����
}TGuiDvdDriverState;

typedef struct								
{
	int m_iDvdDriverSta[GUI_CBL_MAX_CD];			//����״̬������״̬��ö��
}TGuiGetDvdDriverStateRsp;


#define GUI_GET_DISK_LEFT_RECTIME_REQ    738	//��ȡӲ��ʣ��¼��ʱ������
#define GUI_GET_DISK_LEFT_RECTIME_RSP    -738	//��ȡӲ��ʣ��¼��ʱ����Ӧ

typedef struct
{
	int m_iWhetherDiskSatisfy;			//Ӳ��ʣ��¼��ʱ���Ƿ�����������������Ѷ�豣��24Сʱ(0-�����㣬1-����)
	int m_iDiskLeftFreeSize;			//Ӳ��ʣ��ռ䣬��λ��M
	int m_iDiskLeftRecTime;			//Ӳ��ʣ��¼��ʱ������λ������
}TGuiGetDiskLeftRecTimeRsp;


//=================�����ļ���ѯ==================

// ���̻ط����Э��(ֻ��ӹ����ļ���ѯ�������Ϣ��ȡЭ��)
// ���̻ط�Э����ԭ�еı�׼�ط�Э��
#define GUI_CBL_FILE_QUERY_REQ			730	//���������ļ�����
#define GUI_CBL_FILE_QUERY_RSP			-730

enum // ��¼״̬
{
	GUI_CBL_STA_FREE	= 0, //�����У�
	GUI_CBL_STA_DOING	= 1, //���ڿ�¼��
	GUI_CBL_STA_PACK	= 2, //���ڴ��
};

enum // ����״̬
{
	GUI_CBL_CD_STA_FREE	= 0, //����δʹ��
	GUI_CBL_CD_STA_BUSY	= 1, //�������ڿ�¼
	GUI_CBL_CD_STA_BAD	= 2, //��������
	GUI_CBL_CD_STA_FULL	= 3, //�����Ѿ���
	GUI_CBL_CD_STA_PACK	= 4, //�������ڴ��
	GUI_CBL_CD_STA_NODISK = 5, //û�������
	GUI_CBL_CD_STA_CHECKDISK = 6,//���̼����
	GUI_CBL_CD_STA_BURN_FINISH = 7, //���̿�¼���
	GUI_CBL_CD_STA_FORMATDISK	= 8,	//���̳�ʼ����
};

typedef struct		// ����¼���ļ���ѯ����
{
	int m_iCd;		// cd��ţ�Ĭ��0��ʽȫ��cd
	int m_iChn;		// ͨ����, 0��ʾ����
	int m_iStartId;	// ��ʱ��������¼�Ŀ�ʼ����
	int m_iMaxCnt;	// ��Ҫ��ȡ�ļ�¼����
	int m_iStartTm;	// ��ʼʱ��(Ԥ����Ĭ��Ϊ0)
	int m_iEndTm;	// ����ʱ��(Ԥ����Ĭ��Ϊ0)
} TGuiCblFileQueryReq;

typedef struct
{
	int m_iCnt;		//���ȡ����������(-1��ʧ��)
} TGuiCblFileQueryRsp; //�����m_iCnt��TGuiVideoFileMsg��¼



#define GUI_CBL_FILE_FREE_COURT_QUERY_REQ			5021	//���������ļ���ͥʱ�������
#define GUI_CBL_FILE_FREE_COURT_QUERY_RSP			-5021

#define MAX_FREE_COURT_CNT	512

typedef struct		// ����¼���ļ���ͥʱ��β�ѯ����
{
	int m_iCd;		// cd��ţ�Ĭ��0��ʽȫ��cd
	char m_strFileName[GUI_VF_NAME_LEN + 1];	//¼���ļ���
	int m_iMaxCnt;	// ��Ҫ��ȡ�ļ�¼����
} TGuiCblFileFreeCourtQueryReq;

typedef struct
{
	int m_iCnt;		//���ȡ����������(-1��ʧ��)
} TGuiCblFileFreeCourtQueryRsp; //�����m_iCnt��TGuiCblVideoFileFreeCourtMsg��¼

typedef struct		//��ͥʱ�������
{
	int m_iBeginTm;	//��ͥʱ��ο�ʼʱ��
	int m_iEndTm;	//��ͥʱ��ν���ʱ��
} TGuiCblVideoFileFreeCourtMsg;



//*******��ȡ����¼���ļ������Ϣ***********//
#define GUI_CBL_TAG_QUERY_REQ			731	//��ȡ�����Ϣ����
#define GUI_CBL_TAG_QUERY_RSP			-731

typedef struct		// ����¼������Ϣ��ѯ����
{
	int m_iCd;		// cd���, 0������cd
	int m_iChn;		// ͨ����, 0������ͨ��
	int m_iStartId;	// ��¼��ʼ���
	int m_iMaxCnt;	// �����Ϣ�������
	int m_iStartTm;	// ��ʼʱ��
	int m_iEndTm;	// ����ʱ��
} TGuiCblTagQueryReq;    //ȫ����ȡ�����Ϣ

typedef struct
{
	char m_strFileName[GUI_VF_NAME_LEN + 1];
}TGuiCblTagQueryReqEx; //���ļ���ȡ�����Ϣ

typedef struct
{
	int m_iCnt;		//��������
} TGuiCblTagQueryRsp; //�����m_iCnt��TGuiCblTagMsg��¼;

typedef struct
{
	int m_iChn;
	int m_iStartTm;
	int m_iEndTm;
} TGuiCblTagMsg;

//*****��ȡӲ��¼���ļ��Ĵ����Ϣ*********//
typedef struct
{
	char m_strFileName[GUI_VF_NAME_LEN + 1];
}TGuiGetMarkMsgReq;   //���ļ���ȡ�����Ϣ

typedef struct
{
	int m_iCnt;		//��������
} TGuiGetMarkMsgRsp; //�����m_iCnt��TGuiCblTagMsg��¼;

typedef struct
{
	int m_iChn;
	int m_iStartTm;
	int m_iEndTm;
} TGuiMarkMsg;


//================��ȡӲ��¼���ļ�һ��ʱ��Ĵ����Ϣ============
#define GUI_GET_PERIODOFTIME_MARK_MSG_REQ   739  //��ȡһ��ʱ���ڵĴ����Ϣ����
#define GUI_GET_PERIODOFTIME_MARK_MSG_RSP   -739 //��ȡһ��ʱ���ڵĴ����Ϣ��Ӧ
typedef struct
{
	char m_strFileName[GUI_VF_NAME_LEN + 1];  //¼���ļ���(�ɰ����ļ�����ѯ)
	int m_iChn;								  //¼��ͨ��
	int m_iStartTm;							  //��ѯ�����Ϣ�Ŀ�ʼʱ��
	int m_iEndTm;							  //��ѯ�����Ϣ�Ľ���ʱ��
}TGuiGetPeriodOfTimeMarkMsgReq;			  //��ȡһ��ʱ���ڵĴ����Ϣ����

#define TGuiGetPeriodOfTimeMarkMsgRsp TGuiGetMarkMsgRsp  //��ȡһ��ʱ���ڵĴ����Ϣ��Ӧ
#define TGuiPeriodOfTimeMarkMsg TGuiMarkMsg				//�����Ϣ�ṹ��
	
//==============��������================
#define GUI_VIDEO_PLAY_VCA_SEARCH_REQ 	1116
#define GUI_VIDEO_PLAY_VCA_SEARCH_RSP	-1116

#define GUI_VP_VCA_SEARCH_MAX_CNT 	1024     //����������������Ŀ
typedef struct
{	
	int m_iCurTime;		//��ǰʱ��
	int m_iType;           //���ܷ����¼����� ʹ��֮ǰ��ö������EGuiVcaEventType
	char m_strFileName[GUI_VF_NAME_LEN + 1];
}TGuiVpVcaSearchReq; //������������

typedef  TGuiCblTagQueryRsp	TGuiVpVcaSearchRsp;

typedef TGuiCblTagMsg		TGuiVcaSearchMsg; //�����������

#define GUI_VIDEO_PLAY_VCA_SEARCH_REQ_EX 	 1117
#define GUI_VIDEO_PLAY_VCA_SEARCH_RSP_EX	 -1117

typedef struct
{	
	int m_iChn;		//ͨ��
	int m_iType;           //���ܷ����¼����� ʹ��֮ǰ��ö������EGuiVcaEventType
	int m_iBeginTm;
	int m_iEndTm;
	char m_strFileName[GUI_VF_NAME_LEN + 1];
}TGuiVpVcaSearchReqEx; //������������

typedef  TGuiCblTagQueryRsp	TGuiVpVcaSearchRspEx;

//���ܻط��첽����Э��
#define GUI_START_VP_VCA_SEARCH_REQ     5010
#define GUI_START_VP_VCA_SEARCH_RSP		-5010

typedef TGuiVpVcaSearchReqEx TGuiStartVpVcaSearcReq;
typedef struct 
{
	int m_iSearchId;
}TGuiStartVpVcaSearcRsp;



#define GUI_GET_VP_VCA_SEARCH_STAT_REQ     5011
#define GUI_GET_VP_VCA_SEARCH_STAT_RSP	-5011
enum
{
	GUI_VP_VCA_SEARCH_OVER = 0,
	GUI_VP_VCA_SEARCH_DOING
}; 
typedef TGuiStartVpVcaSearcRsp TGuiGetVpVcaSearcStatReq;
typedef struct 
{
	int m_iSearchId;
	int m_iStat;			//��16λ��������״̬����16λ��ʾ�Ƿ����
	int m_iSearchPro;      //���� 0-100
	int m_iSearchCurTm;		//��ǰ����ʱ��
}TGuiGetVpVcaSearcStatRsp;


#define GUI_GET_VP_VCA_SEARCH_RESULT_REQ     	5012
#define GUI_GET_VP_VCA_SEARCH_RESULT_RSP		-5012

typedef TGuiStartVpVcaSearcRsp TGuiGetVpVcaSearcResultReq;

typedef  TGuiCblTagQueryRsp TGuiGetVpVcaSearchResultRsp;


// *****************�������**********************//

#define GUI_GET_VP_VCA_FACESEA_RESULT_REQ		5013	//���������������
#define GUI_GET_VP_VCA_FACESEA_RESULT_RSP		-5013	//�������������Ӧ

typedef  TGuiStartVpVcaSearcRsp TGuiGetVpVcaFaceSeaResultReq;
typedef  TGuiCblTagQueryRsp TGuiGetVpVcaFaceSeaResultRsp;

typedef struct
{
	unsigned short	m_usLeft;
	unsigned short	m_usTop;
	unsigned short	m_usRight;
	unsigned short	m_usBottom;
}TGuiVcaRect;

typedef  struct
{
	int 	m_iChn;
	int 	m_iFaceId;      //����ID
	int 	m_iBeginTm;
	int 	m_iEndTm;
	int 	m_iFileloc;
	int 	m_iFrameNo;
	TGuiVcaRect m_tRect;
} TGuiFaceMsg;
//����m_iCnt��TGuiFaceMsg

#define  GUI_START_VP_VCA_DSPFACE_REQ			5014	//������ʾ����
#define  GUI_START_VP_VCA_DSPFACE_RSP			-5014	//������ʾ��Ӧ

typedef struct
{
	int  m_iChn;
	int  m_iFaceId;       //FaceID 
	int  m_iBeginTm;
	int	 m_iEndTm;
	int  m_iFileloc;
	int  m_iFrameNo;
	TGuiVcaRect m_tRect;
	char m_strFaceName[ GUI_PUBLIC_LEN_63 + 1];	//�������ȫ·�������ļ���������ext4����
}TGuiStartVpFaceDspReq;

/*uiָ��·�����ں���������bmp��ʽ��ͼƬ��ui���������ʾ��*/

typedef struct
{
	int  m_iRetCode;		//0��ɹ��������ʧ��
 }TGuiStartVpFaceDspRsp;

//���Ҳ�������ʱ�� ֱ�ӷ���λ������

//*************����ͳ��*********************//
#define GUI_GET_VP_VCA_PEOPLE_CNT_REQ		5015	//����ͳ�ƽ������
#define GUI_GET_VP_VCA_PEOPLE_CNT_RSP		-5015	//����ͳ�ƽ����Ӧ
typedef  TGuiStartVpVcaSearcRsp TGuiGetVpVcaPeopleSeaResultReq;
typedef  TGuiCblTagQueryRsp TGuiGetVpVcaPeopleSeaResultRsp;

typedef  struct 
{
	int  m_iChn;
	int  m_iBeginTm;
	int		m_iInCnt;			//���������
	int		m_iOutCnt;			//��ȥ������
} TGuiGetVpVcaPeopleCntRsp;


//**********************����ʶ��*****************//
#define GUI_START_VP_VCA_SEARCHCAR_REQ		5018  //��ʼ������������
#define GUI_START_VP_VCA_SEARCHCAR_RSP		-5018 	//��Ӧ

typedef enum
{
	GUI_VCA_SEARCH_BY_CAR = 1, //��ͨ����һ������
	GUI_VCA_SERACH_BY_CHN = 2, //��ͨ���������г���
}EGuiCarType;

typedef struct
{
	int 		m_iChnList[32];	//ÿ��bit��ʾһ��ͨ�������֧��1024��ͨ��;
	int 		m_iType;		//�������� ��ö��EGuiCarType
	int  		m_iBeginTm;		//��ʼʱ��
	int 	 	m_iEndTm;		//����ʱ��
	char 	m_strCarNo[GUI_PUBLIC_LEN_63 + 1];
}TGuiVcaCarSearchReq;

typedef struct
{
	int  m_iSearchId;   //����id������idҪ���
}TGuiVcaCarSearchRsp;

#define  GUI_START_VP_VCA_DSPCAR_REQ			5019     //������ʾ����
#define 	GUI_START_VP_VCA_DSPCAR_RSP			-5019	 //��Ӧ

typedef struct
{
	int  m_iSearchId;          
}TGuiStartVpCarDspReq;

typedef struct
{
	int  m_iCnt;         //����ʵ�ʵĳ�����,�����m_iCnt��TGuiVcaCarMsg�ṹ����Ϣ
}TGuiStartVpCarDspRsp;

typedef struct
{
	int		m_iChn;
	int		m_iBeginTm;
	int 	m_iEndTm;
	char 	m_strCarNo[GUI_PUBLIC_LEN_63 + 1];
}TGuiVcaCarMsg;


#define  GUI_VIDEO_PLAY_PERIOD_REQ    5200     //��ʱ�λط�����
#define  GUI_VIDEO_PLAY_PERIOD_RSP	  -5200    //��ʱ�λطŻ�Ӧ
typedef struct
{
	int  m_iChn;            //ͨ����
	int  m_iPlayId;         //voλ��id
	int  m_iBeginTm;		//��ʼʱ��	
	int  m_iEndTm;		//����ʱ��
}TGuiPeriodVideoPlayReq;

typedef struct
{
	int  m_iRetCode;          //����ֵ
}TGuiPeriodVideoPlayRsp;


#define GUI_SET_PEOPCNT_REPORT_REQ	5201  //����ͳ�Ƶ�����������
#define GUI_SET_PEOPCNT_REPORT_RSP	-5201 //����ͳ�Ƶ��������Ӧ

typedef enum
{
	GUI_XLS = 1,
	GUI_TXT,
	GUI_DOC,
}EGuiReportEnum;

typedef struct
{
	int m_iType;   //������ʽ ��ö��EGuiReportEnum
	char m_cPath[GUI_PUBLIC_LEN_127 + 1]; //����·��
}TGuiPeopCntReportReq;

typedef struct
{
	int m_iRetCode;
}TGuiPeopCntReportRsp;

//========================end================


//================ͨ���������Э��=========================
typedef enum
{
	GUI_DIGITAL_CHN  = 0,//����ͨ��
	GUI_LOCAL_CHN,  //����ģ��ͨ��
	GUI_VC_CHN,	     //�ϳ�ͨ��
}TGuiChannelType; //ͨ������

typedef struct
{
	int m_iChn; //ͨ����
}TGuiGetChnTypeReq;

typedef struct
{
	int m_iChn;
	int m_iType;  //ͨ������
}TGuiGetChnTypeRsp;


#define GUI_STREAM_ALL_TYPE   0 //ȫ��
#define GUI_STREAM_MAIN_TYPE  1 //������ 
#define GUI_STREAM_SUB_TYPE   2 //������

#define GUI_GET_CHN_ENABLE_STAT_REQ   805  //��ȡͨ������״̬����
#define GUI_GET_CHN_ENABLE_STAT_RSP   -805  //��ȡͨ������״̬��Ӧ
typedef struct
{
	int m_iChn;
	int m_iStreamType; //0-ȫ����1-������,2-������ ( Ĭ��Ϊ1)
}TGuiGetChnEnableStatReq;
typedef struct
{
	int m_iChn;
	int m_iStat;//ͨ������״̬1-����, 2-�����ã�(��չ16λ,0-ͨ��״̬����ԭ�����ݣ�1-�����ӣ�2-δ����)
}TGuiGetChnEnableStatRsp;
/*���ݳ�Աm_iStat��16λ��ֵ����һ������δ���ӳɹ���ԭ��
3-δ���ӣ��û������������
4-δ���ӣ�IP������
5-δ���ӣ��˺ű�����
6-δ���ӣ��Ѿ��ﵽ���������
7-δ���ӣ������쳣
8-δ���ӣ��������ﵽ����*/


#define GUI_SET_CHN_ENABLE_STAT_REQ   806  //����ͨ������״̬����
#define GUI_SET_CHN_ENABLE_STAT_RSP   -806  //����ͨ������״̬��Ӧ


typedef struct
{
	int m_iChn;
	int m_iStat;//ͨ������״̬1-���� ,2-������(��չ16λ,0-ͨ��״̬����ԭ�����ݣ�1-�����ӣ�2-δ����)
	int m_iStreamType; //0-ȫ����1-������,2-������(Ĭ��Ϊ0)
}TGuiSetChnEnableStatReq;  //����ͨ������״̬����
typedef struct
{
	int m_iRetCode;
}TGuiSetChnEnableStatRsp; //����ͨ������״̬��Ӧ

//����ģ��ͨ��
typedef struct
{
	int m_iChn;
}TGuiGetLocalChnAttrReq; //��ȡ����ģ��ͨ������

typedef struct
{
	int m_iChn;
	char m_cLocalChnAttr[32];
}TGuiGetLocalChnAttrRsp; //��ȡ����ģ��ͨ����Ӧ

//�ϳ�ͨ��
typedef struct
{
	int m_iChn;
}TGuiGetVcChnAttrReq; //��ȡ�ϳ�ͨ������

typedef struct
{
	int m_iChn;
	char m_cVcChnAttr[32];
}TGuiGetVcChnAttrRsp; //�ϳ�ͨ�����Ի�Ӧ


// ����ͨ�����Э��

enum
{
	GUI_DIG_CHN_IP = 0,			//IP��ַ
	GUI_DIG_CHN_HOSTNAME,	 //����
	GUI_DIG_CHN_IMD,			//����ģʽ
};

enum
{
	GUI_DIG_CHN_TCP = 0,	//tcp
	GUI_DIG_CHN_UDP,		//udp
	GUI_DIG_CHN_BC,		//�ಥ
};

#define GUI_DIG_CHN_URL_LEN		39
#define GUI_DIG_CHN_PTZ_NAME		31
#define GUI_DIG_CHN_NAME_LEN		31

#define GUI_DIG_CHN_STAT_ENABLE    1
#define GUI_DIG_CHN_STAT_DISENABLE 2


//�豸����
enum
{
	GUI_DEV_TYPE_PRIVATE = 0, //�豸����Ϊ˽������
	GUI_DEV_TYPE_ONVIF,      //�豸����Ϊonvif
	GUI_DEV_TYPE_PUSH,    //�豸����Ϊpush��
	GUI_DEV_TYPE_RTSP,   //�豸����ΪRTSP
};

//����ģʽ
enum
{
	GUI_DIG_CHN_S_LNET = 0, //������
	GUI_DIG_CHN_S_HNAME, 	//����
	GUI_DIG_CHN_S_AMOD,	//����ģʽ
};

#define GUI_DIG_TIANDY_DEV   GUI_DEV_TYPE_PRIVATE
#define GUI_DIG_ONVIF_DEV    GUI_DEV_TYPE_ONVIF
#define GUI_DIG_RTSP_DEV     GUI_DEV_TYPE_RTSP

/*
m_iConnectMod ��ʾ����:

0x00000000  - ˽�� ip 
0x00000001 - ˽�� ����
0x00000002 - ˽�� ����
0x00010000 - onvif TCP
0x00010001 - onvif UDP
0x00020000 - PUSH
0x00030000 - RTSP
*/

// ����ͨ��
#define GUI_SET_DIG_CHN_REQ			740	//��������ͨ����������
#define GUI_SET_DIG_CHN_RSP			-740 //��������ͨ��������Ӧ


typedef struct
{
	int m_iConnectMod;		//��16λ0-˽�У�1-onvif���������� 
	char m_strUrl[GUI_DIG_CHN_URL_LEN  + 1]; //��������ַ
	char m_strProxy[GUI_DIG_CHN_URL_LEN  + 1]; //����IP
	int m_iPort;	//�˿ں�
	int m_iChn;	//�Է�ͨ����
	int m_iStreamType;	//��������,0:������, 1������2:��Ƶ��
	int m_iConntectType;  //tcp/udp/bc
	int m_iPtzAddr;	//ptz��ַ (m_iConntectTypeΪbcģʽʱ�����ʾ�ಥ�˿ں�)
	char m_strPtzProtocol[GUI_DIG_CHN_PTZ_NAME + 1]; //ptzЭ�� (m_iConntectTypeΪbcģʽʱ�����ʾ�ಥ��ַ)
	char m_strUserName[GUI_DIG_CHN_NAME_LEN + 1]; //�û���
	char m_strUserPsw[GUI_DIG_CHN_NAME_LEN + 1];	//����
	int m_iEnable;    //״̬
	char m_strVdecPsw[GUI_DIG_CHN_NAME_LEN + 1];	//��Ƶ��������
} TGuiDigChnMsg;


#define GUI_SET_DIG_CHN_OK 0
#define GUI_SET_DIG_CHN_ERR 1

#define GUI_DIG_CHN    0  //����ͨ��
#define GUI_SIM_CHN    1  //ģ��ͨ��
typedef struct		//��������ͨ������
{
	int m_iType;		//����:0��������ͨ��, 1����Ϊģʽͨ��(Ԥ��)
	int m_iChn;		//ͨ����
	TGuiDigChnMsg m_tChnMsg; //ͨ����Ϣ
} TGuiSetDigChnReq;

typedef struct
{
	int m_iRetCode;
} TGuiSetDigChnRsp;

#define GUI_GET_DIG_CHN_REQ			741	//��������ͨ����������
#define GUI_GET_DIG_CHN_RSP			-741 //��������ͨ��������Ӧ

typedef struct		//��ȡ����ͨ����Ϣ����
{
	int m_iChn;
} TGuiGetDigChnReq;

typedef struct
{
	int m_iChn;		// -1��ʧ��
	TGuiDigChnMsg m_tChnMsg;
} TGuiGetDigChnRsp;

typedef struct
{
	int m_iConnectMod;		//��16λ0-˽�У�1-onvif���������� 
	char m_strUrl[GUI_DIG_CHN_URL_LEN  + 1]; //��������ַ
	char m_strProxy[GUI_DIG_CHN_URL_LEN  + 1]; //����IP
	int m_iPort;	//�˿ں�
	int m_iChn;	//�Է�ͨ����
	int m_iStreamType;	//��������,0:������, 1������2:��Ƶ��
	int m_iConntectType;  //tcp/udp/bc
	int m_iPtzAddr;	//ptz��ַ (m_iConntectTypeΪbcģʽʱ�����ʾ�ಥ�˿ں�)
	char m_strPtzProtocol[GUI_DIG_CHN_PTZ_NAME + 1]; //ptzЭ�� (m_iConntectTypeΪbcģʽʱ�����ʾ�ಥ��ַ)
	char m_strUserName[GUI_DIG_CHN_NAME_LEN + 1]; //�û���
	char m_strUserPsw[GUI_DIG_CHN_NAME_LEN + 1];	//����
	int m_iEnable;    //״̬
	char m_strVdecPsw[GUI_DIG_CHN_NAME_LEN + 1];	//��Ƶ��������
	char m_strRtspUrl[GUI_PUBLIC_LEN_255 + 1]; //������չRTSP�ĵ�ַ����RTSP ��ַ���ȴ���80�ֽ�ʱ��ʹ�ñ��ֶΣ�����ʹ��ԭ�ֶΡ�
	char m_strMac[GUI_IP_STR_LEN + 1];			//mac��ַ
} TGuiDigChnMsgEx;

#define	GUI_GET_DIG_CHN_REQ_EX	747	//��ȡ����ͨ����������
#define GUI_GET_DIG_CHN_RSP_EX	-747	//��ȡ����ͨ��������Ӧ
typedef struct		//��ȡ����ͨ����Ϣ����
{
	int m_iChn;
} TGuiGetDigChnReqEx;

typedef struct
{
	int m_iChn;		// -1��ʧ��
	TGuiDigChnMsgEx m_tChnMsg;
} TGuiGetDigChnRspEx;

#define GUI_SET_DIG_CHN_REQ_EX			748	//��������ͨ����������
#define GUI_SET_DIG_CHN_RSP_EX			-748 //��������ͨ��������Ӧ

typedef struct		//��������ͨ������
{
	int m_iType;		//����:0��������ͨ��, 1����Ϊģʽͨ��(Ԥ��)
	int m_iChn;		//ͨ����
	TGuiDigChnMsgEx m_tChnMsg; //ͨ����Ϣ
} TGuiSetDigChnReqEx;

typedef struct
{
	int m_iRetCode;
} TGuiSetDigChnRspEx;



#define GUI_SEARCH_DIG_CHN_REQ		742	//��������ͨ������
#define GUI_SEARCH_DIG_CHN_RSP			-742	//��������ͨ����Ӧ

#define GUI_DIG_CHN_ID_LEN  39
typedef struct
{
	char m_strUrl[GUI_DIG_CHN_URL_LEN  + 1]; //��������ַ
	int m_iPort;	//�˿ں�
	int m_iChn;	//�Է�ͨ����
	char m_strServerType[GUI_DIG_CHN_NAME_LEN + 1];//����������
	char m_strDeviceID[GUI_DIG_CHN_ID_LEN + 1];//�����豸ID
	char m_strServerName[GUI_DIG_CHN_NAME_LEN + 1];//����������
	char m_strProxy[GUI_DIG_CHN_URL_LEN  + 1]; //����IP
}TGuiSearchChnMsg;

//�¼�����ͨ����ȡ������
#define GUI_GET_SDIG_CHN_REQ_EX			745	//��ȡ����ͨ���������
#define GUI_GET_SDIG_CHN_RSP_EX			-745	//��ȡ����ͨ�������Ӧ

typedef struct
{
	int m_iPort;	//�˿ں�
	int m_iChn;	//�Է�ͨ����
	char m_strUrl[GUI_DIG_CHN_URL_LEN  + 1]; //��������ַ,IP��ַ
	char m_strServerType[GUI_DIG_CHN_NAME_LEN + 1];//����������
	char m_strDeviceID[GUI_DIG_CHN_ID_LEN + 1];//�����豸ID
	char m_strServerName[GUI_DIG_CHN_NAME_LEN + 1];//����������
	char m_strProxy[GUI_DIG_CHN_URL_LEN  + 1]; //����IP
	char m_strMac[GUI_IP_STR_LEN + 1];			//mac��ַ
	char m_strSubMsk[GUI_IP_STR_LEN + 1];		//��������
	char m_strGateWay[GUI_IP_STR_LEN + 1];		//����
	char m_strDNS[GUI_IP_STR_LEN + 1];			//��������
}TGuiSearchChnMsgEx;

#define	GUI_GET_CBL_CDSERIALNO_REQ	746	//��ȡ�������к�����
#define GUI_GET_CBL_CDSERIALNO_RSP	-746	//��ȡ�������кŻ�Ӧ

#define GUI_CBL_SERIALNO_LEN	16	//���кų���

typedef struct	//��ȡ�������к�����
{
	int m_iCdId;	//������
}TGuiGetSerialNoReq;

typedef struct //��ȡ�������кŻ�Ӧ
{
	int m_iCdId;	//������
	char m_strSerialNum[GUI_CBL_SERIALNO_LEN + 1];		//���к�
}TGuiGetSerialNoRsp;


//onvif  �޸�IP
#define GUI_ONVIF_CHANGE_IP_CMD_REQ	822  //�޸�ǰ��onvif  IPC��IP����
#define GUI_ONVIF_CHANGE_IP_CMD_RSP	-822  //��Ӧ
#define GUI_ID_STR_LEN 39
#define GUI_SERVNAME_STR_LEN 39

typedef struct
{
	int m_iChn;
	char m_strMac[GUI_IP_STR_LEN + 1];			//mac��ַ
	char m_strIp[GUI_IP_STR_LEN + 1];			//IP��ַ
	char m_strSubMsk[GUI_IP_STR_LEN + 1];		//��������
	char m_strGateWay[GUI_IP_STR_LEN + 1];		//����
	char m_strDNS[GUI_IP_STR_LEN + 1];			//��������
	char m_strFactryID[GUI_ID_STR_LEN + 1];		// 
	char m_strServerName[GUI_SERVNAME_STR_LEN + 1];
	char m_strUserName[GUI_ID_STR_LEN + 1];  //�û���
	char m_strPassword[GUI_ID_STR_LEN + 1];	//����
}TGuiChangeOnvifIpReq;

typedef struct
{
	int m_iRetCode;
} TGuiChangeOnvifIpRsp;


/*
m_iSearchMod ��ʾ����:

0x00000000  - ˽�� ip 
0x00000001 - ˽�� ����
0x00000002 - ˽�� ����
0x00010000 - onvif TCP
0x00010001 - onvif UDP
0x00020000 - PUSH
0x00030000 - RTSP

*/
//m_iSearchMod ��m_iConnectMod��һ����
typedef struct		//��������ͨ������
{
	int m_iSearchMod;	//����ģʽ ��16 ��ʾ�豸���ͣ�0-˽�У�1-onvif, 
						//��16λ������ģʽ��˽��Э����0��ʾ
} TGuiSearchDigChnReq;

typedef struct
{
	int m_iSid;	//������ѯ�ţ��Ժ󰴴˺Ż�ȡ���������-1��ʧ��
} TGuiSearchDigChnRsp;
#define GUI_GET_SDIG_CHN_REQ			743	//��ȡ����ͨ���������
#define GUI_GET_SDIG_CHN_RSP			-743	//��ȡ����ͨ�������Ӧ


typedef struct	//��ȡͨ�������������
{
	int m_iSid;
} TGuiGetSearchedDigChnReq;

typedef struct	//��Ӧ�����m_iCnt��TGuiSearchDigChnMsg�ṹ
{
	int m_iCnt;	//�˴η��ص�ͨ��������������0��-1��ʽ��������
} TGuiGetSearchedDigChnRsp;

#define GUI_GET_DIG_CHN_PROTOCOL_CNT_REQ  744  //��ȡ����ͨ��Э������
#define GUI_GET_DIG_CHN_PROTOCOL_CNT_RSP  -744 //��ȡ����ͨ��Э��������Ӧ

typedef struct 								//��ȡ����ͨ��Э���б�����
{
	int m_iChn; //����ͨ����Ĭ��Ϊ0
} TGuiGetDigChnProtocolListReq;

typedef struct 								//��ȡ����ͨ��Э���б��Ӧ
{
	int m_iChn;                             //����ͨ����
	int m_iProtocolCnt;						//Э������
} TGuiGetDigChnProtocolListRsp;

typedef struct 								//Э���б���
{
	char m_strProtocolName[GUI_DIG_CHN_PTZ_NAME + 1]; //Э����
} TGuiDigChnProtocolListItem;

//����ͨ���༭����
#define GUI_SET_CHN_TYPE_PARAM  -1
typedef struct 
{
	int m_iChn;
	int m_iType;
	int m_iParam; //Ԥ�� Ĭ����Ϊ-1
}TGuiChnMagSetChnTypeReq; //����ͨ����������

typedef struct
{
	int m_iRetCode;
}TGuiChnMagSetChnTypeRsp; //����ͨ�����ͻ�Ӧ

typedef struct
{
	int m_iChn;
}TGuiChnGetChnEditAbleTypeReq; //��ȡ�ɱ༭ͨ����������

typedef struct
{
	int m_iChn;
	int m_iEditTypeFlg;
}TGuiChnGetChnEditAbleTypeRsp;  //��ȡ�ɱ༭ͨ�����ͻ�Ӧ

#define GUI_BATCH_ACTION_START    750       //����������ʼ
#define GUI_BATCH_ACTION_STOP     751		//������������

typedef enum
{

	GUI_CHN_ENABLE = 1,
	GUI_CHN_DISABLE,
	GUI_CHN_DEL,
}EGuiBatchEnum;

typedef struct
{
	int m_iBatchType;    //����
}TGuiSetBatchActionReq;

//---------------------����ǰ�˼��弴��-------------------------------
typedef enum                  
{
	GUI_MANUALADD = 0,						//�ֶ���Ӽ������ü��弴��
	GUI_AUTOADD,							//�Զ����
	GUI_PROMPTADD,							//��ʾ���
} EGuiChnAddType;                         //�������ͨ���ķ�ʽ

#define GUI_GET_DIG_CHN_ADD_TYPE_REQ   807  //��ȡ����ͨ����ӷ�ʽ����
#define GUI_GET_DIG_CHN_ADD_TYPE_RSP   -807 //��ȡ����ͨ����ӷ�ʽ��Ӧ

typedef struct
{
	int m_iAddType;	//����ͨ����ӷ�ʽ��0��ʾ�����ã�1��ʾ�Զ���ӣ�2��ʾ��ʾ���
}TGuiGetDigChnAddTypeRsp;				//��ȡ��ӷ�ʽ��Ӧ

#define GUI_SET_DIG_CHN_ADD_TYPE_REQ   808  //��������ͨ����ӷ�ʽ����
#define GUI_SET_DIG_CHN_ADD_TYPE_RSP   -808  //��������ͨ����ӷ�ʽ��Ӧ

#define GUI_SET_DIG_ADD_TYPE_OK   0       //���óɹ�
#define GUI_SET_DIG_ADD_TYPE_ERR  1       //����ʧ��

typedef struct
{
	int m_iAddType;	//����ͨ����ӷ�ʽ��1��ʾ�ֶ���ӣ�2��ʾ��ʾ��ӣ�3��ʾ�Զ����
}TGuiSetDigChnAddtypeReq;	//��������ͨ����ӷ�ʽ����

typedef struct
{
	int m_iRetCode;
}TGuiSetDigChnAddTypeRsp;	//��������ͨ����ӷ�ʽ��Ӧ

#define GUI_GET_DIG_CHN_UPNP_NEW_DEVICE_REQ  809     //���弴�û�ȡ���豸����
#define GUI_GET_DIG_CHN_UPNP_NEW_DEVICE_RSP  -809    //���弴�û�ȡ���豸��Ӧ
typedef struct
{
	int m_iCnt;   //Ĭ��Ϊ1
}TGuiGetDigChnUpnpReq;

typedef struct
{
	int m_iCnt;//���ط��ֵ��豸����
}TGuiGetDigChnUpnpDevCntRsp;

typedef struct
{
	int m_iConStat;		//0 - �豸��ʧ���ӣ�1-�������豸
	int m_iChn;				//������豸����ͨ����
	int m_iConId;        //������豸������ID
	char m_strMac[GUI_IP_STR_LEN + 1]; //������豸��mac��ַ
	char m_strIp[GUI_IP_STR_LEN + 1]; //������豸��IP��ַ
}TGuiGetDigChnUpnpDevMsgItem;

#define GUI_SET_ADD_DIG_CHN_UPNP_REQ          810    //�����������ͨ������
#define GUI_SET_ADD_DIG_CHN_UPNP_RSP          -810    //�����������ͨ����Ӧ

typedef struct		//�����������ͨ������
{
	int m_iConCmd;      // 1-���ӣ�0-������
	int m_iChn;		//������豸��ͨ��
	int m_iConId;        //������豸������ID
	char m_strMac[GUI_IP_STR_LEN + 1]; //������豸��mac��ַ
	char m_strIp[GUI_IP_STR_LEN + 1]; //������豸��IP��ַ
} TGuiSetAddDigChnUpnpReq;

typedef struct
{
	int m_iRetCode;
} TGuiSetAddDigChnUpnpRsp;

//------------------------------------------------------------------------------
// ������������ͨ��ʣ�����

#define GUI_GET_NET_SPARE_BANDWIDTH_REQ  811  //��ȡ��������ʣ���������
#define GUI_GET_NET_SPARE_BANDWIDTH_RSP  -811 //��ȡ��������ʣ������Ӧ

typedef struct
{
	char m_cBandWidth[GUI_PUBLIC_LEN_31 + 1]; //���ַ���
}TGuiGetNetSpareBandwidthRsp;

//�Ƿ��ǰ���Զ������ʣ��������
#define GUI_GET_BANDWIDTH_BALANCE_ENABEL_REQ	840		//��ȡ
#define GUI_GET_BANDWIDTH_BALANCE_ENABEL_RSP	-840
typedef struct
{
	int m_iBalanced;	//0��ʾ������
}TGuiGetBandWidthBalanceRsp;

#define GUI_SET_BANDWIDTH_BALANCE_ENABEL_REQ	841		//����
#define GUI_SET_BANDWIDTH_BALANCE_ENABEL_RSP	-841
typedef struct
{
	int m_iBalanced;	//0��ʾ������
}TGuiSetBandWidthBalanceReq;

typedef struct
{
	int m_iRetCode;  //0��ɹ� 1��ʾʧ��
}TGuiSetBandWidthBalanceRsp;

//POE���ͨ����ʽ
typedef enum
{
	ADD_BY_HUM = 1,  	 //�ֶ����
	ADD_BY_PLUG_AND_PLAY,  	//���弴��
}EAddType;

#define GUI_GET_POE_WORKMODE_REQ		820		//��ȡpoeͨ����ӷ�ʽ����
#define GUI_GET_POE_WORKMODE_RSP		-820
typedef struct
{
	int m_iChn;
}TGuiGetIpcPluginWorkModeReq;

typedef struct
{
	int m_iChn;
	int m_iWorkMode;    // 1 �ֶ� 2���弴��
}TGuiGetIpcPluginWorkModeRsp;

//���õ�
#define GUI_SET_POE_WORKMODE_REQ		821
#define GUI_SET_POE_WORKMODE_RSP		-821

typedef struct
{
	int m_iChn;
	int m_iWorkMode;	//��EAddType
}TGuiSetIpcPluginWorkModeReq;

typedef struct
{
	int m_iRetCode;		//0�ɹ� ����ʧ��
}TGuiSetIpcPluginWorkModeRsp;



//==============IPC���й���=====================
typedef struct
{
	int m_iChn;
	char m_strIpcVersion[GUI_PUBLIC_LEN_31 + 1];  	//�汾��
}TGuiIPCMsg;

//��ȡIPCͨ�����豸�ż��汾��
#define GUI_GET_IPC_VERSION_REQ	812   
#define GUI_GET_IPC_VERSION_RSP	-812
typedef struct
{
	int m_iChn;
}TGuiGetIpcVerReq;

typedef struct
{
	TGuiIPCMsg m_tIpcMsg;
} TGuiGetIpcVerRsp;

//�޸�IP
#define GUI_IPC_CHANGE_IP_CMD_REQ	813  //�޸�ǰ��IPC��IP����
#define GUI_IPC_CHANGE_IP_CMD_RSP	-813  //��Ӧ

typedef struct
{
	int m_iChn;
	char m_strMac[GUI_IP_STR_LEN + 1];			//mac��ַ
	char m_strIp[GUI_IP_STR_LEN + 1];			//IP��ַ
	char m_strSubMsk[GUI_IP_STR_LEN + 1];		//��������
	char m_strGateWay[GUI_IP_STR_LEN + 1];		//����
	char m_strDNS[GUI_IP_STR_LEN + 1];			//��������
}TGuiChangeIpcIpReq;

typedef struct
{
	int m_iRetCode;
} TGuiChangeIpcIpRsp;

//ǰ��IPC����
#define GUI_IPC_REBOOT_CMD_REQ		814  //IPC����
#define GUI_IPC_REBOOT_CMD_RSP		-814 //��Ӧ
typedef struct
{
	int m_iChn;
}TGuiIpcRebootReq;           //��������

typedef struct
{
	int m_iRetCode;
} TGuiIpcRebootRsp;

#define GUI_IPC_CNF_EXPORT_REQ		815  //IPC���õ�������
#define GUI_IPC_CNF_EXPORT_RSP		-815  //IPC���õ�����Ӧ
typedef struct
{
	int m_iChn;
 	char m_iDstDevName[GUI_CNF_NAME_LEN + 1];	//���������ļ���������
	char m_strFileName[GUI_CNF_NAME_LEN + 1];  //���������ļ���
}TGuiIpcExportReq;

typedef struct
{
	int m_iRetCode;
}TGuiIpcExportRsp;

#define GUI_IPC_CNF_IMPORT_REQ		816  //IPC��������
#define GUI_IPC_CNF_IMPORT_RSP		-816
//������ǰ�ĵ����߼���ֻ���ڷ���ʱ������ͨ����
typedef struct
{
	int m_iChn;
char m_strFileName[GUI_CNF_NAME_LEN + 1]; //���������ļ���
}TGuiIpcImportReq;

typedef struct
{
	int m_iRetCode;
}TGuiIpcImportRsp;

//IPC����
#define GUI_IPC_UPDATE_CMD_REQ		817   //IPC����
#define GUI_IPC_UPDATE_CMD_RSP		-817

typedef struct
{
	int m_iChn;
	char m_strFileName[GUI_SYS_UPDATE_FTP_LEN + 1];  //�����ļ���
}TGuiIpcUpdateReq;

typedef struct
{
	int m_iRetCode;
}TGuiIpcUpdateRsp;

#define GUI_IPC_UPDATE_STA_REQ		818
#define GUI_IPC_UPDATE_STA_RSP		-818
//ʹ�þɵĽṹ��TGuiSysUpdateStaReq��TGuiSysUpdateStaRsp

#define GUI_IPC_FILE_UPDATE_NUM_REQ		819	//��ȡIPC�����ļ���������
#define GUI_IPC_FILE_UPDATE_NUM_RSP		-819  //��Ӧ
//ʹ�þɵĽṹ��TGuiGetSysUpdateFileListRsp��TGuiSysUpdateFileRsp

typedef enum
{
	DEFAULT_ISP = 1,     //IPC�������
}EDefaultEnum;

#define GUI_SET_MODULE_DEFAULT_REQ	  830   //�ָ�Ĭ������(������ģ�黮��)
#define GUI_SET_MODULE_DEFAULT_RSP	 -830   //�ָ�Ĭ�ϻ�Ӧ(������ģ�黮��)
typedef struct
{
	int m_iChn;   //ͨ���Ŵ�1��ʼ
	int m_iType;    //��ö��EDefaultEnum
}TGuiSetModuleDefaultReq;

typedef struct
{
	int m_iRetCode;   //0��ɹ�,�����ʧ��
}TGuiSetModuleDefaultRsp; 

//------------------------------------------------------------------------------
// ��Ƶ���ܽ���
#define GUI_VIDEO_PWD_LEN  31    //���볤��

#define GUI_VDECODE_PWD_OK 		0   //��֤�ɹ�
#define GUI_VDECODE_PWD_ERR 	1  //��֤ʧ��
#define GUI_VDECODE_PWD_ERR1 	2 //��¼�����м���ʧ��


typedef struct	//������Ƶ������������
{
	int m_iPlayId;
	char m_strPwd[GUI_VIDEO_PWD_LEN + 1];
}TGuiVdecodePwdSetReq;

typedef struct
{
	int m_iRetCode;
}TGuiVdecodePwdSetRsp;

typedef struct	//������Ƶ���������������
{
	int m_iChn;	//ͨ���ţ�Ԥ����Ĭ��Ϊ0
	char m_strPwd[GUI_VIDEO_PWD_LEN + 1]; //����
} TGuiVEncodePwdSetReq;

typedef struct
{
	int m_iRetCode;	// 0�ɹ���1ʧ��
} TGuiVEncodePwdSetRsp;

typedef struct	//��ȡ��Ƶ��������
{
	int m_iChn;	//ͨ���ţ�Ԥ����Ĭ��0
} TGuiVencodePwdGetReq;

typedef struct
{
	int m_iChn;	//ͨ���ţ���req�е�ͨ������ȣ�-1��ʽʧ��
	char m_strPwd[GUI_VIDEO_PWD_LEN + 1]; //����
} TGuiVencodePwdGetRsp;

enum
{
	GUI_AI_DEV_CHN_ALL_ID = 0,   //�����豸ͨ���ţ�0��ʾȫ��ͨ��
	GUI_AO_DEV_ID = 1001,
};

enum
{
	GUI_VOLUMECTRL_REVERSE = 0,
	GUI_VOLUMECTRL_IN,
	GUI_VOLUMECTRL_OUT,
	GUI_VOLUMECTRL_LINEIN,
	GUI_VOLUMECTRL_MICIN,
};

typedef struct		//������������
{
	int m_iDevId;	//����������ͨ����(�����֣�Ĭ��Ϊ0��ȫ��ͨ��), GUI_AO_MIC_DEV_ID��ao���
	int m_iVolume;	//������С 0-255(0:����,255:�������, -1��ʽ��ѯ��ǰ����)
} TGuiVolumeCtrReq;

typedef struct
{
	int m_iDevId;        //��չ��16λΪ��Ƶ�������ͣ�0������1���룬2�����3-LInein,4-macIn
	//��16λ��ʾͨ���ţ�0��ȫ��
	int m_iVolume;	//��ǰ������ֵ
} TGuiVolumeCtrRsp;

// ��������
typedef struct		//��Ƶ��������
{
	int m_iPid;	//�����ʶ
	int m_iChn;	//ͨ���š� 4��n��5��n-1��ʵʱͼƬ��ͨ������ͨ�ն˷���ר�ã����豸��ͨ������n����ʾ��
} TGuiStreamConnectReq;

typedef struct		//��Ƶ�����Ӧ
{
	int m_iKey;	//�����ڴ�keyֵ(��ֵ��ʽʧ��)
	int m_iSize;	//�����ڴ��С
} TGuiStreamConnectRsp;

typedef struct		//��Ƶ�Ͽ�����
{
	int m_iPid;	//�����ʶ
	int m_iChn;	//ͨ���š�4��n��5��n-1��ʵʱͼƬ��ͨ������ͨ�ն˷���ר�ã����豸��ͨ������n����ʾ��
} TGuiStreamDisConnectReq;

typedef struct		//��Ƶ�Ͽ���Ӧ
{
	int m_iRetCode;	//�����룬0��ʽ�ɹ�
} TGuiStreamDisConnectRsp;

typedef struct		//��������ͨ��
{
	int m_iBase;
	int m_iTop;
	int m_iSize;
	char m_cBuf[0];
} TGuiStreamChannel;

typedef struct						//����������Ϣ
{
	unsigned char m_ucFrameType;	//֡��������, 0x00:I֡,0x01:P֡,0xFF:�������(ֱ�Ӷ���)
	unsigned char m_ucFrameRate;		//֡��
	unsigned char m_ucR1;			//������
	unsigned char m_ucR2;			//������
	unsigned int m_iFrameLenght;		//֡����
	unsigned char m_ucStream[0];		//֡����
} TGuiStreamFrame;


typedef struct		//ǿ��I֡����
{
	int m_iChn;		//ͨ����,0��ʾȫ��
} TGuiForceIframeReq;

typedef struct
{
	int m_iRetCode;
} TGuiForceIframeRsp;


//=================== �������� ====================
//�����������Ƶ�����ں�
#define GUI_PUSH_STREAM_CONNECT_REQ  2004  //�豸�����ⲿpush������������
#define GUI_PUSH_STREAM_CONNECT_RSP  -2004 //�豸�����ⲿpush�������ӻ�Ӧ
typedef struct
{
	int m_iPid; 	//�����ʶ
	int m_iChn;  //����ͨ���ţ��豸���Ǹ�ͨ��Ԥ��PUSH��������
}TGuiPushStreamConnectReq;

typedef struct
{
	int m_iKey;	//�����ڴ�keyֵ(��ֵ��ʽʧ��)
	int m_iSize;	//�����ڴ��С
}TGuiPushStreamConnectRsp;

#define GUI_PUSH_STREAM_DISCONNECT_REQ  2005  //�豸�Ͽ�����push��������
#define GUI_PUSH_STREAM_DISCONNECT_RSP  -2005 //�豸�Ͽ�����push������Ӧ

typedef struct		//��Ƶ�Ͽ�����
{
	int m_iPid;	//�����ʶ
	int m_iChn;	//����ͨ���ţ��豸���Ǹ�ͨ��Ԥ��PUSH��������
} TGuiPushStreamDisConnectReq;

typedef struct		//��Ƶ�Ͽ���Ӧ
{
	int m_iRetCode;	//�����룬0��ʽ�ɹ�
} TGuiPushStreamDisConnectRsp;
#if 0
//����ԭ�����еĽṹ��
typedef struct		//��������ͨ��
{
	int m_iBase;
	int m_iTop;
	int m_iSize;
	char m_cBuf[0];
} TGuiStreamChannel;

typedef struct						//����������Ϣ
{
	unsigned char m_ucFrameType;	//֡��������, 0x00:I֡,0x01:P֡,0xFF:�������(ֱ�Ӷ���)
	unsigned char m_ucFrameRate;		//֡��
	unsigned char m_ucR1;			//������
	unsigned char m_ucR2;			//������
	unsigned int m_iFrameLenght;		//֡����
	unsigned char m_ucStream[0];		//֡����
} TGuiStreamFrame;
#endif

//==============���ܷ���=================================
//¼����

#define MAX_GUI_RULE_NAME_LEN		16
#define MAX_GUI_POLYGON_POINT_NUM	8
#define MAX_GUI_FDEPTH_LINE_NUM 	3

//���ܷ���ͨ������
typedef struct
{
	int m_iX;
	int	m_iY;
} TGuiVcaPoint;

typedef struct
{
	TGuiVcaPoint 	m_stStart;	
	TGuiVcaPoint 	m_stEnd;	
} TGuiVcaLine;

typedef struct
{
	int 			m_iPointNum;
	TGuiVcaPoint 	m_stPoint[MAX_GUI_POLYGON_POINT_NUM];   	
} TGuiVcaPolygon;


//���ܷ���ͨ��ʹ������/��ȡ
#define GUI_GET_VCACHN_CNF_REQ				 900		//��ȡ���ܷ���ͨ��ʹ������
#define GUI_GET_VCACHN_CNF_RSP				-900		//��ȡ���ܷ���ͨ��ʹ�ܻ�Ӧ

typedef struct
{
	int m_iChannelNo;
} TGuiGetVcaChnEnableReq;  //��ȡ���ܷ���ͨ��ʹ������

enum
{
	GUI_VCA_DISABLE = 0,    //��ʹ�����ܷ���
	GUI_VCA_USE_LOCAL,      //ʹ�ܱ���ͨ�����ܷ���
	GUI_VCA_USE_REMOTE,		//ʹ��ǰ��ͨ�����ܷ���
}; //���ܷ���ʹ�ܱ�ʶ

typedef struct
{
	int m_iChannelNo;
	int m_iVcaEnable;		//���ܷ���ʹ�ܱ�ʶ
} TGuiGetVcaChnEnableRsp;

#define GUI_SET_VCACHN_CNF_REQ				 901		//�������ܷ���ͨ��ʹ������
#define GUI_SET_VCACHN_CNF_RSP				-901		//�������ܷ���ͨ��ʹ�ܻ�Ӧ

typedef struct
{
	int m_iChannelNo;
	int m_iVcaEnable;		//���ܷ���ʹ��λ		0��ʹ�ܣ�1ʹ�ܱ��أ�2ʹ��ǰ��
} TGuiSetVcaChnEnableReq;

#define GUI_SET_VCACHN_OK		0
#define GUI_SET_VCACHN_ERR		1
typedef struct
{
	int m_iRetCode;			//����ֵ,0��ʾ�ɹ�������ֵ��ʧ��
} TGuiSetVcaChnEnableRsp;

#define GUI_SET_VCA_ACTION_REQ	913		//��ͣ���߻ָ�VCA����
#define GUI_SET_VCA_ACTION_RSP	-913	//��Ӧ

typedef enum
{
	GUI_VCA_PAUSE = 1,
	GUI_VCA_RESUME,
}TGuiVcaActEnum;

typedef struct
{
	int m_iChn;
	int m_iAct;			//��ö��TGuiVcaActEnum
}TGuiSetVcaChnActReq;

typedef struct
{
	int m_iRetCode;
}TGuiSetVcaChnActRsp;


//���ܷ�����������/��ȡ
#define GUI_GET_VCAPARA_CNF_REQ		 		 902		//��ȡ���ܷ���������������
#define GUI_GET_VCAPARA_CNF_RSP				-902		//��ȡ���ܷ�������������Ӧ

typedef struct
{
	//int m_iVcaEnable;				//���ܷ���ʹ��λ		0-��ʹ�ܴ�ͨ�����ܷ���	1-ʹ�ܴ�ͨ�����ܷ���
	int m_iVcaVideoSize;			//���ܷ�������Ƶ��С	0-QCIF 1-HCIF 2-FCIF 3-HD1 4-FD1 Ŀǰֻ֧��QCIF/FCIF
	int m_iDisplayTarget;			//��Ƶ����Ŀ��			0-������	  1-����		
	int m_iDisplayTrace;			//��Ƶ���ӹ켣			0-������	  1-����
	int m_iDisplayAllTargetTrace;	//�Ƿ��������Ŀ��͹켣0-ֻ���Ӵ��������Ŀ�ꡢ�켣	1-��������Ŀ�ꡢ�켣
	int m_iTargetColor;				//Ŀ��켣��ɫ			0:Ĭ�� 1:��ɫ 2:��ɫ 3:��ɫ 4:��ɫ 5:��ɫ 6:��ɫ 7:��ɫ 8:��ɫ
	int m_iTargetAlarmColor;		//Ŀ��켣������ɫ		0:Ĭ�� 1:��ɫ 2:��ɫ 3:��ɫ 4:��ɫ 5:��ɫ 6:��ɫ 7:��ɫ 8:��ɫ
	int m_iTraceLength;				//�켣����				0~40
} TGuiVcaParaCnf;

typedef struct
{
	int m_iEnableAdvanced;	//���ܷ����߼�����ʹ��	0-��ʹ��	1-ʹ��					
	int m_iTargetMinSize;	//Ŀ����С������
	int m_iTargetMaxSize;	//Ŀ�����������
	int m_iTargetMinWidth;	//��С���
	int m_iTargetMaxWidth;	//�����
	int m_iTargetMinHeight;	//��С�߶�
	int m_iTargetMaxHeight;	//���߶�
	int m_iTargetMinWHRatio;//Ŀ�����С�����*100
	int m_iTargetMaxWHRatio;//Ŀ�����󳤿��*100
	int m_iTargetMinSpeed;	//Ŀ����С�����ٶ�
	int m_iTargetMaxSpeed;	//Ŀ����������ٶ�
	int m_iSensitivity;		//Ŀ����������ȼ���	0:�������� 1:�������� 2:��������
} TGuiVcaAdvParaCnf;

typedef struct 
{
	TGuiVcaLine m_stRefLine;		// ��ֱ�߶�����(unit: pixel)
	int 		m_s32RefLen;		// �߶γ���(unit: cm)
} TGuiVcaFdeLine;	// �����߽ṹ

typedef struct
{
	unsigned int	m_i32NumUsed; 							// ������Ŀ ���ڵ���2
	TGuiVcaFdeLine 	m_stLines[MAX_GUI_FDEPTH_LINE_NUM];   	// ������Ŀ
} TGuiVcaFdepthMeasure;  

typedef struct
{
	unsigned int 			m_iEnableFdepth;	//���ñ�ʶ
	TGuiVcaFdepthMeasure 	m_stMeasure;		//�궨����
} TGuiVcaFdeParaCnf;

typedef struct	//��ȡ���ܷ�����������(ͨ��/�߼�)����
{
	int m_iChannelNo;						//���ܷ���ͨ����
} TGuiGetVcaParaReq;

typedef struct	//��ȡ���ܷ�����������(ͨ��/�߼�)��Ӧ	
{
	int m_iChannelNo;		
	TGuiVcaParaCnf		m_tVcaParaCnf;		//���ܷ���ͨ�����ò���
	TGuiVcaAdvParaCnf	m_tVcaAdvParaCnf;	//���ܷ����߼����ò���
	TGuiVcaFdeParaCnf	m_tVcaFdeParaCnf;	//���ܷ����궨���ò���
} TGuiGetVcaParaRsp;

#define GUI_SET_VCAPARA_CNF_REQ		 		 903		//�������ܷ���������������	
#define GUI_SET_VCAPARA_CNF_RSP				-903		//�������ܷ�������������Ӧ

typedef struct	//�������ܷ��������(ͨ��/�߼�)����
{
	int m_iChannelNo;		
	TGuiVcaParaCnf		m_tVcaParaCnf;
	TGuiVcaAdvParaCnf	m_tVcaAdvParaCnf;
	TGuiVcaFdeParaCnf	m_tVcaFdeParaCnf;
} TGuiSetVcaParaReq; 

#define GUI_SET_VCAPARA_OK		0
#define GUI_SET_VCAPARA_ERR		1
typedef struct	//�������ܷ��������(ͨ��/�߼�)��Ӧ
{
	int m_iRetCode;							//����ֵ,0��ʾ�ɹ�������ֵ��ʧ��
} TGuiSetVcaParaRsp;

//���ܷ��������¼���������/��ȡ
#define GUI_GET_VCAEVENT_CNF_REQ			 904		//��ȡ���ܷ����¼���������
#define GUI_GET_VCAEVENT_CNF_RSP			-904		//��ȡ���ܷ����¼�������Ӧ

typedef enum  //���ܻط��еĻط�����Ҳժȡ�˴�ö�٣���dvr.h Line313
{
	GUI_TRIPWIRE = 0,						//�����¼�
	GUI_DBTRIPWIRE,							//˫�����¼�
	GUI_PERIMETER,							//�ܽ��¼�
	GUI_LOITER,								//�ǻ��¼�
	GUI_PARKING,							//ͣ���¼�
	GUI_RUN,								//�����¼�
	GUI_HIGH_DENSITY,						//��Ա�ܶ��¼�
	GUI_ABANDUM,							//�������¼�
	GUI_OBJSTOLEN,							//�������¼�
	GUI_FACESPOT,           				// ����ʶ��
	GUI_AVD = 10,							//��Ƶ���
	GUI_CAP = 11,							//Ŀ�����
	GUI_CAP_td = 12,			/*tdĿ�����*/
	GUI_CPC = 13,				/*����ͳ��*/
	GUI_CDD = 14,				/*��Ա�ۼ�*/
	GUI_SVD = 15,				/*��ڼ��*/
	GUI_AAD = 16,				/*��Ƶ���*/	
	GUI_VFD = 17,				/*�������*/
	GUI_LPR = 18,				/*���Ƽ��*/
	GUI_MAX
} EGuiVcaEventType;

typedef struct
{
	int				m_iEventValid;		//�Ƿ�ʹ�ܵ������¼�
	int				m_iTargetTypeCheck;	//Ŀ��������
	int				m_iMinDistance;		//��С����
	int				m_iMinTime;			//���ʱ��
	int				m_iDisplayRule;		//�Ƿ���ʾ����
	int				m_iDisplayStat;		//�Ƿ���ʾ��������ͳ��
	int				m_iColor;			//��������ɫ	0:Ĭ�� 1:��ɫ 2:��ɫ 3:��ɫ 4:��ɫ 5:��ɫ 6:��ɫ 7:��ɫ 8:��ɫ
	int				m_iAlarmColor;		//����������ɫ	0:Ĭ�� 1:��ɫ 2:��ɫ 3:��ɫ 4:��ɫ 5:��ɫ 6:��ɫ 7:��ɫ 8:��ɫ
	int				m_iType;			//��Խ����		0:���� 1:˫��
	int				m_iTDirection;		//��ֹ��Խ����	0~359��
	TGuiVcaLine		m_stLine;			//����������
} TGuiVcaTripwire;

typedef struct
{
	int				m_iEventValid;		//�Ƿ�ʹ���ܽ��¼�
	int				m_iDisplayRule;		//�Ƿ���ʾ����
	int				m_iDisplayStat;		//�Ƿ���ʾ��������ͳ��
	int				m_iColor;			//�ܽ���ɫ		0:Ĭ�� 1:��ɫ 2:��ɫ 3:��ɫ 4:��ɫ 5:��ɫ 6:��ɫ 7:��ɫ 8:��ɫ
	int				m_iAlarmColor;		//�����ܽ���ɫ	0:Ĭ�� 1:��ɫ 2:��ɫ 3:��ɫ 4:��ɫ 5:��ɫ 6:��ɫ 7:��ɫ 8:��ɫ
	int				m_iTargetTypeCheck;	//Ŀ��������
	int				m_iMode;			//�ܽ���ģʽ	0:���� 1:���� 2:�뿪
	int 			m_iMinDistance;		//��С����					
	int 			m_iMinTime;			//���ʱ��				
	int				m_iType;			//�Ƿ�����������
	int 			m_iDirection;		//��ֹ����Ƕ�	0~359��
	TGuiVcaPolygon	m_stRegion;			//�ܽ�����
} TGuiVcaPermeter;


typedef struct
{	
	int 			m_iEventValid;		//�Ƿ�ʹ����������¼�
	int 			m_iDisplayRule;		//�Ƿ���ʾ����
	int 			m_iDisplayStat;		//�Ƿ���ʾ��������ͳ��
	int				m_iColor;			//���������ɫ		0:Ĭ�� 1:��ɫ 2:��ɫ 3:��ɫ 4:��ɫ 5:��ɫ 6:��ɫ 7:��ɫ 8:��ɫ
	int 			m_iAlarmColor;		//�������������ɫ	0:Ĭ�� 1:��ɫ 2:��ɫ 3:��ɫ 4:��ɫ 5:��ɫ 6:��ɫ 7:��ɫ 8:��ɫ
	TGuiVcaPolygon	m_stRegion;			//���������������
} TGuiVcaFace;

typedef struct
{
	int				m_iEventValid;		//�Ƿ�ʹ����Ƶ����¼�
	int				m_iDisplayStat;		//�Ƿ���ʾ��������ͳ��
	int				m_iCheckTime;		//�¼���Ч�¼���ֵ�����¼����������˷�ֵʱ����Ϊ���鷢��
} TGuiVcaDiagnose;


typedef struct
{
    int				m_iEventValid;
	int				m_iDisplayRule;
	int				m_iDisplayStat;
	int				m_iColor;
	int				m_iAlarmColor;	
	int				m_iMinTime;
	int				m_iMinSize;
	int 			m_iMaxSize;	
	int				m_iChildAreaNum;    //��Ч���������
	TGuiVcaPolygon	m_stMainRegion;	    //����Ķ��������	
    TGuiVcaPolygon	m_stRegionA;	    //������A
	TGuiVcaPolygon	m_stRegionB;        //������B
	TGuiVcaPolygon	m_stRegionC;        //������C
}TGuiVcaLeave;
#define TGuiVcaLost TGuiVcaLeave


typedef struct
{
	TGuiVcaTripwire	m_tVcaTripwireCnf;		//�������¼��������ò���
	TGuiVcaPermeter m_tVcaPermeterCnf;		//�ܽ��¼��������ò���
	TGuiVcaFace		m_tVcaFaceCnf;			//��������¼��������ò���
	TGuiVcaDiagnose m_tVcaDiagnoseCnf;		//��Ƶ����¼��������ò���
	TGuiVcaLeave    m_tVcaLeaveCnf;         //��Ʒ�����¼��������ò���
	TGuiVcaLost     m_tVcaLostCnf;          //��Ʒ��ʧ�¼��������ò���
} TGuiVcaEventCnf;


typedef struct	//��ȡ���ܷ�����������¼���������
{
	int 				m_iChannelNo;		//ͨ����		
	int 				m_iRulesNo;			//�¼���
	EGuiVcaEventType 	m_eEventType;		//�¼�����			
} TGuiGetVcaEventReq;

typedef struct	//��ȡ���ܷ�����������¼�������Ӧ
{
	int 				m_iChannelNo;		//ͨ����
	int 				m_iRulesNo;			//�¼���
	unsigned char		m_cRuleName[MAX_GUI_RULE_NAME_LEN + 1];	//�¼�����
	int 				m_iRuleEnable;		//�����Ƿ�ʹ��
	EGuiVcaEventType 	m_eEventType;		//�¼�����			
	TGuiVcaEventCnf 	m_tVcaEventCnf;		//�¼��������ò���
} TGuiGetVcaEventRsp;

#define	GUI_SET_VCAEVENT_CNF_REQ	 		 905		//�������ܷ����¼���������
#define GUI_SET_VCAEVENT_CNF_RSP			-905		//�������ܷ����¼�������Ӧ

typedef struct	//�������ܷ�����������¼���������
{
	int 				m_iChannelNo;
	int 				m_iRulesNo;
	unsigned char		m_cRuleName[MAX_GUI_RULE_NAME_LEN + 1];
	int 				m_iRuleEnable;
	EGuiVcaEventType 	m_eEventType;					
	TGuiVcaEventCnf 	m_tVcaEventCnf;
} TGuiSetVcaEventReq;

#define GUI_SET_VCAEVENT_OK		0
#define GUI_SET_VCAEVENT_ERR	1
typedef struct	//�������ܷ�����������¼�������Ӧ
{
	int m_iRetCode;			//����ֵ,0��ʾ�ɹ�������ֵ��ʧ��
} TGuiSetVcaEventRsp;

//���ܷ�����������ͳ�ƻ�ȡ
#define GUI_GET_VCA_ALARM_COUNT_TOTAL_REQ	 	906		//��ȡ���ܷ���������������
#define GUI_GET_VCA_ALARM_COUNT_TOTAL_RSP		-906		//��ȡ���ܷ�������������Ӧ

typedef struct
{
	int 				m_iChannelNo;
	int 				m_iRulesNo;
	EGuiVcaEventType 	m_eEventType;
} TGuiVcaAlarmCountCnf;

typedef struct	
{
	TGuiVcaAlarmCountCnf m_VcaAlarmCountCnf;
} TGuiGetVcaAlarmCountTotalReq;

#define GUI_GET_ALARM_COUNT_TOTAL_OK	0
#define GUI_GET_ALARM_COUNT_TOTAL_ERR	1
typedef struct
{
	TGuiVcaAlarmCountCnf 	m_VcaAlarmCountCnf;
	int 					m_iVcaAlarmCount;
} TGuiGetVcaAlarmCountTotalRsp;

//���ܷ�������������������
#define GUI_SET_VCA_ALARM_COUNT_CLEAN_REQ		 907		//�������ܷ���������������
#define GUI_SET_VCA_ALARM_COUNT_CLEAN_RSP		-907		//�������ܷ������������Ӧ

typedef struct
{
	TGuiVcaAlarmCountCnf m_VcaAlarmCountCnf;
} TGuiSetVcaCleanAlarmCountReq;

#define GUI_SET_ALARM_COUNT_CLEAN_OK	0
#define GUI_SET_ALARM_COUNT_CLEAN_ERR	1
typedef struct
{
	int m_iRetCode;			//����ֵ,0��ʾ�ɹ�������ֵ��ʧ��
} TGuiSetVcaCleanAlarmCountRsp;

//���ܷ�������״̬��ȡ
#define GUI_GET_VCA_ALARM_STATE_MSG_REQ		 	908		//��ȡ���ܷ���������Ϣ����
#define GUI_GET_VCA_ALARM_STATE_MSG_RSP			-908		//��ȡ���ܷ���������Ϣ��Ӧ

typedef	struct	
{
	TGuiVcaPoint 		m_stLeftTopPoint;	
	TGuiVcaPoint 		m_stRightBottomPoint;
} TGuiVcaTargetCoordinate;

typedef struct
{
	int 					m_tTime;			//���鷢��ʱ��
	int 					m_iState;			//����״̬
	unsigned int 			m_uiTargetId;		//Ŀ��ID
	int						m_iTargetType;		//Ŀ������
	TGuiVcaTargetCoordinate	m_stTargetRegion;	//Ŀ����������
	int						m_iTargetSpeed;		//Ŀ���ٶ�
	int						m_iTargetDirection;	//Ŀ���˶�����	0~359
} TGuiVcaAlarmStateMsg;

typedef struct	//��ȡ���ܷ���ʱʱ����������Ӧ
{
	int 	m_iTol;
} TGuiGetVcaAlarmStateMsgRsp;

typedef struct	
{		
	int 					m_iChannelNo;		//ͨ����
	int 					m_iRulesNo;			//�����
	EGuiVcaEventType		m_eEventType;		//�¼�����
	TGuiVcaAlarmStateMsg	m_VcaAlarmStateMsg;	//����״̬��Ϣ
} TGuiGetVcaAlarmStateMsg;


#define GUI_GET_VCAALM_STATE_MSG_REQ_EX		 	4908		//��ȡ���ܷ���������Ϣ����(�¼�)
#define GUI_GET_VCAALM_STATE_MSG_RSP_EX			-4908		//��ȡ���ܷ���������Ϣ��Ӧ(�¼�)

typedef struct	//��ȡ���ܷ���ʱʱ����������Ӧ
{
	int 	m_iTotal;
} TGuiGetVcaAlarmStateMsgRspEx;

typedef struct	
{		
	int 			m_iChannelNo;		//ͨ����
	int 			m_iRulesNo;			//�����
	unsigned char		m_cRuleName[MAX_GUI_RULE_NAME_LEN + 1]; //������
	EGuiVcaEventType	m_eEventType;		//�¼�����
	TGuiVcaAlarmStateMsg	m_VcaAlarmStateMsg;	//����״̬��Ϣ
} TGuiGetVcaAlarmStateMsgEx;

#define	GUI_GET_VCA_ALARM_REQ				 909		//��ȡ���ܷ�������������Ϣ����
#define GUI_GET_VCA_ALARM_RSP				-909		//��ȡ���ܷ�������������Ϣ��Ӧ
typedef	struct											//��������
{
	int m_iEnable;										//����ʹ�� 				0/1
	int m_iSoundEnable;									//����ʹ�� 				0/1,�ε�8λ(8~15)����ʾ�������ʼ�
	int m_iDisplayEnable;								//��Ļ��ʾʹ�� 			0/1
	int m_iToServerEnalbe;								
	int m_iVideoEnable[GUI_DVR_CHN_CNT];				//������ͨ��¼��ʹ�� 	0/1, (0/1 ��λ˳�����������Ԫ�ص�1λ�ֱ��Ӧ1,2,3,4,5��.ͨ��������ѭ��������Ҳ���մ˴���)
	int m_iPicEnable[GUI_DVR_CHN_CNT];					//������ͨ��ͼƬץ��ʹ��
	int m_iAlarmOutEnable[GUI_DVR_ALARM_OUT_CNT];		//�����������ʹ�� 		0/1
	TGuiTimePair m_tTimes[7][GUI_ALARM_TIME_PER_DAY];	//ÿ���ĸ�ʱ�Σ�һ��7��
	TGuiPtzLinkage m_tPtzLinkage[GUI_DVR_CHN_CNT];		//ptz����
} TGuiVcaAlarmCnf;

typedef struct	//��ȡ���ܷ���������Ϣ��������
{
	int 						m_iChannelNo;			//ͨ����
	int 						m_iRulesNo;				//�����
	EGuiVcaEventType			m_eEventType;			//�¼�����
} TGuiGetVcaAlarmReq;

typedef struct	//��ȡ���ܷ���������Ϣ������Ӧ
{
	int 						m_iChannelNo;			//ͨ����
	int 						m_iRulesNo;				//�����
	EGuiVcaEventType			m_eEventType;			//�¼�����
	TGuiVcaAlarmCnf 			m_tAlarmCnf;			//���ܷ�����������	
} TGuiGetVcaAlarmRsp;

#define GUI_SET_VCA_ALARM_REQ				 910		//�������ܷ�������������Ϣ����
#define GUI_SET_VCA_ALARM_RSP				-910		//�������ܷ�������������Ϣ��Ӧ

typedef struct	//�������ܷ���������Ϣ��������
{
	int 						m_iChannelNo;			//ͨ����
	int 						m_iRulesNo;				//�����
	EGuiVcaEventType			m_eEventType;			//�¼�����
	TGuiVcaAlarmCnf 			m_tAlarmCnf;			//���ܷ�����������
} TGuiSetVcaAlarmReq;

#define GUI_SET_VCA_ALARM_OK		0
#define GUI_SET_VCA_ALARM_ERR		1
typedef struct	//�������ܷ���������Ϣ������Ӧ
{
	int m_iRetCode;
} TGuiSetVcaAlarmRsp;


#define GUI_SET_VCA_REBOOT_REQ				 911		//�������ܿ�����
#define GUI_SET_VCA_REBOOT_RSP				-911		//�������ܿ��Ӧ

typedef struct
{
	int	m_iChannel;			//��Ϊ�ı���ĳ��ͨ��������������ͨ����
} TGuiSetVcaRebootReq;

#define GUI_SET_VCA_REBOOT_OK	0
#define GUI_SET_VCA_REBOOT_ERR	1

typedef struct
{
	int m_iRetCode;			//����ֵ,0��ʾ�ɹ�������ֵ��ʧ��
} TGuiSetVcaRebootRsp;

//��ȡ���ܷ��������¼�ʹ��״̬
#define GUI_GET_VCA_RULE_EVENT_ENABLE_REQ	 	912		//��ȡ���ܷ��������¼�ʹ��״̬����
#define GUI_GET_VCA_RULE_EVENT_ENABLE_RSP		-912		//��ȡ���ܷ��������¼�ʹ��״̬��Ӧ
typedef struct
{
	int m_iChannel;
	int m_iRulesNo;
} TGuiGetVcaRuleEventEnableReq;

typedef struct
{
	int m_iRuleEnable;			//�����Ƿ�ʹ��
	int m_iTripwireEnable;		//�������¼��Ƿ�ʹ��
	int m_iPerimeterEnable;		//�ܽ��¼��Ƿ�ʹ��
	int m_iFaceEnable;			//��������¼��Ƿ�ʹ��
	int m_iDiagnoseEnable;		//��Ƶ����¼��Ƿ�ʹ��
	int m_iLeaveEnable;         //��Ʒ�����¼��Ƿ�ʹ��
	int m_iLostEnabe;           //��Ʒ��ʧ�¼��Ƿ�ʹ��
} TGuiVcaRuleEnableMsg;

typedef struct
{
	int 					m_iChannel;
	int 					m_iRulesNo;
	TGuiVcaRuleEnableMsg	m_iEnableMsg;
} TGuiGetVcaRuleEventEnableRsp;

/************�µ����ܷ����㷨***************************/

//�����ĸ����ܷ����㷨
typedef enum     //VCA�㷨����
{
	GUI_AL_BEHAVIOUR = 0,		// 0 ��Ϊ����
	GUI_AL_FOLLOW,				// 1 ����
	GUI_AL_FACE,				// 2 �������
	GUI_AL_COUNT,				// 3 ����ͳ��
	GUI_AL_CAP,					// 4 ��Ƶ���
	GUI_AL_CARNO,				// 5 ����ʶ��
	GUI_AL_AUDIOEXP,			// 6 ��Ƶ�쳣���
	GUI_AL_LEAVE,				// 7 ��ڼ��
	GUI_AL_GATHER,				// 8  ��Ⱥ�ۼ�
}EVCATYPE;

#define GUI_GET_VCATYPE_REQ	4500		//��ȡ���ܷ���������������
#define GUI_GET_VCATYPE_RSP	-4500		//��ȡ���ܷ����������ͻ�Ӧ

typedef struct
{
	int m_iChn;		//ͨ���ţ���1��ʼ��0��ʾȫ��
	int m_iSceneId;	//���� 0~15,�߶�������
	unsigned char m_strSceneName[GUI_PUBLIC_LEN_63 + 1];	//��������
}TGuiGetVcaTypeReq;

typedef struct
{
	int m_iChn;
	int m_iSceneId;
	int m_iVcaType;		//��λ�� ���ö��EVCATYPE��1��ʾ���ã�0��ʾ������
	unsigned char m_strSceneName[GUI_PUBLIC_LEN_63 + 1];
}TGuiGetVcaTypeRsp;

#define GUI_SET_VCATYPE_REQ	4501	//�������ܷ���������������
#define GUI_SET_VCATYPE_RSP	-4501	//��Ӧ
typedef struct
{
	int m_iChn;
	int m_iSceneId;
	int m_iVcaType;		//��λ�� ���ö��EVCATYPE��1��ʾ���ã�0��ʾ������
	unsigned char m_strSceneName[GUI_PUBLIC_LEN_63 + 1];
}TGuiSetVcaTypeReq;

typedef struct
{
	int m_iRetCode;		// 0��ɹ� �����ʾʧ��
}TGuiSetVcaTypeRsp;

//�����Ϊ�����㷨
#define MAX_IGNORE_REGION_NUM	3
#define MAX_PARAM_SIZE			2048		/*����������������ʱΪ2048���ֽ�*/

typedef struct		/* �����߲���*/
{
	int				m_iEventValid;			/*�¼�ʹ��*/
	int				m_iTargetTypeCheck;		/*�������: 1-�ˡ�2-����3-�˳���0-������*/
	int				m_iType;				/*0-������߻�1-˫�����*/
	int				m_iDirection;			/*���߱�������*/
	int				m_iMinDistance;			/*���ü����С����: Ĭ��0*/
	int				m_iMinTime;				/*����ʱ��: Ĭ��0*/
	int				m_iDisplayRule;			/*�Ƿ���ʾ������: 0 - ����ʾ	1-��ʾ */
	int				m_iDisplayStat;			/*�Ƿ���ʾ��������: 0 - ����ʾ	1-��ʾ*/
	int				m_iAlarmCount;			/*��������: �ø���������Ļ����ʾ*/
	int				m_iColor;				/*δ����ʱ��������ɫ0:Ĭ�� 1:��ɫ 2:��ɫ 3:��ɫ 4:��ɫ 5:��ɫ 6:��ɫ 7:��ɫ 8:��ɫ*/
	int				m_iAlarmColor;			/*����ʱ�Ĺ�������ɫ0:Ĭ�� 1:��ɫ 2:��ɫ 3:��ɫ 4:��ɫ 5:��ɫ 6:��ɫ 7:��ɫ 8:��ɫ*/
	TGuiVcaLine		m_stLine;				
	int				m_iMinSize;
	int				m_iMaxSize;
	TGuiVcaPolygon	m_stLineEx;
}TGuiVcaParamTripwire;

typedef struct		/* ˫���߲���*/
{
	int				m_iEventValid;			/*�¼�ʹ��*/
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
	int				m_iMinDBTime;
	int				m_iMaxDBTime;
	int				m_iMaxSize;
	int				m_iMinSize;
	TGuiVcaPolygon	m_stLine[2];
}TGuiVcaParamDBTripwire;


typedef struct		/*�ܽ����*/
{
	int				m_iEventValid;			/*�¼�ʹ��*/
	int				m_iTargetTypeCheck;		/*�������: 1-�ˡ�2-����3-�˳���0-������*/
	int				m_iMode;				/*����ģʽ: ���֡����롢�뿪*/
	int				m_iType;				/*���޷���*/
	int 			m_iDirection;			/*��������*/
	int				m_iMinDistance;			/*������С���ؾ���: Ĭ��0	*/
	int 			m_iMinTime;				/*�������ʱ��: Ĭ��0*/
	int				m_iDisplayRule;			/*�Ƿ���ʾ������: 0 - ����ʾ	1-��ʾ */
	int				m_iDisplayStat;			/*�Ƿ���ʾ��������: 0 - ����ʾ	1-��ʾ*/
	int				m_iAlarmCount;			/*��������: �ø���������Ļ����ʾ*/
	int				m_iColor;				/*δ����ʱ��������ɫ*/
	int				m_iAlarmColor;			/*����ʱ�Ĺ�������ɫ*/
	int				m_iMinSize;
	int				m_iMaxSize;
	TGuiVcaPolygon	m_stRegion;
}TGuiVcaParamPerimeter;


typedef struct		/*��Ʒ������������*/
{
	int				m_iEventValid;		/*�¼�ʹ��*/
	int				m_iSceneType;		/*��������  0���� 1����*/
	int				m_iCameraType;		/*�������  0��ͨ��� 1������*/
	int				m_iDisplayRule;		/*�Ƿ���ʾ������: 0 - ����ʾ	1-��ʾ */
	int				m_iDisplayStat;		/*�Ƿ���ʾ��������: 0 - ����ʾ	1-��ʾ*/
	int				m_iAlarmCount;		/*��������: �ø���������Ļ����ʾ*/
	int				m_iColor;			/*δ����ʱ��������ɫ*/
	int				m_iAlarmColor;		/*����ʱ�Ĺ�������ɫ*/
	int				m_iTimeMin;			/*�������ʱ�䣬��Ʒ��ʧʱ�����Ҫ���ڴ˷�ֵ*/
	int				m_iSizeMin;			/*������������С������*/
	int				m_iSizeMax;			/*�������������������*/
	TGuiVcaPolygon	m_stMainRegion;		/*�������ṹ*/
	TGuiVcaPolygon	m_stIgnoreRegion[MAX_IGNORE_REGION_NUM]; /*���Լ���С��*/
}TGuiVcaParamOSC;


typedef struct		/*�ǻ�������ò���*/
{	
	int				m_iEventValid;			/*�¼�ʹ��*/
	int				m_iMinTime;				/*��Сʱ��*/
	int				m_iAlarmCount;			/*��������: �ø���������Ļ����ʾ*/
	int				m_iSensitivity;			/*yansm 20140222 add ������*/
	int				m_iMinRange;			/*yansm 20140222 add �ǻ���С����ٷֱ�*/
	int				m_iColor;		 		/*������ɫ*/
	int				m_iAlarmColor;			/*����ʱ�������ɫ*/
	int				m_iDisplayRule;			/*�����Ƿ���ʾ*/
	int				m_iDisplayStat;			/*���������Ƿ���ʾ*/
	TGuiVcaPolygon	m_stRegion;
	int				m_iMinBoundy;
}TGuiVcaParamOabLoi;


typedef struct		/*���ܼ�����ò���*/
{
	int				m_iEventValid;			/*�¼�ʹ��*/
	int				m_iColor;				/*������ɫ*/
	int				m_iAlarmColor;			/*����ʱ�������ɫ*/
	int				m_iDisplayRule;			/*�����Ƿ���ʾ*/
	int				m_iDisplayStat;			/*���������Ƿ���ʾ*/
	int				m_iMaxDistance;			/*�˱���������*/
	int				m_iMinDistancePreS;		/*ÿ����С�ƶ�����*/
	int				m_iAlarmCount;			/*��������: �ø���������Ļ����ʾ*/
	int				m_iMinSize;
	int				m_iMaxSize;
	TGuiVcaPolygon	m_stRegion;
}TGuiVcaParamRun;

typedef struct		/*ͣ��������ò���*/
{
	int				m_iEventValid;			/*�¼�ʹ��*/
	int				m_iColor;				/*������ɫ*/
	int				m_iAlarmColor;			/*����ʱ�������ɫ*/
	int				m_iDisplayRule;			/*�����Ƿ���ʾ*/
	int				m_iDisplayStat;			/*���������Ƿ���ʾ*/
	int				m_iAlarmTime;			/*����ͣ�������ĳ���ʱ��*/
	int				m_iAlarmCount;			/*��������: �ø���������Ļ����ʾ*/
	int				m_iMinSize;
	int				m_iMaxSize;
	int				m_ifThVeloc;
	TGuiVcaPolygon	m_stRegion;
}TGuiVcaParamPark;

/**********           ��Ϊ�����¼�����        **********/

//��ȡ��Ϊ���������¼�ʹ��״̬
#define GUI_GET_VCA_ANALY_ENABLE_REQ		4522		//��ȡ���ܷ��������¼�ʹ��״̬����
#define GUI_GET_VCA_ANALY_ENABLE_RSP		-4522		//��ȡ���ܷ��������¼�ʹ��״̬��Ӧ

typedef struct
{
	int 	m_iChannel;		//ͨ����
	int		m_iSceneId;		//�������
	int		m_iRulesNo;		//�����
} TGuiGetVcaAnalyRuleEventEnableReq;

typedef struct
{
	int 	m_iChannel;				//ͨ����
	int		m_iSceneId;				//�������
	int		m_iRuleEnable;			//�����Ƿ�ʹ��
	int 	m_iEventType;			//�����Ӧ�������¼���Ч��bit EGuiVcaEventType��λ��ʾ��1����
} TGuiVcaAnalyEnableMsg;

typedef struct
{
	int						m_iChannel;
	int						m_iRulesNo;
	TGuiVcaAnalyEnableMsg 	m_iEnableMsg;
} TGuiGetVcaAnalyRuleEventEnableRsp;

typedef union
{
	TGuiVcaParamTripwire		m_stTripwire;		/*��Խ���߲���*/
	TGuiVcaParamDBTripwire		m_stDBTripwire;		/*˫����*/
	TGuiVcaParamPerimeter		m_stPerimeter;		/*�ܽ����*/
	TGuiVcaParamOSC				m_stoscer;			/*��Ʒ��������*/
	TGuiVcaParamOabLoi			m_stOabLoi;			/*�ǻ�*/
	TGuiVcaParamRun				m_stRun;			/*����(�����ƶ�)*/
	TGuiVcaParamPark			m_stPark;			/*ͣ��*/
	/*������������ռ䡣�Ժ���ӵ����ܷ����ܲ������ܳ��������ʹ�С*/
	char						m_s8MaxSize[MAX_PARAM_SIZE];
}UGuiVcaEventParam;	

#define GUI_GET_VCAANALYSE_CNF_REQ	 4502	//��ȡ��Ϊ������������
#define GUI_GET_VCAANALYSE_CNF_RSP	-4502	//��ȡ��Ϊ�������û�Ӧ
typedef  struct 
{
	int 				m_iChannelNo;		//ͨ����		
	int					m_iSceneId;			//�������
	int 				m_iRulesNo;			//�����
	EGuiVcaEventType 	m_eEventType;		//�¼�����
}TGuiGetVcaAnalyReq;

typedef struct
{
	int 					m_iChannelNo;		//ͨ����
	int						m_iSceneId;			//�������
	unsigned char 			m_strSceneName[GUI_PUBLIC_LEN_63 + 1]; //��������
	int 					m_iRulesNo;			//�����
	unsigned char			m_cRuleName[MAX_GUI_RULE_NAME_LEN + 1];	//�¼�����
	int 					m_iRuleEnable;		//�����Ƿ�ʹ��
	EGuiVcaEventType 		m_eEventType;		//�¼�����	
	UGuiVcaEventParam 	m_stEventParam;			// ��Ϊ�����¼�����
} TGuiGetVcaAnalyRsp;

#define GUI_SET_VCAANALYSE_CNF_REQ	 4503	//������Ϊ������������
#define GUI_SET_VCAANALYSE_CNF_RSP	-4503	//������Ϊ�������û�Ӧ
typedef  TGuiGetVcaAnalyRsp  TGuiSetVcaAnalyReq;

typedef struct
{
	int m_iRetCode;	//0��ɹ�, �����ʾʧ��
} TGuiSetVcaAnalyRsp;

//************��Ⱥ�ۼ�*********************//
typedef struct 
{
	TGuiVcaPoint m_LeftUp;
	TGuiVcaPoint m_RightDown;
}TGuiVcaRect_Ex;

typedef struct		/*��Ա�ۼ�CDD���ò���*/
{
	int				m_iStructSize;
	int				m_iSensitivity;		/*������*/
	int				m_iFlag;			/*��ʱ����*/
	int				m_iRegionNum;		/*�������*/
	TGuiVcaRect_Ex	m_stRegion[4];		/*�������,���4��*/
	int				m_iTimes;			/*����ʱ��*/
	TGuiVcaPolygon	m_stMainRegion;		/*�޸�Ϊ�����*/
	int				m_iDisplayRule;		/*�����Ƿ���ʾ*/
	int				m_iDisplayStat;		/*���������Ƿ���ʾ*/
	int 			m_iColor;
	int 			m_iAlarmColor;
}TGuiVcaParamCDD;

#define GUI_GET_VCACCD_REQ		 		4504	//��ȡ��Ⱥ�ۼ���������
#define GUI_GET_VCACCD_RSP				-4504	//��ȡ��Ⱥ�ۼ�������Ӧ
typedef struct
{
	int m_iChn;			//ͨ����
	int m_iSceneId;		//�������
	unsigned char m_strSceneName[GUI_PUBLIC_LEN_63 + 1]; //��������
}TGuiGetVcaCCDReq;

typedef struct
{
	int m_iChn;			//ͨ����
	int m_iSceneId;		//�������
	unsigned char m_strSceneName[GUI_PUBLIC_LEN_63 + 1]; //��������
	TGuiVcaParamCDD  m_tCcdCnf;
}TGuiGetVcaCCDRsp; 

#define GUI_SET_VCACCD_REQ			4505		//������Ⱥ�ۼ���������
#define GUI_SET_VCACCD_RSP			-4505		//������Ⱥ�ۼ�������Ӧ
typedef  TGuiGetVcaCCDRsp TGuiSetVcaCCDReq;
typedef struct
{
	int m_iRetCode;		//0��ɹ��������ʾʧ��
}TGuiSetVcaCCDRsp;


//***************����ͳ��*******************//
typedef struct		/*����ͳ��CPC���ò���*/
{
	int				m_iStructSize;
	int				m_iMode;				/*1-��ֱ����ͳ�ƣ�2-ˮƽ����ͳ��*/
	int				m_iMinSize;				/*Ŀ����С�ߴ�*/
	int				m_iMaxSize;				/*Ŀ�����ߴ�*/
	int				m_iSensitiv;			/*������*/
	int				m_iDetecType;			/*�������*/
	int 			m_iColor;
	int 			m_iAlarmColor;
	int				m_iAlarmInCount;
	int				m_iAlarmOutConut;
	TGuiVcaPolygon	m_stRegion;
	TGuiVcaPolygon	m_stRegionEx;
}TGuiVcaCPCAdv;

#define GUI_GET_VCA_CPCADV_REQ		4506 //��ȡ����ͳ������
#define GUI_GET_VCA_CPCADV_RSP		-4506 //��ȡ����ͳ�ƻ�Ӧ
typedef struct
{
	int m_iChn;
	int m_iSceneId;		//�������
	unsigned char m_strSceneName[GUI_PUBLIC_LEN_63 + 1]; //��������
}TGuiGetCpcAdvanceReq;

typedef struct
{
	int m_iChn;
	int m_iSceneId;		//�������
	unsigned char m_strSceneName[GUI_PUBLIC_LEN_63 + 1]; //��������
	TGuiVcaCPCAdv  m_tCpcAdvCnf;
}TGuiGetCpcAdvancedRsp;

#define GUI_SET_CPCADVANCE_REQ		4507  //��������ͳ������
#define GUI_SET_CPCADVANCE_RSP		-4507 //��������ͳ�ƻ�Ӧ
typedef TGuiGetCpcAdvancedRsp TGuiSetCpcAdvancedReq;
typedef struct
{
	int m_iRetCode;     //0��ɹ� �����ʾʧ��
}TGuiSetCpcAdvancedRsp;

//**************�������*******************//
typedef struct     /*����ʶ��VFD���ò���*/
{
	int			m_iStructSize;
	int			m_iMaxSize;			/*��������ߴ�*/
	int			m_iMinSize;			/*��С�����ߴ�*/
	int			m_iLevel;			/*�㷨���м���*/
	int			m_iSensitiv;		/*������*/
	int			m_iPicScal;			/*ͼ�����ű���*/
	int			m_iSnapEnable;		/*����ץ��ʹ��*/
	int			m_iSnapSpace;		/*ץ�ļ��*/
	int			m_iSnapTimes;		/*ץ�Ĵ���*/
	int 			m_iColor;
	int 			m_iAlarmColor;
	TGuiVcaPolygon	m_stRegion;	
}TGuiVcaVFDAdv;

#define GUI_GET_FACEADVANCE_REQ		4508	//��ȡ�����������
#define GUI_GET_FACEADVANCE_RSP		-4508	//��ȡ��������Ӧ
typedef struct
{
	int m_iChn;			//ͨ����
	int m_iSceneId;		//�������
	unsigned char m_strSceneName[GUI_PUBLIC_LEN_63 + 1]; //��������
}TGuiGetFaceAdvanceReq;

typedef struct
{
	int m_iChn;			//ͨ����
	int m_iSceneId;		//�������
	unsigned char m_strSceneName[GUI_PUBLIC_LEN_63 + 1]; //��������
	TGuiVcaVFDAdv m_tVfdCnf;
}TGuiGetFaceAdvanceRsp;

#define GUI_SET_FACEADVANCE_REQ		4509	//���������������
#define GUI_SET_FACEADVANCE_RSP		-4509	//������������Ӧ
typedef TGuiGetFaceAdvanceRsp TGuiSetFaceAdvanceReq;
typedef struct
{
	int m_iRetCode;      //0��ɹ�, 1��ʧ��
}TGuiSetFaceAdvanceRsp;

//*****************����ʶ��*****************//
#define GUI_GET_ITS_VLOOP_REQ		4510 	//��ȡ������Ȧ��������
#define GUI_GET_ITS_VLOOP_RSP		-4510 	//��ȡ������Ȧ������Ӧ
typedef  struct
{
	int m_iChn;          //ͨ����
	int m_iRoadId;       //�������
	int m_iVLoopId;      //������Ȧ
	int m_iSceneId;		 //����ID
	int m_iDayNight;	 //ʱ���־ 1-����0-����
	unsigned char m_strSceneName[GUI_PUBLIC_LEN_63 + 1]; //��������
}TGuiGetVLoopCnfReq;

typedef struct
{
	int m_iChn; 		 //ͨ����
	int m_iRoadId;       //�������
	int m_iVLoopId;      //������Ȧ
	int m_iSceneId;		 //����ID
	int m_iDayNight;	 //ʱ���־ 1-����0-����
	int m_iSensitivity;	 //�����ȣ�ռ��
	unsigned char m_strSceneName[GUI_PUBLIC_LEN_63 + 1]; //��������
	TGuiVcaPolygon m_tVLoopRegion;	//��Ȧ����
}TGuiGetVLoopCnfRsp;

#define GUI_SET_ITS_VLOOP_REQ		4511  //����������Ȧ��������
#define GUI_SET_ITS_VLOOP_RSP		-4511 //����������Ȧ������Ӧ
typedef TGuiGetVLoopCnfRsp TGuiSetVLoopCnfReq;

typedef struct
{
	int m_iRetCode;			//0��ɹ��������ʾʧ��
}TGuiSetVLoopCnfRsp;		//��Ӧ


//*****************����ʶ������*************************//
#define GUI_GET_ITS_RECO_RANGE_REQ	4512	//��ȡ����ʶ����������
#define GUI_GET_ITS_RECO_RANGE_RSP	-4512	//��ȡ����ʶ�������Ӧ
typedef struct
{
	int m_iChn; 		 //ͨ����
	int m_iRoadId;       //����  0~3
	int m_iSceneId;		 //����
	unsigned char m_strSceneName[GUI_PUBLIC_LEN_63 + 1]; //��������
}TGuiGetRecoRangeReq;

typedef struct
{
	int m_iChn;
	int m_iRoadId;       //����  0~3
	int m_iSceneId;		 //����
	int m_iLeftRange;	 //��߽� 0~100
	int m_iTopRange;	 //�ϱ߽� 0~100
	int m_iRightRange;	 //�ұ߽� 0~100
	int m_iBottomRange;	 //�±߽� 0~100
	unsigned char m_strSceneName[GUI_PUBLIC_LEN_63 + 1]; //��������
}TGuiGetRecoRangeRsp;

#define GUI_SET_ITS_RECO_RANGE_REQ	4513	//���ó���ʶ����������
#define GUI_SET_ITS_RECO_RANGE_RSP	-4513	//���ó���ʶ�������Ӧ
typedef TGuiGetRecoRangeRsp TGuiSetRecoRangeReq;

typedef struct
{
	int m_iRetCode;	//0��ɹ��������ʧ��
}TGuiSetRecoRangeRsp;

//*************************�����Ż�**********************//
#define GUI_GET_ITS_OPTIM_REQ		4514	//��ȡ�����Ż�����
#define GUI_GET_ITS_OPTIM_RSP		-4514	//��ȡ�����Ż���Ӧ

typedef struct
{
	int m_iChn;			//ͨ����
	int m_iSceneId;		//����
	unsigned char m_strSceneName[GUI_PUBLIC_LEN_63 + 1]; //��������
}TGuiGetItsOptimReq;

typedef struct
{
	int m_iChn;					//ͨ����
	int m_iSceneId;				//����
	char m_strModifyChar[GUI_PUBLIC_LEN_15 + 1];        //�Ż��׺���  utf-8����
	int m_iMinCharConfig;		//�׺����Ż�������Ŷ�  ����1000
	char m_strModifyAlpha[GUI_PUBLIC_LEN_15 + 1];       //�Ż�����ĸ
	int m_iMinAlphaConfig;		//����ĸ�Ż�������Ŷ�
	unsigned char m_strSceneName[GUI_PUBLIC_LEN_63 + 1]; //��������
}TGuiGetItsOptimRsp;

#define GUI_SET_ITS_OPTIM_REQ		4515	//���ó����Ż�����
#define GUI_SET_ITS_OPTIM_RSP		-4515	//���ó����Ż���Ӧ
typedef  TGuiGetItsOptimRsp TGuiSetItsOptimReq;

typedef struct
{
	int m_iRetCode;		//0��ɹ��������ʧ��
}TGuiSetItsOptimRsp;


//**************************��ڼ��***********************//   
typedef struct		/*��ڼ��SVD���ò���*/
{
	int			    m_iStructSize;
	int				m_iAlertTime;
	int				m_iClearTime;
	int				m_iSensitivity;
	int				m_iAlarmCount;
	int				m_iColor;			/*δ����ʱ��������ɫ*/
	int				m_iAlarmColor;		/*����ʱ�Ĺ�������ɫ*/
	int				m_iDisplayRule;		
	int				m_iDisplayStat;
	int				m_iRegionNum;
	int				m_iDutyNum;
	int				m_iMinSize;
	int				m_iMaxSize;
	TGuiVcaRect_Ex	m_stRegion[4];		/*�������,���4��*/
}TGuiVcaParamSVD;

#define GUI_GET_VCASVD_REQ		 		4516	//��ȡ��ڼ���������
#define GUI_GET_VCASVD_RSP				-4516	//��ȡ��ڼ�������Ӧ
typedef struct
{
	int m_iChn;		//ͨ����
	int m_iSceneId;	//�������
	unsigned char m_strSceneName[GUI_PUBLIC_LEN_63 + 1]; //��������
}TGuiGetVcaSVDReq;

typedef struct
{
	int m_iChn;		//ͨ����
	int m_iSceneId;	//�������
	unsigned char m_strSceneName[GUI_PUBLIC_LEN_63 + 1]; //��������
	TGuiVcaParamSVD m_tSvdCnf;
}TGuiGetVcaSVDRsp;


#define GUI_SET_VCASVD_REQ			4517		//������ڼ���������
#define GUI_SET_VCASVD_RSP			-4517		//������ڼ�������Ӧ
typedef  TGuiGetVcaSVDRsp TGuiSetVcaSVDReq;
typedef struct
{
	int m_iRetCode;		//0��ɹ��������ʾʧ��
}TGuiSetVcaSVDRsp;

//*****************��Ƶ���*********************//

typedef struct
{
	int				m_iLevel;
	int				m_iTime;
}TGuiVcaLevelTimePara;

typedef struct		/*��Ƶ���AVD ����*/
{
	int			    m_iStructSize;
	int				m_iRuleEvevtid;		/* ��Ƶ��Ϲ����ʶ����λ��Э���ĵ����
											������� 	0x0000000001
											���������	0x0000000010
											�������	0x0000000100 
											��������Ϊƫɫ��ϡ����涳����ϡ��ź�ȱʧ���
											�����任��� ��Ϊ������� PTZʧ�����*/
	int				m_iAlarmCount;		/*��������: �ø���������Ļ����ʾ*/
	int				m_iDisplayStat;
	int				m_iCheckTime;
	TGuiVcaLevelTimePara		m_stAvdPara[9];
} TGuiVcaParamAVD;

#define GUI_GET_VCAAVD_REQ		 		4518	//��ȡ��Ƶ��ϼ���������
#define GUI_GET_VCAAVD_RSP				-4518	//��ȡ��Ƶ��ϼ�������Ӧ
typedef struct
{
	int m_iChn;			//ͨ����
	int m_iSceneId;		//�������
	unsigned char m_strSceneName[GUI_PUBLIC_LEN_63 + 1]; //��������
}TGuiGetVcaAVDReq;

typedef struct
{
	int m_iChn;			//ͨ����
	int m_iSceneId;		//�������
	unsigned char m_strSceneName[GUI_PUBLIC_LEN_63 + 1]; //��������
	TGuiVcaParamAVD m_tAvdCnf;
}TGuiGetVcaAVDRsp; 


#define GUI_SET_VCAAVD_REQ			4519		//������Ƶ��ϼ���������
#define GUI_SET_VCAAVD_RSP			-4519		//������Ƶ��ϼ�������Ӧ
typedef  TGuiGetVcaAVDRsp TGuiSetVcaAVDReq;
typedef struct
{
	int m_iRetCode;		//0��ɹ��������ʾʧ��
}TGuiSetVcaAVDRsp;

//***********************��Ƶ�쳣���***************************//
typedef struct		/*��Ƶ���AAD ����*/
{
	int			    m_iStructSize;
	int				m_iRuleEvevtid;		/* ��Ƶ��Ϲ����ʶ����λ��Э���ĵ����
										Lost			-00001
										Abnormal		-00010
										NoiseSupr		-00100
										EchoSupr		-01000
										FeedbackSupr	-10000
										*/
	int				m_iAlarmCount;		/*��������: �ø���������Ļ����ʾ*/
	int				m_iDisplayStat;
	int				m_iCheckTime;
	TGuiVcaLevelTimePara		m_stAadPara[5];
}TGuiVcaParamAAD;

#define GUI_GET_VCAAAD_REQ				4520	//��ȡ��Ƶ�쳣����������
#define GUI_GET_VCAAAD_RSP				-4520	//��ȡ��Ƶ�쳣��������Ӧ
typedef struct
{
	int m_iChn;			//ͨ����
	int m_iSceneId;		//�������
	unsigned char m_strSceneName[GUI_PUBLIC_LEN_63 + 1]; //��������
}TGuiGetVcaAADReq;

typedef struct
{
	int m_iChn;			//ͨ����
	int m_iSceneId;		//�������
	unsigned char m_strSceneName[GUI_PUBLIC_LEN_63 + 1];	//��������
	TGuiVcaParamAAD m_tAadCnf;
}TGuiGetVcaAADRsp;


#define GUI_SET_VCAAAD_REQ			4521		//������Ƶ�쳣����������
#define GUI_SET_VCAAAD_RSP			-4521		//������Ƶ�쳣��������Ӧ
typedef  TGuiGetVcaAADRsp TGuiSetVcaAADReq;
typedef struct
{
	int m_iRetCode;		//0��ɹ��������ʾʧ��
}TGuiSetVcaAADRsp;


//*******************����**********************//
typedef enum
{
	GUI_PTZP=1,
	GUI_PTZT,
	GUI_ZOOMRATE,		//���ٱ���
	GUI_ZOOMRATIO,		//���ٱ���ϵ��
	GUI_CMRTYPE,			//��о����
	GUI_MAXFOLLOWTIME,	//�����ʱ��
	GUI_HEIGHT,			//����߶�
	GUI_DESSTOPTIME,		//Ŀ�꾲ֹ����ʱ��
	GUI_ENABLEFLAG,		//ʹ�ܱ�־��λ
							//��0λ:��⵽�������Ƿ񷵻�
							//��1λ:�Ƿ�ʹ�ÿ��ڵ�����
							//��2λ:�Ƿ�������λ
	GUI_LEFTPOS,		// >= 0 ��ʾ��Ч�������ʾ��Ч��Ϊ�Ƕ�
	GUI_TOPPOS,
	GUI_RIGHTPOS,
	GUI_BOTTOMPOS,
}EGuiVcaParamCAP;

typedef struct
{
	int m_iId;			//TGuiVcaParamCAP KEY
	int m_iValue;		//��ӦTGuiVcaParamCAP��ֵ
}TGuiItem;

typedef struct
{
	int m_iCnt;  //����
	TGuiItem m_tItem[0];
}TGuiVcaCAPCnf;

#define GUI_GET_VCACAP_REQ			4523	//��ȡ���ٲ�������
#define GUI_GET_VCACAP_RSP			-4523	//��ȡ���ٲ�����Ӧ

typedef struct
{
	int m_iChn;			//ͨ����
	int m_iSceneId;		//�������
	unsigned char m_strSceneName[GUI_PUBLIC_LEN_63 + 1]; //��������
}TGuiGetVcaCAPReq;

typedef struct
{
	int m_iChn;			//ͨ����
	int m_iSceneId;		//�������
	unsigned char m_strSceneName[GUI_PUBLIC_LEN_63 + 1]; //��������
	TGuiVcaCAPCnf  m_tCapCnf;
}TGuiGetVcaCAPRsp; 

#define GUI_SET_VCACAP_REQ				4524	//���ø��ٲ�������
#define GUI_SET_VCACAP_RSP				-4524	//���ø��ٲ�����Ӧ

typedef  TGuiGetVcaCAPRsp TGuiSetVcaCAPReq;
typedef struct
{
	int m_iRetCode;		//0��ɹ��������ʾʧ��
}TGuiSetVcaCAPRsp;

// ================================================================
// 2010-11-9 Э����չ

// ========�û�����=======================================
// ��ȡ�û���ϢЭ��(��չ)
#define GUI_GET_USER_MSG_EX_REQ	10000
#define GUI_GET_USER_MSG_EX_RSP	-10000

typedef struct
{
	char m_strUser[GUI_USER_NAME_LEN + 1];
} TGuiGetUserMsgExReq;

typedef struct
{
	int m_iGid;	//�û���
	char m_strUser[GUI_USER_NAME_LEN + 1];
	char m_strPsw[GUI_USER_PSW_LEN + 1];
} TGuiGetUserMsgExRsp;

// =====================�ַ������������=============

#define GUI_SET_OSD_OK   0
#define GUI_SET_OSD_ERR  1
//===================��չ ͨ�����Ƶ���====================
#define GUI_GET_OSD_CHN_NAME_EX_REQ		1008		//��չ�Ļ�ȡͨ�����Ƶ�������
#define GUI_GET_OSD_CHN_NAME_EX_RSP		-1008		//��չ�Ļ�ȡͨ�����Ƶ��ӻ�Ӧ
#define GUI_SET_OSD_CHN_NAME_EX_REQ		1009		//��չ������ͨ�����Ƶ�������
#define GUI_SET_OSD_CHN_NAME_EX_RSP		-1009		//��չ������ͨ�����Ƶ��ӻ�Ӧ

typedef struct
{
	int m_iDsp;		//�Ƿ���ʾ
	int m_iColor;		//������ɫ
	int m_iLocType;	//��������:0 ��������, 1 : 24x16С����
	int m_iXp;
	int m_iYp;
	char m_strName[0];  //ʵ�ʵ�ͨ����������
} TGuiOsdChnNameCnfEx;  //��չ������ͨ�����ƵĽṹ��

typedef struct
{
	int m_iChn;
} TGuiGetOsdChnNameExReq;		//��չ�Ļ�ȡͨ�����Ƶ�������

typedef struct
{
	int m_iChn;
	TGuiOsdChnNameCnfEx m_tCnf;
} TGuiGetOsdChnNameExRsp; //��չ�Ļ�ȡͨ�����Ƶ��ӻ�Ӧ

typedef struct
{
	int m_iChn;		//ͨ����
	TGuiOsdChnNameCnfEx m_tCnf;
} TGuiSetOsdChnNameExReq;		//��չ������ͨ�����Ƶ�������

typedef struct
{
	int m_iRetCode;    //���óɹ�GUI_SET_OSD_OK�� ����ʧ��GUI_SET_OSD_ERR
} TGuiSetOsdChnNameExRsp;	   //��չ������ͨ�����Ƶ��ӻ�Ӧ


//=================== ͨ�����Ƶ���====================
#define GUI_SET_OSD_CHN_NAME_REQ		1010
#define GUI_SET_OSD_CHN_NAME_RSP		-1010
#define GUI_GET_OSD_CHN_NAME_REQ		1011
#define GUI_GET_OSD_CHN_NAME_RSP		-1011

typedef struct
{
	int m_iDsp;		//�Ƿ���ʾ
	int m_iColor;		//������ɫ
	int m_iLocType;	//��������:0 ��������, 1 : 24x16С����
	int m_iXp;
	int m_iYp;
	char m_strName[GUI_CHN_NAME_LEN + 1];
} TGuiOsdChnNameCnf;

typedef struct
{
	int m_iChn;		//ͨ����
	TGuiOsdChnNameCnf m_tCnf;
} TGuiSetOsdChnNameReq;

typedef struct
{
	int m_iRetCode; //���óɹ�GUI_SET_OSD_OK�� ����ʧ��GUI_SET_OSD_ERR
} TGuiSetOsdChnNameRsp;

typedef struct
{
	int m_iChn;
} TGuiGetOsdChnNameReq;

typedef struct
{
	int m_iChn;
	TGuiOsdChnNameCnf m_tCnf;
} TGuiGetOsdChnNameRsp;


//==================== ʱ�����=====================
#define GUI_SET_OSD_TM_REQ		1012		
#define GUI_SET_OSD_TM_RSP		-1012
#define GUI_GET_OSD_TM_REQ		1013
#define GUI_GET_OSD_TM_RSP		-1013

typedef struct
{
	int m_iDsp;		//����ȫ��
	int m_iColor;	
	int m_iLocType;
	int m_iXp;
	int m_iYp;
	int m_iType;		//���Ӹ�ʽ
} TGuiOsdTmCnf;

typedef struct
{
	int m_iChn;
	TGuiOsdTmCnf m_tCnf;
} TGuiSetOsdTmReq;

typedef struct
{
	int m_iRetCode; //���óɹ�GUI_SET_OSD_OK�� ����ʧ��GUI_SET_OSD_ERR
} TGuiSetOsdTmRsp;

typedef struct
{
	int m_iChn;
} TGuiGetOsdTmReq;

typedef struct
{
	int m_iChn;
	TGuiOsdTmCnf m_tCnf;
} TGuiGetOsdTmRsp;

// =================�Զ����ı�===============
#define GUI_SET_OSD_TEXT_REQ	1014
#define GUI_SET_OSD_TEXT_RSP	-1014
#define GUI_GET_OSD_TEXT_REQ	1015
#define GUI_GET_OSD_TEXT_RSP	-1015

#define GUI_CHG_OSD_TEXT_REQ     1018
#define GUI_CHG_OSD_TEXT_RSP     -1018

typedef struct
{
	int m_iDsp;
	int m_iColor;
	int m_iLocType;
	int m_iXp; 		/*��8λ���� ��ʪ��ģ���Ƿ����*/
	int m_iYp;		/*��8λ���� ����ģ���Ƿ����*/
	char m_strText[0];
} TGuiOsdTextCnf;

typedef struct
{
	int m_iChn;
	TGuiOsdTextCnf m_tCnf;
} TGuiSetOsdTextReq;

typedef struct
{
	int m_iRetCode;//���óɹ�GUI_SET_OSD_OK�� ����ʧ��GUI_SET_OSD_ERR
} TGuiSetOsdTextRsp;

typedef struct
{
	int m_iChn;
} TGuiGetOsdTextReq;

typedef struct
{
	int m_iChn;
	TGuiOsdTextCnf m_tCnf;
} TGuiGetOsdTextRsp;
//�Զ����ַ����ӣ�֧�ֶ������
#define GUI_SET_MUTI_OSD_TEXT_REQ	1204
#define GUI_SET_MUTI_OSD_TEXT_RSP	-1204
#define GUI_GET_MUTI_OSD_TEXT_REQ	1205
#define GUI_GET_MUTI_OSD_TEXT_RSP	-1205
#define GUI_CHG_MUTI_OSD_TEXT_REQ   1206
#define GUI_CHG_MUTI_OSD_TEXT_RSP   -1206

typedef struct
{
	int m_iLayNo;
	TGuiOsdTextCnf m_tCnf;
} TGuiMutiOsdTextCnf;

typedef struct
{
	int m_iChn;
	TGuiMutiOsdTextCnf m_tCnf;
} TGuiSetMutiOsdTextReq;

typedef struct
{
	int m_iRetCode;//���óɹ�GUI_SET_OSD_OK�� ����ʧ��GUI_SET_OSD_ERR
} TGuiSetMutiOsdTextRsp;

typedef struct
{
	int m_iChn;
	int m_iLayNo;
} TGuiGetMutiOsdTextReq;

typedef struct
{
	int m_iChn;
	TGuiMutiOsdTextCnf m_tCnf;
} TGuiGetMutiOsdTextRsp;

// ��Ƶ�ڵ���������
#define GUI_SET_OSD_PAREA_REQ		1016
#define GUI_SET_OSD_PAREA_RSP		-1016
#define GUI_GET_OSD_PAREA_REQ		1017
#define GUI_GET_OSD_PAREA_RSP		-1017

typedef struct
{
	int m_iEnable;	//��Ƶ�ڵ�����ȫ�ܱ�ʶ
	int m_iLocType;	//��������
	int m_iAreaCnt;
	TGuiArea m_tPrvAreas[GUI_MAX_COVER_AREA];
} TGuiOsdPrvAreaCnf;

typedef struct
{
	int m_iChn;
	TGuiOsdPrvAreaCnf m_tCnf;
} TGuiSetOsdPrvAreaReq;

typedef struct
{
	int m_iRetCode;
} TGuiSetOsdPrvAreaRsp;

typedef struct
{
	int m_iChn;
} TGuiGetOsdPrvAreaReq;

typedef struct
{
	int m_iChn;
	TGuiOsdPrvAreaCnf m_tCnf;
} TGuiGetOsdPrvAreaRsp;

#define GUI_GET_DYNAMIC_PRVAREA_REQ      1050//��ȡ��̬��˽��������
#define GUI_GET_DYNAMIC_PRVAREA_RSP	    -1050  //��ȡ��̬��˽�����Ӧ
#define GUI_SET_DYNAMIC_PRVAREA_REQ      1051  //���ö�̬��˽��������
#define GUI_SET_DYNAMIC_PRVAREA_RSP	    -1051  //���ö�̬��˽�����Ӧ

typedef struct
{
	int m_iAreaNo;         //������ 1~24
	int m_iMinZoomSize;    //��С�䱶 1~50
	int m_iColor;          //��ɫ 1����ɫ 2����ɫ 3����ɫ 4����ɫ 5����ɫ 6����ɫ 7����ɫ 8����ɫ 9:������
	TGuiVcaPolygon m_tPolygon;  
}TGuiDynPrvArea;

typedef struct
{
	int m_iChn;
}TGuiGetDynPrvAreaReq;

typedef struct
{
	int m_iChn;
	TGuiDynPrvArea m_tDynPrvArea[24];  //���֧��24������
}TGuiGetDynPrvAreaRsp;

typedef struct
{
	int m_iChn;
	TGuiDynPrvArea m_tDynPrvArea[24];
}TGuiSetDynPrvAreaReq;

typedef struct
{
	int m_iRetCode;       // 0��ɹ��������ʾʧ��
}TGuiSetDynPrvAreaRsp;

#define GUI_GET_CHN_ABILITY_REQ 	  1060   //��ȡͨ��֧�ֵ�����������
#define GUI_GET_CHN_ABILITY_RSP	  -1060   //��ȡͨ��֧�ֵ���������Ӧ

typedef enum
{
	CHN_DYNPRVAREA = 1,    //ͨ���Ƿ�֧�ֶ�̬��˽�ڵ�(�߶���)
	CHN_STATICPRVAREA,        //�Ƿ�֧����˽�ڵ�(IPC)
	CHN_LINKDBLIGHT = 3,    //�Ƿ�֧��˫��
	CHN_COLOR2GRAY,       //�Ƿ�֧�ֲ�ת�ڹ���
	CHN_DAYNIGHT,           //�Ƿ�֧����ҹģʽ(��Ĳ�ת�ڹ���)
}EChnAbilityEnum;

typedef struct
{
	int m_iType;
}TGuiGetChnAbilityReq;            //��ȡ������

typedef struct
{
	int m_iType;
	int m_iChn[GUI_DVR_CHN_CNT];      //��λ ��ʾ 32*32=1024��
}TGuiGetChnAbilityRsp;


// ===============ϵͳ�������=================
#define GUI_SET_SYS_TIME_OK        0
#define GUI_SET_SYS_TIME_ERR       1
// ����ϵͳʱ��
#define GUI_SET_SYS_TIME_REQ			1020
#define GUI_SET_SYS_TIME_RSP			-1020
#define GUI_GET_SYS_TIME_ZONE_REQ		1023
#define GUI_GET_SYS_TIME_ZONE_RSP		-1023
#define GUI_SET_SYS_TIME_ZONE_REQ		1024
#define GUI_SET_SYS_TIME_ZONE_RSP		-1024		

#define GUI_TIME_ZONE_DEFAULT			100

typedef struct
{
	int m_iTimeZone;					//ʱ����Ĭ��GUI_TIME_ZONE_DEFAULT����ʾ���ı䵱ǰʱ��
	int m_iYear;
	int m_iMon;
	int m_iDay;
	int m_iHour;
	int m_iMin;
	int m_iSec;
} TGuiSetSysTimeReq;

typedef struct
{
	int m_iRetCode;
} TGuiSetSysTimeRsp;

typedef struct
{
	int m_iTimeZone;   //����ʱ���Ӽ�100(����-8:00��Ӧ��ֵΪ-8+100=92, +8Ϊ8+100=108)
	//����45֮��ļӼ�10000(����+5:40,��Ӧ��ֵΪ10545, -4:30��Ϊ-0430+10000)
} TGuiGetSysTimeZoneRsp;

typedef struct
{
	int m_iTimeZone;
} TGuiSetSysTimeZoneReq;

typedef struct
{
	int m_iRetCode;
} TGuiSetSysTimeZoneRsp;

// ��ȡͨ����Ŀ������Ϣ
#define GUI_GET_DEV_NUM_REQ	1021
#define GUI_GET_DEV_NUM_RSP	-1021

enum
{
	VI_NO = 1,	//��Ƶ����·��
	VO_NO,		//��Ƶ����豸��
	VL_NO,		//��Ƶ����·��
	AI_NO,		//��Ƶ������
	AO_NO,		//��Ƶ�����
	AL_NO,		//��Ƶ����·��
	AIP_NO,		//��������˿���
	AOP_NO,		//��������˿���
	COM_NO,		//������Ŀ
	VC_NO,		//�ϳɱ���ͨ����
	VC_VO_NO,	//�ϳɱ�������VO��(0/1) 1-��0-��
	NETWORK_CARD_NO,  //��������
	SYNCPLAY_NO,    //ͬ���طŴ�����
	VI_NO_PSE,		//PSEͨ������
	POWER_PSE,		//PSE�ܹ���
};

typedef struct
{
	int m_iDevId;	//�豸����
} TGuiGetDevNumReq;

typedef struct
{
	int m_iDevId;	//�豸����
	int m_iNum;		//��Ŀ
} TGuiGetDevNumRsp;

// ��ȡ�����޸İ汾��
#define GUI_GET_CNF_VER_REQ	1022
#define GUI_GET_CNF_VER_RSP	-1022

// �������ÿ��ƥ�����޸ĺ󣬶����Ӧ�İ汾��+1
// ����ڱ�Ҫ��ʱ��ͨ����Э��ѯ�����õİ汾�ţ�
// �ڰ汾�ŷ����仯������²�ͨ����Ӧ��Э���ػ�ȡ��ز���
typedef enum
{
	GUI_VI_CNF_ID = 0,	//VI����
	GUI_VENC_CNF_ID,	//��������
	GUI_VREC_CNF_ID,	//¼������
	GUI_SYS_CNF_ID,	//ϵͳ��������
	GUI_USER_CNF_ID,		//�û�����
	GUI_PTZ_CNF_ID,		//�ƾ�����
} TGuiCnfMajorId;

typedef struct
{
	int m_iCnfId;		//����������
	int m_iCnfSubId;	//���������ͣ�����ϸ��
	int m_iChn;		//������Ӧ��ͨ����,0��ʾ����ͨ��
} TGuiGetCnfVerReq;

typedef struct
{
	int m_iVer;		//�汾��
} TGuiGetCnfVerRsp;

// PUD������ȡ
#define GUI_GET_PU_CNF_REQ		1025
#define GUI_GET_PU_CNF_RSP		-1025

typedef struct
{
	char    m_cManagerServerIp[16];    //������IP
	long    m_lManagerServerPort;      //�������˿�
	char    m_cHeartBeatServerIp[16];  //����������IP
	long    m_lHeartBeatPort;  			//�����������˿�
	char    m_cRegisterServerIP[16];	//ע�������IP
	long    m_lRegisterPort;			//ע��������˿�
	char    m_cEnableHeartBeat[16];		//ʹ������
	int     m_iHeartBeatPeriod;			//��������
	int     m_iRegisterTime;			//ע��ʱ��
	char    m_cVapPath[256];			//
	char    m_authServerIp[16];			//
	long    m_lauthServerPort;
	char    m_authUserName[16];
	char    m_authUserPassword[16];
	char    m_cputhreshold;
	char	m_memthreshold;
} TGuiPuCnf;

typedef struct
{
	int m_iRetCode;	//������
	TGuiPuCnf m_tCnf; //������Ϣ
} TGuiGetPuCnfRsp;

// PU��Ϣ��ȡ
#define GUI_SET_PU_CNF_REQ		1026
#define GUI_SET_PU_CNF_RSP		-1026

typedef struct
{
	TGuiPuCnf m_tCnf;
} TGuiSetPuCnfReq;

typedef struct
{
	int m_iRet;
} TGuiSetPuCnfRsp;

// ��ȡӲ��������
#define GUI_GET_HPM_CODE_REQ	1027
#define GUI_GET_HPM_CODE_RSP	-1027

typedef struct
{
	unsigned int m_uiCode[8];
} TGuiGetHpmCodeRsp;

//���û�ȡ�豸������Ϣ
#define GUI_DEV_COMMON_INFO_LEN  63
#define GUI_DEV_NFS_PATH_LEN  255 
#define GUI_DEV_IP_LEN 15
typedef struct
{
    char    m_cDeviceId[GUI_DEV_COMMON_INFO_LEN + 1];   //�豸id
    char    m_cDeviceName[GUI_DEV_COMMON_INFO_LEN + 1]; //�豸����
    char    m_cNFSIp[GUI_DEV_IP_LEN + 1];      			//�豸nfs����ip
    char  	m_cNFSPath[GUI_DEV_NFS_PATH_LEN + 1];  		//�豸nfs����·��
	int		m_iDevNo;			//�豸��ţ���������2008-12-03��DVR�����ֶ�
	int 	m_blNfsEnable;		//NFSʹ��
	int		m_iVspport;         //����ƽ̨ʹ��
	int		m_iVapport;			//����ƽ̨ʹ��
	char	m_cAccessnum[GUI_DEV_COMMON_INFO_LEN + 1];   //����ƽ̨ʹ��
}TGuiDevCommonInfoCnf;

#define GUI_GET_DEV_COMMON_INFO_CNF_REQ   1028  //��ȡ�豸commoninfo��Ϣ����
#define GUI_GET_DEV_COMMON_INFO_CNF_RSP	 -1028	//��ȡ�豸commoninfo��Ϣ��Ӧ

typedef struct
{
	TGuiDevCommonInfoCnf m_tCommonInfo;
}TGuiGetDevCommonInfoCnfRsp;


#define GUI_SET_DEV_COMMON_INFO_CNF_REQ   1029 //�����豸commoninfo��Ϣ����
#define GUI_SET_DEV_COMMON_INFO_CNF_RSP	  -1029 //�����豸commoninfo��Ϣ��Ӧ
typedef struct
{
	TGuiDevCommonInfoCnf m_tCommonInfo;
}TGuiSetDevCommonInfoCnfReq;  //�����豸commoninfo��Ϣ����

typedef struct
{
	int m_iRetCode;  //GUI_SET_OK -�ɹ���GUI_SET_ERR-ʧ��
}TGuiSetDevCommonInfoCnfRsp;  //�����豸commoninfo��Ϣ��Ӧ


// �Խ�����
#define GUI_TALK_CTRL_REQ		1030
#define GUI_TALK_CTRL_RSP		-1030

enum //�Խ���Ƶ���ݸ�ʽ
{
	GUI_AS_NORMAL = 0,
	GUI_AS_PCM,
};

typedef struct		//�Խ�����
{
	int m_iAct;		//������:1 start, 0: stop
	int m_iDevId;	//�Խ��豸���, Ԥ����Ĭ��ֵ1
	int m_iType;		//��������
	int m_iReserve;	//������	, Ĭ��0	
} TGuiTalkCtrlReq;

typedef struct
{
	int m_iRetCode;
} TGuiTalkCtrlRsp;

//IPC�Խ�
#define GUI_IPC_TALK_CTRL_REQ	1031   //�Խ�����
#define GUI_IPC_TALK_CTRL_RSP	-1031 
typedef struct
{
	int m_iChn;
	int m_iActId;	   //������:1 start, 0: stop
	int m_iType;		//��������
}TGuiIpcTalkCtrlReq;

typedef struct
{
	int m_iRetCode; //-1��ʾʧ��
} TGuiIpcTalkCtrlRsp;

#define GUI_GET_IPC_WHO_TALK_REQ	1032 //��ȡ���ĸ�����ͨ���Խ�
#define GUI_GET_IPC_WHO_TALK_RSP	-1032 //��ȡ���ĸ�ͨ���Խ���Ӧ

typedef struct
{
	int m_iChn;  //��ǰû��ͨ�����жԽ����򷵻�-1
}TGuiGetIpcWhoTalkRsp;

// �����������ԭ��Э�� 2011/01/10 dxl
#define GUI_SET_ENCODE_PARAM_REQ	1040
#define GUI_SET_ENCODE_PARAM_RSP	-1040
#define GUI_GET_ENCODE_PARAM_REQ	1041
#define GUI_GET_ENCODE_PARAM_RSP	-1041

#define GUI_SET_ENCODE_PARAM_OK    0
#define GUI_SET_ENCODE_PARAM_ERR   1

enum
{
	GUI_ENCODE_VSIZE = 1,			//��Ƶ��С
	GUI_ENCODE_FRAME_RATE,		//֡��
	GUI_ENCODE_BITS_RATE_TYPE,	//λ������
	GUI_ENCODE_BITS_RATE,			//����
	GUI_ENCODE_QUALITY,			//ͼ������
	GUI_ENCODE_TYPE,				//��������(��������/��Ƶ/��Ƶ)
	GUI_ENCODE_IFAME_RATE,		//I֡���
	GUI_ENCODE_AUDIO_TYPE,		//��Ƶ���뷽ʽ
};

typedef struct
{
	int m_iChn;				//ͨ����
	int m_iParamId;			//�������(������ö��ָ��)
	int m_iParamValue;		//����ֵ
} TGuiSetEncodeParamReq;

typedef struct
{
	int m_iRetCode;
} TGuiSetEncodeParamRsp;

typedef struct
{
	int m_iChn;
	int m_iParamId;
} TGuiGetEncodeParamReq;

typedef struct
{
	int m_iParamId;		//������ֵ��Ӧ��-1��ʽʧ��
	int m_iParamValue;	//����ֵ
} TGuiGetEncodeParamRsp;


// ͸��ͨ��/��������
#define GUI_TX_DATA_SEND_CMD			2000

enum	//��������
{
	GUI_TX_DATA_COM 		= 1, 	//��������
	GUI_TX_DATA_LOCAL,			//����������ҵ�͸��ͨ��(������ʹ�ã����Ƿǳ��ر�Ĺ���)
	GUI_TX_DATA_OTHER, 			//����͸��ͨ������(�ͻ���ͨ�����緢����ҵ�Э������)
	GUI_TX_DATA_TALK,				//�Խ�����
};

typedef struct
{
	int m_iType;	//��������
	int m_iSeq;	//���к�(���Ե�����һֱ���0)
	int m_iSrc;	//Դ���(�����Լ��ĸ�����)(Ĭ��ֵΪ0)
	int m_iDst;	//Ŀ���(��Ҫ�����ĸ�����)(Ĭ��ֵΪ0)
	int m_iR1;	//����(Ĭ��ֵ0)
	char m_cData[0];	 //����
} TGuiTxDataSendCmd;

//=========================��ҵǶ��ʽ��=========================
/*��ҵ��ʱUI���ں�ͨ�ŵ�Э����ṹ*/
#define GUI_TX_APP_DATA_SEND_REQ		2100             //UI �����ں������ں�ת�����������
#define GUI_TX_APP_DATA_SEND_RSP		-2100			//UI �����ں������ں�ת������һ�Ӧ

typedef struct
{
	int m_iSendSize;		//�ɹ����͵��ֽ���
} TGuiAppDataSendRsp;

#define GUI_TX_APP_DATA_RCV_REQ			2101			//UI���ں˷��������ֽ���
#define GUI_TX_APP_DATA_RCV_RSP			-2101			//UI���ں˷������ݵĴ�С��Ӧ

typedef struct
{
	int m_iRcvBufSize;
} TGuiAppDataRecvReq;

//Ƭͷ����
#define GUI_GET_VIDEO_HEADER_OSD_REQ	2180         //UI���ں˻�ȡƬͷ������Ϣ����
#define GUI_GET_VIDEO_HEADER_OSD_RSP    -2180        //UI���ں˻�ȡƬͷ������Ϣ��Ӧ

#define MAX_INQUEST_VIDEO_HEADER_LEN	384

typedef struct 
{
	int 		m_iOverlayTime;			//����ʱ��
	int			m_iX;					//Ƭͷ���Ӻ�����
	int			m_iY;					//Ƭͷ����������
	int 		m_isDispaly;			//�Ƿ���ʾ	//add by zxs 2012.9.5
	int 		m_iIedemo;				//�Ƿ���ͨ�������´���Ƭͷ
	char 		m_cHeaderMsg[MAX_INQUEST_VIDEO_HEADER_LEN + 1];	//Ƭͷ���ӵ����ݣ����384�ֽ�
}TGuiGetVideoHeaderOsdMsgRsp;

#define GUI_SET_VIDEO_HEADER_OSD_REQ	2181		//������ں�����Ƭͷ������Ϣ����
#define GUI_SET_VIDEO_HEADER_OSD_RSP	-2181		//������ں�����Ƭͷ������Ϣ��Ӧ

#define TGuiSetVideoHeaderOsdMsgReq TGuiGetVideoHeaderOsdMsgRsp

#define GUI_SET_VIDEO_HEADER_OSD_MSG_OK  	0   //���óɹ�
#define GUI_SET_VIDOE_HEADER_OSD_MSG_ERR	1	//����ʧ��
typedef struct
{
	int m_iRetCode;
}TGuiSetVideoHeaderOsdMsgRsp;

//-----------------------ATM------���ŵ���----------------------------------
#define GUI_GET_ATM_CARD_OSD_REQ	2010  //��ȡ���ŵ��Ӳ�������
#define GUI_GET_ATM_CARD_OSD_RSP	-2010 //��Ӧ

#define GUI_CARD_PROTOCOL_LEN			63
#define	GUI_CARD_PROTOCOL_VIA_COM		0
#define GUI_CARD_PROTOCOL_VIA_NET 		1

typedef struct
{
	int	m_iType;			//ͨ�ŷ�ʽ0:���� 1:UDP
	int m_iPortId; 				//����ID
	char m_strProtocolName[GUI_CARD_PROTOCOL_LEN + 1];	//Э�鳧������	
	char m_strSrcIp[GUI_IP_STR_LEN + 1];	//ATM  IP��ַ
	char m_strDstIp[GUI_IP_STR_LEN + 1];			//�豸IP��ַ
	int	m_iSrcPort;				//ATM�˿ں�
	int	m_iDstPort;			//�豸�˿ں�
}TGuiAtmMsg;    //ATM������Ϣ

typedef struct
{
	int m_iChn;             //���ӵ�ͨ���Ű�λ��ʾ 0x1��ʾ��1ͨ��,0x2��ʾ�ڶ�ͨ������������,0��ʾ����
	int m_iColor;			//������ɫ
	int	m_iXp;
	int	m_iYp;				//����λ��   m_iYp = -1��λ�õ��ӣ����ഫ����
	TGuiAtmMsg m_tAtmMsg;         //ATM ����
}TGuiGetAtmCardNoOsdRsp;

#define	GUI_SET_ATM_CARD_OSD_REQ	2011	//���ÿ��ŵ��Ӳ�������
#define GUI_SET_ATM_CARD_OSD_RSP 	-2011    //��Ӧ

#define TGuiSetAtmCardNoOsdReq	TGuiGetAtmCardNoOsdRsp  //���ÿ��ŵ��Ӳ�������

#define GUI_SET_ATM_CardNoOsd_MSG_OK		0		//���ò����ɹ�
#define GUI_SET_ATM_CardNoOsd_MSG_ERR		1		//���ò���ʧ��
typedef struct							//���ÿ��ŵ��Ӳ�����Ӧ
{
	int m_iRetCode;
} TGuiSetAtmCardNoOsdRsp;

#define GUI_GET_ATM_PROTOCOL_LIST_REQ   2012  	//��ȡATM֧�ֵ�Э���б�����
#define GUI_GET_ATM_PROTOCOL_LIST_RSP   -2012   //��ȡATM֧�ֵ�Э���б��Ӧ

#define GUI_ATM_PROTOCOL_NAME_LEN 		31
typedef struct 								//��ȡЭ���б��Ӧ
{
	int m_iProtocolCnt;							//Э������
} TGuiGetAtmProtocolListRsp;

typedef struct 								//Э���б���
{
	char m_strAtmProtocolName[GUI_ATM_PROTOCOL_NAME_LEN + 1]; //Э����
} TGuiAtmProtocolListItem;

//----------------------ATM----ץ������----------------------
#define GUI_GET_SNAPSHOT_CNF_REQ	2013
#define GUI_GET_SNAPSHOT_CNF_RSP	-2013

typedef struct
{
	int m_iSnaptype;	//ץ��ģʽ��0����ץ�� 1��ʱץ��
	int m_iQvalue;	//ͼƬ����
	int m_iTmval;	//ץ��ʱ���� 
	int m_iPicSize;   //ͼƬ��С -1��ʾ�Զ� ����ֵ��Ӧ��Ƶ��С
	int m_iSnapLink;	//ץ������ftp 0/1 ��λ���� 0x1��ftp 0x2��email��������չ
}TGuiSnapShotCnf;

typedef struct                     //��ȡץ�����ò��� ��ͨ���Ų�ѯ
{
	int m_iChn;       //ͨ����	
}TGuiGetSnapshotCnfReq;

typedef struct					 // ��ȡץ�����ò�����Ӧ
{
	int m_iChn;
	TGuiSnapShotCnf m_tSnapCnf;
}TGuiGetSnapshotCnfRsp;

#define GUI_SET_SNAPSHOT_CNF_REQ	2014
#define GUI_SET_SNAPSHOT_CNF_RSP	-2014

typedef struct
{
	int m_iChn;			//ͨ����
	TGuiSnapShotCnf m_tSnapCnf;
}TGuiSetSnapshotCnfReq;			//����ץ�Ĳ�������

#define GUI_SET_SNAPSHOT_CNF_OK		0		//���ò����ɹ�
#define GUI_SET_SNAPSHOT_CNF_ERR	1		//���ò���ʧ��

typedef struct							
{
	int m_iRetCode;
} TGuiSetSnapshotCnfRsp;			//����ץ�Ĳ�����Ӧ



/*******************������������**************************/
#define GUI_SET_ALARMER_CNF_OK   0		//�����������óɹ�
#define GUI_SET_ALARMER_CNF_ERR  1		//������������ʧ��

#define GUI_ALARM_IP_ADDRESS_LEN	31

typedef struct						//7601B��������
{
	int m_iIsUsed;		   	 		//�Ƿ�����
	int m_iSerialNo;	     		//���ں�
	int m_iProtocoType;	     		//Э������
	int m_iAddress;					//��ַ(0~255)
	int m_iAlarmInNum;	   	 		//����������
	int m_iAlarmOutNum;   	 		//���������
}TGuiSerialAlarmerMsg;


typedef struct						//���籨������
{
	int m_iIsUsed;					//����
	char m_strAddress[GUI_ALARM_IP_ADDRESS_LEN + 1];	//ip��ַ
	int m_iPort;		//�˿ں�
	int m_iAlarmInNum;	//����������
	int m_iAlarmOutNum;	//���������
}TGuiNetAlarmerMsg;

typedef struct									//��ȡ���籨��������������
{
	int m_iDevNo;									//�豸��
} TGuiGetNetAlarmerMsgReq;

typedef struct				
{
	int m_iDevNo;							
	TGuiNetAlarmerMsg	m_tNetAlarmMsg;			//������Ϣ
} TGuiGetNetAlarmerMsgRsp;						//��ȡ���籨��������Ϣ

typedef struct
{
	int m_iDevNo;
	TGuiNetAlarmerMsg m_tNetAlarmerMsg;			//������Ϣ
} TGuiSetNetAlarmerMsgReq;						//�������籨��������Ϣ����

typedef struct
{
	int m_iRetCode;    							 //���û�Ӧ 0��ʾ �ɹ�
}TGuiSetNetAlarmerMsgRsp;					     //�������籨��������Ӧ

typedef struct									//��ȡ���ڱ���������������
{
	int m_iDevNo;									//�豸��
} TGuiGetSerialAlarmerMsgReq;

typedef struct
{
	int m_iDevNo;								//�����룬0��ʾ�ɹ�
	TGuiSerialAlarmerMsg	m_tSeialAlarmerMsg;	//������Ϣ
}TGuiGetSerialAlarmerMsgRsp;					//��ȡ���ڱ���������Ϣ

typedef struct
{
	int m_iDevNo;
	TGuiSerialAlarmerMsg m_tSeialAlarmerMsg;
}TGuiSetSerialAlarmerMsgReq;

typedef struct
{
	int m_iRetCode;
}TGuiSetSerialAlarmerMsgRsp;

//�л���������
typedef struct
{
	int m_iRetCode;
}TGuiChangeLangRebootRsp;

//============================������Э�鲿��start==============================
//������
#define GUI_DEC_CLARITY_CMD_REQ			3000  //������͸����������
#define GUI_DEC_CLARITY_CMD_RSP 		-3000 //������͸�������Ӧ
#define GUI_DEC_CLARITY_DATA_LEN  		63
typedef struct
{
	int m_iDevId;								//�豸���dxl 2009/11/30
	int m_iVoChn;								//vo������(1-16)
	int m_iDataSize;							//���ݳ���
	char m_cData[0];							//������Ϣ
}TGuiDecClarityReq; //������͸����������

#define GUI_DEC_CLARITY_OK   0 //͸���ɹ�
#define GUI_DEC_CLARITY_ERR  1 //͸��ʧ��
typedef struct
{
	int m_iRetCode;
}TGuiDecClarityRsp; //������͸�������Ӧ


//����������logo
#define GUI_GET_DEC_LOGO_STAT_REQ     3001  //��ȡ����������logo��Ϣ����
#define GUI_GET_DEC_LOGO_STAT_RSP     -3001 //��ȡ����������logo��Ϣ��Ӧ

#define GUI_BMP_FILE_NAME_LEN 63
typedef struct
{
	int m_iDspEnable;		//�Ƿ����
	int m_iXp;			//������
	int m_iYp;			//������
	int m_iAlpha;			//͸����	
	int m_iTransparentColor;	//͸��ɫ
	char m_cBmpFileName[GUI_BMP_FILE_NAME_LEN + 1];	//BMPͼƬ�ļ���
}TGuiDecDspLogoMsgRsp;

#define GUI_GET_DEC_COM_ADDR_REQ    3002  //��ȡ���������ڵ�ַ����
#define GUI_GET_DEC_COM_ADDR_RSP    -3002 //��ȡ���������ڵ�ַ��Ӧ

typedef struct
{
	int m_iPortId;       //����uart��
}TGuiDecComAddrReq; //��ȡ��������ַ���Ժ�

typedef struct
{
	int m_iAddr;    	//�豸��ַ
}TGuiDecComAddrRsp; 	//��ȡ��������ַ��Ӧ

#define GUI_DEC_PREVIEW_PAGE_UP		3003			//Ԥ����һҳ
#define GUI_DEC_PREVIEW_PAGE_DOWN	3004			//Ԥ����һҳ
//��������һҳ����һҳ
typedef struct
{
	int m_iDevId;
	int m_iChn;
} TGuiDecoderPreviewPageUpReq;					//Ԥ���Ϸ�ҳ

typedef struct
{
	int m_iDevId;
	int m_iChn;
} TGuiDecoderPreviewPageDownReq;					//Ԥ���·�ҳ

#define GUI_DEC_PTZ_REMOTE_CODE			3005		//���������ɵ���̨����	

typedef struct									//��̨���Ʊ��ؿ�����
{
	int m_iDevId;	//�豸��							
	int m_iChn;	//ͨ����							
	int m_iCode;	//������ֵ						
	int m_iParam[4];	//��ز���
} TGuiDecPtzLocalCode;

#define GUI_DEC_SET_NVS_PARA_REQ    3006   //UI����NVS��������
#define GUI_DEC_SET_NVS_PARA_RSP    -3006  //UI����NVS������Ӧ

typedef struct
{
    char            	m_serName[36];		//����������(��ʱ����)
    char            	m_serIP[36];		//��������ַ��������IP��ַ��Ҳ������������
    char            	m_serProxy[16];		//�������ϼ�����
    unsigned char  	 	m_serChan;		//������ͨ��
    unsigned char		m_serStream;		//��������������,��������
    unsigned char		m_serNetmode;		//����Э��1��TCP��2��UDP��3���ಥ��
    unsigned char		m_bUseddns;		//ͨ����������������
    unsigned short		m_serPort;		//�������˿�
    char            	m_username[20];		//�û���
    char            	m_password[20];		//����
    int         		m_holdtime;		//����ʱ�䣬ȡֵ��Χ��5�D�D60��
    int         		m_bisView;
    int         		m_iAudioOut;		//��Ƶ�����Ƿ����
    char            	m_deviceType[16];   	//�豸����Э�飨��Ҫ���뵽��Э�飩
    unsigned char   	m_iAddress;         	//NVS�豸��ַ��ȡֵ��Χ��1-255��
    unsigned char   	m_iAudioEType;         	//��Ƶ��������
    unsigned char   	m_cSubStreamFlag;       //�豸�Ƿ��и�����0----��   1-----��   Ĭ����0
    char            	m_cEncrypt[20];		//����
    unsigned char		m_u8SerType;		//�豸����0Ϊtiandy��1Ϊonvif  �� 2Ϊpush��
} TDECNVSITEM; 

typedef struct
{
	int  m_iChan;   		//  ͨ��(������豸��m_iDevId)
	int  m_iPic;      		// ����(��ͨ���� m_iChn)
	TDECNVSITEM m_nvsItem;  //ǰ���豸��������Ϣ
}TGuiDecSetNvsParaReq;

typedef struct
{
	int  m_iRetCode;   //���÷���, 0-��ʾ�ɹ���1-��ʾʧ��
}TGuiDecSetNvsParaRsp;

#define GUI_SET_DEC_AUDIO_CTRL_REQ  3007    //���ý�������Ƶ��������
#define GUI_SET_DEC_AUDIO_CTRL_RSP  -3007   //���ý�������Ƶ���ƻ�Ӧ

#define GUI_DEC_AUDIO_ON   1
#define GUI_DEC_AUDIO_OFF  0

typedef struct
{
	int m_iChn;		//  ͨ��(������豸��m_iDevId)
	int m_iPic;		// ����(��ͨ���� m_iChn)
	int m_iCtrl;    // 1: GUI_DEC_AUDIO_ON ��  0:GUI_DEC_AUDIO_OFF ��
}TGuiSetDecAuidoCtrlReq;

typedef struct
{
	int m_iRetCode;
}TGuiSetDecAuidoCtrlRsp;


#define GUI_VIRTUAL_MATRIX_DATA_SEND_REQ  3010   //�������������ݷ��͸��ں�����
#define GUI_VIRTUAL_MATRIX_DATA_SEND_RSP  -3010 //�������������ݷ��͸��ں˻�Ӧ

#define GUI_VIRTUAL_MATRIX_DATA_LEN  255
typedef struct
{
	int m_iDataSize;   							   //���ݳ���
	char m_cData[GUI_VIRTUAL_MATRIX_DATA_LEN + 1]; //������Ϣ
}TGuiVirtualMatrixDataSendReq;

#define GUI_VIRTUAL_MATRIX_DATA_SEND_OK  0 //���ͳɹ�
#define GUI_VIRTUAL_MATRIX_DATA_SEND_ERR  1 //����ʧ��

typedef struct
{
	int m_iRetCode;
}TGuiVirtualMatrixDataSendRsp;


//������Э�鲿��end

//*********************Miracle��Ŀ����Э��*********************//
//�ֶ���������
#define GUI_GET_MANUAL_ALARM_LST_REQ  550    //��ȡ�ֶ������б�����
#define GUI_GET_MANUAL_ALARM_LST_RSP  -550   //��ȡ�ֶ������б��Ӧ

#define GUI_MANUAL_ALARM_NAME    31
typedef struct
{
	int m_iAlarmOutChn; //�ֶ����������˿ں�
}TGuiManualGetAlarmOutReq;

typedef struct
{
	int m_iStat; //�ֶ���������״̬ 0 
	char m_cAlarmOutName[GUI_MANUAL_ALARM_NAME + 1];//��������
	char m_cAlarmAddr[GUI_MANUAL_ALARM_NAME + 1];   //ģ��ͨ��Ϊ"����",����ͨ��Ϊ"IP��ַ"
}TGuiManualAlarmOutMsg;

typedef struct
{
	int m_iAlarmOutChn; //�ֶ����������˿ں�
	TGuiManualAlarmOutMsg m_tManAlarmOut;
}TGuiManualGetAlarmOutRsp;   //�ֶ�����������Ӧ

#define GUI_SET_MANUAL_ALARM_REQ           551     //�ֶ����ñ�������
#define GUI_SET_MANUAL_ALARM_RSP           -551    //�����ֶ�������Ӧ

typedef struct
{
	int m_iAlarmOutChn;
	int m_iStat; // 1-������0 - ������
}TGuiSetManualAlarmOutReq;

typedef struct
{
	int m_iRetCode;
}TGuiSetManulAlarmOutRsp;

/********************************************************************/
//��Ƶ��������

#define GUI_VIDEO_CLIP_DISK_NOSAPCE  -3  //������Ƶ����Ƭ�ϴ��̿ռ䲻��
#define GUI_VIDEO_CLIP_GENERIC_ERR    -1 //����һ���Դ���

#define GUI_DO_VIDEO_CLIP_REQ    560  //��Ƶ������ʼ����
#define GUI_DO_VIDEO_CLIP_RSP    -560  //��Ƶ������ʼ��Ӧ

#define GUI_VIDEO_CLIP_SAVE_PATH_LEN   127
typedef struct
{
	int m_iChn; //��Ҫ������ͨ��
	int m_iStartTime; //��ʼʱ��
	int m_iEndTime;   //����ʱ��
	char m_cPath[GUI_VIDEO_CLIP_SAVE_PATH_LEN + 1];  //����·��
}TGuiDoVideoClipReq;
typedef struct
{
	int m_iClipID;  //����ID  �ݴ�ID ��ѯ������� 
}TGuiDoVideoClipRsp;

#define GUI_VIDEO_CLIP_QUERY_PRO_REQ   561 //��Ƶ���������������
#define GUI_VIDEO_CLIP_QUERY_PRO_RSP   -561  //��Ƶ ����������Ȼ�Ӧ
typedef struct
{
	int m_iClipID;
}TGuiVideoClipQueryProReq;

typedef struct
{
	int m_iPro; //�ٷֱ�
}TGuiVideoClipQueryProRsp;

//¼���ļ����ݡ���������һ���ļ��Ĺ�������ֹ����
#define GUI_VIDEO_BACKUP_PRO_STOP_REQ   562 //��Ƶ����һ���ļ��Ĺ�������ֹ����
#define GUI_VIDEO_BACKUP_PRO_STOP_RSP   -562 //��Ƶ����һ���ļ��Ĺ�������ֹ��Ӧ
typedef struct
{
	int m_iRetCode; //0 �ɹ���1ʧ��
}TGuiVideoBackupProStopRsp;

#define GUI_GET_CLIPFILE_MSG_REQ 		563	//��ȡ¼�������С����
#define GUI_GET_CLIPFILE_MSG_RSP 		-563	//��ȡ¼�������С��Ӧ

typedef struct						//��ȡ¼�������С����
{
	int m_iChn;					//ͨ��
	int m_iStartTime;				//��ʼ����ʱ��
	int m_iEndTime;				//��������ʱ��
} TGuiGetClipFileMsgReq;

typedef struct						//��ȡ¼�������С��Ӧ
{
	TGuiGetClipFileMsgReq m_tGuiClipFileMsg;
	unsigned int m_uiFileSize;				//�ļ���С
}TGuiGetClipFileMsgRsp;


//���̼�����޸�����
#define GUI_GET_DISK_CHECK_REQ      566         //��ȡ���̶ϵ�������
#define GUI_GET_DISK_CHECK_RSP      -566        //��ȡ���̶ϵ��������Ӧ
#define GUI_CHECK_ALL_DISK   1    //���
#define GUI_UNCHECK_ALL_DISK  0   //�����
#define GUI_REPAIR_DISK   1       //�޸�����
#define GUI_UNREPAIR_DISK 0       //���޸�����
typedef struct
{
	int m_iCheckAllDisk;
	int m_iRepairDisk;   
}GuiGetDiskCheckRsp;

#define GUI_SET_DISK_CHECK_REQ       567        //���ô��̶ϵ�������
#define GUI_SET_DISK_CHECK_RSP       -567        //���ô��̶ϵ��������Ӧ
typedef struct
{
	int m_iCheckAllDisk;
	int m_iRepairDisk;
}TGuiSetDiskCheckReq; //���ô��̶ϵ�������

typedef struct
{
	int m_iRetCode;
}TGuiSetDiskCheckRsp;  //���ô��̶ϵ��������Ӧ

//====================����ģʽ==============================
#define GUI_GET_STORAGE_MODE_REQ   	 	568  //��ȡ�洢ģʽ����(��������   )
#define GUI_GET_STORAGE_MODE_RSP 		-568 //��ȡ�洢ģʽ��Ӧ
#define GUI_SET_STORAGE_MODE_REQ		569  //���ô洢ģʽ����
#define GUI_SET_STORAGE_MODE_RSP		-569 //���ô洢ģʽ��Ӧ

enum
{
	DISK_GROUP = 1,   //����
	DISK_QUOTA,      //���
}; //�洢ģʽ

typedef struct
{
	int m_iType;  //�洢ģʽ
}TGuiGetStorageModeRsp;   //��ȡ�洢ģʽ��Ӧ(��������   )

typedef struct
{
	int m_iType;
} TGuiSetStorageModeReq; //���ô洢ģʽ����

typedef struct
{
	int m_iRetCode;
} TGuiSetStorageModeRsp;//���ô洢ģʽ��Ӧ

//==================��������===============================
#define GUI_GET_DISK_GROUP_REQ      570 	//��ȡ������Ϣ����
#define GUI_GET_DISK_GROUP_RSP		-570	//��ȡ������Ϣ��Ӧ
#define GUI_SET_DISK_GROUP_REQ		571		//����������Ϣ����
#define GUI_SET_DISK_GROUP_RSP		-571	//����������Ϣ��Ӧ

#define GUI_MAX_DISK_GROUP_CNT		8		//�����������

typedef struct
{
	unsigned int m_iDiskLst[GUI_MAX_DISK_GROUP_CNT][8];     //Ӳ���б�
	unsigned int m_iChannelLst[GUI_MAX_DISK_GROUP_CNT][8];   //ͨ���б�
} TGuiGetDiskGroupRsp; //��ȡ������Ϣ��Ӧ

typedef TGuiGetDiskGroupRsp TGuiSetDiskGroupReq;  //����������Ϣ����

#define GUI_SET_DISK_GROUP_OK   0  //���óɹ�
#define GUI_SET_DISK_GROUP_ERR  1  //����ʧ��
typedef struct
{
	int m_iRetCode;
} TGuiSetDiskGroupRsp;  //����������Ϣ��Ӧ

//==================�������==============================
#define GUI_GET_DISK_QUOTA_REQ    572	//��ȡ�����Ϣ����
#define GUI_GET_DISK_QUOTA_RSP    -572	//��ȡ�����Ϣ��Ӧ
#define GUI_SET_DISK_QUOTA_REQ	  573	//���������Ϣ����
#define GUI_SET_DISK_QUOTA_RSP    -573  //���������Ϣ��Ӧ

typedef struct
{
	int m_iChn;  //ͨ����
}TGuiGetDiskQuotaReq;      //��ȡ�����Ϣ����

typedef struct
{
	int m_iChn;
	unsigned int m_iTotalCap;  //���д��̵�������(��λ:G)
	unsigned int m_iRecUsed;   //����¼�����(��λ: M)
	unsigned int m_iPicUsed;    //����ͼƬ���(��λ: M)
	unsigned int m_iRecQuota;  //¼�����(��λ: G)
	unsigned int m_iPicQuota;    //ͼƬ���(��λ: G)
} TGuiGetDiskQuotaRsp;		//��ȡ�����Ϣ��Ӧ

typedef TGuiGetDiskQuotaRsp TGuiSetDiskQuotaReq;

typedef struct
{
	int  m_iRetCode;   //0��ɹ���1��ʧ��
}TGuiSetDiskQuotaRsp;		//���������Ϣ��Ӧ

//======================IPSAN=============
#define GUI_GET_IPSAN_MSG_REQ		574		//��ȡIPSAN��Ϣ����
#define GUI_GET_IPSAN_MSG_RSP		-574	//��ȡIPSAN��Ϣ��Ӧ
typedef struct
{
	int m_iIPSANId;	//IPSAN���(1-8)
}TGuiGetIPSANMsgReq;

typedef struct
{
	int m_iIPSANId;	//IPSAN���(1-8)��0Ԥ��
	int m_iPort;			//�˿ںţ�Ĭ��Ԥ��
	char m_strIPSANIp[GUI_PUBLIC_LEN_63 + 1];
	char m_strIPSANPath[GUI_PUBLIC_LEN_63 + 1]; 
	char m_strUserName[GUI_PUBLIC_LEN_31+ 1];
	char m_strPasswd[GUI_PUBLIC_LEN_31+ 1];
} TGuiGetIPSANMsgRsp;

#define GUI_SET_IPSAN_MSG_REQ		575//����IPSAN��Ϣ����
#define GUI_SET_IPSAN_MSG_RSP		-575//����IPSAN��Ϣ��Ӧ
typedef   TGuiGetIPSANMsgRsp TGuiSetIPSANMsgReq;

typedef struct
{
	int m_iRetCode;   //0��ɹ�,1��ʧ��
}TGuiSetIPSANMsgRsp;
  
#define GUI_DEL_IPSAN_REQ		577     //ɾ��ipsan����
#define GUI_DEL_IPSAN_RSP		-577   //ɾ��ipsan��Ӧ
typedef TGuiGetIPSANMsgRsp  TGuiDeleteIpSanReq;
typedef TGuiSetIPSANMsgRsp   TGuiDeleteIpSanRsp;


#define GUI_SEARCH_IPSAN_TARGET_REQ		576//����IPSAN��Ϣ����
#define GUI_SEARCH_IPSAN_TARGET_RSP		-576//����IPSAN��Ϣ��Ӧ
typedef struct
{
	int m_iPort;
	char m_strIPSanIP[GUI_PUBLIC_LEN_63 + 1];	
	char m_strUserName[GUI_PUBLIC_LEN_31 + 1];
	char m_strPasswd[GUI_PUBLIC_LEN_31 + 1];
}TGuiSearchIpSanTargetReq;

typedef struct
{
	int m_iTargetCnt;     //�ȷ�������,Ȼ��������ȡ
}TGuiSearchIpSanRsp;

typedef struct
{
	char m_strIPSanIP[GUI_PUBLIC_LEN_63 + 1];	
	char m_strIpSanTarget[GUI_PUBLIC_LEN_63 + 1];
}TGuiSearchIpSanTargetMsg;

#define GUI_SET_UNLOADDISK_REQ			578   //�����Ȳ������
#define GUI_SET_UNLOADDISK_RSP			-578 //�����Ȳ�λ�Ӧ

typedef struct
{
	int m_iAction;        // 1- ���� 2-����
	int m_iDiskId;       //���̱��
}TGuiSetUnloadDiskReq;

typedef struct
{
	int m_iRetCode;   //0��ɹ� �����ʧ��
}TGuiSetUnloadDiskRsp;


//==================�ȱ�����================
#define GUI_GET_DEV_WORKMODE_REQ     2040  //��ȡ�豸����ģʽ����
#define GUI_GET_DEV_WORKMODE_RSP 	-2040  //��ȡ�豸����ģʽ��Ӧ
enum
{
	GUI_DEV_NORMAL_MODE = 0,   //��ͨģʽ
	GUI_DEV_HOTSPARE_MODE,     //�ȱ�ģʽ
};

typedef struct
{
	int m_iDevWorkMode;
}TGuiGetDevWorkModeRsp;

#define GUI_SET_DEV_WORKMODE_REQ    2041  //�����豸����ģʽ����
#define GUI_SET_DEV_WORKMODE_RSP    -2041 //�����豸����ģʽ��Ӧ
typedef TGuiGetDevWorkModeRsp TGuiSetDevWorkModeReq;
typedef struct
{
	int m_iRetCode;	 //0��ɹ�,1��ʧ��
}TGuiSetDevWorkModeRsp;

//�������ϵ�����
#define GUI_GET_HOT_SPARE_ENABLE_REQ       2042    //��ȡ�ȱ�ʹ������
#define GUI_GET_HOT_SPARE_ENABLE_RSP		-2042  //��ȡ�ȱ�ʹ�ܻ�Ӧ��
typedef struct
{
	int m_iHotSpareEnable ;					//�Ƿ������ȱ�
}TGuiGetHotSpareEnabelRsp;

#define GUI_SET_HOT_SPARE_ENABLE_REQ       2043    //�����ȱ�ʹ������
#define GUI_SET_HOT_SPARE_ENABLE_RSP		-2043  //�����ȱ�ʹ�ܻ�Ӧ��
typedef TGuiGetHotSpareEnabelRsp TGuiSetHotSpareEnableReq;
typedef struct
{
	int m_iRetCode;	 //0��ɹ�,1��ʧ��
}TGuiSetHotSpareEnableRsp;

//���������������ȱ���
#define GUI_HOTSPARE_SEARCH_START_REQ      2044  //��������ʼ
#define GUI_HOTSPARE_SEARCH_START_RSP	  -2044  //���������Ӧ
typedef struct		//��������ͨ������
{
	int m_iDevType;	
} TGuiSearchHotSpareReq;

typedef struct
{
	int m_iSid;	//������ѯ�ţ��Ժ󰴴˺Ż�ȡ���������-1��ʧ��
} TGuiSearchHotSpareRsp;


#define GUI_SEARCH_DEVICE_CNF_REQ		2045//��ȡ������/�ȱ�����������
#define GUI_SEARCH_DEVICE_CNF_RSP		       -2045//��ȡ������/�ȱ������û�Ӧ

typedef struct
{
	int m_iDevType;       //�豸���� 0��ʾ��������1��ʾ�ȱ���
	int m_iSid;               //ʹ��TGuiSearchHotSpareRsp���ص�m_iSid
}TGuiGetDevCntReq;

typedef struct
{
	int m_iDevCnt;
}TGuiGetDevCntRsp;   //�ȷ��ظ����������������豸ip��ַ

typedef struct
{
	char m_strDevIp[GUI_PUBLIC_LEN_63 + 1];
}TGuiDevMsg;

#define GUI_ADD_DEVICE_REQ      2046   //����ȱ������߹���������
#define GUI_ADD_DEVICE_RSP	      -2046 //����ȱ������߹�������Ӧ

typedef struct
{
	int m_iDevType;      //�豸���� 0��ʾ��������1��ʾ�ȱ���          
	char m_strDevIp[GUI_PUBLIC_LEN_63 + 1];
	char m_strPasswd[GUI_PUBLIC_LEN_31 + 1];
}TGuiAddDeviceReq;

typedef struct
{
	int m_iRetCode;	 //0��ɹ�,1��ʧ��
}TGuiAddDeviceRsp;

//�ȱ�������˶��ٹ�����
#define GUI_GET_HOT_SPARE_CNF_REQ		2047//��ȡ�ȱ���������
#define GUI_GET_HOT_SPARE_CNF_RSP		-2047//��ȡ�ȱ����û�Ӧ
typedef struct
{
	int m_iHotSpareDevType;       //�豸���� 0��ʾ��������1��ʾ�ȱ���
}TGuiGetHotSpareDevCntReq;

typedef struct
{
	int m_iHotSpareDevCnt;
}TGuiGetHotSpareDevCntRsp;

typedef  struct
{
	char m_strHotSpareIp[GUI_PUBLIC_LEN_63 + 1];
}TGuiHotSpareDevMsg;

#define GUI_GET_DEV_STAT_REQ 		2048 //��ȡ�ȱ������߹���������״̬����
#define GUI_GET_DEV_STAT_RSP 		-2048 //��ȡ�ȱ������߹���������״̬��Ӧ

enum
{
	GUI_DEV_ONLINE = 0,       //�豸����
	GUI_DEV_OFFLINE,           //�豸������
};

enum
{
	GUI_WORK_DEV_STAT_NORMAL = 0,//�����ȱ�
	GUI_WORK_DEV_STAT_BACKUP,//���ڱ���
	GUI_WORK_DEV_STAT_SYNCING ,//����ͬ��
	GUI_WORK_DEV_STAT_OFFLINE,   //���ߣ�����ʾ�����ȱ�
};  //���ȱ�������ʾ������״̬

enum
{
	GUI_HOT_BACKUP_STAT_LINK_FAILED = 0,   //����ʧ��
	GUI_HOT_BACKUP_STAT_LINK_SUCCED ,	  //���ӳɹ�
	GUI_HOT_BACKUP_STAT_SYNCING,			//����ͬ��
};//�ڹ���������ʾ���ȱ���״̬

typedef struct
{
	int m_iDevType;
	char m_strDevIp[GUI_PUBLIC_LEN_63 + 1];
}TGuiGetDeviceStatReq;

typedef struct
{
	int m_iDevType;
	char m_strDevIp[GUI_PUBLIC_LEN_63 + 1];
	int m_iStat;
	int m_iStatPara;    //ͬ���ٷֱ�(0-100)
}TGuiGetDeviceStatRsp;

#define GUI_DEL_DEV_REQ   	2049   //ɾ���豸�����߹���������
#define GUI_DEL_DEV_RSP	-2049  //ɾ���豸�����߹�������Ӧ
typedef struct
{
	int m_iDevType;
	char m_strDevIp[GUI_PUBLIC_LEN_63 + 1];
}TGuiDelDevReq;

typedef struct
{
	int m_iRetCode;  //0��ɹ�,1��ʧ��
}TGuiDelDevRsp;


//=====================Raid���==================
#define GUI_GET_RAID_ENABLE_REQ    2060  //��ȡraidʹ������
#define GUI_GET_RAID_ENABLE_RSP     -2060 //��ȡraidʹ�ܻ�Ӧ

typedef  struct
{
	int m_iRaidEnable;     // 1��ʾʹ��
}TGuiGetRaidEnableRsp;

#define GUI_SET_RAID_ENABLE_REQ      2061     //����raidʹ������
#define GUI_SET_RAID_ENABLE_RSP	 -2061	//����raidʹ�ܻ�Ӧ
typedef struct
{
	int m_iRaidEnable;
}TGuiSetRaidEnableReq;

typedef struct
{
	int m_iRetCode;
}TGuiSetRaidEnableRsp;

#define GUI_GET_RAID_SATA_LIST_REQ 	  2062    //��ȡ�����������
#define GUI_GET_RAID_SATA_LIST_RSP	 -2062	//��ȡ������̻�Ӧ
typedef struct
{
	int m_iSataDiskCnt;
}TGuiGetRaidSataListRsp;  //�ȷ��ش��̸���������������TGuiSataDiskMsg��Ϣ


enum
{
	GUI_DISK_NOR_TYPE = 0,   		//��ͨ��
	GUI_DISK_RAID_BACKUP_TYPE, 	 //�����ȱ�
	GUI_DSIK_GLOBAL_BACKUP_TYPE,    //ȫ���ȱ�
	GUI_DISK_RAID_TYPE,			//������
	GUI_INVALID_DISK_RAID_TYPE,    //��Ч������
	GUI_FAIL_DISK_TYPE,			//������
};

enum
{
	GUI_DISK_SMART_GOOD = 0,    //����
	GUI_DISK_SMART_BAD,         //�쳣
	GUI_DISK_SMART_LOWHEALTH,   //����Ԥ��
};

typedef struct
{
	int m_iDiskId;
	int m_iDiskType;
	int m_iDiskStat;
	int m_iDiskSize; //��λΪM
	char m_strRaidName[GUI_PUBLIC_LEN_31 + 1];
	char m_strDiskModel[GUI_PUBLIC_LEN_31 + 1];
}TGuiSataDiskMsg;

#define GUI_SET_DISK_BACKUP_REQ    2063      //���������ȱ�����
#define GUI_SET_DISK_BACKUP_RSP	-2063	//���������ȱ���Ӧ
typedef struct
{
	int m_iDiskId;
	int m_iHotSpareType;   //�ȱ�����ȫ�ֻ�������
	char m_strRaidName[GUI_PUBLIC_LEN_31 + 1];  //���Ϊȫ���ȱ������ַ���Ϊ��
}TGuiSetDiskBackupTypeReq;

typedef struct
{
	int m_iRetCode;
}TGuiSetDiskBackupTypeRsp;

//raid����ö��
enum
{
	GUI_RAID_JBOD = 100,
	GUI_RAID_RIAD0 = 0,
	GUI_RAID_RIAD1 = 1,
	GUI_RIAD_RAID5 = 5,
	GUI_RAID_RAID10 = 10,
};

#define GUI_CREATE_RAID_REQ   		2064   //����raid����
#define GUI_CREATE_RAID_RSP  		-2064  //����raid��Ӧ
typedef  struct
{
	int m_iRaidType;
	int m_iDisklist; //��λ��ʾ (0~31��ʾ32��Ӳ��)
	int m_iDisklist1; //����
	char m_strRaidName[GUI_PUBLIC_LEN_31 + 1];
}TGuiRaidBasicMsg;

typedef struct
{	
	TGuiRaidBasicMsg m_tRaidMsg;
}TGuiCreateRaidReq; 

typedef struct
{	
	int m_iRetCode;     //0��ɹ�1��ʧ��
}TGuiCreateRaidRsp;

#define GUI_REBUILD_RAID_REQ   		2065   //�ؽ�raid����
#define GUI_REBUILD_RAID_RSP    	-2065 //�ؽ�raid��Ӧ

typedef struct
{	
	TGuiRaidBasicMsg m_tRaidMsg;
}TGuiRebuildRaidReq; 

typedef struct
{
	int m_iRetCode; 	//0��ɹ�1��ʧ��
}TGuiRebuildRaidRsp;

#define GUI_DEL_RAID_REQ   			2066//ɾ��raid����
#define GUI_DEL_RAID_RSP  			-2066//ɾ��raid��Ӧ

typedef struct
{	
	char m_strRaidName[GUI_PUBLIC_LEN_31 + 1];
}TGuiDelRaidReq; 

typedef struct
{
	int m_iRetCode; 	//0��ɹ�1��ʧ��
}TGuiDelRaidRsp;

#define GUI_GET_RAID_MSG_REQ   2067  //��ȡraid��Ϣ����
#define GUI_GET_RAID_MSG_RSP   -2067 //��ȡraid��Ϣ��Ӧ
typedef struct
{
	int m_iRaidCnt;     //���ظ������ٸ�TGuiRaidMsg��Ϣ
}TGuiGetRaidMsgRsp;  

typedef enum
{
	GUI_RAID_STAT_NORMAL =1,		//����
	GUI_RAID_STAT_DOWNGRADE,     //����
	GUI_RAID_STAT_DAMAGE,		//��
}TGuiRaidStatus;

typedef enum
{
	GUI_RAID_TASK_NONE = 1,      	//��
	GUI_RAID_TASK_INITING,       	//���ڳ�ʼ��
	GUI_RAID_TASK_REBUILDING,	//�����ؽ�
}TGuiRaidTaskType;

typedef struct
{
	int m_iRaidId;
	int m_iRaidAllSize;
	int m_iRiadUseAbleSize;
	int m_iDiskList;
	int m_iDiskList1;
	int m_iDiskBackUpId;  //-1��ʾû���ȱ���
	int m_iRaidStat;   //����״̬ TGuiRaidStatus
	int m_iRaidType;
	int m_iRaidTask;  //��������TGuiRaidTaskType
	int m_iRaidTaskPara[4]; //Ԥ�����ٷֱȣ�ʣ��ʱ���
	char m_strRaidName[GUI_PUBLIC_LEN_31 + 1];
}TGuiRaidMsg;

//===================�������=============
#define GUI_CREATE_VIRTUALDISK_REQ       2070  //���������������
#define GUI_CREATE_VIRTUALDISK_RSP	   -2070	//����������̻���
enum
{
	GUI_RAID_VD_INIT_FG = 1,   //ǰ̨��ʼ��
	GUI_RAID_VD_INIT_BG,	    //��̨��ʼ��
	GUI_RAID_VD_INIT_FAST,    //���ٳ�ʼ��
};

typedef struct
{
	int m_iVdSize;
	int m_iInitType;
	char m_strVdName[GUI_PUBLIC_LEN_31+1];
	char m_strRaidName[GUI_PUBLIC_LEN_31+1];
}TGuiRaidCreateVdReq;

typedef struct
{
	int m_iRetCode;
}TGuiRaidCreateVdRsp;

#define GUI_GET_VD_MSG_REQ   	2071//��ȡ���������Ϣ����
#define GUI_GET_VD_MSG_RSP   	-2071//��ȡ���������Ϣ��Ӧ

 typedef  enum
{
	GUI_VD_STAT_NORMAL = 1,   //����
	GUI_VD_STAT_DEGRADE,      //����
	GUI_VD_STAT_OFFLINE,        // ����
}TGuiVdStatType;

typedef enum
{
	GUI_VD_TASK_NONE = 1,    //��
	GUI_VD_TASK_INITING,     //���ڳ�ʼ��
	GUI_VD_TASK_FIXING,     //�����޸�
}TGuiVdTaskType;
typedef struct
{
	int m_iRaidVdCnt;
}TGuiGetVdMsgRsp;

typedef struct
{
	int m_iRaidVdSize;
	int  m_iVdStat;       //�������״̬TGuiVdStatType
	int m_iRaidtype;    //�������������raid����
	int m_iVdTask;      //���������������TGuiVdTaskType
	int m_iVdTaskPara[4];  //����Ԥ�������������ٷֱȣ�ʣ��ʱ���
	char m_strVdName[GUI_PUBLIC_LEN_31 + 1];
	char m_strRaidName[GUI_PUBLIC_LEN_31 + 1];
}TGuiVdMsg;

#define GUI_FIX_VD_REQ   	2072  //�޸������������
#define GUI_FIX_VD_RSP  	-2072  //�޸�������̻�Ӧ

typedef struct
{
	char m_strVdName[GUI_PUBLIC_LEN_31 + 1];
}TGuiFixVdReq;

typedef struct
{
	int m_iRetCode;
}TGuiFixVdRsp;

#define GUI_DEL_VD_REQ   	2073 //ɾ�������������
#define GUI_DEL_VD_RSP		-2073 //ɾ��������̻�Ӧ

typedef struct
{
	char m_strVdName[GUI_PUBLIC_LEN_31 + 1];
}TGuiDelVdReq;

typedef struct
{
	int m_iRetCode;
}TGuiDelVdRsp;


//==================/*�������add  by quxinfeng 2012.2.7*/============
#define GUI_SET_MIXAUDIO_REQ       20000
#define GUI_SET_MIXAUDIO_RSP 		-20000 	
#define GUI_GET_MIXAUDIO_REQ       20001
#define GUI_GET_MIXAUDIO_RSP 		-20001
#define MIXAUDIO_OPERATER_OK     	0
#define GUI_MAX_AUDIO_SOURCE  		4
typedef struct
{
	int m_iChn;		
}TGuiGetMixAudioReq;

typedef struct
{	 int m_iChn;
	 int m_iMixAudioEnable;//�Ƿ����
	 int m_iMixAudioSourceChnNo[GUI_MAX_AUDIO_SOURCE];//��Դ
}TGuiGetMixAudioRsp;

#define TGuiSetMixAudioReq   TGuiGetMixAudioRsp

typedef struct
{
	int m_iRetCode;		// 0��ʾ�ɹ�
}TGuiSetMixAudioRsp;

#define GUI_SET_AUDIO_THRESHOLD_REQ   20002  //������Ƶ��ֵ����
#define GUI_SET_AUDIO_THRESHOLD_RSP   -20002  //������Ƶ��ֵ��Ӧ
typedef struct
{
	int m_iChn;
	int m_iThreshold;	 //��ֵ
}TGuiSetAudioThresholdReq;

typedef struct
{
	int m_iRetCode;
}TGuiSetAudioThresholdRsp; 

#define GUI_GET_AUDIO_THRESHOLD_REQ   20003  //��ȡ��Ƶ��ֵ����
#define GUI_GET_AUDIO_THRESHOLD_RSP   -20003  //��ȡ��Ƶ��ֵ��Ӧ
typedef struct
{
	int m_iChn;
}TGuiGetAudioThresholdReq;

typedef struct
{
	int m_iChn;
	int m_iThreshold;  //��ֵ
}TGuiGetAudioThresholdRsp;
//****************************************//
//����������������

typedef struct
{
	int m_iStructLenth;//�ṹ�峤��,��16λΪ�����ٶ�
	/*0--1/25��1--1/50��2--1/60��3--1/80��4--1/100��5--1/120��6--1/125��7--1/150��8--1/180��9--1/200��10--1/250��
	11--1/500��12--1/1000��13--1/2000��14--1/4000��15--1/10000��16--1/30��17-1/100000��18-1/15��19-1/12��20-1/10��
	21-1/8��22-1/6��23-1/5��24-1/4��25-1/3��26-1/2��27-1��*/
  int m_iExposureMode;//�ع�ģʽ:0,�ֶ�;1,�Զ�
  int m_iExpPriority;//�ع����:0����������;1��֡������
  int m_iExpCompensiton;//Ŀ������0-255
  int m_iExpMaxTime;//����ع�ʱ�䣬��λus
  int m_iExpMinTime;//��С�ع�ʱ�䣬��λus
	int m_iExpMaxGain;//������棬��λ 0.01������Ӧ����Э���������0~255
  int m_iExpMinGain;//��С���棬��λ 0.01��
  TGuiArea m_tExpArray;//�ع�����
  int m_iIrisMode;//��Ȧģʽ:0���ֶ���1���Զ�
	int m_iWBMode;//��ƽ��ģʽ:0���ֶ�;1,�Զ��� ��16λ������Ӧģʽ�µ� ��������
	/*�Զ�ģʽ��0-Ĭ���Զ�1-����ģʽ2-�չ��ģʽ3-ů���ģʽ4-�׳��ģʽ5-��Ȼ��ģʽ
	6-������ƽ�� �ֶ�ģʽ��0-���Զ� 1-���ֶ�*/
  int m_iWBRGain;//�ֶ�ģʽ�µĺ�����:0-255
  int m_iWBBGain;//�ֶ�ģʽ�µ�������:0-255
	int m_iWDRMode;//��̬ģʽ:1���򿪣�2�ر� ��	��16λ��ʾ�Զ�(1)���ֶ�(0)����16λ��ʾ����״̬����(1)�ر�(0)������ǿ(2)
	int m_iWDRLevel;//��̬���𣨱�������Χ��0-255
  int m_iBLCMode;//���ⲹ��ģʽ:1���򿪣�2�ر�
  int m_iBLCLevel; //���ⲹ������
  int m_iIRMode;//�����˹�Ƭģʽ:0���Զ�;1,��;2���ر�
  int m_iSharpness;//���0-255
	int m_iNoise;//����0-255 �����8λ��ʾ����ģʽ�����8λ��ʾ2D����ֵ��8-15λ��ʾ3D����ֵ
  int m_iGamma;//gammaֵ*100
}TGuiVideoISPInfo;

#define GUI_GET_VIDEO_ISP_INFO_REQ  4000 //��ȡ����������������
#define GUI_GET_VIDEO_ISP_INFO_RSP	-4000 //��ȡ�����������������Ӧ
typedef struct
{
	TGuiVideoISPInfo m_tVideoISPInfo;
}TGuiGetVideoISPInfoRsp; //��ȡ�����������������Ӧ

#define GUI_SET_VIDEO_ISP_INFO_REQ   4001 //��������������������
#define GUI_SET_VIDEO_ISP_INFO_RSP   -4001 //������������������Ӧ

typedef struct
{
	TGuiVideoISPInfo m_tVideoISPInfo;
}TGuiSetVideoISPInfoReq; //��������������������

#define GUI_SET_VIDEO_ISP_INFO_OK  0 //�����������������ɹ�
#define GUI_SET_VIDEO_ISP_INFO_ERR	1 //����������������ʧ��

typedef struct
{
	int m_iRetCode;
}TGuiSetVideoISPInfoRsp; //������������������Ӧ

#define GUI_GET_VIDEO_ISP_INFO_REQ_EX      4002 //��ȡ����������������
#define GUI_GET_VIDEO_ISP_INFO_RSP_EX 	-4002//��ȡ�����������������Ӧ

typedef struct
{
	int m_iChn; // ͨ����
}TGuiGetVideoISPInfoReqEx;

typedef struct
{
	int m_iChn;                              //ͨ����
	TGuiVideoISPInfo m_tVideoISPInfo;
}TGuiGetVideoISPInfoRspEx; //��ȡ�����������������Ӧ

#define GUI_SET_VIDEO_ISP_INFO_REQ_EX   4003 //��������������������
#define GUI_SET_VIDEO_ISP_INFO_RSP_EX   -4003 //������������������Ӧ

typedef struct
{
	int m_iChn;
	TGuiVideoISPInfo m_tVideoISPInfo;
}TGuiSetVideoISPInfoReqEx; //��������������������

typedef struct
{
	int m_iRetCode;
}TGuiSetVideoISPInfoRspEx; //������������������Ӧ


//=====================================================
//����S3E ��Ƶ��ת����
//��ת����  UI�ϵ���Ƶ��ת���ں˷�ö������3����
typedef enum
{
	GUI_VIDEO_TURN_H = 1,		//ˮƽ��ת
	GUI_VIDEO_TURN_V,			//��ֱ��ת
	GUI_VIDEO_TURN_R,			//���÷�ת
}TGuiVideoTurnType;

#define GUI_SET_VIDEO_TURN_TYPE_REQ  4101 //������Ƶ��ת��������
#define GUI_SET_VIDEO_TURN_TYPE_RSP  -4101 //������Ƶ��ת���������Ӧ

typedef struct
{
	int m_iChn;
	int m_iType; 		//��ת����
}TSetVideoTurnTypeReq; //������Ƶ��ת��������

typedef struct
{
	int m_iRetCode;     //ʹ�ù������óɹ�ʧ�ܷ�����
}TSetVideoTurnTypeRsp; //������Ƶ��ת���������Ӧ

//=====================================================
//===============��ͨ��������ҵ��===============

//��ȡ�洢·���б�(�¼�)(ͬ��ͨ��)
#define GUI_GET_DEV_STORAGE_REQ    30000   //��ȡ�洢�豸����
#define GUI_GET_DEV_STORAGE_RSP    -30000   //��ȡ�洢�豸��Ӧ

typedef struct 	//��ȡ�洢�豸����
{
	int m_iDevType; //��������
}TGuiGetStorageReq;

typedef struct		//��ȡ�洢�豸��Ӧ
{
	int    m_iStorageCnt;	// �洢�豸����
}TGuiGetStorageRsp;


typedef struct 		//�����б���
{
	int m_iDevType;  //��������
	int m_iStorageId; // �洢�豸���
	char m_pcStorageName[4][GUI_PUBLIC_LEN_31 + 1]; //Usb�洢�豸·�����ƣ����·��������ָ��ʲô��
}TGuiStorageListItem;
 

//��ȡ��ǰ���ô���·��(�¼�) (ͬ��ͨ��)
#define GUI_GET_APP_STORAGE_PATH_REQ   30001  //��ȡ��ҿ��ô���·������
#define GUI_GET_APP_STORAGE_PATH_RSP   -30001  //��ȡ��ҿ��ô���·����Ӧ

#define GUI_GET_APP_STORAGE_PATH_OK			0	//��ȡ���ô洢�ռ�ɹ�
#define GUI_GET_APP_STORAGE_PATH_ERR		1	//����ԭ��ʧ��
#define GUI_GET_APP_STORAGE_PATH_CRITICAL	2	//���ÿռ��ѵ��ٽ�ֵ
#define GUI_GET_APP_STORAGE_PATH_FULL		3	//���ÿռ���
#define GUI_GET_APP_STORAGE_PATH_NOT_READY	4	//���ÿռ�δ׼����

//������Ϣ��
typedef struct  //��Ӧ
{
	int iRetCode;					//������
	char cPath[GUI_PUBLIC_LEN_255 + 1];
}TGuiGetAppStoragePathRsp;


//����豸״̬������������Ȧ������¶ȣ�(�¼�)(�첽ͨ��)
#define GUI_GET_DEVICE_STATE_REQ    30002   //��ȡ�豸״̬����
#define GUI_GET_DEVICE_STATE_RSP    -30002   //��ȡ�豸״̬��Ӧ
//֮ǰ����������Ϊ0��Ϊ�˺ͽ�ͨ�������Э��һ�£���Ϊ1
#define    GUI_REDLIGHT_STATUS 0
#define    GUI_SENSOR_STATUS    1    //������״̬
#define    GUI_LOOP_STATUS      2    //��Ȧ״̬
#define    GUI_CAMERA_TEMP     3     //����¶�
#define    GUI_REDLIGHT_SIGCHEACK_STATUS     4     //��ѯ����źż����״̬

typedef struct		//��ȡ�豸״̬����
{
	int  m_iChn;    //ͨ����(0-n,0��ʾ���ȫ��ͨ��)
	int  m_iDeviceType; //�豸���ͣ�0:��� 1:��������2:��Ȧ��3:����¶�
} TGuiGetDeviceStateReq;

#define    GUI_DEVICE_STATE_OK    0    //�ɹ�
#define    GUI_DEVICE_STATE_ERR   -1    //ʧ��

typedef struct		
{
	int  m_iRet;
}TGuiGetDeviceStateRsp;

//¼��ü�(�¼�) (�첽ͨ��)
#define GUI_CUTOUT_VIDEO_REC_REQ    30003   //¼��ü�����
#define GUI_CUTOUT_VIDEO_REC_RSP    -30003   //¼��ü���Ӧ

#define GUI_CUTOUT_VIDEO_OK    0     //�ɹ�
#define GUI_CUTOUT_VIDEO_ERR   -1    //ʧ��

typedef struct		//¼��ü�����
{
	int  m_iChn;    //ͨ����(0-n,0��ʾ���ȫ��ͨ��)
	int  m_iBeginTime; //��ʼʱ��
	int  m_iEndTime;  //����ʱ��
	char m_cPath[GUI_PUBLIC_LEN_255 + 1];	//·��+�ļ���
} TGuiCutOutVideoRecReq; //�ں���ɲü����͸ýṹ��

typedef struct		//¼��ü���Ӧ
{
	int  m_iChn;        //ͨ����(0-n,0��ʾ���ȫ��ͨ��)
	int  m_iRetCode;    // 0�ɹ���-1ʧ��
}TGuiCutOutVideoRecRsp;

//�첽��Ӧ��Ϣ��
#define GUI_SEND_DEVICE_STATE_REQ    10005   //�����豸״̬���Խ�ģ��
#define GUI_SEND_DEVICE_STATE_RSP    -10005   //��ȡ�豸״̬���Խ�ģ��

typedef struct		//�豸״̬�ṹ��
{
	int  m_iDeviceType;   //�豸���ͣ�0:��� 1:��������2:��Ȧ��3:����¶�
	int  m_iDevState[4];    //״̬
}TGuiDeviceState;

typedef struct		//��ȡ�豸״̬��Ӧ
{
	int  m_iChn;    //ͨ����(0-n,0��ʾ���ȫ��ͨ��)
	TGuiDeviceState  m_tDevState; //�豸״̬�ṹ��
}TGuiSendDeviceStateReq;


//�첽��Ӧ��Ϣ��
#define GUI_SEND_CUTOUT_VIDEO_REQ    10001   //���Ͳü�������Խ�ģ��
#define GUI_SEND_CUTOUT_VIDEO_RSP    -10001   //���Ͳü�������Խ�ģ��

#define GUI_SEND_CUTOUT_VIDEO_OK	0 //�ü��ɹ�
#define GUI_SEND_CUTOUT_VIDEO_ERR	1 //����ԭ��ü�ʧ��
#define GUI_SEND_CUTOUT_VIDEO_NOT_EXIST	2 //¼���ļ�������
#define GUI_SEND_CUTOUT_VIDEO_DISK_FULL	3 //���̿ռ䲻��

 //�ں���ɲü����͸ýṹ��TGuiCutOutVideoRecReq

typedef struct
{
	int m_iRetCode;
	TGuiCutOutVideoRecReq m_tGuiCutOutVideoRec;
}TGuiSendCutOutVideoRsp;

//��ȡ��ͨΥ������¼����Ϣ (�¼�) (�첽ͨ��)
//�첽��Ӧ��Ϣ��
#define GUI_SEND_ITS_ILLEGAL_RECORD_REQ    10002   //����Υ��¼����Ϣ���Խ�ģ��
#define GUI_SEND_ITS_ILLEGAL_RECORD_RSP    -10002   //����Υ��¼����Ϣ���Խ�ģ��

typedef struct tagNVS_FILE_TIME_V1
{
	unsigned short iYear;   /* Year */
	unsigned short iMonth;  /* Month */
	unsigned short iDay;    /* Day */
	unsigned short iHour;   /* Hour */
	unsigned short iMinute; /* Minute */
	unsigned short iSecond; /* Second */
	unsigned short iMillisecond; /* Millisecond */
} NVS_FILE_TIME_V1,*PNVS_FILE_TIME_V1;

typedef struct		//¼����Ϣ�ṹ��
{
	int	 iBufSize;	//��ϴ����ṹ���С
	long lCarID;          //����ID
	int  iRecordFlag;     //��������0:ֹͣ,1:��ʼ��2:ȡ��
	int  iIllegalType;     //Υ������
	int  iPreset;         //����id
	char cCrossingID[GUI_PUBLIC_LEN_63 + 1];		 //·�ڱ�� 64���ַ�
	char cLaneID[GUI_PUBLIC_LEN_63 + 1];			 //�������	64���ַ�
	NVS_FILE_TIME_V1 m_tSnapTime;//ץ�Ŀ�ʼʱ��(��һ��ͼƬץ��ʱ��) 
}TGuIllegalRecordMsg;

typedef struct		 //�ں˷��͵�Υ��¼����Ϣ
{
	int 	m_iChn;	//ͨ����(0-n,0��ʾ���ȫ��ͨ��)
	TGuIllegalRecordMsg tRecMsg; //¼����Ϣ
}TGuiIllegalRecReq;

//=====================================================


//------------------------------------------------------------------
//����DVR��Դ����
#define GUI_GET_POWER_CNF_REQ   200000     //��ȡ��Դ������������
#define GUI_GET_POWER_CNF_RSP    -200000    //��ȡ��Դ�������û�Ӧ
#define GUI_SET_POWER_CNF_REQ    200001    //���õ�Դ������������
#define GUI_SET_POWER_CNF_RSP    -200001   //���õ�Դ�������û�Ӧ
typedef struct 
{
	int m_iOpenEnable;
	int m_iOpenDevDelayTime;
	int m_iCloseEnable;
	int m_iCloseDevDelayTime;
}TGuiPowerManageMsg;

typedef struct								//��ȡ��Դ�����Ӧ	
{
	TGuiPowerManageMsg m_tPowerManageMsg;						
} TGuiGetPowerManageCnfRsp;

typedef struct                          //���õ�Դ��������
{
	TGuiPowerManageMsg m_tPowerManageMsg;
}TGuiSetPowerManageCnfReq;

#define GUI_SET_POWER_MANAGE_CNF_OK			0    //���óɹ�
#define GUI_SET_POWER_MANAGE_CNF_ERR		1    //����ʧ��
typedef struct                           //���õ�Դ�����Ӧ
{
	int m_iRetCode;
}TGuiSetPowerManageCnfRsp;

//============================ 

typedef struct 
{
	int m_iPoweroffVoltage;  	//�ػ���ѹֵ�������10
	int m_iAlarmVoltage;		//��ѹ����ֵ�������10
}TGuiPowerAlarmMsg;

#define GUI_GET_POWER_ALARM_MSG_REQ	200002	//��ȡ�ػ���ѹ�ͱ�����ѹ����
#define GUI_GET_POWER_ALARM_MSG_RSP	-200002	//��ȡ�ػ���ѹ�ͱ�����ѹ��Ӧ

typedef struct 
{
	TGuiPowerAlarmMsg m_tPowerAlarmMsg;
}TGuiGetPowerAlarmMsgRsp;

#define GUI_SET_POWER_ALARM_MSG_REQ	200003	//���ùػ���ѹ�ͱ�����ѹ����
#define GUI_SET_POWER_ALARM_MSG_RSP	-200003	//���ùػ���ѹ�ͱ�����ѹ��Ӧ

typedef struct 
{
	TGuiPowerAlarmMsg m_tPowerAlarmMsg;
} TGuiSetPowerAlarmMsgReq;

typedef struct								
{	
	int m_iRetCode;
}TGuiSetPowerAlarmMsgRsp;

//============================ 
//FTP�ϴ�����(�ò���Э���ֹ)
#define GUI_STR_SERVER_NAME_LEN    63
typedef struct
{
	char	m_cServerName[GUI_STR_SERVER_NAME_LEN + 1];       //��������ַ
	char    m_cServerPath[GUI_STR_SERVER_NAME_LEN + 1];       //�ڷ������ϵ�·��
	char 	m_cUserName[GUI_IP_STR_LEN + 1];         //�û���
	char	m_cPassword[GUI_IP_STR_LEN + 1];			//����
	int		m_iPort;					//�˿ں�
	int     m_iAutoFtpEnable;                 //�Զ��ϴ�����
}TGuiFTPServerParaMsg;

#define GUI_GET_FTP_CNF_REQ       200004   //��ȡFTP�ϴ���������
#define GUI_GET_FTP_CNF_RSP       -200004  //��ȡFTP�ϴ����û�Ӧ
typedef struct									//��ȡFTP�ϴ����������Ӧ
{
	TGuiFTPServerParaMsg m_tFTPParaMsg;
}TGuiGetFTPServerParaCnfRsp;

#define GUI_SET_FTP_CNF_REQ       200005   //����FTP �ϴ���������
#define GUI_SET_FTP_CNF_RSP       -200005  //����FTP�ϴ����û�Ӧ
#define GUI_UP_FTP_CNF_REQ        200006   //�ϴ���������
#define GUI_UP_FTP_CNF_RSP        -200006  //�ϴ������Ӧ
typedef struct                               //����FTP�ϴ������������
{
	TGuiFTPServerParaMsg m_tFTPParaMsg;
}TGuiSetFTPServerParaCnfReq;

#define GUI_SET_FTP_PARA_CNF_OK			0   //���óɹ�
#define GUI_SET_FTP_PARA_CNF_ERR			1   //����ʧ��
typedef struct								//����FTP�ϴ����������Ӧ
{
	int m_iRetCode;
}TGuiSetFTPServerParaCnfRsp;

//============================ 
#define GUI_GET_WIFI_AUTO_FTP_STAT_REQ	200101	//��ȡwifi�Զ�ftp�ϴ�ʹ��״̬����
#define GUI_GET_WIFI_AUTO_FTP_STAT_RSP	-200101	//��ȡwifi�Զ�ftp�ϴ�ʹ��״̬��Ӧ
typedef struct								
{	
	int m_iEnable; //�������궨��GUI_SET_ENABLE
}TGuiGetAutoFtpStatRsp;

#define GUI_SET_WIFI_AUTO_FTP_STAT_REQ	200102	//����wifi�Զ�ftp�ϴ�ʹ��״̬����
#define GUI_SET_WIFI_AUTO_FTP_STAT_RSP	-200102	//����wifi�Զ�ftp�ϴ�ʹ��״̬��Ӧ

typedef struct								
{	
	int m_iEnable; //�������궨��GUI_SET_ENABLE
}TGuiSetAutoFtpStatReq;

typedef struct								
{	
	int m_iRetCode;
}TGuiSetAutoFtpStatRsp;

//============================ 
#define GUI_SEND_WIFI_FTP_UP_CMD_REQ        200103   //�����ֶ��ϴ���������
#define GUI_SEND_WIFI_FTP_UP_CMD_RSP        -200103  //�����ֶ��ϴ������Ӧ

typedef struct								
{	
	int m_iRetCode;
}TGuiSendWifiFtpUpCmdRsp;
//============================ 




//------------------------------------------------------------------
//���Ź���
#define GUI_SMS_COUNT_REQ        200009   //ͳ�ƶ�����������
#define GUI_SMS_COUNT_RSP        -200009  //ͳ�ƶ���������Ӧ
#define GUI_SMS_QUERY_REQ         200010  //��ѯ��������
#define GUI_SMS_QUERY_RSP         -200010  //��ѯ���Ż�Ӧ
#define GUI_SMS_CLEAR_REQ        200011    //��ն�������
#define GUI_SMS_CLEAR_RSP         -200011   //��ն��Ż�Ӧ
#define GUI_SMS_DEL_REQ           200012   //ɾ����������
#define GUI_SMS_DEL_RSP           -200012   //ɾ�����Ż�Ӧ
#define GUI_SMS_SIGN_READ_REQ    200013   //����Ѷ���Ϣ����
#define GUI_SMS_SIGN_READ_RSP    -200013  //����Ѷ���Ϣ��Ӧ

//��ѯ�¼�
#define GUI_SMS_ALL     1
#define GUI_SMS_READ    2
#define GUI_SMS_UNREAD  3
typedef struct
{
	int m_iCondition;         //��ѯ���
}TGuiSmsQueryCondition;

typedef struct        //ͳ�ƶ��Ÿ�������
{
	TGuiSmsQueryCondition m_tCondition;
}TGuiCountSmsReq;
typedef struct       //ͳ�ƶ��Ÿ�����Ӧ
{
   int m_iSmsCnt;   //ͳ�ƵĶ��Ÿ���
}TGuiCountSmsRsp;

#define GUI_DIAL_NUMBER   31                  //�����˺�����󳤶�
#define GUI_SMS_CONTENT_LEN  159               //����������󳤶�(���ַ�����)
#define GUI_SMS_NAME   63
typedef struct
{
	int m_iRecTm;                                     //���Ž���ʱ��
	char m_strFrom[GUI_DIAL_NUMBER + 1];            //������
	char m_strContent[GUI_SMS_CONTENT_LEN + 1];     // ��������	
	char m_strName[GUI_SMS_NAME + 1];	//������
}TGuiSmsMsg;


typedef struct					//���Ų�ѯ����
{
	TGuiSmsQueryCondition m_tCondition; //��ѯ����
	int m_iPageId;          //��ʼ����ҳ(��һҳΪ0)
 	int m_iSmsCnt;               //ÿҳ��������
}TGuiSmsQueryReq;

typedef struct                 //��ѯ���Ż�Ӧ
{
	int m_iSmsCnt;			//���ص�����
}TGuiSmsQueryRsp;

//����ɾ���¼�
typedef struct									//ɾ����������
{
	char m_strName[GUI_SMS_NAME + 1];	//�����ļ���	
} TGuiSmsDeleteReq;

#define GUI_SMS_DEL_OK			0		//ɾ�����ųɹ�
#define GUI_SMS_DEL_ERR			1		//ɾ������ʧ��
typedef struct									//ɾ�����Ż�Ӧ
{
	int m_iRetCode;							//������
} TGuiSmsDeleteRsp;

//��������¼�
#define GUI_SMS_CLEAR_OK		0				//��ն��ųɹ�
#define GUI_SMS_CLEAR_ERR		1				//��ն���ʧ��
typedef struct									//��ն��Ż�Ӧ
{
	int m_iRetCode;							//������շ�����
} TGuiSmsClearRsp;

//���ű���Ѷ��¼�
typedef struct									//���ű������
{
	char m_strName[GUI_SMS_NAME + 1];	//�����ļ���	
} TGuiSmsSignReadReq;

#define GUI_SMS_SIGN_READ_OK			0		//���ű���Ѷ��ɹ�
#define GUI_SMS_SIGN_READ_ERR			1		//���ű���Ѷ�ʧ��
typedef struct									//���ű�ǻ�Ӧ
{
	int m_iRetCode;							//������
} TGuiSmsSignReadRsp;

//-----------------------------------------------------------------------------------------
//3G����
#define GUI_GET_3G_STATUS_CNF_REQ       200018 //��ȡ3G������������
#define GUI_GET_3G_STATUS_CNF_RSP        -200018 //��ȡ3G�������û�Ӧ
//3G���ŷ�ʽ
#define NET_3G_AUTO_DIAL  0
#define NET_3G_SMS_DIAL   1
#define NET_3G_PHONE_DIAL 2
#define NET_3G_ALARM_DIAL 3

//3G�豸����
#define NET_USB0_DEVICE		7  //�ƶ�����
#define NET_3G_NONE_DEVICE   3 //�޷�ʶ��
#define NET_3G_WCDMA_DEVICE  2 //��ͨ3G
#define NET_3G_EVDO_DEVICE   1 //����3G
#define NET_3G_TD_DEVICE     0 //�ƶ�3G
//3G����״̬
#define NET_3G_NOTONLINE    0  //������
#define NET_3G_ONLINE       1  // ���� 
#define NET_3G_LINING       2   //������...
//3G���߷�ʽ 
#define NET_3G_INITIATIVE   0
#define NET_3G_PASSIVE       1

//3G�ź�ǿ��
#define NET_3G_SIGNAL_WEAKER   0
#define NET_3G_SIGNAL_WEAK     1
#define NET_3G_SIGNAL_GENERAL  2
#define NET_3G_SIGNAL_STRONG   3


#define NET_3G_DISCONNECT	    0				//3Gδ����
#define NET_3G_CONNECTED    	1				//3G���ӳɹ�(������)
#define NET_3G_CONNECTING       2               //3G�����С�����

typedef struct
{
	int m_iConnectState; 
	int m_iDeviceType;//�豸���� 
	int m_iOnLineState;//����״̬
	int m_iIntensity;  //�ź�ǿ��
	char m_strIP[GUI_IP_STR_LEN + 1]; //IP��ַ
	int m_iDialBeginTm;  //��ʼ����ʱ��
}TGui3GStatusMsg;

typedef struct          //��ȡ3G������Ϣ��Ӧ
{
	TGui3GStatusMsg m_t3GStatusMsg;
}TGuiGet3GStatusCnfRsp;

//3G����
#define GUI_GET_3G_DIAL_STATUS_CNF_REQ   200019 //��ȡ3G����״̬����
#define GUI_GET_3G_DIAL_STATUS_CNF_RSP   -200019 //��ȡ3G����״̬��Ӧ
#define GUI_SET_3G_DIAL_STATUS_CNF_REQ   200020  //  ����3G����״̬����
#define GUI_SET_3G_DIAL_STATUS_CNF_RSP   -200020  //  ����3G����״̬��Ӧ

typedef struct
{
	int m_iDialType;   //���ŷ�ʽ	//0,�Զ����ţ�1�����Ų��ţ�2���绰���ţ�3����������(Ԥ��),4.��ʱ  5. �ֶ�
	int m_iStopType;   //���߷�ʽ
	int m_iDurationTm; //����ʱ��
}TGui3GDialStatusMsg;

typedef struct                            //��ȡ3G����״̬������Ӧ
{
	TGui3GDialStatusMsg m_t3GDialStatusMsg;
}TGuiGet3GDialStatusMsgRsp;

typedef struct                           //����3g����״̬��������
{
	TGui3GDialStatusMsg m_t3GDialStatusMsg;
}TGuiSet3GDialStatusMsgReq;

#define GUI_SET_3G_DIAL_STATUS_OK    0    //���óɹ�
#define GUI_SET_3G_DIAL_STATUS_ERR   1    //����ʧ��

typedef struct                          //����3g����״̬������Ӧ
{
	int m_iRetCode;
}TGuiSet3GDialStatusMsgRsp;

//3G����-�Ͽ��¼�
#define GUI_SET_3G_DISCONN_CNF_REQ   200023 //����3G����Ͽ�����
#define GUI_SET_3G_DISCONN_CNF_RSP   -200023 //����3G����Ͽ���Ӧ

//����3G�Ͽ�����Ļ�Ӧ
typedef struct
{
	int m_iRetCode;
}TGuiSet3GDisconnectRsp;

//3G����-�����¼�
#define GUI_SET_3G_CONNECT_CNF_REQ   200024 //����3G������������
#define GUI_SET_3G_CONNECT_CNF_RSP   -200024 //����3G�������ӻ�Ӧ
//����3G��������Ļ�Ӧ
typedef struct
{
	int m_iRetCode;
}TGuiSet3GConnectRsp;

//3G����-��������
#define GUI_GET_3G_DIAL_CNF_REQ      200025   //��ȡ3G��������������
#define GUI_GET_3G_DIAL_CNF_RSP      -200025  //��ȡ3G ���������û�Ӧ
#define GUI_SET_3G_DIAL_CNF_REQ      200026   //����3G��������������
#define GUI_SET_3G_DIAL_CNF_RSP      -200026   //����3G ���������û�Ӧ

#define GUI_DIAL_NOTIFY_LEN 19
typedef struct
{
	char m_strNotify[GUI_DIAL_NOTIFY_LEN + 1];
	char m_strPhone1[GUI_DIAL_NUMBER + 1];
	char m_strPhone2[GUI_DIAL_NUMBER + 1];
	char m_strPhone3[GUI_DIAL_NUMBER + 1];
	char m_strPhone4[GUI_DIAL_NUMBER + 1];
	char m_strPhone5[GUI_DIAL_NUMBER + 1];
}TGui3GDialSetParaMsg;

typedef struct                                //��ȡ3G����-�������ý��������Ӧ
{
	TGui3GDialSetParaMsg m_t3GDialSetParaMsg;
}TGuiGet3GDialSetParaCnfRsp;

typedef struct                               //����3G ����-�������ý����������
{
	TGui3GDialSetParaMsg m_t3GDialSetParaMsg;
}TGuiSet3GDialSetParaCnfReq;

#define GUI_SET_3G_DIAL_SET_PARA_OK    0    //���óɹ�
#define GUI_SET_3G_DIAL_SET_PARA_ERR   1    //����ʧ��
typedef struct                              //����3G����-�������ý��������Ӧ
{
	int m_iRetCode;
}TGuiSet3GDialSetParaCnfRsp;

//3G����-�߼�����
//3G����-�߼�����-3G����ʱ���
#define GUI_GET_3G_ADV_SCH_CNF_REQ     200029   //��ȡ3G�߼�������3G����ʱ�������
#define GUI_GET_3G_ADV_SCH_CNF_RSP    -200029 //��ȡ3G�߼�������3G����ʱ����Ӧ
#define GUI_SET_3G_ADV_SCH_CNF_REQ     200030  //����3G�߼�������3G����ʱ�������
#define GUI_SET_3G_ADV_SCH_CNF_RSP    -200030 //����3G�߼�������3G ����ʱ����Ӧ

#define NET_3G_ENABLE_TASK_SCH      1          //��������ʱ���
#define NET_3G_UNENABLE_TASK_SCH    0          //��������ʱ���
typedef struct
{
	int m_iTmSchEnable;
	int m_iStartTm;
	int m_iEndTm;
}TGui3GTmSchMsg;

typedef struct							//��ȡ3G����ʱ����Ӧ
{
	TGui3GTmSchMsg m_t3GTmSchMsg;
}TGuiGet3GTmSchCnfRsp;

typedef struct                       //����3G����ʱ�������
{
	TGui3GTmSchMsg m_t3GTmSchMsg;
}TGuiSet3GTmSchCnfReq;

#define GUI_SET_3G_TMSCH_OK    0  //���óɹ�
#define GUI_SET_3G_TMSCH_ERR   1  //����ʧ��
typedef struct                      //����3G����ʱ����Ӧ
{
	int m_iRetCode;
}TGuiSet3GTmSchCnfRsp;

//3G����-�߼�����-֪ͨ
#define GUI_GET_3G_ADV_NOTIFY_CNF_REQ   200031 //��ȡ3G�߼������ж���֪ͨ��������
#define GUI_GET_3G_ADV_NOTIFY_CNF_RSP    -200031 //��ȡ3G�߼������ж���֪ͨ���û�Ӧ
#define GUI_SET_3G_ADV_NOTIFY_CNF_REQ   200032 //����3G�߼������ж���֪ͨ��������
#define GUI_SET_3G_ADV_NOTIFY_CNF_RSP    -200032 //����3G�߼������ж���֪ͨ���û�Ӧ

typedef struct
{
	int m_iNotifyType;
	char m_strNotifyMsg[GUI_SMS_CONTENT_LEN + 1];
}TGui3GNotifyMsg;

typedef struct                        //��ȡ3G֪ͨ�Ĳ�����Ϣ��Ӧ
{
	TGui3GNotifyMsg m_t3GNotifyMsg;
}TGuiGet3GNotifyCnfRsp;


typedef struct                        //����3G֪ͨ�Ĳ�����Ϣ����
{
	TGui3GNotifyMsg m_t3GNotifyMsg;
}TGuiSet3GNotifyCnfReq;

#define GUI_SET_3G_NOTIFY_MSG_OK    0  //���óɹ�
#define GUI_SET_3G_NOTIFY_MSG_ERR   1  //����ʧ��
typedef struct							//����3G֪ͨ�Ĳ�����Ϣ��Ӧ
{
	int m_iRetCode;
}TGuiSet3GNotifyCnfRsp;

//3G����-�߼�����-VPN
#define GUI_GET_3G_ADV_VPN_CNF_REQ  200035 //��ȡ3G�߼�������VPN��������
#define GUI_GET_3G_ADV_VPN_CNF_RSP   -200035 //��ȡ3G�߼�������VPN���û�Ӧ
#define GUI_SET_3G_ADV_VPN_CNF_REQ  200036 //����3G�߼�������VPN��������
#define GUI_SET_3G_ADV_VPN_CNF_RSP   -200036 //����3G�߼�������VPN���û�Ӧ

typedef struct
{
	char m_strDial[GUI_DIAL_NUMBER + 1];		//APN
	char m_strAccount[GUI_DIAL_NUMBER + 1];
	char m_strPassword[GUI_DIAL_NUMBER + 1];
}TGui3GVPNMsg;
typedef struct                     //��ȡ3G VPN ������Ϣ���û�Ӧ
{
	TGui3GVPNMsg m_t3GVPNMsg;
}TGuiGet3GVPNCnfRsp;


typedef struct                     //����3G VPN ������Ϣ��������
{
	TGui3GVPNMsg m_t3GVPNMsg;
}TGuiSet3GVPNCnfReq;

#define GUI_SET_3G_VPN_CNF_OK    0  //���óɹ�
#define GUI_SET_3G_VPN_CNF_ERR   1  //����ʧ��

typedef struct                    //����3GVPN ������Ϣ���û�Ӧ
{
    int m_iRetCode;
}TGuiSet3GVPNCnfRsp;

//3G ����-�߼����� - SIM ��
#define GUI_GET_3G_ADV_SIM_CNF_REQ    200037 //��ȡ3G�߼�������SIM������������
#define GUI_GET_3G_ADV_SIM_CNF_RSP    -200037//��ȡ3G�߼�������SIM�������û�Ӧ
#define GUI_SET_3G_ADV_SIM_CNF_REQ    200038 //����3G�߼�������SIM��������
#define GUI_SET_3G_ADV_SIM_CNF_RSP    -200038// ����3G�߼�������SIM���Ż�Ӧ

#define GUI_3G_ADV_SIM_LEN     31
typedef struct
{
	char m_strSim[GUI_3G_ADV_SIM_LEN + 1];
}TGui3GSimMsg;
typedef struct							//��ȡSIM�����Ӧ
{
	TGui3GSimMsg m_t3GSimMsg;
}TGuiGet3GSimCnfRsp;

typedef struct              //����SIM����
{
	TGui3GSimMsg m_t3GSimMsg;
}TGuiSet3GSimCnfReq;  

typedef struct                      //����SIM��Ӧ
{
	int m_iRetCode;
}TGuiSet3GSimCnfRsp;

//--------------------------------------------------------------
//GPS��Ϣ����Ԥ��
#define GUI_GET_GPS_MSG_REQ          200041//��ȡGPS��ַ��Ϣ����
#define GUI_GET_GPS_MSG_RSP          -200041//��ȡGPS��ַ��Ϣ��Ӧ

#define GUI_GPS_MSG_LEN  31
#define GUI_GPS_DSP_OFF  0   //����ʾ
#define GUI_GPS_DSP_ON   1   //��ʾ

typedef struct   //��ȡGPS��ַ��Ϣ��Ӧ
{
	int m_iDspEnable;
	char m_cGPSMsg[GUI_GPS_MSG_LEN + 1];
}TGuiGPSMsg;

typedef struct
{
	TGuiGPSMsg m_tGpsMsg;
}TGuiGetGPSMsgRsp;

#define GUI_SET_GPS_MSG_REQ          200042//����GPS��ַ��Ϣ����
#define GUI_SET_GPS_MSG_RSP          -200042//����GPS��ַ��Ϣ��Ӧ
#define GUI_SET_GPS_CNF_OK			0
#define GUI_SET_GPS_CNF_ERR			1

typedef struct
{
	TGuiGPSMsg m_tGpsMsg;
}TGuiSetGPSMsgReq;

typedef struct
{
	int m_iRetCode;
}TGuiSetGPSMsgRsp;

//=============================
#define GUI_GET_GPS_MODULE_TYPE_REQ          200043//��ȡGPSģ����������
#define GUI_GET_GPS_MODULE_TYPE_RSP          -200043//��ȡGPSģ�����ͻ�Ӧ

#define MODULE_TYPE_GPS		0
#define MODULE_TYPE_BEIDOU	1

typedef struct
{
	int m_iGPSModuleType;		//GPSģ�����ͣ�0��GPS��1������
}TGuiGetGPSModuleTypeRsp;

//=============================
#define GUI_GPS_TIMING_DISENABLE  0 //δʹ��
#define GUI_GPS_TIMING_ENABLE  	  1 //ʹ�� 

#define GUI_GET_GPS_TIMING_STA_REQ	200044 //��ȡGPSУʱʹ��״̬����
#define GUI_GET_GPS_TIMING_STA_RSP	-200044 //��ȡGPSУʱʹ��״̬��Ӧ

typedef struct								
{	
	int m_iEnable; //���궨��
}TGuiGetGPStimingStatRsp;

#define GUI_SET_GPS_TIMING_STA_REQ          200045//����GPSУʱʹ��״̬����
#define GUI_SET_GPS_TIMING_STA_RSP          -200045//����GPSУʱʹ��״̬��Ӧ

typedef struct								
{	
	int m_iEnable; //���궨��
}TGuiSetGPStimingStatReq;

typedef struct								
{	
	int m_iRetCode; //�����궨�巵��ֵ
}TGuiSetGPStimingStatRsp;
//=============================

#define GUI_SET_BOARD_CONTROL_FAN_REQ			20004//����������Ʒ���ת������
#define GUI_SET_BOARD_CONTROL_FAN_RSP			-20004//����������Ʒ���ת����Ӧ

enum
{
	GUI_CONTROL_FAN_START = 1,		//����ת��
	GUI_CONTROL_FAN_STOP,			//����ֹͣ
};

typedef struct
{
	int m_iAct;
}TGuiSetBoardControlFanReq;

typedef struct
{
	int m_iRetCode;
}TGuiSetBoardControlFanRsp;


#define GUI_SET_INQUEST_VIDEO_ENCRYPT_REQ   20005//������Ѷ��Ƶ��������
#define GUI_SET_INQUEST_VIDEO_ENCRYTP_RSP	-20005//������Ѷ��Ƶ���ܻ�Ӧ
typedef struct
{
	int m_iInquestVideoPwdEnable; //0-��ʹ�� 1-ʹ��
	char m_cInquestVideoPwd[GUI_VIDEO_PWD_LEN + 1];
}TGuiSetInquestVideoEncryptReq;

typedef struct
{
	int m_iRetCode;
}TGuiSetInquestVideoEncryptRsp;

#define GUI_GET_INQUEST_VIDEO_ENCRYPT_REQ  	20006//��ȡ��Ѷ��Ƶ��������
#define GUI_GET_INQUEST_VIDEO_ENCRYPT_RSP   -20006//��ȡ��Ѷ��Ƶ���ܻ�Ӧ

typedef struct
{
	int m_iInquestVideoPwdEnable;
	char m_cInquestVideoPwd[GUI_VIDEO_PWD_LEN + 1];
}TGuiGetInquestVideoEncryptRsp;

// ��ȡ�����ڴ�keyֵ��size��С
#define GUI_GET_SHM_MSG_REQ	      2500
#define GUI_GET_SHM_MSG_RSP	      -2500

typedef struct	
{
	int m_iPid;	//�����ʶ
	int m_iType;    //�����ڴ�����
} TGuiGetShmMsgReq;

typedef struct	
{
	int m_iKey;	//�����ڴ�keyֵ(��ֵ��ʽʧ��)
	int m_iSize;	//�����ڴ��С
} TGuiGetShmMsgRsp;



#define GUI_GET_SIP_DEVICE_INFO_REQ  1130 //��ȡSIP�豸��Ϣ����
#define GUI_GET_SIP_DEVICE_INFO_RSP  -1130 //��ȡSIP�豸��Ϣ��Ӧ

//SIP�豸����
typedef struct
{
	char m_SipServerIp[GUI_PUBLIC_LEN_31 + 1];	//sip������ip
	int  m_SipServerPort;	//sip�������˿ں�
	char m_SipServerID[GUI_PUBLIC_LEN_31 + 1];	//sip������ID
	char m_SipDeviceID[GUI_PUBLIC_LEN_31 + 1]; //�豸���
	char m_SipUserName[GUI_PUBLIC_LEN_31 + 1]; //�û���
	char m_SipPassword[GUI_PUBLIC_LEN_31 + 1];	//����
	int  m_RegisterValidity;//ע����Ч��	
	int  m_keepalivetime;	//����ʱ��
	int  m_HeartBeatinterval;	//�������ʱ��
	int  m_HeartBeatTimes;	//��������
	int  m_EnableRegister;
}TGuiSIPDeviceInfoRsp;

#define GUI_GET_SIP_CHN_PARA_REQ  1131//��ȡSIP��Ƶͨ��������Ϣ����
#define GUI_GET_SIP_CHN_PARA_RSP   -1131 //��ȡSIP��Ƶͨ��������Ϣ��Ӧ
//SIP��Ƶͨ������
typedef struct
{
	int  m_iChn;
} TGuiGetSIPChnParaReq;

typedef struct
{
	int   	m_iChn;
	char	m_pcChnId[GUI_PUBLIC_LEN_31 + 1];	//ͨ���豸���
	int   	m_iLevel;		//��ǰptz���Ƽ���
	int   	m_iPTZtime;		//�ϴ�ptz���Ƽ�ʱ
}TGuiGetSIPChnParaRsp;

#define GUI_GET_SIP_ALARM_PARA_REQ  1132 //��ȡSIPͨ������������Ϣ����
#define GUI_GET_SIP_ALARM_PARA_RSP  -1132//��ȡSIPͨ������������Ϣ��Ӧ
//SIP����ͨ������
typedef struct									
{
	int   	m_iPortNo;
	char	m_pcAlarmInPortId[GUI_PUBLIC_LEN_31 + 1]; //ͨ���豸���
	int   	m_iLevel;			//ͨ����������
}TGuiGetSIPAlarmParaRsp;

typedef struct
{
	int     m_iPortNo;
}TGuiGetSIPAlarmParaReq;

#define GUI_SET_PU_COMMON_INFO_REQ  1138 
#define GUI_SET_PU_COMMON_INFO_RSP  -1138
#define GUI_SET_PU_COMMON_INFO_OK			0
#define GUI_SET_PU_COMMON_INFO_ERR			1

typedef struct
{
	char		m_cDeviceId[GUI_PUBLIC_LEN_63 + 1];
	char   	m_cDeviceName[GUI_PUBLIC_LEN_63 + 1];
	char  	m_cNFSIp[GUI_PUBLIC_LEN_15 + 1];
	char 	m_cNFSPath[GUI_PUBLIC_LEN_255 + 1];
	int		m_iDevNo;
	int 		m_blNfsEnable;
	int		m_iVspport;
	int		m_iVapport;
	char		m_cAccessnum[GUI_PUBLIC_LEN_63 + 1];
}TGuiSetCommonInfoReq;

typedef struct
{
	int m_iRetCode;
}TGuiSetCommonInfoRsp;

#define GUI_GET_RTMP_LIST_INFO_REQ  1135//��ȡRTMP��Ϣ����
#define GUI_GET_RTMP_LIST_INFO_RSP  -1135 //��ȡRTMP��Ϣ��Ӧ

typedef struct
{
	int m_iUrlIDNo; //���
	int m_iUrlChn; //�����豸�Ǹ�ͨ�������� ��һͨ��Ϊ0
	int m_iUrlEnable; //ʹ�ܸ�url,������������
	char m_cUrl[GUI_PUBLIC_LEN_127 + 1]; //����������RTMP��������url��ַ
}TGuiRtmpInfoItem;

typedef struct
{
	int m_iRtmpCount;
}TGuiGetRtmpListInfoRsp;   //����RTMP��Ϣ����

#define GUI_GET_RTSP_LIST_INFO_REQ  1136//��ȡRTSP��Ϣ����
#define GUI_GET_RTSP_LIST_INFO_RSP  -1136 //��ȡRTSP��Ϣ��Ӧ

typedef struct
{
	int m_iRtspNo; //���
	char m_cRtspIp[GUI_PUBLIC_LEN_31 + 1]; //RTSPԶ����Ƶ����IP
}TRtspInfoItem;

typedef struct
{
	int m_iRtspCount;
}TGuiGetRtspListInfoRsp;   //����RTSP��Ϣ����



#define GUI_GET_CHN_FRAMERATE_LST_REQ   1140//��ȡͨ��֡���б�����
#define GUI_GET_CHN_FRAMERATE_LST_RSP    -1140//��ȡͨ��֡���б��Ӧ
typedef struct
{
	int m_iChn;
}TGuiGetChnFrameRateLstReq;
typedef struct
{
	int m_iChn;
	int m_iFrameRateCnt;
}TGuiGetChnFrameRateLstRsp;

typedef struct
{
	int m_iFrameRate;
}TGuiGetChnFrameRateItem;

#define  GUI_SET_PATH_NAME_REQ	1141//����·������
#define  GUI_SET_PATH_NAME_RSP  -1141//����·����Ӧ
typedef struct
{
	char   m_cPathName[GUI_PUBLIC_LEN_127 + 1];		//Ŀ¼����
}TGuiSetPathNameReq;//����·����Ϣ����

typedef  struct
{
	int m_iRetCode;
}TGuiSetPathNameRsp;

#define GUI_SET_VI_MOD_REQ	1142 //����VIģʽ���� SDI ����ʾ֤����
#define GUI_SET_VI_MOD_RSP	-1142 //����VIģʽ��Ӧ SDI ����ʾ֤���� 
typedef struct
{
	int m_iChn;
	int m_iViMod;		// 1:�������룬2:ʾ֤����
}TGuiSetViModReq;


typedef struct
{
	int m_iChn;
	int m_iRetCode;
}TGuiSetViModRsp;

#define GUI_GET_VI_MOD_REQ	1143 //��ȡVIģʽ���� SDI ����ʾ֤����
#define GUI_GET_VI_MOD_RSP	-1143 //��ȡVIģʽ��Ӧ SDI ����ʾ֤���� 

typedef struct
{
	int m_iChn;
}TGuiGetViModReq;


typedef struct
{
	int m_iChn;
	int m_iViMod;		// 1:�������룬2:ʾ֤����
}TGuiGetViModRsp;


/************************************************************
20141107  NVR���� ������������Ŀ
*************************************************************/

//	�Ƿ��¼���������
#define GUI_GET_RECORD_PLAYER_REQ	316
#define GUI_GET_RECORD_PLAYER_RSP	-316
#define GUI_SET_RECORD_PLAYER_REQ	317
#define GUI_SET_RECORD_PLAYER_RSP	-317

typedef struct
{
	int m_iReocrdPlayer;   //0 ����¼ 1��¼������
}TGuiRecPlayerCnf;

typedef struct
{
	TGuiRecPlayerCnf m_tCnf;
}TGuiGetRecordPlayerRsp;


typedef struct
{
	TGuiRecPlayerCnf m_tCnf;
}TGuiSetRecordPlayerReq;

typedef struct
{
	int m_iRetCode;         //0�ɹ���1ʧ��
}TGuiSetRecordPlayerRsp;

//	����ǰ��IPC���ֺ�
#define GUI_GET_IPCFONT_SIZE_REQ		1200
#define GUI_GET_IPCFONT_SIZE_RSP		-1200
#define GUI_SET_IPCFONT_SIZE_REQ		1201
#define GUI_SET_IPCFONT_SIZE_RSP		-1201

typedef struct			//��ȡ�����С��������
{
	int m_iChn;			//ͨ����
} TGuiGetIpcFontSizeReq;

typedef struct			//��ȡ�����С������Ӧ
{
	int m_iChn;
	int m_iFontSize;	
} TGuiGetIpcFontSizeRsp;


typedef struct			//���������С��������
{
	int m_iChn;
	int m_iFontSize;	
} TGuiSetIpcFontSizeReq;

typedef struct			//���������С������Ӧ
{
	int m_iRetCode; 		//0�ɹ���1ʧ��
} TGuiSetIpcFontSizeRsp;

#define GUI_CMD_IPC_ONKEY_FOCUS_REQ		5020  //һ���۽�����
#define GUI_CMD_IPC_ONKEY_FOCUS_RSP		-5020 //һ���۽���Ӧ

typedef struct
{
	int m_iChn;
}TGuiSetIpcOneKeyFocusReq;

typedef struct
{
	int m_iChn;
	int m_iRetCode;   //0��ɹ� �����ʧ��
}TGuiSetIpcOneKeyFocusRsp;

//	�����ַ�����֧��5������,��һ������Э�飬�����ĸ��������Э��
#define GUI_GET_OSD_TEXT_EX_REQ		1202	//��չ�����ַ�����
#define GUI_GET_OSD_TEXT_EX_RSP		-1202
#define GUI_SET_OSD_TEXT_EX_REQ		1203    
#define GUI_SET_OSD_TEXT_EX_RSP		-1203

typedef struct
{
	int m_iChn;
	int m_iIndex;  //1��ʾ��һ��������������
} TGuiGetOsdTextExReq;

typedef struct
{
	int m_iChn;
	int m_iIndex;  //1��ʾ��һ��������������
	TGuiOsdTextCnf m_tCnf;
} TGuiGetOsdTextExRsp;

typedef struct
{
	int m_iChn;
	int m_iIndex;
	TGuiOsdTextCnf m_tCnf;
} TGuiSetOsdTextExReq;

typedef struct
{
	int m_iRetCode;			//0�ɹ���1ʧ��
} TGuiSetOsdTextExRsp;

//ROI��������
#define GUI_GET_ENCODE_ROI_REQ		1034
#define GUI_GET_ENCODE_ROI_RSP		-1034
#define GUI_SET_ENCODE_ROI_REQ		1035
#define GUI_SET_ENCODE_ROI_RSP		-1035

typedef struct
{
	int m_iEnable;	  //ROI����ʹ�ܱ�ʶ  1��ʾʹ��
	int m_iLocType;	//��������
	int m_iAbsQp;	//0���ֵ��1����ֵ	
	int m_iQp;		//��Χ��������֡��֮��ģ��ȱ���
	TGuiArea m_tROIAreas;
} TGuiROICnf;

typedef struct
{
	int m_iChn;
	int m_iIndex;     //1��ʾ��һ��������������
} TGuiGetROIAreaReq;

typedef struct
{
	int m_iChn;
	int m_iIndex;   
	TGuiROICnf m_tCnf;
} TGuiGetROIAreaRsp;

typedef struct
{
	int m_iChn;
	int m_iIndex;   
	TGuiROICnf m_tCnf;
} TGuiSetROIAreaReq;

typedef struct
{
	int m_iRetCode;     //0��ɹ���1��ʾʧ��
} TGuiSetROIAreaRsp;


//	�ط����
#define GUI_VIDEO_PLAYER_FULL_SCREEN_REQ   	5000 //���
#define GUI_VIDEO_PLAYER_FULL_SCREEN_RSP   	-5000 //���

typedef struct
{
	int m_iVoid;
	TGuiVoAttr m_iVoLoc;
}TGuiVideoPlayerFullScreenReq;

typedef struct
{
	int m_iRetCode;
}TGuiVideoPlayerFullScreenRsp;


#define GUI_VIDEO_PLAYER_RESIZEVO_REQ   		5001//ȫ����ȥ���壩�ͷ���
#define GUI_VIDEO_PLAYER_RESIZEVO_RSP  		-5001 //ȫ����ȥ���壩�ͷ���

typedef struct
{
	int m_iVoCnt;
	int m_iType;           //0��¼�� 1��ͼƬ
	TGuiVoAttr m_iVoLoc[GUI_SYNC_PLAYER_MAX_CNT];
}TGuiVideoPlayerResizeVoReq;

typedef struct
{
	int m_iRetCode;
}TGuiVideoPlayerResizeVoRsp;


#define GUI_PLAYER_THUMBNAIL_ACTIVE_REQ    	5002     //������Ԥ��
#define GUI_PLAYER_THUMBNAIL_ACTIVE_RSP		-5002	
typedef struct    
{
	int m_iVodev;
	int m_iVolevel;       //0��ʾ��ͨ��1��ʾpip
	TGuiVoAttr m_tVoAttrs;
}TGuiPlayerthumbnailActiveReq;

typedef struct    
{
	int m_iPlayId;
}TGuiPlayerthumbnailActiveRsp;


#define GUI_PLAYER_THUMBNAIL_PLAY_REQ		5003
#define GUI_PLAYER_THUMBNAIL_PLAY_RSP		-5003

typedef struct   
{
	int m_iPlayid;
	int m_iChn;
	int m_iBeginTm;
	int m_iEndTm;
	int m_iStepFlag;
}TGuiPlayerthumbnailPlayReq;

typedef struct
{
	int m_iRetCode;
}TGuiPlayerthumbnailPlayRsp;


#define GUI_PLAYER_THUMBNAIL_EXIT_REQ		5004
#define GUI_PLAYER_THUMBNAIL_EXIT_RSP		-5004

typedef struct
{
	int m_iPlayId;
}TGuiPlayerThunbnailExitReq;
typedef struct
{
	int m_iRetCode;
}TGuiPlayerThunbnailExitRsp;

//jpeg��ʼ��
#define GUI_JPEG_VIEWER_INIT_REQ_EX 			5005
#define GUI_JPEG_VIEWER_INIT_RSP_EX			-5005
typedef struct
{
	int m_iDev;
	TGuiVoAttr m_tVoAttrs;
}TGuiJpegViewerInitReqEx;

#define GUI_SYNC_STEP_REVERSE	 				5006   // ͬ������

//��ͨ������
#define GUI_SET_QUERY_CHN_LIST_REQ		5007
#define GUI_SET_QUERY_CHN_LIST_RSP		-5007
typedef struct
{
	int m_iChnOffSet;
	int m_iChnLlist;
}TGuiSetQueryChnListReq;

typedef struct
{
	int m_iRetCode; 
}TGuiSetQueryChnLiIstRsp;

//��ͨ������(��)    ��������Ҫ��ѯ��ͨ���ţ�Ȼ���ٽ��в�ѯ
#define GUI_SET_QUERY_CHN_LIST_REQ_EX		5107
#define GUI_SET_QUERY_CHN_LIST_RSP_EX		-5107
typedef struct
{
	int m_iChnOffSet;
	int m_iChnLst[32];   //��λ��֧��32*32=1024��ͨ��
}TGuiSetQueryChnLstReqEx;

typedef struct
{
	int m_iRetCode; 
}TGuiSetQueryChnLstRspEx;


#define GUI_SET_FILE_CONVERT_FORMAT_REQ   5008    //���ñ����ļ�����ʱ���ļ���ʽ����
#define GUI_SET_FILE_CONVERT_FORMAT_RSP   -5008   //���ñ����ļ�����ʱ���ļ���ʽ��Ӧ

enum
{
	GUI_FILE_SDV = 1,
	GUI_FILE_AVI,
	GUI_FILE_MP4,
};

enum
{
	GUI_DEFAULT = 0,
	GUI_CBL_TYPE,
	GUI_BACKUP_TYPE,
};

#define GUI_GHOST_NUM		0

typedef struct
{
	int m_iDevId;         //����  ��Ŀǰ��GUI_GHOST_NUM
	int m_iType;  //0-Ĭ�� 1-����ʵʱ��¼ 2-���̱��ݿ�¼
	int m_iConvertFormat;
}TGuiSetFileConvertFormatReq;


typedef struct
{
	int m_iRetCode;
}TGuiSetFileConvertFormatRsp;


#define GUI_GET_FILE_CONVERT_FORMAT_REQ    5009    //��ȡ�����ļ�����ʱ���ļ���ʽ����
#define GUI_GET_FILE_CONVERT_FORMAT_RSP    -5009   //��ȡ�����ļ�����ʱ���ļ���ʽ��Ӧ

typedef struct
{
	int m_iDevId; //���� ,Ŀǰ��GUI_GHOST_NUM
	int m_iType;//0-Ĭ�� 1-����ʵʱ��¼ 2-���̱��ݿ�¼
}TGuiGetFileConvertFormatReq;

typedef struct
{
	int m_iDevId; //���� ,Ŀǰ��GUI_GHOST_NUM
	int m_iType; //0-Ĭ�� 1-����ʵʱ��¼ 2-���̱��ݿ�¼
	int m_iConvertFormat;
}TGuiGetFileConvertFormatRsp;

#define GUI_SET_CBL_SINGLE_FILE_FORMAT_REQ   20020    //���ÿ�¼�򱸷ݵ�һ�ļ���ʽ����
#define GUI_SET_CBL_SINGLE_FILE_FORMAT_RSP   -20020   //���ÿ�¼�򱸷ݵ�һ�ļ���ʽ��Ӧ

enum
{
	GUI_DISABLE_SINGLE_FILE = 0,
	GUI_SINGLE_FILE_SDV,
	GUI_SINGLE_FILE_AVI,
	GUI_SINGLE_FILE_MP4,
};

typedef struct
{
	int m_iDevId;         //����  ��Ŀǰ��GUI_GHOST_NUM
	int m_iType;  //0-Ĭ�� 1-����ʵʱ��¼ 2-���̱��ݿ�¼
	int m_iSingleFileFormat;
}TGuiSetSingleFileFormatReq;


typedef struct
{
	int m_iRetCode;
}TGuiSetSingleFileFormatRsp;


#define GUI_GET_CBL_SINGLE_FILE_FORMAT_REQ    20021    //��ȡ��¼�򱸷ݵ�һ�ļ���ʽ����
#define GUI_GET_CBL_SINGLE_FILE_FORMAT_RSP    -20021   //��ȡ��¼�򱸷ݵ�һ�ļ���ʽ��Ӧ

typedef struct
{
	int m_iDevId; //���� ,Ŀǰ��GUI_GHOST_NUM
	int m_iType;//0-Ĭ�� 1-����ʵʱ��¼ 2-���̱��ݿ�¼
}TGuiGetSingleFileFormatReq;

typedef struct
{
	int m_iDevId; //���� ,Ŀǰ��GUI_GHOST_NUM
	int m_iType; //0-Ĭ�� 1-����ʵʱ��¼ 2-���̱��ݿ�¼
	int m_iSingleFileFormat;
}TGuiGetSingleFileFormatRsp;

#define GUI_SET_FILE_AUDIO_FORMAT_REQ   5010    //���ñ���/��¼��Ƶ�ļ���ʽ����
#define GUI_SET_FILE_AUDIO_FORMAT_RSP   -5010   //���ñ���/��¼��Ƶ�ļ���ʽ��Ӧ

enum
{
	GUI_FILE_NONE = 0,	//������/��¼��Ƶ�ļ�
	GUI_FILE_AAC,	//����/��¼AAC�ļ�
};


typedef struct
{
	int m_iDevId;         //����  ��Ŀǰ��GUI_GHOST_NUM
	int m_iType;  //0-Ĭ�� 1-����ʵʱ��¼ 2-���̱��ݿ�¼
	int m_iAudioFormat;
}TGuiSetCblAudioFormatReq;


typedef struct
{
	int m_iRetCode;
}TGuiSetCblAudioFormatRsp;


#define GUI_GET_FILE_AUDIO_FORMAT_REQ    5011    //��ȡ����/��¼��Ƶ�ļ���ʽ����
#define GUI_GET_FILE_AUDIO_FORMAT_RSP    -5011   //��ȡ����/��¼��Ƶ�ļ���ʽ��Ӧ

typedef struct
{
	int m_iDevId; //���� ,Ŀǰ��GUI_GHOST_NUM
	int m_iType;//0-Ĭ�� 1-����ʵʱ��¼ 2-���̱��ݿ�¼
}TGuiGetCblAudioFormatReq;

typedef struct
{
	int m_iDevId; //���� ,Ŀǰ��GUI_GHOST_NUM
	int m_iType; //0-Ĭ�� 1-����ʵʱ��¼ 2-���̱��ݿ�¼
	int m_iAudioFormat;
}TGuiGetCblAudioFormatRsp;


#define GUI_SET_VCBINDVODEV_REQ  1150   //����VC���Ǹ�Vo�豸ͬԴ(VGA/HDMI1��HDMI2)����
#define GUI_SET_VCBINDVODEV_RSP  -1150  //����VC���Ǹ�Vo�豸ͬԴ(VGA/HDMI1��HDMI2)��Ӧ
typedef struct
{
	int m_iVcId;  //VCͨ��ID
	int m_iVoDevId; // 0-���� 0x1-VGA/HDMI1  0x2-HDMI2  0x3-VGA/HDMI1/HDMI2
}TGuiSetVcBindVoDevReq;

typedef struct
{
	int m_iRetCode;
}TGuiSetVcBindVoDevRsp;

#define GUI_GET_VCBINDVODEV_REQ  1151 //��ȡVC���Ǹ�Vo�豸ͬԴ(VGA/HDMI1��HDMI2)����
#define GUI_GET_VCBINDVODEV_RSP  -1151  //��ȡVC���Ǹ�Vo�豸ͬԴ(VGA/HDMI1��HDMI2)��Ӧ
typedef struct
{
	int m_iVcId;	//VCͨ��ID
}TGuiGetVcBindVoDevReq;

typedef struct
{
	int m_iVcId;   //VCͨ��ID
	int m_iVoDevId;  // 0-���� 0x1-VGA/HDMI1  0x2-HDMI2  0x3-VGA/HDMI1/HDMI2
}TGuiGetVcBindVoDevRsp;


#define GUI_SET_BESTIR_RESPONSE_REQ 1152 //���ü�����Ӧ����(dvr->app)
#define GUI_SET_BESTIR_RESPONSE_RSP -1152 //���ü�����Ӧ��Ӧ(app->dvr)

enum
{
	GUI_BESTIR_SAVE = 0,
	GUI_BESTIR_START,
	GUI_BESTIR_END,
};

typedef struct
{
	int m_iChn; //��Ӧ��������Ƶͨ����
	int m_iStat; //����״̬ 0-���� 1-����  2-ȡ������
}TGuiSetBestirResponseReq;

typedef struct
{
	int m_iRetCode;
}TGuiSetBestirResponseRsp;

#define GUI_SET_BESTIR_TYPE_REQ 1153 //���ü�����ʽ����
#define GUI_SET_BESTIR_TYPE_RSP -1153 //���ü�����ʽ��Ӧ

enum
{
	GUI_BESTIR_EXCHANGE = 0, //��������
	GUI_BESTIR_SPECIFIC,  //��д����
};

typedef struct
{
	int m_iType;
}TGuiSetBestirTypeReq;
typedef struct
{
	int m_iRetCode;
}TGuiSetBestirTypeRsp;


#define GUI_SET_MIC_TYPE_REQ  1154  //����MIC���ͻ�Ӧ-ͥ������-Ԥ��
#define GUI_SET_MIC_TYPE_RSP  -1154 //����MIC���ͻ�Ӧ-ͥ������
enum
{
	GUI_MIC_HAND_TO_HAND = 0, //������MIC
	GUI_MIC_POT_TO_POT, //��Ե�MIC
};

typedef struct
{
	int  m_iVideoChn;  //MIC��Ӧ����Ƶͨ�� -Ԥ��
	int  m_iAudioChn;  //MIC��Ӧ����Ƶͨ��-Ԥ��
	int  m_iMicType;  //MIC����
}TGuiSetMicTypeReq;

typedef struct
{
	int m_iRetCode;
}TGuiSetMicTypeRsp;

#define GUI_SET_MIC_AUDIO_AMPLITUDE_REQ  1155 //������Ƶ���ֵ����
#define GUI_SET_MIC_AUDIO_AMPLITUDE_RSP  -1155 //������Ƶ�����Ӧ����
typedef struct
{
	int m_iChn; //ͨ����
	int m_iMicId; //MIc��
	int m_iAmplitude; // >= 0
}TGuiSetMicAudioAmplitudeReq;

typedef struct
{
	int m_iRetCode;
}TGuiSetMicAudioAmplitudeRsp;


#define GUI_GET_URLINFO_REQ		1500
#define GUI_GET_URLINFO_RSP		-1500
#define GUI_URL_LEN		128
#define GUI_ID_LEN	32

enum
{
	GUI_ANDROID_ENUM = 1,
	GUI_IOS_ENUM,
	GUI_ID,
};

typedef struct
{
	int m_iType;		//�������ö������
}TGuiGetURLInfoReq;

typedef struct
{
	int m_iType;
	char m_strUrl[0];
}TGuiGetURLInfoRsp;

//�̶�ʽ����������������  

#define GUI_SET_CBL_RESSPACE_REQ	791  //����ʵʱ��¼�Ĺ��̱����ռ�����
#define GUI_SET_CBL_RESSPACE_RSP	-791 //����ʵʱ��¼�Ĺ��̱����ռ��Ӧ
typedef struct
{
	int m_iDvdSpace;  //��λM
}TGuiSetCblResSpaceReq;

typedef struct
{
	int m_iRetCode;
}TGuiSetCblResSpaceRsp;

#define GUI_GET_CBL_RESSPACE_REQ	792	//��ȡʵʱ��¼�Ĺ��̱����ռ�����
#define GUI_GET_CBL_RESSPACE_RSP	-792	//��ȡʵʱ��¼�Ĺ��̱����ռ��Ӧ 
typedef struct
{
	int m_iDvdSpace; //��λM
}TGuiGetCblResSpaceRsp;



///////////////////////////////////////////////////////////////////////323������ȡ���Խ�ģ��ͨ���ں˻�ȡ
//��ȡ�����ļ���ͨ�ýṹ��
#define GUI_GET_CONFIG_VALUE_REQ	793	//��ȡ���ò�������
#define GUI_GET_CONFIG_VALUE_RSP	-793	//��ȡ���ò�����Ӧ

typedef struct
{
	char m_cKeyName[GUI_PUBLIC_LEN_31 + 1];//�ؼ�������
}TGuiKeyValueInfo;

typedef struct
{
	char m_cSectionName[GUI_PUBLIC_LEN_31 + 1];//Section����
	int m_iValueCount;//��Ҫ��ȡ�ֶθ���
	TGuiKeyValueInfo m_pcKeyValueInfo[0];//Key�Ľṹ��ָ��
}TGuiGetConfigValueReq;

typedef struct
{
	char m_cKeyName[GUI_PUBLIC_LEN_31 + 1];//�ؼ�������
	char m_cValue[GUI_PUBLIC_LEN_31 + 1];//ȡֵ
}TGuiGetConfigValueRsp;

#define GUI_SET_CBL_FILE_TYPE_REQ   794 //���ÿ�¼�ļ���������
#define GUI_SET_CBL_FILE_TYPE_RSP   -794 //���ÿ�¼�ļ����������Ӧ

typedef struct
{
	int m_iFileType;  // GUI_AUDIO_ONLY -20  GUI_VIDEO_AUDIO_NEW-3
}TGuiSetCblFileTypeReq;

typedef struct
{
	int m_iRetCode;
}TGuiSetCblFileTypeRsp;

#define GUI_GET_CBL_FILE_TYPE_REQ 795	//��ȡ��¼�ļ���������
#define GUI_GET_CBL_FILE_TYPE_RSP -795  //��ȡ��¼�ļ����ͻ�Ӧ

typedef struct
{
	int m_iFileType;
}TGuiGetCblFileTypeRsp;



//////////////////////////////////////////////////////////////
//=====================����======================
//1�������豸��Ϣ
enum
{
	GUI_CALL_MODEL_TYPE_H323 = 0,
	GUI_CALL_MODEL_TYPE_SIP,
};//��������

enum
{
	GUI_CALL_ONLY_AUDIO = 0,
	GUI_CALL_VIDEO_AUDIO,
};//����ģʽ

typedef struct
{
	int m_iCallType;//��������
	int m_iCallModel;//����ģʽ,��323������ĺ�������
	int m_iCallRate;//��������
	int m_iNetPort;//����˿�
	char m_cIP[GUI_PUBLIC_LEN_31 + 1];//IP��ַ
	char m_cNetNum[GUI_PUBLIC_LEN_31 + 1];//�豸����
	char m_cURI[GUI_PUBLIC_LEN_63 + 1];//URI�ַ�
}TGuiH323CallDevInfo;

#define GUI_GET_H323_CALL_DEVINFO_REQ  20009	//��ȡH323�����豸��Ϣ����
#define GUI_GET_H323_CALL_DEVINFO_RSP  -20009	//��ȡH323�����豸��Ϣ��Ӧ

typedef struct
{
	TGuiH323CallDevInfo m_tInfo;	
}TGuiGetH323CallDevInfoRsp;

#define GUI_SET_H323_CALL_DEVINFO_REQ	20010 //����H323�����豸��Ϣ����
#define GUI_SET_H323_CALL_DEVINFO_RSP	-20010 //����H323�����豸��Ϣ��Ӧ

enum
{
	GUI_H323_SET_TYPE_HUNGUP = 0,	//�Ҷ�
	GUI_H323_SET_TYPE_CALL,		//��Ƶ����
};//��������

typedef struct
{
	int m_iSetType;	//��������
	TGuiH323CallDevInfo m_tInfo;
}TGuiSetH323CallDevInfoReq;


typedef struct
{
	int m_iRetCode;  //0-�ɹ���1-ʧ�� �ù����궨��	
}TGuiSetH323CallDevInfoRsp;

#define GUI_GET_H323_SUB_STREAM_STA_REQ	20015 //��ȡ��������״̬����
#define GUI_GET_H323_SUB_STREAM_STA_RSP	-20015 //��ȡ��������״̬��Ӧ

typedef struct
{
	char m_cIP[GUI_PUBLIC_LEN_31 + 1];//IP��ַ
}TGuiGetH323SubStreamLinkStaReq;

enum
{
	GUI_SUB_STREAM_LINK_FREE_STA = 0,	//����
	GUI_SUB_STREAM_LINK_SEND_STA,		//������
	GUI_SUB_STREAM_LINK_RECEIVE_STA,	//������
};


typedef struct
{
	int m_iLinkSta;  //0:���У�1:�����У�2:������
}TGuiGetH323SubStreamLinkStaRsp;


#define GUI_SET_H323_SUB_STREAM_STA_REQ	20016 //��/�Ͽ���������
#define GUI_SET_H323_SUB_STREAM_STA_RSP	-20016 //��/�Ͽ�������Ӧ

enum
{
	GUI_SUB_STREAM_DIS_CONNECT = 0,	//�Ͽ�����
	GUI_SUB_STREAM_CONNECT,			//����
};

typedef struct
{
	int iState;	//0:�Ͽ������� 1:���Ӹ���
	char m_cIP[GUI_PUBLIC_LEN_31 + 1];//IP��ַ
}TGuiSetH323SubStreamStaReq;

typedef struct
{
	int m_iRetCode;  //0-�ɹ���1-ʧ�� �ù����궨��	
}TGuiSetH323SubStreamStaRsp;


//==============���� �ֶ�ģʽ===========================

#define GUI_GET_H323_CALLMSG_REQ   20011//��ȡ������Ϣ����
#define GUI_GET_H323_CALLMSG_RSP   -20011//��ȡ������Ϣ��Ӧ


typedef struct
{
	char m_strCallMsg[GUI_PUBLIC_LEN_63 + 1];	
}TGuiGetH323CallMsgRsp;


#define GUI_SET_H323_RESPONSE_CMD_REQ   20012//��Ӧ��������
#define GUI_SET_H323_RESPONSE_CMD_RSP   -20012//��Ӧ�����Ӧ

enum
{
	GUI_CMD_TYPE_HANGUP = 0,
	GUI_CMD_TYPE_ANSWER,
};

typedef struct
{
	char m_strCallMsg[GUI_PUBLIC_LEN_63 + 1];
	int m_iCmdType;		
}TGuiSetH323ResponseCmdReq;

typedef struct
{
	int m_iRetCode;	
}TGuiSetH323ResponseCmdRsp;

//2�����ز���
enum
{
	GUI_GK_TYPE_DISABLE = 0,//����
	GUI_GK_TYPE_FIXIP,			//ָ��
	GUI_GK_TYPE_AUTOSEARCH,	//�Զ�����
};//gkģʽ

enum
{
	GUI_GK_ENC_DISABLE = 0,//����
	GUI_GK_ENC_AUTO,//�Զ�
	GUI_GK_ENC_ZTE,//����
	GUI_GK_ENC_NEWTV,//����ͨ
	GUI_GK_ENC_CISCO,//˼��
};//gk���ܷ�ʽ

#define GUI_GET_H323_GK_PARA_REQ   20013//��ȡGK��������
#define GUI_GET_H323_GK_PARA_RSP   -20013//��ȡGK������Ӧ
typedef struct
{
	int m_iGKGroupId;
	int m_iGkType;//gkģʽ
	char m_cGkIP[GUI_PUBLIC_LEN_63 + 1];//gk��ַ
	int m_iGkPort;//gk�˿�
	char m_cGkRegName[GUI_PUBLIC_LEN_63 + 1];//gkע������
	int m_iEncType;//gk���ܷ�ʽ
}TGuiGetH323GKParaRsp;


//3����������
enum
{
	GUI_ENCODE_UTF8 = 0,
	GUI_ENCODE_UNICODE,
};//ID���뷽ʽ
enum
{
	GUI_ANW_TYPE_AUTO = 0,//�Զ�
	GUI_ANW_TYPE_MANUAL,//�ֶ�
	GUI_ANW_TYPE_UNANW,//�����
};//��Ӧ��ʽ

#define GUI_GET_H323_LOCAL_PARA_REQ 20014//��ȡH323���ز�������
#define GUI_GET_H323_LOCAL_PRAR_RSP -20014//��ȡH323���ز�����Ӧ
typedef struct
{
	int m_iGroupId;
	int m_iLisenPort;//���������˿�
	char m_cLocalNo[GUI_PUBLIC_LEN_63 + 1];//�ն˺���
	char m_cPassWord[GUI_PUBLIC_LEN_63 + 1];//��������
	int m_iIdCodeType;//ID���뷽ʽ
	int m_iAnwTypeForCall;//��Ե������Ӧ��ʽ
	int m_iEncMainVideoChn;//��ƵԴ������ͨ��
	int m_iEncSubVideoChn;//��ƵԴ������ͨ��
	int m_iDecMainVideoChn;//������ʾ������ͨ��
	int m_iDecSubVideoChn;//������ʾ������ͨ��
}TGuiGetH323LocalParaRsp;

#define GUI_SET_AUDIO_CHANGE_TAG_REQ  20017 //����ͨ����Ƶ�ı�������
#define GUI_SET_AUDIO_CHANGE_TAG_RSP  -20017 //����ͨ����Ƶ�ı����Ӧ
typedef struct
{
	int m_iChn; //ͨ����
	int m_iSoundStat; //����״̬ 0-���� 1-����
}TGuiSetAudioChangeTagReq;

typedef struct
{
	int m_iRetCode;
}TGuiSetAudioChangeTagRsp;

#define GUI_SET_COMMON_TAG_REQ  20018 //����ͨ�ô������
#define GUI_SET_COMMON_TAG_RSP  -20018 //����ͨ�ô��

typedef struct
{
	int m_iType;//��λ��ʾ��0����δ��ǣ�1������,2-�������к�,4-��Ƶ��ǣ�(ǰ��λ������Э�����)��8-��������,
	int m_iChn; //ͨ����,Ĭ��0������ͨ��,
	int m_iLen; //ʵ�ʱ�ǩ�ĳ��ȣ��64�ֽ�
	char m_cTag[0];
}TGuiSetCommonTagReq;

typedef struct
{
	int m_iRetCode;
}TGuiSetCommonTagRsp;

#define GUI_GET_VITAL_SIGN_CONFIG_REQ	20022	//��ȡ����������������
#define GUI_GET_VITAL_SIGN_CONFIG_RSP	-20022	//��ȡ�����������û�Ӧ

typedef struct
{
	int m_iDeviceId;			//�豸ID����ʱ��0
}TGuiGetVitalSignConfigReq;

typedef struct
{
	int m_iDeviceId;							//�豸ID����ʱ��0
	int m_iPort;									//�˿�
	char m_cIP[GUI_PUBLIC_LEN_63 + 1];		//IP��ַ ��ר�ú꣬���û�м�һ��
}TGuiGetVitalSignConfigRsp;

#define GUI_SET_VITAL_SIGN_CONFIG_REQ	20023	//��������������������
#define GUI_SET_VITAL_SIGN_CONFIG_RSP		-20023	//���������������û�Ӧ

typedef struct
{
	int m_iDeviceId;							//�豸ID����ʱ��0
	int m_iPort;									//�˿�
	char m_cIP[GUI_PUBLIC_LEN_63 + 1];		//IP��ַ ��ר�ú꣬���û�м�һ��
}TGuiSetVitalSignConfigReq;

typedef struct
{
	int m_iRetCode;
}TGuiSetVitalSignConfigRsp;

enum
{
	GUI_VITAL_SIGN_TYPE_HEARTRATE = 1,			//����
	GUI_VITAL_SIGN_TYPE_BLOODOXYGEN,		//Ѫ��
	GUI_VITAL_SIGN_TYPE_BLOODPRESSURE,		//Ѫѹ
	GUI_VITAL_SIGN_TYPE_RESP,     				//����
	GUI_VITAL_SIGN_TYPE_MAX
};//��������


#define GUI_SET_VITAL_SIGN_DATA_REQ		20024	//��������������������
#define GUI_SET_VITAL_SIGN_DATA_RSP		-20024	//���������������ݻ�Ӧ

#define MAX_VITAL_SIGN_DATA_LEN		125			//�����������ε㼯���125����

typedef struct //���������ɼ����ݷ�װ
{
	char m_cVersion;//Э��汾
	char m_cType;	//���������ɼ�����,1������ 2��Ѫ�� 3��Ѫѹ  4 ����
	char m_cMonFlg; //1:����2:������ 3��������4:���� 5:�豸����    
	char m_iOscilloGramSeqID; //��1��ʼ���ĵ�����������δ���1��2��3��Ѫ��һ����ʹ��1
	int m_iMonVal[4]; //����ʵʱֵ, Ѫѹ3��,SYS DIA PR���δ�ţ����ȣ�ԭֵ����100;
	int m_iGramRate;//1s�ж��ٸ���
	int m_iSizeType; // 1:�� 2���� 3��С
	int m_iXPosition; // �������Ƶ�����Ͻ�(0,0)����Ժ�����
	int m_iYPosition; // �������Ƶ�����Ͻ�(0,0)�����������
	int m_iPointLen;
	unsigned char m_cPointValue[0]; //�㼯
}TUserDataVitalSignData;	//��TUserDataVitalSign����һ��

typedef struct 
{
	int m_iType;							//bit0:�Ƿ��ϱ�IE��bit1:�Ƿ񱣴�UserData
	TUserDataVitalSignData m_tVitalSignData;//�����������ݣ���UserDta����һ��
} TGuiSetVitalSignDataReq;

typedef struct
{
	int m_iRetCode;
}TGuiSetVitalSignDataRsp;

//#####################M7����2015###########begin####################//

//��ȡ�豸�Ƿ��Ѿ�������p2p������
#define GUI_GET_DEV_LINK_INTERNET_REQ		1510
#define GUI_GET_DEV_LINK_INTERNET_RSP		-1510
typedef struct
{
	int m_iLinked;       //0��ʾ���� �����ʾδ����
}TGuiGetDevLinkedRsp;      


//��Һ��ں˽���
#define GUI_NOTIFY_DEV_LINK_INTERNET_REQ		1511
#define GUI_NOTIFY_DEV_LINK_INTERNET_RSP		-1511
typedef struct
{
	int m_iLinked;
}TGuiNotifyDevLinkedReq;  //notify ���֪ͨ�ں��Ƿ�����p2p������

typedef struct
{
	int m_iRet;
}TGuiNotifyDevLinkedRsp;

//֡�ʡ����ʡ��ֱ��ʼ�ʱֵ��ȡ
#define	GUI_GET_CHN_ENCODE_CONFIG_REQ		5203
#define	GUI_GET_CHN_ENCODE_CONFIG_RSP		-5203
#define GUI_MAGIC_PICSIZE		-20150917

typedef struct
{
	int m_iChn;
}TGuiGetChnEncodeCfgReq;

typedef struct
{
	int m_iChn;
	int m_iFrmRate;        	//֡��
	int m_iBitRate;			//����
	int m_iPicSize;				//�ֱ��� ,���ΪGUI_MAGIC_PICSIZE�����ʾ��ͨ������Ƶ
	int m_iRemain[4];        //Ԥ��4���ֽ�
} TGuiGetChnEncodeCfgRsp;

//��ת��--��ȡ�豸ͨ�����ʵʱ��Ϣ
#define GUI_GET_DEVICE_IM_STATE_REQ		5205
#define GUI_GET_DEVICE_IM_STATE_RSP		-5205
typedef enum
{
	GUI_BRIGHTNESS = 1,   //����
}EGuiDeviceStateEnum;

typedef struct
{
	int m_iChn;
	int m_iType;
}TGuiGetDeviceImStateReq;

typedef struct
{
	int m_iValue;   //ʵʱֵ
} TGuiGetDeviceImStateRsp;

//��ȡ֧�ֵĲ�ת������
#define GUI_GET_COLOR2GRAYLST_REQ    5206
#define GUI_GET_COLOR2GRAYLST_RSP	 -5206	
typedef struct
{
	int m_iChn;
}TGuiGetColor2GrayLstReq;

typedef struct
{
	int m_iChn;
	int m_iEnable;  //��λ��1: ֧�֣� 0: ��֧��bit0�����Զ�����ͬ����bit1���ڰף�
	//bit2����ɫ��bit3�����Զ�����ͬ��; bit4, ����ͬ�� ;bit5����ʱ��  6--�Զ�����ת����ͬ������ת����ͬ����
}TGuiGetColor2GrayLstRsp;

//��ת�ڲ������û�ȡ
#define GUI_GET_COLOR2GRAY_CNF_REQ		5210
#define GUI_GET_COLOR2GRAY_CNF_RSP		-5210
typedef struct
{
	int m_iChn;
}TGuiGetColor2GrayCnfReq;

typedef struct
{
	int m_iChn;
	int m_iColor2Gray; // 0--�Զ�����ͬ����1--�ڰ�2--��ɫ3--�Զ�����ͬ����4--����ͬ��5--��ʱ6--�Զ�����ת����ͬ������ת����ͬ����
	int m_iDayRange;  //��������ֵ(0~255)������������ֵ���л�Ϊ����
	int m_iNightRange;  // ��������ȵ��ڴ����֣��л�Ϊҹ��(0-255)���������ȸ������ϣ�
	int m_iTimeRange;   // bit24-bit31:����Сʱbit16-bit23:��������bit8-bit15:���Сʱbit0-bit7:��ڷ���
	int m_iColorDelay;	 //��ת����ʱ
	int m_iGrayDelay;  //��ת����ʱ
} TGuiGetColor2GrayCnfRsp;

#define GUI_SET_COLOR2GRAY_CNF_REQ		5211
#define GUI_SET_COLOR2GRAY_CNF_RSP		-5211

typedef  TGuiGetColor2GrayCnfRsp  TGuiSetColor2GrayCnfReq;

typedef struct
{
	int m_iRetCode;   //0��ɹ��������ʧ��
} TGuiSetColor2GrayCnfRsp;

#define GUI_GET_DAYNIGHT_CNF_REQ		5212
#define GUI_GET_DAYNIGHT_CNF_RSP		-5212
typedef struct
{
	int m_iChn;
}TGuiGetDayNightCnfReq;

typedef struct
{
	int m_iChn;
	int m_iDayNightType;      //ģʽ 0-�Զ���1-ҹ��2-����
	int m_iSensitivity;           //������0--�ͣ�1--�У�2--�� (������ֻ���Զ�ʱ����)
}TGuiGetDayNightCnfRsp;

#define GUI_SET_DAYNIGHT_CNF_REQ		5213
#define GUI_SET_DAYNIGHT_CNF_RSP		-5213

typedef TGuiGetDayNightCnfRsp TGuiSetDayNightCnfReq;

typedef struct
{
	int m_iRetCode;   //0��ɹ��������ʧ��	
}TGuiSetDayNightCnfRsp;

//========������ͳ��===
#define GUI_GET_PEOPLE_CNT_REQ		5214	//������ͳ�ƽ������
#define GUI_GET_PEOPLE_CNT_RSP		-5214	//������ͳ�ƽ����Ӧ

typedef struct 
{
	int m_iChn;
	int m_iGranularity;  // ͳ�����ȣ�1--Сʱ��2--�죬3--�ܣ�4--�£�5--�꣩
	int m_iBeginTm;     //��ʼʱ��
	int m_iEndTm;       //����ʱ��
}TGuiGetPeopleCntReq;

typedef struct
{
	int m_iTotalCnt;     //�����n��TGuiPeopleCntCnf��Ϣ
}TGuiGetPeopleCntRsp;   

typedef struct
{
	int m_iChn;
	int m_iBeginTm;
	int m_iInCnt;
	int m_iOutCnt;
}TGuiPeopleCntCnf;


//#####################M7����2015###########end#####################//


//#define GUI_TEST   //ĳЩ���ܵ�����ʹ�ܣ�release�汾Ӧ��ע�͵�
#endif

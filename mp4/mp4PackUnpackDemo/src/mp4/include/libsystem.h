/*******************************************************************
�ļ���	:maintenance.h
��˾	:������ΰҵ����Ƽ����޹�˾
������	:������
��������:2009-10-28
��Ҫ����:ϵͳά��������ݶ��塢�ӿں���ԭ��
�޸ļ�¼:2009-10-28,��������������
        
******************************************************************/

#ifndef _MAINTENANCE_H_
#define _MAINTENANCE_H_

#define IMPORT_CONFIG_FILE				"/tmp/config.box"	//���������ļ������ʱ��ŵ�
#define EXPORT_CONFIG_FILE                      "../tmp/config.box"

#define UPGRADE_V2

//for verifying file head while upgrading
#ifdef UPGRADE_V2
#define DVR_BIN         			(1 << 8)    	//DVR-�ںˣ�ԭΪ1001
#define DVR_WEB         			(2 << 8)    	//DVR-WEB����ԭΪ1002
#define DVR_FS          			(3 << 8)    	//DVR-�ļ�ϵͳ�������ļ���ԭΪ1003

#define DVR_SLAVE					(4 << 8) 		//DVR-������Ƭ�ļ�ϵͳ
#define DVR_GUI						(5 << 8) 		//DVR-����GUI������
#define DVR_STARTUP			        (6 << 8) 		//DVR-������������
#define DVR_CONFIG					(7 << 8)		//DVR-�����ļ�����

//NVS/IPC��
#define	NVS_BIN_S					(1 << 16)	//Sϵ��-1/4·�ں�
#define	NVS_WEB_S					(2 << 16)	//Sϵ��-Web����
#define	NVS_BIN_FS					(3 << 16)	//Sϵ��-�ļ�ϵͳ�������ļ�����
#define	NVD_BIN_S					(4 << 16)	//Sϵ��-�������ں�


#define BOX_FILE_NAME_LEN			128

#define BOX_FILE_HEADER_LEN 176


#define CHIP_All		0X0	//������������оƬ������������ƥ��ʱ���Ը�����
#define CHIP_HI3531	0X1	//Hi3531
#define CHIP_HI3521	0X2	//Hi3521/Hi3520A
#define CHIP_HI3520D	0X3	//Hi3520D/Hi3515A
#define CHIP_HI3535	0X4	//Hi3535
#define CHIP_HI3518A	0X5	//Hi3518A/ Hi3518C/Hi3516C
#define CHIP_HI3516	0X6	//Hi3516
#define CHIP_TI8127	0X7	//TI8127


#else
#define DVR_BIN         				1001    	//DVR-�ں�
#define DVR_WEB         				1002    	//DVR-WEB����
#define DVR_FS          				1003    	//DVR-�ļ�ϵͳ�������ļ�
#define DVR_SLAVE					1004		//DVR-������Ƭ�ļ�ϵͳ
#define DVR_GUI						1005		//DVR-����GUI������
#define DVR_STARTUP				1006		//DVR-������������
#define DVR_CONFIG					1007		//DVR-�����ļ�����

#define BOX_FILE_NAME_LEN			32
#endif


//�ļ�ͷ�ṹ��
typedef struct
{
    unsigned char	cCompany[8];	//= "Tiandy"	
    unsigned int	u32Filesize;	//�ļ��ܴ�С�������ļ�ͷ
    unsigned int	u32ProductID;	//��ƷID��NVS-S�ں˳���=1��NVS-S��ҳ����=2���������ж���
    unsigned int	u32Version;		//�汾�ţ��̶�����
    unsigned int	u32Reserved;	//����
    unsigned long long u64Checknum; //У��ͣ�64λ����Windows����Ҫ�� long long ����
}T_BFHeader;

//ϵͳ�˳�ʱ��ѡ��
typedef enum
{
	EXIT_SAVE_CONFIG = 0,										//���������ļ�
	EXIT_STOP_FEEDDOG,											//ֹͣι��
	EXIT_DISABLE_DOG,											//������Ϊ��ʹ��
	EXIT_STOP_PEVIEW,
}TExitParam;

//����ģʽ
typedef enum
{
	WORK_MODE_NORMAL,											//�����Ĺ���ģʽ
	WORK_MODE_GUIDE,											//�򵼹���ģʽ
	WORK_MODE_SAFE,												//��ȫ����ģʽ
	WORK_MODE_TEST,												//���Թ���ģʽ
	WORK_MODE_MAX,												//����ģʽ��Ŀ���µ�ģʽ���������
}TWorkMode;

//zhangsheng �Զ�ά��
typedef struct
{
	td_s32 m_iRebootDay;
	td_s32 m_iReboottime;//����������������
}TSysAutoMaintain;

int UpgradeWebPageReType(int _len, td_u8* _buf);
int UpgradeWebPageAnalyse(int _len, td_u8* _buf);
int UpgradeWebPagestart(td_u8* _buf,int *_pipos);

int UpgradeProgam(int _len, td_u8* _buf);

int UpgradeWebPage(int _len, td_u8* _buf);

td_s32 mtn_Upgrade(td_u8* _pcIP, td_u8* _pcFileName, td_u8* _pcUserName, td_u8* _pcPassWd);
/*
 * �������ƣ�Upgrade
 * ��Ҫ���������������ļ�,ͨ��FTP����ͨ��USB�豸��
 * ��	  �룺
 *			_pcIP,FTP��������ַ���� 10.10.60.200�����Ϊ�����ʾ����ͨ��USB����
 *			_pcFileName,�������ļ������ǿ�,�� /ftp/update/blade.bin
 *			_pcUserName,FTPվ���û������ǿ� �� Admin
 *			_pcPassWd,FTPվ������,�ǿ�, �� Admin
 * ��	 ����
 * 			ERR_SYS_NO_FILE, �޿��������ļ�
 *			ERR_SYS_OTHER_UPDATING, �����ͻ������ڽ�������
 *			ERR_SYS_NO_FTP, �޿���FTPվ��
 *			ERR_SYS_WRONG_PARAM, ����Ĳ���
 *			ERR_SYS_FAILED, ����ԭ����ʧ��
 * 			ERR_SYS_SUCCESSFUL,�����ɹ�
 * �޸���־��
 * 			2008-12-09,������,����
 */

td_s32 mtn_ValidFileList(char _cFileList[][256], td_s32* _piFileNum);
/*
 * �������ƣ�ValidFileList
 * ��Ҫ������ͨ��FTP��������
 * ��	  �룺
 *			_pcIP,FTP��������ַ���ǿ�,�� 10.10.60.200
 *			_pcFileName,�������ļ������ǿ�,�� /ftp/update/blade.bin
 *			_pcUserName,FTPվ���û������ǿ� �� Admin
 *			_pcPassWd,FTPվ������,�ǿ�, �� Admin
 * ��	 ����
 * 			ERR_SYS_NO_FILE, �޿��������ļ�
 *			ERR_SYS_OTHER_UPDATING, �����ͻ������ڽ�������
 *			ERR_SYS_NO_USB, �޿��õ�USB�豸
 *			ERR_SYS_WRONG_PARAM, ����Ĳ���
 *			ERR_SYS_FAILED, ����ԭ����ʧ��
 * 			ERR_SYS_SUCCESSFUL,�����ɹ�
 * �޸���־��
 * 			2008-12-09,������,����
 */

td_s32 mtn_IpcValidFileList(char _cFileList[][256], td_s32* _piFileNum);
 
//td_s32 sys_UpdateApp(td_s32 _iUpdateType, td_u8* _iFtpAddr);
/*
 * �������ƣ�UpdateApp
 * ��Ҫ�����������ں˳���
 * ��	  �룺
 			_iUpdateType,�������ͣ�GUI_SYS_UPDATE_USE_USB �� GUI_SYS_UPDATE_USE_FTP
 * 			_iFtpAddr�� FTP��ַ���ǿ�
 * ��	 ����
 * 			ERR_SYS_NO_FILE, �޿��������ļ�
 *			ERR_SYS_NO_USB, �޿���USB�洢�豸
 *			ERR_SYS_NO_FTP, �޿���FTPվ��
 *			ERR_SYS_WRONG_PARAM, ����Ĳ���
 *			ERR_SYS_FAILED, ����ԭ����ʧ��
 * 			ERR_SYS_SUCCESSFUL,�����ɹ�
 * �޸���־��
 * 			2008-12-09,������,����
 *			2009-12-07,������������FTP���������˲������ýӿ�ֹͣʹ��
 */

td_s32 mtn_UpdateProgress(void);
/*
 * �������ƣ�UpdateProgress
 * ��Ҫ��������ȡ�����ں˳������
 * ��	  �룺
 *			��
 * ��	 ����
 * 			
 *			-1, ����ԭ��������ʧ��
 *			-2, �Ҳ���USB�豸
 *			-3, �Ҳ����ļ�
 *			-4, �޷�����FTPվ��
 *			>0, ����״̬��������ʾ����
 * �޸���־��
 * 			2009-01-09,������,����
 */
 
td_s32 mtn_BackupApp(void);
/*
 * �������ƣ�BackupApp
 * ��Ҫ���������ݵ�ǰ�ں˳���
 * ��	  �룺
 			��
 * ��	 ����
 * 			ERR_SYS_OPEN_FILE_ERROR, ���ļ�ʧ��
 *			ERR_SYS_READ_FILE_ERROR, ���ļ�ʧ��
 *			ERR_SYS_WRITE_FILE_ERROR, д�ļ�ʧ��
 *			ERR_SYS_SYSTEM_ERROR, ִ��ϵͳ����ʧ��
 *			ERR_SYS_FAILED, ����ԭ����ʧ��
 * 			ERR_SYS_SUCCESSFUL,�����ɹ�
 * �޸���־��
 * 			2008-12-09,������,����
 */


td_s32 mtn_UpdateTime(void);
/*
 * �������ƣ�UpdateTime
 * ��Ҫ����������ϵͳʱ��
 * ��	  �룺
 * 			��
 * ��	 ����
 * 			ERR_SYS_WRONG_PARAM,����Ĳ���
 * 			ERR_SYS_SUCCESSFUL,��ʼ���ɹ�
 * �޸���־��
 * 			2008-12-03,������,����
 */
 
td_s32 mtn_SetTime(td_s32 _iYear, td_s32 _iMon, td_s32 _iDay, td_s32 _iHour, td_s32 _iMin, td_s32 _iSec);
/*
 * �������ƣ�SetTime
 * ��Ҫ����������ϵͳʱ��
 * ��	  �룺
 * 			6�����Ͳ����ֱ�Ϊ�ꡢ�¡��ա�ʱ���֡���
 * ��	 ����
 * 			ERR_SYS_WRONG_PARAM,����Ĳ���
 * 			ERR_SYS_SUCCESSFUL,��ʼ���ɹ�
 * �޸���־��
 * 			2008-11-25,������,����
 */
 
td_s32 mtn_GetTime(td_s32 * _piYear, td_s32 * _piMon, td_s32 * _piDay, td_s32 * _piHour, td_s32 * _piMin, td_s32 * _piSec);
/*
 * �������ƣ�GetTime
 * ��Ҫ��������ȡϵͳʱ��
 * ��	  �룺
 * 			6������ָ��ֱ����ڴ����ꡢ�¡��ա�ʱ���֡���
 * ��	 ����
 * 			ERR_SYS_WRONG_PARAM,����Ĳ���
 * 			ERR_SYS_SUCCESSFUL,��ʼ���ɹ�
 * �޸���־��
 * 			2008-11-25,������,����
 */


void mtn_StartUI(void);
/*
 * �������ƣ�StartUI
 * ��Ҫ����������UI
 * ��	  �룺
 			��
 * ��	 ����
 * 			��
 * �޸���־��
 * 			2008-12-18,������,����
 */

td_s32	sys_Exit(td_u8 _cParam);
/*
 * �������ƣ�Exit
 * ��Ҫ������ȥ��ʼ��ϵͳ����ģ��
 * ��	  �룺
 * 			_cParam, �˳�ϵͳ�Ĳ���:bit0,�Ƿ񱣴������ļ���bit1,�Ƿ�ֹͣι��;bit2:�Ƿ񽫹���Ϊ��ʹ��
 * ��	 ����
 * 			ERR_SYS_WRONG_PARAM,����Ĳ���
 * 			ERR_SYS_SUCCESSFUL,��ʼ���ɹ�
 * �޸���־��
 * 			2008-11-25,������,����
 */
 
void mtn_Reboot(int level,char* msg);
/*
 * �������ƣ�Reboot
 * ��Ҫ��������������
 * ��	  �룺
 			level, 0~6, ��¼��־�ļ���
 			msg, �ǿգ���¼��־������
 * ��	 ����
 * 			��
 * �޸���־��
 * 			2008-12-31,������,��NerServer.c����System.c
 */
 
void mtn_ShutDown(td_s32 _iParam);

/*
 * �������ƣ�ShutDown
 * ��Ҫ�������ػ����ú���ֻ��ִ�г���İ�ȫ�˳������������Ĺر��豸
 * ��	  �룺
 * 			��
 * ��	 ����
 * 			��
 * �޸���־��
 * 			2008-12-06,������,����
 */

void mtn_Reset();
/*
 * �������ƣ�Reset
 * ��Ҫ��������λ�����ָ���������
 * ��	  �룺
 * 			��
 * ��	 ����
 * 			��
 * �޸���־��
 * 			2009-10-29,������,������
 */

td_s32 mtn_Init(void);
/*
 * �������ƣ�Init
 * ��Ҫ��������ʼ��ϵͳά��ģ��
 * ��	  �룺
 * 			��
 * ��	 ����
 * 			ERR_SYS_SUCCESSFUL, ��ʼ���ɹ�
 *			ERR_SYS_FAILED,	��ʼ��ʧ��
 * �޸���־��
 * 			2010-02-02,������,������
 */

td_s32 mtn_ValidConfigFileList(char _cFileList[][256], td_s32* _piFileNum);
/*
 * �������ƣ�ValidConfigFileList
 * ��Ҫ��������ȡ���������ļ��б�
 * ��	  �룺
 * 			_cFileList, ���ڴ����ļ��б�
 *			_piFileNum, ���ڴ����ļ�����
 * ��	 ����
 * 			ERR_SYS_WRONG_PARAM,����Ĳ���
 *			ERR_SYS_NO_USB, �޿���U��
 *			ERR_SYS_NO_FILE, �޿��������ļ�
 * 			ERR_SYS_SUCCESSFUL, ��ȡ�ɹ�
 * �޸���־��
 * 			2010-04-13,������,����
 */

td_s32 mtn_ImportConfigFile(td_u8* _pcSrcFile);
/*
 * �������ƣ�ImportConfigFile
 * ��Ҫ���������������ļ�
 * ��	  �룺
 * 			_pcSrcFile, ��������ļ����ǿ�
 * ��	 ����
 * 			ERR_SYS_WRONG_PARAM,����Ĳ���
 * 			ERR_SYS_SUCCESSFUL,����ɹ�
 * �޸���־��
 * 			2010-04-13,������,����
 */

td_s32 mtn_ExportConfigFile(td_s32 _iDstDevice, td_s32 _iPartNo, td_u8* _pcDstFile);
/*
 * �������ƣ�ExportConfigFile
 * ��Ҫ���������������ļ�
 * ��	  �룺
 * 			_iDstDevice, Ŀ��U�̱�ţ� һ��Ϊ0
 *                 _iPartNo, Ŀ��U�̷�����20120209�����
 *			_pcDstFile, Ŀ���ļ��������Ϊ�ս��Զ����졣
 * ��	 ����
 * 			ERR_SYS_WRONG_PARAM,����Ĳ���
 *			ERR_SYS_ALPHA_DIGIT_ONLY, �ļ�����ֻ��������ĸ������
 * 			ERR_SYS_SUCCESSFUL,��ʼ���ɹ�
 *			ERR_SYS_NO_USB, �޿���U��
 * �޸���־��
 * 			2010-04-13,������,����
 *                 2012-02-09,����,����
 */

td_s32 mtn_RecoverSlaveSuit(td_s32 _iFlag);
td_s32 mtn_BackupSlaveSuit(td_s32 _iFlag);

td_s32 mtn_SetWorkMode(td_s32 _iWorkMode);
//��ȡ����ģʽ
td_s32 mtn_GetWorkMode(void);
//����ԭʼ�ļ�
td_s32 mtn_BackupImage(void);




//int extractStream(td_u8* _buf,char* _pDstPath,int _iMv);

//*************************�汾����**************************//
const td_s8 *ver_Core();
const td_s8 *ver_Ocx();
const td_s8 *ver_Gui();
const td_s8 *ver_App();
const td_s8 *ver_Slave();
const td_s8 *ver_Sdk();
td_s32 ver_SetGui(const td_s8* _version);
td_s32 ver_SetSlave(const td_s8* _version);
td_s32 ver_setApp(const char *_version);
//���õ�Ƭ���汾
td_s32 ver_SetSingleChip(const td_char *_pcSingleChip);
//��ȡ��Ƭ���汾
const char *ver_GetSingleChip();


//for decoder
int Dec_UpgradeLogo(int _len, char* _buf);

//����ͨ������
void sys_ChnHeart(unsigned long _ulType);
void sys_TstChnHeart(unsigned long _ulType);
void sys_AutoMaintain(unsigned long _param);//by zhangsheng

void mtn_SetDBStatFlg(td_s32 _iStat);
void mtn_SetRebldProgress(int _iProgress);
void mtn_CheckDBStat(unsigned long _param);
long long CombinDataCheckSum(td_u8 *_pcData, int _iSize);

td_s32 CombineFiles(td_u8* _cFileList[64], td_u8* _pcDstFile,int _iOffset);

#endif /*_MAINTENANCE_H_*/


/*******************************************************************
�ļ���	:DiskManagement.h
��˾	:������ΰҵ����Ƽ����޹�˾
������	:������
��������:2008-08-29
��Ҫ����:���̹�����ر�������Ķ��壬�ӿں���ԭ��
�޸ļ�¼:2008-08-29,������������
        
******************************************************************/

#ifndef DISKMANAGMENT_H_
#define DISKMANAGMENT_H_

#include "smart.h"
#include "td_types.h"

#ifndef FULL_PATH_LEN
#define FULL_PATH_LEN		64
#endif

#define DEV_PATH	 "/dev"
#define SATA_PATH    "/mnt/sata" //SATAӲ�̹��ظ�Ŀ¼
#define USB_PATH     "/mnt/usb" //USB�豸����Ŀ¼
#define NFS_PATH      "/mnt/nfs"  //NFS����Ŀ¼
#define ESATA_PATH   SATA_PATH   //eSATA�豸����Ŀ¼
#define SDCARD_PATH   "/mnt/sdcard"   //SdCard�豸����Ŀ¼
#define DB_FILE_NAME  "index.db"//�½����ݿ��ļ���
#define MAX_BAD_FILE_SYSTEM	16		//���ֻ���ļ�ϵͳ����

//����Э����Ӳ��ID�趨
#define BASEID_HDD_GROUP0  0    //��Э���Ӳ����ʼ�豸��
#define BASEID_HDD_GROUP1  1008 //����չ��Ӳ����ʼ�豸��
#define DEVNUM_HDD_GROUP   8    //Ӳ�̱�ŷ��飬ÿ����Ӳ�̸���
#define BASEID_VD          2000 //VD��ʼ�豸��
#define BASEID_IPSAN       3000 //IPSAN��ʼ�豸��
#define BASEID_USB         8    //USB��ʼ�豸��
#define BASEID_ESATA       32   //eSATA��ʼ�豸��
#define BASEID_ESATA_UK    14   //UKЭ���eSATA��ţ�������Э�鲻ͬ
#define BASEID_SD          50   //SDCARD��ʼ�豸��


//Ӳ����;
typedef enum
{
	RECORD = 0,									//¼��
	BACKUP,										//����
	REDUNDANCE,
	READONLY,
}TDiskUsage;

//�ļ�ϵͳ����
typedef enum
{
	FS_EXT3 = 0,		//ext3�ļ�ϵͳ
	FS_EXT2,			//ext2�ļ�ϵͳ
	FS_FAT32,			//FAT32�ļ�ϵͳ
}TFSType;

//�洢������
typedef enum
{
	DISK_USB = 1,	//USB�洢�豸
	DISK_NFS,		//�����ļ�ϵͳ
	DISK_SATA,		//SATAӲ��
	DISK_RECORDER,	//DVR��¼��
	DISK_ESATA,
	DISK_SD,        //SDCard
}TDiskType;

typedef enum
{
	FORMAT_MODE_NORMAL = 0,	//������ʽ��
	FORMAT_MODE_FAST = 1, 	//���ٸ�ʽ��
}TFormatMode;

//��ʽ�����̲���
typedef struct
{
	td_s32 		m_iDiskNo;					//���ڸ�ʽ���Ĵ��̱��
	TFSType 	m_eFsType;					//�ļ�ϵͳ����
	TFormatMode m_eMode;					//��ʽ�����ͣ����ٻ�������
}TFormatArg;

//����״̬
typedef enum
{
	STATE_NONE = 0,								//��ͨ���޴���
	STATE_UNFORMATED,							//�ô���δ��ʽ��
	STATE_FORMATED,								//�ô����Ѹ�ʽ��
	STATE_MOUNTED,								//�ô����ѹ���
	STATE_USING,								//�ô��̵�ǰ���ڶ�д
}TDsikState;

//������Ϣ
typedef struct
{
	td_u32		m_uiDiskNo;							//���̱��
	td_u64		m_ulTotalSize;						//�����ܴ�С,��λBytes
	td_u64		m_uldleSize;						//ʣ��ռ��С����λBytes
	td_u64		m_ulUsedSize;						//��ʹ�õĿռ��С����λBytes
	td_s32		m_iPartNum;							//������Ŀ
	//TDsikState	m_blHasFormated;				//�Ƿ��ʽ��
	TDsikState	m_eState;							//����״̬���޴��̣�δ��ʽ�����Ѹ�ʽ��
	td_u8		m_ucDeviceFilePath[FULL_PATH_LEN];	//�豸�ļ�·��
	td_u8		m_blSleeping;						//�Ƿ�����
	time_t		m_tLastActiveTime;					//����Ծʱ��
	TDiskType	m_eDiskType;						//�洢�豸����
	TDiskUsage  m_eUsage;							//��;��TDiskUsage
}TDiskInfo;

typedef enum
{
	ALL_DISK = 0,
	SATA,
	USB,
	NFS,
	ESATA,
	SDCARD,
}TDiskTypeNum;

//������Ϣ
typedef struct
{
	td_u8		m_ucPart;								//�������
	td_u64		m_ulTotal;								//�ܷ�����С
	td_u64		m_ulFree;								//ʣ��ռ��С
	td_u64		m_ulUsed;								//��ʹ�ÿռ��С
}TPartInfo;

typedef struct
{
	td_s32 m_iDiskId; //����id��
	td_s32 m_iDiskPartId; //���̷���id ��
	td_s32 m_iDiskPartWriteProtect;					//���̷���д����
	char m_strDiskName[32]; //������
	td_u64 m_ullDiskPartSize; 			//���̷�����С
	td_u64 m_ullDiskPartUsed;			//���̷������ÿռ�
	td_u64 m_ullDiskPartFree;			//���̷������пռ�
}TDiskPartMsg;

td_s32 disk_FormatDisk(td_s32 _iDiskNo,td_s32 _iFSType, td_s32 _iMode);
/*
 * �������ƣ�FormatDisk
 * ��Ҫ��������ʽ��Ӳ��
 * ��	 ��:
 * 			_iDiskNo,���̱�ţ�0~MAX_DISK_NUM
 * 			_iFSType,�ļ�ϵͳ���ͣ�TFSType
 * ��	 ��:
 * 			ERR_REC_SUCCESSFUL,��ʽ���ɹ�
 * 			ERR_REC_WRONG_PARAM,����Ĳ���
 * �޸���־��
 * 			2008-08-29,������������
 */
td_s32 disk_PartDisk(td_s32 _iDiskNo,td_s32 _iPartNum,td_s32 _blIfFormat);
/*
 * �������ƣ�PartDisk
 * ��Ҫ���������̷���
 * ��	 ��:
 * 			_iDiskNo,���̱�ţ�0~MAX_DISK_NUM
 * 			_iPartNum,������Ŀ��1~MAX_PARTITION_NUM
 * 			_blIfFormat,�������Ƿ�������ʽ��������ֵ
 * ��	 ��:
 * 			ERR_REC_SUCCESSFUL,�����ɹ�
 * 			ERR_REC_WRONG_PARAM,����Ĳ���
 * �޸���־��
 * 			2008-08-29,������������
 */
td_s32 disk_IsCheckDiskExist(td_s32 _iDisk);
 /*
  * �������ƣ�IsCheckDiskExist
  * ��Ҫ���������̴���ε��ļ��
  * ��	  ��:��
  * ��	  ��:�����Ĵ��̱��
  * �޸���־��
  * 		 2012-12-21,���ڣ�����
  */

 td_s32 disk_GetDiskNum(TDiskTypeNum _iType);
 /* ��������:GetDiskNum
  * ��Ҫ����:��ȡSATA���̵���Ŀ
  * ��	  ��:
  			_iType,���ڴ���Ҫ��ȡ���ִ��̵���Ŀ��
  *			
  * ��	  ��:
  *			 0 ��ʾ�����޴���
  			 > 0 ��ʾ���ش�����
  *			
  * �޸���־:
  *			 2011-03-15,yjq �޸�
  */
 td_s32 disk_GetDiskInfo(td_s32 _iDiskNo, TDiskInfo* _pstInfo);
 /* ��������:GetDiskInfo
  * ��Ҫ����:��ȡ��Ӧ���̺ŵ���Ϣ
  * ��	  ��:
  *			 _iDiskNo,���̱��,0~MAX_DISK_NUM
  *			 _pstInfo,���ڴ���������Ϣ���ǿ�
  * ��	  ��:
  * 		 ERR_REC_SUCCESSFUL����ȡ������Ϣ�ɹ�
  * 	     ERR_REC_WRONG_PARAM,����Ĳ���
  * �޸���־:
  *			 2008-09-18,������������
  */
 td_s32 disk_GetFormatProgress(td_s32 _iDiskNo, td_s32* _pucP);
 /* ��������:GetFormatProgress
  * ��Ҫ����:��ȡ��ǰ��ʽ���Ľ���
  * ��	  ��:
  *			 _iDiskNo,���ڸ�ʽ���Ĵ��̱��
  *			 _pucP,���ڴ�����ǰ���̸�ʽ���Ľ���
  * ��	  ��:
  * 		 ERR_REC_SUCCESSFUL,��ȡ�ɹ�
  * 		 ERR_REC_WRONG_PARAM,����Ĳ���
  * �޸���־:
  * 		 2008-09-18,������������
  */

 td_s32 disk_SetDiskUsage(td_s32 _iDiskNo, TDiskUsage _eUsage);
 
 /* ��������:SetDiskUsage
  * ��Ҫ����:��ȡ��ǰ��ʽ���Ľ���
  * ��	  ��:
  *			 _iDiskNo,���̱��,0~MAX_DISK_NUM
  *			 _eUsage,��;��¼��򱸷�
  * ��	  ��:
  * 		 ERR_REC_SUCCESSFUL,��ȡ�ɹ�
  * 		 ERR_REC_WRONG_PARAM,����Ĳ���
  * �޸���־:
  * 		 2008-10-23,������������
  */
 td_s32 disk_DMInit(void (*_ReportDiskInitNum)(int));
 /*
  * ��������:DMInit
  * ��Ҫ����:��ʼ�����̹���ģ�飬����SATA��NFS������USB�����߳�
  * ��	  ��:
  *			 ��
  *	��	  ��:
  *			 ERR_REC_SUCCESSFUL,��ʼ���ɹ�
  * �޸���־:
  *			 2008-09-25,������������
  */


#define VIR_DISK_NUMBER			Cfg_gFlyBurnSataNum()	//������̱��
td_s32 disk_GetDistIsExist(void);
/*
 * ��������:disk_GetDistIsExist
 * ��Ҫ����:��ȡ�Ƿ���Ӳ��
 * ��	 ��:
 *          ��
 * ��	 ��:
 *			��ɹ��򷵻�td_success��ʧ���򷵻�td_failure
 * �޸���־:
 *			2015-05-14,wzq��������
 */
 td_s32 disk_DMExit();
 /*
  * ��������:DMExit
  * ��Ҫ����:��ȫ�˳����̹���ģ��
  * ��	  ��:
  *			 ��
  * ��	  ��:
  *			 ERR_REC_SUCCESSFUL,�˳��ɹ�
  * �޸���־:
  *			 2008-09-25,������������
  */

 td_s32 disk_UMountNfs();
 /*
  * ��������:UMountNfs
  * ��Ҫ����:ж�������ļ�ϵͳ
  * ��	  ��:
  *			 ��
  * ��	  ��:
  *			 ERR_REC_SUCCESSFUL,ж�سɹ�
  *			 ERR_REC_UMOUNT_NFS_FAILED, ж��ʧ��
  * �޸���־:
  *			 2008-09-25,������������
  */
  
 td_s32 disk_MountNfs(td_s8 * _pcArg);
 /*
  * ��������:MountNfs
  * ��Ҫ����:���������ļ�ϵͳ
  * ��	  ��:
  *			 _pcArg, ���������ļ�ϵͳ�����������ʽΪIP:Path
  * ��	  ��:
  *			 ERR_REC_SUCCESSFUL,���سɹ�
  *			 ERR_REC_WRONG_PARAM, ��������
  *			 ERR_REC_MOUNT_NFS_FAILED,����ʧ��
  * �޸���־:
  *			 2008-09-25,������������
  */

void disk_NeedSleepTimer(unsigned long param);
 /*
  * ��������:NeedSleepTimer
  * ��Ҫ����:Ӳ�����߼�ⶨʱ��
  * ��	  ��:
  *			 ��
  * ��	  ��:
  *			 ERR_REC_SUCCESSFUL,���ɹ�
  *			 ERR_REC_FAILED
  * �޸���־:
  *			 2008-01-16,������������
  */

void disk_WakeUpDisk(td_s32 _iDiskNo);
 /*
  * ��������:WakeUpDisk
  * ��Ҫ����:���Ѵ���
  * ��	  ��:
  *			 _iDiskNo, SATA���̱��,0~MAX_SATA_NUM
  * ��	  ��:
  *			 ��
  * �޸���־:
  *			 2010-01-20,������������
  */
  
td_s32 disk_FormatFail(td_s32 _iDiskNo);
 /*
  * ��������:FormatFail
  * ��Ҫ����:��ʽ������ʧ�ܵĻص�����
  * ��	  ��:
  *			 _iDiskNo, ���̱��,0~MAX_DISK_NUM
  * ��	  ��:
  *			 ERR_REC_SUCCESSFUL,�����ɹ�
  *			 ERR_REC_WRONG_PARAM, ����Ĳ���
  * �޸���־:
  *			 2009-04-07,������������
  */

td_s32 disk_GetUSBPath(td_s32 _iUsbNo, td_s32 _iPartNo, td_u8* _pcPath);
/*
 * ��������:GetUSBPath
 * ��Ҫ����:��ȡĳ��USB���̷����Ĺ���·��
 * ��	  ��:
 *			 _iUsbNo, U�̱��,0~MAX_USB_NUM
 *			 _iPartNo, �������,0~MAX_PART_NUM
 *			 _pcPath, ��������·�����ǿ�
 * ��	  ��:
 *			 ERR_REC_SUCCESSFUL,�����ɹ�
 *			 ERR_REC_WRONG_PARAM, ����Ĳ���
 *			 ERR_REC_WRONG_DISK,����Ĵ��̱�Ż��߷������
 * �޸���־:
 *			 2009-12-06,������������
 */
	
//Not interface
//td_s32 extract_file_path(td_u8* _pucFilePath);
//td_s32 make_dir(td_u8* _pcDirName);

td_s32 disk_GetDiskPartMsg(td_s32 _iDiskNo, td_s32 _iPartNo, TDiskPartMsg* _tMsg);

td_s32 disk_AddBadFileSystem(td_u8* _pcPath);
td_s32 disk_DelBadFileSystem(td_u8* _pcPath);

td_s32 disk_IsBadFileSystem(td_u8* _pcPath);
td_s32 disk_InitBadFileSystem(void);
td_s32 disk_GetMountNfsFlag(); //��ȡ�Ƿ���Ҫ����NFS��ʶ
td_s32 disk_SetMountNfsFlag(td_s32 _iFlag); //���ù���NFS��ʶ

td_s32 disk_SetInUseDiskNo(td_s32 _iDiskNo); //�����˵��� td_s32 rec_DataBaseDiskNo(void); �ӿ�

// ������Ϣ֪ͨ
typedef enum
{
	FORMATE_INUSE_DISK, //��ʽ��ʹ�ô���
	DISK_READY,			//�д���׼����
	NFS_MOUNT,			//NFS����
	NFS_UNMOUNT,		//NFSж��
	USB_MOUNT,		//USB����
	ESATA_MOUNT,		//eSATA����
	SATA_PART,		//���̷���
}TEN_DiskSetNotify;

typedef void (*disk_Notify)(td_s32 _iAction, td_s32 _iDisk);
td_s32 disk_SetNotify(disk_Notify _Notify);

const TDiskInfo *disk_GetDiskInfoArray();
td_u8* disk_GetBadFileSystem(td_s32 _iBad);

td_s32 disk_GetSmartMsg(td_s32 _iDiskNo, TSmartMsg *_ptMsg, int _iMaxCnt);
td_s32 disk_SetSmartStatus(td_s32 _iDiskNo, td_s32 _iStatus);
td_s32 disk_GetSmartBasicMsg(td_s32 _iDiskNo, TSmartBasicMsg *_ptMsg);
//20121115 ����add ��U��ʵ��ж�ؼ��ع���
int disk_UmonutMountUsbEx(int _iDiskNo, char *_strPath);
#define disk_UmonutMountUsb(_iDiskNo)	disk_UmonutMountUsbEx(_iDiskNo, NULL)
#define disk_UmonutMountUsbPath(_strpath)	disk_UmonutMountUsbEx(0, _strpath)
td_s32 disk_GetExistDisks();

td_s32 disk_StopSata(td_s32 _iDiskNo);
char* disk_GetDevName(char* _pcDevName, td_s32 _iDiskNo);
td_s32 disk_DisknoToUniqID(td_s32 _iDiskNo);
td_s32 disk_HddnoToUniqID(td_s32 _iHddNo);
td_s32 disk_UniqIDToDiskno(td_s32 _iUniqID);

td_s32 raid_Init();
td_s32 raid_StartUp();
td_s32 raid_Shuwdown();
td_s32 raid_GetVDInfo(TRaidVdStat *_pstRaidVdStat, td_s32 *_piTotal);
td_s32 raid_GetRAIDInfo(TRaidArrayStat *_pstRaidArrayStat, td_s32 *_piTotal);
td_s32 raid_CreateRAID(td_s8 *_pcRaidName, td_s32 _iRaidType, td_s32 *_piDisklist, td_s32 _iTotal);
td_s32 raid_DeleteRAID(td_s8 *_pcRaidName);
td_s32 raid_RebuildRAID(td_s8 *_pcRaidName, td_s32 *_piDisklist, td_s32 _iTotal);
td_s32 raid_GetVDCfgMsg(td_s32 _iNo, TRaidVdCfg *_pstRaidVdCfg);
td_s32 raid_GetRaidStat(td_s32 *_piEnable);
td_s32 raid_GetHDInfo(TSataDiskCfg *_pstSataDiskCfg, td_s32 *_piTotal);
td_s32 raid_GetRaidArrayCfgMsg(td_s32 _iNo, TRaidArrayCfg *_pstRaidArrayCfg);
td_s32 raid_AddSpare(td_s32 _iHddNo, td_s8 *_pcRaidName, td_s32 _WorkMode);
td_s32 raid_DelSpare(td_s32 _iHddNo, td_s8 *_pcRaidName, td_s32 _WorkMode);
td_s32 raid_CreateVD(TRaidVdCfg * _pstRaidVdCfg);
td_s32 raid_DeleteVD(td_s8 *_pcVDName);
td_s32 raid_RebuildVD(td_s8 *_pcVDName);
#if JMB39X == ON
td_s32 raid_JMB393_MapDisc(int _iDisk);
void raid_JMB393_ScanDisc(int _iDisk);
#endif

#endif //DISKMANAGMENT_H_


#ifndef _LIB_DISKGRP_H
#define _LIB_DISKGRP_H



#include "public_def.h"
#include "libdiskmnt.h"

//�ļ��������
typedef enum
{
	PACKET_TIME = 0,	//���ļ�ʱ�����
	PACKET_SIZE,		//���ļ���С���
}TPacketPolicy;

//����������
typedef enum
{
	POLICY_STOP_RECORD = 0,         //ֹͣ¼��
	POLICY_OVERWRITE_ALL,			//����ȫ��
	POLICY_OVERWRITE_EX_ALARM,		//���ǳ��˱���¼���ļ��������ļ�
}TDiskFullPolicy;
#define MAX_EXT_LEN			10		//�����չ������
#define MAX_DISKGRP_NUM		8

#define MIN_IDLE_DISK		2048	//��Сʣ����̿ռ䣬��λ: M   ����20120601 900->2048
#define	MAX_IDLE_DISK		10240	//���ʣ����̿ռ䣬��λ��M
#define DEFALUT_IDLE_DISK	2048	//Ĭ��ʣ����̿ռ䣬��λ: M
#define MIN_SNAP_SPACE		40		//��Сץ�Ŀռ䣬��λM

#define MIN_TIME_LEN		2		//��С���ʱ��
#define MIN_FILE_SIZE		20		//��С�����С
#define MAX_TIME_LEN		60		//����¼���ļ������ʱ������λ:��
#define MAX_FILE_SIZE		1024//200		//�����ļ�����С����λM

#define FILE_SIZE_500M      251  //��λM
#define FILE_SIZE_1024M     252  //��λM


typedef struct
{
	TDiskFullPolicy 	m_ePolicy;					//����������
	td_u8				m_ucExtName[MAX_EXT_LEN];	//¼���ļ���չ����ֲ��config_server.ini����
	TPacketPolicy		m_ePacket;					//�������
	td_u8				m_ucPerFileSize;			//�����ļ���С����λM
	td_u8				m_ucPerFileLen;				//����¼���ļ�ʱ������λ��
	td_s32				m_iFreeSpace;				//Ԥ�����̿ռ�,��λM,MIN_IDLE_DISK~MAX_IDLE_DISK

	//Added by Leeon Tonie, 90219, for disk exception.
	//Leeon Tonie 100128 delete below
	//td_u8				m_blHandleType[2];					//����ʽʹ�ܣ�0Ϊ��Ļ��ʾ��1Ϊ������ʾ
}TRecordConfig;



const TRecordConfig* dg_GetResHost();

int dg_WriteCfg();
/*
 * ��������:dg_WriteCfg
 * ��Ҫ����:�������������Ϣ���棬����¼��ģʽ��������Ϣ�������Ϣ�����Ǽ�������ԡ�������;��
 * ��	 ��:
 *          ��
 * ��	 ��:
 *			0��д���óɹ���-1��д����ʧ��
 * �޸���־:
 *			2013-06-06��ĳ����Ӻ���˵��
 */
 

int dg_DefaultCfg();
/*
 * ��������:dg_DefaultCfg
 * ��Ҫ����:�������������Ϣ�ָ�Ĭ��
 * ��	 ��:
 *          ��
 * ��	 ��:
 *			
 * �޸���־:
 *			2013-06-06��ĳ����Ӻ���˵��
 */

td_s32 dg_AddChnUsed(int _iChn, TFileType _eType, int _iSize);
/*
 * ��������:dg_AddChnUsed
 * ��Ҫ����:ͳ�Ƹ�ͨ��¼���ץ�ĵ�����
 * ��	 ��:
 *          _iChn, ͨ���ţ�_eType,�ļ����ͣ�_iSize,���Ӵ�С
 * ��	 ��:
 *			
 * �޸���־:
 *			2013-06-06��ĳ����Ӻ���˵��
 */

td_s32 dg_GetGrpDisks(td_s32 _iDiskGrp, td_u32 *_upiDisks);
/*
 * ��������:dg_GetGrpDisks
 * ��Ҫ����:��ȡ�����ڰ���������Ϣ
 * ��	 ��:
 *          _iDiskGrp,����ţ�*_upiDisks,���������̣���λ��ʾ
 * ��	 ��:
 *			
 * �޸���־:
 *			2013-06-06��ĳ����Ӻ���˵��
 */

td_s32 dg_SetGrpDisks(td_u32 _uiDisks[]);
/*
 * ��������:dg_SetGrpDisks
 * ��Ҫ����:������������Ĵ��̰�����Ϣ
 * ��	 ��:
 *          _uiDisks[],�������Ӧ������Ϣ�������±��Ӧ����ţ�������Ϣ��λ��ʾ
 * ��	 ��:
 *			
 * �޸���־:
 *			2013-06-06��ĳ����Ӻ���˵��
 */

td_s32 dg_GetGrpChannels(td_s32 _iDiskGrp, td_u32 *_puiChannels);
/*
 * ��������:dg_GetGrpChannels
 * ��Ҫ����:��ȡ�����Ӧͨ��
 * ��	 ��:
 *          _iDiskGrp,����ţ�*_puiChannels������Ӧͨ����Ϣ����λ��ʾ
 * ��	 ��:
 *			
 * �޸���־:
 *			2013-06-06��ĳ����Ӻ���˵��
 */

td_s32 dg_SetGrpChannels(td_u32 _uiChannels[]);
/*
 * ��������:dg_SetGrpChannels
 * ��Ҫ����:���������Ӧͨ��
 * ��	 ��:
 *          _uiChannels[],�������Ӧͨ����Ϣ�������±��Ӧ����ţ�ͨ����Ϣ��λ��ʾ
 * ��	 ��:
 *			
 * �޸���־:
 *			2013-06-06��ĳ����Ӻ���˵��
 */

td_s32 dg_GetDiskUsage(td_s32 _iDiskNum, td_s32 *_piUsage);
/*
 * ��������:dg_GetDiskUsage
 * ��Ҫ����:��ȡ������;��Ϣ
 * ��	 ��:
 *          _iDiskNum,���̺�;*_piUsage,������;����д�����ࡢֻ���򱸷�
 * ��	 ��:
 *			
 * �޸���־:
 *			2013-06-06��ĳ����Ӻ���˵��
 */

td_s32 dg_SetDiskUsage(td_s32 _iDiskNum, td_s32 _iUsage);
/*
 * ��������:dg_SetDiskUsage
 * ��Ҫ����:���ô�����;��Ϣ������������������ƣ����в������
 * ��	 ��:
 *          _iDiskNum,���̺ţ�_iUsage,������;����д�����ࡢֻ��������
 * ��	 ��:
 *			
 * �޸���־:
 *			2013-06-06��ĳ����Ӻ���˵��
 */

td_s32 dg_GetRecPath(td_s32 _iChn, char* _ucRecPath, char* _ucRecPathSed, td_s32 _iRedund);//����ֵ��0:	·�����䣻1:		·���ı�
/*
 * ��������:dg_GetRecPath
 * ��Ҫ����:��ȡ����¼��·����Ϣ�����ִ洢ģʽ�����ô˺�����ȡ����·��
 * ��	 ��:
 *          _iChn,ͨ���ţ�*_ucRecPath,��������·����*_ucRecPathSed,������������·����_iRedund,ͨ��������¼������
 * ��	 ��:
 *		����ֵ��ʾ��·���Ƿ����仯��0λ��Ӧ��·����1λ��Ӧ����·��	
 * �޸���־:
 *			2013-06-06��ĳ����Ӻ���˵��
 */

td_s32 dg_GetChnSpace(td_s32 _iChn, td_u32* _puiUsedRec, td_u32* _puiLimitRec, td_u32* _puiUsedSnap, td_u32* _puiLimitSnap);
/*
 * ��������:dg_GetChnSpace
 * ��Ҫ����:��ȡͨ�������Ϣ
 * ��	 ��:
 *          _iChn,ͨ���ţ�*_puiUsedRec,¼�����ÿռ䣻*_puiLimitRec,¼���趨��*_puiUsedSnap,ץ�����ÿռ䣻*_puiLimitSnap,ץ���趨���
 * ��	 ��:
 *			
 * �޸���־:
 *			2013-06-06��ĳ����Ӻ���˵��
 */

td_s32 dg_SetChnLimitSpace(td_s32 _iChn, td_u32 _uiLimitRec, td_u32 _uiLimitSnap);
/*
 * ��������:dg_SetChnLimitSpace
 * ��Ҫ����:�趨ͨ�������Ϣ
 * ��	 ��:
 *          _iChn, ͨ���ţ�_uiLimitRec, ¼���޶_uiLimitSnap,ץ���޶�
 * ��	 ��:
 *			
 * �޸���־:
 *			2013-06-06��ĳ����Ӻ���˵��
 */

td_s32 dg_GetStorageMode();
/*
 * ��������:dg_GetStorageMode
 * ��Ҫ����:��ȡ¼��ģʽ��Ϣ
 * ��	 ��:
 *          ��
 * ��	 ��:
 *		0������ģʽ��1�����ģʽ	
 * �޸���־:
 *			2013-06-06��ĳ����Ӻ���˵��
 */

td_s32 dg_SetStorageMode(td_s32 _iMode);
/*
 * ��������:dg_SetStorageMode
 * ��Ҫ����:����¼��ģʽ��Ϣ
 * ��	 ��:
 *          _iMode, ¼��ģʽ��0������ģʽ��1�����ģʽ
 * ��	 ��:
 *			
 * �޸���־:
 *			2013-06-06��ĳ����Ӻ���˵��
 */

td_s32 dg_GetExistDisks(td_s32 *_piDisk);

td_s32 dg_SetExitStatus();

td_s32 dg_Init();

td_s32 dg_Uninit();

td_s32 rec_GetPartSpace(const char* _pucPath, TPartInfo* _stInfo);

td_s32 rec_SetDiskStatus(td_s32 _iStat);

td_s32 rec_HandleIOError(td_s32 _Type, td_u8* _pcPath, const td_u8* _pcFunc);

td_s32 rec_DetectNoDisk(void);
/*
 * ��������:DetectNoDisk
 * ��Ҫ����:����޴����쳣
 * ��	 ��:
 *          ��
 * ��	 ��:
 *			0,�޴����쳣��ʧ;1,�޴����쳣����
 * �޸���־:
 *			2009-11-27,��������������
 */
 
td_s32 rec_DetectFullDisk(void);
/*
 * ��������:DetectFullDisk
 * ��Ҫ����:���������쳣
 * ��	 ��:
 *          ��
 * ��	 ��:
 *			0,�������쳣��ʧ;1,�������쳣����
 * �޸���־:
 *			2009-11-27,��������������
 */
 
td_s32 rec_DetectIOError(void);
/*
 * ��������:DetectIOError
 * ��Ҫ����:������IO����
 * ��	 ��:
 *          ��
 * ��	 ��:
 *			0,����IO������ʧ;1,����IO������
 * �޸���־:
 *			2009-11-27,��������������
 */
 //�������������쳣
td_s32 rec_DetectNoRebundanceDisk(void);

const TRecordConfig* dg_GetRecHost();
/*
 * ��������:dg_GetNoDiskRecHost
 * ��Ҫ����:��ȡ��Ӳ��ģʽ�µ�¼��������
 * ��	 ��:
 *          ��
 * ��	 ��:
 *			TRecordConfig*
 * �޸���־:
 *			2015-05-13,����ǿ��������
 */

const TRecordConfig* dg_GetNoDiskRecHost();

td_s32 rec_SetStoreRules(td_s32 _iPolicy, td_s32 _iIdleDisk);
/*
 * �������ƣ�SetRules
 * ��Ҫ���������ô洢����
 * ��	 ��:
 * 			_iPolicy,���ǲ���,TDiskFullPolicy
 * 			_iIdleDisk,ʣ����̿ռ�,��λM,0~MAX_IDLE_DISK
 * ��	 ��:
 *			ERR_REC_SUCCESSFUL,���ô洢����ɹ�
 *			ERR_REC_WRONG_PARAM,����Ĳ���
 * �޸���־��
 * 			2008-08-28,������,����
 */
td_s32 rec_GetStorageRules(td_s32* _piPolicy, td_s32* _piIdleDisk);
/*
 * �������ƣ�GetStorageRules
 * ��Ҫ��������ȡ�洢����
 * ��	 ��:
 * 			_piPolicy,�洢���ԣ��ǿ�
 * 			_piIdleDisk,��Сʣ����̿ռ䣬�ǿ�
 * ��	 ����
 * 			ERR_REC_SUCCESSFUL,��ȡ�洢����ɹ�
 * 			ERR_REC_WRONG_PARAM,����Ĳ���
 * �޸���־��
 * 			2008-08-28,������������
 */
 td_s32 rec_SetPacketRules(td_s32 _iPacket, td_s32 _iFileLen, td_s32 _iFileSize);
/*
 * ��������:SetPacketRules
 * ��Ҫ����:���ô������
 * ��	 ��:
 *			_iPacket,������ԣ�TPacketPolicy
 *			_iFileLen,����¼���ļ�ʱ��,0~MAX_TIME_LEN
 *			_iFileSize,����¼���ļ���С��0~MAX_FILE_SIZE
 * ��	 ��:
 *			ERR_REC_SUCCESSFUL,���óɹ�
 * �޸���־:
 *			2008-09-28,������������
 */
 td_s32 rec_GetPacketRules(td_s32 * _piPacket, td_s32 * _piFileLen, td_s32 * _piFileSize);
/*
 * ��������:GetPacketRules
 * ��Ҫ����:��ȡ�������
 * ��	 ��:
 *			_piPacket,���ڴ���������ԣ��ǿ�
 *			_piFileLen,���ڴ�������¼���ļ�ʱ�����ǿ�
 *			_piFileSize,���ڴ�������¼���ļ���С���ǿ�
 * ��	 ��:
 *			ERR_REC_SUCCESSFUL,��ȡ�ɹ�
 * �޸���־:
 *			2008-09-28,������������
 */
 #if 0
td_s32 rec_SetExtName(const td_u8* _cst_pucNewExt);
/*
 * �������ƣ�SetExtName
 * ��Ҫ����������¼���ļ�����չ��
 * ��	 ��:
 *			_pucNewExt,�µ��ļ���չ��,�ǿ�
 * ��	 ��:
 *			ERR_REC_SUCCESSFUL,�����ļ���չ���ɹ�
 *			ERR_REC_WRONG_PARAM,�����ļ���չ���ɹ�
 * �޸���־:
 *			2008-08-28,������������
 */
td_s32 rec_GetExtName(td_u8* _pucExtName);
/*
 * �������ƣ�GetExtName
 * ��Ҫ��������ȡ¼���ļ�����չ��
 * ��	 ��:
 *			_pucNewExt,����ļ���չ�����ǿ�
 * ��	 ��:
 *			ERR_REC_SUCCESSFUL,��ȡ�ļ���չ���ɹ�
 *			ERR_REC_WRONG_PARAM,����Ĳ���
 * �޸���־��
 *			2008-08-28,������������
 */
 #endif
td_s32 rec_OverWriteImages(void);
/*
 * ��������:OverWriteImages
 * ��Ҫ����:����ͼƬ���ú���������ʽ������ÿ24h����һ�μ��ɡ����ǽӿڣ���Ҫ�ڶ�ʱ���е���
 * ��	 ��:
 *			��
 * ��	 ��:
 *			ERR_REC_NO_DBFILE, ���ݿ�δ��ʼ��
 *			ERR_REC_SUCCESSFUL, �����ɹ�
 *			ERR_REC_FAILED,����ԭ���²���ʧ��
 * �޸���־:
 *			2009-12-03,��������������
 */

td_s32 dg_CalcAllDiskSixe(void);

typedef void (*dg_AlterFirstDiskCallBack)(td_s32 _iDiskNum);
td_s32 dg_RegAlterFirstDiskCallBack(dg_AlterFirstDiskCallBack _CallBack);



#endif

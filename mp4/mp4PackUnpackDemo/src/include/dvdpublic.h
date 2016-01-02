#ifndef _DVD_PUBLIC_H
#define _DVD_PUBLIC_H

enum DVD_FILE_TYPE
{
	DVD_FILE = 0,
	DVD_DIR = 1	
};

enum DVD_DEVNO_TYPE
{
	DVD_SR0 = 0,
	DVD_SR1 = 1
};

enum DVD_INIT_STATUS
{
	DVD_UNINIT = 0,
	DVD_INITING = 1,
	DVD_INITED = 2
};

enum DVD_DISK_TYPE
{
	 DVD_ROM,
	 DVD_MINUS_R_SEQ,
	 DVD_RAM,
	 DVD_MINUS_RW_RO,
	 DVD_MINUS_RW_SEQ,
	 DVD_MINUS_R_DL_SEQ,
	 DVD_MINUS_R_DL_J,
	 DVD_PLUS_RW,
	 DVD_PLUS_R,
	 DVD_PLUS_RW_DL,
	 DVD_PLUS_R_DL,
	 BD_ROM,
	 BD_R_SRM,
	 BD_R_RRM,
	 BD_RE,
	 DVD_UNKNOWN	    
};

enum DVD_TRAY_ACTION
{
	DVD_EJECT_TRAY = 0,
	DVD_LOAD_TRAY = 1
};

enum DVD_LOCK_ACTION
{
	DVD_UNLOCK = 0,
	DVD_LOCK = 1
};



enum DVD_MEDIA_EXIST
{
	DVD_DISK_NO_EXIST = 0,
	DVD_DISK_EXIST  = 1
};

enum DVD_DISKSPACE_BLANK
{
	DVD_DISK_NO_BLANK = 0,
	DVD_DISK_BLANK = 1
};



#define DVD_MAX_TRACK_NUM 5
#define DVD_MAX_FILE_NAME_LEN 255
#define DVD_DEVNO_VALID(_uiDEVNo) (  _uiDEVNo >= DVD_SR0 && _uiDEVNo <= DVD_SR1)
#define DVD_DEVFD_VALID(_uiDEVFD) (  _uiDEVFD > 0)
#define DVD_TRACK_VALID(_uiTrackNo) (_uiTrackNo >= 1 && _uiTrackNo < DVD_MAX_TRACK_NUM)
#define DVD_IS_BLANK(_ucBuf)  ( (_ucBuf[2]&3) == 0)
#define DVD_DEV_FULL_PATH_LEN 64
#define DVD_INVALID_UINT_VALUE 0xFFFFFFFF
#define DVD_DEVNUM 2
#define DVD_CLEAR_DISK_BUFFER(pDev) do{ memset(pDev->m_pBuffer, 0x00, (pDev->m_uiBlockSize * pDev->m_uiBlockNumPerPacket));}while(0)
#define DVD_MARK_DISK_BUFFER(pDev) do{ memset(pDev->m_pBuffer, 0xAA, (pDev->m_uiBlockSize * pDev->m_uiBlockNumPerPacket));}while(0)


#define DVD_MIN_VALUE 1e-8  //������Ҫ�������ֵ
#define DVD_IS_DOUBLE_ZERO(d) (abs(d) < DVD_MIN_VALUE) 
#define DVD_1X	1352	// 1385 * 1000 / 1024
#define BD_1X	4390	// 4495.5 * 1000 / 1024
#define REVERSE_TRACK_BLOCKNUM 1024
#define FILE_TRACK_START_LBA ((unsigned int) 0x400)
#define DVD_ALIGN(size, boundary) (((size) + ((boundary) - 1)) & ~((boundary) - 1))
#define DVD_ALIGN_DEFAULT(size) DVD_ALIGN(size, (32 * 1024))

#define DVD_DISK_BAD (-1)
#define DVD_UDF_EXIST (0)
#define DVD_UDF_ERROR (1)
#define DVD_NOT_UDF (2)
#define DVD_FIRSTTRACK_BLANK (3)
#define DVD_UDF_FILEBODY_NUM 2

//#define IN
#define OUT
#define INOUT

typedef struct udf_file
{
	unsigned int m_uiIndex;
	unsigned int m_uiParentIndex; // 0����root
	unsigned int m_uiBodyStartLBA[DVD_UDF_FILEBODY_NUM]; // �ļ�����ʼ��ַ ����ΪĿ¼���ļ���0
	unsigned int m_uiBodyEndLBA[DVD_UDF_FILEBODY_NUM];// �ļ��������ַ ����ΪĿ¼���ļ���0
	unsigned int m_uiHeadStartLBA;// �ļ�ͷ��ʼ��ַ ����ΪĿ¼���ļ���0
	unsigned int m_uiHeadEndLBA;// �ļ�ͷ������ַ ����ΪĿ¼���ļ���0
	unsigned long long  m_uiHeadSize; // ��ʵ����, ��λ���ֽڣ�����ΪĿ¼���ļ���0
	unsigned long long m_uiBodySize[DVD_UDF_FILEBODY_NUM]; // ��ʵ���ȣ���λ���ֽڣ�����ΪĿ¼���ļ���0
	unsigned int m_uiFiletype;	// 0�������ļ� 1��Ŀ¼
       unsigned char m_pFileName[256];	// �ļ�(Ŀ¼)��
	unsigned char m_rezerved[32]; // �����ֶΣ�Ϊ�Ժ���չʹ��
}udf_file;

typedef struct udf_fs
{
	unsigned int m_uiDevNo; // �����豸��
	unsigned int m_uiFileNum; // ������һ��Ҫ�̼��������ļ�
	unsigned int m_uiFolderNum; // ������һ��Ҫ�̼���Ŀ¼
	unsigned char m_pLogicVolIdent[128]; // ���̾��
	unsigned int m_lengthAlloc; // �䳤���䣬����ֶμ�¼allocUdfFile��m_allocUdfFolder�ķ��䳤�ȣ���λ���ֽ�
	unsigned char m_allocUdfFolder[0]; // ʵ�ʵ�struct udf_file Ŀ¼���Զ�������װ
	unsigned char m_allocUdfFile[0]; // ʵ�ʵ�struct udf_file  �����ļ�
}udf_fs;

/************************************************* 
Function: udf_Check
Description: �����̼��豸�Ƿ����
Input: _uiDevNo�� �����豸��
Output: 
Return: ���سɹ���ʧ�� 0��td_success��-1��td_failure��
Others: 
*************************************************/
int udf_Check(unsigned int  _uiDevNo);

/************************************************* 
Function: udf_Ready
Description: ��ʼ�����̣�ʹ�������ڹ���״̬
Input: _uiDevNo�� �����豸��
Output: 
Return: ���سɹ���ʧ�� 0��td_success��-1��td_failure��
Others: 
*************************************************/
int udf_Ready(unsigned int  _uiDevNo);

/************************************************* 
Function: udf_IsBlankDisk
Description: �ж��Ƿ�Ϊ�հ׹���
Input:  _uiDevNo�������豸��
Output: 
Return: 0:�ǿ�      1���չ���-1:ʧ��
Others: 
*************************************************/
int udf_IsBlankDisk(unsigned int _uiDevNo);

/************************************************* 
Function: udf_ControlDVDRomUnit 
Description: ���ƹ���оƬ��ת
Input: _uiDevNo�������豸��
          _uiAction��1������Unit  0��ֹͣUnit
Output: 
Return: ���سɹ���ʧ�� 0��td_success��-1��td_failure��
Others:
*************************************************/
int udf_ControlDVDRomUnit (unsigned int _uiDevNo, unsigned int _uiAction);

/************************************************* 
Function: udf_TestDVDRomUnit 
Description: ���Թ���оƬ��ת
Input: _uiDevNo�������豸��     
Output: 
Return: ���سɹ���ʧ�� 0��оƬ��ת��������0��оƬ�쳣��
Others:
*************************************************/
int udf_TestDVDRomUnit (unsigned int _uiDevNo);


/************************************************* 
Function: udf_GetDiskType
Description: ��ȡ��������
Input: _uiDevNo�������豸��
Output: _pType���������ͣ�����μ�ö����DVD_DISK_TYPE
Return: ���سɹ���ʧ�� 0��td_success��-1��td_failure��
Others: 
*************************************************/
int udf_GetDiskType (unsigned int _uiDevNo, OUT unsigned int * _pType);

/************************************************* 
Function: udf_GetCapacity
Description: ��ȡ����ʣ������
Input:    _uiDevNo�������豸��        
Output: 	_puiTotalSpace��������������λ��MB
		_puiUsedSpace����������������λ��MB
Return: ���سɹ���ʧ�� 0��td_success��-1��td_failure��
Others:
*************************************************/
int udf_GetCapacity(unsigned int _uiDevNo, OUT unsigned int * _puiTotalSpace, OUT unsigned int * _puiUsedSpace);

/************************************************* 
Function: udf_GetNextWriteLBA
Description: ��ȡ��ǰ���п���д��ĵ�ַ 
Input:  _uiDevNo�������豸��      
Output: _uiLBA����ǰ���п�д����߼���ַ
Return:        ���سɹ���ʧ�� 0��td_success��-1��td_failure��
Others: 
*************************************************/
int udf_GetNextWriteLBA(unsigned int _uiDevNo, OUT unsigned int *_uiLBA);

/************************************************* 
Function: udf_WriteDisk
Description: д�� 
Input:  _uiDevNo�������豸��
_pbuf��д������
_uiLen��д�����ݵ�ʵ�ʳ���
Output: _puiEndLBA��д�̵Ľ�����ַ
Return: >=0������д������ĳ��ȣ�-1��td_failure��
Others: 
*************************************************/
int udf_WriteDisk(unsigned int _uiDevNo, IN unsigned char* _pbuf, unsigned int _uiLen, OUT unsigned int * _puiEndLBA);

/************************************************* 
Function: udf_ReadDisk
Description: ��ȡ�ļ������� 
Input:  	_uiDevNo�������豸��
       	_uiStartLBA�����̵���ʼ��ַ��0��ʼ
		_pbuf����ȡ����
		_uiLen����ȡ���ݵ�ʵ�ʳ���
Output: 
Return: >=0�����ض�ȡ�ĳ��ȣ�-1��td_failure��
Others: 

*************************************************/
int udf_ReadDisk(unsigned int _uiDevNo, unsigned int _uiStartLBA, OUT unsigned char* _pbuf, int _uiLen);

/************************************************* 
Function: udf_CreateFS
Description: ����UDF�ļ�ϵͳ
Input:   _uiDevNo�������豸��
		_pFS����ʶ��Ҫ��¼�������ļ�(����+Ŀ¼)
Output: 
Return: 0��td_success��-1��td_failure   >0:����ʧ�ܣ�ֵΪ����������
Others: 
*************************************************/
int udf_CreateFS (unsigned int _uiDevNo, IN struct udf_fs * _pFS);

/************************************************* 
Function: udf_RepairDisk
Description: �޸�����
Input:   _uiDevNo�������豸��
 	    _pFS����ʶ��Ҫ��¼�������ļ�(����+Ŀ¼)
Output: 
Return: ���سɹ���ʧ�� 0��td_success��-1��td_failure��
Others: 
*************************************************/
int udf_RepairDisk(unsigned int _uiDevNo, IN struct udf_fs * _pFS);

/************************************************* 
Function: udf_CloseDisk
Description: ����
Input:_uiDevNo�������豸��        
Output: 
Return: ���سɹ���ʧ�� 0��td_success��-1��td_failure��
Others: 
*************************************************/
int udf_CloseDisk(unsigned int _uiDevNo);

/************************************************* 
Function: udf_SetSpeed 
Description: ��ȡ��������
Input: _uiDevNo�������豸��
         _uiSpeed��4.0��6.0��8.0��12.0��16.0
Output: 
Return: ���سɹ���ʧ�� 0��td_success��-1��td_failure��
Others: 
*************************************************/
int udf_SetSpeed (unsigned int _uiDevNo, double _dSpeed);

/************************************************* 
Function:udf_IsUDFExist
Description: �ж��Ƿ��ڹ����Ѿ������ļ�ϵͳ
Input:  _uiDevNo�������豸��		
Output: 
Return: -1 :������
           0:UDF����
           1:��UDF���ǲ�����
           2:�����ݵ�����UDF
           3:��һ�����û�п�¼����
Others: 
*************************************************/
int udf_IsUDFExist(unsigned int _uiDevNo);

/************************************************* 
Function: udf_SyncDVDCache 
Description: �������ڵĻ���ˢ�µ�����
Input: _uiDevNo�������豸��        
Output: 
Return: ���سɹ���ʧ�� 0��td_success��-1��td_failure��
Others: 
*************************************************/
int udf_SyncDVDCache (unsigned int _uiDevNo);

/************************************************* 
Function: udf_ReleaseDVDDevice 
Description:�ͷŹ����豸��Դ�ӿ�
Input: _uiDevNo�������豸��          
Output: 
Return: ���سɹ���ʧ�� 0��td_success��-1��td_failure��
Others: 
*************************************************/
int udf_ReleaseDVDDevice(unsigned int _uiDevNo);

/************************************************* 
Function: udf_Eject_Load_Tray 
Description:���ֽӿ�
Input: _uiDevNo�������豸��
          _uiAction :    0:���� 1:�ز�
Output: 
Return: ���سɹ���ʧ�� 0��td_success��-1��td_failure��
Others: 
*************************************************/
int udf_Eject_Load_Tray(unsigned int _uiDevNo, unsigned int _uiAction);

/************************************************* 
Function: udf_IsDiskExist 
Description:�жϹ������Ƿ�����
Input: _uiDevNo�������豸��        
Output: 
Return: 1:���� 0:û�� -1:ʧ��
Others: 
*************************************************/
int udf_IsDiskExist(unsigned int _uiDevNo);

/************************************************* 
Function: udf_OpenDVDDevice 
Description:�򿪹����豸��Դ�ӿ�
Input: _uiDevNo�������豸��          
Output: 
Return: ���سɹ���ʧ�� 0��td_success��-1��td_failure��
Others: 
*************************************************/
int udf_OpenDVDDevice(unsigned int _uiDevNo);

int udf_RepairLastWritenBlock(unsigned int _uiDevNo);

int udf_InitDVDDevice(unsigned int _uiDevNum);
int udf_WriteDiskByOneBlock(unsigned int _uiDevNo, IN unsigned char* _pbuf, unsigned int _uiLen, OUT unsigned int * _puiEndLBA);
int udf_ReadDiskByOneBlock(unsigned int _uiDevNo, unsigned int _uiStartLBA, OUT unsigned char* _pbuf, int _iLen);
int udf_ControlDVDLock (unsigned int _uiDevNo, unsigned int _uiAction);
int udf_KeepBDAlive(unsigned int  _uiDevNo);


int udf_GetNextFakeWriteLBA(unsigned int _uiDevNo, OUT unsigned int *_uiLBA);
#endif

/********************************************************************
Copyright (C), 1994-2009, ���ΰҵ����Ƽ����޹�˾
¼���ļ�֧��hashУ�鹦�ܳ���
FileName: libhash.c
Description: hashУ�鹦�ܻ�������
History: 

*******************************************************************/
#ifndef _LIBHASH_
#define _LIBHASH_

#define MAX_CALC_FILE_LIST 64
#define MD5_FILE_EXTNAME ".md5"
#define MD5_VALUE_LEN 16

typedef enum
{
	MD5MODE = 1, //md5
	OTHREMODE, //������ʽ	
}HashMode;


typedef enum
{
	CalcWait = 0, //δ����
	CalcFinished, //�������	
}CalcFileStatus;

typedef struct
{
	td_u8   	m_ucFileName[FULL_PATH_LEN];		//�ļ���(����·��)
}TCalcFileInfo;

typedef struct
{
	TCalcFileInfo   stFileInfo; //�ļ���Ϣ
	CalcFileStatus 	Fileinfo; //����״̬
}hash_FileStat;

typedef struct t_Calc_File_List
{
	hash_FileStat    Rec_File[MAX_CALC_FILE_LIST];  //64����¼�ļ��б�
	int 			m_iRead;		//����־
	int 			m_iWrite;  		//д��־
	pthread_mutex_t m_ListMutex;	//��
}T_CALC_FILE_LIST;//��ǰ�Ŀ�¼����


/*
������ 	:	td_s32 Hash_Init(td_s32 _iEnable)
����	:	��ʼ��hashģ��
�������	:	_ iEnable	: 0 ��ʹ�� 1 ʹ��
����ֵ	: 	>=0 �ɹ�   -1 ʧ��
*/
td_s32 Hash_Init(td_s32 _iEnable);
/*
������ 	:	td_s32 Hash_UnInit(void)
����	:	����ʼ��hashģ��
�������	:	��
����ֵ	: 	>=0 �ɹ�   -1 ʧ��
*/
td_s32 Hash_UnInit(void);
/*
������ 	:	td_s32 Hash_SetHashMode (int _iHashMode)
����	:	���ù�ϣУ���㷨����
�������	:	_iHashMode  : �㷨���� 1-md5 
����ֵ	: 	>=0 �ɹ�   -1 ʧ��
*/
td_s32 Hash_SetHashMode (int _iHashMode);
/*
������ 	:	td_s32 Hash_DeleteHashFile (const td_s8* _pcRecFileName)
����	:	ɾ��¼���ļ���Ӧ�Ĺ�ϣ�ļ�
�������	:	_pcRecFileName: ¼���ļ���
����ֵ	: 	>=0 �ɹ�   -1 ʧ��
*/
td_s32 Hash_DeleteHashFile (const td_s8* _pcRecFileName);
/*
������ 	:	td_s32 Hash_ReadHashValue (const td_s8* _pcRecFileName, td_s8* _pcHashValue)
����	:	��ȡ��ϣ�ļ��еĹ�ϣֵ
�������	:	_pcRecFileName: ¼���ļ���
�������: 	_pcHashValue: ��ϣֵ
����ֵ	: 	>=0 �ɹ�   -1 ʧ��
*/
td_s32 Hash_ReadHashValue (const td_s8* _pcRecFileName, td_s8* _pcHashValue);
/*
������ 	:	td_s32 Hash_AddToHashFileList (const td_s8* _pcRecFileName)
����	:	�������¼���ļ����������Ĺ�ϣ����
�������	:	_pcRecFileName: ¼���ļ���
����ֵ	: 	>=0 �ɹ�   -1 ʧ��
*/
td_s32 Hash_AddToHashFileList (const td_s8* _pcRecFileName);
/*
������ 	:	td_s32 Hash_CalcHashFile (const td_s8* _pcRecFileName, td_s8* _pcHashValue)
����	:	������ȡ�ļ��Ĺ�ϣֵ
�������	:	_pcRecFileName: ¼���ļ���
���������	_pcHashValue: ��ϣֵ
����ֵ	: 	>=0 �ɹ�   -1 ʧ��
*/
td_s32 Hash_CalcHashFile (const td_s8* _pcRecFileName, td_s8* _pcHashValue);
/*
������ 	:	td_s32 Hash_AddToHashBigFileList (const td_s8* _pcRecFileName)
����	:	�������¼���ļ����������Ĺ�ϣ����
�������	:	_pcRecFileName: ¼���ļ���
����ֵ	: 	>=0 �ɹ�   -1 ʧ��
*/
td_s32 Hash_AddToHashBigFileList (const td_s8* _pcRecFileName);
/*
������ 	:	td_s32 Hash_RenameHashFile (const td_s8* _pcSrcRecFileName��const td_s8* _pcNewRecFileName)
����	:	�޸�¼���ļ���ͬʱ�޸Ĺ�ϣ�ļ�����
�������	:	_pcSrcRecFileName: ԭ¼���ļ���
_pcNewRecFileName: �µ�¼���ļ���
����ֵ	: 	>=0 �ɹ�   -1 ʧ��
*/
td_s32 Hash_CalcHashBigFile (const td_s8* _pcRecFileName);
/*
������ 	:	td_s32 Hash_CalcHashBigFile (const td_s8* _pcRecFileName)
����	:	����ĳ���ļ���md5ֵ
�������	:	_pcRecFileName: ¼���ļ���
����ֵ	: 	>=0 �ɹ�   -1 ʧ��
*/
td_s32 hash_WriteHashFile(td_s8* _pcHashFullPath, td_s8* _pcHashValue);
td_s32 hash_GenerateHashFileFullpath(td_s8* _pcTempName, td_s8* _pcHashFullPath);
td_s32 Hash_Md5BigFileInit(int _iCdNo);
/*
������ 	:	td_s32 Hash_Md5BigFileInit(int _iCdNo)
����	:	��¼���ļ�ʱ,hash��ʼ��
�������	:	_iCdNo: ������
����ֵ	: 	>=0 �ɹ�   -1 ʧ��
*/
td_s32 Hash_Md5Update(int _iCdNo,unsigned char *_pcBuffer,unsigned int iBufferLen);
/*
������ 	:	td_s32 Hash_Md5Update(int _iCdNo,unsigned char *_pcBuffer,unsigned int iBufferLen)
����	:	�����ͽ�ȥȻ�����md5
�������	:	_iCdNo :������ _pcBuffer: ��Ƶ��  iBufferLen:��Ƶ������

����ֵ	: 	>=0 �ɹ�   -1 ʧ��
*/
td_s32 Hash_GetMd5Info(int _iCdNo,char *_pstMd5Info);
td_s32 Hash_SetMd5Info(int _iCdNo,char *_pstMd5Info);
td_s32 Hash_Md5BigFileFinal(int _iCdNo,char *_cOutputBuf);
/*
������ 	:	Hash_Md5BigFileFinal
����	:	����md5ֵ
�������	:	_iCdNo :������ _cOutputBuf: md5ֵ

����ֵ	: 	>=0 �ɹ�   -1 ʧ��
*/
td_s32 Hash_UpdateHashFile (const td_s8* _pcRecFileName);
/*
������ 	:	Hash_UpdateHashFile
����	:	����¼���ļ�������md5�ļ���
�������	:	_pcRecFileName: ¼���ļ���

����ֵ	: 	>=0 �ɹ�   -1 ʧ��
*/
td_s32 Hash_RenameHashFile (const td_s8* _pcSrcRecFileName, const td_s8* _pcNewRecFileName);
/*
������ 	:	td_s32 Hash_BackupHashFile (const td_s8* _pcSrcRecFileName��const td_s8* _pcDstRecFileName)
����	:	¼�񱸷�ʱ��ͬʱ���ݹ�ϣ�ļ�
�������	:	_pcSrcRecFileName: Դ¼���ļ���
_pcDstRecFileName: ���ݺ��¼���ļ���
����ֵ	: 	>=0 �ɹ�   -1 ʧ��
*/
td_s32 Hash_BackupHashFile (const td_s8* _pcSrcRecFileName, const td_s8* _pcDstRecFileName);
/*
������ 	:	td_s32 Hash_GetHashEnble (void)
����	:	��ȡ��ϣ����ʹ��״̬
�������	:	��
����ֵ	: 	��ϣʹ��״̬ 0 ��ʹ�� 1 ʹ��
*/
td_s32 Hash_iGetHashEnble (void);
/*
������ 	:	td_s32 Hash_iSetHashEnble (td_S32 _iEnable)
����	:	���ù�ϣ����ʹ��״̬
�������	:	_iEnable����ϣ����ʹ��״̬ 0 ��ʹ�� 1 ʹ��
����ֵ	: 	>=0 �ɹ�   -1 ʧ��
*/
td_s32 Hash_iSetHashEnble (td_s32 _iEnable);

/*
������ 	:	td_s32 hach_CheckHashFileExist(td_s8* _pcTempName, td_s8* _pcHashFullPath);
����	:	��ȡMD5�ļ�·��
�������	:	_pcTempName��¼���ļ��� _pcHashFullPath: md5�ļ�·��
����ֵ	: 	>=0 �ɹ�   -1 ʧ��
*/

td_s32 hach_CheckHashFileExist(td_s8* _pcTempName, td_s8* _pcHashFullPath);
td_s32 Hash_GetHashBigFileList(void);
/*
������ 	:	td_s32 Hash_GetHashBigFileList();
����	:	��ȡMD5�Ƿ�ת�����
�������:   ��
����ֵ	: 	1 ���   0 δ���
*/
#endif /*_LIBTIANDY_*/

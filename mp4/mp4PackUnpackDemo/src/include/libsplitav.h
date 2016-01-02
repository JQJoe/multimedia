#ifndef _LIBSPLITAV_
#define _LIBSPLITAV_

#define MAX_SPLITAV_FILE_LIST 64
#define AAC_FILE_EXTNAME ".aac"
#define AAC_VALUE_LEN 16

typedef enum
{
	AACMODE = 1, //AAc
	MAXEMODE, //������ʽ	
}SplitAvMode;


typedef enum
{
	SplitWait = 0, //δ����
	SplitFinished, //�������	
}SplitFileStatus;

typedef struct
{
	td_u8   	m_ucFileName[FULL_PATH_LEN];		//�ļ���(����·��)
}TSplitFileInfo;

typedef struct
{
	TSplitFileInfo   stFileInfo; //�ļ���Ϣ
	SplitFileStatus 	Fileinfo; //����״̬
}splitAv_FileStat;

typedef struct t_Split_File_List
{
	splitAv_FileStat    Rec_File[MAX_CALC_FILE_LIST];  //256����¼�ļ��б�
	int 			m_iRead;		//����־
	int 			m_iWrite;  		//д��־
	pthread_mutex_t m_ListMutex;	//��
}T_SPLIT_FILE_LIST;//��ǰ�Ŀ�¼����

td_s32 SplitAv_Init();

td_s32 SplitAv_UnInit(void);

td_s32 SplitAv_SetSplitAvMode (int _iMode);

td_s32 SplitAv_DeleteSplitAvFile (const td_s8* _pcRecFileName);

td_s32 SplitAv_AddToSplitAvFileList (const td_s8* _pcRecFileName);

td_s32 SplitAv_RenameSplitAvFile (const td_s8* _pcSrcRecFileName, const td_s8* _pcNewRecFileName);

td_s32 SplitAv_BackupSplitAvFile (const td_s8* _pcSrcRecFileName, const td_s8* _pcDstRecFileName);

td_s32 SplitAv_iGetSplitAvEnble (td_s32 _iChn);

td_s32 SplitAv_iSetSplitAvEnble (td_s32 _iChn, td_s32 _iEnable);

td_s32 SplitAv_CheckSplitAvFileExist(td_s8* _pcRecFileName, td_s8* _pcFullPath);
td_s32 SplitAv_GenerateAudioFileFullpath(td_s8* _pcTempName, td_s8* _pcAudioFullPath);

td_s32 SplitAv_GetSplitAvFileSize(td_s8 *_pcRecFileName);

#endif /*_LIBTIANDY_*/


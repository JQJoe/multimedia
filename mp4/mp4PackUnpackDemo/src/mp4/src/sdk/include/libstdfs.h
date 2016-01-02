#ifndef __LIBSTDFS_H__
#define __LIBSTDFS_H__

#include <sys/stat.h> 
#include <sys/statfs.h> 
#include "public_def.h"
#include <sys/vfs.h> 
#include "libtdfs.h"
#include "libvfs.h"
#if 0
typedef enum
{
	FS_TD,
	FS_NORMAl,
}TFsType;

typedef enum
{
	TD_FILE_TYPE_REC = 0,	//¼���ļ�
	TD_FILE_TYPE_PRO,		//Ԥ¼�ļ�
	TD_FILE_TYPE_PIC,		//ͼƬ�ļ�
}TTdFileType;

typedef struct
{
	struct stat m_stat;
	td_u64		m_iRecChn;
	td_u64 		m_iRecLock;
	td_u64 		m_iRecType;
	td_char		m_iOthAttribute[32];			//�Զ�������	
	char		m_cFileName[MAX_PATH_LEN];		//�ļ���
}TTdStat;

typedef struct
{
	int 		m_iChn;							//ͨ����	
	int			m_iTime;						//¼���ļ��Ŀ�ʼʱ��		
	TTdFileType m_eType;						//¼���ļ����ͣ�¼��/Ԥ¼/ͼƬ
	int			m_iPreSize;						//Ԥ¼�ļ���Сbyte
	int			m_iParam;						//¼���ļ�����
	int  		m_iCustomType;					//�Զ������ͻ��ߺ���ֵ
	char		m_cBlockDevPath[MAX_PATH_LEN];	//���豸·��
}TTFileParam;

typedef struct
{
	int 		m_iId;					//����
	td_u64 	m_lStartTime;		//�����ʼʱ��
	int 		m_iFileNum;			//�����ļ�����
}TBlockInfo;


/*======
�����ⲿʵ�ֵ���������
1��
	int getDiskType(char* _cBlockDevPath)
	//��ȡ�����ļ�ϵͳ������
	
2��	int CopyFile(char* _cSrcPath,char* _cDstPath)
	//��td�ļ�ϵͳ�е��ļ�������ͨ���ļ�ϵͳ��
======*/
#endif

int stdfs_Init();
/*
	��	��	:	��ʼ���ļ�ϵͳ��
	��	��	:

	��	��	:	td_success	�ɹ�
				����		ʧ��
*/

int stdfs_DeInit();
/*
	��	��	:	�ر��ļ�ϵͳ
	��	��	:	��
	��	��	:	td_success	�ɹ�
				����		ʧ��	
*/



int stdfs_Open(TTFileParam* _pFileParam,char* _cFileName,int _iMode);
/*
	��	��	:	���ļ�	
	��	��	:	_cFileName 	�ļ���������tdfs_CreateFile������ȡ
				_iMode		�򿪷�ʽ�������µ��ļ����ߴ����е��ļ� (O_RDONLY, O_WRONLY, or O_RDWR  O_TRUNC O_APPEND)
	��	��	:	>0			�ļ����
				����		ʧ��
*/

size_t stdfs_Write(int _iFd, const void *_pBuf, size_t _iCount);
/*
	��	��	:	���ļ���д����
	��	��	:	_iFd		�ļ����
				_ucBuf		����ָ��
				_iLen		���ݳ���
	��	��	:	>0			ʵ��д������ݳ���
				����		ʧ��
*/

size_t stdfs_Read(int _iFd, void *_pBuf, size_t _iCount);
/*
	��	��	:	���ļ��ж�ȡ����
	��	��	:	_iFd		�ļ����
				_ucBuf		����ָ��
				_iLen		���ݳ���
	��	��	:	>0			ʵ�ʶ�ȡ�������ݳ���
				����		ʧ��
*/

off_t stdfs_Seek(int _iFd,off_t _lOffSet,int _iWhere);
/*
	��	��	:	�ļ���λ
	��	��	:	_iFd		�ļ����
				_lOffSet	ƫ����
				_iWhere		��ʼλ��
	��	��	:	td_success	�ɹ�
				����		ʧ��
*/

long stdfs_Tell(int _iFd);
/*
	��	��	:	�ļ���λ
	��	��	:	_iFd		�ļ����
	��	��	:	>0			�ļ�ָ��ĵ�ǰλ��
				����		ʧ��
*/

int stdfs_Eof(int _iFd);
/*
	��	��	:	�ж��Ƿ��ļ�β
	��	��	:	_iFd		�ļ����
	��	��	:	��0			���ļ�β
				0			δ���ļ�β
*/

int stdfs_Close(int _iFd);
/*
	��	��	:	�ر��ļ�
	��	��	:	_iFd		�ļ����
	��	��	:	td_success	�ɹ�
				����		ʧ��
*/

int stdfs_Unlink(char* _cFileName);
/*
	��	��	:	ɾ��ָ�����ļ�
	��	��	:	_cFileName	�ļ���
	��	��	:	td_success	�ɹ�
				����		ʧ��
*/

int stdfs_Stat(char* _cFileName,TTdStat *_buf);
/*
	��	��	:	��ȡ�ļ����������
	��	��	:	_cFileName	�ļ���
				_buf		�ļ����Խṹ��
	��	��	:	td_success	�ɹ�
				����		ʧ��				
*/

int stdfs_Rename(const char *oldpath, const char *newpath);
/*
	��	��	:	¼���ļ�����/����
	��	��	:	_cFileName	�ļ���
				_iLock		0	����
							1	����
	��	��	:	td_success	�ɹ�
				����		ʧ��
*/

int stdfs_ChangeTime(char* _cFileName, const struct timeval times[2]);
/*
	��	��	:	�޸��ļ����޸�ʱ��
	��	��	:	_cFileName	�ļ���
				_iTime		ʱ��ֵ��ʹ����������ʾ	
						
	��	��	:	td_success	�ɹ�
				����		ʧ��
*/


int stdfs_SetUsrParam(char* _cFileName,void *_pBuf,int _iLen);
/*
	��	��	:	�����û��Զ�������
	��	��	:	_cFileName	�ļ���
				_pBuf		����ָ��
				_iLen		���ݳ���	
						
	��	��	:	td_success	�ɹ�
				����		ʧ��
*/

td_u32 stdfs_error(int _iFd);
/*
	��	��	:	��ȡ�ļ�ϵͳ���һ�εĳ�����Ϣ
	��	��	:	�������һ�γ�����Ϣ
	��	��	:	td_success		�ɹ�
				����			ʧ��
*/

int stdfs_fsync(int _iFd);
/*
	��	��	:	ˢ��
	��	��	:	_iFd	���
	��	��	:	td_success		�ɹ�
				����			ʧ��
*/
#if 0
void* stdfs_fopen(TTFileParam* _pFileParam, IN OUT char* _cFileName, char* _cMode);
int stdfs_fread(void *ptr, size_t size, size_t nmemb, TVfile *stream);
int stdfs_fwrite(const void *ptr, size_t size, size_t nmemb, TVfile *stream);
int stdfs_fseek(TVfile *stream, long offset, int whence);
int stdfs_ftell(TVfile *stream);
int stdfs_feof(TVfile *stream);
int stdfs_fclose(TVfile *fp);
#endif
//int (*vfile_fstat)(int _iFd, TTdStat *buf);
int stdfs_ftruncate(int _iFd, off_t length);
int stdfs_fcntl(int fd, int cmd, long flg);
int stdfs_Format(char* _cBlockDevPath);
/*
	��	��	:	��ʽ������
	��	��	:	_cBlockDevPath	���豸·��
	��	��	:	td_success		�ɹ�
				����			ʧ��	
*/

int stdfs_Statfs(char* _cBlockDevPath,TTdStatfs *_pBuf);
/*
	��	��	:	��ȡ���̿ռ���Ϣ
	��	��	:	_cBlockDevPath	���豸·��
				_pBuf			������̿ռ���Ϣ��ָ��
	��	��	:	td_success		�ɹ�
				����			ʧ��	
*/	

int vfs_PartDisk(char* _cBlockDevPath);
/*
	��	��	:	���̷���
	��	��	:	
*/

int stdfs_ScanDir(const char *dirp, struct dirent ***namelist);
VDIR* stdfs_OpenDir(const char* _cDir);
struct dirent * stdfs_ReadDir(VDIR* _cDir);
int stdfs_CloseDir(VDIR* _cDir);

#endif 


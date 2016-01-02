#ifndef __LIBVFS_H__
#define __LIBVFS_H__

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/vfs.h>
#include <dirent.h>
#include "libtdfs.h"

typedef struct
{
	int				m_iBlockId;		//����
	int 			m_iState;		//�򿪻�رձ�־
	int 			m_iFileNum;		//���ڹ��ж��ٸ��ļ�
	int 			m_iPtr;			//��ȡλ��
	TTdStat*		m_tdStat;	
	pthread_mutex_t m_tLock;
	struct dirent	m_dirent;
	DIR*			m_tDir;		
}VDIR;


/* vfile �ṹ*/
typedef struct vfile
{
	int vfs_fd; //vfs����
	int tdfs_fd; //tdfs����
	void* vfile_interface;
	
}TVfile;

int vfs_Init();
/*
	��	��	:	��ʼ���ļ�ϵͳ����ʼ�������ļ�ϵͳ��ʵ��	
	��	��	:

	��	��	:	td_success	�ɹ�
				����		ʧ��
*/

int vfs_DeInit();
/*
	��	��	:	�ر��ļ�ϵͳ
	��	��	:	��
	��	��	:	td_success	�ɹ�
				����		ʧ��	
*/

int vfs_PartDisk(char* _cBlockDevPath);
/*
	��	��	:	���̷���
	��	��	:	
*/
	
int vfs_Format(char* _cBlockDevPath);
/*
	��	��	:	��ʽ�����̣����ɸ�ʽ��ΪTDFS
	��	��	:	_cBlockDevPath	���豸·��
	��	��	:	td_success		�ɹ�
				����			ʧ��	
*/

int vfs_Statfs(char* _cPath,TTdStatfs *_pBuf);
/*
	��	��	:	��ȡ�ļ�ϵͳ�������Ϣ
	��	��	:	_cPath			���豸·�����ļ�ϵͳ���غ��·��
								�����ڲ������·��������ʹ�������ļ�ϵͳ�ĺ���ָ��
				_pBuf			������̿ռ���Ϣ��ָ��
	��	��	:	td_success		�ɹ�
				����			ʧ��	
*/

int vfs_Open(TTFileParam* _pFileParam,IN OUT char* _cFileName,int _iMode);
/*
	��	��	:	���ļ��򴴽��ļ�	
	��	��	:	_pFileParam	�ļ�����	
				_cFileName 	�ļ���
				_iMode		�򿪷�ʽ�������µ��ļ����ߴ����е��ļ� (O_RDONLY, O_WRONLY, or O_RDWR  O_TRUNC O_APPEND)
	��	��	:	>0			�ļ����
				����		ʧ��
*/

ssize_t vfs_Write(int _iFd, const void *_pBuf, size_t _iCount);
/*
	��	��	:	���ļ���д����
	��	��	:	_iFd		�ļ����
				_ucBuf		����ָ��
				_iLen		���ݳ���
	��	��	:	>0			ʵ��д������ݳ���
				����		ʧ��
*/

ssize_t vfs_Read(int _iFd, void *_pBuf, size_t _iCount);
/*
	��	��	:	���ļ��ж�ȡ����
	��	��	:	_iFd		�ļ����
				_ucBuf		����ָ��
				_iLen		���ݳ���
	��	��	:	>0			ʵ�ʶ�ȡ�������ݳ���
				����		ʧ��
*/

off_t vfs_Seek(int _iFd,long _lOffSet,int _iWhere);
/*
	��	��	:	�ļ���λ
	��	��	:	_iFd		�ļ����
				_lOffSet	ƫ����
				_iWhere		��ʼλ��
	��	��	:	td_success	�ɹ�
				����		ʧ��
*/

long vfs_Tell(int _iFd);
/*
	��	��	:	�����ļ�ָ���λ��
	��	��	:	_iFd		�ļ����
	��	��	:	>0			�ļ�ָ��ĵ�ǰλ��
				����		ʧ��
*/

int vfs_Eof(int _iFd);
/*
	��	��	:	�ж��Ƿ��ļ�β
	��	��	:	_iFd		�ļ����
	��	��	:	��0			���ļ�β
				0			δ���ļ�β
*/

int vfs_Close(int _iFd);
/*
	��	��	:	�ر��ļ�
	��	��	:	_iFd		�ļ����
	��	��	:	td_success	�ɹ�
				����		ʧ��
*/


int vfs_ScanDir(const char *dirp, struct dirent ***namelist);
/*
	��	��	:	���ļ����ڵ�Ŀ¼����ʱ���������,��Ҫע���ڴ��������ͷ�����
	��	��	:	dirp		Ŀ¼����
				namelist	������Ŀ¼�б�
							��׼�ļ�ϵͳΪĿ¼��
							tdfsΪ�����
	��	��	:	>0	�����������ļ��и���
				<	ʧ�ܷ���
*/

VDIR* vfs_OpenDir(const char* _cDir);
/*
	��	��	:	��ĳ��Ŀ¼
	��	��	:	_cDir		·������	
	��	��	:	td_success	�ɹ�
				����		ʧ��	
*/

//struct dirent *vfs_ReadDir(VDIR* _pVDir);
TTdStat *vfs_ReadDir(VDIR* _pVDir);
/*
	��	��	:	��ȡĿ¼�е�����
	��	��	:	_cDir		·������				
	��	��	:	td_success	�ɹ�
				����		ʧ��	
*/

int vfs_CloseDir(VDIR* _pVDir);
/*
	��	��	:	�ر�ĳ��Ŀ¼
	��	��	:	_cDir		·������				
	��	��	:	td_success	�ɹ�
				����		ʧ��	
*/

int vfs_Unlink(char* _cFileName);
/*
	��	��	:	ɾ��ָ�����ļ�
	��	��	:	_cFileName	�ļ���
	��	��	:	td_success	�ɹ�
				����		ʧ��
*/

int vfs_Stat(char* _cFileName,TTdStat *_buf);
/*
	��	��	:	��ȡ�ļ����������
	��	��	:	_cFileName	�ļ���
				_buf		�ļ����Խṹ��
	��	��	:	td_success	�ɹ�
				����		ʧ��				
*/

int vfs_Rename(const char *oldpath, const char *newpath);
/*
	��	��	:	¼���ļ�����/����
	��	��	:	_cFileName	�ļ���
				_iLock		0	����
							1	����
	��	��	:	td_success	�ɹ�
				����		ʧ��
*/

int vfs_utimes(const char *filename, const struct timeval times[2]);
/*
	��	��	:	�޸��ļ����޸�ʱ��
	��	��	:	_cFileName	�ļ���
				_iTime		ʱ��ֵ��ʹ����������ʾ	
						
	��	��	:	td_success	�ɹ�
				����		ʧ��
*/

int vfs_SetUsrParam(char* _cFileName,void *_pBuf,int _iLen);
/*
	��	��	:	�����û��Զ�������,EXT4�ļ�ϵͳ��֧�֣�ֱ�ӷ��سɹ�
	��	��	:	_cFileName	�ļ���
				_pBuf		����ָ��
				_iLen		���ݳ���	
						
	��	��	:	td_success	�ɹ�
				����		ʧ��
*/

int vfs_error(int _iFd);
/*
	��	��	:	��ȡ�ļ�ϵͳ���һ�εĳ�����Ϣ
	��	��	:	�������һ�γ�����Ϣ
	��	��	:	td_success		�ɹ�
				����			ʧ��
*/

int vfs_fsync(int _iFd);
/*
	��	��	:	ˢ��
	��	��	:	_iFd	���
	��	��	:	td_success		�ɹ�
				����			ʧ��
*/

int vfs_UpdataePreRecPtr(int _iFd,long _lBeginPtr,long _lEndPptr);
/*
	��	��	:	��Ԥ¼���Ŀ�ʼָ�뼰����ָ��д�뵽�ļ�ϵͳ��
	��	��	:	_iFd			�ļ����
				_lBeginPtr		Ԥ¼���ݵĿ�ʼ��ַ
				_lEndPptr		Ԥ¼���ݵĽ�����ַ
	��	��	:	td_success		�ɹ�
				����			ʧ��
*/

int vfs_ChangeRecType(char* _cFileName, int _iRecType);
/*
    ��  ��  :   �޸�¼���ļ���¼������(Ԥ¼ת��ʽ¼��ʱʹ��)
    ��  ��  :   _cFileName  �ļ���
                _iRecType   ¼������(TRecordType����)
                        
    ��  ��  :   td_success  �ɹ�
                ����        ʧ��
*/

TVfile* vfs_fopen(TTFileParam* _pFileParam,IN OUT char* _cFileName,char* _cMode);

int vfs_fread(void *ptr, size_t size, size_t nmemb, TVfile *stream);

int vfs_fwrite(const void *ptr, size_t size, size_t nmemb, TVfile *stream);

int vfs_fseek(TVfile *stream, long offset, int whence);

long vfs_ftell(TVfile *stream);

int vfs_feof(TVfile *stream);

int vfs_fclose(TVfile *fp);

int vfs_ftruncate(int _iFd, td_u64 length);

int vfs_fcntl(int fd, int cmd, long flg);

int vfs_ChangeCreateTime(char* _cFileName,const struct timeval _times);

#endif 



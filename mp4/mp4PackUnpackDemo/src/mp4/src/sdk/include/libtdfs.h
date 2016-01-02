#ifndef __LIBTDFS_H__
#define __LIBTDFS_H__

#include <sys/stat.h> 
#include <sys/statfs.h> 
#include <sys/types.h>
#include <unistd.h>

#include "public_def.h"

#define TDFS_KEY_PATH  "/dvr/tdfs"

enum
{
	FILEUNLOCK,
	FILELOCK,
	FILEBACK,
};

typedef enum
{
	FS_TD,
	FS_NORMAl,
}TFsType;

typedef enum
{
	TD_FILE_TYPE_REC = 0,	//¼���ļ�
	TD_FILE_TYPE_PRO,		//Ԥ¼�ļ�
	TD_FILE_TYPE_BACKUP,    //����¼���ļ�
	TD_FILE_TYPE_PIC,		//ͼƬ�ļ�
}TTdFileType;

#define FILE_REV_ATTR_LEN 32

typedef struct
{
	struct stat m_stat;
	td_u64		m_iRecChn;
	td_u64 		m_iRecLock;
	td_u64 		m_iRecType;
	td_u64		m_lRecStartTm;
	td_char		m_iOthAttribute[FILE_REV_ATTR_LEN];			//�Զ�������	
	char		m_cFileName[FULL_PATH_LEN];		//�ļ���
}TTdStat;

typedef struct
{
	struct statfs m_statfs;
}TTdStatfs;

typedef struct
{
	int 		m_iChn;							//ͨ����	
	int			m_iTime;						//¼���ļ��Ŀ�ʼʱ��		
	TTdFileType m_eType;						//¼���ļ����ͣ�¼��/Ԥ¼/ͼƬ
	int			m_iPreSize;						//������;:Ԥ¼�ļ���С�������ļ���С;��λbyte
	int			m_iParam;						//¼���ļ�����(�ֶ�����ʱ��������......)
	int  		m_iCustomType;					//�Զ������ͻ��ߺ���ֵ
	char		m_cBlockDevPath[FULL_PATH_LEN];	//���豸·��
	char        m_cExtName[8];
}TTFileParam;

typedef struct
{
	int 		m_iId;					//����
	td_u64 		m_lStartTime;		//�����ʼʱ��
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


int tdfs_Init();
/*
	��	��	:	��ʼ���ļ�ϵͳ��
	��	��	:

	��	��	:	td_success	�ɹ�
				����		ʧ��
*/

int tdfs_DeInit();
/*
	��	��	:	�ر��ļ�ϵͳ
	��	��	:	��
	��	��	:	td_success	�ɹ�
				����		ʧ��	
*/

int tdfs_Format(char* _cBlockDevPath);
/*
	��	��	:	��ʽ������
	��	��	:	_cBlockDevPath	���豸·��
	��	��	:	td_success		�ɹ�
				����			ʧ��	
*/

int tdfs_Statfs(char* _cBlockDevPath,TTdStatfs *_pBuf);
/*
	��	��	:	��ȡ���̿ռ���Ϣ
	��	��	:	_cBlockDevPath	���豸·��
				_pBuf			������̿ռ���Ϣ��ָ��
	��	��	:	td_success		�ɹ�
				����			ʧ��	
*/

int tdfs_GetUsedBlockNum(char* _cPath);
/*	
	��	��	:	��ȡ���������õĿ���
	��	��	:	_cBlockDevPath	���豸·��
	��	��	:	>0				��������ʹ�õ��ܿ���
				<0				ʧ��
*/

int tdfs_GetBlockInfo(char* _cPath,TBlockInfo* _pInfo,int _iNum);
/*
	��	�� 	:	��ȡ��Ŀ�ʼʱ��
	��	��	:	_cBlockDevPath	���豸·��
				_pInfo			��������
				_iNum			���룬���������鳤��
								�����ʵ�ʷ��صĿ����Ը���
	��	��	:	td_success		�ɹ�
				����			ʧ��		
*/

int tdfs_GetFileNum(char* _cPath,int _iBlockId);
/*
	��	�� 	:	��ȡ���ڵ��ļ�����
	��	��	:	_cBlockDevPath	���豸·��
				_iBlockId		����
	��	��	:	>0				���ڵ��ļ�����
				<0				ʧ��
*/
int tdfs_BlockStat(char* _cPath,int _iBlockId,TTdStat* _pStat,int _iNum);
/*	
	��	�� 	:	��ȡָ�����������ļ�����
	��	��	:	_cBlockDevPath	���豸·��
				_iBlockId		����
				_pStat			�ļ���������
				_iNum			���룬�ļ��������鳤��
								�����ʵ�ʷ��ص��ļ����Ը���
	��	��	:	td_success		�ɹ�
				����			ʧ��			
*/

int tdfs_Open(TTFileParam* _pFileParam,char* _cFileName,int _iMode);
/*
	��	��	:	���ļ�	
	��	��	:	_cFileName 	�ļ���������tdfs_CreateFile������ȡ
				_iMode		�򿪷�ʽ�������µ��ļ����ߴ����е��ļ� (O_RDONLY, O_WRONLY, or O_RDWR  O_TRUNC O_APPEND)
	��	��	:	>0			�ļ����
				����		ʧ��
*/

ssize_t tdfs_Write(int _iFd, const void *_pBuf, size_t _iCount);
/*
	��	��	:	���ļ���д����
	��	��	:	_iFd		�ļ����
				_ucBuf		����ָ��
				_iLen		���ݳ���
	��	��	:	>0			ʵ��д������ݳ���
				����		ʧ��
*/

ssize_t tdfs_Read(int _iFd, void *_pBuf, size_t _iCount);
/*
	��	��	:	���ļ��ж�ȡ����
	��	��	:	_iFd		�ļ����
				_ucBuf		����ָ��
				_iLen		���ݳ���
	��	��	:	>0			ʵ�ʶ�ȡ�������ݳ���
				����		ʧ��
*/

off_t tdfs_Seek(int _iFd, off_t _lOffSet, int _iWhere);
/*
	��	��	:	�ļ���λ
	��	��	:	_iFd		�ļ����
				_lOffSet	ƫ����
				_iWhere		��ʼλ��
	��	��	:	td_success	�ɹ�
				����		ʧ��
*/

ssize_t tdfs_Tell(int _iFd);
/*
	��	��	:	�ļ���λ
	��	��	:	_iFd		�ļ����
	��	��	:	>0			�ļ�ָ��ĵ�ǰλ��
				����		ʧ��
*/

int tdfs_Eof(int _iFd);
/*
	��	��	:	�ж��Ƿ��ļ�β
	��	��	:	_iFd		�ļ����
	��	��	:	��0			���ļ�β
				0			δ���ļ�β
*/

int tdfs_Close(int _iFd);
/*
	��	��	:	�ر��ļ�
	��	��	:	_iFd		�ļ����
	��	��	:	td_success	�ɹ�
				����		ʧ��
*/

int tdfs_Unlink(char* _cFileName);
/*
	��	��	:	ɾ��ָ�����ļ�
	��	��	:	_cFileName	�ļ���
	��	��	:	td_success	�ɹ�
				����		ʧ��
*/

int tdfs_Stat(char* _cFileName,TTdStat *_buf);
/*
	��	��	:	��ȡ�ļ����������
	��	��	:	_cFileName	�ļ���
				_buf		�ļ����Խṹ��
	��	��	:	td_success	�ɹ�
				����		ʧ��				
*/

int tdfs_Lock(char* _cFileName,int _iLock);
/*
	��	��	:	¼���ļ�����/����
	��	��	:	_cFileName	�ļ���
				_iLock		0	����
							1	����
	��	��	:	td_success	�ɹ�
				����		ʧ��
*/
int tdfs_ChangeCreateTime(char* _cFileName,const struct timeval _times);
/*
��	��	:	�޸��ļ��Ŀ�ʼʱ��
��	��	:	_cFileName	�ļ���
			_times		ʱ��ֵ	
					
��	��	:	td_success	�ɹ�
			����		ʧ��

*/

int tdfs_ChangeTime(char* _cFileName,const struct timeval _times[2]);
/*
	��	��	:	�޸��ļ����޸�ʱ��
	��	��	:	_cFileName	�ļ���
				_iTime		ʱ��ֵ��ʹ����������ʾ	
						
	��	��	:	td_success	�ɹ�
				����		ʧ��
*/

int tdfs_ChangeRecType(char* _cFileName, int _iRecType);
/*
    ��  ��  :   �޸�¼���ļ���¼������(Ԥ¼ת��ʽ¼��ʱʹ��)
    ��  ��  :   _cFileName  �ļ���
                _iRecType   ¼������(TRecordType����)
                        
    ��  ��  :   td_success  �ɹ�
                ����        ʧ��
*/

int tdfs_SetUsrParam(char* _cFileName,void *_pBuf,int _iLen);
/*
	��	��	:	�����û��Զ�������
	��	��	:	_cFileName	�ļ���
				_pBuf		����ָ��
				_iLen		���ݳ���	
						
	��	��	:	td_success	�ɹ�
				����		ʧ��
*/

int tdfs_error(int _iFd);
/*
	��	��	:	��ȡ�ļ�ϵͳ���һ�εĳ�����Ϣ
	��	��	:	�������һ�γ�����Ϣ
	��	��	:	td_success		�ɹ�
				����			ʧ��
*/

int tdfs_fsync(int _iFd);
/*
	��	��	:	ˢ��
	��	��	:	_iFd	���
	��	��	:	td_success		�ɹ�
				����			ʧ��
*/

int tdfs_UpdataePreRecPtr(int _iFd,long _lBeginPtr,long _lEndPptr);
/*
	��	��	:	��Ԥ¼���Ŀ�ʼָ�뼰����ָ��д�뵽�ļ�ϵͳ��
	��	��	:	_iFd			�ļ����
				_lBeginPtr		Ԥ¼���ݵĿ�ʼ��ַ
				_lEndPptr		Ԥ¼���ݵĽ�����ַ
	��	��	:	td_success		�ɹ�
				����			ʧ��
*/
int tdfs_ftruncate(int _iFd,td_u64 _lRecSize);
/*
	��	��	:	�޸��ļ���С
	��	��	:	_iFd			�ļ����
				_lRecSize		�ļ���С
				
	��	��	:	td_success		�ɹ�
				����			ʧ��
*/

int tdfs_Mount(char* _cPath);
/*
*/
int tdfs_UnMount(char* _cPath);

int tdfs_GetDebugInfo(char * _strBuf, int _iBufSize);
/*
*/



#endif 

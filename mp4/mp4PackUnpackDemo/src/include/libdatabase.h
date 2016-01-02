/*******************************************************************
�ļ���	:database.h
��˾	:������ΰҵ����Ƽ����޹�˾
������	:������
��������:2009-11-25
��Ҫ����:���ݿ���غ�����ԭ��
�޸ļ�¼:2009-11-25,������������
		 2011-03-14,���ɣ��޸Ľӿ�����
        
******************************************************************/

#ifndef _LIB_DATABASE_H_
#define _LIB_DATABASE_H_

#include "public_def.h"

#define DB_MAX_NUM  9



typedef enum
{
	COLUMN_INDEX = 0,
	COLUMN_CHN,
	COLUMN_FILETYPE,
	COLUMN_RECTYPE,
	COLUMN_DEVTYPE,
	COLUMN_RECATTR,
	COLUMN_NAME,
	COLUMN_SIZE,
	COLUMN_START,
	COLUMN_STOP,
	COLUMN_RESERVED,
	COLUMN_MAX
}TDbTableColumn;

int db_Init(int _iDisksExist);

/*
 * �������ƣ�InitDB
 * ��Ҫ����: ��ʼ�����ݿ���ģ��
 * ��	  �룺
 * 			���ô��̣���λ��ʾ
 * ��	  ����
 * 			ERR_REC_SUCCESSFUL,�����ɹ�
 * 			ERR_REC_FAILED,����ԭ���²���ʧ��
 */
 
int db_IsInited(void);
/*
 * �������ƣ�IsDBInited
 * ��Ҫ����: ��ѯ���ݿ�ģ���Ƿ��ѳ�ʼ��
 * ��	  �룺
 * 			��
 * ��	  ����
 * 			1,�ѳ�ʼ��
 *			0��δ��ʼ��
 * �޸���־��
 * 			2009-11-26,������,��storage.c��Ų��database.c
 */
 
int db_Exit(void);
/*
 * �������ƣ�ExitDB
 * ��Ҫ����: �˳����ݿ�ģ��
 * ��	  �룺
 * 			��
 * ��	  ����
 * 			ERR_REC_SUCCESSFUL,�����ɹ�
 * 			ERR_REC_CLOSE_DB_FAILED,�ر����ݿ�ʧ��
 * �޸���־��
 * 			2009-11-26,������,��storage.c��Ų��database.c
 */
int db_OpenDb(int _iDbNum);
/*
*����:�����ݿ�
*����:���ݿ��Ӧ���̱��
*/

int db_CloseDB(int _iDbNum);
/*
*����:�ر����ݿ�
*����:���ݿ��Ӧ���̱��
*/
td_s32 db_Cleardb(int _iDbNum);
td_s32 db_ExecSql(const char* _pcSql, int _iDbNum);
/*
 * �������ƣ�ExecSql
 * ��Ҫ����: ִ��SQL���
 * ��	  �룺
 * 			_pcSql,SQL��䣬�ǿ�
 * ��	  ����
 * 			ERR_REC_SUCCESSFUL,�����ɹ�
 * 			ERR_REC_QUERY_INDEX_FAILED,ִ��SQL���ʧ��
 * �޸���־��
 * 			2009-11-26,������,��storage.c��Ų��database.c
 */
int db_GetRebuildState(int _iDbNum);
/*
*��ȡ���ݿ��ؽ�����״̬
*����:_iState	0,�ؽ���ɣ�1,�ؽ���ʼ
*/
int db_SetRebuildState(int _iState, int _iDbNum);
/*
*�������ݿ��ؽ�����״̬
*����:_iState	0,�ؽ���ɣ�1,�ؽ���ʼ
*/
int db_GetTable(const char* _pucSql, char*** _pppcResult, int* _piRow, int* _piColumn, int _iChn);
/*
 * �������ƣ�GetTable
 * ��Ҫ����: ��SQL����ѯ��¼
 * ��	  �룺
 * 			_pucSql,SQL��䣬�ǿ�
 *			_pppcResult, ���ڴ���������ǿ�
 *			_piRow, ���ڴ������ж�������¼
 *			_piColumn, ���ڴ���ÿ����¼�м����ֶ�
 * ��	  ����
 * 			ERR_REC_SUCCESSFUL,�����ɹ�
 * 			ERR_REC_GET_TABLE_FAILED,ִ��SQL���ʧ��
 * �޸���־��
 * 			2009-11-26,������,��storage.c��Ų��database.c
 */
int db_GetCountOrSum(const char* _pcSql, int _iChn);
/*
*����:��ȡ��Ŀ������ͳ�����ܺ�
*����:
*		_pcSql:	sql��䣬�ǿ�
*		_iChn:	ͨ����
*/
int db_GetTableEx(const char* _pcSql, TQueryResult** _ppstResult, int* _piRow, int* _piColumn, int _iChn, unsigned int _iDbNums, int _iMaxColNum);
/*
*����:��ѯ���ݿ�
*/

int db_GetDB(void **_pstDB);
/*
 * �������ƣ�db_GetDB
 * ��Ҫ����: ���⺯���������ⲿ��ȡ�򿪵����ݿ�ָ��
 * ��	  �룺
 *			_pstDB, ���ڴ������
 * ��	  ����
 * 			TD_SUCCESS,�����ɹ�
 * 			TD_FAILURE,ִ��SQL���ʧ��
 * �޸���־��
 * 			2011-12-28,���
 */
 int db_Sqlite3Exec(void *_pstDB, const char *sql, int (*callback)(void*,int,char**,char**), void *_CallBackParam, char **errmsg);
/*
 * �������ƣ�db_Sqlite3Exec
 * ��Ҫ����: ���⺯���������ⲿ�������ݿ��sqlite3_exec����
 * ��	  �룺
 *			��sqlite3_exec()������ֵ��ͬ
 * ��	  ����
 * 			����ֵ��sqlite3_exec()�ķ���ֵ��ͬ
 * �޸���־��
 * 			2011-12-28,���
 */
typedef void (*db_ChangeCallBack)(void);
int db_RegChangeCallBack(db_ChangeCallBack _CallBack);
int db_ExecSqlTrans(char** _pcSql, int _iCount,int _iDbNum);
int db_ExecSqlRight(const char* _pcSql, int _iDbNum);
/*
 * �������ƣ�db_ExecSqlRight
 * ��Ҫ����: ִ��SQL���,����Ҫ����ִ�У���������sql���д���
 * ��	  �룺
 * 			_pcSql,SQL��䣬�ǿ�
 *			_iDbNum,���ݿ��Ӧ���̺�
 * ��	  ����
 * 			ERR_REC_SUCCESSFUL,�����ɹ�
 * 			ERR_REC_QUERY_INDEX_FAILED,ִ��SQL���ʧ��
 * �޸���־��
 * 			20121127�����ɴ���
 */

/*
*��Ҫ����:ע�������ݿ�仯�Ļص�����
*/
int db_GetTableName(char* _pcTableName[]);
int db_GetRebuildState(int _iDbNum);
void db_FreeResultMem(TQueryResult* _pstResultMem);
TQueryResult *db_MallocResultMem(unsigned int _usSize);

#endif /*_DATABASE_H_*/



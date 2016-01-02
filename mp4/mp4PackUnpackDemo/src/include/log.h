/*******************************************************************
�ļ���	  :Log.h
��˾	        :TIANDY
������	  :YP
��������:2009-09-01
��Ҫ����:��־���ݽṹ���弰��غ�������
�޸ļ�¼:
        
******************************************************************/

#ifndef LOG_H_
#define LOG_H_

#include "log_template.h"

#define LOG_ONE_SIZE			100  //��־ÿ����¼�ĳ��ȣ���λByte
#define LOG_MIN_FILE_SIZE		1000   //��־�ļ�����С��С����λKByte
#define LOG_MAX_FILE_SIZE		16 * 1000 //��־�ļ�������С����λKByte
#define LOG_FLASH_FILE_SIZE		100

#define MAX_LOG_PAGE_SIZE		20	//ÿҳ�����ʾ����־����
#define MAX_LOG_TEMPLATE_LEN	100 //��־��Ӣ��ģ��ÿ�е���󳤶�
#define MAX_LOG_MSG_LEN			128	//��־���ݵ���󳤶�
#define MAX_LOG_WRITE_PARA_STRING_TYPE_SIZE 30 //��¼��־�����ַ����������͵���󳤶�
#define MAX_LOG_LEN			(MAX_LOG_MSG_LEN - 1)		//�����־���ݳ���
#define MAX_LENGTH_USER_NAME 16
//#define LANG_EN					0 		//��ѯӢ��ģ��
//#define LANG_CH					1		 //��ѯ����ģ��
typedef int (*GetUseInfo)(int _socket, char *_pcstrUserName, int _iMaxUserNameLen);

typedef enum
{
	LANG_EN = 0,     //��ѯӢ��ģ��
	LANG_CH,         //��ѯ����ģ��
	LANG_TCH,        //��ѯ��������ģ��
	LANG_KOR,        //��ѯ����ģ��
	LANG_SPAN,       //��ѯ��������ģ��
	LANG_ITA,        //��ѯ�����ģ��
	LANG_ALL,
}TLogLangType;

#define CHANNEL_ALL				0xFF     //��ѯ����ͨ��
#define CHANNEL_INVALID			0xF0     //��ͨ���޹�
#define LOG_DEL_FLAG			0xFFFF   //��־��¼�Ѿ�ɾ����־

#define LOG_LEVEL_NUM       	7  		 //��־��������
#define LOG_LEVEL_MIN			0		 //��־��С����
#define LOG_LEVEL_ALL			0xFF	 //��ѯ���м���
#define LOG_LEVEL_SET_ALL		((0x1 << LOG_LEVEL_NUM) - 1)	//��־��������ȫ����
#define TAB_STR					"\t"	 //�ָ����ַ���
#define TAB_CHAR				'\t'	 //�ָ����ַ�

typedef struct		//��־�ļ�ȫ����Ϣ�ṹ
{
	td_u32	m_cLevel;		//�洢�����¼����־�ļ���
	td_u32 	m_usFileSize;	//�ϲ����õ�  �洢��־�ļ��Ĵ�С����λk
	td_u32 	m_usIndex;		//���ڱ�����־������
	td_bool	m_bCovered;     //��־�ļ�ѭ�����Ǳ��
	td_u8 * m_uLogFileName;	//������־��¼�ļ���
} gen_TLogInfo;
#define LOGINFO_DEFAULT \
	(gen_TLogInfo){LOG_LEVEL_SET_ALL, LOG_MAX_FILE_SIZE, 0, td_false}

typedef struct				//��־ÿ����¼��ͷ�ṹ��������ѯ
{
	td_u32	m_usIndex; 		//����
	time_t	m_iTime;   		//��¼��ʱ��
	td_u32	m_iChannel;		//ͨ����
	td_u32	m_cLevel;  		//����
	td_u32	m_uiTemInd;		//ģ���
	td_u8	m_UserName[MAX_LENGTH_USER_NAME + 1];
} gen_TLogHead;

#define LOG_HEAD_SIZE (sizeof(gen_TLogHead))
#define MSG_SIZE (LOG_ONE_SIZE - LOG_HEAD_SIZE)		  //ÿ����־��������С

typedef struct				//д��־�����ṹ��
{
	gen_TLogHead m_gLogHead;
	td_u8	m_uMsgParaStr[MSG_SIZE]; //������
} gen_TLog;


typedef struct				//��־��Ϣ
{
	gen_TLogHead m_gLogHead;
	td_u8	m_cContent[MAX_LOG_MSG_LEN]; //��־����
}TLogInfo;

typedef struct				//��ѯ��־��Ϣ�Ľṹ��
{
	td_s32	m_blLang;		//�����Ӣ��
	td_s32	m_iPageNo;		//ҳ��
	td_s32	m_iPageSize;	//ÿҳ�Ĵ�С
	td_s32	m_iTotalNum;	//�ܲ�ѯ����
	td_s32	m_iShowNum;		//���β�ѯ������
	td_u32	m_iLevel;		//��־����
	td_u32	m_iChannel;		//��־����ͨ����
	time_t	m_iStartTime;	//��ʼ��ѯʱ��
	time_t	m_iStopTime;	//������ѯʱ��
	TLogInfo m_stInfo[MAX_LOG_PAGE_SIZE]; //��ѯ���	
}TLogQuery;
#define QUERY_START_TIME_DEFAULT	0			//Ĭ�ϲ�ѯ��ʼʱ��
#define QUERY_STOP_TIME_DEFAULT		1352240666	//Ĭ�ϲ�ѯ����ʱ��
#define LOGQUERY_DEFAULT (TLogQuery){LANG_EN,0,MAX_LOG_PAGE_SIZE,0,0,\
	LOG_LEVEL_ALL,CHANNEL_ALL,QUERY_START_TIME_DEFAULT,QUERY_STOP_TIME_DEFAULT}

typedef enum		//��־����
{
	LOG_LEVEL_SYSTEM = 0,//ϵͳ�����������ػ��������ļ�,�������ش����
	LOG_LEVEL_WARNING,	 //���棬�����쳣ʱ���棬����������������жϵ�
	LOG_LEVEL_ALARM,	 //��������Ҫָ��Ƶ��ʧ���ƶ���⡢�˿ڱ�����
	LOG_LEVEL_OPERATION, //�������޸����ã�������Ƶ��¼�񣬶Խ������������������
	LOG_LEVEL_USER,		 //�û��������û���¼�ǳ������ɾ�����޸������
	LOG_LEVEL_OTHER,	 //�����������������������е���������
	LOG_LEVEL_DEBUG,	//������־
}TLogLevel;

td_s32 log_Get(td_u32 * _piMinLevel, td_u32 * _piFileSize);
/*
 * �������ƣ�log_Get
 * ��Ҫ����: ��ȡ��־ģ�����ز���
 * ��	  �룺
 * 			_piMinLevel, ���ڴ�����־��ʾ����
 *			_piFileSize, ���ڴ�����־�ļ��Ĵ�С����λΪK
 * ��	  ����
 * 			ERR_LOG_WRONG_PARAM,����Ĳ���
 * 			ERR_LOG_SUCCESSFUL,�����ɹ�
 * 			ERR_LOG_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2009-09-01
 */
td_s32 log_Set(td_u32 _iMinLevel, td_u32 _iFileSize);
/*
 * �������ƣ�log_Set
 * ��Ҫ����: ������־ģ�����ز���
 * ��	  �룺
 * 			_iMinLevel, ��־��ʾ����
 *			_iFileSize, ��־�ļ��Ĵ�С����λΪK
 * ��	  ����
 * 			ERR_LOG_WRONG_PARAM,����Ĳ���
 * 			ERR_LOG_SUCCESSFUL,�����ɹ�
 * 			ERR_LOG_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2009-09-01
 */
#if 0
td_s32 log_Write(td_u32 _cLevel, td_u32 _iChannelNo, td_u32 _temID, td_u8* _pcMsg, ...);
/*
 * �������ƣ�log_Write
 * ��Ҫ����: ����־�ļ�д��һ����־
 * ��	  �룺
 * 			_iLevel, ������־�ļ����Ի����
 *			_iChannelNo,����־��ص�ͨ��
 *			_temID,����־��ģ���
 *			_pcMsg, ��־���ݲ������ʹ�
 *			..., ��־���ݲ�����
 *			ע��:�������ʹ�+���������ΪMSG_SIZE(47Bytes)��С
 * ��	  ����
 * 			ERR_LOG_WRONG_PARAM,����Ĳ���
 * 			ERR_LOG_SUCCESSFUL,�����ɹ�
 * 			ERR_LOG_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2009-09-01
 */
 #endif
td_s32 log_Query(TLogQuery* _stQ);
/*
 * �������ƣ�Query
 * ��Ҫ����: ��ѯ��־, �������͡�ͨ��������ʱ�䡢ҳ������ѯ
 * ��	  �룺
 * 			_stQ, �ǿ�
 * ��	  ����
 * 			ERR_LOG_WRONG_PARAM,����Ĳ���
 * 			ERR_LOG_SUCCESSFUL,�����ɹ�
 * 			ERR_LOG_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2009-09-01
 */
td_s32 log_QueryEx(TLogQuery* _stQ);
td_s32 log_Clear();
/*
 * �������ƣ�Clear
 * ��Ҫ����: �����־, ʹ֮Ϊ0
 * ��	  �룺
 * 			��
 * ��	  ����
 * 			ERR_LOG_WRONG_PARAM,����Ĳ���
 * 			ERR_LOG_SUCCESSFUL,�����ɹ�
 * 			ERR_LOG_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2009-09-01
 */

td_s32 log_Init(GetUseInfo _fun);
/*
 * �������ƣ�Init
 * ��Ҫ����: ��־ģ��ȫ�ֱ�����ʼ��, ���ļ��������ڴ�
 * ��	  �룺
 * 			��
 * ��	  ����
 * 			ERR_LOG_WRONG_PARAM,����Ĳ���
 * 			ERR_LOG_SUCCESSFUL,�����ɹ�
 * 			ERR_LOG_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2009-09-01
 */

td_s32 log_Exit();
/*
 * �������ƣ�Exit
 * ��Ҫ����: ��־ģ���ȥ��ʼ��, �ر��ļ����ͷ��ڴ�
 * ��	  �룺
 * 			��
 * ��	  ����
 * 			ERR_LOG_WRONG_PARAM,����Ĳ���
 * 			ERR_LOG_SUCCESSFUL,�����ɹ�
 * 			ERR_LOG_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2009-09-01
 */


int log_fflushCacheMem(unsigned long _param);

td_s32 log_Write(td_u32 arg, td_u32 _cLevel, td_u32 _iChannelNo, td_u32 _temID, td_u8* _pcMsg, ...);
//��־�л��洢·��,��ʱ����
td_s32 log_ChangePath(td_s32 _iDiskNo, td_s32 _iFormatStat);
td_s32 log_Pause(td_s32 _iDiskNo);
td_s32 log_Restart(td_s32 _iDiskNo);




#endif

/*******************************************************************
�ļ���	:vod.h
��˾	:������ΰҵ����Ƽ����޹�˾
������	:������
��������:2009-11-05
��Ҫ����:��洢��صı�������Ķ��壬�洢ģ��ӿں���ԭ��
�޸ļ�¼:2009-11-05,������������
        
******************************************************************/
#ifndef _VOD_H_
#define _VOD_H_

#include "public_def.h"
#include "libstorage.h"
#include "net_tcp_common.h"

#define MAX_VOD_FILE_NUM		1024	//��ʱ���VODʱ���ļ��б�����
#define MAX_VOD_CONNECT			5		//���VOD������
#define IS_INVALID_VOD(client)	(client == NULL || (client->m_hRecState == 1 || client->m_hSendState == 1))
#define IS_SEGMENT_VOD(vod)		(vod.m_stSeg.m_iStartTime + vod.m_stSeg.m_iStopTime\
								+ vod.m_stSeg.m_iFileNum != 0)
#define SEGMENT_PREFIX			"TM"
#define SEGMENT_SPLIT			":"
#define SEGMENT_INTERVAL		86400 * 7	//��ʱ���VOD������ȣ�������������
#define SEGMENT_OFFSET			7200		//Ϊ��ȷ��ʱ������ڵ��׸��ļ�������������Ҫ��ǰ���ҡ�

#define VOD_FILETAIL_TIMEOUT	60000		//VOD�����ļ�������ʱ���ر��ļ�����λ:����
#define VOD_PROGRESS_INTERVAL	2000		//��ʱ���VOD���ȷ��ͼ��

//������ 091106 ��ʱ���VOD����Ϣ
typedef struct
{
	time_t		m_iStartTime;							//��ʼʱ��
	time_t		m_iStopTime;							//����ʱ��
	td_s32		m_iFileNum;								//�ļ��б��е��ļ���Ŀ
	td_s32		m_iHead;								//��ʶ�����������׸��Ϸ��ļ���λ��
	td_s32		m_iPos;									//��ǰ���ڲ��ŵ��ļ�λ��
	TFileInfo*	m_pstFileList;							//�ļ��б�
	td_s32		m_iCurFrameRate;						//��ǰ���ڲ��ŵ��ļ���֡��
	td_s32		m_iCurFirstFrameNo;						//��ǰ���ڲ��ŵ��ļ�����֡֡��
}TVodBySegment;

//VOD״̬ö��
typedef enum
{
	VOD_STATE_FREE,
	VOD_STATE_PREPARING,
	VOD_STATE_SENDING,
	VOD_STATE_PAUSE,//��ͣ
	VOD_STATE_END,//��ʶ�ļ�β.���ļ�βʱ�����ʱ���ر�����
	VOD_STATE_STOP,
	VOD_STATE_BUTT,
}TVodState;


//VOD�ṹ
typedef struct
{
	PCONNECT	m_stClient;								//��¼������Ƶ������
	td_s32		m_iInterval;							//���ͼ��
	td_u64		m_ulSendTime;							//����ʱ�䣬 ��λ����
	FILE*		m_fp;									//Ҫ���͵��ļ�
	td_s32		m_iPosition;							//��λ,-1,��ʾ�������ţ�0~100��ʾ�ðٷֱȶ�λ
	td_s32 		m_iSpeed;								//�����ٶ�
	td_s32		m_iIFrame;								//�Ƿ�ֻ��I֡
	td_s32		m_iFileSize;							//�ļ��ܴ�С
	td_u8		m_ucFileType;							//�ļ�����
//	pthread_mutex_t	m_stMutex;							//������ ������ 090804 ���
	TVodState     m_iState;						    	//vod״̬��־
	TVodBySegment m_stSeg;					 		    //��ʱ���VOD����Ϣ
	td_s32        m_iDownMode;                          //����ģʽ����ֵΪ0
	td_s32        m_iBreakStat;                         //�ϵ�����״̬����ֵΪ2
	td_s32        m_iSendFileSize;
}TVod;

 
td_s32 rec_AddLink(void* _stClient, td_u8* _pucFilename, td_s32 _iReqMode, td_s32 _iBreak);
/*
 * �������ƣ�rec_AddLink
 * ��Ҫ���������һ��¼�񲥷ſͻ���.����ÿͻ��˵�ǰ���ڰ�ʱ��λطţ���Ϊ�������ʱ���׷��һ��ʱ���
 * ��	  �룺
 * 			_stClient,PCONNECT�ͣ����ڱ�ʶһ�����ӣ��ǿ�
 * 			_pucFilename,��������ļ���,�ǿ�
 *                 _iReqMode, ����ģʽ��0----֡ģʽ��1----��ģʽ
 *                 _iBreak, �ϵ�����2 ----�ϵ�����
 * ��	 ����
 * 			ERR_REC_TOO_MANY_USERS,�Ѵ�����û���
 * 			ERR_REC_OPEN_FILE_FAILED,���ļ�ʧ��
 * 			ERR_REC_READ_FILE_ERROR,���ļ���������
 *			ERR_REC_WRONG_PARAM,����Ĳ���
 * 			ERR_REC_FAILED,����ԭ����ʧ��
 *			ERR_REC_SUCCESSFUL,�ɹ�
 * �޸���־��
 * 			2008-10-22,������,����
 */
td_s32 rec_CloseLink(void* _stClient);
/*
 * �������ƣ�rec_CloseLink
 * ��Ҫ������ֹͣһ��¼���ļ���������
 * ��	  �룺
 * 			_stClient,PCONNECT�ͣ����ڱ�ʾһ���ͻ�������
 * ��	 ����
 *			ERR_REC_WRONG_PARAM,����Ĳ���
 * 			ERR_REC_FAILED,����ԭ����ʧ��
 *			ERR_REC_SUCCESSFUL,�ɹ�
 * �޸���־��
 * 			2008-10-22,������,����
 */
 td_u32 rec_ErrorHandler(td_u32 _iSocket);
/*
 * �������ƣ�rec_ErrorHandler
 * ��Ҫ������������
 * ��	  �룺
 * 			��
 * ��	 ����
 * 			ERR_REC_SUCCESSFUL
 *			
 * �޸���־��
 * 			2010-08-14,������,����
 */
td_s32 rec_VodCtrl(void* _stClient, td_s32 _iPosition, td_s32 _iSpeed, td_s32 _iIFrame);
/*
 * �������ƣ�rec_VodCtrl
 * ��Ҫ����������¼���ļ����ŵ��ٶȡ����ȵ�
 * ��	  �룺
 * 			_stClient,PCONNECT�ͣ����ڱ�ʾһ���ͻ�������
 *			_iPosition,���ڶ�λ�ļ���0~100
 *			_iSpeed,���ڿ����ļ��Ĳ����ٶ�,0~32,0��ʾ��ͣ��1��ʾ�����ٶȲ���
 *			_iIFrame,ֻ����I֡
 * ��	 ����
 *			ERR_REC_WRONG_PARAM,����Ĳ���
 * 			ERR_REC_FAILED,δ�ҵ�������
 *			ERR_REC_SUCCESSFUL,�ɹ�
 * �޸���־��
 * 			2008-10-22,������,����
 */

td_s32 rec_IsVodNull(td_s32 _iId);
/*
 * �������ƣ�IsVodNull
 * ��Ҫ�������ж�ĳ��VOD�ڵ��Ƿ�Ϊ��
 * ��	  �룺
 * 			_iId,VOD�ڵ��ţ��������±꣬0~MAX_VOD_CONNECT
 * ��	 ����
 *			ERR_REC_WRONG_PARAM,����Ĳ���
 * 			ERR_REC_FAILED,����ԭ����ʧ��
 *			ERR_REC_SUCCESSFUL,�ɹ�
 * �޸���־��
 * 			2009-11-20,������,����
 */

td_s32 rec_VodInit(void);
/*
 * �������ƣ�VodInit
 * ��Ҫ��������ʼ��VOD��ģ��
 * ��	  �룺
 * 			��
 * ��	 ����
 * 			ERR_REC_FAILED,����ԭ����ʧ��
 *			ERR_REC_SUCCESSFUL,�ɹ�
 * �޸���־��
 * 			2010-01-29,������,����
 */
 
td_s32 rec_CloseLinkByID(td_s32 _iID);
/*
 * ��������:CloseLinkByID
 * ��Ҫ����:����ID�ر�VOD����
 * ��	 ��:
 *          ����ID
 * ��	 ��:
 *			ERR_REC_SUCCESSFUL, ��ȡ�ɹ�
 * �޸���־:
 *			2009-03-02,��������������
 */
td_s32 rec_GetVodNetCost();

#endif /*_VOD_H_*/


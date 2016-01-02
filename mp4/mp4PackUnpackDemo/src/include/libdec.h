#ifndef _LIB_DEC_H_
#define _LIB_DEC_H_

#include "td_types.h"
#include "td_errno.h"
#include "td_media.h"

typedef struct
{
    int 	m_iWidth;				//��Ƶ���
    int 	m_iHeight;				//��Ƶ�߶�
}VideoDimSize;	//��Ƶ�ߴ�

typedef struct
{
	td_s32	m_iType; 				//��������	
	td_s32	m_iMod; 				//֡ģʽ  ��ģʽ	
	td_s32 	m_iHeight;				//��Ƶ�߶�	
	td_s32	m_iWidth;				//��Ƶ���
}TVdecPara;


typedef struct
{
	td_s32 	m_iVdecChan;													//����ͨ����		
	
	TVdecPara  m_TVdecPara;				
	
	td_s32 	m_iIsUse;														//�Ƿ�ռ��
	
	td_s32 	m_iStat;															//�Ƿ񴴽�
	
	td_s32 	m_iVsize;															//��Ƶ��С
	
	td_s32 (* Reset)(void * _pThis);											//��ѯ״̬

	td_s32 (* QueryStat)(void * _pThis);											//��ѯ״̬
	
	td_s32 (*SendStream)(void * _pThis,td_u8 *_cFrameBuf,td_s32 _iFlen, td_u32 _uiPts, td_s32 _iBlockFlag);	//������
	
}TVdecChannel; 



typedef struct
{
	td_s32 	m_iAdecChan;		// ����ͨ��
	
	td_s32	m_iType;			// ��������	
	
	td_s32	m_iIsUse;			// �Ƿ���ʹ��
	
	td_s32	m_iStat;			// �Ƿ��Ѿ�����
	
	td_s32 (*SendStream)(void * _pThis,td_u8 *_cFrameBuf,td_s32 _iFlen,td_s32 _iBlockFlag);	//������
	
	td_s32 (*ClearChnBuf)(void * _pThis);	//�������

}TAdecChannel; 


td_s32 tvdec_Init(td_s32 _iNum, int _iMaxDecAbilty);

td_s32 tadec_Init(td_s32 _iNum);

//_iType=0 commonvdec ; _iType=1 vcavdec
TVdecChannel * media_CreateVdecChannel(TVdecPara *_pTVdecPara, td_s32 _iType, td_s32 _s32LogChn);

//td_s32 media_DestroyVdecChannel(TVdecChannel *_pTVdec);

td_s32 media_FreeVdecChannel(TVdecChannel *_pTVdec,  td_s32 _s32LogChn);

TAdecChannel * media_CreateAdecChannel(td_s32 _iType);

td_s32 media_FreeAdecChannel(TAdecChannel *_pTAdec);

td_s32 media_ClearAdecChannel(TAdecChannel *_pTAdec);


td_s32 libdec_GetDebug(char *_cString,int _iLen);

td_s32 media_SetDecMaxSize(td_s32 _iMaxDecSize);

td_s32 media_FreeAllNoUseVdecChannel(void);

td_s32 media_ClearAdecChannel(TAdecChannel *_pTAdec);

#endif


#ifndef _RING_BUF_H_
#define _RING_BUF_H_

#include "public_def.h"

typedef struct
{
	void *m_ptSelftData;	//Ӧ�ò�����
} TRingBuf;

enum
{
	RINGBUF_WRITE_BLOCK = 0,	//�ռ䲻��ʱд����
	RINGBUF_WRITE_COVER = 1,	//�ռ䲻��ʱд����
};

// ����һ������buf
TRingBuf *ringbuf_Create(td_s32 _iBufSize, int _iType);

// ����һ������buf
void *ringbuf_Destroy(TRingBuf *_ptBuf);

// ����buf���ִ�ɶ�����
td_s32 ringbuf_DataSize(TRingBuf *_ptBuf);

// ����buf�ֿ�д����
td_s32 ringbuf_Capacity(TRingBuf *_ptBuf);

// д���ݵ�����buf
td_s32 ringbuf_Write(td_s32 _iSize, const void *_ptSrc, TRingBuf *_ptBuf);

// �ӻ���buf��ȡ����
td_s32 ringbuf_Read(td_s32 _iSize, void *_ptDst, TRingBuf *_ptBuf);

td_s32 ringbuf_Clear(TRingBuf *_ptBuf);

// zty 20120220
//���ƻ���buf����,��ɾ��
td_s32 ringbuf_Copy(td_s32 _iSize, void *_ptDst, TRingBuf *_ptBuf);

//ɾ������buf����
td_s32 ringbuf_Remove(td_s32 _iSize, TRingBuf *_ptBuf);
// zty add end

//��ȡring buf�е���ʼ���ݵ�ַ - dlq added at 20120919
td_u8 *ringbuf_GetData(TRingBuf *_ptBuf);
#endif


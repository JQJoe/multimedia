#ifndef _ALARMER_H_
#define _ALARMER_H_

// ���������ඨ��
#include "public_def.h"
#include "vca_head.h"
#include "libstorage.h"
#define  NSGTEST  //add by nsg0926
typedef enum
{
	ALARMER_ATTR_EN		= 0x0000, //ʹ�ܣ�����Ϊ����, 0��ʹ��,1ʹ��
	ALARMER_ATTR_PORT_MOD 	= 0x0001, //�˿ڱ�����ģʽ, ����Ϊ����,  0 : ��·, 1��·
} ALARMER_ATTR_ID;

typedef enum
{
	ALARMER_PORT 	= 0x0100,	//�˿ڱ���
	ALARMER_MD	= 0x0200,	//�ƶ����
	ALARMER_VL		= 0x0300,	//��Ƶ��ʧ
    ALARMER_OD		= 0x0A00,	//��Ƶ�ڵ�����  20130305 SUN Wei add for video cover

	//add by caizhaoxu for vca 20120321
	ALARMER_TRIPWIRE   = 0x0400,    //���߱���     
	ALARMER_PERIMETER  = 0x0500,    // �ܽ籨��
	ALARMER_FACE       = 0x0600,    // �������
	ALARMER_DIAGNOSE   = 0x0700,    //��Ƶ���
	ALARMER_OSCER      = 0x0800,    //��Ʒ����
    ALARMER_AL         = 0x0900,    //��Ƶ��ʧ

	//shihc add 20130225 
	ALARMER_CAP         = 0x1000,    //���ܸ���
	ALARMER_CPC         = 0x2000,    //����ͳ��
	ALARMER_CDD         = 0x3000,    //��Ⱥ�ۼ�
	ALARMER_SVD         = 0x4000,    //��Ⱥ�ۼ�
} ALARMER_TYPE;

typedef struct _TAlarmer	//������ͨ�ö���
{
	td_s32 m_iType;		//����������
	
	td_s32 (*GetStat)(struct _TAlarmer *_ptThis);		//״̬���
	td_s32 (*SetAttr)(td_s32 _iId, void *_pValue, struct _TAlarmer *_ptThis); //��������
} TAlarmer;


typedef struct _TAlarmOutPort // ��������˿�ͨ�ö���
{
	td_s32 m_iType;
	td_s32 (*GetStat)(struct _TAlarmOutPort *_ptThis); //��ȡ״̬
	td_s32 (*SetStat)(td_s32 _iStat, struct _TAlarmOutPort *_ptThis); //����״̬
} TAlarmOutPort;
#endif


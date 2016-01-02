#ifndef _FONTBUF_H_
#define _FONTBUF_H_
#include "libfont.h"
#include "public_def.h"
#include "hi_comm_video.h"

//½���� add   

/*	ʸ���ֿ⻺�����,ֻ���ͨ��ʱ��
	��Ҫ������ַ�����:A-Z a-z 0~9  /  .  - :

	0-9    	32-41
	A-Z   	65-90
	a-z     97-122
*/
/*
	��Ƶ��Сת��Ϊ�����±�
	QIF     0
	CIF 	1	
	HD1 	2
	D1		3
	960H	4	
	720P	5
	1080I	6
	1080P	7
*/


#define MAX_VIDEO_SIZE_NUM 	8 //shihc mod 20121224 ����1080I��֧��
#define MAX_COLOR_NUM		16
#define MAX_CHAR_NUM		127


typedef struct 
{
	td_s32 			m_iVideoSize;	//��Ƶ��С	
	td_u32 		    m_uiColor;		//��ɫ
	td_char 		m_cChar;		//�ַ�
	int 			m_iWidth;
	int 			m_iBytes;
	TFontBmp 		m_FontBmp;
}str_FontBuf;

typedef struct
{
	int 			m_iVideoSize;
	unsigned int 	m_uiColor;
	BITMAP_S 		m_Bitmap;	
	int 			m_iInit;
}STR_TimeBmpBuf;

BITMAP_S* GetTimeBmpBuf(td_s32 _iVideoSizeIndex,td_s32 _s32Color);

td_void SetTimeBmpBuf(td_s32 _iVideoSizeIndex,td_s32 _s32Color,BITMAP_S* _TimeBmp,td_s32 _sBitMapSize);
/*
	���λͼ����ֱ�ӷ���m_Bitmap
	���������
		1�������ڴ棬����λͼ
		2����m_iInit��1
		3������λͼָ��
*/

td_s32 ClearTimeBmpBuf();
/*
	��һ�뿪ʼʱ��������λͼ������գ�ֻ�轫m_iInit��Ϊ0����
*/

TFontBmp *GetFontBitsFromBuf(td_s32 _iSizeIndex,td_char _cChar,td_u32 _s32Color,int *_iWidth,int *_iBytes);

/*
	����������Ѿ��и��ַ��ĵ�����Ϣ�����ص����ָ��
	���򷵻ؿ�
*/

td_void SetFontBitsFromBuf(td_s32 _iSizeIndex,char _cChar,td_u32 _s32Color,TFontBmp* _tFontBmp,td_s32 _iBitLen,int _iWidth,int _iBytes);

/*
	��������Ϣ�����ڻ�����	
*/
td_void initFontBuf();
/*
	��ʼ��FontBuf
*/

td_s32  initBmpBuf();


#endif


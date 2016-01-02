#ifndef _FB_H_
#define _FB_H_

#ifndef u8
#define u8 unsigned char
#endif

#ifndef u32
#define u32 unsigned int
#endif

#ifndef bool
#define bool	int
#endif

#ifndef true
#define true	1
#endif

#ifndef false
#define false 0
#endif

typedef  unsigned int TFbRgb;	//fb RGB  0xAARGB
typedef struct
{
	int m_iFlg;
	u32 m_u32Width;
	u32 m_u32Height;
} TFbScreenMsg;


#define FB_VIRTUAL_SCREEN_WIDTH  352
#define FB_VIRTUAL_SCREEN_HEIGHT 288


// FB��ʼ��,�ɹ�����true�����򷵻�false
bool FbInit(int _iVoDevCnt, int _iVoDevs[], char *_iFbDevs[], TFbScreenMsg _tMsg[]);

// FB����ʼ��
void FbUninit();

// ��FBͼ�㴴��һ������ͼ��
// xp, yp����ͼ������Ļ�ϵ���ʼ���ꣻ
// width, heightָ��ͼ���ʵ�ʳߴ�(ͼ������Ļ�ϵĴ�С)
// virwidth, virheightָ��ͼ��������С
// �ɹ�����ͼ����(>=0)����������ʧ��
int FbCreateOverlay(int _iVoDev, int _iXp, int _iYp, u32 _u32Width, u32 _u32Height, u32 _u32VirWidth, u32 _u32VirHeight);

// ע���Ѵ����ĵ���ͼ��,idΪͼ����
void FbDestroyOverlay(int _iVoDev, int _iId);

// �ڵ���ͼ�������
// idָ��ͼ����
// xp, ypָ����������
// colorָ�����ɫ
void FbOverlaySetPixel(int _iVoDev, int _iId, int _iXp, int _iYp, TFbRgb _tColor); 

// ���ָ��ͼ��
void FbOverlayClear(int _iVoDev, int _iId);

void FbUpdate(int _iVoDev);

void FbClear(int _iVoDev);

#endif


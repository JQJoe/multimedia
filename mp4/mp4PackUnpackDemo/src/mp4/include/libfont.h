#ifndef __FONT__H_
#define __FONT__H_

#define DVR_GUI_LAN_PATH "./lang"      //UI ���е����԰�����·��
#define CUR_GUI_LAN_PATH "./gui_config/curlang"  //��ǰ��������·��
#define CUR_GUI_LAN_DIR  "./lang/%s"   //��ǰ���԰��ļ�����Ŀ¼

#define FONTLIB_FILE	   		"./gui_config/fontinfo.txt"
#define DEFAULT_FONT_FILE	 "./gui_config/arial.ttf"

//#define ft_render_mode_normal  FT_RENDER_MODE_NORMAL
//#define ft_render_mode_mono    FT_RENDER_MODE_MONO


typedef struct
{
	int iLangNo;
	char cLangBuf[32];
}TGuiLangType; //�����ļ��Ľṹlang.txt

typedef struct
{
	int m_iWidth;
	int m_iHeight;
	int m_borderX;
	int m_bordery;
	void *m_usBmp;
} TFontBmp;   //�ַ�λͼ��Ϣ

int  GetFontName(char* _pcFontPath, char* _cFileName, int* _iFontSize); //��ȡ�ֿ�����
int IsFontFileExist(char* _cFileName);  //�ж��ֿ��ļ��Ƿ����
int SetFontSize(int _iFontSize[], int _iLen);	
int LoadFontResourse(const  char* _pcFontFile); //װ�س�ʼ���ֿ�
int LoadSupportLang(void);
int LoadSlaveFontResource();
int ReleaseFontResource();//�ͷ��ֿ���Դ

int GetFontBits(unsigned short _uCode, int _iIndex,  unsigned int _tFontColor, unsigned int _tBgColor, TFontBmp* _tFontBmp);

int GetUniCharWidth(unsigned short _usUni, int _iSizeIndex); //��ȡһ���ַ��Ŀ��
int GetUniStringWidth(const unsigned char *_strWords, int _iSizeIndex);// ��ȡһ���ַ����Ŀ��
int GetUniStringWidthEx(unsigned char *_strWords, int _iSizeIndex, int _iMaxWidth);

int GetUniCharBytes(const unsigned char *_strWords);//��ȡһ��unicode�����ַ�ռ�����ֽ�
int GetFontHeight(int _iSizeIndex);  //��ȡ����ĸ߶�
int GetIndexBySize(int _iSize);  //���������� �����ֺ�

const int GetCurGuiLangValue(); //��ȡ��ǰ���Ե�ֵ
const char *GetCurGuiLangDir(char *_cDir);//��ȡ��ǰ���Ե�Ŀ¼

int SetCurGuiLangValue(int _iValue); //���õ�ǰ����

int GetCurDevGuiLangList(TGuiLangType *_GuiLangType, int *_iLangCnt); //��ȡ��ǰ�����б���ֵΪ��ǰ֧�����Եĸ���

unsigned short Utf8toUnicode ( const unsigned char  *_pucUtf8, int *_iBytes);

int GB2312ToUTF8(const unsigned char *_Gb2312, unsigned char *_Utf8, int _iBufSize);//gb2312תutf8
int UTF8ToGB2312(const unsigned char *_Utf8, unsigned char *_Gb2312, int _iBufSize);//utf8תgb2312
unsigned short Gb2312ToUnicode(unsigned char *str);

//��ȡ�Զ������Ա�Ŷ�Ӧ�Ĺ��ʼ�д����
char* GetSimpleCodeByIndex(int _iIndx);

//��ȡ��д�����Ӧ���Զ�����
int GetLangIndexBySimepleCode(char* _pCode);

//�����ַ����Ľض�
int TruncationString(unsigned char* _strText, int _iStrSize);

#endif

//*********************************
// ͨ�ú�����
// dxl 20110314 create
//*********************************

#ifndef _LIB_OTHER_H_
#define _LIB_OTHER_H_

#include "td_types.h"
#include "td_errno.h"

// ��ȡ�ļ��б�
int file_filter(int (*judge)(char* file_name), char* path, char file_list[][256], int* file_num);

// �޸��ļ���չ��
int chext(char* file_name, const char* new_ext);

int prime_list(int* list, int max);

// �ַ����Ƚ�
int strcmpx(char* first, char* second);

// ��ɫ��ʽת��
td_s32 BGR2RGB(td_u32 _uiColor);
td_u32 RGB2BGR(td_s32 _uiColor);

// ����ַ���_pcSourceString���Ƿ����ָ�����ַ���_pcCharacterSet����
td_s32 if_has_bad_character(td_u8* _pcSourceString, td_u8* _pcCharacterSet);


// ���������ַ��������ݽṹ��ת��
int ComString2Struct(const td_u8* _pcString, TCom* _pstStruct);


/*
 * �������ƣ�VideoSize2WidthHeight
 * ��Ҫ������������Ƶ��С�������Ƶ�Ŀ�͸�
 * ��	  �룺
 * 			_iNorm, ��ʽ��PAL/NTSC
 *			_iSize,��С��FD1/HD1/FCIF/HCIF/QCIF
 *			_iVideoWidth,������Ƶ���ǿ�
 * 			_iVideoHeight,������Ƶ�ߡ��ǿ�
 * ��	 ����
 * 			TD_SUCCESS,�ɹ�
 *			TD_FAILURE,ʧ��
 * �޸���־��
 * 			2009-10-29,������,����
 */
int VideoSize2WidthHeight(int _iNorm,int _iSize,int* _iVideoWidth,int* _iVideoHeight);


/*
 * ������WidthHeight2VideoSize
 * ���ܣ����ݿ�߻������Ƶ��С,���������������(��sdi)
 * ��	  �룺
 * 			_iNorm, ��ʽ
 *			_iSize,��С��FD1/HD1/FCIF/HCIF/QCIF
 *			_iVideoWidth,������Ƶ���ǿ�
 * 			_iVideoHeight,������Ƶ�ߡ��ǿ�
 * ��	 ����
 * 			��С��HD1/F1080P/F720P��
 * �޸���־��20121009 hq create
 */
int WidthHeight2VideoSize(int _iNorm, int _iVideoWidth, int _iVideoHeight);
int Play_WithHeightToVideoSize(int _iWith, int _iHeight);
/*
shihc add 20120311
Ϊʸ���������ӣ��ַ��ֱ��ʻ������ʹ�С��
_iPx:ͨ���ֱ��ʵ�x��Ŵ�ϵ�������cif; _iPyͬ��
*/
td_s32 osd_CountSizeIndex(td_s32 _iPx , td_s32 _iPy);

//��QCIFΪ��׼�����㲻ͬ�ֱ����£��ַ����ӵ�����ռ�õĿ�ߵı���
td_void osd_GetZoomTime(td_s32 _s32VideoSize, td_s32 *_ps32Px,td_s32 *_ps32Py, td_s32 _s32Type);

/*
ʵ�ֽ�CIF�ĳߴ�����2����Ӧ��hd1,1080I�ֱ��ʡ�
shihc add 20120324:HD1��ʵ��ԭ���ǽ�CIF���ַ���������2��
shihc add 20120607:����1080I �ַ���������2����1080P
*/
td_s32 CIFx2(td_s32 _iNum, td_s32 _iSizeIndex);


// ����pos����osdʵ������
// width, height:��Ƶ�ߴ�
// pos:λ��0-15
// len:ods�ַ�����
// x, y : ����ֵ���
// dlx 20110331
void OsdPosToXY(int _iWidth, int _iHeight, int _iPos, int _iLen, int *_iX, int *_iY,int _iNorm);

 

/** Places base 64 encoded input buffer into output buffer.
*/
int base64_encode(unsigned char* outputBuf, unsigned int* outputLen,
                          unsigned char* inputBuf, unsigned int inputLen);


/** Places base 64 decoded input buffer into output buffer.
*/
int base64_decode(unsigned char* outputBuf, unsigned int* outputLen,
                          unsigned char* inputBuf, unsigned int inputLen);

/*
    _pcVData    ���������ݻ���
    _iDataLen   ���������ݳ���
    _iCTRKey    Ψһ��ʶ
    _pucAESKey  ��Կ������չ��16λ

    �����㷨��飺Ψһ��ʶ����Ƶ֡��֡�ţ�ʹ��AES�㷨��֡�Ž��м��ܣ�
                  �����ܺ�Ľ����ԭʼ��Ƶ���ݽ�����������ʵ�ֶ���Ƶ���ݵļ��ܡ�
                  �ͻ���ʹ����ͬ���㷨���ɻ�ý��ܺ����Ƶ����
*/	 
int aes_crypt(unsigned char* _pcVData,int _iDataLen,unsigned int _iCTRKey,
	unsigned char* _pucAESKey,int _iAESKeyLen);


// ���ip��ַ�����������Ƿ�Ϸ�
// ����ֵ: 0�Ϸ�, -1�Ƿ�
int Valid_IPMask(int _IP, int _SubMask);

// ���ip��ַ���Ƿ�Ϸ�
// ����ֵ: 0�Ϸ�������ֵ�Ƿ�
int Valid_IP(const char *  _IPAddress);

// ǧ�ֱ�ת��
#define permillage_rate(_iValue, _iMaxValue)	((_iMaxValue) ? (_iValue) * 1000 / (_iMaxValue) : 0)   
#define permillage_value(_iRate,  _iMaxValue)	((_iRate) * (_iMaxValue) / 1000) 
void permillage_shitf(int _iType, int _iWidth, int _iHeight, int *_piXp, int *_piYp);

// ����ַ����Ƿ񳬳�����
// ����:
// _psSrc : �ַ���
// _pcSplit : �ָ���
// _iMaxLineLen : ÿ����󳤶�
// _iFieldNum : �������
// ����ֵ: 0�Ϸ���-1���
int IsStringTooLong(td_u8* _pcSrc, td_u8* _pcSplit, td_s32  _iMaxLineLen, td_s32 _iFieldNum);

// ������Ƶ�ߴ��ص�������
void countMaskRect(int _iVideoSize, Rect_t *_pRect);

char *strncopy(char *_strDst, const char *_strSrc, int n);

// �¾ɽṹת��
// type : 0 : �Ͻṹ->�½ṹ, 1 : �½ṹ->�Ͻṹ
// width, height ��ǰ��Ƶ���
// old : �Ͻṹ(ǧ�ֱ�)
// new : �½ṹ(ʵ��ֵ)

//typeֵ����
#define NEW_TO_OLD   1
#define OLD_TO_NEW   0
void ChnNameOsdShift(int _iType, int _iWidth, int _iHeight, OSD_CHANNAME_T *_ptOld, TChnNameOsdCnf *_ptNew);
void ChnTimeOsdShift(int _iType, int _iWidth, int _iHeight, OSD_CHANNAME_T *_ptOld, TChnTimeOsdCnf *_ptNew);
void ChnTextOsdShift(int _iType, int _iWidth, int _iHeight, STR_WordOverlay *_ptOld, TChnTextOsdCnf *_ptNew);
void ChnVideoCoverAreaShift(int _iType, int _iWidth, int _iHeight, Rect_t *_ptOld, TChnArea *_ptNew);
void ChnMdAreaShift(int _iType, td_u32 *_puiOld, TChnMdAreaCnf *_ptNew);
void ChnLogoOsdShift(int _iType, int _iWidth, int _iHeight, OSD_CHANNAME_T *_ptOld, TChnLogOsdCnf *_ptNew);


int StrToTime(const char* _strTime);

void GuiChannels2DvrChannels(const td_s32* _piGuiCh, td_s32* _piChannelNum, td_s32* _piDvrCh);
void DvrChannels2GuiChannels(td_s32 _iChannelNum, const td_s32* _piDvrCh, td_s32* _piGuiCh);


int AudioFramLenToAoPoiNum(int _iType,int _iFramLen);

//������Ƶ�ߴ����λ��(�ߴ�Խ��λ��ԽС)
int VideoSizeIndex(int _iSize);
//�Ƚ�������С��_size1 > _isze2, Ϊ��
int CmpVideoSize(int _iSize1, int _iSize2);
//���������Ƶ�ֱ��ʣ������б�
int GetVideoList(int _iMinSize, int _iMaxSize, int *_ptpVideoList, int _iMaxCnt);
/*
*��ȡrtcʱ������
*������־:20121129�����ɴ���
*/
int GetRtcTimeSeconds(time_t *_pTime);

//���ڼ����ַ����ӵľ�������
td_s32 channel_ComputeCifPos(int _iVideoSize, int _iPosFrom[2], int _iPosTo[2]);
//���ڽ��ṹ�б����������껻��ɾ�������
td_s32 channel_ComputeSetPos(int _iVideoSize, int _iPosFrom[2], int _iPosTo[2]);

int MD5File (char *filename,char *_cOutputBuf);
int MD5BigFile (char *filename);
int MD5_Encrypt(char *_cOutputBuf, int _iOutputLen, const char *_cInputbuf, int _iInputLen);
int DES_Decrypt(char *_cOutputBuf, int _iOutputLen, char _cKey[8], const char *_cInputbuf, int _iInputLen);
int DES_Encrypt(char *_cOutputBuf, int _iOutputLen, char _cKey[8], const char *_cInputbuf, int _iInputLen);
int EncryptSrcToDesToBase64(char *_cOutputBuf, int _iOutputLen, char _cKey[8], const char *_cInputbuf, int _iInputLen);
int DecodeBase64toDesToSrc(char *_cOutputBuf, int _iOutputLen, char _cKey[8], const char *_cInputbuf, int _iInputLen);
int EncryptStrToMd5ToBase64(const char* _cSrcStr1, int _iStrLen1, const char * _cSrcStr2, int _iStrLen2, OUT char *_cOutBuf, int _iOutLen);
#endif


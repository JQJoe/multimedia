#ifndef Md5H
#define Md5H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//#include <memory.h>
#include <string.h>
//---------------------------------------------------------------------------
/* typedef a 32 bit type */ 
typedef unsigned long int UINT4;

/* Data structure for MD5 (Message Digest) computation */ 
typedef struct { 
UINT4 i[2]; /* number of _bits_ handled mod 2^64 */ 
UINT4 buf[4]; /* scratch buffer */ 
unsigned char in[64]; /* input buffer */ 
unsigned char digest[16]; /* actual digest after MD5Final call */ 
} MD5_CTX; 




void MD5Init (MD5_CTX *mdContext); 
void MD5Update (MD5_CTX *mdContext,unsigned char *inBuf,unsigned int inLen); 
void MD5Final (unsigned char *digest,MD5_CTX *mdContext); 
void Transform (UINT4 *buf,UINT4 *in); 
void hmac_md5 (unsigned char *text,int text_len,unsigned char * key,int key_len,unsigned char * digest); 

char* DecodeBase64(char* Source); 
//char* EncodeBase64(char* Source); 
int EncodeBase64(char* Result,char* Source);
unsigned char FindInTable(unsigned char);

int MD5File (char *filename,char *_cOutputBuf);
int MD5BigFile (char *filename);
int Md5BigFileInit(int _iCdNo);
/*
������ 	:	td_s32 Md5BigFileInit(int _iCdNo)
����	:	��¼���ļ�ʱ,hash��ʼ��
�������	:	_iCdNo: ������
����ֵ	: 	>=0 �ɹ�   -1 ʧ��
*/
int Md5BigFileFinal(int _iCdNo,char *_pcMd5Buffer);
/*
������ 	:	Md5BigFileFinal
����	:	����md5ֵ
�������	:	_iCdNo :������ _cOutputBuf: md5ֵ

����ֵ	: 	>=0 �ɹ�   -1 ʧ��
*/
int Md5BigFileUpdate(int _iCdNo,unsigned char * _pcBuffer,unsigned int iBufferLen);
/*
������ 	:	td_s32 Md5BigFileUpdate(int _iCdNo,unsigned char *_pcBuffer,unsigned int iBufferLen)
����	:	�����ͽ�ȥȻ�����md5
�������	:	_iCdNo :������ _pcBuffer: ��Ƶ��  iBufferLen:��Ƶ������

����ֵ	: 	>=0 �ɹ�   -1 ʧ��
*/
int Md5_GetInfo(int _iCdNo,char *_pstMd5Info);
int Md5_SetInfo(int _iCdNo,char *_pstMd5Info);
#endif
 

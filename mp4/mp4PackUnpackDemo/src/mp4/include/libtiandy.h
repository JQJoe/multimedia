#ifndef _LIBTIANDY_
#define _LIBTIANDY_

#include <pthread.h>

/******************************net********************************************/
unsigned short int GetRandomPort(unsigned short int miniseed);
/*
 * ��������:GetRandomPort
 * ��Ҫ����:��ȡһ������˿�
 * ��	 ��:
 *			miniseed��ָ���˿ںŵ����ޣ�����ȡ���Ķ˿ڱ��������������
 * ��	 ��:
 *			��ȡ��������˿�
 * �޸���־:
 *			2009-10-26,������������
 */
 
int GetIPbyDNS(char* _domainName, char *_cIP);
/*
 * ��������:GetIPbyDNS
 * ��Ҫ����: ��һ������ͨ��DNSת��ΪIP��ַ
 * ��	 ��:
 *			_domainName����ת��������
 *			_cIP����ַ���ʾ��Ŀ��IP��ַ
 * ��	 ��:
 *			0���ɹ�
 *			-1��ʧ��
 * �޸���־:
 *			2009-10-26,������������
 */
int get_local_address(char* szIPAddr,char* szNetMask, char * _cDevName);

int IPAddressU32ToChar(unsigned int _u32IPAddress,char* cIpAddress);
/*
 * ��������:IPAddressU32ToChar
 * ��Ҫ����:��һ�����ͱ�ʾ��IP��ַת��Ϊ��ַ���ʾ��IP
 * ��	 ��:
 *			_u32IPAddress����ת��������IP
 *			cIpAddress��ת����ĵ�ַ�IP
 * ��	 ��:
 *			0���ɹ�
 *			-1��ʧ��
 * �޸���־:
 *			2009-10-26,������������
 */

unsigned int ipstring2u32(char* _ip);
/*
 * ��������:ipstring2u32
 * ��Ҫ����:��һ����ַ���ʾ��IP��ַת��Ϊ32λ�޷�������
 * ��	 ��:
 *			_ip���ǿգ���ת��IP
 * ��	 ��:
 *			ת������޷�������
 * �޸���־:
 *			2009-10-26,������������
 */
void ReverseMAC(char *_cMac);

int IsValidIP(const char* _cIP);
/*
 * ��������:IsValidIP
 * ��Ҫ����:�ж�һ���ַ����Ƿ�Ϊ�Ϸ�IP��ַ
 * ��	 ��:
 *			_cIP���ǿգ����ж�IP
 * ��	 ��:
 *			-1,�Ƿ�IP��ַ
 *			1����׼IP��ַ
 *			2���㲥IP��ַ
 *			3����IP��ַ(ȫ0)
 * �޸���־:
 *			2009-10-26,������������
 */

//zhangweiwei 0412
//int CheckIp(int _iEth, char *_strIp, int _iTimeOut);
int CheckIp(int _iEth, char *_strIp, char *_mac, int _iTimeOut, int _iReciveCnt);
/*
 * ��������:CheckIp
 * ��Ҫ����:���IP��ַ��ͻ
 * ��	 ��:
 			_iEth    device
 *			_strIp���ǿգ�ip��ַ����10.10.10.61
 *			_iTimeOut����ʱʱ�䣬�룬>= 1
 * ��	 ��:
 *			-1����������
 *			0��IP��ַδ��ռ��
 *			1��IP��ַ��ռ��
 * �޸���־:
 *			2009-10-26,������������
 */
int CheckMac(char *_cstrIp,char *_cInterfaceName,char *_cdstIp, int _iTimeOut);
	/*
	 * ��������:CheckMac
	 * ��Ҫ����:���MAC��ַ��ͻ
	 * ��	 ��:
				_cstrIp	 �豸ip��ַ
	 *			_cInterfaceName����������
				 _cdstIp         MAC ��ͻ��Ӧ��ip��ַ
	 *			_iTimeOut����ʱʱ�䣬�룬>= 1
	 * ��	 ��:
	 *			-1����������
	 *			0�� MAC ��ַδ��ռ��
	 *			1�� MAC ��ַ��ռ��
	 * �޸���־:
	 *			2013-10-26,zhb���޸ġ�
	 */

int CheckNetDelay(int _iEth,char *_cIp,int *_pidelay,int *_piLostrate,int  _icount, int _itimeout);

int DetectEth0(int _iEth);
/*
 * ��������:DetectEth0
 * ��Ҫ����:����������������Ƿ��ж�
 * ��	 ��:
 *			0: eth0
                   1: eth1
 * ��	 ��:
 *			1�������ж�
 *			0����������
 *			������״̬δ֪
 * �޸���־:
 *			2009-10-26,������������
 *			2010-02-03,����������Hi3520�л�ʱ�����µķ���ʵ��
 */

int DetectEth0Ex(void);
/*
 * ��������:DetectEth0Ex
 * ��Ҫ����:����������������Ƿ��ж�,��Hi3520�л�ʱ�����µķ���ʵ��
 * ��	 ��:
 *			��
 * ��	 ��:
 *			1����������
 *			0�������ж�
 *			������״̬δ֪
 * �޸���־:
 *			2010-02-03,������������
 */

int get_gateway(char *gateway,char* dev);
/*
 * ��������:get_gateway
 * ��Ҫ����:��ȡ����
 * ��	 ��:
 *			gateway���ǿգ�������ȡ��������
 *			dev���豸���ƣ�����������Ϊ"eth0"
 * ��	 ��:
 *			-1��ʧ��
 *			0���ɹ�
 * �޸���־:
 *			2009-10-26,������������
 */
 
/******************************string*****************************************/
/*----------------------------------------------------------------------------*/
typedef struct 
{
    int      m_iStringCount;
    char**   m_cStrings;

    int (*Add)(void* _strThis,char* _cBuf);
    int (*Clear)(void* _strThis);
    int (*Insert)(void* _strThis,char* _cBuf,int _iIndex);
    int (*Delete)(void* _strThis,int _iIndex);
    int (*Init)(void* _strThis);
    int (*Destroy)(void* _strThis);
    int (*IndexOf)(void* _strThis,char* _cBuf);
}StringList;

/*----------------------------------------------------------------------------*/
int sList_Add(void* _strThis,char* _cBuf);
int sList_Clear(void* _strThis);
int sList_Insert(void* _strThis,char* _cBuf,int _iIndex);
int sList_Delete(void* _strThis,int _iIndex);
int sList_Init(void* _strThis);
int sList_IndexOf(void* _strThis,char* _cBuf);
int sList_Destroy(void* _strThis);

void itoa(unsigned int value, char *string, int radix);
/*
 * ��������:itoa
 * ��Ҫ����:��һ��������ת��Ϊ�ַ�������456->"456"
 * ��	 ��:
 *			value��Դ������
 *			string���ǿգ�Ŀ���ַ���
 *			radix�����ƣ�Ŀǰֻ֧��ʮ����
 * ��	 ��:
 *			��
 * �޸���־:
 *			2009-10-26,������������
 */
 
int OnCharLeft(const char* c1,const char* c2,char* c3);
/*
 * ��������:OnCharLeft
 * ��Ҫ����:��ȡԴ�ַ���c1�зָ��ַ���c2��ߵĲ��֣���������Ŀ���ַ���c3
 * ��	 ��:
 *			c1���ǿգ�Դ�ַ���
 *			c2���ǿգ��ָ��ַ���
 *			c3���ǿգ�Ŀ���ַ���
 * ��	 ��:
 *			0���ɹ�
 *			-1��ʧ��
 * �޸���־:
 *			2009-10-26,������������
 */
 
int OnCharRight(const char* c1,const char* c2,char* c3);
/*
 * ��������:OnCharRight
 * ��Ҫ����:��ȡԴ�ַ���c1�зָ��ַ���c2�ұߵĲ��֣���������Ŀ���ַ���c3
 * ��	 ��:
 *			c1���ǿգ�Դ�ַ���
 *			c2���ǿգ��ָ��ַ���
 *			c3���ǿգ�Ŀ���ַ���
 * ��	 ��:
 *			0���ɹ�
 *			-1��ʧ��
 * �޸���־:
 *			2009-10-26,������������
 */
 
int SplitStringToArrayEx(char* cSource,char* cSplitChar,char** cDest, int len);
int SplitStringToArray(char* cSource,char* cSplitChar,char** cDest);
/*
 * ��������:SplitStringToArray
 * ��Ҫ����:��һ���ַ�������һ���ķָ����ָ�Ϊ�ַ������飬��һ�����գ����Ƽ�ʹ��
 * ��	 ��:
 *			cSource��Դ�ַ���
 *			cSplitChar���ָ���
 *			cDest��Ŀ���ַ�������
 * ��	 ��:
 *			Ŀ���ַ�������
 * �޸���־:
 *			2009-10-26,������������
 */
 
int SplitString(unsigned char* _pcSrc, unsigned char* _pcSplit, unsigned char** _ppcDst, int _iFieldLen, int _iFieldNum);
/*
 * ��������:SplitString
 * ��Ҫ����:����ͬ��һ������:��һ���ַ�������һ���ķָ����ָ�Ϊ�ַ������飬������һ��������ȫ
 * ��	 ��:
 *			_pcSrc��Դ�ַ���
 *			_pcSplit���ָ���
 *			_ppcDst��Ŀ���ַ�������
 *			_iFieldLen��Ŀ���ַ����ĳ�������
 *			_iFieldNum��Ŀ���ַ���������ַ���������
 * ��	 ��:
 *			-1��ָ������ǿ�
 *			-2���ַ������ȳ�������
 *			-3���ַ���������������
 *			������Ŀ���ַ�������
 * �޸���־:
 *			2009-10-26,������������
 */
 #if 0
int decimal2binary(int decimal, int* binary);
 #else
int decimal2binary(unsigned long long decimal, int* binary);
#endif
/*
 * ��������:decimal2binary
 * ��Ҫ����:��һ��������ת��Ϊ���������飬��12->1100
 * ��	 ��:
 *			decimal����ת����������
 *			binary������ת����Ķ���������
 * ��	 ��:
 *			-1����ת��������С��0
 *			-2�����ڴ����Ķ���������Ϊ��
 *			������ת�������������ĳ�Ա����
 * �޸���־:
 *			2009-10-26,������������
 */
#if 0
int binary2decimal(int nbits, int* binary);
#else
unsigned long long binary2decimal(int nbits, int* binary);
#endif
/*
 * ��������:binary2decimal
 * ��Ҫ����:��һ������������ת��Ϊһ��ʮ����������1100->12
 * ��	 ��:
 *          nbits������������ĳ�Ա����
 *			binary���ǿգ���ת���Ķ���������
 * ��	 ��:
 *			-1��ת��ʧ��
 *			������ת�����ʮ������
 * �޸���־:
 *			2009-10-26,������������
 */
int binary2decimalEx(int nbits, int* binary, unsigned int decimal[]);//wangsong16D1
int Netbinary2decimalEx(int nbits, int* binary, unsigned int decimal[]);
int decimal2binaryEx(unsigned int decimal[], int* binary, int nbits);//wangsong16D1

int check_string(char* _string);
/*
 * ��������:check_string
 * ��Ҫ����:���һ���ַ����Ƿ�Ϊ�Ϸ����ַ���(ֻ������ĸ�����֣���Admin123)
 * ��	 ��:
 *          _string���ǿգ��������ַ���
 * ��	 ��:
 *			1����
 *			0������
 * �޸���־:
 *			2009-10-26,������������
 */
 
/******************************file*******************************************/
int remove_file(const char *path);
/*
 * ��������:remove_file
 * ��Ҫ����:ɾ��һ���ļ���Ŀ¼�����Եݹ�ɾ��
 * ��	 ��:
 *          path���ǿգ���ɾ�����ļ���Ŀ¼
 * ��	 ��:
 *			0���ɹ�
 *			-1��ʧ��
 * �޸���־:
 *			2009-10-26,������������
 */
 
int copy_file(const char* src,const char* des, int file_size);
/*
 * ��������:copy_file
 * ��Ҫ����:�����ļ���ֻ�ܿ��������ļ������ܵݹ鿽��
 * ��	 ��:
 *          src���ǿգ�Դ�ļ�
 *			des���ǿգ�Ŀ���ļ�
 *			file_size����Ҫ�������ֽ��������С��0����ʾ���������ļ�
 * ��	 ��:
 *			0�������ɹ�
 *			-1����Դ�ļ�ʧ��
 *			-2����Ŀ���ļ�ʧ��
 *			-3��д�ļ�ʧ��
 *			-4�����ļ�ʧ��
 *			-5�������ڴ�ʧ��
 *			-6���޸�Դ�ļ�Ϊ����ģʽʧ��
 *			-7���޸�Ŀ���ļ�Ϊ����ģʽʧ��
 *			-8����ȡԴ�ļ���Ϣʧ��
 * �޸���־:
 *			2009-10-26,������������
 */

int is_dir(const unsigned char* _pucPath);
/*
 * ��������:is_dir
 * ��Ҫ����:�ж�һ���ַ����Ƿ�һ���Ϸ���Ŀ¼
 * ��	 ��:
 *          _pucPath���ǿգ����жϵ��ַ���
 * ��	 ��:
 *			1����
 *			0������
 * �޸���־:
 *			2009-10-26,������������
 */

int is_empty_dir(const signed char* _cst_pcPath);
/*
 * ��������:is_empty_dir
 * ��Ҫ����:�ж�һ��Ŀ¼�Ƿ�Ϊ�գ������Ŀ¼����������Ŀ¼��Ϊ������Ϊ���ǿ�Ŀ¼
 * ��	 ��:
 *          _cst_pcPath���ǿգ����жϵ�Ŀ¼
 * ��	 ��:
 *			1����
 *			0���ǿ�
 * �޸���־:
 *			2009-10-26,������������
 */

int extract_file_name(unsigned char* _pucFullPath);
/*
 * ��������:extract_file_name
 * ��Ҫ����:��ȫ·������ȡ�ļ���
 * ��	 ��:
 *          _pucFullPath���ǿգ�ȫ·������ȡ�ļ����Ľ���ԴӸò�������
 * ��	 ��:
 *			0���ɹ�
 *			-1��ʧ��
 * �޸���־:
 *			2009-10-26,������������
 */

int extract_file_path(unsigned char* _pucFilePath);
/*
 * ��������:extract_file_path
 * ��Ҫ����:��ȫ·������ȡ�ļ�����Ŀ¼
 * ��	 ��:
 *          _pucFilePath���ǿգ�ȫ·������ȡ·���Ľ���ԴӸò�������
 * ��	 ��:
 *			0���ɹ�
 *			-1��ʧ��
 * �޸���־:
 *			2009-10-26,������������
 */
 
int make_dir(unsigned char* _pcDirName);
/*
 * ��������:make_dir
 * ��Ҫ����:����Ŀ¼
 * ��	 ��:
 *          _pcDirName���ǿգ�������Ŀ¼��ȫ·��
 * ��	 ��:
 *			0���ɹ�
 *			-1��ʧ��
 * �޸���־:
 *			2009-10-26,������������
 */


enum
{
	DU_FLAG_FOLLOW_LINK = (1 << 0),	//���������ӣ�������������ָ���ļ��Ĵ�С
	DU_FLAG_B_BYTES = (1 << 8),	//����ֵ���ֽ�Ϊ��λ
	DU_FLAG_K_BYTES = (1 << 9),	//����ֵ��KBΪ��λ
	DU_FLAG_M_BYTES = (1 << 10),	//����ֵ��MBΪ��λ
	DU_FLAG_G_BYTES = (1 << 11),	//����ֵ��GBΪ��λ
};
unsigned long long du(const char *_pcFileName, int _iFlag);
/*
 * ��������:du
 * ��Ҫ����:ͳ��һ��Ŀ¼/�ļ����ܴ�С
 * ��	 ��:
 *          _pcFileName���ǿգ��ļ���Ŀ¼
 *		_iFlag������������ö�ٵ���ϣ���DU_FLAG_FOLLOW_LINK | DU_FLAG_M_BYTES
 * ��	 ��:
 *			�ļ�/Ŀ¼���ܴ�С
 * �޸���־:
 *			2014-07-24,��������ʵ�֡�
 */


/******************************math*******************************************/
void to_base64 (unsigned char *out, const unsigned char *in, int len);
/*
 * ��������:to_base64
 * ��Ҫ����:raw bytes to null-terminated base 64 string
 * ��	 ��:
 *          out��������
 *			in��Դ����
 *			len��Դ���ݳ���
 * ��	 ��:
 *			��
 * �޸���־:
 *			2009-10-26,������������
 */

int EncodeBase64(char* Result,char* Source);
/*
 * ��������:EncodeBase64
 * ��Ҫ����:Base64�����㷨
 * ��	 ��:
 *          Result���ǿգ�������
 *			Source���ǿգ�Դ����
 * ��	 ��:
 *			0���ɹ�
 *			-1,ʧ��
 * �޸���־:
 *			2009-10-26,������������
 */

typedef unsigned int Uint32;
#define SHA1HashSize 20

/*
 *  This structure will hold context information for the SHA-1
 *  hashing operation
 */
typedef struct SHA1Context
{
    Uint32 Intermediate_Hash[SHA1HashSize/4]; /* Message Digest  */

    Uint32 Length_Low;            /* Message length in bits      */
    Uint32 Length_High;           /* Message length in bits      */

                               /* Index into message block array   */
    Uint32 Message_Block_Index;
    unsigned char Message_Block[64];      /* 512-bit message blocks      */

    int Computed;               /* Is the digest computed?         */
    int Corrupted;             /* Is the message digest corrupted? */
} SHA1Context;

int SHA1Reset(  SHA1Context * p);
/*
 * ��������:SHA1Reset
 * ��Ҫ����:SHA-1�﷨�ṹ��λ
 * ��	 ��:
 *          p��SHA-1�㷨�﷨�ṹ
 * ��	 ��:
 *			0���ɹ�
 *			1������Ϊ��
 * �޸���־:
 *			2009-10-26,������������
 */
 
int SHA1Input(  SHA1Context * p, const unsigned char * data, unsigned int len);
/*
 * ��������:SHA1Input
 * ��Ҫ����:������ҪSHA-1���������
 * ��	 ��:
 *          p��SHA-1�㷨�﷨�ṹ
 *			data������������
 *			len���������ݳ���
 * ��	 ��:
 *			0���ɹ�
 *			1�������Ƿ�
 *			3����result֮�������input
 * �޸���־:
 *			2009-10-26,������������
 */
 
int SHA1Result( SHA1Context * p, const unsigned char Message_Digest[SHA1HashSize]);
/*
 * ��������:SHA1Result
 * ��Ҫ����:�����SHA-1����Ľ��
 * ��	 ��:
 *          p��SHA-1�㷨�﷨�ṹ
 *			Message_Digest��������
 * ��	 ��:
 *			0���ɹ�
 *			1������Ϊ��
 * �޸���־:
 *			2009-10-26,������������
 */

int pow1(int a, int _iMax);
/*
 * ��������:pow1
 * ��Ҫ����:�������n����
 * ��	 ��:
 *          a������
 *			_iMax������
 * ��	 ��:
 *			a��_iMax����
 * �޸���־:
 *			2009-10-26,������������
 */
 
/******************************system*****************************************/

void set_uptime(unsigned long _msec);
int get_uptime(int* _msec);
time_t getmytime(time_t *_T);
void setmytime(unsigned long _uLTm);
//#define time(n)	getmytime(n)

/*
 * ��������:get_uptime
 * ��Ҫ����:��ȡϵͳ������ľ���ʱ��
 * ��	 ��:
 *          _msec������Ϊ�գ������Ҫ��ȷ�����룬����ͨ���ò�������
 * ��	 ��:
 *			�����������������������ŵ�����
 * �޸���־:
 *			2009-10-26,������������
 */

void GetSystemInfo(double *_pdCPUuse, double *_pdMEMuse, double *_pdFlashUse);
/*
 * ��������:GetSystemInfo
 * ��Ҫ����:��ȡϵͳ��Ϣ
 * ��	 ��:
 *          _pdCPUuse���ǿգ����ڴ���CPUʹ����
 *			_pdMEMuse���ǿգ����ڴ����ڴ�ʹ����
 *			_pdFlashUse���ǿգ����ڴ���FLASHʹ����
 * ��	 ��:
 *			��
 * �޸���־:
 *			2009-10-26,������������
 */

/******************************timer******************************************/
struct timer_list{
	unsigned long expires;
	void (*fuc)(unsigned long);
	unsigned long data;
};

int init_timer(struct timer_list* timer);
/*
 * ��������:init_timer
 * ��Ҫ����:��ʼ����ʱ��
 * ��	 ��:
 *          timer���ǿգ��ڶ�ʱ����������ӵĵ�һ����ʱ��
 * ��	 ��:
 *			0���ɹ�
 *			-1�������Ƿ�
 *			-2�������Ѵ���
 *			-3�������߳�ʧ��
 * �޸���־:
 *			2009-10-26,������������
 */

int add_timer(struct timer_list* timer);
/*
 * ��������:add_timer
 * ��Ҫ����:���һ���µĶ�ʱ��
 * ��	 ��:
 *          timer���ǿգ�����ӵĶ�ʱ��
 * ��	 ��:
 *			0���ɹ�
 *			-1�������Ƿ�
 *			-2����������
 * �޸���־:
 *			2009-10-26,������������
 */

int	del_timer(struct timer_list* timer);
/*
 * ��������:del_timer
 * ��Ҫ����:ɾ��һ����ʱ��
 * ��	 ��:
 *          timer���ǿգ���ɾ���Ķ�ʱ��
 * ��	 ��:
 *			0���ɹ�
 *			-1�������Ƿ�
 *			-2����������
 * �޸���־:
 *			2009-10-26,������������
 */

struct timer_list* search_timer(struct timer_list* timer);
/*
 * ��������:search_timer
 * ��Ҫ����:�ڶ�ʱ�������в���һ���ض��Ķ�ʱ��
 * ��	 ��:
 *          timer���ǿգ������ҵĶ�ʱ��
 * ��	 ��:
 *			NULL������ʧ��
 *			�ǿգ����ҳɹ�
 * �޸���־:
 *			2009-10-26,������������
 */

/******************************thread*****************************************/
int CreateThreadInPool(pthread_t *_ptThr, void *(*_Task)(void *), void *_pArg);
/*
 * ��������:CreateThreadInPool
 * ��Ҫ����:���̳߳��д����߳�
 * ��	 ��:
 *          _ptThr���ǿգ����ڴ����̺߳�
 *			_Task���ǿգ��߳�����
 *			_pArg������Ϊ�գ��߳��������
 * ��	 ��:
 *			0���ɹ�
 *			<0��ʧ��
 * �޸���־:
 *			2009-10-26,������������
 */

int GetIPbyDNS_Ex(char * _domainName, char _cIP [ 16 ]);			//½���� 20110303 ����ģʽ��Ҫʹ�øú���
unsigned short cal_chksum(unsigned short *addr, int len);

long long get_uptime_ms (void);
/*
*��������:get_uptime_ms
*��Ҫ����:��ȡϵͳ����ʱ�䣬����Ϊ����
*���:����ϵͳ���������еĺ�������-1��ʾʧ��
*�޸���־:
*               2012-11-06�����ɴ�����    
*/
int SetDeletelFileSize(int _iS);//����ɾ���ļ���Ԫ��С
int myunlink(const char *_pcfilepath);//��װɾ������

int td_strnchr(char *_strSrc, int _iLen, char _c, char *_strDes[], int *_pistrLen, int _n);

int strtoken_r(char *str, char *delim, char ** array, int kwSect);
/*
 * ��������:strtoken_r
 * ��Ҫ����:���ַ������շָ������䵽�ַ�ָ������
 * ��	 ��:
 *			str����Ҫ��������Դ�ַ���
 *			delim���ָ���
 *			array, Ŀ��ָ������
 *			kwSect, ָ�������ά��
 * ��	 ��:
 *			��
 * �޸���־:
 *			2010-01-28,��ΰ������
 */
/******************************debug******************************************/
#ifdef TD_DEBUG
#define TD_RETURN(exp,ret,arg...)  \
	do{	\
		if (exp) {\
		td_printf(0XFF0000,"\nTD_RETURN{" #exp "}\r\n");\
		printf(" >Error   : 0x%08x\r\n", ret);\
		printf(" >File    : %s\r\n >In Func : %s\r\n >Line    : %d\r\n >ERR MSG : \r\n", __FILE__, __FUNCTION__, __LINE__);\
		}\
        }while(0)

int	td_printf(unsigned int handle, char* pszfmt, ...);
/*
 * ��������:td_printf
 * ��Ҫ����:��ʽ����ӡ�ַ����������ʱ����Ϣ������ʱ����Ϣ����ѡȡ��ͬ����ɫ
 * ��	 ��:
 *			handle����ӡ����:0����ɫ;0xFF0000,��ɫ;0x12345678,��ɫ;��������ӡ���ļ�printf.txt
 *			pszfmt���ǿգ���ʽ��
 *			...���ɱ�����б�
 * ��	 ��:
 *			�Ѵ�ӡ���ַ���
 * �޸���־:
 *			2009-10-26,������������
 */

void print_hex(unsigned char* _string, int _len);
/*
 * ��������:print_hex
 * ��Ҫ����:����ʮ����������ӡ�ַ�����
 * ��	 ��:
 *			_string������ӡ���ַ�����
 *			_len���ַ������Ա����
 * ��	 ��:
 *			��
 * �޸���־:
 *			2009-10-26,������������
 */

int strtoken_r(char *str, char *delim, char ** array, int kwSect);
/*
 * ��������:strtoken_r
 * ��Ҫ����:���ַ������շָ������䵽�ַ�ָ������
 * ��	 ��:
 *			str����Ҫ��������Դ�ַ���
 *			delim���ָ���
 *			array, Ŀ��ָ������
 *			kwSect, ָ�������ά��
 * ��	 ��:
 *			��
 * �޸���־:
 *			2010-01-28,��ΰ������
 */

//ȥ��ip��ַÿ���ֶε�ǰ��0, wzy 20140730
int ChangeIpAddr(char *_strIp);

#else
#define TD_RETURN(exp,ret,arg...)
#if 1
#ifdef TD_MP4LOG
#define td_printf td_printf_mp4log
#else
#define td_printf(a,b,...)
#endif
#else
#define td_printf(a, b, args...)	printf(b, ##args)
#endif
#define print_hex(_string,_len)
#endif

#endif /*_LIBTIANDY_*/

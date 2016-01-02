#ifndef _USER_DATA_H_
#define _USER_DATA_H_

#include <time.h>

typedef enum
{
    USER_DATA_TIME = 0,
    USER_DATA_VCA,
    USER_DATA_VITAL_SIGN,
    USER_DATA_MAX,
}TUserDataType;

//ʱ��η�װ�ṹ
typedef struct
{
	unsigned short	m_usSegmentflag;
	unsigned short	m_usSegmentLength;
	int 			m_CurrentTime;		
}TUserDataTimeSegment;


typedef enum
{
	VITAL_SIGN_HR = 1, //����
	VITAL_SIGN_BO = 2, //Ѫ��
 	VITAL_SIGN_BP = 3, //Ѫѹ 
}TVitalSignDataType;

typedef struct //���������ɼ����ݷ�װ
{
	char m_cVersion;//Э��汾
	char m_cType;	//���������ɼ�����,1������ 2��Ѫ�� 3��Ѫѹ
	char m_cMonFlg; //1:����2:������ 3��������4:���� 5:�豸����    
	char m_iOscilloGramSeqID; //��1��ʼ���ĵ�����������δ���1��2��3��Ѫ��һ����ʹ��1
	int m_iMonVal[4]; //����ʵʱֵ, Ѫѹ3��,SYS DIA PR���δ�ţ����ȣ�ԭֵ����100;
	int m_iGramRate;//1s�ж��ٸ���
	int m_iSizeType; // 1:�� 2���� 3��С
	int m_iXPosition; // �������Ƶ�����Ͻ�(0,0)����Ժ�����
	int m_iYPosition; // �������Ƶ�����Ͻ�(0,0)�����������
	int m_iPointLen;
	unsigned char m_cPointValue[0]; //�㼯
} TUserDataVitalSign;

#define MAX_VITAL_DATA_POINT_LEN 125		//ÿ���������125����
#define MAX_USER_DATA_VITAL_DATA_LEN		(sizeof(TUserDataVitalSign) + MAX_VITAL_DATA_POINT_LEN)

typedef struct
{
	unsigned short		m_usType;    			/*0xFEDA */
	unsigned short		m_usLentgh;  			/*���ݳ���*/
	TUserDataVitalSign	m_tVitalSignData;		/*������������*/
} TUserDataVitalSignSegment;

//�����û�˽�����ݽṹ
typedef struct
{
	char			m_cCheckoutSegment[4];
	unsigned short	m_usUserDataSegmentTotal;
	unsigned short	m_usUserDataSegmentLength;	
} TInsertUserData;

typedef int(* _InserUserDataFun)(int _iId,void * _pBuf,int _iSize);
int UserDataInit(int(*_InserUserDataFun)(int _iId, void *_pBuf, int _iSize));
void UserDataUninit();
typedef int (*_GetUserDataFun)(int _iId, void *_pBuf, int *_iBufSize);
void UserDataRegist(int _iType, int _iInterval, int _iId, int (*_GetUserDataFun)(int _iId, void *_pBuf, int *_iBufSize));

typedef struct _TUserDataTask
{
    TUserDataType m_iType;                        //�û���������
    int m_iInterval;                    //���ݸ��¼��,�����ʾ
    long long m_llNextUpdateTime;        //��һ�θ���ʱ��
    struct _TUserDataTask *m_ptNextTask;//��һ������ָ��    

    int (*GetUserDataFun)(int _iId, void *_pBuf, int *_iBufSize);//�û��������ɺ���
}TUserDataTask;//�û���������ṹ��һ�����͵��û������Ӧһ������

typedef struct _UserDataGroup
{
    int m_iId;                          //�û��������ţ�ͨ��Ϊ����ͨ����
    TUserDataTask *m_ptTaskList;        //�����Ӧ�û����������б�
    struct _UserDataGroup *m_ptNextGrp; //��һ���û�������
}TUserDataGroup;        //�û������飬һ������ͨ����Ӧһ����

#endif

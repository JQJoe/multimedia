#ifndef _GPS_H_
#define _GPS_H_

#include <time.h>

typedef struct GPSWORKMODE
{
	int	m_iMode;	//gxl added 20130815 mode for gps or bd, gps:0 bd:1auto:3
}GPSWORKMODE_T;

typedef struct stDataGroup
{    	
	float m_fLatitude;			//γ�ȣ���λ�Ƕ�
	float m_fLongitude;			//���ȣ���λ�Ƕ�
	char m_cWorE;				//��������
	char m_cNorS;				//�ϻ��߱�
	float m_fSpeed;				//�ٶȣ���λ��ǧ��/Сʱ
	float m_fElevation;			//���Σ���λ��	
	int m_iLocated;				//�Ƿ�λ, 1Ϊ��λ��2Ϊδ��λ
	char m_cgpsWord[1024];		//����ԭʼ����	
	int m_iIntensity;			//�ź�ǿ��,0-100
	int m_iSateliteNum;			//��ǰ���Ǹ���
	time_t m_iTimer;			//gpsУʱʱ��	
}GPSData;

/*
GPSģ���ʼ��,
����:_pcComPath: 	�����豸�ڵ�,
             _pstComAttr:��������
����ֵ:0 �ɹ�
		    -1ʧ��
*/
int gps_init(char *_pcComPath, TCom *_pstComAttr);

/*
��ȡGPSģ�鹤��ģʽ
����ֵ:ģ�鹤��ģʽ
*/
int gps_getworkmode(void);


/*
GPSģ������
����:_tWorkMode: 	ģ�鹤��ģʽ
����ֵ:0 �ɹ�
		    -1ʧ��
*/
int gps_reset(void);


/*
����gps��Ϣ����ϵ��
����:_iFilter: ��Ϣ����ϵ��,ÿλ����һ��Э�飬��ĳλ������Ϊ1����ʾ�ͻ�����Ҫ����GPSЭ�飬��Э�齫��ת�����ͻ��ˣ�0��ʾ����Ҫ����ת����iFilterΪ0��ʾ��ת���κ�GPSЭ�顣Ϊ65535ʱ��ʾ������Ϣ����Ҫ���൱�ڲ������κ���Ϣ����
GPGGA---��1λ��GPRMC---��2λ��GPVTG---��3λ�� GPGLL����λ��Ϣ---��4λ�� GPGSA---��5λ�� GPGSV---��6λ������λ��ʱ������
����ֵ:0 �ɹ�
		    -1ʧ��
*/
int gps_setfilter(int _iFilter);


/*
��ȡGPS����
����ֵ:GPS����
*/
const GPSData* gps_getdata(void);
#endif


/*******************************************************************
�ļ���	:PTZ.h
��˾	:������ΰҵ����Ƽ����޹�˾
������	:������
��������:2008-11-12
��Ҫ����:���ڵĳ�ʼ�������á���̨������صĺ���ԭ���Լ�����
�޸ļ�¼:2008-11-12,������������
		 2008-11-28,����������Ӷ�̬����PTZЭ��Ĺ��ܣ��޸������ӿ�
******************************************************************/
#ifndef PTZ_H_
#define PTZ_H_

#include "ptzex.h"
#include "td_types.h"


#define		MAX_PTZ_ADDRESS			256				//PTZ��ַ�����ֵ
#define		MIN_PTZ_ADDRESS			0				//PTZ��ַ����Сֵ
#define 	MAX_PTZ_ROUTINE_NUM		8				//���ģʽ·����
#define 	MAX_PTZ_CRUISE_NUM		8				//���Ѳ���켣��
#define 	MAX_PTZ_ASSISTANT_NUM	8				//�����������
#define 	MAX_PTZ_PRESET_NUM		255				//���Ԥ��λ��
#define		MAX_PRESET_PER_CRUISE	32				//ÿ��Ѳ���켣�������õ����Ԥ�õ���
#define		MAX_PROTOCOL_NUM		64				//���֧�ֵ�PTZЭ����
#define		MAX_PROTOCOL_PATH_LEN	64				//���Э�鶯̬��·������
#define		MAX_PROTOCOL_NAME_LEN	32				//���Э�����Ƴ���
#define     MAX_PTZ_DO_ROUTINE_NUM	65				//���켣������
#define		MAX_CHANNLE_NUM			32				//���ͨ����
#define SLEEP_FOR_BALLINTER usleep(100000)                              //�������������ʱ��100ms


typedef int (*pPtzAction)(int, PTZ_DATA *);

//�ɿ��Ƶ�Э��(PROTOCOL)����
typedef enum
{
	PRT_TIANDY = 0, 								//���Э��
	PRT_PELCO_P,									//Pelco_p
	PRT_PELCO_D,									//Pelco_D
	PRT_TC615_P,									//615_P
	PRT_TC615_D,									//615_D
	PRT_TYPES,										//�豸��֧�ֵ�Э����Ŀ����Ҫ��չ�����ڸ���������ӡ�
}TProtocolType;


//Ѳ����
typedef struct
{
	td_u8		m_cPreset;									//Ԥ��λ��
	td_u8		m_cStayTime;								//ͣ��ʱ��
	td_u8		m_cSpeed;									//�ٶ�
	td_u8		m_cReserved;								//Ԥ��
}TCruisePoint;	

//Ѳ���켣,��ӦUI��Ѳ��·��
typedef struct
{
	td_s32			m_blEnable;								//ʹ��
	td_s32			m_blState;								//��ǰѲ���켣���ڱ�1, ����.0,δ������
	td_s32			m_iCruiseNum;							//Ѳ������
	TCruisePoint	m_stCrisePoint[MAX_PRESET_PER_CRUISE];	//Ѳ����
}TCruise;

//��PTZЭ�������
typedef struct
{
	td_u8			m_cProtocolName[MAX_PROTOCOL_NAME_LEN];	//Э������
	td_u8			m_cSoPath[MAX_PROTOCOL_PATH_LEN];		//��̬��·������
	void*			m_pHandle;								//��̬����
	pPtzAction		m_fAction;								//��Э������Ӧ�����뺯��
}TProtocol;

typedef struct
{
	td_s32			m_time;
	PTZ_DATA		m_data;
	td_s32 			m_iAction;
}RoutinePama;

typedef enum{
	PTZ_TU = 1, 	//��
	PTZ_TD,		//��
	PTZ_PL,		//��
	PTZ_PR,		//��
	PTZ_TUPR,	//����
	PTZ_TUPL,	//�� ��
	PTZ_TDPR,	//����
	PTZ_TDPL,	//����
	PTZ_STOP,	//ֹͣ
	PTZ_ZIN,	// ��������
	PTZ_ZOUT,	//������Զ
	PTZ_IST,	//�仯ֹͣ
	PTZ_FN,		//�������
	PTZ_FR,		//�����Զ
	PTZ_FST,	//����仯ֹͣ
	PTZ_IA_ON,	//��Ȧ�Զ�����
	PTZ_IO,		//��Ȧ����
	PTZ_IC,		//��Ȧ��С
	PTZ_WP_ON,//��������
	PTZ_WP_OFF,//����ֹͣ
	PTZ_LP_ON,	//�ƹ⿪��
	PTZ_LP_OFF,//�ƹ�ֹͣ
	PTZ_AUTO_START,//�Զ�ɨ�迪ʼ
	PTZ_AUTO_STOP,//�Զ�ɨ��ֹͣ
	PTZ_GOTO_PRESET,//ת��Ԥ���
	PTZ_START_TRACK_CRUISE,//��ʼ�켣Ѳ��
	PTZ_STOP_TRACK_CRUISE,//ֹͣ�켣Ѳ��
	PTZ_SET_PRESET,
	PTZ_POWER_ON,	//��Դ����
	PTZ_POWER_OFF,//��Դ�ر�
	PTZ_3D_POSITION,		//PTZ 3D��λ
	PTZ_3D_ROCKER,			//��3άҡ�˵���Ӧ
	PTZ_ASSISTANT_ON,		//�������ؿ�
	PTZ_ASSISTANT_OFF,		//�������ع�
	PTZ_START_ROUTINE,	//��ʼ��ʾ�켣
	PTZ_STOP_ROUTINE,		//������ʾ�켣
}ENUM_PTZ;

td_s32 ptz_GetComNum(td_s32* _piComNum, td_s32* _piComEnable);
/*
 * �������ƣ�GetComNum
 * ��Ҫ����: ��ȡ�豸�Ĵ�����
 * ��	  �룺
 * 			_piComNum, ���ڴ����豸���������ǿ�
 *			_piComEnable,���������Ƿ���ã��ǿ�
 * ��	  ����
 * 			ERR_PTZ_SUCCESSFUL,�����ɹ�
 *			ERR_PTZ_WRONG_PARAM, ����Ĳ���
 * 			ERR_PTZ_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-12-25,������,����, Merry Christmas
 */

td_s32 ptz_SetBaudRate(td_s32 _iComNo, td_s32 speed);
/*
 * �������ƣ�SetBaudRate
 * ��Ҫ����: ����ĳͨ���Ĳ�����
 * ��	  �룺
 * 			_iComNo, 0~MAX_SERIAL_NUM,�˿ں�
 *			speed, �����ʣ���PTZ.c�ļ��������������name_arr
 * ��	  ����
 * 			ERR_PTZ_WRONG_PARAM,����Ĳ���
 * 			ERR_PTZ_SUCCESSFUL,�����ɹ�
 * 			ERR_PTZ_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-11-13,������,����
 */
 
td_s32 ptz_GetBaudRate(td_s32 _iComNo, td_s32* _piBaudRate);
/*
 * �������ƣ�GetBaudRate
 * ��Ҫ����: ��ȡĳͨ���Ĳ�����
 * ��	  �룺
 * 			_iComNo, 0~MAX_SERIAL_NUM,�˿ں�
 *			_piBaudRate, ���ڴ��������ʣ��ǿգ�����ȡֵ��PTZ.c�ļ��������������name_arr
 * ��	  ����
 * 			ERR_PTZ_WRONG_PARAM,����Ĳ���
 * 			ERR_PTZ_SUCCESSFUL,�����ɹ�
 * 			ERR_PTZ_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-11-13,������,����
 */

td_s32 ptz_SetBits (td_s32 _iComNo, td_s32 databits, td_s32 stopbits, td_s32 parity);
/*
 * �������ƣ�SetBits
 * ��Ҫ����: ����ĳͨ��������λ��ֹͣλ��У��λ
 * ��	  �룺
 * 			_iComNo, 0~MAX_SERIAL_NUM,�˿ں�
 *			databits, ����λ,ȡ7��8
 *			stopbits, ֹͣλ,ȡ1��2
 *			parity,У�鷽ʽ,���ܵ�ȡֵΪ'N','n','O','o','E','e','S','s'
 * ��	  ����
 * 			ERR_PTZ_WRONG_PARAM,����Ĳ���
 * 			ERR_PTZ_SUCCESSFUL,�����ɹ�
 * 			ERR_PTZ_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-11-13,������,����
 */

td_s32 ptz_GetBits(td_s32 _iComNo, td_s32* _piDataBits, td_s32* _piStopBits, td_s32* _piVerifyBits);
/*
 * �������ƣ�GetBits
 * ��Ҫ����: ��ȡĳͨ��������λ��ֹͣλ��У��λ
 * ��	  �룺
 * 			_iComNo, 0~MAX_SERIAL_NUM,�˿ں�
 *			_piDataBits, ���ڴ�������λ,���ܵ�ȡֵΪȡ7��8
 *			_piStopBits, ���ڴ���ֹͣλ,���ܵ�ȡֵΪȡ1��2
 *			_piVerifyBits,���ڴ���У�鷽ʽ,���ܵ�ȡֵΪ'N','n','O','o','E','e','S','s'
 * ��	  ����
 * 			ERR_PTZ_WRONG_PARAM,����Ĳ���
 * 			ERR_PTZ_SUCCESSFUL,�����ɹ�
 * 			ERR_PTZ_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-11-13,������,����
 */
 
td_s32 ptz_SetMode(td_s32 _iComNo, td_s32 _iMode);
/*
 * �������ƣ�SetMode
 * ��Ҫ����: ����ĳͨ���Ĺ���ģʽ
 * ��	  �룺
 * 			_iComNo, 0~MAX_SERIAL_NUM,�˿ں�
 *			_iMode, �˿ڵĹ���ģʽ��1Ϊ����Э��ģʽ��2Ϊ͸��ͨ��
 * ��	  ����
 * 			ERR_PTZ_WRONG_PARAM,����Ĳ���
 * 			ERR_PTZ_SUCCESSFUL,�����ɹ�
 * 			ERR_PTZ_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-11-13,������,����
 */

td_s32 ptz_GetMode(td_s32 _iComNo, td_s32* _piMode);
/*
 * �������ƣ�SetMode
 * ��Ҫ����: ����ĳͨ���Ĺ���ģʽ
 * ��	  �룺
 * 			_iComNo, 0~MAX_SERIAL_NUM,�˿ں�
 *			_piMode, ���ڴ����˿ڵĹ���ģʽ��1Ϊ����Э��ģʽ��2Ϊ͸��ͨ��
 * ��	  ����
 * 			ERR_PTZ_WRONG_PARAM,����Ĳ���
 * 			ERR_PTZ_SUCCESSFUL,�����ɹ�
 * 			ERR_PTZ_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-11-13,������,����
 */

td_s32 ptz_SetSlaveCom(void);
/*
 * �������ƣ�SetSlaveCom
 * ��Ҫ����: ��ʼ����Ƭʱ���ô�Ƭ�Ĵ������ԣ���Ҫ���ڴ�Ƭ�쳣������Ĳ���
 * ��	  �룺
 * 			��
 * ��	  ����
 * 			ERR_PTZ_SUCCESSFUL,�����ɹ�
 * 			ERR_PTZ_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2009-06-18,������,����
 */

td_s32 ptz_Clarity(td_s32 _iComNo, td_u8 * _pcData, td_s32 _iLen);
/*
 * �������ƣ�Clarity
 * ��Ҫ����: ��ĳͨ������͸��ͨ���µ�PTZ����
 * ��	  �룺
 * 			_iComNo, ���ںţ�0~MAX_CHANNEL_NUM
 *			_pcData, Ҫд�����ڵ�����
 *			_iLen, Ҫд�����ڵ����ݳ���
 * ��	  ����
 * 			ERR_PTZ_WRONG_PARAM,����Ĳ���
 *			ERR_PTZ_UNKNOWN_PROTOCOL,��֧�ָ�Э��
 *			ERR_PTZ_MAKE_CODE_ERROR,����ʧ��
 *			ERR_PTZ_WRITE_COM_ERROR,�򴮿�д����ʧ��
 * 			ERR_PTZ_SUCCESSFUL,�����ɹ�
 * 			ERR_PTZ_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-12-03,������,����
 */


td_s32 ptz_GetProtocolList(td_u8 _cList[MAX_PROTOCOL_NUM][MAX_PROTOCOL_NAME_LEN]);
/*
 * �������ƣ�GetProtocolList
 * ��Ҫ����: ��ȡ�豸֧�ֵ�Э���б�
 * ��	  �룺
 * 			_cList, �ǿ�,���ڴ���Э���б�
 * ��	  ����
 * 			�豸֧�ֵ�Э������-1Ϊ����Ĳ���
 * �޸���־��
 * 			2009-11-01,������,����
 */

td_s32 ptz_GetDelProtocolList(td_u8 _cList[MAX_PROTOCOL_NUM][MAX_PROTOCOL_NAME_LEN]);
/*
 * �������ƣ�GetDelProtocolList
 * ��Ҫ����: ��ȡ��ж�ص�Э���б�
 * ��	  �룺
 * 			_cList, �ǿ�,���ڴ���Э���б�
 * ��	  ����
 * 			-1,����Ĳ���
 * 			����,��ж�ص�Э����
 * �޸���־��
 * 			2009-11-28,������,����
 */
 
td_s32 ptz_AddProtocol(td_u8 _cProtocol[MAX_PROTOCOL_NAME_LEN]);
/*
 * �������ƣ�AddProtocol
 * ��Ҫ����: ���һ���µ�Э��
 * ��	  �룺
 * 			_cProtocol, �ǿգ�����ӵ�Э��
 * ��	  ����
 * 			ERR_PTZ_MAX_PRTNUM,�Ѵ��豸֧�ֵ�Э��������
 * 			ERR_PTZ_UNKNOWN_PROTOCOL,��֧�ָ�Э��
 * 			ERR_PTZ_WRONG_PARAM,����Ĳ���
 *			ERR_PTZ_SUCCESSFUL,��ӳɹ�
 * �޸���־��
 * 			2009-11-28,������,����
 */
 
td_s32 ptz_DelProtocol(td_u8 _cProtocol[MAX_PROTOCOL_NAME_LEN]);
/*
 * �������ƣ�DelProtocol
 * ��Ҫ����: ж��ĳһ��PTZЭ��
 * ��	  �룺
 * 			_cProtocol, �ǿգ���ɾ����Э��
 * ��	  ����
 * 			ERR_PTZ_WRONG_PARAM,����Ĳ���
 * 			ERR_PTZ_SUCCESSFUL,�����ɹ�
 * 			ERR_PTZ_USING_PROTOCOL,��Э�����ڱ�ĳһ��ͨ��ʹ��
 *			ERR_PTZ_UNKNOWN_PROTOCOL,��֧�ָ�Э�飬ͨ�����Ҳ�����Э���Ӧ��so�ļ�
 * �޸���־��
 * 			2009-11-28,������,����
 */
 
td_s32 ptz_SetChannelPTZ(td_s32 _iChannelNo, td_s32 _iComNo, td_u8* _cProtocolName, td_s32 _iAddress);
/*
 * �������ƣ�SetChannelPTZ
 * ��Ҫ����: ����ĳͨ����PTZ����
 * ��	  �룺
 * 			_iChannelNo, 0~MAX_CHANNEL_NUM,ͨ����
 *			_iComNo, ���ø�ͨ������PTZ���ƵĶ˿�,0~MAX_SERIAL_NUM
 *			_cProtocolName,��ͨ������PTZ���Ƶ�Э����������,�ǿ�
 *			_iAddress,��ͨ�������豸��PTZ��ַ
 * ��	  ����
 * 			ERR_PTZ_WRONG_PARAM,����Ĳ���
 *			ERR_PTZ_UNKNOWN_PROTOCOL,��֧�ֵ�Э��
 * 			ERR_PTZ_SUCCESSFUL,�����ɹ�
 * 			ERR_PTZ_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-11-13,������,����
 *			2008-11-28,���������������������޸�ΪЭ������
 */

td_s32 ptz_GetChannelPTZ(td_s32 _iChannelNo, td_s32* _piComNo, td_u8* _pcProtocol, td_s32* _piAddress);
/*
 * �������ƣ�GetChannelPTZ
 * ��Ҫ����: ��ȡĳͨ����PTZ����
 * ��	  �룺
 * 			_iChannelNo, 0~MAX_CHANNEL_NUM,ͨ����
 *			_piComNo, ���ڴ�����ͨ������PTZ���ƵĶ˿�,0~MAX_SERIAL_NUM
 *			_pcProtocol,���ڴ�����ͨ������PTZ���Ƶ�Э����������,�ǿ�
 *			_piAddress,���ڴ�����ͨ�������豸��PTZ��ַ
 * ��	  ����
 * 			ERR_PTZ_WRONG_PARAM,����Ĳ���
 * 			ERR_PTZ_SUCCESSFUL,�����ɹ�
 * 			ERR_PTZ_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-11-13,������,����
 *			2008-11-28,���������������������޸�ΪЭ������
 */
 
td_s32 ptz_Control(td_s32 _iChannelNo, td_s32 _iAction ,PTZ_DATA* _pData);
/*
 * �������ƣ�Control
 * ��Ҫ����: ��ĳͨ������PTZ����
 * ��	  �룺
 * 			_iChannelNo, ͨ���ţ�0~MAX_CHANNEL_NUM
 *			_iAction, ��������, �������ö������ENUM_PTZ;��͸��ͨ��ģʽ�²�ʹ�øò���
 *			_pData, ����PTZ��������Ĳ���,��͸��ͨ��ģʽ��ֻʹ�����е�iCount��DecBuf�����ֶ�
 * ��	  ����
 * 			ERR_PTZ_WRONG_PARAM,����Ĳ���
 *			ERR_PTZ_UNKNOWN_PROTOCOL,��֧�ָ�Э��
 *			ERR_PTZ_MAKE_CODE_ERROR,����ʧ��
 *			ERR_PTZ_WRITE_COM_ERROR,�򴮿�д����ʧ��
 * 			ERR_PTZ_SUCCESSFUL,�����ɹ�
 * 			ERR_PTZ_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-11-13,������,����
 */

td_s32 ptz_Init(td_s32 _iMaxChannelCnt);
/*
 * �������ƣ�Init
 * ��Ҫ����: ��ʼ��PTZģ��
 * ��	  �룺
 * 			��
 * ��	  ����
 * 			ERR_PTZ_SUCCESSFUL,�����ɹ�
 * 			ERR_PTZ_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-11-13,������,����
 */
 
td_s32 ptz_Exit(void);
/*
 * �������ƣ�Exit
 * ��Ҫ����: ȥ��ʼ��PTZģ��
 * ��	  �룺
 * 			��
 * ��	  ����
 * 			ERR_PTZ_SUCCESSFUL,�����ɹ�
 * 			ERR_PTZ_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-11-13,������,����
 */

td_s32 ptz_SetCruise(td_s32 _iChannelNo, td_s32 _iCruiseNo, TCruise* _pstCruise);
/*
 * �������ƣ�SetCruise
 * ��Ҫ����: ����ĳͨ����ĳ��Ѳ���켣
 * ��	  �룺
 * 			_iChannelNo, 0~MAX_CHANNEL_NUM, ͨ����
 *			_iCruiseNo, 0~MAX_PTZ_CRUISE_NUM, Ѳ���켣��
 *			_pstCruise, �ǿգ�����Ѳ���켣����
 * ��	  ����
 * 			ERR_PTZ_SUCCESSFUL,�����ɹ�
 *			ERR_PTZ_WRONG_PARAM, ����Ĳ���
 * 			ERR_PTZ_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-12-25,������,����, Merry Christmas
 */

td_s32 ptz_GetCruise(td_s32 _iChannelNo, td_s32 _iCruiseNo, TCruise * _pstCruise);
/*
 * �������ƣ�GetCruise
 * ��Ҫ����: ��ȡĳͨ����ĳ��Ѳ���켣
 * ��	  �룺
 * 			_iChannelNo, 0~MAX_CHANNEL_NUM, ͨ����
 *			_iCruiseNo, 0~MAX_PTZ_CRUISE_NUM, Ѳ���켣��
 *			_pstCruise, �ǿգ�����Ѳ���켣����
 * ��	  ����
 * 			ERR_PTZ_SUCCESSFUL,�����ɹ�
 *			ERR_PTZ_WRONG_PARAM, ����Ĳ���
 * 			ERR_PTZ_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-12-25,������,����, Merry Christmas
 */
td_s32 ptz_StartCruise(td_s32 _iChannelNo, td_s32 _iCruiseNo);
/*
 * �������ƣ�StartCruise
 * ��Ҫ����: ��ʼ����ĳ��Ѳ���켣
 * ��	  �룺
 * 			_iChannelNo, 0~MAX_CHANNEL_NUM, ͨ����
 *			_iCruiseNo, 0~MAX_PTZ_CRUISE_NUM, Ѳ���켣��
 * ��	  ����
 * 			ERR_PTZ_SUCCESSFUL,�����ɹ�
 *			ERR_PTZ_WRONG_PARAM, ����Ĳ���
 *			ERR_PTZ_UNUSABLE_FUNCTION,��Ѳ���켣δ������
 * 			ERR_PTZ_FAILED,����ԭ���²���ʧ��,��ù켣�Ѿ�������
 * �޸���־��
 * 			2008-12-25,������,����, Merry Christmas
 */
 
td_s32 ptz_StopCruise(td_s32 _iChannelNo, td_s32 _iCruiseNo);
/*
 * �������ƣ�StopCruise
 * ��Ҫ����: ֹͣ����ĳ��Ѳ���켣
 * ��	  �룺
 * 			_iChannelNo, 0~MAX_CHANNEL_NUM, ͨ����
 *			_iCruiseNo, 0~MAX_PTZ_CRUISE_NUM, Ѳ���켣��
 * ��	  ����
 * 			ERR_PTZ_SUCCESSFUL,�����ɹ�
 *			ERR_PTZ_WRONG_PARAM, ����Ĳ���
 *			ERR_PTZ_UNUSABLE_FUNCTION,��Ѳ���켣δ������
 * 			ERR_PTZ_FAILED,����ԭ���²���ʧ��,��ù켣�Ѿ�������
 * �޸���־��
 * 			2008-12-25,������,����, Merry Christmas
 */
 
td_s32 ptz_StartSetRoutine(td_s32 _iChannelNo, td_s32 _iRoutineNo);
/*
 * �������ƣ�StartSetRoutine
 * ��Ҫ����: ��ʼ����ģʽ·��
 * ��	  �룺
 * 			_iChannelNo, 0~MAX_CHANNEL_NUM, ͨ����
 *			_iRoutineNo, 0~MAX_PTZ_ROUTINE_NUM, ģʽ·����
 * ��	  ����
 * 			ERR_PTZ_SUCCESSFUL,�����ɹ�
 *			ERR_PTZ_WRONG_PARAM, ����Ĳ���
 * 			ERR_PTZ_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-12-25,������,����, Merry Christmas
 */
 
td_s32 ptz_StopSetRoutine(td_s32 _iChannelNo, td_s32 _iRoutineNo);
/*
 * �������ƣ�StopSetRoutine
 * ��Ҫ����: ��������ĳ��ģʽ·��
 * ��	  �룺
 * 			_iChannelNo, 0~MAX_CHANNEL_NUM, ͨ����
 *			_iRoutineNo, 0~MAX_PTZ_ROUTINE_NUM, ģʽ·����
 * ��	  ����
 * 			ERR_PTZ_SUCCESSFUL,�����ɹ�
 *			ERR_PTZ_WRONG_PARAM, ����Ĳ���
 * 			ERR_PTZ_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-12-25,������,����, Merry Christmas
 */
 
td_s32 ptz_StartRoutine(td_s32 _iChannelNo, td_s32 _iRoutineNo);
/*
 * �������ƣ�StartRoutine
 * ��Ҫ����: ��ʼ����ĳ��ģʽ·��
 * ��	  �룺
 * 			_iChannelNo, 0~MAX_CHANNEL_NUM, ͨ����
 *			_iRoutineNo, 0~MAX_PTZ_ROUTINE_NUM, ģʽ·����
 * ��	  ����
 * 			ERR_PTZ_SUCCESSFUL,�����ɹ�
 *			ERR_PTZ_WRONG_PARAM, ����Ĳ���
 * 			ERR_PTZ_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-12-25,������,����, Merry Christmas
 */
 
td_s32 ptz_StopRoutine(td_s32 _iChannelNo, td_s32 _iRoutineNo);
/*
 * �������ƣ�StopRoutine
 * ��Ҫ����: ��������ĳ��ģʽ·��
 * ��	  �룺
 * 			_iChannelNo, 0~MAX_CHANNEL_NUM, ͨ����
 *			_iRoutineNo, 0~MAX_PTZ_ROUTINE_NUM, ģʽ·����
 * ��	  ����
 * 			ERR_PTZ_SUCCESSFUL,�����ɹ�
 *			ERR_PTZ_WRONG_PARAM, ����Ĳ���
 * 			ERR_PTZ_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-12-25,������,����, Merry Christmas
 */

td_s32 ptz_GotoPreset(td_s32 _iChannelNo, td_s32 _iPresetNo);
/*
 * �������ƣ�GotoPreset
 * ��Ҫ����: ����Ԥ��λ
 * ��	  �룺
 * 			_iChannelNo, 0~MAX_CHANNEL_NUM, ͨ����
 *			_iPresetNo, Ԥ��λ��,1~MAX_PTZ_PRESET_NUM 
 * ��	  ����
 * 			ERR_PTZ_SUCCESSFUL,�����ɹ�
 *			ERR_PTZ_WRONG_PARAM, ����Ĳ���
 * 			ERR_PTZ_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2008-08-21,������,��Alarm.c������PTZ.c
 */

td_s32 ptz_DefaultCfg(void);
/*
 * �������ƣ�DefaultCfg
 * ��Ҫ����: �ָ�Ѳ���켣�ĳ�ʼ����
 * ��	  �룺
 * 			��
 * ��	  ����
 * 			ERR_PTZ_SUCCESSFUL,�����ɹ�
 *			ERR_PTZ_WRONG_PARAM, ����Ĳ���
 * 			ERR_PTZ_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2009-01-16,������,����
 */

td_s32 ptz_AssistantSwitch(td_s32 _iChannelNo, td_s32 _iSwitchNo, td_s32 _iType);
/*
 * �������ƣ�AssistantSwitch
 * ��Ҫ����: �򿪻�رո�������
 * ��	  �룺
 * 			_iChannelNo, ͨ����, 0~MAX_CHANNEL_NUM
 *			_iSwitchNo, �������غţ�0~MAX_PTZ_ASSISTANT_NUM
 *			_iType, 1Ϊ�򿪣� 0Ϊ�ر�
 * ��	  ����
 * 			ERR_PTZ_SUCCESSFUL,�����ɹ�
 *			ERR_PTZ_WRONG_PARAM, ����Ĳ���
 * 			ERR_PTZ_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2009-05-16,������,����
 */

td_s32 ptz_SetChannelComAttr(td_s32 _iChannelNo, TCom* _pstCom, td_s32 _blEnable);
/*
 * �������ƣ�SetChannelComAttr
 * ��Ҫ����: ����ͨ��PTZ�Ĵ�������
 * ��	  �룺
 * 			_iChannelNo, ͨ����, 0~MAX_CHANNEL_NUM
 *			_pstCom, �������ԣ��ǿ�
 *			_blEnable, �Ƿ��Զ��崮�����ԣ�0��1
 * ��	  ����
 * 			ERR_PTZ_SUCCESSFUL,�����ɹ�
 *			ERR_PTZ_WRONG_PARAM, ����Ĳ���
 * 			ERR_PTZ_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2009-11-20,������,����
 */
 
td_s32 ptz_GetChannelComAttr(td_s32 _iChannelNo, TCom* _pstCom, td_s32* _pblEnable);
/*
 * �������ƣ�GetChannelComAttr
 * ��Ҫ����: ��ȡͨ��PTZ�Ĵ�������
 * ��	  �룺
 * 			_iChannelNo, ͨ����, 0~MAX_CHANNEL_NUM
 *			_pstCom, �����������ԣ��ǿ�
 *			_pblEnable, ���ڴ����Ƿ��Զ��崮�����ԣ��ǿ�
 * ��	  ����
 * 			ERR_PTZ_SUCCESSFUL,�����ɹ�
 *			ERR_PTZ_WRONG_PARAM, ����Ĳ���
 * 			ERR_PTZ_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2009-11-20,������,����
 */

td_s32 ptz_NetKeyBorad(td_s32 _iCh, td_s32 _iCode);
/*
 * �������ƣ�NetKeyBorad
 * ��Ҫ����: ͨ��������̽���PTZ����
 * ��	  �룺
 * 			_iCh, ͨ����, 0~MAX_CHANNEL_NUM
 *			_iCode, ������
 * ��	  ����
 * 			ERR_PTZ_WRONG_PARAM,����Ĳ���
 *			ERR_PTZ_UNKNOWN_PROTOCOL,��֧�ָ�Э��
 *			ERR_PTZ_MAKE_CODE_ERROR,����ʧ��
 *			ERR_PTZ_WRITE_COM_ERROR,�򴮿�д����ʧ��
 * 			ERR_PTZ_SUCCESSFUL,�����ɹ�
 * 			ERR_PTZ_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2009-11-28,������,��gui_cmd_execute.c�������ˣ�������Ϊ����
 */

td_s32 ptz_3DPosition(td_s32 _iCh, td_s32* _iParam);
/*
 * �������ƣ�3DPosition
 * ��Ҫ����: ͨ��������̽���PTZ����
 * ��	  �룺
 * 			_iCh, ͨ����, 0~MAX_CHANNEL_NUM
 *			_iParam, 3D��λ�������������飬����Ϊ���λ��x/���λ��y/��Ļ��/��Ļ��/
 *			�����(����������������, 0���)/�����(����������������, 0���)
 * ��	  ����
 * 			ERR_PTZ_WRONG_PARAM,����Ĳ���
 *			ERR_PTZ_UNKNOWN_PROTOCOL,��֧�ָ�Э��
 *			ERR_PTZ_MAKE_CODE_ERROR,����ʧ��
 *			ERR_PTZ_WRITE_COM_ERROR,�򴮿�д����ʧ��
 * 			ERR_PTZ_SUCCESSFUL,�����ɹ�
 * 			ERR_PTZ_FAILED,����ԭ���²���ʧ��
 * �޸���־��
 * 			2009-11-28,������,��gui_cmd_execute.c�������ˣ�������Ϊ����
 */

td_s32 ptz_GetRoutineStat(int _iChn);
td_s32 ptz_GetCruiseStat(int _iChn);

td_s32 ptz_GetVcChnComNo(td_s32 *_piComNo,td_s32 *_piVcMainChnNo);
/*
 * �������ƣ�ptz_GetVcChnComNo
 * ��Ҫ����: ��ȡ�ϳ�ͨ���Ĵ��ڱ�ţ�Ĭ�������Ĵ��ں�
 * ��	  �룺
 * 			_piComNo, ���ں�
 *			_piVcMainChnNo,  �ϳ�ͨ�����������
 * ��	  ����
 * 			
 * �޸���־��
 * 			2009-11-10,�����
 */

td_s32 Ptz_sComAttrForVc(int _iComNo);

td_s32 Ptz_sChannelPTZForVc(td_s32 _iMainChannelNo);
/*
 * �������ƣ�Ptz_sChannelPTZForVc
 * ��Ҫ����: 
 * ��	  �룺
 * 			_iMainChannelNo, ͨ����, ��ǰ����ptz��ͨ����
 * ��	  ����

 * �޸���־��
 * 			2012-11-15,����骣�Ϊ��ʵ�ֺϳ�ͨ������ס����ʱ����
 			͸��ͨ��ģʽ�¿�����ȷ����
 */


/*
 * �������ƣ�RockerAction
 * ��Ҫ����: 
 * ��	  �룺

 * ��	  ����

 * �޸���־��
 * 			2012-12-25,����ǿ��Ϊ�˼���ONVIF����ҡ��
 */

int RockerAction(PTZ_DATA* _pData, TPtzCtrProtocolData *_pPtzCtrl);
void ptz_DelProtocoltoDefalut();
//for decoder
td_s32 ptz_SetComAddr4Decoder(td_s32 _iComNo, td_u8 _u8Addr);

#endif  /*PTZ_H_*/


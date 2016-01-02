#ifndef _TD_VO_H
#define _TD_VO_H

#include "public_def.h"
#include "td_media.h"

typedef enum
{
	VO_BIND_VI,		//��VIͨ��
	VO_BIND_VDEC,	//�󶨽���ͨ��
	VO_BIND_PCI,	//��PCIͨ��
	VO_BIND_BT1120,
	VO_BIND_BUTT,
}TVOBindType;

typedef struct Td_VO
{
	td_s32 		m_iDispDev;		//VO���ڵ���ʾ�豸���
	td_s32		m_iVoChn;		//VOͨ����
	td_s32		m_iEzoom;		//��ǰ�Ƿ��ڵ��ӷŴ�״̬
	TRect		m_VoRect;		//VO����ʾ�豸�ϵľ�������
	TRect		m_DspArea;		//
	TVOBindType 	m_iBindType;		//VO�󶨵�����
	td_s32 		m_iBindChn;		//�󶨵�ͨ����
	td_s16		m_u16Clear;
	td_s16		m_iIsOnShow;
	pthread_mutex_t m_tLock;	// dxl 20120517
	
	td_s32  (*Bind)(void* _pThis,TVOBindType _iType,td_s32 _iChn,TRect* _stZoom);						//��һ����Ƶ����ͨ��
	/*
		����:	��VO���а󶨲���		
		
		����:	_iType		������
				_iChn		��ͨ����
				_stZoom		����зŴ�����ľ�������
							�����ָ��Ϊ������Ҫ���е��ӷŴ����
				
		����:	SUCCESS		�ɹ�
				FAILD		ʧ��
	*/
	
	td_s32  (*UnBind)(void* _pThis);							
	/*
		����:	���
		
		����:	��
				
		����:	SUCCESS		�ɹ�
				FAILD		ʧ��
	*/
	
	td_s32  (*AdjustArea)(void* _pThis,TRect* _stZoomRect);
	/*
		����:	�Ե��ӷŴ�������е���
		
		����:	_stZoomRect	��������
				
		����:	SUCCESS		�ɹ�
				FAILD		ʧ��
	*/

	td_s32 (*AdjustVoRect)(void* _pThis,TRect* _stZoomRect);
	/*
		����:	����VO��ʾ����
		
		����:	_stZoomRect	��������
				
		����:	SUCCESS		�ɹ�
				FAILD		ʧ��
	*/
	
	
	td_s32  (*SetVoFrameRate)(void* _pThis,td_s32 _iFrameRate);
	/*
		����:	����VO���֡��
		
		����:	_iFrameRate	֡��
				
		����:	SUCCESS		�ɹ�
				FAILD		ʧ��
	*/

	td_s32  (*VoChnCtrl)(void* _pThis,VO_CTRL_E _eCtrl);
	/*
		����:	voͨ����ʾ����
		����:	_s32VoDev	vo�豸��
				_s32VoChn	voͨ����
				_eCtrl		��ʾ������
							0 ʹ��
							1 ��ֹ
							2 ��ͣ
							3 �ָ�
							4 ����
							5 ����
							6 ��ʾ
							7 ���		
	*/

	td_s32 (*ShowNoVideo)(void* _pThis);
	/*
		����:	��ʾNo Video �ṩ������ͨ��ʹ��
	*/

	td_s32 (*SetVoChnField)(void* _pThis, td_s32 _s32Field);	
	

	td_s32 (*CopyFrame)(void* _pFrom, void* _pTo);

	
}Td_VO;

td_s32 TdVO_Init();

td_s32 TdVO_Uninit();

td_s32 TdVO_SetVODiff(td_s32  _s32VoDev,  td_s32 _s32Diff, td_s32 _s32VoDevIntfType, td_s32 _s32WbcBindVoDev);
/*
	����:������Ƶ����ֱ���
	����:	_s32VoDev	VO�豸���
			_s32Diff		VO�ֱ���
*/
td_s32 TdVO_SetVodevDspArea(td_s32 _s32VoDev, td_s32 _x, td_s32 _y, td_s32 _w, td_s32 _h);
td_s32 TdVO_SetVodevDspAreaEx(td_s32 _s32VoDev, td_s32 _s32VoChn,TRect * _ptRect);//ljj add 20130827
td_s32 TdVO_GetVODiff(td_s32  _s32VoDev,int* _iVideoWidth,int* _iVideoHeight);

Td_VO* CreateVO(int _iDispDev, TRect* _stVO);
Td_VO* CreateVO_Ex(int _iDispDev, TRect* _stVO, int _iLevel);	//zhangyi modify 20120207
/*
	����:	����һ��VOʵ��
			��������²���
			1��ΪVOʵ�������ڴ�
			2�����г�ʼ��������Ϊʵ���еĳ�Ա��������ֵ
			
	����:  ��

	����:	�ɹ�	����VOʵ����ָ��
			ʧ��	���ؿ�ָ��
*/

td_s32 DestroyVO(Td_VO* _tdVO);
/*
	����:	����һ��VOʵ��
		 	1������VOͨ��
		 	2���ͷ�VOʵ��ռ�õ��ڴ�
*/

td_s32 TdVO_DisableVoDev(td_s32 _s32VoDev);
/*
����VO��ʾ�豸
*/

td_s32 TdVO_SetVoDevImgSize(td_s32 _s32VoDev, td_s32 _iWidth, td_s32 _iHeight);

td_s32 TdVO_GetVoDevImgSize(td_s32 _s32VoDev, td_s32* _iWidth, td_s32* _iHeight);

td_s32 TdVo_Snapshot(Td_VO *_ptVo, strPicParam *_ptSnapshotParam);

#define TdVo_SetVoClearStat(_ptVo, _iClear)	((NULL != _ptVo) && (_ptVo->m_u16Clear = _iClear))
#define TdVo_GetVoClearStat(_ptVo, _piClear)	((*_piClear = 0, NULL != _ptVo) && (*_piClear = _ptVo->m_u16Clear))

#endif

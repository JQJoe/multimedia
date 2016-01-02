#ifndef _COM_H_
#define _COM_H_

#include "td_types.h"

typedef void (*ComDataProcCallback)(td_s32 _iComId, td_s32 _iDataLen, td_u8 *_pcData);

// ��ʼ������ģ��
// ����˵��:
// 	_iComCnt : ������
//	_strPaths[] : ������·������ /dev/xxx Ϊ����Ĵ���, /pci/x/y���Ƭx�ĵ�y������
// ComDataProcCallback : ���ڽ������ݻص�
td_s32 com_Init(td_s32 _iComCnt, td_u8 *_strPaths[], TComAttribute _ptAttr[], td_s32 _iRead[], ComDataProcCallback _CallBack);

// ����ģ��ȥ��ʼ������
td_s32  com_Uninit();

// ��ȡ����ʵ��
TComInstance *com_GetInstance(td_s32 _iComdId);
//��ȡ�մ���ʵ��
TComInstance *com_GetNullInstance();

td_s32 com_SetBaudRateOfCPLD(td_s32 _iUardId, td_s32 _iSpeed);

//add by zhuangzhibing 20120218
//��ʼ��pl2303������usb����
td_s32 comInitusbserial(int _iRead,int _iComNum,td_u8 *_strPaths, TComAttribute *_ptAttr);
//����ʼ������
td_s32 comUinitusbserial(int _iComNum);
//���ô���ʵ��
td_s32 com_SetInstance(td_s32 _iComdId,TComInstance *_ptCom);
//add end

#endif


#ifndef __VCA_USER_DATA_H_
#define __VCA_USER_DATA_H_

#include "public_def.h"
#include "vca_head.h"

#define		MAX_SAVE_TARGET_NUM			16
#define     USERDATA_FLAG_GPS            	(0xFED4)       	                    //�û������и���GPS��Ϣ�ı�ʶ
#define     USERDATA_FLAG_USER_DEFINE       (0x0001)       	                    //�û������и����û��Զ�������
#define     USERDATA_MAX_LENGTH             1024
#define     FLAG_VIRTUAL_FRAME_HEAD			0x02000000
#define     FLAG_VIRTUAL_FRAME_TAIL			0x0123ABCD


#define     USERDATA_FLAG_HEADER         	{ 0x00, 0x00, 0x00, 0x01, 0x06, 0xf0 }	//H264�������û����ݱ�ʾ
#define     USERDATA_FLAG_NEW_DATA_HEADER 	{'T', 'D', 'S', 'T'}                    //�����������豸�û����ݵı�ʶ
#define     USERDATA_FLAG_OSD            	(0xFED1)         	                //�û������и����ַ����ӵı�ʶ
#define     USERDATA_FLAG_VCA            	(0xFED2)          	                //�û������и������ܷ����ı�ʶ
#define     USERDATA_FLAG_FRAMETIME      	(0xFED3)                                //�û������и�������ʱ��ı�ʶ
#define     USERDATA_FLAG_GPS            	(0xFED4)       	                        //�û������и���GPS��Ϣ�ı�ʶ
#define     USERDATA_FLAG_USER_DEFINE           (0x0001)       	                        //�û������и����û��Զ�������


/////////////////////////////////H264�û����ݽṹͷ��/////////////////////////////////////////
typedef struct TUserDataHeader
{
	unsigned char ucFlag[4];           //TDST�������������еĸ���OSD��Ϣ�����ܷ�����Ϣ���ֿ���
	unsigned short uiSegmentCount; //������
	unsigned short uiDataLen;      //�����ܳ��ȣ��û������ܳ��Ȱ�����1����n���ݵĳ���֮�ͣ���������У���롱�����������������û������ܳ��ȡ��ĳ���֮�͡���
}TUserDataHeader,*pTUserDataHeader;

typedef struct TSegmentHeader
{
	unsigned short sFlag;           //
	unsigned short uiDataLen;      //�����ܳ��ȣ��û������ܳ��Ȱ�����1����n���ݵĳ���֮�ͣ���������У���롱�����������������û������ܳ��ȡ��ĳ���֮�͡���
}TSegmentHeader,*pTSegmentHeader;


int rec_vca_SetRuleparam(TVcaEventType _eVcaEventType,void *_pstVcaParam,time_t _starttime);
int rec_vca_GetVcaMsg(IN char *_strName, OUT int *_iCnt, OUT vca_TimeSegment *_ptTimeSegment, IN int _iLen);
#endif

/*************************************************************
*george(393) transplant&modify for this linux version  2006.9.1
*
**************************************************************/
#ifndef _USER_H_
#define _USER_H_

#include "td_types.h"

//#define USER_BEGIN				1248
//#define LENGTH_USER				268

//�û�Ȩ��
#define AUT_BROWSE				1		//���������Ƶ		
#define AUT_BROWSE_CTRL			2		//�������Ƶ�����豸���п���	
#define AUT_BROWSE_CTRL_SET		3		//�����Ƶ�������豸���޸����ò���
#define AUT_ADMIN				4		//�����û�����0���û�Ϊ�����û���
										//�û���ΪAdmin�Ҳ����޸�,��ʼ����Ϊtiandy��
										//�ɽ����û�����ӡ�ɾ����Ȩ���޸ĵȲ���

//Leeon Tonie add for Tiandy-Dvr IP Filter
#define IP_FILTER_ALLOW				2
#define IP_FILTER_FORBID			1
#define IP_FILTER_NONE				0
#define USER_ALL_CHAL_RIGHT	0XFFFFFFFF


/*
void InitUser();
//int GetUserAuthority(char* _cUserName);
*/
int  LoadUserList();
/*
 * ��������:LoadUserList
 * ��Ҫ����:���л���û��б�ͬʱ��ʼ�����ڱ����û�IP��ַ��StringList
 * ��	 ��:
 *			��
 * ��	 ��:
 *			0,�ɹ�
 * 			<0,ʧ��
 * �޸���־:
 *			2008-10-28,������������
 */

int UserLogon(char* _cUserName,char* _cPassWord,td_u32 _u32IP,int _iAuthority,int _iNetMode, void* _cthis, td_u32 _u32Socket);
/*
 * ��������:UserLogon
 * ��Ҫ����:�����û���¼
 * ��	 ��:
 *			_cUserName,�û���
 *			_cPassWord,����
 *			_u32IP,��������socket/IP��ַ
 *			_iAuthority,�û�Ȩ��
 *			_iNetMode,����ģʽ:1,TCP 0,UDP
 *			_cthis,�������ӽڵ�
 *			_u32Socket,socket��,dxl 20110307����Ӵ˲���ʹuserģ�鲻����pconnect
 * ��	 ��:
 *			0,�ɹ�
 * 			-2,�Ѵ��û�������
 *			-3,�Ƿ�IP(��IP�ѱ�����)
 *			-4,�û������ڻ����벻��ȷ
 * �޸���־:
 *			2008-10-28,������������
 */	
 
int UserLogoff(char* _cUserName,int _cIP);
/*
 * ��������:UserLogoff
 * ��Ҫ����:ע�������û���¼
 * ��	 ��:
 *			_cUserName,�û���
 *			_cIP,��������socket/IP��ַ
 * ��	 ��:
 *			0,�ɹ�
 * 			-1,ʧ��,��IP��ַ���û�δ��¼
 * �޸���־:
 *			2008-10-28,������������
 */	
 
int  AddUser(char* _cUserName,char* _cPwd,int _iAuthority);
/*
 * ��������:AddUser
 * ��Ҫ����:����û�
 * ��	 ��:
 *			_cUserName,�û���
 *			_cPwd,����
 *			_iAuthority,Ȩ��
 * ��	 ��:
 *			0,�ɹ�
 * 			-1,���û����Ѵ���
 *			-2,�û����Ѵ�����
 *			-3,�û���������Ƿ�(������󳤶ȣ�������ĸ������������ַ�)
 * �޸���־:
 *			2008-10-28,������������
 */	

int  DelUser(char* _cUserName);
/*
 * ��������:DelUser
 * ��Ҫ����:ɾ���û�
 * ��	 ��:
 *			_cUserName,�û���
 * ��	 ��:
 *			0,�ɹ�
 * 			-1,���û���������
 *			-2,�����û�������ɾ��
 * �޸���־:
 *			2008-10-28,������������
 */	
 
int  ModifyPwd(char* _cUserName,char* _cPwdOld,char* _cPwdNew);
/*
 * ��������:ModifyPwd
 * ��Ҫ����:�޸��û�����
 * ��	 ��:
 *			_cUserName,�û���
 *			_cPwdOld,ԭ����
 *			_cPwdNew,������
 * ��	 ��:
 *			0,�ɹ�
 * 			-1,���û���������
 *			-2,ԭ���벻��ȷ
 *			-3,�����벻�Ϸ�(������������/������ĸ������������ַ�)
 * �޸���־:
 *			2008-10-28,������������
 */
 
td_u8 GetUserNum();
/*
 * ��������:GetUserNum
 * ��Ҫ����:��ȡ�û���
 * ��	 ��:
 *			��
 * ��	 ��:
 *			�û���
 * �޸���־:
 *			2008-10-28,������������
 */
 
int GetUserInfo(td_u8 _u8UserSerial,char _cUserName[LENGTH_USER_NAME],char _cPassword[LENGTH_PASSWORD],int* _iAuthority);
/*
 * ��������:GetUserInfo
 * ��Ҫ����:�����û������ȡĳ���û�����Ϣ
 * ��	 ��:
 *			_u8UserSerial,�û����
 *			_cUserName,�����û���			
 *			_cPassword,�����û�����
 *			_iAuthority,�����û�Ȩ��
 * ��	 ��:
 *			0,�ɹ�
 * 			-1,�û���Ų��Ϸ�
 * �޸���־:
 *			2008-10-28,������������
 */
 
int  SetMaxConUser(int _iMaxConUser);
/*
 * ��������:SetMaxConUser
 * ��Ҫ����:�����������������
 * ��	 ��:
 *			_iMaxConUser,������������û���
 * ��	 ��:
 *			0,�ɹ�
 * 			-1,�û���Ų��Ϸ�
 * �޸���־:
 *			2008-10-28,������������
 */
 
int  GetMaxConUser();
/*
 * ��������:GetMaxConUser
 * ��Ҫ����:��ȡ�������������
 * ��	 ��:
 *			��
 * ��	 ��:
 *			������������û���
 * �޸���־:
 *			2008-10-28,������������
 */
 
int IsUserLogon(td_u32 _u32IP);
/*
 * ��������:IsUserLogon
 * ��Ҫ����:�ж�ĳ���û��Ƿ��ѵ�¼
 * ��	 ��:
 *			_u32IP,��������socket/IP��ַ
 * ��	 ��:
 *			1,�ѵ�¼
 * 			0,δ��¼
 * �޸���־:
 *			2008-10-28,������������
 */

int ModifyLevel(char* _pcUser, int iLevel);
/*
 * ��������:ModifyLevel
 * ��Ҫ����:�޸��û�Ȩ��
 * ��	 ��:
 *			_pcUser,�û���
 *			iLevel,�û�Ȩ��
 * ��	 ��:
 *			0,�ɹ�
 *			-1,���û�������
 * 			-2,�������޸�Admin�û���Ȩ��
 * �޸���־:
 *			2008-10-28,������������
 */
 
int LocalLogOn(td_u8* _pcName, td_u8* _pcPass);
/*
 * ��������:LocalLogOn
 * ��Ҫ����:�����û���¼
 * ��	 ��:
 *			_pcName,�û���
 *			_pcPass,����
 * ��	 ��:
 *			-1,�Ѿ��������û���¼
 *			-2,���벻��ȷ
 *			-3,�û�������ȷ
 *			0,��¼�ɹ�
 * �޸���־:
 *			2008-10-28,������������
 */
 
int LocalLogOff(td_u8 * _pcName);
/*
 * ��������:LocalLogOff
 * ��Ҫ����:�����û��ǳ�
 * ��	 ��:
 *			_pcName,�û���
 * ��	 ��:
 *			-1,�޵����û�
 *			-2,�ѵ���Ĳ��Ǹ��û�
 *			0,�ǳ��ɹ�
 * �޸���־:
 *			2008-10-28,������������
 */
 
int LocalGetNowUser(td_u8* _pcName);
/*
 * ��������:LocalGetNowUser
 * ��Ҫ����:��ȡ�����ѵ�¼���û���
 * ��	 ��:
 *			_pcName,�����û���
 * ��	 ��:
 *			-1,����Ϊ�ջ��ߵ�ǰ���û���¼
 *			0,�ɹ�
 * �޸���־:
 *			2008-10-28,������������
 */
 
int GetUserLevel(td_u8* _pcName);
/*
 * ��������:GetUserLevel
 * ��Ҫ����:��ȡ�û�Ȩ��
 * ��	 ��:
 *			_pcName,�û���
 * ��	 ��:
 *			-1,�����޴��û�
 *			-2,�Ƿ�����
 *			>0,���û���Ȩ��
 * �޸���־:
 *			2008-10-28,������������
 */

td_u8* GetUserPwd(const td_u8* _pcUserName);
/*
 * ��������:GetUserPwd
 * ��Ҫ����:��ȡ�û�����
 * ��	 ��:
 *			_pcUserName,�û���
 * ��	 ��:
 *			NULL,��ȡʧ��
 *			�ǿ�,�û�����
 * �޸���־:
 *			2008-10-28,������������
 */

int UpdateFtpuser(void);
/*
 * ��������:UpdateFtpuser
 * ��Ҫ����:���û��б�ͬ����FTP
 * ��	 ��:
 *			��
 * ��	 ��:
 *			-1,ͬ��ʧ��
 *			0,ͬ���ɹ�
 * �޸���־:
 *			2008-10-28,������������
 */

td_s32 SetExpectIp(td_u32 _uiIp, td_s32 _uiMask);
/*
 * ��������:SetExpectIp
 * ��Ҫ����:��������IP
 * ��	 ��:
 *			_uiIp,����IP
 *			_uiMask,����IP����
 * ��	 ��:
 *			-1,�������Ϸ�
 *			-2,���������ļ�ʧ��
 *			0,�ɹ�
 * �޸���־:
 *			2008-10-28,������������
 */
 
td_s32 GetExpectIp(td_u32* _puiIp, td_u32* _puiMask);
/*
 * ��������:GetExpectIp
 * ��Ҫ����:��ȡ����IP
 * ��	 ��:
 *			_puiIp,��������IP
 *			_puiMask,��������IP����
 * ��	 ��:
 *			-1,�����Ƿ�
 *			0,�ɹ�
 * �޸���־:
 *			2008-10-28,������������
 */
td_s32 SetIpFilter(td_s32 _iType, td_s32 _iNum, td_u32* _puiList);
/*
 * ��������:SetIpFilter
 * ��Ҫ����:����IP������/������
 * ��	 ��:
 *			_iType,IP_FILTER_FORBID,������/IP_FILTER_ALLOW,������/IP_FILTER_NONE,������
 *			_iNum,��������(IP��)
 *			_puiList,����
 * ��	 ��:
 *			-1,�����Ƿ�
 *			-2,���������ļ�ʧ��
 *			0,�ɹ�
 * �޸���־:
 *			2008-10-28,������������
 */
 
td_s32 GetIpFilter(td_s32* _piType, td_s32* _piNum, td_u32* _puiList);
/*
 * ��������:GetIpFilter
 * ��Ҫ����:��ȡIP������/������
 * ��	 ��:
 *			_piType,����IP_FILTER_FORBID,������/IP_FILTER_ALLOW,������/IP_FILTER_NONE,������
 *			_piNum,������������(IP��)
 *			_puiList,��������
 * ��	 ��:
 *			-1,�����Ƿ�
 *			0,�ɹ�
 * �޸���־:
 *			2008-10-28,������������
 */

int  GetConUserNum();
/*
 * ��������:GetConUserNum
 * ��Ҫ����:��ȡ�ѵ�¼�Ŀͻ�����Ŀ
 * ��	 ��:
 *			��
 * ��	 ��:
 *			�ѵ�¼�Ŀͻ�����
 * �޸���־:
 *			2010-02-03,������������
 */
 
unsigned int GetConUserIp(int _iUserNo);
/*
 * ��������:GetConUserIp
 * ��Ҫ����:��ȡ�ѵ�¼�Ŀͻ���IP��ַ
 * ��	 ��:
 *			_iUserNo, �ѵ�¼���û����, 0~MAX_CLIENT
 * ��	 ��:
 *			�ѵ�¼�ͻ��˵�IP
 * �޸���־:
 *			2010-02-03,������������
 */
 
void* GetConUserPoint(int _iUserNo);
/*
 * ��������:GetConUserPoint
 * ��Ҫ����:��ȡ�ѵ�¼�Ŀͻ���socket
 * ��	 ��:
 *			_iUserNo, �ѵ�¼���û����, 0~MAX_CLIENT
 * ��	 ��:
 *			�ѵ�¼�ͻ��˵�socket(PCONNECT)
 * �޸���־:
 *			2010-02-03,������������
 */



int user_JudgeRight(unsigned int _iSocket, int _iOperate, unsigned int _u32ChnlBit);
int user_GetRight(IN char* _strUserName, int iAuthority, unsigned int *_pu32ChnlBit);
int user_SetRight(char* _strUserName, int _iAuthority, unsigned int _u32ChnlBit);

td_s32 GetUserName(td_s32 _s32UserNo, char cUserName[LENGTH_USER_NAME]);
int GetUserRight(char *_pcUserName, int *_iAuthority); 
//zhangshengusr
TIPFilter_ex *GetIPFilter();
NetUser *GetNetUser();

td_s32 GetUserInfoOfWritingLog(int _socket, char *_pcstrUserName, int _iMaxUserNameLen);

td_s32 GetUserKeyIp(int _socket, char _ckey[USER_KEY_LEN], unsigned int *_Ip);
#define GetUserKey(_socket, _ckey)	GetUserKeyIp(_socket, _ckey, NULL)
td_s32 GetUserKeyStat(int _socket, char _ckey[USER_KEY_LEN]);
int userCreatekey(td_u32 _u32IP, OUT char _cKey[USER_KEY_LEN]);
int UserSetLogonDecodeCallBack(LogonDecodeCallBack _func);

td_s32 VerifyUserInfo(td_char* _cUserName, td_char* _cPassWord);
void *GetConFormSocket(int _socket);

#endif /*_USER_H_*/

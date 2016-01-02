/*******************************************************************
�ļ���	:td_errno.h
��˾	:������ΰҵ����Ƽ����޹�˾
������	:������
��������:2008-8-28
��Ҫ����:TD�����붨��
�޸ļ�¼:2008-08-28,������������
		 2009-10-29,�������������ģ�����
        
******************************************************************/

#ifndef TD_ERRNO_H_
#define TD_ERRNO_H_

#define TD_SUCCESS						0				//�ɹ�
#define TD_FAILURE						(-1)			//ʧ��
#define TD_TRUE							1				//��
#define TD_FALSE						0				//��
#define TD_ENABLE						1				//ʹ��
#define TD_DISABLE						0				//��ʹ��

//�洢ģ�������
#define	ERR_REC_BASE					1000			//�洢ģ���������ʼ��
#define ERR_REC_SUCCESSFUL				ERR_REC_BASE+1	//��ʼ¼��ɹ�
#define ERR_REC_OTHER_RECORDING 		ERR_REC_BASE+2	//��ǰ��ͨ�����ڽ�����������¼��,�������¼��
#define ERR_REC_DISK_FULL				ERR_REC_BASE+3	//������
#define ERR_REC_NO_DISK					ERR_REC_BASE+4	//�޿��ô���
#define ERR_REC_DISABLED_TYPE			ERR_REC_BASE+5	//��¼������δʹ��
#define ERR_REC_PORT_DISABLED			ERR_REC_BASE+6	//�˿ڱ���¼��δʹ��
#define ERR_REC_TIMING_DISABLED			ERR_REC_BASE+7	//����¼��δʹ��
#define ERR_REC_NONE_RECORDING			ERR_REC_BASE+8	//��ǰδ��¼��
#define ERR_REC_WRONG_TYPE				ERR_REC_BASE+9	//ֹͣ¼������Ͳ���ȷ
#define ERR_REC_WRONG_PARAM				ERR_REC_BASE+10	//����Ĳ������������ںϷ���ȡֵ��Χ
#define ERR_REC_OPEN_DB_FAILED			ERR_REC_BASE+11	//�����ݿ��ļ�ʧ��
#define ERR_REC_CREATE_TABLE_FAILED		ERR_REC_BASE+12	//����������ʧ��
#define ERR_REC_NO_DBFILE				ERR_REC_BASE+13 //�����ݿ��ļ�
#define ERR_REC_CLOSE_DB_FAILED			ERR_REC_BASE+14 //�ر����ݿ�ʧ��
#define ERR_REC_WRITE_INDEX_FAILED		ERR_REC_BASE+15 //д�������ļ�ʧ��
#define ERR_REC_OPEN_DEVICEFILE_FAILED	ERR_REC_BASE+16 //��Ӳ���豸�ļ�ʧ��
#define ERR_REC_IOCTL_FAILED			ERR_REC_BASE+17	//IO����ʧ��
#define ERR_REC_READ_MBR_FAILED			ERR_REC_BASE+18	//��MBRʧ��
#define ERR_REC_LEGAL_MBR				ERR_REC_BASE+19	//�Ƿ���MBR
#define ERR_REC_OPEN_INTERFILE_FAILED	ERR_REC_BASE+20	//�򿪽����ļ�ʧ��
#define ERR_REC_DELETE_PART_FAILED		ERR_REC_BASE+21	//ɾ������ʧ��
#define ERR_REC_FDISK_FAILED			ERR_REC_BASE+22	//����ʧ��
#define ERR_REC_QUERY_INDEX_FAILED		ERR_REC_BASE+23 //��ѯ�����ļ�ʧ��
#define ERR_REC_QUERY_COUNT_FAILED		ERR_REC_BASE+24	//��ȡ��ѯ�������ʧ��
#define ERR_REC_GET_TABLE_FAILED		ERR_REC_BASE+25 //ִ��sqlite3_get_tableʧ��
#define ERR_REC_NONEXIST_NAME			ERR_REC_BASE+26 //�ļ���������
#define ERR_REC_NOT_DIRRECTORY			ERR_REC_BASE+27 //����Ŀ¼
#define ERR_REC_UMOUNT_NFS_FAILED		ERR_REC_BASE+28 //ж��NFSʧ��
#define ERR_REC_MOUNT_NFS_FAILED		ERR_REC_BASE+29	//����NFSʧ��
#define ERR_REC_NO_RECORD_SPACE			ERR_REC_BASE+30	//¼��ռ䲻�㣬��������ץ��
#define ERR_REC_NO_SNAP_SPACE			ERR_REC_BASE+31	//ץ�Ŀռ䲻��
#define ERR_REC_VALID_FRAME				ERR_REC_BASE+32 //�Ƿ���֡ͷ
#define ERR_REC_OPEN_FILE_FAILED		ERR_REC_BASE+33 //���ļ�ʧ��
#define ERR_REC_ALARM_DELAY				ERR_REC_BASE+34	//תΪ������ʱ¼��
#define ERR_REC_NO_INDEX_PATH			ERR_REC_BASE+35 //�������ļ�
#define ERR_REC_TABLE_NOT_EXISTED		ERR_REC_BASE+36	//������
#define ERR_REC_SOME_RECORDING			ERR_REC_BASE+37	//��ͨ������¼��
#define ERR_REC_INVALID_FILE_NAME		ERR_REC_BASE+38 //�Ƿ��ļ���
#define ERR_REC_MALLOC_ERROR			ERR_REC_BASE+39 //mallocִ��ʧ��
#define ERR_REC_WRITE_FILE_ERROR		ERR_REC_BASE+40 //д�ļ�ʧ��
#define ERR_REC_NOT_I_FRAME				ERR_REC_BASE+41	//����I֡
#define ERR_REC_NO_SUCH_INDEX			ERR_REC_BASE+42 //ָ����¼������
#define ERR_REC_REBUILDING_INDEX		ERR_REC_BASE+43 //�����ؽ�����
#define ERR_REC_NOT_EMPTY_DIR			ERR_REC_BASE+44	//Ŀ¼��Ϊ��
#define ERR_REC_READ_FILE_ERROR			ERR_REC_BASE+45	//���ļ�����
#define ERR_REC_MKDIR_FAILED			ERR_REC_BASE+46	//����Ŀ¼ʧ��
#define ERR_REC_USING_DISK				ERR_REC_BASE+47	//��ͼ��ʽ�����������ʹ�õĴ���
#define ERR_REC_SYSTEM_ERROR			ERR_REC_BASE+48	//ϵͳ�����쳣�˳�
#define ERR_REC_WRONG_DISK				ERR_REC_BASE+49	//���̲����ã��������;����ȷ
#define ERR_REC_OTHER_FORMATING			ERR_REC_BASE+50 //���ڸ�ʽ����������
#define ERR_REC_NO_IDLE_POS				ERR_REC_BASE+51	//û�п���λ��(һ���ڹ���USB�豸��ʱ��)
#define ERR_REC_TOO_MANY_USERS			ERR_REC_BASE+52	//VOD�Ѵ����������
#define ERR_REC_BACKUP_TO_USB_ONLY		ERR_REC_BASE+53	//���α����ļ�ֻ��������U����
#define ERR_REC_NOT_ALLOWED_BACKUP		ERR_REC_BASE+54	//SATA0����������Ϊ������
#define ERR_REC_NO_FIRST_SATA			ERR_REC_BASE+55	//SATA0������
#define ERR_REC_FILES_NOT_READY			ERR_REC_BASE+56	//��¼�ļ���û��׼����
#define ERR_REC_RECORDER_NOT_READY		ERR_REC_BASE+57	//��¼����û��׼����
#define ERR_REC_DVD_DISK_NOT_READY		ERR_REC_BASE+58	//��¼����û�з�����̻��߹��̲����á�
#define ERR_REC_HUGE_SIZE_TO_BURN		ERR_REC_BASE+59 //����¼�ļ��ܴ�С����4200M��������ѡ��
#define ERR_REC_INVALID_RECORD_FILE		ERR_REC_BASE+60	//�Ƿ���¼���ļ�
#define ERR_REC_BURNING_FORBIDSETTING   ERR_REC_BASE+61 //��¼�����в��������¼����Բ�������
#define ERR_REC_PACKING                 ERR_REC_BASE+62  //���ڴ�������Ժ�
#define ERR_REC_NO_CHANNEL_SELECT      	ERR_REC_BASE+63  //δѡ��ͨ��
#define ERR_REC_NO_FILE_IN_DVD          ERR_REC_BASE+64   //DVR�����ļ��б�
#define ERR_REC_DEVICE_FAIL             ERR_REC_BASE+65   //�豸���ϣ��޷�������¼����
#define ERR_REC_STOP_MANUAL				ERR_REC_BASE+66   //��Щͨ�����ڿ�¼���޷�ֹͣ�ֶ�¼��
#define ERR_REC_INTERLACE               ERR_REC_BASE+67   //CD1��CD2��ѡͨ�����ظ���������ѡ��
#define ERR_REC_BURNING_FORMAT			ERR_REC_BASE+68	//��¼�����в������ʽ��Ӳ��!
#define ERR_REC_REINDEX_FORMAT			ERR_REC_BASE+69	//�ؽ����������в������ʽ��Ӳ��!
#define ERR_REC_LACK_OF_MEMORY			ERR_REC_BASE+70	//�ڴ治��
#define ERR_REC_DEL_RECING_FAILED		ERR_REC_BASE+71	//�ڴ治��
#define ERR_REC_NOT_ALLOWED_READONLY	ERR_REC_BASE+72
#define ERR_REC_FAILED					ERR_REC_BASE+99//ʧ��
#define ERR_RTBURN_FINISHED				ERR_REC_BASE+100//ʵʱ��¼����
#define ERR_REC_MAX_NUM_TO_BURN			ERR_REC_BASE+101 //����¼�ļ��ܸ�������512��������ѡ��
#define ERR_REC_DVD_DISK_NOT_EMPTY		ERR_REC_BASE+102	//��¼�����й��̣�����������̱�������(�չ���)

//����ģ�������
#define ERR_ALM_BASE					2000			//����ģ����������
#define ERR_ALM_SUCCESSFUL				ERR_ALM_BASE+1	//�����ɹ�
#define ERR_ALM_WRITE_COM_FAILED		ERR_ALM_BASE+2	//�򴮿�д����ʧ��
#define ERR_ALM_WRONG_PARAM				ERR_ALM_BASE+3	//����Ĳ���
#define ERR_ALM_OPEN_FILE_ERROR 		ERR_ALM_BASE+4	//���ļ�����
#define ERR_ALM_READ_FILE_ERROR			ERR_ALM_BASE+5	//���ļ�����
#define ERR_ALM_WRITE_FILE_ERROR		ERR_ALM_BASE+6	//д�ļ�����
#define ERR_ALM_SYSTEM_ERROR			ERR_ALM_BASE+7	//ִ��ϵͳ���ô���
#define ERR_ALM_MALLOC_ERROR			ERR_ALM_BASE+8	//MALLOC�����ڴ����
#define ERR_ALM_NO_SUCH_FILE			ERR_ALM_BASE+9	//�ļ�������
#define ERR_ALM_MEMMAP_FAILED			ERR_ALM_BASE+10	//memmapʧ��(�ڼ�ⱨ������˿�ʱ)
#define ERR_ALM_FAILED					ERR_ALM_BASE+999//����ʧ��

//PTZģ�������
#define ERR_PTZ_BASE					3000			//PTZģ�������Ļ���
#define ERR_PTZ_SUCCESSFUL				ERR_PTZ_BASE+1	//�����ɹ�
#define ERR_PTZ_WRONG_PARAM				ERR_PTZ_BASE+2	//����Ĳ���
#define ERR_PTZ_OPEN_FILE_ERROR			ERR_PTZ_BASE+3	//���ļ�ʧ��
#define ERR_PTZ_READ_FILE_ERROR			ERR_PTZ_BASE+4	//���ļ�ʧ��
#define ERR_PTZ_WRITE_FILE_ERROR		ERR_PTZ_BASE+5	//д�ļ�ʧ��
#define ERR_PTZ_UNKNOWN_PROTOCOL		ERR_PTZ_BASE+6	//�豸��֧�ָ�Э�飬���޷�ʶ��
#define ERR_PTZ_MAKE_CODE_ERROR			ERR_PTZ_BASE+7	//�������ʧ��
#define ERR_PTZ_WRITE_COM_FAILED		ERR_PTZ_BASE+8	//�򴮿�д����ʧ��
#define ERR_PTZ_UNUSEABLE_FUNCTION		ERR_PTZ_BASE+9	//δ���õĹ���
#define ERR_PTZ_USING_PROTOCOL			ERR_PTZ_BASE+10	//��Э�����ڱ�ʹ��
#define ERR_PTZ_MAX_PRTNUM				ERR_PTZ_BASE+11	//�Ѵ��豸֧�ֵ�PTZЭ��������
#define ERR_PTZ_FAILED					ERR_PTZ_BASE+999//����ʧ��

//��־ģ�������
#define	ERR_LOG_BASE					4000			//��־ģ����������
#define ERR_LOG_SUCCESSFUL				ERR_LOG_BASE+1 	//�����ɹ�
#define ERR_LOG_WRONG_PARAM				ERR_LOG_BASE+2	//����Ĳ���
#define ERR_LOG_FAILED					ERR_LOG_BASE+999//����ʧ��

//ϵͳģ�������
#define ERR_SYS_BASE					5000			//ϵͳģ����������
#define ERR_SYS_SUCCESSFUL				ERR_SYS_BASE+1	//�����ɹ�
#define ERR_SYS_WRONG_PARAM				ERR_SYS_BASE+2	//����Ĳ���
#define ERR_SYS_OPEN_FILE_ERROR			ERR_SYS_BASE+3	//���ļ�����
#define ERR_SYS_WRITE_FILE_ERROR		ERR_SYS_BASE+4	//д�ļ�����
#define ERR_SYS_READ_FILE_ERROR			ERR_SYS_BASE+5	//���ļ�����
#define ERR_SYS_IOCTL_ERROR				ERR_SYS_BASE+6	//ioctl����
#define ERR_SYS_NO_USB					ERR_SYS_BASE+7	//��USB�豸
#define ERR_SYS_NO_FTP					ERR_SYS_BASE+8	//�޷����ӵ�ָ��FTPվ��
#define ERR_SYS_NO_FILE					ERR_SYS_BASE+9	//�Ҳ����������ļ�
#define ERR_SYS_OTHER_UPDATING			ERR_SYS_BASE+10	//�����ͻ�����������
#define ERR_SYS_GET_FILE_FAILED			ERR_SYS_BASE+11	//��FTPվ���ȡ�����ļ�ʧ��
#define ERR_SYS_ALPHA_DIGIT_ONLY		ERR_SYS_BASE+12 //�ļ�����ֻ������ĸ������
#define ERR_SYS_FILE_EXIST				ERR_SYS_BASE+13	//�������ݿ��Ѿ�����
#define ERR_SYS_FAILED					ERR_SYS_BASE+999//����ʧ��

//������ 091029 �쳣����ģ�������
#define ERR_EXCP_BASE					6000			//�쳣����ģ����������
#define ERR_EXCP_SUCCESSFUL				TD_SUCCESS		//�ɹ�
#define ERR_EXCP_FAILED					TD_FAILURE		//ʧ��
#define ERR_EXCP_WRONG_PARAM			ERR_EXCP_BASE+1	//��������
#define ERR_EXCP_WRITE_CONFIG			ERR_EXCP_BASE+2	//д�����ļ�ʧ��
#define ERR_EXCP_READ_CONFIG			ERR_EXCP_BASE+3	//�������ļ�ʧ��
#define ERR_EXCP_CREATE_THREAD			ERR_EXCP_BASE+4	//�����߳�ʧ��

//������ 091101 ���ڹ���ģ�������
#define ERR_COM_BASE					7000			//���ڹ���ģ����������
#define ERR_COM_SUCCESSFUL				TD_SUCCESS		//�ɹ�
#define ERR_COM_FAILED					TD_FAILURE		//ʧ��
#define ERR_COM_WRONG_PARAM				ERR_COM_BASE+1	//�����������
#define ERR_COM_TOO_MUCH_DATA			ERR_COM_BASE+2	//���������ݹ���
#define ERR_COM_OPEN_ERROR				ERR_COM_BASE+3	//�򿪴��ڴ���
#define ERR_COM_CLOSE_ERROR				ERR_COM_BASE+4	//�رմ��ڴ���
#define ERR_COM_READ_ERROR				ERR_COM_BASE+5	//�����ڴ���
#define ERR_COM_WRITE_ERROR				ERR_COM_BASE+6	//д���ڴ���
#define ERR_COM_CALL_ERROR				ERR_COM_BASE+7	//���õײ㺯������
#define ERR_COM_CREATE_THREAD_ERROR		ERR_COM_BASE+8	//�����߳�ʧ��

//��ƽ 091229 Ԥ��������
#define ERR_VIEW_BASE					10000
#define ERR_VIEW_SUCCESSFUL				TD_SUCCESS		//�ɹ�
#define ERR_VIEW_FAILED					TD_FAILURE		//ʧ��
#define ERR_VIEW_SET_LIMIT_VO			ERR_VIEW_BASE+1	//Ԥ������VO��Ŀ����33

//������ 100311 ý��������
#define ERR_MEDIA_BASE					11000
#define ERR_MEDIA_SUCCESSFUL			TD_SUCCESS			//�ɹ�
#define ERR_MEDIA_FAILED				TD_FAILURE			//ʧ��
#define ERR_MEDIA_BIT_FRAME_BALANCE		ERR_MEDIA_BASE+1	//С֡�ʴ����ʴ���
#define ERR_MEDIA_TOTAL_BANDWIDTH		ERR_MEDIA_BASE+2	//ͨ���ܴ�������
#define ERR_MEDIA_AREA_CONFLICT			ERR_MEDIA_BASE+3	//�ַ����������ص�
#define ERR_MEDIA_WRONG_STREAM_TYPE		ERR_MEDIA_BASE+4	//��֧�ֵ�ý��������
#define ERR_MEDIA_UNKNOWN_AUDIO_TYPE	ERR_MEDIA_BASE+5	//��֧�ֵ���Ƶ�����ʽ
#define ERR_MEDIA_TALK_IS_OPEN			ERR_MEDIA_BASE+6	//�Խ�ʱ�������޸���Ƶ�����ʽ
#define ERR_MEDIA_VCA_UNSUPPORT_SIZE	ERR_MEDIA_BASE+9	//����ͨ�����ܷ�������Ŀǰ��֧��CIF���·ֱ���
#define ERR_MEDIA_VCA_VDEC_VENC_FAILED  ERR_MEDIA_BASE+10   //����ͨ���������ܷ��������ͨ��ʧ��

//Cheng 100407 ������ش�����
#define ERR_NETWORK_BASE                12000
#define ERR_NETWORK_SUCCESSFUL          TD_SUCCESS          ///
#define ERR_NETWORK_FAILED              TD_FAILURE
#define ERR_NETWORK_IP_ALIMIT           ERR_NETWORK_BASE+1    //�����ַ ��һ������1-223֮��
#define ERR_NETWORK_IP_MASK             ERR_NETWORK_BASE+2   //����mask��IP��ϲ���ȷ
#define ERR_NETWORK_IP_INVALID          ERR_NETWORK_BASE+3   //IP���ò��Ϸ�������255
#define ERR_NETWORK_NTPPARA_INVALID     ERR_NETWORK_BASE+4   //NTP�������ò��Ϸ�
#define ERR_NETWORK_NTPINTVAL_INVALID   ERR_NETWORK_BASE+5   //NTPУʱ������ò��Ϸ�
#define ERR_NETWORK_OLD_PACKET      	ERR_NETWORK_BASE+6
#define ERR_NETWORK_NEW_PACKET			ERR_NETWORK_BASE+7
#define ERR_NETWORK_IP_GATEWAY          ERR_NETWORK_BASE+8    //IP��gateway����ͬһ����
#define ERR_NETWORK_MASK_INVALID        ERR_NETWORK_BASE+9   //�������벻�Ϸ�
#define ERR_NETWORK_SAME_NET_SEGMENT    ERR_NETWORK_BASE+10  //˫����ͬһ����
#define ERR_NETWORK_DIALING_CHANGETYPE    ERR_NETWORK_BASE+11  //���ڲ��Ź����в������޸Ĳ��ŷ�ʽ��

#define ERR_NETWORK_MAX                 ERR_NETWORK_BASE+500

//nsg 20120307 ���ܷ���ģ�������
#define ERR_VCA_BASE					8000
#define ERR_VCA_SUCCESSFUL				TD_SUCCESS		//�ɹ�
#define ERR_VCA_FAILED					TD_FAILURE		//ʧ��
#define ERR_VCA_OPEN_FILE_ERROR			ERR_VCA_BASE+1	//�������ļ�ʧ��
#define ERR_VCA_WRITE_FILE_ERROR		ERR_VCA_BASE+2	//д�����ļ�ʧ��
#define ERR_VCA_READ_ERROR				ERR_COM_BASE+3	//�������ļ�����
#define ERR_VCA_NO_SUCH_FILE			ERR_VCA_BASE+4	//û������ļ�

//û����Ӧ���û�Ȩ��
#define ERR_USER_BASE					9000
#define ERR_USER_RIGHT					ERR_USER_BASE + 1	//Ȩ�޲��㣬����ʧ��

//#define ERR_NETWORK_PPPOE_CONNECT        ERR_NETWORK_BASE+4
//#define ERR_NETWORK_PPPOE_DISCONNECT        ERR_NETWORK_BASE+5

//�طŲ���
#define ERR_PLAY_BASE					10000
#define ERR_PLAY_CAP_ERR				ERR_PLAY_BASE
#define ERR_PLAY_CAP_OK					ERR_PLAY_BASE + 1
#define ERR_PLAY_BACK_ERR				ERR_PLAY_BASE + 2
#endif /* TD_ERRNO_H_ */


/*
 ====================================================================
 Name         : sys_type.h
 Author       : shanbingdong
 Version      : 0.1
 Copyright    : Tiandy
 Description  : ��·��NVR raid/iscsiģ�鹫��ͷ�ļ�
 ====================================================================
 */
#ifndef SYS_TYPEH
#define SYS_TYPEH

#define MAX_PATH 260	/**< ���·������ */
#define MAX_IP_LEN 16	/**< ���IP��ַ���� */
#define MAX_USERNAME_LEN 60	/**< ����û������� */
#define MAX_PASSWORD_LEN 60	/**< ������볤�� */

//RAID����
#define RAID_0 		0
#define RAID_1 		1
#define RAID_5 		5
#define RAID_10     10
#define RAID_JBOD 	100

#define RAID_SYNC_PRIORITY_LOW      0
#define RAID_SYNC_PRIORITY_MIDDLE   1
#define RAID_SYNC_PRIORITY_HIGH     2

#define DISK_STATUS_OK 				1
#define DISK_STATUS_NO 				0

#define MAX_BIG_DATA_NVR_DISK_NUM 	16//��NVRԭ�ȵ�MAX_DISK_NUM��ͻ
#define MAX_VIRTUAL_DISK_NUM		16
#define MAX_RAID_NUM 				8
#define MAX_ISCSI_TARGET_NUM  		8
#define MAX_SEARCH_DISK_NUM 		64

#define MAX_MSG_LEN  	128
#define MAX_NAME_LEN	64


//����smart ״̬��Ϣ
#define DISK_SMART_GOOD		0
#define DISK_SMART_LOWHEALTH	1
#define DISK_SMART_BAD			2

#define UDV_TYPE_NONE     	0
#define UDV_TYPE_RAW      	1
#define UDV_TYPE_ISCSI    	2
#define UDV_TYPE_NAS       	3

#define UDV_CREATE_START_SIZE 209715200	//200M

//����ģ���ʾ
#define MODULE_PHYSICAL_DISK            0
#define MODULE_RAID                     1
#define MODULE_VIRTUAL_PARTITION        2 //�ݲ�֧��

/* ��������*/
//����״̬����:������ר���ȱ��̡�ȫ���ȱ��̡�RAID�̡���ЧRAID�̡�������
#define STATUS_TYPE_DISK_FREE     				0
#define STATUS_TYPE_DISK_SPECIAL				1
#define STATUS_TYPE_DISK_GLOBAL			    	2
#define STATUS_TYPE_DISK_RAID     				3
#define STATUS_TYPE_DISK_INVALID				4
#define STATUS_TYPE_DISK_FAIL					5
#define STATUS_TYPE_DISK_REALLOCATE_SECTORS 6	//���·���������������
#define STATUS_TYPE_DISK_PENDING_SECTORS 	7	//���ȶ�������������
#define STATUS_TYPE_DISK_UNCORRECTABLE 		8	//�޷����������������

//RAID״̬:����(normal)������(degrade)��ʧЧ(fail)���ؽ�(rebuild��recovering)����ʼ��(initial)������(reshape)
#define STATUS_TYPE_RAID_NORMAL         100 
#define STATUS_TYPE_RAID_DEGRADED       101
#define STATUS_TYPE_RAID_FAIL           102
#define STATUS_TYPE_RAID_RECOVERING     103
#define STATUS_TYPE_RAID_INITIAL        104
#define STATUS_TYPE_RAID_RESHAPE        105
#define STATUS_TYPE_RAID_ACTIVE         106 

//ISCSI�ͻ��˽ṹ��
typedef struct _IscsiDiskInfo {
	int iscsi_id;								//iscsi��ʾ(16-23) ���ϲ�UIΨһ��ʾ
	char id_serial[MAX_NAME_LEN];				//iscsi  id_serial��ϵͳkernelΨһ��ʾ
	long long int volume; 						//������������λ�ֽ�
	long long int avalible_volumn;				//���ô�����������λ�ֽ�
	int disk_status;							//����״̬
	char iscsi_dev_dir[MAX_PATH];				//iscsi�豸�� /dev/s(p)db
	char tgt_name[MAX_NAME_LEN];			//target����
} IscsiDiskInfo;

typedef struct _TargetInfo {
	char tgt_name[MAX_NAME_LEN];			//target����
	IscsiDiskInfo* disk[MAX_SEARCH_DISK_NUM ];//target��Ӧ����ָ������
} TargetInfo;


typedef struct _IscsiInfo {
	char ip[MAX_IP_LEN];  						//ipsan��IP
	int port;									//iscsiӳ��˿�
	char username[MAX_USERNAME_LEN];		//�û���
	char passwd[MAX_PASSWORD_LEN];			//����
	TargetInfo* target[MAX_ISCSI_TARGET_NUM];//target��ָ������
} IscsiInfo;


//RAIDģ��ṹ��
/*****���¹��ܽ�Ҫʹ��RetResult�ṹ�������ؽ����Ϣ*****
2.3 ���ô���״̬
3.1 �������顢3.2 ɾ������ ��3.4 ��֤�������顢3.5 ���ɾ������ơ�3.6 ���þ����ʼ��/�ؽ����ȼ�
3.7 ��ȡ�����ʼ��/�ؽ����ȼ���msg�ֶε����Ϊ��low|middle|high����3.8 �������ݣ���֧��raid5/6��
4.1 �����û����ݾ�4.2 ɾ���û����ݾ�4.3 �޸��û����ݾ�����
6.1.2 �޸�Target���ԡ�6.1.3 ����Target��6.1.4 ɾ��Target
*/
typedef struct _RetResult {				//���ؽ����Ϣ�ṹ��
	int status;				//ִ�еĽ��
	char msg[MAX_MSG_LEN];	//ִ������ɹ�����ʾ��ʧ��ԭ��
} RetResult;


/*****�����б�*****/
typedef struct _DiskInfo {				//������Ϣ
	int slot;						//λ�ã�����   ( x: 0~4  y: 1~16  ==>  0-15, 100-115, 200-215, 300-315, 400-415)
	char model[MAX_NAME_LEN];	//�����ͺţ��ַ����������ֺ��ַ�����
	char serial[MAX_NAME_LEN];	//���кţ���ĸ���������
	char firmware[MAX_NAME_LEN];	//�̼��汾��
	long long int capacity;			//��������λ�ֽ�
	int smart;					//Good �C ���ã�SMART��Ϣ���쳣;LowHealth �C �����ȵͣ�����������ĳ����ֵ;(��Լ5w��������); Bad �C ���̹��ϣ������޷�ʶ��
	int state;					//���̹���״̬��Free �C ������ Special �C ר���ȱ��� Global �C ȫ���ȱ��� RAID �C RAID��
	char name[MAX_NAME_LEN];	//��������
} DiskInfo;

typedef struct _DiskListInfo {			//�����б���Ϣ
	int total;						//���̽����Ŀ����
	DiskInfo row[MAX_BIG_DATA_NVR_DISK_NUM];	//����ÿ����Ŀ�Ķ���
} DiskListInfo;

/*****��ȡ������ϸ��Ϣ*****/
typedef struct _DiskSmartInfo {			//����smart��Ϣ
	int	read_err;			//��������
	int	spin_up;			//����ʱ��
	int	reallocate_sectors;	//���·�����������
	int	pending_sectors;	//���ȶ���������
	int	uncorrectable;		//�޷������������
	int	power_on_hours;	//�ۼ�ͨ��ʱ��
	int	temperature;		//�¶�
} DiskSmartInfo;

typedef struct _DiskDetailInfo {		//������ϸ��Ϣ
	DiskInfo disk_info;		//������Ϣ
	DiskSmartInfo smart_info;	//smart��Ϣ
	int bus_type;				//SAS / SATA
	int	rpm;				//����ȡֵ��5400 / 7200 / 10000
	int wr_cache;			//д���棺enable / disable
	int rd_ahead;			//Ԥ����enable / disable
	int	standby;			//����ģʽ����������������޶�д�������ģʽ��0��ʾ�رգ��������������ģʽ������ȡֵ��30 / 60 / 600 / 1800
	int cmd_queue;			//������У�enable / disable
	int	mapped_cnt;		//���޸���������
	int	max_map_cnt;		//�����޸�������	
} DiskDetailInfo;

/*****�����б�*****/
typedef struct _VGInfo {					//������Ϣ
	char name[MAX_NAME_LEN];		//��������
	char dev[MAX_NAME_LEN];			//������豸����	���磺/dev/md1
	int raid_level;					//ȡֵ��Χ��0 / 1 / 5 /  JBOD
	int raid_state;					//������normal����������degrade����ʧЧ��fail�����ؽ���rebuild������ʼ����initial�������ݣ�reshape��
	int raid_strip;					//������С	ȡֵ��Χ��4/8/16/32/64/128/256/512/1024����λKB
	float sync_percent;				//RAID��ʼ��/�ؽ�����	����raid_stateΪrebuild����initialʱ��Ч���ٷֱ���ʽ���������һλС����
	float sync_speed;					//RAID��ʼ��/�ؽ��ٶ�	����raid_stateΪrebuild����initialʱ��Ч���������һλС������λ��MB/s
	int sync_finish;					//RAID��ʼ��/�ؽ�ʣ��ʱ��	����raid_stateΪrebuild����initialʱ��Ч�����Ϊ��������λ������ min
	long long int capacity;				//����������	��λ���ֽ�
	long long int remain;				//ʣ������	��λ���ֽ�
	int max_single;					//�����������	��λ���ֽ�
	int disk_cnt;						//��ǰRAID��Ա�̸���	ȡֵ��Χ��1~��������֧����������
	int disk_total;					//�ܵ�RAID��Ա�̸���	ȡֵ��Χ��1~��������֧����������
	char raid_uuid[MAX_NAME_LEN];	//�����ڲ�Ψһ��ʶ	���磺3a32c2ed:1df8f4d2:a62159fd:8ecc787b
	int disk_list[MAX_BIG_DATA_NVR_DISK_NUM];		//RAID��Ա�����б�	��ʽ������ID�б�ʹ�ÿո�ָ���̺�Ϊ1-16
} VGInfo;

typedef struct _VGListInfo {			//������Ϣ�б�
	int total;						//��������Ŀ����
	VGInfo row[MAX_RAID_NUM];	//����ÿ����Ŀ�Ķ���
} VGListInfo;


/*****��ȡ������ÿռ�*****/
typedef struct _VGAvalibaleInfo {		//���������Ϣ
	char vg[MAX_NAME_LEN];		//��������
	long long int max_avaliable;	//���ÿռ��ܺ�	��λ���ֽ�
	long long int max_single;		//���������ÿռ�	��λ���ֽ�
} VGAvalibaleInfo;

/*****��֤�����û����ݾ� (���Բ�Ҫ����ṹ��)*****/
typedef struct _VGDup {
	char vg[MAX_NAME_LEN];		//��������
	int duplicate;					//�Ƿ��ظ�:true - ��ʾname�Ѿ�����,false - ��ʾname������
} VGDup;

/*****�û����ݾ��б�*****/
typedef struct _UDVInfo { 				//�û����ݾ���Ϣ
	char name[MAX_NAME_LEN];	//�û����ݾ�����
	long long int capacity;			//���� ��λ���ֽ�
	int state;					//״̬ ȡֵ��Χ��δʹ�ã�raw����ӳ��ΪiSCSI��iscsi����ӳ��ΪNAS��nas��
	char vg[MAX_NAME_LEN];		//�û����ݾ����ڵ�VG����	
	char combin[MAX_NAME_LEN];	//�û����ݾ����ƺ�����	
	char dev[MAX_NAME_LEN];		//�豸�ڵ�·����	
} UDVInfo;

typedef struct _UDVListInfo {			//�û����ݾ��б���Ϣ
	int total;							//�û����ݾ�����Ŀ����
	UDVInfo row[MAX_BIG_DATA_NVR_DISK_NUM];		//�û����ݾ���Ϣ
} UDVListInfo;

/*

//ISCSI����˽ṹ��
//����Target
typedef struct _TargetNameList {
	int total;							//target����
	char* target_name[MAX_NAME_LEN];	//target�����б�
} TargetNameList;


//��ȡTarget�б�
typedef struct _IscsiProtocol {			//iSCSIЭ����ص���Ϣ
	int HeaderDigest;							//Э��ͷУ�鷽ʽ	Ŀǰ֧��None��ʽ����ʾ��У��
	int DataDigest;							//����У�鷽ʽ	Ŀǰ֧��None��ʽ����ʾ��У��
	int ImmediateData;						//�Ƿ�����Я����������	ȡֵ��Yes��������No��������
	int InitialR2T;								//�Ƿ����������������	ȡֵ��Yes��������No��������
	long long int FirstBurstLength;				//��������������󳤶�	��λ���ֽ�
	long long int MaxBurstLength;				//������������󳤶�	��λ���ֽ�
	long long int MaxOutstandingR2T;				//ÿ���������R2T����	������
	long long int MaxRecvDataSegmentLength;		//PDU���ݶ������ճ���	��λ���ֽ�
	long long int MaxXmitDataSegmentLength;		//PDU���ݶ�����ͳ���	��λ���ֽ�
	int IncommingChap;						//����Target CHAP��֤	ȡֵ��Χ��enable / disable
} IscsiProtocol;

typedef struct _TargetAttribute {		//Target�������
	int NopInInterval;			//�޲���ʱ����	��λ����
	int NopInTimeout;			//�޲�����ʱʱ��	��λ����
	int RspTimeout;			//��Ӧ��ʱʱ��	��λ����
	int MaxSessions;			//�������Session����	�����������޸Ĳ�����
} TargetAttribute;

typedef struct _TargetInfo {			//Target��Ϣ
	int tid;							//Target ID
	char target_name[MAX_NAME_LEN];	//Target����
	int state;							//״̬ ȡֵ��Χ��enable / disable
	int luns;							//�Ѿ�ӳ�䵽��Target��iSCSI�����	0 ~ ʵ������
	int sessions;						//session���� 0 ~ ʵ������
	IscsiProtocol iscsi_protocal;			//iSCSIЭ����ص���Ϣ
	TargetAttribute target_attr;			//Target�������
	int QueuedCommands;				//�ڶ����л����������� ������ (statistics	ͳ����Ϣ)
} TargetInfo;

typedef struct _TargetListInfo {			//ISCSI��target�б���Ϣ
	int total;						//ISCSI��target�����Ŀ����
	TargetInfo row[MAX_BIG_DATA_NVR_DISK_NUM];	//target��Ϣ
} TargetListInfo;

*/

#endif

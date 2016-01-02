#ifndef SYS_RAIDH
#define SYS_RAIDH

#ifndef SYS_TYPEH
#include "sys_type.h"
#endif

#define TURE  1
#define FALSE 0

enum
{
	RAID_STAT_NORMAL=1,
	RAID_STAT_DEGRADED,	
	RAID_STAT_FAIL,
};

enum
{
	RAID_TSK_NULL=1,
	RAID_TSK_INIT,	
	RAID_TSK_REBUILD,
};


/*
	����: sys_raid_startup
	����: raid��ʼ��
	����: ��
	����: 0 �ɹ�
		  >0 ʧ��
*/
int 
sys_raid_startup();


/*
	����: sys_raid_cleanup
	����: raid����ʼ��
	����: ��
	����: 0 �ɹ�
		  >0 ʧ��
*/
int 
sys_raid_cleanup();


/*
	����: sys_disk_list
	����: �г�������Ϣ
	����: disk_info ������Ϣ
		total ��������
	����: 0 �ɹ�
		  >0 ʧ��
*/
int 
//sys_disk_list( OUT DiskInfo *disk_info, IN OUT int* total);
sys_disk_list( OUT DiskInfo *disk_info, OUT int* total);


/*
	����: sys_disk_get_detail
	����: �г�������ϸ��Ϣ
	����: slot_id Ӳ�̲ۺ�
		disk_detail_info ������ϸ��Ϣ
	����: 0 �ɹ�
		  >0 ʧ��
*/
int
sys_disk_get_detail(int slot_id, OUT DiskDetailInfo* disk_detail_info);


/*
	����: sys_disk_set
	����: iscsi�ǳ�
	����: slot_id Ӳ�̲ۺ�
		type ��������
		vg_name ��������
	����: 0 �ɹ�
		  >0 ʧ��
*/
int
sys_disk_set(int  slot_id, int type, const char* vg_name);


/*
	����: sys_raid_create
	����: ����raid/����
	����: vg_name  ��������
		level ���м���(0,1,5,10,JBOD)
		raid_devices   �������ݴ�������
		raid_dev_num �������ݴ�������
		spare_devices �����ȱ�������
		spare_dev_num �����ȱ�������
		chunk ������С(Ĭ��128KB)
	����: 0 �ɹ�
		  >0 ʧ��
*/
int
sys_raid_create(const char* vg_name, int level, int* raid_devices, int raid_dev_num, int* spare_devices, int spare_dev_num, int chunk);


/*
	����: sys_raid_delete
	����: ɾ��raid/����
	����: vg_name  ��������
	����: 0 �ɹ�
		  >0 ʧ��
*/
int
sys_raid_delete(const  char* vg_name);


/*
	����: sys_raid_list
	����: ��ȡraid�б�
	����: vg_info ������Ϣ
		total �������
	����: 0 �ɹ�
		  >0 ʧ��
*/
int
sys_raid_list(OUT VGInfo * vg_info,  OUT int* total);


/*
	����: sys_raid_assemble
	����: �ֶ��ؽ�����
	����: vg_name:��������
		 old_disk_list�����д����б�
		 old_disk_num:���д�������
		 new_disk_list���¼Ӵ����б�
		 new_disk_num���¼Ӵ�������
	����: 0 ������
		  >0 ������
*/
int 
sys_raid_assemble(const char* vg_name, int* old_disk_list, int old_disk_num, int* new_disk_list, int new_disk_num);

/*
	����: sys_raid_duplicate_check
	����: ��֤����������
	����: vg_name  ��������
	����: 0 �ɹ�(˵��raid�����Ѿ�����)
		  >0 ʧ��
*/
int
sys_raid_duplicate_check(const  char* vg_name);


/*
	����: sys_raid_generate_name
	����: ���ɾ�������
	����: suffix Ҫ���ɵľ�������ǰ׺
		vg_name  ��������
	����: 0 �ɹ�
		  >0 ʧ��
*/
int
sys_raid_generate_name(const char* suffix,  OUT char* vg_name);


/*
	����: sys_raid_set_sync_prio
	����: ���þ����ʼ��/�ؽ����ȼ�
	����: init_level ��ʼ������
	����: 0 �ɹ�
		  >0 ʧ��
*/
int
sys_raid_set_sync_prio(int init_level);


/*
	����: sys_raid_get_sync_prio
	����: ��ȡ�����ʼ��/�ؽ����ȼ�
	����: init_level ��ʼ������
	����: 0 �ɹ�
		  >0 ʧ��
*/
int
sys_raid_get_sync_prio(OUT int* init_level);


/*
	����: sys_udv_create
	����: �����û����ݾ�
	����: vg_name  ��������
		udv_name   �û����ݾ�(�������)����
		offset  �û����ݾ�ƫ����,��ʼ��СΪ209715200Byte(200M),��4K����
		size �û����ݾ��С,���������м���С��1G�Ŀռ䣬����Ϊ����Ƭ������
	����: 0 �ɹ�
		  >0 ʧ��
*/
int
sys_udv_create(const char* vg_name, const char* udv_name, long long int offset, long long int size);


/*
	����: sys_udv_delete
	����: ɾ���û����ݾ�
	����: vg_name  ��������
	����: 0 �ɹ�
		  >0 ʧ��
*/
int
sys_udv_delete(const  char*  udv_name);


/*
	����: sys_udv_remain_capacity
	����: ��ȡ������ÿռ�
	����: vg_name  ��������
		vg_avalibale_info ���������Ϣ
	����: 0 �ɹ�
		  >0 ʧ��
*/
int
sys_udv_remain_capacity(const  char*  vg_name,  OUT  VGAvalibaleInfo* vg_avalibale_info);


/*
	����: sys_udv_list
	����: �û����ݾ��б�
	����: udv_info �û����б���Ϣ
		total �û����ݾ�����
	����: 0 �ɹ�
		  >0 ʧ��
*/
int
sys_udv_list(OUT UDVInfo * udv_info, OUT int* total);

/*
	����: sys_udv_assemble
	����: ɾ��ԭ��������������ӣ���ȡ�����б���Ϣ�����½��н���
	����: 
	����: 0 �ɹ�
		  >0 ʧ��
*/
int
sys_udv_assemble();

/*
	����: RECV_ALARM_NOTIFY
	����: ����ָ��
	����: module  ģ������ ������� 0 ��RAID 1 �� (������� 2,�ݲ�֧��)
		type �����¼�����:��������𻵡�RAID������
		param   ָ���������͵�����ָ��
		usr �û�����
*/
typedef int (*RECV_ALARM_NOTIFY)(int module, int type, void* param, void* usr);

/*
	����: sys_alarm_set_callback
	����: ���ñ����ص�
	����: module  ģ������ ������� 0 ��RAID 1 
		alarm_callback   �����ص�����
		usr �û�����
	����: 0 �ɹ�
		  >0 ʧ��
*/
int sys_alarm_set_callback(int module, RECV_ALARM_NOTIFY alarm_callback, void* usr);
#if JMB39X == ON
int sys_raid_mapPort(int _iDisk);
void sys_raid_init(void);
void raid_JMB393_ScanDisc(int _iDisk);
#endif

#endif

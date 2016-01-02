/*
 *	file: dlist.h
 *	description: dynamic list
 *	history: dongliqiang created at 20130304
 */

//#include "common.h"
#include <pthread.h>

#define STDCALL 
#define X_API 

typedef struct _DList DList;            /**< ˫������ */
typedef struct _DListNode DListNode;    /**< ˫������ڵ� */

typedef struct {
	pthread_mutex_t mutex;
}LMutex;

struct _DListNode
{
	DListNode* next, * prev;
	char data[0];
};

struct _DList
{
	DListNode* head;
	DListNode* end;
	unsigned int node_size;
	unsigned int len;
	LMutex mutex;
};

/**
    @brief ˫��������    
    @param node_size �ڵ����ݵĴ�С
    @retval NULL ʧ�� 
    @retval ���� ����
 */
DList *X_API STDCALL adt_dlist_create(unsigned int node_size);

/**
    @brief �������� 
    @param dlist ����
    @retval TRUE �ɹ� 
    @retval FALSE ʧ��
 */
int X_API STDCALL adt_dlist_destroy(DList *dlist);

/**
    @brief ������� 
    @param dlist ����
    @param node ����λ��
    @param data ����
    @retval NULL ʧ�� 
    @retval ���� �ɹ�
 */
DListNode *X_API STDCALL adt_dlist_insert(DList *dlist, DListNode *node, void *data);

/**
    @brief ������� 
    @param dlist ����
    @param node ���λ��
    @param data ����
    @retval NULL ʧ�� 
    @retval ���� �ɹ�
 */
DListNode *X_API STDCALL adt_dlist_add(DList *dlist, DListNode *node, void *data);

/**
    @brief ������һ���ڵ� 
    @param dlist ����
    @param node ��ǰλ��
    @return NULL ����β 
    @retval ���� ��һ���ڵ�
 */
DListNode *X_API STDCALL adt_dlist_next(DListNode *node);

/**
    @brief ������һ���ڵ� 
    @param dlist ����
    @param node ��ǰλ��
    @retval NULL ����β 
    @retval ���� ��һ���ڵ�
 */
DListNode *X_API STDCALL adt_dlist_prev(DListNode *node);

/**
    @brief ����ͷ�ڵ� 
    @param dlist ����
    @return ����ͷ
 */
DListNode *X_API STDCALL adt_dlist_head(DList *dlist);

/**
    @brief ����β�ڵ� 
    @param dlist ����
    @return ����β
 */
DListNode *X_API STDCALL adt_dlist_end(DList *dlist);

/**
    @brief �����С 
    @param dlist ����
    @return �����нڵ����
 */
unsigned int X_API STDCALL adt_dlist_size(DList *dlist);

/**
    @brief �����Ƿ�Ϊ�� 
    @param dlist ����
    @retval TRUE �� 
    @retval FALSE �ǿ�
 */
int X_API STDCALL adt_dlist_empty(DList *dlist);

/**
    @brief  ����ɾ���ڵ� 
     @param dlist ����
    @param node �ڵ�
    @return TRUE �ɹ� 
    @retval FALSE ʧ��
 */
int X_API STDCALL adt_dlist_delete(DList *dlist, DListNode *node);

/**
    @brief �����ýڵ�����  
    @param node �ڵ�
    @retval NULL ʧ�� 
    @retval ���� �ڵ�����
 */
void *X_API STDCALL adt_dlist_getdata(DListNode *node);

/**
    @brief �������� 
    @param dlist ����
    @retval TRUE �ɹ� 
    @retval FALSE ʧ��
 */
int X_API STDCALL adt_dlist_lock(DList *dlist);

/**
    @brief �������� 
    @param dlist ����
    @retval TRUE �ɹ� 
    @retval FALSE ʧ��
 */
int X_API STDCALL adt_dlist_unlock(DList *dlist);

/**
    @brief ��������ʼ�� 
    @param dlist ����
    @retval TRUE �ɹ� 
    @retval FALSE ʧ��
 */
int X_API STDCALL adt_dlist_lock_init(DList* dlist);

/**
    @brief ����������ʼ��
    @param dlist ����
    @retval TRUE �ɹ� 
    @retval FALSE ʧ��
 */
int X_API STDCALL adt_dlist_lock_uninit(DList* dlist);


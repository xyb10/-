#define _CRT_SECURE_NO_WARNINGS
#include"slinkedlist.h"
//��ʼ���ṹ��
struct slinkedlist* slinkedlist_init() {
	struct slinkedlist* list = NULL;
	list = (struct slinkedlist*)malloc(sizeof(struct slinkedlist));
	list->head = (struct slinkedlist_node*)malloc(sizeof(struct slinkedlist_node));
	list->head->next = NULL;
	list->count = 0;
	return list;

}
//�ͷŴ������ڴ�ռ�
void slinkedlist_free(struct slinkedlist* list) {
	struct slinkedlist_node* p;
	while (list->head != NULL)
	{
		p = list->head;
		list->head = p->next;
		free(p);
	}
	free(list);
}
//����������
int slinkedlist_count(struct slinkedlist* list) {
	return list->count;
}
//�������
void slinkedlist_clear(struct slinkedlist* list) {
	struct slinkedlist_node* p, * q;
	p = list->head->next;	//��ͷ���ָ��ָ�����һ���ĵ�ַ��ֵ��p
	while (p)	//��������
	{
		q = p->next;
		free(p);
		p = q;
	}
	p = NULL;
}
//ָ��λ�ò������ݽ��
void slinkedlist_add(struct slinkedlist* list, int index, int value) {
	struct slinkedlist_node* p, * q;
	int i = 1;
	q = list->head;    //��ͷ���ĵ�ַ��ֵ��q
	p = (struct slinkedlist_node*)malloc(sizeof(struct slinkedlist_node));    //Ϊ�½������ڴ�ռ�
	p->data = value;    //Ϊ�½��������ֵ
	while (i < index && q->next)    //�ҵ�ָ����λ��
	{
		q = q->next;
		i++;
	}
	p->next = q->next;
	q->next = p;
	return OK;
}
//ָ��λ��ɾ�����ݽ��
void slinkedlist_remove(struct slinkedlist* list, int index) {
	struct slinkedlist_node* p, * q;
	int i = 1;
	p = list->head;
	if (index<1 || index>list->count)	//�ж�ɾ����λ�úϲ�����
	{
		return ERROR;
	}
	while (i < index && p->next)	//�ҵ�ָ��λ��
	{
		p = p->next;
		i++;
	}
	q = p->next;	//����ɾ�����ĵ�ַ��ֵ��q
	p->next = q->next;		//����ɾ��������һ���ĵ�ַ��ֵ����ɾ��������һ����ָ����
	free(q);
	list->count--;		//��������Լ�
	return;
}
//����һ��ֵ
void slinkedlist_set(struct slinkedlist* list, int index, int value) {
	struct slinkedlist_node* p;
	int i = 0;
	p = list->head;
	if (index<1 || index>list->count)		//�ж�λ���Ƿ����
	{
		return ERROR;
	}
	while (i < index && p->next)
	{
		p = p->next;
		i++;
	}
	p->data = value;
	return OK;
}
//���һ��ֵ
int slinkedlist_get(struct slinkedlist* list, int index) {
	struct slinkedlist_node* p;
	int i = 0;
	p = list->head;
	if (index<1 || index>list->count)
	{
		return ERROR;
	}
	while (i < index && p->next)
	{
		p = p->next;
		i++;
	}
	return p->data;
}
//����ĳ��Ԫ�ص����ݽ��
int slinkedlist_lookup(struct slinkedlist* list, int value) {
	struct slinkedlist_node* p;
	int i = 0;
	p = list->head->next;
	while (p)
	{
		if (p->data == value)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}
//�ж������Ƿ�Ϊ��
int slinkedlist_isempty(struct slinkedlist* list) {
	return list->head == NULL ? 1 : 0;
}
//����һ��������ע�⣺�˺�����ֱ������Ԫ��
struct slinkedlist* slinkedlist_creat() {
	struct slinkedlist* list = slinkedlist_init();
	return list;
}
//�ϲ�������
void slinkedlist_merge(struct slinkedlist* list1, struct slinkedlist* list2) {
	struct slinkedlist_node* p, * q;
	p = list1->head->next;	//ʹ��ָ��pָ������1����Ԫ���
	q = list2->head->next;	//ʹ��ָ��pָ������2����Ԫ���
	struct slinkedlist_node* list3 = list1->head;	//ʹ��ָ��list3ָ������1��ͷ��㣬��ͷ��㽫��Ϊ�������ͷ���
	free(list2);		//�ͷŵ�����2ͷ���ʹ�õ��ڴ�ռ�
	while (p && q)		//ѭ���жϵ������Ƿ��н��
	{
		if (p->data <= q->data)		//�Ա������������н���ֵ���ӵ�һ����㿪ʼ
		{
			list3->next = p;
			list3 = p;
			p = p->next;
		}
		else
		{
			list3->next = q;
			list3 = q;
			q = q->next;
		}
	}
	if (p == NULL)		//���������1�еĽ��Ƚ���
	{
		list3->next = q;	//ֱ�ӽ�������2ʣ��Ľ�����ӵ�������
	}
	if (q == NULL)		//���������2�еĽ��Ƚ���
	{
		list3->next = p;	////ֱ�ӽ�������1ʣ��Ľ�����ӵ�������
	}
}
//��ʾ���ݽ��
void slinkedlist_show(struct slinkedlist* list) {
	struct slinkedlist_node* p;
	p = list->head;
	while (p->next != NULL)		//�жϸý�����һ����Ƿ���ڣ��������ƶ�ָ��
	{
		p = p->next;
		printf("%d ", p->data);		//��ӡ�������
	}
	printf("\n");
}
//��������
struct slinkedlist* ReverseLink(struct slinkedlist* list) {
	if (list->head->next == NULL)
	{
		return NULL;
	}
	struct slinkedlist_node* p1;
	struct slinkedlist_node* p2;
	p1 = list->head->next;	//���������е�ͷ������������Ͽ�������ָ��Pָ��ĳ�������ݵĽ��
	list->head->next = NULL;
	while (p1 != NULL)		//�ж���һ����Ƿ����
	{
		p2 = p1;	//��P1��P2ָ����ͬ�Ľ��
		p1 = p1->next;	//�ƶ�ָ��p1����p1ָ����һ���
		p2->next = list->head->next;	//ͷ�巨�����¿�ʼ������
		list->head->next = p2;	//��p2ָ��Ľ�����²���
	}
	return list;
}
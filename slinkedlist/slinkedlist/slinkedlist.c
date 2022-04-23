#define _CRT_SECURE_NO_WARNINGS
#include"slinkedlist.h"
//初始化结构体
struct slinkedlist* slinkedlist_init() {
	struct slinkedlist* list = NULL;
	list = (struct slinkedlist*)malloc(sizeof(struct slinkedlist));
	list->head = (struct slinkedlist_node*)malloc(sizeof(struct slinkedlist_node));
	list->head->next = NULL;
	list->count = 0;
	return list;

}
//释放创建的内存空间
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
//计算链表长度
int slinkedlist_count(struct slinkedlist* list) {
	return list->count;
}
//清空链表
void slinkedlist_clear(struct slinkedlist* list) {
	struct slinkedlist_node* p, * q;
	p = list->head->next;	//将头结点指针指向的下一结点的地址赋值给p
	while (p)	//遍历链表
	{
		q = p->next;
		free(p);
		p = q;
	}
	p = NULL;
}
//指定位置插入数据结点
void slinkedlist_add(struct slinkedlist* list, int index, int value) {
	struct slinkedlist_node* p, * q;
	int i = 1;
	q = list->head;    //将头结点的地址赋值给q
	p = (struct slinkedlist_node*)malloc(sizeof(struct slinkedlist_node));    //为新结点分配内存空间
	p->data = value;    //为新结点数据域赋值
	while (i < index && q->next)    //找到指定的位置
	{
		q = q->next;
		i++;
	}
	p->next = q->next;
	q->next = p;
	return OK;
}
//指定位置删除数据结点
void slinkedlist_remove(struct slinkedlist* list, int index) {
	struct slinkedlist_node* p, * q;
	int i = 1;
	p = list->head;
	if (index<1 || index>list->count)	//判断删除的位置合不合理
	{
		return ERROR;
	}
	while (i < index && p->next)	//找到指定位置
	{
		p = p->next;
		i++;
	}
	q = p->next;	//将被删除结点的地址赋值给q
	p->next = q->next;		//将被删除结点的下一结点的地址赋值给被删除结点的上一结点的指针域
	free(q);
	list->count--;		//结点数量自减
	return;
}
//设置一个值
void slinkedlist_set(struct slinkedlist* list, int index, int value) {
	struct slinkedlist_node* p;
	int i = 0;
	p = list->head;
	if (index<1 || index>list->count)		//判断位置是否合理
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
//获得一个值
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
//查找某个元素的数据结点
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
//判断链表是否为空
int slinkedlist_isempty(struct slinkedlist* list) {
	return list->head == NULL ? 1 : 0;
}
//创建一个单链表。注意：此函数可直接输入元素
struct slinkedlist* slinkedlist_creat() {
	struct slinkedlist* list = slinkedlist_init();
	return list;
}
//合并单链表
void slinkedlist_merge(struct slinkedlist* list1, struct slinkedlist* list2) {
	struct slinkedlist_node* p, * q;
	p = list1->head->next;	//使用指针p指向单链表1的首元结点
	q = list2->head->next;	//使用指针p指向单链表2的首元结点
	struct slinkedlist_node* list3 = list1->head;	//使用指针list3指向单链表1的头结点，该头结点将作为新链表的头结点
	free(list2);		//释放单链表2头结点使用的内存空间
	while (p && q)		//循环判断单链表是否还有结点
	{
		if (p->data <= q->data)		//对比两个单链表中结点的值，从第一个结点开始
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
	if (p == NULL)		//如果单链表1中的结点比较完
	{
		list3->next = q;	//直接将单链表2剩余的结点连接到新链表
	}
	if (q == NULL)		//如果单链表2中的结点比较完
	{
		list3->next = p;	////直接将单链表1剩余的结点连接到新链表
	}
}
//显示数据结点
void slinkedlist_show(struct slinkedlist* list) {
	struct slinkedlist_node* p;
	p = list->head;
	while (p->next != NULL)		//判断该结点的下一结点是否存在，存在则移动指针
	{
		p = p->next;
		printf("%d ", p->data);		//打印结点数据
	}
	printf("\n");
}
//逆置链表
struct slinkedlist* ReverseLink(struct slinkedlist* list) {
	if (list->head->next == NULL)
	{
		return NULL;
	}
	struct slinkedlist_node* p1;
	struct slinkedlist_node* p2;
	p1 = list->head->next;	//将单链表中的头结点与其它结点断开，并将指针P指向某个带数据的结点
	list->head->next = NULL;
	while (p1 != NULL)		//判断下一结点是否存在
	{
		p2 = p1;	//将P1与P2指向相同的结点
		p1 = p1->next;	//移动指针p1，将p1指向下一结点
		p2->next = list->head->next;	//头插法，重新开始插入结点
		list->head->next = p2;	//将p2指向的结点重新插入
	}
	return list;
}
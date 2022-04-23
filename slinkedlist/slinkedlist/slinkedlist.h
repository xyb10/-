#pragma once

#include<stdio.h>
#include<stdlib.h>

#define ERROR
#define OK
//定义结构体结点
struct slinkedlist_node {
	int data;
	struct slinkedlist_node* next;
};
//定义一个结构体
struct slinkedlist {
	struct slinkedlist_node* head;
	int count;
};
//初始化结构体
struct slinkedlist* slinkedlist_init();
//释放创建的内存空间
void slinkedlist_free(struct slinkedlist* list);
//计算链表长度
int slinkedlist_count(struct slinkedlist* list);
//清空链表
void slinkedlist_clear(struct slinkedlist* list);
//指定位置插入数据结点
void slinkedlist_add(struct slinkedlist* list,int index,int value);
//指定位置删除数据结点
void slinkedlist_remove(struct slinkedlist* list,int index);
//设置一个值
void slinkedlist_set(struct slinkedlist* list,int inedx,int value);
//获得一个值
int slinkedlist_get(struct slinkedlist* list,int index);
//查找某个元素的数据结点
int slinkedlist_lookup(struct slinkedlist* list, int value);
//判断链表是否为空
int slinkedlist_isempty(struct slinkedlist* list);
//创建一个单链表。注意：此函数可直接输入元素
struct slinkedlist* slinkedlist_creat();
//合并单链表
void slinkedlist_merge(struct slinkedlist* list1, struct slinkedlist* list2);
//显示数据结点
void slinkedlist_show(struct slinkedlist* list);

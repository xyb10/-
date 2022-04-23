#pragma once

#include<stdio.h>
#include<stdlib.h>

#define ERROR
#define OK
//����ṹ����
struct slinkedlist_node {
	int data;
	struct slinkedlist_node* next;
};
//����һ���ṹ��
struct slinkedlist {
	struct slinkedlist_node* head;
	int count;
};
//��ʼ���ṹ��
struct slinkedlist* slinkedlist_init();
//�ͷŴ������ڴ�ռ�
void slinkedlist_free(struct slinkedlist* list);
//����������
int slinkedlist_count(struct slinkedlist* list);
//�������
void slinkedlist_clear(struct slinkedlist* list);
//ָ��λ�ò������ݽ��
void slinkedlist_add(struct slinkedlist* list,int index,int value);
//ָ��λ��ɾ�����ݽ��
void slinkedlist_remove(struct slinkedlist* list,int index);
//����һ��ֵ
void slinkedlist_set(struct slinkedlist* list,int inedx,int value);
//���һ��ֵ
int slinkedlist_get(struct slinkedlist* list,int index);
//����ĳ��Ԫ�ص����ݽ��
int slinkedlist_lookup(struct slinkedlist* list, int value);
//�ж������Ƿ�Ϊ��
int slinkedlist_isempty(struct slinkedlist* list);
//����һ��������ע�⣺�˺�����ֱ������Ԫ��
struct slinkedlist* slinkedlist_creat();
//�ϲ�������
void slinkedlist_merge(struct slinkedlist* list1, struct slinkedlist* list2);
//��ʾ���ݽ��
void slinkedlist_show(struct slinkedlist* list);

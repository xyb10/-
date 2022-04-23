#define _CRT_SECURE_NO_WARNINGS
#include"slinkedlist.h"
#include<malloc.h>

int main()
{
	struct slinkedlist* list1, * list2;
	list1 = slinkedlist_creat();
	slinkedlist_add(list1, 1, 70);
	slinkedlist_add(list1, 2, 50);
	slinkedlist_add(list1, 3, 30);
	slinkedlist_add(list1, 4, 10);
	slinkedlist_show(list1);
	ReverseLink(list1);
	slinkedlist_show(list1);
	list2 = slinkedlist_creat();
	slinkedlist_add(list2, 1, 20);
	slinkedlist_add(list2, 2, 40);
	slinkedlist_add(list2, 3, 60);
	slinkedlist_show(list2);
	slinkedlist_merge(list1, list2);
	slinkedlist_show(list1);
	return 0;
}
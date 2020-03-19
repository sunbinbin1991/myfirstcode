#pragma once
#include<iostream>
#include<malloc.h>            //可有可无
using namespace std;
typedef struct node
{
	int data;
	struct node *next;
} linklist;

linklist *create(int n)
{
	linklist *head = NULL, *p = NULL, *q = NULL;
	head = (linklist*)malloc(sizeof(linklist));
	p = head;        //尾插法建表（含头结点）
	for (int i = 1; i <= n; i++)
	{
		q = (linklist*)malloc(sizeof(linklist));
		cin >> q->data;
		q->next = NULL;      //若没有这一句则程序运行出现问题
		p->next = q;
		p = q;
	}
	return head;
	//free(head);
	//head = NULL;
	//free(s);
	//s = NULL;      这4句无意义,return head则程序结束,不执行这几句;不能放在return head前面，会导致return head时发生错误
}

void fun(linklist *head, int n, int k)
{
	if (k>n || k<0)
		cout << "NULL" << endl;
	else if (k == 0)
		cout << "0" << endl;    //该题倒数第0个结点比较扯，给出结果为0，题意并未提示。不加这句话则运行错误
	else
	{
		linklist *p = head->next;     //让p指向开始结点
		for (int i = 0; i<n - k; i++)       //倒数第一个结点下标为n-1,倒数第k个结点下标为n-k
			p = p->next;
		cout << p->data << endl;
	}
}


int test_last_k_node()
{
	int n;
	while (cin >> n)
	{
		linklist *head = create(n);
		int k;
		cin >> k;
		fun(head, n, k);
	}
	//system("pause");
	return 0;
}

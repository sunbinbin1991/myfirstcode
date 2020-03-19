#pragma once
#include<iostream>
#include<malloc.h>            //���п���
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
	p = head;        //β�巨������ͷ��㣩
	for (int i = 1; i <= n; i++)
	{
		q = (linklist*)malloc(sizeof(linklist));
		cin >> q->data;
		q->next = NULL;      //��û����һ����������г�������
		p->next = q;
		p = q;
	}
	return head;
	//free(head);
	//head = NULL;
	//free(s);
	//s = NULL;      ��4��������,return head��������,��ִ���⼸��;���ܷ���return headǰ�棬�ᵼ��return headʱ��������
}

void fun(linklist *head, int n, int k)
{
	if (k>n || k<0)
		cout << "NULL" << endl;
	else if (k == 0)
		cout << "0" << endl;    //���⵹����0�����Ƚϳ����������Ϊ0�����Ⲣδ��ʾ��������仰�����д���
	else
	{
		linklist *p = head->next;     //��pָ��ʼ���
		for (int i = 0; i<n - k; i++)       //������һ������±�Ϊn-1,������k������±�Ϊn-k
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

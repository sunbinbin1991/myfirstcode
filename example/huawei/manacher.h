#pragma once
#include <iostream>  
#include <cstring>
#include <algorithm>  

using namespace std;

char s[1000];
char s_new[2000];
int p[2000];

int Init()
{
	int len = strlen(s);
	s_new[0] = '$';
	s_new[1] = '#';
	int j = 2;

	for (int i = 0; i < len; i++)
	{
		s_new[j++] = s[i];
		s_new[j++] = '#';
	}

	s_new[j] = '\0';  // ������Ŷ

	return j;  // ���� s_new �ĳ���
}

int Manacher()
{
	int len = Init();  // ȡ�����ַ������Ȳ������ s_new ��ת��
	int max_len = -1;  // ����ĳ���

	int id;
	int mx = 0;

	for (int i = 1; i < len; i++)
	{
		if (i < mx)
			p[i] = min(p[2 * id - i], mx - i);  // ��������������ͼ����, mx �� 2*id-i �ĺ���
		else
			p[i] = 1;

		while (s_new[i - p[i]] == s_new[i + p[i]])  // ����߽��жϣ���Ϊ����'$',����'\0'
			p[i]++;

		// ����ÿ��һ�� i����Ҫ�� mx �Ƚϣ�����ϣ�� mx �����ܵ�Զ���������ܸ��л���ִ�� if (i < mx)�����룬�Ӷ����Ч��
		if (mx < i + p[i])
		{
			id = i;
			mx = i + p[i];
		}

		max_len = max(max_len, p[i] - 1);
	}

	return max_len;
}

int test_manacher()
{
	while (printf("�������ַ�����\n"))
	{
		scanf("%s", s);
		printf("����ĳ���Ϊ %d\n\n", Manacher());
	}
	return 0;
}
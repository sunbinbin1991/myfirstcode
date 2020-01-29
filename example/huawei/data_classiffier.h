#pragma once
//https://www.nowcoder.com/practice/9a763ed59c7243bd8ab706b2da52b7fd?tpId=37&tqId=21248&tPage=2&rp=&ru=/ta/huawei&qru=/ta/huawei/question-ranking
# include <iostream>
# include <cstring>
using namespace std;

//对Sort[] 排序从小到大
void Sort(int R[], int n)
{
	int i;
	int j;
	int temp;

	for (i = 0; i<n; i++)
	{
		for (j = i + 1; j<n; j++)
		{
			if (R[i] > R[j])
			{
				temp = R[i];
				R[i] = R[j];
				R[j] = temp;
			}
		}
	}
}

//把整数a,转化为字符串，在用strstr函数判断是否符合条件。
bool Fun(int a, int b)
{
	int c1 = 0;
	char c[100];
	char d[100];
	int i = 0;
	int j = 0;

	while (a)
	{
		c[i] = a % 10 + '0';
		a /= 10;
		i++;
	}
	while (b)
	{
		d[j] = b % 10 + '0';
		b /= 10;
		j++;
	}
	c[i] = '\0';
	d[j] = '\0';
	//char *strstr( const char *str1, const char *str2 );
	//功能：函数返回一个指针，它指向字符串str2 首次出现于字符串str1中的位置，如果没有找到，返回NULL。
	if (strstr(d, c))
		return true;
	else
		return false;

}

int test_data_classify()
{
	int i, j, k;
	int t;
	//最后输出数据的个数
	int a;
	int cnt;//计数
	int m;//序列I的个数
	int n;//序列R的个数
	int I[65535];
	int R[65535];
	int P[65535];
	int Q[1000];
	while (cin >> m)
	{
		a = 0;
		for (i = 0; i<m; i++)
		{
			cin >> I[i];
		}
		cin >> n;
		for (j = 0; j<n; j++)
		{
			cin >> R[j];
		}

		Sort(R, n);
		for (i = 0; i<n; i++)
		{
			cnt = 0;
			k = 0;
			while (R[i] == R[i + 1] && i<n - 1)
				i++;
			for (j = 0; j<m; j++)
			{
				if (Fun(R[i], I[j]))
				{
					Q[k++] = j;
					Q[k++] = I[j];
					cnt++;
				}
			}
			if (cnt > 0)
			{
				P[a] = R[i];
				P[a + 1] = cnt;
				for (t = 1; t <= 2 * cnt; t++)
				{
					P[a + 1 + t] = Q[t - 1];
				}
				a = a + 2 + 2 * cnt;
			}
		}
		cout << a << ' ';
		for (i = 0; i<a; i++)
		{
			cout << P[i];
			if (i == a - 1)
				cout << endl;
			else
				cout << ' ';
		}
	}
	return 0;
}

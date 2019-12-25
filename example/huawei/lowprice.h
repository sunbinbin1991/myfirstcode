#include <iostream>
#include <string>
using namespace std;
int getmax(int a, int b)
{
	return (a>b) ? a : b;
}
int test_lowprice()
{
	int N, m;
	int price[60][3] = { 0 };
	int value[60][3] = { 0 };
	int f[60][3200];
	int v, p, q;
	cin >> N >> m;
	N /= 10;
	for (int i = 1; i <= m; ++i)
	{
		cin >> v >> p >> q;
		v /= 10;
		if (q == 0)
		{
			price[i][0] = v;
			value[i][0] = v*p;
		}
		else
		{
			if (price[i][1] == 0)
			{
				price[i][1] = v;
				value[i][1] = v*p;
			}
			if (price[i][2] == 0)
			{
				price[i][2] = v;
				value[i][2] = v*p;
			}
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		for (int j = N; j>0; j--)
		{
			if (j >= price[i][0])
				f[i][j] = getmax(f[i - 1][j], f[i - 1][j - price[i][0]] + value[i][0]);
			if (j >= price[i][0] + price[i][1])
				f[i][j] = getmax(f[i - 1][j], f[i - 1][j - price[i][0] - price[i][1]] + value[i][0] + value[i][1]);
			if (j >= price[i][0] + price[i][2])
				f[i][j] = getmax(f[i - 1][j], f[i - 1][j - price[i][0] - price[i][2]] + value[i][0] + value[i][2]);
			if (j >= price[i][0] + price[i][1] + price[i][2])
				f[i][j] = getmax(f[i - 1][j], f[i - 1][j - price[i][0] - price[i][1] - price[i][2]] + value[i][0] + value[i][1] + value[i][2]);
		}
	}
	cout << f[m][N] * 10 << endl;
	return 0;
}
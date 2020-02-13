#pragma once
#include<stdio.h>
#include<iostream>
using namespace std;

int inc(int a)
{
	return (++a);
}

int multi(int *a, int *b, int *c)
{
	return (*c = *a* *b);
}

typedef int(*FUNC1)(int in);

typedef int(*FUNC2)(int*, int*, int*);

void show(FUNC2 fun, int arg1, int *arg2)
{
	FUNC1 p = &inc;
	int temp = p(arg1);
	fun(&temp, &arg1, arg2);
	printf("%d\n", *arg2);
}

int test_char_str()
{
	//char p1[10] = "abcd", *p2, str[10] = "xyz";

	//p2 = "ABCD";
	//strcpy(str + 2, strcat(p1 + 2, p2 + 1));
	//printf(" %s", str);

	if ('\0' == 0)putchar('X');
	if ('\0' == 0)putchar('Y');
	if ('a' > 'b')putchar('Z');
	int i = 5, k;

	k = (++i) + (++i) + (i++);

	printf("%d,%d", k, i);
	printf("\n");

	string tt;
	tt[1];
	return 0;
}

void test_string() {
	char ptr_A[] = "greet";
	char *ptr_B = "greet";
	const char *ptr_C = "greeter";
	char * const ptr_D = "greeter";//ptr_d data could not change!
	const char * const ptr_E = "greeter";
	ptr_C = "D";
	char *const name = new char[5];
	char a = '\82';
	name[3] = char('q');
	//ptr_D = "H";//error when build;
}

struct _THUNDER {
	int iVersion;
	char cTag;
	char cAdv;
	char cAdv2;
	char cAdv3;
	int iUser;
	char cEnd;
}Thunder;//ËÄ×Ö½Ú¶ÔÆë

void test_struct() {
	int sz = sizeof(Thunder);
	printf("sz = %d\n", sz);
}

using namespace std;
vector<int>g[10];
int ans = 0;
void dfs(int x) {
	if (g[x].size() == 0) {
		ans++;
		return;
	}
	for (int i = 0; i < g[x].size(); ++i) {
		dfs(g[x][i]);
	}
}
int test_vector() {
	int n, x;
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i) {
		scanf("%d", &x);
		g[x].push_back(i);
	}
	
	dfs(1);
	cout << ans << endl;
	return 0;
}

char* getMem(void) {
	char p[] = "tt";
	p[5] = 0x0;
	return p;
}
void test(void) {
	char *s = 0x0;
	s = getMem();
	printf(s);
}

int test_basic()
{
	//int a;
	//show(multi, 10, &a);

	//test_struct();

	//char a[] = "xyz";
	//char  b[] = { 'x','y','z' };

	//printf("%d %d \n", sizeof(a), sizeof(b));

	/*int i, j, m = 6, n = 4, *p = &n, *q = &m;

	i = p == &m;
	j = (-*p) / (*q) + 7;

	printf("i=%d,j=%d\n", i, j);*/

//	test_vector();

	//test();
	short si = -32767;
	unsigned short usi = si;
	char msg[20];
	sprintf(msg, "tt = %d ff%f", 1, 1);
	printf("%s\n", msg);
	int s = 100;
	printf("%d\n", 100>>1);
	//printf("end\n");
	return 0;
}
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
int test_basic()
{
	//int a;
	//show(multi, 10, &a);

	test_struct();
	return 0;
}
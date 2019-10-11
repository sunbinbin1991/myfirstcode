#include"base.h"
#include"utils.hpp"


int base::stringPattern(string T, string p, int pos) {

	int i = 0;
	int j = 0;
	int next[255];
	get_next(T,next);
	while (i < (int)T.length() && j < (int)p.length())
	{
		if (j == 0 || T[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j == (int)p.length())
	{
		return i - j;
	}
	return -1;
}

void base::PrintToMaxOfNDigits(int n) {
	if (n <= 0) {
		return;
	}

	char *num = new char[n + 1];
	memset(num, '0', n);
	num[n] = '\0';
	
	while (!Increment(num)) {
		printf(num);
		printf("\n");
	}
	delete []num;
}
//#include"typedef.h"
void get_next(string p, int *next) {

	next[0] = -1;           //while the first char not match, i++,j++
	int j = 0;
	int k = -1;
	while (j < (int)p.length() - 1)
	{
		if (k == -1 || p[j] == p[k])
		{
			j++;
			k++;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}


	/*int i, j;
	i = 0;
	j = 0;
	next[0] = 0;
	while (i < T.length()) {
	if (j == 0 || T[i] == T[j]) {
	++i;
	++j;
	next[i] = j;
	}
	else {
	j = next[j];
	}
	}*/
}

bool Increment(char* num) {
	bool isOverflow = false;
	int len = strlen(num);
	int nTakeOver = 0;//控制是否有进位
	for (int i = len-1; i >= 0; i--) {
		int nSum = num[i] - '0' + nTakeOver;
		if (i == len - 1)
			++nSum;

		if (nSum >= 10) {
			if (i == 0) {
				isOverflow = true;
			}
			else {
				nTakeOver = 1;
				nSum -= 10;
				num[i] = '0';
			}
		}
		else {
			num[i] = '0' + nSum;
			break;
		}
	}
	return isOverflow;
}

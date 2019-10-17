//#include"typedef.h"
void printfNum(int num) {
	printf("%d\t", num);
}

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

bool scannUnsignedInteger(const char** str) {
	const char* before = *str;
	while (**str!='\0'&&**str>='0'&&**str<='9')
		++(*str);

	//printf("%d %d %d 2\n ", &(**str), &(*str),&(str));
	return *str > before;
}
 
bool scannInteger(const char** str) {
	if (**str == '+' || **str == '-') {
		++(*str);
	}
	return scannUnsignedInteger(str);
}

void PrintMatrixClockCircle(int **data,int col, int row,int start) {
	if (data == nullptr) {
		return;
	}
	int endY = row - start - 1;
	int endX = col - start - 1;
	//--->
	for (int i = start; i <= endX; i++)
	{
		int num = data[start][i];
		printfNum(num);
	}
	printf("\n");
	//----↓
	if (endX > start) {
		for (int i = start + 1; i <= endY; i++)
		{
			int num = data[i][endX];
			printfNum(num);
		}
	}
	printf("\n");
	//←---- 
	if (endX > start&&endY > start) {
		for (int i = endX-1; i >=start; i--)
		{
			int num = data[endY][i];
			printfNum(num);
		}
	}
	printf("\n");
	//----↑
	if (start < endX && start < endY - 1) {
		for (int i = endY-1; i >=start+1; i--)
		{
			int num = data[i][start];
			printfNum(num);
		}
	}
	printf("\n");

	
}
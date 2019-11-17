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

void FindPath(BinaryTreeNode* pRoot, int expectSum, std::vector<int> path, int currentsum) {
	if (pRoot == nullptr) {
		return;
	}
	path.push_back(pRoot->m_nValue);
	currentsum += pRoot->m_nValue;
	if (pRoot->m_pLeft == nullptr&& pRoot->m_pRight == nullptr&& expectSum == currentsum) {
		printf("find a path");
		std::vector<int>::iterator itr = path.begin();//这种方法遍历数组的好处在哪？？更快了？？？
		for (; itr != path.end(); ++itr) {
			printf(" %d ", *itr);
		}
		printf("\n");
	}
	if (pRoot->m_pLeft != nullptr) {
		FindPath(pRoot->m_pLeft, expectSum, path, currentsum);
	}
	if (pRoot->m_pRight != nullptr) {
		FindPath(pRoot->m_pRight, expectSum, path, currentsum);
	}

	path.pop_back();


}

void  cloneComplexListNode(ComplexListNode* pHead) {
	if (pHead == nullptr) {
		return ;
	}
	ComplexListNode* pNode = pHead;
	while (pNode != nullptr) {
		ComplexListNode * tmpNode = new ComplexListNode();
		tmpNode->m_value = pNode->m_value;
		tmpNode->m_pNext = pNode->m_pNext;
		tmpNode->m_pSibling = pNode->m_pSibling;
		pNode->m_pNext = tmpNode;
		pNode = pNode->m_pNext;
	}
}

void connectSimpleNode(ComplexListNode* pHead) {
	ComplexListNode* pNode = pHead;
	while (pNode!=nullptr)
	{
		ComplexListNode* tmpNode = pNode->m_pNext;
		if (pNode->m_pSibling != nullptr) {
			tmpNode->m_pSibling = pNode->m_pSibling->m_pNext;//
			//tmpNode->m_pSibling = pNode->m_pSibling;//deference beteen upper
		}
		pNode = pNode->m_pNext;
	}
}

void reconnectNode(ComplexListNode* pHead) {
	ComplexListNode *pNode = pHead;
	ComplexListNode *pCloneHead = nullptr;
	ComplexListNode *pCloneNode = nullptr;
	if (pNode != nullptr) {
		pCloneHead = pCloneNode = pNode->m_pNext;
		pNode->m_pNext = pCloneHead->m_pNext;
		pNode = pNode->m_pNext;
	}
	while (pNode != nullptr) {
		pCloneNode->m_pNext = pNode->m_pNext;
		pCloneNode = pCloneNode->m_pNext;
		pNode->m_pNext = pCloneNode->m_pNext;
		pNode = pNode->m_pNext;
	}
}

void permutationPart(char* pstr, char* pbegin) {
	if(*pbegin=='\0')
	{
		printf("%s\n", pstr);
	}
	else
	{
		for (char* pch = pbegin;*pch!='\0';++pch)
		{
			char temp = *pch;
			*pch = *pbegin;
			*pbegin = temp;
			permutationPart(pstr, pbegin+1);

			temp = *pch;
			*pch = *pbegin;
			*pbegin = temp;
		}
	}
}

void Permutation(char* pStr, char* pBegin)
{
	if (*pBegin == '\0')
	{
		printf("%s\n", pStr);
	}
	else
	{
		for (char* pCh = pBegin; *pCh != '\0'; ++pCh)
		{
			char temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;

			Permutation(pStr, pBegin + 1);

			temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
		}
	}
}

int PowerBase10(unsigned int n) {
	int result = 1;
	for (size_t i = 0; i < n; i++)
	{
		result *= 10;
	}
	return result;
}

int numofone(char * pStr) {
	if (!*pStr || *pStr<'0' || *pStr>'9' || *pStr == '\0') {
		return 0;
	}
	int first = *pStr- '0';
	unsigned int len = static_cast<unsigned int>(strlen(pStr));
	if (len == 1 && first == 0) {
		return 0;
	}
	if (len == 1 && first > 0) {
		return 1;
	}

	int numfirstdigit = 0;
	if (first > 1) {
	}
	else if (first ==1) {
		numfirstdigit = atoi(pStr + 1) + 1;
	}

	int numotherDig = first * (len - 1)*PowerBase10(len - 1);
	int numRecur = numofone(pStr + 1);
	return numfirstdigit + numotherDig + numRecur;




}

int countOfInteger(int digit) {
	if (digit == 1) {
		return 10;
	}
	int count = (int)std::pow(10, digit - 1);
	return count;
}

int beginNumber(int dig) {
	if (dig == 1)
		return 0;
	return (int)std::pow(10, dig-1);
}

int digAtIndex2(int index,int dig) {
	int number = beginNumber(dig) + index / dig;
	int indexfromright = dig - index%dig;
	for (size_t i = 0; i < indexfromright; i++)
	{
		number /= 10;
	}
	return number % 10;
}


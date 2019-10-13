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

void base::DeleteNode(ListNode** pListNode, ListNode* pToBeDel) {
	if (!pListNode||*pListNode == nullptr|| pToBeDel==nullptr) {
		return;
	}
	if (pToBeDel->next != nullptr) {
		//listnode need del is not tail
		pToBeDel->m_key = pToBeDel->next->m_key;

		ListNode * temp = pToBeDel->next;

		pToBeDel->next = temp;
	}
	else if (* pListNode==pToBeDel) {
		//listnode has only one node
		delete pToBeDel;
		pToBeDel = nullptr;
		*pListNode = nullptr;
	}
	else {
		//listnode has a lot of node,del the last one
		ListNode * pNode = *pListNode;
		while (pNode->next !=pToBeDel)
		{
			pNode = pNode->next;
		}

		pNode->next = nullptr;
		delete pToBeDel;
		pToBeDel = nullptr;



	}
	



}    

bool base::isNumString(const char* str){
	if (str == nullptr) {
		return false;
	}
	bool isNum = false;
	isNum = scannInteger(&str);
	if (*str == '.') {
		++str;
		isNum = scannUnsignedInteger(&str) || isNum;
	}
	if (*str == 'e' || *str == 'E') {
		++str;
		isNum = isNum && scannInteger(&str);
	}

	return isNum && *str == '\0';	
}
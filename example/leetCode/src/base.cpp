#include"base.h"
#include"utils.hpp"
#include <stack>
#include <queue>
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

void base::RecorderOldEven(int *data, int len) {
	if (data == nullptr || len <= 0){
		return;
	}

	int* p_begin = data;
	int* p_end = data+len-1;

	while (p_begin < p_end) {
		if (p_begin < p_end&&(*p_begin & 0x01) != 0) {
			p_begin++;
		}
		if (p_begin < p_end&&(*p_end & 0x01) == 0) {
			p_end--;
		}
		//这种操作可以交换指针对应的值；
		if (p_begin < p_end) {
			int temp = *p_begin;
			*p_begin = *p_end;
			*p_end = temp;
		}
	}

}

void base::PrintMatrixClockwisely(int **data, int col, int row) {
	if (data == nullptr || col <= 0 || row <= 0) {
		return;
	}
	int start = 0;

	while (col > start * 2 && row > start * 2) {
		PrintMatrixClockCircle(data, col, row, start);
		start++;
	}

}
/*
借助辅助栈，判定序列依次读入，若辅助队列为空，则直接和原始队列比较，直到获得相同数据；
若是非相同数据，则将数据存入辅助栈
*/
bool base::isPopOrder(int *sPush, int * sPop, int nlength) {
	if (sPop == nullptr || sPush == nullptr) {
		return false;
	}
	bool res = false;
	std::stack<int> stack_container;
	if (sPush != nullptr&&sPop != nullptr&&nlength > 0) {
		const int* pNextPush = sPush;
		const int* pNextPop = sPop;
		
		while (pNextPop - sPop < nlength) {//判定序列依次读入，当=nlength时，代表数据已经读完了
			while (stack_container.empty() || stack_container.top() != *pNextPop) {
				if (pNextPush - sPush == nlength) {
					break;
				}
				stack_container.push(*pNextPop);
				pNextPush++;
			}
			
			if (stack_container.top() != *pNextPop) {
				break;
			}
			stack_container.pop();
			pNextPop++;

			if (stack_container.empty() && pNextPop - sPop == nlength) {
				res = true;
			}
		}
		return res;
	}
};

void base::printBinaryTreeFromTomToBottom(BinaryTreeNode* pTreeRoot) {
	if (pTreeRoot==nullptr)
	{
		return ;
	}

	std::deque<BinaryTreeNode* > dequeTree;

	dequeTree.push_back(pTreeRoot);

	while (dequeTree.size()) {
	
		BinaryTreeNode* front = dequeTree.front();
	
		dequeTree.pop_front();

		printf("%d ", front->m_nValue);
		
		if (front->m_pLeft) {
			dequeTree.push_back(front->m_pLeft);
		}

		if (front->m_pRight) {
			dequeTree.push_back(front->m_pRight);
		}
	}


};

void base::printBinaryTreeFromLeftToRight(BinaryTreeNode* pTreeRoot) {
	if (pTreeRoot==nullptr)
	{
		return;
	}

	std::queue<BinaryTreeNode* > queueTree;

	queueTree.push(pTreeRoot);

	bool isPrintAll = false;
	int nextLevel = 0;
	int toBeprint = 1;
	while (!queueTree.empty()) {
		BinaryTreeNode *front = queueTree.front();
		printf("%d\t", front->m_nValue);
		if (front->m_pLeft != nullptr) {
			queueTree.push(front->m_pLeft);
			nextLevel++;
			//printf("%d", front->m_nValue);
		}

		if (front->m_pRight != nullptr) {
			queueTree.push(front->m_pRight);
			nextLevel++;
			//printf("%d", front->m_nValue);
		}
		queueTree.pop();
		--toBeprint;
		if (toBeprint == 0) {
			printf("\n");
			toBeprint = nextLevel;
			nextLevel = 0;
		}
	}


};

void base::prinBinaryTreeZway(BinaryTreeNode* pTreeRoot) {
	if (pTreeRoot == nullptr) return;
	
	stack<BinaryTreeNode*> stackcomb[2];
	int current = 0;
	int next = 1;
	stackcomb[0].push(pTreeRoot);

	while (!stackcomb[0].empty() || !stackcomb[1].empty()) {
		BinaryTreeNode* front = stackcomb[current].top();
		printf("%d ", front->m_nValue);
		stackcomb[current].pop();
		if (current != 0) {
			if (front->m_pRight != nullptr) {
				stackcomb[next].push(front->m_pRight);
			}
			if (front->m_pLeft != nullptr) {
				stackcomb[next].push(front->m_pLeft);
			}
		}
		else {
			if (front->m_pLeft != nullptr) {
				stackcomb[next].push(front->m_pLeft);
			}
			if (front->m_pRight != nullptr) {
				stackcomb[next].push(front->m_pRight);
			}
		}
		if (stackcomb[current].empty()) {
			printf("\n");
			current = 1 - current;
			next = 1 - next;
		}		
	}
}

bool base::VerifySeqOfBST(int seq[], int length) {

	if (seq == nullptr || length <= 0) {
		return false;
	}
	//find root
	int root_value = seq[length-1];
	//find left 
	int right_index;
	for (size_t i = 0; i < length-1; i++)
	{
		if (seq[i] > root_value) {
			right_index = i;
			break;
		}
	}
	//find right
	for (size_t i = root_value; i < length-1; i++)
	{
		if (seq[i] < root_value) {
			return false;
		}
	}

	////judge left
	//for (size_t i = 0; i < right_index -1; i++)
	//{
	//	if (seq[i] > root_value) {
	//		return false;
	//	}
	//}

	bool left = true;
	bool right = true;
	if (right_index > 0) left = VerifySeqOfBST(seq, right_index);
	if (right_index <= length -1) right = VerifySeqOfBST(seq+right_index, length-1-right_index);

	return left&&right;

};

void base::findPath(BinaryTreeNode *pRoot, int expectSum) {
	if (pRoot == nullptr) {
		return;
	}
	std::vector<int> path;
	int currSum = 0;
	FindPath(pRoot, expectSum, path, currSum);
};

void base::cloneComplexListNode(ComplexListNode* pHead) {
	cloneComplexListNode(pHead);
	connectSimpleNode(pHead);
	reconnectNode(pHead);	
};

void base::permutation(char* pstr) {
	if (pstr==nullptr)
	{
		return;
	}
	Permutation(pstr,pstr);

};

int base::halfInArray(int *array, int length) {
	if (array == nullptr || length <= 0) {
		return 0;
	}

	int result = array[0];
	int times = 1;
	for (size_t i = 1; i < length; i++)
	{
		if (times == 0) {
			result = array[i];
			times = 1;
		}
		else if (result == array[i]) {
			times++;
		}
		else
		{
			times--;
		}
	}
	return result;


};

void base::getTopKGreater(const vector<int>data, inSet& inset, int topK) {
	inset.clear();
	if (topK < 0 || data.size() < topK) {
		return;
	}


	for (size_t i = 0; i < data.size(); i++)
	{
		if (inset.size() < topK) {
			inset.insert(data[i]);
		}
		{
			inSetIterator itrLeast = inset.begin();
			if (data[i] > *(inset.begin()) ){
				inset.erase(itrLeast);
				inset.insert(data[i]);
			}
		}
	}
};

int base::getConsequentMax(int * arry, int len){
	if (arry == nullptr || len <= 0) {
		return 0;
	}
	int curr_max = 0;
	int final_max = 0;
	for (size_t i = 0; i < len; i++)
	{
		curr_max += arry[i];
		if (curr_max < 0) {
			curr_max = 0;
		}
		/*if (curr_max <= 0) {
			curr_max = arry[i];
		}
		else {
			curr_max += arry[i];
		}*/

		if (curr_max > final_max)
		{
			final_max = curr_max;
		}
	}
	return final_max;
} 

int base::getNumsofOneBeforeN(int n){
	if (n <= 0) {
		return 0;
	}
	char strN[50];
	sprintf(strN,"%d", n);
	return numofone(strN);
}

int base::digAtIndex(int index) {
	if (index <= 0) {
		return 0;
	}
	int digit = 0;
	while (true) {
		int num = countOfInteger(digit);
		if (index < num*digit) {
			return digAtIndex2(index, digit);
		}
		index -= digit*num;
	}
	{
		digit++;
	}
	return -1;
}


void base::printMinNumber(int* number, int length) {
	if (number == nullptr || length <= 0) {
		return;
	}

	char** strNum = (char**)(new int[length]);
	for (size_t i = 0; i < length; i++)
	{
		strNum[i] = new char[g_max_num_len + 1];
		sprintf(strNum[i], "%d", number[i]);
	}
	
	//Sorts the num elements of the array pointed to by base, each element size bytes long, using the compar function to determine the order.
	qsort(strNum, length, sizeof(char*), compare);
	for (size_t i = 0; i < length; i++)
	{
		printf("%s", strNum[i]);
	}
	printf("\n");

	for (size_t i = 0; i < length; i++)
	{
		delete[] strNum[i];
	}
	delete[] strNum;
};

int base::changeBottle3(int num) {
	printf("hello num=%d\n", num);
	int res = 0;
	if (num <= 1) {
		return res;
	}
	if (num == 2) {
		printf("num == 2%d", res++);
		return res;
	}
	int total_res = 0;
	res = num /  3;
	total_res = num % 3;
	total_res += res;
	printf("res=%d, total = %d\n",res, total_res);
	return res+changeBottle3(total_res);
};

bool base::hasCircle(ListNode *head) {
	ListNode *firstNode = head;
	ListNode *secondNode = head;
	if(firstNode->next != nullptr&&secondNode->next != nullptr) {
		firstNode = firstNode->next;
		secondNode = secondNode->next->next;
		if(firstNode == secondNode) {
			return true;
		}
	}
	return false;
}
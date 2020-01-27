#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void calIncSub(vector<int> quene, vector<int> &Num) {
	for (int i = 1; i<quene.size(); i++)
		for (int j = i - 1; j >= 0; j--)
			if (quene[j]<quene[i] && Num[i]<Num[j] + 1)  //�ҵ�ǰ��ȵ�ǰС�ģ��ҡ��ܻ�õ�����Ӵ�������
				Num[i] = Num[j] + 1;
}

int dp_delnum2makeIncDec() {
	int n;
	int h;

	while (cin >> n) {
		vector<int> quene;
		vector<int> incNum(n, 1);  //��ʼ��Ϊn��1
		vector<int> decNum(n, 1);
		vector<int> totalNum;
		for (int i = 0; i<n; i++) {
			cin >> h;
			quene.push_back(h);
		}
		calIncSub(quene, incNum);    //�ҵ����Ӵ�����
		reverse(quene.begin(), quene.end()); //��ת�����ҷ�����Ӵ�����
		calIncSub(quene, decNum);
		reverse(decNum.begin(), decNum.end());   //�������������ݼ�
		int max = 0;
		for (int i = 0; i<n; i++) {
			totalNum.push_back(incNum[i] + decNum[i]);
			if (totalNum[i]>max)
				max = totalNum[i];
		}
		cout << n - max + 1 << endl;
	}
	return 0;
}
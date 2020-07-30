#pragma once
//https://www.nowcoder.com/practice/bfd8234bb5e84be0b493656e390bdebf?tpId=37&tqId=21284&tPage=3&rp=&ru=%2Fta%2Fhuawei&qru=%2Fta%2Fhuawei%2Fquestion-ranking
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
using namespace std;
// �ݹ�ѭ����������˳���?


//��f(m, n) Ϊm��ƻ����n�����ӵķŷ���Ŀ�����ȶ�n�����ۣ�
//��n>m���ض���n - m��������Զ���ţ�ȥ�����Ƕ԰ڷ�ƻ��������Ŀ������Ӱ�졣��if(n>m) f(m, n) = f(m, m)
//��n <= m����ͬ�ķŷ����Էֳ����ࣺ
	//1��������һ�����ӿ��ţ����൱��f(m, n) = f(m, n - 1);
	//2���������Ӷ���ƻ�����൱�ڿ��Դ�ÿ���������õ�һ��ƻ����
	//��Ӱ�첻ͬ�ŷ�����Ŀ����f(m, n) = f(m - n, n).
//���ܵķ�ƻ���ķŷ���Ŀ�������ߵĺͣ��� f(m, n) = f(m, n - 1) + f(m - n, n)
//�ݹ��������˵����
//��n = 1ʱ������ƻ�����������һ����������Է��أ���
//��û��ƻ���ɷ�ʱ������Ϊ���ַŷ���
//�ݹ������·����һ��n���𽥼��٣��ջᵽ�����n == 1;
//�ڶ���m���𽥼��٣���Ϊn>mʱ�����ǻ�return f(m, m)�������ջᵽ�����

int getNumsDevides(int num, int n) {
	if (num == 0 || n == 1) return 1;
	
	if (num < n) {
		return getNumsDevides(num, num);
	}
	else {
		printf("%d %d\n", num, n-1);
		printf("%d %d\n", num-n, n);
		return getNumsDevides(num,  n-1)+ getNumsDevides(num-n, n);
	}
}

int test_getNumsDevides() {
	int mApple,nPlasic;
	while (cin>> mApple >> nPlasic){
		int res = getNumsDevides(mApple, nPlasic);
		cout << res << endl;
	}
	return 0;
}
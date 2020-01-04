#pragma once
#include "iostream"
#include <set>
#include <map>
using namespace std;
// set input data only one std::set<int>
//map  �����Ľ���Ѿ��ǰ��ռ�ֵ���й�������
//url:https://www.nowcoder.com/practice/de044e89123f4a7482bd2b214a685201?tpId=37&tqId=21231&rp=0&ru=/ta/huawei&qru=/ta/huawei/question-ranking

//���ݱ��¼��������������ֵ��int��Χ������������Ա�������ͬ�ļ�¼���кϲ���������ͬ��������ֵ����������㣬�������keyֵ������������
//
//�������� :
//�������ֵ�Եĸ���
//Ȼ������ɶԵ�index��valueֵ���Կո����
//
//������� :
//����ϲ���ļ�ֵ�ԣ����У�


void test_sort_key_value() {
	int total_nums;
	cin >> total_nums;
	std::set<int> dataset;
	std::map<int, int> keyvalmap;
	while (total_nums--) {
		int first_key;
		cin >> first_key;
	
		int first_value;
		cin >> first_value;

		if (keyvalmap.find(first_key) != keyvalmap.end()){
			keyvalmap[first_key] += first_value;
		}
		else {
			keyvalmap[first_key] = first_value;
		}
	}


	for (auto itr = keyvalmap.begin();itr!= keyvalmap.end();itr++)
	{
		printf("%d %d ",itr->first, itr->second);
	}

}
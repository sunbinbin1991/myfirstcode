#pragma once
#include "iostream"
#include <set>
#include <map>
using namespace std;
// set input data only one std::set<int>
//map  遍历的结果已经是按照键值进行过排序了
//url:https://www.nowcoder.com/practice/de044e89123f4a7482bd2b214a685201?tpId=37&tqId=21231&rp=0&ru=/ta/huawei&qru=/ta/huawei/question-ranking

//数据表记录包含表索引和数值（int范围的整数），请对表索引相同的记录进行合并，即将相同索引的数值进行求和运算，输出按照key值升序进行输出。
//
//输入描述 :
//先输入键值对的个数
//然后输入成对的index和value值，以空格隔开
//
//输出描述 :
//输出合并后的键值对（多行）


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
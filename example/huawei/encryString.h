#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<map>
//https://www.nowcoder.com/practice/e4af1fe682b54459b2a211df91a91cf3?tpId=37&tqId=21259&tPage=2&rp=&ru=%2Fta%2Fhuawei&qru=%2Fta%2Fhuawei%2Fquestion-ranking
using namespace std;

void encryString(const string&  Key,const string& input) {
	const string helper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string PlainText;
	map<char, bool> dic;
	int len = Key.length();
	string newKey;
	for (int i = 0; i < len; i++)
	{
		char tmp = Key.at(i);
		if (tmp >= 'a'&&tmp <= 'z') {
			tmp -= 32;
		}
		if (dic.find(tmp) == dic.end()) {
			if (tmp >= 'A'&&tmp <= 'Z') {
				dic[tmp] = false;
				newKey += tmp;
			}
		}
	}
	string codebook =newKey;
	for (int i =0; i < 26; i++)
	{
		char tmp = helper.at(i);
		if (dic.find(tmp) == dic.end()) {
			codebook += tmp;
		}
	}
	string res;
	for (int i = 0; i < input.length(); i++)
	{
		char tmp = input.at(i);
		char c_res = tmp;
		if (tmp >= 'A'&&tmp <= 'Z') {
			c_res = codebook[tmp - 'A'];
		}
		if (tmp >= 'a'&&tmp <= 'z') {
			c_res = codebook[tmp - 'a']+32;
		}
		res += c_res;
	}
	printf("newKey len %s\n", newKey.c_str());
	printf("dic len %d\n", dic.size());
	printf("codebook %s\n", codebook.c_str());
	printf("res %s\n", res.c_str());

}

void test_encryString() {
	string key= "igtxbesmnyrehanvuvqhukrtmpynmpdvjlppuq";
	string input = "wiumbxibguwicjfyvkznbqzvo";
	//while (cin >> key >> input) {
		encryString(key,input);
	//}
}
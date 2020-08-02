#pragma once
#include<vector>
#include<iostream>
#include<unordered_map>
// ά������map,����һ��Ϊ��ʼmap,��¼�ַ���������
// �ڶ���map���ڼ�¼����ʱ�ĸ���.����map�������,�����Ϊ�ܹ�����Ҫ��
// �ӵ�һ���ַ�����,ֱ�����һ���ַ���
using namespace std;
vector<int> findSubstring(string s, vector<string>& words)
{
    //�������ֱ���ų�
    if (s.empty() || words.empty())return{};

    //��Ž��������
    vector<int> result;

    //���������еĵ��ʵĴ�С���������Լ��ܳ���
    int one_word = words[0].size();
    int word_num = words.size();
    int all_len = one_word*word_num;

    //��������->���ʸ�����ӳ��
    unordered_map<string, int> m1;
    for (const auto& w : words)m1[w]++;

    for (int i = 0; i<one_word; ++i) {
        //left��rigth��ʾ���ڵ����ұ߽磬count����ͳ��ƥ��ĵ��ʸ���
        int left = i, right = i, count = 0;

        unordered_map<string, int>m2;

        //��ʼ��������
        while (right + one_word <= s.size()) {
            //��s����ȡһ�����ʿ�����w
            string w = s.substr(right, one_word);
            right += one_word;//�����ұ߽�����һ�����ʵĳ���

            if (m1.count(w) == 0) {//�˵��ʲ���words�У���ʾƥ�䲻�ɹ�,Ȼ�����õ��ʸ��������ڱ߽硢�Լ�m2
                count = 0;
                left = right;
                m2.clear();
            } else {//�õ���ƥ��ɹ�����ӵ�m2��
                m2[w]++;
                count++;
                while (m2.at(w)>m1.at(w))//һ������ƥ���Σ���Ҫ��С���ڣ�Ҳ����left����
                {
                    string t_w = s.substr(left, one_word);
                    count--;
                    m2[t_w]--;
                    left += one_word;
                }
                if (count == word_num)result.push_back(left);
            }
        }
    }
    return result;
}

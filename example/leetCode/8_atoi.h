#pragma once
#include<iostream>
using namespace std;

class Solution_atoi {
public:

	int myAtoi(string str)
	{
		long long int ans = 0;
		int flag = 0;//��ÿһλ�ֱ�洢״̬��Ϣ����ʼλ0000��ֻ�õ���λ��
		for (int i = 0; i<str.size(); i++) {
			if ((flag & 1) == 0 && str[i] == ' ')
				continue;
			flag |= 1;//��ʱλ0001��������ַ��жϽ���
			if ((flag & 14) == 0 && (str[i] == '+' || str[i] == '-')) {//14=1110��3��1�ֱ����������֡�����λΪ��+���ͷ���λΪ��-������Ȼ��Ҫ����λ��Ϊ0�ſ��Խ��з���λ�ж�
				flag |= (str[i] == '-' ? 2 : 4);//'+'���0100ȡ�򣬼���4'-'���0010ȡ��
				continue;
			}
			if (str[i] >= '0' && str[i] <= '9') {
				flag |= 8;
				ans = 10 * ans + str[i] - '0';//'0'������ascll��ת�������֣��������������
				if (ans>(long long)INT_MAX)//ÿ��һλ���ֶ���������жϣ���ֹ���ֹ���
					return (flag & 2) == 2 ? INT_MIN : INT_MAX;
				continue;
			}
			break;//�ж��״γ������ֺ��Ƿ���ַ������ַ������������ѭ��
		}
		return (flag & 2) == 2 ? -ans : ans;
	}
};

int myAtoi(string str)
{
    if (str.empty()) return 0;

    int flag = 1;
    int startIndex = 0;
    string subString = "";
    int i = 0;
    while (str[i] == ' ') {
        i++;
    }
    if (str[i] == '+') flag = 1;
    if (str[i] == '-') flag = -1;
    int sum = 0;
    if (str[i] == '-' || str[i] == '+') i++;
    while (i < str.size() && isdigit(str[i])) {
        int res = str[i] - '0';
        if (sum > INT_MAX / 10 || sum == INT_MAX && res > 7) {
            return flag > 0 ? INT_MAX : INT_MIN;
        }
        sum = 10 * sum + res;
        i++;
    }
    return sum * flag;
}


int test_atoi()
{
    string str = "-42";
    int res = myAtoi(str);
	return 0;
	
}
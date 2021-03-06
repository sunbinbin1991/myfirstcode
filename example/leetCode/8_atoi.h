#pragma once
#include<iostream>
using namespace std;

class Solution_atoi {
public:

	int myAtoi(string str)
	{
		long long int ans = 0;
		int flag = 0;//用每一位分别存储状态信息，初始位0000（只用到四位）
		for (int i = 0; i<str.size(); i++) {
			if ((flag & 1) == 0 && str[i] == ' ')
				continue;
			flag |= 1;//此时位0001，代表空字符判断结束
			if ((flag & 14) == 0 && (str[i] == '+' || str[i] == '-')) {//14=1110，3个1分别代表出现数字、符号位为“+”和符号位为“-”。显然需要这三位都为0才可以进行符号位判断
				flag |= (str[i] == '-' ? 2 : 4);//'+'则和0100取或，加上4'-'则和0010取或
				continue;
			}
			if (str[i] >= '0' && str[i] <= '9') {
				flag |= 8;
				ans = 10 * ans + str[i] - '0';//'0'用来将ascll码转换成数字（利用其排序规则）
				if (ans>(long long)INT_MAX)//每加一位数字都进行溢出判断，防止数字过大
					return (flag & 2) == 2 ? INT_MIN : INT_MAX;
				continue;
			}
			break;//判断首次出现数字后是否出现非数字字符，出现则结束循环
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
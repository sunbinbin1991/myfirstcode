#include "string"
#include "iostream"
using namespace std;
bool canSuccess(const string &s) {
	if (s.length() < 2 || s.length() >= 15) return false;
	if (s.length() == 2) return s[0] == s[1];
	bool flag = false;
	auto begin = s.begin();
	auto end = s.end();
	while (end - begin > 2)
	{
		if (*begin == *(begin + 1) && *begin == *(begin + 2))
		{
			string temp1(s.begin(), begin);
			string temp2(begin + 3, end);
			flag |= canSuccess(temp1 + temp2);
		}
		else if (*begin + 1 == *(begin + 1)) {
			int midSameCount = 0;
			char mid = *(begin + 1);
			auto iter = begin + 1;
			while (*iter == mid)
			{
				midSameCount++;
				if (++iter == end)
				{
					midSameCount = -1;
					break;
				}
			}
			if (midSameCount > 0 && mid + 1 == *iter) {
				string temp1(s.begin(), begin);
				string temp2;
				temp2.insert(0, midSameCount - 1, mid);
				string temp3(iter + 1, end);
				flag |= canSuccess(temp1 + temp2 + temp3);
			}
		}
		++begin;
	}
	return flag;
}

void test_hupai() {
	string str = "1112234";
	//cin >> str;
	bool flag = canSuccess(str);
	printf("flag =%d", flag);
}
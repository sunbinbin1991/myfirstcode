#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;
int test_printRenminbi() {
	string input;
	while (cin >> input) {
		if (input.empty()) return 0;
		int length = strlen(input.c_str());
		string res = "";
		for (int i = 0; i < length; i++)
		{
			char tmp = input[i];
			if (tmp >= '0'&&tmp << '9') {
				res += "*";
				res += tmp;
				res += "*";
			}
		}
		while (res.find("**") != std::npos) {
			res = res.replace(res.find("**"), 2, "*");
		}
		printf("%s\n", res.c_str());
	}
}
#include<stdio.h>
#include<string>
#include<iostream>

using namespace std;
string toLowCase(string s) {
	char * res = new char[s.length()];
	for (int i = 0; i < s.length(); i++) {
		char temp = s[i];
		if ((90 >= (int)s[i] &&(int)s[i] >= 65) ){
			temp = (int)s[i] + 32;
		}
		res[i] = temp;
	}
	res[s.length()] = '\0';
	return res;
}
int main_temp3() {
	//printf("hello world");
	string s = "AAhfSDABDDsdfZZ";
	string res = toLowCase(s);
	std::cout<< res << res.length()<<std::endl;
	
	return -1;
}
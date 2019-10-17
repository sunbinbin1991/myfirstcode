#include<stdio.h>
#include<vector>
#include<iostream>
#include <map>
using namespace std;

int uniqueMorseRepresentations(vector<string>& words) {
	string str[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
	vector <string> letter;
	map< string,string> mymap;
	for (int i = 0; i < words.size(); i++) {
		string temp;
		for (int j = 0; j < words[i].length(); j++) {
			int letterNum = (int)(words[i].at(j))-97;
			temp.append(str[letterNum]);
		}
		cout << temp.c_str() << endl;
		mymap[temp.c_str()]= "ss";
	}
	cout << mymap.size()<<endl;
	return mymap.size();
}


int main_temp4() {
	vector <string> words;
	words.push_back("gin");
	words.push_back("zen");
	words.push_back("gig");
	words.push_back("msg");
	int res = uniqueMorseRepresentations(words);
	//std::cout << words[0].c_str() << endl;
	return -1;
}
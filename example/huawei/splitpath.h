#pragma once
#include <iostream>
#include <string>
#include <iterator>
#include <map>
#include <sstream>
//#include <stringstream>
using namespace std;

template<typename Out>
void split(const std::string &s, char delim, Out result) {
	std::stringstream ss;
	ss.str(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		*(result++) = item;
	}
}

std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, std::back_inserter(elems));
	return elems;
}

std::string splitpath(const std::string& path) {
	std::vector<std::string>strs =  split(path, '\\');
	std::string res = strs[strs.size() - 1];
	if (strlen(res.c_str()) > 16) {
		std::string res2(res.end() - 16, res.end());
		return res2;
	}
	else {
		return res;
	}	
}

using pair_key = std::pair<string, int>;
void count_error_reocrd(const std::string& record, int num,
	std::map<pair_key, int>& pathset) {
	string filename = splitpath(record);

	std::pair<string, int> key;
	key.first = filename;
	key.second = num;
	if (pathset.find(key) != pathset.end()) {
		pathset[key] += 1;
	}
	else {
		pathset[key] = 1;
	}
}


void test_splitpath() {
	string record;
	std::map<pair_key, int> pathset;
	int count = 0;
	while (cin>>record) {
		int num;
		cin >> num;
		count_error_reocrd(record, num,pathset);
		if (pathset.size()>7) {
			break;
		}
	
	}

	for (auto itr = pathset.begin(); itr != pathset.end(); itr++)
	{
		printf("%s %d %d", itr->first.first.c_str(), itr->first.second, itr->second);
	}
}

链接：https://www.nowcoder.com/questionTerminal/2baa6aba39214d6ea91a2e03dff3fbeb?f=discussion
来源：牛客网

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string getFileName(string path) {
	int pos = path.rfind('\\');
	return path.substr(pos + 1);
}

string modifyName(string name) {
	if (name.size() > 16) {
		name = name.substr(name.size() - 16);
	}

	return name;
}

struct ErrRecord {
	string file;
	int lineNo;
	int count;

	ErrRecord(string file, int lineNo) {
		this->file = file;
		this->lineNo = lineNo;
		count = 1;
	}

	bool operator==(const ErrRecord & a) {
		return (file == a.file) && (lineNo == a.lineNo);
	}
};

int test_main() {

	string file;
	int lineNo;
	vector<ErrRecord> myvec;
	while (cin >> file >> lineNo) {
		ErrRecord record(getFileName(file), lineNo);
		auto res = find(myvec.begin(), myvec.end(), record);
		if (res == myvec.end()) {
			myvec.push_back(record);
		}
		else {
			res->count++;
		}
	}

	int count = 0;
	for (auto item : myvec) {
		if (count + 8 >= myvec.size()) {
			cout << modifyName(item.file) << " " << item.lineNo << " "
				<< item.count << endl;
		}
		count++;
	}


	return 0;
}
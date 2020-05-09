#include <iostream>
#include <vector>
#include <deque>

using namespace std;
bool checkHasdumplate(const string &input){
    int letter[26] = {0};
    for(int i = 0; i< input.size(); i++){
        letter[input[i]-'a'] ++;
    }
    for(int i = 0; i<26; i++){
        if(letter[i]>1){
            return true;
        }
    }
    return false;
}

int lengthOfLongestSubstring(string s) {
    if(s.empty()) return 0;
    int max_len = 1;
    vector<char> res;
    auto begin = s.begin();
    string maxStr = s.substr(0,1);
    for(int i = 1; i < s.size(); i++){
        bool has_let = false;
        for (size_t j = 0; j < maxStr.size(); j++)
        {
            if(s[i] == maxStr[j]){
                has_let = true;
                if(j == 0) {
                    //maxStr = s.substr(i - max_len + 1,max_len);
                }
                break;
            }
        }
       
		string tmp = s.substr(i - max_len, max_len + 1);
		//cout << "tmp = " << tmp << endl;
        if(!checkHasdumplate(tmp)){
			maxStr = tmp;
            max_len = maxStr.size();
			//cout << "maxStr22 = " << maxStr << endl;
		}
		else {
			string tmp2 = s.substr(i - max_len, max_len);
			//cout << "tmp222 = " << tmp2 << endl;
			if (!checkHasdumplate(tmp2)) {
				maxStr = tmp;
			}
		}
    }
     //cout << "maxStr = " <<maxStr << endl;
    return max_len;
}

void test_lengthOfLongestSubstring(){
    string str;
    while(cin >> str) {
        int res = lengthOfLongestSubstring(str);
        cout << res << endl;
    }
}
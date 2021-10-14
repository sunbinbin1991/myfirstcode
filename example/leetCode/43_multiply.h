//
// Created by s30001871 on 2021/9/17.
//

#ifndef MYFIRSTCODE_43_MULTIPLY_H
#define MYFIRSTCODE_43_MULTIPLY_H

string multiOne(string num1, char num2, int pos) {
    int len = 0;
    string res = "";
    int carry = 0;
    int rmnumZero1 = 0;
    int len11 = 0;
    while (num1[len11++] == '0'){
        rmnumZero1++;
    }
    if (rmnumZero1 > 0) {
        num1.erase(num1.begin(), num1.begin()+rmnumZero1);
    }

    while(len < num1.size()) {
        int pos1 = num1[len] - '0';
        int pos2 = num2- '0';
        res += std::to_string((pos1 * pos2 + carry) % 10);
        carry = (pos1 * pos2 + carry) / 10;
        len++;
    }
    if( carry != 0) {
        res += std::to_string(carry);
    }

    while (pos--) {
        res = "0" + res;
    }
    while (rmnumZero1--) {
        res = "0" + res;
    }
    return res;
}

string stringAdd (string num1,string num2) {
    if(num1.empty()) return num2;
    if(num2.empty()) return num1;
    int len1 = num1.size();
    int len2 = num2.size();
    int len = min(len1,len2);
    int index = 0;
    int carry = 0;
    string res = "";
    while(index  < len) {
        int pos1 = num1[index] - '0';
        int pos2 = num2[index] - '0';

        res += std::to_string((pos1 + pos2 + carry) % 10);
        carry = (pos1 + pos2 + carry) / 10;
        index++;
    }
    string tmp = num1.size() > num2.size() ? num1 : num2;
    int maxLen = max(num1.size(), num2.size());
    for (int i = index; i < maxLen; ++i) {
        int pos1 = tmp[i] - '0';
        res +=  std::to_string((pos1 + carry) % 10);
        carry = (pos1 + carry) / 10;
    }
    if( carry != 0) {
        res += std::to_string(carry);
    }
    return res;
}

string multiply(string num1, string num2) {
    if(num1.empty() || num2.empty()) return 0;
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int len2 = 0;
    string res = "";
    printf(" %d %d\n",num1.size(),num2.size());
    vector<string> eachStr;
    while (len2 < num2.size()){
        auto posStr = multiOne(num1, num2[len2], len2);
        res = stringAdd(res, posStr);
        printf("pos:%d:%s\n",len2, res.c_str());
        len2++;
    }
    reverse(res.begin(), res.end());
    return  res;
}

void test_multiply()
{
    string s1 = "1230";
    string s2 = "456";
    cout << multiply(s1, s2) << endl;
    cout << (1230 * 456) << endl;
}

#endif //MYFIRSTCODE_43_MULTIPLY_H

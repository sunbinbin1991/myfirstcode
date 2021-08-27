string getDigit(string s, size_t& ptr){
    string tmp = "";
    while (isdigit(s[ptr])){
        tmp += s[ptr++];
    }
    return tmp;
}

string getString(vector<string> &v){
    string ret = "";
    for (const auto & s:v) {
        ret += s;
    }
    return ret;
}

string getString(stack<string> &v){
    string ret = "";
    while (!v.empty()) {
        ret = v.top()+ ret;
        v.pop();
    }
    return ret;
}

string decodeString(string s) {
    if(s.empty()) return "";
    stack<char> chStk;
    stack<string> strStk;
    string ans = "";
    size_t ptr = 0;
    while(ptr < s.size()){
        char cur = s[ptr];
        // cout << isdigit(s[ptr]) << endl;
        if(isdigit(s[ptr])){
            string digStr = getDigit(s, ptr);
            strStk.push(digStr);
        } else if (isalpha(s[ptr]) || cur == '['){
            strStk.push(string(1,s[ptr++]));
        } else {
            ++ptr;
            vector <string> sub;//字符串倒置
            while(strStk.top() != "["){
                sub.push_back(strStk.top());
                strStk.pop();
            }
            reverse(sub.begin(), sub.end());
            strStk.pop();
            int repTime = stoi(strStk.top());
            strStk.pop();
            string t, o;
            o = getString(sub);
            while (repTime--){
                t += o;
            }
            strStk.push(t);
        }
    }
    return getString(strStk);
}

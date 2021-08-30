    string reverseWords557(string s) {
        if(s.empty()) return "";
        string temp = "";
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                temp += s[i];
            } else {
                reverse(temp.begin(), temp.end());
                ans += temp;
                ans += s[i];
                temp = "";
            }
        }

        if(!temp.empty()){
            reverse(temp.begin(), temp.end());
            ans += temp;
        }
        return ans;
    }

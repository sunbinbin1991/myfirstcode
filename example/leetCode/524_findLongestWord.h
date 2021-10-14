   int getDelNum(string s, string t){
        int sl = s.size();
        int tl = t.size();
        if(tl > sl) return -1;
        int lefts = 0;
        int leftt = 0;
        while (lefts < sl && leftt < tl) {
            if (s[lefts] == t[leftt]) {
                leftt++;
                lefts++;
            } else {
                lefts++;
            }
        }
        return leftt == tl ? sl - leftt : -1;
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        unordered_map<string, int> mp;
        string tmp = "";
        for (int i = 0; i < dictionary.size(); ++i) {
            int res = getDelNum(s, dictionary[i]);
            if (res == -1) { // 说明无法匹配成功
                continue;
            }
            if(!tmp.empty()) {
                if(tmp.size() < (s.size() - res)) {
                    tmp = dictionary[i];
                } else if(tmp.size() == (s.size() - res)){
                    if(tmp.compare(dictionary[i]) > 0) { // 字典序比较，>0 则tmp字典序靠后
                        tmp = dictionary[i];
                    }
                }
            } else {
                tmp = dictionary[i];
            }
        }
        return tmp;
    }
   int getDelNum(string s, string t){
        int sl = s.size();
        int tl = t.size();
        if(tl > sl) return -1;
        int lefts = 0;
        int leftt = 0;
        while (lefts < sl && leftt < tl) {
            if (s[lefts] == t[leftt]) {
                leftt++;
                lefts++;
            } else {
                lefts++;
            }
        }
        return leftt == tl ? sl - leftt : -1;
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        unordered_map<string, int> mp;
        string tmp = "";
        for (int i = 0; i < dictionary.size(); ++i) {
            int res = getDelNum(s, dictionary[i]);
            if (res == -1) { // 说明无法匹配成功
                continue;
            }
            if(!tmp.empty()) {
                if(tmp.size() < (s.size() - res)) {
                    tmp = dictionary[i];
                } else if(tmp.size() == (s.size() - res)){
                    if(tmp.compare(dictionary[i]) > 0) { // 字典序比较，>0 则tmp字典序靠后
                        tmp = dictionary[i];
                    }
                }
            } else {
                tmp = dictionary[i];
            }
        }
        return tmp;
    }


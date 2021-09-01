// https://labuladong.gitee.io/algo/1/8/
string minWindow(string s, string t) {
    int left = 0;
    int right = 0;
    int start  = 0;
    int minStrLen = INT_MAX;
     // 记录最小覆盖子串的起始索引及长度
    unordered_map<char, int> need, window;
    for(int i = 0; i < t.size(); i++){
        need[t[i]] ++;
    }
    int valid = 0;
    while (right < s.size()) {
         // c 是将移入窗口的字符
        char c = s[right];
        // 右移窗口
        right++;
        // 进行窗口内数据的一系列更新
        if(need.count(c)){
            window[c]++;
            if(window[c] == need[c]){
                valid++;
            }
        }
        
        // 判断左侧窗口是否要收缩
        while (valid == need.size()) {
         // 在这里更新最小覆盖子串
            if(right - left < minStrLen){
                start = left;
                minStrLen = right - left;
            }
            // d 是将移出窗口的字符
            char d = s[left];
             // 左移窗口
            left++;
             // 进行窗口内数据的一系列更新
            if(need.count(d)){
                if(window[d] == need[d]){
                    valid--;
                }
                window[d]--;
            }
        }
    }
    // 返回最小覆盖子串
    return minStrLen == INT_MAX ? "" : s.substr(start, minStrLen);
}
string minWindow_TimeLimited(string s, string t) {
    int left = 0;
    int right = 0;
    int minStrLen = INT_MAX;
    string windowSlide = "";
    string ans = "";
    
    vector<int> letterT(52);
    unordered_map<char, int> need, window;
    for(int i = 0; i < t.size(); i++){
        need[t[i]] ++;
    }
    while (right < s.size()) {
        right++;
        char c = s[right];
        windowSlide = s.substr(left, right - left);
        unordered_map temp = need;
        int windowProper = true;
        for (int i = 0; i < windowSlide.size(); i++) {
            temp[windowSlide[i]]--;
        }

        for(auto itr: temp){
            if(itr.second > 0){
                windowProper = false;
                break; 
            }
        }

        if (windowProper && (minStrLen > right - left)) {
            ans = windowSlide;
            minStrLen = right - left;
        } 

        while (windowProper) {
            left++;
            string windowSlide2 = s.substr(left, right - left);
            temp = need;
            for (int i = 0; i < windowSlide2.size(); i++) {
                temp[windowSlide2[i]]--;
            }

            for(auto itr: temp){
                if(itr.second > 0){
                    windowProper = false;
                    break; 
                }
            }

            if (windowProper && (minStrLen > right -left)) {
                ans = windowSlide2;
                minStrLen = right - left;
            }
        }
    }
    return ans;
}

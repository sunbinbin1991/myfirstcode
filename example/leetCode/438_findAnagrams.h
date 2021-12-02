//
// Created by s30001871 on 2021/12/2.
//

#ifndef MYFIRSTCODE_438_FINDANAGRAMS_H
#define MYFIRSTCODE_438_FINDANAGRAMS_H
bool checkWindows(unordered_map<char, int>& need,
                  unordered_map<char, int>& windows){
    for(auto itr : need){
        if(windows.find(itr.first) == windows.end()){
            return false;
        }
        if(windows[itr.first] < itr.second){
            return false;
        }
    }
    return true;
}

bool checkWindows2(unordered_map<char, int>& need,
                  unordered_map<char, int>& windows){
    for(auto itr : need){
        if(windows.find(itr.first) == windows.end()){
            return false;
        }
        if(windows[itr.first] != itr.second){
            return false;
        }
    }
    return true;
}

vector<int> findAnagrams2(string s, string p) {
    if(s.size() < p.size()) return {};
    vector<int> res;
    int left = 0, right = 0;
    int len = s.size() - 1;
    unordered_map<char, int> windows;
    unordered_map<char, int> need;
    for (int i = 0; i < p.size(); ++i) {
        need[p[i]] ++;
    }
    for(auto itr : need){
        cout <<itr.first << " "<< itr.second << " \n";
    }
    while(left <= len && right <= len) { // 什么条件
        char c = s[right++];
        windows[c]++;

        bool isCatains = checkWindows(need, windows);
        while(isCatains && left < right){
            bool isSatisfied2 = checkWindows2(need, windows);
            if(isSatisfied2) {
                res.push_back(left);
            }
            char lc = s[left++];
            windows[lc]--;
            if(windows[lc] <= 0){
                windows.erase(lc);
            }
            isCatains = checkWindows(need, windows);
        }
    }
    return res;
}

vector<int> findAnagrams_WRONG(string s, string p) {
    if(s.size() < p.size()) return {};
    vector<int> res;
    int left = 0, right = 0;
    int len = s.size() - 1;
    int valid = 0;
    unordered_map<char, int> windows;
    unordered_map<char, int> need;
    for (int i = 0; i < p.size(); ++i) {
        need[p[i]] ++;
    }
    while(right <= len) { // 什么条件
        char c = s[right++];
        if(need.count(c)){
            windows[c]++;
            if(windows[c] == need[c]){
                valid++;
            }
        }
        printf("L:[%d],R:[%d]\n", left, right);
        while(valid == need.size()){
             printf("### L:[%d],R:[%d]\n", left, right);
            char lc = s[left++];
            if(need.count(lc)){
                if(windows[lc] == need[lc]){
                    valid--;
                    res.push_back(left - 1);
                }
                windows[lc]--;
            }
        }
    }
    return res;
}

 vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size()) return {};
        vector<int> res;
        int left = 0, right = 0; // left right 初始值
        int len = s.size() - 1;
        int valid = 0; // 记录当前窗口和目标字符串的匹配情况，valid == p.size 说明p中数据全部找到
        unordered_map<char, int> windows; // 当前窗口
        unordered_map<char, int> need;
        for (int i = 0; i < p.size(); ++i) { // 目标窗口初始化
            need[p[i]] ++;
        }
        while(right <= len) { // 当到达右侧端点终止
            char c = s[right++];
            if(need.count(c)){
                windows[c]++;
                if(windows[c] == need[c]){
                    valid++;
                }
            }
            while(right - left >= p.size()) {  // 因为异位词和目标值的个数一样大，当右界- 左界 >= p.size() 即可进行左指针收缩
                char lc = s[left];
                if(valid == need.size()){ // 若是当前valid 则说明当前的window窗是符合的
                    res.push_back(left);
                }
                left++;
                if(need.count(lc)) { 
                    if(windows[lc] == need[lc]){
                        valid--;
                    }
                    windows[lc]--;
                }
            }
        }
        return res;
    }

void test_findAnagrams(){
    string s = "abbb";
    string t = "bb";
    auto fi = findAnagrams(s, t);
    for (int i = 0; i < fi.size(); ++i) {
        cout << fi[i] << endl;
    }
}

void test_findAnagrams2(){
    string s = "cbaebabacd";
    string t = "abc";
    auto fi = findAnagrams(s, t);
    for (int i = 0; i < fi.size(); ++i) {
        cout << fi[i] << endl;
    }
}
#endif //MYFIRSTCODE_438_FINDANAGRAMS_H

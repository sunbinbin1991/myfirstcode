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

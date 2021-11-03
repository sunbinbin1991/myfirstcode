// 滑动窗口的模板题

long long ChooseMessage(string messages, string keys) {
    unordered_map<char, int> window;
    unordered_map<char, int> need;
    for (auto &c: keys) {
        if (need.count(c) == 0) {
            need[c] = 1;
        } else {
            need[c] += 1;
        }
    }
    int left = 0;
    int right = 0;
    int valid = 0;
    long long num = 0;
    while (right < messages.size()) {
        char c = messages[right];
        right++; // 窗口的右移
        if (need.count(c)) {
            if(window.count(c)) {
                window[c] ++;
            } else {
                window[c] = 1;
            }
        }
        valid = 0;
        for (auto c : need) {
            if(window[c.first] >= c.second) {
                valid++;
            }
        }

        if (window.size() < need.size()) {
            continue;
        }
        if(valid == need.size()){
            num += (messages.size() - right + 1);
        }

        printf("window : %d %d num:%jd valid:%d\n", left, right, num, valid);
        while (valid == need.size()) { // 窗口的收缩条件，不要轻易移动right left,每次都是边界条件下移动
            char d = messages[left];
            left++;
            if (need.count(d)) {
                if(window.count(d)) {
                    window[d] --;
                } else {
                    window.erase(d);
                }
            }

            for (auto c : need) {
                if(window.count(c.first)) {
                    if(window[c.first] >= c.second) {
                    } else {
                        valid--;
                    }
                }else {
                    valid--;
                }
            }
            if(valid == need.size()){
                num += (messages.size() - right + 1);
            }
            printf("window : %d %d num:%jd valid:%d\n", left, right, num, valid);
        }
    }
    return num;
}

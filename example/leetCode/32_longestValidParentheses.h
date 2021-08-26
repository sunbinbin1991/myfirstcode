    int longestValidParentheses(string s) {
        if(s.empty()) return 0;
        stack<int> stk;
        int ans = 0;
        int start = 0;
        for (int i = 0; i < s.size(); ++i) {
            if(s[i] == '('){
                stk.push(i);
            } else {
                if (stk.empty()) {
                    start = i + 1; // 堆栈为空，且出现右括号，则起始位置加一
                } else {
                    // 堆栈不为空，此时肯定有左括号，存在有多个做括号的可能
                    // 先把第一个左括号干掉,(此处存疑，怎么想到的额)
                    // 若是把第一个左括号干掉后,
                    // 1:若是堆栈未空，则表示当前是最后一个，计算当前的最后的差值
                    // 2:若是当前对战不为空，则为当前位置和上一个左括号的索引插值
                    stk.pop();
                    if(stk.empty()) {
                        ans = max(ans, i - start + 1);
                    } else {
                        ans = max(ans, i - stk.top());
                    };
                }
            }
        }
        return ans;
    }

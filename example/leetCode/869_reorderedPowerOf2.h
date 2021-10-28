class Solution869 {
public:
    string split(int i) {
        string res = "";
        vector<int> ans;
        while (i > 0) {
            int num = i % 10;
            ans.push_back(num);
            i = i / 10;
        }
        sort(ans.begin(), ans.end());
        for (int j = 0; j < ans.size(); ++j) {
            res += ans[j];
        }
        return res;
    }
    bool reorderedPowerOf2(int n) {
        long i = 1;
        unordered_set<string> sets;
        while (i <= INT_MAX) {
            string s = split(i);
            sets.insert(s);
            i = i * 2;
        }
        string t = split(n);
        return sets.find(t) != sets.end();
    }
};

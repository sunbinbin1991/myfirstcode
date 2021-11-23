class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.empty() || goal.empty()) return false;
        if (s.size() != goal.size()) return false;
        vector<int> nums1(26);
        vector<int> nums2(26);
        vector<int> nums3(26);
        int isChange = 0;
        for (int i = 0; i < s.size(); i++) {
            if(s[i] != goal[i]) {
                nums1[s[i] - 'a'] ++;
                nums2[goal[i] - 'a'] ++;
                isChange++;
            }
            nums3[goal[i] - 'a'] ++;
        }
        bool hasDouble = false;

        for (int i = 0; i < 26; i++) {
            if (nums1[i] != nums2[i]) {
                return false;
            }
            if (nums3[i] > 1) {
                hasDouble = true;
            }
        }
        if (isChange == 2 || isChange == 0 && hasDouble) return true;
        return false;
    }
};

#include<algorithm>
class Solution {
public:
    bool compareMatrix(vector<int>& letter1, vector<int>& letter2) {
        for (int i = 0; i < 26; i++) {
            if (letter1[i]!= 0 && letter2[i] != 0){
                return false;
            }
        }
        return true;
    }
    int maxProduct(vector<string>& words) {
        if (words.empty()) return  0;
        vector<int> letter(26);
        vector<vector<int>> matrix(words.size(), vector<int>(26));
        for (int i = 0; i < words.size(); i++) {
            vector<int> letter(26);
            for (int j = 0; j < words[i].size(); j++) {
                letter[words[i][j] - 'a']++;
            }
            matrix[i] = letter;
        }
        int res = INT_MIN;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i; j < words.size(); j++) {
                if (compareMatrix(matrix[i], matrix[j])) {
                    int tmp = words[i].size() * words[j].size();
                    res = max(tmp, res);
                }
            }
        }
        return res == INT_MIN ? 0: res;
    }
};

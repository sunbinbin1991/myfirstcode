static set<char> g_set2 = { 'a','s','d','f','g','h','j','k','l' };
static set<char> g_set3 = { 'z','x','c','v','b','n','m' };
class Solution500 {
public:
    vector<string> findWords(vector<string>& words)
    {
        if (words.empty()) return{};
        vector<string> res;
        for (auto& word : words) {
            char c1 = tolower(word[0]);
            int level;
            if (g_set3.find(c1) != g_set3.end()) {
                level = 3;
            } else if (g_set2.find(c1) != g_set2.end()) {
                level = 2;
            } else {
                level = 1;
            }
            bool isProper = true;
            for (char c : word) {
                char cc = tolower(c);
                int level2;
                if (g_set3.find(cc) != g_set3.end()) {
                    level2 = 3;
                } else if (g_set2.find(cc) != g_set2.end()) {
                    level2 = 2;
                } else {
                    level2 = 1;
                }
                if (level != level2) {
                    isProper = false;
                    break;
                }
            }
            if (isProper) {
                res.push_back(word);
            }
        }
        return res;
    }
};
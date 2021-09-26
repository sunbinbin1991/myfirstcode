class Solution58 {
public:
    void splitString(string input, char dev, vector<string> &splits) {
        stringstream ss(input);
        string token;
        while (getline(ss, token, dev)) {
            splits.push_back(token);
        }
    }

    int lengthOfLastWord(string s) {
        if(s.empty()) return 0;
        vector<string> splits;
        splitString(s, ' ', splits);
        int len = 0;
        for(auto itr: splits){
            len = itr.size() != 0 ? itr.size() : len;
        }
        return len;
    }
};

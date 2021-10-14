class Solution187 {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.empty()) return {};
        set<string> strSets;
        set<string> res;
        for (int i = 0; i <= s.size() - 10 && s.size() >= 10; i++){
            string sub = s.substr(i, 10);
            // cout << "sub :" << sub << endl;
            if(strSets.find(sub) != strSets.end()){
                res.insert(sub);
            }
            strSets.insert(sub);
        }
        vector<string> ans;
        for(auto ss : res){
            ans.push_back(ss);
        }
        return ans;
    }
};

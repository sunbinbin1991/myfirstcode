class Solution165 {
    string delPrefixZero(string input)
    {
        string temp = "";
        bool isPrefixZero = false;
        for(int i = 0; i < input.size(); i++){
            if(!isPrefixZero && input[i] == '0'){
                continue;
            } else {
                isPrefixZero = true;
                temp += input[i];
            }
        }
        return temp;
    }

    void splitString(string input, char dev, vector<string> &splits) {
        stringstream ss(input);
        string token;
        while (getline(ss, token, dev)) {
            token = delPrefixZero(token);
            splits.push_back(token);
        }
    }

public:
    int compareVersion(string version1, string version2) {
        vector<string> v1,v2;
        splitString(version1, '.', v1);
        splitString(version2, '.', v2);
        int index = 0;
        int maxLen = max(v1.size(), v2.size());
     
        while (index < maxLen) {
            int n1 = 0;
            int n2 = 0;
            if(index < v1.size()) {
                n1 = atoi(v1[index].c_str());
            }
            if(index < v2.size()) {
                n2 = atoi(v2[index].c_str());
            }
            if (n1 > n2) {
                return 1;
            } else if (n1 < n2) {
                return -1;
            }
            index++;
        }
        return 0;
    }
};

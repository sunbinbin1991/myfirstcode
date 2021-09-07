int balancedStringSplit(string s) {
    if(s.empty()) return 0;
    int rNum = 0;
    int lNum = 0;
    int splitNums = 0;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i] == 'L'){
            lNum++;
        } else {
            rNum++;
        }
        if(lNum == rNum){
            splitNums++;
            lNum = 0;
            rNum = 0;
        }
    }
    return splitNums;
}

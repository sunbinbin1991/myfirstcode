class Solution335 {
  
public:
    bool isSelfCrossing(vector<int>& distance) {
        int n = distance.size();
        int i = 0;
        while (i < n && (i < 2 || distance[i] > distance[i-2])) {
            ++i;
        }
        if(i == n) return false;
        if(i == 3 && distance[i] == distance[i - 2] || (i >= 4 && distance[i] >= distance[i-2] - distance[i -4])){
            distance[i -1] -= distance[i-3];
        }
        ++i;
        while(i < n&& distance[i] < distance[i-2]){
            ++i;
        }
        return i!= n;
        
    }
    bool isSelfCrossing1(vector<int>& distance) {
        int lastPosX = 0;
        int lastPosY = 0;
        unordered_set<string> sets;
        string temp = "";
        temp += std::to_string(lastPosX);
        temp += ",";
        temp += std::to_string(lastPosY);
        sets.insert(temp);
        for (int i = 0; i < distance.size(); i++) {
            int dir = i % 4;
            if (dir == 0) { // up
                for (int j = 0; j < distance[i]; j++) {
                    lastPosY++;
                    string temp = "";
                    temp += std::to_string(lastPosX);
                    temp += ",";
                    temp += std::to_string(lastPosY);
                    auto res = sets.emplace(temp);
                    if(!res.second) return true;
                }
            }
            if (dir == 1) { // left
                for (int j = 0; j < distance[i]; j++) {
                    lastPosX--;
                    string temp = "";
                    temp += std::to_string(lastPosX);
                    temp += ",";
                    temp += std::to_string(lastPosY);
                    auto res = sets.emplace(temp);
                    if(!res.second) return true;
                }
            }
            if (dir == 2) { // down
                for (int j = 0; j < distance[i]; j++) {
                    lastPosY--;
                    string temp = "";
                    temp += std::to_string(lastPosX);
                    temp += ",";
                    temp += std::to_string(lastPosY);
                    auto res = sets.emplace(temp);
                    if(!res.second) return true;
                }
            }
            if (dir == 3) { // right
                for (int j = 0; j < distance[i]; j++) {
                    lastPosX++;
                    string temp = "";
                    temp += std::to_string(lastPosX);
                    temp += ",";
                    temp += std::to_string(lastPosY);
                    auto res = sets.emplace(temp);
                    if(!res.second) return true;
                }
            }                           
        }
        return false;
    }
};

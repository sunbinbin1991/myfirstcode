    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        std::priority_queue<float, vector<float>, less<float> >greater;//从小到大排序
        map<float, pair<int, int>> pMap;
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = i + 1; j < arr.size(); ++j) {
                if(greater.empty() || greater.size() < k){
                    greater.push(arr[i] * 1.0 / arr[j]);
                    pMap[arr[i] * 1.0 / arr[j]] = std::make_pair(arr[i], arr[j]);
                }else{
                    float val = arr[i] * 1.0 / arr[j];
                    if(greater.top() > val){
                        greater.pop();
                        greater.push(val);
                        pMap[arr[i] * 1.0 / arr[j]] = std::make_pair(arr[i], arr[j]);
                    }
                }
            }
        }
        auto res = pMap[greater.top()];

        return {res.first, res.second};
    }

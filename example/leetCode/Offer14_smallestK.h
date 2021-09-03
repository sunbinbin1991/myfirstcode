class SolutionOffer14 {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        if(arr.empty() || k == 0) return {};
        priority_queue<int,vector<int>,less<int>> pt;
        for (int i = 0; i < arr.size(); i++){
            if(pt.empty() || (!pt.empty() && pt.size() < k)){
                pt.push(arr[i]);
            } else {
               auto tp = pt.top();
            //    cout << tp << endl;
               if(tp > arr[i]) {
                   pt.pop();
                   pt.push(arr[i]);
               }
            }
        }
        vector<int> ans;
        // int j = 0;
        while(!pt.empty()){
            ans.push_back(pt.top());
            pt.pop();
            // j++;
        }
        return ans;
    }
};

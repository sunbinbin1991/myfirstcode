class Solution496 {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty() || nums2.empty()) return {};
        map<int, int> num2Index;
        vector<int> nums2Prefix;
        for(int i = 0; i < nums2.size(); i++) {
            num2Index[nums2[i]] = i;
        }
        vector<int> res;
        for(int i = 0; i < nums1.size(); i++){
            bool isFind = false;
            for(int j = num2Index[nums1[i]]; j < nums2.size(); j++){
                if(!isFind && nums2[j] > nums1[i]){
                    res.push_back(nums2[j]);
                    isFind = true;
                }
            }
            if(!isFind){
                res.push_back(-1);
            }
        }
        return res;
    }
};

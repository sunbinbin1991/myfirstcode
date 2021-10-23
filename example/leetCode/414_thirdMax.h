class Solution414 {
public:
    int thirdMax(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        int maxVal = INT_MIN;
        int secondVal = INT_MIN;
        int thirdVal = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            maxVal = max(nums[i], maxVal);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != maxVal) {
                secondVal = max(nums[i], secondVal);
            }
        }
        bool isExist = false;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != maxVal && nums[i] != secondVal) {
                thirdVal = max(nums[i], thirdVal);
                isExist = true;
            }
        }
        if (!isExist) {
            thirdVal =  maxVal; // 返回数组中最大的数
        } 
        return thirdVal;
    }
};

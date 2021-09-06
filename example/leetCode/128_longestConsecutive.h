    int GetMaxContinueNum(vector<int>& nums){
        if(nums.empty()) return {};
        int ans = 1;
        int count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if(nums[i] - nums[i-1] == 1){
                count++;
                ans = max(count, ans);
            } else if(nums[i] - nums[i -1] == 0) {
                nums[i] = nums[i-1];
            } else {
                count = 1;
            }
        }
        return ans;
    }

    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        auto tt = GetMaxContinueNum(nums);

        return tt; 
    }

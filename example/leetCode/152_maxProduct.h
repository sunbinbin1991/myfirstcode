int maxProduct(vector<int>& nums) {
    if(nums.empty()) return 0;
    vector<int> dpMax(nums);
    vector<int> dpMin(nums);

    for (int i = 1; i < nums.size(); ++i) {
        dpMax[i] = max(dpMax[i-1] * nums[i], max(nums[i], dpMin[i-1] * nums[i]));
        dpMin[i] = max(dpMin[i-1] * nums[i], max(nums[i], dpMax[i-1] * nums[i]));

//        dp[i] = dp[i-1] * nums[i];
//        printf("pt: %d\n ", dp[i]);
    }

//    vector<int> preProduct2(nums.size());
//    for (int i = 0; i < nums.size(); ++i) {
//        preProduct2[i] = preProduct[nums.size()-1] / nums[i];
//        printf("pt2: %d\n ",preProduct2[i]);
//    }

    return *max_element(dpMax.begin(), dpMax.end());;
}

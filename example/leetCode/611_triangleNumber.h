#pragma once
bool checkTriangle(vector<int> nums) {
    if (nums.size() != 3) return false;
    if (nums[0] + nums[1] > nums[2]) {
        return true;
    }
    return false;
}

int triangleNumber(vector<int>& nums)
{
    if (nums.empty() || nums.size() < 3) return 0;
    sort(nums.begin(), nums.end());
    int len = nums.size();
    int ans = 0;
    for (size_t i = 0; i < len - 2; i++) {
        for (size_t j = i + 1; j < len - 1;j++) {
            for (size_t k = j + 1; k < len; k++) {
                vector<int> trmp = { nums[i], nums[j], nums[k]};
                if (nums[i] + nums[j] < nums[k]) {
                    continue;
                }
                if (checkTriangle(trmp)) {
                    ans++;
                }
            }
        }
    }

    return ans;
}

int triangleNumber_better(vector<int>& nums)
{
    if (nums.empty() || nums.size() < 3) return 0;
    sort(nums.begin(), nums.end());
    int len = nums.size();
    int ans = 0;
    for (int i = 0; i < len; ++i) {
        int k = i;
        for (int j = i + 1; j < len; ++j) {
            while (k + 1 < len && nums[k + 1] < nums[i] + nums[j]) {
                ++k;
            }
            ans += max(k - j, 0);
        }
    }
    return ans;
}

void test_triangleNumber() {
    vector<int> input = {2,2,3,4};
    int asn = triangleNumber(input);
    cout << asn << endl;
    for (size_t i = 0; i < input.size(); i++) {
        //cout << input[i] << endl;
    }
}
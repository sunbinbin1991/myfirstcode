#pragma once
#include<vector>
int removeElement(vector<int>& nums, int val)
{
    int len = nums.size();
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (nums[i] != val) {
            nums[j] = nums[i];
            j++;
        }
    }
    return j;
}

int rmDep(vector<int>& nums)
{
    if (nums.size() == 0) return 0;
    int i = 0;
    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}

int removeDuplicates(vector<int>& nums)
{
	vector<int> res;
	if (nums.empty())  return 0;
    vector<bool> flags(nums.size());
	int first = nums[0];
    flags[0] = true;
	int second;
	for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i+1] == nums[i]) {
            flags[i + 1] = false;
        } else {
            flags[i + 1] = true;
        }
	}

    for (int i = 0; i < nums.size(); i++) {
        if (flags[i]) {
            res.push_back(nums[i]);
        }
    }
    nums = res;
    return res.size();
}

void test_rmDuplicates() {
	vector<int> input = { 1,2,2,3,4,4,4,5 };
	int len = removeDuplicates(input);

	for (int i = 0; i < len; i++) {
		printf("%d \t",input[i]);
	}
}
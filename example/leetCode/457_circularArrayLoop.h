#pragma once
#include<vector>
#include<string>
#include<set>

bool circularArrayLoop(vector<int>& nums)
{
    int len = nums.size();
    auto next = [&](int cur) {
        return ((cur + nums[cur]) % len + len) % len;
    };
    for (size_t i = 0; i < nums.size(); i++) {
        if (!nums[i]) {
            continue;
        }
        int slow = i;
        int fast = next(i);
        //判定慢指针和快指针及慢指针和快指针的走两步指针符号一致
        while (nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(fast)] > 0) {
            if (slow == fast) {
                if (slow != next(slow)) {
                    return true;
                } else {
                    break;
                }
            } 
            slow = next(slow); // 慢指针走一步
            fast = next(next(fast)); // 快指针走两步
        }
        int add = i;
        // 判定过的index 置零
        while (nums[add] * nums[next(add)] > 0) {
            int temp = add;
            add = next(add);
            nums[temp] = 0;
        }
    }
    return false;
}

void test_circularArrayLoop() {
    vector<int> nums{ 2,-1,1,2,2 };
    auto flag = circularArrayLoop(nums);
    cout << flag << endl;
}

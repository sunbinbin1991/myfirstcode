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
        //�ж���ָ��Ϳ�ָ�뼰��ָ��Ϳ�ָ���������ָ�����һ��
        while (nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(fast)] > 0) {
            if (slow == fast) {
                if (slow != next(slow)) {
                    return true;
                } else {
                    break;
                }
            } 
            slow = next(slow); // ��ָ����һ��
            fast = next(next(fast)); // ��ָ��������
        }
        int add = i;
        // �ж�����index ����
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
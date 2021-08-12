#pragma once
#include<vector>
#include<algorithm>
using namespace std;
int jump_better(vector<int>& nums)
{
    int max_far = 0;// Ŀǰ����������Զλ��
    int step = 0;   // ��Ծ����
    int end = 0;    // �ϴ���Ծ�ɴﷶΧ�ұ߽磨�´ε����������㣩
    for (int i = 0; i < nums.size() - 1; i++) {
        max_far = std::max(max_far, i + nums[i]);
        // �����ϴ���Ծ�ܵ�����ұ߽���
        if (i == end) {
            end = max_far;  // Ŀǰ����������Զλ�ñ�����´�����λ�õ��б߽�
            step++;         // ������һ����Ծ
        }
    }
    return step;
}

int jump2(vector<int>& nums)
{
    if (nums.empty() || nums.size() == 1) return 0;
    int len = nums.size();
    vector<int> dp(len + 1);
    dp[0] = 0;
    for (int i = 1; i <= len; ++i) {
        int minJump = INT_MAX - 1;
        for (int j = 0; j < i; ++j) {
            if (dp[j] > minJump) {
                continue;
            }
            if (nums[j] + j >= i) {
                minJump = min(dp[j], minJump);
            }
        }
        dp[i] = minJump + 1;
    }
    return dp[len - 1];
}

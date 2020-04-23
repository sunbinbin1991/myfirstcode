#pragma once
//https://www.nowcoder.com/practice/24e6243b9f0446b081b1d6d32f2aa3aa?tpId=37&tqId=21326&tPage=6&rp=&ru=/ta/huawei&qru=/ta/huawei/question-ranking
//此题即:最长递增子序列
//定义 dp[i]dp[i] 为考虑前 ii 个元素，以第 ii 个数字结尾的最长上升子序列的长度，注意 \textit{ nums }[i]nums[i] 必须被选取。
//我们从小到大计算 dp[]dp[] 数组的值，在计算 dp[i]dp[i] 之前，我们已经计算出 dp[0 \ldots i - 1]dp[0…i−1] 的值，则状态转移方程为：
//dp[i] = \text{ max }(dp[j]) + 1, \text{ 其中 } \, 0 \leq j < i \, \text{ 且 } \, \textit{ num }[j]<\textit{ num }[i]
//	dp[i] = max(dp[j]) + 1, 其中0≤j<i且num[j]<num[i]
//	即考虑往 dp[0 \ldots i - 1]dp[0…i−1] 中最长的上升子序列后面再加一个 \textit{ nums }[i]nums[i]。由于 dp[j]dp[j] 代表 \textit{ nums }[0 \ldots j]nums[0…j] 中以 \textit{ nums }[j]nums[j] 结尾的最长上升子序列，所以如果能从 dp[j]dp[j] 这个状态转移过来，那么 \textit{ nums }[i]nums[i] 必然要大于 \textit{ nums }[j]nums[j]，才能将 \textit{ nums }[i]nums[i] 放在 \textit{ nums }[j]nums[j] 后面以形成更长的上升子序列。
//	最后，整个数组的最长上升子序列即所有 dp[i]dp[i] 中的最大值

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void get_maxIncreaseOrder(std::vector<int>&nums) {
	if (nums.empty()) return;
	int len = nums.size();
	vector<int> DP(len);
	DP[0] = 1;
	int max_order_num;
	std::vector<int> target(nums.size());
	target[0] = 1;
	for (size_t i = 0; i < nums.size(); i++)
	{
		printf("nums = %d\n", nums[i]);
		target[i] = 1;
	}
	int max_num = 1;
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = 0; j <= i; j++) {
			if (nums[j] < nums[i]) {
				target[i] = std::max(target[j] + 1, target[i]);
			}
			max_num = std::max(max_num, target[i]);
			printf("i= %d, j= %d ，target = %d，num = %d\n", i, j, target[i], max_num);
		}
	}
	max_num = 1;
	for (int i = 1; i < nums.size(); i++)
	{
		//printf("target %d = %d\n", i, target[i]);
		max_num = std::max(max_num, target[i]);
	}
	printf("%d\n", max_num);
}

int test_maxIncreseOrder() {
	int num;
	while (cin >> num) {
		vector<int> input;
		while (num--) {
			int tmp;
			cin >> tmp;
			input.push_back(tmp);
			get_maxIncreaseOrder(input);
		}
	}
	
	return 0;
}

#pragma once
//广度优先遍历方法
//深度优先遍历方法(DFS)


void dfs(vector<int>& nums, int len,int depth,
    std::stack<int> &path, std::vector<bool>& used, std::vector<stack<int>>& result) {
	if (depth == len) {
		result.push_back(path);
		return ;
	}
	for (size_t i = 0; i < len; i++) {
		if (used[i]) continue;
		path.push(nums[i]);
		used[i] = true;
		dfs(nums, len, depth + 1, path, used, result);
		path.pop();
		used[i] = false;
	}
}
//状态
void test_permute() 
{
	std::vector<int> input = { 1,2,3,4,5,6 };
	int len = input.size();
	std::vector<bool> useds(len);
	std::vector<stack<int>> results;
	stack<int> path;
	dfs(input, len, 0, path, useds, results);
	cout<< "results.size() = " << results.size() << "\n";
	for (size_t i = 0; i < results.size(); i++) {
		auto ttlen = results[i].size();
		for (size_t j = 0; j < ttlen; j++) {
			int tmp = results[i].top();
			results[i].pop();
			cout << tmp << "\t";
		}
		cout << "\n";
	}
}
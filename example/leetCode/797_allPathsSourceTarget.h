#pragma once
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
void dfsGraph(vector<vector<int>>& graph, vector<vector<int>>& paths, vector<int>& path, int i)
{
    if (i == graph.size() - 1) {
        paths.push_back(path);
        return;
    }

    for (auto p : graph[i]) { // 针对第i个点的所有可能性,p为所有在i中的节点可能性
        path.push_back(p);  // 将可能的p点加入
        dfsGraph(graph, paths, path, p); // 下一步,在p点时,继续走,去找p点的所有可能结果
        path.pop_back(); // 将当前加入的p点取出
    }

}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
{
    if (graph.empty()) return{};
    vector<int> path;
    vector<vector<int>> paths;
    path.push_back(0);
    dfsGraph(graph, paths, path, 0);
    return paths;
}
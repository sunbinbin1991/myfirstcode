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

    for (auto p : graph[i]) { // ��Ե�i��������п�����,pΪ������i�еĽڵ������
        path.push_back(p);  // �����ܵ�p�����
        dfsGraph(graph, paths, path, p); // ��һ��,��p��ʱ,������,ȥ��p������п��ܽ��
        path.pop_back(); // ����ǰ�����p��ȡ��
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
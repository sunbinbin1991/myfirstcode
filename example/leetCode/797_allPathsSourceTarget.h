#pragma once
void dfsGraph(vector<vector<int>>& graph, vector<vector<int>>& paths, vector<int>& path, int i)
{
    if (i == graph.size() - 1) {
        paths.push_back(path);
        return;
    }

    for (auto p : graph[i]) {
        path.push_back(p);
        dfsGraph(graph, paths, path, p);
        path.pop_back();
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
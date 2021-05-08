#pragma once
#include <vector>
using namespace std;

//深度优先搜索的思路是很直观的。遍历所有城市，对于每个城市，如果该城市尚未被访问过，
//则从该城市开始深度优先搜索，通过矩阵 \textit{ isConnected }isConnected 
//得到与该城市直接相连的城市有哪些，这些城市和该城市属于同一个连通分量，然后对这些
//城市继续深度优先搜索，直到同一个连通分量的所有城市都被访问到，即可得到一个省份。
//遍历完全部城市以后，即可得到连通分量的总数，即省份的总数。

void dfs(vector<vector<int>>& isConnected, vector<bool> &visited, int privince, int i) {
    for (int j = 0; j < privince; j++) {
        if (!visited[j] && isConnected[i][j]) {
            visited[j] = true;
            dfs(isConnected, visited, privince, j); // 这个为什么写在这里 不理解?
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected)
{
    if (isConnected.empty()) return 0;

    int privinces = isConnected.size();
    vector<bool> visited(privinces);
    int circleNum = 0;
    for (size_t i = 0; i < privinces; i++) {
        if (!visited[i]) {
            dfs(isConnected, visited, privinces, i);
            circleNum++;
        }
    }
}
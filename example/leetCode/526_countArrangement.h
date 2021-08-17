#pragma once
#include<vector>
#include<algorithm>
using namespace std;
void dfs_countArrangement(int & res, int level,
    vector<int> &vis, vector<int> &arry, int n)
{
    if (level > n) {
        bool flag = true;
        for (size_t i = 1; i <= arry.size(); i++) {
            cout << arry[i - 1] << endl;
            bool temp = (arry[i - 1] % i == 0) || (i % arry[i - 1] == 0);
            // bool temp = (i % arry[i-1]  == 0);
            // cout << "arry[i-1] % i"<< (arry[i-1] % i == 0)<< endl;
            // cout << "i % arry[i-1] "<< (i % arry[i-1] == 0)<< endl;
            // cout << "temp "<< temp<< endl;
            flag = flag && temp;
        }
        if (flag) {
            res++;
        }
        return;
    }

    for (size_t i = 0; i < n; i++) {
        if (vis[i]) {
            continue;
        }
        vis[i] = 1;
        arry.push_back(i + 1);
        dfs_countArrangement(res, level + 1, vis, arry, n);
        vis[i] = 0;
        arry.pop_back();
    }
}

int countArrangement(int n)
{
    vector<int> vis;
    vis.resize(n + 1);
    int res = 0;
    vector<int> per;
    dfs_countArrangement(res, 1, vis, per, n);
    return res;
}
#pragma once
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

void dfsComb(vector<vector<int>>& paths,
    vector<int>& path, int level, int k, int n)
{
    if (k == 0) {
        paths.push_back(path);
        return;
    }
    if (level > n - k + 1) {
        return;
    }


    // for (int i = level; i < arry.size(); ++i){
    // if(vis[i]) {
    // continue;
    // }
    // vis[i] = true;
    // path.push_back(arry[i]);
    dfsComb(paths, path, level + 1, k, n);
    cout << "L " << level << endl;
    path.push_back(level);
    dfsComb(paths, path, level + 1, k - 1, n);
    path.pop_back();
    // vis[i] = false;
    // }
}

vector<vector<int>> combine(int n, int k)
{
    vector<int> path;
    vector<vector<int>> paths;
    vector<int> vis(n);
    vector<int> arry;
    for (int i = 0; i < n; i++) {
        arry.push_back(i + 1);
    }
    dfsComb(paths, path, 1, k, n);
    for (auto pts : paths) {
        for (auto itr : pts) {
            cout << itr;
        }
        cout << endl;
    }
    return paths;
}

void test_combine() {
    int n = 4;
    int k = 2;
    combine(4, 2);
}
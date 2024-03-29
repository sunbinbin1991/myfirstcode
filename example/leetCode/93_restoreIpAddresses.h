#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
void dfsIPAddr(string s, vector<vector<int>>& paths, vector<int>& path,
         int level, vector<bool>& vis)
{
    if(!path.empty() && (path.size() > 4)){
        return;
    }
    if(level == s.size() && (!path.empty() && (path.size() == 4))) {
        paths.push_back(path);
        return;
    }

    for (int i = 0; i < 3; ++i) {
        if(i == 0) {
            auto num = s[level] - '0';
            vis[level] = true;
            path.push_back(num);
            dfsIPAddr(s, paths, path, level + 1, vis);
            path.pop_back();
            vis[level] = false;
        }
        if(i == 1) {
            if((level + 1 < s.size())) {
                auto num2 = 10 * (s[level] - '0') + s[level+1] - '0';
                if((!vis[level] && !vis[level+1]) && num2 >= 10) {
                    vis[level] = true;
                    vis[level+1] = true;
                    path.push_back(num2);
                    dfsIPAddr(s, paths, path,  level + 2, vis);
                    path.pop_back();
                    vis[level] = false;
                    vis[level+1] = false;
                }
            }
        }
        if(i == 2) {
            if((level + 1 < s.size())&& (level + 2 < s.size())) {
                auto num3 = 100 * (s[level] - '0') + 10 * (s[level+1] - '0') + s[level+2] - '0';
                if((!vis[level] && !vis[level+1] && !vis[level+2]) && (num3 >= 100 && num3 <= 255)) {
                    vis[level] = true;
                    vis[level+1] = true;
                    vis[level+2] = true;
                    path.push_back(num3);
                    dfsIPAddr(s, paths, path,level + 3, vis);
                    path.pop_back();
                    vis[level] = false;
                    vis[level+1] = false;
                    vis[level+2] = false;
                }
            }
        }

    }
}

vector<string> restoreIpAddresses(string s)
{
    if(s.empty()) return {};
    vector<int> path;
    vector<vector<int>> paths;
    vector<bool> vis;
    vis.resize(s.size());
    dfsIPAddr(s,paths,path,0,vis);
    vector<string> res;
    for (auto pat : paths) {
        string temp = "";
        for(int i= 0; i < pat.size(); i++){
            temp += std::to_string(pat[i]);
            if (i != pat.size() - 1) {
                temp += ".";
            }
        }
        res.push_back(temp);
    }
    return res;
}

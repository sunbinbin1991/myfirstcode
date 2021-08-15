#pragma once
#include<vector>
#include<deque>
#include<algorithm>
#include<map>
using namespace std;
//1:找到与朋友 xx 配对的朋友 yy。
//2:找到朋友 yy 在朋友 xx 的朋友列表中的亲近程度下标，记为 \textit{ index }index。
//3:朋友 xx 的朋友列表中的下标从 00 到 \textit{ index }-1index−1 的朋友都是可能的 uu。遍历每个可能的 uu，找到与朋友 uu 配对的朋友 vv。
//4:如果 \textit{ order }[u][x] < \textit{ order }[u][v]order[u][x]<order[u][v]，则 xx 是不开心的朋友。

bool isHappy(int index, vector<vector<int>>& preferences,
    map<int, int> &pairSets) {
    int pair = pairSets[index];

    return false;
}

int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs)
{
    int ans = 0;
    map<int, int> pairSets;
    for (size_t i = 0; i < pairs.size(); i++) {
        //cout << pairs[i][0] << ":" << pairs[i][1] << endl;
        pairSets[pairs[i][0]] = pairs[i][1];
        pairSets[pairs[i][1]] = pairs[i][0];
        //cout << pairSets[pairs[i][0]] << ":" << pairSets[pairs[i][1]] << endl;
    }

    vector<vector<int>> matrix(n, vector<int>(n));
    for (size_t i = 0; i < n; i++) {
        int count = 0;
        int rank = 1;
        for (size_t j = 0; j < n; j++) {
            if (j == i) {
                matrix[i][j] = 0;
                cout << matrix[i][j];
            } else {
                matrix[i][preferences[i][count]] = rank++;
                //cout << matrix[i][preferences[i][count]];
                count++;
            }
        }
    }
    cout << "matrix:\n";
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }

    for (size_t i = 0; i < n; i++) {
        int xyR = matrix[i][pairSets[i]];
        int uxR = matrix[i][i];
        for (auto itr : pairSets) {
            if (itr.first != i && itr.first != pairSets[i]) {
                
            }
        }

       /* if (matrix[i][pairSets[i]]&& matrix[i][pairSets[i]] < ) {
            ans++;
        }*/

    }
    return ans;
}

void test_unhappyFriends() {
    int n = 4;
    vector<vector<int>> preferences, pairs;
    //preferences = { {1,2,3},{3,2,0},{3,1,0},{1,2,0} };
    preferences = { { 1,3,2 },{ 2,3,0 },{ 1,0,3 },{ 1,0,2} };
    pairs = { {1,2},{3,0} };
    int ans = unhappyFriends(n, preferences, pairs);
    cout << ans << endl;
}
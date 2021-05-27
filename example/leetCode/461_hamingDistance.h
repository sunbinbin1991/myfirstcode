#pragma once
#include<vector>
#include<iostream>
#include<stack>

vector<int> bin2vec(int nums) {
    vector<int> vec;
    while (nums > 0) {
        if (nums % 2 == 0) {
            vec.push_back(0);
        } else {
            vec.push_back(1);
        }
        nums = nums >> 1;
    }
    return vec;
}
int hammingDistance(int x, int y)
{
    int s = x ^ y, ret = 0;
    while (s) {
        s &= s - 1;
        ret++;
    }
    return ret;
}

int hammingDistance(int x, int y)
{
    int ans = 0;
    vector<int> v1 = bin2vec(x);
    vector<int> v2 = bin2vec(y);
    for (size_t i = 0; i < v1.size(); i++) {
        cout << v1[v1.size() - i - 1];
    }
    cout << endl;
    for (size_t i = 0; i < v2.size(); i++) {
        cout << v2[v2.size() - i - 1];
    }
    int len1 = v1.size();
    int len2 = v2.size();
    if (len1 < len2) {
        for (size_t i = 0; i < len1; i++) {
            if (v1[i] != v2[i]) ans++;
        }
        for (size_t i = len1; i < len2; i++) {
            if(v2[i]) ans++;
        }
    } else {
        for (size_t i = 0; i < len2; i++) {
            if (v1[i] != v2[i]) ans++;
        }
        for (size_t i = len2; i < len1; i++) {
            if (v1[i]) ans++;
        }
    }
    return ans;
}

void test_hammingDistance() {
    int s = hammingDistance(1, 4);
    cout << s << endl;
}
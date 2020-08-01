#pragma once
#include<vector>
#include<iostream>

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    if (intervals.size() == 0) {
        return{};
    }
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    for (int i = 0; i < intervals.size(); ++i) {
        int L = intervals[i][0], R = intervals[i][1];
        if (!merged.size() || merged.back()[1] < L) {
            merged.push_back({ L, R });
        } else {
            merged.back()[1] = max(merged.back()[1], R);
        }
    }
    return merged;
}

vector<vector<int>> merge(vector<vector<int>>& input)
{
    if (input.empty()) return input;
    if (input.size() == 1) return input;
    vector<vector<int>> res;
    sort(input.begin(), input.end());
    vector<int> start;
    vector<int> end;
    start = input[0]; // ³õÊ¼Çø¼ä
    int i = 0;
    for (i = 0; i < input.size(); i++) {
        if (!res.empty()) {
            if (res[res.size() - 1][1] > input[i][0] ||
                res[res.size() - 1][1] > input[i][1]) {
                continue;
            }
        }
        for (int j = i + 1; j < input.size(); j++) {
            end = input[j];
            if (start[1] < end[0]) {
                res.push_back(start);
                start = end;
                break;
            }
            if (start[1] < end[1]) {
                start[1] = end[1];
            }
        }
    }
    if (res.empty()) {
        res.push_back(start);
    } else {
        if (res[res.size() - 1][1] < start[0]) {
            res.push_back(start);
        }
    }

    return res;
}
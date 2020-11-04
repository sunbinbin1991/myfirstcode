#pragma once
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
{
    int left = newInterval[0];
    int right = newInterval[1];
    bool placed = false;
    vector<vector<int>> ans;
    for (const auto& interval : intervals) {
        if (interval[0] > right) {
            // 在插入区间的右侧且无交集
            if (!placed) {
                ans.push_back({ left, right });
                placed = true;
            }
            ans.push_back(interval);
        } else if (interval[1] < left) {
            // 在插入区间的左侧且无交集
            ans.push_back(interval);
        } else {
            // 与插入区间有交集，计算它们的并集
            left = min(left, interval[0]);
            right = max(right, interval[1]);
        }
    }
    if (!placed) {
        ans.push_back({ left, right });
    }
    return ans;
}

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
{
    vector<vector<int>> outIntervals;
    intervals.push_back(newInterval);
    sort(intervals.begin(),intervals.end());
    outIntervals.push_back(intervals.front());
    for (size_t i = 1; i < intervals.size(); i++) {
        if (outIntervals.back().back() < intervals[i].front()) {
            //outIntervals.push_back(intervals[i]);
            outIntervals.push_back({ intervals[i].front(),intervals[i].back() });
        } else {
            if (outIntervals.back().back() < intervals[i].back()) {
                //if (i == intervals.size() - 1) {
                    outIntervals.back().back() = intervals[i].back();
                //}
            }
        }
    }

}
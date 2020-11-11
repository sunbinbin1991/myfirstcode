#pragma once
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>
using namespace std;
struct PointsStr{
    vector<int> pts;
    long dis;
};

int comparerVec(const void *a, const void *b ) {
    PointsStr* pointA = (PointsStr*)a;
    PointsStr* pointb = (PointsStr*)b;
    return pointA->dis - pointb->dis;
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int K)
{
    if (points.empty() || K <= 0) return {};
    vector<PointsStr> pointsRes;
    for (size_t i = 0; i < points.size(); i++) {
        PointsStr ptStr;
        ptStr.pts = points[i];
        ptStr.dis = points[i].front() * points[i].front() + points[i].back() * points[i].back();
        pointsRes.push_back(ptStr);
    }

    qsort(pointsRes.data(), pointsRes.size(), sizeof(PointsStr),comparerVec);
    for (size_t i = 0; i < pointsRes.size(); i++) {
        printf(" %d\n", pointsRes[i].dis);
    }
}

void test_kClosest() {
    vector<vector<int>> points = { {1,2},{1,3},{-2,2} };
    int k = 1;
    kClosest(points, k);
}
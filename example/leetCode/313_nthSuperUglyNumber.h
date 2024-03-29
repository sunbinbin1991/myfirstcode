#pragma once
#include<vector>
#include<iostream>
#include<unordered_set>
using namespace std;
bool isNotPrimer(int num)
{
    bool flag = false;
    for (int i = 2; i < num >> 1; i++) {
        if (num % i == 0) {
            flag = true;
            return flag;
        }
    }
    return flag;
}
// 这题为什么不用dfs ? 不合适?
// 从1-N个逐个遍历,对于每个N,使用最小堆,
// 将数组中的元素依次添加, 添加的元素为最小堆的top值和当前数组中元素的依次乘积
int nthSuperUglyNumber(int n, vector<int>& primes)
{
    unordered_set<long> seen;
    priority_queue<long, vector<long>, greater<long>> heap;
    seen.insert(1);
    heap.push(1);
    int ugly = 0;
    for (int i = 0; i < n; i++) {
        long curr = heap.top();
        heap.pop();
        ugly = (int)curr;
        for (int prime : primes) {
            long next = curr * prime;
            if (seen.insert(next).second) {
                heap.push(next);
            }
        }
    }
    return ugly;
}

void test_nthSuperUglyNumber() {
    int n = 12;
    vector<int> primers = {2, 7, 13, 19};
    auto t = nthSuperUglyNumber(n, primers);
    cout << t << endl;
}

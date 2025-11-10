#pragma once
#include<vector>
#include<deque>
#include<unordered_map>
#include<algorithm>
#include<map>
using namespace std;

void demo_0626(vector<int>nums, vector<char> colors) 
{
    int maxNum = 0;
    int num = 0;
    unordered_map<int,int> nMaps;
    unordered_map<char, int> cMaps;
    for (int i = 0; i < nums.size(); i++) {
        if (nMaps.find(nums[i]) != nMaps.end()) {
            nMaps[nums[i]] += 1;
        } else {
            nMaps.emplace(std::pair<int, int>(nums[i], 1));
        }
    }
    for (int i = 0; i < colors.size(); i++) {
        if (cMaps.find(colors[i]) != cMaps.end()) {
            cMaps[colors[i]] += 1;
        } else {
            cMaps.emplace(std::pair<char, int>(colors[i], 1));
        }
    }
    for (int i = 0; i < nums.size(); i++) {
        if (nMaps.find(nums[i]) != nMaps.end()) {
            if (nMaps[nums[i]] == 1) {
                num = cMaps[colors[i]];
            } else if (nMaps[nums[i]] >= 2) {
                num = cMaps[colors[i]];
                for (int j = i+1;j < nums.size(); j++) {
                    if (nums[i] == nums[j]) {
                        if(colors[i] == colors[j]){
                        } else {
                            num += cMaps[colors[j]];
                        }
                    } 
                }
            }
        }
        if (maxNum < num) {
            maxNum = num;
        }
    }

    printf("%max Num = %d", maxNum);
}

void test_demo_0626() {
    printf("0626");
    vector<int> num = { 1,4,3,4,5 };
    vector<char> color = { 'r','y','b','b','r'};

 /*   vector<int> num = { 1,2,3,4 };
    vector<char> color = { 'r','y','b','g'};*/

    demo_0626(num, color);
}
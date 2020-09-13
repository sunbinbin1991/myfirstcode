#pragma once
#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cmath>
using namespace std;
void reverseString(vector<char>& s)
{
    if (s.empty()) return;
    char * left = s.data();
    char * right = s.data() + s.size()-1;
    if (left == right) return;
   
    //printf("%d %d \n", left, right);
    while (left < right) {
        printf("%c %c \n", *left, *right);
        swap(*left, *right);
        printf("%c %c \n", *left, *right);
        left += 1;
        right -= 1;
        printf("%d %d \n", left, right);
    }
    for (int i = 0; i < s.size(); i++) {
        printf("%c\n", s[i]);
    }
}

void test_reverseString() {
    string input = "hello world";
    vector<char> inputStr(input.size());
    memcpy(inputStr.data(), input.data(), input.size() * sizeof(char));
    reverseString(inputStr);
}
#pragma once
#include <iostream>
#include <string>
using namespace std;
int strStr(string haystack, string needle)
{
    return haystack.find(needle);
}

void test_strStr() {
    string first = "a";
    string second = "a";
    cout << strStr(first, second) <<endl;
}


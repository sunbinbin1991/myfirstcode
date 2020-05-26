#pragma once
class Solution {
public:
	int calculateArea(int *start,int *end) {
		int min2 = std::min(*start, *end);
		//printf("*end - *start= %d end - start = %d\n", *end - *start,end - start);
		return (min2)*  (end - start);
	}

	int maxArea(vector<int>& height)
	{
		if (height.size() < 2) return 0;
		int *start;
		int *end;
		start = height.data();
		end = height.data() + height.size() - 1;
		int max_val = INT_MIN;
		while (end != start) {
			int tmpval = calculateArea(start, end);
			if (tmpval > max_val) {
				max_val = tmpval;
			} 
			if (*start > *end) {
				end--;
			} else {
				start++;
			}
		}
		//printf(" start end %d %d \n", *start, *end);
		printf(" max_val  %d \n", max_val);
		return 0;
	}
};

void test_maxArea() {
	Solution s1;
	vector<int> inputArray = { 1,8,6,2,5,4,8,3,7 };
	//s1.maxArea(inputArray);
}
#pragma once
#include <vector>
#include <iostream>
#include<algorithm>
template<tpyename T> class DynamicArray {
public:
	void insert(T num) {
		if ((min.size() + max.size()) & 1 == 0) {
			if (max.size() > 0 && num < max[0]) {
				max.push_back(num);
				push_heap(max.begin(), max.end(), less<T>());

				num = max[0];

				pop_heap(max.begin(), max.end(), less<T>());
				max.pop_back();
			}
			min.push_back(num);
			push_heap(min.begin(), min.end(), less<T>());
			
		}
		else {
			if (min.size() > 0 && num < min[0]) {
				min.push_back(num);

				push_heap(min.begin(), min.end(), less<T>());
				
				num = min[0];
				pop_heap(min.begin(), min.end(), less<T>());
				min.pop_back();
			}
			max.push_back(num);
			push_heap(max.begin(), max.end(), less<T>());		
		}
	};
	
	T getMedian() {
		int size = min.size() + max.size();
		if (size == 0) {
			printf("error");
		}
		T median = 0;
		if (size & 1 == 1)
			median = min[0];
		else
			median = (min[0] + max[0]) / 2;
		return median;
	}

private:
	vector<T> min;
	vector<T> max;
};
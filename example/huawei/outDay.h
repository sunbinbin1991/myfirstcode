#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int mounth[12] = { 31,29,31,30,31,30,31,31,30,30,31 };
bool checkInput(int year,int mouth,int date) {
	return (year < 0) || mouth < 0 || mouth>12 || date < 0 || date>31;
}
int getDate(int year,int mouth,int day) {
	if (checkInput(year, mouth, day)) {
		return -1;
	}
	int * tmpMounth = mounth;
	if (year % 4 != 0) {
		tmpMounth[1] = 28;
		if (day > 28) return -1;
	}
	if (year % 100 == 0&&year%400!=0) {
		tmpMounth[1] = 28;
		if (day > 28) return -1;
	}
	int sum = 0;
	for (int i = 0; i < mouth-1; i++)
	{
		sum += tmpMounth[i];
	}
	sum += day;
	
	return sum;

}

int test_getOutDay() {
	int year = 0;
	int mth = 0;
	int date = 0;
	while (cin>>year>> mth >>date) {
		int flag =  getDate(year, mth, date);
		cout << flag << endl;
	}

	return 0;
}
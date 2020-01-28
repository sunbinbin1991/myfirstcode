#pragma once
#include<iostream>
template<class T>
class NameObject {
public:
	NameObject(std::string& name, const T&value, const T&value2);
private:
	std::string namevalue;
	T objectValue;
	T objectValue;
};

void test_class() {
	std::string oldDog("apple");
	std::string newDog("banana");

	NameObject<int> p(newDog, 2,2);
	NameObject<int> s(newDog, 36,24);

	p = s;//failed when build
}

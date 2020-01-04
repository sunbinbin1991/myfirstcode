#include <iostream>
#include <vector>
#include <chrono>
#include "lowprice.h"
#include "posision_move.h"
#include "maxLengthofString.h"
#include "alg_basic.h"
#include "hupai.h"
#include "splitString.h"
#include "hex2binary.h"
#include "primerfactor.h"
#include "sortkeyvalue.h"

void test_case() {
	//test_lowprice();
	//test_move();
	//test_len_of_string();
	//bubblesort();
	//test_hupai();
	//test_splitstring();	
	//test_hex2binary();
	//test_primerfactor();

	test_sort_key_value();


}


int main()
{
    printf("hello world\n");

	test_case();
	system("pause");
	return 0;
}


//1£º for num
//int num;
//while (cin >> num)
//{
//	if (num == 0) return 0;
//	int res = changeBottle3(num);
//	cout << res << endl;
//}
//return 0;

//2:for string
//string str;
//while (cin >> str) {
//}
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
#include "integerdelduplicate.h"
#include "sortstringbydict.h"
#include "ipinfojudge.h"
#include "getCubeRoot.h"
#include "splitpath.h"
#include "checkpassword.h"
#include "simple_encry.h"

void test_case() {
	//test_lowprice();
	//test_move();
	//test_len_of_string();
	//bubblesort();
	//test_hupai();
	//test_splitstring();	
	//test_hex2binary();
	//test_primerfactor();
	//test_sort_key_value();
	//test_integerdelduplicate();
	//test_getallacellnums();
	//test_getInversesentence();
	//test_string_compare();
	//sort_string_by_dict();
	//test_ip_illegal();
	//test_getCubeRoot();
	//test_splitpath();
	//test_decry();

}


void test_basic() {
	char ptr_A[] = "greet";
	char *ptr_B = "greet";
	const char *ptr_C = "greeter";
	char * const ptr_D = "greeter";//ptr_d data could not change!
	const char * const ptr_E = "greeter";
	ptr_C = "D";
	//ptr_D = "H";//error when build;
}

int main()
{
    printf("hello world\n");

	//test_case();
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
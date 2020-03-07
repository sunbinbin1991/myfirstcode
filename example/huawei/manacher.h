#pragma once
#include <iostream>  
#include <cstring>
#include <algorithm>  
#include<string>
using namespace std;

//char s[1000];
//char s_new[2000];
//int p[2000];
//
//int Init()
//{
//	int len = strlen(s);
//	s_new[0] = '$';
//	s_new[1] = '#';
//	int j = 2;
//
//	for (int i = 0; i < len; i++)
//	{
//		s_new[j++] = s[i];
//		s_new[j++] = '#';
//	}
//
//	s_new[j] = '\0';  // 别忘了哦
//
//	return j;  // 返回 s_new 的长度
//}
//
//int Manacher()
//{
//	int len = Init();  // 取得新字符串长度并完成向 s_new 的转换
//	int max_len = -1;  // 最长回文长度
//
//	int id;
//	int mx = 0;
//
//	for (int i = 1; i < len; i++)
//	{
//		if (i < mx)
//			p[i] = min(p[2 * id - i], mx - i);  // 需搞清楚上面那张图含义, mx 和 2*id-i 的含义
//		else
//			p[i] = 1;
//
//		while (s_new[i - p[i]] == s_new[i + p[i]])  // 不需边界判断，因为左有'$',右有'\0'
//			p[i]++;
//
//		// 我们每走一步 i，都要和 mx 比较，我们希望 mx 尽可能的远，这样才能更有机会执行 if (i < mx)这句代码，从而提高效率
//		if (mx < i + p[i])
//		{
//			id = i;
//			mx = i + p[i];
//		}
//
//		max_len = max(max_len, p[i] - 1);
//	}
//
//	return max_len;
//}

//int test_manacher()
//{
//	while (printf("请输入字符串：\n"))
//	{
//		scanf("%s", s);
//		printf("最长回文长度为 %d\n\n", Manacher());
//	}
//	return 0;
//}

//ERROR

#include <iostream>  
#include <cstring>
#include <algorithm>  

using namespace std;

//char s[1000];
//char s_new[2000];
//int p[2000];

int Init(const string& s, string & s_new)
{
	int len = strlen(s.c_str());
	s_new += "$";
	s_new += '#';
	int j = 2;

	for (int i = 0; i < len; i++)
	{
		s_new += s[i];
		s_new += '#';
		//j+=2;
	}

	s_new += '\0';  // 别忘了哦

	return  strlen(s_new.c_str());;  // 返回 s_new 的长度
}

int Manacher(const string& input)
{
	string s_new = "";
	int len = Init(input, s_new);  // 取得新字符串长度并完成向 s_new 的转换
	int max_len = -1;  // 最长回文长度
	int* p = new int[len+1];
	int id;
	int mx = 0;
	printf("%s \n%d\n", s_new.c_str(), strlen(s_new.c_str()));
	for (int i = 0; i < len; i++)
	{
		if (i < mx)
			p[i] = min(p[2 * id - i], mx - i);  // 需搞清楚上面那张图含义, mx 和 2*id-i 的含义
		else
			p[i] = 1;

		//while (s_new[i - p[i]] == s_new[i + p[i]])  // 不需边界判断，因为左有'$',右有'\0'
		//  p[i]++;

		while (i - p[i] >= 0 && i + p[i]<len && s_new[i - p[i]] == s_new[i + p[i]]) {
			p[i]++;
		}
		// 我们每走一步 i，都要和 mx 比较，我们希望 mx 尽可能的远，这样才能更有机会执行 if (i < mx)这句代码，从而提高效率
		if (mx < i + p[i])
		{
			id = i;
			mx = i + p[i];
		}
		//printf(" max_len= %d",len);
		max_len = max(max_len, p[i] - 1);
	}

	return max_len;
}

int test_main(const string& str) {
	//string str;
	//while (getline(cin, str)) {
		int len = str.length();
		if (len <= 1)
		{
			cout << len << endl;
			return 0;
		}
		int num = 1;
		for (int i = 1; i<len - 1; i++)
		{
			if (str[i] == str[i + 1])
			{//偶数对成
				int curnum = 0;
				int start = i; int end = i + 1;
				while (start >= 0 && end <= len && str[start] == str[end])
				{
					start--;
					end++;
					curnum += 2;
				}
				if (curnum>num)
					num = curnum;
			}
			if (str[i - 1] == str[i + 1])
			{//偶数对成
				int curnum = 1;
				int start = i - 1; int end = i + 1;
				while (start >= 0 && end <= len && str[start] == str[end])
				{
					start--;
					end++;
					curnum += 2;
				}
				if (curnum>num)
					num = curnum;
			}
		}
		cout << num << endl;
	//}
	return num;
}


int test_manacher()
{
	//while (printf("请输入字符串：\n"))
	//{
	//  scanf("%s", s);
	//printf("最长回文长度为 %d\n\n", Manacher());
	//}
	string str1 = "dsuehgfqxzrnkmtmiwytshrerjfybxirufrsobkjeghiunftxyqqcyoreevvktxgvjjqzvcujsynsrlgllebyukyxgugrvkesovfhzdznstvtbblmjcngwsdrmfczsihiblqhkfvhzylwopepfmnixeesvugyifdxvpcknpqunolpgjehoxgylnzoggqpbdkhrngchidhfdktblrifjvppttemmplzrsbjhltvwprhkigkvfkxcxfsgyiyuuziqurgcmddqshenindtrfzlrqpfpekfosmugpwjgydtbwexcwrvdedposftffjrfeojsqpxtoguroojsgrwpyiyhurprcfsgnnykjtrjjzdswfqfwuohpcssgjzyikruvomeggqzyslmfurgnmhyvnksktvdcidvutrrxzixbxiypbvozgnmopfjiljggqrronwkfqvlpdwhtzfpsokfbvftyxdinknsrjlxbzyfmsinegprbnuezqlikgsbbixfdjtsjxojqwxdrvwfflrwjsnpcxqvfpmbidyvvlcnvvvvbglhhmkpuzhosfitgzclicpzsvozsbtvtlmjffqieosliqysgyxmceytmezfbtkcprfomftlkyortyfmykslfdmxzfeetmzxbuvoorpwmkerujcjcuuyvmpqidrrksrtmxhqoqdyvjgvcftbhywmbdfoixecfgorpxoxbqlhbnynwflbodsdqvwwoizdfyczefvonoczocvtbixehcvpmimyxgzddvomklofuthtytqougojqwmxvhzpmvtfsjwrgmxuoeizmnfptssolqbmnrhfjitoqxizflyoddgjlxknumclfmpmrzpomrqqogvmwgclpquhuqbkriyjkwcusetkyxozomcrsuyfmsddwubkiyyjoeqlzjsfnwkhdpgxkeicbivlwbdvcbvdqbyxuwdolmtxzgpogtzctlcjemoxdrbrmmtkuuidtiebckmqluiszgichpm";
	//std::cin >> str1;
	int len = Manacher(str1);
	//int len = test_main(str1);
	printf("%d", len);

	return 0;
}

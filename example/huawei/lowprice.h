#include <iostream>
#include <string>
#include <vector>
using namespace std;

int test_lowprice()
{

	int nlen;
	int n2;
	vector<int> out;
	cin >> hex>> nlen;
	
	for (int i = 0; i < nlen; i++)
	{
		cin >> hex >> n2;
		if(n2==0xA)
		{
			out.push_back(0x12);
			out.push_back(0x34);
		}
		else if (n2 == 0xB)
		{
			out.push_back(0xab);
			out.push_back(0xcd);
		}
		else
		{
			out.push_back(n2);
		}


	}
	int outsize = out.size();
	cout<<outsize<<' ';
	for (int i = 0; i < outsize; i++)
	{
		cout << out.at(i) << ' ';
	}
	return 0;
}
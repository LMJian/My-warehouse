#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	if (str.empty())
	{
		cout << "" << endl;
		return 0;
	}
	auto left = str.begin();
	string::iterator right;
	string tmp;
	while (left != str.end() && right != str.end())
	{
		while ((*left<'0' || *left>'9') && left != str.end())
			++left;
		right = left;
		while ((*right >= '0'&&*right <= '9') && right != str.end())
			++right;
		string sst(left, right);
		if (tmp.size() < sst.size())
			tmp = sst;
		left = right;
	}
	cout << tmp << endl;
	return 0;
}
#include<iostream>
#include<string>
using namespace std;

/*class Solution {
public:
	int StrToInt(string str) {
		int number = 0;
		auto it = str.begin();
		char ch = '\0';
		if (*it == '+' || *it == '-')
		{
			ch = *it;
			it++;
		}
		while (it != str.end())
		{
			if (*it < '0' || *it>'9')
				return 0;
			number = number * 10 + *it - '0';
			it++;
		}
		if (ch == '-')
			number = -number;
		return number;
	}
};*/
class Solution {
public:
	string addStrings(string num1, string num2) {
		string num("0");
		string numt;
		if (num1.size()>num2.size())
		{
			num += num1;
			numt = num2;
		}
		else
		{
			num += num2;
			numt = num1;
		}
		auto it = num.rbegin();
		auto it_t = numt.rbegin();
		while (it_t != numt.rend())
		{
			*it = *it + *it_t - '0';
			if (*it>'9')
			{
				*it -= 10;
				it++;
				(*it)++;
				it_t++;
			}
			else
			{
				it++;
				it_t++;
			}
		}
		while (it != num.rend())
		{
			if (*it > '9')
			{
				*it -= 10;
				it++;
				(*it)++;
			}
			else
				it++;
		}
		if (num[0] == '0')
			num.erase(0);
		return num;
	}
};
int main()
{
	///Solution s;
	//cout<<s.addStrings("999999", "888") << endl;
	string s;
	getline(std::cin, s);
	/* s;
	Solution so;
	while (true)
	{
		cin >> s;
		cout << so.StrToInt(s) << endl;
	}*/
	system("pause");
	return 0;
}
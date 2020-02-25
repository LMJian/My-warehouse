#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> splite(const string &s, const string &c)//·Ö¸î×Ö·ûÓÃµÄ
{
	vector<string> ret;
	int left = 0;
	if (s.find(c) == 0)
		left = c.size();
	int right = s.find(c, left);
	while (right != string::npos) {
		ret.push_back(s.substr(left, right - left));
		left = right + c.size();
		right = s.find(c, left);
	}
	if (left < s.size() && right == string::npos)
		ret.push_back(s.substr(left));
	return ret;
}

int main()
{
	splite("1  23  345  6", "  ");
	system("pause");
	return 0;
}

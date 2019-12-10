#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string ReverseSentence(string str) {
		string ret(str.rbegin(), str.rend());
		auto left = ret.begin();
		auto right = ret.begin();
		while (left != ret.end() && right != ret.end()) {
			while (*left == ' '&&left != ret.end())
				++left;
			right = left;
			while (*right != ' '&&right != ret.end())
				++right;
			--right;
			auto a = left;
			auto b = right;
			while (a < b) {
				char tmp = *a;
				*a = *b;
				*b = tmp;
				++a;
				--b;
			}
			++right;
			left = right;
		}
		return ret;
	}
};

int main() {
	Solution sa;
	string str = "l am student";
	string ret = sa.ReverseSentence(str);
	cout << ret << endl;

	system("pause");
	return 0;
}
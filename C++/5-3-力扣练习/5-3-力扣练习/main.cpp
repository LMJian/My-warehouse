#include<iostream>
#include<string>
#include<stack>
using namespace std;

/*class Solution {
public:
	bool isValid(string s) {
		stack<char> sa;
		const char* ptr = s.c_str();
		while (*ptr != '\0') {
			if (sa.empty() || !judge(sa.top(), *ptr))
				sa.push(*ptr);
			else if (judge(sa.top(), *ptr))
				sa.pop();
			++ptr;
		}
		return sa.empty();
	}
private:
	bool judge(char a, char b) {
		if (a == '('&&b == ')')
			return true;
		if (a == '{'&&b == '}')
			return true;
		if (a == '['&&b == ']')
			return true;
		return false;
	}
};*/
#include<vector>
#include<algorithm>
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> ret;
		string str(n, '(');
		str += string(n, ')');
		do {
			if (isValid(str))
				ret.push_back(str);
		} while (next_permutation(str.begin(), str.end()));
		return ret;
	}
private:
	bool isValid(const string& s) {
		stack<char> sa;
		const char* ptr = s.c_str();
		while (*ptr != '\0') {
			if (sa.empty() || (!(sa.top() == '('&&*ptr == ')')))
				sa.push(*ptr);
			else
				sa.pop();
			++ptr;
		}
		return sa.empty();
	}
};
int main() {
	Solution sa;
	sa.generateParenthesis(3);
	//Solution sa;
	//cout<<sa.isValid("()")<<endl;
	system("pause");
	return 0;
}
#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
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
};

int main() {
	Solution sa;
	cout<<sa.isValid("()")<<endl;
	system("pause");
	return 0;
}
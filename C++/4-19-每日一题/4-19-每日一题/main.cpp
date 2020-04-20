#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int mate[1000][1000] = { 0 };
		int max = 0;
		string ret;
		for (size_t i = 0; i < s.size(); ++i) {
			for (size_t j = 0; j < s.size(); ++j) {
				if (s[s.size() - 1 - i] == s[j]) {
					if (i - 1 >= 0 && j - 1 >= 0) {
						mate[i][j] = mate[i - 1][j - 1] + 1;
					}
					else {
						mate[i][j] = 1;
					}
					if (max < mate[i][j]) {
						string tmp = s.substr(j + 1 - mate[i][j], mate[i][j]);
						if (Find(tmp)) {
							max = mate[i][j];
							ret = tmp;
						}
					}
				}
			}
		}
		return ret;
	}
private:
	bool Find(const string& s) {
		for (size_t i = 0; i < s.size() / 2; ++i) {
			if (s[i] != s[s.size() - 1 - i])
				return false;
		}
		return true;
	}
};

int main() {
	Solution sa;
	string s = "babad";
	cout<<sa.longestPalindrome(s)<<endl;


	system("pause");
	return 0;
}
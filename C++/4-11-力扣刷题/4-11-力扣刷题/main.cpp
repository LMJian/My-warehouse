#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() == 0 || s.size() < 2) {
			return s;
		}
		const int strLen = s.size();
		int maxStart = 0;  //最长回文串的起点
		int maxEnd = 0;    //最长回文串的终点
		int maxLen = 1;  //最长回文串的长度

		vector<vector<bool>>dp;
		vector<bool> t;
		t.resize(strLen);
		for (int i = 0; i < strLen; ++i)
			dp.push_back(t);

		for (int r = 1; r < strLen; r++) {
			for (int l = 0; l < r; l++) {
				if (s[l] == s[r] && (r - l <= 2 || dp[l + 1][r - 1])) {
					dp[l][r] = true;
					if (r - l + 1 > maxLen) {
						maxLen = r - l + 1;
						maxStart = l;
						maxEnd = r;

					}
				}

			}
		}
		for (int i = 0; i < strLen; i++) {
			for (int j = 0; j < strLen; j++) {
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		return s.substr(maxStart, maxEnd + 1);
	}
};
int main() {
	Solution sa;
	string s = "babad";
	cout << sa.longestPalindrome(s) << endl;
	system("pause");
	return 0;
}
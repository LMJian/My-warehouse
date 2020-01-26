#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
	bool isMatch(string s, string p) {
		int x = s.size(), y = p.size();
		bool arr[x + 1][y + 1] = { 0 };
		arr[0][0] = true;
		for (int i = 1; i <= y; ++i)
			arr[0][i] = (arr[0][i - 1]) && (p[i - 1] == '*');
		for (int i = 1; i <= x; ++i) {
			for (int j = 1; j <= y; ++j) {
				if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
					arr[i][j] = arr[i - 1][j - 1];
				else if (p[j - 1] == '*')
					arr[i][j] = arr[i][j - 1] || arr[i - 1][j] || arr[i - 1][j - 1];
			}
		}
		return arr[x][y];
	}
};
int main() {
	Solution sa;
	sa.isMatch("adceb", "*a*b");
	system("pause");
	return 0;
}
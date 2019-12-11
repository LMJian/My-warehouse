#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int DP(string& s1, string& s2) {
	int len1 = s1.size();
	int len2 = s2.size();
	if (s1.empty() || s2.empty())
		return max(len1, len2);
	vector<vector<int>> arr(len1 + 1, vector<int>(len2 + 1, 0));
	for (int i = 0; i <= len1; ++i) {
		arr[i][0] = i;
	}
	for (int i = 0; i <= len2; ++i) {
		arr[0][i] = i;
	}
	for (int i = 1; i <= len1; ++i) {
		for (int j = 1; j <= len2; ++j) {
			if (s1[i - 1] == s2[j - 1]) {
				//arr[i][j]=min(arr[i][j-1]+1,arr[i-1][j]+1);
				//arr[i][j]=min(arr[i-1][j-1],arr[i][j]);
				arr[i][j] = arr[i - 1][j - 1];
			}
			else {
				arr[i][j] = min(arr[i][j - 1] + 1, arr[i - 1][j] + 1);
				arr[i][j] = min(arr[i - 1][j - 1] + 1, arr[i][j]);
			}
		}
	}
	return arr[len1][len2];
}
int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		cout << DP(s1, s2) << endl;
	}
	return 0;
}

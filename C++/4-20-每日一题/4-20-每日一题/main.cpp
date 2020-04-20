#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		vector<string> arr;
		arr.resize(numRows);
		auto it = s.begin();
		while (it != s.end()) {
			for (int i = 0; it != s.end() && i < numRows; ++i) {
				arr[i] += *it;
				++it;
			}
			for (int i = numRows - 2; it != s.end() && i > 0; --i) {
				arr[i] += *it;
				++it;
			}
		}
		string ret;
		for (int i = 0; i < numRows; ++i) {
			ret += arr[i];
		}
		return ret;
	}
};

int main() {
	Solution sa;
	string s = "PAYPALISHIRING";
	cout << sa.convert(s, 4) << endl;
	system("pause");
	return 0;
}
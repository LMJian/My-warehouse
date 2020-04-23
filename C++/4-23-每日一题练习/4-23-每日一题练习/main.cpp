/*// write your code here cpp
#include<iostream>
using namespace std;

int main() {
	int left;
	int right;
	while (cin >> left >> right) {
		long long a = 0;
		long long b = 1;
		long long c = 1;
		for (int i = 2; i <= left; ++i) {
			c = a + b;
			a = b;
			b = c;
		}
		long long ret = c;
		for (int i = left + 1; i <= right; ++i) {
			c = a + b;
			ret += c;
			a = b;
			b = c;
		}
		cout << ret << endl;
	}
	return 0;
}*/
// write your code here cpp
#include<vector>
#include<string>
#include<iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		getchar();
		vector<string> arr;
		arr.resize(n);
		for (int i = 0; i < n; ++i)
			getline(cin, arr[i]);
		for (int i = 0; i < n - 1; ++i) {
			if (arr[i].find(' ', 0) != string::npos || arr[i].find(',', 0) != string::npos)
				cout << "\"" << arr[i] << "\"" << ", ";
			else
				cout << arr[i] << ", ";
		}
		if (arr[n - 1].find(' ', 0) != string::npos || arr[n - 1].find(',', 0) != string::npos)
			cout << "\"" << arr[n - 1] << "\"" << endl;
		else
			cout << arr[n - 1] << endl;
	}
	return 0;
}

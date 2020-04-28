// write your code here cpp
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<string> arr;
		arr.resize(n);
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		sort(arr.begin(), arr.end(), [](const string& left, const string& right) {
			return strcmp(left.c_str(), right.c_str()) < 0;
		});
		for (int i = 0; i < n - 1; ++i) {
			if (arr[i + 1].find(arr[i], 0) != 0)
				cout << "mkdir -p " << arr[i] << endl;
		}
		cout << "mkdir -p " << arr[n - 1] << endl;
	}
	return 0;
}
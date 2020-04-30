// write your code here cpp
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main() {
	int n;
	vector<int> arr;
	int _max = 0;
	while (cin >> n) {
		_max = 0;
		if (n > arr.size())
			arr.resize(n);
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		for (int i = 0; i < n - _max; ++i) {
			stack<int> sta;
			for (int j = i; j < n; ++j) {
				if (sta.empty() || sta.top() < arr[j])
					sta.push(arr[j]);
				else {
					while ((!sta.empty()) && sta.top() >= arr[j])
						sta.pop();
					sta.push(arr[j]);
				}
				if (_max < sta.size())
					_max = sta.size();
			}
		}
		cout << _max << endl;
	}
	return 0;
}
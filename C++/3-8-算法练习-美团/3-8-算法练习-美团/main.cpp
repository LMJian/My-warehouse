#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	vector<int> arr;
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int left = 0;
	int right = n - 1;
	int count = 0;
	int zero = 0;
	while (left <= right) {
		while (left <= right && arr[left] == 0)
			++left;
		while (left <= right && arr[right] == 0)
			--right;
		if (left > right)
			break;
		zero = 0;
		for (int i = left; i <= right; ++i) {
			if (arr[i] == 0)
				++zero;
			else
				--arr[i];
		}
		count += zero + 1;
	}
	cout << count << endl;
}
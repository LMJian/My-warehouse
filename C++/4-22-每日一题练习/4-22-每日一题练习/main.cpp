// write your code here cpp
#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> arr;
	arr.resize(100001);
	arr[1] = 1;
	arr[2] = 2;
	int index = -1;
	for (int i = 3; i <= 100000; ++i) {
		arr[i] = arr[i - 1] + arr[i - 2];
		if (arr[i] >= 1000000) {
			arr[i] = arr[i] % 1000000;
			if (index == -1)
				index = i;
		}
	}
	int n;
	while (cin >> n) {
		if (n < index)
			cout << arr[n] << endl;
		else
			printf("%06d\n", arr[n]);
	}
	return 0;
}
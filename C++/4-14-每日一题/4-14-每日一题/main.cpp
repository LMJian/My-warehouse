// write your code here cpp
#include<iostream>
#include<vector>
using namespace std;

int Count(int n) {
	if (n <= 3)
		return n;
	int a = 2;
	int b = 3;
	int c;
	for (int i = 4; i <= n; ++i) {
		c = (a + b) % 10000;
		a = b;
		b = c;
	}
	return c;
}


int main() {
	int n;
	vector<int> arr;
	while (cin >> n) {
		arr.resize(n);
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		for (int i = 0; i < n; ++i) {
			printf("%04d", Count(arr[i]));
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
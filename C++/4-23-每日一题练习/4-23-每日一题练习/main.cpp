// write your code here cpp
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
}
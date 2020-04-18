// write your code here cpp
#include<iostream>
#include<cmath>
using namespace std;

bool Find(int n) {
	if (n == 1)
		return false;
	if (n == 2 || n == 3)
		return true;

	if (n % 2 == 0)
		return false;
	for (int i = 3; i <= sqrt(n); i = i + 2) {
		if (n%i == 0)
			return false;
	}
	return true;
}

int main() {
	int n;
	while (cin >> n) {
		int ret = 0;
		for (int i = 1; i < sqrt(n); ++i) {
			if (n%i == 0) {
				if (Find(i))
					++ret;
				if (Find(n / i))
					++ret;
			}
		}
		int s = sqrt(n);
		if (s*s == n && Find(s))
			++ret;
		cout << ret << endl;
	}
	return 0;
}
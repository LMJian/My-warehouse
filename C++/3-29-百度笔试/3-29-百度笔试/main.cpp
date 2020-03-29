#include<iostream>
using namespace std;
typedef int(*ZAA)[10000];

//ZAA LCM = (ZAA)new int[1000000]{ 0 };
int LCM[10000][10000] = { 0 };
int lcm(int a, int b) {
	if (LCM[a][b] != 0)
		return LCM[a][b];
	int max = a > b ? a : b;
	int min = a < b ? a : b;
	for (int i = 2;; ++i) {
		if ((i*min) % max == 0) {
			LCM[a][b] = i * min;
			return i * min;
		}
	}
	return -1;
}
//ZAA GCD = (ZAA)new int[1000000]{ 0 };
int GCD[10000][10000] = { 0 };
int gcd(int a, int b) {
	if (GCD[a][b] != 0)
		return GCD[a][b];
	int max = a > b ? a : b;
	int min = a < b ? a : b;
	for (int i = 2; i <= max; ++i) {
		if (max%i == 0) {
			int num = max / i;
			if (min%num == 0) {
				GCD[a][b] = num;
				return num;
			}
		}
	}
	return -1;
}

int main() {
	int n;
	cin >> n;
	int max = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (max < lcm(i, j) - gcd(i, j))
				max = lcm(i, j) - gcd(i, j);
		}
	}
	cout << max << endl;
	system("pause");
	return 0;
}
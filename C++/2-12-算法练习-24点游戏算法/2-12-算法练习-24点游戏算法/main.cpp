#include<iostream>
#include<algorithm>
using namespace std;

int arr[4] = { 0 };

bool Find(int num) {
	int ret = 0;
	if (num / 16 == 0)//+
		ret = arr[0] + arr[1];
	else if (num / 16 == 1)//-
		ret = arr[0] - arr[1];
	else if (num / 16 == 2)//*
		ret = arr[0] * arr[1];
	else
		ret = arr[0] / arr[1];
	num = num % 16;
	if (num / 4 == 0)//+
		ret += arr[2];
	else if (num / 4 == 1)//-
		ret -= arr[2];
	else if (num / 4 == 2)//*
		ret *= arr[2];
	else
		ret /= arr[2];
	num = num % 4;
	if (num == 0)//+
		ret += arr[3];
	else if (num == 1)//-
		ret -= arr[3];
	else if (num == 2)//*
		ret *= arr[3];
	else
		ret /= arr[3];
	return ret == 24;
}
int main() {
	while (cin >> arr[0] >> arr[1] >> arr[2] >> arr[3]) {
		int flog = 1;
		for (int i = 0; i < 64; ++i) {
			do {
				if (Find(i)) {
					cout << "true" << endl;
					flog = 0;
					goto LOOP;
				};
			} while (next_permutation(arr, arr + 4));
		}
	LOOP:
		if (flog)
			cout << "false" << endl;
	}
	return 0;
}
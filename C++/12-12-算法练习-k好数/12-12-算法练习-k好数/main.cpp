#include<iostream>
#include<vector>
using namespace std;

int k, l;
int arr[100][100] = { 0 };

int Print(int ret, int len) {
	int sum = 0;
	if (len == l)
		return 1;
	for (int i = 0; i < k; ++i) {
		if (i - 1 != ret && i + 1 != ret)
		{
			if (len == l - 1 && i == 0)
				sum += 0;
			else if (arr[i][len + 1] > 0)
				sum += arr[i][len + 1];
			else
				sum += Print(i, len + 1);
		}
	}
	if (ret != -2)
		arr[ret][len] = sum;
	return sum;
}

int main() {
	while (cin >> k >> l) {
		memset(arr, 0, sizeof(arr));
		cout << Print(-2, 0) << endl;
	}
	return 0;
}
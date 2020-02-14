#include<iostream>
#include<vector>
using namespace std;

bool dfs(vector<double> &arr, double left) {
	if (arr[0] == -1 && arr[1] == -1 && arr[2] == -1 && arr[3] == -1)
		return left == 24;
	for (int i = 0; i < 4; ++i) {
		if (arr[i] != -1) {
			double tmp = arr[i];
			arr[i] = -1;
			if (dfs(arr, left + tmp) || dfs(arr, left - tmp) || dfs(arr, left*tmp) || dfs(arr, left / tmp))
				return true;
			arr[i] = tmp;
		}
	}
	return false;
}
int main() {
	vector<double> arr(4);
	while (cin >> arr[0] >> arr[1] >> arr[2] >> arr[3]) {
		int flog = 1;
		for (int i = 0; i < 4; ++i) {
			double tmp = arr[i];
			arr[i] = -1;
			if (dfs(arr, tmp)) {
				cout << "true" << endl;
				flog = 0;
				break;
			}
			arr[i] = tmp;
		}
		if (flog)
			cout << "false" << endl;
	}
	return 0;
}
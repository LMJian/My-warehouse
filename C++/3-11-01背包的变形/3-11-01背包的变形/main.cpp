#include<iostream>
using namespace std;

int n, x;
int arr[100] = { 0 };
int mate[100][10000] = { 0 };

int dfs(int i, int t) {
	if (t <= 0)     //正确结果
		return 0;
	if (i == n)     //错误结果
		return 0x7FFFFFFF;

	if (mate[i][t] > 0)
		return mate[i][t];
	int v1 = dfs(i + 1, t);
	int v2 = 0x7FFFFFFF;
	if (t > 0) {
		//v2=arr[i]+dfs(i+1,t-arr[i]);
		v2 = dfs(i + 1, t - arr[i]);
		if (v2 != 0x7FFFFFFF)
			v2 += arr[i];
	}
	v1 = v1 < v2 ? v1 : v2;
	mate[i][t] = v1;
	return v1;
}
int main() {
	cin >> n >> x;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	cout << dfs(0, x) << endl;
	system("pause");
	return 0;
}
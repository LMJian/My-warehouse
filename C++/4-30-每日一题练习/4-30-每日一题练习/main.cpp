// write your code here cpp
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int n;
vector<int> arr;
int _max = 0;

void dfs(stack<int>& sta, int index) {
	if (index == n) {
		if (sta.size() > _max)
			_max = sta.size();
		return;
	}
	dfs(sta, index + 1);
	if (sta.empty() || sta.top() < arr[index]) {
		sta.push(arr[index]);
		dfs(sta, index + 1);
		sta.pop();
	}
}

int main() {
	while (cin >> n) {
		_max = 0;
		stack<int> sta;
		if (n > arr.size())
			arr.resize(n);
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		dfs(sta, 0);
		cout << _max << endl;
	}
	return 0;
}
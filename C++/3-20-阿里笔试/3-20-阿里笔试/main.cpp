#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

int n;
vector<string> arr;
int max_ = 0;
unordered_map<string, int> umap;
int maze[1024] = { 0 };
int ret[1024][1024] = { 0 };

void dfs(int index, int count, string& str) {
	if (index == n) {
		if (max_ < count) {
			max_ = count;

			int x = maze[index - 1];
			int y = umap[str];
			ret[x][y] = count;
		}
		return;
	}
	int x = maze[index];
	int y = umap[str];
	if (ret[x][y] > 0) {
		return;
	}
	if (str.empty() || *(str.rbegin()) <= *(arr[index].begin())) {
		string tmp = str;
		str += arr[index];
		dfs(index + 1, count + arr[index].size(), str);
		str = tmp;
	}
	dfs(index + 1, count, str);

}

int main() {
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	sort(arr.begin(), arr.end());
	string str = "";
	dfs(0, 0, str);
	cout << max_ << endl;
	system("pause");
	return 0;
}
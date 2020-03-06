#include<iostream>
#include<vector>
using namespace std;

vector<int> arr[100001];

int main() {
	int n;
	cin >> n;
	int x, y;
	for (int i = 0; i < n - 1; ++i) {
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}

	int count = 0;
	vector<int> tmp;
	tmp.push_back(1);
	while (!tmp.empty()) {
		vector<int> t;
		for (int i = 0; i < tmp.size(); ++i) {
			for (int j = 0; j < arr[tmp[i]].size(); ++j) {
				t.push_back(arr[tmp[i]][j]);
			}
			arr[tmp[i]].clear();
		}
		if (!t.empty()) {
			++count;
		}
		tmp = t;
	}
	if (count > 0)
		--count;
	cout << 2 * (n - 1) - count << endl;
	return 0;
}
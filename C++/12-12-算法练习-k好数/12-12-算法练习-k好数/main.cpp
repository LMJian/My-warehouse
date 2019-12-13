#include<iostream>
#include<vector>
using namespace std;

void Set(vector<int>& arr, int num) {

}
void Print(int k, int l) {
	vector<int> arr(k, 0);
	for (int i = 1; i < k - 1; ++i) {
		arr[i] = k - 2;
	}
	arr[0] = arr[k - 1] = k - 1;
	vector<int> maze(k, 0);
	Set(maze, 1);
	for (int i = 0; i < l - 1; ++i) {

	}

}
int main() {
	int k, l;
	while (cin >> k >> l) {
		Print(k, l);
	}
	return 0;
}
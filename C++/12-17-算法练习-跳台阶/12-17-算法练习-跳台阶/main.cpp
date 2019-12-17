#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int jumpFloor(int number) {
		if (number == 0 || number == 1 || number == 2)
			return number;
		vector<int> arr;
		arr.resize(number + 1);
		arr[1] = 1; arr[2] = 2;
		for (int i = 3; i <= number; ++i) {
			arr[i] = arr[i - 1] + arr[i - 2];
		}
		return arr[number];
	}
};

int main() {
	Solution sa;
	int n;
	while (cin >> n)
		cout << sa.jumpFloor(n) << endl;
	return 0;
}
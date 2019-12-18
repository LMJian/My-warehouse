#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		vector<int> odd;
		vector<int> even;
		for (int i = 0; i < array.size(); ++i) {
			if (array[i] % 2 == 1) {
				odd.push_back(array[i]);
			}
			else {
				even.push_back(array[i]);
			}
		}
		for (int i = 0; i < odd.size(); ++i) {
			array[i] = odd[i];
		}
		for (int i = 0; i < even.size(); ++i) {
			array[odd.size() + i] = even[i];
		}
	}
};

int main() {
	vector<int> arr{ 1,3,6,9,8,5,2,3,4,7 };
	Solution sa;
	sa.reOrderArray(arr);
	for (auto e : arr) {
		cout << e << " ";
	}
	system("pause");
	return 0;
}
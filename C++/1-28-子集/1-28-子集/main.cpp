#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		int size = nums.size();
		size = int(pow(2, size));
		vector<vector<int>> ret;
		for (int i = 0; i < size; ++i) {
			Set(nums, i, ret);
		}
		return ret;
	}
private:
	void Set(vector<int>& nums, int num, vector<vector<int>>& ret) {
		vector<int> arr;
		for (int i = 0; i < nums.size(); ++i) {
			if (num & 0x01)
				arr.push_back(nums[i]);
			num >>= 1;
		}
		ret.push_back(arr);
	}
};

int main() {
	Solution sa;
	vector<int> v{ 1,2,3 };
	vector<vector<int>> ret=sa.subsets(v);
	for (int i = 0; i < ret.size(); ++i) {
		for (int j = 0; j < ret[i].size(); ++j)
			cout << ret[i][j] << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> mp;
		vector<int> ret;
		for (int i = 0; i < nums.size(); ++i) {
			if (2 * nums[i] != target && mp.find(target - nums[i]) != mp.end()) {
				ret.push_back(i);
				ret.push_back(mp[target - nums[i]]);
				return ret;
			}
			else if (2 * nums[i] == target && mp.find(nums[i]) != mp.end()) {
				if (mp.find(nums[i])->second != i) {
					ret.push_back(mp[nums[i]]);
					ret.push_back(i);
					return ret;
				}
			}
			mp[nums[i]] = i;
		}
		return ret;
	}
};


int main() {
	Solution sa;
	vector<int> a{ 3,2,4 };
	sa.twoSum(a, 6);

	system("pause");
	return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> ret;
		int len = nums.size();
		int left, right;
		for (int index = 0; index < len&&nums[index] <= 0; ++index) {
			left = index + 1;
			right = len - 1;
			while (left < right) {
				if (nums[index] + nums[left] + nums[right] < 0)
					++left;
				else if (nums[index] + nums[left] + nums[right] > 0)
					--right;
				else {
					ret.push_back(vector<int>{nums[index], nums[left], nums[right]});
					while (left + 1 < len&&nums[left] == nums[left + 1])
						++left;
					while (right - 1 >= 0 && nums[right] == nums[right - 1])
						--right;
					++left;
					--right;
				}
			}
			while (index + 1 < len&&nums[index] == nums[index + 1])
				++index;
		}
		return ret;
	}
};*/

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (digits.empty())
			return ret;
		dfs(digits, 0, "");
		return ret;
	}
private:
	void dfs(string& digits, int index, string str) {
		if (index == digits.size()) {
			ret.push_back(str);
			return;
		}
		for (int i = 0; i < arr[digits[index] - '2'].size(); ++i) {
			dfs(digits, index + 1, str + arr[digits[index] - '2'][i]);
		}
	}
	vector<string> ret;
	vector<string> arr{ "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
};

int main() {
	Solution sa;
	sa.letterCombinations("23");
	//vector<int> arr{ -1, 0, 1, 2, -1, -4 };
	//sa.threeSum(arr);
	return 0;
}
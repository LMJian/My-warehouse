#include<iostream>
#include<vector>
using namespace std;
/*
class Solution {
public:
	string reverseOnlyLetters(string S) {
		vector<char> arr(S.begin(), S.end());
		int left = 0;
		int right = S.size() - 1;
		while (left < right) {
			while ((left < right) && (!Judge(arr[left])))
				++left;
			while ((left < right) && (!Judge(arr[right])))
				--right;
			if (left < right) {
				char tmp = arr[left];
				arr[left] = arr[right];
				arr[right] = tmp;
			}
			++left;
			--right;
		}
		string ret(arr.begin(), arr.end());
		return ret;
	}
private:
	bool Judge(char ch) {
		return (ch >= 'A'&&ch <= 'Z') || (ch >= 'a'&&ch <= 'z');
	}
};
float func(float a, int b) { 
	float m = 1, n = 1; 
	int i; 
	for (i = 1; i < b; i++) { 
		m *= a / i; 
		n += m; 
	}
	return n; 
}*/
/*class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> index_arr;
		vector<int> ret;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] > index_arr.size() - 1) {
				index_arr.resize(nums[i] + 1, -1);
			}
			index_arr[nums[i]] = i;
		}
		for (int i = 0; i < nums.size(); ++i) {
			if (index_arr[target - nums[i]] != -1) {
				ret.push_back(index_arr[target]);
				ret.push_back(index_arr[nums[i]]);
				return ret;
			}
		}
		return ret;
	}
};*/
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> index_arr;
		vector<int> ret;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] > int(index_arr.size()) - 1) {
				index_arr.resize(nums[i] + 1, -1);
			}
			index_arr[nums[i]] = i;
		}
		for (int i = 0; i < nums.size(); ++i) {
			if (index_arr[target - nums[i]] != -1) {
				ret.push_back(index_arr[target]);
				ret.push_back(index_arr[nums[i]]);
				return ret;
			}
		}
		return ret;
	}
};


int main() { 
	Solution sa;
	vector<int> arr{ 2,7,11,15 };
	sa.twoSum(arr, 9);
	//cout << func(0, 9999) << endl;
	//char str[] = "ABCD", *p = str;
	//printf("%d\n", *(p + 4)); 
	system("pause");
	return 0;
}
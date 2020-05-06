#include<iostream>
#include<vector>
using namespace std;

/*class Solution {
private:
	int findMaxIndex(vector<int>& height) {
		int max = -1;
		int maxIndex = -1;
		for (int i = 0; i < height.size(); ++i) {
			if (max < height[i]) {
				max = height[i];
				maxIndex = i;
			}
		}
		return maxIndex;
	}
	void initArr(vector<int>& arr, int maxIndex) {
		int max = -1;
		for (int i = 0; i < maxIndex; ++i) {
			if (arr[i] > max)
				max = arr[i];
			else
				arr[i] = max;
		}
		max = -1;
		for (int i = arr.size() - 1; i > maxIndex; --i) {
			if (arr[i] > max)
				max = arr[i];
			else
				arr[i] = max;
		}
	}
	void myCount(vector<int>& height, vector<int>& arr, int left, int right, int& count) {
		for (int i = left; i <= right; ++i) {
			count += arr[i] - height[i];
		}
	}
public:
	int trap(vector<int>& height) {
		//寻找最大值及其下标
		int maxIndex = findMaxIndex(height);
		//初始化arr
		vector<int> arr(height.begin(), height.end());
		initArr(arr, maxIndex);
		//开始统计
		int count = 0;
		//统计左边
		int mid = maxIndex - 1;
		for (int i = maxIndex - 1; i > 0; --i) {
			if (arr[i] != arr[i - 1]) {
				myCount(height, arr, i + 1, mid, count);
				mid = i - 1;
			}
			else if (i - 1 == 0) {
				myCount(height, arr, i, mid, count);
			}
		}
		//统计右边
		mid = maxIndex + 1;
		for (int i = maxIndex + 1; i < arr.size() - 1; ++i) {
			if (arr[i] != arr[i + 1]) {
				myCount(height, arr, mid, i - 1, count);
				mid = i + 1;
			}
			else if (i + 1 == arr.size() - 1) {
				myCount(height, arr, mid, i, count);
			}
		}
		return count;
	}
};*/

class Solution {
private:
	bool judge(const string& a, const string& b) {
		if (a.size() != b.size())
			return false;
		int arr[256] = { 0 };
		auto it = a.begin();
		while (it != a.end()) {
			++arr[(unsigned char)(*it)];
			++it;
		}
		it = b.begin();
		while (it != b.end()) {
			--arr[(unsigned char)(*it)];
			if (arr[(unsigned char)(*it)] < 0)
				return false;
			++it;
		}
		return true;
	}
	int myFind(const vector<vector<string>>& ret, const string& str) {
		for (int i = 0; i < ret.size(); ++i) {
			if (judge(ret[i][0], str)) {
				return i;
			}
		}
		return -1;
	}
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> ret;
		for (int i = 0; i < strs.size(); ++i) {
			int index = myFind(ret, strs[i]);
			if (index == -1) {
				ret.push_back(vector<string>{strs[i]});
			}
			else {
				ret[index].push_back(strs[i]);
			}
		}
		return ret;
	}
};

#include<algorithm>
int main() {
	Solution sa;
	vector<string> arr{ "tea","","eat","","tea","" };
	sa.groupAnagrams(arr);
	//Solution sa;
	//vector<int> arr{ 0,1,0,2,1,0,1,3,2,1,2,1 };
	//sa.trap(arr);
	system("pause");
	return 0;
}
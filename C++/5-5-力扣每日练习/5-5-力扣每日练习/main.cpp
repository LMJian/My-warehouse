#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		int mid;
		while (left <= right) {
			mid = (left + right) >> 1;
			if (nums[mid] == target)
				return mid;
			//ÅĞ¶ÏÓĞĞò    [left,mid-1]
			if (left <= mid - 1 && nums[left] <= nums[mid - 1]) {
				if (target >= nums[left] && target <= nums[mid - 1])
					right = mid - 1;
				else
					left = mid + 1;
			}
			//  [mid+1,right]
			else if (mid + 1 <= right && nums[mid + 1] <= nums[right]) {
				if (target >= nums[mid + 1] && target <= nums[right])
					left = mid + 1;
				else
					right = mid - 1;
			}
			else
				break;
		}
		return -1;
	}
};

int main() {
	Solution sa;
	vector<int> arr{ 4,5,6,7,0,1,2 };
	cout<<sa.search(arr, 3) << endl;
	system("pause");
	return 0;
}
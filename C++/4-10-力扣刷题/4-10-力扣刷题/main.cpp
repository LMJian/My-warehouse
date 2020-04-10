#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int len = nums1.size() + nums2.size();
		int k = (len + 1) / 2;
		double ret = 0;
		int index = 0;
		int ind1 = 0;
		int ind2 = 0;
		while (k&&ind1 < nums1.size() && ind2 < nums2.size()) {
			index = k / 2;
			if (index != 0)
				--index;
			if (ind1 + index < nums1.size() && ind2 + index < nums2.size() && nums1[ind1 + index] < nums2[ind2 + index]) {
				ind1 += index + 1;
				k -= index + 1;
			}
			else if(ind1 + index < nums1.size() && ind2 + index < nums2.size() && nums1[ind1 + index] >= nums2[ind2 + index]){
				ind2 += index + 1;
				k -= index + 1;
			}
			else if (ind1 + index >= nums1.size()) {
				k -= nums1.size() - ind1;
				ind1 = nums1.size();
			}
			else {
				k -= nums2.size() - ind2;
				ind2 = nums2.size();
			}
		}
		if (!k) {
			if (len % 2 == 1) {
				if (ind2 == 0 || ind1 - 1 >= 0 && ind2 - 1 >= 0 && nums1[ind1 - 1] > nums2[ind2 - 1])
					ret = nums1[ind1 - 1];
				else
					ret = nums2[ind2 - 1];
			}
			else {
				if (ind2 == 0 || ind1 - 1 >= 0 && ind2 - 1 >= 0 && nums1[ind1 - 1] > nums2[ind2 - 1]) {
					ret = nums1[ind1 - 1];
					if (ind1 == nums1.size())
						ret += nums2[ind2];
					else if (ind2 == nums2.size())
						ret += nums1[ind1];
					else
						ret += nums1[ind1] < nums2[ind2] ? nums1[ind1] : nums2[ind2];
					ret /= 2;
				}
				else {
					ret = nums2[ind2 - 1];
					if (ind1 == nums1.size())
						ret += nums2[ind2];
					else if (ind2 == nums2.size())
						ret += nums1[ind1];
					else
						ret+= nums1[ind1] < nums2[ind2] ? nums1[ind1] : nums2[ind2];
					ret /= 2;
				}
			}
		}
		else if (k&&ind1 < nums1.size()) {
			if (len % 2 == 1) {
				ret = nums1[ind1 + k - 1];
			}
			else {
				ret = nums1[ind1 + k - 1] + nums1[ind1 + k];
				ret /= 2;
			}
		}
		else if (k&&ind2 < nums2.size()) {
			if (len % 2 == 1) {
				ret = nums2[ind2 + k - 1];
			}
			else {
				ret = nums2[ind2 + k - 1] + nums2[ind2 + k];
				ret /= 2;
			}
		}
		return ret;
	}
};
 int main() {
	Solution sa;
	vector<int> a{ 4 };
	vector<int> b{ 1,2,3,5,6,7 };
	sa.findMedianSortedArrays(a, b);

	system("pause");
	return 0;
}
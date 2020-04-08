#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


/*class Solution {
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
};*/



struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		//对l1进行修改
		ListNode* l3 = new ListNode(0);
		ListNode* ptr = l3;
		int ret = 0;
		while (l1&&l2) {
			l3->next = new ListNode(l1->val + l2->val + ret);
			ret = 0;
			if (l3->next->val >= 10) {
				ret = 1;
				l3->next->val -= 10;
			}
			l1 = l1->next;
			l2 = l2->next;
			l3 = l3->next;
		}
		while (l1) {
			l3->next = new ListNode(l1->val + ret);
			ret = 0;
			if (l3->next->val >= 10) {
				ret = 1;
				l3->next->val -= 10;
			}
			l1 = l1->next;
			l3 = l3->next;
		}
		while (l2) {
			l3->next = new ListNode(l2->val + ret);
			ret = 0;
			if (l3->next->val >= 10) {
				ret = 1;
				l3->next->val -= 10;
			}
			l2 = l2->next;
			l3 = l3->next;
		}
		if (ret) {
			l3->next = new ListNode(1);
		}
		return ptr->next;
	}
};


int main() {
	Solution sa;
	//vector<int> a{ 3,2,4 };
	//sa.twoSum(a, 6);
	ListNode* p1 = new ListNode(2);
	p1->next= new ListNode(4);
	p1->next->next= new ListNode(3);

	ListNode* p2 = new ListNode(5);
	p2->next = new ListNode(6);
	p2->next->next = new ListNode(4);

	sa.addTwoNumbers(p1, p2);
	system("pause");
	return 0;
}
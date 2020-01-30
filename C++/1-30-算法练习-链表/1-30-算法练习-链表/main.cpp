#include<iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (!pHead)
			return pHead;
		ListNode *ptr = pHead;
		int min = pHead->val - 1;
		while (ptr->next) {
			if (ptr->val == ptr->next->val) {
				ptr->next = ptr->next->next;
				ptr->val = min;
			}
			else
				ptr = ptr->next;
		}
		ListNode *ret = new ListNode(0);
		ret->next = pHead;
		ptr = ret;
		while (ptr->next) {
			if (ptr->next->val == min)
				ptr->next = ptr->next->next;
			else
				ptr = ptr->next;
		}
		return ret->next;
	}
};

int main() {
	ListNode* ptr = new ListNode(1);
	ListNode *p = ptr;
	for (int i = 0; i < 10; ++i) {
		p->next = new ListNode(1);
		p = p->next;
	}
	Solution sa;
	sa.deleteDuplication(ptr);
	system("pause");
	return 0;
}
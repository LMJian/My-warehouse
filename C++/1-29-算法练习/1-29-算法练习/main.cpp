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
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if (!pHead)
			return nullptr;
		ListNode* one = pHead;
		ListNode* two = pHead;
		do {
			one = one->next;
			two = two->next;
			if (!one || !two)
				return nullptr;
			two = two->next;
			if (!two)
				return nullptr;
		} while (one != two);
		two = pHead;
		while (one != two) {
			one = one->next;
			two = two->next;
		}
		return one;
	}
};
int main() {
	Solution sa;
	ListNode* ptr = new ListNode(1);
	ListNode* p = ptr;
	for (int i = 2; i <= 10; ++i) {
		p->next = new ListNode(i);
		p = p->next;
	}
	p->next = ptr->next->next->next;
	cout << sa.EntryNodeOfLoop(ptr)->val << endl;
	system("pause");
	return 0;
}
#include<iostream>
#include<vector>
#include<list>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() == 0 || vin.size() == 0)
			return nullptr;
		int count = 0;
		auto vit = vin.begin();
		auto pit = pre.begin();
		while (vit != vin.end()) {
			if (*pit == *vit)
				break;
			++vit;
			++count;
		}
		TreeNode* ptr = new TreeNode(*pit);
		if (*vit != *(vin.begin()))
		{
			ptr->left = reConstructBinaryTree(vector<int>(pre.begin() + 1, pre.begin() + count + 1), vector<int>(vin.begin(), vit));
		}
		if (*vit != *(vin.end() - 1))
		{
			ptr->right = reConstructBinaryTree(vector<int>(pre.begin() + count + 1, pre.end()), vector<int>(vit + 1, vin.end()));
		}
		return ptr;
	}
};
int main() {
	vector<int> pre{ 1,2,4,7,3,5,6,8 };
	vector<int> vin{ 4,7,2,1,5,3,8,6 };
	Solution sa;
	sa.reConstructBinaryTree(pre, vin);
	system("pause");
	return 0;
}
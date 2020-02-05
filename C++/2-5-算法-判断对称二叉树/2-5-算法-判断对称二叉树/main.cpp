#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		vector<int> arr;
		stack<TreeNode*> sa;
		while (!sa.empty() || pRoot) {
			while (pRoot) {
				sa.push(pRoot);
				pRoot = pRoot->left;
			}
			if (!sa.top()->left&&sa.top()->right)
				arr.push_back(-1);
			arr.push_back(sa.top()->val);
			if (sa.top()->left && !sa.top()->right)
				arr.push_back(-1);
			pRoot = sa.top()->right;
			sa.pop();
		}
		for (int i = 0; i < arr.size() / 2; ++i) {
			if (arr[i] != arr[arr.size() - 1 - i])
				return false;
		}
		return true;
	}
};

int main() {
	TreeNode *ptr = new TreeNode(5);
	ptr->left = new TreeNode(5);
	ptr->right = new TreeNode(5);
	ptr->left->left = new TreeNode(5);
	ptr->left->left->left = new TreeNode(5);
	ptr->right->right = new TreeNode(5);
	ptr->right->right->left = new TreeNode(5);
	Solution sa;
	sa.isSymmetrical(ptr);

	system("pause");
	return 0;
}
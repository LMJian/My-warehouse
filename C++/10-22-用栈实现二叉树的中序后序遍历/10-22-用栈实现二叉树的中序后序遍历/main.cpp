#include<iostream>
using namespace std;
#include<vector>
#include<stack>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> arr;
		stack<TreeNode*> sa;
		while (!sa.empty() || root != NULL)
		{
			while (root)
			{
				sa.push(root);
				root = root->left;
			}
			root = sa.top();
			sa.pop();
			arr.push_back(root->val);
			root = root->right;
		}
		return arr;
	}
};*/


int main()
{
	TreeNode *ptr = new TreeNode(3);
	ptr->left = new TreeNode(5);
	ptr->right = new TreeNode(1);
	TreeNode *p1 = ptr->left;
	p1->left = new TreeNode(6);
	p1->right = new TreeNode(2);
	TreeNode *p2 = p1->right;
	p2->left = new TreeNode(7);
	p2->right = new TreeNode(4);
	//Solution so;
	//TreeNode *pp=so.lowestCommonAncestor(ptr, p1, p2->right);



	system("pause");
	return 0;
}
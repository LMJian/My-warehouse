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
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> arr;
		stack<TreeNode*> sa;
		if (!root)
			return arr;
		arr.push_back(root->val);
		sa.push(root);
		root = root->left;
		while (root || !sa.empty())
		{
			while (root)
			{
				arr.push_back(root->val);
				sa.push(root);
				root = root->left;
			}
			do
			{
				if (sa.empty())
					break;
				root = sa.top();
				sa.pop();
			} while (!(root->right));
			root = root->right;
		}
		return arr;
	}
};

int main()
{
	TreeNode *node=new TreeNode(1);
	node->right = new TreeNode(2);
	TreeNode *ptr = node;
	ptr = ptr->right;
	ptr->left = new TreeNode(3);
	Solution so;
	vector<int> arr=so.preorderTraversal(node);

	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	system("pause");
	return 0;
}
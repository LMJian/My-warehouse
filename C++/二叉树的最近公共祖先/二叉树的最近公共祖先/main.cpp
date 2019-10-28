#include<iostream>
#include<vector>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
	void count(TreeNode* root, TreeNode* ptr, vector<TreeNode*>& vv)
	{
		static int log = 1;
		if (vv.empty())
			log = 1;
		vv.push_back(root);
		if (root == ptr)
		{
			log = 0;
			return;
		}
		if (root->left)
		{
			count(root->left, ptr, vv);
			if (log)
				vv.pop_back();
		}
		if (log&&root->right)
		{
			count(root->right, ptr, vv);
			if (log)
				vv.pop_back();
		}
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*> arr1;
		count(root, p, arr1);
		vector<TreeNode*> arr2;
		count(root, q, arr2);
		int size = arr1.size() < arr2.size() ? arr1.size() : arr2.size();
		for (int i = 0; i < size; i++)
		{
			if (arr1[i] != arr2[i])
			{
				return arr1[i - 1];
				break;
			}
		}
		return arr1[size - 1];
	}
};

int main()
{
	vector<vector<int>> arr;

	arr.resize(1);
	arr[0].push_back(1);
	cout << endl;


}
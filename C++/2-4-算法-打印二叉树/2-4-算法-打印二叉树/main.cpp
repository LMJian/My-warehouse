#include<iostream>
#include<vector>
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
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int>> ret;
		if (!pRoot)
			return ret;
		vector<vector<TreeNode*>> arr;
		vector<TreeNode*> a;
		vector<TreeNode*> b;
		a.push_back(pRoot);
		while (!a.empty()) {
			arr.push_back(a);
			for (size_t i = 0; i < a.size(); ++i) {
				if (a[i]->left)
					b.push_back(a[i]->left);
				if (a[i]->right)
					b.push_back(a[i]->right);
			}
			a = b;
			b.clear();
		}
		for (size_t i = 0; i < arr.size(); ++i) {
			vector<int> tmp;
			if (i % 2 == 0) {
				for (size_t j = 0; j < arr[i].size(); ++j)
					tmp.push_back(arr[i][j]->val);
			}
			else {
				for (int j = arr[i].size() - 1; j >= 0; --j)
					tmp.push_back(arr[i][j]->val);
			}
			ret.push_back(tmp);
		}
		return ret;
	}
};

int main() {
	Solution sa;
	TreeNode *ptr = new TreeNode(0);
	ptr->left = new TreeNode(1);
	ptr->right = new TreeNode(2);
	ptr->left->left = new TreeNode(3);
	ptr->left->right = new TreeNode(4);
	ptr->right->left = new TreeNode(5);
	ptr->right->right = new TreeNode(6);
	sa.Print(ptr);
	system("pause");
	return 0;

}
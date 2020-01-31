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
		vector<TreeNode*> a;
		vector<TreeNode*> b;
		a.push_back(pRoot);
		while (!a.empty()) {
			vector<int> arr;
			for (size_t i = 0; i < a.size(); ++i) {
				arr.push_back(a[i]->val);
				if (a[i]->left)
					b.push_back(a[i]->left);
				if (a[i]->right)
					b.push_back(a[i]->right);
			}
			ret.push_back(arr);
			a = b;
			b.clear();
		}
		return ret;
	}
};

int main() {
	TreeNode* ptr = new TreeNode(0);
	ptr->left = new TreeNode(1);
	ptr->right = new TreeNode(2);
	ptr->left->left = new TreeNode(3);
	ptr->left->right = new TreeNode(4);
	Solution sa;
	vector<vector<int>> arr=sa.Print(ptr);
	for (size_t i = 0; i < arr.size(); ++i) {
		for (size_t j = 0; j < arr[i].size(); ++j) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
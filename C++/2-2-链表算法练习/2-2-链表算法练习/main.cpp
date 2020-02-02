#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
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
	char* Serialize(TreeNode *root) {
		string str = "";
		stack<TreeNode*> sa;
		while (!sa.empty() || root) {
			while (root) {
				sa.push(root);
				char ch[20] = { 0 };
				sprintf(ch, "%d!", root->val);
				str = str + ch;
				root = root->left;
			}
			str = str + "#!";
			root = sa.top()->right;
			sa.pop();
		}
		str = str + "#!";
		int len = strlen(str.c_str());
		char *ptr = (char*)malloc((len + 1) * sizeof(char));
		strcpy(ptr, str.c_str());
		return ptr;
	}
	TreeNode* Deserialize(char *str) {
		buff = str;
		TreeNode *ret = nullptr;
		CreateBiTree(&ret);
		return ret;
	}
private:
	char *buff = nullptr;
	void CreateBiTree(TreeNode **bt)
	{
		if (*buff == '#') {
			*bt = nullptr;
			buff += 2;
		}
		else
		{
			char* tmp = buff;
			while (*tmp != '!')
				++tmp;
			*tmp = '\0';
			int num = atoi(buff);
			buff = tmp + 1;
			*bt = new TreeNode(num);
			CreateBiTree(&((*bt)->left));
			CreateBiTree(&((*bt)->right));
		}
	}
};

int main() {
	TreeNode *ptr = new TreeNode(8);
	ptr->left = new TreeNode(6);
	ptr->right = new TreeNode(10);
	ptr->left->left = new TreeNode(5);
	ptr->left->right = new TreeNode(7);
	ptr->right->left = new TreeNode(9);
	ptr->right->right = new TreeNode(11);
	Solution sa;
	char * ret = sa.Serialize(ptr);
	TreeNode *p = sa.Deserialize(ret);

	system("pause");
	return 0;
}
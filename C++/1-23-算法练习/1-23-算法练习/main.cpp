#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

/*class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<string> sa;
		for (int i = 0; i < tokens.size(); ++i) {
			if (tokens[i] != "+"&&tokens[i] != "-"&&tokens[i] != "*"&&tokens[i] != "/") {
				sa.push(tokens[i]);
			}
			else {
				int right = atoi(sa.top().c_str());
				sa.pop();
				int left = atoi(sa.top().c_str());
				sa.pop();
				if (tokens[i] == "+") {
					int num = left + right;
					Push(num, sa);
				}
				else if (tokens[i] == "-") {
					int num = left - right;
					Push(num, sa);
				}
				else if (tokens[i] == "*") {
					int num = left * right;
					Push(num, sa);
				}
				else {
					int num = left / right;
					Push(num, sa);
				}
			}
		}
		string ret = sa.top();
		return atoi(ret.c_str());
	}
private:
	void Push(int num, stack<string>& sa) {
		int head = num;
		if (num < 0)
			num = -num;
		string str = "";
		string tmp = "0";
		while (num) {
			tmp[0] = '0' + (num % 10);
			str = tmp + str;
			num /= 10;
		}
		if (head < 0)
			str = "-" + str;
		sa.push(str);
	}
};*/
/**
 * Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<vector<TreeNode*>> arr;
		vector<TreeNode*> a;
		a.push_back(root);
		while (!a.empty()) {
			arr.push_back(a);
			vector<TreeNode*> b;
			for (int i = 0; i < a.size(); ++i) {
				if (a[i]->left)
					b.push_back(a[i]->left);
				if (a[i]->right)
					b.push_back(a[i]->right);
			}
			a = b;
		}
		vector<int> ret;
		for (int i = 0; i < arr.size(); ++i) {
			int index = arr[i].size() - 1;
			ret.push_back(arr[i][index]->val);
		}
		return ret;
	}
};*/

class Solution {
public:
	bool isMatch(string s, string p) {
		const char* ch1 = s.c_str();
		const char* ch2 = p.c_str();
		return Find(ch1, ch2);
	}
private:
	bool Find(const char* a, const char* b) {
		while (*a != '\0'&&*b != '\0'&&*a == *b) {
			++a;
			++b;
		}
		if (*a == '\0'&&*b == '\0')
			return true;
		if (*b == '?') {
			if (*a != '\0')
				return Find(a + 1, b + 1);
			else
				return false;
		}
		else if (*b == '*') {
			int n = 0;
			if (*a != '\0')
				n = Find(a + 1, b) || Find(a + 1, b + 1);
			if (n)
				return true;
			return Find(a, b + 1);
		}
		else
			return false;
	}
};


int main() {
	/*Solution sa;
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(5);
	root->right->right = new TreeNode(4);
	sa.rightSideView(root);*/
	/*string str = "123";
	const char *ch = str.c_str();
	for (int i = 0; i < 4; ++i)
		printf("%d ", *ch++);*/
	Solution sa;
	cout << sa.isMatch("adceb", "*a*b") << endl;
	system("pause");
}
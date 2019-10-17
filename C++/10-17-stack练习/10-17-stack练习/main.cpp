#include<iostream>
using namespace std;
#include<stack>
#include<vector>
#include<string>

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		int ret;
		if (sa.empty())
		{
			sa.push(x);
			sa.push(x);
		}
		else
		{
			ret = sa.top();
			sa.push(x);
			if (ret < x)
				sa.push(ret);
			else
				sa.push(x);
		}	
	}

	void pop() {
		if (!sa.empty())
		{
			sa.pop();
			sa.pop();
		}
	}

	int top() {
		if (!sa.empty())
		{
			int tmp = sa.top();
			sa.pop();
			int ret = sa.top();
			sa.push(tmp);
			return ret;
		}
	}
	int getMin() {
		//if (!sa.empty())
			return sa.top();
	}
private:
	stack<int> sa;
};


class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		size_t index = 1;
		size_t outdex = 0;
		stack<int> sa;
		sa.push(pushV[0]);
		while (!sa.empty())
		{
			if (sa.top() == popV[outdex])
			{
				sa.pop();
				outdex++;
				if (sa.empty() && index < pushV.size())
				{
					sa.push(pushV[index++]);
				}
			}
			else {
				if (index == pushV.size())
					return false;
				sa.push(pushV[index++]);
			}
		}
		return true;
	}
};


class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int>sa;
		for (size_t i = 0; i < tokens.size(); i++)
		{
			string str = tokens[i];
			if (str == "+" || str == "-" || str == "*" || str == "/")
			{
				int right = sa.top();
				sa.pop();
				int left = sa.top();
				sa.pop();
				char ch = str[0];
				switch (ch)
				{
				case '+':sa.push(left + right);
					break;
				case '-':sa.push(left - right);
					break;
				case '*':sa.push(left*right);
					break;
				case '/':sa.push(left / right);
					break;
				}
			}
			else
			{
				const char *tmp = str.c_str();
				int num = atoi(tmp);
				sa.push(num);
			}
		}
		return sa.top();
	}
};

int main()
{
	
	/*MinStack ma;
	cout << ma.getMin() << endl;
	/*ma.push(-2);
	ma.push(0);
	ma.push(3);
	cout<<ma.getMin()<<endl;
	ma.pop();
	cout<<ma.top()<<endl;
	cout<<ma.getMin() << endl;
	ma.pop();
	ma.pop();
	ma.pop();*/
	system("pause");
	return 0;
}
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
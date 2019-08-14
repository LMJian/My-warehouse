#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<functional>
using namespace std;

/*class MinStack
{
public:
	void push(int x)
	{
		_elem.push(x);

		if (_min.empty() || x <= _min.top())
			_min.push(x);
	}
	void pop()
	{
		if (_min.top() == _elem.top())
			_min.pop();

		_elem.pop();
	}
	int top()
	{
		return _elem.top();
	}
	int getMin()
	{
		return _min.top();
	}
private:
	std::stack<int>_elem;
	std::stack<int>_min;
};

bool IsPopOrder(vector<int>pushV, vector<int>popV)
{
	if (pushV.size() != popV.size())
		return false;

	int outIdx = 0;
	int inIdx = 0;
	stack<int>s;
	while (outIdx < popV.size())
	{
		while (s.empty() || s.top() != popV[outIdx])
		{
			if (inIdx < pushV.size())
				s.push(pushV[inIdx++]);
			else
				return false;
		}
		s.pop();
		outIdx++;
	}
	return true;
}
int evalRPN(vector<string>& tokens)
{
	stack<int>s;
	for (size_t i = 0; i < tokens.size(); ++i)
	{
		string& str = tokens[i];
		if (!("+" == str || "-" == str || "*" == str || "/" == str))
			s.push(atoi(str.c_str()));
		else
		{
			int right = s.top();
			s.pop();
			int left = s.top();
			s.pop();
			switch (str[0])
			{
			case'+':
				s.push(left + right);
				break;
			case'-':
				s.push(left - right);
				break;
			case'*':
				s.push(left*right);
				break;
			case'/':
				s.push(left / right);
				break;
			}
		}
	}
	return s.top();
}
void TestPriorityQueue()
{
	vector<int>v{ 3, 2, 7, 6, 0, 4, 1, 9, 8, 5 };
	priority_queue<int>q1;
	for (auto&e : v)
		q1.push(e);
	cout << q1.top() << endl;

	priority_queue<int, vector<int>, greater<int>>q2(v.begin(), v.end());
	cout << q2.top() << endl;
}
class Date
{
public:
	Date(int year=1900,int month=1,int day=1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	bool operator<(const Date& d)const
	{
		return (_year < d._year) ||
			(_year == d._year&&_month < d._month) ||
			(_year == d._year&&_month == d._month&&_day < d._day);
	}
	bool operator>(const Date& d)const
	{
		return (_year>d._year) ||
			(_year == d._year&&_month>d._month) ||
			(_year == d._year&&_month == d._month&&_day > d._day);
	}
	friend ostream& operator<<(ostream& _cout, const Date& d)
	{
		_cout << d._year << "-" << d._month << "-" << d._day;
		return _cout;
	}
private:
	int _year;
	int _month;
	int _day;
};
/*void TestPriorityQueue()
{
	priority_queue<Date>q1;
	q1.push(Date(2018, 10, 29));
	q1.push(Date(2018, 10, 28));
	q1.push(Date(2018, 10, 30));
	cout << q1.top() << endl;

	priority_queue<Date, vector<Date>, greater<Date>>q2;
	q2.push(Date(2018, 10, 29));
	q2.push(Date(2018, 10, 28));
	q2.push(Date(2018, 10, 30));
	cout << q2.top() << endl;
}
class Less
{
public:
	bool operator()(const Date*pLeft, const Date*pRight)
	{
		return *pLeft < *pRight;
	}
};
void TestPriorityQueue()
{
	priority_queue<Date*, vector<Date*>, Less>q;
	q.push(&Date(2018, 10, 29));
	q.push(&Date(2018, 10, 28));
	q.push(&Date(2018, 10, 30));
	cout << *q.top() << endl;
}
class Solution{
public:
	int findKthLargest(vector<int>&nums, int k){
		priority_queue<int>p(nums.begin(), nums.end());
		for (int i = 0; i < k - 1; i++)
		{
			p.pop();
		}
		return p.top();
	}
};*/
template<class T, class Con=deque<T>>
class stack
{
public:
	stack(){}
	void push(const T& x)
	{
		_c.push_back(x);
	}
	void pop()
	{
		_c.pop_back();
	}
	T&top()
	{
		return _c.back();
	}
	const T&top()const
	{
		return _c.back();
	}
	size_t size()const
	{
		return _c.size();
	}
	bool empty()const
	{
		return _c.empty();
	}
private:
	Con _c;
};
int main()
{
	std::stack<int>s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout << s.size() << endl;
	cout << s.top() << endl;

	s.pop();
	s.pop();
	cout << s.size() << endl;
	cout << s.top() << endl;
	/*vector<int>nums{ 9, 5, 1, 7, 5, 3, 2, 8, 4, 6 };
	Solution s;
	cout << s.findKthLargest(nums, 4) << endl;
	//TestPriorityQueue();
	//TestPriorityQueue();
	/*vector<int>s1{ 1, 5, 9, 7, 5, 3 };
	vector<int>s2{ 3, 5, 7, 9, 5, 1 };
	IsPopOrder(s1, s2);*/

	system("pause");
	return 0;
}
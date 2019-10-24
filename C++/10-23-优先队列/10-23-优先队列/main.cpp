#include<iostream>
#include<vector>
#include<queue>
//#include<functional>
using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1,int day=1)
		:_year(year)
		,_month(month)
		,_day(day)
	{}
	bool operator<(const Date& d)const
	{
		return (_year < d._year) ||
			(_year == d._year&&_month < d._month) ||
			(_year == d._year&&_month == d._month&&_day < d._day);
	}
	bool operator>(const Date& d)const
	{
		return (_year > d._year) ||
			(_year == d._year&&_month > d._month) ||
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
template<class T>
class Sess
{
public:
	bool operator()(const T pLeft, const T pRight)
	{
		return *pLeft < *pRight;
	}
};


/*template<class T, class Sequence = vector<T>, class Compare = less<T>>
class priority_queue
{
public:
	priority_queue()
		:_seq()
	{}
	template<class InputIt>
	priority_queue(InputIt start, InputIt last)
		: _seq(start, last)
	{
		int parent = (_seq.size() - 2) >> 1;
		while (parent >= 0)
		{
			makeDown(parent);
			parent--;
		}
	}
	void push(const T& x)
	{
		_seq.push_back(x);
		makeUp(_seq.size() - 1);
	}
	void pop()
	{
		if (empty())
			return;
		//swap(_seq.begin(), _seq.end() - 1);
		swap(_seq.front(), _seq.back());
		_seq.pop_back();
		makeDown(0);
	}
	bool empty()const
	{
		return _seq.empty();
	}
	const T& top()const
	{
		return _seq.front();
	}
	size_t size()const
	{
		return _seq.size();
	}
private:
	void makeUp(int child)
	{
		int parent = (child - 1) >> 1;
		while (child)
		{
			if (_com(_seq[parent], _seq[child]))
			{
				swap(_seq[parent], _seq[child]);
				child = parent;
				parent = (child - 1) >> 1;
			}
			else
				return;
		}
	}
	void makeDown(int parent)
	{
		int child = parent * 2 + 1;
		while (child < _seq.size())
		{
			if (child + 1 < _seq.size() && _com(_seq[child], _seq[child + 1]))
				++child;
			if (_com(_seq[parent], _seq[child]))
			{
				swap(_seq[parent], _seq[child]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
				break;
		}
	}
	Sequence _seq;
	Compare _com;
};*/

void TestPriorityQueue()
{
	priority_queue<Date*,vector<Date*>,Sess<Date*>> q;
	q.push(&Date(2019, 10, 23));
	q.push(&Date(2019, 10, 24));
	q.push(&Date(2019, 10, 25));
	cout << *q.top() << endl;


	/*priority_queue<Date> q1;
	q1.push(Date(2019, 10, 23));
	q1.push(Date(2019, 10, 24));
	q1.push(Date(2019, 10, 25));
	cout << q1.top() << endl;

	priority_queue<Date, vector<Date>, greater<Date>> q2;
	q2.push(Date(2019, 10, 23));
	q2.push(Date(2019, 10, 24));
	q2.push(Date(2019, 10, 25));

	cout << q2.top() << endl;*/
	/*vector<int> v{ 3,2,7,6,0,4,1,9,8,5 };
	/*priority_queue<int> q1;
	for (auto& e : v)
		q1.push(e);
	cout << q1.top() << endl;
	priority_queue<int, vector<int>, greater<int>> q2(v.begin(), v.end());
	cout << q2.top() << endl;*/
}

int main()
{
	TestPriorityQueue();
	system("pause");
	return 0;
}
#include<iostream>
#include<vector>
#include<queue>
#include<functional>
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

class Less
{
public:
	bool operator()(const Date* pLeft, const Date* pRight)
	{
		return *pLeft < *pRight;
	}
};
void TestPriorityQueue()
{
	priority_queue<Date*, vector<Date*>, Less>q;
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

	cout << q2.top() << endl;
	/*vector<int> v{ 3,2,7,6,0,4,1,9,8,5 };
	priority_queue<int> q1;
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
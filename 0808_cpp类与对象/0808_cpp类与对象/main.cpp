#include<iostream>
using namespace std;
/*class Date
{
public:
	Date(int year,int month,int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
};
class A
{
public:
	A(int a)
		:_a(a)
	{}
private:
	int _a;
};

class B
{
public:
	B(int a,int ref)
		:_aobj(a)
		, _ref(ref)
		, _n(10)
	{}
private:
	A _aobj;
	int& _ref;
	const int _n;
};
class Date;
class Time
{
	friend class Date;
public:
	Time(){}
	Time(int hour, int minute, int second)
		:_hour(hour)
		, _minute(minute)
		, _second(second)
	{}
private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	void SetTimeOfDate(int hour, int minute, int second)
	{
		_t._hour = hour;
		_t._minute = minute;
		_t._second = second;

	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;
};
class Array
{
public:
	Array(int size)
		:_size(size)
		, _array((int*)malloc(sizeof(int)*_size))
	{}
private:
	int* _array;
	int _size;
};
/*class Date
{
public:
	/*Date(int year)
		:_year(year)
	{}
	explicit Date(int year)
		:_year(year)
	{}
private:
	int _year;
	int _month;
	int _day;
};
void TestDate()
{
	Date d1(2008);
	d1 = 2019;

}

class A
{
public:
	A()
	{
		++_scount;
	}
	A(const A& t)
	{
		++_scount;
	}
	static int GetACount()
	{
		return _scount;
	}
private:
	static int _scount;
};

int A::_scount = 0;
void TestA()
{
	cout << A::GetACount() << endl;
	A a1, a2;
	A a3(a1);
	cout << A::GetACount() << endl;
}
class B
{
public:
	B(int b = 0)
		:_b(b)
	{}
	int _b;
};
class A
{
public:
	void Print()
	{
		cout << a << endl;
		cout << b._b << endl;
		cout << p << endl;
	}
private:
	int a = 10;
	B b = 20;
	int* p = (int*)malloc(4);
	static int n;
};
int A::n = 10;
class Date
{
	friend ostream& operator<<(ostream& _cout, const Date& d);
	friend istream& operator>>(istream& _cin, const Date& d);
public:
	Date(int year,int month,int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	/*ostream& operator<<(ostream& _cout)
	{
		_cout << _year << "-" << _month << "-" << _day;
		return _cout;
	}
private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}
istream& operator>>(istream& _cin, const Date& d)
{
	cin >> d._year;
	_cin >> d._month;
	_cin >> d._day;
	return _cin;
}*/
class A
{
private:
	static int k;
	int h;
public:
	class B
	{
	public:
		void foo(const A&a)
		{
			cout << k << endl;
			cout << a.h << endl;
		}
	};
};
int A::k = 1;
int main()
{
	A::B b;
	b.foo(A());
	/*Date d;
	cin >> d;
	cout << d << endl;
	//d<<cout;

	//A a;
	//a.Print();
	//TestA();
	//TestDate();
	//Date d(1);
	//Date test(1, 2, 3);*/
	system("pause");
	return 0;
}
#include<iostream>
using namespace std;

/*class Date
{
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	friend ostream& operator<<(ostream& _cout, const Date& d);
	/*ostream& operator<<(ostream& _cout)
	{
		_cout << d._year << "-" << d._month << "-" << d._day;
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
class Base
{
	int x;
public:
	Base(int b) : x(b) {}
	virtual void display()
	{
		cout << x;
	};
};
class Derived : public Base
{
	int y;
public:
	Derived(int d) : Base(d), y(d+1) {} void display()
	{
		cout << y;
	}
};*/

int main()
{
#define N 2017  int arr[N];
	cout << sizeof(arr) << endl;

	/*info = { 'name':'°à³¤', 'id' : 100, 'sex' : 'f', 'address' : '±±¾©' }
		age = info.get('age')
		print(age)
		age = info.get('age', 18)
		print(age)
	/*Base b(1);
	Derived d(2);
	Base *p = &d;
	b.display();
	d.display();
	p->display();

	struct T {
		char a;
		int *d;
		int b;
		int c : 16;
		double e;
	};
	T *p;
	cout << sizeof(p) << endl;
	cout << sizeof(*p) << endl;

	/*struct T{
		int aa;
		int c : 16;
	}a;
	a.aa = 12;
	a.c = 14;
	cout << (a.c) << endl;
	//char a[] = { "ABNV" };
	/*Date d(2017, 12, 24);
	cout << d << endl;
	/*cout << ((12) % (-5)) << endl;
	/*int a, b;
	cout << (a = 2, b = 3, b++, a + b) << endl;*/

	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<math.h>
//#include<queue>
//#include<cstdio>
//#include<vector>
using namespace std;

/*class A
{
public:
	//friend void print(A& pt);
	/*{
		cout << pt.a < "  " << pt.b << endl;
	}
	ostream& operator<<(ostream& _cout)
	{
		_cout << a << "  " << b << endl;
		return _cout;
	}
//private:
	int a = 1;
	double b = 2.3;
};
/*friend void print(A& pt)
{
	cout << pt.a < "  " << pt.b << endl;
}*/
/*class Date
{
	friend void test()
	{
		cout << _year << endl;
	}
public:
	Date(){}
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
};
class Time
{
public:
	istream& operator>>(istream& _cin, Date& d)
	{
		_cin >> d._year;
		_cin >> d._month;
		_cin >> d._day;
		return _cin;
	}
private:
	int hour;
	int minute;
	int second;
};

istream& operator>>(istream& _cin,   Date& d)
{
	_cin >> d._year;
	_cin >> d._month;
	_cin >> d._day;
	return _cin;
}
void func(const int& v1, const int& v2)
{
	cout << v1 << ' ';
	cout << v2 << ' ';
}

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}
struct stsort{
	bool operator()(const int a, const int b)const{
		if (gcd(30, a) < gcd(30, b)){
			return 1;
		}
		else if (gcd(30, a) == gcd(30, b))
		{
			return a < b;
		}
		else
			return 0;
	}
};
class A
{
public:
	int a = 123;
	static int n;
};
class B :public A
{
public:
	int b = 321;
	/*void test()
	{
		cout << n << endl;
	}
};
int A::n = 1;*/

double sqrt(double num)
{
	return 100.23;
}
int main()
{
	double nu = 1230.2;
	cout << sqrt(nu) << endl;
	/*B::n++;
	A a;
	B b;
	cout << a.a << " " << a.n << endl;
	cout << b.a << " " << b.b << " " << b.n << endl;

	//a.n = 1;
	//B b;
	//b.n = 2;
	//cout << a.a << " " << a.n << " " << b.a << " " << b.b << " " << b.n << endl;
	/*A::n = 1;
	//B::n = 2; 
	cout << A::n; //<< "  " << B::n << endl;
	/*cout << "welcome to sogou" << endl;
	/*int n = 5;
	typedef n uInt;

	priority_queue<int, vector<int>, stsort>q;
	for (int i = 1; i <= n; ++i){
		q.push(i);
	}
	for (int i = 1; i <= n; ++i){
		printf("%d", q.top());
		q.pop();
	}
	/*int i = 0;
	func(++i, i++);
	i = 0;
	func(i++,i);
	/*signed char a = 0Xe0;
	unsigned int b = a;
	unsigned char c = a;

	/* d;
	cin >> d;
	cout << d << endl;
	/*A a, b;
	a.operator<<(cout);
	a << cout;
	/*b.a = -9;
	b.b = 15.156;
	a.operator<<(b);*/

	system("pause");
	return 0;
}
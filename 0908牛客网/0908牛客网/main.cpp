#include<iostream>
using namespace std;

/*class A
{
public:
	A()
	{
		cout << "A" << endl;
	}
};
class B :virtual public A
{
public:
	B()
	{
		cout << "B" << endl;
	}
};
class C :virtual public A
{
public:
	C()
	{
		cout << "C" << endl;
	}
};
class D :public C, public B
{
public:
	D()
	{
		cout << "D" << endl;
	}
};*/
/*class A
{
public:
	A(char *s)
	{
		cout << s << endl;
	}
	~A()
	{}
};
class B:virtual public A
{
public:
	B(char *s1, char *s2)
		:A(s1)
	{
		cout << s2 << endl;
	}
};
class C :virtual public A
{
public:
	C(char *s1, char *s2)
		:A(s1)
	{
		cout << s2 << endl;
	}
};
class D :public C, public B
{
public:
	D(char *s1, char *s2, char *s3, char *s4)
		:B(s1, s2)
		, C(s1, s3)
		,A(s1)
	{
		cout << s4 << endl;
	}
};*/
/*class A
{
public:
	virtual void print()
	{
		cout << "A" << endl;
	}
};
class B :public A
{
public:
	/*virtual void print()
	{
		cout << "b  "<< endl;
	}

	virtual void print(int x)
	{
		cout << x << endl;
	}
};
class Z
{
	static int a;
public:
	static void fStatic(Z&);
};
int Z::a = 0;
Z objz;
void Z::fStatic(Z& objz)
{
	objz.a = 1;
	a = 1;
	Z::a = 1;
}*/
/*struct A{
	A(){}
	~A(){}
	int m1=-1;
	int m2=-2;
};
struct B :A{
	B(){}
	~B(){}
	int m1=1;
	char m2=65;
	static char m3;
};
struct C{
	C(){}
	virtual ~C(){}
	int m1;
	short m2;
};*/
class A
{
	inline A()
	{}
};
int main()
{
	double a = 15.6562;
	a = a & 1;
	/*B b;
	//B::m3++;
	
	cout << b.A::m1 << endl;
	cout << b.A::m2 << endl;
	//cout << b.m3 << endl;
	/*cout << sizeof(struct A) << endl;
	cout << sizeof(struct B) << endl;
	cout << sizeof(struct C) << endl;
	/*B b;
	b.print();
	//new D("1", "2", "3", "4");
	//delete p;*/


	system("pause");
	return 0;
}
#include<iostream>
using namespace std;


/*void Test()
{
	int i = 1;
	double d = i;
	printf("%d,%.2f\n", i, d);

	int *p = &i;
	int address = (int)p;
	printf("%x,%d\n", p, address);
}
typedef void(*FUNC)();
int DoSomething(int i)
{
	cout << "DoSomething" << endl;
	return 0;
}
void Test()
{
	FUNC f =reinterpret_cast<FUNC>(DoSomething);
	f();
}
void Test()
{
	const int a = 2;
	int* p = const_cast<int*>(&a);
	*p = 3;
	cout << a << endl;
}*/
/*class A
{
public:
	virtual void f(){
		cout << "A" << endl;
	}
};
class B :public A
{
public:
	virtual void f(){
		cout << "B" << endl;
	}
};
void fun(A* pa)
{
	B* pb1 = static_cast<B*>(pa);
	B* pb2 = dynamic_cast<B*>(pa);

	cout << "pb1:" << pb1 << endl;
	cout << "pb2:" << pb2 << endl;
}
class A
{
public:
	explicit A(int a)
	{
		cout << "A(int a)" << endl;
	}
	A& operator=(const A& a)
	{
		_a = a._a;
	}
	A(const A& a)
	{
		cout << "A(const A& a)" << endl;
	}
private:
	int _a;
};*/
class A
{
public:
	void test()
	{
		cout << "A1" << endl;
	}
	void test1()
	{
		cout << "A2" << endl;
	}
};
class B :public A
{
public:
	void test()
	{
		cout << "B1" << endl;
	}
	void test2()
	{
		cout << "B2" << endl;
	}
};
int main()
{
	B* pa = static_cast<B*>(new A());
	//A* pa = new B();
	pa->test1();
	/*A a1(1);

	A a2 = 1;
	/*B* pb1 = static_cast<B*>(new A());
	B* pb2 = dynamic_cast<B*>(new A());

	pb1->f();
	pb2->f();
	/*A a;
	B b;
	fun(&a);
	fun(&b);
	//Test();
	/*double d = 12.34;
	int a = static_cast<int>(d);
	cout << a << endl;
	/*Test();*/

	system("pause");
	return 0;
}
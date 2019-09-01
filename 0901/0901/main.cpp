#include<iostream>
using namespace std;

/*class A
{
public:
	A(){}
	static void print()
	{
		cout << "A" << endl;
	}
	virtual void foo()
	{
		cout << "A" << endl;
	}
};
class B : public A
{
public:
	B(){}
	/*static void print()
	{
		cout << "B" << endl;
	}
	void foo()
	{
		cout << "B" << endl;
	}
};*/
class A
{
public:
	A()
		:num(10)
	{
		printf("A");
	}
	/*A(int a)
		:num(a)
	{
		printf("1");
	}
	A& operator=(const A& a)
	{
		//printf("%d\n", a.num);
		printf("2");
		return *this;
	}*/
	int num;
};
class B :public A
{
public:
	B()
		:num(12)
	{
		printf("B");
	}
	int num;
};
void print(int a, char b = 'b', int c = 1)
{
	printf("%d %d %d\n", a, b, c);
}
int main()
{
	//print(5, '#');
	float a = 0XFF800000;
	printf("%f\n", a);
	//cout << a << endl;
	/*cout << (int)a << endl;
	cout << (int&)a << endl;

	/*B bb;
	cout << bb.num << endl;
	//B *b = new B();
	/*B b;
	A *a = new B();
	//a->print();
	b.print();*/

	system("pause");
	return 0;
}
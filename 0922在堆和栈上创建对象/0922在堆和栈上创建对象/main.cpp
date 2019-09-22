#include<iostream>
using namespace std;

/*class test
{
public:
	test()
		:data(1)
	{
		cout << "test()" << endl;
	}
	~test()
	{
		cout << "~test()" << endl;
	}
	void show()
	{
		cout << data << endl;
	}
private:
	int data = 2;
	};*/
class HeapOnly
{
public:
	static HeapOnly* CreateObject()
	{
		return new HeapOnly;//这使得创建该类对象都只能通过new，确保了
		                    //该类只能在堆上创建对象
	}
	void test()
	{
		cout << "H test" << endl;
		cout << data << '\n' << *p << endl << endl;
	}
private:
	HeapOnly(){
		data = 12;
		p = new int(12);
	}//在堆和栈上创建对象都会调用构造函数
	            //为了防止在栈上创建对象我们将构造函数私有化
	HeapOnly(const HeapOnly&) = delete;//拷贝构造函数是在栈上创建对象
	int data;
	int *p;
};
class StackOnly
{
public:
	static StackOnly CreateObject()
	{
		return StackOnly();//确保了该类创建对象时不会使用new操作符
		                   //从而使得该类只能在栈上创建对象
	}
	void test()
	{
		cout << "S test" << endl;
		cout << data << '\n' << *p << endl << endl;
	}
private:
	StackOnly(){
		data = 12;
		p = new int(12);
	}//在堆和栈上创建对象都会调用构造函数，为了防止在堆上
	             //创建对象，应该将构造函数私有化
	int data;
	int *p;
};

int main()
{

	HeapOnly *p1 = HeapOnly::CreateObject();
	//HeapOnly *p2 = HeapOnly::CreateObject();
	StackOnly *p3 = &(StackOnly::CreateObject());
	//StackOnly *p4 = &(StackOnly::CreateObject());
	p1->test();
	p3->test();
	//cout << p1 << '\n' << p2 << '\n' << p3 << '\n' << p4 << '\n' << endl;

	/*int* t1 = new int;
	int* t2 = new int;
	int t3 = 0;
	int t4 = 0;
	cout << t1 << '\n' << t2 << '\n' << &t3 << '\n' << &t4 << endl;

	/*test t1;
	test t2;
	test t3(t2);
	test* t4 = new test;
	test* t5 = new test;
	cout << &t1 << '\n' << &t2 << '\n' << &t3 << '\n' << t4 << '\n' << t5 << endl;

	/*int a, b;
	int *p1, *p2;
	p1 = new int;
	p2 = new int;
	cout << &a << '\n' << &b << '\n' << p1 << "\n" << p2 << endl;
	/*test t1; test t2;
	test* t3 = new test;
	test* t4 = new test;
	cout << &t1 << '\n' << &t2 << '\n' << t3 << '\n' << t4 << endl;*/



	system("pause");
	return 0;
}
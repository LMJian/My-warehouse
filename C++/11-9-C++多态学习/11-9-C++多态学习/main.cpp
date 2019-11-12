#include<iostream>
using namespace std;

#if 0
class A {
public:
	virtual void test() = 0
	{
		cout << "A::test()" << endl;
	}
	static void print()
	{
		cout << "~A()" << endl;
	}
};
class B :public A {
public:
	void test()
	{
		cout << "B::test()" << endl;
	}
	~B()
	{
		cout << "~B()" << endl;
	}
};
class C :public B {
public:
	void test()
	{
		cout << "C::test()" << endl;
	}
	~C()
	{
		cout << "~C()" << endl;
	}
};

void Test(A* p)
{
	p->test();
	delete p;
}
#endif 

#if 0
class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};
class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};
class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};
#endif

/*class A
{
public:
	virtual void test()
	{
		cout << "A::test()" << endl;
	}
	virtual ~A()
	{
		cout << "~A" << endl;
	}
};
class B : public  A
{
public:
	virtual void test()
	{
		cout << "B::test()" << endl;
	}
};
class C : public  A
{
private:
	virtual void test()
	{
		cout << "C::test()" << endl;
	}
};
class D :public B, public C
{
private:
	virtual void test()
	{
		cout << "D::test()" << endl;
	}
	int d = 1;
};

void test(B* p)
{
	p->test();
	delete p;
}
class Car {
public:
	virtual void Drive() {}
};

class Benz :public Car {
public:
	//如果没有构成重写，编译时会报错
	virtual void Drive(int a) override { cout << "Benz-舒适" << endl; }
};*/
#if 0
class A {
public:
	virtual void Func1()
	{
		cout << "A::Func1()" << endl;
	}
};
class B :public A {
public:
	virtual void Func1()
	{
		cout << "B::Func1()" << endl;
	}
};
#endif 

#if 0
class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};

class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};
class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};
#endif 

class A {
public:
	virtual void func1() { cout << "A::func1" << endl; }
private:
	int _a = 1;
};

class B :virtual public A {
public:
	virtual void func1() { cout << "B::func1" << endl; }
	virtual void func2() { cout << "B::func2" << endl; }
private:
	int _b = 2;
};
class C :virtual public A {
public:
	virtual void func1() { cout << "C::func1" << endl; }
	virtual void func2() { cout << "C::func2" << endl; }
private:
	int _c = 3;
};
class D : public B, public C {
public:
	virtual void func1() { cout << "D::func1" << endl; }
	virtual void func3() { cout << "D::func3" << endl; }
private:
	int _d = 4;
};

typedef void(*VFPTR)();//虚函数指针
void Print(VFPTR *arr)
{
	for (int i = 0; arr[i] != nullptr; ++i)
	{
		printf("第%d个虚函数地址：%0x\n", i, arr[i]);
		arr[i]();
	}
}

int ret = 0;
int main()
{
	A a;
	const char* p = "hello world";
	printf("全局变量--->%p\n", &ret);
	printf("常量--->%p\n", p);
	printf("虚表--->%p\n", *(int*)&a);
	/*D d;

	VFPTR* vfptr1 = (VFPTR*)(*(int*)&d);//第一个虚表
	VFPTR* vfptr2 = (VFPTR*)(*(((int*)&d) + 3));//第二个虚表
	VFPTR* A_Func1 = (VFPTR*)(*(((int*)&d) + 7));//A::Func1()在对象组成后面的函数指针

	Print(vfptr1);
	Print(vfptr2);

	printf("A::Func1()地址：%0x\n", (int*)A_Func1);
	(*A_Func1)();*/



	//Derive d;
	//d.func1();
	//Test(new A);

	//A::print();

	//Test(new B);
	//Test(new C);*/


	system("pause");
	return 0;
}
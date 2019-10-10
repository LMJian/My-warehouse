#include<iostream>
#include<time.h>
using namespace std;

namespace N
{
	int a = 10;
	int b = 20;
	int Add(int left, int right)
	{
		return left + right;
	}
	int Sub(int left, int right)
	{
		return left - right;
	}
}
//使用命名空间方法一
/*int main()
{
	//printf("%d\n", a);//错误
	printf("%d\n", N::a);
	printf("%d\n", N::Add(1, 8));
	system("pause");
	return 0;
}*/
//使用命名空间方法二
/*using N::b;
int main()
{
	printf("%d\n", N::a);
	//printf("%d\n", a);//错误
	printf("%d\n", N::b);
	printf("%d\n", b);
	system("pause");
	return 0;
}*/
//使用命名空间方法三
/*using namespace N;
int main()
{
	printf("%d\n", N::a);
	printf("%d\n", b);
	printf("%d\n", Add(10, 20));
	system("pause");
	return 0;
}*/

//cpp的输入输出
/*int main()
{
	cout << "hello world!!!" << endl;
	int a;
	double b;
	char c;

	cin >> a;
	cin >> b >> c;
	cout << a << endl;
	cout << b << "\n" << c << endl;

	system("pause");
	return 0;
}*/
//缺省函数
/*void TestFunc(int a = 99)
{
	cout << a << endl;
}

//全缺省函数
void TestFunc1(int a = 10, int b = 20, int c = 30)
{
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
}
//半缺省函数
//void TestFunc2(int a, int b, int c);缺省函数在定义时不能给出参数值
void TestFunc2(int a, int b, int c = 20)
{
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
}

//函数重载
int Add(int left, int right)
{
	return left + right;
}
/*long Add(int left, int right)形参相同，返回值不同，不能重载
{
	return left + right;
}*/
/*double Add(double left, double right)
{
	return left + right;
}

long Add(long left, long right)
{
	return left + right;
}*/

//下面两个函数不可重载
/*void TestFunc(int a = 10)
{
	cout << "void TestFunc(int)" << endl;
}
void TestFunc(int a)
{
	cout << "void TestFunc(int)" << endl;
}*/

//引用         给变量起别名，不会重新开辟空间，类型必须相同
/*void TestRef()
{
	int a = 10;
	int& ra = a;//原理其实就是定义了一个地址和a相同的,类型为int的变量ra

	printf("%p\n", &a);
	printf("%p\n", &ra);
}
//常引用
void TestConstRef()
{
	const int a = 10;
	//int& ra = a;//错误，a是常量
	const int&ra = a;
	//int& b=10;   错误，10是常量
	const int& b = 10;
	double d = 12.34;
	//int& rd = d;类型不匹配
	//const int& rd = d;
}
//引用做参数,传引用实现两个数的置逆
void Swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}
//做返回值
int& TestRefReturn(int& a)
{
	a += 10;
	return a;
}*/
//引用类型返回时，返回值的生命周期不受函数的限制
/*int& Add(int a, int b)
{
	int c = a + b;
	return c;
}*/
//传值传引用的效率比较
/*struct A
{
	int a[10000];
};
void TestFun1(A a)
{}
void TestFun2(A& a)
{}
void TestRefAndValue()
{
	A a;
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFun1(a);
	size_t end1 = clock();

	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFun2(a);
	size_t end2 = clock();

	cout << "TestFun1(int*)-time:" << end1 - begin1 << endl;
	cout << "TestFun2(int&)-time:" << end2 - begin2 << endl;
}*/
//值和引用的作为返回值类型的性能比较
/*struct A
{
	int a[10000];
};
A a;
A TestFun1()
{
	return a;
}
A& TestFun2()
{
	return a;
}
void TestReturnByRefOrValue()
{
	//以值为函数的返回值类型
	size_t begin1 = clock();
	for (size_t i = 0; i < 100000; i++)
		TestFun1();
	size_t end1 = clock();

	//以引用作为函数返回值
	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; i++)
		TestFun2();
	size_t end2 = clock();
	cout << "TestFun1 time:" << end1 - begin1 << endl;
	cout << "TestFun2 time:" << end2 - begin2 << endl;
}*/
//内联函数
/*inline void f(int i)
{
	cout << i << endl;
}*/
//auto关键字
/*int TestAuto()
{
	return 10;
}
//auto 不能推导的场景
void TestAuto(auto a)
{}
void TestAuto()
{
	int a[] = { 1, 2, 3 };
	auto b[] = { 4, 5, 6 };不能推导数组
}*/
//指针空值
void f(int)
{
	cout << "f(int)" << endl;
}
void f(int*)
{
	cout << "f(int*)" << endl;
}
int main()
{
	f(0);
	f(NULL);//这里NULL其实就是0，作为指针空值并不合适，无法正确调用函数
	f((int*)NULL);
	f(nullptr);//指针空值
	/*//基于范围的循环,foreach 循环
	int array[] = { 1, 2, 3, 4, 5 };
	for (auto& e : array)
		e *= 2;
	for (auto e : array)
		cout << e << endl;
	/*auto a = 1, b = 2;
	//auto c = 3, d = 4.0;错误，编译器只能对第一个类型进行推导，推导出来的类型定义其他变量
	/*int x = 10;
	auto b = &x;
	auto *c = &x;
	auto &d = x;

	/*int a = 10;
	auto b = a;
	auto c = 'a';
	auto d = TestAuto();
	//auto e;    错误，必须进行初始化*/
	/*cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	*b = 20;
	*c = 30;
	d = 40;
	
	/*f(10);
	/*int a = 10;
	int& ra = a;
	cout << "&a=" << &a << endl;
	cout << "&ra=" << &ra << endl;
	/*for (int i = 0; i < 10; i++)
		TestReturnByRefOrValue();
	/*for (int i = 0; i < 10; i++)
		TestRefAndValue();
	/*int& ret = Add(1, 2);
	Add(3, 4);
	cout << "Add(1,2)is:" << ret << endl;
	/*int a = 2;
	TestRefReturn(a);
	cout << a << endl;
	cout << TestRefReturn(a) << endl;
	/*int a = 10;
	int b = 20;
	Swap(a, b);
	printf("%d %d\n", a, b);
	TestRef();
	//TestFunc();
	/*TestFunc2(15, 21);
	TestFunc(10);*/
	/*cout << Add(10, 20) << endl;
	cout << Add(10.0, 20.0) << endl;
	cout << Add(10L, 20L) << endl;*/
	system("pause");
	return 0;
}
#include<iostream>
using namespace std;

class A
{
public:
	A()
	{
		cout << "~A" << endl;
	}
};
class B :public A
{
private:
	A _a;
public:
	B(A &a)
		:_a(a)
	{
		cout << "~B" << endl;
	}
};
void test()
{
	A a;
	B b(a);
}
/*class Man
{
public:
	Man()
	{
		cout << "我是man的构造函数，我被调用了" << endl;
	}
	~Man()
	{
		cout << "我是man的析构函数，我被调用" << endl;
	}
};
class Boy
{
public:
	Boy()
	{
		cout << "我是boy的构造函数，我被调用了" << endl;
	}
	~Boy()
	{
		cout << "我是boy的析构函数，我被调用了" << endl;
	}
};

class Girl
{
public:
	Girl()
	{
		cout << "我是girl的构造函数，我被调用了" << endl;
	}
	~Girl()
	{
		cout << "我是girl的析构函数，我被调用了" << endl;
	}
};

class Teenager : public Man
{
	Boy boy;
	Girl girl;
public:
	Teenager()
	{
		cout << "我是teenager的构造函数，我被调用了" << endl;
	}
	~Teenager()
	{
		cout << "我是teenager的析构函数，我被调用了" << endl;
	}
};
void test()
{
	Teenager teenager;
}*/
int main()
{
	test();
	/*A a;
	B b(a);
	/*char a[80] = " 0123\0789 ";
	char b[80] = " 0123\0779 ";
	//cout << strlen(a) << endl;
	//cout << strlen(b) << endl;
	printf("%c\n", 7);*/

	system("pause");
	return 0;
}
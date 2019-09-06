#include<iostream>
#include<string>
#include<Windows.h>
#include<math.h>
#include<time.h>
using namespace std;

/*class A{};
class B : public A {};

class Person {
public:
double f() {
cout << "per" << endl;
return 0;
}
};

class Student : public Person {
public:
int f(int n){
cout << "stu" << endl;
return 123;
}
};*/
/*class Person {
public:
virtual ~Person() { cout << "~Person()" << endl; }
};

class Student : public Person {
public:
virtual ~Person() { cout << "~Person()**" << endl; }
virtual ~Student() { cout << "~Student()" << endl; }
};

// 只有派生类Student的析构函数重写了Person的析构函数，下面的delete对象调用析构函数，才能构成 多态，才能保证p1和p2指向的对象正确的调用析构函数。

*/
class A
{
public:
	A()
	{
		printf("A");
	}
	~A()
	{
		printf("~A");
	}
};
class B
{
public:
	B()
	{
		printf("B");
	}
	~B()
	{
		printf("~B");
	}
};
class C :public A, public B
{
public:
	C()
	{
		printf("C");
	}
	~C()
	{
		printf("~C");
	}
};
void knuth(int n, int m)
{
	srand((unsigned int)time(0));
	for (int i = 0; i < n; i++)
	{
		int ran = rand() % (n - i);
		if (ran < m)
		{
			cout << i << endl;
			m--;
		}
	}
}
int main()
{
	knuth(100, 5);
	/*C *a = new C();
	delete a;
	//a == 1;
	//++i;
	//a++ = 5;
	//a = int(i);
	/*Person* p1 = new Person;
	Person* p2 = new Student;

	delete p1;
	delete p2;
	/*Student s;
	s.f();
	/*Person *p = new Student;
	p->f();
	/*Student s1;
	s1.print();
	/*Assistant a;
	a.print();
	//cout<<a. <<endl;
	//cout << a._name << endl;
	/*Derive d;
	d.func1();
	/*VFPTR* vTableb1 = (VFPTR*)(*(int*)&d);
	PrintVTable(vTableb1);

	VFPTR* vTableb2 = (VFPTR*)(*(int*)((char*)&d + sizeof(Base1)));
	PrintVTable(vTableb2);*/
	/*Base b;
	Derive d;
	VFPTR *vTableb = (VFPTR*)(*(int*)&b);
	PrintVTable(vTableb);

	VFPTR* vTabled = (VFPTR*)(*(int*)&d);
	PrintVTable(vTabled);


	/*cout << sizeof(b) << endl;
	cout << sizeof(d) << endl;*/

	system("pause");
	return 0;
}
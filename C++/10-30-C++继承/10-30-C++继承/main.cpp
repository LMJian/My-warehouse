#include<iostream>
#include<string>
using namespace std;

/*class A {
public:
	virtual ~A() {};
	virtual void FuncA() {};
	int a=1;
};
class B {
public:
	virtual void FuncB() {};
	int b=2;
};
class C :public B,public A{
public:
	virtual void FuncC() {};
	int c=3;
};

class Person {
public:
	string _name = "小李子";
	int _num = 27;
	void Print(int num)
	{
		printf("Person---\n");
	}
};
class Student :public Person
{
public:
	void Print()
	{
		cout << "姓名:" << _name << endl;
		cout << "身份证号：" << Person::_num << endl;
		cout <<  "学号：" << _num << endl;
	}
protected:
	int _num = 999;
};*/

/*class A {
public:
	A(int x)
		:_a(x)
	{}
	void fun() {
		cout << "func()" << endl;
	}
	const A& operator =(const A& a)
	{
		_a = a._a;
		return *this;
	}
private:
	int _a;
};
class B :public A {
public:
	B(int x,int b)
		:_b(x)
		,A(b)
	{}
	void fun(int i) {
		A::fun();
		cout << "func(int i)->" << i << endl;
	}
	const B& operator=(const B& b)
	{
		this->A::operator=(b);
		_b = b._b;
		return *this;
	}
private:
	int _b;
};*/



/*class Person
{
public:
	friend void Display(const Person& p, const Student& s);
public:
	string _name="hehe";
	Student sa;
};
class Student :public Person
{
protected:
	int _stuNum;
};
void Display(const Person& p, const Student& s)
{
	cout << p._name << endl;
	//cout << s._stuNum << endl;
}*/

/*class Person {
public:
	Person() {
		++_count;
	}
protected:
	string _name;
public:
	static int _count;
};
int Person::_count = 0;
class Student :public Person
{
protected:
	int _stuNum;
};
class Graduate :public Student
{
protected:
	string _seminarCourse;
};
void TestPerson()
{
	Student s1;
	Student s2;
	Student s3;
	Graduate s4;
	cout << "人数" << Person::_count << endl;
	Student::_count = 0;
	cout << "人数" << Person::_count << endl;
}*/

/*class Person {
public:
	int _name=1;
};
class Student :virtual public Person
{
protected:
	int _num=2;
};
class Teacher :virtual public Person
{
protected:
	int _id=3;
};
class Assistant :public Student, public Teacher
{
protected:
	int _majorCourse=4;
};
void Test()
{
	Assistant a;
	a._name = 5;
	a.Student::_name = 6;
	a.Teacher::_name = 7;

}

class A {
public:
	int _a;
};
// class B : public A
class B : public A {
public:
	int _b;
};
// class C : public A
class C :  public A {
public:
	int _c;
};
class D : public B, public C {
public:
	int _d;
};*/
class Base1 {
public:
	int _b1;
};
class Base2 {
public:
	int _b2;
};
class Derive : public Base1, public Base2 {
public:
	int _d;
};
int main() {
	// A. p1 == p2 == p3
	// B. p1 < p2 < p3
	// C. p1 == p3 != p2
	// D. p1 != p2 != p3
	Derive d;
	Base1* p1 = &d;
	Base2* p2 = &d;
	Derive* p3 = &d;
	system("pause");
	return 0;
}


/*int main()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;

	
	//Test();
	//Person();
	/*Person p;
	Student s;
	Display(p, s);
	/*B b(1, 2), c(4, 3);
	b = c;
	//b.fun(10);
	/*Student s1;
	s1.Print(1);

	/*A a;
	B b;
	C obj;
	A* ptr1 = &obj;
	B* ptr2 = &obj;
	C* ptr3 = &obj;
	cout << ptr1 << endl << ptr2 << endl << ptr3 << endl;
	/*int *p();
	//int (*)q();
	int (*m)();

	system("pause");
	return 0;
}*/
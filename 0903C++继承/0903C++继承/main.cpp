#include<iostream>
#include<string>
using namespace std;

/*class Person
{
public:
	void Print()
	{
		cout <<  _name << endl;
		//cout << "age:" << _age << endl;
	}
protected:
	string _name ;
public:
	int _age;
};
class Student :public Person
{
public:
	void Print()
	{
		cout << _name << endl;
		//cout << _age << endl;
		cout << _stunum << endl;
	}
	int _stunum;
};
int main()
{
	Student s1;
	s1.Print();
	s1._age
	system("pause");
	return 0;
}
/*class Teacher :public Person
{
protected:
	int _jobid;
};
class Person
{
protected:
	string _name;
	string _sex;
	int _age;
};
class Student :public Person
{
public:
	int _No;
};
void Test()
{
	Student sobj;
	Person pobj = sobj;//子类给父类截断构造
	Person* pp = &sobj;//父类指针指向子类
	Person& rp = sobj;//子类传给父类引用

	//sobj = pobj;   父类给子类赋值不可以，因为父类没有子类的全部成员

	pp = &sobj;
	Student* ps1 = (Student*)pp;
	ps1->_No = 10;

	pp = &pobj;
	Student* ps2 = (Student*)pp;
	ps2->_No = 10;
}
class Person
{
protected:
	string _name = "小李子";
	int _num = 111;
};
class Student :public Person
{
public:
	void Print()
	{
		cout << "姓名" << _name << endl;
		cout << "身份证号：" << Person::_num << endl;
		cout << "学号" << _num << endl;
	}
protected:
	int _num = 999;
};
void Test()
{
	Student s1;
	s1.Print();
}
class A
{
public:
	void fun()
	{
		cout << "func()" << endl;
	}
};
class B :public A
{
public:
	void fun(int i)
	{
		A::fun();
		cout << "func(int i)->" << i << endl;
	}
};
void test()
{
	B b;
	b.fun(10);
}
class Person
{
public:
	Person(const char* name = "peter")
		:_name(name)
	{
		cout << "Person()" << endl;
	}
	Person(const Person& p)
		:_name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}
	Person& operator=(const Person& p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;
		return *this;
	}
	~Person()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name;
};
class Student :public Person
{
public:
	Student(const char* name, int num)
		:Person(name)
		, _num(num)
	{
		cout << "Student()" << endl;
	}
	Student(const Student& s)
		:Person(s)
		, _num(s._num)
	{
		cout << "Student(const Student& s)" << endl;
	}
	Student& operator=(const Student& s)
	{
		cout << "Student& operator=(const Student& s)" << endl;
		if (this != &s)
		{
			Person::operator=(s);
			_num = s._num;
		}
		return *this;
	}
	~Student()
	{
		cout << "~Student()" << endl;
	}
protected:
	int _num;
};
void test()
{
	Student s1("jack", 18);
	Student s2(s1);
	Student s3("rose", 17);
	s1 = s3;
}
class NonInherit
{
public:
	static NonInherit GetInstance()
	{
		return NonInherit();
	}
private:
	NonInherit()
	{}
};
class A :public NonInherit
{
public:
	void print()
	{
		cout << "123" << endl;
	}
};
class Student;
class Person
{
public:
	friend void Display(const Person& p, const Student& s);
protected:
	string _name;
};
class Student :public Person
{
public:
	int _stuNum;
};
void Display(const Person& p, const Student& s)
{
	cout << p._name << endl;
	cout << s._stuNum << endl;
}
class Person
{
public:
	Person(){ ++_count; }
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
	cout << "人数：" << Graduate::_count << endl;
	Student::_count = 0;
	cout << "人数：" << Person::_count << endl;
}
class Person
{
public:
	string _name;
};
class Student :virtual public Person
{
protected:
	int _num;
};
class Teacher:virtual public Person
{
protected:
	int _id;
};
class Assistant :public Student, public Teacher
{
protected:
	string _majorCourse;
};
void test()
{
	Assistant a;
	a._name = "peter";

	//a.Student::_name = "xxx";
	//a.Teacher::_name = "yyy";
}
class A
{
public:
	int _a;
};
class B :virtual public A
{
public:
	int _b;
};
class C :virtual public A
{
public:
	int _c;
};
class D :public B, public C
{
public:
	int _d;
};
class Car
{
protected:
	string _colour = "白色";
	string _num = "陕ABIT00";
};
class BMW :public Car
{
public:
	void Drive()
	{
		cout << "好开-操作" << endl;
	}
};
class Benz :public Car
{
public:
	void Drive()
	{
		cout << "好坐-舒适" << endl;
	}
};
class Tire
{
protected:
	string _brand = "Michelin";
	size_t _size = 17;
};
class Car
{
protected:
	string _colour = "白色";
	string _num = "陕ABIT00";
	Tire _t;
};
class Base1
{
public:
	int _b1;
};
class Base2
{
public:
	int _b2;
};
class Derive :public Base1, public Base2
{
public:
	int _d;
};*/
class A
{
public:
	int _a;
};

//class B : public A 
class B : virtual public A
{
public:
	int _b;
};

//class C : public A 
class C : virtual public A
{
public:
	int _c;
};

class D : public B, public C
{
public:
	int _d;
};

int main()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;
	printf("%p\n", d.B::_a);
	/*Derive d;
	Base1 *p1 = &d;
	Base2 *p2 = &d;
	Derive *p3 = &d;
	/*D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;
    //TestPerson();
	/*Person p;
	Student s;
	Display(p, s);
	//A a;
	/*Student s;
	//Teacher t;
	s.Print();
	cout << s._name << endl;
	//t.Print();*/

	system("pause");
	return 0;
}
#include<iostream>
using namespace std;

/*class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "È«¼Û" << endl;
	}
};
class Student :public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "°ë¼Û" << endl;
	}
};
void Func(Person& p)
{
	p.BuyTicket();
}*/
/*class A{};
class B :public A{};

class Person{
public:
	virtual A* f()
	{
		cout << "person" << endl;
		return new A;
	}
};
class Student :public Person{
public:
	virtual B* f()
	{
		cout << "student" << endl;
		return new B;
	}
};
void Func(Person &pt)
{
	pt.f();
}*/
/*class Person{
public:
	virtual ~Person()
	{
		cout << "~Person()" << endl;
	}
};
class Student :public Person{
public:
	virtual ~Student()
	{
		cout << "~student()" << endl;
	}
};*/
/*class Car
{
public:
	virtual void Drive()final {}
};
class Benz :public Car
{
public:
	virtual void Drive()
	{
		cout << "Benz-ÊæÊÊ" << endl;
	}
};*/
/*class Car{
public:
	 virtual void Drive(){
		 cout << "1" << endl;
	 }
};
class Benz :public Car{
public:
	 virtual void Drive()override
	{
		cout << "Benz-ÊæÊÊ" << endl;
		//return 0;
	}
};
void Func(Car &pt)
{
	pt.Drive();
}*/
/*class Car
{
public:
	virtual void Drive() = 0;
};
class Benz :public Car
{
public:
	virtual void Drive()
	{
		cout << "Benz-ÊæÊÊ" << endl;
	}
};
class BMW :public Car
{
public:
	virtual void Drive()
	{
		cout << "BMW-²Ù¿Ø" << endl;
	}
};
void Test()
{
	//Car *a = new Car;
	Car *pBenz = new Benz;
	pBenz->Drive();

	Car *pBMW = new BMW;
	pBMW->Drive();
}*/
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
/*public:
	void print()
	{
		cout << "B" << endl;
	}
};*/
/*class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}
	void Func3()
	{
		cout << "Base::Func3()" << endl;
	}
private:
	int _b = 1;
};
class Derive :public Base
{
public:
	virtual void Func1()
	{
		cout << "Derive::Func1()" << endl;
	}
private:
	int _d = 2;
};*/
class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "ÂòÈ«Æ±" << endl;
	}
};
class Student :public Person{
public:
	virtual void BuyTicket() override{
		cout << "Âò°ëÆ±" << endl;
	}
};
void Func(Person* p)
{
	p->BuyTicket();
}
int main()
{
	Person mike;
	Student johnson;
	Func(&mike);
	Func(&johnson);
	mike.BuyTicket();

	/*Person Mike;
	Func(Mike);
	Student JohnSon;
	Func(JohnSon);
	/*Base b;
	Derive d;
	cout << sizeof(b) << endl;
	cout << sizeof(d) << endl;
	//b.print();
	//Test();
	/*Benz p;
	Func(p);
	//Person *p1 = new Person;
	//Person *p2 = new Student;
	/*Person *p1 = new Person;
	Person *p2 = new Student;
	delete p1;
	cout << endl;
	delete p2;
	/*Person ps;
	Student st;
	
	Func(ps);
	Func(st);*/

	system("pause");
	return 0;
}
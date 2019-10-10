#include<iostream>
#include<string>
using namespace std;

/*class Base{
public:
	virtual void func1(){
		cout << "Base::func1" << endl;
	}
	virtual void func2(){
		cout << "Base::func2" << endl;
	}
private:
	int a;
};
class Derive :public Base{
public:
	virtual void func1(){
		cout << "Derive::func1" << endl;
	}
	virtual void func3(){
		cout << "Derive::func3" << endl;
	}
	virtual void func4(){
		cout << "Derive::func4" << endl;
	}
private:
	int b;
};
typedef void(*VFPTR)();//函数指针
void PrintVTable(VFPTR vTable[])
{
	cout << "虚表地址>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf("第%d个虚函数地址：0X%x,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}
class A{
	void a()
	{
		cout << "a" << endl;
	}
};
class Base1{
public:
	virtual void func1(){
		cout << "Base1::func1" << endl;
	}
	virtual void func2(){
		cout << "Base1::func2" << endl;
	}
private:
	int b1;
};
class Base2{
public:
	virtual void func1(){
		cout << "Base2::func1" << endl;
	}
	/*virtual void func2(){
		cout << "Base2::func2" << endl;
	}
private:
	int b2;
};
class Derive :public Base1, public Base2{
public:
	virtual void func1(){
		cout << "Derive::func1" << endl;
	}
	virtual void func3(){
		cout << "Derive::func3" << endl;
	}
private:
	int d1;
};
int main()
{
	Derive d;
	d.func1();
	d.func2();
	d.func3();



	system("pause");
	return 0;
}*/
/*typedef void(*VFPTR)();//函数指针
void PrintVTable(VFPTR vTable[])
{
	cout << "虚表地址>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf("第%d个虚函数地址：0X%x,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}*/
class Person {
public:    
	virtual void print()
	{
		cout << "Person" << endl;
	}
	string _name; // 姓名 
}; 
class Student : public Person { 
public:
	virtual void print()
	{
		cout << "Student" << endl;
	}
protected:
	int _num ; //学号 
}; 
class Teacher : virtual public Person { 
public:
	virtual void print()
	{
		cout << "Teacher" << endl;
	}
private :    
	int _id ; // 职工编号 
}; 
class Assistant : public Student, public Teacher { 
protected :    
	string _majorCourse ; // 主修课程 
}; 

int main()
{
	Student s1;
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
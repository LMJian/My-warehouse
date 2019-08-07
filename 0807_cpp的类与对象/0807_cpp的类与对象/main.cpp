#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string.h>

using namespace std;

/*struct Student
{
	void SetStudentInfo(const char* name, const char* gender, int age)
	{
		strcpy_s(_name, name);
		strcpy_s(_gender, gender);
		_age = age;
	}
	void PrintStudentInfo()
	{
		cout << _name << " " << _gender << " " << _age << endl;
	}
	char _name[20];
	char _gender[3];
	int _age;
};*/
/*class Person
{
public:
	void showInfo();
public:
	char* _name;
	char* _sex;
	int _age;
};
//在类体外定义成员
void Person::showInfo()
{
	cout << _name << "-" << _sex << "-" << _age << endl;
}*/
/*class A1{
public:
	void f1(){}
private:
	int _a;
};
class A2{
public:
	void f2(){}
};
class A3{};
class A
{
public:
	void PrintA()
	{
		cout << _a << endl;
	}
	void Show()
	{
		cout << "Show()" << endl;
	}
private:
	int _a;
	};*/
/*
class Date {
public:    
	void Display()    
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}        
	void SetDate(int year, int month, int day)    
	{ 
		_year = year;        
		_month = month;        
		_day = day; 
	} 
private:    
	int _year = 1; // 年    
	int _month = 2; // 月    
	int _day = 3; // 日 
};
class Date
{
public:
	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
class Time
{
public:
	Time()
	{
		cout << "Time()" << endl;
		_hour = 0;
		_minute = 0;
		_second = 0;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	/*bool operator==(const Date& d1, const Date& d2) 
	{ 
		return d1._year == d2._year
			&& d1._month == d2._month
			&& d1._day == d2._day; 
	}
	bool operator==(const Date& d2)
	{
		return _year == d2._year
			&&_month == d2._month
			&&_day == d2._day;
	}
private:
	int _year;
	int _month;
	int _day;
	//Time _t;
};*/

/*typedef int DataType;
class SeqList
{
public:
	SeqList(int capacity = 10)
	{
		_pData = (DataType*)malloc(capacity*sizeof(DataType));
		//(_pData);
		_size = 0;
		_capacity = capacity;
	}
	~SeqList()
	{
		cout << "1523" << endl;
		if (_pData)
		{
			free(_pData);
			_pData = NULL;
			_capacity = 0;
			_size = 0;
		}
	}
private:
	int *_pData;
	size_t _size;
	size_t _capacity;
};
class String
{
public:
	String(const char* str = "jack")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~String()
	{
		cout << "~String()" << endl;
		free(_str);
	}
private:
	char* _str;
};
class String
{
public:
	String(const char* str = "")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~String()
	{
		cout << "~String()" << endl;
		free(_str);
	}
private:
	char* _str;
};*/

class Date {
public:    
	void Display(){
	cout << "Display ()" << endl;        
	cout << "year:" << _year << endl;        
	cout << "month:" << _month << endl;
	cout << "day:" << _day << endl << endl;}    
	void Display() const{ 
		cout << "Display () const" << endl;        
		cout << "year:" << _year << endl;        
		cout << "month:" << _month << endl;       
		cout << "day:" << _day << endl << endl; } 
	Date* operator&()
	{
		return this;
	}
	const Date* operator&()const
	{
		return this;
	}

private:    
	int _year; // 年
	int _month ; // 月 
	int _day ; // 日 
}; 
void Test () {    
	Date d1;
	Date d2;
	cout << (d1&d2) << endl;
}


int main()
{
	Test();
	/*String s1("hello");
	String s2("dsadsa");
	s1 = s2;
	/*Date d1(2018, 9, 26);
	Date d2(2018, 9, 27);
	cout << (d1 == d2) << endl;
	/*String s1("hello");
	String s2(s1); 
	/*Date y1;
	Date y2(y1);
	y1.Display();
	y2.Display();
	/*Date d1;
	/*Date d1, d2;
	d1.SetDate(2018, 5, 1);
	d1.Display();

//	Date d2;
	d2.Display();
	/*Date* p = NULL;
	p->PrintA();     
	p->Show();
	/*cout << "  A1->" << sizeof(A1) << "  A2->" << sizeof(A2) << "  A3->" << sizeof(A3) << endl;
	/*Person per;
	per._age = 20;
	per._name = "lmj";
	per._sex = "f";
	per.showInfo();
	cout << sizeof(per) << endl;
	/*Student s;
	s.SetStudentInfo("Peter", "男", 18);
	s.PrintStudentInfo();
	Date d1, d2;
	d1.SetDate(2018, 5, 1);
	d2.SetDate(2018, 7, 1);
	d1.Display();
	d2.Display();*/
	system("pause");
	return 0;
}
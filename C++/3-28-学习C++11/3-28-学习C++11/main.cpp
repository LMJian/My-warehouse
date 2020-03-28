#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Car
{
public:
	virtual void Drive() final {
		cout << "123" << endl;
	}
};

class Benz :public Car
{
public:
	//编译报错
	//void Drive() { cout << "Benz-舒适" << endl; }
};
#include<map>

class Point {
public:
	Point(int x=0,int y=0)
		:_x(x)
		,_y(y)
	{}
//private:
	int _x;
	int _y;
};

#include<string>

/*class A
{
public:
	virtual void f() {}
};

class B : public A {};

void fun(A* pa) {
	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回   
	B* pb1 = static_cast<B*>(new A());
	B* pb2 = dynamic_cast<B*>(pa);
	cout << "pb1:" << pb1 << endl;
	cout << "pb2:" << pb2 << endl;
}*/

/*class A
{
public:
	/*explicit A(int a)
	{
		cout << "A(int a)" << endl;
	}
	A(int a)
	{
		cout << "A(int a)" << endl;
	}

	A(const A& a)
	{
		cout << "A(const A& a)" << endl;
	}
private:
	int _a;
};
void Test()
{
	const int a = 2;
	int* p = const_cast<int*>(&a);
	*p = 3;
	cout << a << endl;
}

void* GetMemory(size_t size) {
	return malloc(size);
}
#include<array>
#include<forward_list>

class Info {
public:
	Info()
		:_type(0)
		,_name('a')
	{
		InitRSet();
	}
	Info(int type)
		:Info()
	{
		_type = type;
	}
	Info(char a)
		:Info()
		//,_name(a)
	{
		_name = a;
	}
private:
	void InitRSet() {
		cout << "InitRSet" << endl;
	}
private:
	int _type;
	char _name;
};

class A {
public:
	A(int a)
		:_a(a)
	{}
	A(const A&) = delete;
	A() = delete;
	A& operator=(const A& a) = delete;
private:
	int _a;
};

//A& A::operator=(const A& a) = default;
class A{
public:
	A(const char* p) {
		cout << "A()" << endl;
	}
	A(const A& a) {
		cout << "A(const A& a)" << endl;
	}
	A(const A&& a) {
		//cout << "A(const A& a)" << endl;
	}
};


String GetString(const char* pStr) {
	return String(pStr);
}
void test(string& s) {
}
void test(string&& s) {
}*/

class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	String(String&& s)
		:_str(s._str)
	{
		s._str = nullptr;
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* pTemp = new char[strlen(s._str) + 1];
			strcpy(pTemp, s._str);
			delete[] _str;
			_str = pTemp;
		}
		return *this;
	}

	~String()
	{
		if (_str) delete[] _str;
	}
private:
	char* _str;
};

class Person
{
public:
	Person(const char* name, const char* sex, int age)
		: _name(name)
		, _sex(sex)
		, _age(age)
	{}

	Person(const Person& p)
		: _name(p._name)
		, _sex(p._sex)
		, _age(p._age)
	{}

#if 0

	Person(Person&& p)
		: _name(p._name)
		, _sex(p._sex)
		, _age(p._age)
	{}

#else

	Person(const Person&& p)
		: _name(move(p._name))
		, _sex(move(p._sex))
		, _age(p._age)
	{}

#endif

private:
	String _name;
	String _sex;
	int _age;
};
Person GetTempPerson()
{
	Person p("prety", "male", 18);
	return p;
}

void Fun(int &x) { cout << "lvalue ref" << endl; }
void Fun(int &&x) { cout << "rvalue ref" << endl; }
void Fun(const int &x) { cout << "const lvalue ref" << endl; }
void Fun(const int &&x) { cout << "const rvalue ref" << endl; }
template<typename T>
void PerfectForward(T &&t) { Fun(std::forward<T>(t)); }


int main() {
	PerfectForward(10); // rvalue ref
	int a;
	PerfectForward(a); // lvalue ref
	PerfectForward(std::move(a)); // rvalue ref
	const int b = 8;
	PerfectForward(b); // const lvalue ref
	PerfectForward(std::move(b)); // const rvalue ref

	//Person p(GetTempPerson());
	/*test("123");
	const int&& ra = 10;
	//int a = 10;
	//int&& ra;
	//int&& ra = a;
	//String&& s = GetString("hello");
	//test("123");
	//String s1("hello");
	//String s2(GetString("world"));
	//A s1("hello");
	//A s2(test("word"));

	//A a1(10);
	//A a2;
	//a2 = a1;

	/*forward_list<int> arr;
	arr.push_front(1);
	arr.push_front(2); 
	arr.push_front(3); 
	arr.push_front(4); 
	arr.push_front(5); 
	arr.push_front(6);
	for (auto& e : arr)
		cout << e << " ";
	cout << endl;

	/*array<int, 10> arr { 1, 2, 3, 4, 5 };
	//arr.assign(19);
	cout << arr.at(3) << endl;
	cout << arr.front() << endl;

	for (auto& e : arr)
		cout << e << " ";
	cout << endl;
	
	/*cout << typeid(decltype(GetMemory)).name() << endl;
	cout << typeid(decltype(GetMemory(0))).name() << endl;
	/*int a = 0x7FFFFFFF;
	long long b = 0x7FFFFFFF;
	decltype(a + b) c;
	c = a + b;
	cout << c << endl;
	cout << typeid(c).name() << endl;
	/*long long c = a + b;
	cout << a << " " << b << " " << c << endl;
	cout << typeid(a + b).name() << endl;

	//Test();
	/*A a1(1);

	// 隐式转换-> A tmp(1); A a2(tmp);     
	A a2 = 1;
	/*A a;
	B b;
	fun(&a);
	fun(&b);
	/*short a = 32670;
	short b = 32670;
	short c = a + b;
	cout << c << endl;

	map<string, string> m{ {"apple","苹果"},{"banana","香蕉"} };
	//map<string, string>::iterator it = m.begin();
	auto it = m.begin();
	while (it != m.end()) {
		cout << it->first << " " << it->second << endl;
		++it;
	}
	/*Point p{ 1,2 };
	cout << p._x << " " << p._y << endl;

	vector<Point> arr{ {1,2},{3,4} };
	for (auto& e : arr)
		cout << e._x << ":" << e._y << endl;

	/*vector<int> v={ 1,2,3,4,5 };
	for (auto& e : v)
		cout << e << " ";
	cout << endl;*/

	/*int x1 = { 10 };
	int x2{ 10 };
	int x3 = 1 + 2;
	int x4 = { 1 + 2 };
	int x5{ 1 + 2 };
	cout << x1 << " " << x2 << " " << x3 << " " << x4 << " " << x5 << endl;


	int arr1[5]{ 1,2,3,4,5 };
	int arr2[]{ 1,2,3,4,5 };
	for (auto& e : arr1)
		cout << e << " ";
	cout << endl;
	for (auto& e : arr2)
		cout << e << " ";
	cout << endl;

	int* arr3 = new int[5]{ 1,2,3,4,5 };
	for (int i = 0; i < 5; ++i) 
		cout << arr3[i] << " ";
	cout << endl;

	vector<int> v{ 1,2,3,4,5 };
	for (auto& e : v)
		cout << e << " ";
	cout << endl;
	map<int, int> m{ {1,1},{2,2},{3,3},{4,4} };
	for (auto& e : m)
		cout << e.first << ":" << e.second << endl;*/

	//Benz z;
	//z.Drive();
	system("pause");
	return 0;
}
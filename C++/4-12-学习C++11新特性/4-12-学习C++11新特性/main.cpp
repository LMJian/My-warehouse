#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
#include<vector>
using namespace std;

/*class Point
{
public:
	Point(int x = 0, int y = 0) : _x(x), _y(y)
	{}
private:
	int _x;
	int _y;
};

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

	String operator+(const String& s)
	{
		char* pTemp = new char[strlen(_str) + strlen(s._str) + 1];
		strcpy(pTemp, _str);
		strcpy(pTemp + strlen(_str), s._str);
		String strRet(pTemp);
		return strRet;
	}
	String(String&& s)
		: _str(s._str)
	{
		s._str = nullptr;
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

	Person(Person&& p)
		: _name(move(p._name))
		, _sex(move(p._sex))
		, _age(p._age)
	{}

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

void Fun(int &x) {
	cout << "int &x" << endl;
}
void Fun(int &&x) {
	cout << "int &&x" << endl;
}
void Fun(const int &x) {
	cout << "const int &x" << endl;
}
void Fun(const int &&x) {
	cout << "const int &&x" << endl;
}
template<typename T>
void PerfectForward(T &&t) {
	Fun(t);
}


class Rate
{
public:
	Rate(double rate) : _rate(rate)
	{}
	double operator()(double money, int year)
	{
		return money * _rate * year;
	}
private:
	double _rate;
};*/

#include<thread>

void ThreadFunc1(int& x) {
	x += 10;
}
void ThreadFunc2(int* x) {
	*x += 10;
}

template<class T>
void test(T&& x) {
	cout << "ok" << endl;
}
#include<atomic>

#include<string>

int main()
{
	string a = "123";
	string b = "345";
	const string &c = a + b;
	string &&d = a + b;

	/*vector<int> arr{ 1,2,3,4,5,6,7,8,9 };
	for (auto e : arr)
		cout << e << " ";
	cout << endl;


	/*atomic<int> a1(0);
	// ����ʧ��
	//atomic<int> a2(a1);
	atomic<int> a2(0);
	// ����ʧ��
	//a2 = a1;



	/*int a = 10;
	// ���̺߳����ж�a�޸ģ�����Ӱ���ⲿʵ�Σ���Ϊ���̺߳���������Ȼ�����÷�ʽ������ʵ�����õ����߳�ջ�еĿ���
	//thread t1(ThreadFunc1, a);
	//t1.join();
	//cout << a << endl;

	// �����Ҫͨ���βθı��ⲿʵ��ʱ���������std::ref()����
	thread t2(ThreadFunc1, std::ref(a));
	t2.join();
	cout << a << endl;

	// ��ַ�Ŀ���
	thread t3(ThreadFunc2, &a);
	t3.join();
	cout << a << endl;



	// ��������
	double rate = 0.49;
	Rate r1(rate);
	r1(10000, 2);

	// lamber
	auto r2 = [=](double monty, int year)->double {return monty * rate*year; };
	r2(10000, 2);
	return 0;


	/*string s1("hello");
	string s2(" world");
	string s3 = s1 + s2; // s3����s1��s2ƴ�����֮��Ľ������������¶���
	string&& s4 = s1 + s2; // s4����s1��s2ƴ�����֮�����ı���

	/*PerfectForward(10); // ��ֵ

	int a = 10;
	PerfectForward(a); // ��ֵ
	PerfectForward(std::move(a)); // ��ֵ
	const int b = 8;
	PerfectForward(b); // const��ֵ
	PerfectForward(std::move(b)); // const��ֵ*/

	system("pause");
	return 0;
}
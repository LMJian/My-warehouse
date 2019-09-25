#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class string1
{
public:
	string1(const char *s = "")
	{
		if (s == nullptr)
			s = "";
		_str = new char[strlen(s) + 1];
		strcpy(_str, s);
	}
	~string1()
	{
		if (_str)
		{
			delete _str;
			_str = nullptr;
		}
	}
	string1(const string1& s)
	{
		_str = new char[strlen(s._str) + 1];
		strcpy(_str, s._str);
	}
	string1& operator=(const string1& s)
	{
		if (this != &s)
		{
			delete _str;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}
		return *this;
	}
private:
	char *_str;
};

class string2
{
public:
	string2(const char *s = "")
	{
		if (s == nullptr)
			s = "";
		_str = new char[strlen(s) + 1];
		strcpy(_str, s);
	}
	~string2()
	{
		if (_str)
		{
			delete _str;
			_str = nullptr;
		}
	}
	string2(const string2& s)
		:_str(nullptr)
	{
		string2 st(s._str);
		swap(_str, st._str);
	}
	string2& operator=(string2 s)
	{
		swap(_str, s._str);
		return *this;
	}
private:
	char *_str;
};

class string3
{
public:
	string3(const char* s="")
		:_count(new int(1))
	{
		if (s == nullptr)
			s = "";
		_str = new char[strlen(s) + 1];
		strcpy(_str, s);
	}
	string3(const string3& s)
		:_count(s._count)
	{
		_str = s._str;
		++(*_count);
	}
	string3& operator=(const string3& s)
	{
		if (--(*_count) == 0)
		{
			delete _count;
			delete _str;
		}
		_count = s._count;
		_str = s._str;
		++(*_count);
		return *this;
	}
	~string3()
	{
		--(*_count);
		if (*_count == 0)
		{
			delete _count;
			delete _str;
		}
	}
private:
	char *_str;
	int *_count;
};
void test()
{
	string3 s1("123");
	string3 s2(s1);
	string3 s3("456");
	string3 s4(s3);
	s3 = s1;
	s4 = s2;
}
int main()
{
	test();
	//new int;
	_CrtDumpMemoryLeaks();


	system("pause");
	return 0;
}
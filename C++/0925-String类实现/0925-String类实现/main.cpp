#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

/*class string1
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
};*/

class String
{
public:
	String(const char* s="")
		:_count(new int(1))
	{
		if (s == nullptr)
			s = "";
		_str = new char[strlen(s) + 1];
		strcpy(_str, s);
	}
	String(const String& s)
		:_count(s._count)
	{
		_str = s._str;
		++(*_count);
	}
	char& operator[](size_t index)
	{
		if (_str == nullptr || index > strlen(_str))
		{
			static char nullchar = 0;
			return nullchar;
		}
		if (*_count == 1)
			return *(_str + index);
		char *str_t = new char[strlen(_str) + 1];
		strcpy(str_t, _str);
		if (--(*_count) == 0)
		{
			delete _count;
			delete _str;
		}
		_count = new int(1);
		_str = str_t;
		return *(_str + index);
	}
	String& operator=(const String& s)
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
	~String()
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
	String s1("123");
	String s2(s1);
	//cout << s1 << "\n" << &s2 << endl;
	s1[1] = 4;
	//cout << &s1 << "\n" << &s2 << endl;
}
int main()
{
	//cout << strlen(nullptr) << endl;
	test();
	//new int;
	_CrtDumpMemoryLeaks();

	system("pause");
	return 0;
}
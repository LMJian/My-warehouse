#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <iostream>
#include <time.h>
using namespace std;

class String
{
public:
	String(const char* s = "")
		:_count(new int(1))
		, _str (nullptr)
	{
		if (s == nullptr)
			s = "";
		_str = new char[strlen(s) + 1];
		strcpy(_str, s);
	}
	String(const String& s)
		:_count(s._count)
		,_str(nullptr)
	{
		_str = s._str;
		++(*_count);
	}
	char& operator[](size_t index)
	{
		if (index >= strlen(_str))
		{
			static char nullchar = 0;
			return nullchar;
		}
		if (*_count == 1)
			return *(_str + index);

		--(*_count);
		String str_t(_str);
		_str = nullptr;//防止临时变量释放原先的资源
		swap(_str, str_t._str);
		_count = new int(1);

		/*char *str_t = new char[strlen(_str) + 1];
		strcpy(str_t, _str);
		--(*_count);
		_str = str_t;
		_count = new int(1);*/
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
	clock_t start = clock();
	String s("123");
	for (int i = 0; i < 100000; i++)
		String s1 = s;
	clock_t end = clock();
	cout << end - start << endl;

	clock_t left = clock();
	string t("123");
	for (int i = 0; i < 100000; i++)
		string t1 = t;
	clock_t right = clock();
	cout << right - left << endl;
}

int main()
{
	String s1("123456");
	String s3(s1);
	String s2(s1);
	s2[1] = 'x';
	/*test();
	String  s1("123");
	char& ch = s1[1];
	String s2(s1);
	ch = '9';*/
	system("pause");
	return 0;
}
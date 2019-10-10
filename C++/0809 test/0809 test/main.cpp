#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class String
{
public:
	String(const String& s)
	{
		_str = s._str;
	}
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

void test()
{
	String s1("hello");
	String s2(s1);
}

int main()
{
	test();

	system("pause");
	return 0;
}
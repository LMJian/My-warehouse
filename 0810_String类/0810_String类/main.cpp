#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

/*void TestString()
{
	string s1;
	string s2("hello world!");
	string s3(s2);
}
void TestString1()
{
	string s("hello world!!!");
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	//cout << s << endl;

	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(10, 'a');
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(15);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	//cout << s << endl;

	s.resize(5);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	//cout << s << endl;
}
void TestString2()
{
	string s;
	s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(50);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}
void TestPushBack()
{
	string s;
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed:" << sz << '\n';
		}
	}
}
void TestPushBackReserve()
{
	string s;
	s.reserve(100);
	size_t sz = s.capacity();

	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed:" << sz << '\n';
		}

	}
}
void TestString()
{
	string s1("hello world");
	const string s2("hello world2");
	//cout << s1 << " " << s2 << endl;
	cout << s1[0] << " " << s2[0] << endl;

	s1[0] = 'H';
	//cout << s1 << endl;

	//s2[0] = 'h';
}
void TestString()
{
	string s("hello World");

	for (size_t i = 0; i < s.size(); ++i)
		cout << s[i] << endl;

	string::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << endl;
		++it;
	}
	string::reverse_iterator rit = s.rbegin();
	while (rit != s.rend())
		cout << *rit << endl;

	for (auto ch : s)
	{
		cout << ch << endl;
	}
}

void TestString()
{
	string str;
	str.push_back(' ');
	str.append("hello");
	str += 'b';
	str += "it";
	//cout << str << endl;
	cout << str.c_str() << endl;

	string file("string.cpp");
	size_t pos = file.rfind('.');
	string suffix(file.substr(pos, file.size() - pos));
	//cout << suffix << endl;

	string url("http://www.cplusplus.com/reference/string/string/find/");
	//cout << url << endl;
	size_t start = url.find("://");
	if (start == string::npos)
	{
		cout << "invalid url" << endl;
		return;
	}
	start += 3;
	size_t finish = url.find('/', start);
	string address = url.substr(start, finish - start);
	//cout << address < endl;

	pos = url.find("://");
	url.erase(0, pos + 3);
	//cout << url << endl;
}
class Solution{
public:
	string reverseString(string s){
		if (s.empty())
			return s;

		size_t start = 0;
		size_t end = s.size() - 1;

		while (start < end)
		{
			swap(s[start], s[end]);
			++start;
			--end;
		}
		return s;
	}
};
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
		{
			//assert(false);
			return;
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s)
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* pStr = new char[strlen(s._str) + 1];
			strcpy(pStr, s._str);
			delete[] _str;
			_str = pStr;
		}
		return *this;
	}
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
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
		:_str(nullptr)
	{
		String strTmp(s._str);
		swap(_str, strTmp._str);
	}
	String& operator=(String s)
	{
		swap(_str, s._str);
		return *this;
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			String strTmp(s);
			swap(_str, strTmp._str);
		}
		return *this;
	}
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};
void TestString()
{
	String s1("hello world!");
	String s2(s1);
}*/
namespace bit
{
	class String
	{
	public:
		typdef char* iterator;
	public:
		String(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		String& operator=(String s)
		{
			this->Swap(s);
			return *this;
		}
		~String()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		void PushBack(char c)
		{
			if (_size == _capacity)
				Reserve(_capacity * 2);
			_str[_size++] = c;
			_str[_size] = '\0';
		}
		String& operator+=(char c)
		{
			PushBack(c);
			return *this;
		}
		void Append(const char* str);
		String& operator+=(const char* str);
		void Clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}
		void Swap(String& s)
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}
		const char* C_Str()const
		{
			return _str;
		}
		size_t Size()const;
		size_t Capacity()const;
		bool Empty()const;
		void Resize(size_t newSize, char c = '\0')
		{
			if (newSize > _size)
			{
				if (newSize > _capacity)
					Reserve(newSize);
				memset(_str + _size, c, newSize - _size);
			}
			_size = newSize;
			_str[newSize] = '\0';
		}
		void Reserve(size_t newCapacity)
		{
			if (newCapacity > _capacity)
			{
				char *str = new char[newCapacity + 1];
				strcpy(str, _str);
				delete[] _str;
				_str = str;
				_capacity = newCapacity;
			}
		}
		char& operator[](size_t index)
		{
			assert(index < _size);
			return _str[index];
		}
		const char& operator[](size_t index)const
		{
			assert(index < _size);
			return _str[index];
		}
		bool operator<(const String& s);        
		bool operator<=(const String& s);        
		bool operator>(const String& s);        
		bool operator>=(const String& s);        
		bool operator==(const String& s);        
		bool operator!=(const String& s);
		// 返回c在string中第一次出现的位置        
		size_t Find (char c, size_t pos = 0) const;         
		// 返回子串s在string中第一次出现的位置         
		size_t Find (const char* s, size_t pos = 0) const;                
		// 在pos位置上插入字符c/字符串str，并返回该字符的位置        
		String& Insert(size_t pos, char c);        
		String& Insert(size_t pos, const char* str);

		// 删除pos位置上的元素，并返回该元素的下一个位置 
		String& Erase(size_t pos, size_t len);
	private:        
		friend ostream& operator<<(ostream& _cout, const bit::String& s);    
	private:        
		char* _str;        
		size_t _capacity;
		size_t _size;
	};
}
ostream& bit::operator<<(ostream& _cout, const bit::String& s)
{
	cout << s._str;
	return _cout;
}
int main()
{
	//TestString();
	/*string line;
	while (getline(cin, line))
	{
		size_t pos = line.rfind(' ');
		cout << line.size() - pos - 1 << endl;
	}*/
	//TestString();
	//TestPushBackReserve();
	//TestPushBack();
	//TestString();
	//TestString1();
	//TestString2();
	system("pause");
	return 0;
}
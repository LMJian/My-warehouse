#include<iostream>
using namespace std;
#include<string>

/*template<class T, size_t N=10>
class _array
{
public:
	T& operator[](size_t index)
	{
		return _array[index];
	}
	const T& operator[](size_t index)const
	{
		return _array[index];
	}
	size_t size()const
	{
		return _size;
	}
	bool empty()const
	{
		return 0 == _size;
	}
private:
	T _array[N];
	size_t _size;
};

template<class T>
bool IsEqual(T& left, T&right)
{
	return left == right;
}
///template<>
bool IsEqual(char*& left, char*& right)
{
	return strcmp(left, right) == 0;
}
void test()
{
	char p1[] = "hello";
	char p2[] = "hello";
	char *f1 = p1;
	char *f2 = p2;
	if (IsEqual(f1, f2))
		cout << "1" << endl;
	else
		cout << "2"<< endl;
}

template<class T1,class T2>
class Data
{
public:
	Data() { cout << "Data<T1,T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};
template<>
class Data<int, char>
{
public:
	Data() { cout << "Data<int,char>" << endl; }
private:
	int _d1;
	char _d2;
};
void TestVector()
{
	Data<int, int> d1;
	Data<int, char> d2;
	Data<char, char> d3;
	Data<double, char> d4;
}*/

/*template<class T1,class T2>
class Data {
public:
	Data() { cout << "Data<T1,T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};
template<class T1>
class Data<T1, int>
{
public:
	Data() { cout << "Data<T1,int>" << endl; }
private:
	T1 _d1;
	int _d2;
};
template <typename T1,typename T2>
class Data<T1*, T2*>
{
public:
	Data() { cout << "Data<T1*,T2*>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};
template <typename T1, typename T2>
class Data<T1&, T2&>
{
public:
	Data(const T1& d1,const T2& d2)
	:_d1(d1)
	,_d2(d2)
	{ 
		cout << "Data<T1&,T2&>" << endl; 
	}
private:
	const T1& _d1;
	const T2& _d2;
};
void test2()
{
	Data<double, int> d1;
	Data<int, double> d2;
	Data<int*, int*> d3;
	Data<int&, int&>d4(1, 2);
}*/

/*template<class T>
void Copy(T* dst, const T* src, size_t size)
{
	
}*/

/*bool PODtype(const char* name)
{
	const char* arr[] = { "int","short","long long","long","char","double","float","bool" };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (strcmp(arr[i], name) == 0)
			return true;
	}
	return false;
}
bool IsPOD()
{
	return true;
}
bool NotPOD()
{
	return false;
}*/
template<class T>
struct PODtype
{
	static bool get()
	{
		return true;
	}
};
template<>
struct PODtype<string>
{
	static bool get()
	{
		return false;
	}
};

template<class T>
void Copy(T* dst, const T* src, size_t size)
{
	if(PODtype<T>::get())
		memcpy(dst, src, sizeof(T)*size);
	else
	{
		for (size_t i = 0; i < size; ++i)
		{
			dst[i] = src[i];
		}
	}
}
void test()
{
	string strarr1[3] = { "132","156","123" };
	string strarr2[3];
	Copy(strarr2, strarr1, 3);
}
//#include"Add.h"


int main()
{
	test();
	//Add(1, 2);
	//test();
	//string s1;
	//s1.resize(102400);
	//string s2 = "adsdadsdsadsadsadsadsadsadsadsadsadsadsadsadsadsada";
	//cout << sizeof(s1) << endl << sizeof(s2) << endl;

	//test2();
	//TestVector();
	//_array<int, 20> arr;
	//cout << arr.size() << endl;
	//test();

	system("pause");
	return 0;
}
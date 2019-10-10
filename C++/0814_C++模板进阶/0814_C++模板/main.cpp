#include"a.h"

/*namespace bite
{
	template<class T,size_t N=10>
	class array
	{
	public:
		array(T *str, T n)
		{
			_size = n;
			size_t index = 0;
			while (n)
			{
				_array[index++] = *(str++);
				n--;
			}
		}

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
}
template<class T>
bool IsEqual(T& left, T& right)
{
	return left == right;
}
template<>
bool IsEqual<char*>(char*& left, char*& right)
{
	if (strcmp(left, right) == 0)
		return true;
	return false;
}

void Test()
{
	char *p1 = "hello";
	char *p2 = "hello";
	
	if (IsEqual(p1, p2))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}
template<class T1,class T2>
class Data
{
public:
	Data()
	{
		cout << "Data<T1,T2>"<<endl;
	}
private:
	T1 _d1;
	T2 _d2;
};
template<>
class Data < int , char >
{
public:
	Data()
	{
		cout << "Data<int,char>"<<endl;
	}
private:
	int _d1;
	char _d2;
};
void TestVector()
{
	Data<int, int>d1;
	Data<int, char>d2;
}
template<class T1,class T2>
class Data
{
public:
	Data()
	{
		cout << "Data<T1,T2>"<<endl;
	}
private:
	T1 _d1;
	T2 _d2;
};
template<class T1>
class Data < T1, int >
{
public:
	Data()
	{
		cout << "Data<T1,int>" << endl;
	}
private:
	T1 _d1;
	int _d2;
};
template<typename T1,typename T2>
class Data//< T1, T2 >
{
public:
	Data()
	{
		cout << "Data<T1*,T2*>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};
template<typename T1,typename T2>
class Data < T1&, T2& >
{
public:
	Data(const T1& d1, const T2& d2)
		:_d1(d1)
		, _d2(d2)
	{
		cout << "Data<T1&,T2&>" << endl;
	}
private:
	const T1& _d1;
	const T2& _d2;
};
void test2()
{
	Data<double, int>d1;
	Data<int, double>d2;
	Data<int*, int*>d3;
	Data<int&, int&>d4(1, 2);
}
template<class T>
/*void Copy(T* dst, const T* src, size_t size)
{
	memcpy(dst, src, sizeof(T)*size);
	cout << sizeof(T) << endl;
}*/
/*void Copy(T* dst, const T* src, size_t size, bool IsPODType)
{
	if (ISPODType)
		memcpy(dst, src, sizeof(T)*size);
	else
	{
		for (size_t i = 0; i < size; ++i)
		{
			dst[i] = src[i];
		}
	}
}
bool IsPODType(const char* strType)
{
	const char* arrType[] = { "char", "short", "int", "long", "long long", "float", "double", "long double" };
	for (size_t i = 0; i < sizeof(arrType) / sizeof(arrType[0]); ++i)
	{
		if (0 == strcmp(strType, arrType[i]))
			return true;
	}
	return false;
}
template<class T>
void Copy(T* dst, const T* src, size_t size)
{
	if (IsPODType(typeid(T).name()))
		memcpy(dst, src, sizeof(T)*size);
	else
	{
		for (size_t i = 0; i < size; ++i)
		{
			dst[i] = src[i];
		}
	}
}
struct TrueType
{
	static bool Get()
	{
		return true;
	}
};
struct FalseType
{
	static bool Get()
	{
		return false;
	}
};
template<class T>
struct TypeTraits
{
	typedef FalseType IsPODType;
};
template<>
struct TypeTraits < char >
{
	typedef TrueType IsPODType;
};
template<>
struct TypeTraits < short >
{
	typedef TrueType IsPODType;
};
template<>
struct TypeTraits < int >
{
	typedef TrueType IsPODType;
};
template<>
struct TypeTraits < long >
{
	typedef TrueType IsPODType;
};
template<class T>
void Copy(T* dst, const T* src, size_t size)
{
	if (TypeTraits<T>::IsPODType::Get())
		memcpy(dst, src, sizeof(T)*size);
	else
	{
		for (size_t i = 0; i < size; ++i)
			dst[i] = src[i];
	}
}*/

int main()
{
	Add(1, 2);
	Add(1.0, 2.0);
	/*int a1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int a2[10];
	Copy(a2, a1, 10);

	string s1[] = { "1111", "2222", "3333", "4444" };
	string s2[4];
	Copy(s2, s1, 4);

	/*string strarr1[3] = { "11", "22", "33" };
	string strarr2[3];
	Copy(strarr2, strarr1, 3);
	//test2();
	//TestVector();
	//Test();
	/*int ar[] = { 1, 2, 3 };
	bite::array<int>a1(ar, 3);
	cout <<a1.empty() << endl;
	cout << a1.operator[](2) << endl;*/
	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


template<class T>
class DFDef
{
public:
	void operator()(T*& p)
	{
		if (p)
		{
			delete p;
			p = nullptr;
		}
	}
};

template<class T>
class Free
{
public:
	void operator()(T*& p)
	{
		if (p)
		{
			free(p);
			p = nullptr;
		}
	}
};


class FClose
{
public:
	void operator()(FILE*& p)
	{
		if (p)
		{
			fclose(p);
			p = nullptr;
		}
	}
};

namespace bite
{
	template<class T, class DF = DFDef<T>>
	class unique_ptr
	{
	public:
		 
		unique_ptr(T* ptr = nullptr)
			: _ptr(ptr)
		{}

		~unique_ptr()
		{
			if (_ptr)
			{
				 
				DF df;
				df(_ptr);
				_ptr = nullptr;
			}
		}

		 
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		unique_ptr(const unique_ptr<T>&) = delete;   
		unique_ptr<T>& operator=(const unique_ptr<T>&) = delete;

	private:
		T* _ptr;
	};
}

void TestUniquePtr()
{
	bite::unique_ptr<int> up1(new int);
	bite::unique_ptr<int, Free<int>> up2((int*)malloc(sizeof(int)));
	bite::unique_ptr<FILE, FClose> up3(fopen("1.txt", "w"));
}

int main()
{
	TestUniquePtr();
	return 0;
}
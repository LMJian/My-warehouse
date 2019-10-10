#include<iostream>
using namespace std;

/*template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}

int Add(int left, int right)
{
	return left + right;
}
/*template<class T>
T Add(T left, T right)
{
	return left + right;
}
template<class T1,class T2>
T1 Add(T1 left, T2 right)
{
	return left + right;
}*/
template<class T>
class Vector
{
public:
	Vector(size_t capacity=10)
		:_pData(new T[capacity])
		, _size(0)
		, _capacity(capacity)
	{}
	~Vector();
	void PushBack(const T& data);
	void PopBack();

	size_t Size()
	{
		return _size;
	}
	T& operator[](size_t pos)
	{
		assert(pos < _size);
		return _pData[pos];
	}
private:
	T* _pData;
	size_t _size;
	size_t _capacity;
};
template <class T>
Vector<T>::~Vector()
{
	if (_pData)
		delete[] _pData;
	_size = _capacity = 0;
}
int main()
{
	Vector<int> s1(2);
	Vector<double> s2(9);
	/*Add(1, 2);//调用非函数模板类型，不需要实例化
	Add(1, 2.0);//实例化函数模板
	/*Add(1, 2);
	Add<int>(1, 2);
	/*int a1 = 10, a2 = 20;
	double d1 = 10.0, d2 = 20.0;
	Add(a1, a2);
	Add(d1, d2);
	//Add(a1, d1);两个参数类型不能不同
	Add(a1, (int)d1);//强转可以解决
	Add<int>(a1, d1);//显式实例化*/

	system("pause");
	return 0;
}
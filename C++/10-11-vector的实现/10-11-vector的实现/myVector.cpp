#include<iostream>
using namespace std;
#include<assert.h>
template<class T>
class vector
{
	
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	vector()
		:_start(nullptr)
		,_finish(nullptr)
		,_endOfStorage(nullptr)
	{}
	vector(int num, const T& val=T())
		:_start(new T[num])
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	{
		_finish = _start;
		for (size_t i = 0; i < num; i++)
			*_finish++ = val;
		_endOfStorage = _finish;
	}
	vector(const vector<T>& from)
		:_start(new T[from.capacity()])
		,_finish(nullptr)
		,_endOfStorage(nullptr)
	{
		size_t cap = from.capacity();
		iterator it = from.begin();
		_finish = _start;
		while (it != from.end())
			*_finish++ = *it++;
		_endOfStorage = _start + cap;
	}
	template<class Iterator>
	vector(Iterator start, Iterator end)
		:_start(nullptr)
		,_finish(nullptr)
		,_endOfStorage(nullptr)
	{
		size_t num = 0;
		auto it = start;
		while (it != end)
		{
			it++;
			num++;
		}
		_start = new T[num];
		for (size_t i = 0; i < num; i++)
		{
			_start[i] = *start++;
		}
			//*_finish++ = *start++;
		_finish = _start + num;
		_endOfStorage = _finish;
	}
	
	vector<T>& operator=(vector<T> v)
	{
		swap(v._start,_start);
		swap(v._finish, _finish);
		swap(v._endOfStorage, _endOfStorage);
		return *this;
	}
	~vector()
	{
		if (_start)
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}
	}
	void reserve(size_t newcapacity)
	{
		if (capacity() < newcapacity)
		{
			T* tmp = new T[newcapacity];
			size_t oldSize = size();
			for (size_t i = 0; i < oldSize; i++)
				tmp[i] = _start[i];	
			if (_start)
				delete[] _start;
			_start = tmp;
			_finish = _start + oldSize;
			_endOfStorage = _start + newcapacity;
		}
	}
	void resize(size_t n,const T& value=T())
	{
		if (n > size())
		{
			if (n > capacity())
			{
				int max = n > 2 * capacity() + 1 ? n : 2 * capacity() + 1;
				reserve(max);
			}
			size_t addsize = n - size();
			for (size_t i = 0; i < addsize; i++)
				*_finish++ = value;
		}
		_finish = _start + n;
	}
	T& operator[](size_t index)
	{
		assert(index < size());
		return _start[index];
	}
	const T& operator[](size_t index)const
	{
		assert(index < size());
		return _start[index];
	}
	T& front()
	{
		return *_start;
	}
	const T& front()const
	{
		return *_start;
	}
	T& back()
	{
		return *(_finish-1);
	}
	const T& back()const
	{
		return *(_finish - 1);
	}
	void push_back(const T& value)
	{
		if (_finish == _endOfStorage)
			reserve(2 * capacity() + 1);
		*_finish++ = value;
	}
	void pop_back()
	{
		if (_finish != _start)
			_finish--;
	}
	iterator insert(iterator pos, const T& value)
	{
		assert(pos <= end());
		if (_finish == _endOfStorage)
		{
			size_t size = pos - _start;
			reserve(2 * capacity() + 1);
			pos = _start + size;
		}
		auto it = end() - 1;
		while (it >= pos)
		{
			*(it+1) = *it;
			it--;
		}
		*pos = value;
		_finish++;
		return pos;
	}
	iterator erase(iterator pos)
	{
		assert(pos < end());
		auto it = pos + 1;
		while (it != end())
		{
			*(it - 1) = *it;
			it++;
		}
		_finish--;
		return pos;
	}
	void clear()
	{
		_finish = _start;
	}
	size_t capacity()const
	{
		return _endOfStorage - _start;
	}
	size_t size()const
	{
		return _finish - _start;
	}
	iterator begin()
	{
		return  _start;
	}
	iterator end()
	{
		return _finish;
	}
private:
	iterator _start; 
	iterator _finish; 
	iterator _endOfStorage;
};

void TestVector()
{
	vector<int> v1;
	vector<int> v2(10, 5);

	int array[] = { 1, 2, 3, 4, 5 };
	vector<int> v3(array, array + sizeof(array) / sizeof(array[0]));

	cout << v2.size() << endl;
	cout << v2.capacity() << endl;
	cout << v3.front() << endl;
	cout << v3.back() << endl;

	for (size_t i = 0; i < v3.size(); ++i)
		cout << v3[i] << " ";
	cout << endl;

	//bite::vector<int>::iterator it = v3.begin();
	auto it = v3.begin();
	while (it != v3.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto& e : v3)
		e *= 2;

	for (auto e : v3)
		cout << e << " ";
	cout << endl;
}


void TestVector2()
{
	vector<int> v;
	v.push_back(1);  // 3
	v.push_back(2);
	v.push_back(3);
	v.push_back(4); // 9
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	cout << v.back() << endl;

	v.pop_back();
	cout << v.back() << endl;
	cout << v.size() << endl;

	cout << v.front() << endl;
	v.insert(v.begin(), 0);
	cout << v.front() << endl;
	cout << v.size() << endl;
}


void TestVector3()
{
	vector<int> vv;
	vector<int> v(10, 5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(8);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(20, 5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}

int main()
{
	TestVector();
	TestVector2();
	TestVector3();
	return 0;
}
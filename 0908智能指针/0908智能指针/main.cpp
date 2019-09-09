#include<iostream>
#include<vector>
#include<memory>
#include<thread>
#include<mutex>
using namespace std;

/*void _MergeSort(int *a, int left, int right, int *tmp)
{
	if (left >= right)
		return;
	int mid = left + ((right - left) >> 1);
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1&&begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	while (begin1 <= end1)
		tmp[index++] = a[begin1++];
	while (begin2 <= end2)
		tmp[index++] = a[begin2++];
	memcpy(a + left, tmp + left, sizeof(int)*(right - left + 1));
}
void MergeSort(int* a, int n)
{
	int *tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n - 1, tmp);

	//vector<int>v(1000000000, 10);

}*/
/*template<class T>
class SmartPtr{
public:
	SmartPtr(T* ptr=nullptr)
		:_ptr(ptr)
	{}
	~SmartPtr()
	{
		if (_ptr)
			delete []_ptr;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
};

void MergeSort(int *a, int n)
{
	int *tmp = (int*)malloc(sizeof(int)*n);
	SmartPtr<int>sp(tmp);
	vector<int>v(1000000000, 10);
}
void test(int *arr)
{
	SmartPtr<int>spl(arr);
}
class Date
{
public:
	Date(){ cout << "Date()" << endl; }
	~Date(){ cout << "~Date()" << endl; }

	int _year;
	int _month;
	int _day;
};
/*template<class T>
class Autoptr
{
public:
	Autoptr(T* ptr=NULL)
		:_ptr(ptr)
	{}
	~Autoptr()
	{
		if (_ptr)
			delete _ptr;
	}
	Autoptr(Autoptr<T>& ap)
		:_ptr(ap._ptr)
	{
		ap._ptr = NULL;//置空
	}
	Autoptr<T>& operator=(Autoptr<T>& ap)
	{
		if (this != &ap)
		{
			if (_ptr)
				delete _ptr;//把原先的空间释放
			_ptr = ap._ptr;
			ap._ptr = NULL;//置空
		}
		return *this;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
};*/
/*template<class T>
class UniquePtr
{
public:
	UniquePtr(T* ptr=nullptr)
		:_ptr(ptr)
	{}
	~UniquePtr()
	{
		if (_ptr)
			delete _ptr;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
//private:
	//UniquePtr(UniquePtr<T>const&);
	//UniquePtr& operator=(UniquePtr<T>const&);

	UniquePtr(UniquePtr<T>const &) = delete;//删除此函数
	UniquePtr& operator=(UniquePtr<T>const&) = delete;
private:
	T* _ptr;
};
template<class T>
class SharedPtr
{
public:
	SharedPtr(T* ptr = nullptr)
		:_ptr(ptr)
		, _pRefCount(new int(1))
		, _pMutex(new mutex)
	{}
	~SharedPtr()
	{
		Release();
	}
	SharedPtr(const SharedPtr<T>& sp)
		:_ptr(sp._ptr)
		, _pRefCount(sp._pRefCount)
		, _pMutex(sp._pMutex)
	{
		//AddRefCount();
	}
	SharedPtr<T>& operator=(const SharedPtr<T>& sp)
	{
		if (_ptr != sp._ptr)
		{
			Release();//释放当前管理资源
			//共同管理sp的资源
			_ptr = sp._ptr;
			_pRefCount = sp._pRefCount;
			_pMutex = sp._pMutex;

			AddRefCount();
		}
		return *this;
	}
	T& operator* ()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
	int UseCount()
	{
		return *_pRefCount;
	}
	T* Get()
	{
		return _ptr;
	}
	/*void AddRefCount()
	{
		_pMutex->lock();
		++(*_pRefCount);
		_pMutex->unlock();
	}
private:
	void Release()
	{
		bool deleteflag = false;
		(*_pMutex).lock();
		if (--(*_pRefCount) == 0)
		{
			delete _ptr;
			delete _pRefCount;
			deleteflag = true;
		}
		(*_pMutex).unlock();

		if (deleteflag == true)
			delete _pMutex;
	}

private:
	int *_pRefCount;//引用计数
	T* _ptr;        //指向管理资源的指针
	mutex* _pMutex; // 互斥锁
};
void SharePtrFunc(SharedPtr<Date>& sp, size_t n)
{
	cout << sp.Get() << endl;
	for (size_t i = 0; i < n; i++)
	{
		SharedPtr<Date>copy(sp);
		copy->_year++;
		copy->_month++;
		copy->_day++;
	}
}
struct ListNode
{
	int _data;
	weak_ptr<ListNode>_prev;
	weak_ptr<ListNode>_next;

	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}
};

template<class T>
struct FreeFunc{
	void operator()(T* ptr)
	{
		cout << "free:" << ptr << endl;
		free(ptr);
	}
};
template<class T>
struct DeleteArrayFunc{
	void operator()(T* ptr)
	{
		cout << "delete[]" << ptr << endl;
		delete[] ptr;
	}
};*/
template<class Mutex>
class LockGuard
{
public:
	LockGuard(Mutex& mtx)
		:_mutex(mtx)
	{
		_mutex.lock();
	}
	~LockGuard()
	{
		_mutex.unlock();
	}
	LockGuard(const LockGuard<Mutex>&) = delete;
private:
	Mutex& _mutex;
};
mutex mtx;
static int n = 0;
void Func()
{
	for (size_t i = 0; i < 1000000; ++i)
	{
		LockGuard<mutex>lock(mtx);
		++n;
	}
}
int main()
{
	int begin = clock();
	thread t1(Func);
	thread t2(Func);

	t1.join();
	t2.join();

	int end = clock();

	cout << n << endl;
	cout << "const time:" << end - begin << endl;
	/*FreeFunc<int>freeFunc;
	shared_ptr<int>sp1((int*)malloc(4), freeFunc);

	DeleteArrayFunc<int>deleteArrayFunc;
	shared_ptr<int>sp2((int*)malloc(4), deleteArrayFunc);

	/*shared_ptr<ListNode>node1(new ListNode);
	shared_ptr<ListNode>node2(new ListNode);
	cout << node1.use_count() << endl;
	cout << node2.use_count() << endl;

	node1->_next = node2;
	node2->_prev = node1;

	cout << node1.use_count() << endl;
	cout << node2.use_count() << endl;

	/*SharedPtr<Date>p(new Date);
	cout << p.Get() << endl;

	const size_t n = 100;
	thread t1(SharePtrFunc, p, n);
	thread t2(SharePtrFunc, p, n);

	t1.join();
	t2.join();

	cout << p->_year << endl;
	cout << p->_month << endl;
	cout << p->_day << endl;

	/*SharedPtr<int>sp1(new int(10));
	SharedPtr<int>sp2(sp1);
	*sp2 = 20;
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;

	SharedPtr<int>sp3(new int(10));
	sp2 = sp3;
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;
	cout << sp3.UseCount() << endl;

	sp1 = sp3;
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;
	cout << sp3.UseCount() << endl;
	/*shared_ptr<Date>sp(new Date);
	//shared_ptr<Date>copy(sp);

	cout << "ref count:" << sp.use_count() << endl;
	//cout << "ref count:" << copy.use_count() << endl;
	/*UniquePtr<Date>ap(new Date);
	UniquePtr<Date>copy(ap);
	//ap->
	/*Autoptr<Date>ap(new Date);
	Autoptr<Date>copy(ap);
	ap->_year = 2018;
	/*auto_ptr<Date>ap(new Date);
	auto_ptr<Date>copy(ap);

	ap->_year = 2018;
	/*int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 90 };
	test(arr);
	/*SmartPtr<int>sp1(new int);
	sp1.operator*() = 20;
	*sp1 = 10;
	cout << *sp1 << endl;

	SmartPtr<Date>sparray(new Date);

	sparray.operator->()->_year = 2019;
	sparray->_year = 2018;
	sparray->_month = 1;
	sparray->_day = 1;
	/*try{
		int a[5] = { 4, 5, 2, 3, 1 };
		MergeSort(a, 5);
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
	/*int a[5] = { 4, 5, 2, 3, 1 };
	MergeSort(a, 5);*/

	system("pause");
	return 0;
}
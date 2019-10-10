#include<iostream>
#include<thread>
#include <mutex>
#include <memory>
using namespace std;

/*class Date
{
public:
	Date() { cout << "Date()" << endl; }
	~Date(){ cout << "~Date()" << endl; }

	int _year;
	int _month;
	int _day;
};

template <class T>
class SharedPtr
{
public:
	SharedPtr(T* ptr = nullptr)
		: _ptr(ptr)
		, _pRefCount(new int(1))
		, _pMutex(new mutex)
	{}

	~SharedPtr() { Release(); }

	SharedPtr(const SharedPtr<T>& sp)
		: _ptr(sp._ptr)
		, _pRefCount(sp._pRefCount)
		, _pMutex(sp._pMutex)
	{
		AddRefCount();
	}

	// sp1 = sp2    
	SharedPtr<T>& operator=(const SharedPtr<T>& sp)
	{
		//if (this != &sp)        
		if (_ptr != sp._ptr)
		{
			// 释放管理的旧资源            
			Release();

			// 共享管理新对象的资源，并增加引用计数            
			_ptr = sp._ptr;
			_pRefCount = sp._pRefCount;
			_pMutex = sp._pMutex;

			AddRefCount();
		}

		return *this;
	}

	T& operator*() { return *_ptr; }
	T* operator->() { return _ptr; }

	int UseCount() { return *_pRefCount; }
	T* Get() { return _ptr; }

	void AddRefCount()
	{
		// 加锁或者使用加1的原子操作        
		_pMutex->lock();
		++(*_pRefCount);
		_pMutex->unlock();
	}
private:
	void Release()
	{
		bool deleteflag = false;
		// 引用计数减1，如果减到0，则释放资源        
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
	int* _pRefCount; // 引用计数    
	T*   _ptr;       // 指向管理资源的指针       
	mutex* _pMutex;      // 互斥锁
};

void SharePtrFunc(SharedPtr<Date>& sp, size_t n)
{
	cout << sp.Get() << endl;
	for (size_t i = 0; i < n; ++i)
	{
		// 这里智能指针拷贝会++计数，智能指针析构会--计数，这里是线程安全的。        
		SharedPtr<Date> copy(sp);

		// 这里智能指针访问管理的资源，不是线程安全的。所以我们看看这些值两个线程++了2n次，但是最 终看到的结果，并一定是加了2n        
		copy->_year++;
		copy->_month++;
		copy->_day++;
	}
}

int main()
{
	SharedPtr<Date> p(new Date);
	cout << p.Get() << endl;

	const size_t n = 100;
	thread t1(SharePtrFunc, p, n);
	thread t2(SharePtrFunc, p, n);

	t1.join();
	t2.join();

	cout << p->_year << endl;
	cout << p->_month << endl;
	cout << p->_day << endl;

	system("pause");
	return 0;
}*/
/*#include <thread> 
#include <mutex>

// C++11的库中也有一个lock_guard，下面的LockGuard造轮子其实就是为了学习他的原理 
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
	// 注意这里必须使用引用，否则锁的就不是一个互斥量对象    
	Mutex& _mutex;
};

mutex mtx;
static int n = 0;

void Func()
{
	for (size_t i = 0; i < 1000000; ++i)
	{
		LockGuard<mutex> lock(mtx);
		++n;
	}
}
typedef int(*FUNC)();
int DoSomething(int i)
{
	cout << "DoSomething" << endl;
	return 0;
}

void Test()
{
	//     
	// reinterpret_cast可以编译器以FUNC的定义方式去看待DoSomething函数     
	// 所以非常的BUG，下面转换函数指针的代码是不可移植的，所以不建议这样用     
	// C++不保证所有的函数指针都被一样的使用，所以这样用有时会产生不确定的结果     
	//     
	FUNC f = DoSomething;
	f();
}
int main()
{
	Test();
	/*int begin = clock();
	thread  t1(Func);
	thread  t2(Func);

	t1.join();
	t2.join();

	int end = clock();

	cout << n << endl;
	cout << "cost time:" << end - begin << endl;
	system("pause");
	return 0;
}
class A 
{ 
public:     
	virtual void f(){} 
};

class B : public A {};

void fun(A* pa) {   
	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回   
	B* pb1 = static_cast<B*>(new A());
	B* pb2 = dynamic_cast<B*>(pa);      
	cout<<"pb1:" <<pb1<< endl;   
	cout<<"pb2:" <<pb2<< endl; 
}
int main() 
{ 
	A a;     
	B b;     
	fun(&a);     
	fun(&b);     
	system("pause");
	return 0; 
}*/
class A
{
public:
	virtual void test()
	{
		cout << "A-test" << endl;
	}
	void test2()
	{
		cout << "A-test2" << endl;
	}
	void test3()
	{
		cout << "A-test3" << endl;
	}
	/*A(int a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& a)
	{
		cout << "A(const A& a)" << endl;
	}
private:
	int _a*/
};
class B:public A
{
public:
	virtual void test()
	{
		cout << "B-test" << endl;
	}
	void test1()
	{
		cout << "B-test1" << endl;
	}
	void test2()
	{
		cout << "B-test2" << endl;
	}
};
int main()
{
	B *pa = static_cast<B*>(new A());
	pa->test1();
	pa->test2();
	pa->test3();
	//A a1(1);

	// 隐式转换-> A tmp(1); A a2(tmp);     
	//A a2 = 1;
	system("pause");
	return 0;
}

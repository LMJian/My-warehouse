#if 0
// 1 
// 2
namespace bite
{
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			: _ptr(ptr)
			, _pCount(nullptr)
		{
			if (_ptr)
				_pCount = new int(1);
		}

		~shared_ptr()
		{
			if (_ptr && 0 == --*_pCount)
			{
				delete _ptr;
				delete _pCount;
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

		shared_ptr(const shared_ptr<T>& sp)
			: _ptr(sp._ptr)
			, _pCount(sp._pCount)
		{
			if (_ptr)
				++*_pCount;
		}

		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (this != &sp)
			{
				// 1. 与旧资源断开联系
				// this现在不是用自己的资源，要与sp对象共享资源
				if (_ptr && 0 == --*_pCount)
				{
					// 当前对象是最后一个使用资源的对象
					delete _ptr;
					delete _pCount;
				}

				// 2. 与sp共享资源及计数
				_ptr = sp._ptr;
				_pCount = sp._pCount;
				if (_ptr)
					++*_pCount;

			}

			return *this;
		}

		int use_count()
		{
			return *_pCount;
		}

	private:
		T* _ptr;
		int* _pCount;
	};
}


void TestShradPtr()
{
	bite::shared_ptr<int> sp1(new int);
	cout << sp1.use_count() << endl;

	bite::shared_ptr<int> sp2(sp1);
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;


	bite::shared_ptr<int> sp3(new int);
	cout << sp3.use_count() << endl;

	bite::shared_ptr<int> sp4(sp3);
	cout << sp3.use_count() << endl;
	cout << sp4.use_count() << endl;

	sp3 = sp2;
	cout << sp2.use_count() << endl;
	cout << sp3.use_count() << endl;

	sp4 = sp2;
	cout << sp2.use_count() << endl;
	cout << sp4.use_count() << endl;
}


int main()
{
	TestShradPtr();
	return 0;
}
#endif


#if 0
// 定制删除器：让用户可以控制资源具体的释放操作
// 不是线程安全的

// 进程：公司
// 线程：员工
#include <mutex>

template<class T>
class DFDef
{
public:
	void operator()(T*& ptr)
	{
		if (ptr)
		{
			delete ptr;
			ptr = nullptr;
		}
	}
};

namespace bite
{
	template<class T, class DF = DFDef<T>>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			: _ptr(ptr)
			, _pCount(nullptr)
			, _pMutex(nullptr)
		{
			if (_ptr)
			{
				_pCount = new int(1);
				_pMutex = new mutex;
			}

		}

		~shared_ptr()
		{
			Release();
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		shared_ptr(const shared_ptr<T>& sp)
			: _ptr(sp._ptr)
			, _pCount(sp._pCount)
			, _pMutex(sp._pMutex)
		{
			AddRef();
		}

		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (this != &sp)
			{
				// 1. 与旧资源断开联系
				// this现在不是用自己的资源，要与sp对象共享资源
				Release();

				// 2. 与sp共享资源及计数
				_ptr = sp._ptr;
				_pCount = sp._pCount;
				if (_ptr)
					AddRef();
			}

			return *this;
		}

		int use_count()
		{
			return *_pCount;
		}

	private:
		void AddRef()
		{
			if (_pCount)
			{
				_pMutex->lock(); // 加锁
				++*_pCount;
				_pMutex->unlock();// 解锁
			}
		}

		int SubRef()
		{
			if (_pCount)
			{
				_pMutex->lock(); // 加锁
				--*_pCount;
				_pMutex->unlock();// 解锁
			}

			return *_pCount;
		}

		void Release()
		{
			if (_ptr && 0 == SubRef())
			{
				// 当前对象是最后一个使用资源的对象
				DF()(_ptr);
				delete _pCount;
			}
		}

	private:
		T* _ptr;
		int* _pCount;
		mutex* _pMutex;
	};
}

struct Date
{
	Date()
	{
		_year = _month = _day = 0;
	}

	int _year;
	int _month;
	int _day;
};

// 1. shared_ptr的引用计数是否安全---mutex
// 2. shared_ptr所管理的用户数据是否是线程安全
void SharePtrFunc(bite::shared_ptr<Date>& sp, size_t n)
{
	for (size_t i = 0; i < n; ++i)
	{
		bite::shared_ptr<Date> copy(sp);

		copy->_year++;
		copy->_month++;
		copy->_day++;
	}
}

#include <thread>

int main()
{
	bite::shared_ptr<Date> sp(new Date);

	thread t1(SharePtrFunc, sp, 100000);
	thread t2(SharePtrFunc, sp, 100000);

	t1.join();
	t2.join();
	return 0;
}
#endif

#include <memory>

// struct ListNode
// {
// 	ListNode* _pPre;
// 	ListNode* _pNext;
// 	int _data;
// };

struct ListNode
{
	ListNode(int data = 0)
		: pre(nullptr)
		, next(nullptr)
		, _data(data)
	{
		cout << "ListNode(int):" << this << endl;
	}

	~ListNode()
	{
		cout << "~ListNode():" << this << endl;
	}

	shared_ptr<ListNode> pre;
	shared_ptr<ListNode> next;
	int _data;
};

void TestListNode()
{
	shared_ptr<ListNode> sp1(new ListNode(10));
	shared_ptr<ListNode> sp2(new ListNode(20));

	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;

	sp1->next = sp2;
	sp2->pre = sp1;

	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;
}

int main()
{
	TestListNode();
	return 0;
}

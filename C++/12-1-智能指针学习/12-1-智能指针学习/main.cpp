#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

namespace LMJian {

	template<class T>
	class DFDef {
	public:
		void operator()(T*& _ptr) {
			delete _ptr;
			_ptr = nullptr;
		}
	};

	template<class T, class DF = DFDef<T>>
	class shared_ptr {
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _ret(nullptr)
			, _mutex(nullptr)
		{
			if (_ptr) {
				_ret = new int(1);
				_mutex = new mutex;
			}
		}
		~shared_ptr() {
			Release();
		}
		shared_ptr(const shared_ptr<T>& ptr)
			:_ptr(ptr._ptr)
			, _ret(ptr._ret)
			, _mutex(ptr._mutex)
		{
			if (_ret)
				AddRef();
		}
		shared_ptr<T>& operator=(const shared_ptr<T>& ptr) {
			if (this != &ptr) {
				Release();

				_ptr = ptr._ptr;
				_ret = ptr._ret;
				_mutex = ptr._mutex;
				if (_ret) {
					AddRef();
				}
			}
			return *this;
		}
		T& operator *() {
			return *_ptr;
		}
		T* operator ->() {
			return _ptr;
		}
		int use_count()
		{
			return *_ret;
		}
	private:
		void Release() {
			if (_ptr && 0 == SubRef()) {
				DF()(_ptr);
				delete _ret;
				delete _mutex;
			}
		}
		void AddRef() {
			if (_ret)
			{
				_mutex->lock();
				++*_ret;
				_mutex->unlock();
			}
		}
		int SubRef() {
			if (_ret) {
				_mutex->lock();
				--*_ret;
				_mutex->unlock();
			}
			return *_ret;
		}
		T* _ptr;
		int* _ret;
		mutex* _mutex;
	};

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

	class Test {
	public:
		Test() {
			_int = new int(1);
		}
		~Test() {
			free(_int);
		}
	private:
		int* _int;
	};

#if 0
	/*void test_shared_ptr()
	{
		//Test arr[10];
		LMJian::shared_ptr<Test> sp1(new Test[10]);

		/*LMJian::shared_ptr<int> sp1(new int);
		cout << sp1.use_count() << endl;

		LMJian::shared_ptr<int> sp2(sp1);
		cout << sp1.use_count() << endl;
		cout << sp2.use_count() << endl;


		LMJian::shared_ptr<int> sp3(new int);
		cout << sp3.use_count() << endl;

		LMJian::shared_ptr<int> sp4(sp3);
		cout << sp3.use_count() << endl;
		cout << sp4.use_count() << endl;

		sp3 = sp2;
		cout << sp2.use_count() << endl;
		cout << sp3.use_count() << endl;

		sp4 = sp2;
		cout << sp2.use_count() << endl;
		cout << sp4.use_count() << endl;
	}*/
#endif

	void SharePtrFunc(shared_ptr<Date>& sp, size_t n)
	{
		for (size_t i = 0; i < n; ++i)
		{
			shared_ptr<Date> copy(sp);

			copy->_year++;
			copy->_month++;
			copy->_day++;
		}
	}
}
	struct ListNode {
		ListNode(int ret)
			:_ret(ret)
		{
			cout << "ListNode" << endl;
		}
		~ListNode() {
			cout << "~ListNode" << endl;
		}
		//LMJian::shared_ptr<ListNode> _pre;
		//LMJian::shared_ptr<ListNode> _next;
		weak_ptr<ListNode> _pre;
		weak_ptr<ListNode> _next;
		int _ret;
	};

	void testlist()
	{
		shared_ptr<ListNode> sp1(new ListNode(10));
		shared_ptr<ListNode> sp2(new ListNode(20));

		cout << sp1.use_count() << endl;
		cout << sp2.use_count() << endl;

		sp1->_next = sp2;
		sp2->_pre = sp1;

		cout << sp1.use_count() << endl;
		cout << sp2.use_count() << endl;
	}

int main() {
	testlist();
	//weak_ptr<int> p1(nullptr);
	//weak_ptr<int> p2(new int);
	weak_ptr<int> p3;
	/*shared_ptr<Date> sp(new Date);

	thread t1(SharePtrFunc, sp, 10000);
	thread t2(SharePtrFunc, sp, 10000);

	t1.join();
	t2.join();

	//cout << (sp->_day) << " " << (sp->_month) << " " << (sp->_year) << endl;*/


	system("pause");
	return 0;
}
#include<iostream>
using namespace std;

/*#include<list>
/*void TestList2()
{
	list<int> L;
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);
	L.push_back(4);

	cout << L.size() << endl;

	L.push_front(0);
	cout << L.front() << endl;

	L.pop_front();
	cout << L.front() << endl;

	L.pop_back();
	cout << L.back() << endl;

	// 1   2    3
	auto it = find(L.begin(), L.end(), 2);
	if (it != L.end())
		L.insert(it, 5);

	L.erase(it);
}
template<class T>
bool IsOdd(T data)
{
	if (0 == data % 2)
		return true;
	return false;
}

void TestList3()
{
	list<int> L{ 9,1,2,2,3,4,2 };
	for (auto e : L)
		cout << e << " ";
	cout << endl;

	// 删除所有2
	//L.remove(2);

	// 删除L中所有的偶数
	// remove_if：删除所有满足条件的节点
	// 条件：就是该函数的参数
	// 该函数的实现原理：对每个节点中的值域用参数条件进行验证，如果满足则删除，如果不满足什么都不做
	L.remove_if(IsOdd);
}

void TestList4()
{
	list<int> L{ 9, 1, 2, 2, 3, 4, 2 };
	//L.sort();
	L.unique();
}
void TestListIterator()
{
	list<int> L{ 1, 2, 3, 4 };
	auto it = L.begin();

	// erase之后，it所指向的节点已经被删除掉了
	// it迭代器失效
	L.erase(it);

	// 解决方法: 给迭代器重新赋值
	//it = L.begin();
	while (it != L.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}*/
namespace bite
{
	template<class T>
	struct Node
	{
		Node(const T& data = T())
			:_pNext(nullptr)
			, _pPre(nullptr)
			, _data(data)
		{}
		T _data;
		Node<T> *_pNext;
		Node<T> *_pPre;
	};

	template<class T>
	class list_iterator
	{
		typedef Node<T> Node;
		typedef list_iterator<T> shef;
	public:
		list_iterator(Node *ptr)
			:_ptr(ptr)
		{}
		T& operator *()
		{
			return _ptr->_data;
		}
		T* operator ->()
		{
			return &(_ptr->_data);
		}
		shef& operator ++()
		{
			_ptr = _ptr->_pNext;
			return *this;
		}
		shef operator ++(T)
		{
			shef tmp(*this);
			//shef tmp(_ptr);
			_ptr = _ptr->_pNext;
			return tmp;
		}
		shef& operator --()
		{
			_ptr = _ptr->_pPre;
			return *this;
		}
		shef operator --(T)
		{
			shef tmp(_ptr);
			_ptr = _ptr->_pPre;
			return tmp;
		}
		bool operator !=(const shef& it)
		{
			return _ptr != it._ptr;
		}
		bool operator ==(const shef& it)
		{
			return _ptr == it._ptr;
		}
		Node* _ptr;
	};

	template<class iterator, class T>
	struct list_riterator
	{
		typedef Node<T> Node;
		typedef list_riterator<iterator, T> shef;
		list_riterator(Node *ptr)
			:_it(ptr)
		{}
		/*list_riterator(iterator it)
			:_it(it)
		{}*/
		T& operator *()
		{
			auto it = _it;
			--it;
			return *it;
		}
		
		T* operator ->()
		{
			return &(operator *());
		}
		shef& operator ++()
		{
			--_it;
			return *this;
		}
		shef operator ++(T)
		{
			shef tmp(_it._ptr);
			--_it;
			return tmp;
		}
		shef& operator --()
		{
			++_it;
			return *this;
		}
		shef operator --(T)
		{
			shef tmp(_it._ptr);
			++_it;
			return tmp;
		}
		bool operator !=(shef ptr)
		{
			return _it != ptr._it;
		}
		bool operator ==(shef ptr)
		{
			return _it == ptr._it;
		}
		iterator _it;
	};


	template<class T>
	class list
	{
		typedef Node<T> Node;
		typedef list_iterator<T> iterator;
		typedef const list_iterator<T> const_iterator;
		typedef list_riterator<iterator, T> riterator;
	public:
		list()
		{
			CreateHead();
		}
		list(int n, const T& data)
		{
			CreateHead();
			for (int i = 0; i < n; i++)
				push_back(data);
		}
		template<class Iterator>
		list(Iterator first, Iterator last)
		{
			CreateHead();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		list(const list<T>& L)
		{
			CreateHead();
			/*Node *pt = L._pHead->_pNext;
			while (pt != L._pHead)
			{
				push_back(pt->_data);
				pt = pt->_pNext;
			}*/
			iterator it = L.begin();
			while (it != L.end())
			{
				push_back(*it);
				++it;
			}
		}


		// L1 =&L2;
		list<T>& operator=(const list<T>& L)
		{
			if (this != &L)
			{
				clear();
				auto it = L.begin();
				while (it != L.end())
				{
					push_back(*it);
					++it;
				}
			}
			return *this;
		}

		~list()
		{
			clear();
			delete _pHead;
		}

		iterator begin()
		{
			return iterator(_pHead->_pNext);
		}
		iterator begin()const 
		{
			return iterator(_pHead->_pNext);
		}
		iterator end()
		{
			return iterator(_pHead);
		}
		iterator end()const 
		{
			return iterator(_pHead);
		}
		riterator rbegin()
		{
			return riterator(_pHead);
		}
		riterator rend()
		{
			return riterator(_pHead->_pNext);
		}
		size_t size()const
		{
			size_t count = 0;
			auto it = begin();
			while (it != end())
			{
				++it;
				++count;
			}
			return count;
		}

		bool empty()const 
		{
			return _pHead->_pNext == _pHead;
		}
		void resize(int n, const T& data = T())
		{
			int oldsize = size();
			if (n > oldsize)
			{
				for (int i = oldsize; i < n; i++)
					push_back(data);
			}
			else
			{
				for (int i = n; i < oldsize; i++)
					pop_back();
			}
		}
		T& front()
		{
			return _pHead->_pNext->_data;
		}
		const T& front()const
		{
			return _pHead->_pNext->_data;
		}
		T& back()
		{
			return _pHead->_pPre->_data;
		}
		const T& back()const
		{
			return _pHead->_pPre->_data;
		}
		void push_back(const T& data)
		{
			insert(end(), data);
		}
		void clear()
		{
			Node* it = _pHead->_pNext;
			while (it != _pHead)
			{
				_pHead->_pNext = it->_pNext;
				delete it;
				it = _pHead->_pNext;
			}
			_pHead->_pNext = _pHead;
			_pHead->_pPre = _pHead;
		}
		void pop_back()
		{
			erase(--end());
		}
		iterator insert(iterator pos, const T& data)
		{
			Node *node = pos._ptr;
			Node *pt = new Node(data);
			pt->_pPre = node->_pPre;
			pt->_pNext = node;
			node->_pPre = pt;
			pt->_pPre->_pNext = pt;
			return iterator(pt);
		}
		iterator erase(iterator pos)
		{
			Node *pt = pos._ptr;
			if (pt == _pHead)
				return end();
			Node *ret = pt->_pNext;
			pt->_pPre->_pNext = pt->_pNext;
			pt->_pNext->_pPre = pt->_pPre;
			delete pt;
			return iterator(ret);
		}
		void push_front(const T& data)
		{
			insert(begin(), data);
		}
		void pop_front()
		{
			erase(begin());
		}

		void swap(list<T> L)
		{
			swap(_pHead, L._pHead);
		}
	private:
		void CreateHead()
		{
			_pHead = new Node();
			_pHead->_pNext = _pHead;
			_pHead->_pPre = _pHead;
			_pHead->_data = NULL;
		}
	protected:
		Node* _pHead;
	};
}
#include<vector>
void TestList1()
{
	bite::list<int> L1;
	bite::list<int> L2(10, 5);

	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	bite::list<int> L3(v.begin(), v.end());
	
	bite::list<int> L4(L3);
	
	auto it = L2.begin();
	while (it != L2.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : L3)
		cout << e << " ";
	cout << endl;

	auto rit = L4.rbegin();
	while (rit != L4.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}

void TestList2()
{
	bite::list<int> L;
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);
	L.push_back(4);

	cout << L.size() << endl;
	cout << L.front() << endl;
	cout << L.back() << endl;

	L.push_front(0);
	cout << L.size() << endl;
	cout << L.front() << endl;
	cout << L.back() << endl;

	L.pop_front();
	cout << L.size() << endl;
	cout << L.front() << endl;
	cout << L.back() << endl;

	L.pop_back();
	cout << L.size() << endl;
	cout << L.front() << endl;
	cout << L.back() << endl;

	L.clear();
	if (L.empty())
		cout << "clear is OK" << endl;
}

void TestList3()
{

	bite::list<int> L;
	
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);
	bite::list<int> L2(L);

	auto it = L.begin();
	//cout << *it << endl;
	
	auto itt = it++;

	L.resize(10, 5);
	for (auto e : L)
		cout << e << " ";
	cout << endl;

	L.resize(2);
	for (auto e : L)
		cout << e << " ";
	cout << endl;
}

int main()
{
	//TestList1();
	//TestList2();
	TestList3();
	//new int();
	_CrtDumpMemoryLeaks();

	//TestList2();
	//TestList3();
	//TestList4();
	//TestListIterator();

	system("pause");
	return 0;
}
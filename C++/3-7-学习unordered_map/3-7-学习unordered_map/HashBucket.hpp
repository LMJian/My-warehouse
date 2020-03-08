#pragma once
#include"Common.hpp"
#include<vector>

template<class T>
struct HashNode {
	HashNode(const T& data = T())
		:_pNext(nullptr)
		,_data(data)
	{}

	HashNode<T>* _pNext;
	T _data;
};

template<class T, class KOFV, class DF = DFDef<T>>
class HashBucket;

//迭代器
template<class T, class KOFV, class DF = DFDef<T>>
struct HBIterator {
	typedef HashNode<T> Node;
	typedef HBIterator<T, KOFV, DF> Self;
	HBIterator(Node* pNode = nullptr, HashBucket<T, KOFV ,DF>* ht = nullptr)
		:_pNode(pNode)
		, _ht(ht)
	{}
	T& operator*() {
		return _pNode;
	}
	T* operator->() {
		return &(_pNode->_data);
	}
	//能够移动
	Self& operator++() {
		Next();
		return *this;
	}
	//后置++
	Self operator++(int) {
		Self temp = (*this);
		Next();
		return temp;
	}
	//比较
	bool operator!=(Self& s) {
		return _pNode != s._pNode;
	}
	bool operator==(Self& s) {
		return _pNode == s._pNode;
	}

	void Next() {
		if (_pNode->_pNext) {

			_pNode = _pNode->_pNext;
		}
		else {
			//pNode是当前链表中的最后一个节点
			//找node后序的第一个非空桶
			//问题：如何pNode是在哪一个桶中的，知道哈希函数，就能知道pNode的桶号
			size_t bucketNo = _ht->HashFunc(_pNode->_data) + 1;
			for (; bucketNo < _ht->_table.capacity(); ++bucketNo) {
				if (_ht->_table[bucketNo]) {
					//非空桶拿到
					_pNode = _ht->_table[bucketNo];
					return;
				}
			}
			_pNode = nullptr;
		}
	}
	HashNode<T>* _pNode;
	HashBucket<T, KOFV, DF>* _ht;
};


//迭代器如何和类结合
//1.为该类定义迭代器
//2.在类中重新给迭代器命名
//3.增加begin/end

template<class T, class KOFV, class DF>
class HashBucket {
	friend struct HBIterator<T, KOFV, DF>;
	typedef HashNode<T> Node;
	typedef HBIterator<T, DF>iterator;
public:
	HashBucket(size_t capacity = 10)
		:_size(0)
	{
		_table.resize(GetNextPrime(10));
	}
	//插入时，哈希桶中的元素是唯一的
	pair<iterator,bool> insertunique(const T& data) {

		CheckCapacity();
		//通过哈希元素，计算桶号
		size_t bucketNo = HashFunc(data);

		//检测值为data的元素在哈希桶中是否存在
		Node* pCur = _table[bucketNo];
		while (pCur) {
			if (pCur->_data == data)
				return make_pair(iterator(pCur, this), false);
			pCur = pCur->_pNext;
		}
		//插入新节点,采用头插的方式
		pCur = new Node(data);
		pCur->_pNext = _table[bucketNo];
		_table[bucketNo] = pCur;
		++_size;

		//return make_pair(iterator()));
	}
	bool insertEqual(const T& data);

	size_t eraseunique(const T& data) {
		//通过哈希函数计算data所在的桶号
		size_t bucketNo = HashFunc(data);

		//在bucketNo所对应的链表中找值为data的节点
		Node* pCur = _table[bucketNo];
		Node* pPre = nullptr;
		while (pCur) {
			if (pCur->_data == data) {
				//删除pCur节点删除
				if (nullptr == pPre) {
					//删除第一个节点
					_table[bucketNo] = pCur->_pNext;
				}
				else {
					//删除非第一个节点
					pPre->_pNext = pCur->_pNext;
				}
				delete pCur;
				--_size;
				return 1;
			}
			else {
				pPre = pCur;
				pCur = pCur->_pNext;
			}
		}
		return 0;
	}

	bool eraseEqual(const T& data);

	iterator find(const T& data)const {
		//计算data所在的桶号
		size_t bucketNo = HashFunc(data);

		//在bucketNo所对应的链表中找值为data的节点
		Node* pCur = _table[bucketNo];
		while (pCur) {
			if (KOFV()(pCur->_data) == KOFV()(data))
				return iterator(pCur, this);
			pCur = pCur->_pNext;
		}
		return end();
	}
	size_t size()const {
		return _size;
	}
	bool empty()const {
		return 0 == _size;
	}

	iterator begin() {
		//找第一个非空桶
		for (size_t bucket = 0; bucket < _table.capacity(); ++bucket) {
			if (_table[bucket])
				return iterator(_table[bucket], this);
		}
		return end();
	}
	iterator end() {
		return iterator(nullptr, this);
	}

	void clear() {
		for (size_t bucketNo = 0; bucketNo < _table.capacity(); ++bucketNo) {
			Node* cur = _table[bucketNo];
			while (cur) {
				_table[bucketNo] = cur->_pNext;
				delete cur;
				cur = _table[bucketNo];
			}
		}
	}

	size_t bucket_count()const {
		return _table.capacity();
	}
	size_t bucket_size(size_t bucketNo)const {
		if (bucketNo >= bucket_count())
			return 0;

		size_t count = 0;
		Node* cur = _table[bucketNo];
		while (cur) {
			count++;
			cur = cur->_pNext;
		}
		return count;
	}
	//获取key所在的桶号
	size_t bucket(const T& data) {
		return HashFunc(data);
	}

	void PrintHashBucket() {
		for (size_t bucketNo = 0; bucketNo < _table.capacity(); ++bucketNo) {
			Node* pCur = _table[bucketNo];
			std::cout << "_table[" << bucketNo << "]:";
			while (pCur) {
				std::cout << pCur->_data << "--->";
				pCur = pCur->_pNext;
			}
			std::cout << "NULL" << std::endl;
		}
	}
private:
	//扩容
	void CheckCapacity() {
		if (_size == _table.capacity()) {
			HashBucket<T, DF> newHT(GetNextPrime());

			for (size_t bucketNo = 0; bucketNo < _table.capacity(); ++bucketNo) {
				Node* cur = _table[bucketNo];
				while (cur) {
					size_t newBucketNo = newHT.HashFunc(cur->_data);

					_table[bucketNo] = cur->_pNext;

					cur->_pNext=newBT
				}
			}
		}
	}
	size_t HashFunc(const T& data) const {
		return DF()(KOFV()(data)) % _table.capacity();
	}
private:
	std::vector<Node*> _table;
	size_t _size;
};

#include<iostream>
using namespace std;

/*void TestHashBucket() {
	HashBucket<int> ht;
	int array[] = { 1,4,7,9,6,5 };
	for (auto e : array)
		ht.insertunique(e);

	cout << ht.size() << endl;
	ht.PrintHashBucket();

	ht.insertunique(44);
	ht.insertunique(54);

	auto it = ht.begin();
	while (it != ht.end()) {
		cout << *it << endl;
		++it;
	}
	cout << endl;
	ht.PrintHashBucket();

	ht.eraseunique(44);
	if (ht.find(44)) {
		cout << "44 is in hashbucket" << endl;
	}
	else {
		cout << "44 is not in hashbucket" << endl;
	}
	cout << ht.size() << endl;
	ht.PrintHashBucket();
}*/
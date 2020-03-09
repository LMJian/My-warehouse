#pragma once
#include<vector>
#include"Common.hpp"

template<class T>
struct HashNode {
	HashNode(const T& data = T())
		:_pNext(nullptr)
		,_data(data)
	{}
	HashNode<T>* _pNext;
	T _data;              //哈希桶中的键值对
};

template<class T, class KorV, class DF = DFStr>
class HashBucket;

template<class T, class KorV,class DF = DFStr>
struct Iterator {
	typedef HashNode<T> Node;
	typedef Iterator<T, KorV, DF> Self;

	Iterator(Node* pNode = nullptr, HashBucket<T, KorV, DF>* ht = nullptr)
		:_pNode(pNode)
		,_ht(ht)
	{}
	T& operator*() {
		return _pNode->_data;
	}
	T* operator->() {
		return &(_pNode->_data);
	}
	Self& operator++() {
		Next();
		return *this;
	}
	Self operator++(int) {
		Self tmp(_pNode);
		Next();
		return tmp;
	}
	bool operator==(Self& t) {
		return _pNode == t._pNode;
	}
	bool operator!=(Self& t) {
		return _pNode != t._pNode;
	}
	void Next() {
		if (_pNode->_pNext) {
			_pNode = _pNode->_pNext;
		}
		else {
			size_t addr = _ht->HashFunc(_pNode->_data);
			for (int i = addr + 1; i < _ht->_arr.size(); ++i) {
				if (_ht->_arr[i]) {
					_pNode = _ht->_arr[i];
					return;
				}
			}
			_pNode = nullptr;
		}
	}
	Node* _pNode;
	HashBucket<T, KorV, DF>* _ht;
};

template<class T, class KorV, class DF>
class HashBucket {
public:
	typedef HashNode<T> Node;
	typedef HashBucket<T, KorV, DF> Self;
	typedef Iterator<T, KorV, DF> iterator;
	friend struct Iterator<T, KorV, DF>;
public:
	HashBucket(size_t size = 11)
		:_size(0)
	{
		_arr.resize(size);
	}
	~HashBucket() {
		Clear();
	}
	std::pair<iterator, bool> Insert(const T& data) {
		CheckCapacity();

		size_t addr = HashFunc(data);

		//查找是否有重复节点
		Node* ptr = _arr[addr];
		while (ptr) {
			if (KorV()(ptr->_data) == KorV()(data))   
				return make_pair(iterator(ptr, this), false);
			ptr = ptr->_pNext;
		}

		ptr = new Node(data);
		ptr->_pNext = _arr[addr];
		_arr[addr] = ptr;
		++_size;
		return make_pair(iterator(ptr, this), true);
	}
	size_t Erase(const T& data) {
		size_t addr = HashFunc(data);
		Node* ptr = _arr[addr];
		Node* pre = nullptr;
		while (ptr) {
			if (ptr->_data == data) {
				if (!pre) //删除头结点
					_arr[addr] = ptr->_pNext;
				else //删除中间节点
					pre->_pNext = ptr->_pNext;
				delete ptr;
				--_size;
				return 1;
				
			}
			else {
				pre = ptr;
				ptr = ptr->_pNext;
			}
		}
		return 0;
	}
	iterator find(const T& data) const{
		size_t addr = HashFunc(data);
		Node* ptr = _arr[addr];
		while (ptr) {
			if (KorV()(ptr->_data) == KorV()(data))
				return iterator(ptr, this);
			ptr = ptr->_pNext;
		}
		return iterator(nullptr, this);
	}
	size_t size() const{
		return _size;
	}
	bool empty()const {
		return _size == 0;
	}
	iterator begin() {
		for (int i = 0; i < _arr.size(); ++i) {
			if (_arr[i]) {
				return iterator(_arr[i], this);
			}
		}
		return iterator(nullptr, this);
	}
	iterator end() {
		return iterator(nullptr, this);
	}
	void Clear() {
		for (size_t i = 0; i < _arr.size(); ++i) {
			Node* ptr = _arr[i];
			while (ptr) {
				_arr[i] = ptr->_pNext;
				delete ptr;
				ptr = _arr[i];
			}
		}
		_size = 0;
	}
	size_t bucket_count() const{
		return _arr.size();
	}
	size_t bucket_size(size_t n) const{
		if (n >= _arr.size())
			return 0;
		size_t count = 0;
		Node* ptr = _arr[n];
		while (ptr) {
			++count;
			ptr = ptr->_pNext;
		}
		return count;
	}
	size_t bucket(const T& data) {
		return HashFunc(data);
	}
	void Swap(Self& t) {
		_arr.swap(t._arr);
		std::swap(_size, t._size);
	}
private:
	void CheckCapacity() {    //扩容
		if (_size == _arr.size()) {
			size_t newSize = GetNextPrime(_arr.size());
			Self newBucket(newSize);
			for (size_t i = 0; i < _arr.size(); ++i) {
				Node* ptr = _arr[i];
				while (ptr) {
					size_t addr = newBucket.HashFunc(ptr->_data);
					_arr[i] = ptr->_pNext;
					ptr->_pNext = newBucket._arr[addr];
					newBucket._arr[addr] = ptr;
					++newBucket._size;
					ptr = _arr[i];
				}
			}
			Swap(newBucket);
		}
	}
	size_t HashFunc(const T data) const{
		return DF()(KorV()(data)) % _arr.size();
	}
private:
	std::vector<Node*>  _arr;
	size_t _size;
};
#pragma once
#include <vector>
#include "Common.hpp"

template<class T>
struct HashNode
{
	// T():
	// T是内置类型的元素，T()--->0
	// T是自定义类型的元素， T()--->调用T类的无参构造函数
	HashNode(const T& data = T())
		: _pNext(nullptr)
		, _data(data)
	{}

	HashNode<T>* _pNext;
	T _data;
};


template<class T, class KOFV, class DF = DFStr>
class HashBucket;

// 迭代器：从实现原理上分类---1. 原生态指针   2. 对原生态指针进行封装

template<class T, class KOFV, class DF = DFStr>
struct HBIterator
{
	typedef HashNode<T> Node;
	typedef HBIterator<T, KOFV, DF> Self;
	HBIterator(Node* pNode = nullptr, HashBucket<T, KOFV, DF>* ht = nullptr)
		: _pNode(pNode)
		, _ht(ht)
	{}

	// 具有类似指针的操作
	T& operator*()
	{
		return _pNode->_data;
	}

	T* operator->()
	{
		return &(_pNode->_data);
	}

	// 能够移动
	// 前置++
	Self& operator++()
	{
		Next();
		return *this;
	}

	// 后置++
	Self operator++(int)
	{
		Self temp(*this);
		Next();
		return temp;
	}

	// 比较
	bool operator!=(Self& s)
	{
		return _pNode != s._pNode;
	}

	bool operator==(Self& s)
	{
		return _pNode == s._pNode;
	}

	void Next()
	{
		if (_pNode->_pNext)
		{
			// _pNode对应的链表后序还有节点
			_pNode = _pNode->_pNext;
		}
		else
		{
			// pNode是当前链表中的最后一个节点
			// 找pNode后序第一个非空桶
			// 问题：如何pNode是在哪个桶中？简单：如果能够知道哈希函数，就能够知道pNode的桶号
			// 如果能够拿到当前迭代器对应的哈希表，就可以拿到哈希函数
			size_t bucketNo = _ht->HashFunc(_pNode->_data) + 1;
			for (; bucketNo < _ht->_table.capacity(); ++bucketNo)
			{
				if (_ht->_table[bucketNo])
				{
					// 非空桶已经找到
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

// 迭代器如何与类结合：
// 1. 为该类定义迭代器
// 2. 在类中重新给迭代器命名
// 3. 增加begin/end
template<class T, class KOFV, class DF>
class HashBucket
{
	friend struct HBIterator<T, KOFV, DF>;
	typedef HashNode<T> Node;

public:
	typedef HBIterator<T, KOFV, DF> iterator;

public:
	HashBucket(size_t capacity = 10)
		: _size(0)
	{
		_table.resize(capacity/*GetNextPrime(10)*/);
	}

	~HashBucket()
	{
		clear();
	}

	// 在插入时，哈希桶中的元素是唯一的
	std::pair<iterator, bool> insertunique(const T& data)
	{
		CheckCapacity();

		// 1. 通过哈希函数，计算桶号
		size_t bucketNo = HashFunc(data);

		// 2. 检测值为data的元素在哈希桶中是否存在
		Node* pCur = _table[bucketNo];
		while (pCur)
		{
			if (KOFV()(pCur->_data) == KOFV()(data))
				return make_pair(iterator(pCur, this), false);

			pCur = pCur->_pNext;
		}

		// 3. 插入新节点---采用头插
		pCur = new Node(data);
		pCur->_pNext = _table[bucketNo];
		_table[bucketNo] = pCur;
		++_size;

		return make_pair(iterator(pCur, this), true);
	}

	// 表格中可以插入相同的元素
	bool insertEqual(const T& data);

	size_t eraseunique(const T& data)
	{
		// 1. 通过哈希函数计算data所在的同号
		size_t bucketNo = HashFunc(data);

		// 2. 在bucketNo所对应的链表中找值为data的节点
		Node* pCur = _table[bucketNo];
		Node* pPre = nullptr;
		while (pCur)
		{
			if (pCur->_data == data)
			{
				// 删除pCur节点删除
				if (nullptr == pPre)
				{
					// 删除的是第一个节点
					_table[bucketNo] = pCur->_pNext;
				}
				else
				{
					// 删除非第一个节点
					pPre->_pNext = pCur->_pNext;
				}

				delete pCur;
				--_size;
				return 1;
			}
			else
			{
				pPre = pCur;
				pCur = pCur->_pNext;
			}
		}

		return 0;
	}

	// 将所有值为data的节点删除
	bool eraseEqual(const T& data);

	// O(1)
	iterator find(const T& data)const
	{
		// 1. 计算data所在的桶号
		size_t bucketNo = HashFunc(data);

		// 2. 在bucketNo所对应的链表中找值为data的节点
		Node* pCur = _table[bucketNo];
		while (pCur)
		{
			if (KOFV()(pCur->_data) == KOFV()(data))
				return iterator(pCur, this);

			pCur = pCur->_pNext;
		}

		return end();
	}

	size_t size()const
	{
		return _size;
	}

	bool empty()const
	{
		return 0 == _size;
	}

	iterator begin()
	{
		// 找第一个非空桶
		for (size_t bucket = 0; bucket < _table.capacity(); ++bucket)
		{
			if (_table[bucket])
				return iterator(_table[bucket], this);
		}

		return end();
	}

	iterator end()
	{
		return iterator(nullptr, this);
	}

	void clear()
	{
		for (size_t bucketNo = 0; bucketNo < _table.capacity(); ++bucketNo)
		{
			Node* cur = _table[bucketNo];
			while (cur)
			{
				_table[bucketNo] = cur->_pNext;
				delete cur;
				cur = _table[bucketNo];
			}
		}

		_size = 0;
	}

	// 桶的总的个数
	size_t bucket_count()const
	{
		return _table.capacity();
	}

	// bucketNo中包含的节点总数
	size_t bucket_size(size_t bucketNo)const
	{
		if (bucketNo >= bucket_count())
			return 0;

		size_t count = 0;
		Node* cur = _table[bucketNo];
		while (cur)
		{
			count++;
			cur = cur->_pNext;
		}

		return count;
	}

	// 获取key所在的桶
	size_t bucket(const T& data)
	{
		return HashFunc(data);
	}

	// 测试
	void PrintHashBucket()
	{
		for (size_t bucketNo = 0; bucketNo < _table.capacity(); bucketNo++)
		{
			Node* pCur = _table[bucketNo];
			std::cout << "_table[" << bucketNo << "]:";
			while (pCur)
			{
				std::cout << pCur->_data << "--->";
				pCur = pCur->_pNext;
			}

			std::cout << "NULL" << std::endl;
		}
	}

	void swap(HashBucket<T, KOFV, DF>& ht)
	{
		_table.swap(ht._table);
		std::swap(_size, ht._size);
	}

private:
	// 如果哈希桶中所存储的元素个数和桶的个数相等时
	// 原因：找哈希桶最佳状态--->每个桶中都存储一个元素
	// >> 每个桶中都有一个元素，如果继续插入一定会发生冲突
	// >> 桶的利用率最大
	void CheckCapacity()
	{
		if (_size == _table.capacity())
		{
			HashBucket<T, KOFV, DF> newHT(GetNextPrime(_size));

			// 将旧哈希桶中的节点重新连接到新哈希桶中
			// 将节点从旧哈希桶中删除，将其插入到新哈希桶中
			for (size_t bucketNo = 0; bucketNo < _table.capacity(); ++bucketNo)
			{
				Node* cur = _table[bucketNo];
				while (cur)
				{
					// 计算cur在新哈希桶中的桶号
					size_t newBucketNo = newHT.HashFunc(cur->_data);

					// 先把cur从旧桶中删除
					_table[bucketNo] = cur->_pNext;

					// 将其插入到新哈希newBucketNo中
					cur->_pNext = newHT._table[newBucketNo];
					newHT._table[newBucketNo] = cur;
					newHT._size++;

					// 取旧哈希桶中的下一个节点
					cur = _table[bucketNo];
				}
			}

			this->swap(newHT);

			/*
			// 该方式可以，缺陷：直接插入后果是将哈希桶中的节点翻倍
			for (size_t bucketNo = 0; i < _table.capacity(); ++bucketNo)
			{
				// 将bucketNo桶中元素插入到新哈希桶newHT中
				Node* cur = _table[bucketNo];
				while (cur)
				{
					newHT.insertunique(cur->_data);
					cur = cur->_pNext;
				}
			}

			this->swap(newHT);
			*/
		}
	}

	size_t HashFunc(const T& data)const
	{
		return DF()(KOFV()(data)) % _table.capacity();
	}
private:
	std::vector<Node*> _table;
	size_t _size;
};

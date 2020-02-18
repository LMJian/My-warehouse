#pragma once
#include<vector>
#include"Common.hpp"

template<class T>
struct HashNode {
	HashNode(const T& data = T())
		:pNext_(nullptr)
		,data_(data)
	{}
	HashNode<T> * pNext_;
	T data_;
};

template<class T, class DF = DFDef<T>>
class HashBucket {
public:
	typedef HashNode<T> Node;
	HashBucket(size_t capacity=10)
		:size_(0)
	{
		table_.resize(10/*GetNextPrime(10)*/);
	}
	bool insertunique(const T& data) {
		size_t bucketNo = HashFunc(data);
		Node* pCur = table_[bucketNo];
		while (pCur) {
			if (pCur->data_ == data)
				return false;
			pCur = pCur->pNext_;
		}
		pCur = new Node(data);
		pCur->pNext_ = table_[bucketNo];
		table_[bucketNo] = pCur;
		++size_;
		return true;
	}

	//可以插入重复的
	bool insertEqual(const T& data);

	bool eraseunique(const T& data) {
		size_t bucketNo = HashFunc(data);

		Node* pCur = table_[bucketNo];
		Node* pPre = nullptr;
		while (pCur) {
			if (pCur->data_ == data) {
				if (pPre == nullptr) {
					table_[bucketNo] = pCur->pNext_;
				}
				else {
					pPre->pNext_ = pCur->pNext_;
				}
				delete pCur;
				--size_;
				return true;
			}
			else {
				pCur = pCur->pNext_;
			}
		}
		return false;
	}

	bool eraseEqual(const T& data);

	Node* find(const T&data)const {
		size_t bucketNo = HashFunc(data);

		Node* pCur = table_[bucketNo];
		while (pCur) {
			if (pCur->data_ == data)
				return pCur;
			pCur = pCur->pNext_;
		}
		return nullptr;
	}
	size_t size()const {
		return size_;
	}
	bool empty()const {
		return 0 == size_;
	}
	void PrintHashBucket() {
		for (size_t bucketNo = 0; bucketNo < table_.capacity(); ++bucketNo) {
			Node *pCur = table_[bucketNo];
			cout << "table_[" << bucketNo << "]:";
			while (pCur) {
				cout << pCur->data_ << "--->";
				pCur = pCur->pNext_;
			}
			cout << "NULL" << endl;
		}
	}
private:
	//存储元素的个数等于桶的个数
	//每个桶中都有一个元素，继续插入一定会发生冲突
	void CheckCapacity() {
		if (size_ == table_.capacity()) {

		}
	}
	size_t HashFunc(const T& data)const {
		return DF()(data) % table_.capacity();
	}
	std::vector<Node*> table_;
	size_t size_;
};

#include<iostream>
using namespace std;

void TestHashBucket() {
	HashBucket<int> ht;
	int arr[] = { 1,4,7,9,6,5 };
	for (auto e : arr) {
		ht.insertunique(e);
	}
	cout << ht.size() << endl;
	ht.PrintHashBucket();

	ht.insertunique(44);
	ht.insertunique(54);
	ht.PrintHashBucket();

	ht.eraseunique(44);
	if (ht.find(44))
		cout << "44 is in hashbucket" << endl;
	else
		cout << "44 is no in hashbucket" << endl;

	cout << ht.size() << endl;
	ht.PrintHashBucket();
}
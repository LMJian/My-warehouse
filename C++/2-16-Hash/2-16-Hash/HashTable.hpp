#pragma once
#include<vector>
#include<iostream>
using namespace std;

enum STATE { EMPTY, EXIST, DELETE };

template<class T>
struct Elem {
	Elem(const T& data = T())
		:data_(data)
		,state_(EMPTY)
	{}
	T data_;
	STATE state_;
};

template<class T>
class HashTable {
public:
	HashTable(size_t capacity = 10)
		:size_(0)
	{
		table_.resize(10);
	}
	bool Insert(const T& data) {
		size_t hashAddr = HashFunc(data);
		while(table_[hashAddr].state_ != EMPTY) {
			if (table_[hashAddr].state_ == EXIST && table_[hashAddr].data_ == data)
				return false;
			
			hashAddr++;
			//hashAddr %= table_.capacity();

			if (hashAddr == table_.capacity())
				hashAddr = 0;
		}
		table_[hashAddr].data_ = data;
		table_[hashAddr].state_ = EXIST;
		++size_;
		return true;
	}
	int Find(const T& data){
		size_t hashAddr = HashFunc(data);
		while (table_[hashAddr].state_ != EMPTY) {
			if (table_[hashAddr].state_ == EXIST && table_[hashAddr].data_ == data)
				return hashAddr;
			
			hashAddr++;
			if (hashAddr == table_.capacity())
				hashAddr = 0;
		}
		return -1;
	}
	bool Erase(const T& data) {
		int pos = Find(data);
		if (pos != -1) {
			table_[pos].state_ = DELETE;
			--size_;
			return true;
		}
		return false;
	}
	size_t Size()const {
		return size_;
	}
private:
	size_t HashFunc(const T& data) {
		return data % 10;
	}
	vector<Elem<T>> table_;
	size_t size_;
};

void TestHashTable() {
	int array[] = { 21,67,112,99,5,13,44 };
	HashTable<int> ht;
	for (auto e : array)
		ht.Insert(e);
	cout << ht.Size() << endl;
	ht.Insert(87);
	ht.Insert(77);
	cout << ht.Size() << endl;
	if (ht.Find(87) != -1) {
		cout << "87 is in hashTable" << endl;
	}
	else {
		cout << "87 is not in hashtable" << endl;
	}
	ht.Erase(67);
	if (ht.Find(67) != -1) {
		cout << "67 is in hashTable" << endl;
	}
	else {
		cout << "67 is not in hashtable" << endl;
	}
	if (ht.Find(87) != -1) {
		cout << "87 is in hashTable" << endl;
	}
	else {
		cout << "87 is not in hashtable" << endl;
	}
}
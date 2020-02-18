#pragma once
#include<vector>
#include<iostream>
#include<string>
#include"Common.hpp"
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

template<class T, class DF = DFDef<T>, bool isLine = true>
class HashTable {
public:
	HashTable(size_t capacity = 10)
		:size_(0)
		,table_(0)
		,total_(0)                                               //
	{
		table_.resize(5);                         //
	}
	bool Insert(const T& data) {
		size_t hashAddr = HashFunc(data);

		size_t i = 0;

		while(table_[hashAddr].state_ != EMPTY) {
			if (table_[hashAddr].state_ == EXIST && table_[hashAddr].data_ == data)
				return false;
			if (isLine) {                                     //
				hashAddr++;   //线性探测
				if (hashAddr == table_.capacity())
					hashAddr = 0;
			}
			else {
				++i;
				hashAddr = hashAddr + 2 * i + 1;
				hashAddr %= table_.capacity();
			}
		}
		table_[hashAddr].data_ = data;
		table_[hashAddr].state_ = EXIST;
		++size_;
		++total_;                                  //
		return true;
	}
	int Find(const T& data){
		size_t hashAddr = HashFunc(data);
		size_t i = 0;
		while (table_[hashAddr].state_ != EMPTY) {
			if (table_[hashAddr].state_ == EXIST && table_[hashAddr].data_ == data)
				return hashAddr;
			
			if (isLine) {                             //
				hashAddr++;   //线性探测
				if (hashAddr == table_.capacity())
					hashAddr = 0;
			}
			else {
				++i;
				hashAddr = hashAddr + 2 * i + 1;
				hashAddr %= table_.capacity();
			}
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
	void Swap(HashTable<T, DF, isLine>&ht) {
		table_.swap(ht.table_);
		swap(size_, ht.size_);
	}
private:
	void CheckCapacity() {
		if (total_ * 10 / table_.capacity() >= 7) {
			HashTable<T, DF, isLine> newHT(GetNextPrime(table_.capacity()));
			for (auto e : table_) {
				if (e.state_ == EXIST)
					newHT.Insert(e);
			}
			Swap(newHT);
		}
	}
	size_t HashFunc(const T& data) {
		return  DF()(data) % table_.capacity();
	}
	vector<Elem<T>> table_;
	size_t size_;
	size_t total_;   //有效元素和删除元素之和
};

void TestHashTable1() {
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

void TestHashTable2() {
	HashTable<string, DFStr, false> ht;
	//HashTable<string, DFStr, false> ht;
	ht.Insert("1111");
	ht.Insert("2222");
	ht.Insert("3333");
	ht.Insert("4444");
	ht.Insert("1311");
	ht.Insert("2322");
	ht.Insert("3233");
	ht.Insert("4344");
}
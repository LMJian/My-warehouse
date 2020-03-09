#pragma once

#include "HashBucket.hpp"
#include <string>
#include <iostream>
using namespace std;

namespace bite
{
	template<class K>
	class unordered_set
	{
	public:
		// 未加typename之前：编译器可能会将HashBucket<ValueType, KOFV>::iterator当成是类中的成员变量来进行处理
		// 因为成员变量也是根据类型::静态成员变量名字
		// typename: 在此处的作用就是明确告诉编译器，此处的iterator是哈希桶中的一个类型
		typedef K ValueType;

		struct KOFV
		{
			const K& operator()(const ValueType& data)const
			{
				return data;
			}
		};

		typename typedef HashBucket<ValueType, KOFV>::iterator iterator;

	public:
		unordered_set()
			: _ht()
		{}

		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		bool empty()const
		{
			return _ht.empty();
		}

		size_t size()const
		{
			return _ht.size();
		}

		pair<iterator, bool> insert(const ValueType& key)
		{
			return _ht.insertunique(key);
		}

		size_t erase(const K& key)
		{
			return _ht.eraseunique(key);
		}

		iterator find(const K& key)
		{
			return _ht.find(key);
		}

		void clear()
		{
			_ht.clear();
		}

		void swap(const unordered_set<K>& m)
		{
			_ht.swap(m._ht);
		}

		size_t bucket_count()const
		{
			return _ht.bucket_count();
		}

		size_t bucket_size(size_t n)const
		{
			return _ht.bucket_size(n);
		}

		size_t bucket(const K& key)
		{
			return _ht.bucket(key);
		}

	private:
		HashBucket<ValueType, KOFV> _ht;
	};
}




void TestUnorderedSet()
{
	bite::unordered_set<string> m;

	// 构造键值对的两种方式：pair结构体  make_pair
	m.insert("apple");
	m.insert("banana");
	m.insert("orange");
	m.insert("peach");

	cout << m.size() << endl;
	cout << m.bucket_count() << endl;  // 桶的个数
	cout << m.bucket_size(0) << endl;  // 0号桶中的元素个数
	cout << m.bucket("orange") << endl;   // 获取key所在的桶号

	// key不能重复
	m.insert("apple");
	cout << m.size() << endl;

	m.erase("orange");
	cout << m.size() << endl;

	m.clear();
}
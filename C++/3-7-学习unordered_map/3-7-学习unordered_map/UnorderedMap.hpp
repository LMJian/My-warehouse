#pragma once

#include "HashBucket.hpp"
#include <string>
#include <iostream>
using namespace std;

namespace bite
{
	template<class K, class V>
	class unordered_map
	{
	public:
		// 未加typename之前：编译器可能会将HashBucket<ValueType, KOFV>::iterator当成是类中的成员变量来进行处理
		// 因为成员变量也是根据类型::静态成员变量名字
		// typename: 在此处的作用就是明确告诉编译器，此处的iterator是哈希桶中的一个类型
		typedef pair<K, V> ValueType;

		struct KOFV
		{
			const K& operator()(const ValueType& data)const
			{
				return data.first;
			}
		};

		typename typedef HashBucket<ValueType, KOFV>::iterator iterator;

	public:
		unordered_map()
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

		pair<iterator, bool> insert(const ValueType& data)
		{
			return _ht.insertunique(data);
		}

		size_t erase(const K& key)
		{
			return _ht.eraseunique(ValueType(key, V()));
		}

		iterator find(const K& key)
		{
			return _ht.find(ValueType(key, V()));
		}

		void clear()
		{
			_ht.clear();
		}

		void swap(const unordered_map<K, V>& m)
		{
			_ht.swap(m._ht);
		}

		V& operator[](const K& key)
		{
			return (*(insert(ValueType(key, V())).first)).second;
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
			return _ht.bucket(ValueType(key, V()));
		}

	private:
		HashBucket<ValueType, KOFV> _ht;
	};
}

void TestUnorderedMAP()
{
	bite::unordered_map<string, string> m;

	// 构造键值对的两种方式：pair结构体  make_pair
	m.insert(pair<string, string>("宋江", "及时雨"));
	m.insert(pair<string, string>("李逵", "铁牛"));
	m.insert(pair<string, string>("林冲", "豹子头"));

	m.insert(make_pair("武松", "行者"));

	cout << m.size() << endl;
	cout << m.bucket_count() << endl;  // 桶的个数
	cout << m.bucket_size(0) << endl;  // 0号桶中的元素个数
	cout << m.bucket("宋江") << endl;   // 获取key所在的桶号

	// key不能重复
	m.insert(make_pair("李逵", "黑旋风"));
	cout << m.size() << endl;


	// []：如果key存在，直接返回与key所对应的value
	cout << m["李逵"] << endl;   // 给一个key，返回与该key对应的value
	cout << m.size() << endl;

	// []: 如果key不存在，<key, 默认value>构建一个键值对，然后将其插入到容器中，返回默认的value
	cout << m["鲁达"] << endl;
	cout << m.size() << endl;

	m.erase("鲁达");
	cout << m.size() << endl;

	m.clear();
}
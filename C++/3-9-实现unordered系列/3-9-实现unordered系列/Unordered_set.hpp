#pragma once
#include"HashBucket.hpp"

template<class K>
class Unordered_set {
	typedef K ValueType;
	struct KORV
	{
		const ValueType& operator()(const ValueType& data)const {
			return data;
		}
	};
	typename typedef HashBucket<ValueType, KORV>::iterator iterator;
public:
	Unordered_set(size_t size = 11)
		:_ht(size)
	{}

	iterator begin() {
		return _ht.begin();
	}
	iterator end() {
		return _ht.end();
	}
	bool empty()const {
		return _ht.empty();
	}
	size_t size()const {
		return _ht.size();
	}
	std::pair<iterator, bool> insert(const ValueType& data) {
		return _ht.Insert(data);
	}
	size_t erase(const ValueType& key) {
		return _ht.Erase(key);
	}
	iterator find(const ValueType& key) const {
		return _ht.find(key);
	}
	void clear() {
		_ht.Clear();
	}
	void swap(const Unordered_set<K>& m) {
		_ht.Swap(m._ht);
	}
	size_t buck_count()const {
		return _ht.bucket_count();
	}
	size_t buck_size(size_t n)const {
		return _ht.bucket_size(n);
	}
	size_t bucket(const ValueType& k) {
		return _ht.bucket(k);
	}
private:
	HashBucket<ValueType, KORV> _ht;
};
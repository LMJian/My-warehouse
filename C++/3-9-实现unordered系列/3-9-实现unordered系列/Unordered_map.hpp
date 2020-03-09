#pragma once
#include"HashBucket.hpp"

template<class K,class V>
class Unordered_map {
	typedef std::pair<K, V> ValueType;
	struct KORV 
	{
		const K& operator()(const ValueType& data)const {
			return data.first;
		}
	};
	typedef Iterator<ValueType, KORV> iterator;
	//typename typedef HashBucket<ValueType, KORV>::iterator iterator;
public:
	Unordered_map(size_t size = 11)
		:_ht(size)
	{}

	iterator begin(){
		return _ht.begin();
	}
	iterator end(){
		return _ht.end();
	}
	bool empty()const {
		return _ht.empty();
	}
	size_t size()const {
		return _ht.size();
	}
	std::pair<iterator,bool> insert(const ValueType& data){
		return _ht.Insert(data);
	}
	size_t erase(const K& key){
		return _ht.Erase(ValueType(key,V()));
	}
	iterator find(const K& key) const{
		return _ht.find(ValueType(key, V()));
	}
	void clear() {
		_ht.Clear();
	}
	void swap(const Unordered_map<K,V>& m) {
		_ht.Swap(m._ht);
	}
	V& operator[](const K& k) {
		return (*(insert(ValueType(k, V())).first)).second;
	}
	size_t buck_count()const {
		return _ht.bucket_count();
	}
	size_t buck_size(size_t n)const {
		return _ht.bucket_size(n);
	}
	size_t bucket(const K& k) {
		return _ht.bucket(ValueType(k, V()));
	}
private:
	HashBucket<ValueType, KORV> _ht;
};
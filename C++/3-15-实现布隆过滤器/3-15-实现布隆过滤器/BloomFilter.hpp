#pragma once
#include"bitset.hpp"
#include"Common.hpp"

template<class K, size_t N, class HF1 = Str2Int1,
	class HF2 = Str2Int2,
	class HF3 = Str2Int3,
	class HF4 = Str2Int4,
	class HF5 = Str2Int5>
class BloomFilter {
public:
	BloomFilter()
		:_size(0)
	{}
	void insert(const K& val) {
		size_t totalBits = N * 5;
		size_t hashAddr1 = HF1()(val) % totalBits;
		size_t hashAddr2 = HF2()(val) % totalBits;
		size_t hashAddr3 = HF3()(val) % totalBits;
		size_t hashAddr4 = HF4()(val) % totalBits;
		size_t hashAddr5 = HF5()(val) % totalBits;

		_bst.set(hashAddr1);
		_bst.set(hashAddr2);
		_bst.set(hashAddr3);
		_bst.set(hashAddr4);
		_bst.set(hashAddr5);
		
		++_size;
	}
	bool find(const K& val) {
		size_t totalBits = N * 5;
		size_t hashAddr = HF1()(val) % totalBits;
		if (!_bst.test(hashAddr))
			return false;
		hashAddr = HF2()(val) % totalBits;
		if (!_bst.test(hashAddr))
			return false;
		hashAddr = HF3()(val) % totalBits;
		if (!_bst.test(hashAddr))
			return false;
		hashAddr = HF4()(val) % totalBits;
		if (!_bst.test(hashAddr))
			return false;
		hashAddr = HF5()(val) % totalBits; 
		if (!_bst.test(hashAddr))
			return false;
		return true;
	}
	size_t size()const {
		return _size;
	}
private:
	LMJian::BitSet<N * 5> _bst;
	size_t _size;
};


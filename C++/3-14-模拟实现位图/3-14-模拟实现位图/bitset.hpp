#pragma once
#include<bitset>
#include<iostream>
#include<vector>
using namespace std;

namespace LMJian {
	template<size_t N>
	class BitSet {
	public:
		BitSet() 
		:_count(0)
		{
			_bset.resize((N >> 3) + 1);
		}
		//将pos位置1
		BitSet<N>& set(size_t pos) {
			if (pos >= N)
				return *this;
			size_t index = pos >> 3;
			size_t bitNo = pos % 8;
			if (0 == (_bset[index] & (1 << bitNo))) {
				++_count;
				_bset[index] |= (1 << bitNo);
			}
			return *this;
		}
		//将pos位置0
		BitSet<N>& reset(size_t pos) {
			if (pos >= N)
				return *this;
			size_t index = pos >> 3;
			size_t bitNo = pos % 8;
			if (_bset[index] & (1 << bitNo)) {
				--_count;
				_bset[index] &= ~(1 << bitNo);
			}
			return *this;
		}
		size_t size()const {
			return N;
		}
		size_t count()const {
			return _count;
		}
		//检查pos位是0还是1
		bool test(size_t pos)const {
			if (pos >= N)
				return false;
			size_t index = pos >> 3;
			size_t bitNo = pos % 8;
			return 0 != (_bset[index] & (1 << bitNo));
		}
	private:
		size_t _count;
		vector<unsigned char> _bset;
	};
}






void TestBitSet() {
	LMJian::BitSet<100> bt;
	bt.set(12);
	bt.set(23);
	bt.set(45);
	bt.set(78);
	bt.set(90);
	
	
	cout << bt.size() << endl;
	cout << bt.count() << endl;
	bt.reset(12);
	bt.reset(12);
	cout << bt.count() << endl;
	bt.set(27);
	bt.set(27);
	cout << bt.count() << endl;

	if (bt.test(12)) {
		cout << "12 bit is  1" << endl;
	}
	else {
		cout << "12 bit is 0" << endl;
	}
	bt.reset(12);
	if (bt.test(12)) {
		cout << "12 bit is  1" << endl;
	}
	else {
		cout << "12 bit is 0" << endl;
	}
		
}
#pragma once
#include<vector>

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
		std::vector<unsigned char> _bset;
	};
}
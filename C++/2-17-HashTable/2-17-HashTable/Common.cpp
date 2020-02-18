#include"Common.hpp"

size_t GetNextPrime(size_t capacity) {
	for (const auto& e : primeList) {
		if (e > capacity)
			return e;
	}
	return primeList[PRIMECOUNT - 1];
}
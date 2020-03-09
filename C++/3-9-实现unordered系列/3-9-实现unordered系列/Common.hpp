#pragma once
#include<string>

const int PRIMECOUNT = 28;
const size_t primeList[PRIMECOUNT] = {
	53ul, 97ul, 193ul, 389ul, 769ul,
 1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
 49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
 1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
 50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
 1610612741ul, 3221225473ul, 4294967291ul
};

size_t GetNextPrime(size_t capacity) {
	size_t i = 0;
	for (; i < PRIMECOUNT; ++i)
	{
		if (primeList[i] > primeList[i])
			return primeList[i];
	}
	return primeList[i];
}

class DFInt {
public:
	size_t operator()(const int& data) {
		return data;
	}
};

class DFStr {
public:
	size_t operator()(const std::string& data) {
		return AtoI(data.c_str());
	}
private:
	size_t AtoI(const char* ch) {
		register size_t ret = 0;
		while (size_t t = (size_t)*ch++) {
			ret = ret * 131 + t;
		}
		return ret;
	}
};


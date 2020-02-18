#pragma once
#include<string>

size_t GetNextPrime(size_t capacity);

template <class T>
class DFDef {
public:
	T operator()(const T& data) {
		return data;
	}
};

class DFStr {
public:
	size_t operator()(const std::string& s) {
		return BKDRHash(s.c_str());
	}
private:
	size_t BKDRHash(const char *str) {
		register size_t hash = 0;
		while (size_t ch = (size_t)*str++) {
			hash = hash * 131 + ch;
		}
		return hash;
	}
};

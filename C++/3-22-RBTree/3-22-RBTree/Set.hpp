#include"RBTree.hpp"

template<class K>
class Set {
	typedef K ValueType;
	struct KorV {
		const K& operator()(const ValueType& data) {
			return data;
		}
	};
public:
	typename typedef RBTree<ValueType, KorV>::iterator iterator;
public:
	Set()
	{}
	iterator begin() {
		return _tree.begin();
	}
	iterator end() {
		return _tree.end();
	}
	std::pair<iterator, bool> insert(const ValueType& data) {
		return _tree.Insert(data);
	}
	size_t size()const {
		return _tree.size();
	}
	bool empty()const {
		return _tree.empty();
	}
	iterator find(const K& key) {
		return _tree.find(key);
	}
private:
	RBTree<ValueType, KorV> _tree;
};
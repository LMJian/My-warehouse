#include"RBTree.hpp"

template<class K,class V>
class Map {
	typedef std::pair<K, V> ValueType;
	struct KorV {
		const K& operator()(const ValueType& v)const{
			return v.first;
		}
	};
	typename typedef RBTree<ValueType, KorV>::iterator iterator;
public:
	Map() 
	{}
	iterator begin() {
		return _tree.begin();
	}
	iterator end() {
		return _tree.end();
	}
	size_t size()const {
		return _tree.size();
	}
	bool empty()const {
		return _tree.empty();
	}
	std::pair<iterator, bool> insert(const ValueType& data) {
		return _tree.Insert(data);
	}
	iterator find(const K& key)const{
		return _tree.find(ValueType(key, V()));
	}
	V& operator[](const K& k) {
		return (*(insert(ValueType(k, V())).first)).second;
	}
private:
	RBTree<ValueType, KorV> _tree;
};
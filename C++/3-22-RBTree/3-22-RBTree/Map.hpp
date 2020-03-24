#include"RBTree.hpp"

template<class K,class V>
class Map {
	typename typedef std::pair<K, V> ValueType;
	struct KorV {
		const K& operator()(const ValueType& v){
			return v.first;
		}
	};
public:
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
	iterator find(const K& key){
		return _tree.find(std::make_pair(key, V()));
	}
	V& operator[](const K& k) {
		return (*(this->insert(std::make_pair(k, V()))).first).second;
	}
private:
	RBTree<ValueType, KorV> _tree;
};
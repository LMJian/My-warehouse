#pragma once
#include<algorithm>

enum Color {
	RED,
	BLACK
};

template<class ValueType>
struct RBTreeNode
{
	RBTreeNode(const ValueType& data = ValueType(), Color color = RED)
		:_pLeft(nullptr)
		,_pRight(nullptr)
		,_pParent(nullptr)
		,_data(data)
		,_color(color)
	{}

	RBTreeNode<ValueType>* _pLeft;
	RBTreeNode<ValueType>* _pRight;
	RBTreeNode<ValueType>* _pParent;
	ValueType _data;
	Color _color;
};

template<class T, class KorV>
class RBTree;

template<class T>
class Iterator {
public:
	typedef RBTreeNode<T> Node;
	typedef Iterator<T> Self;

	Iterator(Node* pNode=nullptr)
		:_pNode(pNode)
	{}
	T& operator*() {
		return _pNode->_data;
	}
	T* operator->() {
		return &(_pNode->_data);
	}
	Self& operator++() {
		Next();
		return *this;
	}
	Self operator++(int) {
		Self tmp(_pNode);
		Next();
		return tmp;
	}
	Self& operator--() {
		Prev();
		return *this;
	}
	Self operator--(int) {
		Self tmp(_pNode);
		Prev();
		return tmp;
	}
	bool operator==(const Self& t) const {
		return _pNode == t._pNode;
	}
	bool operator!=(const Self& t) const{
		return _pNode != t._pNode;
	}
private:
	void Next() {
		//如果有右子树
		if (_pNode->_pRight) {
			_pNode = _pNode->_pRight;
			while (_pNode->_pLeft)
				_pNode = _pNode->_pLeft;
			return;
		}
		Node* pParent = _pNode->_pParent;
		while (pParent->_pRight == _pNode) {
			_pNode = pParent;
			pParent = _pNode->_pParent;
		}
		//根节点没有右子树，并且迭代器刚好在根节点位置
		if (_pNode->_pRight != pParent)
			_pNode = pParent;
	}
	void Prev() {
		//1._pNode在head位置（即end()位置），应该将_pNode放在最大结点处
		if (_pNode->_pParent->_pParent == _pNode && _pNode->_color == RED)
			_pNode = _pNode->_pRight;
		//2. 如果有左子树
		else if (_pNode->_pLeft) {
			_pNode = _pNode->_pLeft;
			while (_pNode->_pRight)
				_pNode = _pNode->_pRight;
		}
		else {
			Node* pParent = _pNode->_pParent;
			while (pParent->_pLeft == _pNode) {
				_pNode = pParent;
				pParent = _pNode->_pParent;
			}
			_pNode = pParent;
		}
	}
	Node* _pNode;
};

template<class T,class KorV>
class RBTree {
public:
	typedef RBTreeNode<T> Node;
	typedef Node* PNode;
	typedef RBTree<T, KorV> Self;
	typedef Iterator<T> iterator;
public:
	RBTree()
		:_pHead(new Node)
		,_size(0)
	{
		_pHead->_pLeft = _pHead;
		_pHead->_pRight = _pHead;
	}
	~RBTree() {
		if (_pHead->_pParent)
			del(_pHead->_pParent);
		delete _pHead;
	}
	std::pair<iterator,bool> Insert(const T& data) {
		PNode& pRoot = GetRoot();   //获取根节点
		PNode newPtr = nullptr;
		if (nullptr == pRoot) {   //如果红黑树为空
			newPtr = pRoot = new Node(data, BLACK);
			pRoot->_pParent = _pHead;
		}
		else {
			PNode pParent = nullptr;
			PNode pCur = pRoot;
			//插入节点
			while (pCur) {
				pParent = pCur;
				if (KorV()(data) < KorV()(pCur->_data))
					pCur = pCur->_pLeft;
				else if (KorV()(data) > KorV()(pCur->_data))
					pCur = pCur->_pRight;
				else
					return std::make_pair(iterator(), false);
			}
			newPtr = pCur = new Node(data);
			if (KorV()(data) < KorV()(pParent->_data)) {
				pParent->_pLeft = pCur;
				pCur->_pParent = pParent;
			}
			else {
				pParent->_pRight = pCur;
				pCur->_pParent = pParent;
			}

			//检测新节点插入后。红黑树的性质是否遭到破坏
			while (pParent != _pHead && RED == pParent->_color) {
				PNode pGrand = pParent->_pParent;
				//pParent在pGrand左侧的情况
				if (pParent == pGrand->_pLeft) {
					PNode unclue = pGrand->_pRight;
					//情况一
					if (unclue&&RED == unclue->_color) {
						pParent->_color = BLACK;
						unclue->_color = BLACK;
						pGrand->_color = RED;

						pCur = pGrand;
						pParent = pCur->_pParent;
					}
					else {
						//情况三
						if (pParent->_pRight == pCur) {
							RotateLeft(pParent);
							std::swap(pParent, pCur);
						}
						//情况二
						RotateRight(pGrand);
						pParent->_color = BLACK;
						pGrand->_color = RED;
					}
				}
				//pParent在pGrand右侧的情况
				else {
					PNode unclue = pGrand->_pLeft;
					//情况一
					if (unclue&&RED == unclue->_color) {
						pParent->_color = BLACK;
						unclue->_color = BLACK;
						pGrand->_color = RED;

						pCur = pGrand;
						pParent = pCur->_pParent;
					}
					else {
						//情况三
						if (pParent->_pLeft == pCur) {
							RotateRight(pParent);
							std::swap(pParent, pCur);
						}
						//情况二
						RotateLeft(pGrand);
						pParent->_color = BLACK;
						pGrand->_color = RED;
					}
				}
			}
		}
		//根节点的颜色可能被修改，将其改回黑色
		pRoot->_color = BLACK;
		//更新头结点的左右孩子
		_pHead->_pLeft = LeftMost();
		_pHead->_pRight = RightMost();
		++_size;
		return std::make_pair(iterator(newPtr), true);
	}
	void Inorder()
	{
		_InOrder(GetRoot());
		std::cout << std::endl;
	}

	bool IsValidRBTree()
	{
		PNode pRoot = GetRoot();
		// 空树也是红黑树
		if (nullptr == pRoot)
			return true;
		// 检测根节点是否满足情况
		if (BLACK != pRoot->_color)
		{
			std::cout << "违反红黑树性质二：根节点必须为黑色" << std::endl;
			return false;
		}
		// 获取任意一条路径中黑色节点的个数
		size_t blackCount = 0;
		PNode pCur = pRoot;
		while (pCur)
		{
			if (BLACK == pCur->_color)
				blackCount++;
			pCur = pCur->_pLeft;
		}
		// 检测是否满足红黑树的性质，k用来记录路径中黑色节点的个数
		size_t k = 0;
		return _IsValidRBTree(pRoot, k, blackCount);
	}

	iterator find(const T& data)const {
		PNode ptr = GetRoot();
		while (ptr) {
			if (KorV()(data) == KorV()(ptr->_data))
				return iterator(ptr);
			else if (KorV()(data) < KorV()(ptr->_data))
				ptr = ptr->_pLeft;
			else
				ptr = ptr->_pRight;
		}
		return end();
	}

	size_t size()const {
		return _size;
	}

	bool empty()const {
		return _size == 0;
	}

	iterator begin() {
		return iterator(_pHead->_pLeft);
	}
	iterator end() {
		return iterator(_pHead);
	}
private:
	void _InOrder(Node* pRoot)
	{
		if (pRoot)
		{
			_InOrder(pRoot->_pLeft);
			std::cout << pRoot->_data << " ";
			_InOrder(pRoot->_pRight);
		}
	}
	void del(PNode ptr) {
		if (ptr->_pLeft)
			del(ptr->_pLeft);
		if (ptr->_pRight)
			del(ptr->_pRight);
		delete ptr;
	}
	bool _IsValidRBTree(PNode pRoot, size_t k, const size_t blackCount) {
		//走到null之后，判断k和black是否相等
		if (nullptr == pRoot)
		{
			if (k != blackCount)
			{
				std::cout << "违反性质四：每条路径中黑色节点的个数必须相同" << std::endl;
				return false;
			}
			return true;
		}
		// 统计黑色节点的个数
		if (BLACK == pRoot->_color)
			k++;
		// 检测当前节点与其双亲是否都为红色
		PNode pParent = pRoot->_pParent;
		if (pParent && RED == pParent->_color && RED == pRoot->_color)
		{
			std::cout << "违反性质三：没有连在一起的红色节点" << std::endl;
			return false;
		}
		return _IsValidRBTree(pRoot->_pLeft, k, blackCount) &&
			_IsValidRBTree(pRoot->_pRight, k, blackCount);
	}
	PNode& GetRoot() {
		return _pHead->_pParent;
	}
	PNode LeftMost() {
		PNode ptr = GetRoot();
		if (!ptr)
			return _pHead;
		while (ptr->_pLeft)
			ptr = ptr->_pLeft;
		return ptr;
	}
	PNode RightMost() {
		PNode ptr = GetRoot();
		if (!ptr)
			return _pHead;
		while (ptr->_pRight)
			ptr = ptr->_pRight;
		return ptr;
	}
	void RotateLeft(PNode pParent) {
		PNode pPParent = pParent->_pParent;
		PNode pRight = pParent->_pRight;
		pParent->_pRight = pRight->_pLeft;
		if (pRight->_pLeft)
			pRight->_pLeft->_pParent = pParent;
		pRight->_pLeft = pParent;
		pParent->_pParent = pRight;
		//当pPParent不存在时
		if (pPParent==_pHead) {
			//设置pRight为根节点
			_pHead->_pParent = pRight;
			pRight->_pParent = _pHead;
		}
		else {
			if (pPParent->_pLeft == pParent) {
				pPParent->_pLeft = pRight;
				pRight->_pParent = pPParent;
			}
			else {
				pPParent->_pRight = pRight;
				pRight->_pParent = pPParent;
			}
		}
	}
	void RotateRight(PNode pParent) {
		PNode pPParent = pParent->_pParent;
		PNode pLeft = pParent->_pLeft;
		pParent->_pLeft = pLeft->_pRight;
		if (pLeft->_pRight)
			pLeft->_pRight->_pParent = pParent;
		pLeft->_pRight = pParent;
		pParent->_pParent = pLeft;
		//当pPParent不存在时
		if (pPParent == _pHead) {
			//设置pLeft为根节点
			_pHead->_pParent = pLeft;
			pLeft->_pParent = _pHead;
		}
		else {
			if (pPParent->_pLeft == pParent) {
				pPParent->_pLeft = pLeft;
				pLeft->_pParent = pPParent;
			}
			else {
				pPParent->_pRight = pLeft;
				pLeft->_pParent = pPParent;
			}
		}
	}
private:
	PNode _pHead;    //头结点(根节点的父亲节点)
	size_t _size;
};
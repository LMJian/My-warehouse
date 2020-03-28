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
	bool operator==(Self& t){
		return _pNode == t._pNode;
	}
	bool operator!=(Self& t){
		return _pNode != t._pNode;
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
private:
	void Next() {
		//�����������
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
		//���ڵ�û�������������ҵ������պ��ڸ��ڵ�λ��
		if (_pNode->_pRight != pParent)
			_pNode = pParent;
	}
	void Prev() {
		//1._pNode��headλ�ã���end()λ�ã���Ӧ�ý�_pNode��������㴦
		if (_pNode->_pParent->_pParent == _pNode && _pNode->_color == RED)
			_pNode = _pNode->_pRight;
		//2. �����������
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
		PNode& pRoot = GetRoot();   //��ȡ���ڵ�
		PNode newPtr = nullptr;
		if (nullptr == pRoot) {   //��������Ϊ��
			newPtr = pRoot = new Node(data, BLACK);
			pRoot->_pParent = _pHead;
		}
		else {
			PNode pParent = nullptr;
			PNode pCur = pRoot;
			//����ڵ�
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

			//����½ڵ����󡣺�����������Ƿ��⵽�ƻ�
			while (pParent != _pHead && RED == pParent->_color) {
				PNode pGrand = pParent->_pParent;
				//pParent��pGrand�������
				if (pParent == pGrand->_pLeft) {
					PNode unclue = pGrand->_pRight;
					//���һ
					if (unclue&&RED == unclue->_color) {
						pParent->_color = BLACK;
						unclue->_color = BLACK;
						pGrand->_color = RED;

						pCur = pGrand;
						pParent = pCur->_pParent;
					}
					else {
						//�����
						if (pParent->_pRight == pCur) {
							RotateLeft(pParent);
							std::swap(pParent, pCur);
						}
						//�����
						RotateRight(pGrand);
						pParent->_color = BLACK;
						pGrand->_color = RED;
					}
				}
				//pParent��pGrand�Ҳ�����
				else {
					PNode unclue = pGrand->_pLeft;
					//���һ
					if (unclue&&RED == unclue->_color) {
						pParent->_color = BLACK;
						unclue->_color = BLACK;
						pGrand->_color = RED;

						pCur = pGrand;
						pParent = pCur->_pParent;
					}
					else {
						//�����
						if (pParent->_pLeft == pCur) {
							RotateRight(pParent);
							std::swap(pParent, pCur);
						}
						//�����
						RotateLeft(pGrand);
						pParent->_color = BLACK;
						pGrand->_color = RED;
					}
				}
			}
		}
		//���ڵ����ɫ���ܱ��޸ģ�����Ļغ�ɫ
		pRoot->_color = BLACK;
		//����ͷ�������Һ���
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
		// ����Ҳ�Ǻ����
		if (nullptr == pRoot)
			return true;
		// �����ڵ��Ƿ��������
		if (BLACK != pRoot->_color)
		{
			std::cout << "Υ����������ʶ������ڵ����Ϊ��ɫ" << std::endl;
			return false;
		}
		// ��ȡ����һ��·���к�ɫ�ڵ�ĸ���
		size_t blackCount = 0;
		PNode pCur = pRoot;
		while (pCur)
		{
			if (BLACK == pCur->_color)
				blackCount++;
			pCur = pCur->_pLeft;
		}
		// ����Ƿ��������������ʣ�k������¼·���к�ɫ�ڵ�ĸ���
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
		//�ߵ�null֮���ж�k��black�Ƿ����
		if (nullptr == pRoot)
		{
			if (k != blackCount)
			{
				std::cout << "Υ�������ģ�ÿ��·���к�ɫ�ڵ�ĸ���������ͬ" << std::endl;
				return false;
			}
			return true;
		}
		// ͳ�ƺ�ɫ�ڵ�ĸ���
		if (BLACK == pRoot->_color)
			k++;
		// ��⵱ǰ�ڵ�����˫���Ƿ�Ϊ��ɫ
		PNode pParent = pRoot->_pParent;
		if (pParent && RED == pParent->_color && RED == pRoot->_color)
		{
			std::cout << "Υ����������û������һ��ĺ�ɫ�ڵ�" << std::endl;
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
		//��pPParent������ʱ
		if (pPParent==_pHead) {
			//����pRightΪ���ڵ�
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
		//��pPParent������ʱ
		if (pPParent == _pHead) {
			//����pLeftΪ���ڵ�
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
	PNode _pHead;    //ͷ���(���ڵ�ĸ��׽ڵ�)
	size_t _size;
};
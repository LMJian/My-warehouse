#pragma once
#include<iostream>
#include<stack>
using namespace std;

template<class T>
struct BSTreeNode
{
	BSTreeNode(const T& data = T())
		: _pLeft(nullptr)
		, _pRight(nullptr)
		, _data(data)
	{}
	BSTreeNode<T>* _pLeft;
	BSTreeNode<T>* _pRight;
	T _data;
};


template<class T>
class BSTree
{
	typedef BSTreeNode<T> Node;
public:
	BSTree()
		: _pRoot(nullptr)
	{}
	~BSTree() {
		dele();
	}
	bool Insert(const T& data) {
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}
		Node* _pCur = _pRoot;
		Node* _pParent = nullptr;
		while (_pCur) {
			_pParent = _pCur;
			if (data < _pCur->_data)
				_pCur = _pCur->_pLeft;
			else if (data > _pCur->_data)
				_pCur = _pCur->_pRight;
			else
				return false;
		}
		if (data < _pParent->_data) {
			_pParent->_pLeft = new Node(data);
		}
		else
			_pParent->_pRight = new Node(data);
		return true;
	}

	bool Delete(const T& data) {
		Node* pCur = _pRoot;
		Node* pParent = nullptr;
		while (pCur) {
			if (data == pCur->_data) {
				break;
			}
			else if (data < pCur->_data) {
				pParent = pCur;
				pCur = pCur->_pLeft;
			}
			else {
				pParent = pCur;
				pCur = pCur->_pRight;
			}
		}
		if (!pCur)//没找到
			return false;
		if (pCur->_pLeft && pCur->_pRight) {//左右孩子都有
			//在pCur右子树中找最小节点，和pCur交换值，然后删除
			Node* R_Min = pCur->_pRight;
			Node* MParent = pCur;
			while (R_Min->_pLeft) {
				MParent = R_Min;
				R_Min = R_Min->_pLeft;
			}
			pCur->_data = R_Min->_data;
			if (MParent->_pLeft == R_Min)
				MParent->_pLeft = nullptr;
			else
				MParent->_pRight = nullptr;
			delete R_Min;
		}
		else if (pCur->_pLeft) {//只有左子树
			if (!pParent) {//删除节点为根节点
				_pRoot = pCur->_pLeft;
				delete pCur;
			}
			else
			{
				if (pCur == pParent->_pLeft)
					pParent->_pLeft = pCur->_pLeft;
				else
					pParent->_pRight = pCur->_pLeft;
				delete pCur;
			}
		}
		else {//只有右子树或者空树
			if (!pParent) {//删除节点为根节点
				_pRoot = pCur->_pRight;
				delete pCur;
			}
			else
			{
				if (pCur == pParent->_pLeft)
					pParent->_pLeft = pCur->_pRight;
				else
					pParent->_pRight = pCur->_pRight;
				delete pCur;
			}
		}
		return true;
	}
	
	Node* Find(const T& data) {
		Node* ptr = _pRoot;
		while (ptr) {
			if (data == ptr->_data)
				return ptr;
			else if (data < ptr->_data)
				ptr = ptr->_pLeft;
			else
				ptr = ptr->_pRight;
		}
		return nullptr;
	}

	Node* LeftMost() {
		if (!_pRoot)
			return nullptr;
		Node* ptr = _pRoot;
		while (ptr->_pLeft)
			ptr = ptr->_pLeft;
		return ptr;
	}

	Node* RightMost() {
		if (!_pRoot)
			return nullptr;
		Node* ptr = _pRoot;
		while (ptr->_pRight)
			ptr = ptr->_pRight;
		return ptr;
	}

	// 中序遍历结果是否有序
	void InOrder() {
		stack<Node*> sa;
		Node *ptr = _pRoot;
		while (!sa.empty() || ptr) {
			while(ptr) {
				sa.push(ptr);
				ptr = ptr->_pLeft;
			}
			cout << sa.top()->_data << " ";
			ptr = sa.top()->_pRight;
			sa.pop();
		}
		cout << endl;
	}

private:
	Node* _pRoot;
	void dele() {
		stack<Node*> sa;
		Node* ptr = _pRoot;
		while (!sa.empty() || ptr) {
			while (ptr) {
				sa.push(ptr);
				ptr = ptr->_pLeft;
			}
			ptr = sa.top()->_pRight;
			delete sa.top();
			sa.pop();
		}
	}
};

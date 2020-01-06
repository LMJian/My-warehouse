#pragma once
#include<vector>
#include<iostream>
#include<stack>
using namespace std;

template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& data)
		: _pLeft(nullptr), _pRight(nullptr), _pParent(nullptr)
		, _data(data), _bf(0)
	{}
	AVLTreeNode<T>* _pLeft; 
	AVLTreeNode<T>* _pRight; 
	AVLTreeNode<T>* _pParent; 
	T _data;
	int _bf; 
};

template<class T>
class AVLTree {
	typedef AVLTreeNode<T>* PNode;
	typedef AVLTreeNode<T> Node;
public:
	AVLTree()
		:_Root(nullptr) 
	{}
	~AVLTree() {
		stack<PNode> arr;
		PNode node = _Root;
		while (!arr.empty() || node) {
			while (node) {
				arr.push(node);
				node = node->_pLeft;
			}
			PNode del = arr.top();
			arr.pop();
			node = del->_pRight;
			delete del;
		}
	}
	bool Insert(const T& data){
		if (!_Root) {
			_Root = new Node(data);
			return true;
		}
		PNode pParent=nullptr;
		PNode pCur = _Root;
		while (pCur) {
			pParent = pCur;
			if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else if (data > pCur->_data)
				pCur = pCur->_pRight;
			else
				return false;
		}
		pCur = new Node(data);
		if (data < pParent->_data) {
			pParent->_pLeft = pCur;
			pCur->_pParent = pParent;
		}
		else {
			pParent->_pRight = pCur;
			pCur->_pParent = pParent;
		}
		while (pParent) {
			if (pParent->_pLeft == pCur) {
				--pParent->_bf;
			}
			else {
				++pParent->_bf;
			}
			if (pParent->_bf == 0)
				break;
			if (pParent->_bf > 1 || pParent->_bf < -1) {
				if (pParent->_bf == 2) {
					if (pParent->_pRight->_bf == 1) {//左旋
						RotateL(pParent);
					}
					else {//右左旋
						RotateRL(pParent);
					}
				}
				else {
					if (pParent->_pLeft->_bf == -1) {//右旋
						RotateR(pParent);
					}
					else {//左右旋
						RotateLR(pParent);
					}
				}
				break;
			}
			pCur = pParent;
			pParent = pParent->_pParent;
		}
		return true;
	}
	PNode Find(const T& data) {
		PNode ptr = _Root;
		while (ptr) {
			if (data < ptr->_data)
				ptr = ptr->_pLeft;
			else if (data > ptr->_data)
				ptr = ptr->_pRight;
			else
				return ptr;
		}
		return nullptr;
	}
	//bool DelNode(const T& data);
	bool IsBalanceTree() {
		return IsAVLTree(_Root);
	}
private:
	void RotateL(PNode pParent) {
		pParent->_bf = pParent->_pRight->_bf = 0;
		PNode pPParent = pParent->_pParent;
		PNode pRight = pParent->_pRight;
		pParent->_pRight = pRight->_pLeft;
		if (pRight->_pLeft)
			pRight->_pLeft->_pParent = pParent;
		pRight->_pLeft = pParent;
		pParent->_pParent = pRight;
		if (!pPParent) {
			_Root = pRight;
			pRight->_pParent = nullptr;
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
	void RotateR(PNode pParent) {
		pParent->_bf = pParent->_pLeft->_bf = 0;
		PNode pPParent = pParent->_pParent;
		PNode pLeft = pParent->_pLeft;
		pParent->_pLeft = pLeft->_pRight;
		if (pLeft->_pRight)
			pLeft->_pRight->_pParent = pParent;
		pLeft->_pRight = pParent;
		pParent->_pParent = pLeft;
		if (!pPParent) {
			_Root = pLeft;
			pLeft->_pParent = nullptr;
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
	void RotateLR(PNode pParent) {
		PNode pLeft = pParent->_pLeft;
		PNode pLeftR = pLeft->_pRight;
		int bf = pLeftR->_bf;
		RotateL(pParent->_pLeft);
		RotateR(pParent);
		if (1 == bf)               //最难最难的是这里的判断     花了好久才想到
			pLeft->_bf = -1;
		else if (-1 == bf)
			pParent->_bf = 1;
	}
	void RotateRL(PNode pParent) {
		PNode pRight = pParent->_pRight;
		PNode pRightL = pRight->_pLeft;
		int bf = pRightL->_bf;
		RotateR(pParent->_pRight);
		RotateL(pParent);
		if (1 == bf)
			pParent->_bf = -1;
		else if (-1 == bf)
			pRight->_bf = 1;
	}
	int Height(PNode pRoot) {
		if (!pRoot)
			return 0;
		vector<PNode> v1;
		vector<PNode> v2;
		int count = 1;
		v1.push_back(pRoot);
		while (1) {
			for (size_t i = 0; i < v1.size(); ++i) {
				if (v1[i]->_pLeft)
					v2.push_back(v1[i]->_pLeft);
				else if (v1[i]->_pRight)
					v2.push_back(v1[i]->_pRight);
			}
			v1 = v2;
			v2.clear();
			if (!v1.empty())
				++count;
			else
				break;
		}
		return count;
	}
	bool IsAVLTree(PNode pRoot) {
		if (!pRoot)
			return true;
		int left = Height(pRoot->_pLeft);
		int right = Height(pRoot->_pRight);
		if (right - left < -1 || right - left>1 || pRoot->_bf != right - left)
			return false;
		return IsAVLTree(pRoot->_pLeft) && IsAVLTree(pRoot->_pRight);
	}
	PNode _Root;
};
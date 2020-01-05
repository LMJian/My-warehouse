#pragma once
#include<iostream>

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
public:
	typedef AVLTreeNode<T> Node;
	typedef AVLTreeNode<T>* PNode;
	bool Insert(const T& data);
	void RotateL(PNode pParent);
	void RotateR(PNode pParent);
	void RotateLR(PNode pParent);
	void RotateRL(PNode pParent);
	int _Height(PNode pRoot);
	bool _IsBalanceTree(PNode pRoot);
	bool Del(const T& data);
private:
	PNode _Root;
};
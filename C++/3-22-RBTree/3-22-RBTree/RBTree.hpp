#pragma once

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

template<class ValueType>
class RBTree {
	typedef RBTreeNode<ValueType> Node;
	typedef Node* PNode;
public:
	bool Insert(const ValueType& data) {
		PNode& pRoot = GetRoot();   //获取根节点
		if (nullptr == pRoot) {   //如果红黑树为空
			pRoot = new Node(data, BLACK);
			
			pRoot->_pParent = _pHead;
			_pHead->_pParent = pRoot;
		}
		else {
			//插入节点
			PNode pParent = nullptr;
			PNode pCur = pRoot;
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
			//检测新节点插入后。红黑树的性质是否遭到破坏
			while (pParent&&RED == pParent->_color) {
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
						if (pParent->_pRight==pCur) {
							RotateLeft(pParent);
							swap(pParent, pCur);
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
							swap(pParent, pCur);
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
		return true;
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

private:
	PNode& GetRoot() {
		return _pHead->_pParent;
	}
	PNode LeftMost() {
		PNode ptr = GetRoot();
		while (ptr->_pLeft)
			ptr = ptr->_pLeft;
		return ptr;
	}
	PNode RightMost() {
		PNode ptr = GetRoot();
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
};
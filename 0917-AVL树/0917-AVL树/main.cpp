#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;

template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& data)
		:_pLeft(nullptr), _pRight(nullptr), _pParent(nullptr)
		, _data(data), _bf(0)
	{}
	AVLTreeNode* _pLeft;
	AVLTreeNode* _pRight;
	AVLTreeNode* _pParent;
	T _data;
	int _bf;
};

template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
	typedef Node* PNode;
public:
	AVLTree()
		:_pRoot(nullptr)
	{}
	~AVLTree()
	{
		dele(_pRoot);
	}
	void dele(PNode pCur)
	{
		if (pCur->_pLeft)
			dele(pCur->_pLeft);
		if (pCur->_pRight)
			dele(pCur->_pRight);
		free(pCur);
		cout << "1 ";
	}
	PNode Find(const T&data)
	{
		PNode pCur = _pRoot;
		while (pCur)
		{
			if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else if (data>pCur->_data)
				pCur = pCur->_pRight;
			else
				return pCur;
		}
		return nullptr;
	}
	bool Insert(const T& data)
	{
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}
		PNode pCur = _pRoot;
		PNode pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else if (data>pCur->_data)
				pCur = pCur->_pRight;
			else
				return false;
		}
		pCur = new Node(data);
		if (data < pParent->_data)
		{
			pParent->_pLeft = pCur;
			pCur->_pParent = pParent;
		}
		else
		{
			pParent->_pRight = pCur;
			pCur->_pParent = pParent;
		}
		//更新平衡因子
		while (pParent)
		{
			if (pCur == pParent->_pLeft)
				pParent->_bf--;
			else
				pParent->_bf++;

			if (0 == pParent->_bf)//插入的结点使得父结点的度为0
				                  //说明原先就有一个左节点或者右节点，不影响故无需调整
				break;
			else if (1 == pParent->_bf || -1 == pParent->_bf)
				//度为+-1，此处无需调整，向上继续查找是否有需要调整的
			{
				pCur = pParent;
				pParent = pCur->_pParent;
			}
			else//出现了度为+-2的情况，需要调整
			{
				if (2 == pParent->_bf)
				{
					if (1 == pParent->_pRight->_bf)//右右，左单旋
					{
						Left(pParent);
						break;
					}
					else//-1 == pParent->_pRight->_bf 
						//右左，先右单旋，再左单旋
					{
						RightLeft(pParent);
						break;
					}
				}
				else
				{
					if (-1 == pParent->_pLeft->_bf)//左左，右单旋
					{
						Right(pParent);
						break;
					}
					else//左右，先左旋，再右旋
					{
						LeftRight(pParent);
						break;
					}
				}
			}
		}
		return true;
	}
	void Left(PNode root)//左单旋
	{
		PNode pParent = root->_pRight;
		PNode pCur = pParent->_pLeft;

		root->_pRight = pCur;
		if (pCur!=nullptr)
			pCur->_pParent = root;

		if (root->_pParent == nullptr)
		{
			pParent->_pParent = nullptr;
			_pRoot = pParent;
		}
		else
		{
			if (root->_pParent->_pLeft == root)
			{
				root->_pParent->_pLeft = pParent;
				pParent->_pParent = root->_pParent;
			}
			else
			{
				root->_pParent->_pRight = pParent;
				pParent->_pParent = root->_pParent;
			}
		}
		root->_pParent = pParent;
		pParent->_pLeft = root;

		root->_bf = pParent->_bf = 0;
	}
	void Right(PNode root)//右单旋
	{
		PNode pParent = root->_pLeft;
		PNode pCur = pParent->_pRight;
		root->_pLeft = pCur;
		if (pCur != nullptr)
			pCur->_pParent = root;
		
		if (root->_pParent == nullptr)
		{
			pParent->_pParent = nullptr;
			_pRoot = pParent;
		}
		else
		{
			if (root->_pParent->_pLeft == root)
			{
				root->_pParent->_pLeft = pParent;
				pParent->_pParent = root->_pParent;
			}
			else
			{
				root->_pParent->_pRight = pParent;
				pParent->_pParent = root->_pParent;
			}
		}
		root->_pParent = pParent;
		pParent->_pRight = root;

		root->_bf = pParent->_bf = 0;
	}
	void show()
	{
		_show(_pRoot);
	}
	void _show(PNode pt)
	{
		if (pt->_pLeft != nullptr)
			_show(pt->_pLeft);
		if (pt->_pRight != nullptr)
			_show(pt->_pRight);
		printf("结点：%d 度：%d \n", pt->_data, pt->_bf);
	}
	void LeftRight(PNode pParent)//左右旋
	{
		PNode pSubL = pParent->_pLeft;
		PNode pSubLR = pSubL->_pRight;
		int bf = pSubLR->_bf;
		Left(pParent->_pLeft);
		Right(pParent);
		if (1 == bf)
			pSubL->_bf = -1;
		else if (-1 == bf)
			pParent->_bf = 1;
	}
	void RightLeft(PNode pParent)//右左旋
	{
		PNode pSubR = pParent->_pRight;
		PNode pSubRL = pSubR->_pLeft;
		int bf = pSubRL->_bf;
		Right(pParent->_pRight);
		Left(pParent);
		if (1 == bf)
			pParent->_bf = -1;
		else if (-1 == bf)
			pSubR->_bf = 1;
	}

	int _Height(PNode pRoot)
	{
		if (pRoot == nullptr)
			return 0;
		count++;
		if (count > max)
			max = count;
		if (pRoot->_pLeft != nullptr)
		{
			_Height(pRoot->_pLeft);
			count--;
		}
		if (pRoot->_pRight != nullptr)
		{
			_Height(pRoot->_pRight);
			count--;
		}
		return max;
	}
	bool IsBalanceTree()
	{
		return _IsBalanceTree(_pRoot);
	}
	bool _IsBalanceTree(PNode pRoot)//验证是否是AVL树
	{
		if (nullptr == pRoot)
			return true;
		max = 0;count = 0;
		int leftHeight = _Height(pRoot->_pLeft);
		max = 0; count = 0;
		int rightHeight = _Height(pRoot->_pRight);
		int diff = rightHeight - leftHeight;

		if (diff != pRoot->_bf || (diff > 1 || diff < -1))
			return false;
		return _IsBalanceTree(pRoot->_pLeft) && _IsBalanceTree(pRoot->_pRight);
	}
private:
	PNode _pRoot;
	static int count;//记录当前所在层数
	static int max;//记录count历史最大值
}; 
int AVLTree<int>::count = 0;
int AVLTree<int>::max = 0;

AVLTree<int> tree;
int main()
{
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (auto e : a)
		tree.Insert(e);
	tree.show();
	cout<<tree.IsBalanceTree() << endl;

	system("pause");
	return 0;
}
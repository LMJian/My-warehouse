#include<iostream>
#include<string>
#include<map>
#include<set>
#include<vector>
using namespace std;


/*template<class T1,class T2>
struct pair
{
	typedef T1 first_type;
	typedef T2 second_type;

	T1 first;
	T2 second;
	pair()
		:first(T1())//***
		, second(T2())
	{}
	pair(const T1& a,const T2& b)
		:first(a)
		, second(b)
	{}
};

void TestMap()
{
	map<string, string>m;
	//m.insert(pair<string, string>("peach", "桃子"));
	m.insert(make_pair("banan", "香蕉"));
	m["apple"] = "苹果";
	m["banan"] = "xiangjiao";

	m.at("banan") = "水蜜桃";
	cout << m.size() << endl;

	for (auto& e : m)
		cout << e.first << "--->" << e.second << endl;
	cout << endl;

	auto ret = m.insert(make_pair("peach", "桃色"));
	if (ret.second)
		cout << "<peach,桃色>不在map中，已经插入" << endl;
	else
		cout << "键值为peach的元素已经存在：" << ret.first->first \
		<< "--->" << ret.first->second << "插入失败" << endl;

	auto rett = m.insert(make_pair("banan", "桃色"));
	if (rett.second)
		cout << "不在map中，已经插入" << endl;
	else
		cout << "元素已经存在：" << rett.first->first \
		<< "--->" << rett.first->second << "插入失败" << endl;

	m.erase("apple");

	if (1 == m.count("apple"))
		cout << "apple还在" << endl;
	else
		cout << "apple被吃了" << endl;

}*/
/*void TestSet()
{
	int array[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0, 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	set<int>s(array, array + sizeof(array) / sizeof(array[0]));
	cout << s.size() << endl;

	for (auto& e : s)
		cout << e << " ";
	cout << endl;

	for (auto it = s.rbegin(); it != s.rend(); ++it)
		cout << *it << " ";
	cout << endl;

	cout << s.count(3) << endl;
}
void TestSet()
{
	int array[] = { 2, 1, 3, 9, 6, 0, 5, 8, 4, 7, 1, 2, 3 };
	multiset<int>s(array, array + sizeof(array) / sizeof(array[0]));
	for (auto& e : s)
		cout << e << " ";
	cout << endl;
}*/
/*class Solution{
public:
	class Compare
	{
	public:
		bool operator()(const pair<string, int>&left, \
			const pair<string, int>&right)
		{
			return left.second > right.second;
		}
	};
	vector<string>topKFrequent(vector<string>&words, int k)
	{
		map<string, int>m;
		for (size_t i = 0; i < words.size(); ++i)
			++(m[words[i]]);

		multiset<pair<string, int>, Compare>ms(m.begin(), m.end());

		set<string>s;
		size_t count = 0;
		size_t leftCount = k;

		vector<string>ret;
		for (auto&e : ms)
		{
			if (!s.empty())
			{
				if (count != e.second)
				{
					if (s.size() < leftCount)
					{
						ret.insert(ret.end(), s.begin(), s.end());
						leftCount -= s.size();
						s.clear();
					}
					else
					{
						break;
					}
				}
			}
			count = e.second;
			s.insert(e.first);
		}
		for (auto& e : s)
		{
			if (0 == leftCount)
				break;
			ret.push_back(e);
			leftCount--;
		}
		return ret;
	}
};*/
/*template<class T>
struct BSTNode
{
	BSTNode(const T& data = T())
		:_pLeft(nullptr), _pRight(nullptr), _data(data)
	{}
	BSTNode<T>* _pLeft;
	BSTNode<T>* _pRight;
	T _data;
};
template<class T>
class BSTree
{
	typedef BSTNode<T> Node;
	typedef Node* PNode;
public:
	BSTree()
		:_pRoot(nullptr)
	{}
	~BSTree()
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
			pParent->_pLeft = pCur;
		else
			pParent->_pRight = pCur;
		return true;
	}
	bool Erase(const T& data)
	{
		if (nullptr == _pRoot)
			return false;
		PNode pCur = _pRoot;
		PNode pParent = nullptr;
		while (pCur)
		{
			if (data == pCur->_data)
				break;
			else if (data < pCur->_data)
			{
				pParent = pCur;
				pCur = pCur->_pLeft;
			}
			else
			{
				pParent = pCur;
				pCur = pCur->_pRight;
			}
		}
		LOOP:
		if (nullptr == pCur)//不存在
			return false;
		if (nullptr == pCur->_pLeft)//已找到该节点，其左子树为空
		{
			if (pParent->_pLeft == pCur)//父节点的左子树是该节点
			{
				pParent->_pLeft = pCur->_pRight;
				free(pCur);
			}
			else                         //父节点的右子树是该节点
			{
				pParent->_pRight = pCur->_pRight;
				free(pCur);
			}
		}
		else if (nullptr == pCur->_pRight)//右子树为空
		{
			if (pParent->_pLeft == pCur)
			{
				pParent->_pLeft = pCur->_pLeft;
				free(pCur);
			}
			else
			{
				pParent->_pRight = pCur->_pLeft;
				free(pCur);
			}
		}
		else//左右子树都不为空
		{
			PNode pnr = pCur->_pRight;//右子树中最小节点
			pParent = pCur;
			while (pnr->_pLeft)
			{
				pParent = pnr;
				pnr = pnr->_pLeft;
			}
			pCur->_data = pnr->_data;
			pCur = pnr;
			goto LOOP;
		}
		return true;
	}
	void InOrder();
private:
	PNode _pRoot;
};*/
template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& data)
		:_pLeft(nullptr), _pRight(nullptr), _pParent(nullptr)
		, _data(data), _bf(0)
	{}
	AVLTreeNode<T>* _pLeft;
	AVLTreeNode<T>* _pRight;
	AVLTreeNode<T>* _pParent;
	T _data;
	int _bf;
};
//template<class T>
//typedef AVLTreeNode<T>* PNode;
template<class T>
bool Insert(const T& data)
{
	while (data.pParent)
	{
		if (pCur == pParent->_pLeft)
			pParent->_bf--;
		else
			pParent->_bf++;

		if (0 == pParent->_bf)
			break;
		else if (1 == pParent->_bf || -1 == pParent->_bf)
		{
			pCur = pParent;
			pParent = pCur->_pParent;
		}
		else
		{
			if (2 == pParent->_bf)
			{

			}
			else
			{

			}
		}
	}
	return true;
}

/*void _RotateR(PNode pParent)
{
	PNode pSubL = pParent->_pLeft;
	PNode pSubLR = pSubL->_pRight;

	pParent->_pLeft = pSubLR;
	if (pSubLR)
		pSubLR->_pParent = pParent;

	pSubL->_pRight = pParent;

	PNode pPParent = pParent->_pParent;

	pParent->_pParent = pSubL;
	
	pSubL->_pParent = pPParent;

	if (NULL == pPParent)
	{
		_pRoot = pSubL;
		pSubL->_pParent = NULL;
	}
	else
	{
		if (pPParent->_pLeft == pParent)
			pPParent->_pLeft = pSubL;
		else
			pPParent->_pRight = pSubL;
	}
	pParent->_bf = pSubL->_bf = 0;
}
void _RotateLR(PNode pParent)
{
	PNode pSubL = pParent->_pLeft;
	PNode pSubLR = pSubL->_pRight;

	int bf = pSubLR->_bf;

	_RotateL(pParent->_pLeft);

	_RotateR(pParent);

	if (1 == bf)
		pSubL->_bf = -1;
	else if (-1 == bf)
		pParent->_bf = 1;
}
int _Height(PNode pRoot);
bool _IsBalanceTree(PNode pRoot)
{
	if (nullptr == pRoot)
		return true;
	int leftHeight = _Height(pRoot->_pLeft);
	int rightHeight = _Height(pRoot->_pRight);
	int diff = rightHeight - leftHeight;

	if (diff != pRoot->_bf || (diff > 1 || diff < -1))
		return false;
	return _IsBalanceTree(pRoot->_pLeft) && _IsBalanceTree(pRoot->_pRight);
}*/
int main()
{

	/*BSTree<int> tree;
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	for (auto e : a)
		tree.Insert(e);
	BSTNode<int>* pn = tree.Find(3);
	cout << pn->_data<< " " << pn->_pLeft->_data << " " << pn->_pRight->_data << endl;
	//cout << tree.Erase(99) << endl;
	//cout << tree.Erase(7) << endl;
	tree.~BSTree();

	/*Solution so;
	string str[] = { "leetcode", "ia", "love", "coding", "i", "love", "coding" };
	vector<string>vec(str, str + 7);
	vector<string>ss(so.topKFrequent(vec, 4));
	for (auto s : ss)
		cout << s << endl;
	//TestSet();
	//TestMap();*/

	system("pause");
	return 0;
}
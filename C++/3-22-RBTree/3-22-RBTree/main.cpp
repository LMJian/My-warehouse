#include<iostream>
#include"RBTree.hpp"
using namespace std;

struct KeyOfValue
{
	int operator()(int data)
	{
		return data;
	}
};
void TestRBTree()
{
	int array[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	RBTree<int, KeyOfValue> tree;
	for (auto e : array)
	{
		tree.Insert(e);
	}
	tree.Inorder();
	if (tree.IsValidRBTree())
	{
		std::cout << "Is a valid RBTree" << std::endl;
	}
	else
	{
		std::cout << "Is a Invalid RBTree" << std::endl;
	}

	RBTree<int, KeyOfValue>::iterator it = tree.begin();
	while (it != tree.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

int main() {
	TestRBTree();
	system("pause");
	return 0;
}
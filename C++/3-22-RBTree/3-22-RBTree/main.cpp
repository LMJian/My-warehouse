#include<iostream>
#include"RBTree.hpp"
#include"Map.hpp"
#include"Set.hpp"
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

void TestMap()
{
	Map<std::string, std::string> m;
	m.insert(std::pair<std::string, std::string>("2222", "2222"));
	m.insert(std::make_pair("1111", "1111"));
	m["0000"] = "0000";
	std::cout << m.size() << std::endl;

	for (auto e : m)
	{
		cout << e.first << " " << e.second << endl;
	}
	std::cout << std::endl;
}
void TestSet()
{
	Set<std::string> m;
	m.insert("2222");
	m.insert("1111");
	m.insert("0000");
	std::cout << m.size() << std::endl;

	for (auto e : m)
	{
		printf("%s\n", e.c_str());
	}
	std::cout << std::endl;
}

int main() {
	//TestSet();
	TestMap();
	//TestRBTree();
	system("pause");
	return 0;
}
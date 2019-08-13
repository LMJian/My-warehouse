#include<iostream>
#include<list>
#include<vector>
using namespace std;

/*void print_list(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void PrintList(list<int>& L)
{
	for (auto&e : L)
		cout << e << " ";
	cout << endl;
}
void TestList1()
{
	int array[] = { 1, 2, 3 };
	list<int>L(array, array + sizeof(array) / sizeof(array[0]));

	L.push_back(4);
	L.push_front(0);
	PrintList(L);

	L.pop_back();
	L.pop_front();
	PrintList(L);
}
void TestList3()
{
	int array1[] = { 1, 2, 3 };
	list<int>L(array1, array1 + sizeof(array1) / sizeof(array1[0]));

	auto pos = ++L.begin();
	cout << *pos << endl;

	L.insert(pos, 4);
	PrintList(L);

	L.insert(pos, 5, 5);
	PrintList(L);

	vector<int>v{ 7, 8, 9 };
	L.insert(pos, v.begin(), v.end());
	PrintList(L);

	L.erase(pos);
	PrintList(L);

	L.erase(L.begin(), L.end());
	PrintList(L);
}
void TestList4()
{
	int array1[] = { 1, 2, 3 };
	list<int>L1(array1, array1 + sizeof(array1) / sizeof(array1[0]));
	PrintList(L1);

	list<int>L2;
	L1.swap(L2);
	PrintList(L1);
	PrintList(L2);

	L2.clear();
	cout << L2.size() << endl;
}*/
void TestListIterator1()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int>L(array, array + sizeof(array) / sizeof(array[0]));

	auto it = L.begin();
	while (it != L.end())
	{
		L.erase(it);
		++it;
	}
}
void TestListIterator()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int>L(array, array + sizeof(array) / sizeof(array[0]));
	auto it = L.begin();
	while (it != L.end())
	{
		L.erase(it++);
	}
}
int main()
{
	//TestListIterator1();
	TestListIterator();
	//TestList4();
	/*int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int>L(array, array + sizeof(array) / sizeof(array[0]));

	for (list<int>::iterator it = L.begin(); it != L.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	for (list<int>::reverse_iterator it = L.rbegin(); it != L.rend(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	print_list(L);
	/*std::list<int>L1;
	std::list<int>L2(4, 100);
	std::list<int>L3(L2.begin(), L2.end());
	std::list<int>L4(L3);

	int array[] = { 16, 2, 77, 29 };
	std::list<int>L5(array, array + sizeof(array) / sizeof(int));

	for (std::list<int>::iterator it = L5.begin(); it != L5.end(); it++)
		std::cout << *it << " ";
	std::cout << endl;

	for (auto& e : L5)
		std::cout << e << " ";

	std::cout << endl;*/

	system("pause");
	return 0;
}
#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

void PrintDeque(const std::deque<int>&d)
{
	for (const auto&e : d)
		cout << e << " ";
	cout << endl;
}
void TestDeque1()
{
	std::deque<int>d1;

	std::deque<int>d2(10, 5);
	PrintDeque(d2);

	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	std::deque<int>d3(array, array + sizeof(array) / sizeof(array[0]));
	PrintDeque(d3);

	std::deque<int>d4(d3);
	PrintDeque(d4);
}
void TestDeque2()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	std::deque<int>d(array, array + sizeof(array) / sizeof(array[0]));

	for (auto it = d.cbegin(); it != d.cend(); ++it)
		cout << *it << " ";
	cout << endl;

	auto cit = d.cbegin();
	//*cit = 100;

	for (auto it = d.crbegin(); it != d.crend(); ++it)
		cout << *it << " ";
	cout << endl;
}
void TestDeque3()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	std::deque<int>d1(array, array + sizeof(array) / sizeof(array[0]));

	d1.push_back(6);
	d1.push_front(2);
	PrintDeque(d1);
	cout << d1.size() << endl;
	cout << d1.front() << endl;
	cout << d1.back() << endl;

	d1.insert(d1.begin(), 0);
	PrintDeque(d1);

	d1.pop_front();
	d1.pop_back();
	d1.erase(d1.begin());
	PrintDeque(d1);

	d1.clear();
	cout << d1.size() << endl;
}
void TestDequeSort()
{
	int array[] = { 5, 2, 1, 9, 6, 3, 8, 7, 4, 0 };
	deque<int>d(array, array + sizeof(array) / sizeof(array[0]));
	PrintDeque(d);

	sort(d.begin(), d.end());
	PrintDeque(d);
}
int main()
{
	TestDequeSort();
	//TestDeque3();
	//TestDeque1();
	//TestDeque2();
	system("pause");
	return 0;
}
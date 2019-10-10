#include<iostream>
#include<vector>
using namespace std;

/*void PrintVector(const vector<int>& v)
{
	vector<int>::const_iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
class Solution{
public:
	vector<vector<int>>generate(int numRows)
	{
		vector<vector<int>>vv;
		vv.resize(numRows);
		for (size_t i = 1; i <= numRows; ++i)
		{
			vv[i - 1].resize(i, 0);
			vv[i - 1][0] = 1;
			vv[i - 1][i - 1] = 1;
		}
		for (size_t i = 0; i < vv.size(); ++i)
		{
			for (size_t j = 0; j < vv[i].size(); ++j)
			{
				if (vv[i][j] == 0)
				{
					vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
				}
			}
		}
		return vv;
	}
};*/
int main()
{

	int a[] = { 1, 2, 3, 4 };
	vector<int>v(a, a + sizeof(a) / sizeof(int));

	/*vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			v.erase(it);
		++it;
	}*/

	/*vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			it = v.erase(it);
		else
			++it;
	}
	/*vector<int>::iterator pos = find(v.begin(), v.end(), 1);
	v.erase(pos);
	cout << *pos << endl;

	pos = find(v.begin(), v.end(), 3);
	v.insert(pos, 30);
	cout << *pos << endl;

	/*v[0] = 10;
	cout << v[0] << endl;

	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	vector<int>swapv;
	swapv.swap(v);

	cout << "v data:";
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	cout << "swapv data:";
	for (size_t i = 0; i < swapv.size(); ++i)
	{
		cout << swapv[i] << " ";
	}
	cout << endl;

	for (auto x : swapv)
	{
		cout << x << " ";
	}
	cout << endl;
	/*vector<int>::iterator pos = find(v.begin(), v.end(), 3);

	v.insert(pos, 30);

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	pos = find(v.begin(), v.end(), 3);

	v.erase(pos);
	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	/*vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	v.pop_back();
	v.pop_back();

	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	/*std::vector<int>myvector;
	for (int i = 1; i < 10; i++)
		myvector.push_back(i);
	myvector.resize(5);
	myvector.resize(8, 100);
	myvector.resize(12);

	std::cout << "myvector contains:";
	for (int i = 0; i < myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	/*size_t sz;
	std::vector<int>bar;
	sz = bar.capacity();
	bar.reserve(10);
	std::cout << "making bar grow:\n";
	for (int i = 0; i < 10; i++)
	{
		bar.push_back(i);
		if (sz != bar.capacity())
		{
			sz = bar.capacity();
			std::cout << "capacity changed:" << sz << '\n';
		}
	}
	/*size_t sz;
	std::vector<int>foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		foo.push_back(i);
		if (sz != foo.capacity())
		{
			sz = foo.capacity();
			std::cout << "capacity changed:" << sz << '\n';
		}
	}
	/*vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	it = v.begin();
	while (it != v.end())
	{
		*it *= 2;
		++it;
	}

	vector<int>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	PrintVector(v);
	std::vector<int>first;
	std::vector<int>second(4, 100);
	std::vector<int>third(second.begin(), second.end());
	std::vector<int>fourth(third);

	int myints[] = { 16, 2, 77, 29 };
	std::vector<int>fifth(myints, myints + sizeof(myints) / sizeof(int));

	std::cout << "The contents of fifth are:";
	for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';*/

	system("pause");
	return 0;
}
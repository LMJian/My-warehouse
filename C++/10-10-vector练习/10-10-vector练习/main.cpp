#include<iostream>
using namespace std;
#include<vector>

#if 0
int main()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	// 使用find查找3所在位置的iterator
	auto it = v.begin();
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	// 删除pos位置的数据，导致pos迭代器失效。
	v.erase(pos);
	cout << *it << endl; // 此处会导致非法访问
	// 在pos位置插入数据，导致pos迭代器失效。
	// insert会导致迭代器失效，是因为insert可
	// 能会导致增容，增容后pos还指向原来的空间，而原来的空间已经释放了。
	pos = find(v.begin(), v.end(), 3);
	v.insert(pos, 30);
	cout << *pos << endl; // 此处会导致非法访问

	/*int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	// 通过[]读写第0个位置。
	v[0] = 10;
	cout << v[0] << endl;
	// 通过[i]的方式遍历vector
	for (size_t i = 0; i < v.size(); ++i)
		cout << v[i] << " ";	cout << endl;
	vector<int> swapv;
	swapv.swap(v);
	cout << "v data:";
	for (size_t i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << "swapv data:";
	for (size_t i = 0; i < swapv.size(); ++i)
		cout << swapv[i] << " ";
	cout << endl;

	// C++11支持的新式范围for遍历
	for (auto x : v)
		cout << x << " ";
	cout << endl;*/	
	system("pause");
	return 0;
}
/*void PrintVector(const vector<int>& v)
{
	// const对象使用const迭代器进行遍历打印
	vector<int>::const_iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
int main()
{
	// 使用push_back插入4个数据
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	// 使用迭代器进行遍历打印
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	// 使用迭代器进行修改
	it = v.begin();
	while (it != v.end())
	{
		*it *= 2;
		++it;
	}
	// 使用反向迭代器进行遍历再打印
	vector<int>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	PrintVector(v);
	system("pause");
	return 0;
}
int main()
{
	/*size_t sz;
	std::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i) {
		foo.push_back(i);		if (sz != foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
	std::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(10); // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i = 0; i < 10; ++i) {
		bar.push_back(i);
		if (sz != bar.capacity()) {
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}*/

	/*std::vector<int> myvector;// set some initial content:
	for (int i = 1; i < 10; i++)
		myvector.push_back(i);
	myvector.resize(5);
	myvector.resize(8, 100);
	myvector.resize(12);
	std::cout << "myvector contains:";
	for (int i = 0; i < myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';*/

	/*int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	vector<int>::iterator it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	v.pop_back();
	v.pop_back();
	it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;*/	/*int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	// 使用find查找3所在位置的iterator
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);

	// 在pos位置之前插入30
	v.insert(pos, 30);
	vector<int>::iterator it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	pos = find(v.begin(), v.end(), 3);
	// 删除pos位置的数据
	v.erase(pos);
	it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}*/#endif
int main()
{
	vector<int> vv{ 1,2,3,4,5,6,7 };
	auto it = vv.begin();
	printf("*it=%d,&(*it)=%p,it=%p\n", *it, &(*it), it);
	it++;
	printf("*it=%d,&(*it)=%p,it=%p\n", *it, &(*it), it);
	it--;
	printf("*it=%d,&(*it)=%p,it=%p\n", *it, &(*it), it);
	it = vv.erase(it);
	printf("*it=%d,&(*it)=%p,it=%p\n", *it, &(*it), it);
	system("pause");
	return 0;
}
#include<iostream>
#include"HashBucket.hpp"
#include"Unordered_map.hpp"
#include"Unordered_set.hpp"
#include<string>
using namespace std;

void TestUnorderedMAP()
{
	Unordered_map<string, string> m;

	// 构造键值对的两种方式：pair结构体  make_pair
	m.insert(pair<string, string>("宋江", "及时雨"));
	m.insert(pair<string, string>("李逵", "铁牛"));
	m.insert(pair<string, string>("林冲", "豹子头"));

	m.insert(make_pair("武松", "行者"));

	cout << m.size() << endl;
	cout << m.buck_count()<< endl;  // 桶的个数
	cout << m.buck_size(0) << endl;  // 0号桶中的元素个数
	cout << m.bucket("宋江") << endl;   // 获取key所在的桶号

	// key不能重复
	m.insert(make_pair("李逵", "黑旋风"));
	cout << m.size() << endl;


	// []：如果key存在，直接返回与key所对应的value
	cout << m["李逵"] << endl;   // 给一个key，返回与该key对应的value
	cout << m.size() << endl;

	// []: 如果key不存在，<key, 默认value>构建一个键值对，然后将其插入到容器中，返回默认的value
	cout << m["鲁达"] << endl;
	cout << m.size() << endl;

	m.erase("鲁达");
	cout << m.size() << endl;

	m.clear();
}

void TestUnorderedSet()
{
	Unordered_set<string> m;

	// 构造键值对的两种方式：pair结构体  make_pair
	m.insert("apple");
	m.insert("banana");
	m.insert("orange");
	m.insert("peach");

	cout << m.size() << endl;
	cout << m.buck_count()<< endl;  // 桶的个数
	cout << m.buck_size(0) << endl;  // 0号桶中的元素个数
	cout << m.bucket("orange") << endl;   // 获取key所在的桶号

	// key不能重复
	m.insert("apple");
	cout << m.size() << endl;

	m.erase("orange");
	cout << m.size() << endl;

	m.clear();
}
int main() {
	//TestUnorderedMAP();
	TestUnorderedSet();
	system("pause");
	return 0;
}
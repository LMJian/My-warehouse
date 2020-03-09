#include<iostream>
#include"UnorderedMap.hpp"
#include"UnorderedSet.hpp"
#include"HashBucket.hpp"
using namespace std;
void TestUnorderedMAP()
{
	bite::unordered_map<string, string> m;

	// 构造键值对的两种方式：pair结构体  make_pair
	m.insert(pair<string, string>("宋江", "及时雨"));
	m.insert(pair<string, string>("李逵", "铁牛"));
	m.insert(pair<string, string>("林冲", "豹子头"));

	m.insert(make_pair("武松", "行者"));

	cout << m.size() << endl;
	cout << m.bucket_count() << endl;  // 桶的个数
	cout << m.bucket_size(0) << endl;  // 0号桶中的元素个数
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
int main() {

	TestUnorderedMAP();
	system("pause");
	return 0;
}
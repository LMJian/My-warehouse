#include"HashBucket.hpp"
#include<iostream>
using namespace std;

/*void test_unordered_map() {
	unordered_map<string, string> m;
	//构造键值对的两种方式
	m.insert(pair<string, string>("宋江", "及时雨"));
	m.insert(pair<string, string>("李逵", "铁牛"));
	m.insert(pair<string, string>("林冲", "豹子头"));
	
	m.insert(make_pair("武松", "行者"));

	cout << m.size() << endl;
	cout << m.bucket_count() << endl;   //桶的个数
	cout << m.bucket_size(0) << endl;   //0号桶中的个数
	cout << m.bucket("宋江") << endl;   //获取key所在的桶号

	//key不能重复
	m.insert(make_pair("李逵", "黑旋风"));
	cout << m.size() << endl;

	cout << m["李逵"] << endl;   //返回value
	cout << m.size() << endl;
	//m["李明健"] = "张玉玉";
	//cout << m["李明健"] << endl;
	cout << m["鲁达"] << endl;
	cout << m.size() << endl;

	m.erase("鲁达");
	cout << m.size() << endl;

	m.clear();

}

void test_unordered_multimap() {
	unordered_multimap<string, string> m;
	//构造键值对的两种方式
	m.insert(pair<string, string>("宋江", "及时雨"));
	m.insert(pair<string, string>("李逵", "铁牛"));
	m.insert(pair<string, string>("林冲", "豹子头"));

	m.insert(make_pair("武松", "行者"));

	cout << m.size() << endl;
	cout << m.bucket_count() << endl;   //桶的个数
	cout << m.bucket_size(0) << endl;   //0号桶中的个数
	cout << m.bucket("宋江") << endl;   //获取key所在的桶号

	//key不能重复
	m.insert(make_pair("李逵", "黑旋风"));
	cout << m.size() << endl;

	m.erase("鲁达");
	cout << m.size() << endl;

	m.clear();
}
*/

int main() {
	//test_unordered_multimap();
	//test_unordered_map();
	TestHashBucket();
	system("pause");
	return 0;
}
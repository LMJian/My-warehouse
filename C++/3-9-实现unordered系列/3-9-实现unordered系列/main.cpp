#include<iostream>
#include"HashBucket.hpp"
#include"Unordered_map.hpp"
#include"Unordered_set.hpp"
#include<string>
using namespace std;

void TestUnorderedMAP()
{
	Unordered_map<string, string> m;

	// �����ֵ�Ե����ַ�ʽ��pair�ṹ��  make_pair
	m.insert(pair<string, string>("�ν�", "��ʱ��"));
	m.insert(pair<string, string>("����", "��ţ"));
	m.insert(pair<string, string>("�ֳ�", "����ͷ"));

	for (auto& e : m) {
		cout << e.first << "  " << e.second << endl;
	}

	m.insert(make_pair("����", "����"));

	cout << m.size() << endl;
	cout << m.buck_count()<< endl;  // Ͱ�ĸ���
	cout << m.buck_size(0) << endl;  // 0��Ͱ�е�Ԫ�ظ���
	cout << m.bucket("�ν�") << endl;   // ��ȡkey���ڵ�Ͱ��

	// key�����ظ�
	m.insert(make_pair("����", "������"));
	cout << m.size() << endl;


	// []�����key���ڣ�ֱ�ӷ�����key����Ӧ��value
	//cout << m["����"] << endl;   // ��һ��key���������key��Ӧ��value
	cout << m.size() << endl;

	// []: ���key�����ڣ�<key, Ĭ��value>����һ����ֵ�ԣ�Ȼ������뵽�����У�����Ĭ�ϵ�value
	//cout << m["³��"] << endl;
	cout << m.size() << endl;

	m.erase("³��");
	cout << m.size() << endl;

	m.clear();
}

void TestUnorderedSet()
{
	Unordered_set<string> m;

	// �����ֵ�Ե����ַ�ʽ��pair�ṹ��  make_pair
	m.insert("apple");
	m.insert("banana");
	m.insert("orange");
	m.insert("peach");

	cout << m.size() << endl;
	cout << m.buck_count()<< endl;  // Ͱ�ĸ���
	cout << m.buck_size(0) << endl;  // 0��Ͱ�е�Ԫ�ظ���
	cout << m.bucket("orange") << endl;   // ��ȡkey���ڵ�Ͱ��

	// key�����ظ�
	m.insert("apple");
	cout << m.size() << endl;

	m.erase("orange");
	cout << m.size() << endl;

	m.clear();
}
int main() {
	TestUnorderedMAP();
	//TestUnorderedSet();
	system("pause");
	return 0;
}
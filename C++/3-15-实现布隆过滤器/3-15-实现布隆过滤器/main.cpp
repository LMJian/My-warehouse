#include"BloomFilter.hpp"
#include<iostream>
using namespace std;

void TestBloomFilter() {
	BloomFilter<string, 100> bf;
	bf.insert("欧阳峰");
	bf.insert("欧阳克");
	bf.insert("霍都");
	bf.insert("金轮法王");
	bf.insert("灭霸");
	bf.insert("灰太狼");

	cout << bf.size() << endl;
	if (bf.find("过儿"))
		cout << "过儿是个坏人" << endl;
	else
		cout << "过儿是个大侠" << endl;
	if (bf.find("金轮法王"))
		cout << "金轮法王是个坏人" << endl;
	else
		cout << "金轮法王是个大侠" << endl;
}

int main() {
	TestBloomFilter();
	system("pause");
	return 0;
}
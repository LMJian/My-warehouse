#include"HashTable.hpp"
#include"HashBucket.hpp"
#include<iostream>
using namespace std;

void TestHashTable1() {
	int array[] = { 21,67,112 };
	HashTable<int> ht;
	for (auto e : array)
		ht.Insert(e);
	ht.Erase(67);
	cout << ht.Size() << endl;
	ht.Insert(87);
	ht.Insert(77);
	cout << ht.Size() << endl;
	if (ht.Find(87) != -1) {
		cout << "87 is in hashTable" << endl;
	}
	else {
		cout << "87 is not in hashtable" << endl;
	}
	ht.Erase(67);
	if (ht.Find(67) != -1) {
		cout << "67 is in hashTable" << endl;
	}
	else {
		cout << "67 is not in hashtable" << endl;
	}
	if (ht.Find(87) != -1) {
		cout << "87 is in hashTable" << endl;
	}
	else {
		cout << "87 is not in hashtable" << endl;
	}
}

void TestHashTable2() {
	HashTable<string, DFStr, false> ht;
	ht.Insert("1111");
	ht.Insert("2222");
	ht.Insert("3333");
	ht.Insert("4444");
	ht.Insert("1311");
	ht.Insert("2322");
	ht.Insert("3233");
	ht.Insert("4344");
}
void TestHashBucket1() {
	HashBucket<int> ht;
	int arr[] = { 1,4,7,9,6,5 };
	for (auto e : arr) {
		ht.InsertUnique(e);
	}
	cout << ht.size() << endl;
	ht.printHashBucket();

	ht.InsertUnique(44);
	ht.InsertUnique(54);
	ht.printHashBucket();

	ht.eraseUnique(44);
	if (ht.find(44))
		cout << "44 is in hashbucket" << endl;
	else
		cout << "44 is no in hashbucket" << endl;

	cout << ht.size() << endl;
	ht.printHashBucket();
}

void TestHashBucket2() {
	HashBucket<int> ht;
	int arr[] = { 1,1,1,2,2,3 };
	for (auto e : arr) {
		ht.InsertEqual(e);
	}
	cout << ht.size() << endl;
	ht.printHashBucket();

	ht.InsertEqual(44);
	ht.InsertEqual(54);
	ht.printHashBucket();

	ht.eraseEqual(1);
	if (ht.find(1))
		cout << "1 is in hashbucket" << endl;
	else
		cout << "1 is no in hashbucket" << endl;

	cout << ht.size() << endl;
	ht.printHashBucket();
}

int main() {
	//TestHashTable1();
	//TestHashTable2();
	//TestHashBucket1();
	TestHashBucket2();

	system("pause");
	return 0;
}
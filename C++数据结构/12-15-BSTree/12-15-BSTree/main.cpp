#include"BSTree.hpp"
void test() {
	int arr[] = { 5,3,4,1,7,8,2,6,0,9 };
	BSTree<int> tree;
	for (auto e : arr) {
		tree.Insert(e);
	}
	tree.InOrder();
	tree.Delete(5);
	tree.InOrder();
	cout << tree.Find(6)->_data << endl;
	cout << tree.LeftMost()->_data << endl;
	cout << tree.RightMost()->_data << endl;
}
int main() {
	test();
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}
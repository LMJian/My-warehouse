#include"AVLTree.hpp"
using namespace std;

void testAVLTree() {
	AVLTree<int> tree_a, tree_b;
	vector<int> a{ 16,3,7,11,9,26,18,14,15 };
	vector<int> b{ 4,2,6,1,3,5,15,7,16,14 };
	for (size_t i = 0; i < a.size(); ++i){
		tree_a.Insert(a[i]);
	}
	for (size_t i = 0; i < b.size(); ++i){
		tree_b.Insert(b[i]);
	}
	cout << tree_a.IsBalanceTree() << " " << tree_b.IsBalanceTree() << endl;
	cout << tree_a.Find(7)->_data << " " << tree_b.Find(15)->_data << endl;
	tree_a.Show();
	tree_b.Show();
	for (size_t i = 0; i < a.size(); ++i) {
		tree_a.DelNode(a[i]);
		tree_a.Show();
		cout<<tree_a.IsBalanceTree() << endl;
	}
	for (size_t i = 0; i < b.size(); ++i) {
		tree_b.DelNode(b[i]);
		tree_b.Show();
		cout << tree_b.IsBalanceTree() << endl;
	}
}
int main() {
	testAVLTree();
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}
#include<iostream>
using namespace std;
#include<list>

class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n == 0)
			return -1;
		list<int> arr;
		for (int i = 0; i < n; ++i) {
			arr.push_back(i);
		}
		auto it = arr.begin();
		for (int i = 0; i < n - 1; ++i) {
			int num = m;
			while (num--) {
				++it;
			}
			it = arr.erase(it);
		}
		return arr.front();
	}
};

/*int main() {

	/Solution sa;
	//sa.LastRemaining_Solution(10, 3);
	list<int> l{ 1,2,3,4,5,6,7,8,9 };
	list<int>::iterator it = l.end();
	cout << *it << endl;
	cout << *(++it) << endl;
	cout << *(++it) << endl;

	system("pause");
	return 0;
}*/
#include<iostream>
#include<math.h>
using namespace std;

int coun = 0;
bool key = true;

void Find(int n, int m, int sum) {
	if (n > m)
		return;
	if (n == m) {
		if (sum < coun)
			coun = sum;
		return;
	}
	for (int i = n - 1; i >= 2; --i) {
		if (n%i == 0 && key)
			Find(n + i, m, sum + 1);
	}
}
int main() {
	int n, m;
	while (cin >> n >> m)
	{
		coun = m - n;
		Find(n, m, 0);
		if (coun == m - n)
			cout << -1 << endl;
		else
			cout << coun << endl;
	}
	
		
	return 0;
}
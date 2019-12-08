#include<iostream>
using namespace std;

class Solution {
public:
	int Add(int num1, int num2)
	{
		if (num1 == 0)
			return num2;
		else if (num2 == 0)
			return num1;

		int n1 = (num1&num2) << 1;
		int n2 = num1 ^ num2;
		return Add(n1, n2);
	}
};

int main() {
	int a, b;
	cin >> a >> b;
	Solution sa;
	cout << sa.Add(a, b) << endl;
	system("pause");
	return 0;
}
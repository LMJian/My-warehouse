#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	while (cin >> n) {
		cout << n << " =";
		for (int i = 2; n != 1; ++i) {
			while (n%i == 0) {
				n /= i;
				if (n != 1)
					cout << " " << i << " *";
				else
					cout << " " << i << endl;
			}
		}
	}
	return 0;
}
// write your code here cpp
/*#include<iostream>
using namespace std;

long long toA(int n) {
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	long long a = 0;
	long long b = 1;
	long long c;
	for (int i = 3; i <= n; ++i) {
		c = (a + b)*(i - 1);
		a = b;
		b = c;
	}
	return c;
}
long long toB(int n) {
	long long ret = 1;
	for (int i = 2; i <= n; ++i)
		ret = ret * i;
	return ret;
}
int main() {
	int n;
	while (cin >> n) {
		long long a = toA(n);
		long long b = toB(n);
		double ret = 100.0*a / b;
		printf("%.2f%\n", ret);
	}
	return 0;
}*/

// write your code here cpp
#include<iostream>
#include<string>
using namespace std;

int main() {
	string a;
	string b;
	while (getline(cin, a), cin >> b) {
		getchar();
		int index = 0;
		int end;
		while (index < a.size()) {
			if (a[index] == '\"') {
				end = a.find('\"', index + 1);
				if (end - index - 1 == b.size() && a.find(b, index + 1) == index + 1) {
					//if(a.substr(index+1,end-index-1)==b){
					cout << "Ignore" << endl;
					break;
				}
				index = end + 2;
			}
			else {
				end = a.find(',', index);
				if (end - index == b.size() && a.find(b, index) == index) {
					//if(a.substr(index,end-index)==b){
					cout << "Ignore" << endl;
					break;
				}
				index = end + 1;
			}
		}
		if (index >= a.size())
			cout << "Important!" << endl;
	}
	return 0;
}
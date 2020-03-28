#include<iostream>
using namespace std;


int main() {
	int arr[9];
	char ch;
	for (int i = 0; i < 9; ++i) {
		cin >> arr[i];
		if (i != 8)
			cin >> ch;
	}
	if (arr[0] + arr[1] + arr[2] + arr[3] == arr[3] + arr[4] + arr[5] + arr[6] && arr[3] + arr[4] + arr[5] + arr[6] == arr[6] + arr[7] + arr[8] + arr[0])
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	system("pause");
	return 0;
}
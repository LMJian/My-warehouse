// write your code here cpp
/*#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> arr;
	arr.resize(100001);
	arr[1] = 1;
	arr[2] = 2;
	int index = -1;
	for (int i = 3; i <= 100000; ++i) {
		arr[i] = arr[i - 1] + arr[i - 2];
		if (arr[i] >= 1000000) {
			arr[i] = arr[i] % 1000000;
			if (index == -1)
				index = i;
		}
	}
	int n;
	while (cin >> n) {
		if (n < index)
			cout << arr[n] << endl;
		else
			printf("%06d\n", arr[n]);
	}
	return 0;
}*/

#include<iostream>
using namespace std;

int nor[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool Judge_leap(int y)
{
	if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))         
		return true;     
	else         
		return false;
}

int Earn(int y1, int y2, int m1, int m2, int d1, int d2)
{
	int money = 0;     
	if (m1 == 2 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 11)         
		money = 1;     
	else         
		money = 2;     
	while ((y1 != y2) || (m1 != m2) || (d1 != d2)) { 
		if (Judge_leap(y1))             
			nor[2] = 29;         
		else             
			nor[2] = 28;         
		if (d1 <= nor[m1]) { 
			if (m1 == 2 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 11) { 
				money += 1;                 
				d1++; 
			} 
			else { 
				money += 2;                 
				d1++; 
			} 
		} 
		else { 
			if (m1 == 12) { 
				y1++;         
				m1 = 1; 
				d1 = 1; 
			}
			else { 
				m1++;   
				d1 = 1;
			}
		}
	}
	return money;
}

int main()
{
	int y1, m1, d1;   
	int y2, m2, d2;   
	while (cin >> y1 >> m1 >> d1) { 
		cin >> y2 >> m2 >> d2;       
		cout << Earn(y1, y2, m1, m2, d1, d2) << endl;
	} 
	return 0;
}
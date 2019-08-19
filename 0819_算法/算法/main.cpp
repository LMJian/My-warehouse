#include<iostream>
using namespace std;

class Solution{
public:
	int Fibonacci(int n){
		if (n <= 0)
			return 0;
		if (n == 1 || n == 2)
			return 1;
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
};
class Solution2{
public:
	int Fibonacci(int n){
		if (n <= 0)
			return 0;
		if (n == 1 || n == 2)
			return 1;
		int *record = new int[n + 1];
		record[0] = 0;
		record[1] = 1;
		for (int i = 2; i <= n; i++){
			record[i] = record[i - 1] + record[i - 2];
		}
		return record[n];
		delete[] record;
	}
};
class Solution3{
public:
	int Fibonacci(int n){
		if (n <= 0)
			return 0;
		if (n == 1 || n == 2)
			return 1;
		int fn1 = 1;
		int fn2 = 1;
		int result = 0;
		for (int i = 3; i <= n; i++)
		{
			result = fn1 + fn2;
			fn1 = fn2;
			fn2 = result;
		}
		return result;
	}
};
int main()
{
	Solution3 s1;
	cout << s1.Fibonacci(6) << endl;



	system("pause");
	return 0;
}
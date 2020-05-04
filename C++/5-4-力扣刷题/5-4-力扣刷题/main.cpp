#include<iostream>
using namespace std;

class Solution {
public:
	int divide(int a, int b) {
		long long dividend = a;
		long long divisor = b;
		//判断溢出情况
		if (divisor == -1 && dividend == INT_MIN)
			return INT_MAX;
		//转换成正整数
		bool key = false;
		if (dividend < 0 && divisor < 0) {
			dividend = -dividend;
			divisor = -divisor;
		}
		else if (dividend < 0 || divisor < 0) {
			key = true;
			if (dividend < 0)
				dividend = -dividend;
			else
				divisor = -divisor;
		}
		//除数小于被除数返回0
		if (dividend < divisor)
			return 0;
		//开始计算
		long long sum = divisor;
		for (int i = 1;; ++i) {
			if (sum == dividend) {
				sum = pow(2, i - 1);
				if (key)
					sum = -sum;
				return sum;
			}
			if (sum > dividend) {
				sum = pow(2, i - 2) + dfs(dividend - (sum >> 1), divisor);
				if (key)
					sum = -sum;
				return sum;
			}
			sum = sum << 1;
		}
	}
private:
	int dfs(int a, int b) {
		//除数小于被除数返回0
		if (a < b)
			return 0;
		//开始计算
		long long sum = b;
		for (int i = 1;; ++i) {
			if (sum == a)
				return pow(2, i - 1);
			if (sum > a)
				return pow(2, i - 2) + dfs(a - (sum >> 1), b);
			sum = sum << 1;
		}
	}
};


int main() {
	Solution sa;
	cout << sa.divide(10, 3) << endl;
	system("pause");
	return 0;
}
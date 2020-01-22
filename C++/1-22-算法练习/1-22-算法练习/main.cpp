#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;


/*class Solution {
public:
	int myAtoi(string str) {
		auto left = str.begin();
		while (*left == ' ')
			++left;
		if (*left == '+' || *left == '-' || (*left >= '0'&&*left <= '9')) {
			int tmp = 1;
			if (*left == '+' || *left == '-') {
				if (*left == '-')
					tmp = -1;
				++left;
			}
			long long num = 0;
			int count = 0;
			while (left != str.end() && *left >= '0'&&*left <= '9') {
				++count;
				if (count > 10) {
					if (tmp == 1)
						return INT_MAX;
					else
						return INT_MIN;
				}
				num = num * 10 + (*left - '0');
				++left;
			}
			num = tmp * num;
			if (num < INT_MIN)
				return INT_MIN;
			else if (num > INT_MAX)
				return INT_MAX;
			else
				return int(num);
		}
		else
			return 0;
	}
};*/
class Solution {
public:
	bool isPalindrome(string s) {
		string str = "";
		auto it = s.begin();
		while (it != s.end()) {
			if (*it >= 'a'&&*it <= 'z')
				str += *it;
			else if (*it >= 'A'&&*it <= 'Z')
				str += (*it + 32);
			++it;
		}
		auto left = str.begin();
		auto right = str.end() - 1;
		while (left < right) {
			if (*left != *right)
				return false;
			++left;
			--right;
		}
		return true;
	}
};
int func(int i, int j) { 
	if (i <= 0 || j <= 0) 
		return 1; 
	return 2 * func(i - 3, j / 2); 
}

#include<cstring>
int main() {
	int a[ ] = { 2,4,6,8 }, *p=a, i; 
	for( i=0; i<4; i++ ) 
		a[i]=*p++; 
	printf( "%d\n" ,a[2] ); 
	//cout<<func(15, 20) << endl;
	/*Solution sa;
	cout << sa.isPalindrome("0P") << endl;
	/*char s[] = "abcdefgh", *p = s; 
	p += 3; 
	printf("%d\n", strlen(strcpy(p, "ABCD")));*/
	system("pause");
	return 0;
}
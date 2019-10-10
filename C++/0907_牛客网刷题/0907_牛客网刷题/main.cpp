#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Base{
	char data[3];
public:
	virtual void f(){}
	virtual void g(){}
	virtual void h(){}
};
int main()
{
	char c1, c2;
	int a1, a2;
	c1 = getchar();
	scanf("%2d", &a1);
	c2 = getchar();
	scanf("%3d", &a2);
	printf("%d,%d,%c,%c\n", a1, a2, c1, c2);
	/*cout << sizeof(Base) << endl;
	/*struct st
	{
		char p[250];
		char b;
	};
	cout << sizeof(struct st) << endl;
	/*int a, b;
	a = [1, 2, 3];
	b = [1, 2, 4];
	/*int arr[10];
	int(&rarr)[10] = arr;
	/*int a = 1, b = 3, c = 5, d = 4;
	int x;
	if (a < b)
		if (c < d)
			x = 1;
		else
			if (a < c)
				if (b < d)
					x = 2;
				else
					x = 3;
			else
				x = 6;
	else
		x = 7;

	cout << x << endl;*/

	system("pause");
	return 0;
}
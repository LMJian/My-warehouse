#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//#define F(x,y) ((x)+(y))
//int x2;
/*bool find(int arr[][4], int num)
{
	int x = 0;
	while (x < 4)
	{
		for (int i = x; i < 4; i++)
		{
			if (arr[x][i] == num)
				return true;
		}
		for (int i = x + 1; i < 4; i++)
		{
			if (arr[i][x] == num)
				return true;
		}
		if (arr[x + 1][x + 1] > num)
			return false;
		else
			x++;
	}
	return false;
}
void replace(char *string)
{
	char *end = string;
	while (*end != '\0')
		end++;

	while (*string != '\0')
	{
		if (*string == ' ')
		{
			for (char *p = end; p > string; p--)
				*(p + 2) = *p;
			end = end + 2;
			*string = '%';
			*(string + 1) = '2';
			*(string + 2) = '0';
			string = string + 3;
		}
		else
			string++;
	}
}
int Fib(int n)
{
	int num1, num2, tmp;
	tmp = num1 = num2 = 1;
	for (int i = 3; i <= n; i++)
	{
		tmp = num1 + num2;
		num1 = num2;
		num2 = tmp;
	}
	return tmp;
}*/
#pragma pack(4)
int main(int argc,char* argv[])
{
	struct tagTest1
	{
		short a;
		char d;
		long b;
		long c;
	};
	struct tagTest2
	{
		long b;
		short c;
		char d;
		long a;
	};
	struct tagTest3
	{
		short c;
		long b;
		char d;
		long a;
	};
	struct tagTest1 stT1;
	struct tagTest2 stT2;
	struct tagTest3 stT3;
	printf("%d   %d   %d\n", sizeof(stT1), sizeof(stT2), sizeof(stT3));

	//cout << sizeof(long) << endl;
	/*int i = 1, sum = 0;
	while (i < 10)
	{
		sum = sum + 1;
		i++;
	}
	printf("%d %d ", i, sum);

	/*int x;
	x = 5 > 1 + 2 && 2;// || 2 * 4 < 4 - !0;
	cout << (5 > 1 + 2 && 2) << endl;
	cout << x << endl;
	/*int a = 3, b = 4;
	printf("%d\n", F(a++, b++));
	/*char a[20];
	char *p1 = (char*)a;
	char *p2 = (char*)(a + 5);
	int n = p2 - p1;
	cout << n << endl;
	/*cout << Fib(9) << endl;
	/*char acHello[] = "hello\0world";
	char acNew[15] = { 0 };
	strcpy(acNew, acHello);
	cout << strlen(acNew) << endl;
	cout << sizeof(acHello) << endl;
	/*int x, y, z;
	x = z = 2, y = 3;
	if (x > y)
		z = 1;
	else if (x == y)
		z = 0;
	else
		z = -1;
	cout << z << endl;
	/*double **a[3][4];
	cout << sizeof(a) << endl;
	/*int a = 5;
	if (a = 0)
	{
		printf("%d", a - 10);
	}
	else
	{
		printf("%d", a++);
	}

	/*char arr[] = "abc defgx yz";
	replace(arr);
	cout << arr << endl;
	/*int i = 0;
	while (i < 10){
		if (i < 1)
			continue;
		if (i == 5)
			break;
		i++;
	}
	/*int a = 10;
	cout << (a += a *= a -= a / 3) << endl;
	/*const char *p = "Hello!";
	*p = 'C';
	printf("%c\n", *p);
	/*typedef struct{
		int a;
		char b;
		short c;
		short d;
	}AA_t;
	cout << sizeof(AA_t) << endl;
	//cout << sizeof(short) << endl;
	/*int a[2][2] = { { 1 }, { 2 } };
	int b[][2] = { 1, 2, 3, 4 };
	int c[2][2] = { { 1 }, 2, 3 };
	int d[2][] = { { 1, 2 }, { 3, 4 } };
	/*cout << (0x13 & 0x17) << endl;
	cout << (0x13 | 0x17) << endl;
	/*int arr[4][4] = {
		1, 2, 7, 9,
		2, 4, 9, 12,
		4, 7, 10, 13,
		6, 8, 11, 15
	};
	cout << find(arr, 8) << endl;
	/*int a[4][5];
	cout << a[1] + 3 << endl;
	cout << &a[1][3] << endl;
	cout << sizeof(a[1]) << endl;
	/*int x1=9;
	printf("%d\n%d\n", x1, x2);
	/*INT_PTR a, b;
	int_ptr c, d;
	int x = 0;
	/*a = &x;
	b = &x;
	c = &x;
	d = &x;
	/*cout << sizeof(a) << endl;
	cout << sizeof(b) << endl;
	cout << sizeof(c) << endl;
	cout << sizeof(d) << endl;

	/*char a=0;
	int b=0;
	float c=0.0;
	double d = 1.0;
	float max;
	max = a*b + d - c;
	/*int i, j, a = 0;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (j % 2)
				break;
			a++;
		}
		a++;
	}
	printf("%d\n", a);
	/*int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 }, *q[4], k;
	for (k = 0; k < 4; k++)
		q[k] = &a[k * 3];
	//printf("%p\n", &q[0]);
	//printf("%p\n", &q[3][1]);
	printf("%d\n", *q[0]);//1
	printf("%d\n", *q[1]);//4
	printf("%d\n", *q[2]);//7
	printf("%d\n", *q[3]);//10
	//printf("%d\n", *q[4]);
	printf("%d\n", q[1][0]);
	printf("%d\n", q[3][1]);*/

	system("pause");
	return 0;
}
#pragma pack()
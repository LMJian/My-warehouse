#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

/*int fun(int x, int y)
{
	static int m = 0;
	static int i = 2;
	i += m + 1;
	m = i + x + y;
	return m;
}
int count(unsigned int x)
{
	int count = 0;
	while (x)
	{
		if (x & 1)
			count++;
		x = x >> 1;
	}
	return count;
}
int change(int *px)
{
	int y = 8;
	y = y - *px;
	px = &y;
	return 0;
}
int fun(int x)
{
	int count = 0;
	while (x)
	{
		count++;
		x = x&(x - 1);
	}
	return count;
}
#define CIR(r) r*r
unsigned long g_ulGlobal = 0;
void GlobalInit(unsigned long ulArg)
{
	ulArg = 0x01;
	return;
}
int fun(int a, int b)
{
	if (a > b)
		return(a + b);
	else
		return (a - b);
}*/
/*int f(int a)
{
	int b = 0;
	static int c = 3;
	a = (c++, b++);
	return (a);
}
void f()
{

}
int x = 3;
void inc()
{
	static int x = 1;
	x *= (x + 1);
	printf("%d", x);
	return;
}
int a = 1;
void test()
{
	int a = 2;
	a += 1;
}
#define MOD(x,y) x%y
int findMin(int *arr, int arrlen, int k)
{
	int min = arr[0];
	for (int i = 1; i < k&&i < arrlen; i++)
	{
		if (min > arr[i])
			min = arr[i];
	}
	return min;
}
int find(int *arr, int arrlen)
{
	int maze[100] = { 0 };
	for (int i = 0; i < arrlen; i++)
	{
		maze[arr[i]]++;
		if (maze[arr[i]] > arrlen / 2.0)
			return arr[i];
	}
	return -1;
}
void Func(char str_arg[2])
{
	int m = sizeof(str_arg);
	int n = strlen(str_arg);
	printf("%d\n", m);
	printf("%d\n", n);
}
#define MIN(a,b) ((a)<(b)?(a):(b))
int maxSum(int *arr, int arrlen)
{
	int *maze = (int*)malloc(sizeof(int)*arrlen);
	maze[0] = arr[0];
	for (int i = 1; i < arrlen; i++)
	{
		if (arr[i] >= 0)
		{
			if (maze[i - 1] < 0)
				maze[i] = arr[i];
			else
				maze[i] = maze[i - 1] + arr[i];
		}
		else
		{
			maze[i] = maze[i - 1] + arr[i];
		}
	}
	int max = maze[arrlen - 1];
	for (int i = arrlen - 2; i >= 0; i--)
	{
		if (max < maze[i])
			max = maze[i];
	}
	return max;
}
char *myString()
{
	char buffer[6] = { 0 };
	char *s = "Hello world!";
	for (int i = 0; i < sizeof(buffer) - 1; i++)
	{
		buffer[i] = *(s + i);
	}
	return buffer;
}
char find(char *arr)
{
	int maze[128] = { 0 };
	char *pt = arr;
	while (*pt != '\0')
	{
		maze[*pt - '\0']++;
		pt++;
	}
	while (*arr != '\0')
	{
		if (maze[*arr - '\0'] == 1)
			return *arr;
		arr++;
	}
	return -1;
}
int fun(char *s)
{
	char *p = s;
	while (*p != '\0')
	{
		p++;
	}
	return (p - s);
}*/
char find(char *s)
{
	int maze[128] = { 0 };
	while (*s != '\0')
	{
		maze[*s - '\0']++;
		if (maze[*s - '\0'] == 2)
			return *s;
		s++;
	}
	return -1;
}
int main()
{
	char arr[] = "qywyer23tdd";
	cout << find(arr) << endl;
	/*const int i = 0;
	int *j = (int*)&i;
	*j = 1;
	printf("%d,%d\n", i, *j);
	/*unsigned char a = 0xA5;
	//printf("%d\n", ~a);
	unsigned char b = ~a >> 5;
	printf("%d\n", b);
	//int a[4] = { 0 };
	//a++;
	/*int arr1[4] = { 0 };
	int arr2[4] = { 1 };
	//printf("%d\n", fun("goodbye!"));
	/*char arr[] = "a baccdeff";
	cout << find(arr) << endl;
	/*char a[1000];
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = (char)(-1 - i);
	}
	printf("%d\n", strlen(a));
	/*int i = 1;
	printf("%d\n", sizeof(i++));
	printf("%d\n", i);
	/*printf("%s\n", myString());
	/*int x[] = { 1, 2, 3, 4, 5, 6 }, *p = x;
	//cout << (p += 2, *++p) << endl;
	//cout << (p += 2, *p++) << endl;
	//cout << (p += 3, *p) << endl;
	cout << (p += 2, ++*p) << endl;
	/*char *str[3] = { "stra", "strb", "strc" };
	char *p = str[0];
	int i = 0;
	while (i < 3)
	{
		printf("%s   ", *str);
		i++;
	}
	/*char *p1 = "ABC";
	char *p2 = "ABC";
	printf("%p\n%p\n", p1, p2);
	/*int arr[] = { 1, -2, 3, 10, 27, -99, 2, 12 };
	cout << maxSum(arr, 8) << endl;
	/*int a[5] = { 1, 2, 3, 4, 5 };
	int *p1 = (int*)(&a + 1);
	int *p2 = (int*)((int)a + 1);
	int *p3 = (int*)(a + 1);
	printf("%p\n%p\n", p1, p3);
	printf("%d %x %d\n", p1[-1], p2[0], p3[1]);

	/*printf("%d\n", MIN(59,9));
	/*const char *p = "hello£¬world";
	char *pt;
	printf("%p\n", p);
	printf("%p\n", &p);
	printf("%p\n", &pt);

	/*union X
	{
		int x;
		char y[4];
	}a;
	a.x = 0x11223344;
	printf("%0x\n", a.y[0]);
	printf("%0x\n", a.y[1]);
	printf("%0x\n", a.y[2]);
	printf("%0x\n", a.y[3]);
	/*cout << (1 << 3 + 2) << endl;
	/*char str[2] = "h";
	cout << sizeof(str) << endl;
	//Func(str);
	/*int array[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	cout << find(array, 9) << endl;
	/*unsigned long ulA = 0x11000000;
	printf("%x\n", *(unsigned char*)&ulA);
	/*char *pcColor = "blue1";
	char acColor[] = "blue1";
	cout << strlen(pcColor) << endl;
	cout << strlen(acColor) << endl;
	cout << sizeof(pcColor) << endl;
	cout << sizeof(acColor) << endl;
	/*int s = 0, n;
	for (n = 0; n < 4; n++)
	{
		switch (n)
		{
		default:s += 4;
		case 1:s += 1;
		case 2:s += 2;
		case 3:s += 3;
		}
	}
	printf("%d\n", s);
	/*char s[] = "\\123456\123456\t";
	printf("%c\n", s[0]);
	printf("%d\n", strlen(s));
	/*typedef char STRING[255];
	STRING s;
	int x = s;
	/*int array[] = { 7, 5, 3, 6, 2, 1, 4, 9, 8, 0 };
	cout << findMin(array, 10, 6) << endl;
	/*int x = 0;
	switch (++x)
	{
	case 0:++x;
	case 1:++x;
	case 2:++x;
	}
	cout << x << endl;
	/*int a = 13, b = 94;
	printf("%d\n", MOD(b, a + 4));
	/*int i = 0;
	int j = 0;
	if ((++i > 0) || (++j > 0))
	{
		printf("%d %d", i, j);
	}
	/*test();
	printf("%d\n", a);
	/*int m, n;
	for (m = 0, n = -1; n = 0; m++, n++)
		n++;
	/*int i;
	for (i = 1; i < x; i++)
	{
		inc();
	}
	/*void();
	pt = f;
	/*int a = 2, i, k;
	for (i = 0; i < 2; i++)
	{
		k = f(a++);
	}
	printf("%d\n", k);
	/*int a = 4;
	int x = ++(a++);
	cout << x << endl;
	/*int x = 3, y = 8, z = 6, r;
	r = fun(fun(x, y), 2 * z);
	printf("%d\n", r);
	/*GlobalInit(g_ulGlobal);
	printf("%lu", g_ulGlobal);
	/*int a = 1;
	int b = 2;
	int t = CIR(a + b);
	cout << t << endl;
	//printf("fun(2017)=%d\n", fun(2019));
	/*int a = 4, b = 3, *p, *q, *w;
	p = &a;
	q = &b;
	w = q;
	q = NULL;
	
	//*q = 0;
	w = p;
	*p = a;
	*p = *w;
	/*char x = 0xe5;
	cout << (int)x << endl;
	/*char arr[2][4];
	strcpy((char*)arr, "you");
	strcpy(arr[1], "me");
	arr[0][3] = '&';
	printf("%s\n", arr);

	/*int xx = 3;
	int *py = &xx;
	change(py);
	printf("%d\n", *py);
	/*unsigned int x = 123;
	cout << count(x) << endl;
	/*int j = 4;
	int m = 1;
	int k;
	k = fun(j, m);
	printf("%d,", k);
	k = fun(j, m);
	printf("%d\n", k);
	/*enum ENUM_A
	{
		x1,
		y1,
		z1=5,
		a1,
		b1
	};
	enum ENUM_A enumA = y1;
	enum ENUM_A enumB = b1;
	cout << enumA << endl;
	cout << enumB << endl;*/

	system("pause");
	return 0;
}
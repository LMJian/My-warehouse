#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
using namespace std;

/*int*& f(int*& p)
{
	int& arr[3] = { 3, 6, 4 };
	return arr;
}
int f(int x, int y)
{
	return (x&y) + ((x^y) >> 1);
}
void fun(int x, int y, int* c, int *d)
{
	*c = x + y;
	*d = x - y;
}
void find(int *arr, int arrlen)
{
	sort(arr, arr+arrlen);
	for (int i = 0; i < arrlen; i++)
	{
		if (i == arrlen - 1)
			printf("%d ", arr[i]);
		else if (arr[i] != arr[i + 1])
			printf("%d ", arr[i]);
		else
			i++;
	}
}
#define sum(a,b,c) a+b+c
int f(int n)
{
	static int i = 1;
	if (n >= 5)
		return n;
	n = n + i;
	i++;
	return f(n);
}
int func()
{
	int i, j, k = 0;
	for (i = 0, j = -1; j = 0; i++, j++)
		k++;
	return k;
}
void del(char *s1, char *s2)
{
	while (*s2 != '\0')
	{
		char *pt = s1;
		while (*pt != '\0')
		{
			if (*pt == *s2)
			{
				char *ptt = pt;
				while (*ptt != '\0')
				{
					*ptt = *(ptt + 1);
					ptt++;
				}
			}
			else
				pt++;
		}
		s2++;
	}
}
bool judge(int num)
{
	int arr[10] = { 0 };
	int arrlen = 0;
	while (num)
	{
		arr[arrlen++] = num % 10;
		num = num / 10;
	}
	for (int i = 0; i < arrlen / 2; i++)
	{
		if (arr[i] != arr[arrlen - 1 - i])
			return false;
	}
	return true;
}
int pow(int x, int y)
{
	int sum = 1;
	for (int i = 0; i < y; i++)
		sum *= x;
	return sum;
}
void foo(int b[][3])
{
	++b;
	b[1][1] = 9;
}*/
int judge(int num)
{
	while (num != 1 && num % 2 == 0)
	{
		num = num / 2;
	}
	if (num == 1)
		return 1;
	else
		return 0;
}
void compressedString(char *str)
{
	int slen = strlen(str) + 1;
	char *arr = (char*)malloc(slen);
	int arrlen = 0;
	int count = 0;
	char ch=str[0];
	for (int i = 0; i < slen - 1; i++)
	{
		if (str[i] == ch)
			count++;
		else
		{
			if (count != 1)
				arr[arrlen++] = '0' + count;
			arr[arrlen++] = ch;
			ch = str[i];
			count = 1;
		}
	}
	if (count != 1)
		arr[arrlen++] = '0' + count;
	arr[arrlen++] = ch;
	arr[arrlen] = '\0';
	strcpy(str, arr);
}
int func(int a)
{
	int b = 0;
	static int c = 3;
	a = c++, b++;
	return a;
}

void delSpace(char *s)
{
	char *sp = s;
	int slen = strlen(s) + 1;
	char *arr = (char*)malloc(slen);
	int arrlen = 0;
	while (*s == ' ')
		s++;
	while (*s != '\0')
	{
		if (*s != ' ')
		{
			arr[arrlen++] = *s;
			s++;
		}
		else
		{
			if (*(s - 1) != ' ')
				arr[arrlen++] = ' ';
			while (*s == ' ')
				s++;
		}
	}
	if (arr[arrlen - 1] == ' ')
		arr[arrlen - 1] = '\0';
	else
		arr[arrlen] = '\0';
	strcpy(sp, arr);
}
void findIndex(int *arr, int arrlen, int k)
{
	int *left = arr;
	int *right = arr + arrlen - 1;
	while (*left + *right != k&&left < right)
	{
		if (*left + *right < k)
			left++;
		else
			right--;
	}
	printf("%d,%d\n", left - arr, right - arr);
}
int main()
{
	int arr[] = { 1, 4, 7, 8, 12, 26 };
	findIndex(arr, 6, 16);
	/*char a[] = "asadadq";
	delSpace(a);
	cout << a;
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
	/*int a = 2, i, k;
	for (i = 0; i < 2; i++)
	{
		k = func(a++);
	}
	printf("%d\n", k);
	/*char str[5] = { 'g', 'o', 'o', 'd', '!' };
	cout << str << endl;
	/*int b[][3] = { { 1, 2 }, { 0 } };
	/*char arr[] = "xxxyz";
	compressedString(arr);
	cout << arr << endl;
	/*int x = 4;
	x += x *= x + x;
	cout << x << endl;
	/*int x = 6, n = 5;
	x += n++;
	cout << x << endl;
	/*int a, *p;
	p = a;
//	cout << judge(60) << endl;
	/*int i, x, y;
	i = x = y = 0;
	do{
		++i;
		if (i % 2)
			x += i,
			i++;
		y += i++;
	} while (i <= 7);
	printf("%d   %d   %d\n", i, x, y);
	/*int a, b;
	cout << (a = 2, b = 5, a++, b++, a + b) << endl;
	//cout << (double)(10 / 4 * 4) << endl;
	/*int i, j = 0;
	for (i = 0; i < 10; i--);
	for (i = 0; i < 10, j < 10; i++);
	for (i = 0; i++);
	for (i = 0; i < 10, j < 10; i++);
	/*char ch = -1;
	printf("%d\n", ch);
	/*int For, -abc, IF;
	int For, _abc, IF;
	int 2_a, xyz, b1_s;
	int void, d, WORD;
	/*int i = 6;
	if (i <= 6)
		printf("hello\n");
	else
		printf("bye-bye\n");

/*#define N 3
#define Y(n) ((N+1)*n)
	int z = 2 * (N + Y(5 + 1));
	cout << z << endl;
	/*int i = 10;
	long long t = sizeof(i++);
	printf("%d", i);
	/*int x = 0, y = 0, z = 0;
	z = (x == 1) && (y = 2);
	printf("%d", y);
	/*int a[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	foo(a);
	printf("%d", a[2][1]);
	//int x = 0x12345678;
	/*int i;
	char ac[20] = { 0 };
	for (i = 0; i < 10; i++)
		ac[i] = '0';
	printf("%d\n", strlen(ac));
	/*char *sz = "abcde";
	sz += 2;
	printf("%lu\n", sz);

	/*unsigned x = 1;
	switch (x)
	{
	case 1:printf("ASASA");
		break;
	case 4:
		printf("4");
		break;

	}
	/*unsigned long pul[] = { 6, 7, 8, 9, 10 };
	unsigned long *pulp;
	pulp = pul;
	*(pulp + 2) += 2;
	printf("%d,%d\n", *pulp, *(pulp + 2));
	/*cout << pow(2, 3) << endl;
	/*char ch = 'B' + '8' - '3';
	cout << ch << endl;
	/*unsigned short sht = 0;
	sht--;
	printf("%d", sht);

	/*int arr[] = { 1, 2, 3, 4, 5 };
	int *ptr = (int*)(&arr + 1);
	printf("%d %d\n", *(arr + 1), *(ptr - 1));
	/*int a[12] = { 1, 4, 7, 10, 2, 5, 8, 11, 3, 6, 9, 12 };
	int i = 10;
	cout << a[a[i]] << endl;
	/*int x = 1, y = 012;
	printf("%d", y*x++);
	/*int j = 4;
	int i = j;
	for (; i <= 2 * j; i++)
	{
		switch (i / j)
		{
		case 0:
		case 1:
			printf("*");
			break;
		case 2:
			printf("#");
		}
	}
	/*unsigned int a = 0xFFFFFFF7;
	unsigned char i = (unsigned char)a;
	char *b = (char*)&a;
	printf("%08x,%08x", i, *b);

	/*char str[] = "ABCDEFG";
	char *p1, *p2;
	p1 = "abcd"; p2 = "efgh";
	strcpy(str + 1, p2 + 1);
	strcpy(str + 3, p1 + 3);
	printf("%s\n", str);
	/*char a[] = "123456789", *p = a;
	int i = 0;
	while (*p)
	{
		if (i % 2 == 0)
			*p = '!';
		i++; p++;
	}
	puts(a);
	//cout << judge(121) << endl;
	/*int arr[] = { 6, 7, 8, 9, 10 };
	int *ptr = arr;
	*(ptr++) += 123;
	printf("%d,%d", *ptr, *(ptr++));
	/*int k, j, s;
	for (k = 2; k < 6; k++, k++)
	{
		s = 1;
		for (j = k; j < 6; j++)
		{
			s += j;
		}
	}
	printf("%d\n", s);
	/*int a = 2, *p1, **p2;
	p2 = &p1;
	p1 = &a;
	a++;
	printf("%d %d %d\n", a, *p1, **p2);
	/*struct student{
		char name[10];
		int age;
		char gender;
	}std[3],*p=std;
	scanf("%d", &(*p).age);
	scanf("%c", &std[0].gender);
	scanf("%c", &(p->gender));
	scanf("%s", &std.name);
	/*int c[] = { 1, 3, 5 };
	int *k = c + 1;
	printf("%d", *++k);
	/*char s1[] = "They are students.";
	char s2[] = "aeiou";
	del(s1, s2);
	cout << s1 << endl;
	//printf("%d\n", (func()));
	//printf("%d\n", f(1));
	/*int i = 3;
	int j = 2;
	printf("%d\n", i*sum(i, (i + j), j));
	/*int i = 5;
	i = MA(i, i + 1) - 7;
	cout << i << endl;
	/*int c[] = { 1, 3, 5 };
	int *k = c + 1;
	printf("%d", *++k);
	/*int a[] = { 0, 2, 4, 6, 8, 10 }, *p = a + 1;
	cout << (*(--p)) << endl;
	//find(arr, 9);
	/*int a = 4, b = 3, c = 0, d = 0;
	fun(a, b, &c, &d);
	printf("%d %d\n", c, d);
	/*int res = f(2, 4);
	printf("%d\n", res);
	/*int a[4][10] = { 0 };
	memset(a, 1, sizeof(a));
	int i = 1, j = 2;
	cout << (*(a + i) + j) << endl;
	cout << (*(&a[0][0] + 10 * i + j)) << endl;
	cout << (*(a[i] + j)) << endl;
	cout << (*(*(a + i) + j)) << endl;
	/*int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int *p = a;
	int i;
	cout << a[p - a] << endl;
	cout << *(&a[0]) << endl;
	cout << p[0] << endl;
	cout << a[10] << endl;*/
	//int arr[3] = { 1, 5, 6 };

	system("pause");
	return 0;
}
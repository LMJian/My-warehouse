#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

void fun(int argc, char **argv)
{
	int n = 9, i;
	for (i = 1; i < argc; i++)
	{
		n = n * 10 + *argv[i] - '0';
	}
	printf("%d\n", n);
}
class A
{
	char a[3];
public:
	virtual void fun1(){};
};
class B :public virtual A
{
	char b[3];
public:
	virtual void fun2(){};
};
class C :public virtual B
{
	char c[3];
public:
	virtual void fun3(){};
};

int main()
{
	char *str[3] = { "stra", "strb", "strc" };
	char **p = str;
	int i = 0;
	while (i < 3)
	{
		printf("%s", *p++);
		i++;
	}
	/*cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
	cout << sizeof(C) << endl;

	/*int argc;
	char 
	fun();
	/*float a;
	unsigned b;
	//scanf("%6.2f%d", &a, &b);
	//scanf("%f%n", &a, &b);
	//scanf("%f%3o", &a, &b);
	scanf("%f%f", &a, &b);
	printf("%f\n%d\n", a, b);
	/*int a = 24;
	printf("%0X", a);
	/*printf("a\0X41");
	printf("b\0x41");
	//printf("c\X41");
	printf("d\x41");
	printf("e\a");
	printf("f\b");
	//printf("g\c");
	printf("h\ri");*/
	
	system("pause");
	return 0;
}
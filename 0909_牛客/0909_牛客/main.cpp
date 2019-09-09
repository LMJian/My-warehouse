#include<iostream>
#include<math.h>
using namespace std;

/*class A
{
public:
	A(int x)
		:a(x)
	{}
	int a;
};
class B :public A
{
public:
	B()
		//:a(-1)
		: b(1)
		, A(-2)
	{}
	int b;
};*/
//#define product(x) ((x)*(x))
/*class W
{
	int a;
public:
	void fConst(int&)const;
};
void W::fConst(int& k)const
{
	k = a;
	k = a++;
	cin >> a;
	a = k;
}
char* test1()
{
	char arr[] = "123";
	return arr;
}
void test3()
{
	char str[10];
	char *pa = str;
	pa++;
	*pa = '0';
}*/
char *getMem(void){
	char p[] = "hello world ";
	p[5] = 0x0;
	return p;
}
void test(void){
	char *s = 0x0;
	s = getMem();
	printf(s);
}
int main()
{
	//char *s = "123";
	//printf(s);
	test();
	/*test3();
	//cout << test1() << endl;
	/*int i = 3, j, k;
	j = (i++)*(i++);
	k = (++i)*(++i);
	//j = product(i++);
	//k = product(++i);
	printf("%d %d", j, k);
	/*B b;*/

	system("pause");
	return 0;
}
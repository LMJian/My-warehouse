#include<iostream>
#include<vector>
using namespace std;


/*class A
{
public:
	int test(int a, int b)
	{
		return a + b;
	}
};
class B :public A
{
public:
	int test(int a, int b)
	{
		return a + b;
	}
};

inline int Add(int a, int b)
{
	return a + b;
}*/
class A
{
public:
	A()
	{
		cout << "A" << endl;
	}
	~A()
	{
		cout << "~A" << endl;
	}
};
void test()
{
	A *pA = new A[5];
	delete []pA;
}
int main()
{
	//std::auto_ptr<A*>opbj(new A);
	std::vector<std::auto_ptr<A*>>A_ptr;
	/*//printf("\a");
	//printf("123\a213\n");
	printf("a\bre\'hi\'y\\\bou\n");
	/*test();
	/*int a = Add(1, 2);

	//cout << a << endl;*/
	system("pause");
	return 0;
}
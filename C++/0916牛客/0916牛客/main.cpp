#include<iostream>
using namespace std;


class A
{
public:
	void test()
	{
		B::testb();
	}
	static class B
	{
	public:
		static void testb()
		{
			cout << "B" << endl;
		}
	};
};

int main()
{
	char a[2] = { '1', '2' };
	//cin >> a;
	cout << a << endl;
	//A::B::testb();


	system("pause");
	return 0;
}
#include<iostream>
using namespace std;

/*class Test
{
public:
	Test()
		:_data(0)
	{
		cout << "Test():" << this << endl;
	}
	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _data;
};
/*void Test1()
{
	Test* p1 = (Test*)malloc(sizeof(Test));
	free(p1);
	Test* p2 = (Test*)malloc(sizeof(Test) * 10);
	free(p2);
	//malloc(15);
	_CrtDumpMemoryLeaks();
}
void Test2()
{
	Test* p1 = new Test;
	delete p1;
	Test* p2 = new Test[10];
	delete[] p2;
	//malloc(15);
	_CrtDumpMemoryLeaks();
}
class HeapOnly
{
public:
	static HeapOnly* CreateObject()
	{
		return new HeapOnly;
	}
private:
	HeapOnly(){}
	HeapOnly(const HeapOnly&) = delete;
};
class StackOnly
{
public:
	static StackOnly CreateObject()
	{
		return StackOnly();
	}
	void test()
	{
		cout << data << endl;
	}
private:
	StackOnly()
		:data(11)
	{
		cout << "123" << endl;
	}
	int data = 12;
};

/*void del(int L[], int len, int x, int y)
{
	for (int i = 0; i < len; i++)
	{
		if (L[i]>x&&L[i] < y)
		{
			int index = i + 1;
			while (index != len)
			{
				L[index - 1] = L[index];
				index++;
			}
			len--;
			i--;
		}
	}
}*/
/*class StackOnly
{
public:
	StackOnly()
	//	:data(11)
	{
		cout << "123" << endl;
	}
private:
	void* operator new (size_t size);
	void operator delete(void* p);
	//int data = 12;
};
class test
{
public:
	test()
	{
		cout << "123" << endl;
	}
private:
	void* operator new (size_t size);
	void operator delete(void* p);
	int data = 12;
};*/

class Test
{
public:
	Test()
	{
		_data = 10;
		//_p = new int;
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		//delete _p;
		cout << "~Test():" << this << endl;
	}

private:
	int _data;
	//int* _p;
};

// 对于自定义类型，只要涉及到[]，必然会崩溃
// new会调用构造函数
// free不会调用析构函数--对象中的资源不会被销毁
void Test2()
{
	Test* p3 = new Test;
	Test* p4 = new Test;
	free(p3);     //free只是释放了对象所在的内存空间，如果自定义类型中的成员变量
	              //管理了资源，将无法释放该资源，会产生内存泄露（因为没有调用析构函数）
	delete[] p4;  //delete[] 在自定义类型中只要没有和new[]匹配使用就会运行时出错

	// malloc申请空间时不会调用构造函数--申请的是与对象大小相同的一块内存空间
	// 不能讲该块内存空间看成是一个对象

	Test* p1 = (Test*)malloc(sizeof(Test));
	Test* p2 = (Test*)malloc(sizeof(Test));
	delete p1;    // 会调用析构函数清理对象中的资源，如果自定义类型中的成员变量
	              //管理了资源，将会报错，因为malloc没有调用构造函数，没有给管
				  //理资源的变量申请内存，此时释放空间当然会出错。
	delete[] p2;  //delete[] 在自定义类型中只要没有和new[]匹配使用就会运行时出错

	Test* p5 = new Test[10];
	Test* p6 = new Test[10];
	free(p5);      //free释放new[]创建的运行时会出错
	delete p6;     //delete释放new[]创建的运行时会出错
	_CrtDumpMemoryLeaks();
}
int main()
{
	Test2();
	/*StackOnly* s1 = &(StackOnly::CreateObject());
	s1->test();
	//test s1;
	//new test;
	//StackOnly s1;
	//new StackOnly;
	//cout << s1.data << endl;
	//s1.test();
	/*int a[] = { 0, 2, 6, 9, 8, 5, 3, 1, 4, 7 };
	del(a, 10, 3, 7);
	/*HeapOnly* p1 = HeapOnly::CreateObject();
	HeapOnly* p3 = HeapOnly::CreateObject();
	StackOnly p2;
	//StackOnly* p2 = &(StackOnly::CreateObject());
	cout << p1 << '\n' << p3 << '\n' << &p2 << endl;

	/*Test t1;
	Test *t2 = new Test;
	cout << &t1 << '\n' << t2 << endl;
	/*void* p = new char[0xfffffffful];    
	cout << "new:" << p << endl;

	/*Test* p1 = (Test*)malloc(sizeof(Test));
	new(p1)Test;
	/*Test2();
	/*Test2();
	_CrtDumpMemoryLeaks();
	/*int *p1 = (int*)malloc(sizeof(int));
	free(p1);
	int *p2 = (int*)calloc(4, sizeof(int));
	int *p3 = (int*)realloc(p2, sizeof(int) * 10);
	//free(p2);
	free(p3);
	free(p2);*/

	system("pause");
	return 0;
}
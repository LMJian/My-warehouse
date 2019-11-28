#include <iostream> 
using namespace std;

class A {
public:
	void print() {
		cout << "A:print()";
	}
};
class B : public A {
public:
	void print() {
		cout << "B:print()";
	}
};
class C : public B {
public:
	void print() {
		A::print();
	}
};
int main() {
	C b;
	b.print();
	system("pause");
	return 0;
}


#if 0
#include <iostream> 
using namespace std;

class A { public: ~A() { cout << "~A()"; } };

class B { public: virtual ~B() { cout << "~B()"; } };

class C : public A, public B { public: ~C() { cout << "~C()"; } };

int main() {
	C * c = new C;
	B * b1 = dynamic_cast<B *>(c);
	A * a2 = dynamic_cast<A *>(b1);
	delete a2;
	system("pause");
	return 0;
}
#endif

#if 0
//#include<iostream>
//#include<stdio.h>
//using namespace std;
#include<stdio.h>
void swap_int(int* a, int* b) {
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}


int main()
{
	long long a = 1, b = 2, c = 3;
	int aa = a, bb = b, cc = c;
	printf("%d %d %d\n", aa, bb, cc);
	printf("%d %d %d\n", a, b, c);
	/*char a[] = "abc";
	char b[] = "abc123";
	char *p = a;
	char *q = b;
	while (*p = *q)
		printf("%c %c", *p, *q);
	/*int a = INT_MAX;
	int b = 1;
	swap_int(&a, &b);
	cout << a << endl << b << endl;*/
	system("pause");
	return 0;
}
#endif 
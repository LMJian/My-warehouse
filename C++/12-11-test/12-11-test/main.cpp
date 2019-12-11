#include<iostream>
using namespace std;

class A { 
public: 
	A() :m_iVal(0) { 
		test(); 
	} 
	virtual void func() { 
		std::cout << m_iVal << ' '; 
	} 
	void test() {
		func(); 
	} 
public: 
	int m_iVal; 
}; 
class B : public A { 
public: 
	B() { test(); } 
	virtual void func() { 
		++m_iVal; 
		std::cout << m_iVal << ' '; 
	} 
}; 
int main(int argc, char* argv[]) { 
	A*p = new B;
	p->test(); 
	system("pause");
	return 0; 
}




#if 0
class A {
public: 
	virtual void func(int val = 1) {
		std::cout << "A->" << val << std::endl; 
	}
	virtual void test() { 
		func(); 
	}
}; 
class B : public A { 
public: 
	void func(int val = 0) { 
		std::cout << "B->" << val << std::endl; 
	}
}; 
int main(int argc, char* argv[]) { 
	B*p = new B; 
	p->test(); 
	system("pause");
	return 0; 
}
#endif
#if 0
#include<iostream>
using namespace std;

void Count(int n) {
	int ret = 0;
	while (n) {
		ret += n / 5;
		n = n / 5;
	}
	cout << ret << endl;
}
int main() {
	int n;
	while (cin >> n) {
		Count(n);
	}
	return 0;
}
#endif
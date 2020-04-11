#include<iostream>
using namespace std;
#include<thread>

/*void fun() {
	cout << "A new thread!" << endl;
}

void foo() {
	this_thread::sleep_for(std::chrono::seconds(1));
}*/
#include<mutex>
#include<atomic>
atomic_llong sum{ 0 };

//std::mutex m;
//unsigned long long sum = 0;

void fun(size_t num) {
	for (size_t i = 0; i < num; ++i) {
		//m.lock();
		++sum;
		//m.unlock();
	}
}

int main() {
	cout << "Before joining,sum=" << sum << std::endl;
	double left = clock();
	thread t1(fun, 10000000);
	thread t2(fun, 10000000);
	thread t3(fun, 10000000);
	thread t4(fun, 10000000);
	thread t5(fun, 10000000);
	thread t6(fun, 10000000);
	double right = clock();
	cout << "right-left=" << (right - left)/ CLOCKS_PER_SEC << endl;

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	cout << "After joining,sum=" << sum << std::endl;

	/*thread t(foo);
	t.detach();
	cout << "before join,joinable=" << t.joinable() << std::endl;

	//t.join();
	cout << "after join,joinable=" << t.joinable() << endl;
	
	/*int n1 = 500;
	int n2 = 600;
	thread t([&](int addNum) {
		n1 += addNum;
		n2 += addNum;
	}, 500);
	t.join();
	std::cout << n1 << ' ' << n2 << std::endl;


	/*thread t(fun);
	t.join();
	cout << "Main thread!" << endl;

	/*[] {};

	int a = 3, b = 4;
	[=] {
		return a + 3; 
	};

	auto fun1 = [&](int c) {
		b = a + c; 
	};
	fun1(10);
	cout << a << " " << b << endl;

	auto fun2 = [=, &b](int c)->int {
		return b += a + c; 
	};
	cout << fun2(10) << endl;

	int x = 10;
	auto add_x = [x](int a)mutable {
		x *= 2;
		return a + x;
	};
	cout << add_x(10) << endl;
	cout << x << endl;*/

	/*auto f1 = [] {
		cout << "hello world" << endl; 
	};
	auto f2 = [] {
		cout << "hello world" << endl;
	};

	//f1 = f2;
	auto f3(f2);
	f3();

	void (*PF)();
	PF = f2;
	PF();*/

	/*double rate = 0.49;
	auto r2= [=](double monty, int year)->double {
		return monty * rate*year;
	};
	cout << r2(10000, 2) << endl;*/
	
	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include <windows.h>
#include<vector>
using namespace std;

int main()
{
	try {
		vector<int> v(10, 5);
		
		v.reserve(1000000000);
		 
		v.at(10) = 100;
	}
	catch (const exception& e)  
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "Unkown Exception" << endl;
	}
	return 0;
}

#if 0
double Division(int a, int b) {
	
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}
void Func()
{
	
	int* array = new int[10];
	 {
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	/*catch (...)
	{
		cout << "delete []" << array << endl;
		delete[] array;
		//throw;
	}*/

	cout << "delete []" << array << endl;
	//delete[] array;
}
int main()
{
	try
	{
		Func();
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}
	return 0;
}
#endif

#if 0
double Division(int a, int b) {
	
	if (b == 0)
		throw "Division by zero condition!";
	else
		return ((double)a / (double)b);
}
void Func()
{
	int len, time;
	cin >> len >> time;
	cout << Division(len, time) << endl;
}
int main()
{
	try {
		Func();
	}
	catch (const char* errmsg){
		cout << errmsg << endl;
	}
	catch (...) {
		cout << "unkown exception" << endl;
	}
	return 0;
}
#endif
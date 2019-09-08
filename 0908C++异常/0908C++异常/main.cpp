#include<iostream>
#include<vector>
using namespace std;

/*double Division(int a, int b)
{
	if (b == 0)
		throw "Division by zero condition!";
	else
		return ((double)a / (double)b);
}

void Func()
{
	int *array = new int[10];
	try{
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	catch (const char* str)
	{
		cout << "delete[]" << array << endl;
		delete[] array;
		throw "404";
	}
	cout << "delete[]" << array << endl;
	delete[] array;
	}
class Exception
{
protected:
	string _errmsg = "123";
	int _id = -1;
public:
	virtual void test()
	{
		if (_id == -1)
			throw *this;
	}
};
class SqlException :public Exception
{
public:
	virtual void test()
	{
		if (_id == -1)
			throw *this;
	}
};
class CacheException :public Exception
{
public:
	virtual void test()
	{
		if (_id == -1)
			throw *this;
	}
};
class HttpServerException:public Exception
{
public:
	virtual void test()
	{
		if (_id == -1)
			throw *this;
	}
};*/



int main()
{

	/*try{
		vector<int>v(10, 5);
		//v.reserve(100000);
		v.at(10) = 100;
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
	/*try{
		HttpServerException e;
		e.test();
	}
	catch (const SqlException& s)
	{
		cout << "SqlException" << endl;
	}
	catch (const CacheException& c)
	{
		cout << "CacheException" << endl;
	}
	catch (const HttpServerException& h)
	{
		cout << "HttpServerException" << endl;
	}
	catch (const Exception& e)
	{
		cout << "Exception" << endl;
	}
	/*try{
		Func();
	}
	catch (const char* errmsg){
		cout << errmsg << endl;
	}
	/*catch (){
		cout << "unkown exception" << endl;
	}*/

	system("pause");
	return 0;
}
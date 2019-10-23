#include<iostream>
using namespace std;

#include<vector>
#include<deque>

template<class T,class Con=deque<T>>
class stack
{
public:
	stack(){}
	void push(const T& x)
	{
		_c.push_back(x);
	}
	void pop()
	{
		_c.pop_back();
	}
	T& top()
	{
		return _c.back();
	}
	const T& top()const
	{
		return _c.back();
	}
	size_t size()const
	{
		return _c.size();
	}
	bool empty()const
	{
		return _c.empty();
	}
private:
	Con _c;
};

void TestStack()
{
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout << s.size() << endl;
	cout << s.top() << endl;
	s.pop();
	s.pop();
	cout << s.size() << endl;
	cout << s.top() << endl;
}

template<class T,class Con=deque<T>>
class queue {
public:
	queue(){}
	void push(const T& x)
	{
		_c.push_back(x);
	}
	void pop()
	{
		_c.pop_front();
	}
	T& back()
	{
		return _c.back();
	}
	const T& back()const
	{
		return _c.back();
	}
	T& front()
	{
		return _c.front();
	}
	const T& front()const
	{
		return _c.front();
	}
	size_t size()const
	{
		return _c.size();
	}
	bool empty()const
	{
		return _c.empty();
	}
private:
	Con _c;
};
void Testqueue()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	cout << q.size() << endl;
	cout << q.front() << endl;
	cout << q.back() << endl;

	q.pop();
	q.pop();
	cout << q.size() << endl;
	cout << q.front() << endl;
	cout << q.back() << endl;
	
}
int main()
{
	//TestStack();
	Testqueue();
	system("pause");
	return 0;
}
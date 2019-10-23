#include<iostream>
using namespace std;
#include<vector>

template<class T,class Sequence=vector<T>,class Compare=less<T>>
class priority_queue
{
public:
	priority_queue()
		:_seq()
	{}
	template<class InputIt>
	priority_queue(InputIt start, InputIt last)
		:_seq(start,last)
	{
		int parent = (_seq.size() - 2) >> 1;
		while (parent >= 0)
		{
			makeDown(parent);
			parent--;
		}
	}
	void push(const T& x)
	{
		_seq.push_back(x);
		makeUp(_seq.size() - 1);
	}
	void pop()
	{
		if (empty())
			return;
		//swap(_seq.begin(), _seq.end() - 1);
		swap(_seq.front(),_seq.back());
		_seq.pop_back();
		makeDown(0);
	}
	bool empty()const
	{
		return _seq.empty();
	}
	const T& top()const
	{
		return _seq.front();
	}
	size_t size()const
	{
		return _seq.size();
	}
private:
	void makeUp(int child)
	{
		int parent = (child - 1) >> 1;
		while (child)
		{
			if (_com(_seq[parent], _seq[child]))
			{
				swap(_seq[parent], _seq[child]);
				child = parent;
				parent = (child - 1) >> 1;
			}
			else
				return;
		}
	}
	void makeDown(int parent)
	{
		int child = parent * 2 + 1;
		while (child < _seq.size())
		{
			if (child + 1 < _seq.size() && _com(_seq[child], _seq[child + 1]))
				++child;
			if (_com(_seq[parent], _seq[child]))
			{
				swap(_seq[parent], _seq[child]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
				break;
		}
	}
	Sequence _seq;
	Compare _com;
};

int main()
{
	// 8  1  9  3  6  4  5  0  2  7
	int array[] = {8,1,9,3,6,4,5,0,2,7};
	priority_queue<int> q(array, array+sizeof(array)/sizeof(array[0]));
	q.push(999);
	cout << q.top() << endl;

	q.pop();
	cout << q.top() << endl;

	priority_queue<int, vector<int>, less<int>> q2;
	q2.push(5);
	q2.push(0);
	q2.push(9);
	q2.push(3);
	q2.push(4);
	return 0;
}
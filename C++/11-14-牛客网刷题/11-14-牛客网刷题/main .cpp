#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int>> maze;
		if (sum <= 2)
			return maze;
		list<int> arr;
		int ret = 0, index = 1;
		while (ret < sum)
		{
			ret += index;
			arr.push_back(index++);
		}
		while (1)
		{
			while (ret > sum)
			{
				ret -= arr.front();
				arr.pop_front();
			}
			while (ret < sum)
			{
				ret += index;
				arr.push_back(index++);
			}
			if (ret == sum)
			{
				vector<int> tmp(arr.begin(), arr.end());
				maze.push_back(tmp);
				if (tmp.size() == 2)
					break;
				ret += index;
				arr.push_back(index++);
			}
		}
		for (int i = 0; i < maze.size(); ++i)
		{
			for (int j = 0; j < maze[i].size(); ++j)
				cout << maze[i][j] << " ";
			cout << endl;
		}
		return maze;
	}
};

int main()
{
	Solution sa;
	sa.FindContinuousSequence(100);

	system("pause");
	return 0;
}
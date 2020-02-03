#include<iostream>
#include<vector>
#include<list>
using namespace std;

/*class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		list<int> arr(num.begin(), num.begin() + size);
		int max = myMax(arr);
		vector<int> ret;
		ret.push_back(max);
		for (size_t i = size; i < num.size(); ++i) {
			arr.pop_front();
			arr.push_back(num[i]);
			max = myMax(arr);
			ret.push_back(max);
		}
		return ret;
	}
private:
	int myMax(const list<int>& arr) {
		auto it = arr.begin();
		int max = *it;
		while (it != arr.end()) {
			if (*it > max)
				max = *it;
			++it;
		}
		return max;
	}
};*/
class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		buff = matrix;
		row = rows;
		col = cols;
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (matrix[i*cols + j] == *str) {
					if (bfs(i, j, str))
						return true;
				}
			}
		}
		return false;
	}
private:
	char *buff = nullptr;
	int row;
	int col;
	bool bfs(int i, int j, char* str) {
		if (*(str + 1) == '\0')
			return true;
		char tmp = buff[i*col + j];
		buff[i*col + j] = '\0';
		if (i + 1 < row&&buff[(i + 1)*col + j] == *(str + 1))
			if (bfs(i + 1, j, str + 1))
				return true;
		if (i - 1 >= 0 && buff[(i - 1)*col + j] == *(str + 1))
			if (bfs(i - 1, j, str + 1))
				return true;
		if (j + 1 < col&&buff[i*col + j + 1] == *(str + 1))
			if (bfs(i, j + 1, str + 1))
				return true;
		if (j - 1 >= 0 && buff[i*col + j - 1] == *(str + 1))
			if (bfs(i, j - 1, str + 1))
				return true;
		buff[i*col + j] = tmp;
		return false;
	}
};


int main() {
	Solution sa;
	char arr[] = "abcesfcsadee";
	char ch[] = "bcced";
	auto it = sa.hasPath(arr, 3, 4, ch);

	system("pause");
	return 0;
}
#include<iostream>
using namespace std;

class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		k = threshold;
		row = rows;
		col = cols;
		char *arr = (char*)malloc(rows*cols * sizeof(char));
		memset(arr, '1', rows*cols * sizeof(char));
		bfs(arr, 0, 0);
		return count;
	}
private:
	int k;
	int row;
	int col;
	int count = 0;
	void bfs(char *arr, int i, int j) {
		int sum = 0;
		int num = i;
		while (num) {
			sum += num % 10;
			num /= 10;
		}
		num = j;
		while (num) {
			sum += num % 10;
			num /= 10;
		}
		if (sum > k)
			return;
		arr[i*col + j] = 0;
		++count;
		if (i + 1 < row&&arr[(i + 1)*col + j] == '1')
			bfs(arr, i + 1, j);
		if (i - 1 >= 0 && arr[(i - 1)*col + j] == '1')
			bfs(arr, i - 1, j);
		if (j + 1 < col&&arr[i*col + j + 1] == '1')
			bfs(arr, i, j + 1);
		if (j - 1 >= 0 && arr[i*col + j - 1] == '1')
			bfs(arr, i, j - 1);
	}
};

int main() {
	Solution sa;
	cout << sa.movingCount(18, 40, 40) << endl;
	system("pause");
	return 0;
}
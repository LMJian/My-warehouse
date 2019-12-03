#include<iostream>
#include<vector>
using namespace std;

class Bonus {
public:

	int getMost(vector<vector<int> > board) {
		// write code here
		arr = board;
		Find(0, 0, 0);
		return count + board[5][5];
	}
private:
	vector<vector<int> > arr;
	int count = 0;
	void Find(int x, int y, int ret) {
		if (x >= 6 || y >= 6)
			return;
		if (x == 5 && y == 5)
		{
			if (ret > count)
				count = ret;
			return;
		}
		Find(x + 1, y, ret + arr[x][y]);
		Find(x, y + 1, ret + arr[x][y]);
	}
};

int main() {
	Bonus b;
	

	system("pause");
	return 0;
}
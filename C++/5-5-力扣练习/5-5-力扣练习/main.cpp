#include<iostream>
#include<vector>
using namespace std;

/*class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		if (judge(board, 0, 0) && judge(board, 0, 3) && judge(board, 0, 6) && judge(board, 3, 0) && judge(board, 3, 3) && judge(board, 3, 6) && judge(board, 6, 0) && judge(board, 6, 3) && judge(board, 6, 6)) {
			for (int i = 0; i < 9; ++i) {
				int a[10] = { 0 };
				int b[10] = { 0 };
				for (int j = 0; j < 9; ++j) {
					if (board[i][j] != '.') {
						++a[board[i][j] - '0'];
						if (a[board[i][j] - '0'] > 1)
							return false;
					}
					if (board[j][i] != '.') {
						++b[board[j][i] - '0'];
						if (b[board[j][i] - '0'] > 1)
							return false;
					}
				}
			}
			return true;
		}
		else
			return false;
	}
private:
	bool judge(vector<vector<char>>& board, int x, int y) {
		int arr[10] = { 0 };
		for (int i = x; i < x + 3; ++i) {
			for (int j = y; j < y + 3; ++j) {
				if (board[i][j] != '.') {
					++arr[board[i][j] - '0'];
					if (arr[board[i][j] - '0'] > 1)
						return false;
				}
			}
		}
		return true;
	}
};*/
#include<unordered_map>
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		unordered_map<int, int> mp;
		for (int i = 0; i < nums.size(); ++i) {
			++mp[nums[i]];
		}
		for (int i = 1;; ++i) {
			if (mp[i] == 0)
				return i;
		}
	}
};

int main() {
	Solution sa;
	vector<int> arr{ 2147483647,2147483646,2147483645,3,2,1,-1,0 };
	int t=0x80000000;
	arr.push_back(t);
	cout<<sa.firstMissingPositive(arr)<<endl;
	/*Solution sa;
	vector<vector<char>> arr{
		{'.','.','4','.','.','.','6','3','.'},
		{'.','.','.','.','.','.','.','.','.'},
		{'5','.','.','.','.','.','.','9','.'},
		{'.','.','.','5','6','.','.','.','.'},
		{'4','.','3','.','.','.','.','.','1'},
		{'.','.','.','7','.','.','.','.','.'},
		{'.','.','.','5','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.'}
	};
	cout << sa.isValidSudoku(arr) << endl;*/
	system("pause");
	return 0;
}
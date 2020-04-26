#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) {
		for (int i = 1; i < grid.size(); ++i)
			grid[i][0] += grid[i - 1][0];
		for (int i = 1; i < grid[0].size(); ++i)
			grid[0][i] += grid[0][i - 1];
		for (int i = 1; i < grid.size(); ++i) {
			for (int j = 1; j < grid[0].size(); ++j) {
				grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
			}
		}
		return grid[grid.size() - 1][grid[0].size() - 1];
	}
};*/
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		int left = obstacleGrid.size();
		int right = obstacleGrid[0].size();
		vector<vector<int>> arr(left, vector<int>(right, 0));
		for (int i = 0; i < left; ++i) {
			if (obstacleGrid[i][0] == 0)
				arr[i][0] = 1;
			else
				break;
		}
		for (int i = 0; i < right; ++i) {
			if (obstacleGrid[0][i] == 0)
				arr[0][i] = 1;
			else
				break;
		}
		for (int i = 1; i < left; ++i) {
			for (int j = 1; j < right; ++j) {
				if (obstacleGrid[i][j] == 0) {
					arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
				}
			}
		}
		return arr[left - 1][right - 1];
	}
};

int main() {
	Solution sa;
	vector<vector<int>> arr;
	vector<int> tmp{ 0,0,1,0,0 };
	arr.push_back(tmp);
	arr.push_back(tmp);
	vector<int> t{ 0,0,0,0,0 };
	arr.push_back(t);
	arr.push_back(tmp);
	arr.push_back(tmp);
	cout << sa.uniquePathsWithObstacles(arr) << endl;
	/*Solution sa;
	vector<vector<int>> arr;
	vector<int> tmp{ 1,2,3,4,5,6,7,8,9 };
	arr.push_back(tmp);
	arr.push_back(tmp);
	arr.push_back(tmp);
	cout << sa.minPathSum(arr) << endl;*/
	system("pause");
	return 0;
}
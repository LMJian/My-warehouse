#include<iostream>
#include<vector>
#include<unordered_set>
#include<set>
using namespace std;

/*class Solution{
public:
	int Fibonacci(int n){
		if (n <= 0)
			return 0;
		if (n == 1 || n == 2)
			return 1;
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
};
class Solution2{
public:
	int Fibonacci(int n){
		if (n <= 0)
			return 0;
		if (n == 1 || n == 2)
			return 1;
		int *record = new int[n + 1];
		record[0] = 0;
		record[1] = 1;
		for (int i = 2; i <= n; i++){
			record[i] = record[i - 1] + record[i - 2];
		}
		return record[n];
		delete[] record;
	}
};
class Solution3{
public:
	int Fibonacci(int n){
		if (n <= 0)
			return 0;
		if (n == 1 || n == 2)
			return 1;
		int fn1 = 1;
		int fn2 = 1;
		int result = 0;
		for (int i = 3; i <= n; i++)
		{
			result = fn1 + fn2;
			fn1 = fn2;
			fn2 = result;
		}
		return result;
	}
};
class Solution{
public:
	int jumpFloorII(int number){
		if (number <= 0)
			return 0;
		int total = 1;
		for (int i = 1; i < number; i++)
			total *= 2;
		return total;
	}
}
class Solution{
public:
	int jumpFloorII(int number)
	{
		if (number <= 0)
			return 0;
		return 1 << (number - 1);
	}
};
class Solution {
public:
	int rectCover(int number) {
		if (number <= 0)
			return 0;
		if (number <= 2)
			return number;
		int f1 = 1;
		int f2 = 2;
		int tmp;
		for (int i = 3; i <= number; i++)
		{
			tmp = f1 + f2;
			f1 = f2;
			f2 = tmp;
		}
		return tmp;
	}
};
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int sum = array[0];
		int max = array[0];
		for (size_t i = 1; i < array.size(); i++)
		{
			sum = sum <= 0 ? array[i] : sum + array[i];
			max = max < sum ? sum : max;
		}
		return max;
	}
};
class Solution{
public: 
	bool wordBreak(string s, unordered_set<string> &dict) {
	int len = s.length();
	bool *arrays=new bool[len + 1];
	arrays[0] = true;
	for (int i = 1; i <= len; ++i){
		for (int j = 0; j < i; ++j){
			if (arrays[j] && contains(dict,s,j,i)){
				arrays[i] = true;
				break;
			}
		}
	}
	return arrays[len];
}
	bool contains(unordered_set<string> &dict, string s, int start, int end)
	{
		string str = s.substr(start, end - start + 1);
		const char *pstr = str.c_str();
		unordered_set<string>::iterator pt = dict.begin();
		for (size_t i = 0; i < dict.size(); i++)
		{
			if (strcmp(pstr, (const char*)pt) == 0)
				return true;
		}
		return false;
	}
	bool wordBreak(string s, unordered_set<string> &dict){
		if (s.empty()){ 
			return false; 
		}        
		if (dict.empty()){ 
			return false; 
		}        
		// 获取词典中的单词的大长度        
		size_t max_length = 0;        
		unordered_set<string>::iterator dict_iter= dict.begin();
		for (; dict_iter != dict.end(); dict_iter++){            
			if ((*dict_iter).size() > max_length){                
				max_length = (*dict_iter).size();            
			}        
		}

		vector<bool> can_break(s.size() + 1, false);        
		// 初始化F(0) = true        
		can_break[0] = true;

		for (size_t i = 1; i <= s.size(); i++){
			for (int j = i - 1; j >= 0; j--){                
				// 如果小子串长度大于max_length，跳过             
				if ((i - j) > max_length){ 
					break;            
				}      
				// F(i): true{j <i && F(j) && substr[j+1,i]能在词典中找到} OR false 
				// 第j+1个字符的索引为j           
				if (can_break[j] && dict.find(s.substr(j, i - j)) != dict.end()){
					can_break[i] = true;        
					break;       
				}     
			}       
		}    
		return can_break[s.size()]; 
	}
class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		int len = triangle.size();
		for (int i = len - 2; i >= 0; i--)
		{
			for (size_t j = 0; j < triangle[i].size(); j++)
			{
				triangle[i][j] += triangle[i - 1][j] < triangle[i - 1][j + 1] ? triangle[i - 1][j] : triangle[i - 1][j + 1];
			}
		}
		return triangle[0][0];
	}
};
class Solution {
public:
	int uniquePaths(int m, int n) {
		int *arr = new int[n];
		for (int i = 0; i < n; i++)
			arr[i] = 1;
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
				arr[j] += arr[j - 1];
		}
		return arr[n - 1];
	}
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		if (obstacleGrid.empty() || obstacleGrid[0].empty())
			return 0;
		const int M = obstacleGrid.size();
		const int N = obstacleGrid[0].size();
		vector<vector<int>> ret(M, vector<int>(N, 0));
		for (int i = 0; i < N; i++)
		{
			if (obstacleGrid[0][i] == 0)
				ret[0][i] = 1;
			else
				break;
		}
		for (int i = 0; i < M; i++)
		{
			if (obstacleGrid[i][0] == 0)
				ret[i][0] = 1;
			else
				break;
		}
		for (int i = 1; i < M; i++)
		{
			for (int j = 1; j < N; j++)
			{
				if (obstacleGrid[i][j] == 1)
					ret[i][j] = 0;
				else
					ret[i][j] = ret[i - 1][j] + ret[i][j - 1];
			}
		}
		return ret[M - 1][N - 1];
	}
};*/
class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) {
		const int M = grid.size();
		const int N = grid[0].size();
		for (int i = 1; i < M; i++)
			grid[i][0] += grid[i - 1][0];
		for (int i = 1; i < N; i++)
			grid[0][i] += grid[0][i - 1];
		for (int i = 1; i < M; i++)
		{
			for (int j = 1; j < N; j++)
			{
				int min = grid[i - 1][j] < grid[i][j - 1] ? grid[i - 1][j] : grid[i][j - 1];
				grid[i][j] += min;
			}
		}
		return grid[M - 1][N - 1];
	}
};

int main()
{
	Solution s;
	cout << s.uniquePaths(1, 2) << endl;
	/*Solution s1;
	string s = "leetcode";
	unordered_set<string> dict{ "leet", "code" };
	//vector<int>array{ 6, -3, -2, 7, -15, 1, 2, 2 };
	cout << s1.wordBreak(s,dict) << endl;
	/*Solution s1;
	cout << s1.rectCover(4) << endl;*/

	system("pause");
	return 0;
}
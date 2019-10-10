#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

/*class Solution {
public:    
	int minCut(string s) 
	{
		if (s.empty()) 
			return 0;
		int len = s.size();        
		vector<int> cut;        
		// F(i)初始化        
		// F(0）= -1，必要项，如果没有这一项，对于重叠字符串“aaaaa”会产生错误的结果        
		for (int i = 0; i < 1 + len; ++i) 
		{            
			cut.push_back(i - 1);        
		}
		for (int i = 1; i < 1 + len; ++i) 
		{
			for (int j = 0; j < i; ++j) 
			{
				// F(i) = min{F(i), 1 + F(j)}, where j<i && j+1到i是回文串        
				// 从长串判断，如果从第j+1到i为回文字符串              
				// 则再加一次分割，从1到j，j+1到i的字符就全部分成了回文字符串
				if (isPalindrome(s, j, i - 1))
				{
					cut[i] = cut[i] < (1 + cut[j]) ? cut[i] : (1 + cut[j]);
				}
			}   
		}

		return cut[len];
	}

	//判断是否回文串    
	bool isPalindrome(string s, int i, int j)
	{        
		while (i<j) 
		{      
			if (s[i] != s[j])
			{        
				return false; 
			}           
			i++;     
			j--;
		} 
		return true;
	}
};
/*class Solution {
private:
	string s;
private:
	vector<vector<int>> f; 
public:
	int minCut(string st) {
		s = st;//先求解小段的子序列
		for(int t=0;t<=s.length();t++)
		{
			for(int i=0,j=t;j<s.length();i++,j++)
			{
				f[i][j] = compCut(i,j);
			}
		}
		return f[0][s.length()-1];
	} 
	// 状态转移方程的实现
public:
	int compCut(int i,int j) 
	{
		if(isPalindrome(i,j)) 
			return 0;
		int min = s.length();
		for(int p=i;p<j;p++) 
		{
			int a = f[i][p];
			int b = f[p+1][j];
			a = a + b + 1;
			min = min<a?min:a;
		}
		return min;
	} 
	//判断是否回文串
public:
	bool isPalindrome(int i,int j)
	{
		while(i<j) 
		{
			if(s.at(i) != s.at(j))
				return false;
			i++;j--;
		}
		return true;
	}
};
class Solution {
public:
	int minCut(string s)
	{
		if (s.empty())
			return 0;
		vector<int> maze;
		int len = s.size();
		for (int i = 0; i <= len; i++)
			maze.push_back(i - 1);
		for (int i = 1; i <= len; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (isPalindrome(s, j, i - 1))
				{
					maze[i] = maze[i] < maze[j] + 1 ? maze[i] : maze[j] + 1;
				}
			}
		}
		return maze[len];
	}
	bool isPalindrome(string s, int start, int end)
	{
		while (start < end)
		{
			if (s[start] != s[end])
				return false;
			start++;
			end--;
		}
		return true;
	}
};
class Solution2 {
public:    
	int minCut(string s) 
	{
		if (s.empty()) 
			return 0;
		int len = s.size();        
		vector<int> cut;        
		// F(i)初始化    
		// F(0）= -1，必要项，如果没有这一项，对于重叠字符串“aaaaa”会产生错误的结果        
		for (int i = 0; i < 1 + len; ++i) 
		{   
			cut.push_back(i - 1); 
		}      
		vector<vector<bool> > mat = getMat(s);
		for (int i = 1; i < 1 + len; ++i)
		{
			for (int j = 0; j < i; ++j) 
			{  
				// F(i) = min{F(i), 1 + F(j)}, where j<i && j+1到i是回文串      
				// 从长串判断，如果从第j+1到i为回文字符串        
				// 则再加一次分割，从1到j，j+1到i的字符就全部分成了回文字符串      
				if (mat[j][i - 1]) {    
					cut[i] = cut[i] < 1 + cut[j] ? cut[i] : 1 + cut[j];
				}
			}
		}
		return cut[len];
	}
	vector<vector<bool> > getMat(string s) 
	{
		int len = s.size();       
		vector<vector<bool> > mat = vector<vector<bool> >(len, vector<bool>(len, false));    
		for (int i = len - 1; i >= 0; --i)
		{
			for (int j = i; j < len; ++j) 
			{
				if (j == i) {   
					// 单字符为回文字符串     
					mat[i][j] = true;               
				}
				else if (j == i + 1) {  
					// 相邻字符如果相同，则为回文字符串   
					mat[i][j] = (s[i] == s[j]);       
				}         
				else {         
					// F(i,j) = {s[i]==s[j] && F(i+1,j-1)   
					// j > i+1         
					mat[i][j] = ((s[i] == s[j]) && mat[i + 1][j - 1]);       
				}           
			}    
		}
		return mat;
	}
};*/
class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		if (s.empty() || dict.empty())
			return false;
		int maxlen = 0;
		unordered_set<string>::iterator pt = dict.begin();
		for (; pt != dict.end(); pt++)
		{
			if (maxlen < (*pt).size())
				maxlen = (*pt).size();
		}
		vector<bool> maze(s.size() + 1, false);
		maze[0] = true;
		for (int i = 1; i <= s.size(); i++)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (i - j > maxlen)
					break;
				if (maze[j] && (dict.find(s.substr(j, i -j)) != dict.end()))
				{
					maze[i] = true;
					break;
				}
			}
		}
		return maze[s.size()];
	}
};
int main()
{
	string s1 = "aleelattle";
	//Solution2 s;
	
	cout << s1.size() << endl;

	system("pause");
	return 0;
}
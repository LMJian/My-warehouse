#include<iostream>
#include<string>
using namespace std;

/*bool maze(string s1, string s2)
{
	if (s1.size() != s2.size())
		return false;
	int maze1[256] = { 0 };
	int maze2[256] = { 0 };
	for (size_t i = 0; i < s1.size(); i++)
	{
		maze1[s1[i]]++;
	}
	for (size_t i = 0; i < s2.size(); i++)
	{
		maze2[s2[i]]++;
	}
	for (size_t i = 0; i < s1.size(); i++)
	{
		if (maze1[s1[i]] != maze2[s1[i]])
			return false;
	}
	return true;
}
void judge(int n, int m, string s1, string s2)
{
	if (n != m)//判断长度
	{
		cout << "NO" << endl;
		return;
	}
	/*if (!maze(s1, s2))//判断是否有相同数量的字符
	{
		cout << "NO" << endl;
		return;
	}
	for (int i = 0; i<n; i++)
	{
		if (s1.compare(s2)==0)
		{
			cout << "YES" << endl;
			return;
		}
		char ch = s1[0];
		s1.erase(0);
		s1.push_back(ch);
	}
	cout << "NO" << endl;
}*/

#include<iostream>
#include<string>
using namespace std;

void judge(int n, int m, string s1, string s2)
{
	if (n != m)
	{
		cout << "false" << endl;
		return;
	}
	int maze1[256] = { 0 };
	int maze2[256] = { 0 };
	for (size_t i = 0; i<s1.size(); i++)
		maze1[s1[i]]++;
	for (size_t i = 0; i<s2.size(); i++)
		maze2[s2[i]]++;
	for (size_t i = 0; i<s1.size(); i++)
	{
		if (maze1[s1[i]] != maze2[s1[i]])
		{
			cout << "false" << endl;
			return;
		}
	}
	cout << "true" << endl;
}
int main()
{
	int n, m;
	string s1, s2;
	cin >> n >> m >> s1 >> s2;
	judge(n, m, s1, s2);
	return 0;
}

int main()
{
	/*int n, m;
	string s1, s2;
	cin >> n >> m >> s1 >> s2;
	judge(n, m, s1, s2);*/
	system("pause");
	return 0;
}
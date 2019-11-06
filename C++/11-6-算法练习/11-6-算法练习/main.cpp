#if 0
#include<string>
using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int maze[256] = { 0 };
	for (int i = 0; i < s2.size(); ++i)
		maze[s2[i]] = -1;
	auto it = s1.begin();
	while (it != s1.end())
	{
		if (maze[*it] == -1)
			it = s1.erase(it);
		else
			++it;
	}
	cout << s1;
}
#endif 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
	int n;
	vector<int> arr;
	cin >> n;
	arr.resize(3 * n);
	for (int i = 0; i < 3 * n; ++i)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	int sum1 = 0;
	for (int i = n; i < 3 * n; i = i + 2)
		sum1 += arr[i];
	int sum2 = 0;
	for (int i = n; i < 2 * n; ++i)
		sum2 += arr[i];
	cout << (sum1 > sum2 ? sum1 : sum2) << endl;
	/*for(int i=n;i+3<3*n;i=i+4)
	{
		sum2+=arr[i]+arr[i+1];
	}
	sum2+=arr[3*n-2];*/
	return 0;
}
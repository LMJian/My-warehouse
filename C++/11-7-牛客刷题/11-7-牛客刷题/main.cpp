#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n == 1 || n == 0)
		cout << n << endl;
	vector<int> arr;
	arr.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	int count = 0;
	for (int i = 1; i < n; ++i)
	{
		while (arr[i] == arr[i - 1])
		{
			++i;
			if (i == n)
			{
				++count;
				continue;
			}
		}
		if (arr[i] >= arr[i - 1] && i < n)
		{
			while (arr[i] >= arr[i - 1] && i < n)
				++i;
			++count;
			if (i == n - 1)
				++count;
			continue;
		}
		if (arr[i] <= arr[i - 1] && i < n)
		{
			while (arr[i] <= arr[i - 1] && i < n)
				++i;
			++count;
			if (i == n - 1)
				++count;
			continue;
		}
	}
	cout << count << endl;
	return 0;
}
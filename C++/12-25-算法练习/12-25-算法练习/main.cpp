#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
	//Insert one char from stringstream
	void Insert(char ch)
	{
		arr.push_back(ch);
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		char set[256] = { 0 };
		for (int i = 0; i < arr.size(); ++i) {
			++set[arr[i]];
		}
		for (int i = 0; i < arr.size(); ++i) {
			if (set[arr[i]] == 1)
				return arr[i];
		}
		return '#';
	}
private:
	vector<char> arr;
};

int main() {
	Solution sa;
	sa.Insert('g');
	sa.Insert('o');
	sa.Insert('o');
	sa.Insert('g');
	sa.Insert('l');
	sa.Insert('e');
	cout<<sa.FirstAppearingOnce() << endl;
	system("pause");
	return 0;
}
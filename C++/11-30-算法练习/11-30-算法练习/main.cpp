#include<iostream>
using namespace std;
#include<vector>

class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		// write code here
		vector<int> arr;
		for (int i = 0; i < gifts.size(); ++i) {
			if (gifts[i] + 1 > arr.size())
				arr.resize(gifts[i] + 1);
			++arr[gifts[i]];
			if (arr[gifts[i]] > (n / 2))
				return gifts[i];
		}
		return 0;
	}
};

int main() {
	Gift g;
	vector<int> arr{ 1,2,3,2,2 };
	cout<<g.getValue(arr, 5)<<endl;
	system("pause");
	return 0;
}
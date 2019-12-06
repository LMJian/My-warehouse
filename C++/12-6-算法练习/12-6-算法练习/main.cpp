#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		vector<int> key;
		for (int i = 0; i < length; ++i) {
			int num = numbers[i];
			if (num + 1 > key.size())
				key.resize(num + 1);
			++key[num];
			if (key[num] > 1)
			{
				*duplication = num;
				return true;
			}
		}
		return false;
	}
};

int main() {
	int arr[] = { 2,3,1,0,2,5,3 };
	int num;
	Solution sa;
	sa.duplicate(arr, 7, &num);
	cout << num << endl;
	system("pause");
	return 0;
}
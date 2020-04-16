#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	/**
	 *	���������е���С������ɺ�
	 *	���룺��������arr
	 *	���أ����������е���С������ɺ�
	 */
	int getFirstUnFormedNum(vector<int> arr, int len) {
		if (arr.size() == 1)
			return arr[0] + 1;

		int max = arr[0];
		int min = arr[0];
		for (int i = 1; i < arr.size(); ++i) {
			max += arr[i];
			if (min > arr[i])
				min = arr[i];
		}

		for (int i = min; i <= max; ++i) {
			if (!Find(arr, 0, i))
				return i;
		}
		return max + 1;
	}
private:
	bool Find(vector<int>& arr, int index, int n) {
		if (n == 0)
			return true;
		if (index == arr.size())
			return false;

		if (n >= arr[index]) {
			if (Find(arr, index + 1, n - arr[index]))
				return true;
		}
		if (Find(arr, index + 1, n))
			return true;
		return false;
	}
};

#include<math.h>

int main() {
	int n;
	while (cin >> n && n != 0) {
		int index = 0;
	LOOP:
		if (n <= pow(3, index))
			cout << index << endl;
		else {
			++index;
			goto LOOP;
		}
	}
	/*Solution sa;
	vector<int> arr{ 9,7,4,10,9,5 };
	sa.getFirstUnFormedNum(arr, arr.size());*/

	system("pause");
	return 0;
}
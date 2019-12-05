#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		vector<int> B;
		B.resize(A.size());
		int res = 1;
		for (int i = 0; i < A.size(); ++i) {
			B[i] = res;
			res *= A[i];
		}
		res = 1;
		for (int i = A.size() - 1; i >= 0; --i) {
			B[i] *= res;
			res *= A[i];
		}
		return B;
	}
};

int main() {
	vector<int> arr{ 1,2,3,4,5,6 };
	Solution sa;
	vector<int> ret = sa.multiply(arr);
	system("pause");
	return 0;
}
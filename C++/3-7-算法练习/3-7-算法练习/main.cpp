#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	vector<string> uncommonFromSentences(string A, string B) {
		unordered_map<string, int> sa;
		auto it = A.begin();
		int left = 0;
		int right = 0;
		while (left != A.size() + 1) {
			right = A.find(' ', right);
			if (right == string::npos)
				right = A.size();
			sa[string(it + left, it + right)]++;
			left = right + 1;
			right = left;
		}

		it = B.begin();
		left = 0;
		right = 0;
		while (left != B.size() + 1) {
			right = B.find(' ', right);
			if (right == string::npos)
				right = B.size();
			sa[string(it + left, it + right)]++;
			left = right + 1;
			right = left;
		}
		vector<string> ret;
		for (auto& e : sa) {
			if (e.second == 1)
				ret.push_back(e.first);
		}
		return ret;
	}
};

int main() {
	Solution sa;
	sa.uncommonFromSentences("this apple is sweet", "this apple is sour");
	system("pause");
	return 0;
}
#include<iostream>
#include<queue>
#include<string>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		const char* ptr = s.c_str();
		queue<char> que;
		int arr[256] = { 0 };
		size_t max = 0;
		while (*ptr != '\0') {
			if (arr[*ptr] == 0) {
				que.push(*ptr);
				arr[*ptr] = 1;
				if (que.size() > max)
					max = que.size();
			}
			else {
				while (que.front() != *ptr) {
					arr[que.front()] = 0;
					que.pop();
				}
				que.pop();
				que.push(*ptr);
			}
			++ptr;
		}
		return max;
	}
};

int main() {
	Solution sa;
	string s = "abcabcbb";
	sa.lengthOfLongestSubstring(s);


	system("pause");
	return 0;
}
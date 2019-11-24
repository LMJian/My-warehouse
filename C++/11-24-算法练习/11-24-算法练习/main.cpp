#include<iostream>
#include<string>
using namespace std;

int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		auto it1 = s1.begin();
		auto it2 = s2.begin();
		while (it1 != s1.end() && it2 != s2.end()) {
			if (*it1 == *it2) {
				++it1;
				++it2;
			}
			else {
				if (*it1 == '?') {
					++it1;
					++it2;
				}
				else if (*it1 == '*') {
					++it1;
					while (*it2 != *it1&&it2 != s2.end())
						++it2;
				}
				else
				{
					cout << "false" << endl;
					break;
				}
			}
		}
		if (it1 == s1.end() && it2 == s2.end())
			cout << "true";
	}
	return 0;
}
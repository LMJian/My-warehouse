#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

string&& StrAdd(const string& left, const string& right) {
	string lef = left;
	string rig = right;
	if (left.size() < right.size()) {
		string t = lef;
		lef = rig;
		rig = t;
	}
	auto max = lef.rbegin();
	auto min = rig.rbegin();
	int count = 0;
	while (min != rig.rend()) {
		*max += *min - '0' + count;
		count = 0;
		if (*max > '9') {
			count = 1;
			*max -= 10;
		}
		++max;
		++min;
	}
	while (count&&max != lef.rend()) {
		*max += count;
		count = 0;
		if (*max > '9') {
			count = 1;
			*max -= 10;
		}
		++max;
	}
	if (count)
		lef = "1" + lef;
	return move(lef);
}

int Compre(const string& left, const string& right) {
	if (left.size() < right.size())
		return -1;
	if (left.size() > right.size())
		return 1;
	return strcmp(left.c_str(), right.c_str());
}

int main() {
	vector<string> arr;
	arr.resize(3);
	while (cin >> arr[0] >> arr[1] >> arr[2]) {
		sort(arr.begin(), arr.end(), [](const string& left, const string& right) {
			return Compre(left, right) < 0;
		});

		string left = StrAdd(arr[0], arr[1]);
		if (Compre(left, arr[2]) > 0)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
#include<iostream> 
#include<algorithm> 
#include<vector>
using namespace std; 

int getLuckyPacket(vector<int>& x, int pos, int sum, int multi) {
	int count = 0; 
	int n = x.size();
	for (int i = pos; i<n; i++) { 
		sum += x[i]; 
		multi *= x[i]; 
		if (sum > multi)
			count += 1 + getLuckyPacket(x, i + 1, sum, multi); 
		else if (x[i] == 1)
			count += getLuckyPacket(x, i + 1, sum, multi); 
		else
			break; 
		sum -= x[i]; 
		multi /= x[i]; 
		while (i < n - 1 && x[i] == x[i + 1]) { 
			i++; 
		} 
	}
	return count; 
}
int main() { 
	int n; 
	while (cin >> n) {
		vector<int> x(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> x[i]; 
		}
		sort(x.begin(), x.end());
		cout << getLuckyPacket(x, 0, 0, 1) << endl; 
	}
	return 0; 
}
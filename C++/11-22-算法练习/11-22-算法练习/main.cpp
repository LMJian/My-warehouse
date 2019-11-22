#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 
//计算约数，求除了1和本身的约数 
void divisorNum(int n, vector<int> &divNum) { 
	for (int i = 2; i <= sqrt(n); i++) { 
		if (n%i == 0) { 
			divNum.push_back(i); 
			//非平方数时还有另一个数也要加入 
			if (n / i != i) 
				divNum.push_back(n / i); 
		}
	}
}
int Jump(int N, int M) { 
	//储存的到达此stepNum点的步数，初始N为1步，从N到N为1步 
	vector<int> stepNum(M + 1, 0); 
	stepNum[N] = 1; 
	for (int i = N; i < M; i++) { 
		//N的所有约数，即为从本身这个点开始能走的数量 
		vector<int> divNum; 
		//0代表这个点不能到 
		if (stepNum[i] == 0) 
			continue; 
		//求出所有能走的步数储存在divNum的容器中 
		divisorNum(i, divNum); 
		for (int j = 0; j < divNum.size(); j++) { 
			//由位置i出发能到达的点为 stepNum[divNum[j]+i] 
			if ((divNum[j] + i) <= M && stepNum[divNum[j] + i] != 0) 
				stepNum[divNum[j] + i] = min(stepNum[divNum[j] + i], stepNum[i] + 1); 
			else if ((divNum[j] + i) <= M) stepNum[divNum[j] + i] = stepNum[i] + 1; 
		} 
	}
	if (stepNum[M] == 0) 
		return -1; 
	else
		//初始化时多给了一步，故需要减1 
		return stepNum[M] - 1; 
}
int main() { 
	int n, m; 
	cin >> n >> m; 
	cout << Jump(n, m) << endl; 
	return 0; 
}
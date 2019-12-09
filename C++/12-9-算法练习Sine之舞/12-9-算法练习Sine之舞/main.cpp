#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char Oper[] = "+-";
void PrintAn(int ret, int N) {
	printf("sin(%d", ret);
	if (ret < N)
	{
		printf("%c", Oper[ret % 2]);
		PrintAn(ret + 1, N);
	}
	else if (ret == N)
	{
		int i;
		for (i = 0; i < N; ++i)
			printf(")");
	}
}
void PrintSn(int ret, int n) {
	if (ret == 1) {
		int i;
		for (i = 0; i < n - 1; ++i)
			printf("(");
	}
	PrintAn(1, ret);
	//printf("A%d", ret);
	printf("+%d", n - ret + 1);
	if (ret != n)
		printf(")");
	if (ret < n)
		PrintSn(ret + 1, n);
}
int main()
{
	int n;
	scanf("%d", &n);
	PrintSn(1, n);
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n;
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
void Sn(int ret) {
	PrintAn(1, ret);
	printf("+%d", n - ret + 1);
	if (ret != n)
		printf(")");
	if (ret < n)
		Sn(ret + 1);
}
void PrintSn() {
	int i;
	for (i = 0; i < n - 1; ++i)
		printf("(");
	Sn(1);
}
int main()
{
	scanf("%d", &n);
	PrintSn();
	return 0;
}
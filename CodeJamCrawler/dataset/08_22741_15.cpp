#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define  MAXN 35
int A[MAXN], B[MAXN], C[MAXN];
int M,N,K,Ans;
void DFS(int step, int Cnt)
{
	if (Cnt >= Ans)
		return;
	if (step == -1)
	{
		if (B[0] == K && Cnt < Ans)
			Ans = Cnt;
		return;
	}
	int i = step;
	if (C[i] > 0)
	{
		B[i] = B[i*2+1] & B[i*2+2];
		if (A[i] > 0)
			DFS(step-1, Cnt);
		else
			DFS(step-1, Cnt+1);
		B[i] = B[i*2+1] | B[i*2+2];
		if (A[i] > 0)
			DFS(step-1, Cnt+1);
		else
			DFS(step-1, Cnt);
	}
	else
	{
		if (A[i])
			B[i] = B[i*2+1] & B[i*2+2];
		else
			B[i] = B[i*2+1] | B[i*2+2];
		DFS(step-1, Cnt);
	}
}

int main ()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int T;
	int Case = 1;
	scanf("%d", &T);
	while (T --)
	{
		scanf("%d %d", &N, &K);
		M = (N-1)>>1;
		int i;
		for (i = 0; i < M; i ++)
		{
			scanf("%d", &A[i]);
			scanf("%d", &C[i]);
		}
		for (i = M; i < N; i ++)
			scanf("%d", &B[i]);
		Ans = M+1;
		DFS(M-1, 0);
		printf("Case #%d: ", Case++);
		if (Ans == M+1)
			puts("IMPOSSIBLE");
		else
			printf("%d\n", Ans);
	}
	return 0;
}
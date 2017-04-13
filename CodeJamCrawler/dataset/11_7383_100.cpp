#include <stdio.h>

void solveCase()
{
	int min = 10000000;
	int sum = 0;
	int xor = 0;
	int N, i, nnum;
	
	scanf("%d", &N);
	
	for (i=0; i<N; i++)
	{
		scanf("%d", &nnum);
		sum += nnum;
		xor ^= nnum;
		if (min > nnum)
			min = nnum;
	}
	
	if (xor != 0)
		printf("NO\n");
	else
		printf("%d\n", sum-min);
}

int main()
{
	int T, i;
	
	scanf("%d", &T);
	
	for (i=0; i<T; i++)
	{
		printf("Case #%d: ", i+1);
		solveCase();
	}
	
	return 0;
}

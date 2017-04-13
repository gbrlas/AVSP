
#include<stdio.h>

int main()
{
	int T, N, C[1000];
	int xor, sum;
	int min;

	scanf("%d", &T);
	for(int i=0; i<T; i++)
	{
		scanf("%d", &N);
		xor = 0;
		for(int j=0; j<N; j++)
		{
			scanf("%d", &C[j]);
			xor = xor ^ C[j];
		}
		if(xor)
			printf("Case #%d: NO\n", i+1);
		else
		{
			min = C[0];
			sum = 0;
			for(int j=0; j<N; j++)
			{
				sum += C[j];
				if(min > C[j])
					min = C[j];
			}
			sum -= min;
			printf("Case #%d: %d\n", i+1, sum);
		}
	}

	return 0;
}
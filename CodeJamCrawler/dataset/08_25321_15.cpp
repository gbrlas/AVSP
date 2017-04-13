#include <stdio.h>
#include <cstdlib>

int compare(const void *a, const void *b)
{
	return *((int*)b) - *((int*)a);
}

int main()
{
	int N, P, K, L;
	int kp;
	int freq[1000];
	
	scanf("%d", &N);
	
	for(int cno=0; cno<N; cno++)
	{
		kp=0;
		scanf("%d %d %d", &P, &K, &L);
		for(int i=0; i<L; i++)
		{
			scanf("%d", &freq[i]);
		}
		
		if(L > K * P)
		{
			printf("Case #%d: Impossible\n", cno+1);
			continue;
		}
		
		qsort(freq, L, sizeof(long), compare);
		
		int mult = 0;
		for(int i=0; i<L; i++)
		{
			if(i%K==0)
				mult++;
			kp = kp + mult * freq[i];
			//printf("%d ", freq[i]);
		}
		
		printf("Case #%d: %d\n", cno+1, kp);
	}
}

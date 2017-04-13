#include<stdio.h>
#include<string.h>
#include<math.h>
#define SZ 20

int N, C[SZ];


int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C.out", "w", stdout);
	int t, i, j, cs, max, c, temp;
	int sSum, sXor, pXor, pSum, res;
	char bin[30];
	scanf("%d", &t);
	for(cs=1; cs<=t; cs++)
	{
		scanf("%d", &N);
		for(i=0; i<N; i++)scanf("%d", &C[i]);
		max = int(pow(2, N))-1;
		res = -1;
		for(i=1; i<=max; i++)
		{
			sSum = sXor = pXor = pSum = 0;
			c = 1;
			temp = i;
			for(j=N-1; j>=0; j--)
			{
				bin[j] = (temp&c)?'1':'0';
				if(bin[j] == '0')
				{
					sSum += C[j];
					sXor = sXor ^ C[j];
				}else{
					pSum += C[j];
					pXor = pXor ^ C[j];
				}
				c <<= 1;
			}
			if( (sXor == pXor) && sSum>res )
				res = sSum;
		}
		if(res == -1)
			printf("Case #%d: NO\n", cs);
		else
			printf("Case #%d: %d\n", cs, res);
	}
	return 0;
}
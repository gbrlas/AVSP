#include <cstdio>


int main()
{
	int T;
	scanf("%d", &T);
	for(int c = 1; c <= T; c++)
	{
		int N, S, P;
		scanf("%d %d %d", &N, &S, &P);
		int W = 0;
		for(int i = 0; i < N; i++)
		{
			int x;
			scanf("%d", &x);
			int max = x/3 + (x%3? 1 : 0);
			if(max >= P)
				W++;
			else if(max+1 == P && S && x>1)
				if(x%3 == 0 || x%3 == 2)
					W++, S--;
		}
		printf("Case #%d: %d\n", c, W);
	}
	return 0;
}

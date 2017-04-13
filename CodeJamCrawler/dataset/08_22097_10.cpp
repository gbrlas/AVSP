#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	int text , N , M , A; 
	freopen("B-small-attempt1.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d", & text );
	int Case = 1 ;
	while (text  --)
	{
		scanf("%d%d%d", &N, & M , &A);
		int   i , j , k , t;  
		printf("Case #%d:", Case ++);
		for ( i  = 0; i <= N; i  ++)
			for (j = 0; j <= N; j ++)
				for (k = 0; k <= M; k ++)
					for (t = 0; t <= M; t ++)
						if (abs(i * t - k * j) == A)
						{
							printf(" 0 0 %d %d %d %d\n", i, k, j, t);
							goto END;
						}
		printf(" IMPOSSIBLE\n");
		continue ;
		END:;
	}
	return 0;
}
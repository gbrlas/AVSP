#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int blag ;
int n,m,A;
void solve()
{
	int xA,xB,yA,yB;
	blag = 0 ;
	for (xA = 0; xA <= n; xA ++)
	{
		for (xB = 0; xB <= n; xB ++)
		{
			for (yA = 0; yA <= m; yA ++)
			{
				for (yB = 0; yB <= m; yB ++)
				{
					if (abs(xA * yB - xB * yA) == A)
					{
						printf(" 0 0 %d %d %d %d\n", xA, yA, xB, yB);
						blag = 1 ;
						return ;
					}
				}
			}
		}
	}
}
int main()
{
	int T,Case;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d", &T);
	for(Case = 1 ; Case <= T ; Case ++)
	{
		scanf("%d%d%d", &n, &m, &A);
		printf("Case #%d:", Case);
		solve() ;
		if (blag == 0)
			printf(" IMPOSSIBLE\n");
	}
	return 0;
}
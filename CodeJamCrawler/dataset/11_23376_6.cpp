#include<stdio.h>

int N, Pd, Pg;
int d[] = {1, 2, 4, 5, 10, 20, 25, 50, 100};

int chk()
{
	int i, j;
	for(i=0; d[i]<=N; i++)
	{
		if( !(Pd%(100/d[i])) )
		{
			for(j=i; j<9; j++)
			{
				if( !(Pg%(100/d[j])) )
				{
					if( (Pd/(100/d[i])) <= (Pg/(100/d[j])) )
						return 1;
				}
			}
		}
	}
	return 0;
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int t, cs;
	
	scanf("%d", &t);
	for(cs=1; cs<=t; cs++)
	{
		scanf("%d%d%d", &N, &Pd, &Pg);
		if( (Pg==100 && Pd!=100) || (!Pg && Pd) )
		{
			printf("Case #%d: Broken\n", cs);
			continue;
		}
		if(chk())
			printf("Case #%d: Possible\n", cs);
		else
			printf("Case #%d: Broken\n", cs);
	}

	return 0;
}
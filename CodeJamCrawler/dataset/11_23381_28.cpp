#include<stdio.h>

int gcd(int m, int n)
{
	if (m == 0)return(n);
	if (n == 0)return(m);
	return(gcd(n, m % n));
}

int lcm(int a, int b) 
{ 
	return a*(b/gcd(a,b));
}

int f[10000];

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C.out", "w", stdout);
	int N, L, H, cs, t;
	int i, con, j;
	scanf("%d", &t);
	for(cs=1; cs<=t; cs++)
	{
		scanf("%d%d%d", &N, &L, &H);
		for(i=0; i<N; i++)scanf("%d", &f[i]);
		
		printf("Case #%d: ", cs);

		for(i=L; i<=H; i++)
		{
			con = 1;
			for(j=0; j<N; j++)
			{
				if(i%f[j] == 0)continue;
				if(f[j]%i == 0)continue;
				con = 0;
				break;
			}
			if(con)
			{
				printf("%d\n", i);
				break;
			}
		}
		if(!con)
			puts("NO");
	}
	return 0;
}
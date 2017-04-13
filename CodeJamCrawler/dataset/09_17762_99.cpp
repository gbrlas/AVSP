#include <stdio.h>
#include <string.h>

#define MOD 10000

int a[510][510];
int uz[510][510];
int n, m, t;
char y[] = {"welcome to code jam"};
char x[510];


int f(int i, int j)
{
	if(j > i)
		return 0;
	if(uz[i][j])
		return a[i][j] % MOD;
	++uz[i][j];
	
	if(i == 0)
	{
		if(x[0] == y[0])
			return a[i][j] = 1;
	
		return a[i][j] = 0;
	}
	if(j == 0)
	{
		if(x[i] == y[0])
			return (a[i][j] = f(i-1, 0)+ 1) % MOD;
		return a[i][j] = f(i-1, 0) % MOD;
	}	

	a[i][j] = f(i-1, j) % MOD;
	if(x[i] == y[j])
		a[i][j] = (a[i][j] + f(i-1, j-1)) % MOD;

	return a[i][j] % MOD;
}
	

int main()
{
	freopen("wel.in", "r", stdin);
	freopen("wel.out", "w", stdout);
	
	scanf("%d\n", &t);
	for(int q = 1; q <= t; ++q)	
	{
		memset(uz, 0, sizeof(uz));
		memset(a, 0, sizeof(a));
		fgets(x, 550, stdin);
				
		n = strlen(x)-1;
		m = strlen(y);

				
		printf("Case #%d: %.4d\n", q, f(n-1, m-1) % MOD);
	}	

	return 0;
}



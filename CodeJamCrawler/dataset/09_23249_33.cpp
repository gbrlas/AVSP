#include<stdio.h>
#include<string.h>
#define infile "welcome.in"
#define outfile "welcome.out"
#define a "welcome to code jam"
#define lmax 515
#define modulo 10000
char b[lmax];
int c[lmax][lmax];
int l;

void golire()
{
	int i,j;
	for(i=0;i<lmax;i++)
		for(j=0;j<lmax;j++)
			c[i][j]=0;
}

int solve()
{
	int i,j,k;
	int nr=0;
	for(i=1;i<=strlen(b);i++)
		if(b[i-1]==a[0])
			c[1][i]=1;
	for(i=1;i<=strlen(a);i++)
		for(j=2;j<=strlen(b);j++)
			if(a[i-1]==b[j-1])
				for(k=1;k<=j;k++)
					c[i][j]=(c[i][j]+c[i-1][k])%modulo;
	for(i=1;i<=strlen(b);i++)
		nr=(nr+c[strlen(a)][i])%modulo;
	return nr;
}

int main()
{
	int k,t;
	freopen(infile,"r",stdin);
	freopen(outfile,"w",stdout);
	
	scanf("%d\n", &t);
	for(k=1;k<=t;k++)
	{
		golire();
		fgets(b,lmax,stdin);
		printf("Case #%d: %4.4d\n", k, solve());
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
#include<stdio.h>
#include<string.h>
#define infile "base.in"
#define outfile "base.out"
#define nmax 101
long long p[nmax][nmax];
char v[nmax];
char w[nmax];

void putter()
{
	int i,j;
	for(i=2;i<nmax-33;i++)
	{
		p[i][0]=1; p[i][1]=i;
		for(j=2;j<nmax-33;j++)
			p[i][j]=p[i][j-1]*i;
	}
}

long long convert(char v[nmax], int n, int b)
{
	long long x=0;
	int i;
	for(i=0;i<n;i++)
		x+=(p[b][n-i-1]*v[i]);
	return x;
}

void solve()
{
	int n=strlen(v)-1; //number of caracter
	int nr=0; //distinct caracter
	int i,j;
	
	w[0]=1;
	for(i=1;i<n && v[i]==v[0];i++) w[i]=1; w[i]=0;
	nr=2;
	for(i++;i<n;i++)
	{
		for(j=0;j<i;j++)
			if(v[i]==v[j])
			{
				w[i]=w[j];
				break;
			}
		if(i==j)
			w[i]=nr++;
	}
	
	//convert number to base 10 and show
	printf("%lld\n",convert(w,n,nr));
}

int main()
{
	int i,t;
	freopen(infile,"r",stdin);
	freopen(outfile,"w",stdout);
	
	putter();
	
	scanf("%d\n",&t);
	for(i=1;i<=t;i++)
	{
		fgets(v,nmax,stdin);
		printf("Case #%d: ",i);
		solve();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
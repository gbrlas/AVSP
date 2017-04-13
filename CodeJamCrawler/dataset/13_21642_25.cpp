#include<stdio.h>
#include<string.h>

double f[1<<20];
int l;

double dfs(int x)
{
	if (f[x]>=0) return f[x];
	int i,j,k;
	f[x]=0;
	for (i=0;i<l;i++)
	{
		j=i;
		k=l;
		while (x&(1<<j))
		{
			j++;
			k--;
			if (j==l) j=0;
		}
		f[x]=f[x]+(k+dfs(x^(1<<j)))/l;
	}
	return f[x];
}

int main()
{
	int t,p;
	char s[21];
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D-small-attempt0.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%s",s);
		l=strlen(s);
		memset(f,-1,sizeof(f));
		f[(1<<l)-1]=0.0;
		int ss=0;
		int i;
		for (i=0;i<l;i++)
			if (s[i]=='X') ss=ss^(1<<i);
		printf("Case #%d: %.14lf\n",p,dfs(ss));
	}
	return 0;
}
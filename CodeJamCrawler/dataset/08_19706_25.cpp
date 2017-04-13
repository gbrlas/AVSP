#include<stdio.h>
#include<string.h>

char s[1001];
char s1[1001];
int n,l;
int res;
int a[6];
bool u[6];

void check()
{
	int i,j,k;
	k=l/n;
	for (j=0;j<k;j++)
	{
		for (i=0;i<n;i++)
			s1[j*n+i]=s[j*n+a[i]];
	}
	j=1;
	for (i=1;i<l;i++)
		if (s1[i]!=s1[i-1]) j++;
	if (j<res) res=j;
}

void dfs(int x)
{
	int i;
	if (x==n) check();
	else
	{
		for (i=0;i<n;i++)
			if (u[i])
			{
				u[i]=false;
				a[x]=i;
				dfs(x+1);
				u[i]=true;
			}
	}
}

int main()
{
	int t,p;
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D-small-attempt0.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d",&n);
		scanf("%s",s);
		l=strlen(s);
		res=l+1;
		memset(u,true,sizeof(u));
		dfs(0);
		printf("Case #%d: %d\n",p,res);
	}
	return 0;
}
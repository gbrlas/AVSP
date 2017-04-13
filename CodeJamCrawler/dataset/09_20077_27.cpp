#include<stdio.h>
#include<string.h>

bool use[12000001][11];
bool check[12000001][11];
int res[101];
char s[101];
int n,b;
bool u[11];

bool dfs(int nn)
{
	int rr=nn;
	int l,i;
	check[nn][b]=true;
	l=0;
	while (nn>0)
	{
		l++;
		res[l]=nn%b;
		nn=nn/b;
	}
	nn=0;
	for (i=1;i<=l;i++)
		nn=nn+res[i]*res[i];
	if (check[nn][b]) use[rr][b]=use[nn][b];
	else use[rr][b]=dfs(nn);
	return use[rr][b];
}

int main()
{
	int i,j;
	int l;
	int t,p;
	memset(use,false,sizeof(use));
	memset(check,false,sizeof(check));
	for (b=2;b<=10;b++)
	{
		use[1][b]=true;
		check[1][b]=true;
	}
	for (n=2;n<=12000000;n++)
		for (b=2;b<=10;b++)
			if (!check[n][b]) use[n][b]=dfs(n);
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	scanf("%d",&t);
	gets(s);
	for (p=1;p<=t;p++)
	{
		gets(s);
		l=strlen(s);
		memset(u,false,sizeof(u));
		if (l%2==0)
		{
			for (i=0;i<l-3;i=i+2)
				u[s[i]-'0']=true;
			u[10]=true;
		}
		else
		{
			for (i=0;i<l;i=i+2)
				u[s[i]-'0']=true;
		}
		for (i=2;i<=12000000;i++)
		{
			for (j=2;j<=10;j++)
				if (u[j]&&(!use[i][j])) break;
			if (j==11) break;
		}
		printf("Case #%d: %d\n",p,i);
	}
	return 0;
}







#include<stdio.h>
#include<string.h>

bool use[100001][11];
int res[11];
bool u[100001];
char s[101];

int main()
{
	int i,j;
	int n,b;
	int l;
	int nn;
	int t,p;
	for (b=2;b<=10;b++)
		use[1][b]=true;
	for (n=2;n<=100000;n++)
	{
		for (b=2;b<=10;b++)
		{
			nn=n;
			memset(u,true,sizeof(u));
			while (nn>=n&&u[nn])
			{
				u[nn]=false;
				l=0;
				while (nn>0)
				{
					l++;
					res[l]=nn%b;
					nn=nn/b;
				}
				for (i=1;i<=l;i++)
					nn=nn+res[i]*res[i];
			}
			if (u[nn]) use[n][b]=use[nn][b];
			else use[n][b]=false;
		}
		//printf("%d\n",n);
	}
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
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
		for (i=2;i<=100000;i++)
		{
			for (j=2;j<=10;j++)
				if (u[j]&&(!use[i][j])) break;
			if (j==11) break;
		}
		printf("Case #%d: %d\n",p,i);
	}
	return 0;
}







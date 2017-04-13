#include<stdio.h>
#include<string.h>

char s[101][101];
char ss[1001][101];
int f[2][101];

int main()
{
	int i,j,k;
	int t,tt;
	int p,q;
	int n,m;
	int mm;
	freopen("A-small-attempt2.in","r",stdin);
	freopen("A-small-attempt2.ans","w",stdout);
	scanf("%d",&t);
	for (tt=1;tt<=t;tt++)
	{
		scanf("%d",&n);
		gets(s[0]);
		for (i=1;i<=n;i++)
			gets(s[i]);
		scanf("%d",&m);
		gets(ss[0]);
		for (i=1;i<=m;i++)
			gets(ss[i]);
		memset(f,0,sizeof(f));
		q=1;
		p=0;
		for (i=m;i>=1;i--)
		{
			for (j=1;j<=n;j++)
				if (strcmp(ss[i],s[j])==0)
				{
					mm=100000;
					for (k=1;k<=n;k++)
						if ((k!=j)&&f[p][k]<mm) mm=f[p][k];
					f[q][j]=mm+1;
				}
				else f[q][j]=f[p][j];
			p=1-p;
			q=1-q;
		}
		mm=100000;
		for (i=1;i<=n;i++)
			if (f[p][i]<mm) mm=f[p][i];
		printf("Case #%d: %d\n",tt,mm);
	}
	return 0;
}



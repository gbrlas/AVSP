#include<stdio.h>
#include<string.h>

char s[5001][16];
char ss[1001];
bool u[5001];
char s1[50];

int main()
{
	int l,n;
	int t,p;
	int i,j,k;
	int ll,r;
	freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
	scanf("%d%d%d",&l,&n,&t);
	for (i=1;i<=n;i++)
		scanf("%s",s[i]);
	for (p=1;p<=t;p++)
	{
		scanf("%s",ss);
		memset(u,true,sizeof(u));
		k=0;
		for (j=0;j<l;j++)
		{
			if (ss[k]=='(')
			{
				ll=0;
				k++;
				while (ss[k]!=')')
				{
					s1[ll]=ss[k];
					ll++;
					k++;
				}
				k++;
			}
			else
			{
				s1[0]=ss[k];
				ll=1;
				k++;
			}
			for (i=1;i<=n;i++)
				if (u[i])
				{
					for (r=0;r<ll;r++)
						if (s[i][j]==s1[r]) break;
					if (r==ll) u[i]=false;
				}
		}
		r=0;
		for (i=1;i<=n;i++)
			if (u[i]) r++;
		printf("Case #%d: %d\n",p,r);
	}
	return 0;
}



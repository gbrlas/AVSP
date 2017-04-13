#include<stdio.h>

char s[4];

int main()
{
	int t,p;
	int n;
	int i,j,k;
	int ii,jj;
	int a;
	int res;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d",&n);
		i=1;
		j=1;
		ii=0;
		jj=0;
		res=0;
		for (k=1;k<=n;k++)
		{
			scanf("%s",s);
			scanf("%d",&a);
			if (s[0]=='O')
			{
				if (i>=a)
				{
					if (ii+i-a>=res) res=ii+i-a+1;
					else res++;
				}
				else
				{
					if (ii+a-i>=res) res=ii+a-i+1;
					else res++;
				}
				i=a;
				ii=res;
			}
			else
			{
				if (j>=a)
				{
					if (jj+j-a>=res) res=jj+j-a+1;
					else res++;
				}
				else
				{
					if (jj+a-j>=res) res=jj+a-j+1;
					else res++;
				}
				j=a;
				jj=res;
			}
		}
		printf("Case #%d: %d\n",p,res);
	}
	return 0;
}



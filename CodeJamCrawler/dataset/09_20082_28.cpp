#include<stdio.h>

char s[41][41];

int main()
{
	int t,p;
	int n,i,j,k;
	int res;
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d",&n);
		for (i=0;i<n;i++)
			scanf("%s",s[i]);
		res=0;
		for (i=0;i<n;i++)
		{
			for (j=i;j<n;j++)
			{
				for (k=i+1;k<n;k++)
					if (s[j][k]=='1') break;
				if (k==n) break;
			}
			res=res+j-i;
			for (j=j-1;j>=i;j--)
				for (k=0;k<n;k++)
					s[j+1][k]=s[j][k];
		}
		printf("Case #%d: %d\n",p,res);
	}
	return 0;
}

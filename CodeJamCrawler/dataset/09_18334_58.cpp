#include<stdio.h>
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++)
	{
		int n;
		scanf("%d",&n);
		static int z[40];
		for(int i=0;i<n;i++)
		{
			static char a[41];
			scanf("%s",a);
			int j;
			for(j=n-1;j&&a[j]=='0';j--);
			z[i]=j;
		}
		int r=0;
		for(int i=0;i<n;i++)
		{
			int j=i;
			for(;j<n;j++)if(z[j]<=i)break;
			r+=j-i;
			for(;j>i;j--)z[j]=z[j-1];
		}
		printf("Case #%d: %d\n",tt,r);
	}
}

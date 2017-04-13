#include<stdio.h>

int a[1001];

int main()
{
	int t,p;
	int n;
	int i,j,k,r;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d",&n);
		for (i=1;i<=n;i++)
			scanf("%d",&a[i]);
		j=0;
		k=n+1;
		int tot=0;
		for (r=1;r<=n;r++)
		{
			int tt=j+1;
			int mm=a[j+1];
			for (i=j+2;i<k;i++)
				if (a[i]<mm)
				{
					mm=a[i];
					tt=i;
				}
			if (tt-j-1<k-tt-1)
			{
				tot=tot+tt-j-1;
				for (i=tt;i>j+1;i--)
					a[i]=a[i-1];
				a[j+1]=mm;
				j++;
			}
			else
			{
				tot=tot+k-tt-1;
				for (i=tt;i<k-1;i++)
					a[i]=a[i+1];
				a[k-1]=mm;
				k--;
			}
		}
		printf("Case #%d: %d\n",p,tot);
	}
	return 0;
}

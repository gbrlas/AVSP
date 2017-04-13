#include<stdio.h>
#include<algorithm>

using namespace std;

double a[1001];
double b[1001];

int main()
{
	int t,p;
	int n;
	int i,j;
	freopen("D-large.in","r",stdin);
	freopen("D-large.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d",&n);
		for (i=1;i<=n;i++)
			scanf("%lf",&a[i]);
		for (i=1;i<=n;i++)
			scanf("%lf",&b[i]);
		sort (a+1,a+n+1);
		sort (b+1,b+n+1);
		i=1;
		for (j=1;j<=n&&i<=n;j++)
		{
			while (i<=n&&a[i]<b[j]) i++;
			i++;
		}
		if (i==n+2) j--;
		printf("Case #%d: %d",p,j-1);
		i=n;
		for (j=n;j>=1&&i>=1;j--)
		{
			while (i>=1&&a[i]>b[j]) i--;
			i--;
		}
		if (i==-1) j++;
		printf(" %d\n",j);
	}
	return 0;
}


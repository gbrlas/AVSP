#include<stdio.h>
#include<algorithm>

using namespace std;

int a[10001];

int main()
{
	int t,p;
	int n,i,j;
	int x;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d%d",&n,&x);
		for (i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort (a+1,a+n+1);
		j=1;
		for (i=n;i>=j;i--)
			if (a[i]+a[j]<=x) j++;
		printf("Case #%d: %d\n",p,n-i);
	}
	return 0;
}



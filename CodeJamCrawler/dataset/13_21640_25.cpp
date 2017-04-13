#include<stdio.h>
#include<algorithm>

using namespace std;

long long a[40];

int main()
{
	int t,p;
	int n;
	int i,j,k;
	long long m;
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%lld",&m);
		scanf("%d",&n);
		for (i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		sort (a+1,a+n+1);
		if (n<=1)
		{
			printf("Case #%d: 0\n",p);
			continue;
		}
		double mm=0;
		long long tot=0;
		a[0]=0;
		a[n+1]=m+a[n]+1;
		for (i=1;i<=n+1;i++)
		{
			long long s=a[i]*(36-n+i)-tot-1;
			if (s>m) s=m;
			s=s+tot;
			if (s<a[i-1]*(36-n+i)) 
			{
				tot=tot+a[i];
				continue;
			}
			for (j=0;j<36-n+i&&j<=s;j++)
			{
				long long h=(s-j)/(36-n+i);
				if (h<a[i-1]) break;
				double sum=0;
				for (k=1;k<=36-n+i-j;k++)
					if (k<=37-n) sum=sum+h*36.0/(36-n+i-j);
					else sum=sum+(h-a[k+n-37])*36.0/(36-n+i-j);
				if (sum-(h*(36-n+i)+j-tot)>mm) mm=sum-(h*(36-n+i)+j-tot);
			}
			tot=tot+a[i];
		}
		printf("Case #%d: %.10lf\n",p,mm);
	}
	return 0;
}

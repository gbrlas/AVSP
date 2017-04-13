# include <stdio.h>
# include <algorithm>
using namespace std;
int T,n;
long long x[805],y[805];
int main()
{
	int i,k;
	long long sum;
	scanf("%d",&T);
	for(k=1;k<=T;k++)
	{
		sum=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&x[i]);
		for(i=0;i<n;i++)
			scanf("%lld",&y[i]);
		sort(x,x+n);
		sort(y,y+n);
		for(i=0;i<n;i++)
			sum+=x[i]*y[n-1-i];
		printf("Case #%d: %lld\n",k,sum);
	}
	return 0;
}

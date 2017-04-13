#include<stdio.h>
#include<algorithm>
using namespace std;
long long x[800],y[800];
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%I64d",x+i);
		for(int i=0;i<n;i++)scanf("%I64d",y+i);
		sort(x,x+n);
		sort(y,y+n);
		long long r=0;
		for(int i=0;i<n;i++)r+=x[i]*y[n-i-1];
		printf("Case #%d: %I64d\n",tt,r);
	}
}

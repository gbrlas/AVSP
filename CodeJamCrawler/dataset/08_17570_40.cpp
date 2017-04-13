#include <iostream>

using namespace std;

int x[10000],y[10000];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T,t,n;
	scanf("%d",&T);
	for(t=1;t<=T;++t)
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i) scanf("%d",x+i);
		for(int i=0;i<n;++i) scanf("%d",y+i);
		sort(x,x+n);
		sort(y,y+n);
		long long r=0;
		for(int i=0;i<n;++i) r+=(long long)x[i]*(long long)y[n-i-1];
		printf("Case #%d: %lld\n",t,r);
	}
	return 0;
}

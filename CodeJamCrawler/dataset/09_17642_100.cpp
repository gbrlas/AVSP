#include <iostream>
#include <cmath>

using namespace std;

int m,d[1000],g[10001][10001];

int f(int a,int b)
{
	if(g[a][b]>-1) return g[a][b];
	int r=INT_MAX;
	for(int i=0;i<m;++i)
		if(d[i]>=a&&d[i]<=b)
		{
			int t=b-a;
			if(d[i]>a) t+=f(a,d[i]-1);
			if(d[i]<b) t+=f(d[i]+1,b);
			if(t<r) r=t;
		}
	if(r==INT_MAX) r=0;
	return g[a][b]=r;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int cc,n;
	cin>>cc;
	for(int zz=1;zz<=cc;++zz)
	{
		cin>>n>>m;
		for(int i=0;i<m;++i) cin>>d[i];
		memset(g,-1,sizeof(g));
		printf("Case #%d: %d\n",zz,f(1,n));
	}
	return 0;
}


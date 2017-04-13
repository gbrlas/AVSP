#include <iostream>
#include <cmath>

using namespace std;

int x[44],y[44],r[44];

double radius(int a,int b)
{
	return (sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]))+r[a]+r[b])*.5;
}

int main()
{
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int zz,n;
	cin>>zz;
	for(int z=1;z<=zz;++z)
	{
		cin>>n;
		for(int i=0;i<n;++i) cin>>x[i]>>y[i]>>r[i];
		double ans;
		if(n==1) ans=r[0];
		else if(n==2) ans=max(r[0],r[1]);
		else
		{
			ans=min(max(double(r[0]),radius(1,2)),min(max(double(r[1]),radius(0,2)),max(double(r[2]),radius(0,1))));
		}
		printf("Case #%d: %.6lf\n",z,ans);
	}
	return 0;
}

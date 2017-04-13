#include<algorithm>
#include<iterator>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<ctime>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=100001;
int v,m,n=0;
double a[maxn];
double r;
double ans;
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d\n",&v);
	for (int u=1;u<=v;u++)
	{
		scanf("%d %d\n",&m,&n);
		a[0]=1;
		for (int i=1;i<=m;i++)
		{
			scanf("%lf",&r);
			a[i]=a[i-1]*r;
		}
		ans=a[m]*(n-m+1)+(1-a[m])*(n+2+n-m);
		for (int i=m;i>=1;i--)
		{
			r=a[i-1]*(n-m+2*(m-i+1)+1)+(1-a[i-1])*(n+n-m+2*(m-i+1)+2);
			ans=min(r,ans);
		}
		ans=min(2.0+n,ans);
		printf("Case #%d: %.6lf\n",u,ans);
	}
	return 0;
}

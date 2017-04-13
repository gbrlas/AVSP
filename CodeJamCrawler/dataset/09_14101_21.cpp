#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<string>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
struct circle
{
	double x,y,r;
};
circle a[15];
int main()
{
	freopen("C:\\Users\\daizhy\\Documents\\output.txt","w",stdout);
	int i,j,k;
	int cas,cc=0,n;
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d",&n);
		for (i=0;i<n;i++)
		{
			scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].r);
		}
		if (n==1)
		{
			printf("Case #%d: %lf\n",++cc,a[0].r);
			continue;
		}
		if (n==2)
		{
			double tmp=sqrt((a[0].x-a[1].x)*(a[0].x-a[1].x)+(a[0].y-a[1].y)*(a[0].y-a[1].y));
			//tmp/=2;
			//tmp+=max(a[0].r,a[1].r);
			tmp=max(a[0].r,a[1].r);
			printf("Case #%d: %lf\n",++cc,tmp);
			continue;
		}
		double ans=999999999.0;
		for (i=0;i<n;i++)
		{
			for (j=i+1;j<n;j++)
			{
				double tmp=sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y));
				tmp+=a[i].r;
				tmp+=a[j].r;
				tmp/=2;
				tmp=max(a[3-i-j].r,tmp);
				ans=min(ans,tmp);
			}
		}
		printf("Case #%d: %lf\n",++cc,ans);
	}
}

	

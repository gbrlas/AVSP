#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
double  a[1010],b[1010];
int used[1010];
int main()
{
	int t,tt,i,j,ans1,ans2;
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	for(scanf("%d",&tt),t=1;t<=tt;++t)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
			scanf("%lf",a+i);
		sort(a+1,a+n+1);
		for(i=1;i<=n;++i)
			scanf("%lf",b+i);
		sort(b+1,b+n+1);
		ans1=0;
		ans2=n;
		memset(used,0,sizeof(used));
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=n;++j)
				if(!used[j]&&b[j]>a[i])
					break;
			if(j<=n)
				used[j]=1;
			else
				++ans1;
		}
		memset(used,0,sizeof(used));
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=n;++j)
				if(!used[j]&&a[j]>b[i])
					break;
			if(j<=n)
				used[j]=1;
			else
				--ans2;
		}
		printf("Case #%d: %d %d\n",t,ans2,ans1);
	}
	return 0;
}

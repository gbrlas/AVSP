#include<cstdio>
#include<cstring>
int a[111];
bool vi[111];
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("test.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int u=1;u<=t;u++)
	{
		int n,s,p;
		int ans=0;
		scanf("%d%d%d",&n,&s,&p);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			int tem;
			if(a[i]%3==0)tem=a[i]/3;
			else tem=a[i]/3+1;
			if(tem>=p)ans++;
			else if(s>0&&(a[i]%3==0||a[i]%3==2)&&(tem+1)==p&&a[i]>=2&&a[i]<=28)
			{
				s--;
				ans++;

			}
		}
		printf("Case #%d: %d\n",u,ans);
				
	}
	return 0;
}





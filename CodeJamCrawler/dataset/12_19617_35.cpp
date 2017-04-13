#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int ck(int t,int p)
{
	bool flag=false;
	for(int i=0;i<=10;i++)
		for(int j=i;j<=i+2&&j<=10;j++)
			for(int k=i;k<=i+2&&k<=10;k++)
			{
				if(i+j+k==t&&max(j,k)>=p)
				{
					if(j-i<2&&k-i<2) return 2;
					else flag=true;
				}
			}
	if(flag) return 1;
	return 0;
}
int main()
{
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	int cas=0,_;
	scanf("%d",&_);
	while(_--)
	{
		int n,s,p;
		scanf("%d%d%d",&n,&s,&p);
		int ans=0;
		while(n--)
		{
			int t;
			scanf("%d",&t);
			int x=ck(t,p);
			if(x==2) ans++;
			else if(x==1&&s) ans++,s--;
		}
		printf("Case #%d: %d\n",++cas,ans);
	}
	return 0;
}

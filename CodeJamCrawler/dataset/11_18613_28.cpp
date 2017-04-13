#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
	int T;
	freopen("cc.in","r",stdin);
	freopen("cc.out","w",stdout);
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		int N,L,H;
		scanf("%d%d%d",&N,&L,&H);
		int num[10001];
		for(int i=0;i<N;i++)
			scanf("%d",&num[i]);
		bool flag=false;
		int ans;
		for(int i=L;i<=H;i++)
		{
			int cnt=0;
			for(int j=0;j<N;j++)
				if(num[j]%i==0||i%num[j]==0)
					cnt++;
			if(cnt==N)
			{
				flag=true;
				ans=i;
				break;
			}
		}
		printf("Case #%d: ",tt);
		if(flag)
		{
			printf("%d\n",ans);
		}
		else
			printf("NO\n");
	}
	return 0;
}

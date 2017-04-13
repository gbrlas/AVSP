#include <iostream>
using namespace std;
int num[1000];
int main()
{
	freopen("C-small-attempt2.in","r",stdin);
	freopen("C1.out","w",stdout);
	int T,N,K,R,i,j;
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d%d%d",&R,&K,&N);
		int sum=0;
		for(j=1;j<=N;j++) { scanf("%d",&num[j]); sum+=num[j]; }
		int now=1,money=0;
		if(sum<=K) { printf("Case #%d: %d\n",i,sum*R); continue; }
		while(R--)
		{
			int moment=0,next;
			for(j=now;;)
			{
				if(j==N) next=1;
				else next=j+1;
				moment+=num[j];
				if(moment+num[next]>K) break;
				j=next;
			}
			now=next;
			money+=moment;
		}
		printf("Case #%d: %d\n",i,money);
	}
	return 0;
}

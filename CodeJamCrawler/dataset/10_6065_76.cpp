#include <iostream>
#include <queue>
using namespace std;

queue <int> que;
long long int sum[2000];
long long int site[2000];
long long int se[2000];
int main()
{
	freopen( "C-large.in", "r", stdin );
	freopen( "Cout.txt", "w", stdout );

	int ca;
	int t;
	scanf("%d",&t);
	long long int r,k,n;
	for(int ca=1;ca<=t;ca++)
	{
		memset(sum,0,sizeof(sum));
		memset(site,0,sizeof(site));
		scanf("%lld%lld%lld",&r,&k,&n);
		long long int tmp;
		long long int all = 0;
		while(!que.empty())
			que.pop();
	
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&se[i]);
			if(all <=k)
				all +=se[i];
			que.push(i);
		}
		
		if(all <=k)
		{
			printf("Case #%d: %lld\n",ca,all*r);
			continue;
		}
		long long int total=0;
		int beg;
		for(int i=1;i<=r;i++)
		{
			long long tmp = 0;
			int now;
			while(1)
			{
				now = que.front();
				
				if(site[now] && !tmp)
				{
					
					beg = site[now];
					int MOD = i-beg;
					total = sum[beg-1] + ((r-beg+1)/MOD)*(sum[i-1]-sum[beg-1]) + sum[ (r-beg+1)%MOD + beg-1 ]-sum[beg-1];
					i=r+1;
					break;
				}
				else if(!tmp)
					site[now]=i;
				
				if(tmp+ se[now] <=k)
				{
					tmp += se[now];
					total +=se[now];
					que.push(now);
					que.pop();
				}
				else
				{
					sum[i]=sum[i-1]+tmp;
					break;
				}
			}
		}
			printf("Case #%d: %lld\n",ca,total);
	}
	
	return 0;	
}

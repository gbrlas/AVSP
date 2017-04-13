#include <iostream>
#include <queue>
using namespace std;

queue <int> que;
int sum[2000];
int site[2000];
int se[2000];
int main()
{
	freopen( "C-small-attempt0.in", "r", stdin );
	freopen( "Cout.txt", "w", stdout );

	int ca;
	int t;
	scanf("%d",&t);
	int r,k,n;
	for(int ca=1;ca<=t;ca++)
	{
		memset(sum,0,sizeof(sum));
		memset(site,0,sizeof(site));
		scanf("%d%d%d",&r,&k,&n);
		int tmp;
		int all = 0;
		while(!que.empty())
			que.pop();
	
		for(int i=0;i<n;i++)
		{
			scanf("%d",&se[i]);
			all +=se[i];
			que.push(i);
		}
		
		if(all <=k)
		{
			printf("Case #%d: %d\n",ca,all*r);
			continue;
		}
		int total=0;
		int beg,end;
		for(int i=1;i<=r;i++)
		{
			tmp = 0;
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
			printf("Case #%d: %d\n",ca,total);
	}
	
	return 0;	
}

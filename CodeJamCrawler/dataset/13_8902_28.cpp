#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

const int MAX=1111;
const long long int MOD=1000002013;

long long int n;

long long int payment(long long int dist)
{
	return n*(n+1)/2-(n-dist)*(n-dist+1)/2;
}

int main(void)
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int c,C;
	scanf("%d",&C);
	for(c=1;c<=C;c++)
	{
		int m;
		long long int o[MAX],e[MAX],p[MAX],loss=0,traffic[2*MAX];
		map<long long int,bool> check;
		vector<long long int> nodes;
		scanf("%lld%d",&n,&m);
		for(int i=0;i<m;i++)
		{
			scanf("%lld%lld%lld",&o[i],&e[i],&p[i]);
			loss=(loss+p[i]*payment(abs(o[i]-e[i])))%MOD;
			if(!check[o[i]])
			{
				check[o[i]]=true;
				nodes.push_back(o[i]);
			}
			if(!check[e[i]])
			{
				check[e[i]]=true;
				nodes.push_back(e[i]);
			}
		}
		sort(nodes.begin(),nodes.end());
		int nodesz=nodes.size()-1;
		for(int i=0;i<nodesz;i++)
			traffic[i]=0;
		for(int i=0;i<m;i++)
		{
			if(o[i]>e[i])
			{
				o[i]^=e[i]; e[i]^=o[i]; o[i]^=e[i];
				p[i]*=-1;
			}
			int j;
			for(j=0;;j++)
				if(nodes[j]==o[i])
					break;
			for(;;j++)
			{
				traffic[j]+=p[i];
				if(nodes[j+1]==e[i])
					break;
			}
		}
		while(true)
		{
			int i,j,sn,en;
			for(i=0;i<nodesz;i++)
				if(traffic[i]>0)
					break;
			if(i==nodesz)
				break;
			sn=i;
			long long int min=987654321;
			for(j=sn;;j++)
			{
				if(traffic[j]<=0)
					break;
				if(min>traffic[j])
					min=traffic[j];
			}
			en=j;
			for(i=sn;i<en;i++)
				traffic[i]-=min;
			loss=(loss-(payment(nodes[en]-nodes[sn])%MOD)*(min%MOD))%MOD;
			if(loss<0)
				loss+=MOD;
		}
		while(true)
		{
			int i,j,sn,en;
			for(i=0;i<nodesz;i++)
				if(-traffic[i]>0)
					break;
			if(i==nodesz)
				break;
			sn=i;
			long long int min=987654321;
			for(j=sn;;j++)
			{
				if(-traffic[j]<=0)
					break;
				if(min>-traffic[j])
					min=-traffic[j];
			}
			en=j;
			for(i=sn;i<en;i++)
				traffic[i]+=min;
			loss=(loss-(payment(nodes[en]-nodes[sn])%MOD)*(min%MOD))%MOD;
			if(loss<0)
				loss+=MOD;
		}
		printf("Case #%d: %lld\n",c,loss);
	}

	return 0;
}
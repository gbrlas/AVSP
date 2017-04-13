#include<iostream>
#include<algorithm>
#define ll __int64
using namespace std;
int main()
{
	freopen("c:/in.txt","r",stdin);
	freopen("c:/out.txt","w",stdout);
	ll n;
	scanf("%I64d",&n);
	ll i;
	for(i=1;i<=n;i++)
	{
		ll p,k,l,j,zimu[1001];
		scanf("%I64d%I64d%I64d",&p,&k,&l);
		for(j=1;j<=l;j++)
			scanf("%I64d",zimu+j);
		if(p*k<l)
		{
			printf("Case #%I64d: Impossible\n",i);//////////////
			continue;
		}
		sort(zimu+1,zimu+l+1);
		ll x=1,sum=0,y;
		for(j=l;j>=k;j-=k,x++)
		{
			for(y=0;y<k;y++)
				sum+=x*zimu[j-y];
		}
		for(;j>0;j--)
		{
			sum+=x*zimu[j];
		}
		printf("Case #%I64d: %I64d\n",i,sum);
	}
	return 0;
}
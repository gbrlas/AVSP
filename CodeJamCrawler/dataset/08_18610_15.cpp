#include<iostream>
#include<algorithm>
#define ll __int64
using namespace std;
int main()
{
	freopen("c:/in.txt","r",stdin);
	freopen("c:/out.txt","w",stdout);
	int n;
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
	{
		int p,k,l,j,zimu[1001];
		scanf("%d%d%d",&p,&k,&l);
		for(j=1;j<=l;j++)
			scanf("%d",zimu+j);
		if(p*k<l)
		{
			printf("Case #%d: Impossible\n",i);//////////////
			continue;
		}
		sort(zimu+1,zimu+l+1);
		int x=1,sum=0,y;
		for(j=l;j>=k;j-=k,x++)
		{
			for(y=0;y<k;y++)
				sum+=x*zimu[j-y];
		}
		for(;j>0;j--)
		{
			sum+=x*zimu[j];
		}
		printf("Case #%d: %d\n",i,sum);
	}
	return 0;
}
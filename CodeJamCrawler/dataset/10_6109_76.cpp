#include <iostream>
#define MAXN 1010
using namespace std;


struct NODE{
	int x,y;	
};

bool operator < (const NODE &a,const NODE &b)
{
	return a.x < b.x;	
	
}
NODE node[MAXN];
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("BBout.txt","w",stdout);
	int ca,cs=1,n;
	scanf("%d",&ca);
	long long int l,p,c;
	while(ca--)
	{
		scanf("%lld%lld%lld",&l,&p,&c);
		long long int ans;
		l*=c;
		for(ans=0;l<p;)
		{
			ans++;
			l*=c;
			c*=c;	
		}
		printf("Case #%d: %lld\n",cs++,ans);
		
	}
	
	
	
	return 0;	
}

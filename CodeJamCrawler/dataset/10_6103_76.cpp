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
	freopen("B-small-attempt0 (1).in","r",stdin);
	freopen("BSout.txt","w",stdout);
	int ca,cs=1,n;
	scanf("%d",&ca);
	int l,p,c;
	while(ca--)
	{
		scanf("%d%d%d",&l,&p,&c);
		int ans;
		l*=c;
		for(ans=0;l<p;)
		{
			ans++;
			l*=c;
			c*=c;	
		}
		printf("Case #%d: %d\n",cs++,ans);
		
	}
	
	
	
	return 0;	
}

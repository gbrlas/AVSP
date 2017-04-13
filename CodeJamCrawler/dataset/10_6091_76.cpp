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
	freopen("A-small-attempt0 (2).in","r",stdin);
	freopen("ASout.txt","w",stdout);
	int ca,cs=1,n;
	scanf("%d",&ca);
	while(ca--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d%d",&node[i].x,&node[i].y);
				
		sort(node,node+n);
		int ans=0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(node[j].x>node[i].x && node[j].y <node[i].y)
					ans++;
				
			}	
		}
		printf("Case #%d: %d\n",cs++,ans);
		
	}
	
	
	
	return 0;	
}

#include <iostream>
#define MAXN 100
using namespace std;


bool canbe[MAXN];
int v[MAXN];
int locat[MAXN];
int main()
{

	freopen("B-small-attempt0 (1).in","r",stdin);
	freopen("BSout.txt","w",stdout);
	int ca,n,k,b,t;
	scanf("%d",&ca);
	int cs=1;
	while(ca--)
	{
		scanf("%d%d%d%d",&n,&k,&b,&t);	
		for(int i=0;i<n;i++)
			scanf("%d",&locat[i]);
		for(int i=0;i<n;i++)
			scanf("%d",&v[i]);
		for(int i=0;i<n;i++)
		{
			if(locat[i] + v[i]*t>=b)
				canbe[i]=true;
			else
				canbe[i]=false;	
		}
		int ans=0;
		for(int i=n-1;i>=0 && k;i--)
		{
			if(canbe[i])
				k--;
			else
			{
				for(int j=i-1;j>=0;j--)
					if(canbe[j])
					{
						canbe[j]=false;
						canbe[i]=true;
						ans+=i-j;
						k--;
						break;
							
					}	
			}
		}
		printf("Case #%d: ",cs++);
		
		if(!k)
			printf("%d\n",ans);
		else
			printf("IMPOSSIBLE\n");
	}	
	
	
}

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <stack>
using namespace std;
#define MAXN 2000
#define INF 1000000000
int m[MAXN];
int t[20][2000];
int cnt[MAXN];
int p;
int L,R,U,D;
int map[200][200];
int last[200][200];
int main()
{
	freopen("C-small-attempt1.in","r",stdin);
	freopen("CSout.txt","w",stdout);	
	
	int ca,cs=1;
	scanf("%d",&ca);
	int n;
	while(ca--)
	{
		scanf("%d",&n);
		memset(map,0,sizeof(map));
		int xi,yi,xf,yf;
		L=INF,R=0,U=INF,D=0;
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d%d",&xi,&yi,&xf,&yf);
			L = min(xi,L);
			R = max(xf,R);
			U = min(U,yi);
			D = max(D,yf);
			for(int i=yi;i<=yf;i++)
				for(int j=xi;j<=xf;j++)
				{	
					if(!map[i][j])
						cnt++;
					map[i][j]=1;
					
				}
		}
		int ans=0;
		
		while(cnt)
		{
			ans++;
			for(int i=D;i>=U;i--)
				for(int j=R;j>=L;j--)
				{
					if(map[i-1][j] && map[i][j-1] && !map[i][j])
					{
						cnt++;
						map[i][j]=1;	
					}	
					else if(!map[i-1][j] && !map[i][j-1] && map[i][j])
					{
						cnt--;
						map[i][j]=0;	
					}
				}	
				
		}
		printf("Case #%d: ",cs++);
		printf("%d\n",ans);		
	
				
		
	}
	return 0;	
}

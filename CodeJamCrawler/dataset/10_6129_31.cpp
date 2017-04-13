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
int t[20000];
int cnt[MAXN];
int p,n;
long long int dp[2000][2][200];

int dc(int beg,int end)	
{
	int ans=0;
	for(int i=beg;i<=end;i++)
	{
		if(cnt[i]<p)
		{
			ans++;	
			for(int j=beg;j<=end;j++)
				cnt[j]++;
			break;
		}
	}
	if(!ans)
		return ans;
	else
		return dc(beg,(beg+end)/2) + dc((beg+end)/2,end)+1;	
	
}
long long int DP( int x, int b, int cnt )
{

    if ( x >= n )
    {
        if(b) cnt--;
        if (cnt +m[x-n] < p )
            return INF;
        else
        	return 0;
        	
		
	}

    if ( dp[ x ][ b ][ cnt ]!=-1 )
        return dp[ x ][ b ][ cnt ];

    dp[ x ][ b ][ cnt ] = INF;
	dp[x][b][cnt] = min( dp[x][b][cnt], DP(2 * x, 1, cnt + 1 ) +DP( 2 * x + 1, 1, cnt + 1 ) );
	dp[x][b][cnt] = min( dp[x][b][cnt], DP(2 * x, 0, cnt ) + DP( 2* x + 1, 1, cnt + 1 ) );
    dp[x][b][cnt] = min( dp[x][b][cnt], DP(2 * x, 0, cnt ) + DP( 2* x + 1, 0, cnt ) );
    dp[x][b][cnt] = min( dp[x][b][cnt], DP(2 * x, 1, cnt + 1 ) +DP( 2 * x + 1, 0, cnt ) );
    
    if (b)
        dp[x][b][cnt] += t[x];


    return dp[x][b][cnt];
}
int main()
{
	freopen("B-large (1).in","r",stdin);
	freopen("BBout1.txt","w",stdout);	
	
	int ca,cs=1;
	scanf("%d",&ca);
	while(ca--)
	{
		scanf("%d",&p);
		n=1;
		for(int i=0;i<p;i++)
			n*=2;
		for(int i=0;i<n;i++)
		{	
			scanf("%d",&m[i]);
			cnt[i]=m[i];
		}
		int N=0;
		for(int h=n/2;h;h/=2,N++)
			for(int i=0;i<h;i++)
				scanf("%d",&t[h+i]);	
		memset(dp,-1,sizeof(dp));
		
		printf("Case #%d: ",cs++);
		printf("%lld\n",min(DP(1,1,1),DP(1,0,0)));		
		
	}
	return 0;	
}

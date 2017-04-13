#include<iostream>
#include<sstream>
#include<algorithm>
#include<cmath>

using namespace std;
const int INF = 1000000;
const int max_size = 10005;
bool logic[max_size];
int val[max_size];
bool can_change[max_size];
int M;
int dp[max_size][4][4];
int f(int x,int Tval,int op)
{
	int ll = 2*x;
	int rr = 2*x+1;
	int r1,r2,r3,r4,r5;
	r1 = r2 = r3 = r4 = r5 = INF;
	if( dp[x][Tval][op] == -2 ) 
		return INF;
	if ( dp[x][Tval][op] != -1 )
		return dp[x][Tval][op];
	if( x>=(M+1)/2 )
	{
		if( val[x] == Tval ) return 0;
		return INF;
	}
		dp[x][Tval][op] = -2;

	if( Tval == 0 && op == 1)
		r1 = min( f( ll, 0, logic[ll]) , f(rr,0,logic[rr] ) );

	if( Tval == 1 && op == 1)
		r2 = f( ll, 1, logic[ll]) + f(rr,1,logic[rr] );

	if( Tval == 0 && op == 0)
		r3 = f( ll, 0, logic[ll]) + f(rr,0,logic[rr] );

	if( Tval == 1 && op == 0)
		r4 = min( f( ll, 1, logic[ll]) , f(rr,1,logic[rr] ) );

	if( can_change[x] )
		r5 = f( x , Tval , !logic[x] )+1;
	return dp[x][Tval][op] = min( min(min( r1,r2) , min(r3,r4)) , r5);

}
int main()
{
	freopen("in.txt","rt",stdin);
	freopen("out.txt","wt",stdout);

	int TC,x,a,b,i;
	cin>>TC;
	for(int tc =1;tc<=TC;tc++)
	{
		memset(dp,-1,sizeof(dp));
		scanf("%d %d",&M,&x);
		for(i=1;i<=M/2;i++)
		{
			scanf("%d %d",&a,&b);
			logic[i] = a;
			can_change[i] = b;
		}
		for(;i<=M;i++)
		{
			scanf("%d",&a);
			val[i] = a;
		}

		a = f(1,x,logic[1]);
		printf("Case #%d: ",tc);
		if( a>= INF ) printf("IMPOSSIBLE\n");
		else printf("%d\n",a);
	}
	return 0;
}

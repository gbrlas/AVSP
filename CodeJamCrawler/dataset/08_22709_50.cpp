#include <stdio.h>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int dp[1001][101];
int N,S,Q;
map<string,int> P ;
char str[200];
#define MIN(a,b) (a) > (b) ? (b) : (a)
void solve()
{
	int i,j,k;
	string temp ;
	for(i = 0 ; i < 1001 ; i ++)
	{
		for(j = 0 ; j < 101 ; j ++)
		{
			dp[i][j] = 1000000 ;
		}
	}
	for(i = 0 ; i < 101 ; i ++)
		dp[0][i] = 0 ;
	for(i = 1 ; i <= Q ; i ++)
	{
		gets(str) ;
		temp = str ;
		for(j = 0 ; j < S ; j ++)
		{
			if(P[temp] == j)
				continue ;
			int x = -1 ;
			for(k = 0 ; k < S ; k ++)
			{
				if(dp[i-1][k] == 1000000)
					continue ;
				if(k == j)
				{
					if(x == -1 || dp[i-1][k] < x)
						x = dp[i-1][k] ;
				}
				else
				{
					if(x == -1 || dp[i-1][k]+1 < x)
						x = dp[i-1][k]+1 ;
				}
			}
			dp[i][j] = x ;
		}
	}
	int Min = -1 ;
	for(i = 0 ; i < S ; i ++)
	{
		if(dp[Q][i] < Min || Min == -1)
			Min = dp[Q][i] ;
	}
	printf("%d\n",Min);
}
int main()
{
	int i;
	int Case ;
	string temp ;
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	while(1 == scanf("%d",&N))
	{
		for(Case = 1 ; Case <= N ; Case ++)
		{
			scanf("%d",&S);
			gets(str);
			P.clear();
			for(i = 0 ; i < S ; i ++)
			{
				gets(str) ;
				temp = str ;
				P[temp] = i ;
			}
			scanf("%d",&Q);
			gets(str) ;
			printf("Case #%d: ",Case);
			solve() ;
		}
	}
	return 0;
}
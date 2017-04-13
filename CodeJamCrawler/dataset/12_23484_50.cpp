#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
int pos[31][2];
int dp[101][101];
int val[101];

int solve(int cur,int p)
{
	if(p<0) return -1000;
	if(cur==-1) return 0;
	if(dp[cur][p]==-1)
	{
		if(pos[val[cur]][0]>=0)
			dp[cur][p]=max(dp[cur][p],pos[val[cur]][0]+solve(cur-1,p));
		if(pos[val[cur]][1]>=0)
			dp[cur][p]=max(dp[cur][p],pos[val[cur]][1]+solve(cur-1,p-1));
	}
	return dp[cur][p];
}

int main()
{
	int T;
	scanf("%d",&T);
	REP(test,T)
	{
		int N,P,S;
		scanf("%d%d%d",&N,&S,&P);
		memset(pos,-1,sizeof(pos));
		memset(dp,-1,sizeof(dp));
		REP(i,N) scanf("%d",&val[i]);
		FOR(i,0,11) FOR(j,i,11) FOR(k,j,11)
		{
			if(k-i>2) continue;
			int flag1,flag2;
			flag1=(k-i==2);
			flag2=(k>=P);
			pos[i+j+k][flag1]=max(pos[i+j+k][flag1],flag2);
		}
		printf("Case #%d: %d\n",test+1,solve(N-1,S));
	}
	return 0;
}

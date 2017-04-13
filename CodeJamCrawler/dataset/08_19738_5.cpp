#include"macro.h"
#define mod 10007


int rock[200][200];
int dp[200][200];




bool ok(int u, int v) {
	return (u>0 && v>0);
}
int a[2]={-1,-2};
int b[2]={-2,-1};
int rec(int u, int v) {
	if (rock[u][v]) return 0;
	if (u==1 && v==1) return 1;
	int answer = 0;

	if (dp[u][v]!=-1) return dp[u][v];

	FOR(i,0,1) {
		int _u = u+a[i];
		int _v = v+b[i];
		if (ok(_u,_v)) {
			int temp = rec(_u, _v) % mod;
			answer = (answer + temp) % mod;
		}
	}

	dp[u][v]=answer;
	return answer;

}

int solve() {	
	int h,w,r;
	scanf("%d %d %d",&h,&w,&r);
	FOR(i,1,r) {
		int a,b;
		scanf("%d %d",&a,&b);
		
		rock[a][b]=true;
	}
	return rec(h,w);
}

int main() {
	freopen("D-small-attempt1.in","r",stdin);
	freopen("D-small-attempt1.out","w",stdout);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	int t;
	scanf("%d",&t);
	FOR(i,1,t)  {		
		CLEARW(dp,-1);
		CLEAR(rock);
		int answer = solve();								
		cout<<"Case #"<<i<<": "<<answer<<endl;		
	}
	return 0;
}

#include <iostream>
#include <string>
using namespace std;

const int MAXN =  10240  ; 
const int INF = 1000000000 ; 

int casenum, ca, n, can[MAXN], V, gate[MAXN], dp[MAXN][2], calc[MAXN][2]; 


inline void update(int &a, int b){
	if(b < a) a = b ; 
}
int work(int np, int v){
	
	if(calc[np][v]) return dp[np][v] ; 
//	if(np > n / 2) return dp[np][v] ; 
//	if(dp[np][v] < INF) return dp[np][v] ; 

	int lc, rc ; 
	lc = np * 2 ; 
	rc = np * 2 + 1 ; 
	int now_ans = INF  ; 
	if(gate[np]){
		if(v == 1){
				now_ans = min(now_ans, work(lc,1) + work(rc,1)) ; 
		}
		else if(v == 0){
				now_ans = min(now_ans, work(lc,0) + work(rc,0)) ; 
				now_ans = min(now_ans, work(lc,0) + work(rc,1)) ; 
				now_ans = min(now_ans, work(lc,1) + work(rc,0)) ; 
		}
		if(can[np]){
			if(v){
				now_ans = min(now_ans, work(lc,0) + work(rc,1) + 1) ; 
				now_ans = min(now_ans, work(lc,1) + work(rc,0) + 1) ; 
				now_ans = min(now_ans, work(lc,1) + work(rc,1) + 1) ; 
			}
			else {
				now_ans = min(now_ans, work(lc,0) + work(rc,0) + 1) ; 
			}
		}
	}
	else {
		if(v){
				now_ans = min(now_ans, work(lc,0) + work(rc,1)) ; 
				now_ans = min(now_ans, work(lc,1) + work(rc,0)) ; 
				now_ans = min(now_ans, work(lc,1) + work(rc,1)) ;
		}
		else {
				now_ans = min(now_ans, work(lc,0) + work(rc,0)) ;
		}
		if(can[np]){
			if(v){
				now_ans = min(now_ans, work(lc,1) + work(rc,1) + 1) ; 
			}
			else {
				now_ans = min(now_ans, work(lc,0) + work(rc,0) + 1) ; 
				now_ans = min(now_ans, work(lc,0) + work(rc,1) + 1) ; 
				now_ans = min(now_ans, work(lc,1) + work(rc,0) + 1) ; 
			}
		}
	}
//	if( np == 4 && v == 1 ) printf("now_ans: %d\n", now_ans);
	calc[np][v] = 1 ; 
	dp[np][v] = now_ans ; 
	return now_ans ; 
}

int main(){
	
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0_out.txt","w",stdout);
	
	scanf("%d",&casenum) ; 
	int i ; 
	for(ca = 1 ; ca <= casenum ; ca++){
		scanf("%d %d",&n,&V) ; 
	//	memset(can,0,sizeof(can)) ; 
		for(i = 1 ; i <= n / 2 ; i++){
			scanf("%d %d", &gate[i], &can[i]) ; 
		}
		for( ; i <= n ; i++){
			scanf("%d",&gate[i]) ; 
		}
		memset(calc,0,sizeof(calc)) ; 
		for(i = 0 ; i <= n ; i++) dp[i][0] = dp[i][1] = INF ; 
		for(i = n / 2 + 1 ; i <= n ; i++){
			dp[i][gate[i]] = 0 ;
			calc[i][0] = calc[i][1] = 1 ; 
		}
		int ans = work(1,V) ; 
		printf("Case #%d: ", ca) ; 
		if(ans < INF) printf("%d\n", ans) ; 
		else printf("IMPOSSIBLE\n");
//		for(i = 1 ; i <= n ; i++)
//			printf("dp[%d][0]: %d, dp[%d][1]: %d\n", i,dp[i][0], i,dp[i][1]);
	}

	return 0; 
}




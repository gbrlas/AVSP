#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

const int INF = 1000000000 ; 

int casenum, ns, nq ; 

string s[110], query[1010] ; 

int dp[1010][110] ; 

char line[300] ; 

int main(){
	int ca = 1 ; 
	int i,j,k ; 
	freopen("A-large.in","r",stdin);
	freopen("A-large_out.txt","w",stdout);
	gets(line) ; 
	sscanf(line, "%d",&casenum);
	while(casenum--){
		gets(line); 
		sscanf(line, "%d",&ns) ; 
		for(i = 0 ; i < ns ; i++){
			gets(line) ; 
			s[i] = string(line) ; 
		}
		gets(line) ; 
		sscanf(line, "%d",&nq) ; 
		printf("Case #%d: ", ca++);
		
		if( nq == 0 ) { printf("0\n") ; continue ; }
		for(i = 0 ; i < nq ; i++){
			gets(line) ; 
			query[i] = string(line) ; 
		}
		for(i = 0 ; i < nq ; i++)
			for(j = 0 ; j < ns ; j++)
				dp[i][j] = INF ; 
		for(i = 0 ; i < ns ; i++){
			if( s[i] != query[0] ) dp[0][i] = 0 ; 
		}
		for(i = 0 ; i < nq - 1 ; i++)
			for(j = 0 ; j < ns ; j++){
				if(dp[i][j] >= INF) continue ; 
				
				if( s[j] != query[i+1] ) dp[i+1][j] <?= dp[i][j] ; 
				for( k = 0 ; k < ns ; k++){
					if(k == j) continue ; 
					if( s[k] != query[i+1] ) dp[i+1][k] <?= dp[i][j] + 1 ; 
				}
			}
		int ans = INT_MAX ; 
		for(i = 0 ; i < ns ; i++)
			ans <?= dp[nq-1][i] ; 
		
		printf("%d\n",ans);
	}		
	return 0;
}

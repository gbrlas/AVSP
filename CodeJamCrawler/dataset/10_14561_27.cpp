#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

int N;
long long L;
int B[200];
long long dp[10010];

void read(){
	scanf("%lld%d", &L, &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &B[i]);
	}
}
int caso = 1;
void process(){
	long long total = 0;	
	sort(B, B + N);
	printf("Case #%d: ", caso++);
	long long x2 = B[N-1]*((long long)B[N-1]);
	if(L >= x2){
		total = (L - x2+1 + B[N-1]-1)/B[N-1];
		L -= total*B[N-1];
	}
	dp[0] = 0;
	for(int i = 1; i <= 10000; i++){
		dp[i] = -1;
	}
	for(int j = 0; j < N; j++){
		dp[B[j]] = 1;
		for(int i = B[j]+1; i <= 10000; i++){			
			if(dp[i-B[j]] != -1){
				if(dp[i] == -1){
					dp[i] = dp[i-B[j]]+1; 
				}else{
					dp[i] = min(dp[i-B[j]]+1, dp[i]); 
				}
			}
		}
	}	
	if(dp[L] == -1){
		printf("IMPOSSIBLE\n");
	}else{
		printf("%lld\n", total + dp[L]);
	}
}

int main(){

	int casos;
	scanf("%d", &casos);

	for(int i = 1; i <= casos; i++){
		read();
		process();	
	}
	
	return 0;
}


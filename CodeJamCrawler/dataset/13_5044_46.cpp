#include <iostream>
#include <cstring>
#define LL long long

using namespace std;

int E, R, N, v[11000];

int dp[100][100];
bool init[100][100];

int opt(int pos, int e){
	if(pos == N) return 0;
	
	if(init[pos][e]) return dp[pos][e];
	
	int best=0;
	for(int i=0; i<=e; ++i){
		int cand = i*v[pos] + opt(pos+1, min(E,e-i+R) );
		best = max(best, cand);
	}
	
	return dp[pos][e] = best;
}

int main(){
	int cases;
	
	cin >> cases;
	for(int q=1; q<=cases; ++q){
		cin >> E >> R >> N;
		for(int i=0; i<N; ++i){
			cin >> v[i];
		}
		
		memset(init, 0, sizeof(init));
		cout << "Case #" << q << ": ";
		cout << opt(0,E) << '\n';
	}
	
	return 0;
}

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int T, R, k, N;
	int gs[1001]= {0};
	bool sign[1001] = {false};
	int ns[1001] = {0};
	int nsum[1001] = {0};
	int next[1001] = {0};
	cin >> T;
	for(int i = 1; i <= T; ++i){
		cin >> R >> k >> N;
		for(int jx = 0; jx < N; ++jx){
			cin >> gs[jx];
			sign[jx] = false;
		}
		int j = 0, loopS =0, loopLen = 0;
		for(int nn = 1; nn <= (N+1); ++nn){
			if (sign[j]){
				loopS = j;
				loopLen = nn - ns[j];
				break;
			}else
				sign[j] = true;
			int tk = k - gs[j];
			int m = (j + 1) % N;
			while(m != j && tk >= gs[m]){
				tk -= gs[m];
				m = m + 1;
				if(m >= N)
					m -= N;
			}
			next[j] = m;
			nsum[j] = k - tk ;
			ns[j] = nn;
			j = m;
		}
		int sum = 0, loopSum = 0, beforeLoopSum = 0, beforeLoopNum = 0;
		bool visited = false;
		int csn = 1;
		for(int m = 0; m < N && csn <= R; m = next[m], ++csn){
			if (m == loopS){
				if (visited){					
					loopSum = sum;
					break;
				}
				beforeLoopSum = sum;
				beforeLoopNum = csn - 1;
				sum = 0;
				visited = true;
			}
			sum += nsum[m];
			nsum[m] = sum;
		}
		__int64 res = 0;
		if (csn > R)
			res = sum + beforeLoopSum;
		else{
			int x = (R - beforeLoopNum) % loopLen;
			__int64 nx = (R - beforeLoopNum) / loopLen;			
			res = beforeLoopSum + nx * loopSum;
			if (x > 0){				
				int stop = loopS, xx = 1;
				for(; xx < x ; ++xx)
					stop = next[stop];
				res += nsum[stop];
			}
		}
		printf("Case #%d: %I64d\n", i,  res);   
	}
}
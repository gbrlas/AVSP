#include <iostream>
#include <memory.h>
#include <math.h>
using namespace std;
typedef long long int64;
int main(){
	int T;
	cin >> T;
	int g[1024];
	int next[1024];
	int64 earn[1024];
	int64 used[1024];
	for(int i = 0; i < T; ++i){
		int64 R, k ,N;
		cin >> R >> k >> N;
		for(int j = 0; j < N; ++j){
			cin >> g[j];
		}
		for(int j = 0; j < N; ++j){
			int64 sum = 0;
			for(int d = 0; d < N; ++d){
				sum += g[(j + d) % N];
				if(sum > k){
					earn[j] = sum - g[(j + d) % N];
					next[j] = (j + d) % N;
					break;
				}else if(d == N - 1){
					earn[j] = sum;
					next[j] = j;
				}
			}
		}
		memset(used, 0, sizeof(used));
		int64 cycsum = 0;
		int64  prelen, cyclen, cnt = 1;
		int64 s = 0;
		while(1){
			used[s] = cnt++;
			s = next[s];
			if(used[s]){
				cyclen = cnt - used[s];
				prelen = used[s] - 1;
				break;
			}
		}
		int it = s;
		do{
			cycsum += earn[it];
			it = next[it];
		}while(it != s);
		int64 res = 0;
		for(int j = 0, pos = 0; j < min(R, prelen); ++j, pos = next[pos]){
			res += earn[pos];
		}
		int64 lR = max(0LL, R - prelen);
		int64 cR = lR / cyclen;
		lR = lR % cyclen;
		res += cycsum * cR;
		for(int j = 0, pos = s; j < lR; pos = next[pos], ++j) res += earn[pos];
		cout << "Case #" << i + 1 << ": " << res << endl; 
	}	
}

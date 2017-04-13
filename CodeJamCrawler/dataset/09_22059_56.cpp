#include <cstdio>
#include <string>
using namespace std;

const int MAXN = 10;

int cnt[MAXN], dig[MAXN]; 

void work(int k, int *s){
	memset(s, 0, sizeof(int) * 10);
	while(k > 0){
		s[k%10]++;
		k /= 10;
	}
}

int main(){
	int casenum, ans, N;
	freopen("B-small-attempt0.in", "r",stdin);
	freopen("B-small-attempt0.out", "w",stdout);
	scanf("%d", &casenum);
	for(int ca = 1 ; ca <= casenum ; ca++){
		scanf("%d", &N);
		work(N, dig);
		ans = -1;
		for(int i = N + 1; i < 100000000 ; i++){
			work(i, cnt);
			int j;
			for(j = 1 ; j < 10 ; j++)
				if(cnt[j] != dig[j]) break;
			if(j >= 10) {
				ans = i;
				break;
			}
		}
		printf("Case #%d: %d\n", ca, ans);
	}	
	return 0;
}

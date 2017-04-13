#include <stdio.h>

int T;        // 1 - 50
int R;        // 1 - 10^8
int k;        // 1 - 10^9
int N;        // 1 - 1000
int g[1001];  // 1 - 10^7
int *pg;
int *spg;
long long eurosum[100000001];

int main(void)
{
	int t, n, r;
	long long s, euro;

	scanf("%d", &T);

	for(t=0; t<T; ++t) {

		euro = 0;

		scanf("%d %d %d", &R, &k, &N);

		pg = g;
		for(n=0; n<N; ++n) {
			scanf("%d", pg++);
		}
		*pg = 0;

		pg = g;
		for(r=0; r<R; ++r) {
			s = 0;
			spg = pg;
			while(1) {
				s += *pg;
				if(s>k) {
					s -= *pg;
					break;
				}
				++pg;
				if(!*pg) pg = g;
				if(spg==pg) break;
			}
			euro += s;
			eurosum[r] = euro;
			if(pg==g) break;
		}

		if(r!=R) {
			euro *= R/(r+1);
			euro += eurosum[R%(r+1)-1];
		}

		printf("Case #%d: %lld\n", t+1, euro);

	}

	return 0;
}

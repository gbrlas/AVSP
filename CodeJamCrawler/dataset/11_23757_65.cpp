#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 1000010;
long long t;
int casenum, N, L, C;
int dis[MAXN], s[MAXN];


int main() {
	int i, j, tp;
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w" , stdout);
	//freopen("B-small-attempt0.in", "r", stdin);
	//freopen("B-small-attempt0.out", "w" , stdout);
	scanf("%d", &casenum);
	for (int ca = 1; ca <= casenum; ca++) {
		scanf("%d %I64d %d %d", &L, &t, &N, &C);
		for (i = 0; i < C; i++) {
			scanf("%d", &dis[i]);
			dis[i] <<= 1;
		}
		for (i = 0, j = 0; i < N; i++) {
			dis[i] = dis[j];
			j++;
			if (j >= C) j -= C;
		}
		long long sum = 0;
		for (i = 0; i < N; i++) {
			if (sum + (long long)dis[i] > t) break;
			sum += (long long)dis[i];
		}
		
		printf("Case #%d: ", ca);
		if (i >= N) {
			printf("%I64d\n", sum);
		} else {
			tp = 0;
			s[tp++] = (sum + (long long)dis[i] - t);
			sum = t;
			for (j = i + 1; j < N; j++) {
				s[tp++] = dis[j];
			}
			sort(s, s+tp);
			for (i = tp - 1; i >= 0; i--) {
				if (L > 0) {
					sum += s[i] / 2;
					L--;
				} else sum += s[i];
			}
			printf("%I64d\n", sum);
		}
	}
	return 0;
}

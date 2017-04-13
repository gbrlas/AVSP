#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>

#define INF 2147483647

using namespace std;

struct Swing
{
	int d, l;
} sw[60010];

int n, D;

bool cmp(const Swing &A, const Swing &B)
{
	return A.d < B.d;
}

int dp[60010];

bool search()
{
	int i, j, dis;

	for (i = n - 1; i >= 0; i--) {
		dp[i] = INF;

		for (j = i + 1; j < n; j++) {
			if (sw[j].d > sw[i].d + sw[i].l) break;

			dis = min(sw[j].d - sw[i].d, sw[j].l);
			if (dis >= dp[j]) {
				dp[i] = sw[j].d - sw[i].d;
				break;
			}
		}
		if (sw[i].d + sw[i].l >= D) 
			dp[i] = min(dp[i], D - sw[i].d);
	}

	return sw[0].d >= dp[0];
}

int main()
{
	int testc, test, i;

	freopen("gcj1.in", "r", stdin);
	freopen("gcj1.out", "w", stdout);
	
	scanf("%d", &testc);
	for (test = 1; test <= testc; test++) {
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d%d", &sw[i].d, &sw[i].l);
		}
		scanf("%d", &D);
		sort(sw, sw + n, cmp);
		
		printf("Case #%d: ", test);
		if (search()) {
			printf("YES\n");
		}
		else printf("NO\n");
	}
	return 0;
}


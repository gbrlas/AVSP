#include <stdio.h>
#include <math.h>
#define MaxN 5
int x[MaxN], y[MaxN], r[MaxN];
int main()
{
	int T, n;
	double t, ans;

	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small.out", "w", stdout);
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++) {
		ans = 1000000000.0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d%d%d", &x[i], &y[i], &r[i]);
		if (n == 1)
			printf("Case #%d: %d\n", cas, r[1]);
		else if (n == 2)
			printf("Case #%d: %d\n", cas, r[1] > r[2] ? r[1] : r[2]);
		else {
			for (int i = 1; i <= 3; i++)
				for (int j = i+1; j <= 3; j++) {
					t = sqrt((double)(x[i]-x[j])*(x[i]-x[j])+(double)(y[i]-y[j])*(y[i]-y[j]));
					t = (t+r[i]+r[j])/2;
					t = t > r[6-i-j] ? t : r[6-i-j];
					if (t < ans) ans = t;
				}
			printf("Case #%d: %.6f\n", cas, ans);
		}
	}
	return 0;
}
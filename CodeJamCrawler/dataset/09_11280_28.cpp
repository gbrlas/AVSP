#include <stdio.h>
#include <string.h>
#define MaxN 50
int a[MaxN];
int main()
{
	int T, n, next, ans;
	char t;

	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++) {
		memset(a, 0, sizeof(a));
		ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				scanf(" %c", &t);
				if (t == '1') a[i] = j;
			}
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++)
				if (a[j] <= i) {
					next = j;
					break;
				}
			ans += next-i;
			for (int j = next; j > i; j--)
				a[j] = a[j-1];
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}
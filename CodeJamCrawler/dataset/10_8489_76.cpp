# include <cstdio>

int main()
{
	int t, n, k, tcase;
	freopen("a-s.in", "r", stdin);
	freopen("a-s.out", "w", stdout);

	scanf("%d", &t);

	for(tcase = 1; tcase <= t; tcase++)
	{
		scanf("%d %d", &n, &k);
		printf("Case #%d: %s\n", tcase, ((k & ~(~0 << n))+1) == (1 << n) ? "ON" : "OFF");
	}

	return 0;
}

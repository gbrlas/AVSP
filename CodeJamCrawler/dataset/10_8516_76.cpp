# include <cstdio>
# include <queue>

using namespace std;

int main()
{
	int t, tcase, r, n, k, x, i, total, cnt, p;
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);

	scanf("%d", &t);

	for(tcase = 1; tcase <= t; tcase++)
	{
		scanf("%d %d %d", &r, &k, &n);

		queue <int> qu, rc;

		for(i = 0; i < n; i++)
		{
			scanf("%d", &x);
			qu.push(x);
		}

		total = 0;

		while(r--)
		{
			cnt = 0;
			while(!qu.empty() && cnt+qu.front() <= k)
			{
				p = qu.front();
				cnt += p;
				rc.push(p);
				qu.pop();
			}

			total += cnt;

			while(!rc.empty())
			{
				qu.push(rc.front());
				rc.pop();
			}
		}

		printf("Case #%d: %d\n", tcase, total);
	}

	return 0;
}
# include <cstdio>
# include <vector>

using namespace std;

int main()
{
	freopen("a-l.in", "r", stdin);
	freopen("a-l.out", "w", stdout);
	int t, tcase, i, j, N, p, q, cnt;

	scanf("%d", &t);

	for(tcase = 1; tcase <= t; tcase++)
	{
		vector < pair<int, int> > v;

		scanf("%d", &N);

		for(i = 0; i < N; i++)
		{
			scanf("%d %d", &p, &q);
			v.push_back(make_pair(p, q));
		}

		cnt = 0;
		for(i = 0; i < N; i++)
			for(j = 0; j < N; j++)
			{
				if(v[i].first > v[j].first && v[i].second < v[j].second) cnt++;
				else if (v[i].first < v[j].first && v[i].second > v[j].second) cnt++;
			}

		printf("Case #%d: %d\n", tcase, cnt/2);
	}

	return 0;
}
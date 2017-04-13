#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

const int maxn = 1000 + 10;
const int maxm = 1000 + 10;

set < pair<int, int> > t;
int h[maxn], w[maxn];
int H[maxm], W[maxm], ans[maxm];
bool x[maxn];
int n, m;

int main()
{
	freopen("A-small-attempt3.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int c;
	scanf("%d", &c);
	for (int tst = 1; tst <= c; ++tst)
	{
		t.clear();

		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			char s[20];
			scanf("%d %d", &h[i], &w[i]);
			gets(s);
			//printf("%d\n", s);
			if (!strcmp(s, " BIRD")) x[i] = 1;
			else x[i] = 0, t.insert( make_pair(h[i], w[i]) );
			//if (tst == 6) printf("%d\n", x[i]);
		}
		scanf("%d", &m);
		for (int i = 0; i < m; ++i) scanf("%d%d", &H[i], &W[i]);

		int bhl = 1000000, bhr = 0, bwl = 1000000, bwr = 0;
		for (int i = 0; i < n; ++i)
			if (x[i]) bhl <?= h[i], bhr >?= h[i], bwl <?= w[i], bwr >?= w[i];

			memset(ans, 0, sizeof(ans));
			for (int i = 0; i < m; ++i)
				if (bhl <= H[i] && H[i] <= bhr && bwl <= W[i] && W[i] <= bwr) ans[i] = 1;

			int hr = 0;
			for (int i = 0; i < n; ++i)
				if (!x[i] && h[i] < bhl && bwl <= w[i] && w[i] <= bwr) hr >?= h[i];
			for (int i = 0; i < m; ++i)
				if (!ans[i] && hr < H[i] && H[i] < bhl && bwl <= W[i] && W[i] <= bwr) ans[i] = 2;

			int hl = 1000001;
			for (int i = 0; i < n; ++i)
				if (!x[i] && bhr < h[i] && bwl <= w[i] && w[i] <= bwr) hl <?= h[i];
			for (int i = 0; i < m; ++i)
				if (!ans[i] && bhr < H[i] && H[i] < hl && bwl <= W[i] && W[i] <= bwr) ans[i] = 2;

			int wr = 0;
			for (int i = 0; i < n; ++i)
				if (!x[i] && bhl <= h[i] && h[i] <= bhr && w[i] < bwl) wr >?= w[i];
			for (int i = 0; i < m; ++i)
				if (!ans[i] && bhl <= H[i] && H[i] <= bhr && wr < W[i] && W[i] < bwl) ans[i] = 2;

			int wl = 1000001;
			for (int i = 0; i < n; ++i)
				if (!x[i] && bhl <= h[i] && h[i] <= bhr && bwr < w[i]) wl <?= w[i];
			for (int i = 0; i < m; ++i)
				if (!ans[i] && bhr <= H[i] && H[i] <= bhr && bwr < W[i] && W[i] < wl) ans[i] = 2;

			for (int i = 0; i < m; ++i)
				if (hr < H[i] && H[i] < bhl && wr < W[i] && W[i] < bwl) ans[i] = 2;

			for (int i = 0; i < m; ++i)
				if (bhr < H[i] && H[i] < hl && wr < W[i] && W[i] < bwl) ans[i] = 2;

			for (int i = 0; i < m; ++i)
				if (hr < H[i] && H[i] < bhl && bwr < W[i] && W[i] < wl) ans[i] = 2;

			for (int i = 0; i < m; ++i)
				if (bhr < H[i] && H[i] < hl && bwr < W[i] && W[i] < wl) ans[i] = 2;

			for (int i = 0; i < m; ++i)
				if (t.find( make_pair(H[i], W[i]) ) != t.end()) ans[i] = 0;

		//if (tst == 6) printf("%d %d %d %d\n", hr, hl, wr, wl);
		printf("Case #%d:\n", tst);
		for (int i = 0; i < m; ++i)
			if (ans[i] == 0) printf("NOT BIRD\n");
			else
				if (ans[i] == 1) printf("BIRD\n");
				else printf("UNKNOWN\n");

		//break;
	}

	return 0;
}

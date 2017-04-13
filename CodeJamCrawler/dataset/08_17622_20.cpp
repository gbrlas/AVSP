#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 800 + 10;
const long long maxnum = 20000000000LL;

long long a[maxn][maxn];
int x[maxn], y[maxn], link[maxn];
long long lx[maxn], ly[maxn];
bool px[maxn], py[maxn];
int n;

bool find(int i)
{
	int j;

	px[i] = 1;
	for (j = 0; j < n; ++j)
		if (a[i][j] == lx[i] + ly[j] && !py[j])
		{
			py[j] = 1;
			if (link[j] == -1 || find(link[j]))
			{
				link[j] = i;
				return 1;
			}
		}
	return 0;
}

void KM()
{
	int i, j, k;
	long long delta;
	
	memset(link, -1, sizeof(link));
	memset(lx, 0, sizeof(lx));
	memset(ly, 0, sizeof(ly));
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			lx[i] = max(lx[i], a[i][j]);

	for (k = 0; k < n; ++k)
		while (1)
		{
			memset(px, 0, sizeof(px));
			memset(py, 0, sizeof(py));
			if (find(k)) break;

			delta = maxnum + 10;
			for (i = 0; i < n; ++i)
				if (px[i])
					for (j = 0; j < n; ++j)
						if (!py[j]) delta = min(delta, lx[i] + ly[j] - a[i][j]);
			if (delta == maxnum + 10 || delta == 0) break;

			for (i = 0; i < n; ++i)
				if (px[i]) lx[i] -= delta;
			for (i = 0; i < n; ++i)
				if (py[i]) ly[i] += delta;
		}
}

int main()
{
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A0.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int tst = 1; tst <= T; ++tst)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &x[i]);
		for (int i = 0; i < n; ++i) scanf("%d", &y[i]);

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				a[i][j] = maxnum - (long long)x[i] * y[j];

		KM();

		long long ans = 0;
		for (int i = 0; i < n; ++i) ans += maxnum - a[link[i]][i];

		printf("Case #%d: %I64d\n", tst, ans);
	}

	return 0;
}

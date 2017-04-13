#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100 + 10;

int sa[maxn], ta[maxn], sb[maxn], tb[maxn];
bool useda[maxn], usedb[maxn];
int n, na, nb, t;

int main()
{
	//freopen("B.in", "r", stdin);
	//freopen("B.out", "w", stdout);
	scanf("%d", &n);
	for (int T = 1; T <= n; ++T)
	{
		scanf("%d%d%d", &t, &na, &nb);
		for (int i = 0; i < na; ++i)
		{
			int hh, mm;
			scanf("%d:%d", &hh, &mm);
			sa[i] = hh * 60 + mm;
			scanf("%d:%d", &hh, &mm);
			ta[i] = hh * 60 + mm;
		}
		for (int i = 0; i < nb; ++i)
		{
			int hh, mm;
			scanf("%d:%d", &hh, &mm);
			sb[i] = hh * 60 + mm;
			scanf("%d:%d", &hh, &mm);
			tb[i] = hh * 60 + mm;
		}

		int cnta = 0, cntb = 0, last = -1, side = 0;
		memset(useda, 0, sizeof(useda));
		memset(usedb, 0, sizeof(usedb));
		while (1)
		{
			int j = -1;
			if (last == -1)
			{
				for (int i = 0; i < na; ++i)
					if (!useda[i] && (j == -1 || sa[i] < sa[j])) j = i;
				int k = -1;
				for (int i = 0; i < nb; ++i)
					if (!usedb[i] && (k == -1 || sb[i] < sb[k])) k = i;
				//printf(" %d %d\n", sa[j], sb[k]);
				side = 0;
				if (j == -1 || k != -1 && sb[k] < sa[j]) j = k, side = 1;
				if (j == -1) break;
				if (side == 0) useda[j] = 1, last = ta[j], ++cnta;
				else usedb[j] = 1, last = tb[j], ++cntb;
			}
			else
				if (side == 0)
				{
					for (int i = 0; i < na; ++i)
						if (!useda[i] && last + t <= sa[i] && (j == -1 || sa[i] < sa[j])) j = i;
					if (j != -1) useda[j] = 1, last = ta[j];
				}
				else
				{
					for (int i = 0; i < nb; ++i)
						if (!usedb[i] && last + t <= sb[i] && (j == -1 || sb[i] < sb[j])) j = i;
					if (j != -1) usedb[j] = 1, last = tb[j];
				}
			//printf("%d %d\n", side, j);
			side = 1 - side;
			if (j == -1)
			{
				last = -1;
				continue;
			}
		}

		printf("Case #%d: %d %d\n", T, cnta, cntb);
	}

	return 0;
}

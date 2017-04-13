#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100 + 10;

int sa[maxn], ta[maxn], sb[maxn], tb[maxn];
bool visiteda[maxn], visitedb[maxn];
int n, na, nb, t;

inline int readin()
{
	int hh, mm;
	scanf("%d:%d", &hh, &mm);
	return hh * 60 + mm;
}

int main()
{
	freopen("b0.in", "r", stdin);
	freopen("b.out", "w", stdout);
	scanf("%d", &n);
	for (int T = 0; T < n; T++)
	{
		scanf("%d%d%d", &t, &na, &nb);
		for (int i = 0; i < na; i++)
		{
			sa[i]=readin();
			ta[i]=readin();
		}
		for (int i = 0; i < nb; i++)
		{
			sb[i]=readin();
			tb[i]=readin();
		}

		int ansa = 0, ansb = 0;
		memset(visiteda, 0, sizeof(visiteda));
		memset(visitedb, 0, sizeof(visitedb));
		for (int last = -1, side = 0; ; side = 1 - side)
		{
			int j = -1;
			if (last == -1)
			{
				for (int i = 0; i < na; i++)
					if (!visiteda[i])
						if (j == -1 || sa[i] < sa[j]) j = i;
				int k = -1;
				for (int i = 0; i < nb; i++)
					if (!visitedb[i])
						if (k == -1 || sb[i] < sb[k]) k = i;
				side = 0;
				if (j == -1 || k != -1 && sb[k] < sa[j]) j = k, side = 1;
				if (j == -1) break;
				if (side == 0) visiteda[j] = 1, last = ta[j], ansa++;
				else visitedb[j] = 1, last = tb[j], ansb++;
			}
			else
				if (side == 0)
				{
					for (int i = 0; i < na; i++)
						if (!visiteda[i] && last + t <= sa[i])
							if (j == -1 || sa[i] < sa[j]) j = i;
					if (j != -1) visiteda[j] = 1, last = ta[j];
					else last = -1;
				}
				else
				{
					for (int i = 0; i < nb; i++)
						if (!visitedb[i] && last + t <= sb[i])
							if (j == -1 || sb[i] < sb[j]) j = i;
					if (j != -1) visitedb[j] = 1, last = tb[j];
					else last = -1;
				}
		}

		printf("Case #%d: %d %d\n", T + 1, ansa, ansb);
	}

	return 0;
}

#include <cstdio>
#include <map>
#include <string>
#include <iostream>

using namespace std;

const int maxs = 100 + 10;
const int maxq = 1000 + 10;

map <string, int> t;
int n, s, q;
bool app[maxs];
string S;

string read()
{
	string S = "";
	char c;
	while (scanf("%c", &c), c != '\n') S += c;
	return S;
}

int main()
{
	freopen("a1.in", "r", stdin);
	freopen("a.out", "w", stdout);
	scanf("%d", &n);
	for (int T = 1; T <= n; T++)
	{
		t.clear();
		scanf("%d\n", &s);
		for (int i = 0; i < s; ++i)	t[S= read()] = i;

		int ans = 0;
		scanf("%d\n", &q);
		memset(app, 0, sizeof(app));
		for (int cnt = 0, i = 0; i < q; i++)
		{
			int idx = t[S = read()];
			if (!app[idx])
			{
				app[idx] = 1;
				if ((++cnt) == s)
				{
					ans++;
					memset(app, 0, sizeof(app));
					cnt = 1; app[idx] = 1;
				}
			}
		}

		printf("Case #%d: %d\n", T, ans);
	}

	return 0;
}

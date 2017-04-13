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

int main()
{
	scanf("%d", &n);
	for (int T = 1; T <= n; ++T)
	{
		t.clear();
		scanf("%d\n", &s);
		for (int i = 0; i < s; ++i)
		{
			S = "";
			char c;
			while (scanf("%c", &c), c != '\n') S += c;
			t[S] = i;
		}

		int ans = 0;
		scanf("%d\n", &q);
		memset(app, 0, sizeof(app));
		for (int num = 0, i = 0; i < q; ++i)
		{
			S = "";
			char c;
			while (scanf("%c", &c), c != '\n') S += c;
			int idx = t[S];
			if (!app[idx])
			{
				if (num + 1 == s)
				{
					++ans;
					memset(app, 0, sizeof(app));
					num = 0;
				}
				app[idx] = 1;
				++num;
			}
		}

		printf("Case #%d: %d\n", T, ans);
	}

	return 0;
}

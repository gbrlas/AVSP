#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxl = 15 + 5;
const int maxd = 5000 + 10;
const int maxn = 500 + 10;

char a[maxd][maxl];
bool b[maxl][26];
char s[maxl * 26];
int l, d, n;


int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("a.out", "w", stdout);

	scanf("%d%d%d", &l, &d, &n);
	for (int i = 0; i < d; ++i) scanf("%s", a[i]);

	for (int i = 0; i < n; ++i)
	{
		scanf("%s", s);

		memset(b, 0, sizeof(b));
		int len = strlen(s);
		for (int k = 0, j = 0; j < len; ++j, ++k)
			if (s[j] == '(') for (++j; s[j] != ')'; ++j) b[k][s[j] - 'a'] = 1;
			else b[k][s[j] - 'a'] = 1;

		int ans = 0;
		for (int j = 0; j < d; ++j)
		{
			bool flag = 1;
			for (int k = 0; k < l; ++k)
				if (!b[k][a[j][k] - 'a'])
				{
					flag = 0;
					break;
				}
			if (flag) ++ans;
		}

		printf("Case #%d: %d\n", i + 1, ans);
	}


	return 0;
}

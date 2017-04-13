#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const char pat[25] = "!welcome to code jam";

const int maxn = 500 + 10;
const int base = 10000;

char s[maxn];
int f[25][maxn];
int n;

int main()
{
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int T;
	scanf("%d\n", &T);
	for (int tst = 1; tst <= T; ++tst)
	{
		s[0] = '!'; s[1] = 0;
		gets(s + 1);
		n = strlen(s);
		
		memset(f, 0, sizeof(f));
		f[0][0] = 1;
		for (int i = 0; i < 19; ++i)
			for (int j = 0; j + 1 < n; ++j)
				if (f[i][j])
				{
					if (pat[i + 1] == s[j + 1]) f[i + 1][j + 1] = (f[i + 1][j + 1] + f[i][j]) % base;
					f[i][j + 1] = (f[i][j + 1] + f[i][j]) % base;
				}

		int ans = 0;
		for (int i = 0; i < n; ++i) ans = (ans + f[19][i]) % base;

		printf("Case #%d: %04d\n", tst, ans);
	}

	return 0;
}

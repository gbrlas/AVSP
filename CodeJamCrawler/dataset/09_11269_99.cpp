#include <stdio.h>
#include <string.h>
#define MOD 10000
char p[] = "welcome to code jam", t[550];
int f[550][20];
int main()
{
	int n, m, len;

	//freopen("C-large.in", "r", stdin);
	//freopen("C-large.out", "w", stdout);
	m = strlen(p);
	scanf("%d ", &n);
	for (int cas = 1; cas <= n; cas++) {
		memset(f, 0, sizeof(f));
		gets(t);
		len = strlen(t);
		for (int i = 0; i <= len; i++)
			f[i][0] = 1;
		for (int i = 1; i <= len; i++)
			for (int j = 1; j <= m; j++)
				if (t[i-1] == p[j-1])
					f[i][j] = (f[i-1][j] + f[i-1][j-1]) % MOD;
				else
					f[i][j] = f[i-1][j];
		printf("Case #%d: ", cas);
		for (int i = 1000; i; i /= 10)
			putchar(f[len][m]/i%10+'0');
		putchar('\n');
	}
	return 0;
}
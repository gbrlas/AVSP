#include <stdio.h>
#include <string.h>

const int N = 55;
char s[N][N];
int used[N][N];

int main ()
{
	//freopen("A-small-attempt1.in", "r", stdin);
	//freopen("A-small-attempt1.out", "w", stdout);
	int ca;
	scanf("%d", &ca);
	int cas = 0;
	while (ca--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			scanf("%s", s[i]);
		}
		memset(used, 0, sizeof(used));
		bool found = true;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (s[i][j] == '.') continue;
				if (!used[i][j])
				{
					if (s[i+1][j] == '#' && s[i][j+1] == '#' && s[i+1][j+1] == '#' && !used[i+1][j] && !used[i][j+1] && !used[i+1][j+1] && i < n - 1 && j < m - 1)
					{
						used[i][j] = '/';
						used[i+1][j] = '\\';
						used[i][j+1] = '\\';
						used[i+1][j+1] = '/';
					}
					else
					{
						found = false;
						break;
					}
				}
			}
		}
		printf("Case #%d:\n", ++cas);
		if (found)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (s[i][j] == '.') printf(".");
					else printf("%c", used[i][j]);
				}
				printf("\n");
			}
		}
		else
		{
			printf("Impossible\n");
		}
	}
	return 0;
}

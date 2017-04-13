#include <stdio.h>
#include <string.h>

char map[100][100];

int main()
{
	int T, ca, i, j, ans, n, m;
	
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	scanf("%d", &T);
	for (ca = 1; ca <= T; ca++) {
		scanf("%d %d", &n, &m);
		for (i = 0; i < n; i++)
			scanf("%s", map[i]);
		
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++) {
				if (map[i][j] == '#') {
					if (i + 1 < n && j + 1 < m
						&& map[i][j + 1] == '#'
						&& map[i + 1][j] == '#'
						&& map[i + 1][j + 1] == '#') {
							map[i][j] = '/';
							map[i + 1][j] = '\\';
							map[i][j + 1] = '\\';
							map[i + 1][j + 1] = '/';							
					}
				}
			}
			
			ans = 0;
			for (i = 0; i < n; i++)
				for (j = 0; j < m; j++)
					if (map[i][j] == '#') {
						ans = 1;
					}
					
			printf("Case #%d:\n", ca);
			if (ans == 1) {
				printf("Impossible\n");
			} else {
				for (i = 0; i < n; i++)
					printf("%s\n", map[i]);
			}
		}
		return 0;
	}
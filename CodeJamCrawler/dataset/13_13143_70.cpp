#include <stdio.h>
#define NN 110
#define MAX(x,y) ((x) > (y) ? (x):(y))

static int map[NN][NN];
static int rmax[NN], cmax[NN];

int main(void)
{
	int T, c, i, j, n, m;
	scanf("%d", &T);
	for (c = 1; c <= T; c++) {
		printf("Case #%d: ", c);
		scanf("%d%d", &n, &m);
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		for (i = 0; i < n; i++) {
			rmax[i] = -1;
			for (j = 0; j < m; j++) {
				rmax[i] = MAX(rmax[i], map[i][j]);
			}
		}
		for (j = 0; j < m; j++) {
			cmax[j] = -1;
			for (i = 0; i < n; i++) {
				cmax[j] = MAX(cmax[j], map[i][j]);
			}
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (map[i][j] < rmax[i] && map[i][j] < cmax[j]) {
					goto res;
				}
			}
		}
res:
		puts(i == n ? "YES" : "NO");
	}
	return 0;
}


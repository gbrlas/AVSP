#include <cstdio>
#include <cstring>
char peta[55][55];
int db[4] = {0, 0, 1, 1};
int dc[4] = {0, 1, 1, 0};
int mch[4] = {'/', '\\', '/', '\\'};
inline void solve(const int &tc) {
	int R, C;
	int i, j;
	memset(peta, 0, sizeof peta);
	scanf("%d %d%*c", &R, &C);
	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++)
			scanf("%c", &peta[i][j]);
		scanf("%*c");
	}
	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++) {
			if (peta[i][j] == '#') {
				for (int k = 0; k < 4; k++) {
					if (peta[i + db[k]][j + dc[k]] != '#') {
						printf("Case #%d:\n", tc + 1);
						puts("Impossible");
						return;
					}
					peta[i + db[k]][j + dc[k]] = mch[k];
				}
			}
		}
	}
	printf("Case #%d:\n", tc + 1);
	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++) {
			printf("%c", peta[i][j]);
		}
		puts("");
	}
}
int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
		solve(i);
	return 0;
}

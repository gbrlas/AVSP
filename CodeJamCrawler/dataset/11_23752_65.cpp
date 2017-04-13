#include <cstdio>
#include <string>
#include <cstdlib>
using namespace std;

const int MAXN = 64;

int casenum, row, col;
char g[MAXN][MAXN];

const int dirx[] = {0, 0, 1, 1};
const int diry[] = {0, 1, 0, 1};
const char pattern[] = {'/', '\\', '\\', '/'};

bool in(const int x, const int y) {
	if (x < 0 || x >= row || y < 0 || y >= col) return false;
	return true;
}

bool work() {
	int i, j;
	int x, y;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			if (g[i][j] != '#') continue;
			for (int d = 0; d < 4; d++) {
				x = i + dirx[d];
				y = j + diry[d];
				if (in(x,y) == false || g[x][y] != '#') return false;
				g[x][y] = pattern[d];
			}
		}
	return true;
}

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	//freopen("A-small-attempt0.in", "r", stdin);
	//freopen("A-small-attempt0.out", "w", stdout);
	scanf("%d", &casenum);
	for (int ca = 1; ca <= casenum; ca++) {
		scanf("%d %d", &row, &col);
		for (int i = 0; i < row; i++)
			scanf("%s", g[i]);
		printf("Case #%d:\n", ca);
		bool ok = work();
		if (!ok) printf("Impossible\n");
		else {
			for (int i = 0; i < row; i++, puts(""))
				for (int j = 0; j < col; j++)
					printf("%c", g[i][j]);
		}
	}
	return 0;
}

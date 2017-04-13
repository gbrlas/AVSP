#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>

using namespace std;

const int GO[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int N, K;
char g[60][60], f[60][60];
int cont[60][60][2][8];

bool valid(int x, int y) { return x >= 0 && x < N && y >= 0 && y < N; }
int calc(int x, int y, int c, int d) {
	if (cont[x][y][c][d] != -1)
		return cont[x][y][c][d];
	int dx = x - GO[d][0], dy = y - GO[d][1], ans;
	ans = valid(dx, dy) ? calc(dx, dy, c, d) : 0;
	ans = c == 0 && f[x][y] == 'R' || c == 1 && f[x][y] == 'B' ? ans + 1 : 0;
	return cont[x][y][c][d] = ans;
}

int main() {
//	freopen("A.in","r",stdin);
//	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%d %d", &N, &K);
		for (int i = 0; i < N; ++i)
			scanf("%s", g[i]);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j)
				f[i][j] = g[N - 1 - j][i];
			f[i][N] = 0;
		}
		for (int i = 0; i < N; ++i) {
			for (int j = N - 1; j >= 0; --j) {
				if (f[j][i] == '.') {
					for (int k = j - 1; k >= 0; --k)
						if (f[k][i] != '.') {
							f[j][i] = f[k][i];
							f[k][i] = '.';
							break;
						}
				}
				for (int k = 0; k < 8; ++k)
					cont[i][j][0][k] = cont[i][j][1][k] = -1;
			}
		}

		bool red = false, blue = false;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				for (int k = 0; k < 8; ++k) {
					if (calc(i, j, 0, k) >= K)
						red = true;
					if (calc(i, j, 1, k) >= K)
						blue = true;
				}
		printf("Case #%d: %s\n", t, red && blue ? "Both" : red ? "Red" : blue ? "Blue" : "Neither");
	}
	return 0;
}


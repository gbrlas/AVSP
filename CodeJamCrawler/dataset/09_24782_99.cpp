#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MAX 105

using namespace std;

int W, H;
int h[MAX][MAX];
int c[MAX][MAX];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int ca = 0;

int DFS (int x, int y) {
	if (c[x][y] != -1)
		return c[x][y];
	int l = -1;
	int hm = h[x][y];
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= 0 && xx < H && yy >= 0 && yy < W)
			if (h[xx][yy] < hm) {
				hm = h[xx][yy];
				l = i;
			}
	}
	if (l == -1) {
		c[x][y] = ca;
		ca++;
	}
	else
		c[x][y] = DFS (x + dx[l], y + dy[l]);
	return c[x][y];
}

int main () {
	int T;
	scanf ("%d", &T);
	for (int tes = 1; tes <= T; tes++) {
		ca = 0;
		scanf ("%d%d", &H, &W);
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++) {
				scanf ("%d", &h[i][j]);
				c[i][j] = -1;
			}
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				if (c[i][j] == -1)
					DFS (i, j);
		printf ("Case #%d:\n", tes);
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++)
				printf ("%c ", (char)(c[i][j] + 'a'));
			printf ("\n");
		}
	}
	return 0;
}

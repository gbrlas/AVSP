#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int MXN = 126;

int n, m;
int ans;
char a[4][4];
int d[4][4];


void search (int i, int j) {
	if (i >= n) {
		int flag = 1;
		for (int x = 0; x < n; x++)
			for (int y = 0; y < m; y++)
				flag = flag & (d[x][y] == 1);
		ans += flag;
		return;
	}
	if (a[i][j] == '-') {
		d[i][(j + 1) % m] ++;
		search (i + (j + 1) / m, (j + 1) % m);
		d[i][(j + 1) % m] --;
		d[i][(j + m - 1) % m] ++;
		search (i + (j + 1) / m, (j + 1) % m);
		d[i][(j + m - 1) % m] --;
	} else if (a[i][j] == '|') {
		d[(i + 1) % n][j] ++;
		search (i + (j + 1) / m, (j + 1) % m);
		d[(i + 1) % n][j] --;
		d[(i + n - 1) % n][j] ++;
		search (i + (j + 1) / m, (j + 1) % m);
		d[(i + n - 1) % n][j] --;
	} else if (a[i][j] == '\\') {
		d[(i + 1) % n][(j + 1) % m] ++;
		search (i + (j + 1) / m, (j + 1) % m);
		d[(i + 1) % n][(j + 1) % m] --;
		d[(i + n - 1) % n][(j + m - 1) % m] ++;
		search (i + (j + 1) / m, (j + 1) % m);
		d[(i + n - 1) % n][(j + m - 1) % m] --;
	} else if (a[i][j] == '/') {
		d[(i + 1) % n][(j + m - 1) % m] ++;
		search (i + (j + 1) / m, (j + 1) % m);
		d[(i + 1) % n][(j + m - 1) % m] --;
		d[(i + n - 1) % n][(j + 1) % m] ++;
		search (i + (j + 1) / m, (j + 1) % m);
		d[(i + n - 1) % n][(j + 1) % m] --;
	}
}

int main () {
    freopen ("C-small-attempt1.in", "r", stdin);
    freopen ("out.txt", "w", stdout);
    int cn;
    scanf ("%d", &cn);
    for (int ci = 0; ci < cn; ci ++) {
		scanf ("%d%d", &n, &m);
		memset (d, 0, sizeof(d));
		ans = 0;
		for (int i = 0; i < n; i++) {
			scanf ("%s", a[i]);
		}
		search (0, 0);
        printf ("Case #%d: %d\n", ci + 1, ans);
    }
    return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int mx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
const int my[] = {0, 0, -1, 1, 1, -1, -1, 1};

char s[10][10];
int tag[10][10];
int n, m;

int get(char c) {
	if (c == '|') return 0;
	if (c == '-') return 1;
	if (c == '/') return 2;
	return 3;
}

void Go(int &x, int &y, int k) {
	x += mx[k];
	y += my[k];
	if (x < 0) x = n - 1;
	if (x == n) x = 0;
	if (y < 0) y = m - 1;
	if (y == m) y = 0;
}

int check(int mask) {
	memset(tag, 0, sizeof(tag));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (!tag[i][j]) {
				int x = i, y = j;
				do {
					tag[x][y] = 1;
					int k = (mask >> (x * m + y)) & 1;
					int p = get(s[x][y]);
					Go(x, y, 2 * p + k);
				} while (!tag[x][y]);
				if (x != i || y != j) return 0;
			}
	return 1;
}

int main(){
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("c.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i) scanf("%s", s[i]);
		int ans = 0;
		for (int i = 0;i < (1 << (n * m)); ++i) ans += check(i);
		printf("Case #%d: %d\n", nCase, ans);
	}

	return 0;
}

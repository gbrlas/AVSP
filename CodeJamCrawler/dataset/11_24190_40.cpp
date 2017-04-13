#include <iostream>
#include <cstdio>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	rep(tc, t) {
		int r, c;
		scanf("%d %d", &r, &c);
		char p[50][60];
		rep(i, r)
			scanf("%s", p[i]);
		bool imp = false;
		rep(i, r) { rep(j, c) {
			if (p[i][j] == '#') {
				if (i == r - 1 || j == c - 1 || p[i][j + 1] == '.' || p[i + 1][j] == '.' || p[i + 1][j + 1] == '.') {
					imp = true;
					break;
				}
				p[i][j] = '/';
				p[i][j + 1] = '\\';
				p[i + 1][j] = '\\';
				p[i + 1][j + 1] = '/';
			}
		}
			if (imp)
				break;
		}
		printf("Case #%d:\n", tc + 1);
		if (imp)
			printf("Impossible\n");
		else {
			rep(i, r)
				printf("%s\n", p[i]);
		}
	}
}
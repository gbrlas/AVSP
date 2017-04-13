#include <cstdio>
#include <cstdlib>
#include <cstring>


int cases, n, m;
char data[100][100];

bool check() {
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(data[i][j] == '#') {
				if(data[i + 1][j] != '#' || data[i][j + 1] != '#' || data[i + 1][j + 1] != '#')
					return false;
				data[i][j] = '/';
				data[i][j + 1] = '\\';
				data[i + 1][j] = '\\';
				data[i + 1][j + 1] = '/';
			}
	return true;
}

int main () {
//	freopen("A-large.in", "r", stdin);
//	freopen("A-large.out", "w", stdout);
	scanf("%d", &cases);
	for(int I = 1; I <= cases; ++I) {
		scanf("%d%d", &n, &m);
		memset(data, 0, sizeof(data));
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				scanf("%1s", &data[i][j]);
		printf("Case #%d:\n", I);
		if(check()) {
			for(int i = 0; i < n; ++i) {
				for(int j = 0; j < m; ++j)
					putchar(data[i][j]);
				puts("");
			}
		}
		else
			puts("Impossible");
	}
	return 0;
}
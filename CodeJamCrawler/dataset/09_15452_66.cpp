#include <iostream>
using namespace std;

int dir[4][2] = {-1, 0, 0, -1, 0, 1, 1, 0};
int ma[110][110];
char ret[110][110];
int fa[11000];
int hash[11000];
int n, m;

inline int find(const int &x) {
	int i = x;
	while(fa[i] != i) {
		i = fa[i];
	}
	fa[x] = i;
	return i;
}

inline void merge(const int &x, const int &y) {
	int fx = find(x);
	int fy = find(y);
	if(fx != fy)
		fa[fy] = fx;
}

inline int idof(const int &x, const int &y) {
	return y + x * m;
}

inline void workitout(const int &x, const int &y) {
	int i, nx, ny, np = -1, t1, t2, mi = 0x7fffffff;
	for(i = 0; i < 4; i++) {
		nx = x + dir[i][0];
		ny = y + dir[i][1];
		if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if(ma[nx][ny] < ma[x][y] && ma[nx][ny] < mi) {
			mi = ma[nx][ny];
			np = i;
		}
	}
	if(np >= 0) {
		t1 = idof(x, y);
		nx = x + dir[np][0];
		ny = y + dir[np][1];
		t2 = idof(nx, ny);
		merge(t1, t2);
	}
}

int main()
{
	//freopen("ACM.in", "r", stdin);
	//freopen("ACM.out", "w", stdout);

	int t, ncs;
	scanf("%d", &t);
	for(ncs = 1; ncs <= t; ncs ++) {
		scanf("%d %d", &n, &m);
		int i, j, tmp;
		int ct = n * m;
		for(i = 0; i < ct; i++) {
			fa[i] = i;
		}

		for(i = 0; i < n; i++) {
			for(j = 0; j < m; j++) {
				scanf("%d", &ma[i][j]);
			}
		}

		for(i = 0; i < n; i++) {
			for(j = 0; j < m; j++) {
				workitout(i, j);
			}
		}
		memset(hash, -1, sizeof(hash));
		ct = 0;
		for(i = 0; i < n; i++) {
			for(j = 0; j < m; j++) {
				tmp = idof(i, j);
				tmp = find(tmp);
				if(hash[tmp] < 0) {
					hash[tmp] = ct ++;
				}
				ret[i][j] = 'a' + hash[tmp];
			}
		}

		printf("Case #%d:\n", ncs);
		for(i = 0; i < n; i++) {
			for(j = 0; j < m; j++) {
				if(j) printf(" ");
				printf("%c", ret[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}

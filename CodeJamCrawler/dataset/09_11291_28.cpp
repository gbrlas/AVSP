#include <stdio.h>
#include <string.h>
#define MaxN 110

int g[MaxN][MaxN], res[MaxN], a[MaxN][MaxN];
bool vst[MaxN];
void clique(int n, int* u, int mat[][MaxN], int size, int& max, int& bb, int* res, int* rr, int* c) {
	int i, j, vn, v[MaxN];
	if (n) {
		if (size + c[u[0]] <= max) return;
		for (i = 0; i < n + size - max && i < n; ++ i) {
			for (j = i + 1, vn = 0; j < n; ++ j)
				if (mat[u[i]][u[j]])
					v[vn ++] = u[j];
			rr[size] = u[i];
			clique(vn, v, mat, size + 1, max, bb, res, rr, c);
			if (bb) return;
		}
	} else if (size > max) {
		max = size;
		for (i = 0; i < size; ++ i)
			res[i] = rr[i];
		bb = 1;
	}
}

int maxclique(int n, int mat[][MaxN], int *ret) {
	int max = 0, bb, c[MaxN], i, j;
	int vn, v[MaxN], rr[MaxN];
	for (c[i = n - 1] = 0; i >= 0; -- i) {
		if (vst[i]) continue;
		for (vn = 0, j = i + 1; j < n; ++ j)
			if (mat[i][j])
				v[vn ++] = j;
		bb = 0;
		rr[0] = i;
		clique(vn, v, mat, 1, max, bb, ret, rr, c);
		c[i] = max;
	}
	return max;
}

int main()
{
	int T, n, m, x, y, ans;

	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small.out", "w", stdout);
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++) {
		memset(vst, 0, sizeof(vst));
		ans = 0;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &a[i][j]);
		for (int i = 0; i < n; i++)
			for (int j = i+1; j < n; j++) {
				g[i][j] = g[j][i] = 0;
				for (int k = 1; k < m; k++) {
					x = a[i][k-1] - a[j][k-1];
					y = a[i][k] - a[j][k];
					if (x >= 0 && y <= 0 || x <= 0 && y >= 0) {
						g[i][j] = g[j][i] = 1;
						break;
					}
				}
			}
		printf("Case #%d: %d\n", cas, maxclique(n, g, res));
		/*
		while ((x=maxclique(n, g, res)) > 0) {
			ans++;
			for (int i = 0; i < x; i++)
				vst[res[i]] = 1;
		}
		printf("Case #%d: %d\n", cas, ans);
		*/
	}
	return 0;
}
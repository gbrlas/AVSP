#include "global.h"

int di[] = {-1, 0, 0, +1, 0};
int dj[] = {0, -1, +1, 0, 0};
int cnt, n, m, a[101][101];
char b[101][101];

char Rec(int ii, int jj)
{
	if (b[ii][jj] != '!') return b[ii][jj];
	int pp=4;
	For(p, 0, 4) {
		int ni = ii+di[p];
		int nj = jj+dj[p];
		if (ni<0 || ni>=n || nj<0 || nj>=m) continue;
		if (pp==-1 || a[ii+di[pp]][jj+dj[pp]]>a[ni][nj]) pp=p;
	}
	if (pp == 4) { b[ii][jj] = 'a'+cnt++; return b[ii][jj]; }
	return b[ii][jj] = Rec(ii+di[pp], jj+dj[pp]);
}

int main()
{
	freopen("B-small.in", "r", stdin);
	freopen("B-small.out", "w", stdout);
	int tt;
	scanf("%d", &tt);
	For(ttt, 0, tt)
	{
		scanf("%d %d", &n, &m);
		For(i, 0, n)
			For(j, 0, m) {
				scanf("%d", &a[i][j]);
				b[i][j] = '!';
			}

		cnt = 0;
		For(i, 0, n)
			For(j, 0, m)
				Rec(i, j);

		printf("Case #%d:\n", ttt+1);
		For(i, 0, n)
			For(j, 0, m)
				printf("%c%c", b[i][j], j<m-1 ? ' ' : '\n');
	}
	return 0;
}
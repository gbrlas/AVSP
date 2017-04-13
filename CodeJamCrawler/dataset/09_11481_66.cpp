#include <iostream>
#include <cmath>
using namespace std;

int p[10010];

int find_set (int x)
{
	int t, px = x;
	while (px != p[px])
		px = p[px];
	while (x != px)
	{
		t = p[x];
		p[x] = px;
		x = t;
	}
	return px;
}

void union_set (int x , int y)
{
	x = find_set(x);
	y = find_set(y);
	if (x == y)
		return ;
	if (x < y)
		p[y] = x;
	else
		p[x] = y;
}

int t, n, m, g[110][110];
int go[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
char ans[110][110];

int main ()
{
	freopen ("B-small.in", "r", stdin);
	freopen ("B-small.out", "w", stdout);
	scanf("%d", &t);
	for (int ncase = 1; ncase <= t; ncase++){
		for (int i = 0; i < 10010; i++)
			p[i] = i;
		memset (ans, 0, sizeof (ans));
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &g[i][j]);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++){
				int minx = INT_MAX, mink = 0;
				for (int k = 0; k < 4; k++){
					int dx = i + go[k][0];
					int dy = j + go[k][1];
					if (dx >= 0 && dx < n && dy >= 0 && dy < m)
						if (minx > g[dx][dy])
							minx = g[dx][dy], mink = k;
				}
				if (minx < g[i][j])
					union_set (i * m + j,
					(i + go[mink][0]) * m + (j + go[mink][1]));
			}
		printf("Case #%d:\n", ncase);
		char ch = 'a';
		ans[0][0] = ch++;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				int t = find_set (i * m + j);
				if (ans[t / m][t % m] != '\0')
					ans[i][j] = ans[t / m][t % m];
				else
					ans[i][j] = ch++;
				printf("%c ", ans[i][j]);
			}
			printf("\n");
		}
	}
}
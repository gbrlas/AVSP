# include <iostream>
# include <vector>

using namespace std;

int map[110][110], pred[110][110], m, n;
char map2[110][110];
vector < pair<int, int> > g[110][110];
int move[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

void visit(int x, int y, char c)
{
	int i;
	map2[x][y] = c;

	for(i = 0; i < g[x][y].size(); i++)
		if(!map2[g[x][y][i].first][g[x][y][i].second])
			visit(g[x][y][i].first, g[x][y][i].second, c);
}

void dfs()
{
	int i, j;
	char c = 'a';

	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			if(!map2[i][j])
				visit(i, j, c++);
}

int main()
{
	freopen("b-s.in", "r", stdin);
	freopen("b-s.out", "w", stdout);
    int t, tcase, i, j, k;

    scanf("%d", &t);

    for(tcase = 1; tcase <= t; tcase++)
    {
        scanf("%d %d", &m, &n);

        for(i = 0; i < m; i++)
            for(j = 0; j < n; j++)
			{
                scanf("%d", &map[i][j]);
				g[i][j].clear();
				map2[i][j] = 0;
			}
			
		for(i = 0; i < m; i++)
		{
			for(j = 0; j < n; j++)
			{
				int x;
				int cur = 10000000;
				int u = -1, v = -1;

				for(x = 0; x < 4; x++)
				{
					int p = i+move[x][0];
					int q = j+move[x][1];
					
					if(p >= 0 && p < m && q >= 0 && q < n && map[p][q] < map[i][j] && map[p][q] <= cur)
					{
						cur = map[p][q];
						u = p;
						v = q;
					}
				}

				if(u != -1 && v != -1)
				{
					g[i][j].push_back(make_pair(u, v));
					g[u][v].push_back(make_pair(i, j));
				}
			}
		}

		dfs();

		printf("Case #%d:\n", tcase);

		for(i = 0; i < m; i++)
		{
			for(j = 0; j < n-1; j++)
				printf("%c ", map2[i][j]);
			printf("%c\n", map2[i][j]);
		}
	}
	
	return 0;
}

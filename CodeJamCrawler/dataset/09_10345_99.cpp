#include <iostream>
#include <vector>
using namespace std;

int t, h, w, f;

int hash[110][110];
int num[110][110];

int xx[5] = {-1, 0, 0, 1};
int yy[5] = {0, -1, 1, 0};

struct node
{
	int i, j;
};
vector<node> vt;

void dfs(int x, int y, int id)
{
	if (hash[x][y] != -1)
	{
		f = hash[x][y];
		return;
	}
	node N;
	N.i = x;
	N.j = y;
	vt.push_back(N);
	hash[x][y] = id;
	int lmin = INT_MAX, i;
	for (i = 0; i < 4; i++)
	{
		int nx = x + xx[i];
		int ny = y + yy[i];
		if (nx >= 0 && nx < h && ny >= 0 && ny < w && num[nx][ny] < num[x][y])
		{
			if (num[nx][ny] < lmin)
			{
				lmin = num[nx][ny];
			}
		}
	}
	for (i = 0; i < 4; i++)
	{
		int nx = x + xx[i];
		int ny = y + yy[i];
		if (nx >= 0 && nx < h && ny >= 0 && ny < w && num[nx][ny] == lmin)
		{
			dfs(nx, ny, id);
			break;
		}
	}
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w+", stdout);
	int i, j, k, id, tt = 0;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &h, &w);
		for (i = 0; i < h; i++)
		{
			for (j = 0; j < w; j++)
			{
				scanf("%d", &num[i][j]);
			}
		}
		memset (hash, -1, sizeof(hash));
		id = 0;
		for (i = 0; i < h; i++)
		{
			for (j = 0; j < w; j++)
			{
				if (hash[i][j] == -1)
				{
					f = -1;
					vt.clear();
					dfs(i, j, id);
					if (f == -1)
					{
						id++;
					}
					else
					{
						for (k = 0; k < vt.size(); k++)
						{
							hash[vt[k].i][vt[k].j] = f;
						}
					}
				}
			}
		}
		printf("Case #%d:\n", ++tt);
		for (i = 0; i < h; i++)
		{
			for (j = 0; j < w - 1; j++)
			{
				printf("%c ", hash[i][j] + 'a');
			}
			printf("%c\n", hash[i][w - 1] + 'a');
		}
	}
	return 0;
}
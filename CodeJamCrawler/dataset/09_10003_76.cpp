#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
#include <set>
#include <list>
#include <map>
#include <queue>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include "../SuperTimer.h"
using namespace std;

int T, H, W;
int att[110][110];
char basin[110][110];
char chTotal;

//North, West, East, South.
int dir[4][2] = {
	{-1,0},
	{0,-1},
	{0,1},
	{1,0}
};

char dfs(int x, int y, char chSrc)
{
	if (basin[x][y] >= 'a' && basin[x][y] <= 'z')
		return basin[x][y];

	basin[x][y] = 1;

	int neighb[4], lowest = 99999;
	for (int i = 0; i < 4; i ++)
	{
		neighb[i] = 99999;
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if (tx < 0 || tx >= H || ty < 0 || ty >= W || basin[tx][ty] == 1)
			continue;
		//tx = (tx + H) % H;
		neighb[i] = att[tx][ty];
		lowest = min(lowest, neighb[i]);
	}

	if (lowest >= att[x][y])
	{
		// sink
		return basin[x][y] = chSrc;
	}

	for (int i = 0; i < 4; i ++)
	{
		if (lowest != neighb[i])
			continue;
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		//tx = (tx + H) % H;

		return basin[x][y] = dfs(tx, ty, chSrc);
	}
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);

	cin >> T;
	for (int cas = 1; cas <= T; cas ++)
	{
		printf("Case #%d:\n", cas);
		cin >> H >> W;
		for (int i = 0; i < H; i ++)
			for (int j = 0; j < W; j ++)
				cin >> att[i][j];

		memset(basin, 0, sizeof(basin));
		chTotal = 'a';
		for (int i = 0; i < H; i ++)
			for (int j = 0; j < W; j ++)
			{
				if (basin[i][j] == 0)
				{
					dfs(i, j, chTotal);
					if (chTotal == basin[i][j])
						chTotal ++;
				}
				putchar(basin[i][j]);
				putchar(j + 1 == W ? '\n' : ' ');
			}
	}
}
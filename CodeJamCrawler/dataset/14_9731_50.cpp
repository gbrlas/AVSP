#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;

int W, H, B;
bool mapp[100][500];
int c[] = {0,-1,0,1};
int d[] = {-1,0,1,0};

bool parcours(int x, int y, int direction)
{
	int newx, newy;
	bool retiens = false;
	
	mapp[x][y] = false;
	
	if(y == H-1) return true;
	
	for(int i = 0; i < 4; i++)
	{
		newx = x+c[(direction + 3 + i)%4];
		newy = y+d[(direction + 3 + i)%4];

		if(newx >= 0 && newy >= 0 && newx < W && newy < H && mapp[newx][newy])
		{
			retiens = parcours(newx, newy, (direction + 3 + i)%4);
			if(retiens) return true;
		}
	}
	return false;
}

int main()
{
	int T;
	int x0, x1, y0, y1;
	int rep;
	
	scanf("%d", &T);
	
	for(int t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		
		scanf("%d %d %d", &W, &H, &B);
		
		for(int i = 0; i < W; i++) for(int j = 0; j < H; j++) mapp[i][j] = true;
		
		for(int i = 0; i < B; i++)
		{
			scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
			
			for(int j = x0; j <= x1; j++) for(int k = y0; k <= y1; k++) mapp[j][k] = false;
		}
		
		rep = 0;
		for(int depart = 0; depart < W; depart++)
		{
			int x = depart;
			int y = 0;
			
			if(mapp[x][y] && parcours(x, y, 2)) rep++;
		}

		printf("%d\n", rep);
	}

	return 0;
}

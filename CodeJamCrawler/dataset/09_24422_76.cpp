#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <queue>

#define SZ(a) (int)(a).size()
#define PB push_back
#define ALL(a) (a).begin(),(a).end()
#define INF (int)1e9

#define ll long long
#define vi vector<int>
#define vs vector<string>

using namespace std;

bool exists(int x, int y, int H, int W)
{
	if(x < 0 || y < 0 || x >= H || y >= W)
		return false;
	return true;
}

int main()
{
	int T;
	cin >> T;
	
	for(int cas = 1; cas <= T; cas++)
	{
		int H, W;
		cin >> H >> W;
		int map[H][W];
		for(int i = 0; i < H; i++)
		{
			for(int j = 0; j < W; j++)
			{
				cin >> map[i][j];
			}
		}
		
		int drain[H][W];
		int dx[] = {-1, 0, 0, 1};
		int dy[] = {0, -1, 1, 0};
		
		for(int i = 0; i < H; i++)
		{
			for(int j = 0; j < W; j++)
			{
				int ht = map[i][j], bestdir = -1;
				for(int dir = 0; dir < 4; dir++)
				{
					int xx = i + dx[dir], yy = j + dy[dir];
					if(exists(xx, yy, H, W) && map[xx][yy] < ht)
					{
						ht = map[xx][yy];
						bestdir = dir;
					}
				}
				
				drain[i][j] = bestdir;
			}
		}
		
		char ret[H][W];
		int vis[H][W];
		memset(ret, 0, sizeof(ret));
		memset(vis, 0, sizeof(vis));
				
		int set = 0;
		for(int i = 0; i < H; i++)
		{
			for(int j = 0; j < W; j++)
			{
				if(drain[i][j] == -1)
				{
					set++;
					queue<int> qx, qy;
					qx.push(i);
					qy.push(j);
					
					while(!qx.empty())
					{
						int x = qx.front(), y = qy.front();
						qx.pop();
						qy.pop();
						if(vis[x][y] != 0)
							continue;
						else
						{
							vis[x][y] = set;
							
							for(int dir = 0; dir < 4; dir++)
							{
								int xx = x + dx[dir], yy = y + dy[dir];
								if(exists(xx, yy, H, W))
								{
									
									if( (dir == 0 && drain[xx][yy] == 3) ||
										(dir == 1 && drain[xx][yy] == 2) ||
										(dir == 2 && drain[xx][yy] == 1) ||
										(dir == 3 && drain[xx][yy] == 0) )
									{
										qx.push(xx);
										qy.push(yy);
									}
								}
							}
							
						}
						
					}
				}
			}
		}
		
		int mapping[30];
		memset(mapping, 0, sizeof(mapping));
		int cur = 'a';
			
		for(int i = 0; i < H; i++)
		{
			for(int j = 0; j < W; j++)
			{
				if(mapping[vis[i][j]] == 0)
				{
					mapping[vis[i][j]] = cur++;
				}
				ret[i][j] = mapping[vis[i][j]];
				
			}
		}		
				
		cout << "Case #" << cas << ": " << endl;
		for(int i = 0; i < H; i++)
		{
			for(int j = 0; j < W; j++)
			{
				cout << ret[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}

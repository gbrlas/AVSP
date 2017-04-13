#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>
#include <algorithm>

typedef long long ll;
typedef long double ld;

using namespace std;

char tiles[50][50];

void solve()
{
	puts("");

	int R, C;
	cin >> R >> C;

	int total=0;

	for(int i=0; i<R; ++i)
	{
		for(int j=0; j<C; ++j)
		{
			cin >> tiles[i][j];
			if(tiles[i][j] == '#')
				total++;
		}
	}

	if(total % 4 != 0)
	{
		puts("Impossible");
		return;
	}

	for(int i=0; i<R; ++i)
	{
		for(int j=0; j<C; ++j)
		{
			if(tiles[i][j] == '#')
			{
				if(i == R-1 || j == C-1 || tiles[i+1][j] != '#' || tiles[i][j+1] != '#' || tiles[i+1][j+1] != '#')
				{
					puts("Impossible");
					return;
				}
				else
				{
					tiles[i][j] = '/';
					tiles[i+1][j] = '\\';
					tiles[i][j+1] = '\\';
					tiles[i+1][j+1] = '/';
				
				}
			}
		}
	}
	
	for(int i=0; i<R; ++i)
	{
		for(int j=0; j<C; ++j)
			putchar(tiles[i][j]);
		puts("");
	}

}

int main()
{
	//freopen("test.in", "r", stdin);
	
	int T; cin >> T;
	for(int test=1; test<=T; ++test)
	{
		printf("Case #%d:", test);
		solve();
	}
}
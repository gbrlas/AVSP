#include <cstdio>
#include <cstring>

using namespace std;

bool grid[2][105][105] = {0};
int r, x1, y1, x2, y2;

bool empty(bool g[][105]){
	for(int i = 1; i < 101; ++i)
		for(int j = 1; j < 101; ++j)
			if (g[i][j])
				return false;
	return true;
}

int main()
{
	//freopen("c.in","r",stdin);
		freopen("C-small-attempt0.in","r",stdin);freopen("C-small-attempt0.out","w",stdout);
	//	freopen("C-small-attempt1.in","r",stdin);freopen("C-small-attempt1.out","w",stdout);
	//	freopen("C-large.in","r",stdin);freopen("C-large.out","w",stdout);
	int testcase;
	scanf("%d",&testcase);
	for (int caseId=1;caseId<=testcase;caseId++)
	{
		memset(grid, false, sizeof(grid));
		scanf("%d", &r);

		for(int i = 0; i < r; ++i){
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			for(int x = x1; x <= x2; ++x)
				for(int y = y1; y<=y2; ++y)
					grid[0][x][y] = 1;
		}

		int ret = 0;

		for(int i = 0; ; ++i){
			int now = i &1;
			int next = (i+1) &1;
			if (empty(grid[now])){
				ret = i;
				break;
			}
			memset(grid[next], false, sizeof(grid[next]));
			for(int x = 1; x <=100; ++x)
				for(int y = 1; y <= 100; ++y){
					if (grid[now][x][y]){
						if (!grid[now][x-1][y] && !grid[now][x][y-1])
							grid[next][x][y] = false;
						else
							grid[next][x][y] = true;
					}else{
						if (grid[now][x-1][y] && grid[now][x][y-1])
							grid[next][x][y] = true;

					}
				}
		}

		printf("Case #%d: %d\n",caseId, ret);
	}
}
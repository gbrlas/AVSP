#include <iostream>
#include <algorithm>
using namespace std;

int ans[100][100], list[100][100], H, W, R;

int main()
{
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
	int t; scanf("%d", &t);
	for (int step=1; step<=t; step++)
	{
		int x, y;
		scanf("%d%d%d", &H, &W, &R);
		memset(list, 0, sizeof(list));
		for (int i=0; i<R; i++)
			scanf("%d%d", &x, &y), list[x-1][y-1]=1;
		memset(ans, 0, sizeof(ans));
		ans[0][0]=1;
		for (int i=0; i<H; i++)
			for (int j=0; j<W; j++) if (list[i][j]==0)
			{
				if (i-2>=0 && j-1>=0) ans[i][j]+=ans[i-2][j-1];
				if (i-1>=0 && j-2>=0) ans[i][j]+=ans[i-1][j-2];
				ans[i][j]%=10007;
			}
		printf("Case #%d: %d\n", step, ans[H-1][W-1]);
	}
	return 0;
}

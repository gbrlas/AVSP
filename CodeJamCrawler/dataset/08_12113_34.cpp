#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <complex>
#include <ext/hash_map>
#include <string>
#include <iostream>
#include <cassert>

using namespace std;
using namespace __gnu_cxx;

typedef complex<double> Point;

const int MAX_N = 100 + 10;

int W, H, f[2][2], s, t;
int g[MAX_N][MAX_N], q[MAX_N * MAX_N][2], front, rear;

int solve()
{
	q[0][0] = s; q[0][1] = t;
	memset(g, 0, sizeof(g)); g[s][t] = 1;
	front = -1; rear = 0;
	while (front++ < rear)
	{
		int x = q[front][0], y = q[front][1];
		for (int i = 0; i < 2; ++i)
		{
			int dx = x + f[i][0], dy = y + f[i][1];
			//printf("%d %d\n", dx, dy);
			if (dx >= 0 && dx < W && dy >= 0 && dy < H && g[dx][dy] == 0)
			{
				g[dx][dy] = 1;
				++rear;
				q[rear][0] =dx; q[rear][1] = dy;
			}
		}
	}
	return rear + 1;
}

int main()
{
	freopen("B0.in", "r", stdin);
	freopen("B0.out", "w", stdout);
	int cases;
	scanf("%d", &cases);
	for (int caseNo = 1; caseNo <= cases; ++caseNo)
	{
		scanf("%d %d", &W, &H);
		scanf("%d %d %d %d", &f[0][0], &f[0][1], &f[1][0], &f[1][1]);
		scanf("%d %d", &s, &t);
		printf("Case #%d: %d\n", caseNo, solve());
	}

	return 0;
}



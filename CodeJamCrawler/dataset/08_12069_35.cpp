#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <complex>
#include <set>
#include <map>

using namespace std;

int W, H, cnt;
bool v[101][101];
int f[101][101];
int GO[2][2] = {{2, 1}, {1, 2}};

int solve()
{
	memset(f, 0, sizeof(f));
	f[0][0] = 1;
	for (int i = 0; i < W; ++i)
		for (int j = 0; j < H; ++j)
			for (int k = 0; k < 2; ++k)
			{
				int i0 = i + GO[k][0], j0 = j + GO[k][1];
				if (i0 < W && j0 < H && !v[i0][j0])
					f[i0][j0] = (f[i0][j0] + f[i][j]) % 10007;
			}
	return f[W- 1][H - 1];
}

int main()
{
	int cases;
	scanf("%d", &cases);
	for (int caseNo = 0; caseNo < cases; ++caseNo)
	{
		scanf("%d %d %d", &W, &H, &cnt);
		memset(v, 0, sizeof(v));
		for (int i = 0, r, c; i < cnt; ++i)
		{
			scanf("%d %d", &r, &c);
			v[r - 1][c - 1] = true;
		}
		printf("Case #%d: %d\n", caseNo + 1, solve());
	}
	return 0;
}

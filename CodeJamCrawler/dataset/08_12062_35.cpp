#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <complex>
#include <set>
#include <map>

using namespace std;

const int MAX_N = 15;

int n, m, code[MAX_N], f[1 << MAX_N], g[1 << MAX_N];
char g0[MAX_N][MAX_N];
int way[1 << MAX_N], cnt[1 << MAX_N], wayCnt;

bool isValid(int val)
{
	for (int i = 0; i < m; ++i)
		if (((1 << i) & val) > 0 && ((1 << (i + 1)) & val) > 0)
			return false;
	return true;
}


int getCnt(int val)
{
	int ans = 0;
	for (int i = 0; i < m; ++i)
		if (((1 << i) & val) > 0)
			++ans;
	return ans;
}

int main()
{
	int cases;
	scanf("%d", &cases);
	for (int caseNo = 0; caseNo < cases; ++caseNo)
	{
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", g0[i]);
			code[i] = 0;
			for (int j = 0; j < m; ++j)
				if (g0[i][j] == 'x')
					code[i] |= 1 << j;
		}
		wayCnt = 0;
		for (int i = 0; i < (1 << m); ++i)
			if (isValid(i))
			{
				way[wayCnt] = i; cnt[wayCnt] = getCnt(i); ++wayCnt;
			}
		fill(f, f + (1 << m), -1);
		int ans = 0;
		for (int i = 0; i < wayCnt; ++i)
			if ((code[0] & way[i]) == 0)
			{
				f[way[i]] = cnt[i], ans >?= f[way[i]];
			//	printf("%d = %d\n", way[i], cnt[i]);
			}
		for (int i = 1; i < n; ++i)
		{
			fill(g, g + (1 << m), -1);
			for (int j = 0; j < (1 << m); ++j)
				if (f[j] != -1)
					for (int k = 0; k < wayCnt; ++k)
						if ((code[i] & way[k]) == 0 && (j & (way[k] / 2)) == 0 && (j & (way[k] * 2)) == 0)
						{
						//	printf("%d - %d (%d) ==> %d\n", j, way[k], cnt[k], f[j] + cnt[k]);
							g[way[k]] >?= f[j] + cnt[k];
						}
			for (int j = 0; j < (1 << m); ++j)
				f[j] = g[j], ans >?= f[j];
		}
		printf("Case #%d: %d\n", caseNo + 1, ans);
		//exit(0);
	}
	return 0;
}

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

const int MAX_N = 50, GO[9][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {0, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const double EPS = 1e-6;

int cases, caseNo, R, C;
int sum[MAX_N][MAX_N], id[MAX_N][MAX_N];

// R * C + 1 equations, R * C variables
const int MAX_VAR = MAX_N * MAX_N;
double f[MAX_VAR + 1][MAX_VAR], s[MAX_VAR];

bool hasSolution()
{
	int m = R * C + 1, n = R * C;
	for (int i = 0; i < n; ++i)
	{
		if (fabs(f[i][i]) < EPS)
		{
			bool found = false;
			for (int j = i + 1; j < m; ++j)
				if (f[j][i] != 0)
				{
					found = true;
					for (int k = 0; k < n; ++k)
						swap(f[i][k], f[j][k]);
					swap(s[i], s[j]);
					break;
				}
			if (!found) {
				continue;
				printf("Not found!\n"); exit(0);
			}
		}

		double ratio = 1.0 / f[i][i];
		for (int k = 0; k < n; ++k)
			f[i][k] *= ratio;
		s[i] *= ratio;
		assert(fabs(f[i][i] - 1) < EPS);

		for (int j = 0; j < m; ++j)
			if (i != j && fabs(f[j][i]) > EPS) // can be +/- 1
			{
				double ratio = f[j][i] / f[i][i];
				// f[j][i] -= ratio * f[i][i]
				for (int k = 0; k < n; ++k)
					f[j][k] -= ratio * f[i][k];
				s[j] -= ratio * s[i];
			}
	}
//	for (int i = 0; i < n; ++i)
//		printf("%.2lf ", f[R * C][i]);
//	printf(" = %.2lf\n", s[R * C]);
	for (int i = 0; i < n; ++i)
		if (fabs(f[R * C][i]) > EPS)
			return false;
	if (fabs(s[R * C]) > EPS)
		return false;
	return true;
}

int solve()
{
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			id[i][j] = i * C + j;
	for (int ans = C; ans >= 0; --ans)
	{
		for (int i = R * C; i >= 0; --i)
			fill(f[i], f[i] + R * C, 0.0);
		for (int i = 0; i < R; ++i)
			for (int j = 0; j < C; ++j)
			{
				for (int k = 0, dx, dy; k < 9; ++k)
				{
					dx = i + GO[k][0]; dy = j + GO[k][1];
					if (0 <= dx && dx < R && 0 <= dy && dy < C)
						f[id[i][j]][id[dx][dy]] = 1;
				}
				s[id[i][j]] = sum[i][j];
			}
		for (int i = 0; i < C; ++i) // middle row
			f[R * C][id[R / 2][i]] = 1.0;
		s[R * C] = ans;
		if (hasSolution())
			return ans;
	}
	return 0;
}

int main()
{
	freopen("C0.in", "r", stdin);
	freopen("C0.out", "w", stdout);
	scanf("%d", &cases);
	for (int caseNo = 1; caseNo <= cases; ++caseNo)
	{
		scanf("%d %d", &R, &C);
		for (int i = 0; i < R; ++i)
			for (int j = 0; j < C; ++j)
				scanf("%d", &sum[i][j]);
		printf("Case #%d: %d\n", caseNo, solve());
	}
	return 0;
}




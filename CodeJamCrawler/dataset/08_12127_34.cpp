#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

const int MAX_N = 50, GO[9][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {0, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const double EPS = 1e-6;

int cases, caseNo, R, C;
int sum[MAX_N][MAX_N], id[MAX_N][MAX_N];

// R * C + 1 equations, R * C variables
const int MAX_VAR = MAX_N * MAX_N;
double f[MAX_VAR + 1][MAX_VAR], s[MAX_VAR + 1], sRatio[MAX_VAR + 1];
double f0[MAX_VAR + 1][MAX_VAR], s0[MAX_VAR + 1];
bool var[MAX_VAR + 1];

bool searchSolution(int row)
{
	if (row == -1)
		return true;

	if (!var[row])
	{
		if (fabs(s0[row]) < EPS) // ignore this: is a 0
			return searchSolution(row - 1);
		else if (fabs(s0[row] - 1.0) < EPS) // is a 1
		{
			vector<int> resS;
			for (int i = row - 1; i >= 0; --i)
				if (fabs(f0[i][row]) > EPS)
				{
					resS.push_back(i);
					s0[i] -= f0[i][row]; // elminated all above
				}
			bool res = searchSolution(row - 1);
			for (vector<int>::iterator iter = resS.begin(); iter != resS.end(); ++iter)
				s0[*iter] += f0[*iter][row];
			resS.clear();
			return res;
		}
		else
			return false;
	}
	else if (fabs(s0[row]) > EPS) // 0...0 should == 0
	       return false;
	else
	{
		// set to 0
		if (searchSolution(row - 1))
			return true;

		// set to 1
		vector<int> resS;
		for (int i = row - 1; i >= 0; --i)
			if (fabs(f0[i][row]) > EPS)
			{
				resS.push_back(i); s0[i] -= f0[i][row];
			}
		bool res = searchSolution(row - 1);
		for (vector<int>::iterator iter = resS.begin(); iter != resS.end(); ++iter)
			s0[*iter] += f0[*iter][row];
		resS.clear();
		return res;
	}
}

bool hasSolution(double ans)
{
	int m = R * C + 1, n = R * C;

	// test last row
	for (int j = 0; j < n; ++j)
		if (fabs(f[m - 1][j]) > EPS)
			return false;
	if (fabs(s[m - 1] + sRatio[m - 1] * ans) > EPS)
		return false;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
			f0[i][j] = f[i][j];
		s0[i] = s[i] + sRatio[i] * ans;
	}

	for (int i = n - 1; i >= 0; --i)
	{
		if (fabs(f0[i][i]) < EPS)
		{
			var[i] = true;
			continue;
		}
		else
		{
			var[i] = false;
			for (int j = i - 1; j >= 0; --j)
				if (fabs(f0[j][i]) > EPS)
				{
					double ratio = f0[j][i] / f0[i][i];
					for (int k = 0; k < n; ++k)
						f0[j][k] -= f0[i][k] * ratio;
					s0[j] -= ratio * s0[i];
				}
		}
	}

/*	printf("ans = %.2lf\n", ans);
	for (int j = 0; j < m; ++j)
	{
		printf("[%d] ", var[j] ? 1 : 0);
		for (int i = 0; i < n; ++i)
			printf("%.1lf ", f0[j][i]);
		printf(" = %.1lf\n", s0[j]);
	}*/
	return true;
	cerr << "searching... " << ans << endl;
	return searchSolution(n - 1);
}

int solve()
{
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			id[i][j] = i * C + j;
	for (int i = R * C; i >= 0; --i)
	{
		sRatio[i] = (i == R * C) ? 1.0 : 0.0; // the ratio it contains s[R * C]
		fill(f[i], f[i] + R * C, 0.0);
	}
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
	s[R * C] = 0.0; // for id purpose only

	int m = R * C + 1, n = R * C;
	for (int i = 0; i < n; ++i)
	{
		if (fabs(f[i][i]) < EPS)
		{
			bool found = false;
			for (int j = i + 1; j < m; ++j)
				if (fabs(f[j][i]) > EPS)
				{
					found = true;
					for (int k = 0; k < n; ++k)
						swap(f[i][k], f[j][k]);
					swap(s[i], s[j]);
					swap(sRatio[i], sRatio[j]);
					break;
				}
			if (!found)
				continue;
		}

		double ratio = 1.0 / f[i][i];
		for (int k = 0; k < n; ++k)
			f[i][k] *= ratio;
		s[i] *= ratio;
		sRatio[i] *= ratio;
		assert(fabs(f[i][i] - 1) < EPS);

		for (int j = 0; j < m; ++j)
			if (i != j && fabs(f[j][i]) > EPS)
			{
				double ratio = f[j][i] / f[i][i];
				for (int k = 0; k < n; ++k)
					f[j][k] -= ratio * f[i][k];
				s[j] -= ratio * s[i];
				sRatio[j] -= ratio * sRatio[i];
			}
	}

	for (int ans = C; ans >= 1; --ans)
		if (hasSolution(ans))
			return ans;
	return 0;
}

int main()
{
	freopen("C1.in", "r", stdin);
	freopen("C1.out0", "w", stdout);
	scanf("%d", &cases);
	for (int caseNo = 1; caseNo <= cases; ++caseNo)
	{
		scanf("%d %d", &R, &C);
		for (int i = 0; i < R; ++i)
			for (int j = 0; j < C; ++j)
				scanf("%d", &sum[i][j]);
		//if (caseNo >= 13)
		{
		cerr << "Case " << caseNo << endl;
		int ans = solve();
		printf("Case #%d: %d\n", caseNo, ans);
		cerr << "searching+++ " << ans << endl;
		}
	}
	return 0;
}




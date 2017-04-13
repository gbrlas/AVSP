#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

typedef long long ll;
#pragma warning(disable:4996)
#define all(t) t.begin(),t.end()
#define REP(i, n) for(int i=0; i<(int)(n); ++i)
using namespace std;

double P[45][45];
long double turn[100000][45];

int n, m;
double C[45][45] = {0,};

double go()
{
	turn[0][0] = 1.0;
	double S = 0;
	for(int t=1; t<100000; ++t)
	{
		for(int i=0; i<=n; ++i) {
			turn[t][i] = 0;

			for(int j=0; j<=n; ++j)
			{
				turn[t][i] += turn[t-1][j] * C[j][i];
			}
		}
		S += turn[t][n] * t;
	}
	return S;
}

int main()
{
	freopen("C-small.in", "r", stdin);
	freopen("C-small.out", "w", stdout);
	int T;
	scanf("%d", &T);

	P[0][0] = 1;
	for(int i=1; i<=40; ++i)
	{
		P[i][0] = 1;
		for(int j=1; j<=i; ++j)
			P[i][j] = P[i-1][j-1] + P[i-1][j];
	}
	for(int tt=1; tt<=T; ++tt)
	{
		fprintf(stderr, "%d\n", tt);
		scanf("%d %d", &n, &m);
		memset(C, 0, sizeof(C));

		for(int i = 0; i <= n; ++i)
		{
			// i 개를 모은 경우
			for(int j=0; j<=m; ++j)
			{
				// i개 중 j개를 뽑고, 새로운 n-i개중 m-j 개를 뽑는다.
				double cnt = P[i][j] * P[n-i][m-j];

				int ii = i + m-j;
				if(ii > n) {
					continue;
				}

				if(i == n && ii == n);
				else
					C[i][ii] += cnt / P[n][m] ;
			}
		}

		printf("Case #%d: %.10lf\n", tt, go());
	}
	return 0;
}
#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include <map>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

int X[100], Y[100], R[100];
int d[3][2] = {{0, 1}, {0, 2}, {1, 2}};

double square(int a)
{
	return a * a;
}

double calc(int i, int j)
{
	int X1 = X[i], Y1 = Y[i], R1 = R[i];
	int X2 = X[j], Y2 = Y[j], R2 = R[j];
	double dis = sqrt(square(X2 - X1) + square(Y2 - Y1));
	return (dis + R1 + R2) / 2;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T;
	scanf("%d", &T);
	for(int tests = 1; tests <= T; ++tests)
	{
		int N;
		scanf("%d", &N);
		for(int i = 0; i < N; ++i)
			scanf("%d %d %d", &X[i], &Y[i], &R[i]);

		double res = 1000000;

		if(N == 1)
		{
			res = R[0];
		}
		else if(N == 2)
		{
			res = R[0] > R[1] ? R[0] : R[1];
		}
		else
		{
			for(int i = 0; i < 3; ++i)
			{
				int f = d[i][0], s = d[i][1];
				int t = 3 - f - s;
				double v = calc(f, s);
				double tres = v > R[t] ? v : R[t];
				res = min(res, tres);
			}
		}

		printf("Case #%d: %f\n", tests, res);
	}

	return 0;
}
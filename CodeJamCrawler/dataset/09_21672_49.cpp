#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <memory.h>
using namespace std;
#define sz(c) (int)c.size()
#define pb push_back
#define all(c) c.begin(), c.end()


void initialize()
{
    freopen("D1.in","r",stdin);
    freopen("output.txt","w",stdout);
}

const double INF = 1e100;

const int MAX = 10;
double x[MAX], y[MAX], r[MAX];

double sqr(double a)
{
	return a * a;
}

double pokr(int a, int b)
{
	double res = (sqrt(sqr(x[a] - x[b]) + sqr(y[a] - y[b])) + r[a] + r[b]) / 2.0;
	return res;
}

int other(int a, int b)
{
	if (a == 0 && b == 1) return 2;
	if (a == 0 && b == 2) return 1;
	if (a == 1 && b == 2) return 0;
}

int main()
{
    initialize();

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%lf%lf%lf", &x[i], &y[i], &r[i]);

		double res = -1;
		if (n == 1)
			res = r[0];
		if (n == 2)
		{
			double res1 = pokr(0, 1);
			double res2 = max(r[0], r[1]);
			res = min(res1, res2);
		}
		if (n == 3)
		{
			double res1 = INF;
			for (int i = 0; i < 3; ++i)
				for (int j = i + 1; j < 3; ++j)
					res1 = min(res1, max(pokr(i, j), r[other(i, j)]));
			res = res1;
		}
		printf("Case #%d: %.10lf\n", t, res);
	}

    return 0;
}
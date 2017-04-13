#include <bits/stdc++.h>

using namespace std;

const double INF = 1e9;

double Solve (double C, double F, double X)
{
	if (X <= C)
		return X / 2.0;
	double rate = 2.0, res = 0.0;
	while (X / rate >= C / rate + X / (rate + F))
	{
		res += C / rate;
		rate += F;
	}
	res += X / rate;
	return res;
}

int main ()
{
	int T;
	double C, F, X;
	scanf ("%d", &T);
	for (int testcases = 1; testcases <= T; testcases++)
	{
		printf ("Case #%d: ", testcases);
		scanf ("%lf %lf %lf", &C, &F, &X);
		double res = Solve (C, F, X);
		printf ("%.9lf\n", res);
	}
	return 0;
}

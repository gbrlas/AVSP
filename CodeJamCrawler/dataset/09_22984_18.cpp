#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

const char *inf = "D-small-attempt0.in";
const char *ouf = "output.txt";

using namespace std;

int n;
double x[100], y[100], r[100];

void init()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x[i] >> y[i] >> r[i];
	}
}

double min3(double x, double y, double z)
{
	if (y<x)
		x = y;
	if (z<x)
		x = z;
	return x;
}

double sqr(double x)
{
	return x * x;
}

double dis(int a, int b)
{
	return sqrt(sqr(x[a]-x[b])+sqr(y[a]-y[b]));
}

double cov(int a, int b)
{
	return (dis(a, b)+r[a]+r[b]) / 2;
}

double ans;
void process()
{
	if (n == 1)
		ans = r[0];
	else if (n == 2)
		ans = max(r[0], r[1]);
	else
		ans = min3(max(r[0], cov(1,2)),
					max(r[1], cov(0,2)),
					max(r[2], cov(0,1)));
}

void print()
{
	printf("%0.7lf", ans);
}

int main()
{
	freopen(inf, "rt", stdin);
	freopen(ouf, "wt", stdout);
	
	int tt;
	cin >> tt;
	for (int i = 0; i < tt; ++i)
	{
		printf("Case #%d: ", i+1);
		init();
		process();
		print();
		printf("\n");
	}
	return 0;
}

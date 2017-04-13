#include <cstdio>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#define all(t) t.begin(), t.end()
#define REP(i, n) for(int i=0; i<(int)(n); ++i)

int n, R;
int x[10], y[10], r[10];

double dist(pair<double, double> A, pair <double,double> B)
{
	return sqrt( (A.first - B.first)*(A.first - B.first) +
		(A.second - B.second)*(A.second - B.second) );
}

double get(int a, int b)
{
/*	vector< pair<double, double> > P;
	if(x[b] != x[a])
	{
		double m = (y[b] - y[a]) / (double)(x[b] - x[a]);
		double n = -x[a] * m + y[a];

		double A, B, C, D;
		double x1,y1,x2,y2;

		A = (1 + m*m);
		B = (-2 * x[a] + 2*m*(n - y[a]));
		C = x[a] * x[a] + (n - y[a]) * (n - y[a]) - r[a] * r[a];
		D = sqrt(B*B-4*A*C);
		x1 = (-B + D) / 2.0 / A;
		x2 = (-B - D) / 2.0 / A;
		y1 = m * x1 + n, y2 = m * x2 + n;
		P.push_back(make_pair(x1,y1));
		P.push_back(make_pair(x2,y2));

		A = (1 + m*m);
		B = (-2 * x[b] + 2*m*(n - y[b]));
		C = x[b] * x[b] + (n - y[b]) * (n - y[b]) - r[b] * r[b];
		D = sqrt(B*B-4*A*C);
		x1 = (-B + D) / 2.0 / A;
		x2 = (-B - D) / 2.0 / A;
		y1 = m * x1 + n, y2 = m * x2 + n;
		P.push_back(make_pair(x1,y1));
		P.push_back(make_pair(x2,y2));
	}
	else
	{
		P.push_back(make_pair((double)x[a], (double)y[a] + r[a]));
		P.push_back(make_pair((double)x[a], (double)y[a] - r[a]));
		P.push_back(make_pair((double)x[b], (double)y[b] + r[b]));
		P.push_back(make_pair((double)x[b], (double)y[b] - r[b]));
	}

	double maxdist = 0;

	for(int i=0; i<P.size(); ++i) for(int j=i+1; j<P.size(); ++j)
	{
		maxdist = max(maxdist, dist(P[i], P[j]));
	}*/
	return (dist( make_pair((double)x[a], (double)y[a]),
		make_pair((double)x[b], (double)y[b]) ) + r[a] + r[b]) / 2;
	//return maxdist / 2;
}

double go()
{
	double ret = 1.0e80;
	if(n == 1)
		ret = r[0];

	if(n == 2)
		ret = max(r[0], r[1]);

	for(int i=0; i<n; ++i) for(int j=i+1; j<n; ++j)
	{
		double R1 = get(i, j);
		double R2  = -1;
	
		for(int k=0; k<n; ++k)  {
			if(k!=i && k!=j)
			R2 = r[k];
		}
		
	//	printf("? %lf %lf\n", R1, R2);
		ret = min ( ret, max(R1, R2) );
	}
	return ret;
}

int main()
{
	freopen("d-small.in", "r", stdin);
	freopen("d-small.out", "w", stdout);
	
	int T; scanf("%d", &T);
	for(int tt=1; tt<=T; ++tt)
	{
		scanf("%d", &n);
		for(int i=0;i<n;++i)
			scanf("%d %d %d", x+i,y+i,r+i);
		printf("Case #%d: %.6lf\n", tt, go());
	}
	return 0;
}

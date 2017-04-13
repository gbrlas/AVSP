#pragma comment(linker, "/STACK:16777216")
#pragma warning (disable:4786)
#pragma warning (disable:4996)

#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define Abs(a) ((a)>0?(a):-(a))
#define Sqr(a) ((a)*(a))

#define EPS 1e-9
#define INF 1e9

using namespace std;

#ifdef _MSC_VER
	typedef __int64 LL;
#else
	typedef long long LL;
#endif

typedef vector <int> VI;
typedef vector <VI> VVI;

typedef double LD;
typedef vector <LD> VD;
typedef vector <VD> VVD;

typedef vector <string> VS;

const int MAX = 1600;

struct Point
{
	LD x, y, z;
};

Point p[MAX];
LD power[MAX];

int n;

void Read()
{
	scanf("%d", &n);
	for (int i=0;i<n;i++)
	{
		scanf("%lf %lf %lf %lf", &p[i].x, &p[i].y, &p[i].z, &power[i]);
	}
}

LD CalcPower(Point cen, int ind)
{
	return LD(Abs(p[ind].x-cen.x) + Abs(p[ind].y-cen.y) + Abs(p[ind].z-cen.z))/LD(power[ind]);
}

bool Satis(LD R)
{
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++)
		{
			Point cen;
			LD sum = power[i]+power[j];
			cen.x = (power[j]*p[i].x+power[i]*p[j].x)/sum;
			cen.y = (power[j]*p[i].y+power[i]*p[j].y)/sum;
			cen.z = (power[j]*p[i].z+power[i]*p[j].z)/sum;

			if ( CalcPower(cen, i)>R || CalcPower(cen, j)>R ) return false;
		}

	return true;
}

void Solve()
{
	//bool tr = Satis(2.4);

	LD l = 0, r = INF;
	while ( fabs(l-r)>EPS )
	{
		LD cen = (l+r)/2.0;
		if ( Satis(cen) ) r = cen;
		else l = cen;
	}

	printf("%.8lf\n", l);
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int ntest;
	scanf("%d", &ntest);
	for (int t=0;t<ntest;t++)
	{
		printf("Case #%d: ", t+1);
		Read();
		Solve();
	}

	return 0;
}

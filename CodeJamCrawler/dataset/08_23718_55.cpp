#include <iostream>

using namespace std;
#define eps 0.000001

long T;
double f, R, t, r, g;

long double F(long double X, long double Y, long double r, long double R)
{
	if (r < eps) return 2*r*r;
	if ((X+r)*(X+r)+(Y+r)*(Y+r) <= R*R &&
		(X-r)*(X-r)+(Y+r)*(Y+r) <= R*R &&
		(X+r)*(X+r)+(Y-r)*(Y-r) <= R*R &&
		(X-r)*(X-r)+(Y-r)*(Y-r) <= R*R) return 4*r*r;
	if ((X+r)*(X+r)+(Y+r)*(Y+r) >= R*R &&
		(X-r)*(X-r)+(Y+r)*(Y+r) >= R*R &&
		(X+r)*(X+r)+(Y-r)*(Y-r) >= R*R &&
		(X-r)*(X-r)+(Y-r)*(Y-r) >= R*R) return 0;
	return	F(X-r/2, Y-r/2, r/2, R)+
			F(X-r/2, Y+r/2, r/2, R)+
			F(X+r/2, Y+r/2, r/2, R)+
			F(X+r/2, Y-r/2, r/2, R);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d", &T);
	for (long a = 0; a < T; a ++)
	{
		scanf("%lf %lf %lf %lf %lf", &f, &R, &t, &r, &g);
		f/=R; t/=R; r/=R; g/=R;
		double x = max(g - 2*f, 0.);
		double l = 2*r + g;
		double rr = max(1-t-f, 0.);
		long double S = 0.;
		long m = (long)(rr/l)+1;

		long c = 0, d = m+1;
		while (d >= 0)
		{
			S += F((0.5+c)*l, (0.5+d)*l, x/2, rr);
			if (F((0.5+c+1.)*l, (0.5+d)*l, x/2, rr) < eps)
				d --;
			else
			{
				S += x*x*d;
				c ++;
			}
		}

		printf("Case #%d: %0.6lf\n", a+1, max(1.-S/(3.1415926535897932384626433832795*0.25), 0.));
	}

	return 0;
}
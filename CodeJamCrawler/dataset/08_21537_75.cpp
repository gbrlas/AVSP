#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < vi > vii;

#define REP(i, n)	for( int i = 0; i < (n); ++i )
#define INIT(a)		memset(a, 0, sizeof(a))
#define ALL(a)		a.begin(), a.end()
#define ABS(a)		((a) < 0 ? ((a) * (-1)) : (a))
#define SQR(a)		((a) * (a))

const double PI = 2 * acos(0.0);

double get_area(double r, double h, double theta1, double theta2)
{
	return -SQR(r) / 2 * (theta2 - sin(2 * theta2) / 2 - theta1 + sin(2 * theta1) / 2)
		+ h * r * (-cos(theta2) + cos(theta1));
}

int main()
{
	int tc;
	double f, R, t, r, g;

	freopen("C-large.in", "r", stdin);
	freopen("C-large-out.txt", "w", stdout);
	scanf("%d", &tc);
	REP(tci, tc)
	{
		scanf("%lf %lf %lf %lf %lf", &f, &R, &t, &r, &g);
		double a = PI * SQR(R);
		if ( g > 2 * f )
		{
			for( double x = r + f; x <= R - t - f; x += g + r + r )
			{
				for( double y = r + f; SQR(x) + SQR(y) <= SQR(R - t - f); y += g + r + r )
				{
					double x2 = x + (g - f - f), y2 = y + (g - f - f);
					if ( SQR(x2) + SQR(y2) <= SQR(R - t - f) )
					{
						a -= 4 * SQR(g - f - f);
					}
					else
					{
						double xx1 = x, xx2 = sqrt(SQR(R - t - f) - SQR(y));
						if ( R - t - f > y2 )
						{
							xx1 = sqrt(SQR(R - t - f) - SQR(y2));
							if ( xx1 < x )
								xx1 = x;
						}
						if ( xx2 > x2 )
							xx2 = x2;
						a -= 4 * (xx1 - x) * (g - f - f);
						a -= 4 * get_area(R - t - f, y, acos(xx1 / (R - t - f)), acos(xx2 / (R - t - f)));
					}
				}
			}
		}
		a /= PI * SQR(R);
		printf("Case #%d: %.6lf\n", tci + 1, a);
	}
}

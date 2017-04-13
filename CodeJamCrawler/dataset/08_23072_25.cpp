#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

#define MAXI(a,b) ((a)>(b)?(a):(b))
#define MINI(a,b) ((a)<(b)?(a):(b))
#define DIST(a,b) (sqrt(((a)*(a))+((b)*(b))))
#define EPS 0.00001

int m, n, a;

double x, y, z, w;
int resp;

int vai(int prof)
{
	double l1, l2, l3, p;
	double t;

	if (prof == 2)
	{
		//printf("%d %d %d %d\n", (int)x, (int)y, (int)z,(int) w);
		l1 = DIST(x, y);
		l2 = DIST(z, w);
		l3 = DIST(x-z, y-w);

//		printf("%lf %lf %lf\n", l1, l2, l3);

		p = l1 + l2 + l3;
		p = p/2.0;

		t = p*(p-l1)*(p-l2)*(p-l3);
		t = sqrt(t);

//		printf("%lf %lf-----------	\n", p, t);

		if (fabs(2*t-a) < EPS)
		{

			resp = 1;
			return 1;
		}

		return 0;
	}

	int i, j;

	for (i=0; i<=m; i++)
	{
		for (j=0; j<=n; j++)
		{
			if (prof == 0)
			{
				x = i;
				y = j;
			}
			else
			{
				z = i;
				w = j;
			}
			if (vai(prof+1))
				return 1;
		}
	}
	return 0;
}


int main()
{
	int casos, cas;

	scanf("%d",&casos);

	for (cas = 1; cas <= casos; cas++)
	{
		scanf("%d %d %d", &m, &n, &a);

		printf("Case #%d: ", cas);

		resp = 0;
		vai(0);

		if (!resp)
		{
			printf("IMPOSSIBLE\n");
		}
		else
		{
			printf("%d %d %d %d %d %d\n", 0, 0, (int)x, (int)y, (int)z, (int)w);
		}
	}

	return 0;
}

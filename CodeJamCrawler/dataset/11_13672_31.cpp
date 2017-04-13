#include <stdio.h>
#include <algorithm>
using namespace std;

struct node {
	int l;
	int v;
	double t;
};

node a[3005];

bool cmp(const node & a, const node & b)
{
	return a.v < b.v ;
}

int main ()
{
	//freopen("A-small-attempt5.in","r",stdin);
	//freopen("a.out","w",stdout);
	int ca;
	scanf("%d", &ca);
	for (int cas = 1; cas <= ca; cas++)
	{
		int x, s, r, t, m;
		scanf("%d%d%d%d%d", &x, &s, &r, &t, &m);
		if (m == 0)
		{
			printf("Case #%d: %.6lf", cas ,x * 1.0 / s);
			continue;
		}
		double length=0;
		for (int i = 0; i < m; i++)
		{
			int l, r, v;
			scanf("%d%d%d", &l, &r, &v);
			length += r - l;
			a[i].l = r - l;
			a[i].v = s + v;
			a[i].t = a[i].l * 1.0 /a[i].v;
		}
		a[m].l = x - length;
		a[m].v = s;
		a[m].t = a[m].l * 1.0 / a[m].v;
		m++;
		sort(a, a + m, cmp);
		double res = 0;
		double time = t;
		for (int i = 0; i < m; i++)
		{
			if (time > 0)
			{
				double tt = a[i].l * 1.0 / (a[i].v + r - s);
				if (tt <= time)
				{
					res += tt;
					time -= tt;
				}
				else
				{
					res += time + (a[i].l - time * (a[i].v + r - s)) * 1.0 / a[i].v;
					time = 0;
				}
			}
			else
			{
				res += a[i].t;
			}
		}
		printf("Case #%d: %.6lf\n", cas, res);

	}
	return 0;
}


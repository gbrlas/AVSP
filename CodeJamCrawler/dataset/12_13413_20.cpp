#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 111
#define sqr(x) ((x) * (x))

const int kx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int ky[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

struct circle
{
	double x, y, r;
	int id;
};

circle f[MAXN];
int n, w, l;
bool found;

bool cmp(circle p, circle q)
{
	return p.r > q.r;
}

bool cmp2(circle p, circle q)
{
	return p.id < q.id;
}

double cal(circle p, circle q)
{
	return sqrt(sqr(p.x - q.x) + sqr(p.y - q.y));
}

void dfs(int k)
{
	if (k >= n)
	{
		found = true;
		return;
	}
	for (int i = 0; i < k; ++i)
	{
		for (int dir = 0; dir < 8; ++dir)
		{
			double tmpx = f[i].x + kx[dir] * (f[k].r + f[i].r);
			double tmpy = f[i].y + ky[dir] * (f[k].r + f[i].r);
			if (tmpx >= 0 && tmpx <= w && tmpy >= 0 && tmpy <= l)
			{
				f[k].x = tmpx;
				f[k].y = tmpy;
				bool con = true;
				for (int j = 0; j < k; ++j)
				{
					double dis = cal(f[k], f[j]);
					if (dis < f[k].r + f[j].r)
					{
						con = false;
						break;
					}
				}
				
				if (con) dfs(k + 1);
				if (found)
					return;
			}
		}
	}
}

void work()
{
	if (n >= 1)
		f[0].x = 0, f[0].y = 0;
	if (n >= 2)
		f[1].x = w, f[1].y = l;
	if (n >= 3)
	{
		found = false;
		dfs(2);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, cases = 0;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &n, &w, &l);
		for (int i = 0; i < n; ++i)
		{
			scanf("%lf", &f[i].r);
			f[i].id = i;
		}
		sort(f, f + n, cmp);
		work();
		sort(f, f + n, cmp2);
		//printf("Case #%d:\n", ++cases);
		printf("Case #%d:", ++cases);
		for (int i = 0; i < n; ++i)
			printf(" %.2lf %.2lf", f[i].x, f[i].y);
		puts("");
	}
	return 0;
}
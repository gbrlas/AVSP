#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int c, d;
struct node
{
	int p, v;
};
vector<node> pos;
bool cmp(const node &a, const node &b)
{
	return a.p < b.p;
}

bool check(double t)
{
	double left_most;
	for (int i = 0; i < pos.size(); i++)
	{
		for (int j = 0; j < pos[i].v; j++)
		{
			if (i == 0 && j == 0)
			{
				left_most = pos[i].p - t;
				continue;
			}
			double p1 = left_most + d;
			if (fabs(pos[i].p - p1) <= t)
			{
				left_most = p1;
				continue;
			}
			if (pos[i].p >= p1)
			{
				left_most = pos[i].p - t;
				continue;
			}
			if (p1 > pos[i].p)
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	freopen("B-small-attempt0.in", "r+", stdin);
	freopen("B-small-attempt0.out", "w+", stdout);
	int t, tt = 0;
	scanf("%d", &t);
	while (t--)
	{
		int sum = 0;
		pos.clear();
		scanf("%d %d", &c, &d);
		for (int i = 0; i < c; i++)
		{
			node s;
			scanf("%d %d", &s.p, &s.v);
			pos.push_back(s);
		}
		sort (pos.begin(), pos.end(), cmp);
		double low = 0, high = 1e8;
		double ans = 0;
		while (high - low >= 1e-7)
		{
			double mid = (low + high) / 2;
			if (check(mid) == true)
			{
				high = mid;
				ans = mid;
			}
			else
			{
				low = mid + 1e-7;
			}
		}
		printf("Case #%d: %lf\n", ++tt, ans);
	}
	return 0;
}
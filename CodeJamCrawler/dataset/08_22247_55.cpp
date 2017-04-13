#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>

using namespace std;

char buf[1000000];
bool have;
int xx1, yy1, xx2, yy2;
int n, m, v;

void init()
{
	scanf("%d%d%d\n", &n, &m, &v);
	have = false;
}

int gcd;
bool solve(int w1, int w2, int &xx1, int &xx2, int v)
{
	if (w2==0)
	{
		if (v%w1!=0)
			return false;
		gcd = w1;
		xx1 = v / w1;
		xx2 = 0;
		return true;
	}
	int tmp;
	if (solve(w2, w1%w2, tmp, xx1, v))
	{
		xx2 = tmp - w1/w2*xx1;
		return true;
/*		w1*xx1+w2*xx2=v
		w2*(w1/w2*xx1+xx2)+w1%w2*xx1=v
		w2*xx2+(w1%w2)*tmp=v*/
	}
	return false;
}

void process()
{
	for (int i = 1; i <= n; ++i)
		if (v%i==0 && v/i<=m)
		{
			have = true;
			xx1 = i; yy1 = 0;
			xx2 = 0; yy2 = v/i;
			return ;
		}
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j)
			if (i+j)
			{
				xx1 = j;
				xx2 = i;
				if (!solve(xx1, xx2, yy2, yy1, v))
					continue;
				yy1 = -yy1;
				int l1 = 0, l2 = 0;
				if (yy2<0)
					l2 = (-yy2 - 1) / (xx2/gcd) + 1;
				if (yy1<0)
					l1 = (-yy1 - 1) / (xx1/gcd) + 1;
				l1 = max(l1, l2);
				yy2 += xx2/gcd * l1;
				yy1 += xx1/gcd * l1;
				l1 = 0; l2 = 0;
				if (yy1>m)
					l1 = (yy1-m-1) / (xx1/gcd) + 1;
				if (yy2>m)
					l2 = (yy2-m-1) / (xx2/gcd) + 1;
				l1 = max(l1, l2);
				yy1 -= xx1/gcd * l1;
				yy2 -= xx2/gcd * l1;
				if (yy1>=0 && yy1<=m && yy2>=0 && yy2<=m)
				{
					have = true;
					return ;
				}
			}
}

void print()
{
	static int id = 0;
	++id;
/*
	if (!have)
		printf("-1 -1 -1 -1\n");
	else
		printf("%d %d %d %d\n", xx1, yy1, xx2, yy2);
*/
	if (!have)
		printf("Case #%d: IMPOSSIBLE\n", id);
	else
		printf("Case #%d: %d %d %d %d %d %d\n", id, 0, 0, xx1, yy1, xx2, yy2);
}

int main()
{
	freopen("b.txt", "rt", stdin);
	freopen("b_out.txt", "wt", stdout);
	int tt;
	scanf("%d", &tt);
	for (int i = 0; i < tt; ++i)
	{
		init();
		process();
		print();
	}
}

#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int NMAX = 110;
int cas, na, nb, t;
int ansa, ansb;
struct TIME
{
	int h, m;
	char from;
	bool isdest;

	TIME(int _h = 0, int _m = 0, char _f = 'A', bool _d = 0)
		: h(_h), m(_m), from(_f), isdest(_d) {}
	friend bool operator < (const TIME & t, const TIME & tt);
	bool operator == (const TIME & tt) const
	{
		return (h == tt.h) && (m == tt.m);
	}
	void add_time(int t)
	{
		m += t;
		if (m >= 60)
		{
			m %= 60;
			h ++;
		}
	}
};
TIME sch[1000];
int total;

bool cmp (const TIME & t, const TIME & tt)
{
	if (t.h != tt.h)
		return t.h < tt.h;
	if (t.m != tt.m)
		return t.m < tt.m;
	int bt = t.isdest ? 1 : 0;
	int btt = tt.isdest ? 1 : 0;
	return bt > btt;
}

bool leq(const TIME & t, const TIME & tt)
{
	if (t.h != tt.h)
		return t.h < tt.h;
	return t.m <= tt.m;
}

bool operator < (const TIME & t, const TIME & tt)
{
	return ! leq(t, tt);
}



bool is_have(priority_queue <TIME> & pq, TIME now)
{
	if (pq.empty())
		return false;
	TIME ready = pq.top();
	//ready.h = now.h = 10;
	//ready.m = now.m = 11;
	if ( leq(ready, now) )
	{
		pq.pop();
		return true;
	}
	return false;
}

void solve()
{
	int i, j;

	ansa = ansb = 0;
	sort(sch, sch+total, cmp);
	
	priority_queue <TIME> pqa;
	priority_queue <TIME> pqb;

	for (i=0; i<total; i++)
	{
		if (sch[i].from == 'A')
		{
			if (sch[i].isdest)
			{
				TIME wait = sch[i];
				wait.add_time(t);
				pqb.push(wait);
			}
			else
			{
				if (! is_have(pqa, sch[i]))
					ansa ++;
			}
		}
		else
		{
			if (sch[i].isdest)
			{
				TIME wait = sch[i];
				wait.add_time(t);
				pqa.push(wait);
			}
			else
			{
				if (! is_have(pqb, sch[i]))
					ansb ++;
			}
		}
	}
}

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	int i, j;

	scanf("%d", &cas);
	for (i=1; i<=cas; i++)
	{
		scanf("%d %d %d", &t, &na, &nb);
		total = 0;
		for (j=0; j<na; j++)
		{
			int h, m;
			scanf("%d:%d", &h, &m);
			sch[total ++] = TIME(h, m, 'A', false);
			scanf("%d:%d", &h, &m);
			sch[total ++] = TIME(h, m, 'A', true);
		}
		for (j=0; j<nb; j++)
		{
			int h, m;
			scanf("%d:%d", &h, &m);
			sch[total ++] = TIME(h, m, 'B', false);
			scanf("%d:%d", &h, &m);
			sch[total ++] = TIME(h, m, 'B', true);
		}
		solve();
		printf("Case #%d: %d %d\n", i, ansa, ansb);
	}
}
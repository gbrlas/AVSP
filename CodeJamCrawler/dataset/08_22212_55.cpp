#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

int ns[2], lft[2], nd[2];
int t;
int tt;
pair<int, int> ts[10000];
int ans1, ans2;

void init()
{
	scanf("%d%d %d\n", &t, &ns[0], &ns[1]);
	tt = 0;
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < ns[i]; ++j)
		{
			char c1, c2, c3, c4, c5, c6, c7, c8;
			scanf("%c%c:%c%c %c%c:%c%c\n", &c1, &c2, &c3, &c4, &c5, &c6, &c7, &c8);
			int st = ((c1-'0')*10+(c2-'0'))*60+(c3-'0')*10+(c4-'0'),
				en = ((c5-'0')*10+(c6-'0'))*60+(c7-'0')*10+(c8-'0');
			en += t;
			ts[tt++] = make_pair(st, i+1);
			ts[tt++] = make_pair(en, -(3-i-1));
		}
	}
}

void process()
{
	sort(ts, ts+tt);
	nd[0] = nd[1] = 0;
	lft[0] = lft[1] = 0;
	for (int i = 0; i < tt; ++i)
	{
		if (ts[i].second<0)
			++lft[-ts[i].second-1];
		else
		{
			if (--lft[ts[i].second-1] < 0)
			{
				lft[ts[i].second-1] = 0;
				++nd[ts[i].second-1];
			}
		}
	}
	ans1 = nd[0];
	ans2 = nd[1];
}

void print()
{
	static int id = 0;
	++id;
	printf("Case #%d: %d %d\n", id, ans1, ans2);
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

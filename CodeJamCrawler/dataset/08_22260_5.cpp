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
int ans;
int pr[100000001];
int tt[100000001];

const int mm = 100000001;
const int modx = 10007;
int w, h, tb;
int p[100][2];

void prepare()
{
	memset(tt, 0, sizeof(tt));
	memset(pr, 0, sizeof(pr));
	pr[0] = 0;
	pr[1] = 1;
	for (int i = 2; i < mm; ++i)
	{
		if (pr[i]==0)
		{
			pr[i] = i;
			for (int j = 2; i * j < mm; ++j)
			{
				pr[i*j] = i;
			}
		}
	} 
}

void init()
{
	cin >> w >> h >> tb;
	for (int i = 0; i < tb; ++i)
	{
		cin >> p[i][0] >> p[i][1];
	}
	for (int i = 0; i < tb; ++i)
		for (int j = i + 1; j < tb; ++j)
		{
			if (p[i][0]>p[j][0] || p[i][0]==p[j][0]&&p[i][1]>p[j][1])
			{
				swap(p[i][0], p[j][0]);
				swap(p[i][1], p[j][1]);
			}
		}
}

int getc(int a, int b)
{
	for (int i = b; i > 1; --i)
		for (int x = i; x > 1; x /= pr[x])
			--tt[pr[x]];
	int ret = 1;
	for (int i = a - b + 1; i <= a; ++i)
	{
		for (int x = i; x > 1; x /= pr[x])
			if (tt[pr[x]]==0)
				ret = (ret * pr[x]) % modx;
			else
				++tt[pr[x]];
	}
	return ret;
}

int getv(int w, int h)
{
	if (w<0 || h<0)
		return 0;
	if (w==0 && h==0)
		return 1;
	if (w<h)
		return getv(h, w);
	int t = w - h;
	int r = h - t;
	if (r<0)
		return 0;
	if (r%3!=0)
		return 0;
	int c = r / 3;
	int ret = getc(c+c+t, c);
	return ret;
}

bool mark[100];

int getcur()
{
	int lastx = 1, lasty = 1;
	int ret = 1;
	for (int i = 0; i < tb; ++i)
	{
		if (mark[i])
		{
			ret = ret * getv(p[i][0]-lastx, p[i][1]-lasty) % modx;
			lastx = p[i][0], lasty = p[i][1];
		}
	}
	ret = ret * getv(w-lastx, h-lasty) % modx;
	return ret;
}

void process()
{
	ans = 0;
	int mx = 1 << tb;
	for (int i = 0; i < mx; ++i)
	{
		int x = i;
		int f = 1;
		for (int j = 0; j < tb; ++j)
		{
			mark[j] = (x&1);
			if (mark[j])
				f = -f;
			x >>= 1;
		}
		ans = ans + f * getcur();
	}
	ans = ans % modx;
	while (ans < 0)
		ans += modx;
}

void print()
{
	static int id = 0;
	++id;
	printf("Case #%d: %d\n", id, ans);
}

int main()
{
	prepare();
	freopen("d.txt", "rt", stdin);
	freopen("d_out.txt", "wt", stdout);
	int tt;
	cin >> tt;
	for (int i = 0; i < tt; ++i)
	{
		init();
		process();
		print();
	}
}

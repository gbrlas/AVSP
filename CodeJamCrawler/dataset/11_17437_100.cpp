#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define pub(x) push_back(x)
#define x first
#define y second
#define MP make_pair
typedef long long ll;

vector<int> a, b;
vector<bool> v;

int main()
{
	freopen("a1.in","r",stdin);
	freopen("a1.txt","w",stdout);
	int task; scanf("%d", &task);
	for (int cas = 1; cas <= task; ++cas)
	{
		printf("Case #%d: ", cas);
		int m; scanf("%d", &m);
		int ans = 0;
		char s[100];
		a.clear();
		b.clear();
		v.clear();
		for (int i = 0; i < m; ++i)
		{
			int x; scanf("%s%d", s, &x);
			if (s[0]=='B') a.pub(x);
				else b.pub(x);
			v.pub(s[0] == 'B');
		}
		int p = 0, q = 0, x = 1, y = 1;
		int aWait = 0, bWait = 0;
		for (int i = 0; i < m ; ++i)
		{
			if (v[i])
			{
				int time = abs(a[p] - x);
				x = a[p++];
				if (time <= aWait)
					time = 1; else
					time = time - aWait + 1;
				ans += time;
				bWait += time;
				aWait = 0;
			} else
			{
				int time = abs(b[q] - y);
				y = b[q++];
				if (time <= bWait)
					time = 1; else
					time = time - bWait + 1;
				ans += time;
				aWait += time;
				bWait = 0;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}


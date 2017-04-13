#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <queue>

using namespace std;

#define FOR(i, a, b) for (int i(a), _b(b); i <= _b; ++i)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define REP(i, n) for (int i(0), _n(n); i < _n; ++i)
#define REPD(i, n) for (int i((n)-1); i >= 0; --i)

typedef long long int64;

template<typename T> T abs(T x) { return x < 0 ? -x : x; }
template<typename T> T sqr(T x) { return x*x; }
template<typename T> void remin(T& a, const T& b) { if (b < a) a = b; }
template<typename T> void remax(T& a, const T& b) { if (b > a) a = b; }

void solve()
{
	int ans=0, n, posb=1,poso=1;
	char tmp;
	queue <int> b, o;
	queue <pair <char , int> > q;

	scanf("%d", &n);
	REP(i,n)
	{
		int v;
		scanf(" %c %d", &tmp, &v);
		if (tmp == 'O')
		{
			o.push(v);
		}
		else if (tmp == 'B')
		{
			b.push(v);
		}
		q.push(make_pair(tmp, v));
	}

	while ( ! q.empty())
	{
//		cout << q.front().first << " " << q.front().second << " " << poso << " " << posb << " \n";
		pair <char, int> cur = q.front();
		bool flo = true, flb = true;

		if (cur.first == 'O')
		{
			if (poso == cur.second)
			{
				q.pop();
				o.pop();
				flo = false;
			}
		}
		else
		{
			if (posb == cur.second)
			{
				q.pop();
				b.pop();
				flb = false;
			}
		}

		if (poso != o.front() && flo && ! o.empty())
			if (o.front() - poso > 0)
				++poso;
			else
				--poso;

		if (posb != b.front() && flb && ! b.empty())
			if (b.front() - posb > 0)
				++posb;
			else
				--posb;

		++ans;
	}

	printf("%d", ans);
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int T;
	scanf("%d\n", &T);
	FOR(i, 1, T)
	{
		printf("Case #%d: ", i);
		solve();
		printf("\n");
	}

	return 1;
}

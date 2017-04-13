#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <vector>

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
	vector <char> ret;
	char str[128];
	char combine[128][3];
	char opposed[128][2];
	int c, d, n;

	scanf("%d", &c);
	REP(i, c)
		scanf("%3s", combine[i]);

	scanf("%d", &d);
		REP(i, d)
			scanf("%2s", opposed[i]);

	scanf("%d", &n);
	scanf("%s", str);

	REP(i, n)
	{
		ret.push_back(str[i]);
		int size = ret.size();
		if (size < 2)
			continue;

		// combine
		bool is_combine = false;
		REP(j, c)
			if ((combine[j][0] == ret[size-2] && combine[j][1] == ret[size-1])
			|| (combine[j][1] == ret[size-2] && combine[j][0] == ret[size-1]))
			{
				ret[size-2] = combine[j][2];
				ret.pop_back();
				is_combine = true;
				break;
			}

		if (is_combine)
			continue;

		// opposed
		bool is_opposed = false;
		REPD(j, size-1)
		{
			REP(k, d)
				if ((opposed[k][0] == ret[j] && opposed[k][1] == ret[size-1])
				|| (opposed[k][1] == ret[j] && opposed[k][0] == ret[size-1]))
				{
					ret.clear();
					is_opposed = true;
					break;
				}
			if (is_opposed)
				break;
		}
	}

	bool fl = true;
	cout << "[";
	REP(i, ret.size())
		if (fl)
		{
			fl = false;
			cout << ret[i];
		}
		else
		cout << ", " << ret[i];
	cout << "]";
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

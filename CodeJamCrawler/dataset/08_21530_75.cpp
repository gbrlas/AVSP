#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < vi > vii;

#define REP(i, n)	for( int i = 0; i < (n); ++i )
#define INIT(a)		memset(a, 0, sizeof(a))
#define ALL(a)		a.begin(), a.end()
#define ABS(a)		((a) < 0 ? ((a) * (-1)) : (a))

struct trip
{
	int dt, at, type;

	bool operator < ( const trip &t ) const
	{
		return dt < t.dt;
	}
};

struct arrival
{
	int at, station;

	bool operator < ( const arrival &a ) const
	{
		return at > a.at;
	}
};

int main()
{
	int tc, t, na, nb;

	freopen("B-small.in", "r", stdin);
	freopen("B-small-out.txt", "w", stdout);
	scanf("%d", &tc);
	REP(tci, tc)
	{
		vector < trip > trips;
		priority_queue < arrival > arrivals;
		int ta[2], cnt[2];
		INIT(ta);
		INIT(cnt);

		scanf("%d", &t);
		scanf("%d %d", &na, &nb);
		REP(i, na)
		{
			int dth, dtm, ath, atm;
			trip tr;

			scanf("%d:%d %d:%d", &dth, &dtm, &ath, &atm);
			tr.dt = dth * 60 + dtm;
			tr.at = ath * 60 + atm + t;
			tr.type = 0;
			trips.push_back(tr);
		}
		REP(i, nb)
		{
			int dth, dtm, ath, atm;
			trip tr;

			scanf("%d:%d %d:%d", &dth, &dtm, &ath, &atm);
			tr.dt = dth * 60 + dtm;
			tr.at = ath * 60 + atm + t;
			tr.type = 1;
			trips.push_back(tr);
		}
		sort( ALL(trips) );
		REP(i, trips.size())
		{
			while( !arrivals.empty() && arrivals.top().at <= trips[i].dt )
			{
				++ta[arrivals.top().station];
				arrivals.pop();
			}
			if ( ta[trips[i].type] == 0 )
			{
				++cnt[trips[i].type];
			}
			else
			{
				--ta[trips[i].type];
			}
			arrival a;
			a.at = trips[i].at;
			a.station = 1 - trips[i].type;
			arrivals.push(a);
		}
		printf("Case #%d: %d %d\n", tci + 1, cnt[0], cnt[1]);
	}
}

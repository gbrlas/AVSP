#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <list>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

typedef long long int64;
const int inf = (int)1e9;

inline int64 val(int o, int e)
{
	return (int64)(e - o) * (e - o - 1) / 2;
}

int main()
{
	int testcase;

	scanf("%d", &testcase);

	for(int casenum = 1; casenum <= testcase; ++casenum) {

		int64 ans = 0;
		int64 best = 0, base = 0;
		priority_queue<pair<int, int> > q;
		vector<pair<int, int> > order;

		int n, m;

		scanf("%d%d", &n, &m);
		for(int i = 0; i < m; ++i) {
			int o, e, p;
			scanf("%d%d%d", &o, &e, &p);
			base += val(o, e) * p;
			order.push_back(make_pair(e, p));
			order.push_back(make_pair(o, -p));
		}

		sort(order.begin(), order.end());

		for(int i = 0; i < m * 2; ++i) {

			int pos = order[i].first;
			int count = order[i].second;

			//printf("[debug] pos: %d, count: %d\n", pos, count);

			if(count < 0) {

				q.push(make_pair(pos, -count));

			} else {

				while(count > 0) {

					int ridepos = q.top().first;
					int ridecount = q.top().second;
					q.pop();

					int64 outcount = min(ridecount, count);
					int64 score = val(ridepos, pos) * outcount;

					count -= outcount;
					ridecount -= outcount;
					best += score;

					if(ridecount > 0)
						q.push(make_pair(ridepos, ridecount));
				}
			}
		}


		ans = best - base;
		printf("Case #%d: %lld\n", casenum, ans);

	}

	return 0;
}

/* ハラスメントに負けず */
/* 0完太陽にも負けず */
/* はやく人権を獲得したい */

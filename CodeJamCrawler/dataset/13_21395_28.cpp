#include <iostream>
#include <queue>
#include <utility>
#include <map>
#include <cassert>
using namespace std;
#define MAX_N 1000000000
#define MAX_M 1000
#define MOD 1000002013
#define COST(s,f,p) (((f)-(s))*(2*n-((f)-(s)-1))*p/2)
#define ERR(x) //cerr << x << endl
int main() {
	int t;
	cin >> t;
	for (int c=1; c <= t; c++) {
		int n, m;
		cin >> n >> m;
		assert(2 <= n && n <= MAX_N);
		assert(1 <= m && m <= MAX_M);
		map<int, int> delta;
		int expectedcost=0;
		for (int i=0;i<m;i++) {
			int o,e,p;
			cin >> o >> e >> p;
			assert(1 <= o && o <= n);
			assert(1 <= e && e <= n);
			assert(1 <= p);
			expectedcost += COST(o,e,p) % MOD;
			ERR(p << " people travel from station " << o << " to station " << e << " at expected cost " << COST(o,e,1));
			expectedcost %= MOD;
			if (delta.find(o) == delta.end()) delta[o]=p; else delta[o] += p;
			if (delta.find(e) == delta.end()) delta[e]=-p; else delta[e] -= p;
		}
		priority_queue<pair<int,int> > q;
		map<int,int>::iterator iter = delta.begin();
		ERR("delta.size=" << delta.size());
		int actualcost=0;
		while (iter != delta.end()) {
			//station = iter->first
			//people on - people off = iter->second
			ERR("iter=("<<iter->first<<","<<iter->second<<")");
			if (iter->second >= 0) {
				q.push(pair<int,int>(iter->first,iter->second));
			} else {
				int remaining=-iter->second;
				while (remaining > 0) {
					pair<int,int> t = q.top(); q.pop();
					if (remaining > t.second) {//use all tickets
						remaining -= t.second;
						actualcost += COST(t.first,iter->first,t.second) % MOD;
						ERR(t.second << " people travel from station " << t.first << " to station " << iter->first << " at cost " << COST(t.first,iter->first,1));
						actualcost %= MOD;
					} else {//use some tickets
						q.push(pair<int,int>(t.first,t.second-remaining));
						actualcost += COST(t.first,iter->first,remaining) % MOD;
						ERR(remaining << " people travel from station " << t.first << " to station " << iter->first << " at cost " << COST(t.first,iter->first,1));
						actualcost %= MOD;
						remaining = 0;
					}
				}
			}
			++iter;
		}
		cout << "Case #" << c << ": " << ((expectedcost-actualcost+MOD)%MOD) << endl;
	}
	return 0;
}

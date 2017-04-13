#include <algorithm>
#include <numeric>
#include <sstream>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <iostream>

#define foreach(i, s, w) for(int i = s; i < int(w.size()); ++i)
#define forX(i, m) for(typeof(m.begin()) i = m.begin(); i != m.end(); ++i)

using namespace std;

long long max_boosters, build_time, stars, distances;
int dists[1000];

struct node {
	int pos;
	long long dist;
	bool booster;

	node(int pos, long long dist, bool booster): pos(pos), dist(dist), booster(booster) {}

	inline friend bool operator<(const node &a, const node &b) {
		if(a.dist != b.dist)
			return a.dist > b.dist;
		return a.pos > b.pos;
	}
};

int main() {
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t) {
		cin >> max_boosters >> build_time >> stars >> distances;
		for(int i = 0; i < distances; ++i)
			scanf("%d", &dists[i]);

		// may build first on star i
		long long result = 1000000000000000000ll;
		for(int i = 0; i < stars; ++i) {
			vector <node> v;
			for(int j = 0; j < stars; ++j)
				v.push_back(node(j, dists[j % distances], false));
			sort(v.begin(), v.end());
			int at = 0;
			for(int j = 0; j < max_boosters && at < v.size(); ++j) {
				while(at < v.size() && v[at].pos < i)
					++at;
				if(at == v.size())
					break;
				v[at].booster = true;
				++at;
			}
			vector <pair <int, node> > v2;
			foreach(i, 0, v)
				v2.push_back(make_pair(v[i].pos, v[i]));
			sort(v2.begin(), v2.end());
			long long now = 0;
			foreach(i, 0, v2) {
				long long old = now;
				if(!v2[i].second.booster)
					now += 2 * v2[i].second.dist;
				else if(now >= build_time)
					now += v2[i].second.dist;
				else if(now + 2 * v2[i].second.dist <= build_time)
					now += 2 * v2[i].second.dist;
				else {
					long long t = build_time - now;
					now += t + (v2[i].second.dist - t / 2);
				}
			}
			result = min(result, now);
		}
		cout << "Case #" << (t + 1) << ": " << result << endl;
	}
	return 0;
}

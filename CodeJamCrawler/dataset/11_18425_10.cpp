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
#include <cassert>

#define foreach(i, s, w) for(int i = s; i < int(w.size()); ++i)
#define forX(i, m) for(typeof(m.begin()) i = m.begin(); i != m.end(); ++i)

using namespace std;

const int SIZE = 36;
int planets, holes;
vector <vector <int> > edge;

struct state {
	bool threaten[SIZE];
	bool own[SIZE];
	int num_own, num_threaten;

	state() {
		memset(threaten, 0, sizeof(threaten));
		memset(own, 0, sizeof(own));
		own[0] = 1;
		num_own = 1;
		num_threaten = 0;
		foreach(i, 0, edge[0]) {
			if(edge[0][i] == 0)
				continue;
			threaten[edge[0][i]] = 1;
			++num_threaten;
		}
	}

	state(const state &a) {
		memcpy(threaten, a.threaten, sizeof(threaten));
		memcpy(own, a.own, sizeof(own));
		num_own = a.num_own;
		num_threaten = a.num_threaten;
	}

	state expand(int to) const {
		state next(*this);
		assert(next.threaten[to]);
		next.threaten[to] = 0;
		--next.num_threaten;
		assert(!next.own[to]);
		next.own[to] = 1;
		++next.num_own;
		foreach(i, 0, edge[to]) {
			if(next.threaten[edge[to][i]] || next.own[edge[to][i]])
				continue;
			next.threaten[edge[to][i]] = 1;
			++next.num_threaten;
		}
		assert(next.num_own == count(next.own, next.own + SIZE, 1));
		assert(next.num_threaten == count(next.threaten, next.threaten + SIZE, 1));
		for(int i = 0; i < planets; ++i)
			if(next.own[i])
				assert(!next.threaten[i]);
		return next;
	}

	inline friend bool operator<(const state &a, const state &b) {
		if(a.num_own != b.num_own)
			return a.num_own > b.num_own;
		if(a.num_threaten != b.num_threaten)
			return a.num_threaten < b.num_threaten;
		return memcmp(a.own, b.own, sizeof(a.own)) < 0;
	}
};

int main() {
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t) {
		scanf("%d%d", &planets, &holes);
		edge.clear();
		edge.resize(planets);
		for(int i = 0; i < holes; ++i) {
			int a, b;
			scanf("%d,%d", &a, &b);
			edge[a].push_back(b);
			edge[b].push_back(a);
		}

		set <state> seen;
		priority_queue<state> Q;
		Q.push(state());
		seen.insert(state());
		state s;
		while(!Q.empty()) {
			s = Q.top();
			Q.pop();
			if(s.threaten[1])
				break;
			for(int i = 0; i < planets; ++i) {
				if(!s.own[i])
					continue;
				foreach(j, 0, edge[i]) {
					if(s.own[edge[i][j]])
						continue;
					state s2 = s.expand(edge[i][j]);
					if(seen.count(s2))
						continue;
					seen.insert(s2);
					Q.push(s2);
				}
			}
		}
		printf("Case #%d: %d %d\n", t + 1, s.num_own - 1, s.num_threaten);
	}
	return 0;
}

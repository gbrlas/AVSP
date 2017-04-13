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

int N, X;
int x[11000];
int length[11000];
int max_len[11000];

struct state {
	int pos, len;

	state(int pos, int len): pos(pos), len(len) {}

	inline friend bool operator<(const state &a, const state &b) {
		if(a.pos != b.pos)
			return a.pos < b.pos;
		return a.len < b.len;
		/*int r1 = x[a.pos] + a.len;
		int r2 = x[b.pos] + b.len;
		return r1 < r2;*/
	}
};

bool reachable(int pos, int len, int next) {
	int dist = x[next] - x[pos];
	if(dist > len)
		return false;
	return true;
}

int main() {
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t) {
		scanf("%d", &N);
		for(int i = 0; i < N; ++i)
			scanf("%d%d", &x[i + 1], &length[i + 1]);
		scanf("%d", &X);
		x[0] = 0;
		length[0] = x[1];
		x[N + 1] = X;
		length[N + 1] = X - x[N];

		priority_queue <state> Q;
		Q.push(state(0, length[0]));
		for(int i = 0; i < 11000; ++i)
			max_len[i] = -1;
		max_len[0] = length[0];

		while(!Q.empty()) {
			const int pos = Q.top().pos;
			const int len = Q.top().len;
			Q.pop();
			//cout << "at " << pos << ", " << len << " (" << max_len[pos] << ")" << endl;
			if(max_len[pos] != len)
				continue;
			for(int to = pos + 1; to < N + 2; ++to) {
				if(!reachable(pos, len, to))
					break;
				int len2 = min(x[to] - x[pos], length[to]);
				if(max_len[to] >= len2)
					continue;
				max_len[to] = len2;
				Q.push(state(to, len2));
			}
		}
		printf("Case #%d: %s\n", t + 1, (max_len[N + 1] != -1? "YES": "NO"));
	}
	return 0;
}

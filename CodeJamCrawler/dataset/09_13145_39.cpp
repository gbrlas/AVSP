#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
int price[200][50], lst[200];
vector<int> from[200], to[200];
bool used[200], adj[200][200];

struct Edge {
	int to, capa, gain, rev_id;
	Edge(int _to, int _c, int _g, int _revId) {
		to = _to; capa = _c; gain = _g; rev_id = _revId;
	}
};
vector<Edge> edges[300];
void addEdge(int from, int to, int capa, int gain) {
	edges[from].push_back(Edge(to, capa, gain, (int)edges[to].size()));
	edges[to].push_back(Edge(from, 0, -gain, (int)edges[from].size() - 1));
}
int prev[300], cost[300];

int solve() {
	int src = N + N, dest = N + N + 1;
	for (int i = 0; i < N + N + 2; ++i)
		edges[i].clear();
	for (int i = 0; i < N; ++i) {
		addEdge(src, i, 1, 0);
		addEdge(N + i, dest, 1, 0);
		addEdge(i, N + i, 1, 1);
	}
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (adj[i][j])
				addEdge(N + i, j, 1, 0);
	int ans = 0, gain = 0;
	while (gain < N) {
		for (int i = 0; i <= dest; ++i) {
			prev[i] = -1; cost[i] = -1;
		}
		cost[src] = 0;
		bool updated = false;
		for (int iter = 0; iter <= dest; ++iter) {
			updated = false;
			for (int i = 0; i <= dest; ++i)
				if (cost[i] >= 0) {
					for (vector<Edge>::iterator iter = edges[i].begin(); iter != edges[i].end(); ++iter)
						if (iter->capa > 0 && cost[iter->to] < cost[i] + iter->gain) {
							cost[iter->to] = cost[i] + iter->gain;
							prev[iter->to] = iter->rev_id;
							updated = true;
						}
				}
			if (!updated)
				break;
		}
		assert(cost[dest] != -1);
		gain += cost[dest]; ans += 1;
		int now = dest;
		while (now != src) {
			Edge & prevEdge = edges[now][prev[now]];
			prevEdge.capa += 1; edges[prevEdge.to][prevEdge.rev_id].capa -= 1;
			now = prevEdge.to;
		}
	}
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int tId = 1; tId <= T; ++tId) {
		scanf("%d %d", &N, &K); 
		for (int i = 0; i < N; ++i) {
			from[i].clear(); to[i].clear();
			for (int j = 0; j < K; ++j)
				scanf("%d", &price[i][j]);
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				bool succ = true;
				for (int k = 0; k < K; ++k)
					if (price[j][k] >= price[i][k]) {
						succ = false;
						break;
					}
				if (succ) {
					adj[i][j] = true;
					// i -> j
					from[j].push_back(i);
					to[i].push_back(j);
					//printf("%d - %d\n", i, j);
				} else
					adj[i][j] = false;
			}
		}
		printf("Case #%d: %d\n", tId, solve());
	}
	return 0;
}


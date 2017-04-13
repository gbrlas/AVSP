#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>
#include <bitset>
using namespace std;
int n, a[2050], b[2050], c[2050], l[2050], h, last[2050], tc;
vector<int> adjList[2050], topo;
bitset<2050> visited;
void dfs (int x) {
	if (visited[x]) return;
	visited[x] = true;
	for (vector<int>::iterator it = adjList[x].begin(); it != adjList[x].end(); ++it) {
		dfs(*it);
	}
	topo.push_back(x);
}
int main () {
	scanf("%d", &tc);
	for (int t = 1; t <= tc; ++t) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) adjList[i].clear();
		topo.clear();
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
		memset(last, -1, sizeof(last));
		for (int i = 0; i < n; ++i) {
			int x = a[i];
			if (last[x] != -1) {
				adjList[i].push_back(last[x]);
			}
			if (last[x-1] != -1) {
				adjList[last[x-1]].push_back(i);
			}
			last[x] = i;
		}
		memset(last, -1, sizeof(last));
		for (int i = n-1; i >= 0; --i) {
			int x = b[i];
			if (last[x] != -1) {
				adjList[i].push_back(last[x]);
			}
			if (last[x-1] != -1) {
				adjList[last[x-1]].push_back(i);
			}
			last[x] = i;
		}
		visited.reset();
		for (int i = 0; i < n; ++i) {
			sort(adjList[i].begin(), adjList[i].end());
			reverse(adjList[i].begin(), adjList[i].end());
		}
		for (int i = n-1; i >= 0; --i) dfs(i);
		reverse(topo.begin(), topo.end());
		
		for (int i = 0; i < topo.size(); ++i) {
			//printf("Topo: %d\n", topo[i]);
			c[topo[i]] = i+1;
		}
		printf("Case #%d:", t);

		for (int i = 0; i < n; ++i) {
			printf(" %d", c[i]);
		}
		printf("\n");
		h = 0;
		for (int i = 0; i < n; ++i) {
			int p = lower_bound(l, l+h, c[i]) - l;
			l[p] = c[i];
			if (a[i] != p+1) printf("Something's Wrong!\n");
			h = max(h, p+1);
		}
		h = 0;
		reverse(c, c+n);
		reverse(b, b+n);
		for (int i = 0; i < n; ++i) {
			int p = lower_bound(l, l+h, c[i]) - l;
			l[p] = c[i];
			if (b[i] != p+1) printf("Something's Wrong!\n");
			h = max(h, p+1);
		}
	}
}
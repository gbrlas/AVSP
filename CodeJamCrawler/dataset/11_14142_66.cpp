#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
const int N = 40;

int n, m;
vector<int> vout[N];
int dist[N], ansd, anst;

int cnt(ll x) {
  int res = 0;
  while (x) {
    if (x % 2) res++;
    x /= 2;
  }
  return res;
}

ll add(ll mask, int u) {
  mask |= (1ll << u);
  for (int z = 0; z < vout[u].size(); z++) {
    int v = vout[u][z];
    mask |= (1ll << v);
  }
  return mask;
}

void dfs(int u, int d, ll mask, ll xx) {
  if (dist[u] < d) return;
  dist[u] = d;

  if (mask & 2) {
    if (ansd > d) {
      ansd = d;
      anst = cnt(mask) - cnt(xx);
    } else if (ansd == d) {
      anst = max(anst, cnt(mask) - cnt(xx));
    }
    return;
  }

  for (int z = 0; z < vout[u].size(); z++) {
    int v = vout[u][z];
    dfs(v, d + 1, add(mask, v), xx | (1ll << v));
  }
}

int main() {
  int T, ca = 0;
  scanf("%d", &T);
  while (T--) {

    scanf("%d %d", &n, &m);

    memset(dist, 0x3f, sizeof(dist));
    for (int i = 0; i < n; i++)
      vout[i].clear();

    while (m--) {
      int x, y;
      scanf("%d,%d", &x, &y);
      vout[x].push_back(y);
      vout[y].push_back(x);
    }

    ansd = 0x3f3f3f3f;
    dfs(0, 0, add(0, 0), 1);

    printf("Case #%d: %d %d\n", ++ca, ansd, anst);
  }
  return 0;
}

#include <cstdio>

using namespace std;

const int N = 1024;

int n;
long long r, k;
int cnt[N];
int vis[N], v;
long long euro[N];
long long g[N];
long long sum;

long long rec(int pos, int turn, long long cost)
{
//  printf("%d %d %lld\n", pos, turn, cost);
  if (vis[pos] == v && cnt[pos] == (r % (turn - cnt[pos])))
  {
    return (cost - euro[pos]) * (r / (turn - cnt[pos])) + euro[pos];
  }
  vis[pos] = v;
  cnt[pos] = turn;
  euro[pos] = cost;
  if (cnt[pos] == r)
  {
    return euro[pos];
  }

  long long curr = 0;
  for (int i = 0; i < n; ++ i)
  {
    int np = (pos + i) % n;
    curr += g[np];
    if (curr > k) {
      return rec(np, turn + 1, cost + curr - g[np]);
    }
  }
  return rec(pos, turn + 1, cost + sum);
}

int main()
{
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; ++ i)
  {
    scanf("%lld %lld %d", &r, &k, &n);
    sum = 0;
    ++ v;
    for (int j = 0; j < n; ++ j)
    {
      scanf("%lld", g + j);
      sum += g[j];
      cnt[j] = 0;
      euro[j] = 0;
    }
    printf("Case #%d: %lld\n", i, rec(0, 0, 0));
  }
  return 0;
}

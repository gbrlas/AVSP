#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 1000010;
int p[N], q[N], qn;

int cal(ll n, ll x) {
  ll y = 1;
  int ans = 0;
  while (y * x <= n) {
    y *= x;
    ans++;
  }
  return ans;
}

int solve(ll n) {
  if (n == 1) return 0;

  int ans = 1;
  for (int i = 0; i < qn && (ll)q[i] * q[i] <= n; i++) {
    ans += cal(n, q[i]) - 1;
  }
  return ans;
}

int main() {

  for (int i = 2; i < N; i++)
    p[i] = 0;
  for (int i = 2; i < N; i++)
    if (!p[i]) {
      q[qn++] = i;
      for (int j = i; j < N; j += i)
        p[j] = i;
    }

  int T, ca = 0; scanf("%d", &T);
  while (T--) {
    ll n; scanf("%lld", &n);

    printf("Case #%d: %d\n", ++ca, solve(n));
  }
  return 0;
}

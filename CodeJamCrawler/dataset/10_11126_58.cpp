#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1024;
int a[N], b[N], index[N];

bool comp(int f, int s) {
  return a[f] < a[s];
}

int main()
{
  int tc;
  scanf("%d", &tc);
  for (int t = 1; t <= tc; ++ t) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
      index[i] = i;
      scanf("%d %d", &a[i], &b[i]);
    }
    sort(index, index + n, comp);
    int ans = 0;
    for (int i = 0; i < n; ++ i) {
      int ix1 = index[i];
      for (int j = i + 1; j < n; ++ j) {
        int ix2 = index[j];
        ans += (b[ix1] > b[ix2]);
      }
    }
    printf("Case #%d: %d\n", t, ans);
  }
  return 0;
}

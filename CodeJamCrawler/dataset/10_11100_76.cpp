#include <cstdio>

using namespace std;

int main()
{
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++ i)
  {
    long long n, k;
    scanf("%lld %lld", &n, &k);
    long long x = (1ll << n) - 1;
    printf("Case #%d: %s\n", i + 1, (k & x) == x ? "ON" : "OFF");
  }
  return 0;
}

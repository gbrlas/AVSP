#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define all(v) v.begin(), v.end()
#define forint(i, a, b) for (int i = a; i != b; ++i)
#define foreach(i, v) typedef typeof(v) i##_##c;\
  for (i##_##c::iterator i = v.begin(); i != v.end(); ++i)

const int MOD = 100003;

long long mpower(int x, int n) {
  long long r;
  if (n == 1)
    r = x;
  else if (n % 2) {
    r = mpower(x, n - 1);
    r *= x;
  } else {
    r = mpower(x, n/2);
    r *= r;
  }
  return r % MOD;
}

int inverse[MOD] = {};

long long minv(int x) {
  if (inverse[x] == 0)
    inverse[x] = mpower(x, MOD - 2);
  return inverse[x];
}

long long mch[501][501] = {};

long long mchoose(int n, int k) {
  if (mch[n][k] > 0)
    return mch[n][k];

  long long prod = 1;
  forint(i, 0, k) {
    prod *= n - i;
    prod %= MOD;
    prod *= minv(i + 1);
    prod %= MOD;
  }
  mch[n][k] = prod;
  return prod;
}

long long w[501][501] = {};

long long ways(int n, int k) {
  if (k == 1)
    return 1;
  if (w[n][k] > 0)
    return w[n][k];

  long long sum = 0;
  forint(i, 0, min(k - 1, n - k)) {
    sum += mchoose(n - k - 1, i) * ways(k, k - 1 - i);
    sum %= MOD;
  }
  w[n][k] = sum;
  return sum;
}

int ways(int n) {
  long long sum = 0;
  forint(k, 1, n) {
    sum += ways(n, k);
    sum %= MOD;
  }
  return sum;
}

int main() {
  int t, n;
  cin >> t;
  for(int i = 0; i != t; ++i) {
    cin >> n;
    cout << "Case #" << (i+1) << ": " << ways(n) << endl;
  }
}

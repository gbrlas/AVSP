#include <iostream>
#include <vector>
using namespace std;

int main () {

  int N, n, m, c = 0;
  long long X, Y, Z, mod = 1000000007;
  scanf("%d", &N);
  while (N--) {
    scanf("%d %d %lld %lld %lld", &n, &m, &X, &Y, &Z);
    vector<int> A;
    vector<long long> dp;
    int a;
    for (int i = 0; i < m; ++i) {
      scanf("%d", &a);
      A.push_back(a);
    }
    vector<int> s;
    for (int i = 0; i < n; ++i) {
      s.push_back(A[i%m]);
      A[i%m] = (X*A[i%m]+Y*(i+1))%Z;
      dp.push_back(1);
    }
    long long res = 1;
    for (int i = n-2; i >= 0; --i) {
      for (int j = i+1; j < n; ++j)
	if (s[i] < s[j])
	  dp[i] = (dp[i]+dp[j])%mod;
      res = (res+dp[i])%mod;
    }
    printf("Case #%d: %lld\n", ++c, res);
  }
}

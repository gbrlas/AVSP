#include <iostream>
#include <vector>
using namespace std;

int main () {

  int N, P, K, L, c = 0;
  scanf("%d", &N);
  while (N--) {
    scanf("%d %d %d", &P, &K, &L);
    int t = 0;
    vector<int> uses;
    for (int i = 0; i < L; ++i) {
      scanf("%d", &t);
      uses.push_back(t);
    }
    sort(uses.begin(), uses.end());
    long long res = 0;
    for (int i = 0; i < L; ++i) {
      long long k = uses[L-i-1];
      int p = i/K+1;
      if (p > P) {
	res = -1;
	break;
      }
      res += k*p;
    }
    if (res >= 0)
      printf("Case #%d: %lld\n", ++c, res);
    else
      printf("Case #%d: Impossible\n", ++c);
  }
}

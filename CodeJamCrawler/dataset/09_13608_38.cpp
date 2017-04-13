#include <iostream>
#include <vector>
using namespace std;

int calc (int p, vector<int> & qq, vector<bool> & used, int t, int c) {

  if (t == qq.size())
    return c;
  int best = 1<<30;
  for (int i = 0; i < used.size(); ++i) {
    if (!used[i]) {
      used[i] = true;
      int cost = p-1;
      for (int j = i-1; j >= 0; --j) {
	if (used[j]) {
	  cost -= qq[j];
	  break;
	}
      }
      for (int j = i+1; j < used.size(); ++j) {
	if (used[j]) {
	  cost -= p-qq[j]+1;
	  break;
	}
      }
      best = min(best, calc(p, qq, used, t+1, c+cost));
      used[i] = false;
    }
  }
  return best;
}

int main () {

  int N, P, Q;
  scanf("%d", &N);
  for (int c = 1; c <= N; ++c) {
    scanf("%d %d", &P, &Q);
    vector<int> qq(Q);
    for (int i = 0; i < Q; ++i)
      scanf("%d", &qq[i]);
    vector<bool> used(Q, false);
    printf("Case #%d: %d\n", c, calc(P, qq, used, 0, 0));
  }
}

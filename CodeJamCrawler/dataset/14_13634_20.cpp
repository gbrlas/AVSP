#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int X, N;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    cin >> N >> X;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }
    int ans = 1 << 28;
    sort(a.begin(), a.end());
    do {
      int s = 0, r = 0, ct = 0;
      for (int i = 0; i < N; i++) {
        if (ct >= 2 || r + a[i] > X) {
          r = a[i];
          s++;
          ct = 1;
        } else {
          r += a[i];
          ct++;
        }
      }
      if (r > 0) s++;
      ans = min(ans, s);
    } while (next_permutation(a.begin(), a.end()));
    cout << ans  << endl;
  }
}
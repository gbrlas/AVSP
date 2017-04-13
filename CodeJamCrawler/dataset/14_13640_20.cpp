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
    int p = 0;
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = N - 1; i >= p; i--) {
      if (a[p] + a[i] <= X) {
        p++;
      }
      ans++;
    }
    cout << ans  << endl;
  }
}
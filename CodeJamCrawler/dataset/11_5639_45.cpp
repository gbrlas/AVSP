#include <iostream>
using namespace std;

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int n, sum = 0, m = 0, psum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int v; cin >> v;
      sum += v;
      psum = psum xor v;
      if (m == 0 || v < m) m = v;
    }
    if (psum == 0)
      cout << "Case #" << t << ": " << sum - m << endl;
    else
      cout << "Case #" << t << ": NO" << endl;
  }
  return 0;
}

#include <iostream>

using namespace std;

int main(int argc, const char** argv) {
  int T, N;
  cin >> T;
  for(int c = 1; c <= T; ++c) {
    cin >> N;
    int s = 0, p = 0, m = 1000000;
    for (int i = 0; i < N; ++i) {
      int t;
      cin >> t;
      s += t;
      p ^= t;
      m = min(t, m);
    }
    cout << "Case #" << c << ": ";
    if (p != 0) {
      cout << "NO" << endl;
    } else {
      cout << s - m << endl;
    }
  }
}

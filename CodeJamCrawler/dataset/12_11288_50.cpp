// Language: D (http://dlang.org/)
// (version 2.059 for Windows 7)

import std.stdio;

void main() {
  int T;
  readf("%d\n", &T);
  foreach (int tc; 0 .. T) {
    int N, S, p;
    readf("%d %d %d ", &N, &S, &p);
    int ans = 0;
    foreach (int i; 0 .. N) {
      int v;
      readf("%d ", &v);
      int best = (v + 2) / 3;
      if (best >= p) {
        ans++;
      } else if (best == p - 1 && v % 3 != 1 && v != 0) {
        ans++;
        S--;
      }
    }
    if (S < 0) {
      ans += S;
    }
    writefln("Case #%s: %s", tc + 1, ans);
  }
}
#include <iostream>
#include <map>
#include <string>
using namespace std;

int mkdir (string s, map<string,bool> & seen) {

  if (seen.find(s) != seen.end())
    return 0;
  seen[s] = true;
  int pos = s.rfind("/");
  s = s.substr(0, pos);
  return 1+mkdir(s, seen);
}

int main () {

  int T, N, M;
  char buf[201];
  scanf("%d", &T);
  for (int c = 1; c <= T; ++c) {
    map<string,bool> seen;
    seen[""] = true;
    scanf("%d %d\n", &N, &M);
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      scanf("%s", buf);
      mkdir(string(buf), seen);
    }
    for (int i = 0; i < M; ++i) {
      scanf("%s", buf);
      ans += mkdir(string(buf), seen);
    }
    printf("Case #%d: %d\n", c, ans);
  }
  return 0;
}

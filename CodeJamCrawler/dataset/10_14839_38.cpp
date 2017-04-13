#include <iostream>
#include <map>
using namespace std;

int main () {

  int C, R, x1, y1, x2, y2;
  scanf("%d", &C);
  for (int c = 1; c <= C; ++c) {
    scanf("%d", &R);
    map<pair<int,int>,bool> pos;
    for (int i = 0; i < R; ++i) {
      scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
      for (int a = x1; a <= x2; ++a)
        for (int b = y1; b <= y2; ++b)
          pos[make_pair<int,int>(a, b)] = true;
    }
    int ans = 0;
    while (pos.size()) {
      map<pair<int,int>,bool> pos2;
      for (map<pair<int,int>,bool>::iterator it = pos.begin(); it != pos.end(); ++it) {
        int x1 = it->first.first;
        int y1 = it->first.second;
        if (pos.find(make_pair<int,int>(x1-1,y1)) != pos.end() ||
            pos.find(make_pair<int,int>(x1,y1-1)) != pos.end())
          pos2[make_pair<int,int>(x1,y1)] = true;
        if (pos.find(make_pair<int,int>(x1-1,y1+1)) != pos.end())
          pos2[make_pair<int,int>(x1,y1+1)] = true;
      }
      pos = pos2;
//      printf("%d %d\n", ans, pos.size());
      ++ans;
    }
    printf("Case #%d: %d\n", c, ans);
  }
  return 0;
}

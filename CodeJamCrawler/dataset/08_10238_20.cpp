#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

struct offer {
  int start, end;
  int color;
};

offer O[305];

const int START = 0;
const int END = 1;

struct event {
  int type;
  int color;
  int where;
  int which;
};

int operator<(const event &a, const event &b) {
  if (a.where != b.where)
    return a.where < b.where;

  return a.type < b.type;
}

event E[605];

int main() {
  int z;
  cin >> z;

  for (int ii = 1; ii <= z; ++ii) {
    int n;
    map<string, int> M;
    int ncolors = 0;
    cin >> n;

    for (int i = 0; i < n; ++i) {
      string name;
      int a, b;
      cin >> name >> a >> b;

      if (M.find(name) == M.end()) {
        M[name] = ncolors++;
      }

      offer o = { a, b + 1, M[name] };
      O[i] = o;

      event e1 = { START, M[name], a, i };
      event e2 = { END, M[name], b + 1, i };

      E[2 * i] = e1;
      E[2 * i + 1] = e2;
    }

    event dummy = { END, -1, 1, -1 };
    E[2 * n] = dummy;

    sort(E, E + 2 * n + 1);

    //for (int i = 0; i < 2 * n + 1; ++i)
      //printf("%d %d %d %d\n", E[i].type, E[i].color, E[i].where, E[i].which);
    int best = (int) 2e9;
    if (ncolors < 3)
      ncolors = 3;

    for (int a = 0; a < ncolors; ++a)
      for (int b = a + 1; b < ncolors; ++b)
        for (int c = b + 1; c < ncolors; ++c) {
          int OK = 1;
          int res = 0;
          int max_seen = 1;
          int max_done = 1;

          for (int i = 0; i < 2 * n + 1; ++i) {
            //printf("type: %d, where: %d, max_done: %d\n", E[i].type, E[i].where, max_done);
            if (E[i].type == END) {
              if (max_done == E[i].where) {
                if (max_seen <= max_done && max_done != 10001) {
                  OK = 0;
                } else if (max_done == 10001) {
                  break;
                } else if (max_done < max_seen) {
                  ++res;
                  max_done = max_seen;
                }
              }
            } else if (E[i].color == a || E[i].color == b || E[i].color == c) {
              max_seen = max(max_seen, O[E[i].which].end);
            }

            //printf("max_seen: %d, max_done: %d\n", max_seen, max_done);
          }

          if (OK && max_done == 10001 && res < best) {
            best = res;
          }
        }

    if (best < (int) 2e9) {
      printf("Case #%d: %d\n", ii, best);
    } else {
      printf("Case #%d: IMPOSSIBLE\n", ii);
    }
  }

  return 0;
}
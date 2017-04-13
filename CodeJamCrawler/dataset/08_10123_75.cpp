#include <set>
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;

const int ARR = 0;
const int DEP = 1;

struct event {
  int type;
  int time;
  int where;
};

int operator<(const event &a, const event &b) {
  if (a.time != b.time) {
    return a.time < b.time;
  }

  if (a.type != b.type) {
    return a.type == ARR;
  }

  return 0;
}

int parsetime(string time) {
  int res = 0;
  res = res + (time[0] - '0');
  res = 10 * res + (time[1] - '0');
  res = 6 * res + (time[3] - '0');
  res = 10 * res + (time[4] - '0');

  return res;
}

int main() {
  int zz;
  cin >> zz;

  for (int z = 1; z <= zz; ++z) {
    int T;
    cin >> T;

    int a2b, b2a;
    cin >> a2b >> b2a;

    multiset<event> S;

    for (int i = 0; i < a2b; ++i) {
      string dep, arr;
      cin >> dep >> arr;

      event e1 = { DEP, parsetime(dep), 0 };
      event e2 = { ARR, parsetime(arr) + T, 1 };

      S.insert(e1);
      S.insert(e2);
    }

    for (int i = 0; i < b2a; ++i) {
      string dep, arr;
      cin >> dep >> arr;

      event e1 = { DEP, parsetime(dep), 1 };
      event e2 = { ARR, parsetime(arr) + T, 0 };

      S.insert(e1);
      S.insert(e2);
    }

    int cur[2] = { 0, 0 };
    int minn[2] = { 0, 0 };

    for (multiset<event>::iterator it = S.begin(); it != S.end(); ++it) {
      if (it->type == ARR) {
        cur[it->where]++;
      } else {
        cur[it->where]--;
        minn[it->where] = min(minn[it->where], cur[it->where]);
      }
    }

    cout << "Case #" << z << ": " << (-minn[0]) << " " << (-minn[1]) << endl;
  }

  return 0;
}

#include <iostream>
#include <vector>
using namespace std;

struct TimeTable {
  int d, a;
  TimeTable (int dd, int aa) : d(dd), a(aa) {}
  bool operator<(const TimeTable & t) const {
    if (d != t.d)
      return d < t.d;
    return a < t.a;
  }
};

vector<TimeTable> ab, ba;
int T;

void followTrain (TimeTable t, bool atob) {

  t.a += T;
  vector<TimeTable> & s = (atob ? ba : ab);
  for (vector<TimeTable>::iterator i = s.begin(); i != s.end(); ++i) {
    if (i->d >= t.a) {
      TimeTable tt = *i;
      s.erase(i);
      followTrain(tt, !atob);
      return;
    }
  }
}

void solve (int & ansA, int & ansB) {

  if (!ab.size()) {
    ansB += ba.size();
    ba.clear();
  }
  else if (!ba.size()) {
    ansA += ab.size();
    ab.clear();
  }
  else {
    if (ab[0] < ba[0]) {
      ++ansA;
      TimeTable t = ab[0];
      ab.erase(ab.begin());
      followTrain(t, true);
    }
    else {
      ++ansB;
      TimeTable t = ba[0];
      ba.erase(ba.begin());
      followTrain(t, false);
    }
  }
}

int main () {

  int N, NA, NB, c = 0;
  scanf("%d", &N);
  while (N--) {
    scanf("%d %d %d", &T, &NA, &NB);
    ab.clear();
    ba.clear();
    int hd,md,ha,ma;
    for (int i = 0; i < NA; ++i) {
      scanf("%d:%d %d:%d\n", &hd, &md, &ha, &ma);
      ab.push_back(TimeTable(60*hd+md, 60*ha+ma));
    }
    for (int i = 0; i < NB; ++i) {
      scanf("%d:%d %d:%d\n", &hd, &md, &ha, &ma);
      ba.push_back(TimeTable(60*hd+md, 60*ha+ma));
    }
    sort(ab.begin(), ab.end());
    sort(ba.begin(), ba.end());
    int ansA = 0, ansB = 0;
    while (ab.size() || ba.size())
      solve(ansA, ansB);
    printf("Case #%d: %d %d\n", ++c, ansA, ansB);
  }
}

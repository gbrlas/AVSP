#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <set>
//#include <multiset>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <algorithm>
#include <string>
//#include <>

#define fori(i,b,e) for (int i = (b); i < (e); i++)
#define mp make_pair
#define pb push_back
#define add insert
#define all(a) (a).begin(), (a).end()
#define elsif else if
#define sz(a) ((int)(a).size())

using namespace std;

inline int getInt() { int res;  scanf("%d", &res);  return res; }
inline double getDbl() { double res;  scanf("%lf", &res);  return res; }

void clear() {
}

void read() {
}

void solve() {
  multiset<int> disks;
  int n = getInt();
  int s = getInt();
  fori(i,0,n) {
    disks.insert(getInt());
  }
  int cnt = 0;
  while (!disks.empty()) {
    cnt++;
    auto p = disks.end();
    p--;
    int a = *p;
    //cerr << "a =  " << a << endl;
    disks.erase(p);
    if (disks.empty())
      break;
    auto q = disks.upper_bound(s - a);
    if (q != disks.begin()) {
      q--;
    }
    //cerr << "q =  " << *q << endl;
    if (*q + a <= s) {
      disks.erase(q);
    }
  }
  printf("%d\n", cnt);
}

int main() {
  freopen("in.txt", "rt", stdin);
  freopen("out.txt", "wt", stdout);
  srand(time(0));
  int N = getInt();
  fori(T,1,N+1) {
    clear();
    read();
    printf("Case #%d: ", T);
    solve();
  }
  return 0;
}

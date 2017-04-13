#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <sstream>
#include <set>
#include <utility>
#include <queue>
#include <cassert>
#include <ctime>
using namespace std;

#define PB push_back
#define SZ size()
#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < (int)n; i++)
#define ITR(i, j, n) for(int i = j; i < (int)n; i++)
#define mem(array, val) memset(array, val, sizeof(array))
#define READ(filename) freopen(filename, "r", stdin)
#define WRITE(filename) freopen(filename, "w", stdout)
#define Pii pair <int, int>
#define Fr first
#define Sc second
#define Long long long
#define get(a) scanf("%d", &a)

#define eps 1e-7
#define MULT 1000000
int naomi[1005], ken[1005], n;

int main()
{
  READ("D-large.in");
  WRITE("answerDl.out");
  int t, caseno = 1;
  get(t);

  while(caseno <= t) {
    get(n);
    int nm_f, nm_e, ke_f, ke_e;
    REP(i, n) {
      double a;
      scanf("%lf", &a);
      naomi[i] = (int)(a * MULT);
    }
    REP(i, n) {
      double a;
      scanf("%lf", &a);
      ken[i] = (int)(a * MULT);
    }

    int ans1 = 0, ans2 = 0;
    sort(naomi, naomi+n);
    reverse(naomi, naomi+n);
    sort(ken, ken+n);
    reverse(ken, ken+n);
    //REP(i, n)
      //printf("%d %d\n", naomi[i], ken[i]);
    nm_f = 0, nm_e = n-1, ke_f = 0, ke_e = n-1;
    REP(i, n) {
      if(naomi[nm_e] > ken[ke_e]) {
        nm_e--;
        ke_e--;
        ans1++;
      }
      else {
        nm_e--;
        ke_f++;
      }
    }
    nm_f = 0, nm_e = n-1, ke_f = 0, ke_e = n-1;
    REP(i, n) {
      if(naomi[nm_f] > ken[ke_f]) {
        nm_f++;
        ke_e--;
        ans2++;
      }
      else {
        nm_f++;
        ke_f++;
      }
    }

    printf("Case #%d: %d %d\n", caseno++, ans1, ans2);
  }
  return 0;
}

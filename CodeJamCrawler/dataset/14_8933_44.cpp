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

int a1[4][4], a2[4][4];

int main()
{
  READ("A-small-attempt0.in");
  WRITE("answer.out");
  int t, caseno = 1;
  get(t);

  while(caseno <= t) {
    int ans1, ans2, cnt = 0, last;
    get(ans1);
    ans1--;
    REP(i, 4) REP(j, 4)
      get(a1[i][j]);
    get(ans2);
    ans2--;
    REP(i, 4) REP(j, 4)
      get(a2[i][j]);

    REP(i, 4)
      REP(j, 4)
        if(a1[ans1][i] == a2[ans2][j]) {
          cnt++;
          last = a1[ans1][i];
        }

    printf("Case #%d: ", caseno++);
    if(!cnt)
      puts("Volunteer cheated!");
    else if(cnt == 1)
      printf("%d\n", last);
    else
      puts("Bad magician!");
  }
  return 0;
}

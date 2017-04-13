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
double C, F, X;

int main()
{
  READ("B-small-attempt0.in");
  WRITE("answerBs.out");
  int t, caseno = 1;
  get(t);

  while(caseno <= t) {
    double curr = 0.0, curr_time = 0.0, rate = 2.0;
    scanf("%lf %lf %lf", &C, &F, &X);

    while(abs(curr - X) > eps) {
      double tmp1, tmp2;
      tmp1 = tmp2 = curr_time;
      tmp1 += (X - curr) / rate;
      tmp2 += (C - curr) / rate;
      tmp2 += X / (rate + F);

      if(abs(tmp1- tmp2) < eps) {
        curr_time = tmp1;
        break;
      }
      if(tmp1 > tmp2) {
        curr_time += (C - curr) / rate;
        rate += F;
        curr = 0.0;
      }
      else {
        curr_time = tmp1;
        break;
      }
    }

    printf("Case #%d: %.7lf\n", caseno++, curr_time);
  }
  return 0;
}

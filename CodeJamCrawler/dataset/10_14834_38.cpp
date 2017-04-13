#include <iostream>
using namespace std;

int M[1024], dyn[1024][10], price[1024];

int calc (int m, int t, int s) {

  if (dyn[m][s] != -1)
    return dyn[m][s];
  int & ans = dyn[m][s];
  if (m >= t/2) {
    int mm = m-t/2;
    if (M[mm*2] < s || M[mm*2+1] < s)
      ans = -2;
    else if (M[mm*2] == s || M[mm*2+1] == s)
      ans = price[m];
    else
      ans = 0;
//    printf("%d(%d) %d %d: %d\n", m, mm, t, s, ans);
  }
  else {
    int aa = calc(m*2, t, s);
    int ab = calc(m*2+1, t, s);
    int a = aa == -2 || ab == -2 ? -2 : price[m]+aa+ab;
    int ba = calc(m*2, t, s+1);
    int bb = calc(m*2+1, t, s+1);
    int b = ba == -2 || bb == -2 ? -2 : ba+bb;
    if (a == -2 || b == -2)
      ans = a == -2 ? b : a;
    else
      ans = min(a,b);
  }
//  printf("%d %d %d: %d\n", m, t, s, ans);
  return ans;
}

int main () {

  int T, P, m;
  scanf("%d", &T);
  for (int c = 1; c <= T; ++c) {
    memset(dyn, -1, sizeof(dyn));
    scanf("%d", &P);
//    printf("P: %d\n", P);
    m = 1<<P;
//    printf("m: %d\n", m);
    for (int i = 0; i < m; ++i)
      scanf("%d", M+i);
    int mm = m/2;
    while (mm) {
      for (int j = 0; j < mm; ++j) {
        scanf("%d", price+mm+j);
//        printf("%d %d %d\n", j, mm, mm+j);
      }
      mm /= 2;
    }
    int ans = calc(1, 1<<P, 0);
    printf("Case #%d: %d\n", c, ans);
  }
  return 0;
}

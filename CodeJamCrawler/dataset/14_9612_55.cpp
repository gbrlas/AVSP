#include<stdio.h>

int T;
double C, F, X;

int main() {
  freopen("B.txt","r",stdin);
  freopen("B.out","w",stdout);
  
  scanf("%d",&T);
  for (int tc=0; tc<T; tc++) {
    double rate=2, ans=0;
    scanf("%lf %lf %lf",&C,&F,&X);
    while(true) {
      double a = X/rate;
      double b = C/rate + X/(rate+F);
      if (a <= b) {
        ans += a;
        break;
      }
      else {
        ans += C/rate;
        rate += F;
      }
    }
    printf("Case #%d: %.7lf\n",tc+1,ans);
  }
  return 0;
}

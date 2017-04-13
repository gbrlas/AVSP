#include <stdio.h>
int main(void) {
 long cases, actual, attempts;
 double c, f, x, cookies, time_elapsed, cookie_rate, time_prediction1;
 double time_prediction2;
 scanf("%ld", &cases);
 for(actual=1;actual<=cases;actual++) {
  printf("Case #%ld: ", actual);
  scanf("%lf %lf %lf", &c, &f, &x);
//  printf("%lf %lf %lf\n", c, f, x);
  time_elapsed=0; cookies=0; cookie_rate=2; attempts=0;
  while(cookies<x) {
//   if(attempts++>10) break;
   time_prediction1=time_elapsed+(x-cookies)/cookie_rate;
//   printf("Prediction1: %lf\n", time_prediction1);
   time_prediction2=time_elapsed+c/cookie_rate+((x-cookies)/(cookie_rate+f));
//   printf("Prediction2: %lf\n", time_prediction2);
   if(time_prediction1<=time_prediction2) {
    time_elapsed = time_prediction1;
    cookies=x;
   } else {
    time_elapsed = time_elapsed+c/cookie_rate;
    cookie_rate += f;
   }
//   (x-time_prediction2)/(x-time_prediction1)<cookie_rate/(cookie_rate+f)
  }
  printf("%.7lf\n", time_elapsed);
 }
 return(0);
}

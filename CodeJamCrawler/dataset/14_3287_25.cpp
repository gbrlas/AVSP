#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);
  for (int t=1; t<=T; t++)
  {
    double C, F, X;
    scanf("%lf %lf %lf", &C, &F, &X);
    
    double speed = 2;
    double best = X / speed;
    double cur = 0;
    for(;;)
    {
      cur += C / speed;
      speed += F;
      if (best <= cur + X / speed)
        break;
      else
        best = cur + X / speed;
    }
    printf("Case #%d: %.7lf\n", t, best);
  }
  return 0;
}

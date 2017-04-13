#include <iostream>
#include <stdio.h>
#include <climits>

using namespace std;

main()
{
  int TC, T = 0;
  double c, f, x;
  scanf("%d", &TC);
  while (T++ < TC)
  {
    scanf("%lf %lf %lf", &c, &f, &x);
    double vel = 2.0;
    double acum = 0;
    double time = x/vel;
    while (true)
    {
      acum += c/vel;
      double temp = acum + (x/(vel+f));
      if (temp < time)
      {
        vel += f;
        time = temp;
      }
      else
      {
        break;
      }
    }
    
    printf("Case #%d: %.7lf\n", T, time);
  }
}
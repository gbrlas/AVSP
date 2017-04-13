#include <cmath>
#include <iostream>
using namespace std;

int main () {

  int T, N, M;
  double p1x, p1y, p2x, p2y, x[10], y[10];
  scanf("%d", &T);
  for (int c = 1; c <= T; ++c) {
    scanf("%d %d", &N, &M);
    scanf("%lf %lf %lf %lf", &p1x, &p1y, &p2x, &p2y);
    for (int i = 0; i < M; ++i)
      scanf("%lf %lf", &x[i], &y[i]);
    printf("Case #%d:", c);
    for (int i = 0; i < M; ++i) {
      double ab = sqrt((p2x-p1x)*(p2x-p1x)+(p2y-p1y)*(p2y-p1y));
      double r0 = sqrt((p1x-x[i])*(p1x-x[i])+(p1y-y[i])*(p1y-y[i]));
      double r1 = sqrt((p2x-x[i])*(p2x-x[i])+(p2y-y[i])*(p2y-y[i]));
      double cbd = 2*acos((r1*r1+ab*ab-r0*r0)/(2*r1*ab));
      double cad = 2*acos((r0*r0+ab*ab-r1*r1)/(2*r0*ab));
      double area = cbd*r1*r1/2-r1*r1*sin(cbd)/2;
            area += cad*r0*r0/2-r0*r0*sin(cad)/2;
      printf(" %.7lf", area);
    }
    printf("\n");
  }
  return 0;
}

#include <stdio.h>
#include<math.h>

using namespace std;

int x[500], y[500], z[500], vx[500], vy[500], vz[500];

int main(void) {

  int test; scanf("%d", &test);

  for (int i = 0; i < test; i++) {
    int n; scanf("%d", &n);
    int sx, svx, sy, svy, sz, svz;
    
    sx = svx = sy = svy = sz = svz = 0;

    for (int j = 0; j < n; j++) {
      int x, y, z, vx, vy, vz;
      scanf("%d %d %d %d %d %d", &x, &y, &z, &vx, &vy, &vz);
      sx += x; svx += vx;
      sy += y; svy += vy;
      sz += z; svz += vz;
    }

    //    if (i == 27) printf("%d %d %d %d %d %d\n", sx, sy, sz, svx, svy, svz);

    double a, b, c;
    c = sx*sx + sy*sy + sz*sz;
    b = 2*sx*svx + 2*sy*svy + 2*sz*svz;
    a = svx*svx + svy*svy + svz*svz;

    //    if (i == 27) printf("%f %f %f\n", a, b, c);

    double d, t;
    t = -b/(2.0*a);
    if (a == 0.0 || t < 0.0) t = 0.0;

    d = a*t*t+b*t+c;
    if (d < 1e-7) d = 0.0;
    else d = sqrt(d)/((double) n);

    printf("Case #%d: %.8f %.8f\n", i+1, d, t);
  }

  return 0;
}

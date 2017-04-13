/*
Indefinite integral of Sqrt[r^2 - x^2], calculated using Mathematica

                 2    2     2              x
         x Sqrt[r  - x ] + r  ArcTan[-------------]
                                           2    2
                                     Sqrt[r  - x ]
Out[11]= ------------------------------------------
                             2
 */

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define double long double

inline double sq(double a) {
  return a * a;
}

inline double sqdist(double x1, double y1, double x2, double y2) {
  return sq(x1 - x2) + sq(y1 - y2);
}

typedef pair<double, double> point;

point find_inter(double x1, double y1, double x2, double y2, double sqinRmf) {
  double lo = 0;
  double hi = 1;

  for (int i = 0; i < 100; ++i) {
    double med = (lo + hi) / 2;

    if (sqdist(0, 0, (1 - med) * x1 + med * x2, (1 - med) * y1 + med * y2) >= sqinRmf)
      hi = med;
    else
      lo = med;
  }

  return point((1 - lo) * x1 + lo * x2, (1 - lo) * y1 + lo * y2);
}

double integral(double x, double sqr) {
  return (x * sqrt(sqr - sq(x)) + sqr * atan(x / sqrt(sqr - sq(x)))) / 2;
}

double calc_curve(double x1, double x2, double base, double sqr) {
  return integral(x2, sqr) - integral(x1, sqr) - (x2 - x1) * base;
}

int main() {
  int zz;
  scanf("%d", &zz);

  for (int z = 1; z <= zz; ++z) {
    double f, R, t, r, g;
    scanf("%Lf%Lf%Lf%Lf%Lf", &f, &R, &t, &r, &g);
    double inR = R - t;
    double sqinR = sq(inR);
    double sqinRmf = sq(inR - f);
    double gm2f = g - 2 * f;
    double sqgm2f = sq(gm2f);

    double safe_area = 0;

    for (double x = r; ; x += (g + 2 * r)) {
      if (sqdist(0, 0, x + f, r + f) >= sqinRmf)
        break;

      for (double y = r; ; y += (g + 2 * r)) {
        if (sqdist(0, 0, x + f, y + f) >= sqinRmf)
          break;

        if (sqdist(0, 0, x + g - f, y + g - f) <= sqinRmf) {
          /* Full square is free */
          double this_area = sqgm2f;
          if (gm2f > 0) {
            safe_area += this_area;
          }
        } else {
          double this_area = 0;

          double xx = x;
          double yy = y;

          if (xx > yy)
            swap(xx, yy);
        
          int tl = 1, tr = 1, br = 1;

          if (sqdist(0, 0, xx + f, yy + g - f) >= sqinRmf)
            tl = 0;
          if (sqdist(0, 0, xx + g - f, yy + g - f) >= sqinRmf)
            tr = 0;
          if (sqdist(0, 0, xx + g - f, yy + f) >= sqinRmf)
            br = 0;

          if (!br) {
            point p1 = find_inter(xx + f, yy + f, xx + g - f, yy + f, sqinRmf);
            this_area += calc_curve(xx + f, p1.first, yy + f, sqinRmf);
          } else if (!tl) {
            this_area += calc_curve(xx + f, xx + g - f, yy + f, sqinRmf);
          } else {
            point p1 = find_inter(xx + f, yy + g - f, xx + g - f, yy + g - f, sqinRmf);
            this_area += (g - 2 * f) * (p1.first - (xx + f));
            this_area += calc_curve(p1.first, xx + g - f, yy + f, sqinRmf);
          }

          if (gm2f > 0) {
            safe_area += this_area;
          }
        }
      }
    }

    double total_area = M_PI * sq(R);

//    printf("safe_area: %.9Lf\n", safe_area);

    printf("Case #%d: %.9Lf\n", z, 1.0 - 4 * (safe_area / total_area));
  }

  return 0;
}


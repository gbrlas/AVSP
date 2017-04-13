#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

// assume correct input

double curved(double r, double x, double y)
{
  double l = std::sqrt(x * x + y * y) / 2.0;
  double t = std::asin(l / r);
  double h = sqrt(r * r - l * l);

  return t * r * r - h * l + x * y / 2.0;
}

int main()
{
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
      double f, R, t, r, g;
      std::cin >> f >> R >> t >> r >> g;
      double Rin = R - t; // inner racquet radius
      double geff = g - f - f; // effective gap width
      double per = g + r + r; // gap period

      if (Rin <= r + f + f ||
          geff <= 0) {
          std::cout << "Case #" << i << ": 1.000000" << std::endl;
          continue;
      }

      int max_square = int(std::ceil((Rin - r) / per));
      std::vector<double> inner_bounds(max_square);
      std::vector<double> outer_bounds(max_square);
      double b = Rin - f;
      for (int j = 0; j < max_square; ++j) {
          double tmp = j * per + r + f;
          if (tmp >= b)
              inner_bounds[j] = 0.0;
          else
              inner_bounds[j] = std::sqrt(b * b - tmp * tmp);

          tmp = j * per + r + g - f;
          if (tmp >= b)
              outer_bounds[j] = 0.0;
          else
              outer_bounds[j] = std::sqrt(b * b - tmp * tmp);
      }

      double whole_gap = geff * geff;

      double escape = 0.0;
      for (int j = 0; j < max_square; ++j) {
          double yin = inner_bounds[j];
          double yout = outer_bounds[j];

          if (yin <= r + f)
              break;

          int k = int(std::floor((yout + 3 * f - r) / per));
          if (k < 0)
              k = 0;
          escape += whole_gap * k;

          yin -= k * per + r + f;
          yout -= k * per + r + f;

          for (; k < max_square; ++k) {
              double xin = inner_bounds[k];
              double xout = outer_bounds[k];

              xin -= j * per + r + f;
              xout -= j * per + r + f;

              if (xin <= 0.0 || yin <= 0.0)
                  break;

              if (xin >= geff && yin >= geff) {
                  escape += whole_gap - (geff - xout) * (geff - yout);
                  escape += curved(Rin - f, geff - xout, geff - yout);
              } else if (xin >= geff) {
                  escape += geff * yout;
                  escape += curved(Rin - f, geff, yin - yout);
              } else if (yin >= geff) {
                  escape += geff * xout;
                  escape += curved(Rin - f, xin - xout, geff);
              } else {
                  escape += curved(Rin - f, xin, yin);
              }

              yin -= per;
              yout -= per;
          }
      }

      double prob = 1.0 - escape / (R * R * std::atan(1.0));
      int iprob = int(std::floor(prob * 1000000.0 + 0.5));
      if (iprob < 0)
          iprob = 0;
      std::cout << "Case #" << i << ": ";
      if (iprob >= 1000000)
          std::cout << "1.000000";
      else
          std::cout << "0." << std::setfill('0') << std::setw(6) << iprob;
      std::cout << std::endl;
  }
}

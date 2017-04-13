#include <cassert>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

double f;
double R;
double t;
double r;
double g;

const double PI = 4.0 * atan(1.0);

void
read_case(istream & in)
{
    in >> f >> R >> t >> r >> g;
}

double
norm(double x, double y)
{
    return sqrt(x*x + y*y);
}

double
icept(double rad, double coord)
{
    return sqrt(rad * rad - coord * coord);
}

double
circle_antidiff(double R, double x)
{
    double p = sqrt(R * R - x * x);
    return 0.5 * (x * p + R * R * atan(x / p));
}

double
integrate_disk(double R, double a, double b)
{
    return circle_antidiff(R, b) - circle_antidiff(R, a);
}

double
p_hit()
{
    if (f >= g / 2) {
        return 1.0;
    }

    double A_miss = 0.0;

    double Rp = R - t - f;
    double G = r + g / 2;
    for (unsigned i = 1; true; i += 2) {
        double xs = i * G;
        double a = xs - g / 2 + f;
        double b = xs + g / 2 - f;

        if (a > Rp) {
            break;
        }

        for (unsigned j = 1; true; j += 2) {
            double ys = j * G;
            double c = ys - g / 2 + f;
            double d = ys + g / 2 - f;

            if (c > Rp) {
                break;
            }

            assert(a <= b);
            assert(c <= d);

            if (norm(a, c) > Rp) {
                continue;
            }

            double ap, bp;
            
            if (d > Rp) {
                ap = a;
            } else {
                ap = max(a, icept(Rp, d));
            }
            ap = min(ap, b);

            bp = min(b, icept(Rp, c));

            assert(ap <= bp + 1e-5);

            double As = 0.0;
            if (ap > a) {
                // Rectangle
                As += (ap - a) * (d - c);
            }

            if (ap < bp) {
                // Integral
                double A = integrate_disk(Rp, ap, bp) - (bp - ap) * c;
                if (!isnan(A)) {
                    As += A;
                }
            }

            //cerr << "(" << xs << ", " << ys << "): " << As << endl;
            if (As > 0) {
                A_miss += As;
            }
        }
    }

    return 1.0 - 4 * A_miss / (PI * R * R);
}

int main(int argc, char * argv[]) {
    srand(time(0));
    
    ifstream in(argv[1]);

    unsigned n;
    in >> n;
    for (unsigned i = 0; i < n; ++i) {
        read_case(in);
        double p = p_hit();
        cout << "Case #" << i+1 << ": "
             << showpoint << setprecision(6) << p << endl;
    }

    return 0;
}

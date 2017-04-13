#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
using namespace std;
#define _Test
#ifdef _Test
#define in cin
#define out cout
#else
#endif

double rs(double r, double a)
{
    return sqrt(r * r - a * a);
}
double SQ(double d)
{
    return d * d;
}
double Heron(double a, double b, double c)
{
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
double sqsum(double a, double b)
{
    return sqrt(a * a + b * b);
}

double Ar(double r, double ldx, double ldy, double luy, double rx)
{
    if (r <= 0 || ldx >= rx || ldy >= luy)
    {
        return 0;
    }

    double l = sqsum(rx - ldx, luy - ldy);
    double ang = 2 * asin(l / (2 * r));
    double S = ang * r * r / 2;
    double s1 = S - Heron(r, r , l);
    double s2 = (rx - ldx) * (luy - ldy) / 2;
    return s1 + s2;
}

double Do13(double x, double y, double Rt, double f, double g)
{
    double x1 = x + f;
    double x2 = x + g - f;
    
    if (x1 >= Rt - f)
    {
        return 0;
    }

    double y1 = rs(Rt - f, x1);
    double y2 = y + f;
    if (y1 <= y2)
    {
        return 0;
    }

    if (Rt-f > x2)
    {
        double y3 = rs(Rt-f, x2);
        //4
        if (y3 > y2)
        {
            return (x2 - x1) * (y3 - y2) + Ar(Rt - f, x1, y3, y1, x2);
        }
        //else
        //{
        //    return Ar(Rt - f, x1, y3, y1, x2);
        //}
    }
//   else
    {
        //3 (x1, y1), (x1, y2), (x3, y2)
        double x3 = rs(Rt - f, y2);
        return Ar(Rt-f, x1, y2, y1, x3);
    }
}

double Do23(double x, double y, double Rt, double f, double g)
{
    double x1 = x + f;
    double x2 = x + g - f;
    double y1 = y + f;
    double y2 = y + g - f;
    
    if (x1 >= Rt - f || y1 >= Rt - f || x1 * x1 + y1 * y1 >= (Rt - f) * (Rt - f))
    {
        return 0;
    }

    if (Rt - f > y2)
    {
        double x3 = rs(Rt - f, y2);
        if (Rt - f > x2)
        {
            double y3 = rs(Rt - f, x2);
            return (x3 - x1) * (y2 - y1) + (x2 - x3) * (y3 - y1) 
                + Ar(Rt - f, x3, y3, y2, x2);
        }
        else
        {
            double x4 = rs(Rt - f, y1);
            return (x3 - x1) * (y2 - y1)
                + Ar(Rt - f, x3, y1, y2, x4);
        }
    }
    else
    {
        double y3 = rs(Rt - f, x1);
        if (Rt - f > x2)
        {
            //TODO
            double y4 = rs(Rt - f, x2);

            return (x2 - x1) * (y4 - y1)
                + Ar(Rt - f, x1, y4, y3, x2);
        }
        else
        {
            double x4 = rs(Rt - f, y1);
            return Ar(Rt-f, x1, y1, y3, x4);
        }
    }
}

double Do24(double x, double y, double Rt, double f, double g)
{
    double x1 = x + f;
    double y1 = y + f;
    double y2 = y + g - f;
    
    if (x1 >= Rt - f || y1 >= Rt - f || x1 * x1 + y1 * y1 >= (Rt - f) * (Rt - f))
    {
        return 0;
    }

    double x2 = rs(Rt - f, y1);
    if (x2 <= x1)
    {
        return 0;
    }
    
    if (Rt - f  > y2)
    {
        double x3 = rs(Rt - f, y2);

        return (x3 - x1) * (y2 - y1) + Ar(Rt - f, x3, y1, y2, x2);
    }
    else
    {
        double y3 = rs(Rt - f, x1);

        return Ar(Rt - f, x1, y1, y3, x2);
    }
}

double Do14(double x, double y, double Rt, double f, double g)
{
    double x1 = x + f;
    double y1 = y + f;
    
    if (x1 >= Rt - f || y1 >= Rt - f || x1 * x1 + y1 * y1 >= (Rt - f) * (Rt - f))
    {
        return 0;
    }

    double x2 = rs(Rt - f, y1);
    double y2 = rs(Rt - f, x1);    

    return Ar(Rt-f, x1, y1, y2, x2);
}

int Ht(double y, double g, double r)
{
    int k = (int)((y + r) / (2 * r + g)) - 2;
    if (k < 0)
    {
        k = 0;
    }
    while(true)
    {
        int i = k + 1;
        double yi = (2 * i - 1) * r + i * g;
        if (yi > y)
        {
            break;
        }
        k = i;
    }
    return k;
}

double Do(double Rt, double r, double f, double g)
{
    double x = r;
    if (g <= f + f)
    {
        return 0;
    }

    double sone = (g - f - f) *  (g - f - f);
    double s = 0;
    for (double x = r; x < Rt; x += g + r + r)
    {
        double y1 = rs(Rt, x);
        double xx = x + g;
        if (xx <= Rt)
        {
            double y2 = rs(Rt, xx);
            int k = Ht(y2, g, r);

            s += k * sone;

            double ys = (2 * k - 1) * r + k * g + 2 * r;
            while(ys < y1)
            {
                double ys1 = ys + g;
                if (ys1 >= y1)
                {
                    if (ys >= y2)
                    {
                        s += Do14(x, ys, Rt, f, g);
                    }
                    else
                    {
                        s += Do13(x, ys, Rt, f, g);
                    }
                }
                else
                {
                    if (ys <= y2)
                    {
                        s += Do23(x, ys, Rt, f, g);
                    }
                    else
                    {
                        s += Do24(x, ys, Rt, f, g);
                    }
                }
                ys += r + r + g;
            }
        }
        else
        {
            double ys = r;
            while(ys < y1)
            {
                double ys1 = ys + g;
                if (ys1 >= y1)
                {
                    s += Do14(x, ys, Rt, f, g);
                }
                else
                {
                    s += Do24(x, ys, Rt, f, g);
                }
                ys += r + r + g;
            }
        }
    }
    return s;
}

void One(int idx)
{
    double p;
    double f, R, t, r, g, Rt;
    in >> f >> R >> t >> r >> g;
    if (2 * f >= g)
    {
        p = 1.0;
        goto OP;
    }
    Rt = R - t;

    double S = acos(-1.0) * R * R;

    double s = Do(Rt, r, f, g);

    p = (S - 4 * s) / S;

    if (p < -0.00000001)
    {
        for (int i = 0; i < 1;++i)
        {
            printf("ERROR");
        }
    }
    else
    {
        p = abs(p);
    }

OP:
//    out << "Case #" << idx << ": ";
    printf("Case #%d: %6f\n", idx, p);
//    out << endl;
}
void SolveN()
{
 int n;
 in >> n;
 for (int i = 0; i < n; ++i)
 {
  One(i + 1);
 } 
}
void Solve()
{
}
int main()
{
 SolveN();
 return 0;
}

#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

ofstream cout("C-large.out");
ifstream cin ("C-large.in");


struct Point
{
    Point(double xx = 0, double yy = 0)
        :x(xx), y(yy)
    {}
    double x;
    double y;

    double dist(const Point& p)
    {
        double dx = x - p.x;
        double dy = y - p.y;
        return sqrt(dx * dx + dy * dy);
    }
};

struct Poly
{
    vector<Point> points;
    double area()
    {
        double polyArea = 0.0;
        for (unsigned i = 0; i < points.size() - 1; ++i)
        {
            polyArea += (points[i].x - points[i + 1].x) * (points[i].y + points[i + 1].y);
        }

        polyArea += (points[points.size() - 1].x - points[0].x) * (points[points.size() - 1].y + points[0].y);
        polyArea /= 2;
        return abs(polyArea);
    }
};


struct Square
{
    Point p;
    double side, r;

    bool isInsideCircle (double x, double y)
    {
        return (x * x + y * y <= r * r);
    }

    bool isInside(double& commonArea)
    {
        commonArea = 0;
        if (isInsideCircle(p.x + side, p.y + side))
        {
            commonArea = side * side;
            return true;
        }


        if (isInsideCircle(p.x, p.y))
        {
            Poly poly;
            poly.points.push_back(p);
            
            if (isInsideCircle(p.x, p.y + side))
            {
                poly.points.push_back(Point(p.x, p.y + side));
                
                double xL = sqrt(r * r - (p.y + side) * (p.y + side));
                poly.points.push_back(Point(xL, p.y + side));
            }
            else
            {
                double yL = sqrt(r * r - p.x * p.x);
                poly.points.push_back(Point(p.x, yL));
            }

            if (isInsideCircle(p.x + side, p.y))
            {
                poly.points.insert(poly.points.begin(), Point(p.x + side, p.y));

                double yL = sqrt(r * r - (p.x + side) * (p.x + side));
                poly.points.insert(poly.points.begin(),Point(p.x + side, yL));
            }
            else
            {
                double xL = sqrt(r * r - p.y * p.y);
                poly.points.insert(poly.points.begin(), Point(xL, p.y));
            }

            double d = poly.points[0].dist(poly.points[poly.points.size() - 1]);
            double h = sqrt(r * r - (d/2.0) * (d/2.0));
            
            double chord_area = r * r * acos(h/r) - h * d/2.0;

            commonArea = poly.area() + chord_area;
            return true;
        }
        else
            return false;
       
    }

};



int main()
{

    int count = 0;
    cin >> count;
    for (int tt = 1; tt <= count; ++tt)
    {
        double f, R, t, r, g;
        cin>>f>>R>>t>>r>>g;
        double allArea = M_PI * R * R;
        double innerR = R - t - f;
        r += f;
        g -= 2*f;
        double sutArea = 0.0, commonArea = 0;
        if (innerR <= 0.0 || g <= 0.0)
        {
            // zero
        }
        else
        {
            Square s;
            s.side = g;
            s.r = innerR;
            for (int i = 0; i < 1010; ++i)
            {
                for (int j = 0; j < 1010; ++j)
                {
                    s.p.x = r + i * (g + 2*r); 
                    s.p.y = r + j * (g + 2*r);
                    if (s.isInside(commonArea))
                    {
                        sutArea += commonArea;
                    }
                    else
                        break;
                }
            }
        }
        cout << fixed << showpoint << setprecision(6);
        
        cout<< "Case #"<<tt<<": "<<(1.0 - 4.0 * sutArea / allArea)<<endl;

    }
    return 0;
}
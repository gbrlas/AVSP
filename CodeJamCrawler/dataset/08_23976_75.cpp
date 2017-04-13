#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//ifstream fin("input.txt");
//#define cin fin

#define ABS(a) (a) < 0 ? -(a) : (a)

#define MAXD 20

class pt
{
public:
   double x;
   double y;
   pt(double x,double y)
   :
      x(x),
      y(y)
   {
   }
   bool inside(double r)
   {
      return x*x+y*y <= r*r;
   }
};

double f,R,t,rad,g,epsilon;

class Square
{
public:
   pt a,b,c,d;

   Square(pt a, pt b, pt c, pt d)
   :
   a(a),b(b),c(c),d(d) {}

   Square(double x1, double y1, double x2, double y2)
      :
      a(x1,y1),
      b(x2,y1),
      c(x1,y2),
      d(x2,y2)
      {
      }
   bool inside(double r)
   {
      return b.inside(r);
   }

   bool outside(double r)
   {
      return !c.inside(r);
   }

   double area()
   {
      double side = a.y-c.y;
      return side*side;
   }

   double areaInside(double r, int depth)
   {
      if(inside(r))
      {
         return area();
      }
      else if(outside(r))
      {
         return 0;
      }
      else if(area() < epsilon)
      {
         return estimateAreaInside(r);
      }
      else
      {
         return subDivideArea(r, depth+1);
      }
   }


   static double findVal(double x, double r)
   {
      return sqrt(r*r-x*x);
   }



   double estimateAreaInside(double r)
   {
      if(a.inside(r))
      {
         if(d.inside(r))
         {
            double triArea = .5*(b.x-findVal(a.y,r))*(b.y-findVal(d.x,r));
            return area() - triArea;
         }
         else
         {
            double height = a.y-c.y;
            double wid1 = findVal(a.y,r) - a.x;
            double wid2 = findVal(c.y,r) - c.x;
            return height*(wid1+wid2)*.5;
         }
      }
      else
      {
          if(d.inside(r))
         {
            double h1 = findVal(c.x,r) - c.y;
            double h2 = findVal(d.x,r) - d.y;
            double w = d.x - c.x;
            return w*(h2+h1)*.5;
         }
         else
         {
            return .5*(findVal(a.x,r)-c.y)*(findVal(c.y,r)-c.x);
         }
      }

   }

   double subDivideArea(double r, int depth)
   {
      double x1 = .5*(b.x-a.x)+a.x;
      double y1 = .5*(a.y-c.y)+c.y;
      double val = Square(a.x,a.y,x1,y1).areaInside(r,depth);
      val += Square(x1,b.y,b.x,y1).areaInside(r,depth);
      val += Square(c.x,y1,x1,c.y).areaInside(r,depth);
      val += Square(x1,y1,d.x,d.y).areaInside(r,depth);
      return val;
   }
};



void rockNRoll()
{
   double probability = 0;
   if(g <= 0)
   {
      probability = 1.0;
   }
   else
   {
      double TotalArea = M_PI*R*R;
      double flyFriendlyArea = 0;
      double boxSize = 2.0*rad + g;
      int numBoxes = (int)(1.5 + t / boxSize);
      //cout << numBoxes << " boxes."<< endl;
      /************************************/
      epsilon = (1e-11*TotalArea)/numBoxes;
      /************************************/
      for(int i=0;i<numBoxes;++i)
      {
         double y2 = rad + i*boxSize;
         double y1 = y2 + g;
         for(int j=0;j<numBoxes;++j)
         {
            double x1 = rad + j*boxSize;
            double x2 = x1 + g;
            Square s(x1,y1,x2,y2);
            double addedArea = s.areaInside(t,0);
            //cout << "added " << addedArea << endl;
            flyFriendlyArea += addedArea;
         }
      }
      probability = 1.0-(4.0*flyFriendlyArea/TotalArea);
   }
   cout << fixed << setprecision(6) << probability << endl;
}

int main()
{
   int N;
   cin >> N;
   for(int i=1;i<=N;++i)
   {
      cin >> f >> R >> t >> rad >> g;
      t = R-t-f;
      g = g-2.0*f;
      rad = rad + f;
      cout << "Case #" << i << ": ";
      /*
      printf("\nRadius: %f\nInnerRadius: %f\n", R, t);
      printf("FlyRad: %f\nStringRad: %f\n", f, rad);
      printf("stringGap: %f\n", g);
      */
      rockNRoll();
   }
   return 0;
}

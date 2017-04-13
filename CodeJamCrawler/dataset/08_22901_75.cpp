#include <cstdlib>
//#include <iostream>
#include<fstream>
#include<cmath>
#include<cstdio>
using namespace std;
//ofstream cout("C.out");
ifstream cin("C.in");
FILE *fout;
double const pi = 3.14159265358979323846;

double getarea(double d,double D,double &R)
{
 double th1 = acos (D/R),th2 = acos (d/R);
 return  (0.5*D*R*sin (th1)+ 0.5 *(th2 -th1)*R*R -0.5 *d*R * sin (th2));  
}
double dist (double x1,double y1,double x2,double y2)
{
       return sqrt((x2-x1)*(x2-x1) + (y2 - y1)*(y2 - y1));
}
double encarea(double x,double y,double &r, double s)
{
       if (x==0 && y==0) return 4*s*s;
       if(x==0)  
       {
                // cout << s <<" "<<y<<" "<<r<<endl;
                 if((y-s)>=r) return 0;
                 if(dist(s,y+s,0,0) <=r) return (4*s*s);
                 if((y+s)>=r)
                 {
                            
                  double y1 = sqrt(r*r - s*s);
                  double thet = asin(s/r);
                  return (r*r*(thet - 0.5* sin (2*thet)) + (y1 -y +s)*2*s);
                 }
                 double x1 = sqrt(r*r - (y+s)*(y+s)),y1 =sqrt(r*r - s*s);
                 double alp = asin (y1/r) , bet = asin ((y+s)/r);
                 double th = abs(alp - bet);
                 double sect = 0.5*r*r* ( th -  sin(th) );
                 return (4*s*s + 2*sect - (s-x1)*(y+s - y1));
       }
       if(y==0) return encarea(y,x,r,s);
       
 if (dist(x-s,y-s,0,0) > r) return 0;
 if(dist (x+s,y+s,0,0) < r) return (4*s*s);
 double d1 = dist(x-s,y+s,0,0),d2 = dist(x+s,y-s,0,0); 
 if( (d1 <= r) && (d2 <= r) )
 {
     double y1= sqrt (r*r -  (x+s)*(x+s));
     double x1 = sqrt (r*r - (y+s)*(y+s));
     double alp = acos((x+s)/r),bet = asin ((y+s)/r);
     double th = abs(bet - alp);
     double sect=0.5 *th*r*r - 0.5 *r*r* sin (th);
     return (sect + 4* s*s - 0.5*(y+s-y1)*(x+s-x1));
 }
 if( (d1 >= r) && (d2 >= r) )
 {
     double y1= sqrt (r*r -  (x-s)*(x-s));
     double x1 = sqrt (r*r - (y-s)*(y-s));
     double alp = asin((y-s)/r),bet = acos ((x-s)/r);
     double th = abs(bet - alp);
     double sect=0.5 *th*r*r - 0.5 *r*r* sin (th);
     return (sect + 0.5*(y1 - y + s)*(x1 - x + s));
 }     
 if( (d1 <= r) && (d2 >= r) )
 {
     double x1= sqrt (r*r -  (y+s)*(y+s));
     double x2 = sqrt (r*r - (y-s)*(y-s));
     double alp = asin((y+s)/r),bet = asin ((y-s)/r);
     double th = abs(bet - alp);
     double sect=0.5 *th*r*r - 0.5 *r*r* sin (th);
     return (sect +  s*(x1+x2-2*(x-s)));
 }
 
 if( (d1 >= r) && (d2 <= r) )
 {
     double y1= sqrt (r*r -  (x-s)*(x-s));
     double y2 = sqrt (r*r - (x+s)*(x+s));
     double alp = asin(y2/r),bet = asin (y1/r);
     double th = abs(bet - alp);
     double sect=0.5 *th*r*r - 0.5 *r*r* sin (th);
     return (sect +  s*(y1+y2-2*(y-s)));
 }
}
int main()
{
    int n;
    cin>>n;
    
fout = fopen("C.out","w");
    double f,R,t,r,g,u,s,h,num,tmp,area1,th,area2;
    bool lastrect=false;
    int i,j;
    for(i=0;i<n;i++)
    {
     cin>>f>>R>>t>>r>>g;
     u=2*r+2*f;
     s = g-2*f;
     h = R-t-f;
     if(s<=0 || h<= 0) 
     {
             //cout << "Case #"<<i+1<<": 1.000000"<<endl;
             fprintf(fout,"Case #%d: %1.6f\n",i+1,1.000000);
             continue;
     }
     num = (h - u/2)/(s+u);
     int k = int(num);
     tmp =  h - u/2 - k*(s+u);

     if(tmp >s) lastrect =true;
     else lastrect =false;
     area1=0; area2=0;
     th = asin (u/(2*h));

            area1 += h*u*cos(th) + (th *  h*h)- 0.5 * h*h * sin (2*th);
     if(lastrect)
     {
      double a1 = k*(s+u) + s + u/2;
          double ang1 = acos (a1/h);
      area1 += ang1 * h* h - 0.5 *h *h * sin (2* ang1);
     }
    
     for(j=1;j<=k;j++)
     {
      area1 += 2 *getarea(0.5*u + j*(s+u) - u,0.5*u + j*(s+u),h);
     }
     area1 = area1 *4;
    
     if(lastrect) k++;
     int p,q;
     for(p=0;p<=k;p++)
     {
      for(q=0;q<=k;q++)
      {
       double tba = encarea(p*(s+u),q*(s+u),h,u/2);
       if (p == 0 || q == 0)
       {
             if(p==0 && q==0)
             {
                     area2 += tba/4;
             }
             else 
             {
                  area2 += tba/2;
             }
       }
       else
       {
           area2 += tba;
       }
      }
     }
     area2 = 4*area2;
     double netarea = area1 - area2 + pi*(R*R - (R-t-f)*(R-t-f));
     //cout << "Case #"<<i+1<<": ";
     
     fprintf(fout,"Case #%d: %1.6f\n",i+1,netarea/ (pi* R*R));
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}

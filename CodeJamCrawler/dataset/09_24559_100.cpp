#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(long i = a; i <= b; i++)
using namespace std;
void solve()
{
     long n,a,b,c,d,e,f,A = 0,B = 0 ,C = 0,D = 0,E= 0 ,F= 0;
     scanf("%ld",&n);
     FOR(i,1,n)
     {
          scanf("%ld%ld%ld%ld%ld%ld",&a,&b,&c,&d,&e,&f);
          A+= a;
          B+= b;
          C+= c;
          D+= d;
          E+= e;
          F+= f;
     };
     if (D == 0 && E == 0 && F == 0)
     {
           printf("%.8lf %.8lf\n",sqrt(A*A+B*B+C*C)/n,0);
           return ;
     };
     double t = -(double)(A*D+B*E+C*F)/(double)(D*D+E*E+F*F);
     if (t < 0) t = 0;
     t = abs(t);
     double res1 = sqrt( (A + D*t) * ( A + D * t) + (B+E*t)*(B+E*t) + (C+F*t)*(C+F*t) )/n;
     printf("%.8lf %.8lf\n",res1,t);
};
int main()
{
    freopen("fish6.in","r",stdin);
    freopen("TEST.OUT","w",stdout);
    long ntest;
    scanf("%ld",&ntest);
    FOR(test,1,ntest)
    {
         cout << "Case #" << test << ": ";
         solve();
    };
    return 0;
};

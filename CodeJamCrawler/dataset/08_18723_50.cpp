#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>

using namespace std;
#define iss istringstream
#define pb push_back
#define cs c_str()
#define frr(i,a,b) for(i=(a); i<(b); i++)
#define fr(i,n) frr(i,0,(n))
#define rrf(i,b,a) for(i=(b)-1; i>=(a); i--)
#define rf(i,n) rrf(i,(n),0)
#define sq(x,y,z) sqrt((x)*(x)+(y)*(y)+(z)*(z))
#define in(x,s) (s.find(x)!=s.end())
#define sv(x) sort(x.begin(),x.end())

int x[1<<10], y[1<<10], z[1<<10], p[1<<10], n;

double ask(double X, double Y, double Z)
{
   double ans=0;
   int i;
   fr(i,n) ans>?=(fabs(X-x[i])+fabs(Y-y[i])+fabs(Z-z[i]))/p[i];
   return ans;
}

void init(double &L, double &R, int *w, int n)
{
   int i;
   L=1e100;
   R=-1e100;
   fr(i,n)
   {
      L<?=w[i];
      R>?=w[i];
   }
}

int main()
{
   char s[128];
   int T, t, i, j;
   double X, Y, Z;
   
   for(scanf("%d", &T), t=1; t<=T; t++)
   {
      X=Y=Z=0;
      scanf("%d", &n);
      fr(i,n)
      {
         scanf("%d %d %d %d", x+i, y+i, z+i, p+i);
         X+=x[i];
         Y+=y[i];
         Z+=z[i];
      }
      X/=n;
      Y/=n;
      Z/=n;
      
      double L, R, M1, M2;
      
      fr(j,100)
      {
         init(L, R, x, n);
         fr(i,100)
         {
            M1=(L*2+R)/3;
            M2=(L+R*2)/3;
            ask(M1, Y, Z)<ask(M2, Y, Z)?(R=M2):(L=M1);
         }
         X=(M1+M2)/2;
         init(L, R, y, n);
         fr(i,100)
         {
            M1=(L*2+R)/3;
            M2=(L+R*2)/3;
            ask(X, M1, Z)<ask(X, M2, Z)?(R=M2):(L=M1);
         }
         Y=(M1+M2)/2;
         init(L, R, z, n);
         fr(i,100)
         {
            M1=(L*2+R)/3;
            M2=(L+R*2)/3;
            ask(X, Y, M1)<ask(X, Y, M2)?(R=M2):(L=M1);
         }
         Z=(M1+M2)/2;
      }
      
      printf("Case #%d: %.6lf\n", t, ask(X, Y, Z));
   }
   
   return 0;
}

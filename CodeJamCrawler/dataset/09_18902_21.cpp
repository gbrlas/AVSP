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

int main()
{
   int T, t, n, x[64], y[64], r[64], i, j, k, p;
   double R;
   
   for(scanf("%d", &T), t=1; t<=T; t++)
   {
      scanf("%d", &n);
      fr(i,n) scanf("%d %d %d", x+i, y+i, r+i);
      
      if(n==1)
         R=r[0];
      else if(n==2)
         R=r[0]>?r[1];
      else
      {
         R=1e100;
         fr(k,3)
         {
            if(k==0)
            {
               i=0;
               j=1;
               p=2;
            }
            if(k==1)
            {
               i=1;
               j=2;
               p=0;
            }
            if(k==2)
            {
               i=2;
               j=0;
               p=1;
            }
            R<?=r[p]>?((sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))+r[i]+r[j])/2);
         }
      }
      
      printf("Case #%d: %.6lf\n", t, R);
   }
   
   return 0;
}
